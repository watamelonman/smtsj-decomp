#include "libs/NitroSDK/sdk_020535cc.h"

/* Borrowed records: the updater at 0x02053640 stores held, complemented and
 * newly pressed bits at +0/+2/+4. Initialization advances by 0x56 bytes. */
typedef struct Unk020535ccInput {
    u16 held;
    u16 complemented;
    u16 pressed;
    u16 remaining[40];
} Unk020535ccInput;

/* Borrowed state words used by 0x0205397c and 0x020539dc; provider-owned. */
typedef struct Unk020535ccState {
    u32 state;
    u32 fields04[3];
    u32 reload;
    u32 dispatch14;
    u32 dispatch18;
    u32 dispatch1c;
} Unk020535ccState;

extern Unk020535ccInput data_021605e4[5];
extern Unk020535ccState data_02160794;

/* Tests held bits, as established by the input updater's +0 halfword store. */
int func_020537b8(int device, u32 mask)
{
    int bits = data_021605e4[device].held;
    bits &= mask;
    return bits != 0;
}

/* Tests complemented held bits, stored at +2 by 0x02053640. */
int func_020537dc(int device, u32 mask)
{
    int bits = ((Unk020535ccInput *)((u32)data_021605e4 + device * sizeof(Unk020535ccInput)))->complemented;
    bits &= mask;
    return bits != 0;
}

/* Tests rising input bits: 0x02053640 stores current & ~previous at +4. */
int func_02053800(int device, u32 mask)
{
    int bits = ((Unk020535ccInput *)((u32)data_021605e4 + device * sizeof(Unk020535ccInput)))->pressed;
    bits &= mask;
    return bits != 0;
}

/* Sets the reload word copied into the countdown by 0x02053a28. */
void func_020539cc(u32 value)
{
    data_02160794.reload = value;
}

/* Reads the state word assigned values 0..3 by 0x020539dc. */
u32 func_02053bc8(void)
{
    return data_02160794.state;
}

/* Sets the +0x14 flag tested before the provider sequence at 0x02053a78. */
void func_02053bd8(u32 value)
{
    data_02160794.dispatch14 = value;
}

/* Sets the +0x18 flag tested before the provider call at 0x02053ac0. */
void func_02053be8(u32 value)
{
    data_02160794.dispatch18 = value;
}

/* Sets the +0x1c flag tested before callback dispatch at 0x02053adc. */
void func_02053bf8(u32 value)
{
    data_02160794.dispatch1c = value;
}
