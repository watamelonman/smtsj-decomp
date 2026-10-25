#include "types.h"

/* Offsets are established by the loads and stores in the original callbacks. */
typedef struct Unk0ff030Work {
    s32 unk_00, unk_04, unk_08, unk_0c, unk_10, unk_14, unk_18, unk_1c;
    s32 unk_20, unk_24, unk_28, unk_2c, unk_30, unk_34, unk_38, unk_3c;
} Unk0ff030Work;

typedef void (*Unk0ff030Callback)(Unk0ff030Work *);
/* Callback slots follow the pointer stores in func_020ff248; slot 8 is untouched. */
typedef struct Unk0ff030Descriptor {
    s32 size, flags, unk_08;
    Unk0ff030Callback update, next, unk_14, draw, release;
    void (*message)(Unk0ff030Work *, const void *);
} Unk0ff030Descriptor;

extern void func_02057e18(s32 value);
extern void func_02057ddc(s32 value);
extern void func_02057524(s32 value);
extern void func_02057eb8(s32 value);
extern void func_020572d8(void);
extern void func_0205ddb4(s32 handle);
extern void func_020629c4(s32 handle);
extern s32 func_02052728(void);
extern void CampStatus_Unk_0dd308(s32 *, s32, s32, s32 *, s32 *);
extern u16 *Unk02e000_Thunk_0202e788(void);
extern void CampStatus_Unk_0dde3c(s32, s32, s32, s32 *, s32);
extern void func_02060b60(s32, s32, s32, s32, s32, s32);
extern void func_0205de40(s32, s32, s32, s32, s32, float, float, s32, float, s32);
extern void func_020ff29c(Unk0ff030Work *);
extern void func_020ff638(Unk0ff030Work *);
extern void func_020ffa9c(Unk0ff030Work *, const void *);
void Unk0ff030_Unk_0ff0ec(Unk0ff030Work *work);
void func_020ff120(Unk0ff030Work *work);
void func_020ff5c0(Unk0ff030Work *work);
void Unk0ff030_Unk_0ffa60(Unk0ff030Work *work);

/* Empty callback: the original consists solely of a return instruction. */
void Unk0ff030_Nop_0ff030(void) { }

/* Submit the two operations only in an active state; state 2 consumes +0x20.
 * Evidence: original branches at 020ff044..020ff06c and call arguments. */
void func_020ff034(Unk0ff030Work *work)
{
    s32 order;
    if (work->unk_14 == 0) return;
    if (work->unk_14 == 2) {
        if (work->unk_20 == 0) return;
        work->unk_20 = 0;
    }
    Unk0ff030_Unk_0ff0ec(work);
    order = work->unk_1c;
    func_02060b60(1, work->unk_04, work->unk_0c + 14, work->unk_10 + 116, 0, order + 1);
    func_0205de40(2, work->unk_08, 0, work->unk_0c, work->unk_10, 1.0f, 1.0f, 0, 1.0f, order);
    func_020ff120(work);
}

/* Set the shared call state and apply +0x18 when nonnegative (original loads). */
void Unk0ff030_Unk_0ff0ec(Unk0ff030Work *work)
{
    func_02057e18(31);
    func_02057ddc(-1);
    func_02057524(4);
    if (work->unk_18 < 0) return;
    func_02057eb8(work->unk_18);
}

/* Restore the optional +0x18 setting and finish the operation, per call sequence. */
void func_020ff120(Unk0ff030Work *work)
{
    if (work->unk_18 >= 0) func_02057eb8(-1);
    func_020572d8();
}

/* Populate the 64-byte work descriptor; original relocations identify the slots. */
void func_020ff248(Unk0ff030Descriptor *desc)
{
    desc->size = 64;
    desc->flags = 0;
    desc->update = func_020ff5c0;
    desc->next = func_020ff29c;
    desc->unk_14 = 0;
    desc->draw = func_020ff638;
    desc->release = Unk0ff030_Unk_0ffa60;
    desc->message = func_020ffa9c;
}

/* Advance state 4 once the three observed counters reach their thresholds. */
void func_020ff5c0(Unk0ff030Work *work)
{
    if (work->unk_24 != 4) return;
    if (func_02052728() != 0) return;
    CampStatus_Unk_0dd308(&work->unk_30, -15, 1, &work->unk_34, &work->unk_38);
    if (work->unk_30 > 0) return;
    if (work->unk_34 >= 10 && work->unk_38 >= 10) work->unk_24 = work->unk_28;
}

/* Release the two handles; +4 is passed through even when zero in the original. */
void Unk0ff030_Unk_0ffa60(Unk0ff030Work *work)
{
    if (work->unk_00 != 0) {
        func_0205ddb4(work->unk_00);
        work->unk_00 = 0;
    }
    func_020629c4(work->unk_04);
    if (work->unk_04 != 0) work->unk_04 = 0;
}

/* Copy four borrowed halfwords into call-local words, replacing zero with one;
 * the original passes this array to CampStatus_Unk_0dde3c with count four. */
void func_020ffbcc(s32 handle)
{
    u16 *values = Unk02e000_Thunk_0202e788();
    s32 words[4];
    s32 i;
    words[0] = values[0];
    words[1] = values[1];
    words[2] = values[2];
    words[3] = values[3];
    for (i = 0; i < 4; i++) {
        if (words[i] == 0) words[i] = 1;
    }
    CampStatus_Unk_0dde3c(handle, 6, 0, words, 4);
}
