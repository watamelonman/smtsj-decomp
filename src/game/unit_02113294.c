/* src/game/unit_02113294.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk113294Work {
    u32 unk_0000;
    s32 unk_0004;
    u8 unk_0008;
    u8 pad_0009[3];
    s32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x8];
    u32 unk_001c;
    u32 unk_0020;
    u8 pad_0024[0x4];
    u32 unk_0028;
    u8 pad_002c[0xa4];
    u32 unk_00d0;
    u8 pad_00d4[4];
    u16 unk_00d8;
} Unk113294Work;

int Unk0a0ce4_Unk_0a0da4();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u32 data_02176e54[];
int func_02061f10();
int Unk113294_IsOtherId();
struct Unk113294Ids;
int Unk113294_AnyHi(struct Unk113294Ids *p);
int Unk113294_AnyLo(struct Unk113294Ids *p);
int Unk02e000_Thunk_0202e788();
void func_02008904();
void Unk02ee5c_Unk_02efa4();
typedef struct Unk113294Ids {
    u8 pad[216];
    u16 ids[16];
} Unk113294Ids;
/* Tests the observed conjunction: halfword +0xd8 and word +0xc are zero,
 * and word +4 is one. No broader state meaning is established. */
int Unk113294_Unk_113e90(const Unk113294Work *work)
{
    return work->unk_00d8 == 0 && work->unk_000c == 0 && work->unk_0004 == 1;
}

/* At 0x02113eb4, sets object byte +0 to 5, clears the shared word,
 * then tail-calls the provider with 2. The object must be writable. */
void Unk113294_Unk_113eb4(u8 *p)
{
    p[0] = 5;
    *data_02176e54 = 0;
    Unk0a0ce4_Unk_0a0da4(2);
}

/* At 0x021156c4, calls provider 11, then writes -1 at +0xd0,
 * 3 at +0x1c and byte 3 at +0. Requires the observed writable work layout. */
void Unk113294_Unk_1156c4(u8 *arg0)
{
  Unk0a0ce4_Unk_0a0da4(0xb);
  ((Unk113294Work *)arg0)->unk_00d0 = 0xffffffff;
  ((Unk113294Work *)arg0)->unk_001c = 3;
  *arg0 = 3;
}


/* At 0x02115698, calls provider 11, then writes -1 at +0xd0,
 * 2 at +0x1c and byte 3 at +0. Requires the observed writable work layout. */
void Unk113294_Unk_115698(u8 *arg0)
{
  Unk0a0ce4_Unk_0a0da4(0xb);
  ((Unk113294Work *)arg0)->unk_00d0 = 0xffffffff;
  ((Unk113294Work *)arg0)->unk_001c = 2;
  *arg0 = 3;
}



/* get u32 at +0x20 */
/* Returns the word at +0x20, directly evidenced by the load at 0x02115650. */
u32 Unk113294_GetUnkField20(const Unk113294Work *work)
{
    return work->unk_0020;
}

int Unk113294_Unk_1150e8(u32 a, u32 b);
/* decompiler-derived */
/* Tail-calls the halfword lookup with fixed arguments (1, 53). */
int Unk113294_Unk_115110(void)
{
    return Unk113294_Unk_1150e8(1, 53);
}

void func_020655b4(int value);
void func_02065604(int value);
void func_02065bc0(void);
/* decompiler-derived */
/* Runs the three observed subsystem calls, passing 1 to the final two. */
void Unk113294_Unk_1156ec(void)
{
    func_02065bc0();
    func_02065604(1);
    func_020655b4(1);
}

void *func_020445f4(int group, u32 index);
u16 *func_0204fed8(void *resource, u32 index);
/* decompiler-derived */
/* Resolves resource group 42 at the first index, then its second index. */
u16 *Unk113294_Unk_1150c8(u32 index, u32 entry)
{
    return func_0204fed8(func_020445f4(42, index), entry);
}


/* decompiler-derived */
/* Looks up byte +8 plus one and the low halfword of word +0x10. */
int Unk113294_Unk_115124(const Unk113294Work *work)
{
    return Unk113294_Unk_1150e8(work->unk_0008 + 1, (u16)work->unk_0010);
}


int func_021144e4();
int func_02114588();
int func_02114604();
int func_021146a4();
int func_021148ec();
int func_02114a1c();
/* At 0x02114488, skips inactive work; otherwise updates the palette unless
 * the preceding word is 6, then runs six callbacks. Borrows work and its prefix. */
void Unk113294_Unk_114488(char *arg0)
{
  if (*arg0 == '\0') {
    return;
  }
  if (*(int *)(arg0 + -4) != 6) {
    Unk_LoadPalette_020de678(((Unk113294Work *)arg0)->unk_0028);
  }
  func_021144e4(arg0);
  func_02114588(arg0);
  func_02114604(arg0);
  func_021146a4(arg0);
  func_021148ec(arg0);
  func_02114a1c(arg0);
  return;
}


int func_02061e98();
int func_02061f10();
int func_02063920();
int func_02063a30();
/* At 0x0211508c, sends resource (42,0), entry b to provider a.
 * The resource lookup result is borrowed for the provider call. */
void Unk113294_Unk_11508c(u32 a, u32 b)
{
    func_02061f10(a, -1, 0, 0, func_0204fed8(func_020445f4(42, 0), b));
}

u16 *Unk113294_Unk_1150c8(u32 arg0, u32 arg1);
int Unk113294_Unk_115124(const Unk113294Work *work);
int Unk113294_Unk_115110(void);
typedef struct Unk113294Pair {
    u16 a;
    u16 b;
} Unk113294Pair;
/* At 0x021150e8, returns the first resource halfword unless it is 0xffff;
 * that sentinel selects the low byte of the second halfword instead. */
int Unk113294_Unk_1150e8(u32 a, u32 b)
{
    u16 *q = Unk113294_Unk_1150c8(a, b);
    u32 v = q[0];
    if (v == 0xffff) {
        v = q[1] & 0xff;
    }
    return v;
}

/* At 0x02115144, sends the current lookup ID and a zero halfword to
 * provider +0xc4. The provider consumes the stack pair during this call. */
void Unk113294_Unk_115144(u8 *p)
{
    Unk113294Pair t = {0, 0};
    t.a = Unk113294_Unk_115124((const Unk113294Work *)p);
    func_02061f10(FIELD(u32, p, 196), -1, 0, 0, &t);
}

/* decompiler-derived */
void Unk113294_Unk_11518c(u32 arg0)
{
  u32 tmp1;
  int tmp2;
  func_02061e98(arg0,0x10,1);
  func_02063920();
  tmp2 = 0;
  do {
    Unk113294_Unk_1150c8(0,tmp2 + 0x66U & 0xffff);
    tmp1 = func_02063a30();
    func_02061f10(arg0,0xffffffff,0,0,tmp1);
    tmp2 = tmp2 + 1;
  } while (tmp2 < 2);
  return;
}

extern u8 data_0215159c[];
/* IsOtherId is supported by the comparison at 0x021155d0: a nonzero id
 * qualifies only when it differs from the fixed (1,53) lookup result. */
int Unk113294_IsOtherId(u32 id)
{
    if (id == 0) {
        return 0;
    }
    return id != Unk113294_Unk_115110();
}

/* The halfword scan at 0x021155e0 supports AnyLo: tests IDs 0..7
 * with IsOtherId. Borrows all eight low slots. */
int Unk113294_AnyLo(Unk113294Ids *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (Unk113294_IsOtherId(p->ids[i]) != 0) {
            return 1;
        }
    }
    return 0;
}

/* The halfword scan at 0x02115618 supports AnyHi: tests IDs 8..15
 * with IsOtherId. Borrows all eight high slots. */
int Unk113294_AnyHi(Unk113294Ids *p)
{
    int i;
    for (i = 8; i < 16; i++) {
        if (Unk113294_IsOtherId(p->ids[i]) != 0) {
            return 1;
        }
    }
    return 0;
}

/* At 0x02115658, copies sixteen bytes each from provider +72 and +90
 * into work +232 and +216, then calls the notification provider. */
void Unk113294_CopyIds(u8 *p)
{
    func_02008904(p + 232, (u8 *)Unk02e000_Thunk_0202e788() + 72, 16);
    func_02008904(p + 216, (u8 *)Unk02e000_Thunk_0202e788() + 90, 16);
    Unk02ee5c_Unk_02efa4();
}

/* The halfword scan at 0x02115708 supports FindEmpty: return the first
 * zero slot among IDs 0..7, or 7 when all are occupied. Borrows p. */
int Unk113294_FindEmpty(Unk113294Ids *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->ids[i] == 0) {
            return i;
        }
    }
    return 7;
}

/* Returns zero for byte +8 values 0 and 1, and one for every other value. */
int Unk113294_Unk_115734(const Unk113294Work *work)
{
    switch (work->unk_0008) {
    case 0:
    case 1:
        return 0;
    }
    return 1;
}

/* The address arithmetic at 0x02115754 selects a word from 220-byte
 * records with 11-word rows. Callers must supply indices within the table. */
u32 Unk113294_Unk_115754(int record, int row, int column)
{
    return *(u32 *)(record * 0xdc + data_0215159c + (row * 11 + column) * 4);
}

/* At 0x0211558c, returns 1 when AnyHi is false, otherwise 2 when AnyLo
 * is false, otherwise 0. Borrows the complete sixteen-ID layout. */
int Unk113294_Unk_11558c(Unk113294Ids *p)
{
    if (Unk113294_AnyHi(p) == 0) {
        return 1;
    }
    if (Unk113294_AnyLo(p) == 0) {
        return 2;
    }
    return 0;
}

/* At 0x02115778, the selected table word is compared to float zero via
 * _fneq. Uses the same valid record/row/column indices as 0x02115754. */
int Unk113294_Unk_115778(int record, int row, int column)
{
    return ((float *)(data_0215159c + record * 220))[row * 11 + column] != 0.0f;
}

/* Byte-aligned ID block: the original 0x02115498 uses paired byte copies. */
typedef struct Unk113294IdBlock {
    u8 bytes[16];
} Unk113294IdBlock;

/* See DEC-024 for the scoped propagation setting.
 * At 0x02115498, copies provider +72/+90 into work +232/+216 without
 * notification. Both borrowed blocks must contain sixteen readable bytes. */
#pragma opt_propagation off
void func_02115498(u8 *work)
{
    u8 *source = (u8 *)Unk02e000_Thunk_0202e788();
    Unk113294IdBlock *dest = (Unk113294IdBlock *)(work + 232);
    const Unk113294IdBlock *src = (const Unk113294IdBlock *)(source + 72);
    *dest = *src;
    dest = (Unk113294IdBlock *)(work + 216);
    src = (const Unk113294IdBlock *)(source + 90);
    *dest = *src;
}

#pragma opt_propagation reset

int func_02053d8c(u16 *a, u16 *b);
int func_021157ac(u8 *work, int mode);
void func_02113620(u8 *work);
/* Borrowed word view through +0xd4; only slots 4 and 53 are accessed here. */
typedef struct Unk113294SelectionWork {
    u32 words[54];
} Unk113294SelectionWork;
/* At 0x02115994, polls the provider and records a nonnegative selection
 * at +0x10, refreshing two callbacks. A successful poll returns 1 even for
 * a negative selection; a failed poll writes -1 at +0xd4 and returns 0. */
int func_02115994(Unk113294SelectionWork *work)
{
    u16 a, b;
    int accepted = 0;
    if (func_02053d8c(&a, &b)) {
        int selection;
        work->words[53] = func_021157ac((u8 *)work, 1);
        if ((s32)(selection = work->words[53]) >= 0) {
            work->words[4] = selection;
            Unk113294_Unk_115144((u8 *)work);
            func_02113620((u8 *)work);
        }
        accepted = 1;
    }
    if (!accepted) {
        work->words[53] = -1;
    }
    return accepted;
}
