/* src/game/unit_020b28e4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object referenced by the first word of data_02176b80. Only the two configuration words
   written by func_020b64f8 and the one written by func_020b6514 are known; the gaps keep
   the offsets seen in the original code. */
typedef struct Unk0b28e4Obj {
    u8 pad_0000[0xc8c];
    u32 unk_0c8c;
    u32 unk_0c90;
    u8 pad_0c94[0xc];
    u32 unk_0ca0;
} Unk0b28e4Obj;

/* One 12-byte table slot; no member is accessed in this translation unit. */
typedef struct Unk0b28e4Entry {
    u8 pad_00[0xc];
} Unk0b28e4Entry;

/* 44-byte block referenced by the second word of data_02176b80 (allocated with that size in
   Unk0b28e4_Unk_0b62e8). The three-entry array size is guessed from the 36-byte clear. */
typedef struct Unk0b28e4Buf {
    u8 unk_00;
    u8 pad_01;
    u8 unk_02[6];
    Unk0b28e4Entry unk_08[3];
} Unk0b28e4Buf;

/* Structure passed to Unk0b28e4_Unk_0b5e10; only the byte at +0x37 and the word at +0x2c
   are written before it is forwarded to func_0205f7f4. */
typedef struct Unk0b28e4Fields {
    u8 pad_0000[0x2c];
    u32 unk_002c;
    u8 pad_0030[7];
    s8 unk_0037;
} Unk0b28e4Fields;

typedef struct Unk0b28e4Globals {
    Unk0b28e4Obj *unk_0000;
    Unk0b28e4Buf *unk_0004;
} Unk0b28e4Globals;

extern Unk0b28e4Globals data_02176b80;

void func_020b32bc(void);
void func_020b363c(void);
void func_020b3d28(void);
void func_020b2dd0(void);
void func_0205f7f4(Unk0b28e4Fields *fields, u32 a, u32 b, u32 c);
void func_020552ec(int a, int b);
void *func_02052fe0(u32 size);
void Unk0b28e4_Unk_0b6370(void);
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 value, void *req);
void func_020516d0(void *obj);
void Unk0bc1a8_Unk_0bc9b4(u32 slot, u32 value);
void func_02008644(u32 value, void *dst, u32 size);

/* empty callback */
void Unk0b28e4_Nop_0b28e4(void) { }

/* Populates the callback table at `p`: the size word, cleared slots and four callback
   addresses. */
void Unk0b28e4_InitCallbacks(u32 *p)
{
    p[0] = 0xcac;
    p[1] = 0;
    p[3] = (u32)func_020b32bc;
    p[4] = (u32)func_020b363c;
    p[5] = 0;
    p[6] = 0;
    p[7] = (u32)func_020b3d28;
    p[8] = (u32)func_020b2dd0;
}

/* Sets the byte at +0x37 and the word at +0x2c of `fields`, then forwards `fields` and the
   first three arguments to func_0205f7f4. */
void Unk0b28e4_Unk_0b5e10(Unk0b28e4Fields *fields, u32 a, u32 b, u32 c, s8 d, u32 e)
{
    fields->unk_0037 = d;
    fields->unk_002c = e;
    func_0205f7f4(fields, a, b, c);
}

/* Allocates and clears the 44-byte cache at +0x04 when absent, then selects callback set 13. */
void Unk0b28e4_Unk_0b62e8(void)
{
    func_020552ec(6, 3);
    if (data_02176b80.unk_0004 == 0) {
        data_02176b80.unk_0004 = func_02052fe0(44);
        Unk0b28e4_Unk_0b6370();
    }
    Unk0bc1a8_Unk_0bc928(13, 0xffff, 0);
}

/* Frees the object whose address is cached at +0x04 (see Unk0b28e4_Unk_0b62e8), clears the
   cache and restores callback set 13. */
void Unk0b28e4_Unk_0b6338(void)
{
    func_020552ec(6, 1);
    func_020516d0(data_02176b80.unk_0004);
    data_02176b80.unk_0004 = 0;
    Unk0bc1a8_Unk_0bc9b4(13, 0);
}

/* Zeroes the 44-byte block cached at +0x04 (allocated by Unk0b28e4_Unk_0b62e8): byte 0 and
   the two payload areas at +2 (6 bytes) and +8 (36 bytes) are reset to zero. */
void Unk0b28e4_Unk_0b6370(void)
{
    data_02176b80.unk_0004->unk_00 = 0;
    func_02008644(0, data_02176b80.unk_0004->unk_02, 6);
    func_02008644(0, data_02176b80.unk_0004->unk_08, 36);
}

/* Returns the byte pointer cached at +0x04 advanced past its two-byte header. */
u8 *Unk0b28e4_Unk_0b64c8(void)
{
    return data_02176b80.unk_0004->unk_02;
}

/* Returns a pointer to entry `index` (12 bytes each) of the table whose base is the word
   at +0x04; the first entry starts 8 bytes into that block. */
Unk0b28e4Entry *func_020b64dc(int index)
{
    return &data_02176b80.unk_0004->unk_08[index];
}

/* Stores two words at +0xc8c and +0xc90 of the object referenced by the word at +0x00. */
void func_020b64f8(u32 first, u32 second)
{
    data_02176b80.unk_0000->unk_0c8c = first;
    data_02176b80.unk_0000->unk_0c90 = second;
}

/* Stores one word at +0xca0 of the object referenced by the word at +0x00. */
void func_020b6514(u32 value)
{
    data_02176b80.unk_0000->unk_0ca0 = value;
}

/* Byte view of the table indexed by Unk0b28e4_GetEntry34: the caller selects a slot with a
   12-byte index and reads the word 0x34 bytes into the selected base. */
typedef struct Unk0b28e4Indexed {
    u8 pad_0000[0x34];
    u32 unk_0034;
} Unk0b28e4Indexed;

/* Returns the word at +0x34 of slot `i` in table `p`, or 0 when `i` is outside 0..26 or
   `p` is null. */
u32 Unk0b28e4_GetEntry34(u8 *p, int i)
{
    u32 ok = i >= 0;
    if (ok == 0) {
        return 0;
    }
    ok = i < 27;
    if (ok == 0) {
        return 0;
    }
    if (p == 0) {
        return 0;
    }
    return ((Unk0b28e4Indexed *)(p + i * 12))->unk_0034;
}
