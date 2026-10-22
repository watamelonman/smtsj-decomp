/* src/game/unit_02090e60.c: work-entry refresh helper.
 *
 * Only `func_020934c8` is matched so far. The remaining functions in this
 * translation unit are still linked from the delinked original; see
 * docs/functions/game-unit-02090e60.md for the hard-function notes.
 */
#include "types.h"

/* Partial work layout inferred from the field widths in func_020934c8. */
typedef struct Unk090e60Work {
    u8 pad_0000[0x2f4];
    s16 unk_02f4;
    u8 pad_02f6[0x5d];
    u8 unk_0353;
    u8 unk_0354[0x44]; /* Guessed extent: next observed field is +0x398. */
    s32 unk_0398;
    s32 unk_039c;
    s32 unk_03a0;
    u8 pad_03a4[0x3c];
    s8 unk_03e0;
    u8 pad_03e1[0x2b];
    u32 *unk_040c[12];
} Unk090e60Work;

void func_020937a0(Unk090e60Work *work, u8 group, int arg2, int arg3);
void func_0205c6f8(u32 value);
void Unk065e88_SetFlag3a(u32 *entry, int flag);
int Unk02f078_GetEntry5e12Bit0(u8 index);
void func_0205cac0(u32 value);
void Unk06a224_Unk_06adc0(int id);

/* Clear +0x353, rebuild the current group, and refresh the twelve entry flags.
 * Evidence: the indexed +0x354 loads and twelve +0x40c pointers below. The
 * signed flag at +0x3e0 gates and is cleared before the helper call with id 14.
 * The second parameter is unused; the final two pass through to the builder. */
void func_020934c8(Unk090e60Work *work, int mode, int arg2, int arg3)
{
    s32 i;
    s32 start;

    work->unk_0353 = 0;
    func_020937a0(work, work->unk_0354[work->unk_02f4], arg2, arg3);

    start = work->unk_039c;
    if (start - work->unk_03a0 != 0) {
        i = 0;
        do {
            func_0205c6f8(*work->unk_040c[i]);
            Unk065e88_SetFlag3a(work->unk_040c[i], 0);
            i++;
        } while (i < 12);

        for (i = start; i < start + 12; i++) {
            if (i < work->unk_0398 &&
                Unk02f078_GetEntry5e12Bit0(work->unk_0354[i]) != 0) {
                Unk065e88_SetFlag3a(work->unk_040c[i - start], 1);
                func_0205cac0(*work->unk_040c[i - start]);
            }
        }
    }

    if (work->unk_03e0 == 0) {
        return;
    }
    work->unk_03e0 = 0;
    Unk06a224_Unk_06adc0(14);
}
