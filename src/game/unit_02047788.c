/* src/game/unit_02047788.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



extern u8 data_0215ee9c[];
int func_02052728();
int func_02061698();
void func_020614b0();
u32 Unk044904_Get_data_0215ee98(void);
int Unk047788_Unk_047788(void)
{
    if (func_02052728() != 0) {
        return 0;
    }
    if (func_02061698(data_0215ee9c) != 0) {
        return 0;
    }
    FIELD(u32, Unk044904_Get_data_0215ee98(), 0x40) &= ~0x8000;
    func_020614b0(data_0215ee9c);
    return 1;
}

/* returns 1 */
int Unk047788_GetConst1(void) { return 1; }


/* returns 1 */
int Unk047788_GetConst1_0477dc(void) { return 1; }

int func_020453dc();
void Unk047788_Unk_047834();
typedef struct Unk047788Mgr {
    u8 pad_0000[0x64];
    u32 *slots[10];
} Unk047788Mgr;

void func_020b6514();
int func_0205e4f8();
void func_02116028();
int Unk0a5680_GetEntryUnk14();
void func_020a5fc8();
int Unk047788_Unk_0477e4(void)
{
    FIELD(u32, Unk044904_Get_data_0215ee98(), 0x50) = 0;
    func_020b6514(1);
    if (func_0205e4f8(-1) != 0) {
        return 0;
    }
    func_02116028();
    return 1;
}

void Unk047788_Unk_047834(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        u32 *o = ((Unk047788Mgr *)Unk044904_Get_data_0215ee98())->slots[i];
        if (o != 0) {
            u32 w = o[0];
            if ((w >> 16 & 0xff) == 2) {
                func_020a5fc8(Unk0a5680_GetEntryUnk14(w), 0);
            }
        }
    }
}

/* decompiler-derived */
u32 Unk047788_Unk_047884(void)
{
  func_020453dc();
  Unk047788_Unk_047834();
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
