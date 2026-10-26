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

/* func_0202242c (0x0202242c) is still provided by the delink: MWCC 2.0/sp1p5
 * will not reproduce its duplicate literal-pool slot plus explicit `add`.
 * See docs/functions/libs-nitrosdk-sdk-020222d8.md, "Hard list". */
