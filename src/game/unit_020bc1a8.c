/*
 * src/game/unit_020bc1a8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020bc514();

int Unk0bc1a8_GetConst0(void);
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1);

/* returns 0 */
int Unk0bc1a8_GetConst0(void) { return 0; }

/* decompiler-derived */
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1)
{
  func_020bc514(arg0,arg1,0);
}
