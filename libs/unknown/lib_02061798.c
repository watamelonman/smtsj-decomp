#include "libs/unknown/lib_02061798.h"

/* Returns the font record whose id at +0x20 matches, or null. */
extern Unk061798Font *func_020618cc(u32 id);
/* Returns the second header byte of the current font record (func_02061950+1). */
extern u8 func_02061970(void);
/* Appends a character code to the text buffer and returns that buffer. */
extern Unk061798TextBuffer *func_02063954(const void *text, u32 code);
/* Returns the singleton text-buffer object, or null before initialisation. */
extern Unk061798TextBuffer *func_02063a50(void);

/* Selects a font record by id; callers use the returned glyph table directly
 * (ldrh at +0 and at +2*index in func_02060214/020608a4). */
Unk061798Font *func_0206191c(u32 id)
{
    return func_020618cc(id);
}

/* Returns the second header byte of the selected font record; callers add it
 * to a glyph advance (func_02061ba0). */
u8 func_020619f8(void)
{
    return func_02061970();
}

/* Forwards a character append to the text buffer; callers keep the returned
 * buffer pointer (func_02011c474/02011d900). */
Unk061798TextBuffer *func_02063a44(const void *text, u32 code)
{
    return func_02063954(text, code);
}

/* Returns the shared text-buffer singleton; callers read its fields
 * (func_020641cc) and treat null as "not initialised". */
Unk061798TextBuffer *func_02063a60(void)
{
    return func_02063a50();
}

/* Stores the 32-bit value at +0x30 of a render object; callers use it to
 * update the active glyph record (func_02060318/02060550/02060654). */
void func_0206357c(Unk061798Object *object, u32 value)
{
    object->unk_0030 = value;
}

/* Stores the byte at +0x34 of a render object; callers store a mode
 * (0/1/2) or a count before advancing (func_02062634, func_02063640). */
void func_02063584(Unk061798Object *object, u8 value)
{
    object->unk_0034 = value;
}

/* Stores the 32-bit value at +0x48 of a render object; func_02063e88 uses it
 * to clear the field on the object's first pointer. */
void func_0206359c(Unk061798Object *object, u32 value)
{
    object->unk_0048 = value;
}
