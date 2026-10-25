/* src/StaffRoll.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Borrowed work layout; gaps retain offsets observed in the original ARM code. */
typedef struct StaffRollWork {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u8  pad_0010[0x4];
    s32 unk_0014;
    s32 unk_0018;
    u8  pad_001c[0x90];
    u32 unk_00ac;
    u8  pad_00b0[0x4];
    u32 unk_00b4;
    u32 unk_00b8;
    s32 unk_00bc;
    s32 unk_00c0;
    s32 unk_00c4;
    u8  pad_00c8[0x4];
    u32 unk_00cc;
    u32 unk_00d0;
    u32 unk_00d4;
    u32 unk_00d8;
    s32 scrollY;                /* +0xDC  starts at 0x1F0, grows per text line */
    s32 unk_00e0;
    u32 firstTextCmd;           /* +0xE4 */
    u8  pad_00e8[0x214];
    struct StaffRollCmd *cmds;  /* +0x2FC */
    u32 cmdCount;               /* +0x300 */
    u32 unk_0304;
} StaffRollWork;

/* A 16-byte record view, inferred from the search stride at 0x02118270. */
typedef struct StaffRollSlot {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
} StaffRollSlot;

/* The original at 0x02117cf4 immediately returns; no state is accessed. */
void StaffRoll_Nop_117cf4(void) { }


/* The original at 0x02117cf8 immediately returns; no state is accessed. */
void StaffRoll_Nop_117cf8(void) { }


/* Returns a borrowed halfword stream for the handle stored at work +0x304. */
extern u16 *func_0204fed8(u32 handle);
/* Reads one aligned halfword; only marker 0x8082 is returned (assembly evidence). */
u32 StaffRoll_Unk_117cfc(u16 *p)
{
    u32 v = 0;
    if (*p == 0x8082) {
        v = *p;
    }
    return v;
}

/* Resolves work +0x304 and tests its first halfword; a null stream returns zero. */
u32 StaffRoll_Unk_117d18(StaffRollWork *p, int line)
{
    u16 *q = func_0204fed8(p->unk_0304);
    if (q == 0) {
        return 0;
    }
    return StaffRoll_Unk_117cfc(q);
}

/* Maps marker 0x8082 to the original packed value; all other markers return -1. */
int StaffRoll_Unk_117d38(u16 *p)
{
    if (StaffRoll_Unk_117cfc(p) == 0x8082) {
        return 0x739cd6ff;
    }
    return -1;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_02117dd8(StaffRollWork *work);
u32 StaffRoll_Unk_1181a0(StaffRollWork *arg0);
int func_02118424(StaffRollWork *work);
void StaffRoll_Unk_118490(StaffRollWork *p);
void func_02061424(StaffRollWork *work);
/* Advances +0xB4; reaching unsigned limit +0xC4 selects state 1 and resets it.
 * The counter update in the original at 0x02118174 supports the existing Tick name. */
void StaffRoll_Tick(StaffRollWork *p)
{
    u32 n = p->unk_00b4 + 1;
    p->unk_00b4 = n;
    if (((u32)p->unk_00c4) > n) {
        return;
    }
    p->unk_00ac = 1;
    p->unk_00b4 = 0;
}

/* Clears words +4, +8 and +12 of the supplied writable record; +0 is preserved. */
void StaffRoll_Unk_11825c(StaffRollWork *arg0)
{
  ((StaffRollWork *)arg0)->unk_0004 = 0;
  ((StaffRollWork *)arg0)->unk_0008 = 0;
  ((StaffRollWork *)arg0)->unk_000c = 0;
  return;
}



/* Clears active slots whose signed position plus 16 precedes work +0xE0. */
void StaffRoll_Unk_1182a4(StaffRollWork *arg0)
{
    int i = 0;
    StaffRollSlot *slot = (StaffRollSlot *)((u8 *)arg0 + 0xf8);
    do {
        if (slot->unk_0004 == 1 && (s32)slot->unk_0008 + 16 < arg0->unk_00e0) {
            StaffRoll_Unk_11825c((StaffRollWork *)slot);
        }
        i++;
        slot++;
    } while (i < 32);
}

void func_02117f94(StaffRollWork *work);
void func_021180e4(StaffRollWork *work);

/* Dispatches states 0 through 4 at +0xAC; only state 4 reports completion. */
u32 StaffRoll_Unk_1181a0(StaffRollWork *arg0)
{
  u32 tmp1;
  tmp1 = 0;
  switch(arg0->unk_00ac) {
  case 0:
    if (arg0->unk_00b8 <= arg0->unk_0008) {
      arg0->unk_00ac = 3;
    }
    break;
  case 1:
    func_02117f94(arg0);
    break;
  case 2:
    func_021180e4(arg0);
    break;
  case 3:
    StaffRoll_Tick(arg0);
    break;
  case 4:
    tmp1 = 1;
  }
  return tmp1;
}

/* Staff-roll script entry (20 bytes). */
typedef struct StaffRollCmd {
    u32 type;
    s32 arg[4];
} StaffRollCmd;


int func_02117d5c(StaffRollWork *w, u32 cmd, int line);

/* Advances the frame counter and selects state 2 when all three handlers finish. */
void StaffRoll_Unk_118490(StaffRollWork *p)
{
    int a;
    int b;
    int c;
    p->unk_0008++;
    a = func_02117dd8(p);
    b = StaffRoll_Unk_1181a0(p);
    c = func_02118424(p);
    if (a != 0 && b != 0 && c != 0) {
        p->unk_0000 = 2;
    }
}

/* Dispatches the state at +0: initialize, advance, or call the teardown handler.
 * This per-frame state dispatch supports the existing Update symbol name. */
void StaffRoll_Update(StaffRollWork *p)
{
    switch (p->unk_0000) {
    case 0:
        p->unk_0000 = 1;
        return;
    case 1:
        StaffRoll_Unk_118490(p);
        return;
    case 2:
        func_02061424(p);
        return;
    }
}

/* Parses the staff-roll command list and lays out its text lines. */
void func_0211882c(StaffRollWork *w)
{
    int found = 0;
    int line;
    u32 i;
    StaffRollCmd *c;
    int j;

    w->scrollY = 0x1f0;
    line = 0;
    for (i = 0; i < w->cmdCount; i++) {
        c = &w->cmds[i];
        switch (c->type) {
        case 0:
            break;
        case 1:
            w->unk_0014 = c->arg[0] < 0 ? 0 : c->arg[0];
            w->unk_0018 = c->arg[1] < 1 ? 1 : c->arg[1];
            break;
        case 2:
            w->unk_00b8 = c->arg[0] < 0 ? 0 : c->arg[0];
            w->unk_00bc = c->arg[1] < 1 ? 1 : c->arg[1];
            w->unk_00c0 = c->arg[2] < 1 ? 1 : c->arg[2];
            w->unk_00c4 = c->arg[3] < 1 ? 1 : c->arg[3];
            break;
        case 3:
            w->unk_00d4 = c->arg[0] < 0 ? 0 : c->arg[0];
            w->unk_00d8 = c->arg[1] < 1 ? 1 : c->arg[1];
            break;
        case 4:
            if (!found) {
                w->firstTextCmd = i;
                found = 1;
            }
            for (j = 0; j < c->arg[0]; j++) {
                w->scrollY += func_02117d5c(w, i, line);
                line++;
            }
            break;
        }
    }
}

extern u8 data_0213cc08[];
int func_020572d8();
int func_02057524();
int func_0205789c();
int func_02057df8();
int func_02057e18();
int func_02057e30();
int func_02058d04();
void func_02118518(StaffRollWork *work);
int func_02118584();
/* decompiler-derived */
void StaffRoll_Unk_118620(int arg0)
{
  func_02057524(0);
  func_0205789c();
  func_02057df8();
  func_02057e30(0);
  func_02057e18(0x1f);
  if (((StaffRollWork *)arg0)->unk_00ac == 2) {
    func_02058d04(*(u32 *)(arg0 + 0x9c),0,0,0,0x3f800000,0,0,0);

    func_02058d04(*(u32 *)(arg0 + 0xa0),0,*(u32 *)(data_0213cc08 + 0xc),
                  *(u32 *)(data_0213cc08 + 0x10),0x3f800000,0,0,0);
  }
  func_02118518((StaffRollWork *)arg0);
  func_02118584(arg0,0);
  func_020572d8();
}

extern u8 data_0213cc1c[];
extern u8 data_0213cc30[];
/* decompiler-derived */
void StaffRoll_Unk_1186cc(int arg0)
{
  func_02057524(0);
  func_0205789c();
  func_02057df8();
  func_02057e30(0);
  func_02057e18(0x1f);
  if (((StaffRollWork *)arg0)->unk_00ac == 2) {
    func_02058d04(*(u32 *)(arg0 + 0xa4),0,*(u32 *)(data_0213cc1c + 0xc),
                  *(u32 *)(data_0213cc1c + 0x10),0x3f800000,0,0,0);

    func_02058d04(*(u32 *)(arg0 + 0xa8),0,*(u32 *)(data_0213cc30 + 0xc),
                  *(u32 *)(data_0213cc30 + 0x10),0x3f800000,0,0,0);
  }
  func_02118518((StaffRollWork *)arg0);
  func_02118584(arg0,1);
  func_020572d8();
}

/* Returns a borrowed pointer to the first record with +4 zero in the 32 records
 * at work +0xF8, or null if all are occupied (original load/stride evidence). */
StaffRollSlot *func_02118270(StaffRollWork *work)
{
    StaffRollSlot *result = 0;
    int i = 0;
    for (; i < 32; i++) {
        if (((StaffRollSlot *)((u8 *)work + 0xf8))[i].unk_0004 == 0) {
            result = &((StaffRollSlot *)((u8 *)work + 0xf8))[i];
            break;
        }
    }
    return result;
}

/* Returns the observed line spacing from command args 1..3 according to the
 * adjacent stream markers. Line zero has no preceding spacing. */
int func_02117d5c(StaffRollWork *w, u32 cmd, int line)
{
    StaffRollCmd *entry;
    u32 before;
    u32 after;
    int spacing;
    if (line == 0) return 0;
    entry = &w->cmds[cmd];
    before = StaffRoll_Unk_117d18(w, line);
    after = StaffRoll_Unk_117d18(w, line + 1);
    spacing = 0;
    if (before == 0x8082 && after == 0) spacing = entry->arg[2];
    else if (before == 0 && after == 0) spacing = entry->arg[3];
    else if (before == 0 && after == 0x8082) spacing = entry->arg[1];
    return spacing + 16;
}

/* Initializes a writable 16-byte slot, omitting a leading 0x8082 marker from
 * the borrowed text passed to the external text handler. */
void func_02118208(StaffRollWork *slot, u16 *text, int position, int value)
{
    extern void func_02061f10(u32 handle, int index, int x, int y, u16 *text);
    if (StaffRoll_Unk_117cfc(text) == 0x8082) text++;
    func_02061f10(slot->unk_0000, -1, 0, 0, text);
    slot->unk_0004 = 1;
    slot->unk_0008 = position;
    slot->unk_000c = value;
}

/* Advances +0xD0 at the unsigned frame thresholds +0xD4 and +0xD4 + +0xD8.
 * State 2 reports completion; the state-1 handler receives borrowed work. */
int func_02118424(StaffRollWork *work)
{
    extern void func_021182f0(StaffRollWork *work);
    int done = 0;
    switch (work->unk_00d0) {
    case 0:
        if (work->unk_00d4 <= work->unk_0008) work->unk_00d0 = 1;
        break;
    case 1:
        func_021182f0(work);
        if (work->unk_00d4 + work->unk_00d8 <= work->unk_0008) work->unk_00d0 = 2;
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* Issues the original 256 by 192 draw calls when +0xCC is nonzero, then
 * restores the observed drawing settings. No resource ownership is transferred. */
void func_02118518(StaffRollWork *work)
{
    extern void func_02057fd8(void);
    extern void func_02057ddc(int value);
    extern void func_02057b50(int x, int y, int width, int height, int value);
    if (work->unk_00cc == 0) return;
    func_02057fd8();
    func_02057e18(work->unk_00cc & 255);
    func_02057ddc(255);
    func_02057b50(0, 0, 256, 192, 1);
    func_02057e30(0);
    func_02057e18(31);
    func_02057df8();
}
