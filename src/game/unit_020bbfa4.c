/* src/game/unit_020bbfa4.c: script command handlers for the enemy talk tone selection, plus the
 * helpers that load and release the Tone/TalkTone files. Hand-matched ARM. */
#include "types.h"

/* Script argument reader (see unit_0203c274.c for the same accessor pattern). */
u32 func_0203ac00(u32 index);
/* State-slot helpers used by the command handlers: slot 12..15 live at state + 0x14 + slot * 4. */
void Unk118b04_Unk_118e50(int slot, int value);
u32 Unk118b04_Unk_118e74(int slot);
/* Publishes the command result and clears the wait byte. The stored word is interpreted as signed. */
int Unk03aae8_Unk_03acf4(u32 value);
/* Returns the work object that holds the owner id at +0x40 and talk-tone selector at +0x58. */
int Unk044904_Unk_045048(void);

void Unk0a0ce4_Unk_0a0d68(int value);
/* Forward the input plus six to Unk0a0ce4_Unk_0a0d68; callers at
 * 0x02047d5c and 0x02047d68 supply the input. Its domain is not yet known. */
void Unk0bbfa4_Unk_0bc0a4(int arg0)
{
    Unk0a0ce4_Unk_0a0d68(arg0 + 6);
}

/* Add script argument 0 to state slot 12 and return command status 1.
 * Unk118b04_Unk_118e50 stores the sum at state + 0x14 + slot * 4. */
u32 Unk0bbfa4_Unk_0bbfa4(void)
{
    u32 value = func_0203ac00(0);
    Unk118b04_Unk_118e50(0xc, value);
    return 1;
}

/* Add script argument 0 to state slot 13 and return command status 1. */
u32 Unk0bbfa4_Unk_0bbfc4(void)
{
    u32 value = func_0203ac00(0);
    Unk118b04_Unk_118e50(0xd, value);
    return 1;
}

/* Add script argument 0 to state slot 14 and return command status 1. */
u32 Unk0bbfa4_Unk_0bbfe4(void)
{
    u32 value = func_0203ac00(0);
    Unk118b04_Unk_118e50(0xe, value);
    return 1;
}

/* Add script argument 0 to state slot 15 and return command status 1. */
u32 Unk0bbfa4_Unk_0bc004(void)
{
    u32 value = func_0203ac00(0);
    Unk118b04_Unk_118e50(0xf, value);
    return 1;
}

/* Publish state slot 12 as the command result, clamping signed negative values to zero;
 * return command status 1. */
u32 Unk0bbfa4_Unk_0bc024(void)
{
    int value = Unk118b04_Unk_118e74(0xc);
    if (value < 0) {
        value = 0;
    }
    Unk03aae8_Unk_03acf4(value);
    return 1;
}

/* Publish state slot 13 as the command result, clamping signed negative values to zero;
 * return command status 1. */
u32 Unk0bbfa4_Unk_0bc044(void)
{
    int value = Unk118b04_Unk_118e74(0xd);
    if (value < 0) {
        value = 0;
    }
    Unk03aae8_Unk_03acf4(value);
    return 1;
}

/* Publish state slot 14 as the command result, clamping signed negative values to zero;
 * return command status 1. */
u32 Unk0bbfa4_Unk_0bc064(void)
{
    int value = Unk118b04_Unk_118e74(0xe);
    if (value < 0) {
        value = 0;
    }
    Unk03aae8_Unk_03acf4(value);
    return 1;
}

/* Publish state slot 15 as the command result, clamping signed negative values to zero;
 * return command status 1. */
u32 Unk0bbfa4_Unk_0bc084(void)
{
    int value = Unk118b04_Unk_118e74(0xf);
    if (value < 0) {
        value = 0;
    }
    Unk03aae8_Unk_03acf4(value);
    return 1;
}

/* Enemy talk tone state returned by Unk044904_Unk_045048, including the owner id at +0x40.
 * The index at +0x58 is 0..14
 * while a set is loaded and 15 when nothing is loaded; the two file pointers are then null. */
typedef struct Unk0bbfa4ToneState {
    u8 pad_0000[0x40];
    u32 unk_0040;               /* +0x40: owner id passed to func_02044ec4 */
    u8 pad_0044[0x14];
    s32 index;                  /* +0x58: loaded tone set, or 15 for none */
    void *talkTone;             /* +0x5C: TalkTone%s.mbb data from func_02051610 */
    void *tone;                 /* +0x60: Tone%s.tbb data from func_02051610 */
} Unk0bbfa4ToneState;

/* Owner read at +0x40 of the work object in Unk0bbfa4_Unk_0bc17c; only the halfword at +0x1D8
 * is used here, and it feeds func_020a1428 as an id. */
typedef struct Unk0bbfa4Obj {
    u8 pad_0000[0x1d8];
    u16 unk_01d8;
} Unk0bbfa4Obj;

/* Object returned by func_020a1428; only the word at +0x24 is read. */
typedef struct Unk0bbfa4Entry {
    u8 pad_0000[0x24];
    u32 unk_0024;
} Unk0bbfa4Entry;

int func_02053000(void *data);
int func_02044ec4(u32 id);
Unk0bbfa4Entry *func_020a1428(u32 id);

/* Release both files of the current talk tone set and mark the state as having none loaded (15).
 * Also called before loading a replacement set, so the old pair is always freed first. */
void Unk0bbfa4_Unk_0bc144(void)
{
    Unk0bbfa4ToneState *state = (Unk0bbfa4ToneState *)Unk044904_Unk_045048();
    state->index = 0xf;
    func_02053000(state->talkTone);
    state->talkTone = 0;
    func_02053000(state->tone);
    state->tone = 0;
}

/* Returns bits 21..27 (7 bits) of the word at +0x24 of the entry obtained from the work object's
 * +0x40 owner and its +0x1D8 id. Callers use it as a table selector; its exact meaning is not
 * established. */
u32 Unk0bbfa4_Unk_0bc17c(void)
{
    Unk0bbfa4ToneState *state = (Unk0bbfa4ToneState *)Unk044904_Unk_045048();
    Unk0bbfa4Obj *obj = (Unk0bbfa4Obj *)func_02044ec4(state->unk_0040);
    Unk0bbfa4Entry *entry = func_020a1428(obj->unk_01d8);
    u32 v = entry->unk_0024;
    return (v << 4) >> 25;
}

/* 15 enemy talk tone-set names indexed by the tone argument. data_02150310 and data_02150330 are
 * the "Data/Enemy/Talk/TalkTone%s.mbb" and "Data/Enemy/Talk/Tone%s.tbb" format strings. */
extern char *data_021502d4[];
extern char data_02150310[];
extern char data_02150330[];

void func_02013c3c(char *buf, const char *fmt, ...);
void *func_02051610(const char *path);

/* Selects enemy talk tone set `index` (0..14). Switching away from the current set first releases
 * the two files held by Unk0bbfa4_Unk_0bc144, then formats and loads the TalkTone/Tone pair named
 * by data_021502d4[index]. An out-of-range index only releases the current set and records 15,
 * which is the "nothing loaded" state. Selecting the already active set is a no-op. */
void func_020bc0b4(s32 index)
{
    Unk0bbfa4ToneState *state = (Unk0bbfa4ToneState *)Unk044904_Unk_045048();
    char path[64];

    if (state->index != 15 && state->index == index) {
        return;
    }
    Unk0bbfa4_Unk_0bc144();
    if (index < 15) {
        func_02013c3c(path, data_02150310, data_021502d4[index]);
        state->talkTone = func_02051610(path);
        func_02013c3c(path, data_02150330, data_021502d4[index]);
        state->tone = func_02051610(path);
    }
    state->index = index;
}
