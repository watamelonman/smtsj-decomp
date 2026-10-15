/* src/game/unit_020a23f4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_020fd428(void);
/* forwards to `func_020fd428` */
void Unk0a23f4_Thunk_020fd428(void) { func_020fd428(); }

void func_020fd450(void);
/* forwards to `func_020fd450` */
void Unk0a23f4_Thunk_020fd450(void) { func_020fd450(); }

int func_02061424();
/* decompiler-derived */
void Unk0a23f4_Unk_0a2414(void)
{
  int value;
  value = ScanVisor_Get_data_02176b04();
  if (value == 0) {
    return;
  }
  func_02061424();
}

extern u32 data_02176b04[];
/* decompiler-derived */
int Unk0a23f4_IsSet_data_02176b04(void)
{
  return *data_02176b04 != 0;
}

int func_020a2d0c();
/* decompiler-derived */
void Unk0a23f4_Unk_0a23f4(u32 arg0)
{
  int value;
  value = ScanVisor_Get_data_02176b04();
  if (value != 0) {
    return;
  }
  func_020a2d0c(arg0);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_020a8608();
int func_020a8628();
int Unk0a7d54_Unk_0a8648();
int func_020a4994();
int Unk0a23f4_Unk_0a2448(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return func_020a8608(v + 40 + 1024);
}

int Unk0a23f4_Unk_0a246c(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return func_020a8628(v + 40 + 1024);
}

int Unk0a23f4_Unk_0a2490(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return Unk0a7d54_Unk_0a8648(v + 40 + 1024);
}

int Unk0a23f4_IsField210Zero(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return FIELD(s32, v, 528) == 0;
}

int Unk0a23f4_IsField2cZero(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return FIELD(s32, v, 44) == 0;
}

int Unk0a23f4_IsField14Zero(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return FIELD(s32, v, 20) == 0;
}

int Unk0a23f4_IsField210Is50(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return FIELD(s32, v, 528) == 50;
}

int Unk0a23f4_IsField2cIs81(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return FIELD(s32, v, 44) == 81;
}

int Unk0a23f4_IsField14IsM54(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return FIELD(s32, v, 20) == -54;
}

int Unk0a23f4_Unk_0a25c0(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return func_020a4994(v + 588);
}
