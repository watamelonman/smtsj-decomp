/* src/game/unit_02047788.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* returns 1 */
int Unk047788_GetConst1(void) { return 1; }


/* returns 1 */
int Unk047788_GetConst1_0477dc(void) { return 1; }

int func_020453dc();
int func_02047834();
/* decompiler-derived */
u32 Unk047788_Unk_047884(void)
{
  func_020453dc();
  func_02047834();
  return 1;
}

int func_0209d13c();
/* decompiler-derived */
int Unk047788_Unk_04781c(void)
{
  int value;
  value = func_0209d13c();
  return value != 0;
}

extern u8 data_021432e4[];
extern u8 data_021432f0[];
extern u8 data_021432fc[];
extern u8 data_02143308[];
void func_0204f188(int layer, u32 id, int slot, const void *name, int flag);
void func_0204f24c(int layer, u32 id, u32 sub, int a, int b, int c);
void func_0204f650(int layer, u32 id, u32 sub, int kind);

/* Sets up the dia (ef_e_dia_*) effect layers for an effect id. */
void func_02047898(u32 id, u32 sub, int sub2)
{
    func_0204f650(0xf, id, sub, 0x15);
    func_0204f24c(0xf, id, sub, 1, 0, 1);
    if (sub2 >= 0) {
        func_0204f650(0x13, id, sub2, 0x16);
        func_0204f24c(0x13, id, sub2, 3, 1, 0);
    }
    if (((id >> 16) & 0xff) == 2) {
        func_0204f188(0, id, 3, data_021432e4, 1);
        func_0204f188(0, id, 4, data_021432f0, 1);
        return;
    }
    func_0204f188(0, id, 5, data_021432fc, 1);
    func_0204f188(0xe, id, 5, data_02143308, 1);
}
