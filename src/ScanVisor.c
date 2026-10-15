/*
 * ScanVisor.c (file name from an assert string in this TU); presumably the
 * in-dungeon scan visor UI.
 * Small getters/setters and constant queries.
 */
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef unsigned int u32;


/* Scan visor UI object (name from assert). Named fields from matched accessors. */
typedef struct ScanVisor {
    u8  pad_0000[0x8];
    u32 unk_0008;               /* +0x08 */
    u8  pad_000c[0x4];
    u32 unk_0010;               /* +0x10 */
    u32 field14;                /* +0x14 */
    u8  pad_0018[0x4];
    u32 rangeA;                 /* +0x1C */
    u32 rangeB;                 /* +0x20 */
    u32 unk_0024;               /* +0x24 */
    u32 unk_0028;               /* +0x28 */
    u8  pad_002c[0x14];
    u32 unk_0040;               /* +0x40 */
    u8  pad_0044[0x18];
    u32 unk_005c;               /* +0x5C */
    u8  pad_0060[0x138];
    u32 unk_0198;               /* +0x198 */
    u8  pad_019c[0x20];
    u32 unk_01bc;               /* +0x1BC */
    u32 slots[16];              /* +0x1C0 */
    u8  pad_0200[0x4c];
    u32 unk_024c;               /* +0x24C */
} ScanVisor;
void func_020fc6b8(void);

/* Empty callbacks (called from func_020a3114). */
void ScanVisor_Nop_0a34a4(void) { }
void ScanVisor_Nop_0a34a8(void) { }

/* Constant: 20 (used by six different systems). */
int ScanVisor_GetConst20(void) { return 20; }

/* Constant: 6. */
int ScanVisor_GetConst6(void) { return 6; }

u32 ScanVisor_Unk_0a45f8(ScanVisor *sv) { return sv->field14; }

/* Forwards to func_020fc6b8. */
void ScanVisor_Thunk_020fc6b8(void) { func_020fc6b8(); }

/* Reads entry `index` of the slot table at 0x1C0. */
u32 ScanVisor_GetSlot(ScanVisor *sv, int index) { return sv->slots[index]; }

/* Sets the 0x1C/0x20 pair. */
void ScanVisor_SetRange(ScanVisor *sv, u32 a, u32 b) {
    sv->rangeA = a;
    sv->rangeB = b;
}



/* set +0x24 and +0x28 */
void ScanVisor_SetUnkFields24_28(void *obj, u32 a, u32 b) {
    ((ScanVisor *)obj)->unk_0024 = a;
    ((ScanVisor *)obj)->unk_0028 = b;
}


/* decompiler-derived */
void ScanVisor_Unk_0a4904(int arg0)
{
  ((ScanVisor *)arg0)->unk_01bc = 1;
  return;
}


/* decompiler-derived */
void ScanVisor_ClearUnkField198(int arg0)
{
  ((ScanVisor *)arg0)->unk_0198 = 0;
  return;
}

void func_020a4600(void);
/* forwards to `func_020a4600` */
void ScanVisor_Thunk_020a4600(void) { func_020a4600(); }

extern u32 data_02176b04[];
/* decompiler-derived */
u32 ScanVisor_Get_data_02176b04(void)
{
  return *data_02176b04;
}

void ScanVisor_Unk_0a4a44(int arg0);
/* decompiler-derived */
void ScanVisor_Unk_0a3620(int arg0)
{
  ScanVisor_Unk_0a4a44(arg0 + 0x24c);
  return;
}


/* decompiler-derived */
void ScanVisor_Unk_0a465c(int arg0)
{
  ((ScanVisor *)arg0)->unk_0010 = 0;
  ((ScanVisor *)arg0)->field14 = 0;
  return;
}

void ScanVisor_Unk_0a4950(int arg0,u32 arg1,int arg2);
/* decompiler-derived */
void ScanVisor_Unk_0a4a30(u32 arg0)
{
  ScanVisor_Unk_0a4950(arg0,1,1);
  return;
}



/* decompiler-derived */
void ScanVisor_Unk_0a4644(int arg0,int arg1)
{
  if (arg1 != 0) {
    ((ScanVisor *)arg0)->unk_0010 = 0xd;
  }
  ((ScanVisor *)arg0)->field14 = 1;
  return;
}

int Unk0c855c_Unk_0c9d8c();
/* decompiler-derived */
void ScanVisor_Unk_0a2a1c(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0c855c_Unk_0c9d8c(tmp1 + 0x78);
  return;
}


/* decompiler-derived */
void ScanVisor_Unk_0a2ab0(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  ScanVisor_Unk_0a4a30(tmp1 + 0x24c);
  return;
}


/* decompiler-derived */
void ScanVisor_Unk_0a2acc(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  ScanVisor_ClearUnkField198(tmp1 + 0x24c);
  return;
}

int func_020fd3c4();
/* decompiler-derived */
void ScanVisor_Unk_0a27e0(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020fd3c4(arg0);
  return;
}

int Unk0fd268_Unk_0fd3f0();
/* decompiler-derived */
void ScanVisor_Unk_0a2800(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0fd268_Unk_0fd3f0(arg0);
  return;
}


int Unk0a7d54_Unk_0a8b44();
/* decompiler-derived */
void ScanVisor_Unk_0a2b18(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0a7d54_Unk_0a8b44(tmp1 + 0x428);
  return;
}

int func_020a8b70();
/* decompiler-derived */
void ScanVisor_Unk_0a2b38(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020a8b70(tmp1 + 0x428);
  return;
}

int func_020c9bd8();
/* decompiler-derived */
void ScanVisor_Unk_0a29a0(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020c9bd8(tmp1 + 0x78,arg0);
  return;
}

int Unk0c855c_Unk_0c9c5c();
/* decompiler-derived */
void ScanVisor_Unk_0a29c4(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0c855c_Unk_0c9c5c(tmp1 + 0x78,arg0);
  return;
}

int func_020a4a18();
/* decompiler-derived */
void ScanVisor_Unk_0a2a8c(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020a4a18(tmp1 + 0x24c,arg0);
  return;
}

int func_020a49d8();
/* decompiler-derived */
void ScanVisor_Unk_0a2a38(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020a49d8(tmp1 + 0x24c,arg0,1);
  return;
}


int func_020fda2c();
/* decompiler-derived */
void ScanVisor_Unk_0a28f4(u32 arg0)
{
  int *v1;
  v1 = (int *)ScanVisor_Get_data_02176b04();
  if (v1 == (int *)0x0) {
    return;
  }
  if (*v1 != 1) {
    return;
  }
  func_020fda2c(arg0);
  return;
}


/* decompiler-derived */
void ScanVisor_Unk_0a2a60(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020a49d8(tmp1 + 0x24c,arg0,arg1);
  return;
}


/* decompiler-derived */
int * ScanVisor_Unk_0a42c4(int arg0)
{
  int *v1;
  int tmp2;
  v1 = (int *)(arg0 + 0x20);
  tmp2 = 0;
  do {
    if (*v1 == 0) {
      return v1;
    }
    tmp2 = tmp2 + 1;
    v1 = v1 + 0xd;
  } while (tmp2 < 7);
  return (int *)0x0;
}


int func_020a8b00();
/* decompiler-derived */
void ScanVisor_Unk_0a2ae8(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020a8b00(tmp1 + 0x428,arg0,arg1);
  return;
}

int func_020c9cbc();
/* decompiler-derived */
void ScanVisor_Unk_0a29e8(u32 arg0,u32 arg1,u32 arg2)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020c9cbc(tmp1 + 0x78,arg0,arg1,arg2);
  return;
}

int func_020a2b58();
int Unk0a7d54_Unk_0a8c40();
/* decompiler-derived */
void ScanVisor_Unk_0a2b7c(void)
{
  int tmp1;
  int tmp2;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  tmp2 = func_020a2b58();
  if (tmp2 == 0) {
    return;
  }
  Unk0a7d54_Unk_0a8c40(tmp1 + 0x428);
  ScanVisor_ClearUnkField198(tmp1 + 0x24c);
  return;
}

int func_020a4370();
/* decompiler-derived */
void ScanVisor_Unk_0a4544(int arg0)
{
  int tmp1;
  int *v2;
  v2 = (int *)(arg0 + 0x20);
  tmp1 = 0;
  do {
    if (*v2 != 0) {
      func_020a4370(v2);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xd;
  } while (tmp1 < 7);
  return;
}


/* decompiler-derived */
void ScanVisor_Unk_0a27a8(int arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  if (arg0 == 0) {
    *(u32 *)(tmp1 + 0x2c) = 0x51;
    *(u32 *)(tmp1 + 0x34) = 0;
    return;
  }
  *(u32 *)(tmp1 + 0x2c) = 0;
  return;
}



/* decompiler-derived */
void ScanVisor_Unk_0a284c(int arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  if (arg0 == 0) {
    *(u32 *)(tmp1 + 0x14) = 0xffffffca;
    *(u32 *)(tmp1 + 0x1c) = 0;
    return;
  }
  *(u32 *)(tmp1 + 0x14) = 0;
  return;
}


/* decompiler-derived */
void ScanVisor_Unk_0a28b0(int arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  if (arg0 == 0) {
    *(u32 *)(tmp1 + 0x210) = 0x32;
    *(u32 *)(tmp1 + 0x214) = 0;
    return;
  }
  *(u32 *)(tmp1 + 0x210) = 0;
  return;
}

int func_020a277c();
int func_020a2820();
int func_020a2884();
void ScanVisor_Unk_0a4864(int arg0);
/* decompiler-derived */
void ScanVisor_Unk_0a2660(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020a277c(0);
  ScanVisor_Unk_0a27e0(0);
  func_020a2820(0);
  func_020a2884(0);
  ScanVisor_Unk_0a4864(tmp1 + 0x24c);
  return;
}

int func_020a2950();
/* decompiler-derived */
void ScanVisor_Unk_0a273c(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  ScanVisor_Unk_0a27a8(arg0);
  ScanVisor_Unk_0a2800(arg0);
  ScanVisor_Unk_0a284c(arg0);
  ScanVisor_Unk_0a28b0(arg0);
  func_020a2950(arg0);
  return;
}




int Unk02e000_Unk_02e0cc();
int func_0205af2c();
int func_0205bb68();
int func_0205ddb4();
int Unk0a7d54_Unk_0a8bac();
int func_020c8f08();
int func_020ca648();
int Unk0fc584_Unk_0fc6a0();
int Unk0fd9f0_Unk_0fda14();
/* decompiler-derived */
void ScanVisor_Unk_0a2e5c(int arg0)
{
  int tmp1;
  if (((ScanVisor *)arg0)->unk_0008 != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_0008 = 0;
  }
  if (((ScanVisor *)arg0)->unk_0024 != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_0024 = 0;
  }
  if (((ScanVisor *)arg0)->unk_0040 != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_0040 = 0;
  }
  ((ScanVisor *)arg0)->unk_005c = 0;
  if (((ScanVisor *)arg0)->unk_024c != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_024c = 0;
  }
  Unk0a7d54_Unk_0a8bac(arg0 + 0x428);
  Unk0fc584_Unk_0fc6a0();
  Unk0fd268_Unk_0fd3ac();
  Unk0fd9f0_Unk_0fda14();
  func_020c8f08(arg0 + 0x78);
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 10);
  func_0205bb68();
  func_0205bb68();
  func_0205bb68();
  func_0205bb68();
  func_020ca648(2);
  Unk02e000_Unk_02e0cc();
  func_0205af2c(0xc2);
  func_0205bb68();
  *data_02176b04 = 0;
  return;
}

extern u8 data_0214cddc[];
extern u8 data_0214cdf0[];
extern u8 data_0214ce08[];
int func_0205dcd4();
int func_020c8ce0();
/* Loads Visor/e_appearance + search_parts01/02 (medium). */
void ScanVisor_LoadSearchParts(int arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = func_0205dcd4(data_0214cddc);
  ((ScanVisor *)arg0)->unk_0008 = tmp1;
  tmp1 = func_0205dcd4(data_0214cdf0,arg1);
  ((ScanVisor *)arg0)->unk_0024 = tmp1;
  tmp1 = func_0205dcd4(data_0214ce08,arg1);
  ((ScanVisor *)arg0)->unk_024c = tmp1;
  func_020c8ce0(arg0 + 0x78,arg1);
}

int func_02057eb8();
int func_020a4578();
int func_020a4a70();
/* decompiler-derived */
void ScanVisor_Unk_0a4a44(int arg0)
{
  func_020a4578();
  if (((ScanVisor *)arg0)->unk_0198 == 0) {
    return;
  }
  func_02057eb8(1);
  func_020a4a70(arg0);
}

/* decompiler-derived */
void ScanVisor_Unk_0a4950(int arg0,u32 arg1,int arg2)
{
  u32 tmp1;
  *(u32 *)(arg0 + 400) = arg1;
  if (arg2 != 0) {
    ((ScanVisor *)arg0)->unk_0198 = 1;
    tmp1 = ScanVisor_GetConst6();
    *(u32 *)(arg0 + 0x194) = tmp1;
    return;
  }
  ((ScanVisor *)arg0)->unk_0198 = 2;
  *(u32 *)(arg0 + 0x194) = 0x1000;
}

/* decompiler-derived */
void ScanVisor_Unk_0a4864(int arg0)
{
  int tmp1;
  int *v2;
  tmp1 = 0;
  v2 = (int *)(arg0 + 0x20);
  do {
    if (*v2 != 0) {
      ScanVisor_SetUnkFields24_28(v2,8,0);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xd;
  } while (tmp1 < 7);
  ((ScanVisor *)arg0)->unk_01bc = 0;
}

/* decompiler-derived */
void func_020a4910(int arg0)
{
  int tmp1;
  int *v2;
  tmp1 = 0;
  v2 = (int *)(arg0 + 0x20);
  do {
    if (*v2 != 0) {
      ScanVisor_SetRange((ScanVisor *)v2, (u32)0, (u32)0);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xd;
  } while (tmp1 < 7);
}

/* decompiler-derived */
void func_020a48b4(int arg0)
{
  int tmp1;
  int *v2;
  tmp1 = 0;
  v2 = (int *)(arg0 + 0x20);
  do {
    if (*v2 != 0) {
      ScanVisor_SetRange((ScanVisor *)v2, (u32)0x50, (u32)0);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xd;
  } while (tmp1 < 7);
  *(u32 *)(arg0 + 0x1bc) = 0;
}

int func_020a4284();
/* decompiler-derived */
u32 * func_020a42f0(int arg0,u32 arg1)
{
  u32 *v1;
  int tmp2;
  v1 = (u32 *)ScanVisor_Unk_0a42c4((int)arg0);
  if (v1 != (u32 *)0x0) {
    *v1 = 1;
    *(u8 *)(v1 + 6) = *(u8 *)(arg0 + 0x1c);
    v1[1] = arg1;
    tmp2 = func_020a4284(arg1);
    v1[2] = *(u32 *)(tmp2 + 0xc);
    v1[3] = *(u32 *)(tmp2 + 0x10);
    v1[0xb] = *(u32 *)(tmp2 + 4);
    v1[0xc] = *(u32 *)(tmp2 + 8);
    ScanVisor_SetRange((ScanVisor *)v1, (u32)0x50, (u32)0);
    ScanVisor_SetUnkFields24_28(v1,0,0);
    return v1;
  }
  return (u32 *)0x0;
}
