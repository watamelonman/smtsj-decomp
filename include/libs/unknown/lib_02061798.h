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

/* Opaque object returned through func_02063a44; it is a different global
 * from the one behind Unk061798ResultB. */
typedef struct Unk061798ResultA Unk061798ResultA;

/* Opaque object returned through func_02063a60; it is distinct from
 * Unk061798ResultA and is backed by data_0216b9a8 + 4. */
typedef struct Unk061798ResultB Unk061798ResultB;

/* Partial view of the larger render object whose fields the setters update. */
typedef struct Unk061798Object {
    u8 pad_0000[0x30];
    u32 unk_0030;
    u8 unk_0034;
    u8 pad_0035[0x13];
    u32 unk_0048;
} Unk061798Object;

/* Tail wrapper: selects a font record by id; its glyph table starts at +0. */
Unk061798Font *func_0206191c(u32 id);
/* Tail wrapper: returns the second header byte of the font record for id,
 * which callers pass in r0. */
u8 func_020619f8(u32 id);
/* Tail wrapper: appends a character code and returns Unk061798ResultA. */
Unk061798ResultA *func_02063a44(const void *text, u32 code);
/* Tail wrapper: returns the shared Unk061798ResultB singleton, or null. */
Unk061798ResultB *func_02063a60(void);
/* Stores a 32-bit value at +0x30. */
void func_0206357c(Unk061798Object *object, u32 value);
/* Stores a byte at +0x34. */
void func_02063584(Unk061798Object *object, u8 value);
/* Stores a 32-bit value at +0x48. */
void func_0206359c(Unk061798Object *object, u32 value);

#endif
