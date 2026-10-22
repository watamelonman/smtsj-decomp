/* src/game/unit_02047fb4.c: battle-script handlers for the talk-tone and effect work objects. */
#include "types.h"

int Unk09d060_Unk_09d13c(void);
int Unk044904_Unk_045048(void);
int Unk044904_Unk_045080(void);
int Unk044904_Get_data_0215ee98(void);
int func_02045ca8(void);
int func_0204b054(void *work);
int func_02015118(const char *name);
void func_0204f188(int layer, u32 id, int slot, const void *name, int flag);
void Unk044904_Unk_045bd0(int flag);
void Unk0f81a4_Unk_0f81a4(void *work);
void Unk0f7eb4_Unk_0f8078(void *work);
void func_02065b74(void);
void func_0202b730(int mode);
void func_020450b8(void);

/* Work object layout shared by the two state blocks at manager +0x7804 (returned by
 * Unk044904_Unk_045048, the talk-tone state) and +0x78e4 (returned by
 * Unk044904_Unk_045080, the effect state). The flags word at +0x44 is tested one bit at
 * a time, +0x54 starts a NUL-terminated effect name, and Unk0f7eb4_Unk_0f8078 resets
 * +0x48..+0x50, the byte at +0x54 and the word at +0x84 of this same layout. */
typedef struct Unk047fb4State {
    u8 pad_0000[0x44];
    u32 flag_0044_0 : 1;
    u32 flag_0044_1 : 1;
    u32 pad_0044_2 : 11;
    u32 flag_0044_13 : 1;
    u32 pad_0044_14 : 18;
    u32 unk_0048;
    u32 unk_004c;
    u32 unk_0050;
    u8 name_0054;
    u8 pad_0055[0x0f];
    u16 unk_0064;
    u8 pad_0066[0x22];
    u32 unk_0088;
} Unk047fb4State;

/* Ends the talk-tone request tracked by the +0x7804 work object. When its bit-13 flag is
 * set, clears the pending words at +0x48, +0x4c and +0x64, clears the flag and reports
 * state 2 through arg0. Always returns 1. */
int func_02047fb4(u16 *arg0)
{
    Unk047fb4State *state = (Unk047fb4State *)Unk044904_Unk_045048();
    if (state->flag_0044_13) {
        state->unk_0048 = 0;
        state->unk_004c = 0;
        state->unk_0064 = 0;
        state->flag_0044_13 = 0;
        *arg0 = 2;
    }
    return 1;
}

/* Advances the talk-tone script for the +0x7804 work object. An active wait check
 * (func_02045ca8) or a clear bit-0 flag selects state 4 (arg0[1] = 2); otherwise the
 * manager's bit-16 word is cleared and state 3 is reported when bit 1 is clear (running
 * the tone stop first) or state 2 when it is set. All paths end in the common teardown. */
int func_02047ffc(u16 *arg0)
{
    Unk047fb4State *state = (Unk047fb4State *)Unk044904_Unk_045048();
    u32 *flags;
    if (func_02045ca8() != 0) {
        arg0[0] = 4;
        arg0[1] = 2;
    } else if (state->flag_0044_0 != 0) {
        if (state->flag_0044_1 != 0) {
            FIELD(u32, Unk044904_Get_data_0215ee98(), 0x40) &= ~0x10000;
            arg0[0] = 2;
        } else {
            flags = (u32 *)((u8 *)Unk044904_Get_data_0215ee98() + 0x40);
            Unk044904_Unk_045bd0(0);
            *flags &= ~0x10000;
            arg0[0] = 3;
        }
    } else {
        arg0[0] = 4;
        arg0[1] = 2;
    }
    func_02065b74();
    func_0202b730(0);
    func_020450b8();
    return 1;
}

/* Starts the battle effect work. When Unk09d060_Unk_09d13c reports the required mode
 * active, the +0x78e4 work object is handed to Unk0f81a4_Unk_0f81a4 (which forwards its
 * +0x84 field to func_0204afe0) and state 2 is reported; otherwise returns 0. */
int Unk047fb4_Unk_0480b4(void)
{
    Unk047fb4State *state;
    if (Unk09d060_Unk_09d13c() == 0) {
        return 0;
    }
    state = (Unk047fb4State *)Unk044904_Unk_045080();
    Unk0f81a4_Unk_0f81a4(state);
    return 2;
}

/* Drives the battle effect work object at +0x78e4. func_0204b054 advances the work's
 * +0x18 state and returns 0 only for state 3, 1 for every other state; on that state-3
 * path this reports script state 3 when an action is queued (+0x4c, or +0x88 == 3) and 4
 * otherwise, optionally requests the manager's bit-7 effect flag, resets the work and
 * returns 1. On the nonzero path it waits (returning 0) until the queued word at +0x48
 * is set, then spawns the effect named at +0x54 and reports state 2. */
int func_020480d8(u16 *arg0)
{
    Unk047fb4State *state = (Unk047fb4State *)Unk044904_Unk_045080();
    if (func_0204b054(state) == 0) {
        if (state->unk_004c != 0 || state->unk_0088 == 3) {
            if (state->unk_0050 != 0) {
                FIELD(u32, Unk044904_Get_data_0215ee98(), 0x40) |= 0x80;
            }
            arg0[0] = 3;
        } else {
            arg0[0] = 4;
        }
        func_02065b74();
        Unk0f7eb4_Unk_0f8078(state);
        return 1;
    }
    if (state->unk_0048 != 0) {
        if (func_02015118((const char *)&state->name_0054) != 0) {
            func_0204f188(0, 0xffff, 6, &state->name_0054, 1);
        }
        arg0[0] = 2;
        return 1;
    }
    return 0;
}

/* Cancels a queued effect on the +0x78e4 work object: drops the stored effect name and
 * the queued word, then reports state 2. Safe to call when nothing is queued. */
int Unk047fb4_Unk_0481a0(u16 *arg0)
{
    Unk047fb4State *state = (Unk047fb4State *)Unk044904_Unk_045080();
    if (state->unk_0048 != 0) {
        state->name_0054 = 0;
        state->unk_0048 = 0;
        *arg0 = 2;
    }
    return 1;
}
