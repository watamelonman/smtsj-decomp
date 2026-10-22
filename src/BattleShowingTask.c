/*
 * src/BattleShowingTask.c: battle-showing task callbacks and the post-battle EXP gauge.
 * The functions matched for this card are hand-written; the remaining decompiler-derived
 * bodies are still being cleaned up. Field meanings are not all known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct BattleShowingTaskWork {
    u8 pad_0000[0x4];
    u32 *unk_0004;              /* 0x04: record table, unk_0008 entries */
    s32 unk_0008;
    s32 unk_000c;
    u8 pad_0010[0x8];
    s32 unk_0018;
    s32 unk_001c;
    u8 pad_0020[0x8];
    u32 unk_0028;
} BattleShowingTaskWork;

/* Task object created by func_020611dc; init only touches its first two words. */
typedef struct BattleShowingTask {
    u32 unk_0000;
    u32 unk_0004;
} BattleShowingTask;

/* Handle of the live battle-showing task (bss); 0 when none is running. */
extern u32 data_02176e70;
/* Task-side call forwarded by BattleShowingTask_Unk_1196e0 during task init. */
void Unk0a0ce4_Unk_0a0d30(u32 arg);
/* Creates the task object through func_020611dc and returns it, or 0. */
u32 func_02119658(void);

void BattleShowingTask_Nop_11982c(void);
void BattleShowingTask_Nop_119830(void);
void BattleShowingTask_Nop_11984c(void);
void BattleShowingTask_Nop_119850(void);
u32 BattleShowingTask_GetUnkField28(BattleShowingTaskWork *work);
void BattleShowingTask_Unk_119834(void);
void BattleShowingTask_Unk_1196e0(BattleShowingTask *task);
u32 BattleShowingTask_Unk_11c230(BattleShowingTaskWork *work);

void Unk02cad4_Unk_02cbdc(u32 arg);
/* Teardown hook: clear the live handle, then forward 1 (0x021196c0). */
void BattleShowingTask_Unk_1196c0(void)
{
    data_02176e70 = 0;
    Unk02cad4_Unk_02cbdc(1);
}

/*
 * Task hooks for the battle-showing screen. These addresses are referenced as
 * plain callback words in .data: the descriptor at 0x0213d7f4 is
 * {0x02119834, 0x0211984c, 0x02119850, 1, 1, ...} and func_02119658's literal
 * pool at 0x021196b4 holds 0x0211982c and 0x02119830, which it passes to
 * func_020611dc (the call that returns the new task object). All four Nop
 * hooks are empty (bx lr), so calling them has no effect.
 */

/* 0x0211982c: empty task callback (bx lr), passed to func_020611dc by func_02119658. */
void BattleShowingTask_Nop_11982c(void) { }

/* 0x02119830: empty task callback (bx lr), passed to func_020611dc by func_02119658. */
void BattleShowingTask_Nop_119830(void) { }

/* 0x0211984c: empty task callback (bx lr), slot 1 of the descriptor at 0x0213d7f4. */
void BattleShowingTask_Nop_11984c(void) { }

/* 0x02119850: empty task callback (bx lr), slot 2 of the descriptor at 0x0213d7f4. */
void BattleShowingTask_Nop_119850(void) { }

/*
 * Returns the dword at +0x28 of a battle-showing work object. The two callers
 * at 0x0211adbc and 0x0211ae70 compare the result against 1 and 3, so +0x28 is
 * a state value (the same slot is ExpGauge.state below).
 */
u32 BattleShowingTask_GetUnkField28(BattleShowingTaskWork *work) { return work->unk_0028; }

/*
 * Descriptor entry 0 at 0x0213d7f4: creates the battle-showing task with
 * func_02119658 and publishes its handle in data_02176e70. That global is
 * cleared again by BattleShowingTask_Unk_1196c0 when the task is torn down.
 */
void BattleShowingTask_Unk_119834(void)
{
  u32 value;
  value = func_02119658();
  data_02176e70 = value;
}

/*
 * Initializes a fresh task object: clears words +0x00 and +0x04 and forwards 1
 * to Unk0a0ce4_Unk_0a0d30. Sole caller is func_02119658 (at 0x021196a0),
 * which passes the object returned by func_020611dc and then returns it.
 */
void BattleShowingTask_Unk_1196e0(BattleShowingTask *task)
{
  task->unk_0000 = 0;
  task->unk_0004 = 0;
  Unk0a0ce4_Unk_0a0d30(1);
}

/*
 * Bounds-checked record lookup: returns work->unk_0004[work->unk_000c] while
 * the index is below the count work->unk_0008, and 0 otherwise. The callers
 * BattleShowingTask_Unk_11c5d0/11c610/11c670 use the result as a record and
 * read u16 fields at +0x08, +0x1c and +0x1e from it.
 */
u32 BattleShowingTask_Unk_11c230(BattleShowingTaskWork *work)
{
  u32 value;
  if (work->unk_000c < work->unk_0008) {
    value = work->unk_0004[work->unk_000c];
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


/* Resource lookup and dispatch signatures observed at 0x0211c4c4. */
u32 func_020445f4(u32 id);
u32 func_0204fed8(u32 resource, u32 value);
/* Forward value with resource 0x29 and return the dispatch result; original calls
 * at 0x0211c4d0/0x0211c4d8. The second argument is unused here but the caller
 * at 0x0211c4e0 supplies 2. */
u32 BattleShowingTask_Unk_11c4c4(u32 value, u32 unused)
{
    u32 resource = func_020445f4(0x29);
    return func_0204fed8(resource, value);
}

/* The caller at 0x0211b684 supplies these three resource IDs in order. */
void Unk044394_Unk_044534(u32 id);
void func_0211a380(void);
/* Run the local helper, then process IDs 0x17, 0x21 and 0x29 (0x0211b684). */
void BattleShowingTask_Unk_11b684(void)
{
    func_0211a380();
    Unk044394_Unk_044534(0x17);
    Unk044394_Unk_044534(0x21);
    Unk044394_Unk_044534(0x29);
}

/* Separate live-work handle cleared by the cleanup at 0x0211ce80. */
extern u32 data_02176e74;
/* Cleanup accepts the record-table pointer and the embedded object, respectively. */
void func_02053000(u32 *records);
void Unk0a163c_Unk_0a1ae0(void *object);
/* Release +0x04, clean up the embedded +0x10 object, and clear the global handle.
 * Offsets and call order are from 0x0211ce80; work must be a live work object. */
void BattleShowingTask_Unk_11ce80(BattleShowingTaskWork *work)
{
    func_02053000(work->unk_0004);
    work->unk_0004 = 0;
    Unk0a163c_Unk_0a1ae0(work->pad_0010);
    data_02176e74 = 0;
}

/* The original cleanup at 0x0211a01c passes each nonzero animation handle. */
void func_0205c3dc(u32 anim);
/* Release nonzero handles at +0x18/+0x1c and clear each after its call;
 * these are gaugeAnim/levelUpAnim in the EXP update at 0x02119a60. */
void BattleShowingTask_Unk_11a01c(ExpGauge *g)
{
    if (g->gaugeAnim != 0) {
        func_0205c3dc(g->gaugeAnim);
        g->gaugeAnim = 0;
    }
    if (g->levelUpAnim == 0) {
        return;
    }
    func_0205c3dc(g->levelUpAnim);
    g->levelUpAnim = 0;
}



/* Six-byte entries at +0x268; only the first matching ID gets flag bit 3.
 * Entry count and flag offset are observed in the ARM loop at 0x0211a8dc. */
typedef struct BattleShowingEntry {
    u16 id;
    u16 unk02;
    u8 flags;
    u8 unk05;
} BattleShowingEntry;
/* Only this entry window is known; the preceding work fields are opaque. */
typedef struct BattleShowingEntryWork {
    u8 pad000[0x268];
    BattleShowingEntry entries[15];
} BattleShowingEntryWork;

/* Set bit 3 on the first of 15 entries with the supplied ID (0x0211a8dc). */
void BattleShowingTask_Unk_11a8dc(BattleShowingEntryWork *work, u32 id)
{
    int i = 0;
    BattleShowingEntryWork *cursor = work;
    do {
        if (id == cursor->entries[0].id) {
            work->entries[i].flags |= 8;
            return;
        }
        i++;
        cursor = (BattleShowingEntryWork *)((u8 *)cursor + sizeof(BattleShowingEntry));
    } while (i < 15);
}

/* Record fields read by the resource dispatchers at 0x0211c4e0..0x0211c670. */
typedef struct BattleShowingRecord {
    u8 pad00[8];
    u16 id;
    u8 pad0a[0x12];
    u16 unk1c;
    u16 unk1e;
} BattleShowingRecord;
u32 func_020493e0(u32 id);
void func_0204faf0(u32 slot, u32 value);
void func_02065628(u32 value);
void func_0206569c(u32 value);
void func_02065bc0(void);
void func_02065cfc(u32 mode, s32 value);
void func_02065864(u32 value, u32 mode);
void func_0204fcb0(u32 slot, u32 value);
u32 Unk0caea8_Unk_0cb044(u32 value);

/* Publish current record ID in slot 6, then dispatch resource 10; ARM 0x0211c670. */
void BattleShowingTask_Unk_11c670(BattleShowingTaskWork *work)
{
    BattleShowingRecord *record = (BattleShowingRecord *)BattleShowingTask_Unk_11c230(work);
    func_0204faf0(6, record->id);
    func_02065bc0();
    func_02065628(1);
    func_0206569c(func_020493e0(10));
    func_02065cfc(1, 0);
}

/* Publish current record ID, then pass resource 5 to the mode-1 helper; ARM 0x0211c5d0. */
void BattleShowingTask_Unk_11c5d0(BattleShowingTaskWork *work)
{
    BattleShowingRecord *record = (BattleShowingRecord *)BattleShowingTask_Unk_11c230(work);
    func_0204faf0(6, record->id);
    func_02065bc0();
    func_02065628(1);
    func_02065864(func_020493e0(5), 1);
    func_02065cfc(1, 0);
}

/* Publish ID/+0x1c and converted +0x1e before dispatching resource 6;
 * field offsets and call order are from ARM 0x0211c610. Requires a current record. */
void BattleShowingTask_Unk_11c610(BattleShowingTaskWork *work)
{
    BattleShowingRecord *record = (BattleShowingRecord *)BattleShowingTask_Unk_11c230(work);
    func_0204faf0(6, record->id);
    func_0204faf0(10, record->unk1c);
    func_0204fcb0(1, Unk0caea8_Unk_0cb044(record->unk1e));
    func_02065bc0();
    func_02065628(1);
    func_0206569c(func_020493e0(6));
    func_02065cfc(1, 0);
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

/* Select sequence 17, reset its frame, and start the gauge animation.
 * Called after the level-up pause in ExpGauge_Update (0x02119a60). */
void ExpGauge_PlayGaugeNormal(ExpGauge *g)
{
    func_0205c408(g->gaugeAnim, 17);
    func_0205c41c(g->gaugeAnim, 0);
    func_0205c6e0(g->gaugeAnim);
}

/* Select sequence 16, reset its frame, and start the gauge animation.
 * Called on level-up in ExpGauge_Update (0x02119a60). */
void ExpGauge_PlayGaugeLevelUp(ExpGauge *g)
{
    func_0205c408(g->gaugeAnim, 16);
    func_0205c41c(g->gaugeAnim, 0);
    func_0205c6e0(g->gaugeAnim);
}

/* EXP threshold consumed by the count-up caller at 0x02119a60: use the
 * alternate table for negative info +0, otherwise the curve ID at info +8.
 * DONE or exhausted level-ups includes the level-up count in the third argument. */
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

/* Recompute remaining EXP as threshold - (base EXP + shown EXP - total).
 * The count-up/level-up paths at 0x02119a60 call this after changing the gauge. */
void ExpGauge_UpdateToNextLevel(ExpGauge *g)
{
    g->toNextLevel = ExpGauge_GetExpForNextLevel(g) - ((g->info->baseExp + g->shown) - g->total);
}

/* Set the count-up increment to one sixtieth of the next threshold, at least
 * one; zero gained EXP instead sets zero. Called by the level-up path 0x02119a60. */
void func_02119a10(ExpGauge *g)
{
    if (g->info->expGained == 0) {
        g->step = 0;
        return;
    }
    g->step = ExpGauge_GetExpForNextLevel(g) / 60;
    if ((s32)g->step <= 0) {
        g->step = 1;
    }
}

void func_021196fc(BattleShowingTask *task);
BattleShowingTask *func_020611dc(void (*update)(BattleShowingTask *),
    void (*hook1)(void), void (*hook2)(void), void (*cleanup)(void),
    u32 size, u32 arg5, u32 arg6, u32 arg7);
/* Allocate an eight-byte task with the original four callbacks, initialize it,
 * and return its nullable handle. Callback literals are at 0x021196b0..bc. */
u32 func_02119658(void)
{
    BattleShowingTask *task = func_020611dc(func_021196fc,
        BattleShowingTask_Nop_11982c, BattleShowingTask_Nop_119830,
        BattleShowingTask_Unk_1196c0, 8, 0, 0, 1);
    if (task == 0) {
        return 0;
    }
    BattleShowingTask_Unk_1196e0(task);
    return (u32)task;
}

/* Resource lookup returns a byte at +2 and a packed word at +0x24;
 * only the fields consumed by ARM 0x0211c4e0 are represented. */
typedef struct BattleShowingResource {
    u8 pad00[2];
    u8 unk02;
    u8 pad03[0x21];
    u32 unk24;
} BattleShowingResource;
BattleShowingResource *func_020a1428(u32 id);
/* Publish record/resource fields, dispatch bits 21..27 through resource 0x29,
 * and forward the signed record ID. Evidence: ARM loads/calls at 0x0211c4e0. */
void func_0211c4e0(BattleShowingTaskWork *work)
{
    BattleShowingRecord *record = (BattleShowingRecord *)BattleShowingTask_Unk_11c230(work);
    BattleShowingResource *resource = func_020a1428(record->id);
    u32 value;
    func_0204faf0(6, record->id);
    func_0204faf0(7, resource->unk02);
    value = BattleShowingTask_Unk_11c4c4((resource->unk24 << 4) >> 25, 2);
    func_02065628(1);
    func_0206569c(value);
    func_02065cfc(1, (s16)record->id);
}
