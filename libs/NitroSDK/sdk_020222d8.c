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
extern void func_02022b3c(Unk0222d8RenderState *state, Unk0222d8RenderCmd *command);
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
        func_02022b3c((Unk0222d8RenderState *)data_02156f8c, (Unk0222d8RenderCmd *)object);
        return;
    }
    {
        u8 scratch[392];

        data_02156f8c = scratch;
        func_02022b3c((Unk0222d8RenderState *)scratch, (Unk0222d8RenderCmd *)object);
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

/** Evidence: 020251c8 waits when busy, then copies the staged block to the GX
 *  FIFO and clears its count. */
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
 *  projection/viewport constants, matrix tables, the three 0x1000 staging
 *  sizes in parameters[58..60], the 0x1000 tail word, the zeroed tail words
 *  and the -0x1000 sentinel, then run the three SDK setup helpers. Evidence:
 *  the fixed register-image constants written at the delinked offsets. */
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
void func_02022b3c(Unk0222d8RenderState *state, Unk0222d8RenderCmd *command)
{
    func_0200870c(0, state, 392);
    state->unk_c4 = 1;
    state->flags = 1;
    /* The target writes the base word and the command pointer with two separate
     * stores; the volatile qualifier on the first prevents mwcc from folding them
     * into one stmia. */
    *(volatile u32 *)&state->unk_00 = command->unk_30
        ? (u32)command->unk_30
        : (u32)((u8 *)command->base + command->base->unk_04);
    state->cmd = command;
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
 *  matrix half is active. The cursor advance depends on `option`.
 *  This duplication of 02023bc0 is deliberate: the two are distinct SBC
 *  dispatch targets, so their instruction sequences must not be factored into
 *  a shared helper. */
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

/** Callback fills one joint result using a node-local animation index. */
typedef int (*Unk0222d8JointCallback)(Unk0222d8JointResult *, Unk0222d8Node *, u32);
extern s32 func_0200219c(s32 numerator, s32 denominator);
extern void func_020022fc(const Unk0222d8Vector *, const Unk0222d8Vector *, Unk0222d8Vector *);
extern void func_0200870c(u32 value, void *destination, u32 size);
extern void func_020086bc(const void *source, void *destination, u32 size);
/** Clear caller-owned words using the SDK fast word fill (value precedes destination). */
static inline void ClearSdkWords(void *destination, u32 size)
{
    func_0200870c(0, destination, size);
}
/** The existing scale helper takes three consecutive fixed-point words. */
static inline void BlendScaleVector(Unk0222d8Vector *destination, const Unk0222d8Vector *source,
                                    s32 ratio, u32 one)
{
    func_02022610((s32 *)destination, (const s32 *)source, ratio, one);
}
/** Evidence: NitroSystem g3d/src/anm.c NNSi_G3dAnmBlendJnt. Normalises
 *  positive animation weights and reconstructs an orthogonal rotation basis. */
int func_02022680(Unk0222d8JointResult *pResult, Unk0222d8Node *pAnmObj, u32 nodeID)
{

    if (!pAnmObj) {
        return 0;
    }

    if (!pAnmObj->next) {
        u32 dataIdx;
        if (nodeID < pAnmObj->count) {
            dataIdx = pAnmObj->entries[nodeID];
            if ((dataIdx & (0x100 | 0x200)) == 0x100) {
                Unk0222d8JointCallback func = (Unk0222d8JointCallback)pAnmObj->callback;

                if (func) {
                    (*func)(pResult, pAnmObj, dataIdx & 0xff);
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        Unk0222d8Node *p;
        Unk0222d8JointResult r;
        s32 sumOfRatio = 0;
        Unk0222d8Node *pLastAnmObj;
        int numBlend = 0;
        int i1 = 0;
        Unk0222d8Vector keepAxisX;
        Unk0222d8Vector keepAxisZ;

        p = pAnmObj;
        do {
            if (nodeID < p->count) {
                u32 dataIdx = p->entries[nodeID];
                if ((dataIdx & (0x100 | 0x200)) == 0x100) {

                    if (p->unk_04 > 0x1000)
                        sumOfRatio += 0x1000;
                    else if (p->unk_04 > 0)
                        sumOfRatio += p->unk_04;

                    pLastAnmObj = p;
                    ++numBlend;
                }
            }
            p = p->next;
        } while (p);

        if (sumOfRatio == 0) {
            return 0;
        }

        if (numBlend == 1) {
            Unk0222d8JointCallback func = (Unk0222d8JointCallback)pLastAnmObj->callback;
            u32 dataIdx = pLastAnmObj->entries[nodeID];

            if (func) {
                (*func)(pResult, pLastAnmObj, dataIdx & 0xff);
                return 1;
            } else {
                return 0;
            }
        }

        ClearSdkWords(pResult, sizeof(*pResult));
        pResult->flag = (u32)-1;

        p = pAnmObj;
        do {
            if (nodeID < p->count) {
                u32 dataIdx = p->entries[nodeID];
                if ((dataIdx & (0x100 | 0x200)) == 0x100 && (p->unk_04 > 0)) {
                    s32 ratio;
                    Unk0222d8JointCallback func = (Unk0222d8JointCallback)p->callback;

                    if (func) {
                        (*func)(&r, p, dataIdx & 0xff);

                        if (i1 == 0) {
                            func_020086bc(&r.rot[0], &keepAxisX, sizeof(Unk0222d8Vector));
                            func_020086bc(&r.rot[6], &keepAxisZ, sizeof(Unk0222d8Vector));
                        }

                        if (sumOfRatio != 0x1000) {
                            ratio = func_0200219c(p->unk_04, sumOfRatio);
                        } else {
                            ratio = p->unk_04;
                        }

                        BlendScaleVector(&pResult->scale, &r.scale, ratio, r.flag & 1);

                        BlendScaleVector(&pResult->scaleEx0, &r.scaleEx0, ratio, r.flag & 8);

                        BlendScaleVector(&pResult->scaleEx1, &r.scaleEx1, ratio, r.flag & 16);

                        if (!(r.flag & 4)) {
                            pResult->trans.x += (s32)((s64)ratio * r.trans.x >> 12);
                            pResult->trans.y += (s32)((s64)ratio * r.trans.y >> 12);
                            pResult->trans.z += (s32)((s64)ratio * r.trans.z >> 12);
                        }

                        if (!(r.flag & 2)) {
                            pResult->rot[0] += ratio * r.rot[0] >> 12;
                            pResult->rot[1] += ratio * r.rot[1] >> 12;
                            pResult->rot[2] += ratio * r.rot[2] >> 12;
                            pResult->rot[3] += ratio * r.rot[3] >> 12;
                            pResult->rot[4] += ratio * r.rot[4] >> 12;
                            pResult->rot[5] += ratio * r.rot[5] >> 12;
                        } else {
                            pResult->rot[0] += ratio;
                            pResult->rot[4] += ratio;
                        }

                        pResult->flag &= r.flag;
                    }
                }
            }

            p = p->next;
            ++i1;

        } while (p);

        func_020022fc((Unk0222d8Vector *)&pResult->rot[0], (Unk0222d8Vector *)&pResult->rot[3],
                      (Unk0222d8Vector *)&pResult->rot[6]);

        if ((pResult->rot[0] == 0) && (pResult->rot[1] == 0) && (pResult->rot[2] == 0)) {

            func_020086bc(&keepAxisX, &pResult->rot[0], sizeof(Unk0222d8Vector));
        } else {
            func_020023e0((Unk0222d8Vector *)&pResult->rot[0], (Unk0222d8Vector *)&pResult->rot[0]);
        }

        if ((pResult->rot[6] == 0) && (pResult->rot[7] == 0) && (pResult->rot[8] == 0)) {

            func_020086bc(&keepAxisZ, &pResult->rot[6], sizeof(Unk0222d8Vector));
        } else {
            func_020023e0((Unk0222d8Vector *)&pResult->rot[6], (Unk0222d8Vector *)&pResult->rot[6]);
        }

        func_020022fc((Unk0222d8Vector *)&pResult->rot[6], (Unk0222d8Vector *)&pResult->rot[0],
                      (Unk0222d8Vector *)&pResult->rot[3]);

        return 1;
    }
}

extern Unk0222d8MaterialResult data_02156f90[];
extern void func_02008a84(void *matrix);
/** Test a resource-index bit; each bitset stores 32 entries per word. */
static inline int CheckBit(const u32 *bits, u32 index)
{
    return bits[index >> 5] & (1U << (index & 31));
}
/** Mark an entry cached for the current draw operation. */
static inline void SetBit(u32 *bits, u32 index) { bits[index >> 5] |= 1U << (index & 31); }
/** Callback stage A establishes timing, then rechecks it after user code. */
static inline int CheckCallbackA(Unk0222d8SbcState *rs, u8 cmd, u32 *timing)
{
    *timing = rs->cbVecFunc[cmd] ? rs->cbVecTiming[cmd] : 0;
    if (*timing == 1) {
        rs->flag &= ~0x40;
        rs->cbVecFunc[cmd](rs);
        *timing = rs->cbVecFunc[cmd] ? rs->cbVecTiming[cmd] : 0;
        return rs->flag & 0x40;
    }
    return 0;
}
/** Callback stage B may replace both the selected result and final timing. */
static inline int CheckCallbackB(Unk0222d8SbcState *rs, u8 cmd, u32 *timing)
{
    if (*timing == 2) {
        rs->flag &= ~0x40;
        rs->cbVecFunc[cmd](rs);
        *timing = rs->cbVecFunc[cmd] ? rs->cbVecTiming[cmd] : 0;
        return rs->flag & 0x40;
    }
    return 0;
}
/** Callback stage C returns the final skip bit without changing timing. */
static inline int CheckCallbackC(Unk0222d8SbcState *rs, u8 cmd, u32 timing)
{
    if (timing == 3) {
        rs->flag &= ~0x40;
        rs->cbVecFunc[cmd](rs);
        return rs->flag & 0x40;
    }
    return 0;
}
/** Material dictionary records borrow storage from their resource block. */
static inline Unk0222d8MaterialData *GetSbcMaterial(const Unk0222d8ResourceMat *mat, u32 index)
{
    return (Unk0222d8MaterialData *)GetMaterialDataByIdx(mat, index);
}
/** Node entries carry byte offsets from the node dictionary base. */
static inline Unk0222d8NodeData *GetSbcNode(const Unk0222d8ResourceDict *dict, u32 index)
{
    Unk0222d8ResourceEntry *entry;
    if (dict != 0) {
        entry = (Unk0222d8ResourceEntry *)GetResourceDataByIdx(dict, index);
        if (entry != 0)
            return (Unk0222d8NodeData *)((u8 *)dict + entry->offset);
    }
    return 0;
}
/** The first word is the packed GX opcode; the rest are its parameter block. */
static inline void SendCommandBlock(const u32 *command, u32 count)
{
    func_020252fc(command[0], command + 1, count - 1);
}
/** Evidence: NitroSystem g3d/src/sbc.c NNSi_G3dFuncSbc_MAT_InternalDefault.
 *  Original read-only color masks are at 0x0212b390; outputs may be cached. */
void func_020230b4(Unk0222d8SbcState *rs, u32 opt, const Unk0222d8MaterialData *mat, u32 idxMat)
{
    static const u32 matColorMask_[8] = {0x00000000, 0x00007fff, 0x7fff0000, 0x7fff7fff,
                                         0x00008000, 0x0000ffff, 0x7fff8000, 0x7fffffff};
    int cbFlag;
    u32 cbTiming;

    rs->currentMat = (u8)idxMat;
    rs->flag |= 8;

    rs->pMatAnmResult = &rs->tmpMatAnmResult;

    cbFlag = CheckCallbackA(rs, 4, &cbTiming);

    if (!cbFlag) {
        Unk0222d8MaterialResult *pResult;
        if (rs->pRenderObj->recMatAnm && !(rs->flag & 0x80)) {
            pResult = (rs->pRenderObj->recMatAnm + idxMat);
        } else {
            if ((opt == 0x20 || opt == 0x40) && CheckBit(&rs->isMatCached[0], idxMat)) {

                if (rs->pRenderObj->recMatAnm) {
                    pResult = (rs->pRenderObj->recMatAnm + idxMat);
                } else {
                    pResult = &data_02156f90[idxMat];
                }
            } else {
                if (rs->pRenderObj->recMatAnm) {
                    SetBit(&rs->isMatCached[0], idxMat);
                    pResult = (rs->pRenderObj->recMatAnm + idxMat);
                } else if (opt == 0x40) {
                    SetBit(&rs->isMatCached[0], idxMat);
                    pResult = &data_02156f90[idxMat];
                } else {
                    pResult = &rs->tmpMatAnmResult;
                }

                {
                    pResult->flag = (u32)0;
                    if (GetSbcMaterial(rs->pResMat, idxMat)->flag & 0x20) {
                        pResult->flag |= 0x20;
                    }
                }
                {
                    u32 mask = matColorMask_[(mat->flag >> 6) & 7];
                    pResult->prmMatColor0 =
                        (data_02156d28.parameters[36] & ~mask) | (mat->diffAmb & mask);
                }

                {

                    u32 mask = matColorMask_[(mat->flag >> 9) & 7];
                    pResult->prmMatColor1 =
                        (data_02156d28.parameters[37] & ~mask) | (mat->specEmi & mask);
                }

                pResult->prmPolygonAttr = (data_02156d28.parameters[38] & ~mat->polyAttrMask) |
                                          (mat->polyAttr & mat->polyAttrMask);

                pResult->prmTexImage = mat->texImageParam;
                pResult->prmTexPltt = mat->texPlttBase;

                if (mat->flag & 1) {
                    const u8 *p = (const u8 *)mat + sizeof(Unk0222d8MaterialData);

                    if (!(mat->flag & 2)) {
                        const s32 *p_s32 = (const s32 *)p;

                        pResult->scaleS = *(p_s32 + 0);
                        pResult->scaleT = *(p_s32 + 1);
                        p += 2 * sizeof(s32);
                    } else {
                        pResult->flag |= 1;
                    }

                    if (!(mat->flag & 4)) {
                        const s16 *p_s16 = (const s16 *)p;

                        pResult->sinR = *(p_s16 + 0);
                        pResult->cosR = *(p_s16 + 1);
                        p += 2 * sizeof(s16);
                    } else {
                        pResult->flag |= 2;
                    }

                    if (!(mat->flag & 8)) {
                        const s32 *p_s32 = (const s32 *)p;

                        pResult->transS = *(p_s32 + 0);
                        pResult->transT = *(p_s32 + 1);
                    } else {
                        pResult->flag |= 4;
                    }

                    pResult->flag |= 8;
                }

                if (rs->pRenderObj->anmMat &&
                    CheckBit(&rs->pRenderObj->hintMatAnmExist[0], idxMat)) {

                    (void)(*rs->pRenderObj->funcBlendMat)(pResult, rs->pRenderObj->anmMat, idxMat);
                }

                if (pResult->flag & (8 | 16)) {
                    pResult->origWidth = mat->origWidth;
                    pResult->origHeight = mat->origHeight;
                    pResult->magW = mat->magW;
                    pResult->magH = mat->magH;
                }
            }
        }
        rs->pMatAnmResult = pResult;
    }

    cbFlag = CheckCallbackB(rs, 4, &cbTiming);

    if (!cbFlag) {
        Unk0222d8MaterialResult *pResult;

        pResult = rs->pMatAnmResult;

        if (pResult->prmPolygonAttr & 0x1f0000) {
            if (pResult->flag & 0x20) {
                pResult->prmPolygonAttr &= ~0x1f0000;
            }

            rs->flag &= ~2;

            if (!(rs->flag & 0x100)) {
                u32 cmd[7];

                cmd[0] = 0x293130;
                cmd[1] = pResult->prmMatColor0;
                cmd[2] = pResult->prmMatColor1;
                cmd[3] = pResult->prmPolygonAttr;
                cmd[4] = 0x2b2a;
                cmd[5] = pResult->prmTexImage;
                cmd[6] = pResult->prmTexPltt;

                SendCommandBlock(&cmd[0], 7);

                if (pResult->flag & (8 | 16)) {

                    (*rs->funcTexMtx)(pResult);
                }
            }
        } else {
            rs->flag |= 2;
        }
    }

    (void)CheckCallbackC(rs, 4, cbTiming);
}

/** Evidence: NitroSystem g3d/src/sbc.c NNSi_G3dFuncSbc_NODEDESC.
 *  Original pivot-index table is at 0x0212b3b0; cursor length follows options. */
void func_02023760(Unk0222d8SbcState *rs, u32 opt)
{
    u32 cmdLen = 4;
    static const u8 pivotUtil_[9][4] = {// forge:data-ok NitroSystem rotation pivot indices
                                        {4, 5, 7, 8}, {3, 5, 6, 8}, {3, 4, 6, 7},

                                        {1, 2, 7, 8}, {0, 2, 6, 8}, {0, 1, 6, 7},

                                        {1, 2, 4, 5}, {0, 2, 3, 5}, {0, 1, 3, 4}};
    int cbFlag;
    u32 cbTiming;
    u32 idxNode = *(rs->c + 1);
    rs->currentNodeDesc = (u8)idxNode;
    rs->flag |= 16;

    if (rs->flag & 0x400) {
        if (opt == 0x40 || opt == 0x60) {
            ++cmdLen;
        }

        if (opt == 0x20 || opt == 0x60) {
            ++cmdLen;

            if (!(rs->flag & 0x100)) {
                u32 idxMtxDest = *(rs->c + 4);

                func_020252fc(20, &idxMtxDest, 1);
            }
        }
        rs->c += cmdLen;
        return;
    }

    {
        if (opt == 0x40 || opt == 0x60) {
            u32 idxMtxSrc;

            ++cmdLen;
            if (opt == 0x40) {
                idxMtxSrc = *(rs->c + 4);
            } else {
                idxMtxSrc = *(rs->c + 5);
            }

            if (!(rs->flag & 0x100)) {
                func_020252fc(20, &idxMtxSrc, 1);
            }
        }
    }

    rs->pJntAnmResult = &rs->tmpJntAnmResult;

    cbFlag = CheckCallbackA(rs, 6, &cbTiming);

    if (!cbFlag) {
        Unk0222d8JointResult *pAnmResult;
        int isUseRecordData;

        if (rs->pRenderObj->recJntAnm) {

            pAnmResult = (rs->pRenderObj->recJntAnm + idxNode);
            if (!(rs->flag & 0x80)) {
                isUseRecordData = 1;
            } else {
                isUseRecordData = 0;
            }
        } else {
            isUseRecordData = 0;
            pAnmResult = &rs->tmpJntAnmResult;
        }

        if (!isUseRecordData) {
            pAnmResult->flag = (u32)0;

            if (rs->pRenderObj->anmJnt &&
                (*rs->pRenderObj->funcBlendJnt)(pAnmResult, rs->pRenderObj->anmJnt, idxNode)) {
                ;
            } else {
                const Unk0222d8NodeData *pNd = GetSbcNode(rs->pResNodeInfo, idxNode);
                const u8 *p = (const u8 *)pNd + sizeof(Unk0222d8NodeData);

                if (pNd->flag & 1) {
                    pAnmResult->flag |= 4;
                } else {
                    const s32 *p_s32 = (const s32 *)p;

                    pAnmResult->trans.x = *(p_s32 + 0);
                    pAnmResult->trans.y = *(p_s32 + 1);
                    pAnmResult->trans.z = *(p_s32 + 2);
                    p += 3 * sizeof(s32);
                }

                if (pNd->flag & 2) {
                    pAnmResult->flag |= 2;
                } else {
                    if (pNd->flag & 8) {

                        s32 A = *(s16 *)(p + 0);
                        s32 B = *(s16 *)(p + 2);
                        u32 idxPivot = (u32)((pNd->flag & 0xf0) >> 4);

                        func_02008a84(pAnmResult->rot);

                        pAnmResult->rot[idxPivot] = (pNd->flag & 0x100) ? -0x1000 : 0x1000;

                        pAnmResult->rot[pivotUtil_[idxPivot][0]] = A;
                        pAnmResult->rot[pivotUtil_[idxPivot][1]] = B;

                        pAnmResult->rot[pivotUtil_[idxPivot][2]] = (pNd->flag & 0x200) ? -B : B;

                        pAnmResult->rot[pivotUtil_[idxPivot][3]] = (pNd->flag & 0x400) ? -A : A;

                        p += 2 * sizeof(s16);
                    } else {

                        const s16 *pp = (const s16 *)p;
                        pAnmResult->rot[0] = pNd->_00;
                        pAnmResult->rot[1] = *(pp + 0);
                        pAnmResult->rot[2] = *(pp + 1);
                        pAnmResult->rot[3] = *(pp + 2);
                        pAnmResult->rot[4] = *(pp + 3);
                        pAnmResult->rot[5] = *(pp + 4);
                        pAnmResult->rot[6] = *(pp + 5);
                        pAnmResult->rot[7] = *(pp + 6);
                        pAnmResult->rot[8] = *(pp + 7);

                        p += 8 * sizeof(s16);
                    }
                }

                (*rs->funcJntScale)(pAnmResult, (s32 *)p, rs->c, pNd->flag);
            }
        }
        rs->pJntAnmResult = pAnmResult;
    }

    cbFlag = CheckCallbackB(rs, 6, &cbTiming);

    if (!cbFlag) {
        if (!(rs->flag & 0x100)) {

            (*rs->funcJntMtx)(rs->pJntAnmResult);
        }
    }

    rs->pJntAnmResult = 0;

    cbFlag = CheckCallbackC(rs, 6, cbTiming);

    if (opt == 0x20 || opt == 0x60) {
        ++cmdLen;

        if (!cbFlag) {
            if (!(rs->flag & 0x100)) {
                u32 idxMtxDest = *(rs->c + 4);

                func_020252fc(19, &idxMtxDest, 1);
            }
        }
    }

    rs->c += cmdLen;
}

/** Row-major fixed-point matrix views used by the hardware readback helpers. */
typedef struct Unk0222d8Matrix43 {
    s32 m[4][3];
} Unk0222d8Matrix43;
/** Clip-matrix cache entry uses the hardware's four-word row stride. */
typedef struct Unk0222d8Matrix44 {
    s32 m[4][4];
} Unk0222d8Matrix44;
/** Normal matrices have no translation row. */
typedef struct Unk0222d8Matrix33 {
    s32 m[3][3];
} Unk0222d8Matrix33;
/** Inverse envelope matrices are supplied by the model resource. */
typedef struct Unk0222d8Envelope {
    Unk0222d8Matrix43 invM;
    Unk0222d8Matrix33 invN;
} Unk0222d8Envelope;
/** Each cached position/normal matrix pair occupies 100 bytes. */
typedef struct Unk0222d8EnvelopeCache {
    Unk0222d8Matrix44 M;
    Unk0222d8Matrix33 N;
} Unk0222d8EnvelopeCache;
/** Normal-cache alias starts 64 bytes into the same cache array. */
typedef struct Unk0222d8NormalCache {
    Unk0222d8Matrix33 N;
    u8 stride[64];
} Unk0222d8NormalCache;
extern Unk0222d8EnvelopeCache data_02158390[];
extern Unk0222d8NormalCache data_021583d0[];
extern void func_02003eb8(const Unk0222d8Matrix43 *);
extern void func_02003ed4(const Unk0222d8Matrix33 *);
extern void func_02003e9c(const Unk0222d8Matrix43 *);
/** Evidence: NitroSystem g3d/src/sbc.c NNSi_G3dFuncSbc_NODEMIX.
 *  The stream supplies three-byte stack-slot/joint/weight records; weights
 *  are expanded to 20.12 before accumulating cached envelope matrices. */
void func_0202422c(Unk0222d8SbcState *rs)
{
    s64 w = 0;
    const Unk0222d8Envelope *evpMtx =
        (const Unk0222d8Envelope *)((u8 *)rs->pRenderObj->resMdl +
                                    rs->pRenderObj->resMdl->ofsEvpMtx);
    u32 numMtx = *(rs->c + 2);
    u8 *p = rs->c + 3;

    {
        u32 i;
        struct {
            Unk0222d8Matrix43 M;
            Unk0222d8Matrix33 N;
        } sum;
        Unk0222d8Matrix44 *pX;
        Unk0222d8Matrix33 *pY;

        ClearSdkWords(&sum, sizeof(sum));
        func_020251c8();

        *(volatile u32 *)0x04000440 = 0;
        *(volatile u32 *)0x0400044c = 1;
        *(volatile u32 *)0x04000454 = 0;
        *(volatile u32 *)0x04000440 = 2;

        for (i = 0; i < numMtx; ++i) {
            u32 idxJnt = *(p + 1);
            int evpCached = CheckBit(&rs->isEvpCached[0], idxJnt);

            pX = &data_02158390[idxJnt].M;
            if (!evpCached) {
                SetBit(&rs->isEvpCached[0], idxJnt);

                *(volatile u32 *)0x04000450 = *p;
                *(volatile u32 *)0x04000440 = 1;
                func_02003eb8(&evpMtx[idxJnt].invM);
            }

            if (i != 0) {
                sum.N.m[0][0] += (w * pY->m[0][0]) >> 12;
                sum.N.m[0][1] += (w * pY->m[0][1]) >> 12;
                sum.N.m[0][2] += (w * pY->m[0][2]) >> 12;

                sum.N.m[1][0] += (w * pY->m[1][0]) >> 12;
                sum.N.m[1][1] += (w * pY->m[1][1]) >> 12;
                sum.N.m[1][2] += (w * pY->m[1][2]) >> 12;

                sum.N.m[2][0] += (w * pY->m[2][0]) >> 12;
                sum.N.m[2][1] += (w * pY->m[2][1]) >> 12;
                sum.N.m[2][2] += (w * pY->m[2][2]) >> 12;
            }

            if (!evpCached) {
                while (func_02004210((s32 *)pX))
                    ;
                *(volatile u32 *)0x04000440 = 2;
                func_02003ed4(&evpMtx[idxJnt].invN);
            }

            w = *(p + 2) << 4;

            sum.M.m[0][0] += (w * pX->m[0][0]) >> 12;
            sum.M.m[0][1] += (w * pX->m[0][1]) >> 12;
            sum.M.m[0][2] += (w * pX->m[0][2]) >> 12;

            sum.M.m[1][0] += (w * pX->m[1][0]) >> 12;
            sum.M.m[1][1] += (w * pX->m[1][1]) >> 12;
            sum.M.m[1][2] += (w * pX->m[1][2]) >> 12;

            sum.M.m[2][0] += (w * pX->m[2][0]) >> 12;
            sum.M.m[2][1] += (w * pX->m[2][1]) >> 12;
            sum.M.m[2][2] += (w * pX->m[2][2]) >> 12;

            sum.M.m[3][0] += (w * pX->m[3][0]) >> 12;
            sum.M.m[3][1] += (w * pX->m[3][1]) >> 12;
            sum.M.m[3][2] += (w * pX->m[3][2]) >> 12;

            p += 3;
            pY = &data_021583d0[idxJnt].N;

            if (!evpCached) {
                while (func_02004240((s32 *)pY))
                    ;
            }
        }
        sum.N.m[0][0] += (w * pY->m[0][0]) >> 12;
        sum.N.m[0][1] += (w * pY->m[0][1]) >> 12;
        sum.N.m[0][2] += (w * pY->m[0][2]) >> 12;

        sum.N.m[1][0] += (w * pY->m[1][0]) >> 12;
        sum.N.m[1][1] += (w * pY->m[1][1]) >> 12;
        sum.N.m[1][2] += (w * pY->m[1][2]) >> 12;

        sum.N.m[2][0] += (w * pY->m[2][0]) >> 12;
        sum.N.m[2][1] += (w * pY->m[2][1]) >> 12;
        sum.N.m[2][2] += (w * pY->m[2][2]) >> 12;

        func_02003e9c((const Unk0222d8Matrix43 *)&sum.N);
        *(volatile u32 *)0x04000440 = 1;
        func_02003e9c(&sum.M);
        *(volatile u32 *)0x04000440 = 0;
        *(volatile u32 *)0x04000450 = 1;
        *(volatile u32 *)0x04000440 = 2;
    }

    *(volatile u32 *)0x0400044c = *(rs->c + 1);
    rs->c += 3 + *(rs->c + 2) * 3;
}
