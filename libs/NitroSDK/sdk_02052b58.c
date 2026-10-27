/* Functions at 0x02052b7c-0x02052c94: small accessors for two SDK state
 * blocks and the 3D command port. The delink still supplies the rest of the
 * TU. See docs/functions/libs-nitrosdk-sdk-02052b58.md. */
#include "types.h"

/* Two 32-bit words at data_0215f4a0; func_02052b7c writes both with one STM.
 * The two words have no observed consumer in this TU beyond the getters below,
 * so their fields stay unnamed. */
typedef struct Unk0215f4a0Pair {
    u32 first;
    u32 second;
} Unk0215f4a0Pair;

extern Unk0215f4a0Pair data_0215f4a0;

/* Byte arrays indexed by the byte accessors below. data_0215f4c0 is the
 * 24-byte block at data_0215f4a0 + 0x20 in the original BSS layout. */
extern u8 data_0215f4a8[];
extern u8 data_0215f4c0[];

/* State block returned by func_02052c30; the rest of the TU treats it as a
 * struct whose first two words are initialized to -1. Keep it opaque here so
 * this card does not guess a layout another card must implement. */
extern u8 data_021438c0[];

/* Stores the caller's two words into the pair at data_0215f4a0. Evidence: one
 * literal load and `stm r2, {r0, r1}` at 0x02052b7c. */
void func_02052b7c(u32 first, u32 second)
{
    data_0215f4a0.first = first;
    data_0215f4a0.second = second;
}

/* Returns the first stored word. Evidence: `ldr r0, [r0]` on data_0215f4a0. */
u32 func_02052b8c(void)
{
    return data_0215f4a0.first;
}

/* Returns the second stored word. Evidence: `ldr r0, [r0, #4]` on
 * data_0215f4a0. */
u32 func_02052b9c(void)
{
    return data_0215f4a0.second;
}

/* Returns the unsigned byte at data_0215f4c0[index]. Evidence: `ldrb` from
 * data_0215f4c0 at 0x02052bf8; the index is used without scaling or a bounds
 * check. */
u8 func_02052bf8(int index)
{
    return data_0215f4c0[index];
}

/* Adds two to the unsigned byte at data_0215f4a8[index]. Evidence: `ldrb`,
 * `add #2`, `strb` all using data_0215f4a8 and index directly. */
void func_02052c08(int index)
{
    data_0215f4a8[index] += 2;
}

/* Returns the unsigned byte at data_0215f4a8[index]. Evidence: `ldrb` from
 * data_0215f4a8 at 0x02052c20. */
u8 func_02052c20(int index)
{
    return data_0215f4a8[index];
}

/* Returns the address of the state block at data_021438c0. Evidence: the
 * original body is a single literal load of data_021438c0 followed by bx lr;
 * the block holds the strings WH_SYSSTATE_IDLE and WH_SYSSTATE_BUSY at +0x30,
 * but no function in this card consumes them, so the name stays neutral. */
void *func_02052c30(void)
{
    return data_021438c0;
}

/* Writes 2 to the 3D command port at 0x04000440 and 1 to 0x04000448.
 * Evidence: one literal load of 0x04000440, then `str #2, [r1]` and
 * `str #1, [r1, #8]`. The original has no other side effect. */
void func_02052c94(void)
{
    volatile u32 *commands = (volatile u32 *)0x04000440;
    commands[0] = 2;
    commands[2] = 1;
}
