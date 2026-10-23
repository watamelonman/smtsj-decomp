/* src/game/unit_020bd5f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0bd5f0Work {
    u8 pad_0000[0x150];
    u32 unk_0150;
    u32 unk_0154;
    u32 unk_0158;
    u32 unk_015c;
} Unk0bd5f0Work;


/* 60-byte record in the shared work area; only these two fields are read here. */
typedef struct Unk0bd5f0Record {
    u8 pad_0000[0x1a];
    s16 unk_001a; /* work-area +0x92 for record 0 */
    u8 pad_001c[0x14];
    u16 unk_0030; /* work-area +0xa8 for record 0 */
    u8 pad_0032[0xa];
} Unk0bd5f0Record;

/* View of the work area returned by Unk02e000_GetWorkArea. The record array base
   (+0x78) and count (12) are guesses: +0x78 keeps both record fields inside one
   60-byte record, and 12 records end exactly at the +0x348 map. */
typedef struct Unk0bd5f0WorkArea {
    u8 pad_0000[0x78];
    Unk0bd5f0Record unk_0078[12];
    s8 unk_0348[12]; /* signed record indices; size 12 assumed to match the records */
    s8 unk_0354[3];
    u8 unk_0357; /* number of valid unk_0348 entries */
} Unk0bd5f0WorkArea;

/* Object passed to func_020c84c0; layout from the accesses in that function. */
typedef struct Unk0bd5f0SelectObj {
    u8 pad_0000[0x44];
    u8 unk_0044[0x10]; /* sub-object passed to func_020bcfc4; size unknown */
    u32 unk_0054;
    u8 pad_0058[0xb0];
    void *unk_0108;
    u8 pad_010c[0x4];
    u8 unk_0110;
    u8 pad_0111[0x13];
    u8 unk_0124; /* stack count */
    u8 pad_0125[0x3];
    u32 unk_0128[1]; /* stack entries; real length unknown */
} Unk0bd5f0SelectObj;

/* Callback addresses are stored here without invoking them; their full calling
   contracts are not established by these descriptor initializers. */
typedef struct Unk0bd5f0Descriptor {
    u32 size;
    u32 kind;
    u32 unk_0008;
    void (*unk_000c)(void *);
    void (*unk_0010)(void *);
    u32 unk_0014;
    void (*unk_0018)(void *);
    void (*unk_001c)(void *);
    void (*unk_0020)(void *);
} Unk0bd5f0Descriptor;

extern void func_020bf240(void *);
extern void func_020bda18(void *);
extern void func_020bfddc(void *);
extern void func_020c0c5c(void *);
extern void func_020c0d48(void *);
extern void func_020c5094(void *);
extern void func_020c25d0(void *);
extern void func_020c5dc0(void *);
extern void func_020c67a0(void *);
extern void func_020c6888(void *);
extern u32 *func_020445f4(u32 group, u32 selector);
extern void func_02063920(void);
extern u32 func_0204fed8(u32 *table, u32 index);
extern u32 func_02063a30(u32 value);
extern void func_02061f10(void *obj, int a, int b, int c, u32 value);
extern void func_020c7304(void *obj);
extern void func_020bcfc4(void *obj, u32 value);
extern void Unk0a0ce4_Unk_0a0da4(u32 value);

extern u8 data_0213c4d4[];
int func_02057ddc();
int Unk02e000_GetWorkArea();
/* Non-zero only for an object whose state word at +8 is 2 and whose value at +4 is at least 2
   (the caller compares the result as a predicate). */
int Unk0bd5f0_Unk_0bd5f0(s32 *p)
{
    if (p[2] == 2 && p[1] >= 2) {
        return 1;
    }
    return 0;
}

/* Forwards the word at data_0213c4d4[index] to func_02057ddc (which copies it into four
   consecutive words of data_02168b24) and always reports 0. */
u32 Unk0bd5f0_Unk_0bd614(int arg0)
{
  func_02057ddc(*(u32 *)(((int)data_0213c4d4) + arg0 * 4));
  return 0;
}

int func_020c8008();
int Unk02e000_GetWorkArea();
void *Unk09974c_Unk_099d78(u32 id);
int Unk09974c_Unk_0998d8(u32 id);
int Unk09974c_HasFlagsMid(void *f);
void CampStatus_Unk_0dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n);
void Unk0ddeb0_Unk_0ddeb0(void *obj, int a, int b, int c, int d, int e);
void func_020c72a4(void *obj, u32 a, u32 b);
/* Returns the first matching signed-byte entry at +0x348, or the count at +0x357.
   i indexes the caller-owned three-entry mapping at +0x354. */
int Unk0bd5f0_Unk_0c1870(int i)
{
    Unk0bd5f0WorkArea *w = (Unk0bd5f0WorkArea *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < w->unk_0357; j++) {
        if (w->unk_0348[j] == w->unk_0354[i]) {
            break;
        }
    }
    return j;
}

/* For a nonnegative signed mapping at +0x348+i, tests the mapped 60-byte
   record: true when its +0xa8 halfword is 1 or its signed +0x92 halfword is <= 0. */
int Unk0bd5f0_Unk_0c1918(int i)
{
    Unk0bd5f0WorkArea *w = (Unk0bd5f0WorkArea *)Unk02e000_GetWorkArea();
    s32 k = w->unk_0348[i];
    if (k >= 0) {
        if (w->unk_0078[k].unk_0030 == 1 || w->unk_0078[k].unk_001a <= 0) {
            return 1;
        }
    }
    return 0;
}

/* Tail-calls func_020c8008 with all four arguments zero. */
void Unk0bd5f0_Unk_0c1ad8(void)
{
  func_020c8008(0,0,0,0);
}

extern u32 data_02176bb0[];
int func_020c1b94();
/* Calls func_020c1b94 on the object stored in data_02176bb0 when that pointer is non-null. */
void Unk0bd5f0_Unk_0c20f0(void)
{
  if (*data_02176bb0 == 0) {
    return;
  }
  func_020c1b94();
}


/* Lexicographic ordering of two 16-bit key pairs: compares the word at +2 first and, when those
   are equal, the word at +0. Returns a negative, zero or positive difference. */
int Unk0bd5f0_Unk_0c7588(u16 *arg0,u16 *arg1)
{
  int value;
  value = (u32)arg0[1] - (u32)arg1[1];
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}




/* Orders accepted ids before unaccepted ids, then compares the second halfword
   and finally the id. Each argument borrows a readable pair of halfwords. */
int Unk0bd5f0_Unk_0c75a8(u16 *arg0,u16 *arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = Unk09974c_Unk_0998d8(*arg0);
  tmp2 = Unk09974c_Unk_0998d8(*arg1);
  if ((tmp1 != 0) && (tmp2 == 0)) {
    return -1;
  }
  if ((tmp1 == 0) && (tmp2 != 0)) {
    return 1;
  }
  tmp1 = (u32)arg0[1] - (u32)arg1[1];
  if (tmp1 == 0) {
    tmp1 = (u32)*arg0 - (u32)*arg1;
  }
  return tmp1;
}


int func_020537b8(u32 port, u32 mask);
/* Latches group-zero input masks 0x40, 0x80, 0x20 and 0x10 into the
   caller-owned words at +0x150..+0x15c; clear queries preserve prior values. */
void Unk0bd5f0_Unk_0c2050(Unk0bd5f0Work *arg0){
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    arg0->unk_0150 = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    arg0->unk_0154 = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    arg0->unk_0158 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    arg0->unk_015c = 1;
  }
  return;
}

typedef struct Unk0bd5f0Ctx {
    s32 unk_0000; /* state word: 20, 22 or 24 seen */
    s32 unk_0004;
    u8 pad_0008[0xf8];
    void *unk_0100; /* passed to Unk0ddeb0_Unk_0ddeb0 */
    u8 pad_0104[0x4];
    void *unk_0108; /* passed to CampStatus_Unk_0dde3c */
    u8 pad_010c[0x8];
    s32 unk_0114;
    s32 unk_0118;
    s32 unk_011c;
    s32 unk_0120;
    u8 pad_0124[0x94];
    u32 unk_01b8;
} Unk0bd5f0Ctx;

/* Object passed to Unk0bd5f0_Unk_0c8510. Kept separate from Unk0bd5f0Ctx: its -110
   write lands at +0x114 where Unk0bd5f0Ctx has it at +0x118. */
typedef struct Unk0bd5f0Obj {
    s32 unk_0000;
    s32 unk_0004;
    u8 pad_0008[0xf8];
    void *unk_0100; /* passed to func_020c72a4 */
    u8 pad_0104[0xc];
    u8 unk_0110;
    u8 pad_0111[0x3];
    s32 unk_0114;
} Unk0bd5f0Obj;

extern Unk0bd5f0Ctx *data_02176bb4;

/* Returns true only when both func_020537b8 queries (group 0, masks 0x40 and
   0x80) are clear; the second query is skipped when the first is set. */
int Unk0bd5f0_Unk_0c20bc(void)
{
    if (func_020537b8(0, 64) != 0) {
        return 0;
    }
    return func_020537b8(0, 128) == 0;
}

/* Searches ids 111..210 inclusive for an accepted id whose record passes
   Unk09974c_HasFlagsMid. Evidence for the name: the bounded id loop and
   calls to Unk09974c_Unk_099d78, Unk09974c_Unk_0998d8 and HasFlagsMid. */
int Unk0bd5f0_AnyIdWithFlagsMid(void)
{
    u32 id;
    for (id = 111; id <= 210; id++) {
        void *r = Unk09974c_Unk_099d78(id);
        if (Unk09974c_Unk_0998d8(id) != 0 && Unk09974c_HasFlagsMid(r) != 0) {
            return 1;
        }
    }
    return 0;
}

/* Searches ids 111..210 inclusive for an accepted id whose record fails
   Unk09974c_HasFlagsMid. Evidence for the name: the bounded id loop and
   the negated HasFlagsMid result after Unk09974c_Unk_0998d8 accepts the id. */
int Unk0bd5f0_AnyIdWithoutFlagsMid(void)
{
    u32 id;
    for (id = 111; id <= 210; id++) {
        void *r = Unk09974c_Unk_099d78(id);
        if (Unk09974c_Unk_0998d8(id) != 0 && Unk09974c_HasFlagsMid(r) == 0) {
            return 1;
        }
    }
    return 0;
}

/* For a live global context, forwards its unk_0108 object and the four
   caller-supplied arguments to CampStatus_Unk_0dde3c; a null context is a no-op. */
void Unk0bd5f0_Unk_0c7f70(u32 a, u32 b, const u32 *ids, u32 n)
{
    if (data_02176bb4 == 0) {
        return;
    }
    CampStatus_Unk_0dde3c(data_02176bb4->unk_0108, a, b, ids, n);
}

/* For a live global context, sets the first two words to 20 and 22, the
   word at +0x118 to -110, and the words at +0x120 and +0x11c to zero. */
void Unk0bd5f0_Unk_0c7fbc(void)
{
    if (data_02176bb4 == 0) {
        return;
    }
    data_02176bb4->unk_0000 = 20;
    data_02176bb4->unk_0004 = 22;
    data_02176bb4->unk_0118 = -110;
    data_02176bb4->unk_0120 = 0;
    data_02176bb4->unk_011c = 0;
}

/* For a live global context, passes its +0x100 word and +0x114 word plus
   three to Unk0ddeb0_Unk_0ddeb0, followed by constants -2, 0, 12 and 10. */
void Unk0bd5f0_Unk_0c842c(void)
{
    Unk0bd5f0Ctx *c = data_02176bb4;
    if (c == 0) {
        return;
    }
    Unk0ddeb0_Unk_0ddeb0(c->unk_0100, c->unk_0114 + 3, -2, 0, 12, 10);
}

/* Tests the global context's first word for 22 or 24, returning false for
   a null context. Evidence for the name: the two equality comparisons in this function
   and the state-word writes in Unk0bd5f0_Unk_0c7fbc. */
int Unk0bd5f0_IsState22or24(void)
{
    s32 v;
    if (data_02176bb4 == 0) {
        return 0;
    }
    v = data_02176bb4->unk_0000;
    return v == 22 || v == 24;
}

/* Marks the context object in data_02176bb4 by setting the word at +0x1b8 to 1. */
void Unk0bd5f0_SetCtxUnk1b8(void)
{
    data_02176bb4->unk_01b8 = 1;
}

/* Reads p->unk_0100 and p->unk_0110 and passes them with zero to func_020c72a4,
   then writes unk_0000 = 20, unk_0004 = b and unk_0114 = -110. */
void Unk0bd5f0_Unk_0c8510(Unk0bd5f0Obj *p, s32 b)
{
    func_020c72a4(p->unk_0100, p->unk_0110, 0);
    p->unk_0000 = 20;
    p->unk_0004 = b;
    p->unk_0114 = -110;
}

/* Membership test for the special ids 5, 6, 8 and 22. */
int Unk0bd5f0_IsSpecialId(int id)
{
    if (id == 8 || id == 5 || id == 6 || id == 22) {
        return 1;
    }
    return 0;
}

/* Returns whether the signed byte at offset 0x348 + index in the shared work area is
   non-negative. The explicit u32 arithmetic reproduces the original addressing (See DEC-002). */
int func_020c1968(int idx)
{
    s8 *flags = (s8 *)((u32)Unk02e000_GetWorkArea() + (u32)idx + 0x300);
    return flags[0x48] >= 0;
}

/* Initializes a 352-byte, kind-zero callback descriptor, preserving +8. */
void func_020bd9c4(Unk0bd5f0Descriptor *p)
{
    p->size = 352;
    p->kind = 0;
    p->unk_000c = func_020bf240;
    p->unk_0010 = func_020bda18;
    p->unk_0014 = 0;
    p->unk_0018 = func_020bfddc;
    p->unk_001c = func_020c0c5c;
    p->unk_0020 = func_020c0d48;
}

/* Initializes a 448-byte, kind-three callback descriptor, preserving +8. */
void func_020c2578(Unk0bd5f0Descriptor *p)
{
    p->size = 448;
    p->kind = 3;
    p->unk_000c = func_020c5094;
    p->unk_0010 = func_020c25d0;
    p->unk_0014 = 0;
    p->unk_0018 = func_020c5dc0;
    p->unk_001c = func_020c67a0;
    p->unk_0020 = func_020c6888;
}

/* Uses group 12 and the supplied selector; only indices below table word +12
   are converted and forwarded to obj. The table and obj are borrowed. */
void func_020c72a4(void *obj, u32 selector, u32 index)
{
    u32 *table = func_020445f4(12, selector);
    if (index >= table[3]) return;
    func_02063920();
    func_02061f10(obj, -1, 0, 0, func_02063a30(func_0204fed8(table, index)));
}

/* After func_020c7304, pops the byte-sized stack at +0x124, passes the sub-object
   at +0x44 and the popped +0x128 entry to func_020bcfc4, updates the +0x108 object
   and signals value 2. Requires a populated stack. */
void func_020c84c0(Unk0bd5f0SelectObj *o)
{
    func_020c7304(o);
    o->unk_0124--;
    func_020bcfc4(o->unk_0044, o->unk_0128[o->unk_0124]);
    func_020c72a4(o->unk_0108, o->unk_0110, (u8)(o->unk_0054 + 100));
    Unk0a0ce4_Unk_0a0da4(2);
}

/* Borrowed list owner: offsets are established by the three collection routines. */
typedef struct Unk0bd5f0List {
    u8 pad_0000[0x44];
    u32 start;
    u8 pad_0048[0x6c];
    void *output;
} Unk0bd5f0List;

extern void func_02008644(u32 value, void *dest, u32 bytes);
extern void func_020c1cd0(Unk0bd5f0List *obj, const u32 *ids);
extern int func_0209a158(u32 id);
extern void func_02057e18(u32 value);
extern void func_02057df8(void);

/* Collects at most six mapped halfword ids (+0xaa, stride 60), stopping at a
   negative mapping; forwards the populated count and refreshes the owner. */
void func_020c1af4(Unk0bd5f0List *obj)
{
    u32 work = (u32)Unk02e000_GetWorkArea();
    u32 ids[6];
    u32 i, start, end;
    func_02008644(0, ids, sizeof(ids));
    start = obj->start;
    end = start + 6;
    for (i = start; i < end; i++) {
        s8 *mapping = (s8 *)(work + i + 0x300);
        s32 index = mapping[0x48];
        if (index < 0) break;
        ids[i - start] = *(u16 *)(work + index * 60 + 0xaa);
    }
    CampStatus_Unk_0dde3c(obj->output, 18, 1, ids, i - start);
    func_020c1cd0(obj, ids);
}

/* Refreshes the owner with six zero-initialized slots populated until the first
   negative signed mapping. The borrowed work records use a 60-byte stride. */
void func_020c1c4c(Unk0bd5f0List *obj)
{
    u32 work = (u32)Unk02e000_GetWorkArea();
    u32 ids[6];
    u32 i, start, end;
    func_02008644(0, ids, sizeof(ids));
    start = obj->start;
    end = start + 6;
    for (i = start; i < end; i++) {
        s8 *mapping = (s8 *)(work + i + 0x300);
        s32 index = mapping[0x48];
        if (index < 0) break;
        ids[i - start] = *(u16 *)(work + index * 60 + 0xaa);
    }
    func_020c1cd0(obj, ids);
}

/* Forwards up to six mapped ids to the owner's output. A negative mapping
   terminates collection; the count excludes the unused zero-filled slots. */
void func_020c1d88(Unk0bd5f0List *obj)
{
    u32 ids[6];
    u32 i, start, end;
    u32 work;
    func_02008644(0, ids, sizeof(ids));
    start = obj->start;
    work = (u32)Unk02e000_GetWorkArea();
    end = start + 6;
    for (i = start; i < end; i++) {
        s8 *mapping = (s8 *)(work + i + 0x300);
        s32 index = mapping[0x48];
        if (index < 0) break;
        ids[i - start] = *(u16 *)(work + index * 60 + 0xaa);
    }
    CampStatus_Unk_0dde3c(obj->output, 18, 1, ids, i - start);
}

/* Counts accepted ids in an inclusive signed range. For 111..210 only,
   additionally requires HasFlagsMid; the result wraps to sixteen bits. */
u16 func_020c7b30(s32 first, s32 last)
{
    u16 count = 0;
    if (first == 111 && last == 210) {
        u32 id;
        for (id = 111; id <= 210; id++) {
            void *record = Unk09974c_Unk_099d78(id);
            if (Unk09974c_Unk_0998d8(id) && Unk09974c_HasFlagsMid(record)) count++;
        }
    } else {
        for (; first <= last; first++) {
            if (Unk09974c_Unk_0998d8(first)) count++;
        }
    }
    return count;
}

/* Tests an inclusive unsigned range, using the alternate predicate for exactly
   411..900. Returns on the first accepted id; an empty range returns false. */
int func_020c7bc8(u32 first, u32 last)
{
    if (first == 411 && last == 900) {
        for (; first <= last; first++) {
            if (func_0209a158(first)) return 1;
        }
    } else {
        for (; first <= last; first++) {
            if (Unk09974c_Unk_0998d8(first)) return 1;
        }
    }
    return 0;
}

/* For a live global context, resets helper state and configures two rows on its
   borrowed +0x108 object with the observed coordinates and flags. */
void func_020c83a0(void)
{
    if (data_02176bb4 == 0) return;
    func_02057e18(31);
    func_02057df8();
    Unk0ddeb0_Unk_0ddeb0(data_02176bb4->unk_0108, 1, 152, 0, 25, 10);
    Unk0ddeb0_Unk_0ddeb0(data_02176bb4->unk_0108, 1, 164, 1, 25, 10);
}

/* Descriptor passed synchronously to func_020bcbc4; two flag bytes precede
   sixteen word slots, as established by the initialization loops. */
typedef struct Unk0bd5f0InputDescriptor {
    u8 flags[2];
    u32 slots[16];
} Unk0bd5f0InputDescriptor;
extern void func_020bcbc4(u32 kind, Unk0bd5f0InputDescriptor *descriptor);

/* Installs kind 3 with flag bit 1 and slot 1 set to 24, then latches input
   flags into the caller-owned work object. */
void func_020c1f40(Unk0bd5f0Work *obj)
{
    Unk0bd5f0InputDescriptor desc;
    int i;
    for (i = 0; i < 2; i++) desc.flags[i] = 0;
    for (i = 0; i < 16; i++) desc.slots[i] = 0;
    desc.slots[1] = 24;
    desc.flags[0] |= 2;
    func_020bcbc4(3, &desc);
    Unk0bd5f0_Unk_0c2050(obj);
}
