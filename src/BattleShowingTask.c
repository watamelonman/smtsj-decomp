/*
 * src/BattleShowingTask.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02176e70[];
int func_020a0d30();
int func_02119658();

void func_0211982c(void);
void func_02119830(void);
void func_0211984c(void);
void func_02119850(void);
u32 func_02119854(void *obj);
void func_02119834(void);
void func_021196e0(u32 *arg0);
u32 func_0211c230(int arg0);

/* empty callback */
void func_0211982c(void) { }

/* empty callback */
void func_02119830(void) { }

/* empty callback */
void func_0211984c(void) { }

/* empty callback */
void func_02119850(void) { }

/* get u32 at +0x28 */
u32 func_02119854(void *obj) { return FIELD(u32, obj, 0x28); }

/* decompiler-derived */
void func_02119834(void)
{
  u32 tmp1;
  tmp1 = func_02119658();
  *data_02176e70 = tmp1;
  return;
}

/* decompiler-derived */
void func_021196e0(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  func_020a0d30(1);
  return;
}

/* decompiler-derived */
u32 func_0211c230(int arg0)
{
  u32 tmp1;
  if (*(int *)(arg0 + 0xc) < *(int *)(arg0 + 8)) {
    tmp1 = *(u32 *)(*(int *)(arg0 + 4) + *(int *)(arg0 + 0xc) * 4);
  }
  else {
    tmp1 = 0;
  }
  return tmp1;
}

typedef struct BattleResultInfo {
    u32 unk00;
    u32 expGained;              /* 0x04: total to count up to */
} BattleResultInfo;

/* EXP count-up state of the post-battle result screen (BattleShowingTask.c). */
typedef struct ExpGauge {
    BattleResultInfo *info;     /* 0x00 */
    u32 unk04[5];
    u32 gaugeAnim;              /* 0x18 */
    u32 levelUpAnim;            /* 0x1C */
    s32 fade;                   /* 0x20: brightness, 256 -> 0 */
    u32 unk24;
    s32 state;                  /* 0x28: EXP_GAUGE_* */
    s32 timer;                  /* 0x2C */
    s16 levelUps;               /* 0x30 */
    u16 unk32;
    u32 shown;                  /* 0x34: EXP counted so far */
    u32 step;                   /* 0x38: EXP added per frame */
    s32 total;                  /* 0x3C */
    s32 toNextLevel;            /* 0x40 */
} ExpGauge;

enum {
    EXP_GAUGE_FADE_IN,
    EXP_GAUGE_COUNT,
    EXP_GAUGE_LEVEL_UP,
    EXP_GAUGE_DONE,
    EXP_GAUGE_FADE_OUT
};

s32 func_0205eb20(s32 from, s32 to, s32 frames, s32 frame);  /* linear interpolation */
s32 func_0205c704(u32 anim);
void func_0205c408(u32 anim, int seq);
void func_0205c41c(u32 anim, int frame);
void func_0205c6e0(u32 anim);
void func_020a0da4(int se);
void func_02061424(ExpGauge *g);
void func_0211985c(ExpGauge *g);
void func_02119888(ExpGauge *g);
s32 func_021198b4(ExpGauge *g);
void func_02119910(ExpGauge *g);
void func_02119a10(ExpGauge *g);

/* Per-frame update: fade in, count EXP up (pausing for each level up), fade out. */
void func_02119a60(ExpGauge *g) {
    switch (g->state) {
    case EXP_GAUGE_FADE_IN:
        if (g->timer < 0) {
            g->fade = 256;
        } else {
            g->fade = func_0205eb20(256, 0, 10, g->timer);
            if (g->fade == 0) {
                g->state = EXP_GAUGE_DONE;
            }
        }
        g->timer++;
        break;
    case EXP_GAUGE_COUNT:
        if (g->info->expGained == 0) {
            g->state = EXP_GAUGE_DONE;
        }
        if (g->shown < g->info->expGained) {
            func_0205c704(g->gaugeAnim);
            g->shown += g->step;
            if (g->shown >= g->info->expGained) {
                g->shown = g->info->expGained;
            }
            func_02119910(g);
            if (g->toNextLevel <= 0) {
                g->total += func_021198b4(g);
                g->levelUps++;
                func_02119a10(g);
                func_02119910(g);
                g->state = EXP_GAUGE_LEVEL_UP;
                func_0205c408(g->levelUpAnim, 14);
                func_0205c41c(g->levelUpAnim, 0);
                func_0205c6e0(g->levelUpAnim);
                func_02119888(g);
                func_020a0da4(0x29);
            } else if (g->shown >= g->info->expGained) {
                g->state = EXP_GAUGE_DONE;
            }
        }
        break;
    case EXP_GAUGE_LEVEL_UP:
        if (func_0205c704(g->gaugeAnim) == 0) {
            if (g->shown >= g->info->expGained) {
                g->state = EXP_GAUGE_DONE;
            } else {
                g->state = EXP_GAUGE_COUNT;
            }
            func_0211985c(g);
        }
        break;
    case EXP_GAUGE_DONE:
        func_0205c704(g->gaugeAnim);
        break;
    case EXP_GAUGE_FADE_OUT:
        if (g->timer < 0) {
            g->fade = 0;
        } else {
            g->fade = func_0205eb20(0, -256, 10, g->timer);
            if (g->fade <= -256) {
                func_02061424(g);
            }
        }
        g->timer++;
        break;
    }
    if (g->levelUps != 0 && func_0205c704(g->levelUpAnim) == 0) {
        func_0205c408(g->levelUpAnim, 15);
        func_0205c41c(g->levelUpAnim, 0);
        func_0205c6e0(g->levelUpAnim);
    }
}
