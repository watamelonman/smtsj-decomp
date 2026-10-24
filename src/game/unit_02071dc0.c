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

extern u8 data_02170d14[];
void func_02008848(void *destination, int value, u32 size);
/* Zero the 0x1608-byte dynamic storage beginning at data_02170d14. */
void Unk071dc0_Clear(void)
{
    func_02008848(data_02170d14, 0, 0x1608);
}

/* A 24-byte record; lookup uses the object pointer at offset 0x14. */
typedef struct Unk071dc0Rec {
    u8 pad_00[20];
    u8 *object;
} Unk071dc0Rec;
int func_0205b36c(Unk071dc0Rec *record);
int func_020152cc(const char *left, const char *right);

/* Reset mode, returning 1 on the first zero predicate; otherwise set mode to 4. */
int Unk071dc0_Unk_071fcc(void)
{
    int i;
    FIELD(s32, data_02171d14, 0x604) = 0;
    for (i = 0; i < FIELD(s32, data_02171d14, 0x600); i++) {
        if (func_0205b36c(&((Unk071dc0Rec *)data_02170d14)[i]) == 0) {
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
    record = (Unk071dc0Rec *)data_02170d14;
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
