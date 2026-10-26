#include "libs/unknown/lib_02061798.h"

/* Returns the font record whose id at +0x20 matches, or null. */
extern Unk061798Font *func_020618cc(u32 id);
/* Appends a character code; returns the result object that func_02063a44
 * forwards (distinct from func_02063a50's singleton). */
extern Unk061798ResultA *func_02063954(const void *text, u32 code);

/* The +4 word of this bss object is the shared result singleton. */
typedef struct Unk061798Bss {
    u32 unk_0000;
    Unk061798ResultB *unk_0004;
} Unk061798Bss;
extern Unk061798Bss data_0216b9a8;

/* Returns the +0x28 pointer of the font record selected by id; callers
 * dereference it (call site 0x020601f4). */
Unk061798FontData *func_0206190c(u32 id)
{
    return func_020618cc(id)->unk_0028;
}

/* Selects a font record by id; callers use the returned record's glyph table
 * directly (ldrh at +0 and at +2*index, call sites 0x02060210/0x020608a0). */
Unk061798Font *func_0206191c(u32 id)
{
    return func_020618cc(id);
}

/* Returns a pointer to the first header byte of the font record selected by
 * the id in r0. */
u8 *func_02061950(u32 id)
{
    return &func_020618cc(id)->unk_0024;
}

/* Returns the first header byte of the font record selected by id; callers
 * use it as a glyph offset (call sites 0x02060c54/0x02060e50). */
u8 func_02061960(u32 id)
{
    return *func_02061950(id);
}

/* Returns the second header byte of the font record selected by the id in r0;
 * callers add it to a glyph advance (call site 0x02061b9c). */
u8 func_02061970(u32 id)
{
    return func_02061950(id)[1];
}

/* Returns the second header byte of the font record selected by the id in r0;
 * callers add it to a glyph advance (call site 0x02061b9c). */
u8 func_020619f8(u32 id)
{
    return func_02061970(id);
}

/* Reads the font id at +0x28 of a render object and returns the +0x28 pointer
 * of the selected font record (call sites 0x02060614/0x02060a38/0x020620a8). */
Unk061798FontData *func_02062a2c(Unk061798Object *object)
{
    return func_0206190c(object->unk_0028);
}

/* Clears the two halfwords at +0x4c and +0x4e of a render object; call site
 * 0x02063418 does this while resetting the object's text state. */
void func_02063490(Unk061798Object *object)
{
    object->unk_004e = 0;
    object->unk_004c = 0;
}

/* Stores the 32-bit value at +0x30 of a render object; callers use it to
 * update the active glyph record (call sites 0x02060318/0x02060550/0x02060654). */
void func_0206357c(Unk061798Object *object, u32 value)
{
    object->unk_0030 = value;
}

/* Stores the byte at +0x34 of a render object; callers store a mode
 * (0/1/2) or a count before advancing (call sites 0x02062634/0x02063640). */
void func_02063584(Unk061798Object *object, s8 value)
{
    object->unk_0034 = value;
}

/* Copies the signed byte at +0x81 of a render object into the byte at +0x34;
 * call sites 0x0206255c/0x0206258c/0x020636b8 use it to apply a stored mode. */
void func_0206358c(Unk061798Object *object)
{
    func_02063584(object, object->unk_0081);
}

/* Stores the 32-bit value at +0x48 of a render object; call site 0x02063e88
 * uses it to clear the field on the object's first pointer. */
void func_0206359c(Unk061798Object *object, u32 value)
{
    object->unk_0048 = value;
}

/* Forwards a character append to func_02063954; callers keep the returned
 * pointer (call sites 0x0211c464/0x0211d8f8/0x0211d93c). */
Unk061798ResultA *func_02063a44(const void *text, u32 code)
{
    return func_02063954(text, code);
}

/* Returns the +4 word of data_0216b9a8, the shared result singleton; callers
 * test it for null before reading fields (call sites 0x020654d0/0x02065530). */
Unk061798ResultB *func_02063a50(void)
{
    return data_0216b9a8.unk_0004;
}

/* Returns the shared singleton through func_02063a50; callers read its fields
 * and treat null as "not initialised" (call sites 0x020641c8/0x0206545c). */
Unk061798ResultB *func_02063a60(void)
{
    return func_02063a50();
}
