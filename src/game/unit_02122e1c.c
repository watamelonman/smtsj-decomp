/*
 * src/game/unit_02122e1c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk122e1cWork {
    u8 pad_0000[0x10];
    u32 unk_0010;
    u32 unk_0014;
    u8 pad_0018[0x48];
    u8 unk_0060;
    u8 unk_0061;
    u8 pad_0062[0x2];
    u32 unk_0064;
    u8 pad_0068[0x4];
    u32 unk_006c;
    u8 pad_0070[0x40];
    u32 unk_00b0;
    u8 pad_00b4[0x4];
    u32 unk_00b8;
    u8 pad_00bc[0x58];
    u32 unk_0114;
    u8 pad_0118[0x4];
    s32 unk_011c;
} Unk122e1cWork;

int func_0205caa8();
int Unk0cb32c_Unk_0cb57c();

void Unk122e1c_SetUnkFields64_b0(void *obj, u32 a, u32 b);
void Unk122e1c_Unk_122f88(int arg0,int arg1,u32 arg2);
u32 Unk122e1c_Unk_122f94(int arg0,int arg1);
void Unk122e1c_Unk_122fa0(int arg0,int arg1,u32 arg2);
void Unk122e1c_Unk_12331c(Unk122e1cWork *work);
int Unk122e1c_Unk_122f54(Unk122e1cWork *work);
int Unk122e1c_Unk_122f68(Unk122e1cWork *work);
void Unk122e1c_Unk_12332c(Unk122e1cWork *work);

/* set +0x64 and +0xb0 */
void Unk122e1c_SetUnkFields64_b0(void *obj, u32 a, u32 b) {
    ((Unk122e1cWork *)obj)->unk_0064 = a;
    ((Unk122e1cWork *)obj)->unk_00b0 = b;
}

/* decompiler-derived */
void Unk122e1c_Unk_122f88(int arg0,int arg1,u32 arg2)
{
  *(u32 *)(arg0 + arg1 * 4 + 0x78) = arg2;
}

/* decompiler-derived */
u32 Unk122e1c_Unk_122f94(int arg0,int arg1)
{
  return *(u32 *)(arg0 + arg1 * 4 + 0x78);
}

/* decompiler-derived */
void Unk122e1c_Unk_122fa0(int arg0,int arg1,u32 arg2)
{
  *(u32 *)(arg0 + arg1 * 4 + 200) = arg2;
}

/* decompiler-derived */
void Unk122e1c_Unk_12331c(Unk122e1cWork *work)
{
  Unk0cb32c_Unk_0cb57c(work->unk_0014);
}

/* decompiler-derived */
int Unk122e1c_Unk_122f54(Unk122e1cWork *work)
{
  return work->unk_0060 == '\0';
}

/* decompiler-derived */
int Unk122e1c_Unk_122f68(Unk122e1cWork *work)
{
  return work->unk_0060 == '\b';
}

typedef struct Unk122e1cObj {
    u32 pad0;
    u32 unk4;
    u8 pad[216];
    u32 h[6];
    u32 slot[6];
} Unk122e1cObj;
void Unk0cb32c_Unk_0cb504();
void Unk122e1c_SetSlot(Unk122e1cObj *p, int i, u32 v)
{
    if (p == 0) {
        return;
    }
    if (i < 0 || i >= 6) {
        return;
    }
    p->slot[i] = v;
}

void Unk122e1c_ClearSlots(Unk122e1cObj *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->slot[i] = 0;
    }
}

/* decompiler-derived */
void Unk122e1c_Unk_12332c(Unk122e1cWork *work)
{
  func_0205caa8(work->unk_0014,1);
}


int Unk0fedd4_SetState1();
/* decompiler-derived */
void Unk122e1c_Unk_123024(int arg0)
{
  Unk0fedd4_SetState1();
  ((Unk122e1cWork *)arg0)->unk_0114 = 0;
  ((Unk122e1cWork *)arg0)->unk_0061 = 0;
  ((Unk122e1cWork *)arg0)->unk_0060 = 1;
  return;
}


/* decompiler-derived */
void Unk122e1c_Unk_123048(int arg0)
{
  Unk0fedd4_SetState1();
  ((Unk122e1cWork *)arg0)->unk_0114 = 0;
  ((Unk122e1cWork *)arg0)->unk_0061 = 0;
  ((Unk122e1cWork *)arg0)->unk_0060 = 2;
  return;
}


/* decompiler-derived */
void Unk122e1c_Unk_1232f8(int arg0)
{
  Unk0fedd4_SetState1();
  ((Unk122e1cWork *)arg0)->unk_0114 = 0;
  ((Unk122e1cWork *)arg0)->unk_0061 = 0;
  ((Unk122e1cWork *)arg0)->unk_0060 = 6;
  return;
}

int Unk0fedd4_SetState0();
/* decompiler-derived */
void Unk122e1c_Unk_1232c8(int arg0)
{
  Unk0fedd4_SetState0();
  Unk0cb32c_Unk_0cb57c(((Unk122e1cWork *)arg0)->unk_0014);
  ((Unk122e1cWork *)arg0)->unk_0114 = 0;
  ((Unk122e1cWork *)arg0)->unk_00b8 = 0xffffffa4;
  ((Unk122e1cWork *)arg0)->unk_006c = 0xffffffa4;
  ((Unk122e1cWork *)arg0)->unk_0060 = 0;
  return;
}



/* decompiler-derived */
void Unk122e1c_Unk_122ff0(int arg0)
{
  Unk0fedd4_SetState0();
  Unk0cb32c_Unk_0cb57c(((Unk122e1cWork *)arg0)->unk_0010);
  ((Unk122e1cWork *)arg0)->unk_0114 = ((Unk122e1cWork *)arg0)->unk_011c + -1;
  ((Unk122e1cWork *)arg0)->unk_0061 = 0;
  ((Unk122e1cWork *)arg0)->unk_0060 = 3;
  return;
}


/* decompiler-derived */
void Unk122e1c_Unk_123294(int arg0)
{
  Unk0fedd4_SetState0();
  Unk0cb32c_Unk_0cb57c(((Unk122e1cWork *)arg0)->unk_0014);
  ((Unk122e1cWork *)arg0)->unk_0114 = ((Unk122e1cWork *)arg0)->unk_011c + -1;
  ((Unk122e1cWork *)arg0)->unk_0061 = 0;
  ((Unk122e1cWork *)arg0)->unk_0060 = 7;
  return;
}

void Unk122e1c_SetSlot();
/* decompiler-derived */
void Unk122e1c_Unk_12306c(int arg0)
{
  int tmp1;
  tmp1 = 0;
  ((Unk122e1cWork *)arg0)->unk_0114 = ((Unk122e1cWork *)arg0)->unk_011c + -1;
  ((Unk122e1cWork *)arg0)->unk_0061 = 0;
  ((Unk122e1cWork *)arg0)->unk_0060 = 5;
  do {
    Unk122e1c_SetSlot(arg0,tmp1,0);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 6);
  return;
}

extern u8 data_0213cd7c[];
void Unk122e1c_Unk_123534(Unk122e1cObj *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        Unk0cb32c_Unk_0cb504(p->h[i], (u8)p->unk4, (u8)(i + 110));
    }
}

/* decompiler-derived */
void Unk122e1c_Unk_1241cc(int arg0,int arg1)
{
  func_0205caa8(*(u32 *)(arg0 + arg1 * 4 + 0x10),
                  *(u32 *)(data_0213cd7c + arg1 * 4));
}
