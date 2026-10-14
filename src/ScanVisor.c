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
void func_020a34a4(void) { }
void func_020a34a8(void) { }

/* Constant: 20 (used by six different systems). */
int func_020a2bb0(void) { return 20; }

/* Constant: 6. */
int func_020a4e40(void) { return 6; }

u32 func_020a45f8(ScanVisor *sv) { return sv->field14; }

/* Forwards to func_020fc6b8. */
void func_020a28e8(void) { func_020fc6b8(); }

/* Reads entry `index` of the slot table at 0x1C0. */
u32 func_020a42b8(ScanVisor *sv, int index) { return sv->slots[index]; }

/* Sets the 0x1C/0x20 pair. */
void func_020a43dc(ScanVisor *sv, u32 a, u32 b) {
    sv->rangeA = a;
    sv->rangeB = b;
}



/* set +0x24 and +0x28 */
void func_020a43e8(void *obj, u32 a, u32 b) {
    FIELD(u32, obj, 0x24) = a;
    FIELD(u32, obj, 0x28) = b;
}


/* decompiler-derived */
void func_020a4904(int arg0)
{
  *(u32 *)(arg0 + 0x1bc) = 1;
  return;
}


/* decompiler-derived */
void func_020a4988(int arg0)
{
  *(u32 *)(arg0 + 0x198) = 0;
  return;
}

void func_020a4600(void);
/* forwards to `func_020a4600` */
void func_020a49cc(void) { func_020a4600(); }

extern u32 data_02176b04[];
/* decompiler-derived */
u32 func_020a2cfc(void)
{
  return *data_02176b04;
}

int func_020a4a44();
/* decompiler-derived */
void func_020a3620(int arg0)
{
  func_020a4a44(arg0 + 0x24c);
  return;
}


/* decompiler-derived */
void func_020a465c(int arg0)
{
  *(u32 *)(arg0 + 0x10) = 0;
  *(u32 *)(arg0 + 0x14) = 0;
  return;
}

int func_020a4950();
/* decompiler-derived */
void func_020a4a30(u32 arg0)
{
  func_020a4950(arg0,1,1);
  return;
}
