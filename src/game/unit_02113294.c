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


void func_021144e4(u8 *work);
void func_02114588(u8 *work);
void func_02114604(u8 *work);
void func_021146a4(u8 *work);
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
  func_021144e4((u8 *)arg0);
  func_02114588((u8 *)arg0);
  func_02114604((u8 *)arg0);
  func_021146a4((u8 *)arg0);
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

/* At 0x0211518c, initializes the provider and submits resource entries
 * 102 and 103 after conversion. The handle is borrowed. */
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

void func_02113a6c(u8 *work, u32 id, int start, int count);
void func_021153a4(u8 *work);
void func_02115500(u8 *work);
/* At 0x02113974, toggles byte +8 between zero and one; value two emits
 * provider event four. Other values retain their byte and refresh the ID.
 * See DEC-025 for the switch form and scoped propagation setting. */
#pragma opt_propagation off
void func_02113974(u8 *work)
{
    switch (work[8]) {
    case 0: work[8] = 1; break;
    case 1: work[8] = 0; break;
    case 2: Unk0a0ce4_Unk_0a0da4(4); return;
    }
    switch (work[8]) {
    case 1: ((Unk113294Work *)work)->unk_0020 = 1; break;
    default: ((Unk113294Work *)work)->unk_0020 = 0; break;
    }
    Unk0a0ce4_Unk_0a0da4(1);
    Unk113294_Unk_115144(work);
}
#pragma opt_propagation reset
/* At 0x021139f0, dispatches ID insertion using word +4 and byte +9.
 * Work must expose the ID slots consumed by the downstream callbacks. */
void func_021139f0(u8 *work, u32 id)
{
    switch (FIELD(int, work, 4)) {
    case 0:
        if (work[9] == 0) {
            func_02113a6c(work, id, 0, 8);
            func_021153a4(work);
        } else if (work[9] == 1) {
            func_02113a6c(work, id, 8, 8);
            func_021153a4(work);
        }
        break;
    case 1:
        func_02113a6c(work, id, 0, 32);
        func_02115500(work);
        break;
    }
}
/* At 0x02113a6c, writes the selected halfword and advances the cursor.
 * The observed low-ID transition selects cursor eight and resource 110.
 * The cursor must address writable ID storage in the borrowed work area. */
void func_02113a6c(u8 *work, u32 id, int start, int count)
{
    ((Unk113294Ids *)work)->ids[FIELD(int, work, 12)] = id;
    if (FIELD(int, work, 12) == start + count - 1) {
        if (FIELD(int, work, 4) == 0 && work[9] == 0) {
            if (Unk113294_AnyLo((Unk113294Ids *)work) == 1) {
                work[9] = 1;
                Unk113294_Unk_11508c(FIELD(u32, work, 140), 110);
                FIELD(int, work, 12) = 8;
            }
        }
    } else {
        FIELD(int, work, 12)++;
    }
    Unk0a0ce4_Unk_0a0da4(1);
}
void func_0205c748(int mode, u32 handle, int a, int b, float c, float d, int e, float f, int g);
int Unk0cb32c_Unk_0cb58c(u32 handle);
void func_02057e18(int value);
void func_02060b60(int mode, u32 handle, int a, int b, int c, int d);
/* At 0x02114588, submits handle +56 with unit scale and draws provider
 * entry 13 at 154 when that handle's status is nonzero. Borrows work. */
void func_02114588(u8 *work)
{
    func_0205c748(2, FIELD(u32, work, 56), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    if (Unk0cb32c_Unk_0cb58c(FIELD(u32, work, 56)) == 0) return;
    func_02057e18(31);
    func_02060b60(1, FIELD(u32, work, 140), 13, 154, 0, 5);
}
/* At 0x02114604, selects handles +128/+132 for state three according to
 * byte +1, otherwise +124. Each provider call uses unit scale. */
void func_02114604(u8 *work)
{
    if (work[0] == 3) {
        if (work[1] <= 1) {
            func_0205c748(2, FIELD(u32, work, 128), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
        } else {
            func_0205c748(2, FIELD(u32, work, 132), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
        }
    } else {
        func_0205c748(2, FIELD(u32, work, 124), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    }
}
/* At 0x021151fc, submits three groups of 54 lookup IDs plus a zero
 * terminator. Providers borrow the stack buffer only during each call.
 * See DEC-025 for the scoped propagation setting. */
#pragma opt_propagation off
void func_021151fc(u8 *work)
{
    int group;
    u16 ids[55];
    int index;
    group = 0;
    do {
        index = 0;
        do {
            ids[index] = Unk113294_Unk_1150e8(group + 1, (u16)index);
            index++;
        } while (index < 54);
        ids[54] = 0;
        func_02061f10(((u32 *)(work + 148))[group], -1, 8, 6, ids);
        group++;
    } while (group < 3);
}
#pragma opt_propagation reset

void func_02008848(void *dest, int value, u32 size);
void func_020119a0(void *dest, const void *source, u32 size);
/* At 0x02115500, copies two 32-byte ID blocks into a zeroed 72-byte
 * submission buffer. The original also writes a sentinel beyond that buffer
 * (stack +104); retained here solely to reproduce the observed instructions.
 * See DEC-025 for this original overrun and scoped loop optimization. */
#pragma opt_strength_reduction off
void func_02115500(u8 *work)
{
    u16 ids[36];
    int block;
    int offset;
    func_02008848(ids, 0, 72);
    ids[16] = 0x8001;
    ids[33] = 0x8001;
    ids[50] = 0x8001;
    block = 0;
    offset = 0;
    do {
        func_020119a0(ids + (block + offset), work + 216 + offset * 2, 32);
        block++;
        offset += 16;
    } while (block < 2);
    func_02061f10(FIELD(u32, work, 192), -1, 0, 2, ids);
}

#pragma opt_strength_reduction reset
int func_0205caa0(u32 handle);
void func_021136f8(u8 *work);
void func_021138a4(u8 *work);
void func_02113ae8(u8 *work);
void func_02113bc4(u8 *work, int start, int count);
int func_02053e44(int x, int y, int width, int height, int a, int b);
/* At 0x021144e4, submits handles +48/+52 at unit scale and draws the
 * +136 provider when +48 has positive status. Work borrows these handles. */
void func_021144e4(u8 *work)
{
    func_0205c748(2, FIELD(u32, work, 48), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    func_0205c748(2, FIELD(u32, work, 52), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    if (func_0205caa0(FIELD(u32, work, 48)) > 0)
        func_02060b60(1, FIELD(u32, work, 136), 2,
            FIELD(int, (u8 *)FIELD(u32, work, 48), 24) - 2, 0, 6);
}
/* At 0x021158e4, polls two rectangles and returns one for a hit.
 * A differing mode also writes +208 and byte state three; work is writable. */
int func_021158e4(u8 *work)
{
    u16 a, b;
    int i, x;
    if (!func_02053d8c(&a, &b)) return 0;
    for (i = 0, x = 5; i < 2; i++, x += 60) {
        if (func_02053e44(x, 18, 60, 18, 1, 0)) {
            if (i != Unk113294_Unk_115734((Unk113294Work *)work)) {
                FIELD(int, work, 208) = i;
                work[0] = 3;
                Unk0a0ce4_Unk_0a0da4(11);
            }
            return 1;
        }
    }
    return 0;
}
/* At 0x021138a4, moves the cursor backward, crossing from high slots
 * to the first empty low slot at cursor eight. Requires writable ID work. */
void func_021138a4(u8 *work)
{
    switch (FIELD(int, work, 4)) {
    case 0:
        if (work[9] == 0) {
            if (FIELD(int, work, 12) > 0) {
                Unk0a0ce4_Unk_0a0da4(1);
                FIELD(int, work, 12)--;
            } else Unk0a0ce4_Unk_0a0da4(4);
        } else if (work[9] == 1) {
            if (FIELD(int, work, 12) != 8) FIELD(int, work, 12)--;
            else {
                work[9] = 0;
                FIELD(int, work, 12) = Unk113294_FindEmpty((Unk113294Ids *)work);
                Unk113294_Unk_11508c(FIELD(u32, work, 140), 111);
            }
            Unk0a0ce4_Unk_0a0da4(1);
        }
        break;
    case 1:
        if (FIELD(int, work, 12) > 0) {
            Unk0a0ce4_Unk_0a0da4(1);
            FIELD(int, work, 12)--;
        } else Unk0a0ce4_Unk_0a0da4(4);
        break;
    }
}
/* At 0x02113ae8, selects deletion ranges from mode and byte +9,
 * with a transition to low slots for an empty high slot eight. */
void func_02113ae8(u8 *work)
{
    switch (FIELD(int, work, 4)) {
    case 0:
        if (work[9] == 0) {
            func_02113bc4(work, 0, 8);
            func_021153a4(work);
        } else if (work[9] == 1) {
            if (FIELD(int, work, 12) == 8) {
                if (((Unk113294Ids *)work)->ids[FIELD(int, work, 12)] == 0) {
                    work[9] = 0;
                    Unk113294_Unk_11508c(FIELD(u32, work, 140), 111);
                    FIELD(int, work, 12) = Unk113294_FindEmpty((Unk113294Ids *)work);
                    Unk0a0ce4_Unk_0a0da4(1);
                } else {
                    /* Duplicated tail keeps the original's separate call at 0x2113b7c. */
                    func_02113bc4(work, 8, 8);
                    func_021153a4(work);
                }
            } else {
                /* Duplicated tail keeps the original's separate call at 0x2113b94. */
                func_02113bc4(work, 8, 8);
                func_021153a4(work);
            }
        }
        break;
    case 1: func_02113bc4(work, 0, 32); func_02115500(work); break;
    }
}
#pragma opt_propagation off
/* At 0x02113bc4, removes a slot by shifting subsequent halfwords.
 * The caller supplies a valid writable range and cursor within that range. */
void func_02113bc4(u8 *work, int start, int count)
{
    int end;
    int limit;
    int cursor = FIELD(int, work, 12);
    if (cursor == start) {
        if (((Unk113294Ids *)work)->ids[cursor] == 0) {
            Unk0a0ce4_Unk_0a0da4(2); return;
        }
        limit = start + count;
        for (; start < limit - 1; start++)
            ((Unk113294Ids *)work)->ids[start] = ((Unk113294Ids *)work)->ids[start + 1];
        /* Original store is work+214+2*limit, i.e. slot limit-1; the -2 view
         * reproduces that addressing. See DEC-026. */
        ((Unk113294Ids *)(work - 2))->ids[limit] = 0;
        Unk0a0ce4_Unk_0a0da4(2); return;
    }
    end = start + count;
    if (cursor == end - 1 && ((Unk113294Ids *)work)->ids[cursor] != 0) {
        ((Unk113294Ids *)work)->ids[cursor] = 0;
        Unk0a0ce4_Unk_0a0da4(2); return;
    }
    for (; cursor < end; cursor++)
        ((Unk113294Ids *)work)->ids[cursor - 1] = ((Unk113294Ids *)work)->ids[cursor];
    /* Original store is work+214+2*end, i.e. slot end-1. See DEC-026. */
    ((Unk113294Ids *)(work - 2))->ids[end] = 0;
    FIELD(int, work, 12)--;
    Unk0a0ce4_Unk_0a0da4(2);
}
#pragma opt_propagation reset
#pragma opt_propagation off
/* At 0x021153a4, submits two zero-terminated eight-ID lists to
 * handles +188/+184. The provider borrows each stack list during its call. */
void func_021153a4(u8 *work)
{
    u16 hi[9] = {0,0,0,0,0,0,0,0,0};
    u16 lo[9] = {0,0,0,0,0,0,0,0,0};
    Unk113294IdBlock *dest = (Unk113294IdBlock *)hi;
    const Unk113294IdBlock *src = (const Unk113294IdBlock *)(work + 232);
    *dest = *src;
    dest = (Unk113294IdBlock *)lo;
    src = (const Unk113294IdBlock *)(work + 216);
    *dest = *src;
    func_02061f10(FIELD(u32, work, 188), -1, 8, 0, hi);
    func_02061f10(FIELD(u32, work, 184), -1, 8, 0, lo);
}

#pragma opt_propagation reset

/* At 0x02113620, dispatches six special IDs; remaining IDs use the
 * current resource lookup. The downstream callbacks borrow work. */
void func_02113620(u8 *work)
{
    switch (FIELD(int, work, 16)) {
    case 10: func_021136f8(work); break;
    case 21: func_021138a4(work); break;
    case 32: func_021139f0(work, Unk113294_Unk_115110()); break;
    case 43: func_02113974(work); break;
    case 53:
        if (work[8] != 2) func_02113ae8(work);
        else func_021139f0(work, Unk113294_Unk_115124((Unk113294Work *)work));
        break;
    case 54: func_02113ae8(work); break;
    default: func_021139f0(work, Unk113294_Unk_115124((Unk113294Work *)work)); break;
    }
}

void func_02114014(u8 *work);
void func_02114308(u8 *work);
/* At 0x02113edc, draws four borrowed handles, then the mode-specific panel.
 * Requires a readable word before work for the palette-state check. */
void func_02113edc(u8 *work)
{
    if (!work[0]) return;
    if (FIELD(int, work, -4) != 6) Unk_LoadPalette_020de678(FIELD(u32, work, 40));
    func_0205c748(2, FIELD(u32, work, 72), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    func_0205c748(2, FIELD(u32, work, 68), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    func_0205c748(2, FIELD(u32, work, 64), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    func_0205c748(2, FIELD(u32, work, 60), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    switch (FIELD(int, work, 4)) {
    case 0:
        func_0205c748(2, FIELD(u32, work, 76), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
        func_02114014(work);
        break;
    case 1: func_02114308(work); break;
    }
}

int func_02053824(int device, int mask);
/* At 0x02113450, wraps the selected index in an eleven-column grid.
 * Returns one when a directional input updates the writable index at +16. */
int func_02113450(u8 *work)
{
    int changed = 0;
    if (func_02053824(0, 32)) {
        if (FIELD(int, work, 16) == 0 || FIELD(int, work, 16) % 11 == 0)
            FIELD(int, work, 16) += 10;
        else if (work[8] != 2 && FIELD(int, work, 16) == 54)
            FIELD(int, work, 16) -= 2;
        else FIELD(int, work, 16)--;
        changed = 1;
    } else if (func_02053824(0, 16)) {
        if (FIELD(int, work, 16) == 0) FIELD(int, work, 16) = 1;
        else if (FIELD(int, work, 16) % 11 == 10) FIELD(int, work, 16) -= 10;
        else if (work[8] != 2 && FIELD(int, work, 16) >= 53) FIELD(int, work, 16) = 44;
        else FIELD(int, work, 16)++;
        changed = 1;
    } else if (func_02053824(0, 64)) {
        if (FIELD(int, work, 16) == 0) FIELD(int, work, 16) = 44;
        else if (FIELD(int, work, 16) / 11 == 0) FIELD(int, work, 16) += 44;
        else FIELD(int, work, 16) -= 11;
        changed = 1;
    } else if (func_02053824(0, 128)) {
        if (FIELD(int, work, 16) == 0) FIELD(int, work, 16) = 11;
        else if (FIELD(int, work, 16) / 11 != 4) FIELD(int, work, 16) += 11;
        else FIELD(int, work, 16) %= 11;
        changed = 1;
    }
    return changed;
}

/* At 0x021136f8, advances the cursor through populated slots and switches
 * from low to high slots when available. Work owns the writable ID storage. */
void func_021136f8(u8 *work)
{
    switch (FIELD(int, work, 4)) {
    case 0:
        if (work[9] == 0) {
            int advance;
            if (((Unk113294Ids *)work)->ids[FIELD(int, work, 12)] == 0) {
                if (Unk113294_AnyLo((Unk113294Ids *)work)) {
                    work[9] = 1;
                    FIELD(int, work, 12) = 8;
                    Unk113294_Unk_11508c(FIELD(u32, work, 140), 110);
                    Unk0a0ce4_Unk_0a0da4(1);
                    return;
                }
                Unk0a0ce4_Unk_0a0da4(4);
                Unk113294_Unk_1156ec();
                FIELD(u16, work, 20) = 125;
                work[0] = 4;
                return;
            }
            advance = 0;
            if (FIELD(int, work, 12) == 7) {
                if (Unk113294_AnyLo((Unk113294Ids *)work)) {
                    work[9] = 1;
                    Unk113294_Unk_11508c(FIELD(u32, work, 140), 110);
                    advance = 1;
                }
            } else advance = 1;
            if (advance) {
                FIELD(int, work, 12)++;
                Unk0a0ce4_Unk_0a0da4(1);
                return;
            }
            Unk0a0ce4_Unk_0a0da4(4);
            Unk113294_Unk_1156ec();
            FIELD(u16, work, 20) = 125;
            work[0] = 4;
            return;
        }
        if (work[9] != 1) return;
        if (FIELD(int, work, 12) >= 15) { Unk0a0ce4_Unk_0a0da4(4); return; }
        if (((Unk113294Ids *)work)->ids[FIELD(int, work, 12)] == 0) {
            Unk0a0ce4_Unk_0a0da4(4); return;
        }
        Unk0a0ce4_Unk_0a0da4(1);
        FIELD(int, work, 12)++;
        break;
    case 1:
        if (FIELD(int, work, 12) >= 31) { Unk0a0ce4_Unk_0a0da4(4); return; }
        if (((Unk113294Ids *)work)->ids[FIELD(int, work, 12)] == 0) {
            Unk0a0ce4_Unk_0a0da4(4); return;
        }
        Unk0a0ce4_Unk_0a0da4(1);
        FIELD(int, work, 12)++;
        break;
    }
}

void func_0205de40(int mode, u32 handle, int a, int x, int y,
                    float sx, float sy, int b, float scale, int c);
void func_02057ddc(u32 color);
void func_02057df8(void);
/* At 0x02114308, draws the 2x16 slot background and cursor at eleven/fifteen
 * pixel spacing, then submits the borrowed text handle at +192. */
void func_02114308(u8 *work)
{
    int row, col, x, y;
    func_0205c748(2, FIELD(u32, work, 84), 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    if (work[0] <= 1) return;
    for (row = 0, y = 0; row < 2; row++, y += 15) {
        for (col = 0, x = 0; col < 16; col++, x += 11)
            func_0205de40(2, FIELD(u32, work, 36), 26, x, y, 1.0f, 1.0f, 0, 1.0f, 1);
    }
    if (FIELD(int, work, 12) == 0)
        func_0205c748(2, FIELD(u32, work, 92), 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    else
        func_0205c748(2, FIELD(u32, work, 92), (FIELD(int, work, 12) % 16) * 11,
                      (FIELD(int, work, 12) / 16) * 15, 1.0f, 1.0f, 0, 1.0f, 2);
    func_02057e18(31);
    func_02057ddc(0x39f7efff);
    func_02060b60(1, FIELD(u32, work, 192), 42, 84, 0, 6);
    func_02057df8();
}

#pragma opt_strength_reduction off
/* See DEC-027 for the scoped index-generation setting. */
/* At 0x0211527c, builds six 5x11 resource grids; unavailable row tails
 * use the fixed lookup ID and 0x8001 terminator. Providers borrow the stack grid. */
void func_0211527c(u8 *work)
{
    u16 ids[55];
    u16 *line;
    int base;
    int row, col, group;
    for (group = 0; group < 6; group++) {
        func_02008848(ids, 0, 110);
        for (row = 0, line = ids, base = 0; row < 5; row++, line += 11, base += 11) {
            for (col = 0; col < 11; col++) {
                if (Unk113294_Unk_115778(group, row, col)) {
                    if (col == 10 && row == 4) line[col] = 0;
                    else line[col] = Unk113294_Unk_1150e8(1, (u16)(col + base));
                } else {
                    if (row == 4) line[col] = 0;
                    else {
                        for (; col < 11; col++) {
                            if (col == 10) line[col] = 0x8001;
                            else line[col] = Unk113294_Unk_115110();
                        }
                        break;
                    }
                }
            }
        }
        func_02061f10(FIELD(u32, work + group * 4, 160), -1, 8, 6, ids);
    }
}

#pragma opt_strength_reduction reset

void func_0204fcb0(int mode, const u16 *ids);
/* At 0x02113ca8, validates the two ID banks and advances state four with
 * message 120/121/122/125. Providers borrow the terminated stack lists. */
#pragma opt_propagation off
void func_02113ca8(u8 *work)
{
    switch (FIELD(int, work, 4)) {
    case 0:
        if (work[9] == 0) {
            if (Unk113294_AnyLo((Unk113294Ids *)work)) {
                work[9] = 1;
                Unk113294_Unk_11508c(FIELD(u32, work, 140), 110);
                FIELD(int, work, 12) = 8;
                Unk0a0ce4_Unk_0a0da4(1);
            } else {
                Unk0a0ce4_Unk_0a0da4(4);
                Unk113294_Unk_1156ec();
                FIELD(u16, work, 20) = 125;
                work[0] = 4;
            }
            return;
        }
        if (work[9] != 1) return;
        switch (Unk113294_Unk_11558c((Unk113294Ids *)work)) {
        case 0: {
            u16 hi[9] = {0,0,0,0,0,0,0,0,0};
            u16 lo[9] = {0,0,0,0,0,0,0,0,0};
            Unk113294IdBlock *dest = (Unk113294IdBlock *)hi;
            const Unk113294IdBlock *src = (const Unk113294IdBlock *)(work + 232);
            *dest = *src;
            dest = (Unk113294IdBlock *)lo;
            src = (const Unk113294IdBlock *)(work + 216);
            *dest = *src;
            Unk113294_Unk_1156ec();
            Unk0a0ce4_Unk_0a0da4(1);
            func_0204fcb0(1, lo);
            func_0204fcb0(2, hi);
            FIELD(u16, work, 20) = 120;
            work[0] = 4;
            return;
        }
        case 1: case 2: case 3:
            Unk0a0ce4_Unk_0a0da4(4);
            Unk113294_Unk_1156ec();
            FIELD(u16, work, 20) = 122;
            work[0] = 4;
            return;
        }
        break;
    case 1:
        Unk113294_Unk_1156ec();
        Unk0a0ce4_Unk_0a0da4(1);
        FIELD(u16, work, 20) = 121;
        work[0] = 4;
        break;
    }
}
#pragma opt_propagation reset

/* At 0x021146a4, draws the two borrowed panel handles and highlights
 * the state-three choice using handle coordinates +20/+24. */
void func_021146a4(u8 *work)
{
    int x, y;
    func_0205c748(2, FIELD(u32, work, 112), 0, 0, 1.0f, 1.0f, 0, 1.0f, 4);
    func_0205c748(2, FIELD(u32, work, 116), 0, 0, 1.0f, 1.0f, 0, 1.0f, 4);
    if (work[0] < 1) return;
    if (work[0] == 1 && work[1] < 2) return;
    x = FIELD(int, FIELD(u8 *, work, 112), 20);
    y = FIELD(int, FIELD(u8 *, work, 112), 24);
    if (work[0] == 3 && FIELD(int, work, 28) == 2) {
        func_02057ddc(0xffffff);
        func_0205de40(2, FIELD(u32, work, 36), 19, x, y, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057df8();
        func_0205c748(2, FIELD(u32, work, 104), x, y, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057e18(31);
    } else {
        func_0205de40(2, FIELD(u32, work, 36), 19, x, y, 1.0f, 1.0f, 0, 1.0f, 5);
    }
    x = FIELD(int, FIELD(u8 *, work, 116), 20);
    y = FIELD(int, FIELD(u8 *, work, 116), 24);
    if (work[0] == 3 && FIELD(int, work, 28) == 3) {
        func_02057ddc(0xffffff);
        func_0205de40(2, FIELD(u32, work, 36), 21, x, y, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057df8();
        func_0205c748(2, FIELD(u32, work, 108), x, y, 1.0f, 1.0f, 0, 1.0f, 5);
        func_02057e18(31);
    } else {
        func_0205de40(2, FIELD(u32, work, 36), 21, x, y, 1.0f, 1.0f, 0, 1.0f, 5);
    }
}
