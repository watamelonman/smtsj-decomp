#include "libs/unknown/lib_02061798.h"

/* Returns the font record whose id at +0x20 matches, or null. */
extern Unk061798Font *func_020618cc(u32 id);
/* Returns the second header byte of the font record selected by id. */
extern u8 func_02061970(u32 id);
/* Appends a character code; returns the result object that func_02063a44
 * forwards (distinct from func_02063a50's singleton). */
extern Unk061798ResultA *func_02063954(const void *text, u32 code);
/* Returns the singleton object backed by data_0216b9a8+4, or null. */
extern Unk061798ResultB *func_02063a50(void);

/* Selects a font record by id; callers use the returned record's glyph table
 * directly (ldrh at +0 and at +2*index, call sites 0x02060210/0x020608a0). */
Unk061798Font *func_0206191c(u32 id)
{
    return func_020618cc(id);
}

/* Returns the second header byte of the font record selected by the id in r0;
 * callers add it to a glyph advance (call site 0x02061b9c). */
u8 func_020619f8(u32 id)
{
    return func_02061970(id);
}

/* Forwards a character append to func_02063954; callers keep the returned
 * pointer (call sites 0x0211c464/0x0211d8f8/0x0211d93c). */
Unk061798ResultA *func_02063a44(const void *text, u32 code)
{
    return func_02063954(text, code);
}

/* Returns the shared singleton through func_02063a50; callers read its fields
 * and treat null as "not initialised" (call sites 0x020641c8/0x0206545c). */
Unk061798ResultB *func_02063a60(void)
{
    return func_02063a50();
}

/* Stores the 32-bit value at +0x30 of a render object; callers use it to
 * update the active glyph record (call sites 0x02060318/0x02060550/0x02060654). */
void func_0206357c(Unk061798Object *object, u32 value)
{
    object->unk_0030 = value;
}

/* Stores the byte at +0x34 of a render object; callers store a mode
 * (0/1/2) or a count before advancing (call sites 0x02062634/0x02063640). */
void func_02063584(Unk061798Object *object, u8 value)
{
    object->unk_0034 = value;
}

/* Stores the 32-bit value at +0x48 of a render object; call site 0x02063e88
 * uses it to clear the field on the object's first pointer. */
void func_0206359c(Unk061798Object *object, u32 value)
{
    object->unk_0048 = value;
}
