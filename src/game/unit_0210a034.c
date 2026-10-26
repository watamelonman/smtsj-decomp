/*
 * src/game/unit_0210a034.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk10a034Work {
    u8 pad_0000[0x4];
    s32 unk_0004;
    u32 unk_0008;
    u8 pad_000c[0x4];
    u32 unk_0010;
    u8 pad_0014[0x10];
    u16 unk_0024;
    u8 pad_0026[0x6];
    u32 unk_002c;
    u8 pad_0030[0x84];
    u16 unk_00b4;
} Unk10a034Work;

extern u32 data_02176e38[];
extern u32 data_02176e3c[];
extern u32 data_02176e44[];
void func_02061424(Unk10a034Work *work);
const u8 *func_020a1740(u32 id);

u32 Unk10a034_Get_data_02176e38(void);
u32 Unk10a034_Get_data_02176e3c(void);
u32 Unk10a034_Unk_10af7c(void);
u32 Unk10a034_Get_data_02176e44(void);
void Unk10a034_Clear_data_02176e38(void);
void Unk10a034_Unk_10a9a4(Unk10a034Work *work,u32 arg1,int arg2);
void Unk10a034_Clear_data_02176e44(void);
void Unk10a034_Unk_10b394(Unk10a034Work *work,u32 arg1,int arg2);
void Unk10a034_Unk_10a05c(void);
void Unk10a034_Unk_10a074(void);
u32 Unk10a034_Unk_10a0b4(void);
int Unk10a034_Unk_10afc0(void);
void Unk10a034_Unk_10b000(void);
void Unk10a034_Unk_10b018(void);
int Unk10a034_Unk_10b058(u32 id);
void Unk10a034_Unk_10aeb0(u8 *work);

/* Returns the word at 0x02176e38; the original loads this global directly. */
u32 Unk10a034_Get_data_02176e38(void)
{
  return *data_02176e38;
}

/* Returns the first word at 0x02176e3c; the original loads this global directly. */
u32 Unk10a034_Get_data_02176e3c(void)
{
  return *data_02176e3c;
}

/* Returns the word at +4 from data_02176e3c, as observed in the original load. */
u32 Unk10a034_Unk_10af7c(void)
{
  return data_02176e3c[1];
}

/* Returns the word at 0x02176e44; the original loads this global directly. */
u32 Unk10a034_Get_data_02176e44(void)
{
  return *data_02176e44;
}

/* Clears the word at 0x02176e38; the original stores zero to this global. */
void Unk10a034_Clear_data_02176e38(void)
{
  *data_02176e38 = 0;
}

/* Requires writable work: preserves arg1 at +0x10 and sets +8 to arg1 or, when arg2 is zero, 0x11. Evidence: original stores and conditional move at 0x0210a9a4. */
void Unk10a034_Unk_10a9a4(Unk10a034Work *work,u32 arg1,int arg2)
{
  work->unk_0010 = arg1;
  if (arg2 == 0) {
    arg1 = 0x11;
  }
  work->unk_0008 = arg1;
}

/* Clears the word at 0x02176e44; the original stores zero to this global. */
void Unk10a034_Clear_data_02176e44(void)
{
  *data_02176e44 = 0;
}

/* Requires writable work: preserves arg1 at +0x10 and sets +8 to arg1 or, when arg2 is zero, 8. Evidence: original stores and conditional move at 0x0210b394. */
void Unk10a034_Unk_10b394(Unk10a034Work *work,u32 arg1,int arg2)
{
  work->unk_0010 = arg1;
  if (arg2 == 0) {
    arg1 = 8;
  }
  work->unk_0008 = arg1;
}

/* Borrows the global work, passing it to func_02061424 only when present.
 * Evidence: original call at 0x0210a06c preserves the getter result in r0. */
void Unk10a034_Unk_10a05c(void)
{
  int value;
  value = Unk10a034_Get_data_02176e38();
  if (value == 0) {
    return;
  }
  func_02061424((Unk10a034Work *)value);
}

/* Restores the borrowed work's +8 word from +0x10 when present.
 * Evidence: original conditional load/store; no ownership is transferred. */
void Unk10a034_Unk_10a074(void)
{
  Unk10a034Work *work = (Unk10a034Work *)Unk10a034_Get_data_02176e38();
  if (work != 0) {
    work->unk_0008 = work->unk_0010;
  }
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk10a034Ent {
    u16 id;
    u16 pad;
    u32 used;
    u32 val;
} Unk10a034Ent;
typedef struct Unk10a034Obj {
    u8 pad[200];
    u16 ids[4];
} Unk10a034Obj;
/* Returns true when global work is absent or its +8 word is 18.
 * Evidence: conditional return and comparison at 0x0210a094..0x0210a0ac. */
int Unk10a034_Unk_10a08c(void)
{
    u32 p = Unk10a034_Get_data_02176e38();
    if (p == 0) {
        return 1;
    }
    return FIELD(u32, p, 8) == 18;
}

/* Returns the global work word at +0x18, or 1 when absent.
 * Evidence: original conditional load at 0x0210a0c4. */
u32 Unk10a034_Unk_10a0b4(void)
{
  int value1;
  u32 value2;
  value1 = Unk10a034_Get_data_02176e38();
  if (value1 == 0) {
    value2 = 1;
  }
  else {
    value2 = *(u32 *)(value1 + 0x18);
  }
  return value2;
}

/* Returns a borrowed address at global work +0x18, or zero when absent.
 * Evidence: original conditional addition at 0x0210afd0. */
int Unk10a034_Unk_10afc0(void)
{
  int value;
  value = Unk10a034_Unk_10af7c();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x18;
  }
  return value;
}

/* Borrows the second global work for func_02061424 when present.
 * Evidence: original call at 0x0210b010 passes the getter result in r0. */
void Unk10a034_Unk_10b000(void)
{
  int value;
  value = Unk10a034_Get_data_02176e44();
  if (value == 0) {
    return;
  }
  func_02061424((Unk10a034Work *)value);
}

/* Restores the borrowed work's +8 word from +0x10 when present.
 * Evidence: original conditional load/store; no ownership is transferred. */
void Unk10a034_Unk_10b018(void)
{
  Unk10a034Work *work = (Unk10a034Work *)Unk10a034_Get_data_02176e44();
  if (work != 0) {
    work->unk_0008 = work->unk_0010;
  }
}

/* Scales the provider record's unsigned byte at +2 by 300. The provider
 * must return a readable record; evidence: ldrb/mul at 0x0210b060..68. */
int Unk10a034_Unk_10b058(u32 id)
{
  const u8 *record = func_020a1740(id);
  return record[2] * 300;
}

/* Clears twelve words starting at +0x2c with a twelve-byte stride.
 * Borrows writable storage through +0xb3; evidence: loop at 0x0210aeb8. */
void Unk10a034_Unk_10aeb0(u8 *work)
{
  int i = 0;
  do {
    i++;
    *(u32 *)(work + 0x2c) = 0;
    work += 12;
  } while (i < 12);
}



/* Initializes seven writable words: two caller values followed by five zeros.
 * Evidence: stores at 0x0210b104..0x0210b11c; caller allocates 28 bytes. */
void Unk10a034_Unk_10b104(u32 *arg0,u32 arg1,u32 arg2)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  return;
}

u32 func_020d2eb0(u32 id);
/* Updates the cached ID and provider result only when the ID changes.
 * Evidence: comparison/store at 0x0210af4c and provider call at 0x0210af58. */
void Unk10a034_Unk_10af40(u32 arg0)
{
  int tmp1;
  if (*data_02176e3c == arg0) {
    return;
  }
  *data_02176e3c = arg0;
  tmp1 = func_020d2eb0(arg0);
  data_02176e3c[1] = tmp1;
  return;
}

void func_0204faf0(u32 index, u32 value);
void func_02065864(u32 handle, s32 value);
u32 Unk0d297c_Unk_0d2f98(u32 id);
/* Passes the halfword at +0xb4 to provider slot 7, invokes provider ID 22,
 * then sets the linked work word at +0x18 to 28 (0x0210af0c..0x0210af38).
 * Both work and its +4 link must be valid borrowed writable storage. */
void Unk10a034_Unk_10af0c(Unk10a034Work *arg0)
{
  u32 tmp1;
  func_0204faf0(7,((Unk10a034Work *)arg0)->unk_00b4);
  tmp1 = Unk0d297c_Unk_0d2f98(0x16);
  func_02065864(tmp1,0xffffffff);
  *(u32 *)(((Unk10a034Work *)arg0)->unk_0004 + 0x18) = 0x1c;
  return;
}

int Unk02e000_GetAreaRecord();
int Unk02e000_HasField36();
int Unk096754_Unk_096ab0();
int func_020a1428();
/* decompiler-derived */
void Unk10a034_Unk_10ac28(int arg0)
{
  int tmp1;
  int tmp2;
  int tmp3;
  u16 *v4;
  tmp3 = 0;
  v4 = (u16 *)(arg0 + 0x24);
  do {
    tmp1 = Unk02e000_GetAreaRecord(tmp3);
    tmp2 = Unk02e000_HasField36();
    if (tmp2 == 0) {
      *(u32 *)(v4 + 2) = 0;
    }
    else {
      tmp2 = Unk096754_Unk_096ab0(tmp3);
      if (tmp2 == 0) {
        *(u32 *)(v4 + 2) = 0;
      }
      else {
        *(u32 *)(v4 + 2) = 1;
        *(u32 *)(v4 + 4) = 0;
        *v4 = *(u16 *)(tmp1 + 0x36);
        tmp1 = func_020a1428(((Unk10a034Work *)arg0)->unk_0024);
        v4[1] = (u16)*(u8 *)(tmp1 + 2);
      }
    }
    tmp3 = tmp3 + 1;
    v4 = v4 + 6;
    arg0 = arg0 + 0xc;
  } while (tmp3 < 0xc);
}

/* Tests the four halfword IDs at +0xc8 without taking ownership.
 * Evidence for HasId: indexed ldrh/comparison loop at 0x0210aee0..0x0210aefc. */
int Unk10a034_HasId(Unk10a034Obj *p, u32 x)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (x == p->ids[i]) {
            return 1;
        }
    }
    return 0;
}

/* Clears the first used entry with this ID; borrows twelve writable entries.
 * Evidence for ClearById: ID comparison and +8 zero store at 0x0210ae98. */
void Unk10a034_ClearById(u8 *p, u32 id)
{
    int i;
    Unk10a034Ent *e = (Unk10a034Ent *)(p + 36);
    for (i = 0; i < 12; i++) {
        if (e->used != 0 && e->id == id) {
            e->val = 0;
            return;
        }
        e++;
    }
}

u32 func_0210b080(u32 a, u32 b);
/* Returns a borrowed eight-byte entry for indices 0..3, or zero.
 * Evidence for GetEntry8: bounds checks and index shift at 0x0210af8c. */
u32 Unk10a034_GetEntry8(int i)
{
    u32 p;
    if (i < 0 || i >= 4) {
        return 0;
    }
    p = Unk10a034_Unk_10af7c();
    return p == 0 ? 0 : p + 32 + i * 8;
}

/* Creates the global work only when absent, forwarding both caller words.
 * Evidence for Alloc: func_0210b080 requests 28 bytes via func_020611dc. */
void Unk10a034_Alloc(u32 a, u32 b)
{
    if (*data_02176e44 != 0) {
        return;
    }
    *data_02176e44 = func_0210b080(a, b);
}

/* Returns true when second global work is absent or its +8 word is 10.
 * Evidence: conditional return and comparison at 0x0210b038..0x0210b050. */
int Unk10a034_Unk_10b030(void)
{
    u32 p = Unk10a034_Get_data_02176e44();
    if (p == 0) {
        return 1;
    }
    return FIELD(u32, p, 8) == 10;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

/* Reads the linked descriptor only when +0x18 is set; returns its +0x1c
 * word or scaled provider value. Evidence: cases at 0x0210b484. */
int Unk10a034_Unk_10b484(u8 *p)
{
    u8 *q;
    if (FIELD(u32, p, 24) == 0) {
        return 0;
    }
    q = FIELD(u8 *, p, 20);
    switch (FIELD(u16, q, 24)) {
    case 2:
        return FIELD(int, q, 28);
    case 3:
        return Unk10a034_Unk_10b058(FIELD(u16, q, 26));
    }
    return 0;
}

u32 func_0210a0dc(u32 a, u32 b);

/* Populates the first global work only when absent, forwarding two words.
 * Evidence: guarded provider call and global store at 0x0210a034..0x0210a054. */
void func_0210a034(u32 a, u32 b)
{
    if (*data_02176e38 != 0) {
        return;
    }
    *data_02176e38 = func_0210a0dc(a, b);
}

/* Selects the first used, unmarked entry with the requested +2 halfword.
 * Evidence: scan at 0x0210acac; a nonzero mark claims its +8 word. */
u32 func_0210acac(u8 *work, u32 kind, int mark)
{
    int i;
    Unk10a034Ent *entry = (Unk10a034Ent *)(work + 0x24);
    for (i = 0; i < 12; i++, entry++) {
        if (entry->used != 0 && entry->val == 0 && entry->pad == kind) {
            if (mark != 0) entry->val = 1;
            return entry->id;
        }
    }
    return 0;
}

/* Counts unmarked entries of the requested kind whose IDs are absent from
 * the four-ID list. Evidence: scan and HasId call at 0x0210ad00. */
int func_0210ad00(Unk10a034Obj *work, u32 kind)
{
    int count = 0;
    int i;
    Unk10a034Ent *entry = (Unk10a034Ent *)((u8 *)work + 0x24);
    for (i = 0; i < 12; i++, entry++) {
        if (entry->used != 0 && entry->pad == kind && entry->val == 0) {
            if (!Unk10a034_HasId(work, entry->id)) count++;
        }
    }
    return count;
}

int Unk096754_Unk_096b44(u32 id);
/* Recomputes +0x18 from the linked descriptor; both borrowed objects must
 * exist. Evidence: descriptor cases and provider test at 0x0210b42c. */
void func_0210b42c(u8 *work)
{
    u8 *record;
    FIELD(u32, work, 0x18) = 0;
    record = FIELD(u8 *, work, 0x14);
    switch (FIELD(u16, record, 0x18)) {
    case 1: return;
    case 2: FIELD(u32, work, 0x18) = 1; return;
    case 3:
        if (Unk096754_Unk_096b44(FIELD(u16, record, 0x1a)) == 0)
            FIELD(u32, work, 0x18) = 1;
        return;
    }
}

u32 func_020611dc(void (*update)(u8 *), u32 hook1, u32 hook2,
                 void (*cleanup)(void), u32 size, u32 priority, u32 flags, u32 enabled);
void func_0210a1d8(u8 *work);
void func_0210b124(u8 *work);
void func_0210a160(u32 *work, u32 a, u32 b);
/* Allocates 216 bytes with the original callbacks and initializes the work.
 * Evidence: allocator arguments at 0x0210a0dc; returns zero on failure. */
u32 func_0210a0dc(u32 a, u32 b)
{
    u32 work = func_020611dc(func_0210a1d8, 0, 0,
        Unk10a034_Clear_data_02176e38, 216, 3, 0, 1);
    if (work == 0) return 0;
    func_0210a160((u32 *)work, a, b);
    return work;
}

/* Allocates 28 bytes with the original callbacks and initializes seven words.
 * Evidence: allocator arguments at 0x0210b080; returns zero on failure. */
u32 func_0210b080(u32 a, u32 b)
{
    u32 work = func_020611dc(func_0210b124, 0, 0,
        Unk10a034_Clear_data_02176e44, 28, 3, 0, 1);
    if (work == 0) return 0;
    Unk10a034_Unk_10b104((u32 *)work, a, b);
    return work;
}
