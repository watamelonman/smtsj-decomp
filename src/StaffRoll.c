/* src/StaffRoll.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* A 16-byte record view, inferred from the search stride at 0x02118270. */
typedef struct StaffRollSlot {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
} StaffRollSlot;

/* Borrowed work layout; gaps retain offsets observed in the original ARM code. */
typedef struct StaffRollWork {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    s32 unk_0014;
    s32 unk_0018;
    s32 imageIndex;
    u32 loadState;
    u8 resource[0x78];
    struct StaffRollImage *images[4];
    u32 unk_00ac;
    u32 unk_00b0;
    u32 unk_00b4;
    u32 unk_00b8;
    s32 unk_00bc;
    s32 unk_00c0;
    s32 unk_00c4;
    u32 unk_00c8;
    u32 unk_00cc;
    u32 unk_00d0;
    u32 unk_00d4;
    u32 unk_00d8;
    s32 scrollY;                /* +0xDC  starts at 0x1F0, grows per text line */
    s32 unk_00e0;
    u32 firstTextCmd;           /* +0xE4 */
    u32 textInCmd;
    s32 textLine;
    s32 textY;
    u32 textDone;
    struct StaffRollSlot slots[32];
    u32 unk_02f8;
    struct StaffRollCmd *cmds;  /* +0x2FC */
    u32 cmdCount;               /* +0x300 */
    u32 unk_0304;
} StaffRollWork;

/* The original at 0x02117cf4 immediately returns; no state is accessed. */
void StaffRoll_Nop_117cf4(void) { }


/* The original at 0x02117cf8 immediately returns; no state is accessed. */
void StaffRoll_Nop_117cf8(void) { }


/* Returns a borrowed halfword stream for work +0x304. The viewport caller
 * additionally supplies its line index; marker-only callers pass the handle. */
extern u16 *func_0204fed8(u32 handle, ...);
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

/* Parses 20-byte script entries and accumulates line spacing from 0x1F0.
 * Types 1..3 clamp timing parameters; type 4 marks text (0x0211882C).
 * The borrowed command list must contain cmdCount readable entries. */
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
void func_020572d8(void);
void func_02057524(int value);
void func_0205789c(void);
void func_02057df8(void);
void func_02057e18(int value);
void func_02057e30(int value);
void func_02058d04(struct StaffRollImage *image, int a, u32 b, u32 c,
                    u32 scale, int d, int e, int f);
void func_02118518(StaffRollWork *work);
void func_02118584(StaffRollWork *work, int screen);
/* Draws image pair 0/1 in state 2, then the overlay and first-screen slots;
 * original calls at 0x02118620 borrow all resources. */
void StaffRoll_Unk_118620(StaffRollWork *arg0)
{
  func_02057524(0);
  func_0205789c();
  func_02057df8();
  func_02057e30(0);
  func_02057e18(0x1f);
  if (((StaffRollWork *)arg0)->unk_00ac == 2) {
    func_02058d04(arg0->images[0],0,0,0,0x3f800000,0,0,0);

    func_02058d04(arg0->images[1],0,*(u32 *)(data_0213cc08 + 0xc),
                  *(u32 *)(data_0213cc08 + 0x10),0x3f800000,0,0,0);
  }
  func_02118518((StaffRollWork *)arg0);
  func_02118584(arg0,0);
  func_020572d8();
}

extern u8 data_0213cc1c[];
extern u8 data_0213cc30[];
/* Draws image pair 2/3 in state 2, then the overlay and second-screen slots;
 * original calls at 0x021186CC borrow all resources. */
void StaffRoll_Unk_1186cc(StaffRollWork *arg0)
{
  func_02057524(0);
  func_0205789c();
  func_02057df8();
  func_02057e30(0);
  func_02057e18(0x1f);
  if (((StaffRollWork *)arg0)->unk_00ac == 2) {
    func_02058d04(arg0->images[2],0,*(u32 *)(data_0213cc1c + 0xc),
                  *(u32 *)(data_0213cc1c + 0x10),0x3f800000,0,0,0);

    func_02058d04(arg0->images[3],0,*(u32 *)(data_0213cc30 + 0xc),
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

/* Dispatches +0x10 states, starting and stopping handler 26 at unsigned frame
 * thresholds +0x14 and +0x14 + +0x18; state 2 reports completion. */
int func_02117dd8(StaffRollWork *work)
{
    extern void func_0205e484(int id, int value);
    extern void func_0205e590(int value);
    int done = 0;
    switch (work->unk_0010) {
    case 0:
        if ((u32)work->unk_0014 <= work->unk_0008) {
            func_0205e484(26, 0);
            work->unk_0010 = 1;
        }
        break;
    case 1:
        if ((u32)(work->unk_0014 + work->unk_0018) <= work->unk_0008) {
            func_0205e590(0);
            work->unk_0010 = 2;
        }
        break;
    case 2:
        done = 1;
        break;
    }
    return done;
}

/* Advances +0xB4, derives +0xCC from the unsigned fade intervals, and moves
 * to state 3 or 4 after +0xC8 frames. Divisor +0xC0 must be nonzero. */
void func_021180e4(StaffRollWork *work)
{
    work->unk_00b4++;
    if (work->unk_00b4 <= (u32)work->unk_00c0)
        work->unk_00cc = ((u32)work->unk_00c0 - work->unk_00b4) * 31 / (u32)work->unk_00c0;
    if (work->unk_00c8 - (u32)work->unk_00c0 <= work->unk_00b4)
        work->unk_00cc = (work->unk_00b4 - (work->unk_00c8 - (u32)work->unk_00c0)) * 31 / (u32)work->unk_00c0;
    if (work->unk_00c8 <= work->unk_00b4) {
        work->unk_00b0++;
        work->unk_00ac = work->unk_00b0 < 10 ? 3 : 4;
        work->unk_00b4 = 0;
    }
}

/* Builds a Data/Tex/ path with the indexed 24-byte table record and .gfnt
 * suffix (original literals), and loads it into borrowed resource storage. */
void func_02117e5c(StaffRollWork *work, int index)
{
    typedef struct StaffRollPath { u32 unk_0000; const char *name; u8 pad[16]; } StaffRollPath;
    extern StaffRollPath *Unk02e000_GetAddr_data_02140ac8(void);
    extern void func_0201524c(char *dest, const char *src);
    extern int func_020513d4(const char *path);
    extern void func_020516dc(void *resource, const char *path, int a, int b);
    char path[64] = "Data/Tex/";
    func_0201524c(path, Unk02e000_GetAddr_data_02140ac8()[index].name);
    func_0201524c(path, ".gfnt");
    if (func_020513d4(path) == 0) return;
    func_020516dc(work->resource, path, 0, 0);
}

/* Draws active slots intersecting the 192-line viewport; screen selects a
 * 288-line offset. Slot positions and opacity follow the original loads. */
void func_02118584(StaffRollWork *work, int screen)
{
    extern void func_02057ddc(int value);
    extern void func_02060b60(u32 flags, u32 handle, int x, int y, int a, int b);
    int offset = screen == 0 ? 0 : 288;
    int i = 0;
    int y;
    StaffRollSlot *slot = work->slots;
    for (; i < 32; i++, slot++) {
        if (slot->unk_0004 == 1) {
            y = (s32)slot->unk_0008 - work->unk_00e0 - offset;
            if (y + 16 >= 0 && y < 192) {
                func_02057ddc(slot->unk_000c);
                func_02060b60(0x01000001, slot->unk_0000, 128, y, 0, 2);
            }
        }
    }
    func_02057df8();
}

/* Releases the 32 slot handles and counted resources, invokes the original
 * teardown calls, and clears the global owner pointer at 0x02176E6C. */
void func_02118784(StaffRollWork *work)
{
    extern void func_020629c4(u32 handle);
    extern void func_0205bb68(void);
    extern void Unk044394_Unk_044534(int id);
    extern void Unk065e88_Unk_0663bc(int a, int b);
    extern void func_02052634(int a, int b, int c);
    extern void func_0205e590(int value);
    extern void Unk02cad4_Unk_02cbdc(u32 handle);
    extern StaffRollWork *data_02176e6c;
    int i = 0;
    int j;
    for (; i < 32; i++) {
        func_020629c4(work->slots[i].unk_0000);
        work->slots[i].unk_0000 = 0;
    }
    for (j = 0; j < (s32)work->unk_000c; j++) func_0205bb68();
    work->unk_000c = 0;
    Unk044394_Unk_044534(43);
    Unk044394_Unk_044534(44);
    Unk065e88_Unk_0663bc(3, 39);
    func_02052634(1, 3, 31);
    func_0205e590(0);
    Unk02cad4_Unk_02cbdc(work->unk_0004);
    data_02176e6c = 0;
}

/* Four words copied together by 0x02117EF4; their interpretation is unknown. */
typedef struct StaffRollImageWords { u32 word[4]; } StaffRollImageWords;
/* Borrowed image prefix; halfwords +0x28/+0x2A are output parameters. */
typedef struct StaffRollImage {
    u8 pad_0000[12];
    u32 unk_000c;
    u32 unk_0010;
    u32 unk_0014;
    StaffRollImageWords words;
    u16 unk_0028;
    u16 unk_002a;
    u8 pad_002c[0x2d];
    u8 ready;
} StaffRollImage;
/* Borrowed resource prefix exposes only the four words copied to an image. */
typedef struct StaffRollResource {
    u8 pad_0000[12];
    StaffRollImageWords words;
} StaffRollResource;

/* Copies the resource metadata into an indexed image and resolves its two
 * dimensions through the original helper calls. Index must be in 0..3. */
void func_02117ef4(StaffRollWork *work, int index)
{
    extern StaffRollResource *func_020519e8(void *resource);
    extern void func_0205aa78(StaffRollImageWords *words, int *a, int *b, u16 *c, u16 *d);
    extern void func_0205b444(StaffRollImage *image, StaffRollResource *resource);
    extern u32 func_0205accc(StaffRollResource *resource);
    extern u32 func_0205acd4(StaffRollResource *resource);
    StaffRollResource *resource = func_020519e8(work->resource);
    int a = 0;
    int b = 0;
    work->images[index]->words = resource->words;
    func_0205aa78(&work->images[index]->words, &a, &b,
                 &work->images[index]->unk_0028, &work->images[index]->unk_002a);
    func_0205b444(work->images[index], resource);
    work->images[index]->unk_000c = func_0205accc(resource);
    work->images[index]->unk_0010 = func_0205acd4(resource);
}

/* Advances the text viewport from unsigned frame progress, retires old slots,
 * and queues one line when it enters the 480-line lookahead (0x021182F0).
 * Command and text streams must contain the indexed entries. */
void func_021182f0(StaffRollWork *work)
{
    StaffRollSlot *slot;
    u16 *text;
    int value;
    work->unk_00e0 = (work->unk_0008 - work->unk_00d4) * work->scrollY / work->unk_00d8;
    StaffRoll_Unk_1182a4(work);
    if (work->textDone != 0) return;
    if (work->textY > work->unk_00e0 + 480) return;
    slot = func_02118270(work);
    if (slot == 0) {
        func_02061424(work);
        return;
    }
    text = func_0204fed8(work->unk_0304, work->textLine);
    value = StaffRoll_Unk_117d38(text);
    func_02118208((StaffRollWork *)slot, text, work->textY, value);
    work->textInCmd++;
    if ((u32)work->cmds[work->firstTextCmd].arg[0] <= work->textInCmd) {
        do {
            work->firstTextCmd++;
            if (work->cmdCount <= work->firstTextCmd) {
                work->textDone = 1;
                break;
            }
        } while (work->cmds[work->firstTextCmd].type != 4);
        work->textInCmd = 0;
    }
    if (work->textDone != 0) return;
    work->textY += func_02117d5c(work, work->firstTextCmd, work->textLine);
    work->textLine++;
}

/* Borrowed 20-byte image allocation record, observed at data_0213cbf4. */
typedef struct StaffRollImageConfig {
    int resourceIndex;
    int arg1;
    int arg2;
    int x;
    int y;
} StaffRollImageConfig;
extern StaffRollResource *func_020519e8(void *resource);
extern StaffRollImageConfig data_0213cbf4[];
void Unk02e000_Unk_02e0cc(void);

/* Creates the single global staff-roll owner, loads script/text resources and
 * allocates four images and 32 text slots (calls and counts at 0x02118974).
 * Repeated calls preserve the existing owner; allocation failure returns. */
void func_02118974(void)
{
    extern StaffRollWork *data_02176e6c;
    extern StaffRollWork *func_020611dc(void (*update)(StaffRollWork *),
        void (*draw0)(StaffRollWork *), void (*draw1)(StaffRollWork *),
        void (*destroy)(StaffRollWork *), u32 size, int a, int b, int c);
    extern void func_020662d4(int a, int b);
    extern void Unk044394_Unk_044428(int id);
    extern u32 func_020445d0(int id, int index);
    extern StaffRollCmd *func_0204fde0(u32 handle);
    extern u32 func_0204fe18(u32 handle);
    extern u32 func_020445f4(int id, int index);
    extern StaffRollImage *func_0205ba98(int a, int b, void *c, int d);
    extern u32 func_020629ac(int a, int b, int c, int d);
    extern void func_02052634(int a, int b, int c);
    extern u8 data_02151b34[];
    int i;
    StaffRollImageConfig *config;
    StaffRollWork *work;
    if (data_02176e6c != 0) return;
    work = func_020611dc(StaffRoll_Update, StaffRoll_Unk_118620,
        StaffRoll_Unk_1186cc, func_02118784, sizeof(StaffRollWork), 0, 0, 1);
    data_02176e6c = work;
    if (work == 0) return;
    Unk02e000_Unk_02e0cc();
    func_020662d4(3, 39);
    Unk044394_Unk_044428(43);
    work->unk_02f8 = func_020445d0(43, 0);
    work->cmds = func_0204fde0(work->unk_02f8);
    work->cmdCount = func_0204fe18(work->unk_02f8);
    Unk044394_Unk_044428(44);
    work->unk_0304 = func_020445f4(44, 0);
    config = data_0213cbf4;
    for (i = 0; (u32)i < 4; i++, config++) {
        work->unk_000c++;
        work->images[i] = func_0205ba98(config->arg1, config->arg2, data_02151b34, 331);
    }
    for (i = 0; i < 32; i++) work->slots[i].unk_0000 = func_020629ac(5, 1, 3, 3);
    work->unk_00cc = 31;
    work->textLine = 1;
    work->textY = 480;
    func_0211882c(work);
    func_02052634(2, 3, 0);
    work->unk_0004 = 14;
}

/* Advances four asynchronous image-load states, using the original indexed
 * tables at 0x0213CC44/0x0213CBF4. Work and images are borrowed and writable;
 * table indices must be valid. Readiness is the image byte at +0x59. */
void func_02117f94(StaffRollWork *work)
{
    extern int data_02151b28;
    extern int data_0213cc44[][10];
    extern int func_02051844(void *resource, int wait);
    extern void func_02053000(StaffRollResource *resource);
    int *row = data_0213cc44[data_02151b28];
    int image = work->imageIndex;
    /* See DEC-015: repeated addition preserves the original lookup scheduling. */
    int index = row[work->unk_00b0] + row[work->unk_00b0] + data_0213cbf4[image].resourceIndex;
    Unk02e000_Unk_02e0cc();
    work->unk_00b4++;
    switch (work->loadState) {
    case 0:
        func_02117e5c(work, index);
        work->loadState++;
        break;
    case 1:
        if (func_02051844(work->resource, -1) != 0) return;
        work->loadState++;
        break;
    case 2:
        func_02117ef4(work, work->imageIndex);
        work->loadState++;
        break;
    case 3:
        if (work->images[work->imageIndex]->ready == 0) return;
        func_02053000(func_020519e8(work->resource));
        work->loadState = 0;
        work->imageIndex++;
        if (work->imageIndex < 4) return;
        work->unk_00ac = 2;
        work->unk_00c8 = ((u32)work->unk_00bc - work->unk_00c4 * 9) / 10 - work->unk_00b4;
        work->unk_00b4 = 0;
        work->imageIndex = 0;
        break;
    }
}
