/* Work-record helpers and singleton state queries. */
#include "types.h"



/* decompiler-derived */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11f2d0Work {
    u8 pad_0000[0x10];
    s32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    u32 unk_0020;
    s32 unk_0024;
    s32 unk_0028;
    s32 unk_002c;
    s32 unk_0030;
} Unk11f2d0Work;

/* Borrowed 0x28-byte record; offsets follow loads/stores at 0x0211f2d0. */
typedef struct Unk11f2d0Record {
    u32 active;
    u32 field4;
    u32 field8;
    u32 fieldC;
    u32 state;
    u32 argument;
    u8 reserved[0x10];
} Unk11f2d0Record;

/* Initial prefix of the singleton work area, observed at 0x0211f664. */
typedef struct Unk11f2d0Prefix {
    s32 state;
    u32 field4;
    u32 field8;
    u16 fieldC;
} Unk11f2d0Prefix;

extern u32 data_02176e78[];
void func_02061424(u32 work);
u32 func_0211f3c8(void);
void func_02008848(void *destination, int value, u32 size);
void func_0205ddb4(u32 value);
void func_020629c4(u32 value);

/* At 0x0211f320, request state 3 only for an active, non-null record. */
void Unk11f2d0_Unk_11f320(Unk11f2d0Record *record)
{
    if (record->active != 0) {
        record->state = 3;
    }
}

/* At 0x0211f308, latch the argument before requesting state 1 if active. */
void Unk11f2d0_Unk_11f308(Unk11f2d0Record *record, u32 argument)
{
    if (record->active != 0) {
        record->argument = argument;
        record->state = 1;
    }
}

/* Initialize only the prefix fields written at 0x0211f664; retain the tail. */
void Unk11f2d0_Unk_11f664(Unk11f2d0Prefix *work)
{
    work->state = 0;
    work->field4 = 11;
    work->field8 = 0;
    work->fieldC = 0;
}

/* Forward the existing singleton to 0x02061424, as seen at 0x0211f37c. */
void Unk11f2d0_Unk_11f37c(void)
{
    if (*data_02176e78 == 0) {
        return;
    }
    func_02061424(*data_02176e78);
}

/* At 0x0211f354, publish the factory result only while the singleton is absent. */
void Unk11f2d0_Unk_11f354(void)
{
    u32 value;
    if (*data_02176e78 != 0) {
        return;
    }
    value = func_0211f3c8();
    *data_02176e78 = value;
}

/* At 0x0211f2d0, release fields 4/8 in order, then clear the active record. */
void Unk11f2d0_Unk_11f2d0(Unk11f2d0Record *record)
{
    if (record->active == 0) {
        return;
    }
    func_0205ddb4(record->field4);
    func_020629c4(record->field8);
    func_02008848(record, 0, 0x28);
}

int func_0205c408();
int func_0205c6e0();
int Unk065e88_Call_02065fc0();

/* The load at 0x0211f340 tests word +0xC; a null record returns false. */
int Unk11f2d0_IsFieldCSet(const Unk11f2d0Record *record)
{
    if (record == 0) {
        return 0;
    }
    return record->fieldC != 0;
}

/* The compare at 0x0211f3b4 tests state 7; an absent singleton is also ready. */
int Unk11f2d0_IsState7(void)
{
    const Unk11f2d0Prefix *work = (const Unk11f2d0Prefix *)*data_02176e78;
    if (work == 0) {
        return 1;
    }
    return work->state == 7;
}

/* decompiler-derived */
void Unk11f2d0_Unk_11f544(int arg0)
{
  u32 *v1;
  if (((Unk11f2d0Work *)arg0)->unk_0024 != 0) {
    return;
  }
  v1 = (u32 *)
           Unk065e88_Call_02065fc0(((Unk11f2d0Work *)arg0)->unk_0014,((Unk11f2d0Work *)arg0)->unk_001c,1,0);
  *(u32 **)(arg0 + 0x24) = v1;
  func_0205c408(*v1,0);
  func_0205c6e0(**(u32 **)(arg0 + 0x24));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f58c(int arg0)
{
  u32 *v1;
  if (((Unk11f2d0Work *)arg0)->unk_0028 != 0) {
    return;
  }
  v1 = (u32 *)
           Unk065e88_Call_02065fc0(((Unk11f2d0Work *)arg0)->unk_0014,((Unk11f2d0Work *)arg0)->unk_001c,1,0);
  *(u32 **)(arg0 + 0x28) = v1;
  func_0205c408(*v1,1);
  func_0205c6e0(**(u32 **)(arg0 + 0x28));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f5d4(int arg0)
{
  u32 *v1;
  if (((Unk11f2d0Work *)arg0)->unk_002c != 0) {
    return;
  }
  v1 = (u32 *)
           Unk065e88_Call_02065fc0(((Unk11f2d0Work *)arg0)->unk_0014,((Unk11f2d0Work *)arg0)->unk_001c,1,0);
  *(u32 **)(arg0 + 0x2c) = v1;
  func_0205c408(*v1,2);
  func_0205c6e0(**(u32 **)(arg0 + 0x2c));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f61c(int arg0)
{
  u32 *v1;
  if (((Unk11f2d0Work *)arg0)->unk_0030 != 0) {
    return;
  }
  v1 = (u32 *)
           Unk065e88_Call_02065fc0(((Unk11f2d0Work *)arg0)->unk_0018,((Unk11f2d0Work *)arg0)->unk_0020,0,0);
  *(u32 **)(arg0 + 0x30) = v1;
  func_0205c408(*v1,0);
  func_0205c6e0(**(u32 **)(arg0 + 0x30));
  return;
}

int func_0205bb68();
int func_0205c368();
/* decompiler-derived */
void Unk11f2d0_Unk_11f43c(int arg0)
{
  u32 tmp1;
  if (((Unk11f2d0Work *)arg0)->unk_0024 != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_0024);
    ((Unk11f2d0Work *)arg0)->unk_0024 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0028 != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_0028);
    ((Unk11f2d0Work *)arg0)->unk_0028 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_002c != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_002c);
    ((Unk11f2d0Work *)arg0)->unk_002c = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0030 != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_0030);
    ((Unk11f2d0Work *)arg0)->unk_0030 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_001c != 0) {
    func_0205c368();
    ((Unk11f2d0Work *)arg0)->unk_001c = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0020 != 0) {
    func_0205c368();
    ((Unk11f2d0Work *)arg0)->unk_0020 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0010 != 0) {
    func_0205ddb4(((Unk11f2d0Work *)arg0)->unk_0010);
    ((Unk11f2d0Work *)arg0)->unk_0010 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0014 != 0) {
    func_0205ddb4(((Unk11f2d0Work *)arg0)->unk_0014);
    ((Unk11f2d0Work *)arg0)->unk_0014 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0018 != 0) {
    func_0205ddb4(((Unk11f2d0Work *)arg0)->unk_0018);
    ((Unk11f2d0Work *)arg0)->unk_0018 = 0;
  }
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 5);
  *data_02176e78 = 0;
  return;
}
