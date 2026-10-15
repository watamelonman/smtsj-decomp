/*
 * src/BattleShowingTask.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct BattleShowingTaskWork {
    u8 pad_0000[0x4];
    s32 unk_0004;
    s32 unk_0008;
    s32 unk_000c;
    u8 pad_0010[0x8];
    s32 unk_0018;
    s32 unk_001c;
    u8 pad_0020[0x8];
    u32 unk_0028;
} BattleShowingTaskWork;

extern u32 data_02176e70[];
int Unk0a0ce4_Unk_0a0d30();
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
u32 BattleShowingTask_GetUnkField28(void *obj) { return ((BattleShowingTaskWork *)obj)->unk_0028; }

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
  Unk0a0ce4_Unk_0a0d30(1);
}

/* decompiler-derived */
u32 BattleShowingTask_Unk_11c230(BattleShowingTaskWork *work)
{
  u32 value;
  if (work->unk_000c < work->unk_0008) {
    value = *(u32 *)(work->unk_0004 + work->unk_000c * 4);
  }
  else {
    value = 0;
  }
  return value;
}

typedef struct BattleResultInfo {
    s16 unk00;                  /* 0x00: < 0 selects the alternate EXP table */
    s16 unk02;                  /* 0x02: compared against levelUps */
    u32 expGained;              /* 0x04: total to count up to */
    u16 unk08;                  /* 0x08: EXP curve id */
    s16 level;                  /* 0x0A: level before the battle */
    u32 baseExp;                /* 0x0C: EXP held before the battle */
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
void Unk0a0ce4_Unk_0a0da4(int se);
void func_02061424(ExpGauge *g);
void ExpGauge_PlayGaugeNormal(ExpGauge *g);
void ExpGauge_PlayGaugeLevelUp(ExpGauge *g);
s32 ExpGauge_GetExpForNextLevel(ExpGauge *g);
void ExpGauge_UpdateToNextLevel(ExpGauge *g);
void func_02119a10(ExpGauge *g);
s32 func_020b80c8(s32 level);
s32 func_020b8154(u16 curve, s32 level, s32 level2);

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
            ExpGauge_UpdateToNextLevel(g);
            if (g->toNextLevel <= 0) {
                g->total += ExpGauge_GetExpForNextLevel(g);
                g->levelUps++;
                func_02119a10(g);
                ExpGauge_UpdateToNextLevel(g);
                g->state = EXP_GAUGE_LEVEL_UP;
                func_0205c408(g->levelUpAnim, 14);
                func_0205c41c(g->levelUpAnim, 0);
                func_0205c6e0(g->levelUpAnim);
                ExpGauge_PlayGaugeLevelUp(g);
                Unk0a0ce4_Unk_0a0da4(0x29);
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
            ExpGauge_PlayGaugeNormal(g);
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
int Unk0a163c_Unk_0a1ae0();
/* decompiler-derived */
void BattleShowingTask_Unk_11ce80(int arg0)
{
  func_02053000(((BattleShowingTaskWork *)arg0)->unk_0004);
  ((BattleShowingTaskWork *)arg0)->unk_0004 = 0;
  Unk0a163c_Unk_0a1ae0(arg0 + 0x10);
  *data_02176e74 = 0;
  return;
}

int func_0205c3dc();
/* decompiler-derived */
void BattleShowingTask_Unk_11a01c(int arg0)
{
  if (((BattleShowingTaskWork *)arg0)->unk_0018 != 0) {
    func_0205c3dc();
    ((BattleShowingTaskWork *)arg0)->unk_0018 = 0;
  }
  if (((BattleShowingTaskWork *)arg0)->unk_001c == 0) {
    return;
  }
  func_0205c3dc();
  ((BattleShowingTaskWork *)arg0)->unk_001c = 0;
  return;
}



/* decompiler-derived */
void BattleShowingTask_Unk_11a8dc(int arg0,u32 arg1)
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

int func_020493e0();
int func_0204faf0();
int func_02065628();
int func_0206569c();
int func_02065bc0();
int func_02065cfc();
/* decompiler-derived */
void BattleShowingTask_Unk_11c670(int arg0)
{
  int tmp1;
  tmp1 = BattleShowingTask_Unk_11c230((BattleShowingTaskWork *)arg0);
  func_0204faf0(6,*(u16 *)(tmp1 + 8));
  func_02065bc0();
  func_02065628(1);
  func_020493e0(10);
  func_0206569c();
  func_02065cfc(1,0);
}

int func_02065864();
/* decompiler-derived */
void BattleShowingTask_Unk_11c5d0(int arg0)
{
  int tmp1;
  u32 tmp2;
  tmp1 = BattleShowingTask_Unk_11c230((BattleShowingTaskWork *)arg0);
  func_0204faf0(6,*(u16 *)(tmp1 + 8));
  func_02065bc0();
  func_02065628(1);
  tmp2 = func_020493e0(5);
  func_02065864(tmp2,1);
  func_02065cfc(1,0);
}

int func_0204fcb0();
/* decompiler-derived */
void BattleShowingTask_Unk_11c610(int arg0)
{
  int tmp1;
  u32 tmp2;
  tmp1 = BattleShowingTask_Unk_11c230((BattleShowingTaskWork *)arg0);
  func_0204faf0(6,*(u16 *)(tmp1 + 8));
  func_0204faf0(10,*(u16 *)(tmp1 + 0x1c));
  tmp2 = Unk0caea8_Unk_0cb044(*(u16 *)(tmp1 + 0x1e));
  func_0204fcb0(1,tmp2);
  func_02065bc0();
  func_02065628(1);
  func_020493e0(6);
  func_0206569c();
  func_02065cfc(1,0);
}

extern u8 data_0213ccc0[];
int func_02057df8();
int func_02057e18();
int func_02057fd8();
int func_020580ec();
int func_0205c848();
int func_0205dee8();
int func_0211b100();
int func_0211b2ac();
/* decompiler-derived */
void BattleShowingTask_Unk_11b4e4(u32 *arg0)
{
  int tmp1;
  u32 tmp2;
  u8 *v3;
  Unk044904_Unk_04502c();
  func_02057e18(0x1f);
  func_02057df8();
  func_020580ec(0);
  switch(*arg0) {
  case 0:
    goto LAB_0211b670;
  case 1:
    goto LAB_0211b670;
  case 2:
    goto LAB_0211b54c;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
LAB_0211b54c:
    func_02057fd8();
    tmp1 = 0;
    do {
      if ((arg0[0x14] != 0 || tmp1 != 0) && (arg0[0x13] != 0 || tmp1 != 5)) {

        func_0205c848(2,arg0[tmp1 + 0xb5],0,0,0x3f800000,0x3f800000,0,0x3f800000,0);
      }
      tmp1 = tmp1 + 1;
    } while (tmp1 < 6);
    func_0211b100(arg0,*(u32 *)(arg0[0xb5] + 0x14),
                  *(u32 *)(arg0[0xb5] + 0x28));
    func_0211b2ac(arg0,*(u32 *)(arg0[0xb5] + 0x28));
    goto LAB_0211b670;
  case 10:
    goto LAB_0211b670;
  case 0xb:
    goto LAB_0211b670;
  case 0xc:
    goto LAB_0211b670;
  }
  func_02057fd8();
  tmp2 = 0;
  v3 = data_0213ccc0;
  do {
    if ((arg0[0x14] != 0 || tmp2 != 0) && (arg0[0x13] != 0 || tmp2 != 3)) {

      func_0205dee8(2,arg0[0xb1],*v3,0,0,0x3f800000,0x3f800000,0,0x3f800000,0);
    }
    tmp2 = tmp2 + 1;
    v3 = v3 + 1;
  } while (tmp2 < 6);
  func_0211b100(arg0,0,0x1000);
  func_0211b2ac(arg0,0x1000);
LAB_0211b670:
  func_020580ec(1);
}

/* Gauge back to its normal sequence after a level-up pause. */
void ExpGauge_PlayGaugeNormal(ExpGauge *g)
{
    func_0205c408(g->gaugeAnim, 17);
    func_0205c41c(g->gaugeAnim, 0);
    func_0205c6e0(g->gaugeAnim);
}

/* Gauge level-up sequence. */
void ExpGauge_PlayGaugeLevelUp(ExpGauge *g)
{
    func_0205c408(g->gaugeAnim, 16);
    func_0205c41c(g->gaugeAnim, 0);
    func_0205c6e0(g->gaugeAnim);
}

/* EXP needed for the next level (curve lookup unless unk00 < 0). */
s32 ExpGauge_GetExpForNextLevel(ExpGauge *g)
{
    s32 to;
    if (g->info->unk00 < 0) {
        return func_020b80c8(g->info->level + g->levelUps);
    }
    to = g->info->level;
    if (g->state == EXP_GAUGE_DONE || g->info->unk02 == g->levelUps) {
        to = g->info->level + g->levelUps;
    }
    return func_020b8154(g->info->unk08, g->info->level + g->levelUps, to);
}

/* Recompute EXP remaining until the next level. */
void ExpGauge_UpdateToNextLevel(ExpGauge *g)
{
    g->toNextLevel = ExpGauge_GetExpForNextLevel(g) - ((g->info->baseExp + g->shown) - g->total);
}
