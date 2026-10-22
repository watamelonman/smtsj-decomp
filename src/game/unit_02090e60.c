/* src/game/unit_02090e60.c: menu screen state helpers.
 *
 * Only `func_020934c8` is matched so far. The remaining functions in this
 * translation unit are still linked from the delinked original; see
 * docs/functions/game-unit-02090e60.md for the hard-function notes.
 */
#include "types.h"

/* The object handled by this unit. Only the 12-entry pointer table at +0x40c
 * is described here; the other fields are addressed through their offsets
 * until their roles are known. */
typedef struct Unk090e60Work {
    u8 pad_0000[0x2f4];
    s16 unk_02f4;
    u8 pad_02f6[0x116];
    u32 *unk_040c[12];
} Unk090e60Work;

void func_020937a0(int work, int mode, int arg2, int arg3);
void func_0205c6f8(u32 value);
void Unk065e88_SetFlag3a(u32 *entry, int flag);
int Unk02f078_GetEntry5e12Bit0(u8 index);
void func_0205cac0(u32 value);
void Unk06a224_Unk_06adc0(int id);

/* Refresh the 12 selectable entries after the active group changed. Clears the
 * "pending" byte at +0x353, rebuilds the list, and asks the UI to play the
 * selection sound when the group was swapped. `mode` and `arg2`/`arg3` are
 * forwarded unchanged to func_020937a0 (the list builder). */
void func_020934c8(int work, int mode, int arg2, int arg3)
{
    s32 i;
    s32 start;
    Unk090e60Work *w = (Unk090e60Work *)work;

    *(u8 *)(work + 0x353) = 0;
    func_020937a0(work, *(u8 *)(work + *(s16 *)(work + 0x2f4) + 0x354), arg2, arg3);

    start = *(s32 *)(work + 0x39c);
    if (start - *(s32 *)(work + 0x3a0) != 0) {
        i = 0;
        do {
            func_0205c6f8(*w->unk_040c[i]);
            Unk065e88_SetFlag3a(w->unk_040c[i], 0);
            i++;
        } while (i < 12);

        for (i = start; i < start + 12; i++) {
            if (i < *(s32 *)(work + 0x398) &&
                Unk02f078_GetEntry5e12Bit0(*(u8 *)(work + i + 0x354)) != 0) {
                Unk065e88_SetFlag3a(w->unk_040c[i - start], 1);
                func_0205cac0(*w->unk_040c[i - start]);
            }
        }
    }

    if (*(s8 *)(work + 0x3e0) == 0) {
        return;
    }
    *(u8 *)(work + 0x3e0) = 0;
    Unk06a224_Unk_06adc0(14);
}
