/*
 * src/game/unit_020ea208.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/*
 * One of the six 56-byte slot records that start at work+0x70. Only the first
 * word is read by the functions in this file; the rest of the record is owned
 * by func_020eb034 / func_020eb0a8 and is intentionally opaque here.
 */
typedef struct Unk0ea208Slot {
    u32 UnkField00;
    u8 unk_0004[52];
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
    u8 UnkField01d0;
} Unk0ea208Work;


extern u32 data_02176ddc[];
void func_020572d8(void);
void func_02057eb8(s32 value);
void Unk09974c_Unk_099bac(u32 value);
void Unk0caea8_Unk_0cb044(u32 value);
int Unk0e8228_Unk_0e8374(int selector);
int Unk0e8228_GetArr88Field20(int index);
u32 Unk0e8228_Unk_0e8f38(void);

void Unk0ea208_Unk_0ead3c(void);
u32 Unk0ea208_Get_data_02176ddc(void);
void Unk0ea208_Unk_0eaca0(void);
u32 Unk0ea208_Unk_0ea72c(void);
void Unk0ea208_Unk_0ead4c(void);

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02061f10(u32 value, s32 arg1, s32 arg2, s32 arg3, u32 arg4);

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

void func_020eb0a8(Unk0ea208Slot *slot);

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

void func_020eb178(Unk0ea208Slot *slot);
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
/* decompiler-derived */
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

/* decompiler-derived */
void Unk0ea208_Unk_0ea984(u32 arg0)
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
    func_0204fed8(tmp1,1);
    return;
  }
  func_0204faf0(1,tmp6);
  func_0204fed8(tmp1,0);
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
