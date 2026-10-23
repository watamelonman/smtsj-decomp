/* Optional scan-visor work access and forwarding helpers. */
#include "types.h"


u8 *ScanVisor_Get_data_02176b04(void);
int Unk0fd268_IsField8Zero(void);
int Unk0fd268_IsField8Neg81(void);
void func_02061424(void *work);
void func_020a2d0c(u32 arg0);

/* Preserve the predicate result; 0x020a2504 branches to the field-8-zero helper. */
int Unk0a23f4_Thunk_020fd428(void)
{
    return Unk0fd268_IsField8Zero();
}

/* Preserve the predicate result; 0x020a2588 branches to the field-8-minus-81 helper. */
int Unk0a23f4_Thunk_020fd450(void)
{
    return Unk0fd268_IsField8Neg81();
}

/* Pass the borrowed work pointer to 0x02061424 only when work exists. */
void Unk0a23f4_Unk_0a2414(void)
{
    u8 *work = ScanVisor_Get_data_02176b04();
    if (work == 0) {
        return;
    }
    func_02061424(work);
}

extern u32 data_02176b04[];
/* The load from data_02176b04 at 0x020a242c tests whether work is present. */
int Unk0a23f4_IsSet_data_02176b04(void)
{
  return *data_02176b04 != 0;
}

/* Forward the opaque argument to 0x020a2d0c only while work is absent. */
void Unk0a23f4_Unk_0a23f4(u32 arg0)
{
  u8 *value = ScanVisor_Get_data_02176b04();
  if (value != 0) {
    return;
  }
  func_020a2d0c(arg0);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk0a7d54_HasField8(void *work);
int Unk0a7d54_IsField8Is3(void *work);
int Unk0a7d54_Unk_0a8648(void *work);
int ScanVisor_AllSlotsF28Is80(void *slots);
/* Return zero without work; otherwise query the embedded block at +0x428. */
int Unk0a23f4_Unk_0a2448(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return Unk0a7d54_HasField8(v + 40 + 1024);
}

/* Return zero without work; otherwise test the +0x428 block via 0x020a8628. */
int Unk0a23f4_Unk_0a246c(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return Unk0a7d54_IsField8Is3(v + 40 + 1024);
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

/* Return zero without work; otherwise query the slot block at +0x24c. */
int Unk0a23f4_Unk_0a25c0(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return ScanVisor_AllSlotsF28Is80(v + 588);
}
