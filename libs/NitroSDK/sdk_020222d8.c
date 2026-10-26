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
extern void func_020086e4(void *destination, u32 value, u32 size);
/** Geometry command submission: command id, parameter block, 32-bit word count. */
extern void func_020252fc(u32 command, const s32 *parameters, u32 count);
extern void func_020086a0(u32 value, void *destination, u32 size);
extern void func_02022b3c(void *scratch, void *command);
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
        func_02022b3c(data_02156f8c, object);
        return;
    }
    {
        u8 scratch[392];

        data_02156f8c = scratch;
        func_02022b3c(scratch, object);
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
        if (!(object->flags & 0x100)) func_020252fc(20, &value, 1);
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
        func_020252fc(0x1b, parameters, 3);
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

        func_020086e4(data_02159c90.buffer + 1, 0x4000400, count * 4);
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
        func_020252fc(*(const u32 *)source, (const s32 *)source + 1, (size >> 2) - 1);
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
