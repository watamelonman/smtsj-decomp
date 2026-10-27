#include "types.h"

/* Each function in this unit forwards the word at offset 4 of the supplied
 * record to one CRI worker. The LDR at +4 and the following indirect branch
 * establish the offset and the borrowed pointer; the table at 0212ed98 holds
 * these wrappers' addresses, so their callers own the record. */
typedef struct Cri0208cf94Object {
    u32 unk_00;
    void *handle;
} Cri0208cf94Object;

extern s32 func_0207f7e8(void *handle, s32 argument);
extern s32 func_0207f740(void *handle, s32 first, s32 second, s32 third);
extern s32 func_0207f628(void *handle, s32 first, s32 second);
extern s32 func_0207f824(void *handle, s32 first, s32 second);
extern s32 func_0207f8d4(void *handle, s32 first, s32 second);
extern s32 func_0207efa0(void *handle);
extern s32 func_0207f504(void *handle, s32 argument);

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

/* Returns the borrowed handle stored at offset 4 (0208d1d8..0208d1dc). No
 * caller in this unit establishes a narrower type, so it stays opaque. */
void *func_0208d1d8(Cri0208cf94Object *self)
{
    return self->handle;
}
