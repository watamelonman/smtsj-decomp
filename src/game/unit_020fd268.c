/* Singleton work accessors; field offsets are evidenced by the original ARM loads/stores. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0fd268Work {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x8];
    u32 unk_001c;
    u8 pad_0020[0x4];
    u32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
} Unk0fd268Work;



extern Unk0fd268Work *data_02176e1c;
/* Only the first word of this separate singleton is inspected here. */
extern int *data_02176e18;
/* Returns the first word of data_02176e18, or -1 when absent (ARM 020fd364). */
int Unk0fd268_GetField0(void)
{
    if (data_02176e18 != 0) {
        return *data_02176e18;
    }
    return -1;
}

/* Returns the borrowed singleton pointer; ARM 020fd4b4 loads data_02176e1c. */
Unk0fd268Work *Unk0fd268_Get_data_02176e1c(void)
{
  return data_02176e1c;
}

void func_02061424(Unk0fd268Work *work);
/* Forwards a present singleton to func_02061424 (ARM 020fd3ac); does not clear it. */
void Unk0fd268_Unk_0fd3ac(void)
{
  Unk0fd268Work *value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value == 0) {
    return;
  }
  func_02061424(value);
}


/* Clears offset 0x2c when the singleton exists (ARM 020fd47c). */
void Unk0fd268_Unk_0fd47c(void)
{
  Unk0fd268Work *value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    value->unk_002c = 0;
  }
}


/* Stores the supplied words at offsets 0x30 and 0x34 if present (ARM 020fd494). */
void Unk0fd268_Unk_0fd494(u32 arg0,u32 arg1)
{
  Unk0fd268Work *value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    value->unk_0030 = arg0;
    value->unk_0034 = arg1;
  }
}

Unk0fd268Work *func_020fd4c4(u32 arg0);
/* Creates and stores work only when absent; forwards arg0 unchanged (ARM 020fd380). */
void Unk0fd268_Unk_0fd380(u32 arg0)
{
  Unk0fd268Work *value1;
  Unk0fd268Work *value2;
  value1 = Unk0fd268_Get_data_02176e1c();
  if (value1 != 0) {
    return;
  }
  value2 = func_020fd4c4(arg0);
  data_02176e1c = value2;
}


extern u8 data_021510a4[];
int Unk05b82c_Unk_05b82c();
int func_0205dcd4();
/* Writes +3 for nonzero flag, -3 otherwise, at offset 0x10 (ARM 020fd3c4). */
void Unk0fd268_SetDir(int flag)
{
    Unk0fd268Work *p = Unk0fd268_Get_data_02176e1c();
    if (p == 0) {
        return;
    }
    if (flag != 0) {
        p->unk_0010 = 3;
    } else {
        p->unk_0010 = -3;
    }
}

/* decompiler-derived */
void Unk0fd268_Unk_0fd574(u32 *arg0)
{
  u32 tmp1;
  Unk05b82c_Unk_05b82c(0xd);
  Unk05b82c_Unk_05b82c(0xe);
  tmp1 = func_0205dcd4(((int)data_021510a4),1);
  *arg0 = tmp1;
  return;
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd540(Unk0fd268Work *arg0, u32 arg1){
  arg0->unk_0008 = 0xffffffaf;
  arg0->unk_000c = 0;
  arg0->unk_0010 = 0;
  arg0->unk_001c = arg1;
  arg0->unk_0024 = 0;
  arg0->unk_0028 = 0;
  arg0->unk_002c = 1;
  arg0->unk_0030 = 0;
  arg0->unk_0034 = 0;
  return;
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd3f0(int arg0)
{
  Unk0fd268Work *tmp1;
  tmp1 = Unk0fd268_Get_data_02176e1c();
  if (tmp1 == 0) {
    return;
  }
  if (arg0 == 0) {
    tmp1->unk_0008 = 0xffffffaf;
    tmp1->unk_0010 = 0;
    return;
  }
  tmp1->unk_0008 = 0;
  return;
}

/* Tests offset 8 for zero; an absent singleton returns false (ARM 020fd428). */
int Unk0fd268_IsField8Zero(void)
{
    Unk0fd268Work *p = Unk0fd268_Get_data_02176e1c();
    if (p == 0) {
        return 0;
    }
    return p->unk_0008 == 0;
}

int Unk0fd268_IsField8Neg81(void)
{
    Unk0fd268Work *p = Unk0fd268_Get_data_02176e1c();
    if (p == 0) {
        return 0;
    }
    return p->unk_0008 == -81;
}
