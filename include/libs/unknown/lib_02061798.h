#ifndef LIBS_UNKNOWN_LIB_02061798_H
#define LIBS_UNKNOWN_LIB_02061798_H

#include "types.h"

/* Opaque object returned through func_02063a44; it is a different global
 * from the one behind Unk061798ResultB. */
typedef struct Unk061798ResultA Unk061798ResultA;

/* Object returned through func_02063a60; it is distinct from
 * Unk061798ResultA and is backed by data_0216b9a8 + 4. Only the word at
 * +0x1c, written by func_02065614, is named; the rest is padding. */
typedef struct Unk061798ResultB {
    u8 pad_0000[0x1c];
    u32 unk_001c;
} Unk061798ResultB;

/* Opaque record behind the pointer at +0x28 of a font record; callers read
 * fields +0x10 and +0x0c through it (call site 0x020601f4). */
typedef struct Unk061798FontData Unk061798FontData;

/* Partial view of the 56-byte record selected by func_020618cc: sixteen u16
 * entries at +0 used as a glyph table, an id at +0x20, two header bytes and a
 * pointer at +0x28 that callers dereference. */
typedef struct Unk061798Font {
    u16 unk_0000[16];
    u32 unk_0020;
    u8 unk_0024;
    u8 unk_0025;
    u8 pad_0026[2];
    Unk061798FontData *unk_0028;
    u8 pad_002c[0x0c];
} Unk061798Font;

/* Partial view of the larger render object whose fields these functions
 * update. Only bytes touched by this unit are named; the rest is padding. */
typedef struct Unk061798Object {
    u8 pad_0000[4];
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x14];
    u32 unk_0028;
    u8 pad_002c[4];
    u32 unk_0030;
    u8 unk_0034;
    u8 pad_0035[0x13];
    u32 unk_0048;
    u16 unk_004c;
    u16 unk_004e;
    u8 pad_0050[0x18];
    s8 unk_0068;
    u8 pad_0069[0x18];
    s8 unk_0081;
} Unk061798Object;

/* Returns the +0x28 pointer of the font record selected by id. */
Unk061798FontData *func_0206190c(u32 id);
/* Returns a pointer to the first header byte (+0x24) of the font record. */
u8 *func_02061950(u32 id);
/* Returns the first header byte (+0x24) of the font record selected by id. */
u8 func_02061960(u32 id);
/* Returns the second header byte (+0x25) of the font record selected by id. */
u8 func_02061970(u32 id);
/* Tail wrapper: selects a font record by id; its glyph table starts at +0. */
Unk061798Font *func_0206191c(u32 id);
/* Tail wrapper: returns the second header byte of the font record for id,
 * which callers pass in r0. */
u8 func_020619f8(u32 id);
/* Returns the +0x28 font pointer selected by the object's font id. */
Unk061798FontData *func_02062a2c(Unk061798Object *object);
/* Clears the two halfwords at +0x4c and +0x4e. */
void func_02063490(Unk061798Object *object);
/* Stores a 32-bit value at +0x30. */
void func_0206357c(Unk061798Object *object, u32 value);
/* Stores the signed byte at +0x34; func_0206358c passes the signed byte at
 * +0x81 through it, so the parameter stays signed. */
void func_02063584(Unk061798Object *object, s8 value);
/* Copies the signed byte at +0x81 into the byte at +0x34. */
void func_0206358c(Unk061798Object *object);
/* Stores a 32-bit value at +0x48. */
void func_0206359c(Unk061798Object *object, u32 value);
/* Tail wrapper: appends a character code and returns Unk061798ResultA. */
Unk061798ResultA *func_02063a44(const void *text, u32 code);
/* Returns the singleton object stored at data_0216b9a8 + 4, or null. */
Unk061798ResultB *func_02063a50(void);
/* Tail wrapper: returns the shared Unk061798ResultB singleton, or null. */
Unk061798ResultB *func_02063a60(void);
/* True when any bit of mask is set in the word at +0x4 of the object. */
s32 func_02061eb4(Unk061798Object *object, u32 mask);
/* True when the word at +0x10 of the object is zero. */
s32 func_02062a74(Unk061798Object *object);
/* True when the signed byte at +0x68 of the object is positive. */
s32 func_020642a8(Unk061798Object *object);
/* Stores 2 at +0x8 and 5 at +0xc of the object. */
void func_0206435c(Unk061798Object *object);
/* Stores value at +0 of the shared bss object data_0216b9a8. */
void func_02065604(u32 value);
/* Stores value at +0x1c of the func_02063a60 singleton. */
void func_02065614(u32 value);
/* Tail wrapper: calls func_020656ac with the object and -1. */
s32 func_0206569c(void *object);
/* Tail wrapper: appends 0x8001 through func_02063954. */
Unk061798ResultA *func_02063a30(const void *text);

#endif
