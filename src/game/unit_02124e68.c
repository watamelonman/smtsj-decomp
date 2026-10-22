#include "types.h"

/* Callback state: offsets follow the loads/stores in 02124e9c and 02124f4c. */
typedef struct Unk124e68Obj {
    u32 unk_00;
    u32 unk_04;
    s8 unk_08;
    u8 pad_09[3];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
} Unk124e68Obj;

typedef void (*Unk124e68Callback)(Unk124e68Obj *);
extern Unk124e68Obj *data_02176e88;
extern Unk124e68Obj *func_020611dc(Unk124e68Callback, Unk124e68Callback,
    Unk124e68Callback, void (*)(void), u32, u32, u32, u32);
extern void func_02057524(u32);
extern void func_02057534(void);
extern void func_02057e18(u32);
extern void func_02057fd8(void);
extern void func_02057dcc(u32, u32, u32, u32);
extern void func_02057b50(u32, u32, u32, u32, u32);
extern void func_02057df8(void);
extern void func_02057e30(u32);

void func_02124f4c(Unk124e68Obj *state);
void Unk124e68_Unk_124fbc(Unk124e68Obj *state);
void Unk124e68_Unk_124ff0(Unk124e68Obj *state);
void Unk124e68_Nop_124f48(void);
void func_02125024(u32 mode, u32 value, u32 arg2);

/* Set the fields consumed by the callbacks, resetting their interval counter. */
void Unk124e68_Set(u32 a, u32 b, u32 c)
{
    data_02176e88->unk_00 = a;
    data_02176e88->unk_18 = b;
    data_02176e88->unk_19 = c;
    data_02176e88->unk_1a = 0;
}

/* Register four callbacks with a 28-byte state; allocation failure leaves no state. */
void func_02124e9c(void)
{
    Unk124e68Obj *state;
    data_02176e88 = 0;
    state = func_020611dc(func_02124f4c, Unk124e68_Unk_124fbc,
        Unk124e68_Unk_124ff0, Unk124e68_Nop_124f48, 28, 4, 101, 1);
    if (state == 0) {
        return;
    }
    state->unk_00 = 0;
    state->unk_04 = 0;
    state->unk_08 = 0;
    state->unk_0c = 1;
    state->unk_10 = 1;
    state->unk_14 = 7;
    state->unk_18 = 0;
    state->unk_1a = 0;
    state->unk_19 = 3;
    data_02176e88 = state;
}

/* The fourth registered callback has no work or side effects. */
void Unk124e68_Nop_124f48(void) { }

/* Advance the signed byte on each interval, clamping toward either 0 or 31. */
void func_02124f4c(Unk124e68Obj *state)
{
    if (state->unk_1a >= state->unk_18) {
        if (state->unk_04 == 0) {
            state->unk_08 -= state->unk_19;
            if (state->unk_08 < 0) {
                state->unk_08 = 0;
            }
        } else {
            state->unk_08 += state->unk_19;
            if (state->unk_08 > 31) {
                state->unk_08 = 31;
            }
        }
        state->unk_1a = 0;
    } else {
        state->unk_1a++;
    }
}

/* Invoke the shared operation only when the first callback enable word is set. */
void Unk124e68_Unk_124fbc(Unk124e68Obj *state)
{
    if (state->unk_0c == 0) {
        return;
    }
    func_02057524(state->unk_14);
    func_02125024(state->unk_00, (u8)state->unk_08, 0x16);
    func_02057534();
}

/* Invoke the shared operation only when the second callback enable word is set. */
void Unk124e68_Unk_124ff0(Unk124e68Obj *state)
{
    if (state->unk_10 == 0) {
        return;
    }
    func_02057524(state->unk_14);
    func_02125024(state->unk_00, (u8)state->unk_08, 0x16);
    func_02057534();
}

/* For nonzero values, bracket a 256 by 192 operation with the observed state calls. */
void func_02125024(u32 mode, u32 value, u32 arg2)
{
    if (value == 0) {
        return;
    }
    func_02057e18(value);
    func_02057fd8();
    if (mode == 0) {
        func_02057dcc(255, 255, 255, 255);
    } else {
        func_02057dcc(-1, -1, -1, -1);
    }
    func_02057b50(0, 0, 256, 192, arg2);
    func_02057df8();
    func_02057e30(0);
    func_02057e18(31);
}
