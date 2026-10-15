/*
 * src/game/unit_020f3db4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774();
int Unk044394_Unk_044428();
int Unk044394_Unk_044534();
int Unk0f3db4_Unk_0f3ec8();

u32 Unk0f3db4_Unk_0f44a8(u32 arg0);
void Unk0f3db4_Unk_0f3dc8(void);
void Unk0f3db4_Unk_0f3dd8(void);
int Unk0f3db4_Unk_0f4528(u32 arg0);
void Unk0f3db4_Unk_0f4550(u8 *arg0);
int Unk0f3db4_Unk_0f3db4(void);
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1);
u32 Unk0f3db4_Unk_0f4490(u32 arg0,int arg1);

/* decompiler-derived */
u32 Unk0f3db4_Unk_0f44a8(u32 arg0)
{
  return arg0 & 3;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f3dc8(void)
{
  Unk044394_Unk_044428(8);
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f3dd8(void)
{
  Unk044394_Unk_044534(8);
}

/* decompiler-derived */
int Unk0f3db4_Unk_0f4528(u32 arg0)
{
  return (arg0 & 4) != 0;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4550(u8 *arg0)
{
  *arg0 = *arg0 | 4;
}

/* decompiler-derived */
int Unk0f3db4_Unk_0f3db4(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5e52;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1)
{
  *arg0 = *arg0 & 4 | arg1;
}

/* decompiler-derived */
/* Low two bits of byte `offset` of the table. */
u32 Unk0f3db4_Unk_0f4490(u32 arg0,int arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8();
  return Unk0f3db4_Unk_0f44a8(*(u8 *)(value + arg1));
}



/* decompiler-derived */
void Unk0f3db4_Unk_0f4510(u32 arg0,int arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8();
  Unk0f3db4_Unk_0f4528(*(u8 *)(value + arg1));
}




/* decompiler-derived */
u32 Unk0f3db4_Unk_0f3e6c(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x32;
  case 1:
    return 0x32;
  case 2:
    return 0x32;
  case 3:
    return 0x32;
  case 4:
    return 100;
  case 5:
    return 0x3c;
  default:
    return 0;
  }
}


/* decompiler-derived */
int Unk0f3db4_Unk_0f3ec8(u32 arg0)
{
  int value;
  value = Unk0f3db4_Unk_0f3db4();
  switch(arg0) {
  case 0:
    return value;
  case 1:
    return value + 0x32;
  case 2:
    return value + 100;
  case 3:
    return value + 0x96;
  case 4:
    return value + 200;
  case 5:
    return value + 300;
  default:
    return 0;
  }
}


extern char data_02150e24[];
int func_020152cc();
void func_02099b10();
int Unk02e000_Thunk_0202e788();
int func_0209993c();
typedef struct Unk0f3db4Ent {
    u16 id;
    u16 n;
} Unk0f3db4Ent;
typedef struct Unk0f3db4Obj {
    u8 pad[0xa];
    Unk0f3db4Ent e[3];
} Unk0f3db4Obj;
int Unk0f3db4_IsName(const char *s)
{
    return func_020152cc(s, data_02150e24) == 0;
}

void Unk0f3db4_Unk_0f4398(Unk0f3db4Obj *p, int k)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->e[i].id != 0) {
            func_02099b10(p->e[i].id, k * p->e[i].n);
        }
    }
}

int Unk0f3db4_Unk_0f4448(int id)
{
    u16 *q = (u16 *)Unk02e000_Thunk_0202e788();
    int n = func_0209993c(id);
    if (n <= 0) {
        return n;
    }
    if (id == q[0] || id == q[1] || id == q[2] || id == q[3]) {
        n--;
    }
    return n;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4674(int arg0,int arg1)
{
  u8 value1;
  int value2;
  int value3;
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3));
    *(u8 *)(arg0 + value3) = value1;
    value3 = value3 + 1;
  } while (value3 < 100);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 100));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 100) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 0x96));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 0x96) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 300));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 300) = value1;
  } while (value3 < 0x3c);
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4538(u32 arg0,int arg1)
{
  int tmp1;
  tmp1 = Unk0f3db4_Unk_0f3ec8((u32)arg0);
  Unk0f3db4_Unk_0f4550((u8 *)tmp1 + arg1);
}

/* Forwards (base + offset, value) to Unk0f3db4_Unk_0f44d0. */
void Unk0f3db4_Unk_0f44b0(u32 arg0, int offset, u8 value)
{
    Unk0f3db4_Unk_0f44d0((u8 *)Unk0f3db4_Unk_0f3ec8(arg0) + offset, value);
}

/* Promotes state 2 to state 3. */
void Unk0f3db4_Unk_0f44e4(u32 arg0, int offset)
{
    if (Unk0f3db4_Unk_0f4490(arg0, offset) != 2) {
        return;
    }
    Unk0f3db4_Unk_0f44b0(arg0, offset, 3);
}
