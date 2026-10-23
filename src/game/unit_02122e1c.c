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

void Unk122e1c_SetUnkFields64_b0(Unk122e1cWork *obj, u32 a, u32 b);
void Unk122e1c_Unk_122f88(Unk122e1cWork *work, s32 index, u32 value);
u32 Unk122e1c_Unk_122f94(Unk122e1cWork *work, s32 index);
void Unk122e1c_Unk_122fa0(Unk122e1cWork *work, s32 index, u32 value);
void Unk122e1c_Unk_12331c(Unk122e1cWork *work);
int Unk122e1c_Unk_122f54(Unk122e1cWork *work);
int Unk122e1c_Unk_122f68(Unk122e1cWork *work);
void Unk122e1c_Unk_12332c(Unk122e1cWork *work);

/* Original stores at 0x02122f7c: write the two independent work fields.
 * obj must refer to a writable work object; neither value is range checked. */
void Unk122e1c_SetUnkFields64_b0(Unk122e1cWork *obj, u32 a, u32 b) {
    obj->unk_0064 = a;
    obj->unk_00b0 = b;
}

/* Original 0x02122f88 stores a word at +0x78 + index*4.
 * The caller must supply an index within the backing work storage. */
void Unk122e1c_Unk_122f88(Unk122e1cWork *work, s32 index, u32 value)
{
  *(u32 *)((u8 *)work + index * 4 + 0x78) = value;
}

/* Original 0x02122f94 reads the word at +0x78 + index*4.
 * The caller must supply an index within the backing work storage. */
u32 Unk122e1c_Unk_122f94(Unk122e1cWork *work, s32 index)
{
  return *(u32 *)((u8 *)work + index * 4 + 0x78);
}

/* Original 0x02122fa0 stores a word at +0xc8 + index*4.
 * The caller must supply an index within the backing work storage. */
void Unk122e1c_Unk_122fa0(Unk122e1cWork *work, s32 index, u32 value)
{
  *(u32 *)((u8 *)work + index * 4 + 0xc8) = value;
}

/* Forward the word at +0x14 to Unk0cb32c_Unk_0cb57c, as seen at
 * 0x0212331c. The work object must be readable; the result is discarded. */
void Unk122e1c_Unk_12331c(Unk122e1cWork *work)
{
  Unk0cb32c_Unk_0cb57c(work->unk_0014);
}

/* Return exactly 1 when the byte at +0x60 is zero, otherwise 0.
 * Evidence: ldrb/cmp at 0x02122f54; work must be readable. */
int Unk122e1c_Unk_122f54(Unk122e1cWork *work)
{
  return work->unk_0060 == '\0';
}

/* Return exactly 1 when the byte at +0x60 is eight, otherwise 0.
 * Evidence: ldrb/cmp at 0x02122f68; work must be readable. */
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

/* Forward the word at +0x14 and constant 1 to func_0205caa8.
 * Evidence: 0x0212332c; work must be readable and the result is discarded. */
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
