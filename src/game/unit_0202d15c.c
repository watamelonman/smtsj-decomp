/*
 * src/game/unit_0202d15c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0213d898[];
int Unk095560_GetManagerSub3a8();

u32 Unk02d15c_Unk_02d934(void);
u32 Unk02d15c_Unk_02d944(void);
void Unk02d15c_Unk_02d81c(void);
void Unk02d15c_Unk_02d91c(u32 arg0,u32 arg1);

void Unk02d15c_Call_02d91c(void)
{
    Unk02d15c_Unk_02d91c(0, -1);
}

int Unk095560_Unk_095d1c();
int func_0202d668();
int Unk094fe0_Call_020950b4();
void ImageObj_Unk_077894();
void Unk02dcfc_SetField68();
void func_02095cd8();
void Unk095560_Unk_095d08();
s32 *Unk094fe0_Unk_094fec();
int Unk02d15c_IsMode0Match(int a)
{
    return func_0202d668(Unk095560_Unk_095d1c(), a, 0, 0, -1) == 1;
}

int Unk02d15c_IsStatus1OrNeg(int a)
{
    if (a < 0) {
        return 1;
    }
    return Unk094fe0_Call_020950b4(a) == 1;
}

int Unk02d15c_IsStatus0OrNeg(int a)
{
    if (a < 0) {
        return 1;
    }
    return Unk094fe0_Call_020950b4(a) == 0;
}

void Unk02d15c_ReleaseImage(void)
{
    if ((s32)data_0213d898[0] == -1) {
        return;
    }
    ImageObj_Unk_077894(data_0213d898[0], 0);
}

int Unk02d15c_IsMode1Match(int a)
{
    return func_0202d668(Unk095560_Unk_095d1c(), 0, 1, a, -1) == 1;
}

int Unk02d15c_Setup(int a, int b, int c, int d)
{
    Unk02dcfc_SetField68();
    func_02095cd8(a, c, b, 0);
    Unk095560_Unk_095d08(d);
    return 1;
}

/* decompiler-derived */
u32 Unk02d15c_Unk_02d934(void)
{
  int value;
  value = Unk095560_GetManagerSub3a8();
  return *(u32 *)(value + 4);
}

/* decompiler-derived */
u32 Unk02d15c_Unk_02d944(void)
{
  u32 *v1;
  v1 = (u32 *)Unk095560_GetManagerSub3a8();
  return *v1;
}

/* decompiler-derived */
void Unk02d15c_Unk_02d81c(void)
{
  *data_0213d898 = 0xffffffff;
}

/* decompiler-derived */
void Unk02d15c_Unk_02d91c(u32 arg0,u32 arg1)
{
  u32 *v1;
  v1 = (u32 *)Unk095560_GetManagerSub3a8();
  *v1 = arg1;
  v1[1] = arg0;
}



/* decompiler-derived */
u32 Unk02d15c_Unk_02d9a8(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1a;
  case 1:
    return 0x1d;
  case 2:
    return 0x14;
  case 3:
    return 0x17;
  case 4:
    return 0x20;
  default:
    return 0x1a;
  }
}


/* decompiler-derived */
u32 Unk02d15c_Unk_02d9f8(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1b;
  case 1:
    return 0x1e;
  case 2:
    return 0x15;
  case 3:
    return 0x18;
  case 4:
    return 0x21;
  default:
    return 0x1b;
  }
}



/* decompiler-derived */
u32 Unk02d15c_Unk_02da48(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1c;
  case 1:
    return 0x1f;
  case 2:
    return 0x16;
  case 3:
    return 0x19;
  case 4:
    return 0;
  default:
    return 0x1c;
  }
}

u8 *Unk02d15c_GetManagerRecord(int i)
{
    return (u8 *)Unk095560_GetManager() + 180 + i * 84;
}

int Unk02d15c_ResetRecord(int a, s32 b)
{
    u8 *rec = Unk02d15c_GetManagerRecord(a);
    s32 *p = Unk094fe0_Unk_094fec(a);
    int i;
    p[6] = 0;
    p[0] = b;
    FIELD(s32, rec, 0x50) = b;
    for (i = 0; i < 5; i++) {
        p[1 + i] = 0;
    }
    return 1;
}

int func_0202dcac(int a, int key)
{
    u8 *rec = Unk02d15c_GetManagerRecord(a);
    u32 i;
    u8 *p;
    u32 n;
    if (rec == 0) {
        return -1;
    }
    p = FIELD(u8 *, rec, 0x0c);
    n = FIELD(u32, rec, 0x08);
    for (i = 0; i < n; i++) {
        if (key == p[0]) {
            return i;
        }
        p += 0x30;
    }
    return -1;
}
