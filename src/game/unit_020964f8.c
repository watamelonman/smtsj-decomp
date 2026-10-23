#include "types.h"

/* Borrowed manager view: the gap preserves the observed word offset, not a full layout. */
typedef struct Unit0964f8Manager {
    u8 pad_0000[0x3b8];
    u32 unk_03b8;
} Unit0964f8Manager;

/* Borrowed resolver record view; packed halfword fields follow the original shifts. */
typedef struct Unit0964f8Record {
    u8 pad_0000[0x26];
    u16 unk_0026 : 6;
    u16 category : 5;
    u16 selector : 5;
    u16 kind : 4;
    u16 flag0 : 1;
    u16 flag1 : 1;
    u16 flag2 : 1;
    u16 flag3 : 1;
    u16 flag4 : 1;
    u16 flag5 : 1;
    u16 flag6 : 1;
    u16 flag7 : 1;
    u16 flag8 : 1;
    u16 flag9 : 1;
    u16 flag10 : 1;
    u16 flag11 : 1;
} Unit0964f8Record;

void ImageObj_Unk_0773bc(void);
Unit0964f8Manager *Unk095560_GetManager(void);
int Unk02dcfc_GetState(void);
int Unk02dcfc_GetField54(void);
int Unk02dcfc_GetField58(void);
void func_02077314(void);
Unit0964f8Record *func_020cb21c(u32 id);
int Unk02f078_IsAllowed_02f190(int current, int candidate);

/* Invoke the image-object helper and report completion; the original always returns one. */
u32 Unk0964f8_Unk_0964f8(void)
{
    ImageObj_Unk_0773bc();
    return 1;
}

/* Clear the manager's +0x3b8 word only when all three state queries are zero,
 * then invoke the image-object helper and report completion. */
u32 Unk0964f8_Unk_096508(void)
{
    Unit0964f8Manager *manager = Unk095560_GetManager();
    if (Unk02dcfc_GetState() == 0 && Unk02dcfc_GetField54() == 0 &&
        Unk02dcfc_GetField58() == 0) {
        manager->unk_03b8 = 0;
    }
    func_02077314();
    return 1;
}

/* Inspect six borrowed IDs, ignoring zero/missing records and non-kind-5 entries.
 * Packed flags can return one immediately; otherwise the comparison helper selects
 * among mapped low-nibble values for records whose selector matches the argument. */
int func_02096548(const u16 *ids, u32 selector)
{
    int result = 0;
    int i;
    for (i = 0; i < 6; i++) {
        Unit0964f8Record *record;
        u32 kind;
        int candidate;
        if (ids[i] == 0) continue;
        record = func_020cb21c(ids[i]);
        if (record == 0) continue;
        kind = record->category;
        if (kind != 5) continue;
        kind = record->kind;
        if (kind == 0) {
            switch (selector) {
            case 0: case 1: case 2: case 3: case 4: case 5: break;
            case 6: case 7: if (record->flag0) return 1; break;
            case 8: if (record->flag1) return 1; break;
            case 9: if (record->flag2) return 1; break;
            case 10: if (record->flag3) return 1; break;
            case 11: if (record->flag4) return 1; break;
            case 12: if (record->flag5) return 1; break;
            case 13: if (record->flag6) return 1; break;
            case 14: if (record->flag7) return 1; break;
            case 15: if (record->flag8) return 1; break;
            case 16: if (record->flag9) return 1; break;
            case 17: if (record->flag10) return 1; break;
            }
        } else if (selector == record->selector) {
            candidate = 0;
            switch (kind) {
            case 1: candidate = 5; break;
            case 2: candidate = 1; break;
            case 3: candidate = 3; break;
            case 4: candidate = 4; break;
            case 0: case 5: case 6: break;
            }
            if (Unk02f078_IsAllowed_02f190(result, candidate)) result = candidate;
        }
    }
    return result;
}
