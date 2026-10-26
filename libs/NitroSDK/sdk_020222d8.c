#include "libs/NitroSDK/sdk_020222d8.h"

extern Unk0222d8State data_02156d28;
extern Unk0222d8Vector data_02156e08;
extern s32 data_02156e58[12];
extern s32 data_02156e88[12];
extern Unk0222d8Submission data_02159c90;
/** Shared input and output blocks consumed by the matrix builders. */
extern u8 data_02156d74[];
extern u8 data_02156de4[];
extern u8 data_02156e28[];
/** Dispatch table indexed by the low five bits of a command byte. */
extern int (*data_0213d504[])(void *, u32);

/** Observed black-box helpers; this unit only depends on the argument shapes. */
extern void func_0200101c(void *first, const void *second);
extern void func_020013a8(void *first, const void *second, void *third);
extern void func_02000fe8(s32 *output, const s32 *input, s32 first, s32 second, s32 third);
extern void func_020086e4(const void *source, void *destination, u32 size);
/** Geometry command submission: command id, parameter block, 32-bit word count. */
extern void func_020252fc(u32 command, const u32 *parameters, u32 count);
extern void func_020086a0(u32 value, void *destination, u32 size);
extern void func_02022b3c(void *scratch, Unk0222d8RenderCmd *command);
extern int func_02004210(s32 *matrix);
extern int func_02004240(s32 *matrix);
extern void func_020017b0(const s32 *source, s32 *destination);
extern void func_0200835c(s32 channel, const void *source, u32 size,
                          void (*callback)(void *), void *argument);
extern void func_02008560(s32 channel, const void *source, u32 size,
                          void (*callback)(void *), void *argument);
/** DMA channel id shared with the GX helpers; -1 disables DMA transfers. */
extern s32 data_0213ce44;
/** Asynchronous-DMA flag word; the delink exposes it as data_02159c94. */
extern volatile s32 data_02159c94;
/** Material SBC internal dispatch table, indexed by the resource item tag. */
extern void (*data_0213d414[])(Unk0222d8ResourceState *, u32,
                               const Unk0222d8ResourceData *, u32);
/** Shape SBC internal dispatch table, indexed by the resource item tag. */
extern void (*data_0213d424[])(Unk0222d8ResourceState *, u32,
                               const Unk0222d8ResourceData *, u32);
/** Shared render state built by 02022b3c; null means no draw is in progress. */
extern void *data_02156f8c;

/** Evidence: 02022468 copies three words only for non-null input; clears mask 0xa4. */
void func_02022468(const Unk0222d8Vector *value)
{
    if (value == 0) return;
    data_02156e08 = *value;
    data_02156d28.flags &= ~0xa4;
}

/** Evidence: 02022498 tests flag bit 3, builds 02156e28 once, and returns it. */
u8 *func_02022498(void)
{
    if (!(data_02156d28.flags & 8)) {
        func_0200101c(data_02156d74, data_02156e28);
        data_02156d28.flags |= 8;
    }
    return data_02156e28;
}

/** Evidence: 020224dc feeds 02156de4/02156d74 and words 58..60 of the shared state. */
void func_020224dc(void)
{
    func_020013a8(data_02156de4, data_02156d74, data_02156e58);
    func_02000fe8(data_02156e58, data_02156e58, data_02156d28.parameters[58],
                  data_02156d28.parameters[59], data_02156d28.parameters[60]);
    func_0200101c(data_02156e58, data_02156e88);
}

/** Evidence: 02022534 tests cache bit 7 before returning the 02156e58 matrix. */
s32 *func_02022534(void)
{
    if (!(data_02156d28.flags & 0x80)) {
        func_020224dc();
        data_02156d28.flags |= 0x80;
    }
    return data_02156e58;
}

/** Evidence: 0202256c shares the same cache bit and returns the 02156e88 matrix. */
s32 *func_0202256c(void)
{
    if (!(data_02156d28.flags & 0x80)) {
        func_020224dc();
        data_02156d28.flags |= 0x80;
    }
    return data_02156e88;
}

/** Evidence: 020225a4 walks nodes and calls each matching entry callback with the low byte. */
int func_020225a4(void *context, Unk0222d8Node *node, u32 index)
{
    int found;

    if (node == 0) return 0;
    found = 0;
    do {
        if (index < node->count) {
            u16 entry = node->entries[index];
            if ((entry & 0x300) == 0x100 && node->callback != 0) {
                node->callback(context, node, entry & 0xff);
                found = 1;
            }
        }
        node = node->next;
    } while (node != 0);
    return found;
}

/** Evidence: 02022610 adds `value` directly, or (value * src) >> 12 when additive is zero. */
void func_02022610(s32 *dst, const s32 *src, s32 value, u32 additive)
{
    if (additive != 0) {
        dst[0] += value;
        dst[1] += value;
        dst[2] += value;
    } else {
        dst[0] += (value * src[0]) >> 12;
        dst[1] += (value * src[1]) >> 12;
        dst[2] += (value * src[2]) >> 12;
    }
}

/** Evidence: 02022a6c walks one node chain like 020225a4, calls callbacks with a
 *  scratch word and ORs the callback output into `bits`; returns 1 if any ran.
 *  NitroSystem sbc.c uses the same pattern to accumulate animation hint words. */
u32 func_02022a6c(u32 *bits, Unk0222d8Node *node, u32 index)
{
    u32 found = 0;

    *bits = 0;
    do {
        if (index < node->count) {
            u16 entry = node->entries[index];
            if ((entry & 0x300) == 0x100 && node->callback != 0) {
                u32 value;
                node->callback(&value, node, entry & 0xff);
                *bits |= value;
                found = 1;
            }
        }
        node = node->next;
    } while (node != 0);
    return found;
}

/** Evidence: 02022af4 dispatches data_0213d504[byte & 0x1f] until flag bit 5 is set. */
void func_02022af4(Unk0222d8Command *command)
{
    do {
        u32 op;

        command->flags &= ~0x40;
        op = *command->data;
        data_0213d504[op & 0x1f](command, op & 0xe0);
    } while (!(command->flags & 0x20));
}

/** Evidence: 02022cd8 sets bit `index` of the caller's words for entries with flag 0x100. */
void func_02022cd8(u32 *bits, Unk0222d8Node *node)
{
    if (node == 0) return;
    do {
        int i;

        for (i = 0; i < node->count; ++i) {
            if (node->entries[i] & 0x100) {
                bits[i >> 5] |= 1U << (i & 31);
            }
        }
        node = node->next;
    } while (node != 0);
}

/** Evidence: 02022d40 matches NNS_G3dDraw (NitroSystem sbc.c). Flag bit 4 marks
 *  stale hint bitsets; when set it clears them and rebuilds each bitset from the
 *  matching animation chain. It then builds a shared 392-byte render state on the
 *  stack only when no render state is active. */
void func_02022d40(Unk0222d8DrawObject *object)
{
    if ((object->flags & 0x10) == 0x10) {
        func_020086a0(0, object->bits_a, 8);
        func_020086a0(0, object->bits_b, 8);
        func_020086a0(0, object->bits_c, 8);
        if (object->unk_08 != 0) func_02022cd8(object->bits_a, object->unk_08);
        if (object->unk_10 != 0) func_02022cd8(object->bits_b, object->unk_10);
        if (object->unk_18 != 0) func_02022cd8(object->bits_c, object->unk_18);
        object->flags &= ~0x10;
    }
    if (data_02156f8c != 0) {
        func_02022b3c(data_02156f8c, (Unk0222d8RenderCmd *)object);
        return;
    }
    {
        u8 scratch[392];

        data_02156f8c = scratch;
        func_02022b3c(scratch, (Unk0222d8RenderCmd *)object);
        data_02156f8c = 0;
    }
}

/** Evidence: 02022e1c invokes offset-12 hook before incrementing offset 0. */
void func_02022e1c(Unk0222d8Record *record)
{
    if (record->on_count) record->on_count(record);
    record->count++;
}

/** Evidence: 02022e44 invokes offset-16 hook before setting offset-8 bit 5. */
void func_02022e44(Unk0222d8Record *record)
{
    if (record->on_flag) record->on_flag(record);
    record->flags |= 0x20;
}

/** Evidence: 02022fe8 runs the SBC callback protocol: it optionally calls the
 *  offset-0x18 hook for state 1, emits command 0x14 with the byte after the
 *  command cursor, then calls the hook again for state 3. The state byte and
 *  callback presence are re-read after each hook, matching sbc_inline.h. */
void func_02022fe8(Unk0222d8CallbackState *object)
{
    u32 state;
    u32 skip;

    if (object->flags & 0x200) goto advance;
    if (!(object->flags & 1)) goto advance;
    state = object->callback != 0 ? object->state : 0;
    if (state == 1) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!skip) {
        s32 value = object->data[1];
        if (!(object->flags & 0x100)) func_020252fc(20, (const u32 *)&value, 1);
    }
    if (state == 3) {
        object->flags &= ~0x40;
        object->callback(object);
    }
advance:
    object->data += 2;
}

/** Dictionary record lookup shared by the material and shape handlers; returns
 *  the fixed-stride entry or null, matching NNS_G3dGetResDataByIdx. */
static inline void *GetResourceDataByIdx(const Unk0222d8ResourceDict *dict, u32 index)
{
    Unk0222d8ResourceEntryHeader *header;

    if (dict != 0 && index < dict->numEntry) {
        header = (Unk0222d8ResourceEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)(&header->data[0] + header->sizeUnit * index);
    }
    return 0;
}

/** Resolve a material record by index; mirrors NNS_G3dGetMatDataByIdx. */
static inline Unk0222d8ResourceData *GetMaterialDataByIdx(const Unk0222d8ResourceMat *mat,
                                                          u32 index)
{
    Unk0222d8ResourceEntry *data;

    if (mat != 0) {
        data = (Unk0222d8ResourceEntry *)GetResourceDataByIdx(&mat->dict, index);
        if (data != 0) {
            return (Unk0222d8ResourceData *)((u8 *)mat + data->offset);
        }
    }
    return 0;
}

/** Resolve a shape record by index; mirrors NNS_G3dGetShpDataByIdx. */
static inline Unk0222d8ResourceData *GetShapeDataByIdx(const Unk0222d8ResourceShp *shp,
                                                       u32 index)
{
    Unk0222d8ResourceEntry *data;

    if (shp != 0) {
        data = (Unk0222d8ResourceEntry *)GetResourceDataByIdx(&shp->dict, index);
        if (data != 0) {
            return (Unk0222d8ResourceData *)((u8 *)shp + data->offset);
        }
    }
    return 0;
}

/** Evidence: 0202353c matches NNSi_G3dFuncSbc_MAT. It skips drawing when the
 *  SBC-draw option is set, reuses the cached material when the current-material
 *  flag and index both match, and otherwise dispatches through data_0213d414. */
void func_0202353c(Unk0222d8ResourceState *object, u32 option)
{
    if (!(object->flags & 0x200)) {
        u32 index = object->command[1];

        if ((object->flags & 1) ||
            !((object->flags & 8) && index == object->currentMat)) {
            Unk0222d8ResourceData *material = GetMaterialDataByIdx(object->resMat, index);

            data_0213d414[material->itemTag](object, option, material, index);
        }
    }
    object->command += 2;
}

/** Evidence: 020235ec waits for state 1, forwards the staged block through
 *  02025248, then runs the state-2 and state-3 hooks in sequence. It uses the
 *  same state byte/callback protocol as 02022fe8 with callback slots 0x20/0x91. */
void func_020235ec(Unk0222d8ShapeState *object, u32 unused,
                   Unk0222d8CommandSource *source)
{
    u32 state;
    u32 skip;

    state = object->callback != 0 ? object->state : 0;
    if (state == 1) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!skip) {
        if (!(object->flags & 0x100)) {
            func_02025248((u8 *)source + source->offset, source->size);
        }
    }
    if (state == 2) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
    }
    if (state == 3) {
        object->flags &= ~0x40;
        object->callback(object);
    }
}

/** Evidence: 020236c0 matches NNSi_G3dFuncSbc_SHP. It skips drawing when the
 *  SBC-draw option is set, rejects invisible/transparent nodes, resolves the
 *  shape record through data_0213d424, then advances the command cursor. */
void func_020236c0(Unk0222d8ResourceState *object, u32 option)
{
    if (!(object->flags & 0x200) && (object->flags & 1) && !(object->flags & 2)) {
        u32 index = object->command[1];
        Unk0222d8ResourceData *shape = GetShapeDataByIdx(object->resShp, index);

        data_0213d424[shape->itemTag](object, option, shape, index);
    }
    object->command += 2;
}

/** Evidence: 02024a64 sends command 0x1b with payload word e0 or e4 repeated three times. */
void func_02024a64(Unk0222d8Packet *packet, u32 flag)
{
    if (!(packet->flags & 0x100) && !(packet->flags & 0x200)) {
        s32 parameters[3];

        if (flag == 0) {
            parameters[0] = parameters[1] = parameters[2] = packet->unk_e0;
        } else {
            parameters[0] = parameters[1] = parameters[2] = packet->unk_e4;
        }
        func_020252fc(0x1b, (const u32 *)parameters, 3);
    }
    packet->unk_00++;
}

/** Evidence: 020251c8 waits when busy, then fills the staged block and clears its count. */
void func_020251c8(void)
{
    if (data_02159c90.busy != 0) {
        func_02025224();
    }
    if (data_02159c90.buffer != 0 && data_02159c90.buffer[0] != 0) {
        u32 count = data_02159c90.buffer[0];

        func_020086e4(data_02159c90.buffer + 1, (void *)0x4000400, count * 4);
        data_02159c90.buffer[0] = 0;
    }
}

/** Evidence: 02025224 spins while the shared submission status word is nonzero. */
void func_02025224(void)
{
    while (data_02159c90.busy) {}
}

/** Evidence: 0202523c unconditionally writes zero to the first word of its argument. */
void func_0202523c(u32 *buffer)
{
    *buffer = 0;
}

/** Evidence: 02025248 matches NNS_G3dGeSendDL (NitroSystem gecom.c). Small blocks
 *  or a disabled DMA channel use the buffered command path; larger blocks flush
 *  the buffer and start an asynchronous GX command transfer, selecting the fast
 *  or normal sender from the shared useFastDma word. */
void func_02025248(const void *source, u32 size)
{
    if (size < 256 || data_0213ce44 == -1) {
        func_020252fc(*(const u32 *)source, (const u32 *)source + 1, (size >> 2) - 1);
    } else {
        func_020251c8();
        data_02159c90.busy = 1;
        if (data_02159c90.useFastDma != 0) {
            func_02008560(data_0213ce44, source, size,
                          (void (*)(void *))func_0202523c, (void *)&data_02159c94);
        } else {
            func_0200835c(data_0213ce44, source, size,
                          (void (*)(void *))func_0202523c, (void *)&data_02159c94);
        }
    }
}

/** Evidence: 020253e0 matches NNS_G3dGetCurrentMtx (NitroSystem util.c). It
 *  flushes the command buffer, pushes an identity projection matrix, copies the
 *  hardware clip matrix to the 4x3 position output when requested, copies the
 *  vector matrix to the 3x3 normal output when requested, then pops the stack. */
void func_020253e0(s32 *position, s32 *normal)
{
    volatile u32 *mtx_mode = (volatile u32 *)0x04000440;

    func_020251c8();
    mtx_mode[0] = 0;
    mtx_mode[1] = 0;
    mtx_mode[5] = 0;

    if (position != 0) {
        s32 tmp[16];
        while (func_02004210(tmp) != 0) {}
        func_020017b0(tmp, position);
    }
    if (normal != 0) {
        while (func_02004240(normal) != 0) {}
    }

    ((volatile u32 *)0x04000448)[0] = 1;
    ((volatile u32 *)0x04000448)[-2] = 2;
}

/* func_0202242c (0x0202242c) is still provided by the delink: MWCC 2.0/sp1p5
 * will not reproduce its duplicate literal-pool slot plus explicit `add`.
 * See docs/functions/libs-nitrosdk-sdk-020222d8.md, "Hard list". */

extern u32 data_02156d30;
extern u32 data_0213d3e8[];
extern u32 data_0213d3dc[];
extern u32 data_0213d3f4[];
extern u32 data_0213d4a4[];
extern u32 data_0213d4b0[];
extern u32 data_0213d474[];
extern u32 data_0213d478[];
extern u32 data_0213d480[];
extern u32 data_0213d4bc[];
extern u32 data_0213d4c0[];
extern u32 data_0213d4c8[];
extern u32 data_0213d4ec[];
extern u32 data_0213d4f8[];
extern Unk0222d8FogCmd data_0213d404;
extern u32 data_0213d410;
extern void func_0200870c(u32 value, void *destination, u32 size);
extern void func_02008768(const void *source, void *destination, u32 size);
extern void func_02000f8c(void *argument);
extern void func_02001784(void *argument);
extern void func_02000ddc(void *argument);
extern void func_02000fb4(const void *source, void *destination);
extern void func_020017e4(void *destination, const void *source, void *other);
extern u32 func_02002380(const void *matrix);
extern void func_020023e0(const void *source, void *destination);

/** Send one GX command and its parameter words. Small blocks are appended to the
 *  shared submission buffer when it has room; otherwise the buffer is flushed
 *  (or waited on) and the command is written straight to the GX FIFO at
 *  0x04000400. The parameters are borrowed for the duration of the call. */
void func_020252fc(u32 command, const u32 *parameters, u32 count)
{
    if (data_02159c90.buffer != 0) {
        if (data_02159c90.busy != 0) {
            u32 index = data_02159c90.buffer[0];
            if (index + 1 + count <= 192) {
                data_02159c90.buffer[0] = index + 1;
                *(u32 *)((u8 *)data_02159c90.buffer + index * 4 + 4) = command;
                if (count == 0) return;
                func_02008768(parameters,
                              data_02159c90.buffer + 1 + data_02159c90.buffer[0],
                              count * 4);
                data_02159c90.buffer[0] += count;
                return;
            }
        }
        if (data_02159c90.buffer[0] != 0) {
            func_020251c8();
        } else if (data_02159c90.busy != 0) {
            func_02025224();
        }
    } else if (data_02159c90.busy != 0) {
        func_02025224();
    }
    *(volatile u32 *)0x04000400 = command;
    func_020086e4(parameters, (void *)0x04000400, count * 4);
}

/** Initialise the shared G3X state block data_02156d28: command defaults,
 *  projection/viewport constants, matrix tables and the two 0x1000-sized
 *  staging words, then run the three SDK setup helpers. Evidence: the fixed
 *  register-image constants written at the delinked offsets. */
void func_020222d8(void)
{
    data_02156d28.command = 0x17101610;
    data_02156d28.parameters[0] = 0;
    data_02156d28.parameters[17] = 2;
    data_02156d28.parameters[30] = 0x32323232;
    data_02156d28.parameters[35] = 0x60293130;
    data_02156d28.parameters[40] = 0x33333333;
    data_02156d28.parameters[45] = 0x002a1b19;

    func_02000f8c(data_02156d74);
    func_02001784(&data_02156d30);

    data_02156d28.parameters[31] = 0x2d8b62d8;
    data_02156d28.parameters[32] = 0x40000200;
    data_02156d28.parameters[33] = 0x800001ff;
    data_02156d28.parameters[34] = 0xc0080000;
    data_02156d28.parameters[36] = 0x4210c210;
    data_02156d28.parameters[37] = 0x4210c210;
    data_02156d28.parameters[38] = 0x001f008f;
    data_02156d28.parameters[39] = 0xbfff0000;
    data_02156d28.parameters[41] = 0x7fff;
    data_02156d28.parameters[42] = 0x4000001f;
    data_02156d28.parameters[43] = 0x800003e0;
    data_02156d28.parameters[44] = 0xc0007c00;
    data_02156d28.parameters[55] = 0;
    data_02156d28.parameters[56] = 0;
    data_02156d28.parameters[57] = 0;

    func_02000ddc(data_02156de4);

    data_02156d28.parameters[58] = 0x1000;
    data_02156d28.parameters[59] = 0x1000;
    data_02156d28.parameters[60] = 0x1000;
    data_02156d28.parameters[61] = 0;
    data_02156d28.flags = 0;
    data_02156d28.unk_100[82] = 0;
    data_02156d28.unk_100[81] = 0;
    data_02156d28.unk_100[80] = 0;
    data_02156d28.unk_100[85] = 0;
    data_02156d28.unk_100[83] = 0;
    data_02156d28.unk_100[84] = 0x1000;
    data_02156d28.unk_100[87] = 0;
    data_02156d28.unk_100[86] = 0;
    data_02156d28.unk_100[88] = 0xfffff000;
}

/** Build a 392-byte render state from a command block: copy the resource
 *  pointers, matrix bases, material/joint/visibility dispatch tables, optional
 *  binding slot and flag bits, then run the command callback and the shared
 *  command dispatcher. The scratch block belongs to the caller. */
void func_02022b3c(void *scratch, Unk0222d8RenderCmd *command)
{
    Unk0222d8RenderState *state = scratch;

    func_0200870c(0, state, 392);
    state->unk_c4 = 1;
    state->flags = 1;
    /* The target writes the base word and the command pointer with two separate
     * stores; the volatile qualifier prevents mwcc from folding them into stmia. */
    *(volatile u32 *)&state->unk_00 = command->unk_30
        ? (u32)command->unk_30
        : (u32)((u8 *)command->base + command->base->unk_04);
    *(u32 *)((u8 *)state + 4) = (u32)command;
    state->unk_d4 = command->base ? (u32)((u8 *)command->base + 64) : 0;
    {
        u32 value;
        if (command->base != 0 && command->base->unk_08 != 0)
            value = (u32)((u8 *)command->base + command->base->unk_08);
        else
            value = 0;
        state->unk_d8 = value;
        if (command->base != 0 && command->base->unk_0c != 0)
            value = (u32)((u8 *)command->base + command->base->unk_0c);
        else
            value = 0;
        state->unk_dc = value;
    }
    state->unk_e8 = data_0213d3e8[command->base->tag_15];
    state->unk_ec = data_0213d3dc[command->base->tag_15];
    state->unk_f0 = data_0213d3f4[command->base->tag_16];
    state->unk_e0 = command->base->unk_1c;
    state->unk_e4 = command->base->unk_20;

    if (command->unk_20 != 0 && command->unk_24 < 32) {
        state->arr_0c[command->unk_24] = (u32)command->unk_20;
        state->arr_8c[command->unk_24] = command->unk_25;
    }
    if (command->flags & 1) state->flags |= 0x80;
    if (command->flags & 2) state->flags |= 0x100;
    if (command->flags & 4) state->flags |= 0x200;
    if (command->flags & 8) state->flags |= 0x400;
    if (command->callback != 0) command->callback(state);
    func_02022af4((Unk0222d8Command *)state);
    command->flags &= ~1;
}

/** Texture SBC handler. Reads the texture index from the command cursor, runs
 *  the state-1/2/3 callback protocol, and either asks the render object to
 *  commit that texture through its bitset callback or writes the command bit
 *  directly. Always advances the cursor by three bytes. */
void func_02022e6c(Unk0222d8TexState *object)
{
    u32 state;
    u32 skip;
    u32 index;

    if (object->flags & 0x200) goto advance;

    index = object->command[1];
    object->current = index;
    object->flags |= 4;
    object->unk_b8 = &object->shared;
    state = object->callback != 0 ? object->state : 0;
    if (state == 1) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!skip) {
        Unk0222d8TexObject *obj = object->object;
        u32 table = obj->unk_18;

        if (!(table != 0 &&
              (obj->bits[index >> 5] & (1u << (index & 31))) != 0) ||
            obj->callback(object->unk_b8, table, index) == 0) {
            *object->unk_b8 = object->command[2] & 1;
        }
    }
    if (state == 2) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!skip) {
        if (*object->unk_b8 != 0) object->flags |= 1;
        else object->flags &= ~1;
    }
    if (state == 3) {
        object->flags &= ~0x40;
        object->callback(object);
    }
advance:
    object->command += 3;
}

/** Display-list SBC handler. Runs the state-1/3 callback protocol, decodes the
 *  byte offset and length around the cursor, forwards that block through
 *  func_02025248, and advances the cursor by nine bytes. */
void func_02024988(Unk0222d8DlState *object)
{
    u32 state;
    u32 skip;

    state = object->callback != 0 ? object->state : 0;
    if (state == 1) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!(object->flags & 0x100) && !skip) {
        u8 *command = object->command;
        u32 offset = command[1] | (command[2] << 8) |
                     (command[3] << 16) | (command[4] << 24);
        u32 size = command[5] | (command[6] << 8) |
                   (command[7] << 16) | (command[8] << 24);

        func_02025248(command + offset, size);
    }
    if (state == 3) {
        object->flags &= ~0x40;
        object->callback(object);
    }
    object->command += 9;
}

/** Matrix SBC handler. Pushes/updates the fog and texture-scale state, outputs
 *  the current projection and normal matrices, then emits the material matrix
 *  block selected by the shared G3X flags. The cursor advances by three bytes. */
void func_02024ad4(Unk0222d8MtxState *object)
{
    u32 state;
    u32 skip;
    u32 cmdValue;
    u32 word;
    u32 state2Value;
    u32 state3Value;
    u32 endValue;
    s32 matrix[9];
    u32 parameters[3];

    if (object->flags & 0x200) goto advance;
    if (!(object->flags & 1)) goto advance;

    if ((object->buf->unk_10 & 0xc0000000) != 0x80000000) {
        object->buf->unk_10 &= 0x3fffffff;
        object->buf->unk_10 |= 0x80000000;
        data_0213d404.value = object->buf->unk_10;
        func_020252fc(data_0213d404.command, &data_0213d410, 1);
    }
    cmdValue = 3;
    func_020252fc(16, &cmdValue, 1);
    state = object->callback != 0 ? object->state : 0;
    if (state == 1) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!skip) {
        u16 tex2 = object->buf->unk_2e;
        u16 tex = object->buf->unk_2c;

        parameters[0] = (u32)tex << 15;
        parameters[1] = (u32)-(s32)tex2 << 15;
        parameters[2] = 0x10000;
        func_020252fc(27, (const u32 *)parameters, 3);
        word = ((u32)(u16)(s16)(tex * 8)) | ((u32)(u16)(s16)(tex2 * 8) << 16);
        func_020252fc(34, (const u32 *)&word, 1);
    }
    if (state == 2) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!skip) {
        u32 index = object->command[1];
        Unk0222d8ShapeData *shape =
            (Unk0222d8ShapeData *)GetMaterialDataByIdx(object->res, index);

        {
            u16 flags = shape->flags;
            if (flags & 0x2000) {
                u8 *data = shape->data;
                if (!(flags & 2)) data += 8;
                if (!(flags & 4)) data += 4;
                if (!(flags & 8)) data += 8;
                func_020252fc(24, (const u32 *)data, 16);
            }
        }
    }
    if (state == 3) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!skip) {
        state2Value = 2;
        func_020252fc(16, &state2Value, 1);
        func_020253e0(0, matrix);
        state3Value = 3;
        func_020252fc(16, &state3Value, 1);
        if (data_02156d28.flags & 1) {
            func_020252fc(26, (const u32 *)data_02156d74, 9);
            func_020252fc(26, (const u32 *)data_02156de4, 9);
            func_020252fc(26, (const u32 *)matrix, 9);
        } else if (data_02156d28.flags & 2) {
            func_020252fc(26, (const u32 *)data_02156d74, 9);
            func_020252fc(26, (const u32 *)matrix, 9);
        } else {
            func_020252fc(26, (const u32 *)matrix, 9);
        }
    }
    endValue = 2;
    func_020252fc(16, &endValue, 1);
advance:
    object->command += 3;
}

/** Material SBC handler. Optionally emits the texture-coordinate command,
 *  rebuilds and submits the material matrix/light block, and finally emits the
 *  option-specific command. The cursor advance depends on `option`. */
void func_02023bc0(Unk0222d8MatState *object, u32 option)
{
    u32 valueA;
    u32 valueB;
    s32 matC[16];
    s32 matB[16];
    s32 matA[16];
    u32 count = 2;
    u32 state;
    u32 skip;
    volatile u32 *reg = (volatile u32 *)0x04000400;
    u32 *dstA = data_0213d4a4;
    u32 *dstB = data_0213d4b0;

    if (object->flags & 0x200) {
        if (option == 64 || option == 96) count++;
        if (option == 32 || option == 96) count++;
        object->command += count;
        return;
    }
    if (option == 64 || option == 96) {
        count++;
        if (!(object->flags & 0x100)) {
            if (option == 64)
                valueA = object->command[2];
            else
                valueA = object->command[3];
            func_020252fc(20, &valueA, 1);
        }
    }
    state = object->callback != 0 ? object->state : 0;
    if (state == 1) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!(object->flags & 0x100) && !skip) {
        func_020251c8();
        *reg = 0x00151110;
        *reg = 0;
        *reg = 0;
        while (func_02004210(matC) != 0) { }
        if (data_02156d28.flags & 1) {
            func_02000fb4(func_02022534(), matB);
            func_020017e4(matC, matB, matC);
        } else if (data_02156d28.flags & 2) {
            func_02000fb4(data_02156d74, matA);
            func_020017e4(matC, matA, matC);
        }
        dstA[0] = matC[12];
        dstA[1] = matC[13];
        dstA[2] = matC[14];
        dstB[0] = func_02002380(matC);
        dstB[1] = func_02002380(&matC[4]);
        dstB[2] = func_02002380(&matC[8]);
        if (data_02156d28.flags & 1) {
            *reg = 0x00171012;
            func_020086e4(data_0213d478, (void *)reg, 8);
            func_020086e4(func_0202256c(), (void *)reg, 48);
            *reg = 0x00001b19;
            func_020086e4(data_0213d480, (void *)reg, 60);
        } else if (data_02156d28.flags & 2) {
            *reg = 0x00171012;
            func_020086e4(data_0213d478, (void *)reg, 8);
            func_020086e4(func_02022498(), (void *)reg, 48);
            *reg = 0x00001b19;
            func_020086e4(data_0213d480, (void *)reg, 60);
        } else {
            func_020086e4(data_0213d474, (void *)reg, 72);
        }
    }
    if (state == 3) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (option == 32 || option == 96) {
        count++;
        if (!skip && !(object->flags & 0x100)) {
            valueB = object->command[2];
            func_020252fc(19, &valueB, 1);
        }
    }
    object->command += count;
}

/** Shape SBC handler. Mirrors the material handler but submits the shape
 *  matrix/light block and fixes up the normal-matrix sign depending on which
 *  matrix half is active. The cursor advance depends on `option`. */
void func_02023ec8(Unk0222d8ShpState *object, u32 option)
{
    u32 valueA;
    u32 valueB;
    s32 matC[16];
    s32 matB[16];
    s32 matA[16];
    u32 count = 2;
    u32 state;
    u32 skip;
    volatile u32 *reg = (volatile u32 *)0x04000400;
    u32 *dstA = data_0213d4ec;
    u32 *dstB = data_0213d4f8;
    u32 *cmdBuf = data_0213d4c8;

    if (object->flags & 0x200) {
        if (option == 64 || option == 96) count++;
        if (option == 32 || option == 96) count++;
        object->command += count;
        return;
    }
    if (option == 64 || option == 96) {
        count++;
        if (!(object->flags & 0x100)) {
            if (option == 64)
                valueA = object->command[2];
            else
                valueA = object->command[3];
            func_020252fc(20, &valueA, 1);
        }
    }
    state = object->callback != 0 ? object->state : 0;
    if (state == 1) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (!(object->flags & 0x100) && !skip) {
        func_020251c8();
        *reg = 0x00151110;
        *reg = 0;
        *reg = 0;
        while (func_02004210(matC) != 0) { }
        if (data_02156d28.flags & 1) {
            func_02000fb4(func_02022534(), matB);
            func_020017e4(matC, matB, matC);
        } else if (data_02156d28.flags & 2) {
            func_02000fb4(data_02156d74, matA);
            func_020017e4(matC, matA, matC);
        }
        dstA[0] = matC[12];
        dstA[1] = matC[13];
        dstA[2] = matC[14];
        dstB[0] = func_02002380(matC);
        dstB[1] = func_02002380(&matC[4]);
        dstB[2] = func_02002380(&matC[8]);
        if (matC[5] != 0 || matC[6] != 0) {
            func_020023e0(&matC[4], &cmdBuf[3]);
            cmdBuf[7] = (u32)-(s32)cmdBuf[5];
            cmdBuf[8] = cmdBuf[4];
        } else {
            func_020023e0(&matC[8], &cmdBuf[6]);
            cmdBuf[5] = (u32)-(s32)cmdBuf[7];
            cmdBuf[4] = cmdBuf[8];
        }
        if (data_02156d28.flags & 1) {
            *reg = 0x00171012;
            func_020086e4(data_0213d4c0, (void *)reg, 8);
            func_020086e4(func_0202256c(), (void *)reg, 48);
            *reg = 0x00001b19;
            func_020086e4(data_0213d4c8, (void *)reg, 60);
        } else if (data_02156d28.flags & 2) {
            *reg = 0x00171012;
            func_020086e4(data_0213d4c0, (void *)reg, 8);
            func_020086e4(func_02022498(), (void *)reg, 48);
            *reg = 0x00001b19;
            func_020086e4(data_0213d4c8, (void *)reg, 60);
        } else {
            func_020086e4(data_0213d4bc, (void *)reg, 72);
        }
    }
    if (state == 3) {
        object->flags &= ~0x40;
        object->callback(object);
        state = object->callback != 0 ? object->state : 0;
        skip = object->flags & 0x40;
    } else {
        skip = 0;
    }
    if (option == 32 || option == 96) {
        count++;
        if (!skip && !(object->flags & 0x100)) {
            valueB = object->command[2];
            func_020252fc(19, &valueB, 1);
        }
    }
    object->command += count;
}
