/*
 * src/game/unit_020946e0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02175d94[];
int func_02008848();
int func_02052ff0();
void func_02053000(void);
int func_02057628();
int func_02057678();

int Unk0946e0_Unk_0948fc(int arg0);
void Unk0946e0_Thunk_02053000(void);
u32 Unk0946e0_GetAddr_data_02175d94(void);
void Unk0946e0_Unk_094ae0(int *arg0);
u32 Unk0946e0_Unk_0946e0(void);
void Unk0946e0_Unk_094c50(int *arg0);
void Unk0946e0_Unk_094a64(u32 arg0);

void Unk0946e0_Clear12(void *p)
{
    if (p == 0) {
        return;
    }
    func_02008848(p, 0, 12);
}

/* decompiler-derived */
int Unk0946e0_Unk_0948fc(int arg0)
{
  return arg0 + 4;
}

/* forwards to `func_02053000` */
void Unk0946e0_Thunk_02053000(void) { func_02053000(); }

/* decompiler-derived */
u32 Unk0946e0_GetAddr_data_02175d94(void)
{
  return ((int)data_02175d94);
}

/* decompiler-derived */
void Unk0946e0_Unk_094ae0(int *arg0)
{
  int value;
  value = Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*(short *)(value + 0x10);
}

/* decompiler-derived */
u32 Unk0946e0_Unk_0946e0(void)
{
  u32 value;
  value = func_02052ff0(0xc);
  func_02008848(value,0,0xc);
  return value;
}

/* decompiler-derived */
void Unk0946e0_Unk_094c50(int *arg0)
{
  short *v1;
  int value;
  v1 = (short *)Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*v1;
  value = Unk0946e0_GetAddr_data_02175d94();
  arg0[1] = (int)*(short *)(value + 2);
}

/* decompiler-derived */
void Unk0946e0_Unk_094a64(u32 arg0)
{
  int value;
  value = Unk0946e0_GetAddr_data_02175d94();
  func_02057678(arg0,*(u32 *)(value + 4),*(u32 *)(value + 8));
  func_02057628(arg0,0,0);
}



/* decompiler-derived */
void Unk0946e0_Unk_094704(u16 *arg0,u16 arg1,u16 arg2,u16 arg3,
                  short arg4)
{
  if (arg0 == (u16 *)0x0) {
    return;
  }
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[4] = arg3;
  arg0[5] = -arg4;
  arg0[2] = 0;
  arg0[3] = 0;
}


int func_02094750();
void Unk0946e0_Unk_0949e0();
void Unk0946e0_ApplyRect();
void Unk0946e0_ResetRect(void)
{
    u8 *p = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    FIELD(s16, p, 0x00) = 0;
    FIELD(s16, p, 0x02) = 0;
    FIELD(s32, p, 0x04) = FIELD(s16, p, 0x00);
    FIELD(s32, p, 0x08) = FIELD(s16, p, 0x02);
    FIELD(u16, p, 0x10) = 256;
    FIELD(u16, p, 0x12) = 192;
    FIELD(u32, p, 0x14) = 0;
}

/* decompiler-derived */
void Unk0946e0_Unk_094958(void)
{
  int value;
  short *v2;
  short *v3;
  value = Unk044904_Get_data_0215ee98();
  func_02094750(*(u32 *)(value + 0x7870));
  v2 = (short *)Unk0946e0_GetAddr_data_02175d94();
  value = Unk044904_Get_data_0215ee98();
  v3 = (short *)Unk0946e0_Unk_0948fc(*(u32 *)(value + 0x7870));
  *(int *)(v2 + 2) = (int)*v2 + (int)*v3;
  value = Unk044904_Get_data_0215ee98();
  value = Unk0946e0_Unk_0948fc(*(u32 *)(value + 0x7870));
  *(int *)(v2 + 4) = (int)v2[1] + (int)*(short *)(value + 2);
  Unk0946e0_ApplyRect(0);
  Unk0946e0_Unk_0949e0(1);
  Unk0946e0_ApplyRect(2);
  Unk0946e0_Unk_0949e0(3);
  Unk0946e0_Unk_094a64(6);
}

int func_02061424();
int func_02094af8();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020575ac();
void Unk0946e0_Unk_0949e0(int a)
{
    u8 *v = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    s32 x = (FIELD(s32, v, 4) << 12) / 32;
    s32 y = (FIELD(s32, v, 8) << 12) / 32;
    s32 w = (FIELD(s16, v, 16) << 14) / 256;
    s32 h = (FIELD(s16, v, 18) * 12288) / 192;
    func_020575ac(a, h - y, -(h + y), x - w, x + w);
}

void Unk0946e0_ApplyRect(int a)
{
    u8 *v = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    func_02057678(a, FIELD(u32, v, 4), FIELD(u32, v, 8));
    func_02057628(a, ((FIELD(s16, v, 16) - 256) / 2) << 12, ((FIELD(s16, v, 18) - 192) / 2) << 12);
}

/* decompiler-derived */
void Unk0946e0_Unk_094b98(int arg0)
{
  int tmp1;
  if (*(int *)(arg0 + 8) < 0) {
    *(u32 *)(arg0 + 8) = 0;
    Unk0946e0_Unk_094ae0((int *)arg0);
    return;
  }
  tmp1 = func_02094af8();
  if (tmp1 == 0) {
    return;
  }
  func_02061424(arg0);
}

int func_02094c74();
typedef struct Unk0946e0Task {
    u32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u32 unk_0c;
    u8 unk_10;
} Unk0946e0Task;
void *func_020611dc();
void Unk0946e0_Unk_094b98(int arg0);
void Unk09d060_Unk_09d170();

void func_02094bd4(int a, u32 b, u8 c)
{
    Unk0946e0Task *t = (Unk0946e0Task *)func_020611dc(Unk0946e0_Unk_094b98, 0, 0, 0, 20, 0, 0, 0);
    t->unk_08 = -1;
    t->unk_0c = b;
    t->unk_04 = ((100 - a) << 8) / 100;
    t->unk_10 = c;
    Unk09d060_Unk_09d170(t);
}

/* decompiler-derived */
void Unk0946e0_Unk_094d64(int arg0)
{
  int tmp1;
  if (*(int *)(arg0 + 0x10) < 0) {
    *(u32 *)(arg0 + 0x10) = 0;
    Unk0946e0_Unk_094c50((int *)arg0);
    return;
  }
  tmp1 = func_02094c74();
  if (tmp1 == 0) {
    return;
  }
  func_02061424(arg0);
}

typedef struct Unk0946e0Pt {
    s16 x;
    s16 y;
} Unk0946e0Pt;

void func_02094da0();
int func_02044ec4();
void func_02049c28();
void Unk0946e0_Unk_094e30(int x, int b, int c)
{
    if (x >= 64) {
        x = 64;
    }
    if (x <= -64) {
        x = -64;
    }
    func_02094da0(x, FIELD(s16, Unk0946e0_GetAddr_data_02175d94(), 2), b, c);
}

void Unk0946e0_Unk_094e70(int a, int b, int c)
{
    Unk0946e0Pt pt;
    func_02049c28(func_02044ec4(a), &pt);
    pt.x -= 128;
    pt.y -= 96;
    func_02094da0(pt.x, pt.y, b, c);
}

void Unk0946e0_Unk_094eb8(int a, int b, int c)
{
    Unk0946e0Pt pt;
    func_02049c28(func_02044ec4(a), &pt);
    pt.x -= 128;
    func_02094da0(pt.x, 0, b, c);
}
