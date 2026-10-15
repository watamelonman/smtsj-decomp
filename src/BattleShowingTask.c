/*
 * src/BattleShowingTask.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct BattleShowingTaskWork {
    u8 unk_0000[0x4];
    s32 UnkField0004;
    s32 UnkField0008;
    s32 UnkField000c;
} BattleShowingTaskWork;


extern u32 data_02176e70[];
int func_020a0d30();
int func_02119658();

void BattleShowingTask_Nop_11982c(void);
void BattleShowingTask_Nop_119830(void);
void BattleShowingTask_Nop_11984c(void);
void BattleShowingTask_Nop_119850(void);
u32 BattleShowingTask_GetUnkField28(void *obj);
void BattleShowingTask_Unk_119834(void);
void BattleShowingTask_Unk_1196e0(u32 *arg0);
u32 BattleShowingTask_Unk_11c230(BattleShowingTaskWork *work);

/* empty callback */
void BattleShowingTask_Nop_11982c(void) { }

/* empty callback */
void BattleShowingTask_Nop_119830(void) { }

/* empty callback */
void BattleShowingTask_Nop_11984c(void) { }

/* empty callback */
void BattleShowingTask_Nop_119850(void) { }

/* get u32 at +0x28 */
u32 BattleShowingTask_GetUnkField28(void *obj) { return FIELD(u32, obj, 0x28); }

/* decompiler-derived */
void BattleShowingTask_Unk_119834(void)
{
  u32 value;
  value = func_02119658();
  *data_02176e70 = value;
}

/* decompiler-derived */
void BattleShowingTask_Unk_1196e0(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  func_020a0d30(1);
}

/* decompiler-derived */
u32 BattleShowingTask_Unk_11c230(BattleShowingTaskWork *work)
{
  u32 value;
  if (work->UnkField000c < work->UnkField0008) {
    value = *(u32 *)(work->UnkField0004 + work->UnkField000c * 4);
  }
  else {
    value = 0;
  }
  return value;
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

s32 Unk_InterpolateLinear(s32 from, s32 to, s32 frames, s32 frame);  /* linear interpolation */
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
void ExpGauge_Update(ExpGauge *g) {
    switch (g->state) {
    case EXP_GAUGE_FADE_IN:
        if (g->timer < 0) {
            g->fade = 256;
        } else {
            g->fade = Unk_InterpolateLinear(256, 0, 10, g->timer);
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
            g->fade = Unk_InterpolateLinear(0, -256, 10, g->timer);
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


int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void BattleShowingTask_Unk_11c4c4(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_020445f4(0x29);
  func_0204fed8(tmp1,arg0);
  return;
}

int func_02044534();
int func_0211a380();
/* decompiler-derived */
void BattleShowingTask_Unk_11b684(void)
{
  func_0211a380();
  func_02044534(0x17);
  func_02044534(0x21);
  func_02044534(0x29);
  return;
}

extern u32 data_02176e74[];
int func_02053000();
int func_020a1ae0();
/* decompiler-derived */
void BattleShowingTask_Unk_11ce80(int arg0)
{
  func_02053000(*(u32 *)(arg0 + 4));
  *(u32 *)(arg0 + 4) = 0;
  func_020a1ae0(arg0 + 0x10);
  *data_02176e74 = 0;
  return;
}

int func_0205c3dc();
/* decompiler-derived */
void BattleShowingTask_Unk_11a01c(int arg0)
{
  if (*(int *)(arg0 + 0x18) != 0) {
    func_0205c3dc();
    *(u32 *)(arg0 + 0x18) = 0;
  }
  if (*(int *)(arg0 + 0x1c) == 0) {
    return;
  }
  func_0205c3dc();
  *(u32 *)(arg0 + 0x1c) = 0;
  return;
}



/* decompiler-derived */
void func_0211a8dc(int arg0,u32 arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = 0;
  tmp2 = arg0;
  do {
    if (arg1 == *(u16 *)(tmp2 + 0x268)) {
      *(u8 *)(arg0 + 0x26c + tmp1 * 6) = *(u8 *)(arg0 + 0x26c + tmp1 * 6) | 8;
      return;
    }
    tmp1 = tmp1 + 1;
    tmp2 = tmp2 + 6;
  } while (tmp1 < 0xf);
  return;
}


