/*
 * src/game/unit_0202f078.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_02008848();
int Unk02e000_Unk_02e774();
int Unk02e000_GetWorkArea();

u8 Unk02f078_Unk_02f0d8(void);
u8 Unk02f078_Unk_02f220(void);
int Unk02f078_Unk_02f078(void);
void Unk02f078_Unk_02f0b0(u8 arg0);
void Unk02f078_Unk_02f0c4(void);
void Unk02f078_Unk_02f20c(u8 arg0);
int Unk02f078_Unk_02f0e8(void);
void Unk02f078_Unk_02f08c(void);

/* decompiler-derived */
u8 Unk02f078_Unk_02f0d8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return *(u8 *)(value + 2);
}

int Unk02f078_TestFlag380(int i)
{
    if (i <= 0) {
        return 0;
    }
    if (i >= 37) {
        return 0;
    }
    if (((u8 *)Unk02e000_GetWorkArea() + (i >> 3))[0x380] & (u8)(1 << (i & 7))) {
        return 1;
    }
    return 0;
}

void Unk02f078_SetFlag380(int i)
{
    u8 mask;
    u8 *p;
    if (i <= 0) {
        return;
    }
    if (i >= 37) {
        return;
    }
    mask = 1 << (i & 7);
    p = (u8 *)Unk02e000_GetWorkArea() + 0x380;
    if ((mask & p[i >> 3]) == 0) {
        p[i >> 3] += mask;
    }
}

/* decompiler-derived */
u8 Unk02f078_Unk_02f220(void)
{
  int value;
  value = Unk02e000_GetWorkArea();
  return *(u8 *)(value + 0x361);
}

/* decompiler-derived */
int Unk02f078_Unk_02f078(void)
{
  int value;
  value = Unk02e000_GetWorkArea();
  return value + 0x36e;
}

/* decompiler-derived */
void Unk02f078_Unk_02f0b0(u8 arg0)
{
  int value;
  value = Unk02e000_Unk_02e774();
  *(u8 *)(value + 2) = arg0;
}

/* decompiler-derived */
void Unk02f078_Unk_02f0c4(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  *(u8 *)(value + 2) = 0;
}

/* decompiler-derived */
void Unk02f078_Unk_02f20c(u8 arg0)
{
  int value;
  value = Unk02e000_GetWorkArea();
  *(u8 *)(value + 0x361) = arg0;
}

/* decompiler-derived */
int Unk02f078_Unk_02f0e8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return *(char *)(value + 2) != '\0';
}

/* decompiler-derived */
void Unk02f078_Unk_02f08c(void)
{
  int value;
  value = Unk02f078_Unk_02f078();
  func_02008848(value,0,6);
  *(u8 *)(value + 1) = 100;
}

int Unk02f078_IsAllowed_02f190(int a, int b)
{
    if (a == 0) {
        return 1;
    }
    if (b == 0) {
        return 0;
    }
    switch (a) {
    case 2:
        return 1;
    case 5:
        if (b != 2) {
            return 1;
        }
        break;
    case 1:
        if (b == 3 || b == 4) {
            return 1;
        }
        break;
    case 3:
        if (b == 4) {
            return 1;
        }
        break;
    }
    return 0;
}

void Unk02f078_InitEntry5e12(int i)
{
    if (i >= 64) {
        return;
    }
    if (i < 0) {
        return;
    }
    {
        u8 *p = (u8 *)Unk02e000_Unk_02e774() + 0x5e12;
        if ((p[i] & 2) == 0) {
            p[i] = 3;
        }
    }
}

int Unk02f078_GetEntry5e12Bit0(int i)
{
    if (i >= 64) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }
    if (((u8 *)Unk02e000_Unk_02e774() + i)[0x5e12] & 1) {
        return 1;
    }
    return 0;
}
