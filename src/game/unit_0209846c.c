typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

/* Resolver-owned record; only the collected halfwords have known contracts. */
typedef struct Unk09846cRecord {
    u8 pad_00[62];
    u16 field_3e;
    u16 field_40[3];
} Unk09846cRecord;

/* Area getter storage; signed pairs and status retain their observed offsets. */
typedef struct Unk09846cArea {
    u16 ids[4];
    u8 pad_08[10];
    s16 field_12;
    s16 field_14;
    u8 pad_16[6];
    s16 field_1c;
    s16 field_1e;
    u8 pad_20[76];
    u16 field_6c;
} Unk09846cArea;

/* Work-owned 0x3c-byte entry, indexed by the signed work list. */
typedef struct Unk09846cEntry {
    u8 pad_00[10];
    s16 field_0a;
    s16 field_0c;
    u8 pad_0e[16];
    s16 field_1e;
    s16 field_20;
    u8 pad_22[18];
    u16 field_34;
    u8 pad_36[6];
} Unk09846cEntry;

/* Global work layout; count bounds the active signed-index list. */
typedef struct Unk09846cWork {
    u8 pad_00[116];
    Unk09846cEntry entries[12];
    u8 pad_344[4];
    s8 indices[12];
    u8 pad_354[3];
    u8 count;
} Unk09846cWork;

extern Unk09846cRecord *Unk09974c_Unk_099c60(unsigned int id);
extern Unk09846cWork *Unk02e000_GetWorkArea(void);
extern Unk09846cArea *Unk02e000_Thunk_0202e788(void);

/* Collects nonzero record halfwords for the four area IDs, with extra fields
 * for slot 1. The caller supplies room for six halfwords; unused slots stay intact.
 * Record meanings are unresolved, so the original neutral symbol is retained. */
void func_0209846c(u16 *output, const Unk09846cArea *area)
{
    int count = 0;
    int i;
    u16 id;
    for (i = 0; i < 4; i++) {
        Unk09846cRecord *record;
        switch (i) {
        case 0: id = area->ids[0]; break;
        case 1: id = area->ids[1]; break;
        case 2: id = area->ids[2]; break;
        case 3: id = area->ids[3]; break;
        }
        if (id == 0) continue;
        record = Unk09974c_Unk_099c60(id);
        if (record == 0) continue;
        if (i == 1) {
            int j;
            for (j = 0; j < 3; j++) {
                u16 value = record->field_40[j];
                if (value == 0) continue;
                if (count == 6) break;
                output[count] = value;
                count++;
            }
        }
        if (count == 6) return;
        if (record->field_3e != 0) {
            if (count == 6) return;
            output[count] = record->field_3e;
            count++;
        }
    }
}

/* Aggregates positive field deficits and status weights across the area and
 * indexed work entries. Positive scale is a percentage; result caps at 99999999.
 * No evidence yet establishes the gameplay meaning of these fields. */
int func_02098544(int scale)
{
    Unk09846cWork *work = Unk02e000_GetWorkArea();
    Unk09846cArea *area = Unk02e000_Thunk_0202e788();
    int first = 0, second = 0, ones = 0, sevens = 0, others = 0;
    int i;
    u8 n;
    int result;
    if (area->field_1c < area->field_12) first += area->field_12 - area->field_1c;
    if (area->field_1e < area->field_14) second += area->field_14 - area->field_1e;
    switch (area->field_6c) {
    case 0: case 1: break;
    case 7: sevens++; break;
    default: others++; break;
    }
    n = work->count;
    for (i = 0; i < n; i++) {
        int index = work->indices[i];
        Unk09846cEntry *entry;
        if (index < 0) continue;
        entry = &work->entries[index];
        if (entry == 0) continue;
        if (entry->field_1e < entry->field_0a) first += entry->field_0a - entry->field_1e;
        if (entry->field_20 < entry->field_0c) second += entry->field_0c - entry->field_20;
        switch (entry->field_34) {
        case 0: break;
        case 1: ones++; break;
        case 7: sevens++; break;
        default: others++; break;
        }
    }
    result = first + second * 3;
    result += ones * 300;
    result += sevens * 200;
    result += others * 100;
    if (scale > 0) result = result * scale / 100;
    if (result > 99999999) result = 99999999;
    return result;
}
