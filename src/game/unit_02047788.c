#include "types.h"

/* Only fields accessed by this unit are described; the slot count follows the loop. */
typedef struct Unk047788Entry {
    u32 id;
} Unk047788Entry;
typedef struct Unk047788Work {
    u8 pad_0000[0x40];
    u32 flags;
    u8 pad_0044[0xc];
    u32 unk_0050;
    u8 pad_0054[0x10];
    Unk047788Entry *entries[10];
} Unk047788Work;

extern u8 data_0215ee9c[];
extern u8 data_021432e4[], data_021432f0[], data_021432fc[], data_02143308[];
extern int func_02052728(void);
extern int func_02061698(void *slot);
extern void func_020614b0(void *slot);
extern Unk047788Work *Unk044904_Get_data_0215ee98(void);
extern void func_020b6514(int value);
extern int func_0205e4f8(int value);
extern void func_02116028(void);
extern int Unk09d060_Unk_09d13c(void);
extern void *Unk0a5680_GetEntryUnk14(u32 id);
extern void func_020a5fc8(void *entry, int value);
extern void Unk044904_Unk_0453dc(void);
extern void func_0204f650(int kind, u32 id, int value, int mode);
extern void func_0204f24c(int kind, u32 id, int value, int mode, int a, int b);
extern void func_0204f188(int kind, u32 id, int mode, const void *data, int value);
void Unk047788_Unk_047834(void);

/* Registers the shared slot after clearing flag 0x8000, unless a check blocks it. */
int Unk047788_Unk_047788(void)
{
    if (func_02052728() != 0) return 0;
    if (func_02061698(data_0215ee9c) != 0) return 0;
    Unk044904_Get_data_0215ee98()->flags &= ~0x8000;
    func_020614b0(data_0215ee9c);
    return 1;
}

/* Returns the constant success value; evidenced by the immediate return in the original. */
int Unk047788_GetConst1(void)
{
    return 1;
}

/* Returns the constant success value, as in the separate original entry point. */
int Unk047788_GetConst1_0477dc(void)
{
    return 1;
}

/* Clears the work word and performs setup; the -1 check controls the final call. */
int Unk047788_Unk_0477e4(void)
{
    Unk044904_Get_data_0215ee98()->unk_0050 = 0;
    func_020b6514(1);
    if (func_0205e4f8(-1) != 0) return 0;
    func_02116028();
    return 1;
}

/* Normalizes the shared query result to a boolean. */
int Unk047788_Unk_04781c(void)
{
    return Unk09d060_Unk_09d13c() != 0;
}

/* Applies value zero to non-null entries whose identifier has category byte 2. */
void Unk047788_Unk_047834(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk047788Entry *entry = Unk044904_Get_data_0215ee98()->entries[i];
        if (entry != 0) {
            u32 id = entry->id;
            if (((id >> 16) & 0xff) == 2) {
                func_020a5fc8(Unk0a5680_GetEntryUnk14(id), 0);
            }
        }
    }
}

/* Runs the shared helper before processing this unit's ten entry slots. */
int Unk047788_Unk_047884(void)
{
    Unk044904_Unk_0453dc();
    Unk047788_Unk_047834();
    return 1;
}

/* Configures the identifier through the shared helpers; negative secondary values are omitted.
 * Category byte 2 selects the first pair of constant data records. */
void func_02047898(u32 id, int primary, int secondary)
{
    func_0204f650(15, id, primary, 21);
    func_0204f24c(15, id, primary, 1, 0, 1);
    if (secondary >= 0) {
        func_0204f650(19, id, secondary, 22);
        func_0204f24c(19, id, secondary, 3, 1, 0);
    }
    if (((id >> 16) & 0xff) == 2) {
        func_0204f188(0, id, 3, data_021432e4, 1);
        func_0204f188(0, id, 4, data_021432f0, 1);
    } else {
        func_0204f188(0, id, 5, data_021432fc, 1);
        func_0204f188(14, id, 5, data_02143308, 1);
    }
}

/* Signed contribution at +0x25; the rest of the lookup record is unused. */
typedef struct Unk047788Record {
    u8 pad_0000[0x25];
    s8 contribution;
} Unk047788Record;

u16 *func_0204a0d8(Unk047788Entry *object);
Unk047788Record *func_020cb21c(int id);
int func_02049f24(Unk047788Entry *object, int which);
int Unk0b0b5c_Unk_0b0c30(Unk047788Entry *object, int value);
int Unk0b0b5c_Unk_0b0cac(Unk047788Entry *object, int value);
int Unk0caea8_GetInRange(int id);
void func_0204f108(int a, int b, int c, int d);
void func_0204f59c(int a, int id, int value);
void func_0204f364(int a, int id, int c);
int func_0204ab58(Unk047788Entry *object, int value);
int func_020b081c(int mode);
void func_0204f0d4(void);
void func_020a02c0(int id, int a, int b, int c);
int func_0204a244(Unk047788Entry *object);
int func_02050074(int a, int b);


/* Applies signed contributions from six lookup records per object, then handles
 * objects whose selector is 2. Writes state 2 when emitting an update and returns
 * 2. The calls and offsets establish this behavior, but not a gameplay name. */
int func_020479b8(u16 *state)
{
    register int changed;
    int amount;
    int i;
    int k;
    Unk047788Entry *object;
    int sum;
    u16 *ids;
    int j;
    Unk047788Entry *second;
    int a;
    int b;
    Unk047788Work *manager;
    Unk047788_Unk_047884();
    manager = Unk044904_Get_data_0215ee98();
    changed = 0;
    for (i = 0; i < 10; i++) {
        object = manager->entries[i];
        if (object != 0) {
            sum = 0;
            ids = func_0204a0d8(object);
            for (j = 0; j < 6; j++) {
                Unk047788Record *record = func_020cb21c(ids[j]);
                if (record != 0 && record->contribution != 0)
                    sum += record->contribution;
            }
            if (sum != 0) {
                int value = func_02049f24(object, 0);
                if (sum > 0) {
                    int message;
                    amount = Unk0b0b5c_Unk_0b0c30(object, sum * value / 100);
                    message = Unk0caea8_GetInRange(0x195);
                    if (message != 0) func_0204f108(0, 60, message, 0);
                    func_02047898(object->id, amount, -1);
                    *state = 2;
                    changed = 1;
                } else if (sum < 0) {
                    int message;
                    amount = -sum * value / 100;
                    if (amount <= 0) amount = 1;
                    message = Unk0caea8_GetInRange(0x196);
                    if (message != 0) func_0204f108(0, 60, message, 0);
                    func_0204f59c(0, object->id, amount);
                    func_0204f24c(0, object->id, amount, 0, 0, 1);
                    func_0204f364(0, object->id, 0);
                    if (func_0204ab58(object, amount) != 0) {
                        if (((Unk044904_Get_data_0215ee98()->flags << 20) >> 31) != 0 && func_020b081c(2) != 0)
                            amount = 1;
                        else amount = 0;
                        func_0204f0d4();
                        func_020a02c0(object->id, 0, 0, amount);
                    }
                    *state = 2;
                    changed = 1;
                }
            }
        }
    }
    for (k = 0; k < 10; k++) {
        second = manager->entries[k];
        if (second != 0 && func_0204a244(second) == 2) {
            a = func_02049f24(second, 0);
            i = func_02049f24(second, 1);
            a /= 100;
            i /= 100;
            if (a <= 1) a = func_02050074(0, 2) + 1;
            if (i <= 1) i = func_02050074(0, 2) + 1;
            b = Unk0b0b5c_Unk_0b0c30(second, a);
            a = Unk0b0b5c_Unk_0b0cac(second, i);
            if (changed != 0) {
                changed = 0;
                func_0204f0d4();
            }
            func_02047898(second->id, b, a);
            *state = 2;
        }
    }
    return 2;
}
