#ifndef LIBS_UNKNOWN_LIB_02061798_H
#define LIBS_UNKNOWN_LIB_02061798_H

#include "types.h"

/* Partial view of the 56-byte record selected by func_020618cc: sixteen u16
 * entries at +0 used as a glyph table, an id at +0x20 and two header bytes. */
typedef struct Unk061798Font {
    u16 unk_0000[16];
    u32 unk_0020;
    u8 unk_0024;
    u8 unk_0025;
    u8 pad_0026[0x12];
} Unk061798Font;

/* Opaque text buffer owned by the func_02063954/02063a50 helpers. */
typedef struct Unk061798TextBuffer Unk061798TextBuffer;

/* Partial view of the larger render object whose fields the setters update. */
typedef struct Unk061798Object {
    u8 pad_0000[0x30];
    u32 unk_0030;
    u8 unk_0034;
    u8 pad_0035[0x13];
    u32 unk_0048;
} Unk061798Object;

/* Tail wrapper: selects a font record by id and returns its glyph table. */
Unk061798Font *func_0206191c(u32 id);
/* Tail wrapper: returns the second header byte of the current font record. */
u8 func_020619f8(void);
/* Tail wrapper: appends a character code and returns the text buffer. */
Unk061798TextBuffer *func_02063a44(const void *text, u32 code);
/* Tail wrapper: returns the shared text-buffer singleton, or null. */
Unk061798TextBuffer *func_02063a60(void);
/* Stores a 32-bit value at +0x30. */
void func_0206357c(Unk061798Object *object, u32 value);
/* Stores a byte at +0x34. */
void func_02063584(Unk061798Object *object, u8 value);
/* Stores a 32-bit value at +0x48. */
void func_0206359c(Unk061798Object *object, u32 value);

#endif
