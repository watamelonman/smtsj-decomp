#include "libs/NitroSDK/sdk_020222d8.h"

extern Unk0222d8State data_02156d28;
extern Unk0222d8Vector data_02156e08;
extern s32 data_02156e58[12];
extern s32 data_02156e88[12];
extern Unk0222d8Submission data_02159c90;
/** Recompute the two matrices from shared state (observed calls at 020224dc). */
extern void func_020224dc(void);

/** Evidence: 02022468 copies three words only for non-null input; clears mask 0xa4. */
void func_02022468(const Unk0222d8Vector *value)
{
    if (value == 0) return;
    data_02156e08 = *value;
    data_02156d28.flags &= ~0xa4;
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
