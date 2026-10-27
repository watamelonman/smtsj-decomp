#include "types.h"

/* Shared record for the CRI wrappers in this unit. The literal stored at
 * offset 0 by func_0208d1e0 is 0212ed98, the table of wrapper entry points, so
 * field 0 is the object's dispatch table. The wrapper chains use the word at
 * offset 4 as the handle passed to the underlying CRI worker; callers own the
 * record and the worker handle (evidence: the LDR [r0, #4] in every wrapper
 * and the 0212ed98 stores at 0208d1e0). */
typedef struct Cri0208cf94Object {
    const void *vtable;
    void *handle;
    void *unk_08;
} Cri0208cf94Object;

/* Borrowed creation descriptor read by func_0208cff0 (0208cff4..0208d03c):
 * field_00 is forwarded to func_0207e7ec and copied into the record's offset 8;
 * a non-zero field_08 selects func_0207eb44 instead. Only these two fields are
 * observed, so unk_04 stays opaque and the provider keeps ownership. */
typedef struct Cri0208cf94Source {
    void *field_00;
    u32 unk_04;
    s32 field_08;
} Cri0208cf94Source;

extern const char data_021493c4[];
extern const char data_021493f8[];
extern const char data_02149430[];

extern void func_0208b494(const char *message);
extern void func_0207ebb0(void *handle);
extern void *func_0207eb44(void *argument, u32 size);
extern void *func_0207e7ec(void *source, void *argument, u32 size);
extern s32 func_0207f020(void *handle);
extern s32 func_0207f7e8(void *handle, s32 argument);
extern s32 func_0207f740(void *handle, s32 first, s32 second, s32 third);
extern s32 func_0207f628(void *handle, s32 first, s32 second);
extern s32 func_0207f824(void *handle, s32 first, s32 second);
extern s32 func_0207f8d4(void *handle, s32 first, s32 second);
extern s32 func_0207efa0(void *handle);
extern s32 func_0207f504(void *handle, s32 argument);
extern s32 func_0207f538(void *handle);
extern s32 func_0207f404(void *handle, s32 argument);
extern s32 func_0207f214(void *handle, s32 value);
extern s32 func_0207f288(void *handle);

/* Declared before its first caller because the definition sits later in the
 * file (address order); func_0208cfdc and func_0208cf94 use it to reset a
 * record before filling it in. */
void func_0208d1e0(Cri0208cf94Object *self);

/* Creates an ACSSBADX record in caller-owned work memory. The two rejection
 * paths log the literals at 0208cfd4/0208cfd8, which read "ACSSBADX_Create :
 * Work pointor is NULL." and "... Work size is too small." (0208cfa0..0208cfc4);
 * a non-null pointer with at least the 12-byte record size is reset by
 * func_0208d1e0 and returned. The caller in func_0208b4fc passes 12 for size. */
Cri0208cf94Object *func_0208cf94(Cri0208cf94Object *work, u32 size)
{
    if (work == 0) {
        func_0208b494(data_021493c4);
        return 0;
    }
    if (size < sizeof(*work)) {
        func_0208b494(data_021493f8);
        return 0;
    }
    func_0208d1e0(work);
    return work;
}

/* Creates the worker handle described by the borrowed source descriptor and
 * stores it at offset 4 (0208cff0..0208d050). A non-zero source->field_08 takes
 * the func_0207eb44 path; otherwise source->field_00 becomes the first argument
 * of func_0207e7ec. Both receive the caller's data and size minus 12. Success
 * copies source->field_00 to offset 8 and returns 1; failure logs the literal at
 * 0208d054, "ACSSBADX_CreateHndl : Failed to create handle.", and returns 0. */
s32 func_0208cff0(Cri0208cf94Object *self, Cri0208cf94Source *source, void *argument, u32 size)
{
    if (source->field_08 != 0) {
        self->handle = func_0207eb44(argument, size - 12);
    } else {
        self->handle = func_0207e7ec(source->field_00, argument, size - 12);
    }
    if (self->handle == 0) {
        func_0208b494(data_02149430);
        return 0;
    }
    self->unk_08 = source->field_00;
    return 1;
}

/* Releases the worker handle and marks the record unowned by clearing offset 4
 * (0208d058..0208d078). A null handle skips the release entirely (popeq). */
void func_0208d058(Cri0208cf94Object *self)
{
    if (self->handle != 0) {
        func_0207ebb0(self->handle);
        self->handle = 0;
    }
}

/* Resets the record when a caller passes one, otherwise does nothing
 * (0208cfdc..0208cfef). func_0208cf94 calls this before filling the record
 * and the null branch keeps callers from dereferencing a missing object. */
void func_0208cfdc(Cri0208cf94Object *self)
{
    if (self != 0) {
        func_0208d1e0(self);
    }
}

/* Tail-forwards the handle and the caller's remaining arguments to 0207f7e8
 * (literal at 0208d088). The callee's word result is returned unchanged. */
s32 func_0208d07c(Cri0208cf94Object *self, s32 argument)
{
    return func_0207f7e8(self->handle, argument);
}

/* Tail-forwards the handle and three more words to 0207f740 (0208d098). */
s32 func_0208d08c(Cri0208cf94Object *self, s32 first, s32 second, s32 third)
{
    return func_0207f740(self->handle, first, second, third);
}

/* Tail-forwards the handle and two more words to 0207f628 (0208d0a8). */
s32 func_0208d09c(Cri0208cf94Object *self, s32 first, s32 second)
{
    return func_0207f628(self->handle, first, second);
}

/* Tail-forwards the handle and two more words to 0207f824 (0208d0b8). */
s32 func_0208d0ac(Cri0208cf94Object *self, s32 first, s32 second)
{
    return func_0207f824(self->handle, first, second);
}

/* Tail-forwards the handle and two more words to 0207f8d4 (0208d0c8). */
s32 func_0208d0bc(Cri0208cf94Object *self, s32 first, s32 second)
{
    return func_0207f8d4(self->handle, first, second);
}

/* Tail-forwards the handle to the no-argument worker 0207efa0 (0208d0d8);
 * the worker's word result becomes this wrapper's result. */
s32 func_0208d0cc(Cri0208cf94Object *self)
{
    return func_0207efa0(self->handle);
}

/* Tail-forwards the handle and one more word to 0207f504 (0208d0e8). */
s32 func_0208d0dc(Cri0208cf94Object *self, s32 argument)
{
    return func_0207f504(self->handle, argument);
}

/* Tail-forwards the handle to the no-argument worker 0207f538 (0208d0f8);
 * the worker's word result becomes this wrapper's result. */
s32 func_0208d0ec(Cri0208cf94Object *self)
{
    return func_0207f538(self->handle);
}

/* Maps the worker state returned by func_0207f020 (0208d100..0208d10c) onto the
 * wrapper's five-state result. The jump table at 0208d114 groups states 1/2,
 * 3/4 and 6 with the out-of-range default into 1, 2 and 4 respectively; state 0
 * and 5 map to 0 and 3. */
s32 func_0208d0fc(Cri0208cf94Object *self)
{
    switch (func_0207f020(self->handle)) {
    case 0:
        return 0;
    case 1:
    case 2:
        return 1;
    case 3:
    case 4:
        return 2;
    case 5:
        return 3;
    case 6:
        return 4;
    }
    return 4;
}

/* Clamps the caller's value to -960 before tail-forwarding it with the handle
 * to 0207f214 (0208d17c). The ROM materialises -960 as mov #0x3c0 + rsb
 * because the negative constant is not an ARM immediate (0208d160..0208d163);
 * the signed compare is therefore LT, not LO. */
s32 func_0208d160(Cri0208cf94Object *self, s32 value)
{
    if (value < -960) {
        value = -960;
    }
    return func_0207f214(self->handle, value);
}

/* Tail-forwards the handle to the no-argument worker 0207f288 (0208d18c). */
s32 func_0208d180(Cri0208cf94Object *self)
{
    return func_0207f288(self->handle);
}

/* Forwards the handle and the third argument to 0207f214 only when the second
 * argument is zero (0208d190..0208d1ab); the ROM copies r2 into r1, so the
 * value passed is the caller's third word. No result is used. */
void func_0208d190(Cri0208cf94Object *self, s32 flag, s32 value)
{
    if (flag == 0) {
        func_0207f214(self->handle, value);
    }
}

/* Returns zero without touching the object when the flag is non-zero;
 * otherwise forwards the handle to 0207f288 and returns its word result
 * (0208d1ac..0208d1c7). */
s32 func_0208d1ac(Cri0208cf94Object *self, s32 flag)
{
    if (flag != 0) {
        return 0;
    }
    return func_0207f288(self->handle);
}

/* Tail-forwards the handle and one more word to 0207f404 (0208d1d4). */
s32 func_0208d1c8(Cri0208cf94Object *self, s32 argument)
{
    return func_0207f404(self->handle, argument);
}

/* Returns the borrowed handle stored at offset 4 (0208d1d8..0208d1dc). No
 * caller in this unit establishes a narrower type, so it stays opaque. */
void *func_0208d1d8(Cri0208cf94Object *self)
{
    return self->handle;
}

/* Initialises a fresh record: installs the 0212ed98 dispatch table at offset
 * 0 and clears the handle and glue word at offsets 4 and 8 (0208d1e0..0208d1fb).
 * The stores must happen in address order because the caller reuses the same
 * record afterwards. */
void func_0208d1e0(Cri0208cf94Object *self)
{
    self->vtable = (const void *)0x0212ed98;
    self->handle = 0;
    self->unk_08 = 0;
}
