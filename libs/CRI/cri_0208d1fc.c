#include "libs/CRI/cri_0208d1fc.h"

/* The literals used by the still-delinked Create entry point at 0x0208d1fc
 * read "E2003091209 ACSVHL_Create : Work pointor is NULL." and
 * "E2003091210 ACSVHL_Create : Work size is too small.", so the record is the
 * ACSVHL work area. The eight accessors below only touch the fields listed in
 * the header; their structure comes from the original ARM instructions. */

extern void func_0208d500(AcsvhlWork *self);
extern void func_0208c814(void *handle);
extern u32 func_0208c830(void *handle);

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

/** Writes the signed state byte at offset 0x50 (`strb r1,[r0,#80]`); this is
 * the setter paired with func_0208d310 and is used by func_0208d330's state
 * machine. */
void func_0208d548(AcsvhlWork *self, s8 state)
{
    self->unk_050 = state;
}
