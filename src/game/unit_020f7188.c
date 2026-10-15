/*
 * src/game/unit_020f7188.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))



void Unk0f7188_Nop_0f7884(void);
void Unk0f7188_Nop_0f7ae0(void);
void Unk0f7188_Nop_0f7ae4(void);

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

int Unk0f7188_Unk_0f7210(u8 *p)
{
    if (FIELD(u32, p, 8) != 10) {
        return 0;
    }
    if (FIELD(u32, p, 20) != 0) {
        return 0;
    }
    return FIELD(int, p, 16) >= FIELD(int, p, 28);
}

/* empty callback */
void Unk0f7188_Nop_0f7884(void) { }

/* empty callback */
void Unk0f7188_Nop_0f7ae0(void) { }

/* empty callback */
void Unk0f7188_Nop_0f7ae4(void) { }


void Unk0f7188_Unk_0f7ca8(u32 arg0);
void func_02065cfc(int a, s16 id);
void Unk0f7188_Call_02065cfc(int id)
{
    func_02065cfc(1, (s16)id);
}

/* decompiler-derived */
void Unk0f7188_Unk_0f7cc0(u32 arg0)
{
  switch(arg0) {
  case 0:
    goto LAB_020f7cfc;
  case 1:
    goto LAB_020f7cfc;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    goto LAB_020f7cfc;
  case 8:
    goto LAB_020f7cfc;
  case 9:
    break;
  case 10:
LAB_020f7cfc:
    Unk0f7188_Unk_0f7ca8(1);
    return;
  }
  Unk0f7188_Unk_0f7ca8(0);
}

extern u32 data_02176e08[];
/* decompiler-derived */
void Unk0f7188_Unk_0f780c(u32 *arg0)
{
  *data_02176e08 = (u32)(arg0);
  *arg0 = 0;
  arg0[2] = 0;
  arg0[5] = 0;
  arg0[6] = 0;
}

/* decompiler-derived */
void Unk0f7188_Unk_0f7ca8(u32 arg0)
{
  if (*data_02176e08 != 0) {
    *(u32 *)(*data_02176e08 + 0x18) = arg0;
  }
}
