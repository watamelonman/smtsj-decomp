/* Layout and behavior evidence: original ARM loads/calls; see the unit doc. */
#include "types.h"

/* Only observed offsets are named; the intervening storage is opaque. */
typedef struct Unk0f8448Work Unk0f8448Work;

/* Callback at +0x94 receives the same live work object after setup. */
typedef void (*Unk0f8448Fn)(Unk0f8448Work *work);

/* 12-byte entry walked by func_020bd1a8; only the first word is read here. */
typedef struct Unk0f8448Entry {
    u32 unk_0000;
    u8 pad_0004[0x8];
} Unk0f8448Entry;

/* Storage must extend through the callback at +0x94 before initialization. */
struct Unk0f8448Work {
    u32 unk_0000;
    u32 unk_0004;
    s32 unk_0008;
    u8 pad_000c[0x4];
    s32 unk_0010;
    u8 pad_0014[0x8];
    Unk0f8448Entry unk_001c[6]; /* 0x48 bytes up to +0x64; count of 6 inferred from that gap. */
    u32 unk_0064[0xC]; /* Extent inferred from the callback offset. */
    Unk0f8448Fn unk_0094;
};

void func_020bcc7c(void);
void func_020bccec(void);

u32 Unk0f8448_GetUnkField10(void *obj);
u32 Unk0f8448_GetUnkField0(void *obj);
u32 Unk0f8448_GetUnkField4(void *obj);
u32 Unk0f8448_GetUnkField8(void *obj);
void Unk0f8448_Thunk_020bcc7c(void);
void Unk0f8448_Thunk_020bccec(void);
int Unk0f8448_Unk_0f8468(Unk0f8448Work *work);

/* Original load at +0x10: obj must point to live work storage. */
u32 Unk0f8448_GetUnkField10(void *obj) { return ((Unk0f8448Work *)obj)->unk_0010; }

/* Original load at +0x00: callers use this as the visible entry count. */
u32 Unk0f8448_GetUnkField0(void *obj) { return ((Unk0f8448Work *)obj)->unk_0000; }

/* Original load at +0x04: preserve the word without interpreting its value. */
u32 Unk0f8448_GetUnkField4(void *obj) { return ((Unk0f8448Work *)obj)->unk_0004; }

/* Original load at +0x08: expose its bits through the existing unsigned API. */
u32 Unk0f8448_GetUnkField8(void *obj) { return ((Unk0f8448Work *)obj)->unk_0008; }

/* Original BL identifies the target; preserve its no-argument call boundary. */
void Unk0f8448_Thunk_020bcc7c(void) { func_020bcc7c(); }

/* Original BL identifies the target; preserve its no-argument call boundary. */
void Unk0f8448_Thunk_020bccec(void) { func_020bccec(); }

/* Original loads/subtract return field +0x10 minus field +0x08. */
int Unk0f8448_Unk_0f8468(Unk0f8448Work *work)
{
  return work->unk_0010 - work->unk_0008;
}

void func_020bcfc4(Unk0f8448Work *work, s32 value);
s32 func_020bd1a8(void *entries, Unk0f8448Work *work, u32 *values, s32 flag);

/* Original call sequence sets the index, updates entry storage, then invokes
 * the +0x94 callback. The caller supplies initialized fields and a valid callback. */
void Unk0f8448_Init(Unk0f8448Work *work, s32 value)
{
    func_020bcfc4(work, value);
    func_020bd1a8(work->unk_001c, work, work->unk_0064, 1);
    work->unk_0094(work);
}

/* Bounds-checked read of the first word of entry i (12-byte entries at +0x1C);
 * the bound is the count at +0x00. Returns 0 when i is out of range. */
u32 Unk0f8448_GetEntry(Unk0f8448Work *work, int i)
{
    if (i < 0 || (int)Unk0f8448_GetUnkField0(work) <= i) {
        return 0;
    }
    return work->unk_001c[i].unk_0000;
}

/* State block reached through Unk0f8448Ctx.unk_0000 (only the touched fields). */
typedef struct Unk0f8448State {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u8 pad_000c[0x8];
    s32 unk_0014; /* func_020f8558 waits for 1; set to 2 or 4. */
    u32 unk_0018;
} Unk0f8448State;

/* Owner object of func_020f84f4/func_020f8558; +0x04 is the table passed to
 * Unk02f2a8_Unk_034970, +0x7481 a step counter, +0x7482/+0x7483 a cell position. */
typedef struct Unk0f8448Ctx {
    Unk0f8448State *unk_0000;
    u8 unk_0004[0x747d]; /* Opaque table; extent runs to the next observed field. */
    s8 unk_7481;
    s8 unk_7482;
    s8 unk_7483;
} Unk0f8448Ctx;

/* Global work area (Unk02e000_GetWorkArea); only the fields read here. */
typedef struct Unk0f8448WorkArea {
    u8 pad_0000[0x358];
    u32 unk_0358;
    u8 pad_035c[0x8];
    s8 unk_0364;
    s8 unk_0365;
} Unk0f8448WorkArea;

u8 *Unk02f2a8_Unk_034970(u8 *p, int x, int y);
u8 *Unk038fbc_Unk_039160(u8 *grid, int x, int y);
u8 Unk10b4d0_Unk_10b71c(u32 arg0);
Unk0f8448WorkArea *Unk02e000_GetWorkArea(void);
u32 func_0203611c(u32 a, u32 b);
void Unk0a0ce4_Unk_0a0da4(int value);

/* Looks up the cell at (unk_7482, unk_7483), maps its first byte through
 * Unk10b4d0_Unk_10b71c and func_0203611c (with work-area word +0x358), stores
 * the result in the state block at +0x18 and sets the state's +0x14 to 4. */
void func_020f84f4(Unk0f8448Ctx *ctx)
{
    s8 y = ctx->unk_7483;
    s8 x = ctx->unk_7482;
    u8 *cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(ctx->unk_0004, x, y), x, y);
    u8 v = Unk10b4d0_Unk_10b71c(*cell);

    ctx->unk_0000->unk_0018 = func_0203611c(Unk02e000_GetWorkArea()->unk_0358, v);
    ctx->unk_0000->unk_0014 = 4;
}

/* Two-step update driven by unk_7481. Step 0: once the state's +0x14 is 1, sets
 * it (and +0x18) to 2, clears +0x08, calls Unk0a0ce4_Unk_0a0da4(55) and advances.
 * Step 1: once +0x14 is 1 again, looks up the cell at the work-area position
 * (+0x364, +0x365); if its first byte is 16..19 the position is copied to
 * unk_7482/unk_7483, func_020f84f4 runs and the step resets to 0. Returns 1 only
 * when step 1 ran and the cell did not qualify, else 0. */
int func_020f8558(Unk0f8448Ctx *ctx)
{
    u8 *grid;
    u8 *cell;
    int ret = 0;

    switch (ctx->unk_7481) {
    case 0:
        if (ctx->unk_0000->unk_0014 == 1) {
            ctx->unk_0000->unk_0018 = 2;
            ctx->unk_0000->unk_0014 = 2;
            ctx->unk_0000->unk_0008 = 0;
            Unk0a0ce4_Unk_0a0da4(55);
            ctx->unk_7481++;
        }
        break;
    case 1:
        if (ctx->unk_0000->unk_0014 == 1) {
            grid = Unk02f2a8_Unk_034970(ctx->unk_0004, Unk02e000_GetWorkArea()->unk_0364,
                                        Unk02e000_GetWorkArea()->unk_0365);
            cell = Unk038fbc_Unk_039160(grid, Unk02e000_GetWorkArea()->unk_0364,
                                        Unk02e000_GetWorkArea()->unk_0365);
            ret = 1;
            if (cell != 0 && (u8)(*cell + 0xF0) <= 3) {
                ctx->unk_7482 = Unk02e000_GetWorkArea()->unk_0364;
                ctx->unk_7483 = Unk02e000_GetWorkArea()->unk_0365;
                func_020f84f4(ctx);
                ret = 0;
                ctx->unk_7481 = ret;
            }
        }
        break;
    }
    return ret;
}
