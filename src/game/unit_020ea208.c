/*
 * src/game/unit_020ea208.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/*
 * One of the six 56-byte slot records that start at work+0x70. The two
 * single handles at +0x20/+0x34 and the four-entry handle table at +0x24 are
 * released by func_020eb034; +0x00, +0x04 and +0x10..+0x1c (not +0x08/+0x0c)
 * are zeroed by Unk0ea208_Unk_0eae20.
 */
typedef struct Unk0ea208Slot {
    u32 UnkField00;
    u32 UnkField04;
    u32 UnkField08;
    u32 UnkField0c;
    u32 UnkField10;
    u32 UnkField14;
    u32 UnkField18;
    u32 UnkField1c;
    u32 UnkHandle20;
    u32 UnkTable24[4];
    u32 UnkHandle34;
} Unk0ea208Slot;

/*
 * Borrowed view of the singleton reached through data_02176ddc. Offsets come
 * from the field accesses in this translation unit; the type is a view, not an
 * allocation contract, so callers keep ownership.
 */
typedef struct Unk0ea208Work {
    u32 UnkField0000;
    u32 UnkField0004;
    u32 UnkField0008;
    u32 UnkField000c;
    u32 UnkTable0010[5];        /* +0x10..+0x23 (GetArr10) */
    u32 UnkTable0024[6];        /* +0x24..+0x3b (GetArr24) */
    u32 UnkField003c;
    u32 UnkTable0040[6];        /* +0x40..+0x57 (GetArr40) */
    u32 UnkTable0058[6];        /* +0x58..+0x6f (GetArr58) */
    Unk0ea208Slot UnkSlot0070[6]; /* +0x70..+0x1bf, stride 56 */
    u8 unk_01c0[4];
    u32 UnkField01c4;
    u32 UnkField01c8;
    u32 UnkField01cc;
    s8 UnkField01d0;
    s32 UnkField01d4;
} Unk0ea208Work;

/* Borrowed resource descriptor returned by func_0205ad9c; the two named words
 * are the ones func_020eb324 resets/creates and its four-entry id table. */
typedef struct Unk0ea208Desc {
    u32 UnkField00;
    const char *UnkField04;
    u8 UnkPad08[8];
    u32 UnkField10;
    u32 UnkField14;
} Unk0ea208Desc;

/* Graphics object created by Unk065e88_Call_02065fc0; its word at +0x00 is the
 * animation link passed to the func_0205c4xx helpers. */
typedef struct Unk0ea208Graphic {
    u32 UnkLink00;
} Unk0ea208Graphic;


extern u32 data_02176ddc[];
/* Two 8-byte key/value tables consulted by func_020eacb4; every value is zero. */
typedef struct Unk0ea208IdMap {
    u32 key;
    u32 value;
} Unk0ea208IdMap;
extern Unk0ea208IdMap data_02150c80[4];
extern Unk0ea208IdMap data_02150ca0[5];
/* Default object used by func_020ea208 when Unk09974c_Unk_099bac finds none. */
extern u32 data_02150cc8[];
/* Four resource ids whose descriptors func_020eb324 advances. */
extern u32 data_0213c72c[];

u16 *func_0204a0d8(void *object);
int Unk0cb0d0_IsAbove15e(u16 value);
int Unk0e8228_Unk_0e8c68(void);
int Unk0e8228_Unk_0e8f20(void);
void func_0205de40(int screen, u32 object, int frame, int x, int y,
                   float sx, float sy, int rot, float alpha, int prio);
void func_02058e9c(int screen, u32 resource, int x, int y,
                   float scale, int a, int b);

void func_020572d8(void);
void func_02057eb8(s32 value);
u32 Unk09974c_Unk_099d14(u32 value);
u32 Unk09974c_Unk_099bac(u32 value);
u32 Unk0caea8_Unk_0cb044(u32 value);
void *func_020cb1a0(u32 key);
void *func_02044ec4(u32 key);
int Unk0e8228_Unk_0e8374(int selector);
int Unk0e8228_GetArr88Field20(int index);
u32 Unk0e8228_Unk_0e8c80(void);
u32 Unk0e8228_Unk_0e8f38(void);
void Unk0fedd4_Unk_0fee38(u32 value);

void Unk0ea208_Unk_0ead3c(void);
void Unk0ea208_Unk_0ead1c(void);
u32 Unk0ea208_Get_data_02176ddc(void);
void Unk0ea208_Unk_0eaca0(void);
u32 Unk0ea208_Unk_0ea72c(void);
void Unk0ea208_Unk_0ead4c(void);
void Unk0ea208_Unk_0ead64(void);
u32 Unk0ea208_Unk_0eada8(void);
u32 Unk0ea208_Unk_0eade4(void);
u32 func_020eacb4(u32 id);
void Unk0ea208_Unk_0ea390(int i, u32 x);
void func_020ea320(int i, u32 handle);
void Unk0ea208_Unk_0eae40(u32 obj, u32 a, u32 b, u32 c);
Unk0ea208Slot *Unk0ea208_Unk_0eb2cc(Unk0ea208Work *work);
u32 Unk0ea208_Unk_0ea984(u32 arg0);
u32 func_020eaa90(u32 arg0);
void func_020eae84(Unk0ea208Slot *slot, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_02061424(u32 handle);

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02061f10(u32 value, s32 arg1, s32 arg2, s32 arg3, u32 arg4);

/*
 * Store the object resolved from `value` in the six-entry +0x40 table and
 * submit it, together with the matching +0x24 handle, to func_02061f10.
 * Evidence: `str r0,[r1,#64]` after Unk09974c_Unk_099d14, the null result of
 * Unk09974c_Unk_099bac replaced by data_02150cc8, `ldr r0,[r1,#36]` and the
 * stack argument for func_02061f10. The work and its tables are borrowed.
 */
void func_020ea208(int i, u32 value)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    u32 object;

    if (work == 0 || work->UnkField01cc == 0) {
        return;
    }
    if (i < 0 || i >= 6) {
        return;
    }
    work->UnkTable0040[i] = Unk09974c_Unk_099d14(value);
    object = Unk09974c_Unk_099bac(value);
    if (object == 0) {
        object = (u32)data_02150cc8;
    }
    func_02061f10(work->UnkTable0024[i], -1, 0, 0, object);
}

/*
 * Rebuild the six-entry +0x58 table for one battle entry id: when the
 * 0e8c68 state word is set, reserve index 0 with the group-39/entry-3 handle,
 * then copy each non-sentinel halfword from the entry's id array into the next
 * table index. Evidence: the guarded singleton check, the
 * Unk0cb0d0_IsAbove15e(value) == 1 skip, and the func_020ea320 store loop over
 * all six halfwords returned by func_0204a0d8. The entry and table are borrowed.
 */
void func_020ea290(u32 id)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    int used;
    int i;
    int slot;
    u16 *ids;

    if (work == 0 || work->UnkField01cc == 0) {
        return;
    }
    used = Unk0e8228_Unk_0e8c68();
    if (used != 0) {
        Unk0ea208_Unk_0ea390(0, Unk0ea208_Unk_0ea85c());
    }
    ids = func_0204a0d8(func_02044ec4(id));
    slot = used != 0;
    for (i = 0; i < 6; i++) {
        if (Unk0cb0d0_IsAbove15e(ids[i]) == 1) {
            continue;
        }
        func_020ea320(slot, ids[i]);
        slot++;
    }
}

/*
 * Replace entry i of the six-entry +0x58 table: a zero handle clears the slot,
 * otherwise the table gets the func_020cb1a0 record and the slot index plus the
 * Unk0caea8_Unk_0cb044 result go to Unk0ea208_Unk_0ea390. Evidence: the
 * `str [r?, #88]` on both paths and the two call relocations. Tables are
 * borrowed from the singleton.
 */
void func_020ea320(int i, u32 handle)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();

    if (work == 0 || work->UnkField01cc == 0) {
        return;
    }
    if (i < 0 || i >= 6) {
        return;
    }
    if (handle == 0) {
        work->UnkTable0058[i] = 0;
        return;
    }
    work->UnkTable0058[i] = (u32)func_020cb1a0(handle);
    Unk0ea208_Unk_0ea390(i, Unk0caea8_Unk_0cb044(handle));
}

/*
 * Dispatch selector 4 or 9 to the matching 0ea984/func_020eaa90 refresh, and
 * every other selector to the group-39/entry-1 resource, then hand the final
 * result to Unk0fedd4_Unk_0fee38. Evidence: the two selector compares and the
 * common `bl Unk0fedd4_Unk_0fee38` epilogue. The singleton is only observed.
 */
void func_020ea3cc(int selector)
{
    u32 value;
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();

    if (work == 0 || work->UnkField01cc == 0) {
        return;
    }
    switch (selector) {
    case 4:
        value = Unk0ea208_Unk_0ea984((u32)func_02044ec4(Unk0e8228_Unk_0e8c80()));
        break;
    case 9:
        value = func_020eaa90((u32)func_02044ec4(Unk0e8228_Unk_0e8c80()));
        break;
    default:
        value = func_0204fed8(func_020445f4(39, 1), selector);
        break;
    }
    Unk0fedd4_Unk_0fee38(value);
}

/*
 * Bounds-check a slot index against the six-entry +0x24 table, then pass that
 * table entry and the caller's value to func_02061f10 with the fixed middle
 * arguments -1, 0, 0. Evidence: `cmp r5,#6` / `popge`, the scaled
 * `ldr r0,[r0,r5,lsl #2]` at +36, `mvn r1,#0`, and the stack argument store.
 */
void Unk0ea208_Unk_0ea390(int i, u32 x)
{
    if (i < 0) {
        return;
    }
    if (i >= 6) {
        return;
    }
    func_02061f10(((Unk0ea208Work *)Unk0ea208_Get_data_02176ddc())->UnkTable0024[i],
                  -1, 0, 0, x);
}

/*
 * Return the borrowed word at +0x00 of the singleton when the singleton exists and its
 * +0x1cc word is nonzero; otherwise return 0. Evidence: null check on the 02176ddc load,
 * `ldr r1,[r0,#460]`, then `ldrne r0,[r0]`.
 */
u32 Unk0ea208_GetField0(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 0);
}

/*
 * Return the borrowed word at +0x04 of the singleton when the singleton exists and its
 * +0x1cc word is nonzero; otherwise return 0. Evidence: same guarded shape as GetField0,
 * with the final load at `[r0, #4]`.
 */
u32 Unk0ea208_GetField4(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 4);
}

/*
 * Return the borrowed word at +0x08 of the singleton when the singleton exists and its
 * +0x1cc word is nonzero; otherwise return 0. Evidence: same guarded shape as GetField0,
 * with the final load at `[r0, #8]`.
 */
u32 Unk0ea208_GetField8(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 8);
}

/*
 * Return the borrowed work word at +0x0c when the singleton exists and its
 * +0x1cc word is nonzero; otherwise 0. Evidence: `cmp r0,#0`,
 * `ldr r1,[r0,#460]`, then `ldrne r0,[r0,#12]` in the delinked ARM.
 */
u32 Unk0ea208_GetFieldC(void)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    if (work == 0) {
        return 0;
    }
    if (work->UnkField01cc == 0) {
        return 0;
    }
    return work->UnkField000c;
}

/*
 * Return entry i of the five-word table at work+0x10, or 0 when the singleton
 * is missing or not ready (+0x1cc is zero) or i is outside 0..4. The returned
 * word is a borrowed handle. Evidence: the `cmp r4,#5` bound and the final
 * `ldr r0,[r0,#16]` after `add r0,r0,r4,lsl #2`.
 */
u32 Unk0ea208_GetArr10(int i)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    if (work == 0) {
        return 0;
    }
    if (work->UnkField01cc == 0) {
        return 0;
    }
    if (i < 0 || i >= 5) {
        return 0;
    }
    return work->UnkTable0010[i];
}

void Unk0ea208_ForEachSlot(Unk0ea208Work *work);
void func_020eb034(Unk0ea208Slot *slot);
void func_020ea744(u32 value);
int Unk0e8228_Unk_0e8460(void);
int Unk0e8228_GetArr40(int index);
int func_020445f4(int group, int index);
int func_0204fed8(int resource, int selector);
/*
 * Return entry i of the six-word table at work+0x24, or 0 when the singleton
 * is missing or not ready (+0x1cc is zero) or i is outside 0..5. The returned
 * word is a borrowed handle. Evidence: the `cmp r4,#6` bound and the final
 * `ldr r0,[r0,#36]` after `add r0,r0,r4,lsl #2`.
 */
u32 Unk0ea208_GetArr24(int i)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    if (work == 0) {
        return 0;
    }
    if (work->UnkField01cc == 0) {
        return 0;
    }
    if (i < 0 || i >= 6) {
        return 0;
    }
    return work->UnkTable0024[i];
}

/*
 * Return the borrowed work word at +0x3c when the singleton exists and its
 * +0x1cc word is nonzero; otherwise 0. Evidence: same guard as GetFieldC with
 * the final load `ldrne r0,[r0,#60]`.
 */
u32 Unk0ea208_GetField3c(void)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    if (work == 0) {
        return 0;
    }
    if (work->UnkField01cc == 0) {
        return 0;
    }
    return work->UnkField003c;
}

/*
 * Return entry i of the six-word table at work+0x40, or 0 when the singleton
 * is missing or not ready (+0x1cc is zero) or i is outside 0..5. The returned
 * word is a borrowed handle. Evidence: the `cmp r4,#6` bound and the final
 * `ldr r0,[r0,#64]` after `add r0,r0,r4,lsl #2`.
 */
u32 Unk0ea208_GetArr40(int i)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    if (work == 0) {
        return 0;
    }
    if (work->UnkField01cc == 0) {
        return 0;
    }
    if (i < 0 || i >= 6) {
        return 0;
    }
    return work->UnkTable0040[i];
}

/*
 * Return entry i of the six-word table at work+0x58, or 0 when the singleton
 * is missing/not ready (+0x1cc zero) or i is outside 0..5. Evidence: the
 * `cmp r4,#6` bound after the guard and `ldr r0,[r0,#88]` after the scaled
 * add. The word is a borrowed handle.
 */
u32 Unk0ea208_GetArr58(int i)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    if (i < 0 || i >= 6) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 88);
}

/*
 * Run the fixed selector dispatch: 0/1/5/6/7 call func_020eacb4, 2 -> 0ead3c,
 * 3 -> 0ead1c, 4 -> 0ead4c, 8 -> 0ead64, 9 -> 0eada8, 10 -> 0eade4; other
 * selectors return 0. Evidence: the `cmp r0,#10` / `addls pc,pc,r0,lsl #2`
 * jump table and each call relocation. Callees own any side effects; the
 * void-callee arms (2, 3, 4, 8) intentionally leave the callee's r0 as the
 * result, matching the original.
 */
u32 func_020ea630(int selector)
{
    switch (selector) {
    case 3:
        Unk0ea208_Unk_0ead1c();
        break;
    case 2:
        Unk0ea208_Unk_0ead3c();
        break;
    case 4:
        Unk0ea208_Unk_0ead4c();
        break;
    case 0:
    case 1:
    case 5:
    case 6:
    case 7:
        return func_020eacb4(selector);
    case 8:
        Unk0ea208_Unk_0ead64();
        break;
    case 9:
        return Unk0ea208_Unk_0eada8();
    case 10:
        return Unk0ea208_Unk_0eade4();
    default:
        return 0;
    }
}

/*
 * Claim the first free +0x70 slot and pass it the five caller values through
 * func_020eae84; returns without effect when the singleton is missing/not
 * ready or all six slots are occupied. Evidence: `bl Unk0ea208_Unk_0eb2cc`,
 * the two stack argument stores (`stm sp,{r4,ip}`) and the func_020eae84 call.
 * The slot stays owned by the work area.
 */
void func_020ea6ac(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    Unk0ea208Work *work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
    Unk0ea208Slot *slot;

    if (work == 0 || work->UnkField01cc == 0) {
        return;
    }
    slot = Unk0ea208_Unk_0eb2cc(work);
    if (slot == 0) {
        return;
    }
    func_020eae84(slot, a, b, c, d, e);
}

/*
 * Run the per-slot teardown when the singleton exists and its +0x1cc word is nonzero.
 * Evidence: `bl Unk0ea208_Get_data_02176ddc`, `cmp r0,#0`, `ldrne r1,[r0,#460]`,
 * `cmpne r1,#0`, then `bl Unk0ea208_ForEachSlot` with the singleton as the argument.
 * Callers are the state handlers in game/unit_020f470c and game/unit_020f4c50.
 */
void Unk0ea208_Unk_0ea70c(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p != 0 && FIELD(u32, p, 460) != 0) {
        Unk0ea208_ForEachSlot((Unk0ea208Work *)p);
    }
}

/* Forward the 0e8f38 result to 0cb044; the original call chain supplies r0. */
void Unk0ea208_Unk_0ead3c(void)
{
  Unk0caea8_Unk_0cb044(Unk0e8228_Unk_0e8f38());
}

/* Borrow the singleton address stored at data_02176ddc; zero means absent. */
u32 Unk0ea208_Get_data_02176ddc(void)
{
  return *data_02176ddc;
}

/* Pass the all-ones sentinel to 02057eb8 before calling 020572d8. */
void Unk0ea208_Unk_0eaca0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
}

/*
 * Translate an id through the two static key/value tables: five entries from
 * data_02150ca0, then four from data_02150c80; return 0 when neither table has
 * the id. Evidence: the two `ldr [r2,r3,lsl #3]` loops with bounds 5 and 4 and
 * the final `mov r0,#0`. Tables are read-only and borrowed.
 */
u32 func_020eacb4(u32 id)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        if (id == data_02150ca0[i].key) {
            return data_02150ca0[i].value;
        }
    }
    for (i = 0; i < 4; i++) {
        if (id == data_02150c80[i].key) {
            return data_02150c80[i].value;
        }
    }
    return 0;
}

/* Return the singleton word at +0x1d4, or zero when no singleton exists. */
u32 Unk0ea208_Unk_0ea72c(void)
{
  int value1;
  u32 value2;
  value1 = Unk0ea208_Get_data_02176ddc();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x1d4);
  }
  return value2;
}

/* Two signed coordinates returned by func_02049c28. */
typedef struct Unk0ea208Pair {
    s16 x;
    s16 y;
} Unk0ea208Pair;

int Unk0986ac_Unk_098978(int id);
int Unk0986ac_Thunk_02098714(int bit);
int func_02049f6c(void *entry, int field);
int func_02049d80(void *entry, int which);
int func_02049f24(void *entry, int which);
int func_0204a244(void *entry);
void func_02049c28(void *entry, Unk0ea208Pair *out);

/*
 * Resolve one battle entry id and queue its display request: when the 0xa9
 * check is set and the 0e8f20 index is not 27, entry kinds 1/3/4 select the
 * extra flag; flag the value that is at most 20% of its reference, then submit
 * the entry's parsed coordinates and kind to func_020ea6ac. Evidence: the
 * 0xa9/thunk guard, the switch jump table with cases 1/3/4, the *20 and /100
 * magic constant, and the func_02049c28 pair plus func_0204a244 result passed
 * as the fifth argument. The entry is borrowed.
 */
void func_020ea744(u32 id)
{
    void *entry = func_02044ec4(id);
    Unk0ea208Pair pair;
    int index;
    int extra = 0;
    int selected;
    int kind;

    if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(0xa9)) != 0) {
        index = Unk0e8228_Unk_0e8f20();
        if (index != 27) {
            switch (func_02049f6c(entry, index)) {
            case 0:
            case 2:
            case 5:
                break;
            case 1:
            case 3:
            case 4:
                extra = 1;
                break;
            }
        }
    }
    selected = 0;
    if (func_02049d80(entry, 0) <= (func_02049f24(entry, 0) * 20) / 100) {
        selected = 1;
    }
    kind = func_0204a244(entry);
    func_02049c28(entry, &pair);
    func_020ea6ac(pair.x, pair.y, selected, extra, kind);
}

/*
 * Visit every entry in the 0e8228 +0x40 table below the count returned by
 * Unk0e8228_Unk_0e8460, passing each value to func_020ea744. Evidence: the
 * `bl Unk0e8228_Unk_0e8460` count guard and the paired
 * `bl Unk0e8228_GetArr40` / `bl func_020ea744` loop.
 */
void Unk0ea208_Unk_0ea828(void)
{
    int count = Unk0e8228_Unk_0e8460();
    int i;
    for (i = 0; i < count; i++) {
        func_020ea744(Unk0e8228_GetArr40(i));
    }
}

/* Resolve group 39, entry 3, then pass its result with selector 1. */
int Unk0ea208_Unk_0ea85c(void)
{
    return func_0204fed8(func_020445f4(39, 3), 1);
}

/* Resolve selector 8 through the +0x88 table and forward its +0x20 value. */
void Unk0ea208_Unk_0ead4c(void)
{
  Unk09974c_Unk_099bac(Unk0e8228_GetArr88Field20(Unk0e8228_Unk_0e8374(8)));
}



/*
 * Reset the work state fields: store 1 at +0x1c4, zero the words at +0x1c8 and +0x1cc,
 * and zero the byte at +0x1d0. Evidence: `mov r1,#1`, `str r1,[r0,#452]`, then zero
 * stores at +456/+460 and a zero `strb` at +464. The caller owns `work`.
 */
void Unk0ea208_Unk_0eb308(Unk0ea208Work *work)
{
  work->UnkField01c4 = 1;
  work->UnkField01c8 = 0;
  work->UnkField01cc = 0;
  work->UnkField01d0 = 0;
}

int func_02057524();
int func_02057ddc();
int func_02057e18();
/*
 * Apply the fixed teardown sequence: select value 31, then -1, then mode 4 in three
 * consecutive provider calls. Evidence: `mov r0,#31; bl func_02057e18`,
 * `mvn r0,#0; bl func_02057ddc`, `mov r0,#4; bl func_02057524`.
 */
void Unk0ea208_Unk_0eac80(void)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057524(4);
}

int Unk0ea208_Unk_0ea85c(void);
/*
 * Consume the 0e8f38 result: when it is zero, fall back to the group-39/entry-3 lookup
 * wrapper; otherwise forward the borrowed result to the 0cb044 sink. Evidence: the
 * `cmp r0,#0` / `bne` split and the relocations to 0ea85c and 0cb044.
 */
void Unk0ea208_Unk_0ead1c(void)
{
  int value;
  value = Unk0e8228_Unk_0e8f38();
  if (value == 0) {
    Unk0ea208_Unk_0ea85c();
    return;
  }
  Unk0caea8_Unk_0cb044(value);
}


/*
 * Zero six caller-owned words at +0x00, +0x04, +0x10, +0x14, +0x18 and +0x1c; the
 * words at +0x08 and +0x0c are intentionally untouched. Evidence: six `str r1` stores
 * with r1 fixed at zero and exactly those offsets.
 */
void Unk0ea208_Unk_0eae20(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  arg0[7] = 0;
}



/*
 * Return the first of the six +0x70 slot records whose +0x00 word is zero (a
 * free slot), or NULL when all six are occupied. Evidence: `add r0,r0,#112`,
 * the `ldr r1,[r0]` / `bxeq lr` early return, stride `add r0,r0,#56`, loop
 * bound 6, and the final `mov r0,#0`.
 */
Unk0ea208Slot *Unk0ea208_Unk_0eb2cc(Unk0ea208Work *work)
{
  Unk0ea208Slot *slot;
  int i;
  slot = work->UnkSlot0070;
  i = 0;
  do {
    if (slot->UnkField00 == 0) {
      return slot;
    }
    i = i + 1;
    slot = slot + 1;
  } while (i < 6);
  return (Unk0ea208Slot *)0x0;
}

int func_0205ca48(void *link);
Unk0ea208Graphic *Unk065e88_Call_02065fc0(u32 a, u32 b, u32 c, u16 d);
void func_0205c408(void *object, s32 value);
s32 func_02050074(s32 first, s32 last);
void func_0205c41c(void *object, s32 value);
void func_0205c6e0(void *object);

/*
 * Advance one slot's graphics state: state 1 first waits for func_0205ca48 on
 * its current +0x20 object to finish, releases that old object, builds a new
 * one from the shared field8/fieldC resources, configures its animation, and
 * stores it back with state 2. States other than 1/2 are ignored. Evidence:
 * the two state compares, the +0x20 dereference/guard/release, the
 * Unk065e88_Call_02065fc0 arguments, the func_0205c4xx animation setup, and
 * the conditional 0xa5ff31ff / 0xff0000ff colour argument. Slot and
 * resources are borrowed; the slot owns the returned object handle.
 */
void func_020eb0a8(Unk0ea208Slot *slot)
{
    Unk0ea208Graphic *object;
    u32 resource8;
    u32 resourceC;
    u32 color;

    switch (slot->UnkField04) {
    case 1:
        if (func_0205ca48((void *)FIELD(u32, slot->UnkHandle20, 0)) != 0) {
            return;
        }
        if (slot->UnkHandle20 != 0) {
            func_02061424(slot->UnkHandle20);
            slot->UnkHandle20 = 0;
        }
        resource8 = Unk0ea208_GetField8();
        resourceC = Unk0ea208_GetFieldC();
        object = Unk065e88_Call_02065fc0(resource8, resourceC, 1, 0);
        func_0205c408((void *)object->UnkLink00, 4);
        func_0205c41c((void *)object->UnkLink00, func_02050074(1, 4) << 2);
        func_0205c6e0((void *)object->UnkLink00);
        color = 0xa5ff31ff;
        if (slot->UnkField10 != 0) {
            color = 0xff0000ff;
        }
        Unk0ea208_Unk_0eae40((u32)object, slot->UnkField08, slot->UnkField0c, color);
        slot->UnkHandle20 = (u32)object;
        slot->UnkField04 = 2;
        break;
    case 2:
        break;
    }
}

/*
 * Call func_020eb0a8 for every one of the six +0x70 slot records whose +0x00
 * word is nonzero. Evidence: `ldr r0,[r5]` / `beq` skip, stride 56, loop bound
 * 6, and the func_020eb0a8 call relocation.
 */
void Unk0ea208_Unk_0eb230(Unk0ea208Work *work)
{
  int i;
  Unk0ea208Slot *slot;
  slot = work->UnkSlot0070;
  i = 0;
  do {
    if (slot->UnkField00 != 0) {
      func_020eb0a8(slot);
    }
    i = i + 1;
    slot = slot + 1;
  } while (i < 6);
}

/*
 * When the singleton exists and its +0x1cc word is nonzero, resolve group 39
 * entry 0 and pass that handle to func_0204fed8 with selector 3; return 0 on
 * either guard failure. Evidence: `ldr r0,[r0,#460]`, `mov r0,#39` /
 * `mov r1,#0`, then `mov r1,#3` before the func_0204fed8 call.
 */
u32 Unk0ea208_Unk_0eada8(void)
{
  Unk0ea208Work *work;
  work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
  if (work == 0) {
    return 0;
  }
  if (work->UnkField01cc == 0) {
    return 0;
  }
  return func_0204fed8(func_020445f4(0x27, 0), 3);
}



/*
 * When the singleton exists and its +0x1cc word is nonzero, resolve group 39
 * entry 2 and pass that handle to func_0204fed8 with selector 2; otherwise
 * return 0. Evidence: the guarded +0x1cc load, `mov r0,#39` / `mov r1,#2`,
 * and a second `mov r1,#2` before the 0204fed8 call. The handle is borrowed.
 */
u32 Unk0ea208_Unk_0eade4(void)
{
  Unk0ea208Work *work;
  work = (Unk0ea208Work *)Unk0ea208_Get_data_02176ddc();
  if (work == 0) {
    return 0;
  }
  if (work->UnkField01cc == 0) {
    return 0;
  }
  return func_0204fed8(func_020445f4(0x27, 2), 2);
}

/*
 * Emit the two effect records of a finished slot when the shared field8
 * resource exists and the slot is in state 2. The +0x1c guard selects the
 * ten-argument screen effect (position +0x08/+0x0c, scale 1.0); the +0x14
 * guard selects the seven-argument effect using resource +0x18 at the
 * +15-shifted position. Evidence: the GetField8 guard, the state-2 compare,
 * the two guarded stack-argument blocks and their func_0205de40 /
 * func_02058e9c relocations. The slot and resource are borrowed.
 */
void func_020eb178(Unk0ea208Slot *slot)
{
    u32 resource = Unk0ea208_GetField8();

    if (resource == 0) {
        return;
    }
    if (slot->UnkField04 != 2) {
        return;
    }
    if (slot->UnkField1c != 0) {
        func_0205de40(2, resource, 5, slot->UnkField08, slot->UnkField0c,
                      1.0f, 1.0f, 0, 1.0f, 10);
    }
    if (slot->UnkField14 != 0) {
        func_02058e9c(2, slot->UnkField18, slot->UnkField08 + 15,
                      slot->UnkField0c + 15, 1.0f, 0, 12);
    }
}

/*
 * Tear down the six +0x70 slot records: run the fixed teardown, call
 * func_020eb178 for each record whose +0x00 word is nonzero, then run the
 * closing teardown. Evidence: `add r5,r4,#112`, the `ldr r0,[r5]` / `beq`
 * skip, stride 56, loop bound 6, and the two teardown call relocations.
 */
void Unk0ea208_Unk_0eb264(Unk0ea208Work *work)
{
  int i;
  Unk0ea208Slot *slot;
  Unk0ea208_Unk_0eac80();
  slot = work->UnkSlot0070;
  i = 0;
  do {
    if (slot->UnkField00 != 0) {
      func_020eb178(slot);
    }
    i = i + 1;
    slot = slot + 1;
  } while (i < 6);
  Unk0ea208_Unk_0eaca0();
}


void Unk065e88_SetUnkFieldsc_10(u32 obj, u32 a, u32 b);
void Unk065e88_SetUnkField28(u32 obj, u32 value);
void Unk065e88_SetUnkField24(u32 obj, u32 value);
void Unk065e88_SetUnkField30(u32 obj, u32 value);
void Unk065e88_SetUnkField3c(u32 obj, u32 value);
/*
 * Initialize an object through the 065e88 setters: pass the first three
 * inputs to SetUnkFieldsc_10 (fields +0x0c/+0x10), then store the fourth input
 * at +0x28 and the constants 10, 4 and 2 at +0x24, +0x30 and +0x3c. Evidence:
 * the first call receives the untouched r0/r1/r2, while r3 is saved in r4 for
 * SetUnkField28 before the constant moves. The object is caller-owned.
 */
void Unk0ea208_Unk_0eae40(u32 obj, u32 a, u32 b, u32 c)
{
  Unk065e88_SetUnkFieldsc_10(obj, a, b);
  Unk065e88_SetUnkField28(obj, c);
  Unk065e88_SetUnkField24(obj, 10);
  Unk065e88_SetUnkField30(obj, 4);
  Unk065e88_SetUnkField3c(obj, 2);
}

int func_0204a160();
int func_0204a190();
int func_0204a1b0();
int func_0204a1d0();
int func_0204a1e8();
int func_0204faf0();
int func_0204fcb0();
/*
 * Refresh one mode-1 battle entry's display table: read its four accessor
 * values, resolve group 14 entries 1, 2 and 3 and store them in table slots
 * 4, 5 and 6, then compare the two remaining accessors. When they differ,
 * store both into slots 3 and 4 and submit group 14 entry 0 with selector 3;
 * otherwise store the second value in slot 3 and submit with selector 2. The
 * body is cleaned decompiler output; the func_0204a1xx accessor pairs with
 * argument 1, the 0xe table resolves, and the slot numbers 4/5/6/3/4 are all
 * visible in the original relocations and immediates. The entry is borrowed.
 */
void Unk0ea208_Unk_0ea878(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  int tmp4;
  u32 tmp5;
  int tmp6;
  tmp1 = func_0204a1d0(arg0,1);
  tmp2 = func_0204a160(arg0,1);
  tmp3 = func_0204a1e8(arg0,1);
  tmp4 = func_0204a190(arg0,1);
  tmp5 = func_020445f4(0xe,1);
  tmp1 = func_0204fed8(tmp5,tmp1);
  func_0204fcb0(4,tmp1);
  tmp1 = func_020445f4(0xe,2);
  tmp1 = func_0204fed8(tmp1,tmp2);
  func_0204fcb0(5,tmp1);

  tmp1 = func_020445f4(0xe,3);
  tmp1 = func_0204fed8(tmp1,tmp3);
  func_0204fcb0(6,tmp1);
  tmp6 = func_0204a1b0(arg0,1);
  tmp1 = func_020445f4(0xe,0);
  if (tmp4 != tmp6) {
    func_0204faf0(3,tmp4);
    func_0204faf0(4,tmp6);
    func_0204fed8(tmp1,3);
    return;
  }
  func_0204faf0(3,tmp6);
  func_0204fed8(tmp1,2);
}

/*
 * Refresh one mode-0 battle entry's display table: read its four accessor
 * values, resolve group 14 entries 1, 2 and 3 and store them in table slots
 * 1, 2 and 3, then compare the two remaining accessors. When they differ,
 * store both into slots 1 and 2 and submit group 14 entry 0 with selector 1;
 * otherwise store the second value in slot 1 and submit with selector 0.
 * Returns the last submitted resource for func_020ea3cc. The body is cleaned
 * decompiler output; the accessor mode, the 0xe table and the slot numbers are
 * visible in the original relocations and immediates. The entry is borrowed.
 */
u32 Unk0ea208_Unk_0ea984(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  int tmp4;
  u32 tmp5;
  int tmp6;
  tmp1 = func_0204a1d0(arg0,0);
  tmp2 = func_0204a160(arg0,0);
  tmp3 = func_0204a1e8(arg0,0);
  tmp4 = func_0204a190(arg0,0);
  tmp5 = func_020445f4(0xe,1);
  tmp1 = func_0204fed8(tmp5,tmp1);
  func_0204fcb0(1,tmp1);
  tmp1 = func_020445f4(0xe,2);
  tmp1 = func_0204fed8(tmp1,tmp2);
  func_0204fcb0(2,tmp1);

  tmp1 = func_020445f4(0xe,3);
  tmp1 = func_0204fed8(tmp1,tmp3);
  func_0204fcb0(3,tmp1);
  tmp6 = func_0204a1b0(arg0,0);
  tmp1 = func_020445f4(0xe,0);
  if (tmp4 != tmp6) {
    func_0204faf0(1,tmp4);
    func_0204faf0(2,tmp6);
    return func_0204fed8(tmp1,1);
  }
  func_0204faf0(1,tmp6);
  return func_0204fed8(tmp1,0);
}

extern char data_02150cd4[];
extern char data_02150ce8[];
extern char data_02150d00[];
extern char data_02150d18[];
u32 func_0205dcd4(const char *path, u32 mode);
u32 func_0205c2c4(const char *path);
u32 func_020629ac(int a, int b, int c, int d);
u32 func_02062208(u16 *values);
void Unk0fedd4_Alloc(u32 id);
void Unk044394_Unk_044428(u32 group);
int Unk0e651c_Unk_0e666c(u32 flag);
u32 Unk0ddeb0_Unk_0ddfd8(u32 id);
u32 Unk0ca69c_Unk_0ca6a4(u32 value);

/*
 * Refresh one battle entry's display table for its zero-mode accessors, then
 * scan the resulting id array. The four accessor values fill table slots 1..3
 * through group 14, the two remaining accessors choose selector 5 when they
 * differ or selector 4 when they match, and the returned halfword array is
 * scanned for a 0x8001 entry outside the 0xffff/0xfffe-delimited ranges.
 * Evidence: the func_0204a1xx accessor calls with argument 0, the 0xe table
 * relocations, immediates 1/2/3 and 5/4, and the 0x8001/0xfffe/0xffff literal
 * pool loaded by the scan loop. The entry and array are borrowed.
 */
u32 func_020eaa90(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  u32 tmp4;
  u32 tmp5;
  u32 tmp6;
  u16 *values;
  u32 count;
  u32 stopped;
  u32 flag;
  u32 i;

  tmp1 = func_0204a1d0(arg0, 0);
  tmp2 = func_0204a160(arg0, 0);
  tmp3 = func_0204a1e8(arg0, 0);
  tmp4 = func_0204a190(arg0, 0);
  tmp5 = func_020445f4(0xe, 1);
  tmp1 = func_0204fed8(tmp5, tmp1);
  func_0204fcb0(1, tmp1);
  tmp1 = func_020445f4(0xe, 2);
  tmp1 = func_0204fed8(tmp1, tmp2);
  func_0204fcb0(2, tmp1);
  tmp1 = func_020445f4(0xe, 3);
  tmp1 = func_0204fed8(tmp1, tmp3);
  func_0204fcb0(3, tmp1);
  tmp6 = func_0204a1b0(arg0, 0);
  tmp1 = func_020445f4(0xe, 0);
  if (tmp4 != tmp6) {
    func_0204faf0(1, tmp4);
    func_0204faf0(2, tmp6);
    values = (u16 *)func_0204fed8(tmp1, 5);
  } else {
    func_0204faf0(1, tmp6);
    values = (u16 *)func_0204fed8(tmp1, 4);
  }
  count = func_02062208(values);
  stopped = 0;
  flag = 0;
  i = 0;
  for (i = 0; i < count; i++) {
    u16 value = values[i];
    if (value == 0xffff) {
      flag = 1;
    } else if (value == 0xfffe) {
      flag = 0;
    } else if (flag == 0 && value == 0x8001) {
      stopped = 1;
      break;
    }
  }
  if (stopped != 0) {
    values = &values[i + 1];
  }
  return (u32)values;
}

/* Resolve group 39, entry 4, then pass its result with selector 1. */
int Unk0ea208_Unk_0eac24(void)
{
    return func_0204fed8(func_020445f4(39, 4), 1);
}

/*
 * Resolve group 39 entry 2 and submit it with work+0x3c to func_02061f10 using
 * the fixed middle arguments -1, 0 and 3. Evidence: `mov r0,#39` / `mov r1,#2`
 * for 020445f4, selector 1 for 0204fed8, the stack store of its result,
 * `ldr r0,[r4,#60]`, `mvn r1,#0`, `mov r2,#0` and `mov r3,#3`.
 */
void Unk0ea208_Unk_0eac40(Unk0ea208Work *work)
{
    func_02061f10(work->UnkField003c, -1, 0, 3, func_0204fed8(func_020445f4(39, 2), 1));
}

void *func_02044ec4(u32 key);
void Unk0a163c_Unk_0a1814(u32 id);
/*
 * Resolve group 5 through the 0e8228 table, then report the result of
 * func_02044ec4: when bit 2 of its byte +0x282 is set report id 0x17d, otherwise
 * report the halfword at +0x1d8. Evidence: `mov r0,#5`, the two table calls,
 * `ldrb [r0,#642]` shifted to isolate bit 2, `add r0,r0,#256` and
 * `ldrh [r0,#216]`. The record is borrowed.
 */
void Unk0ea208_Unk_0ead64(void)
{
    u8 *record = (u8 *)func_02044ec4(Unk0e8228_GetArr40(Unk0e8228_Unk_0e8374(5)));
    if (((u32)(record[642] << 29) >> 31) != 0) {
        Unk0a163c_Unk_0a1814(0x17d);
        return;
    }
    Unk0a163c_Unk_0a1814(FIELD(u16, record, 472));
}

/*
 * Initialize one +0x70 slot record and build its graphics objects: store the
 * position minus 12, the caller flags and the resolved +0x18 value, create the
 * main graphic (state 1) with animation 6 and colour 0xa5ff31ff, or 0xff0000ff
 * when +0x10 is set. Unless the caller's fifth argument is nonzero, also create
 * the state-1 companion with animation 5 at +0x34 and four more at +0x24 with
 * animation 0..3. Evidence: the GetField8/GetFieldC guard, the -12 position
 * offsets, the 065fc0 creation arguments (1,0), the 0205c408 animation values
 * 6/5/loop index, the colour literals, the -1 colour for the extra objects and
 * the func_02050074(1,4) shift for the companion animation. The slot stays
 * owned by the work area.
 */
void func_020eae84(Unk0ea208Slot *slot, u32 a, u32 b, u32 c, u32 d, u32 e)
{
  Unk0ea208Graphic *object;
  u32 resource8;
  u32 resourceC;
  u32 color;
  int i;

  resource8 = Unk0ea208_GetField8();
  resourceC = Unk0ea208_GetFieldC();
  if (resource8 == 0 || resourceC == 0) {
    return;
  }
  slot->UnkField00 = 1;
  slot->UnkField04 = 1;
  slot->UnkField08 = a - 12;
  slot->UnkField0c = b - 12;
  slot->UnkField10 = c;
  slot->UnkField14 = e;
  slot->UnkField1c = d;
  if (e != 0) {
    slot->UnkField18 = Unk0ca69c_Unk_0ca6a4(Unk0ddeb0_Unk_0ddfd8((u16)e));
  }
  object = Unk065e88_Call_02065fc0(resource8, resourceC, 1, 0);
  func_0205c408((void *)object->UnkLink00, 6);
  func_0205c41c((void *)object->UnkLink00, 0);
  func_0205c6e0((void *)object->UnkLink00);
  color = 0xa5ff31ff;
  if (slot->UnkField10 != 0) {
    color = 0xff0000ff;
  }
  Unk0ea208_Unk_0eae40((u32)object, a - 12, b - 12, color);
  slot->UnkHandle20 = (u32)object;
  if (d != 0) {
    return;
  }
  object = Unk065e88_Call_02065fc0(resource8, resourceC, 1, 0);
  func_0205c408((void *)object->UnkLink00, 5);
  func_0205c41c((void *)object->UnkLink00, func_02050074(1, 4) << 2);
  func_0205c6e0((void *)object->UnkLink00);
  Unk0ea208_Unk_0eae40((u32)object, a - 12, b - 12, 0xffffffff);
  slot->UnkHandle34 = (u32)object;
  for (i = 0; i < 4; i++) {
    object = Unk065e88_Call_02065fc0(resource8, resourceC, 1, 0);
    func_0205c408((void *)object->UnkLink00, i);
    func_0205c6e0((void *)object->UnkLink00);
    Unk0ea208_Unk_0eae40((u32)object, a - 12, b - 12, 0xffffffff);
    slot->UnkTable24[i] = (u32)object;
  }
}

/*
 * Release the handles owned by one +0x70 slot record: the words at +0x20 and
 * +0x34 and the four handles at +0x24..+0x33 go through func_02061424 and are
 * cleared, then the scalar words at +0x00/+0x04/+0x10..+0x1c are zeroed.
 * Evidence: the two guarded loads at +32/+52, the four-iteration loop over
 * +36, and the Unk0ea208_Unk_0eae20 call. The slot is caller-owned and its
 * handles are released exactly once.
 */
void func_020eb034(Unk0ea208Slot *slot)
{
    int i;

    if (slot->UnkHandle20 != 0) {
        func_02061424(slot->UnkHandle20);
        slot->UnkHandle20 = 0;
    }
    if (slot->UnkHandle34 != 0) {
        func_02061424(slot->UnkHandle34);
        slot->UnkHandle34 = 0;
    }
    for (i = 0; i < 4; i++) {
        if (slot->UnkTable24[i] != 0) {
            func_02061424(slot->UnkTable24[i]);
            slot->UnkTable24[i] = 0;
        }
    }
    Unk0ea208_Unk_0eae20((u32 *)slot);
}

/*
 * Invoke func_020eb034 once per +0x70 slot record: six records, 56 bytes apart.
 * Evidence: `add r5,r0,#112`, loop bound 6, `add r5,r5,#56`, and the
 * func_020eb034 call relocation.
 */
void Unk0ea208_ForEachSlot(Unk0ea208Work *work)
{
    int i;
    Unk0ea208Slot *slot = work->UnkSlot0070;
    for (i = 0; i < 6; i++) {
        func_020eb034(slot);
        slot++;
    }
}

/* Require a valid work address; invoke 0eb264 only when its +0x1c4 state is 8. */
void Unk0ea208_Unk_0eb6cc(Unk0ea208Work *work)
{
  if (work->UnkField01c4 != 8) {
    return;
  }
  Unk0ea208_Unk_0eb264(work);
}

Unk0ea208Desc *func_0205ad9c(int id);
void func_0205ae60(Unk0ea208Desc *desc);
u32 Unk05b82c_CreateNamedEntry(Unk0ea208Desc *desc, int unused, const char *name);
void func_0205b9a0(void *entry);
int Unk05ae50_Unk_05b388(u32 id);
void Unk05ae50_Unk_05af2c(u32 id);
void Unk02e000_Unk_02e0cc(void);
void Unk044394_Unk_044534(u32 id);
void func_0205c368(u32 handle);
void func_0205ddb4(u32 handle);
void func_020629c4(u32 handle);
void Unk0fedd4_Unk_0fee18(void);
void func_0205bb68(void);

/*
 * Step through four resource-descriptor setup stages stored in work+0x1d0,
 * advancing the byte after each successful stage. Stage 0 clears descriptor
 * 0xd3's +0x14 entry and loads it; stage 1 does the same for ids 1..3; stage 2
 * creates the four named entries and runs the post-create hook; stage 3 waits
 * for all four to report ready, then runs the final hook on each. A stage
 * other than 0..3, and stage 3 with every id ready, report success (1); the
 * intermediate stages report 0. Evidence: the `ldrsb [work,#0x1d0]` switch
 * jump table, the data_0213c72c-indexed loops, the +1 stores, and the
 * CreateNamedEntry / readiness / final-hook call relocations. The work and
 * descriptor records are borrowed.
 */
int func_020eb324(Unk0ea208Work *work)
{
    Unk0ea208Desc *desc;
    int ready;
    int i;

    switch (work->UnkField01d0) {
    case 0:
        Unk02e000_Unk_02e0cc();
        desc = func_0205ad9c(0xd3);
        desc->UnkField14 = 0;
        func_0205ae60(desc);
        work->UnkField01d0 = work->UnkField01d0 + 1;
        break;
    case 1:
        Unk02e000_Unk_02e0cc();
        for (i = 1; i < 4; i++) {
            desc = func_0205ad9c(data_0213c72c[i]);
            desc->UnkField14 = 0;
            func_0205ae60(desc);
        }
        work->UnkField01d0 = work->UnkField01d0 + 1;
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            desc = func_0205ad9c(data_0213c72c[i]);
            desc->UnkField14 = Unk05b82c_CreateNamedEntry(desc, desc->UnkField10 + 12, 0);
            func_0205b9a0((void *)desc->UnkField14);
        }
        work->UnkField01d0 = work->UnkField01d0 + 1;
        break;
    case 3:
        ready = 1;
        for (i = 0; i < 4; i++) {
            if (Unk05ae50_Unk_05b388(data_0213c72c[i]) == 0) {
                ready = 0;
                break;
            }
        }
        if (ready == 0) {
            break;
        }
        for (i = 0; i < 4; i++) {
            Unk05ae50_Unk_05af2c(data_0213c72c[i]);
        }
        work->UnkField01d0 = work->UnkField01d0 + 1;
        return 1;
    default:
        return 1;
    }
    return 0;
}

/*
 * Advance the work state machine one step: bump the +0x1d4 frame counter,
 * wrapping it to zero at 0xffff, then process state +0x1c4. State 1 waits for
 * func_020eb324 and moves to 2; state 2 allocates the shared 0fedf4 object and
 * falls into state 3, which creates the five +0x10 and six +0x24 text objects
 * plus +0x3c; state 4 loads the four battle resources; state 5 falls into 6,
 * which rebuilds the two id value tables, submits the +0x3c resource, and
 * advances to 7; state 7 marks the work ready; state 8 advances the slots.
 * Evidence: the 0xffff wrap compare, the addls jump table, the 020629ac text
 * creation argument sets, the 02150cd4/02150ce8/02150d00/02150d18 resource
 * names, the 0x703 conditional selector, the 0204fed8 id-table stores, and the
 * state byte immediates. The work and its handles stay caller-owned.
 */
void func_020eb488(Unk0ea208Work *work)
{
  s32 frame;
  u32 selector;
  int n;
  s32 resource;
  u32 j;

  frame = work->UnkField01d4 + 1;
  work->UnkField01d4 = frame;
  if (frame >= 0xffff) {
    work->UnkField01d4 = 0;
  }
  switch (work->UnkField01c4) {
  case 1:
    if (func_020eb324(work) == 0) {
      return;
    }
    work->UnkField01c8 = 0;
    work->UnkField01c4 = 2;
    break;
  case 2:
    Unk0fedd4_Alloc(1);
    work->UnkField01c4 = 3;
    /* fall through */
  case 3:
    for (n = 0; n < 5; n++) {
      work->UnkTable0010[n] = func_020629ac(4, 1, 1, 1);
    }
    for (n = 0; n < 6; n++) {
      work->UnkTable0024[n] = func_020629ac(4, 1, 1, 1);
    }
    work->UnkField003c = func_020629ac(2, 3, 1, 0);
    work->UnkField01c4 = 4;
    break;
  case 4:
    work->UnkField0000 = func_0205dcd4(data_02150cd4, 1);
    work->UnkField0004 = func_0205dcd4(data_02150ce8, 1);
    work->UnkField0008 = func_0205dcd4(data_02150d00, 1);
    work->UnkField000c = func_0205c2c4(data_02150d18);
    work->UnkField01c4 = 5;
    break;
  case 5:
    work->UnkField01c4 = 6;
    /* fall through */
  case 6:
    Unk044394_Unk_044428(39);
    resource = func_020445f4(39, 0);
    for (j = 0; j < 5; j++) {
      selector = j + 4;
      if (selector == 7 && Unk0e651c_Unk_0e666c(0x703) == 0) {
        selector = 13;
      }
      data_02150ca0[j].value = func_0204fed8(resource, selector);
    }
    for (j = 0; j < 4; j++) {
      data_02150c80[j].value = func_0204fed8(resource, j + 9);
    }
    Unk0ea208_Unk_0eac40(work);
    work->UnkField01c4 = 7;
    /* fall through */
  case 7:
    work->UnkField01c4 = 8;
    work->UnkField01cc = 1;
    break;
  case 8:
    Unk0ea208_Unk_0eb230(work);
    break;
  default:
    break;
  }
}

/*
 * Release everything owned by one work object: run the per-slot teardown, free
 * the +0x0c, +0x08, +0x04 and +0x00 resources, clear the six +0x24 handles and
 * the five +0x10 handles and the +0x3c handle, run the 0fee18 hook, call
 * func_0205bb68 four times, and finally clear the singleton pointer at
 * data_02176ddc. Evidence: the ForEachSlot/044534 calls, the four guarded
 * release pairs, the two func_020629c4 loops with bounds 6 and 5, the
 * Unk0fedd4_Unk_0fee18 call, the four-iteration func_0205bb68 loop, and the
 * `str r1,[data_02176ddc]` literal store. The work and handles are caller-owned.
 */
void func_020eb6e4(Unk0ea208Work *work)
{
    int i;

    Unk0ea208_ForEachSlot(work);
    Unk044394_Unk_044534(39);
    if (work->UnkField000c != 0) {
        func_0205c368(work->UnkField000c);
        work->UnkField000c = 0;
    }
    if (work->UnkField0008 != 0) {
        func_0205ddb4(work->UnkField0008);
        work->UnkField0008 = 0;
    }
    if (work->UnkField0004 != 0) {
        func_0205ddb4(work->UnkField0004);
        work->UnkField0004 = 0;
    }
    if (work->UnkField0000 != 0) {
        func_0205ddb4(work->UnkField0000);
        work->UnkField0000 = 0;
    }
    for (i = 0; i < 6; i++) {
        func_020629c4(work->UnkTable0024[i]);
        work->UnkTable0024[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        func_020629c4(work->UnkTable0010[i]);
        work->UnkTable0010[i] = 0;
    }
    func_020629c4(work->UnkField003c);
    work->UnkField003c = 0;
    Unk0fedd4_Unk_0fee18();
    for (i = 0; i < 4; i++) {
        func_0205bb68();
    }
    *data_02176ddc = 0;
}
