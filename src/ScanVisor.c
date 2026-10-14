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

typedef struct ScanVisor {
    u32 unk00[5];
    u32 field14;            /* 0x14 */
    u32 unk18;
    u32 rangeA;             /* 0x1C: set together with rangeB */
    u32 rangeB;             /* 0x20 */
    u32 unk24[103];
    u32 slots[16];          /* 0x1C0: indexed table */
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
    FIELD(u32, obj, 0x24) = a;
    FIELD(u32, obj, 0x28) = b;
}


/* decompiler-derived */
void ScanVisor_Unk_0a4904(int arg0)
{
  *(u32 *)(arg0 + 0x1bc) = 1;
  return;
}


/* decompiler-derived */
void ScanVisor_ClearUnkField198(int arg0)
{
  *(u32 *)(arg0 + 0x198) = 0;
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

int func_020a4a44();
/* decompiler-derived */
void ScanVisor_Unk_0a3620(int arg0)
{
  func_020a4a44(arg0 + 0x24c);
  return;
}


/* decompiler-derived */
void ScanVisor_Unk_0a465c(int arg0)
{
  *(u32 *)(arg0 + 0x10) = 0;
  *(u32 *)(arg0 + 0x14) = 0;
  return;
}

int func_020a4950();
/* decompiler-derived */
void ScanVisor_Unk_0a4a30(u32 arg0)
{
  func_020a4950(arg0,1,1);
  return;
}



/* decompiler-derived */
void func_020a4644(int arg0,int arg1)
{
  if (arg1 != 0) {
    *(u32 *)(arg0 + 0x10) = 0xd;
  }
  *(u32 *)(arg0 + 0x14) = 1;
  return;
}

int func_020c9d8c();
/* decompiler-derived */
void func_020a2a1c(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020c9d8c(tmp1 + 0x78);
  return;
}


/* decompiler-derived */
void func_020a2ab0(void)
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
void func_020a2acc(void)
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
void func_020a27e0(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020fd3c4(arg0);
  return;
}

int func_020fd3f0();
/* decompiler-derived */
void func_020a2800(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020fd3f0(arg0);
  return;
}
