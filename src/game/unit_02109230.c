/* Mode dispatch and indexed work updates; field meanings remain unknown. */
#include "types.h"



/* Deliberately empty callback, matching the original return-only body. */
void Unk109230_Nop_109284(void) { }


/* Deliberately empty callback, matching the original return-only body. */
void Unk109230_Nop_1093dc(void) { }


/* Constant-success callback: the original returns one without reading state. */
int Unk109230_GetConst1(void) { return 1; }

extern u8 data_0213c9c0[];
/* Return the address of index in the table of 12-byte records; caller supplies a valid index. */
int Unk109230_Unk_109328(int arg0)
{
  return arg0 * 0xc + ((int)data_0213c9c0);
}

/* Only the signed fields read by these handlers are known. */
typedef struct {
    u8 pad_0000[10];
    s16 unk_000a;
    s16 unk_000c;
    u8 pad_000e[4];
    s16 unk_0012;
    s16 unk_0014;
} Unk109230_Record;

typedef struct {
    s32 changed;
    s32 value;
} Unk109230_Entry;

/* Four slots inferred from the 0x20-byte spacing of the two arrays. */
typedef struct {
    u8 pad_0000[0x74a8];
    Unk109230_Entry unk_74a8[4];
    Unk109230_Entry unk_74c8[4];
    s32 pad_74e8;
    s32 unk_74ec;
} Unk109230_Work;

extern int Unk02f078_Unk_02f0d8(void);
extern void Unk02cad4_Unk_02cbdc(int value);
extern Unk109230_Record *Unk02e000_Thunk_0202e788(void);
extern Unk109230_Record *Unk02e000_Unk_02e7c0(int index);
extern void ScanVisor_Unk_0a379c(int index, int value);
extern void func_020fd0c8(int value);

/* Map the current mode to the observed callee values (1:8, 2:3, 3:10, default:8). */
void func_02109230(void)
{
    switch (Unk02f078_Unk_02f0d8()) {
    case 1: Unk02cad4_Unk_02cbdc(8); break;
    case 2: Unk02cad4_Unk_02cbdc(3); break;
    case 3: Unk02cad4_Unk_02cbdc(10); break;
    default: Unk02cad4_Unk_02cbdc(8); break;
    }
}

/* Apply a minimum-one scaled - update to slot index; null records leave work untouched.
 * Index zero uses the primary record; other valid slots use record index - 1. */
void func_02109288(Unk109230_Work *work, int index)
{
    Unk109230_Record *record;
    int value;
    int amount;
    if (index == 0) {
        record = Unk02e000_Thunk_0202e788();
        if (record == 0) return;
        value = record->unk_0014;
    } else {
        record = Unk02e000_Unk_02e7c0(index - 1);
        if (record == 0) return;
        value = record->unk_000c;
    }
    amount = (int)(0.02f * (float)value);
    if (amount < 1) amount = 1;
    work->unk_74c8[index].changed = 1;
    work->unk_74c8[index].value -= amount;
    ScanVisor_Unk_0a379c(index, 3);
    func_020fd0c8(3);
    work->unk_74ec = 1;
}

/* Apply a minimum-one scaled - update to slot index; null records leave work untouched.
 * Index zero uses the primary record; other valid slots use record index - 1. */
void func_0210933c(Unk109230_Work *work, int index)
{
    Unk109230_Record *record;
    int value;
    int amount;
    if (index == 0) {
        record = Unk02e000_Thunk_0202e788();
        if (record == 0) return;
        value = record->unk_0012;
    } else {
        record = Unk02e000_Unk_02e7c0(index - 1);
        if (record == 0) return;
        value = record->unk_000a;
    }
    amount = (int)(0.03f * (float)value);
    if (amount < 1) amount = 1;
    work->unk_74a8[index].changed = 1;
    work->unk_74a8[index].value -= amount;
    ScanVisor_Unk_0a379c(index, 3);
    func_020fd0c8(1);
    work->unk_74ec = 1;
}

/* Apply a minimum-one scaled + update to slot index; null records leave work untouched.
 * Index zero uses the primary record; other valid slots use record index - 1. */
void func_021093e8(Unk109230_Work *work, int index)
{
    Unk109230_Record *record;
    int value;
    int amount;
    if (index == 0) {
        record = Unk02e000_Thunk_0202e788();
        if (record == 0) return;
        value = record->unk_0012;
    } else {
        record = Unk02e000_Unk_02e7c0(index - 1);
        if (record == 0) return;
        value = record->unk_000a;
    }
    amount = (int)(0.05f * (float)value);
    if (amount < 1) amount = 1;
    work->unk_74a8[index].changed = 1;
    work->unk_74a8[index].value += amount;
    func_020fd0c8(2);
    work->unk_74ec = 1;
}
