/*
 * src/game/unit_0203e43c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_020119c0(void *dst, int value, u32 size);
void func_0203e93c(int mode, int x, int y, void *resource, void *entry);
void func_0203f394(const void *src, void *dst, int x, int y, int srcX, int srcY, int width, int height);
void func_0203f450(const void *src, void *dst, int x, int y, int a, int b, int width, int height,
                   int c, int d, int e);

extern u8 data_0215e85e[];
int Unk02e000_GetWorkArea();
int Unk03e43c_Div10Clamp16();
void func_0203fa84(void);
int func_0205410c();

void Unk03e43c_Thunk_0203fa84(void);
u8 *Unk03e43c_Unk_03f2ac(int offset);
int Unk03e43c_Unk_03fa28(void);
void Unk03e43c_Unk_03f2bc(void);
void Unk03e43c_Unk_03fa3c(u8 value);

typedef struct Unk03e43cTimer {
    u8 pad_0000[0x58];
    u16 count;                  /* +0x58 */
} Unk03e43cTimer;

extern u8 data_0215e85c[];
/*
 * Copies one 32-byte entry from `src` into table slot `slot`. The payload
 * starts two bytes past the slot base because the u16 header at data_0215e85c
 * precedes the 512-byte table at data_0215e85e; callers pass a resource entry
 * and a slot number (func_020b5e2c loads consecutive slots).
 */
void Unk03e43c_CopyEntry32(u8 *src, int slot)
{
    int i;
    for (i = 0; i < 32; i += 2) {
        data_0215e85c[slot * 32 + i + 2] = src[i];
        data_0215e85c[slot * 32 + i + 3] = src[i + 1];
    }
}

/*
 * Merges the nonzero u16 entries of the 512-byte `src` table into the shared
 * table at data_0215e85c (payload at +2); zero entries leave the destination
 * unchanged. Callers pass a scratch table of at least 512 bytes.
 */
void Unk03e43c_MergeTable(u8 *src)
{
    int i;
    for (i = 0; i < 512; i += 2) {
        if (src[i] != 0 || src[i + 1] != 0) {
            data_0215e85c[i + 2] = src[i];
            data_0215e85c[i + 3] = src[i + 1];
        }
    }
}

void func_02020f8c(void);
void func_02008848(void *destination, int value, u32 size);
int func_0202092c();
void func_020211d8();
void func_0204b6d0(void);
void Unk03e43c_Unk_043450(s16 *x, s16 *y, u32 unused);
extern u8 data_0215ee60[];
/* Clears the 512-byte table and its leading u16 after func_02020f8c;
 * the two global stores in the original establish the table extent. */
void Unk03e43c_ClearTable(void)
{
    func_02020f8c();
    func_02008848(data_0215e85e, 0, 512);
    *(u16 *)data_0215e85c = 0;
}

/*
 * Initializes one 32-byte draw entry: derives a value with
 * func_0202092c(resource, index) and passes it with the setup pointer `a` to
 * func_020211d8, then clears the u16 countdown at entry + 0x58. The original
 * truncates `index` to u16 before the helper call. Callers pass the resource
 * handles from a setup record (func_020b28e8).
 */
void Unk03e43c_Unk_03e894(u8 *entry, void *a, void *b, int index)
{
    func_020211d8(entry, func_0202092c(b, (u16)index), a);
    FIELD(u16, entry, 0x58) = 0;
}

/*
 * Decrements the 16-bit countdown at +0x58 of `t` when it is nonzero and
 * returns 1 once the counter has already reached zero (so callers can stop).
 */
int Unk03e43c_CountDown(Unk03e43cTimer *t)
{
    if (t->count == 0) {
        return 1;
    }
    t->count--;
    return 0;
}

/*
 * Maps a 0..159 counter to a 0..15 table slot by dividing by 10. Quotients
 * that would not fit in four bits (>= 16) return the -1 sentinel.
 */
int Unk03e43c_Div10Clamp16(int x)
{
    int r = x / 10;
    if (r >= 16) {
        r = -1;
    }
    return r;
}

/* The byte access at +0x360 and comparison with 160 establish this counter:
 * increment with byte wrap, then subtract 160 if the stored value is >= 160. */
void Unk03e43c_AdvanceCounter360(void)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 v = ++w[0x360];
    if (v >= 160) {
        w[0x360] -= 160;
    }
}

/* Forwards to `func_0203fa84` (tail call in the original). */
void Unk03e43c_Thunk_0203fa84(void) { func_0203fa84(); }

/*
 * Returns a byte pointer `offset` bytes into the shared table at data_0215e85e.
 * Unk03e43c_Unk_044194 treats the result as a u16 array.
 */
u8 *Unk03e43c_Unk_03f2ac(int offset)
{
  return data_0215e85e + offset;
}

/*
 * Returns the work-area counter at +0x360 mapped through Unk03e43c_Div10Clamp16
 * (a 0..15 table slot, or -1 when the counter is out of range).
 */
int Unk03e43c_Unk_03fa28(void)
{
  u8 *work = (u8 *)Unk02e000_GetWorkArea();
  return Unk03e43c_Div10Clamp16(work[0x360]);
}

/* Sets bit 1 of the byte at +0x10 in the object returned by func_0205410c. */
void Unk03e43c_Unk_03f2bc(void)
{
  u8 *p = (u8 *)func_0205410c();
  p[0x10] |= 2;
}

/* Stores `value * 10` in the work-area counter byte at +0x360 (inverse of /10). */
void Unk03e43c_Unk_03fa3c(u8 value)
{
  u8 *work = (u8 *)Unk02e000_GetWorkArea();
  work[0x360] = value * 10;
}


int func_02020974(int value, u32 argument);
int func_02051610(u32 argument);
int func_020516d0(u32 value);
/* Obtains a value from arg1, validates it with func_02020974 and arg0,
 * and releases it on validation failure. Returns zero on either failure. */
int Unk03e43c_Unk_03e5a4(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020974(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_020207d0(int value, u32 argument);
/* Returns the acquired value when func_020207d0 accepts it with arg0;
 * releases rejected values and returns zero on failure. */
int Unk03e43c_Unk_03e5dc(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_020207d0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020ac0(int value, u32 argument);
/* Returns the acquired value when func_02020ac0 accepts it with arg0;
 * releases rejected values and returns zero on failure. */
int Unk03e43c_Unk_03e614(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020ac0(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

int func_02020a74(int value, u32 argument);
/* Returns the acquired value when func_02020a74 accepts it with arg0;
 * releases rejected values and returns zero on failure. */
int Unk03e43c_Unk_03e64c(u32 arg0,u32 arg1)
{
  int value1;
  int value2;
  value1 = func_02051610(arg1);
  if (value1 != 0) {
    value2 = func_02020a74(value1,arg0);
    if (value2 != 0) {
      return value1;
    }
    func_020516d0(value1);
  }
  return 0;
}

/* Work area returned by Unk02e000_GetWorkArea; only +0x35c is named here. */
typedef struct Unk03e43cWorkArea {
    u8 pad_0000[0x35c];
    u16 unk_035c;               /* passed to func_0203fb14 when func_0204b4c4() is 0 */
} Unk03e43cWorkArea;

/* 0x299c-byte task object allocated by func_0203fa84 (size from its func_020611dc call);
 * only the field written there is named. */
typedef struct Unk03e43cTask {
    u8 pad_0000[0x28dc];
    Unk03e43cWorkArea *unk_28dc;
} Unk03e43cTask;

/* Header returned by func_02056110: list passed to func_0205bf18 at +8, callback at +0x201c. */
typedef struct Unk03e684Table {
    u8 pad_0000[8];
    u8 unk_0008[0x201c - 0x8];  /* size runs up to the callback; real extent unknown */
    u32 (*unk_201c)(int mode, u32 a, u32 b);
} Unk03e684Table;

/* Argument block passed by pointer to func_0205bf18. */
typedef struct Unk03e684Args {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} Unk03e684Args;

Unk03e684Table *func_02056110(u32 a);
void func_0205bf18(u8 *list, Unk03e684Args *args);
void *func_020611dc(void *update, void *hook1, void *hook2, void *cleanup,
    u32 size, u32 arg5, u32 arg6, u32 arg7);
void func_02040064(void);
void func_020416bc(void);
void Unk03e43c_Unk_041ce4(u8 *p);
int func_0204b4c4(void);
u16 Unk04bb9c_GetCtxUnka20(void);
void func_0203fb14(Unk03e43cTask *task, u32 value);

/*
 * Looks up the table for `id` via func_02056110, asks its callback at +0x201c
 * for a value (mode 4, args b and c), and passes {a, d, value, 0, 0, 0, 0} with
 * the table's list at +8 to func_0205bf18. Meanings of the values are unknown.
 */
void func_0203e684(u32 id, u32 a, u32 b, u32 c, u32 d)
{
    Unk03e684Table *t = func_02056110(id);
    Unk03e684Args args;
    args.unk_08 = t->unk_201c(4, b, c);
    args.unk_00 = a;
    args.unk_04 = d;
    args.unk_0c = 0;
    args.unk_10 = 0;
    args.unk_14 = 0;
    args.unk_18 = 0;
    func_0205bf18(t->unk_0008, &args);
}

/* Copies the 32 bytes at source +0x28 into table slot index. The paired
 * byte loads/stores establish the extent; callers must supply a valid slot. */
void Unk03e43c_Unk_03e794(const u8 *source, int index)
{
    const u8 *pair;
    int offset = 0;
    u8 *destination = data_0215e85c + index * 32;
    do {
        pair = source + offset;
        offset += 2;
        destination[2] = pair[0x28];
        destination[3] = pair[0x29];
        destination += 2;
    } while (offset < 32);
}




int GameState_GetBody();
/* Stores mode at global +0x30; the original checks mode 1 and a zero
 * word at +0x34 before calling func_0204b6d0. These accesses support the name. */
void Unk03e43c_SetMode30(int mode)
{
    FIELD(s32, data_0215ee60, 0x30) = mode;
    if (mode == 1 && FIELD(u32, data_0215ee60, 0x34) == 0) {
        func_0204b6d0();
    }
}

/*
 * Recomputes the two s16 screen coordinates at +0x18/+0x1a through
 * Unk03e43c_Unk_043450, forwarding the object's +0x2000:+0x8dc word as the
 * helper's third argument. When either coordinate changed, sets the dirty
 * flag word at +0x04 to 1; otherwise it leaves the object untouched.
 */
void Unk03e43c_UpdatePos18(u8 *o)
{
    s16 x = FIELD(s16, o, 0x18);
    s16 y = FIELD(s16, o, 0x1a);
    Unk03e43c_Unk_043450((s16 *)(o + 0x18), (s16 *)(o + 0x1a),
                         FIELD(u32, o, 0x28dc));
    if (FIELD(s16, o, 0x18) != x || FIELD(s16, o, 0x1a) != y) {
        FIELD(u32, o, 0x04) = 1;
    }
}

/* Clamps the two signed coordinates to upper bounds 176/112 and lower
 * bounds -8*(map dimension-10), using GameState_GetBody()+0x354 map bytes.
 * Both coordinate pointers must be writable. */
void Unk03e43c_Unk_0434b0(s16 *arg0,s16 *arg1)
{
  int value;
  if (0xb0 < *arg0) {
    *arg0 = 0xb0;
  }
  if (0x70 < *arg1) {
    *arg1 = 0x70;
  }
  value = GameState_GetBody();
  if ((int)*arg0 < (int)((*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8)) {
    value = GameState_GetBody();
    *arg0 = (*(u8 *)(*(int *)(value + 0x354) + 10) - 10) * -8;
  }
  value = GameState_GetBody();
  if ((int)*arg1 < (int)((*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8)) {
    value = GameState_GetBody();
    *arg1 = (*(u8 *)(*(int *)(value + 0x354) + 0xb) - 10) * -8;
    return;
  }
}

int func_02056cc0(int mode, int index, u8 *table);
/*
 * Registers the 512-byte table at data_0215e85e with func_02056cc0, passing the
 * (1, 0, table) arguments seen in the original.
 */
void Unk03e43c_Call_02056cc0(void)
{
  func_02056cc0(1,0,data_0215e85e);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

typedef struct Unk03e43cEnt { u8 pad[4]; u16 unk_04; u8 pad2[2]; } Unk03e43cEnt;
typedef struct Unk03e43cTab { u16 n; u8 pad[10]; Unk03e43cEnt *ents; } Unk03e43cTab;
/*
 * Advances the u16 counter at +0x58 by one until it reaches the sum of the
 * u16 durations at +4 of every entry in the table referenced at +0x1c.
 * Returns 1 when the counter is already at or above the total (no write), or
 * 0 after incrementing it. The animation/timing meaning is not known.
 */
int Unk03e43c_Unk_03e8cc(u8 *p)
{
    Unk03e43cTab *q = FIELD(Unk03e43cTab *, p, 28);
    u32 sum = 0;
    u32 i;
    for (i = 0; i < q->n; i++) {
        sum += q->ents[i].unk_04;
    }
    if (FIELD(u16, p, 88) >= sum) {
        return 1;
    }
    FIELD(u16, p, 88)++;
    return 0;
}

/*
 * Shifts *a by 512 (and *b by 256) toward x (y) when the distance between them
 * exceeds half that period (256 / 128), i.e. unwraps two periodic coordinates
 * so they lie on the same side as the target. The axis meanings are unknown.
 */
void Unk03e43c_Unk_03f234(s16 *a, s16 *b, int x, int y)
{
    int v = *a;
    int d = x - v;
    if (d < 0) {
        d = -d;
    }
    if (d > 256) {
        if (v < x) {
            *a += 512;
        } else if (v > x) {
            *a -= 512;
        }
    }
    v = *b;
    d = y - v;
    if (d < 0) {
        d = -d;
    }
    if (d > 128) {
        if (v < y) {
            *b += 256;
        } else if (v > y) {
            *b -= 256;
        }
    }
}

void func_020629c4();
int GameState_GetUnkField74f4();
int GameState_GetUnkField74f6();
int Unk02f078_TestFlag380();
void Unk04bb9c_SetCtxUnka14();
void Unk03e43c_Unk_044194(u8 *p);
void Unk03e43c_MergeTable(u8 *src);
void Unk03e43c_Call_02056cc0(void);

/* Fills a rectangle clipped to a 256 by 192 byte surface; negative origins
 * discard the corresponding leading rows/columns. The caller owns the buffer. */
void func_0203f960(u8 *dst, int x, int y, int width, u16 h, u8 color)
{
    int top, height, left, offset;
    if (x >= 256 || x + width < 0 || y >= 192 || y + h < 0) {
        return;
    }
    left = 0;
    top = 0;
    height = h;
    if (x < 0) {
        width += x;
        left = -x;
    }
    if (x > 256 - width) {
        width = 256 - x;
    }
    if (y < 0) {
        height += y;
        top = -y;
    }
    if (y > 192 - height) {
        height = 192 - y;
    }
    y += top;
    offset = x + left + (y << 8);
    for (int row = top; row < top + height; row++, offset += 256) {
        func_020119c0(dst + offset, color, width);
    }
}

/*
 * Creates a 0x299c-byte task through func_020611dc with callbacks
 * func_02040064, func_020416bc and Unk03e43c_Unk_041ce4 (third slot empty),
 * stores the work area in it, then calls func_0203fb14 with either
 * Unk04bb9c_GetCtxUnka20() (when func_0204b4c4() is nonzero) or the work-area
 * u16 at +0x35c. Reached through Unk03e43c_Thunk_0203fa84.
 */

void func_0203fa84(void)
{
    Unk03e43cTask *task = func_020611dc(func_02040064, func_020416bc, 0, Unk03e43c_Unk_041ce4,
        0x299c, 0, 0, 0);
    task->unk_28dc = (Unk03e43cWorkArea *)Unk02e000_GetWorkArea();
    if (func_0204b4c4() != 0) {
        func_0203fb14(task, Unk04bb9c_GetCtxUnka20());
    } else {
        func_0203fb14(task, task->unk_28dc->unk_035c);
    }
}

/*
 * Cleanup callback registered by func_0203fa84: releases four handles
 * (+0xc, +0x2874, +0x2878, +0x287c) with func_020516d0, calls func_0204b6d0
 * when the mode word at data_0215ee60+0x30 is 1, passes +0x298c to
 * func_020629c4 and clears it, then clears data_0215ee60 +0x30/+0x34.
 */
void Unk03e43c_Unk_041ce4(u8 *p)
{
    func_020516d0(FIELD(u32, p, 12));
    func_020516d0(FIELD(u32, p + 0x2000, 2228));
    func_020516d0(FIELD(u32, p + 0x2000, 2232));
    func_020516d0(FIELD(u32, p + 0x2000, 2236));
    if (FIELD(s32, data_0215ee60, 48) == 1) {
        func_0204b6d0();
    }
    func_020629c4(FIELD(u32, p + 0x2000, 2444));
    if (FIELD(u32, p + 0x2000, 2444) != 0) {
        FIELD(u32, p + 0x2000, 2444) = 0;
    }
    FIELD(u32, data_0215ee60, 48) = 0;
    FIELD(u32, data_0215ee60, 52) = 0;
}

/* Submits slot+3 and then one of entries 0..2 selected by the signed byte
 * at +0x2982+slot. Entry stride 96 and call coordinates come from the assembly. */
/*
 * Draws the 8x8 icon attached to `obj` at (x, y), choosing the blit path from
 * the work-area mode at +0x358. The draw is skipped unless the work-area
 * context id at +0x35c still matches the active context. Modes 1 and 2 pass
 * a rotation (90 or 0 degrees) to func_0203f450; the fallback mirrors.
 */
void func_02041d98(u8 *obj, int x, int y)
{
    u8 *work = FIELD(u8 *, obj, 0x28dc);
    int mode;
    if (FIELD(u16, work, 0x35c) != Unk04bb9c_GetCtxUnka20()) {
        return;
    }
    mode = FIELD(int, work, 0x358);
    if (mode == 0) {
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14),
                      x + FIELD(s16, obj, 0x1c) + 1, y + FIELD(s16, obj, 0x1e) + 1,
                      0x20, 0, 8, 8);
        return;
    }
    if (mode == 1) {
        func_0203f450(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14),
                      x + FIELD(s16, obj, 0x1c), y + FIELD(s16, obj, 0x1e) + 1,
                      0x20, 0, 8, 8, 90, 0, 0);
        return;
    }
    if (mode == 2) {
        func_0203f450(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14),
                      x + FIELD(s16, obj, 0x1c) + 1, y + FIELD(s16, obj, 0x1e),
                      0x20, 0, 8, 8, 0, 1, 0);
        return;
    }
    func_0203f450(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14),
                  x + FIELD(s16, obj, 0x1c) + 1, y + FIELD(s16, obj, 0x1e) + 1,
                  0x20, 0, 8, 8, 90, 0, 1);
}

void func_02043340(u8 *work, int slot)
{
    int state;
    func_0203e93c(1, 128, 96, work + 0x28a0, work + 32 + (slot + 3) * 96);
    state = FIELD(s8, work + slot, 0x2982);
    if (state == 0) {
        func_0203e93c(1, 128 + (slot << 6), 96, work + 0x28a0, work + 32);
    } else if (state == 1) {
        func_0203e93c(1, 128 + (slot << 6), 96, work + 0x28a0, work + 128);
    } else if (state == 2) {
        func_0203e93c(1, 128 + (slot << 6), 96, work + 0x28a0, work + 224);
    }
}

/*
 * Computes the two s16 screen coordinates pointed to by `x` and `y` from the
 * signed map bytes at work+0x300:+100/+101 and the matching GameState fields:
 * coordinate = 128/96 - ((mapByte - gameField) * 8). The third argument is
 * forwarded by Unk03e43c_UpdatePos18 but this body does not read it.
 */

void Unk03e43c_Unk_043450(s16 *x, s16 *y, u32 unused)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    *x = 128 - ((s8)(FIELD(s8, w + 0x300, 100) - GameState_GetUnkField74f4()) << 3);
    w = (u8 *)Unk02e000_GetWorkArea();
    *y = 96 - ((s8)(FIELD(s8, w + 0x300, 101) - GameState_GetUnkField74f6()) << 3);
}

/*
 * Counts the 37 flags at indices 0..36 through Unk02f078_TestFlag380 and maps
 * the total to a tier constant: >20 -> 48, >16 -> 24, >12 -> 23, >8 -> 22,
 * >4 -> 21, otherwise 20. The flag/tier meanings are not known.
 */
int Unk03e43c_Unk_043560(void)
{
    int n = 0;
    int i;
    for (i = 0; i < 37; i++) {
        if (Unk02f078_TestFlag380(i) != 0) {
            n++;
        }
    }
    if (n > 20) {
        return 48;
    }
    if (n > 16) {
        return 24;
    }
    if (n > 12) {
        return 23;
    }
    if (n > 8) {
        return 22;
    }
    if (n > 4) {
        return 21;
    }
    return 20;
}

/*
 * Resets the seven per-slot bytes at p+0x2000:+0x982, writes 0x73f5 into the
 * four u16 table entries at slots 1..4, merges those nonzero entries into the
 * shared table, and re-registers the table with the resource layer. The
 * per-slot flag and value meanings are not known.
 */
/* Draws a small 7x7 icon selected by `index` at (x, y). */
void func_02043ea8(u8 *obj, int index, int x, int y)
{
    if (index <= 0) return;
    if (index >= 37) return;
    switch (index) {
    case 2:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0x30, 0, 7, 7);
        return;
    case 13:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0x88, 0, 7, 7);
        return;
    case 18:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0xb0, 0, 7, 7);
        return;
    case 19:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0xb8, 0, 7, 7);
        return;
    case 23:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0x10, 8, 7, 7);
        return;
    case 24:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0x18, 8, 7, 7);
        return;
    case 21:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0, 8, 7, 7);
        return;
    case 22:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 8, 8, 7, 7);
        return;
    case 14:
        func_0203f394(FIELD(void *, obj, 0xc), FIELD(void *, obj, 0x14), x + 1, y + 1, 0x90, 0, 7, 7);
        break;
    default:
        return;
    }
}

void Unk03e43c_Unk_044194(u8 *p)
{
    u16 *t;
    int i;
    for (i = 0; i < 7; i++) {
        FIELD(u8, p + i + 0x2000, 2434) = 0;
    }
    t = (u16 *)Unk03e43c_Unk_03f2ac(0);
    for (i = 0; i <= 3; i++) {
        t[i + 1] = 0x73f5;
    }
    Unk03e43c_MergeTable((u8 *)t);
    Unk03e43c_Call_02056cc0();
}

/*
 * Resets the object at data_0215ee60+0x34: clears the bytes at +0x2986, +0x2987,
 * +0x28e3 and the words at +0x28cc, +0x4, +0x10, +0x28c4, re-runs
 * Unk03e43c_Unk_044194 on it and sets the context field via
 * Unk04bb9c_SetCtxUnka14(-1). Field meanings are unknown.
 */
void Unk03e43c_Unk_0441ec(void)
{
    FIELD(u8, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2438) = 0;
    FIELD(u8, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2439) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2252) = 0;
    Unk03e43c_Unk_044194(FIELD(u8 *, data_0215ee60, 52));
    Unk04bb9c_SetCtxUnka14(-1);
    FIELD(u8, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2275) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52), 4) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52), 16) = 0;
    FIELD(u32, FIELD(u8 *, data_0215ee60, 52) + 0x2000, 2244) = 0;
}
