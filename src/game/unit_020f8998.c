/* src/game/unit_020f8998.c: matched functions from the delinked unit at 0x020f8998. */
#include "types.h"

/* Object passed as the first argument; only the fields touched by this unit are named.
   The state at +0x7481 and the counters at +0x7484 match the fields of the same offsets
   used by unit_0202f2a8.c for the global game state, but no caller in C confirms the type,
   so the layout is kept local and neutral. */
typedef struct Unk0f8998Work {
    u8 pad_0000[0x7440];
    u32 unk_7440;
    u8 pad_7444[0x3d];
    s8 state;                   /* +0x7481 */
    s8 unk_7482;                /* +0x7482, first grid coordinate */
    s8 unk_7483;                /* +0x7483, second grid coordinate */
    s32 counter;                /* +0x7484 */
} Unk0f8998Work;

/* The 8-byte record consumed by Unk116360_Unk_116404 and func_02034b7c. */
typedef struct Unk0f8998Entry {
    u16 unk_00;
    s8 unk_02;
    s8 unk_03;
    u32 unk_04;
} Unk0f8998Entry;

/* One grid cell: two bytes followed by a word whose low 3 bits select the entry kind. */
typedef struct Unk0f8998Cell {
    u8 unk_00;
    u8 unk_01;
    u16 pad_02;
    u32 unk_04 : 3;
} Unk0f8998Cell;

u8 *Unk02f2a8_Unk_034970(u8 *p, int x, int y);
u8 *Unk038fbc_Unk_039160(u8 **o, int x, int y);
u8 *Unk038fbc_GetElement(u32 *p, u32 i, u32 j);
u8 *Unk02e000_GetWorkArea(void);
void Unk116360_Unk_116404(Unk0f8998Entry *e, int x, int y);
void func_02034b7c(u16 id, int x, int y, u32 v, u32 a, u32 b, u32 c, u32 d);
void Unk0a0ce4_Unk_0a0da4(int se);
int func_02052728(void);
void func_020a03fc(void);
void ScanVisor_Unk_0a2acc(void);

/* Empty callback referenced from the data table at 0x0213bf98. */
void Unk0f8998_Nop_0f8998(void) { }

/* Per-frame step of a grid-interaction state machine. State 0 waits ten frames and then
   rebuilds the cell entry at (unk_7482, unk_7483), plays sound 45 and advances; states 1
   and 2 wait for func_02052728 to report the matching animation value; state 3 just
   advances; state 4 returns 1 once unk_7440 is set. `counter` is reset on every
   transition and only state 0 reads it. */
int func_020f899c(Unk0f8998Work *w)
{
    int result = 0;
    u8 *table;
    u8 *raw;
    Unk0f8998Cell *entry;

    w->counter++;
    switch (w->state) {
    case 0:
        if (w->counter > 10) {
            s8 y = w->unk_7483;
            s8 x = w->unk_7482;
            table = Unk02f2a8_Unk_034970((u8 *)w + 4, x, y);
            raw = Unk038fbc_Unk_039160((u8 **)table, x, y);
            entry = (Unk0f8998Cell *)Unk038fbc_GetElement(
                (u32 *)Unk02f2a8_Unk_034970((u8 *)w + 4, w->unk_7482, w->unk_7483),
                5, raw[1]);
            Unk0f8998Entry e = {0};
            e.unk_00 = *(u16 *)(Unk02e000_GetWorkArea() + 0x35c);
            e.unk_02 = entry->unk_00;
            e.unk_03 = entry->unk_01;
            e.unk_04 = *(u32 *)(Unk02e000_GetWorkArea() + 0x358);
            switch (entry->unk_04) {
            case 1:
                e.unk_04 = 0;
                break;
            case 2:
                e.unk_04 = 2;
                break;
            case 3:
                e.unk_04 = 3;
                break;
            case 4:
                e.unk_04 = 1;
                break;
            }
            Unk116360_Unk_116404(&e, w->unk_7482, w->unk_7483);
            func_02034b7c(e.unk_00, e.unk_02, e.unk_03, e.unk_04, 4, 1, 0, 1);
            Unk0a0ce4_Unk_0a0da4(45);
            w->counter = 0;
            w->state++;
        }
        break;
    case 1:
        if (func_02052728() == 0) {
            func_020a03fc();
            ScanVisor_Unk_0a2acc();
            w->counter = 0;
            w->state++;
        }
        break;
    case 2:
        if (func_02052728() == 1) {
            w->counter = 0;
            w->state++;
        }
        break;
    case 3:
        w->counter = 0;
        w->state++;
        break;
    case 4:
        if (w->unk_7440 == 1) {
            result = 1;
        }
        break;
    }
    return result;
}
