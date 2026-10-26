/* Record setup, lookup, and mode helpers for the 0x02071dc0 unit. */
#include "types.h"


void func_0205bb68(void);
/* Invoke the shared operation nine times, as in the fixed nine-record loop at 0x02071e10. */
void Unk071dc0_Unk_071e08(void)
{
  u32 value;
  value = 0;
  do {
    func_0205bb68();
    value = value + 1;
  } while (value < 9);
}

void Unk05b82c_Unk_05b82c(u32 index);
void Unk071dc0_Unk_071dc0(void);
/* Initialize the shared context, then process each of the nine fixed record indices. */
void Unk071dc0_Unk_071de4(void)
{
  u32 value;
  Unk071dc0_Unk_071dc0();
  value = 0;
  do {
    Unk05b82c_Unk_05b82c(value);
    value = value + 1;
  } while (value < 9);
}

extern u8 data_02171d14[];
void Unk071dc0_Clear(void);
/* Repeat the shared operation for the current signed count, then clear the dynamic storage. */
void Unk071dc0_Unk_072200(void)
{
    int index;
    for (index = 0; index < FIELD(s32, data_02171d14, 0x600); index++) {
        func_0205bb68();
    }
  Unk071dc0_Clear();
}

extern u8 data_021458d8[];
extern u8 data_021459b0[];
void func_0205ad2c(void *context);
void func_0205ad78(void *records, int count);
/* Select the context at data_021459b0 and initialize nine records at data_021458d8. */
void Unk071dc0_Unk_071dc0(void)
{
  func_0205ad2c(data_021459b0);
  func_0205ad78(data_021458d8,9);
}

/* A 24-byte record; lookup uses the object pointer at offset 0x14. Dynamic
 * records point name at their 64-byte slot in Unk071dc0Store.names. */
typedef struct Unk071dc0Rec {
    u8 pad_00[4];
    const char *name;
    u8 pad_08[8];
    u8 *unk_10;
    u8 *object;
} Unk071dc0Rec;
/* The 0x1608 bytes cleared by Unk071dc0_Clear: 64 dynamic records, their
 * 64-byte names, the record count, and the mode word. The delinker split this
 * object at names (data_02171314) and at +0x1000 (data_02171d14), so count and
 * mode are also data_02171d14 + 0x600/0x604 (the FIELD accesses below).
 * func_02071efc must use the struct: its ROM code rereads count after storing
 * a record name, which mwcc only does when both live in one object. */
typedef struct Unk071dc0Store {
    Unk071dc0Rec recs[64];
    char names[64][64];
    s32 count;
    s32 mode;
} Unk071dc0Store;
extern Unk071dc0Store data_02170d14;
void func_02008848(void *destination, int value, u32 size);
/* Zero the 0x1608-byte dynamic storage beginning at data_02170d14. */
void Unk071dc0_Clear(void)
{
    func_02008848(&data_02170d14, 0, sizeof(Unk071dc0Store));
}

int func_0205b36c(Unk071dc0Rec *record);
int func_020152cc(const char *left, const char *right);

/* Reset mode, returning 1 on the first zero predicate; otherwise set mode to 4. */
int Unk071dc0_Unk_071fcc(void)
{
    int i;
    FIELD(s32, data_02171d14, 0x604) = 0;
    for (i = 0; i < FIELD(s32, data_02171d14, 0x600); i++) {
        if (func_0205b36c(&data_02170d14.recs[i]) == 0) {
            return 1;
        }
    }
    FIELD(s32, data_02171d14, 0x604) = 4;
    return 0;
}

/* Map the mode at offset 0x604 to 1 (4), -1 (5), or 0 (all other values). */
int Unk071dc0_GetMode604Sign(void)
{
    switch (FIELD(s32, data_02171d14, 0x604)) {
    case 4:
        return 1;
    case 5:
        return -1;
    }
    return 0;
}

/* Search the fixed nine records, then the dynamic records. The calls to
 * func_020152cc compare the string at object + 0x2c with name; only records
 * accepted by func_0205b36c participate. Return null when neither array matches.
 */
Unk071dc0Rec *func_02071e44(const char *name)
{
    Unk071dc0Rec *record = (Unk071dc0Rec *)data_021458d8;
    u32 fixedIndex;
    int dynamicIndex;

    for (fixedIndex = 0; fixedIndex < 9; fixedIndex++, record++) {
        if (func_0205b36c(record) != 0) {
            if (func_020152cc((const char *)(record->object + 0x2c), name) == 0) {
                return record;
            }
        }
    }
    record = data_02170d14.recs;
    for (dynamicIndex = 0; dynamicIndex < FIELD(s32, data_02171d14, 0x600);
         dynamicIndex++, record++) {
        if (func_0205b36c(record) != 0) {
            if (func_020152cc((const char *)(record->object + 0x2c), name) == 0) {
                return record;
            }
        }
    }
    return 0;
}

void func_020151fc(char *destination, const char *source, u32 size);
void func_02007e94(void);
/* Return the record named name: an existing fixed or dynamic match, otherwise
 * a new zeroed dynamic record whose name is copied (64 bytes max) into the
 * next names slot. With all 64 slots used, call func_02007e94 (also called
 * when allocation fails in Unk05b82c_CreateNamedEntry) and return null.
 */
Unk071dc0Rec *func_02071efc(const char *name)
{
    Unk071dc0Rec *record;
    int i;
    int count;

    record = func_02071e44(name);
    if (record != 0) {
        return record;
    }
    count = data_02170d14.count;
    record = data_02170d14.recs;
    for (i = 0; i < count; i++, record++) {
        if (func_020152cc(record->name, name) == 0) {
            return record;
        }
    }
    if (count < 64) {
        func_020151fc(data_02170d14.names[count], name, 64);
        record = &data_02170d14.recs[data_02170d14.count];
        func_02008848(record, 0, sizeof(Unk071dc0Rec));
        record->name = data_02170d14.names[data_02170d14.count];
        data_02170d14.count++;
        return record;
    }
    func_02007e94();
    return 0;
}

extern u8 data_021459c4[];
void func_0205ae60(Unk071dc0Rec *record);
/* Real first parameter is Unk05b82cDesc *, whose path (+0x04) and entry (+0x14)
 * fields sit where Unk071dc0Rec keeps name and object. */
u8 *Unk05b82c_CreateNamedEntry(Unk071dc0Rec *desc, int unused, const char *name);
void func_0205b9a0(void);
u32 Unk05ae50_Unk_05af3c(Unk071dc0Rec *record);
/* Advance the dynamic-record state machine in the mode word at +0x604 by one
 * step: 0 -> 1 (records exist) or 4; 1 runs func_0205ae60 on records failing
 * func_0205b36c, then 2; 2 creates each still-failing record's entry, then 3;
 * 3 waits until every record passes func_0205b36c, runs Unk05ae50_Unk_05af3c
 * on each, then 4. Modes 4 and 5 are left unchanged.
 */
void func_02072068(void)
{
    Unk071dc0Rec *record = data_02170d14.recs;
    int ready;
    int i;
    int j;

    func_0205ad2c(data_021459c4);
    switch (FIELD(s32, data_02171d14, 0x604)) {
    case 0:
        if (FIELD(s32, data_02171d14, 0x600) != 0) {
            FIELD(s32, data_02171d14, 0x604) = 1;
        } else {
            FIELD(s32, data_02171d14, 0x604) = 4;
        }
        break;
    case 1:
        for (i = 0; i < FIELD(s32, data_02171d14, 0x600); i++, record++) {
            if (func_0205b36c(record) == 0) {
                func_0205ae60(record);
            }
        }
        FIELD(s32, data_02171d14, 0x604) = 2;
        break;
    case 2:
        for (i = 0; i < FIELD(s32, data_02171d14, 0x600); i++, record++) {
            if (func_0205b36c(record) == 0) {
                record->object = Unk05b82c_CreateNamedEntry(record, (int)(record->unk_10 + 12), 0);
                func_0205b9a0();
            }
        }
        FIELD(s32, data_02171d14, 0x604) = 3;
        break;
    case 3:
        ready = 0;
        for (i = 0; i < FIELD(s32, data_02171d14, 0x600); i++, record++) {
            ready = func_0205b36c(record);
            if (ready == 0) {
                break;
            }
        }
        if (ready == 0) {
            break;
        }
        for (j = 0; j < FIELD(s32, data_02171d14, 0x600); j++) {
            Unk05ae50_Unk_05af3c(&data_02170d14.recs[j]);
        }
        FIELD(s32, data_02171d14, 0x604) = 4;
        break;
    case 4:
    case 5:
        break;
    }
}
