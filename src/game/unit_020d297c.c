/*
 * src/game/unit_020d297c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0d297cWork {
    u8 pad_0000[0x14];
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    s32 unk_0020;
} Unk0d297cWork;


void Unk094fe0_SetUnkField9a0(u32 value);
u32 Unk094fe0_GetWorkUnkField9a0(void);
int Unk0e5fb8_Unk_0e6448(u32 index);
void Unk0e5fb8_Unk_0e64c8(u32 value);
void Unk0e651c_Unk_0e651c(u32 value, u32 mode);

int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(u32 index);
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(u32 value);
void Unk0d297c_Thunk_02095398(u32 value);
u32 Unk0d297c_Thunk_020953ac(void);
void Unk0d297c_Unk_0d2adc(u32 arg0);
/** Borrowed buffer view; +0x0c is the index used by the 0x020d32f8 accessor. */
typedef struct Unk0d297cBuffer {
    u16 *data;
    s32 unk_0004;
    s32 unk_0008;
    s32 index;
} Unk0d297cBuffer;

u16 Unk0d297c_Unk_0d32e8(const Unk0d297cBuffer *buffer, int index);
u16 *Unk0d297c_Unk_0d32f8(const Unk0d297cBuffer *buffer);

void func_020d297c(u16 id);
/** Add 50 and truncate to a halfword before forwarding; see 0x020d2a8c. */
void Unk0d297c_Call_020d297c(u32 id)
{
    func_020d297c((u16)(id + 50));
}

/** Forward the table index unchanged (branch at 0x020d2b58).
 * The target saves r0 as the Get2BitsD80 index and returns its low pair (0..3).
 * Evidence: 0x020e6490 combines the bits; 0x020e6494 masks the result to u8. */
int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(u32 index) { return Unk0e5fb8_Unk_0e6448(index); }

/** Forward the caller value unchanged; target 0x020e64c8 accepts it in r0. */
void Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(u32 value) { Unk0e5fb8_Unk_0e64c8(value); }

/** Forward the value to the +0x9a0 setter, as shown by the target branch. */
void Unk0d297c_Thunk_02095398(u32 value) { Unk094fe0_SetUnkField9a0(value); }

/** Preserve the +0x9a0 getter result, as shown by the target branch. */
u32 Unk0d297c_Thunk_020953ac(void) { return Unk094fe0_GetWorkUnkField9a0(); }

/** Forward the caller value with mode zero, evidenced by mov r1, #0 at 0x020d2adc. */
void Unk0d297c_Unk_0d2adc(u32 arg0)
{
  Unk0e651c_Unk_0e651c(arg0,0);
}

/** Read a halfword without bounds checks; caller must supply a valid index (0x020d32e8). */
u16 Unk0d297c_Unk_0d32e8(const Unk0d297cBuffer *buffer, int index)
{
    return buffer->data[index];
}

/** Return the borrowed buffer address at the +0x0c index; caller guarantees validity. */
u16 *Unk0d297c_Unk_0d32f8(const Unk0d297cBuffer *buffer)
{
    return buffer->data + buffer->index;
}

/** Store the first two words and clear +0x0c/+0x10; +0x08 is preserved (0x020d3250). */
void Unk0d297c_Unk_0d3250(u32 *arg0,u32 arg1,u32 arg2)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[3] = 0;
  arg0[4] = 0;
}


/** Read the halfword at the signed +0x04 index; caller guarantees validity (0x020d32ac). */
u16 Unk0d297c_Unk_0d32ac(const Unk0d297cBuffer *buffer)
{
  return buffer->data[buffer->unk_0004];
}


/** Clear words +0x04, +0x00, +0x0c and +0x10, preserving +0x08 (0x020d31e8). */
void Unk0d297c_Unk_0d31e8(u32 *arg0)
{
  arg0[1] = 0;
  *arg0 = 0;
  arg0[3] = 0;
  arg0[4] = 0;
}


/** Write without advancing +0x04 when signed index < +0x08; no lower bound check (0x020d3290). */
void Unk0d297c_Unk_0d3290(Unk0d297cBuffer *buffer, u16 value)
{
  if (buffer->unk_0004 < buffer->unk_0008) {
    buffer->data[buffer->unk_0004] = value;
  }
}

int func_02053000();
void Unk0d297c_FreeSlot();
/** Release the leading slot, then release and clear +0x18; call order from 0x020d33ac. */
void Unk0d297c_Unk_0d33ac(Unk0d297cWork *work)
{
  Unk0d297c_FreeSlot((u32 *)work);
  func_02053000(work->unk_0018);
  work->unk_0018 = 0;
}


int func_0204459c();
int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk0d297c_Unk_0d2f18(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk0d297c_Unk_0d2f3c(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,1);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk0d297c_Unk_0d2f98(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1d);
  value = func_0204fe68(value,3);
  func_0204fed8(value,arg0);
}

int Unk02dcfc_SetField64();
int func_02095818();
void Unk0d297c_Unk_0d2aa4();
/* decompiler-derived */
void Unk0d297c_Unk_0d2b70(u32 arg0)
{
  int value;
  Unk0e651c_Unk_0e654c();
  Unk0d297c_Unk_0d2aa4(arg0);
  value = func_02095818();
  if (value == 1) {
    return;
  }
  Unk02dcfc_SetField64();
}

int Unk094fe0_Call_02095370();
void Unk0d297c_Unk_0d2aec();
/* decompiler-derived */
void Unk0d297c_Unk_0d2c1c(u32 arg0)
{
  Unk0e651c_Unk_0e6560();
  Unk094fe0_Call_02095370(arg0,1);
  Unk0d297c_Unk_0d2aec(arg0);
  Unk02dcfc_SetField64();
}

extern u32 data_02176be0[];
/* decompiler-derived */
u32 Unk0d297c_Unk_0d2e88(void)
{
  func_02053000(*data_02176be0);
  *data_02176be0 = 0;
  return 1;
}


/* decompiler-derived */
u16 Unk0d297c_Unk_0d32c0(int *arg0)
{
  if (arg0[1] < arg0[2] + -1) {
    return *(u16 *)(*arg0 + arg0[1] * 2 + 2);
  }
  return 0;
}


int func_02008848();
/* decompiler-derived */
void Unk0d297c_Unk_0d3330(Unk0d297cWork *arg0){
  func_02008848(arg0->unk_0018,0,arg0->unk_0020 << 2);
  arg0->unk_001c = 0;
  return;
}

int func_02052fe0();
/* decompiler-derived */
void Unk0d297c_Unk_0d3200(u32 *arg0,int arg1)
{
  u32 tmp1;
  arg0[1] = 0;
  arg0[2] = arg1;
  tmp1 = func_02052fe0(arg1 << 1);
  *arg0 = tmp1;
  arg0[3] = 0;
  arg0[4] = 0;
  return;
}



int func_020d2eb0();
/* decompiler-derived */
u32 Unk0d297c_Unk_0d2fbc(u32 arg0)
{
  int tmp1;
  u32 tmp2;
  if (*data_02176be0 == 0) {
    return 0;
  }
  tmp1 = func_020d2eb0(arg0);
  if (tmp1 != 0) {
    tmp2 = func_0204fe68(*data_02176be0,0);
    tmp2 = func_0204fed8(tmp2,*(u32 *)(tmp1 + 0x40));
    return tmp2;
  }
  return 0;
}

int func_0204fb14();
/* decompiler-derived */
u32 Unk0d297c_Unk_0d3034(u32 arg0,u32 arg1)
{
  u16 tmp1;
  u32 tmp2;
  switch(arg0) {
  case 0:
    break;
  case 1:
    tmp2 = Unk09974c_Unk_099bac(arg1);
    return tmp2;
  case 2:
    return 0;
  case 3:
    tmp2 = Unk0a163c_Unk_0a1814(arg1);
    return tmp2;
  case 4:
    tmp1 = func_0204fb14(2);
    tmp2 = Unk0a163c_Unk_0a1814(tmp1);
    return tmp2;
  }
  return 0;
}

extern u8 data_02150680[];
int func_02051610();
/** Load Data/Event/Mission/MissionLog.mbb (data_02150680 string), store its handle, return 1. */
u32 Unk0d297c_LoadMissionLog(void)
{
  u32 tmp1;
  tmp1 = func_02051610(data_02150680);
  *data_02176be0 = tmp1;
  return 1;
}

/* decompiler-derived */
void Unk0d297c_Unk_0d3308(int arg0)
{
  Unk0d297c_Unk_0d31e8((u32 *)arg0);
  ((Unk0d297cWork *)arg0)->unk_0014 = 0;
  ((Unk0d297cWork *)arg0)->unk_0018 = 0;
  ((Unk0d297cWork *)arg0)->unk_001c = 0;
  ((Unk0d297cWork *)arg0)->unk_0020 = 0x100;
}

/* decompiler-derived */
void Unk0d297c_Unk_0d3358(int arg0, int arg1)
{
  u32 tmp1;
  if (((Unk0d297cWork *)arg0)->unk_0014 == 0) {
    Unk0d297c_Unk_0d3200((u32 *)arg0, (int)arg1);
    if (((Unk0d297cWork *)arg0)->unk_0018 != 0) {
      func_02053000();
      ((Unk0d297cWork *)arg0)->unk_0018 = 0;
    }
    tmp1 = func_02052fe0(((Unk0d297cWork *)arg0)->unk_0020 << 2);
    ((Unk0d297cWork *)arg0)->unk_0018 = tmp1;
    ((Unk0d297cWork *)arg0)->unk_0014 = 1;
  }
  Unk0d297c_Unk_0d3330((Unk0d297cWork *)arg0);
}

void Unk0e5fb8_Unk_0e649c(u32 obj, int mode);

/* Mode 1 setup unless Unk0e5fb8_Unk_0e6448 reports already active. */
void Unk0d297c_Unk_0d2aa4(u32 obj)
{
    if (Unk0e5fb8_Unk_0e6448(obj) != 0) {
        return;
    }
    Unk0e5fb8_Unk_0e649c(obj, 1);
    Unk0e651c_Unk_0e651c(obj, 1);
    Unk094fe0_SetUnkField9a0(obj);
}

/** Pass mode 2 only for a nonzero query result; cmp/popeq at 0x020d2af8-0x020d2afc establishes the guard. */
void Unk0d297c_Unk_0d2aec(u32 obj)
{
    if (Unk0e5fb8_Unk_0e6448(obj) == 0) {
        return;
    }
    Unk0e5fb8_Unk_0e649c(obj, 2);
}

int Unk0e651c_Unk_0e666c(u32 index);
typedef struct Unk0d297cU16Vec {
    u16 *buf;
    int n;
    int cap;
} Unk0d297cU16Vec;
int Unk0d297c_Unk_0d3004(void)
{
    int v;
    if (*data_02176be0 == 0) {
        return 0;
    }
    v = func_0204fe68(*data_02176be0, 0);
    return func_0204fed8(v, 0);
}

/** Query index 0x751; the literal and branch to 0x020e666c establish this contract. */
int Unk0d297c_Unk_0d3138(void)
{
    return Unk0e651c_Unk_0e666c(0x751);
}

/* Frees *slot (if set) and clears it. */
void Unk0d297c_FreeSlot(u32 *slot)
{
    if (*slot == 0) {
        return;
    }
    func_02053000();
    *slot = 0;
}

void Unk0d297c_PushU16(Unk0d297cU16Vec *v, u16 x)
{
    if (v->n < v->cap) {
        v->buf[v->n] = x;
        v->n++;
    }
}
