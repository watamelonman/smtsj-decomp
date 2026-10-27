#include "types.h"

/* Shared navigation state returned by func_020ba90c.
 *
 * Field meanings come from the original instruction streams in this unit and
 * from the callers of the accessors:
 *   +0x00  state: -1 before the first init, then the value passed to
 *          func_020ba964 (the update helpers compare it with 0, 1 and 2)
 *   +0x04  upper limit for the current value
 *   +0x08  current value (advanced by the update helpers)
 *   +0x0c  flag: set by func_020babb4, cleared by func_020babc8 and read by
 *          func_020baba4 (its caller restores and then clears it)
 *   +0x10  flag: set by func_020bab90, cleared by func_020ba964
 *   +0x14  saved current value, restored into +0x08 by func_020bab64
 *   +0x18  flag: set by func_020bab64 and read by func_020bab80
 * Only these words are touched by this translation unit; the field names stay
 * neutral because no public source or string identifies the structure. */
typedef struct Unk020ba90cState {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Unk020ba90cState;

extern Unk020ba90cState data_02176b8c;

/* Plays a sound effect; the argument is the effect index. */
extern void Unk0a0ce4_Unk_0a0da4(s32 value);

/* ARM 0x020ba90c: returns the address of the shared navigation state. The
 * literal pool entry names data_02176b8c. */
Unk020ba90cState *func_020ba90c(void)
{
    return &data_02176b8c;
}

/* ARM 0x020ba918: resets the shared state to its uninitialised form: the
 * state word becomes -1 and the limit, current value, flags and saved value
 * are cleared. */
void func_020ba918(void)
{
    Unk020ba90cState *state = func_020ba90c();

    state->unk_00 = -1;
    state->unk_08 = 0;
    state->unk_04 = 0;
    state->unk_0c = 0;
    state->unk_14 = 0;
    state->unk_18 = 0;
}

/* ARM 0x020ba944: reports whether the state has been initialised, i.e. the
 * state word at +0x00 is no longer the -1 sentinel. */
s32 func_020ba944(void)
{
    return func_020ba90c()->unk_00 != -1;
}

/* ARM 0x020ba990: marks the shared state uninitialised (state = -1). */
void func_020ba990(void)
{
    func_020ba90c()->unk_00 = -1;
}

/* ARM 0x020bab40: plays sound effect 0 and moves the current value to the
 * last entry (limit - 1). */
void func_020bab40(void)
{
    Unk020ba90cState *state = func_020ba90c();

    Unk0a0ce4_Unk_0a0da4(0);
    state->unk_08 = state->unk_04 - 1;
}

/* ARM 0x020bab64: restores the saved current value from +0x14 and raises
 * the +0x18 flag. */
void func_020bab64(void)
{
    Unk020ba90cState *state = func_020ba90c();

    state->unk_08 = state->unk_14;
    state->unk_18 = 1;
}

/* ARM 0x020bab80: reads the +0x18 flag; callers use it to choose the mode and
 * to gate menu progress. */
s32 func_020bab80(void)
{
    return func_020ba90c()->unk_18;
}

/* ARM 0x020bab90: raises the +0x10 flag. */
void func_020bab90(void)
{
    func_020ba90c()->unk_10 = 1;
}

/* ARM 0x020baba4: reads the +0x0c flag; a nonzero result tells the caller to
 * restore its menu state. */
s32 func_020baba4(void)
{
    return func_020ba90c()->unk_0c;
}

/* ARM 0x020babb4: raises the +0x0c flag. */
void func_020babb4(void)
{
    func_020ba90c()->unk_0c = 1;
}

/* ARM 0x020babc8: clears the +0x0c flag. */
void func_020babc8(void)
{
    func_020ba90c()->unk_0c = 0;
}

/* ARM 0x020babdc: reads the current value at +0x08; callers publish it or
 * copy it into their own work object. */
s32 func_020babdc(void)
{
    return func_020ba90c()->unk_08;
}

/* ARM 0x020babec: stores a new upper limit for the current value. */
void func_020babec(s32 limit)
{
    func_020ba90c()->unk_04 = limit;
}

/* ARM 0x020bac34: stores a value to restore later into +0x14. */
void func_020bac34(s32 value)
{
    func_020ba90c()->unk_14 = value;
}

/* ARM 0x020bac48: saves the last entry (limit - 1) as the restore value. */
void func_020bac48(void)
{
    func_020bac34(func_020ba90c()->unk_04 - 1);
}

/* ARM 0x020bac60: reports whether the current value is the last entry
 * (limit - 1). */
s32 func_020bac60(void)
{
    Unk020ba90cState *state = func_020ba90c();

    return state->unk_08 == state->unk_04 - 1;
}
