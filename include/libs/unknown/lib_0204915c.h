#ifndef LIB_0204915C_H
#define LIB_0204915C_H
#include "types.h"

/* Borrowed singleton prefix; only the three observed resource slots are exposed. */
typedef struct {
    u8 pad_0000[0x7990];
    void *unk_7990;
    void *unk_7994;
    void *unk_7998;
} Unk04915cState;

/* Borrowed callback input; bit 15 of the word at +0x40 gates setup. */
typedef struct {
    u8 pad_0000[0x40];
    u32 unk_0040_low : 15;
    u32 unk_0040_bit15 : 1;
    u32 unk_0040_high : 16;
} Unk04915cInput;

/* Runs fixed setup unless the input's bit 15 suppresses it; input is borrowed. */
void func_0204915c(const Unk04915cInput *input);
/* Returns the borrowed singleton resource slot at +0x7990. */
void *func_020491b4(void);
/* Reads table zero after biasing/clamping; the table must be nonempty. */
s32 func_020491cc(s32 index);
/* Reads table one with a nonnegative magnitude limit; the table must be nonempty. */
s32 func_02049220(s32 index, s32 limit);
/* Reads table two after biasing/clamping; the table must be nonempty. */
s32 func_02049298(s32 index);
/* Reads column code 12..14 of a clamped row; table three must be nonempty. */
s32 func_020492ec(s32 column, s32 row);
/* Returns a borrowed lookup result, retrying index zero if the first result is null. */
void *func_02049350(s32 index);

#endif
