#include "libs/CRI/cri_0208d1fc.h"

/* The literals used by the ACSVHL entry points in this unit read
 * "E2003091209 ACSVHL_Create : Work pointor is NULL.",
 * "E2003091210 ACSVHL_Create : Work size is too small.",
 * "E2003091600 ACSVHL_Init : Already initialized." and
 * "E2003091601 ACSVHL_Init : Failed to initialize ACSFDR.", so the record is the
 * ACSVHL work area and func_0208d258 initialises its ACSFDR worker. The record
 * layout comes from the original ARM instructions. */

extern const char data_0214946c[];
extern const char data_021494a0[];
extern const char data_021494d4[];
extern const char data_02149504[];

extern void func_0208b494(const char *message);
extern s32 func_0208b8ec(void *channel);
extern s32 func_0208ba20(void *channel);
extern s32 func_0208ba58(void *channel);
extern s32 func_0208bac0(void *channel);
extern void func_020119c0(void *destination, s32 value, u32 size);
extern void *func_0208c7cc(void *buffer, u32 size);
extern void func_0208c814(void *handle);
extern s32 func_0208c828(void *handle);
extern s32 func_0208c830(void *handle);
extern s32 func_0208c850(void *handle, s32 start, s32 value, s32 arg4, s32 arg5);
extern void func_0208c8ec(void *handle);
extern s32 _s32_div_f(s32 numerator, s32 denominator);

void func_0208d500(AcsvhlWork *self);
void func_0208d548(AcsvhlWork *self, s8 state);
s32 func_0208d550(AcsvhlWork *self);
s32 func_0208d57c(AcsvhlWork *self);

/** Creates (reinitialises) an ACSVHL work area in caller-owned memory. A null
 * pointer logs the "Work pointor is NULL." literal at data_0214946c, and a size
 * below sizeof(AcsvhlWork) logs "Work size is too small." at data_021494a0; both
 * paths return null (`movs r4,r0; bne`, `cmp r1,#96; bcs`, `mov r0,#0`).
 * Otherwise the record is reset by func_0208d500 and returned. */
AcsvhlWork *func_0208d1fc(AcsvhlWork *work, u32 size)
{
    if (work == 0) {
        func_0208b494(data_0214946c);
        return 0;
    }
    if (size < sizeof(*work)) {
        func_0208b494(data_021494a0);
        return 0;
    }
    func_0208d500(work);
    return work;
}

/** Resets a record through func_0208d500, tolerating a null pointer (the
 * original's `cmp r0, #0; popeq {r3, pc}`). Evidence: func_0208d500 is the
 * routine Create calls after validating the work area, and the destroy path at
 * 0x0208af40 calls this entry after releasing the offset-4 handle with
 * func_0208d2d8. The caller owns `self`. */
void func_0208d244(AcsvhlWork *self)
{
    if (self != 0) {
        func_0208d500(self);
    }
}

/** Initialises the ACSFDR worker of a work area. An existing offset-4 handle
 * logs "Already initialized." at data_021494d4 and returns 0 (`ldr r0,[r4,#4];
 * cmp r0,#0; beq`). Otherwise the worker is created over the 68-byte buffer at
 * offset 8 with func_0208c7cc and stored at offset 4; a null result logs
 * "Failed to initialize ACSFDR." at data_02149504 and returns 0. On success the
 * worker is configured with func_0208c850(handle, 0, 0, 0, 0) (r1..r3 and the
 * stack word are all zero) and the call returns 1. */
s32 func_0208d258(AcsvhlWork *self)
{
    if (self->handle != 0) {
        func_0208b494(data_021494d4);
        return 0;
    }
    self->handle = func_0208c7cc(self->unk_008, sizeof(self->unk_008));
    if (self->handle == 0) {
        func_0208b494(data_02149504);
        return 0;
    }
    func_0208c850(self->handle, 0, 0, 0, 0);
    return 1;
}

/** Releases the worker handle with func_0208c814 and clears it. A record with
 * no handle returns immediately (`ldr r0,[r4,#4]; cmp r0,#0; popeq`), and the
 * null store at offset 4 is the original's `mov r0,#0; str r0,[r4,#4]`. */
void func_0208d2d8(AcsvhlWork *self)
{
    if (self->handle != 0) {
        func_0208c814(self->handle);
        self->handle = 0;
    }
}

/** Clears the offset 0x4c word. The original is `mov r1,#0; str r1,[r0,#76]`,
 * so the field is a plain u32 and the function has no result. */
void func_0208d2fc(AcsvhlWork *self)
{
    self->unk_04c = 0;
}

/** Returns the offset 0x4c word (`ldr r0,[r0,#76]`), the value zeroed by
 * func_0208d2fc. No name is inferred because the instructions only establish a
 * getter/setter pair. */
u32 func_0208d308(AcsvhlWork *self)
{
    return self->unk_04c;
}

/** Returns the signed state byte at offset 0x50. The original uses LDRSB, so
 * the field is signed; func_0208d330 compares it against 0..3 and
 * func_0208d548 writes it. */
s8 func_0208d310(AcsvhlWork *self)
{
    return self->unk_050;
}

/** Tail-forwards the offset-4 worker handle to func_0208c830. The original is
 * `ldr ip,[pc,#4]; ldr r0,[r0,#4]; bx ip` with the func_0208c830 literal, and
 * that helper returns the word at handle + 0x1c, so the result is a u32. */
u32 func_0208d318(AcsvhlWork *self)
{
    return func_0208c830(self->handle);
}

/** Stores the caller's pointer in offset 0. The original is `str r1,[r0]`;
 * func_0208d330 reads this field as the base of a four-entry array, so the
 * stored value is a pointer. */
void func_0208d328(AcsvhlWork *self, void *value)
{
    self->unk_000 = value;
}

/** Advances the ACSVHL fade state machine and always finishes by calling
 * func_0208c8ec on the offset-4 worker handle. The loop scans the four channel
 * pointers in offset 0 (`ldr r0,[r4]; ldr r8,[r0,r6,lsl #2]`, counter r6 with
 * bound 4): a channel must be non-null, pass func_0208b8ec, report state 2 from
 * func_0208bac0, and then func_0208ba58 selects the channel kind. The original
 * jump table has five entries (bound `cmp r0,#4; addls pc,pc,r0,lsl #2`) where
 * kinds 0, 3 and 4 fall straight back to the loop and kinds 1/2 call
 * func_0208ba20 and raise the `any` flag (r7) when it returns 0.
 *
 * The signed state byte at offset 0x50 then selects one of four transitions
 * (bound `cmp r0,#3; addls`): state 0 starts a fade-in with the negative 0x5c
 * range and the 0x54 value and moves to 1; state 1 either starts the fade-out
 * ramp from func_0208d550 or, once func_0208c828 reports completion, moves to
 * 2; state 2 starts a fade with start 0 and the 0x58 value and moves to 3;
 * state 3 either starts a fade-in from func_0208d57c or moves back to 0 when
 * func_0208c828 reports completion. Each func_0208c850 call passes two trailing
 * zero arguments (r3 and the stack word). */
void func_0208d330(AcsvhlWork *self)
{
    s32 i;
    s32 any = 0;

    for (i = 0; i < 4; i++) {
        void *channel = ((void **)self->unk_000)[i];

        if (channel == 0)
            continue;
        if (func_0208b8ec(channel) == 0)
            continue;
        if (func_0208bac0(channel) != 2)
            continue;
        switch (func_0208ba58(channel)) {
        case 0:
            break;
        case 1:
        case 2:
            if (func_0208ba20(channel) == 0)
                any = 1;
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }

    switch (self->unk_050) {
    case 0:
        if (any == 1) {
            func_0208c850(self->handle, -(s32)self->unk_05c, self->unk_054, 0, 0);
            func_0208d548(self, 1);
        }
        break;
    case 1:
        if (any == 0) {
            func_0208c850(self->handle, 0, func_0208d550(self), 0, 0);
            func_0208d548(self, 3);
        } else if (func_0208c828(self->handle) == 0) {
            func_0208d548(self, 2);
        }
        break;
    case 2:
        if (any == 0) {
            func_0208c850(self->handle, 0, self->unk_058, 0, 0);
            func_0208d548(self, 3);
        }
        break;
    case 3:
        if (any == 1) {
            func_0208c850(self->handle, -(s32)self->unk_05c, func_0208d57c(self), 0, 0);
            func_0208d548(self, 1);
        } else if (func_0208c828(self->handle) == 0) {
            func_0208d548(self, 0);
        }
        break;
    }
    func_0208c8ec(self->handle);
}

/** Resets a work area to its defaults: clears offsets 0 and 4, zeroes the
 * 68-byte buffer at offset 8 with func_020119c0, clears the word at 0x4c and
 * the state byte at 0x50, and writes 30, 60 and 120 to offsets 0x54, 0x58 and
 * 0x5c (`mov r0,#30/#60/#120; str`). The original stores offset 4 after setting
 * up the memset arguments, which is why the two stores are not adjacent. */
void func_0208d500(AcsvhlWork *self)
{
    self->unk_000 = 0;
    self->handle = 0;
    func_020119c0(self->unk_008, 0, sizeof(self->unk_008));
    self->unk_04c = 0;
    self->unk_050 = 0;
    self->unk_054 = 30;
    self->unk_058 = 60;
    self->unk_05c = 120;
}

/** Writes the signed state byte at offset 0x50 (`strb r1,[r0,#80]`); this is
 * the setter paired with func_0208d310 and is used by func_0208d330's state
 * machine. */
void func_0208d548(AcsvhlWork *self, s8 state)
{
    self->unk_050 = state;
}

/** Returns the fade-in ramp value derived from the worker progress. The
 * original loads the 0x54 interval into r4, asks func_0208c830 for the progress
 * of the offset-4 handle, multiplies both (`mul r0,r4,r0`), negates the 0x5c
 * range (`ldr r1,[r5,#92]; rsb r1,r1,#0`), divides with _s32_div_f and returns
 * interval - quotient (`sub r0,r4,r0`). The negative divisor is kept because
 * the original explicitly negates the field before the divide. */
s32 func_0208d550(AcsvhlWork *self)
{
    s32 interval = self->unk_054;
    s32 progress = func_0208c830(self->handle);

    return interval - interval * progress / -(s32)self->unk_05c;
}

/** Returns the fade-in ramp value for the 0x58 step, mirroring func_0208d550:
 * the original asks func_0208c830 for the progress, multiplies it by the 0x58
 * value (`mul r0,r2,r0`), negates the 0x5c range, divides with _s32_div_f and
 * subtracts the quotient from the 0x54 hold value. */
s32 func_0208d57c(AcsvhlWork *self)
{
    s32 progress = func_0208c830(self->handle);
    s32 interval = self->unk_058;

    return self->unk_054 - interval * progress / -(s32)self->unk_05c;
}
