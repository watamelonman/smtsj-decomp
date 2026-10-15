/*
 * src/game/unit_0205ae50.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk05ae50Work {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x45];
    u8 unk_0059;
} Unk05ae50Work;

extern u8 data_0216a184[];
int func_02053000();
int func_0205ad9c();
int func_0205ae60();
int func_0205b36c();

void Unk05ae50_Unk_05b228(Unk05ae50Work *work);
void Unk05ae50_Unk_05ae50(void);
void Unk05ae50_Unk_05b388(void);
void Unk05ae50_Unk_05afd8(u32 arg0);
int Unk05ae50_Unk_05b358(int arg0);
u32 Unk05ae50_Unk_05af3c(Unk05ae50Work *work);

int func_02008848();
int func_02052624();
void Unk05ae50_Unk_05af64(int *arg0);
int Unk05ae50_Unk_05afec(int x)
{
    s32 vc = *(volatile u16 *)0x04000006;
    int lim;
    if (vc < 191 || vc > 213) {
        return 0;
    }
    lim = FIELD(s32, data_0216a184, 0x5a8);
    if (lim < x) {
        x = lim;
    }
    return x & ~3;
}

void Unk05ae50_Reset(void)
{
    func_02008848(data_0216a184, 0, 0x5ac);
    Unk05ae50_Unk_05afd8(0x18000);
}

/* decompiler-derived */
void Unk05ae50_Unk_05b228(Unk05ae50Work *work)
{
  work->unk_0059 = 1;
}

/* decompiler-derived */
void Unk05ae50_Unk_05ae50(void)
{
  func_0205ad9c();
  func_0205ae60();
}

void Unk05ae50_WaitVCountThen_05af64(int *x)
{
    if (func_02052624() < 31) {
        while ((s32)*(volatile u16 *)0x04000006 < 191 || (s32)*(volatile u16 *)0x04000006 > 213) {
        }
        Unk05ae50_Unk_05af64(x);
    } else {
        Unk05ae50_Unk_05af64(x);
    }
}

/* decompiler-derived */
void Unk05ae50_Unk_05b388(void)
{
  func_0205ad9c();
  func_0205b36c();
}

/* decompiler-derived */
void Unk05ae50_Unk_05afd8(u32 arg0)
{
  *(u32 *)(((int)data_0216a184) + 0x5a8) = arg0 & 0xfffffffc;
}

/* decompiler-derived */
int Unk05ae50_Unk_05b358(int arg0)
{
  return ((Unk05ae50Work *)arg0)->unk_0059 != '\0';
}

/* decompiler-derived */
u32 Unk05ae50_Unk_05af3c(Unk05ae50Work *work)
{
  func_02053000(work->unk_0010);
  work->unk_0010 = 0;
  work->unk_0008 = 0;
  work->unk_000c = 0;
  return 1;
}



int func_02005334();
int func_02005390();
int func_020054d0();
int func_0200551c();
int func_02005550();
int func_020055bc();
int func_02006c94();
int func_02007a58();
int func_02007a6c();
/* decompiler-derived */
void Unk05ae50_Unk_05af64(int *arg0)
{
  u32 tmp1;
  tmp1 = func_02007a58();
  if (*arg0 != 0) {
    func_02005334();
    func_02006c94(*arg0,arg0[2]);
    func_02005390(*arg0,arg0[1],arg0[2]);
    func_020054d0();
  }
  if (arg0[3] != 0) {
    func_0200551c();
    func_02006c94(arg0[3],arg0[5]);
    func_02005550(arg0[3],arg0[4],arg0[5]);
    func_020055bc();
  }
  func_02007a6c(tmp1);
  return;
}

/* decompiler-derived */
void Unk05ae50_Unk_05af2c(void)
{
    Unk05ae50_Unk_05af3c((Unk05ae50Work *)func_0205ad9c());
}
