/* Matched functions at 0x02052b58-0x02052dd8: helpers for two SDK state
 * blocks and the 3D command port. The delink still supplies the rest of the
 * TU. See docs/functions/libs-nitrosdk-sdk-02052b58.md. */
#include "libs/NitroSDK/sdk_02052b58.h"

/* Two 32-bit words at data_0215f4a0; func_02052b7c writes both with one STM.
 * The two words have no observed consumer in this TU beyond the getters below,
 * so their fields stay unnamed. */
typedef struct Unk0215f4a0Pair {
    u32 first;
    u32 second;
    u8 counters[24];
    u8 values[24];
} Unk0215f4a0Pair;

extern Unk0215f4a0Pair data_0215f4a0;

/* Byte arrays indexed by the byte accessors below. data_0215f4c0 is the
 * 24-byte block at data_0215f4a0 + 0x20 in the original BSS layout. */
extern u8 data_0215f4a8[];
extern u8 data_0215f4c0[];

/* Provider-owned state block; only its instruction-established prefix is
 * exposed through Unk02052b58State. */
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
Unk02052b58State *func_02052c30(void)
{
    return (Unk02052b58State *)data_021438c0;
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

extern u32 data_021437e0[];
extern void func_02007e94(void);
extern int func_02052cb0(int mode);
extern void func_020574d4(void);
extern void func_02052c3c(void);

/* Returns table word index; the unsigned comparison at 0x02052b60 calls
 * func_02007e94 for indices outside 0..5 before continuing the lookup. */
u32 func_02052b58(u32 index)
{
    if (index >= 6) {
        func_02007e94();
    }
    return data_021437e0[index];
}

/* Clears the 24 bytes at pair +8, as shown by the STRB loop at 0x02052bb8. */
void func_02052bac(void)
{
    int i;
    for (i = 0; i < 24; i++) {
        data_0215f4a0.counters[i] = 0;
    }
}

/* Fills the 24 bytes at pair +0x20; STRB truncates value to eight bits. */
void func_02052bd4(u8 value)
{
    int i;
    for (i = 0; i < 24; i++) {
        data_0215f4a0.values[i] = value;
    }
}

/* Toggles state +8 by logical negation (LDR/CMP/conditional MOV at
 * 0x02052d1c); any nonzero input becomes zero. */
void func_02052d14(void)
{
    Unk02052b58State *state = func_02052c30();
    state->flag = !state->flag;
}

/* Mode-one guard precedes the provider, toggle and GX setup calls;
 * evidence is the ordered BL sequence at 0x02052d3c..0x02052d50. */
void func_02052d34(void)
{
    if (!func_02052cb0(1)) {
        return;
    }
    func_020574d4();
    func_02052d14();
    func_02052c3c();
}

/* Mode-zero guard precedes the provider, toggle and GX reset calls;
 * evidence is the ordered BL sequence at 0x02052d60..0x02052d74. */
void func_02052d58(void)
{
    if (!func_02052cb0(0)) {
        return;
    }
    func_020574d4();
    func_02052d14();
    func_02052c94();
}

/* A nonnull caller-owned pair array resets the index and stores count and
 * pointer at +4/+12 (conditional STM/STR at 0x02052d94..0x02052d98).
 * A null pointer leaves all fields unchanged; storage must outlive use. */
void func_02052d7c(s8 *pairs, int count)
{
    Unk02052b58State *state = func_02052c30();
    if (pairs) {
        state->index = 0;
        state->count = count;
        state->pairs = pairs;
    }
}

/* Returns the borrowed two-byte record at index, or null for sentinel -1.
 * Evidence: CMP -1 and conditional base + index*2 at 0x02052de0..0x02052df4.
 * The caller/provider must maintain a valid index and backing array. */
s8 *func_02052dd8(void)
{
    Unk02052b58State *state = func_02052c30();
    if (state->index == -1) {
        return 0;
    }
    return state->pairs + state->index * 2;
}
