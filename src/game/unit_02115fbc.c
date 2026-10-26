/* Local layouts follow the loads/stores in the original ARM routines. */
#include "types.h"

typedef struct Unk115fbcWork {
    u32 unk_00;
    u32 unk_04;
    void *unk_08;
    void *unk_0c;
    void *unk_10[3];
} Unk115fbcWork;

typedef struct Unk115fbcState {
    u8 pad_00[0x48];
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    char unk_54[0x20];
} Unk115fbcState;

typedef struct Unk115fbcRecord {
    u32 unk_00;
    u8 pad_04[0x1d4];
    u16 unk_1d8;
} Unk115fbcRecord;

typedef struct Unk115fbcTable {
    u8 pad_00[0x64];
    Unk115fbcRecord *unk_64[10];
    u32 unk_8c;
} Unk115fbcTable;

Unk115fbcState *Unk044904_Unk_045080(void);
Unk115fbcTable *Unk044904_Get_data_0215ee98(void);
int func_0203ac00(int index);
u32 Unk03aae8_Unk_03ac9c(int index);
int func_02013c14(char *out, u32 size, const char *format, u32 value);
extern const char data_02151b24[];
extern const char data_02151afc[];
extern const char data_02151b10[];
void func_0205c3dc(void *resource);
void func_0205ddb4(void *resource);
void func_0205c368(void *resource);
void func_02115ca0(Unk115fbcWork *work);
void func_02115e20(Unk115fbcWork *work);
Unk115fbcWork *func_020611dc(void (*init)(Unk115fbcWork *),
    void (*step)(Unk115fbcWork *), int arg2,
    void (*destroy)(Unk115fbcWork *), int size, int alignment, int arg6, int arg7);
void Unk09d060_Unk_09d170(void);
void Unk02e000_Unk_02e0cc(void);
void *func_0205dcd4(const char *name, int arg1);
void *func_0205c2c4(const char *name);
void *func_0205c3c0(void);
void func_0205c3fc(void *item, void *arg1, void *arg2);
void func_0205c408(void *item, int index);
void func_0205c6e0(void *item);
void *func_02044ec4(u32 record);
int func_02049d80(void *record, int arg1);
void func_0204f59c(int arg0, u32 record, int index);
void func_0204f5e0(int arg0, u32 record, int index);
void func_0204f24c(int arg0, u32 record, int index, int mode, int arg4, int arg5);
void func_0204f364(int arg0, u32 record, int arg2);

/* Releases the three owned items before their backing resources; null slots
 * are allowed, and each released pointer is cleared. */
void func_02115fbc(Unk115fbcWork *work)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (work->unk_10[i] != 0) {
            func_0205c3dc(work->unk_10[i]);
            work->unk_10[i] = 0;
        }
    }
    if (work->unk_08 != 0) {
        func_0205ddb4(work->unk_08);
        work->unk_08 = 0;
    }
    if (work->unk_0c != 0) {
        func_0205c368(work->unk_0c);
        work->unk_0c = 0;
    }
}

/* Allocates a 28-byte callback work block and binds three indexed items to
 * the resources named by the two original data symbols. Returns null on failure. */
Unk115fbcWork *func_02116028(void)
{
    Unk115fbcWork *work = func_020611dc(func_02115ca0, func_02115e20, 0,
        func_02115fbc, 28, 4, 0, 0);
    int i;
    if (work != 0) {
        Unk09d060_Unk_09d170();
        work->unk_00 = 0;
        work->unk_04 = 0;
        Unk02e000_Unk_02e0cc();
        work->unk_08 = func_0205dcd4(data_02151afc, 1);
        work->unk_0c = func_0205c2c4(data_02151b10);
        for (i = 0; i < 3; i++) {
            work->unk_10[i] = func_0205c3c0();
            func_0205c3fc(work->unk_10[i], work->unk_08, work->unk_0c);
            func_0205c408(work->unk_10[i], i);
            func_0205c6e0(work->unk_10[i]);
        }
    }
    return work;
}

/* Formats operand zero into the state's 32-byte buffer and marks it ready. */
u32 Unk115fbc_Unk_1160f8(void)
{
    Unk115fbcState *state = Unk044904_Unk_045080();
    u32 value = Unk03aae8_Unk_03ac9c(0);
    func_02013c14(state->unk_54, 0x20, data_02151b24, value);
    state->unk_48 = 1;
    return 3;
}

/* Sets the request flag and records whether operand zero is zero. */
u32 Unk115fbc_Unk_116134(void)
{
    Unk115fbcState *state = Unk044904_Unk_045080();
    int value = func_0203ac00(0);
    state->unk_4c = 1;
    if (value == 0) {
        state->unk_50 = 1;
    } else {
        state->unk_50 = 0;
    }
    return 1;
}

/* Selects a packed record by category and halfword ID; category 3 returns
 * the table's direct record. Missing matches return the original 0xffff sentinel. */
u32 func_02116168(u32 category, int id)
{
    int type = 0;
    Unk115fbcTable *table = Unk044904_Get_data_0215ee98();
    int i;
    switch (category) {
    case 0: break;
    case 1: type = 2; break;
    case 2: type = 1; break;
    case 3: return table->unk_8c;
    }
    for (i = 0; i < 10; i++) {
        Unk115fbcRecord *record = table->unk_64[i];
        if (record != 0) {
            u32 value = record->unk_00;
            if (type == ((value >> 16) & 0xff) && record->unk_1d8 == id) {
                return value;
            }
        }
    }
    return 0xffff;
}

/* Applies mode zero to the selected record, clamping the signed operand to
 * count minus one. A zero record category leaves state untouched and returns 1. */
u32 func_02116200(void)
{
    Unk115fbcState *state = Unk044904_Unk_045080();
    int category = func_0203ac00(0);
    int id = func_0203ac00(1);
    int index = func_0203ac00(2);
    u32 record = func_02116168(category, id);
    if (((record >> 16) & 0xff) != 0) {
        int count = func_02049d80(func_02044ec4(record), 0);
        if (index >= count) {
            index = count - 1;
        }
        func_0204f59c(0, record, index);
        func_0204f24c(0, record, index, 0, 0, 1);
        func_0204f364(0, record, 0);
        state->unk_48 = 1;
        return 3;
    }
    return 1;
}

/* Applies mode two with the supplied index when the selected packed record
 * has a nonzero category, then marks the state ready and returns 3. */
u32 func_021162c4(void)
{
    Unk115fbcState *state = Unk044904_Unk_045080();
    int category = func_0203ac00(0);
    int id = func_0203ac00(1);
    int index = func_0203ac00(2);
    u32 record = func_02116168(category, id);
    if (((record >> 16) & 0xff) == 0) {
        return 1;
    }
    func_0204f5e0(0, record, index);
    func_0204f24c(0, record, index, 2, 0, 1);
    state->unk_48 = 1;
    return 3;
}
