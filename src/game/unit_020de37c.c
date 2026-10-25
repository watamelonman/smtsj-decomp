#include "types.h"

/* Borrowed record; the two byte thresholds are read at +0x5a and +0x5b. */
typedef struct Unk0de37cRecord {
    u8 pad_00[0x5a];
    u8 threshold0;
    u8 threshold1;
} Unk0de37cRecord;

void func_02058e9c(int layer, int id, int x, int y, float scale, int flags, int order);
void func_02058f10(int layer, int id, int x, int y, int width, int height, int order);
Unk0de37cRecord *func_020a1740(int index);
int Unk02e000_GetRecordUnk1e(int index);

/* Submit the two fixed entries at the supplied coordinates; IDs and call sequence
 * are evidenced by the original at 0x020de37c. Coordinates pass through unchanged. */
void func_020de37c(int x, int y)
{
    func_02058e9c(2, 0x2100, x, y, 1.0f, 0, 9);
    func_02058e9c(0x1002, 0x2101, x, y, 1.0f, 0, 9);
}

/* Submit a segmented 60-unit bar using record +0x1e and byte thresholds +0x5a/5b.
 * Evidence is the fixed-point /10 scaling and width-bearing calls in the original.
 * Index must designate a valid record; x/y use the downstream drawing coordinates. */
void func_020de3f4(int index, int x, int y)
{
    Unk0de37cRecord *record = func_020a1740(index);
    int value = Unk02e000_GetRecordUnk1e(index);
    int t1 = record->threshold1;
    int t0 = record->threshold0;
    int scaled = (value << 12) / 10;
    int scaled0 = (t0 << 12) / 10;
    int scaled1 = (t1 << 12) / 10;
    int amount = (scaled * 6) >> 12;
    s16 width0 = 0;
    s16 width1 = 0;
    u16 bound0 = (scaled0 * 6) >> 12;
    u16 bound1 = (scaled1 * 6) >> 12;
    s16 width2;
    if (amount <= 0) return;
    if (Unk02e000_GetRecordUnk1e(index) >= 100) {
        int left = x - 1;
        func_02058f10(2, 0x2180, left, y, 60, 3, 10);
        func_02058e9c(2, 0x2181, left, y, 1.0f, 0, 11);
        return;
    }
    if (amount >= bound0) {
        if (bound0 != 0) {
            width0 = bound0 - 1;
            func_02058f10(2, 0x2105, x + bound0 - 1, y, 1, 3, 10);
        }
    } else width0 = amount;
    if (amount >= bound1) {
        if (bound1 != 0) {
            width1 = bound1 - bound0 - 1;
            func_02058f10(2, 0x2105, x + bound1 - 1, y, 1, 3, 10);
        }
    } else width1 = amount - bound0;
    width2 = amount - bound1;
    if (width0 > 0) func_02058f10(2, 0x2102, x - 1, y, width0, 3, 10);
    if (width1 > 0) func_02058f10(2, 0x2103, x - 1 + bound0, y, width1, 3, 10);
    if (width2 > 0) func_02058f10(2, 0x2104, x - 1 + bound1, y, width2, 3, 10);
}
