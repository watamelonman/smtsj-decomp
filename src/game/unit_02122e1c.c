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

int func_0205caa8(u32 handle, u32 value);
int Unk0cb32c_Unk_0cb57c(u32 handle);

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
void Unk0cb32c_Unk_0cb504(u32 handle, u8 value, u8 index);
/* Store slot i at +0xf8 when p is nonnull and i is in [0, 6).
 * Evidence: 02122fac checks the pointer and bounds before the indexed store. */
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

/* Clear all six words at +0xf8; p must be writable.
 * Evidence: 02122fd0 loops over six indexed stores of zero. */
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


int Unk0fedd4_SetState1(void);
/* Call the state provider, clear +0x114 and +0x61, and set +0x60 to 1.
 * Evidence: stores at 0x02123024; work must be writable. */
void Unk122e1c_Unk_123024(Unk122e1cWork *work)
{
  Unk0fedd4_SetState1();
  work->unk_0114 = 0;
  work->unk_0061 = 0;
  work->unk_0060 = 1;
  return;
}


/* Call the state provider, clear +0x114 and +0x61, and set +0x60 to 2.
 * Evidence: stores at 0x02123048; work must be writable. */
void Unk122e1c_Unk_123048(Unk122e1cWork *work)
{
  Unk0fedd4_SetState1();
  work->unk_0114 = 0;
  work->unk_0061 = 0;
  work->unk_0060 = 2;
  return;
}


/* Call the state provider, clear +0x114 and +0x61, and set +0x60 to 6.
 * Evidence: stores at 0x021232f8; work must be writable. */
void Unk122e1c_Unk_1232f8(Unk122e1cWork *work)
{
  Unk0fedd4_SetState1();
  work->unk_0114 = 0;
  work->unk_0061 = 0;
  work->unk_0060 = 6;
  return;
}

int Unk0fedd4_SetState0(void);
/* Call both providers, clear +0x114 and +0x60, and write -92 to +0xb8/+0x6c.
 * Evidence: 021232c8 calls and stores; work must be writable. */
void Unk122e1c_Unk_1232c8(Unk122e1cWork *work)
{
  Unk0fedd4_SetState0();
  Unk0cb32c_Unk_0cb57c(work->unk_0014);
  work->unk_0114 = 0;
  work->unk_00b8 = 0xffffffa4;
  work->unk_006c = 0xffffffa4;
  work->unk_0060 = 0;
  return;
}



/* Call the state providers, set +0x114 to +0x11c minus one, and enter state 3.
 * Evidence: calls and stores at 02122ff0; work must be writable. */
void Unk122e1c_Unk_122ff0(Unk122e1cWork *arg0)
{
  Unk0fedd4_SetState0();
  Unk0cb32c_Unk_0cb57c(arg0->unk_0010);
  arg0->unk_0114 = arg0->unk_011c + -1;
  arg0->unk_0061 = 0;
  arg0->unk_0060 = 3;
  return;
}


/* Call the state providers, set +0x114 to +0x11c minus one, and enter state 7.
 * Evidence: calls and stores at 02123294; work must be writable. */
void Unk122e1c_Unk_123294(Unk122e1cWork *arg0)
{
  Unk0fedd4_SetState0();
  Unk0cb32c_Unk_0cb57c(arg0->unk_0014);
  arg0->unk_0114 = arg0->unk_011c + -1;
  arg0->unk_0061 = 0;
  arg0->unk_0060 = 7;
  return;
}

/* Set the countdown and state 5, then clear six slots through the checked setter.
 * Evidence: 0212306c stores and loop; work must include all six slots. */
void Unk122e1c_Unk_12306c(Unk122e1cWork *arg0)
{
  int tmp1;
  tmp1 = 0;
  arg0->unk_0114 = arg0->unk_011c + -1;
  arg0->unk_0061 = 0;
  arg0->unk_0060 = 5;
  do {
    Unk122e1c_SetSlot((Unk122e1cObj *)arg0,tmp1,0);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 6);
  return;
}

extern u32 data_0213cd7c[];
/* Forward two handles with the low byte of +4 and identifiers 110/111.
 * Evidence: indexed loads at 02123534; p borrows readable handle storage. */
void Unk122e1c_Unk_123534(Unk122e1cObj *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        Unk0cb32c_Unk_0cb504(p->h[i], (u8)p->unk4, (u8)(i + 110));
    }
}

/* Forward the indexed word at +0x10 and its table argument to the provider.
 * Evidence: 021241cc indexed loads; index must fit both borrowed arrays. */
void Unk122e1c_Unk_1241cc(Unk122e1cWork *work, s32 index)
{
  func_0205caa8(*(u32 *)((u8 *)work + index * 4 + 0x10),
                  *(u32 *)((u8 *)data_0213cd7c + index * 4));
}

/* Normalize value to 0/1 in the indexed word at +0x78.
 * Evidence: 0212351c conditional moves and indexed store; caller validates index. */
void func_0212351c(Unk122e1cWork *work, s32 value, s32 index)
{
    if (value == 0) {
        *(u32 *)((u8 *)work + index * 4 + 0x78) = 0;
    } else {
        *(u32 *)((u8 *)work + index * 4 + 0x78) = 1;
    }
}

/* Borrowed layout: array extents follow the loops at 02122e1c; counts at
 * +0x68/+0xb4 must fit their provider-owned arrays. */
typedef struct Unk122e1cFull {
    u32 prefix[2];
    u32 unk_0008, unk_000c;
    union {
        u32 handles[17];
        struct {
            u32 first[2];
            u32 a[7];
            u32 b[8];
        } groups;
    } resources;
    u32 unk_0054, unk_0058, unk_005c;
    u8 state, phase, pad_0062[2];
    u32 unk_0064;
    s32 count_a;
    s32 unk_006c, unk_0070;
    u32 unk_0074;
    u8 pad_0078[0x1c];
    u32 secondary[7];
    u32 unk_00b0;
    s32 count_b;
    s32 unk_00b8;
    u32 unk_00bc;
    s32 unk_00c0;
    u32 unk_00c4;
    u8 pad_00c8[0x18];
    u32 handles[6];
    u32 slots[6];
    u8 pad_0110[4];
    u32 unk_0114;
} Unk122e1cFull;

void func_020629c4(u32 handle);
void func_0205c3dc(u32 handle);
void func_0205c368(u32 handle);
void func_0205ddb4(u32 handle);
void func_02061424(Unk122e1cFull *work);
s32 func_0205ca88(u32 handle);
void func_0205c41c(u32 handle, s32 index);

/* Release and clear observed resources, then release work; null succeeds.
 * Evidence: provider calls and conditional clears at 02122e1c. Work is consumed. */
int func_02122e1c(Unk122e1cFull *work)
{
    int i;
    if (work == 0) return 1;
    for (i = 0; i < 6; i++) {
        func_020629c4(work->handles[i]);
        if (work->handles[i] != 0) work->handles[i] = 0;
    }
    for (i = 0; i < work->count_a; i++) {
        func_020629c4(work->secondary[i]);
        if (work->secondary[i] != 0) work->secondary[i] = 0;
    }
    if (work->unk_005c != 0) {
        func_0205c3dc(work->unk_005c);
        work->unk_005c = 0;
    }
    for (i = 0; i < 17; i++) {
        if (work->resources.handles[i] != 0) {
            func_0205c3dc(work->resources.handles[i]);
            work->resources.handles[i] = 0;
        }
    }
    if (work->unk_0058 != 0) {
        func_0205c368(work->unk_0058);
        work->unk_0058 = 0;
    }
    if (work->unk_0054 != 0) {
        func_0205ddb4(work->unk_0054);
        work->unk_0054 = 0;
    }
    if (work->unk_000c != 0) {
        func_0205c368(work->unk_000c);
        work->unk_000c = 0;
    }
    if (work->unk_0008 != 0) {
        func_0205ddb4(work->unk_0008);
        work->unk_0008 = 0;
    }
    func_02061424(work);
    return 1;
}

/* Reset +0xb8/+0xc0/+0xc4, notify count_b resources, and clear six slots.
 * Evidence: 021230b4 calls and stores; work and its counted resources must exist. */
void func_021230b4(Unk122e1cFull *work)
{
    int i;
    work->unk_00b8 = -92;
    work->unk_00c0 = 0;
    work->unk_00c4 = 0;
    for (i = 0; i < work->count_b; i++)
        Unk0cb32c_Unk_0cb57c(work->resources.groups.b[i]);
    func_0205caa8(work->resources.groups.first[0], 0);
    for (i = 0; i < 6; i++)
        Unk122e1c_SetSlot((Unk122e1cObj *)work, i, 0);
}

/* Initialize the first counted resource group at its final provider index and
 * enter state 8. Evidence: 02123340; counts must fit the borrowed arrays/table. */
void func_02123340(Unk122e1cFull *work)
{
    int i;
    Unk0fedd4_SetState1();
    work->unk_006c = 0;
    work->unk_0074 = 0x3f800000;
    work->unk_0070 = work->count_a * 15;
    for (i = 0; i < work->count_a; i++) {
        func_0205caa8(work->resources.groups.a[i], data_0213cd7c[i + 2]);
        func_0205c41c(work->resources.groups.a[i], func_0205ca88(work->resources.groups.a[i]) - 1);
    }
    func_0205caa8(work->resources.groups.first[0], 0);
    work->phase = 0;
    work->state = 8;
}

/* Initialize both counted groups and reset state/countdown fields.
 * Evidence: 021233e0 calls and stores; counts must fit the borrowed arrays/table. */
void func_021233e0(Unk122e1cFull *work)
{
    int i;
    work->unk_0064 = 0;
    work->unk_006c = -92;
    work->unk_0074 = 0x3f800000;
    work->unk_0070 = work->count_a * 15;
    for (i = 0; i < work->count_a; i++) {
        func_0205caa8(work->resources.groups.a[i], data_0213cd7c[i + 2]);
        func_0205c41c(work->resources.groups.a[i], func_0205ca88(work->resources.groups.a[i]) - 1);
    }
    func_0205caa8(work->resources.groups.first[0], 0);
    Unk0cb32c_Unk_0cb57c(work->resources.groups.first[0]);
    work->unk_00b0 = 3;
    work->unk_00b8 = -92;
    work->unk_00c4 = 0x3f800000;
    work->unk_00c0 = work->count_b * 15;
    for (i = 0; i < work->count_b; i++) {
        func_0205caa8(work->resources.groups.b[i], data_0213cd7c[i + 9]);
        func_0205c41c(work->resources.groups.b[i], func_0205ca88(work->resources.groups.b[i]) - 1);
    }
    func_0205caa8(work->resources.groups.first[1], 1);
    Unk0cb32c_Unk_0cb57c(work->resources.groups.first[1]);
    work->unk_0114 = 0;
    work->phase = 0;
    work->state = 0;
}
