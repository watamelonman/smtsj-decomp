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
    u32 unk_08;
} Cri0208cf94Object;

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
