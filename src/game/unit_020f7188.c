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

/* empty callback */
void Unk0f7188_Nop_0f7884(void) { }

/* empty callback */
void Unk0f7188_Nop_0f7ae0(void) { }

/* empty callback */
void Unk0f7188_Nop_0f7ae4(void) { }


int func_020f7ca8();
/* decompiler-derived */
void func_020f7cc0(u32 arg0)
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
    func_020f7ca8(1);
    return;
  }
  func_020f7ca8(0);
  return;
}

