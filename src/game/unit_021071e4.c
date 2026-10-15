/* src/game/unit_021071e4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk1071e4Work {
    u8 pad_0000[0x29];
    u8 unk_0029;
} Unk1071e4Work;



int func_020bc9f4();
int func_020bcacc();
/* decompiler-derived */
void Unk1071e4_Unk_107c34(Unk1071e4Work *arg0){
  func_020bc9f4(0x13,0);
  func_020bcacc(0x12,0);
  arg0->unk_0029 = 4;
  return;
}

int func_02108aec();
/* decompiler-derived */
int Unk1071e4_Unk_1087f4(u32 arg0,int arg1,int arg2,int arg3,short arg4)
{
  int tmp1;
  tmp1 = func_02108aec();
  if (tmp1 != 0) {
    return (arg3 - arg1) + (arg4 - arg2) * 3;
  }
  return 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk1071e4Obj {
    u8 pad[8];
    u32 h[1];
} Unk1071e4Obj;
void Unk096754_CopyAreaPos();
int Unk02e000_GetAreaRecord();
void Unk0979d8_ResetFields();
void func_0205c41c();
void func_0205caa8();
extern u32 data_0213c9ac[];
int Unk09727c_GetAreaSub48();
int func_02063a30();
void func_02061f10();
void func_021088fc(u8 *p)
{
    if (FIELD(u32, p, 32) == 0) {
        Unk096754_CopyAreaPos(p);
        return;
    }
    Unk0979d8_ResetFields(Unk02e000_GetAreaRecord(FIELD(s8, p + FIELD(u32, p, 32), 59)));
}

int func_02108aec(int x)
{
    switch (x) {
    case 1:
    case 7:
        return 0;
    }
    return 1;
}

void func_02108b08(Unk1071e4Obj *p, int i)
{
    func_0205c41c(p->h[i], 0);
    func_0205caa8(p->h[i], data_0213c9ac[i]);
}

void func_02108b94(u32 a)
{
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk09727c_GetAreaSub48(a)));
}
