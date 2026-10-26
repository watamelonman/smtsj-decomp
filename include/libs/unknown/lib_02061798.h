#ifndef LIBS_UNKNOWN_LIB_02061798_H
#define LIBS_UNKNOWN_LIB_02061798_H

#include "types.h"

/* Object returned through func_02063a44; it is a different global
 * from the one behind Unk061798ResultB. */
typedef struct Unk061798ResultA Unk061798ResultA;

/* Render object whose fields these functions update; defined below. */
typedef struct Unk061798Object Unk061798Object;

/* Object returned through func_02063a60; it is distinct from
 * Unk061798ResultA and is backed by data_0216b9a8 + 4. Only the words touched
 * by this unit are named; the rest is padding. The +0 word is the render
 * object tested by func_0206557c, and +0x8/+0xc/+0x58 are the state words set
 * by func_02065c10. */
typedef struct Unk061798ResultB {
    Unk061798Object *unk_0000;
    Unk061798Object *unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x0c];
    u32 unk_001c;
    u32 unk_0020;
    u8 pad_0024[4];
    u32 unk_0028;
    u8 pad_002c[0x20];
    u32 unk_004c;
    u32 unk_0050;
    u8 unk_0054;
    s8 unk_0055;
    u8 pad_0056[2];
    u32 unk_0058;
    s32 unk_005c;
    u32 unk_0060;
    u32 unk_0064;
    u8 pad_0068[8];
    u32 unk_0070;
    u8 unk_0074;
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
    u32 *unk_002c;
    u16 *unk_0030;
    s32 unk_0034;
} Unk061798Font;

/* Descriptor at data_0216b5a0: data_0216b5a8 follows it immediately in bss,
 * matching the +0 pointer and the 1024-byte extent cleared by func_02063920. */
typedef struct Unk061798Buffer {
    u8 *unk_0000;
    u32 unk_0004;
} Unk061798Buffer;

/* The four-entry font registry walked by func_02061798 and func_020618cc. */
extern Unk061798Font data_0216b4c0[4];
/* Text buffer descriptor initialised by func_02063920. */
extern Unk061798Buffer data_0216b5a0;
/* The 1024-byte buffer at data_0216b5a0 + 8 cleared by func_02063920. */
extern u8 data_0216b5a8[0x400];

/* Partial view of the larger render object whose fields these functions
 * update. Only bytes touched by this unit are named; the rest is padding. */
struct Unk061798Object {
    Unk061798Object *unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    void *unk_0014;
    u8 pad_0018[0x0c];
    u32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u8 unk_0034;
    s8 unk_0035;
    s8 unk_0036;
    u8 pad_0037;
    u32 unk_0038;
    u32 unk_003c;
    u8 pad_0040[4];
    u32 unk_0044;
    u32 unk_0048;
    u16 unk_004c;
    u16 unk_004e;
    u8 pad_0050[0x0c];
    u32 unk_005c;
    u8 pad_0060[8];
    s8 unk_0068;
    u8 pad_0069[3];
    s32 unk_006c;
    u8 pad_0070[0x11];
    s8 unk_0081;
    u8 pad_0082[2];
    u32 unk_0084;
    u8 pad_0088[8];
    u8 unk_0090;
};

/* Returns the first borrowed font record with this id, or null if absent. */
Unk061798Font *func_020618cc(u32 id);
/* Clears the id word of every entry in the four-entry font registry. */
void func_02061798(void);
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
/* Returns entry index-1 of the font record's +0x2c table, or entry 0 when the
 * index is at or above the signed +0x34 count. */
u32 *func_02061928(u32 id, s32 index);
/* Tail wrapper: returns the second header byte of the font record for id,
 * which callers pass in r0. */
u8 func_020619f8(u32 id);
/* Releases the object's +0x14 slot when its state word is 1 or 3. */
void func_02062a00(Unk061798Object *object);
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
/* Sets the object's +0x24 word and clears +0x2c when device 0 has mask 1;
 * returns the device query result. */
s32 func_02063f54(Unk061798Object *object);
/* Increments the singleton's +0x28 word, wrapping it at 0xffff to zero. */
void func_020641c4(void);
/* Decrements the signed +0x68 byte when func_0206557c returns non-zero. */
void func_020641f0(Unk061798Object *object);
/* True when any bit of mask is set in the word at +0x4 of the object. */
s32 func_02061eb4(Unk061798Object *object, u32 mask);
/* True when the word at +0x10 of the object is zero. */
s32 func_02062a74(Unk061798Object *object);
/* True when the signed byte at +0x68 of the object is positive. */
s32 func_020642a8(Unk061798Object *object);
/* True when the object's +0x38 word is neither 1 nor 3. */
s32 func_0206431c(Unk061798Object *object);
/* True when the object's +0x44 word is neither 1 nor 3. */
s32 func_0206433c(Unk061798Object *object);
/* Stores 2 at +0x8 and 5 at +0xc of the object. */
void func_0206435c(Unk061798Object *object);
/* Stores value at +0 of the shared bss object data_0216b9a8. */
void func_02065604(u32 value);
/* Stores value at +0x1c of the func_02063a60 singleton. */
void func_02065614(u32 value);
/* Tail wrapper: calls func_020656ac with the object and -1. */
s32 func_0206569c(void *object);
/* Clears the shared text buffer and points its descriptor at data_0216b5a8. */
void func_02063920(void);
/* Tail wrapper: appends 0x8001 through func_02063954. */
Unk061798ResultA *func_02063a30(const void *text);
/* Sets or clears bits of mask in the object's +0x4 word: mode 1 sets, any
 * other mode clears. */
void func_02061e98(Unk061798Object *object, u32 mask, s32 mode);
/* Forwards a, b and the fourth argument to func_02060a48 (the third argument
 * is dropped) and returns the new record, or null. */
void *func_020629ac(u32 a, u32 b, u32 ignored, u32 c);
/* Returns count times the signed glyph advance of the object's font record. */
s32 func_0206232c(Unk061798Object *object, s32 count);
/* True when the object's +0x10 word is neither 0 nor 1. */
s32 func_02062a3c(Unk061798Object *object);
/* True when the object's +0x10 word is 2 or 3. */
s32 func_02062a5c(Unk061798Object *object);
/* Calls func_02065374 when the object's +0x6c word is 0 or 2. */
void func_0206541c(Unk061798Object *object);
/* Calls func_02065374 when the object's +0x6c word is 1 or 2. */
void func_02065438(Unk061798Object *object);
/* True when the shared result singleton exists. */
s32 func_0206552c(void);
/* True when the render object behind the shared singleton has a +0x10 word
 * other than 0 or 1; returns 0 when the singleton is absent. */
s32 func_0206557c(void);
/* Returns the +0x5c word of the shared singleton, or 0 when it is absent. */
s32 func_0206559c(void);
/* Stores value at +0x20 of the shared result singleton. */
void func_02065628(u32 value);
/* Clears the singleton's +0x60/+0x64 words and calls func_0206563c(0). */
void func_0206567c(void);
/* Tail wrapper: calls func_020658b4 with the object and two 1 arguments. */
void func_020658a0(void *object);
/* Applies mode through func_02065864, then value through func_020bac00 unless
 * mode is -1. */
void func_020658b4(void *object, s32 mode, u32 value);
/* Sends the message object for `message` to func_020656ac with mode -1. */
void func_0206597c(s32 message);
/* Releases both render objects of the shared singleton through
 * func_02062a00. */
void func_02065b74(void);
/* Marks the shared singleton as state 2/0 and forwards its object's +0x90
 * byte to func_020babec. */
void func_02065b98(void);
/* Runs func_02065bc0, then sets +0x8, +0xc and +0x58 of the shared singleton
 * to 1. */
void func_02065c10(void);
/* Moves the shared singleton to state 3/5 and releases its render objects. */
void func_02065c30(void);
/* Moves the shared singleton to state 4/5 and releases its render objects. */
void func_02065c58(void);
/* Moves the shared singleton to state 3/0 and releases its render objects. */
void func_02065c80(void);
/* Moves the shared singleton to state 0/0 and clears its +0x4c word. */
void func_02065ca8(void);
/* True when the singleton is absent or its render object's +0x3c word is 1. */
s32 func_02065cd0(void);

/* Dispatches state 1 to the command provider; other states do nothing. */
void func_02063b4c(void *object, const u32 *state);
/* Sets parent and child flags when device zero reports mask 0x400. */
void func_02063f84(Unk061798Object *object);
/* Sends command 25 when no singleton exists, and returns one. */
s32 func_02065498(void);
/* Returns a borrowed optional font-table entry, with an upper-bound clamp. */
u16 *func_02061980(u32 id, s32 index);
/* True when the singleton and its +0x4c flag and +8 state are nonzero. */
s32 func_02065544(void);
/* Releases a nullable object through its providers in original order. */
void func_020629c4(Unk061798Object *object);
/* Applies mode; -1 suppresses shared state/provider updates afterward. */
void func_02065864(void *object, s32 mode);

/* Borrowed four-word metric output; the existing +8 origin is preserved. */
typedef struct Unk061798Metrics {
    s32 unk_0000, unk_0004, unk_0008, unk_000c;
} Unk061798Metrics;
/* Returns glyph advance adjusted by the optional signed bearing pair. */
s32 func_020619b8(u32 id, s32 index);
/* Tests the provider, object state and countdown before allowing progress. */
s32 func_02064268(Unk061798Object *object);
/* Enables the singleton flag once, or clears it when flag is zero. */
void func_0206563c(s32 flag);
/* Releases both render objects and clears the shared singleton references. */
void func_02063b08(Unk061798ResultB *result);
/* Clears the shared state and resets an active child through its providers. */
void func_02064370(Unk061798ResultB *result);
/* Applies an unsigned mode of at least three when no transition is active. */
void func_02065454(u32 mode);
/* Writes vertical metric bounds; count and offset use font metric units. */
void func_02061ec8(Unk061798Object *object, Unk061798Metrics *out, s32 count, s32 offset);
/* Prepares the object's slot and chooses initialization by provider state. */
void func_020621c0(Unk061798Object *object);
#endif
