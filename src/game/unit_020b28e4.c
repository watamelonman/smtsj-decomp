/* src/game/unit_020b28e4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0b28e4_Nop_0b28e4(void) { }

extern u8 data_02176b80[];
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020b32bc();
void func_020b363c();
void func_020b3d28();
void func_020b2dd0();
void func_0205f7f4();
void func_020552ec();
int func_02052fe0();
void Unk0b28e4_Unk_0b6370(void);
void Unk0bc1a8_Unk_0bc928();
void func_020516d0();
void Unk0bc1a8_Unk_0bc9b4();
void func_02008644();
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

/* Sets the byte at +0x37 and the word at +0x2c of `p`, then forwards `p` and the first
   three arguments to func_0205f7f4. */
void Unk0b28e4_Unk_0b5e10(u8 *p, u32 a, u32 b, u32 c, s8 d, u32 e)
{
    FIELD(s8, p, 55) = d;
    FIELD(u32, p, 44) = e;
    func_0205f7f4(p, a, b, c);
}

void Unk0b28e4_Unk_0b62e8(void)
{
    func_020552ec(6, 3);
    if (FIELD(u32, data_02176b80, 4) == 0) {
        FIELD(u32, data_02176b80, 4) = func_02052fe0(44);
        Unk0b28e4_Unk_0b6370();
    }
    Unk0bc1a8_Unk_0bc928(13, 0xffff, 0);
}

/* Frees the object whose address is cached at +0x04 (see Unk0b28e4_Unk_0b62e8), clears the
   cache and restores callback set 13. */
void Unk0b28e4_Unk_0b6338(void)
{
    func_020552ec(6, 1);
    func_020516d0(FIELD(u32, data_02176b80, 4));
    FIELD(u32, data_02176b80, 4) = 0;
    Unk0bc1a8_Unk_0bc9b4(13, 0);
}

/* Fills in the command/parameter buffer at +0x04: byte 0 is cleared and the two payload
   areas at +2 (6 bytes) and +8 (36 bytes) are reset to zero. */
void Unk0b28e4_Unk_0b6370(void)
{
    *FIELD(u8 *, data_02176b80, 4) = 0;
    func_02008644(0, FIELD(u8 *, data_02176b80, 4) + 2, 6);
    func_02008644(0, FIELD(u8 *, data_02176b80, 4) + 8, 36);
}

/* Returns the byte pointer cached at +0x04 advanced past its two-byte header. */
u8 *Unk0b28e4_Unk_0b64c8(void)
{
    return FIELD(u8 *, data_02176b80, 4) + 2;
}

/* Returns a pointer to entry `index` (12 bytes each) of the table whose base is the word
   at +0x04; the first entry starts 8 bytes into that block. */
u8 *func_020b64dc(int index)
{
    return FIELD(u8 *, data_02176b80, 4) + 8 + index * 12;
}

/* Stores two words at +0xc8c and +0xc90 of the object referenced by the word at +0x00. */
void func_020b64f8(u32 first, u32 second)
{
    FIELD(u32, FIELD(u8 *, data_02176b80, 0), 0xc8c) = first;
    FIELD(u32, FIELD(u8 *, data_02176b80, 0), 0xc90) = second;
}

/* Stores one word at +0xca0 of the object referenced by the word at +0x00. */
void func_020b6514(u32 value)
{
    FIELD(u32, FIELD(u8 *, data_02176b80, 0), 0xca0) = value;
}

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
    return FIELD(u32, p + i * 12, 52);
}
