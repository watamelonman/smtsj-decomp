/* Work-area accesses and helper calls recovered from the ARM object. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0ce578Work {
    s32 unk_0000;
    u32 unk_0004;
    s32 phase;
    s32 unk_000c;
    u32 unk_0010;
    u8 records[0x74];
    u32 items[4];
    u8 pad_0098[0x10];
    s32 selection;
    u8 pad_00ac[0x18];
    s32 unk_00c4;
    u8 pad_00c8[8];
    s32 count;
    s32 index;
    u32 unk_00d8;
    u32 unk_00dc;
    u32 unk_00e0;
} Unk0ce578Work;


/** Empty callback: the original consists solely of a return instruction. */
void Unk0ce578_Nop_0ce5e4(void) { }

s32 Unk0d297c_Unk_0d3138(void);
void Unk122e1c_Unk_122f88(u32 handle, s32 zero, s32 value);
/** Forward the global query to helper 122f88 with the borrowed +0x10 handle. */
void Unk0ce578_Unk_0cec98(Unk0ce578Work *arg0){
  u32 tmp1;
  tmp1 = Unk0d297c_Unk_0d3138();
  Unk122e1c_Unk_122f88(arg0->unk_0010,0,tmp1);
  return;
}

void Unk0ce578_SetState(Unk0ce578Work *work, s32 state);
void Unk122e1c_Unk_123294(u32 handle);
/** Reset the +0x10 handle, save the supplied value at +0xd8, and enter state 3. */
void Unk0ce578_Unk_0cf29c(Unk0ce578Work *arg0, u32 arg1){
  Unk122e1c_Unk_123294(arg0->unk_0010);
  arg0->unk_00d8 = arg1;
  arg0->unk_0004 = 1;
  Unk0ce578_SetState(arg0,3);
  return;
}

extern u8 data_02176bd0[];
void Unk095560_Unk_0956c8(void);
void Unk0bc1a8_Unk_0bc9b4(s32 value, s32 zero);
s32 Unk0de678_Get_data_021508d4(void);
void Unk0de678_Unk_0de870(void);
void Unk122a78_Unk_122aa0(void);
void Unk1241ec_Unk_124258(void);
/** Run the observed teardown sequence and clear the global word at +4. */
void Unk0ce578_Unk_0ce5e8(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    Unk0bc1a8_Unk_0bc9b4(0x14,0);
    Unk1241ec_Unk_124258();
    Unk122a78_Unk_122aa0();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
  ((u32 *)data_02176bd0)[1] = 0;
  return;
}

void Unk0a0ce4_Unk_0a0da4(s32 value);

/** Set the state word at +0; ARM callers and the conditional state-2 hook
 * support the existing SetState name. The work area remains caller-owned. */
void Unk0ce578_SetState(Unk0ce578Work *p, int k)
{
    if (k == 2) {
        Unk0ce578_Unk_0cec98(p);
    }
    p->unk_0000 = k;
}

/** Enter state 9 with the supplied value unless value 2 fails the global query. */
void Unk0ce578_Unk_0cf258(Unk0ce578Work *arg0, int arg1){
  int tmp1;
  if ((arg1 == 2) && (tmp1 = Unk0d297c_Unk_0d3138(), tmp1 == 0)) {
    return;
  }
  Unk0a0ce4_Unk_0a0da4(5);
  arg0->unk_0004 = 4;
  Unk0ce578_SetState(arg0,9);
  arg0->unk_000c = arg1;
  return;
}



/* Provider contracts use only the arguments observed in this unit's ARM calls. */
s32 Unk02f078_Unk_02f0e8(void);
void Unk02f078_Unk_02f0c4(void);
void func_020cb3dc(void);
void Unk095560_Unk_095a2c(void);
s32 func_020de8b0(u32 value);
void Unk122a78_Unk_122a78(void);
void Unk1241ec_Thunk_02124338(void);
void Unk0bc1a8_Unk_0bc928(s32 id, s32 value, s32 zero);
s32 Unk0de678_CountLeading(void *records);
void func_020ffebc(u32 item);
void Unk0fd268_Unk_0fd3ac(void);
void ImageBg_Unk_0e5530(void);
void func_02122e1c(u32 handle);
void Unk1241ec_Unk_124214(void);
void Unk0de678_Unk_0dea60(void);
void Unk1241ec_Unk_124224(s32 value);
void func_020de7e8(s32 one, s32 zero);
void Unk1241ec_Unk_1241ec(void);
u32 func_02122abc(void);
void ImageBg_Unk_0e54d4(u32 value);
void Unk0fd268_Unk_0fd380(s32 value);
void Unk0fd268_SetDir(s32 value);
u32 func_020ffd48(u16 id, s32 index, s32 count);
void func_0212351c(u32 handle, s32 count, s32 value);
void func_02124c5c(void);
void func_02124ce8(s32 value);
void func_02123340(u32 handle);
void Unk0de678_Unk_0dec94(void *record);
void CaveNpc_SetActive(u32 item, s32 active);
void Unk124c5c_Unk_124cb0(void);
void Unk122e1c_Unk_123048(u32 handle);
void Unk0bc1a8_Unk_0bc504(Unk0ce578Work *work, s32 zero);
s32 func_020cb5b4(u32 value, s32 *phase);
void func_020cf2cc(Unk0ce578Work *work);
void func_020cf360(Unk0ce578Work *work);
void func_020cf454(Unk0ce578Work *work);

/** Initialize the global mode and providers; evidence: calls and global +4 stores. */
void func_020ce578(void)
{
    if (Unk02f078_Unk_02f0e8()) {
        ((u32 *)data_02176bd0)[1] = 1;
        Unk02f078_Unk_02f0c4();
    } else {
        ((u32 *)data_02176bd0)[1] = 0;
    }
    func_020cb3dc();
    Unk095560_Unk_095a2c();
    if (func_020de8b0(((u32 *)data_02176bd0)[1]) == 0) {
        Unk122a78_Unk_122a78();
        Unk1241ec_Thunk_02124338();
        Unk0bc1a8_Unk_0bc928(20, 0xffff, 0);
    }
}

/** Release counted non-null items and providers, then clear both status words. */
void func_020cf2cc(Unk0ce578Work *work)
{
    int i;
    for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
        if (work->items[i] != 0) {
            func_020ffebc(work->items[i]);
            work->items[i] = 0;
        }
    }
    Unk0fd268_Unk_0fd3ac();
    ImageBg_Unk_0e5530();
    func_02122e1c(work->unk_0010);
    work->unk_0010 = 0;
    Unk1241ec_Unk_124214();
    Unk0bc1a8_Unk_0bc9b4(10, 0);
    Unk0de678_Unk_0de870();
    Unk1241ec_Unk_124258();
    Unk122a78_Unk_122aa0();
    work->unk_00dc = 0;
    work->unk_00e0 = 0;
}

/** Teardown retains resources for saved value 15; clear the global owner afterward. */
void func_020ce7cc(Unk0ce578Work *work)
{
    int i;
    if (work->unk_00d8 != 15) {
        for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
            if (work->items[i] != 0) {
                func_020ffebc(work->items[i]);
                work->items[i] = 0;
            }
        }
        Unk0fd268_Unk_0fd3ac();
        ImageBg_Unk_0e5530();
        func_02122e1c(work->unk_0010);
        work->unk_0010 = 0;
        Unk1241ec_Unk_124214();
    }
    Unk0bc1a8_Unk_0bc9b4(10, 0);
    Unk0de678_Unk_0dea60();
    ((u32 *)data_02176bd0)[0] = 0;
}

/** Map the low half of +0xa8 to provider modes, using d3138 for selection zero. */
void func_020cf454(Unk0ce578Work *work)
{
    int value;
    switch ((u16)work->selection) {
    case 0: value = Unk0d297c_Unk_0d3138() ? 0 : 5; break;
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    default: value = 4; break;
    }
    Unk1241ec_Unk_124224(value);
}

/** Recreate providers and counted 26-byte records; ID 604 offsets the item indices. */
void func_020cf360(Unk0ce578Work *work)
{
    int count, i;
    u8 *record;
    Unk122a78_Unk_122a78();
    Unk1241ec_Thunk_02124338();
    func_020de7e8(1, 0);
    Unk0bc1a8_Unk_0bc928(10, 0xffff, 0);
    Unk1241ec_Unk_1241ec();
    work->unk_0010 = func_02122abc();
    ImageBg_Unk_0e54d4(work->records[8]);
    Unk0fd268_Unk_0fd380(2);
    Unk0fd268_SetDir(1);
    count = Unk0de678_CountLeading(work->records);
    i = 0;
    if (count > 0) {
        record = (u8 *)work;
        do {
            if (*(u16 *)(work->records + 10) == 604) {
                work->items[i] = func_020ffd48(*(u16 *)(record + 30), i - 1, count - 1);
            } else {
                work->items[i] = func_020ffd48(*(u16 *)(record + 30), i, count);
            }
            i++;
            record += 26;
        } while (i < count);
    }
    func_0212351c(work->unk_0010, work->count, 3);
    func_02124c5c();
    func_02124ce8(1);
    func_020cf454(work);
    func_02123340(work->unk_0010);
    work->unk_00dc = 1;
    work->unk_00e0 = 1;
}

/** Borrowed callback descriptor; fields mirror stores at +0..+0x20. */
typedef struct Unk0ce578Descriptor {
    u32 size;
    u32 flags;
    u32 reserved;
    void (*update)(Unk0ce578Work *work);
    void (*dispatch)(Unk0ce578Work *work);
    u32 (*query_dc)(Unk0ce578Work *work);
    u32 (*query_e0)(Unk0ce578Work *work);
    void (*release)(Unk0ce578Work *work);
    void (*event)(Unk0ce578Work *work, const u32 *message);
} Unk0ce578Descriptor;
void func_020ce868(Unk0ce578Work *work);
void func_020cefac(Unk0ce578Work *work);
u32 func_020cf4b8(Unk0ce578Work *work);
u32 func_020cf4c4(Unk0ce578Work *work);
void func_020cf4d0(Unk0ce578Work *work, const u32 *message);

/** Register six observed callbacks and the required 0xe4-byte work size. */
void func_020ce628(Unk0ce578Descriptor *descriptor)
{
    descriptor->size = 0xe4;
    descriptor->flags = 0;
    descriptor->update = func_020ce868;
    descriptor->dispatch = func_020cefac;
    descriptor->query_dc = func_020cf4b8;
    descriptor->query_e0 = func_020cf4c4;
    descriptor->release = func_020ce7cc;
    descriptor->event = func_020cf4d0;
}

/* Decode the optional word only when the payload flag permits it. */
static inline void ReadSelected(const u32 *payload, s32 *selected)
{
    if (payload != 0) {
        s32 value = payload[4];
        if (*(const u8 *)payload & 8) *selected = value;
    }
}

/** Consume event kinds 1 and 3; kind 3 requires state 5 and a valid message. */
void func_020cf4d0(Unk0ce578Work *work, const u32 *message)
{
    const u32 *payload = &message[1];
    int i;
    switch (message[0]) {
    case 0: break;
    case 2: break;
    case 3: {
        s32 output[1] = {0};
        s32 selected;
        if (work->unk_0000 != 5) return;
        ReadSelected(payload, output);
        selected = *output;
        if (selected != 100) {
            work->index = selected;
            Unk0de678_Unk_0dec94((u8 *)work + 0x20 + selected * 26);
            work->unk_0004 = 5;
            Unk0ce578_SetState(work, 7);
        } else {
            for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
                CaveNpc_SetActive(work->items[i], 0);
            }
            Unk124c5c_Unk_124cb0();
            Unk122e1c_Unk_123048(work->unk_0010);
            work->unk_0004 = 4;
            Unk0ce578_SetState(work, 2);
        }
        break;
    }
    case 4: break;
    case 1: Unk0bc1a8_Unk_0bc504(work, 0); break;
    }
}

/** Advance the borrowed phase at +8; helper results select release, setup or state. */
void func_020cecb8(Unk0ce578Work *work, u32 value)
{
    switch (func_020cb5b4(value, &work->phase)) {
    case 1:
        func_020cf2cc(work);
        break;
    case 2:
        func_020cf360(work);
        Unk0ce578_Unk_0cec98(work);
        break;
    case 3:
        Unk0ce578_SetState(work, work->unk_0004);
        break;
    }
}

void func_020de960(void *records, s32 mode);
void Unk0bcef4_Unk_0bcef4(void *cursor, s32 count, s32 value, s32 mode);
void func_02052634(s32 screen, s32 value, s32 mask);
void Unk0cb32c_Unk_0cb35c(u32 value);

/** Create providers and counted items, initialize both cursors, and publish work.
 * Evidence: ARM stores at +0x98/+0xb4 and data_02176bd0; storage is borrowed. */
void func_020ce684(Unk0ce578Work *work)
{
    int i;
    u8 *record;
    func_020de960(work->records, 1);
    Unk0bc1a8_Unk_0bc928(10, 20, 0);
    Unk1241ec_Unk_1241ec();
    work->unk_0010 = func_02122abc();
    ImageBg_Unk_0e54d4(work->records[8]);
    Unk0fd268_Unk_0fd380(2);
    work->count = Unk0de678_CountLeading(work->records);
    i = 0;
    if (work->count > 0) {
        record = (u8 *)work;
        do {
            if (*(u16 *)(work->records + 10) == 604)
                work->items[i] = func_020ffd48(*(u16 *)(record + 30), i - 1, work->count - 1);
            else
                work->items[i] = func_020ffd48(*(u16 *)(record + 30), i, work->count);
            i++;
            record += 26;
        } while (i < work->count);
    }
    work->index = 0;
    func_0212351c(work->unk_0010, work->count, 3);
    Unk0bcef4_Unk_0bcef4((u8 *)work + 0x98, 5, 5, 1);
    Unk0bcef4_Unk_0bcef4((u8 *)work + 0xb4, 4, 4, 1);
    *(Unk0ce578Work **)data_02176bd0 = work;
    work->unk_00dc = 1;
    work->unk_00e0 = 1;
    *(u8 *)&work->phase = 0;
    work->unk_00d8 = 8;
    Unk0ce578_SetState(work, 0);
    work->unk_0004 = 2;
    work->unk_000c = 0;
    func_020cf454(work);
    func_02052634(1, 0, 31);
    Unk0cb32c_Unk_0cb35c(work->records[9]);
}

void Unk124c5c_Set_124d6c(s32 value, s32 mask);
void Unk124c5c_Set_124d8c(s32 value, s32 mask);
void Unk124c5c_Unk_124e50(s32 value);
void func_0205e560(s32 screen, s32 value);
s32 Unk124c5c_IsKind31(void);
void SaveLoadTask_SelectEntry(s32 entry);
void func_020e7f44(s32 a, s32 b, s32 c, s32 d);
s32 Unk0e1648_Unk_0e1648(void);
s32 Unk0e1648_Get_data_02176c78(void);
void func_0205257c(s32 value);
s32 ImageBg_IsMode1or2(void);
s32 Unk124c5c_IsKind0(void);

/** Advance byte phase +8 through release, save/load selection and reconstruction.
 * Evidence: SelectEntry(5/2), provider calls and phase stores in the ARM object. */
void func_020ced18(Unk0ce578Work *work)
{
    int i, count, j;
    u8 *record;
    switch (*(u8 *)&work->phase) {
    case 0:
        Unk124c5c_Set_124d6c(1, 1);
        Unk124c5c_Set_124d8c(1, 0);
        Unk124c5c_Unk_124e50(7);
        func_0205e560(1, 10);
        (*(u8 *)&work->phase)++;
        break;
    case 1:
        if (Unk124c5c_IsKind31()) {
            for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
                if (work->items[i]) {
                    func_020ffebc(work->items[i]);
                    work->items[i] = 0;
                }
            }
            Unk0fd268_Unk_0fd3ac();
            ImageBg_Unk_0e5530();
            func_02122e1c(work->unk_0010);
            work->unk_0010 = 0;
            Unk1241ec_Unk_124214();
            work->unk_00dc = 0;
            (*(u8 *)&work->phase)++;
        }
        break;
    case 2:
        if (work->selection == 1) SaveLoadTask_SelectEntry(5);
        else SaveLoadTask_SelectEntry(2);
        func_020e7f44(0, 0, 0, 0);
        (*(u8 *)&work->phase)++;
        break;
    case 3:
        if (Unk0e1648_Unk_0e1648()) {
            if (Unk0e1648_Get_data_02176c78()) {
                Unk1241ec_Unk_1241ec();
                work->unk_0010 = func_02122abc();
                func_02123340(work->unk_0010);
                Unk0ce578_Unk_0cec98(work);
                ImageBg_Unk_0e54d4(work->records[8]);
                Unk0fd268_Unk_0fd380(2);
                Unk0fd268_SetDir(1);
                count = Unk0de678_CountLeading(work->records);
                j = 0;
                if (count > 0) {
                    record = (u8 *)work;
                    do {
                        if (*(u16 *)(work->records + 10) == 604)
                            work->items[j] = func_020ffd48(*(u16 *)(record + 30), j - 1, count - 1);
                        else
                            work->items[j] = func_020ffd48(*(u16 *)(record + 30), j, count);
                        j++;
                        record += 26;
                    } while (j < count);
                }
                work->index = 0;
                func_0212351c(work->unk_0010, work->count, 3);
                func_020cf454(work);
                (*(u8 *)&work->phase)++;
            } else {
                func_0205257c(0);
                *(u8 *)&work->phase = 0;
                Unk0ce578_SetState(work, 1);
                work->unk_00d8 = 15;
            }
        }
        break;
    case 4:
        if (!ImageBg_IsMode1or2()) {
            func_02124c5c();
            Unk124c5c_Set_124d8c(0, 31);
            work->unk_00dc = 1;
            (*(u8 *)&work->phase)++;
        }
        break;
    case 5:
        if (Unk124c5c_IsKind0()) {
            *(u8 *)&work->phase = 0;
            Unk0ce578_SetState(work, 4);
        }
        break;
    }
}

s32 func_020e807c(void);
s32 Unk0cb32c_Unk_0cb7f0(void);
s32 Unk0e651c_Unk_0e666c(s32 id);
s32 func_02053824(s32 device, s32 mask);
s32 func_02053800(s32 device, s32 mask);
void func_020bcc7c(void *cursor);
void func_020bccec(void *cursor);
s32 Unk122e1c_Unk_122f94(u32 handle, s32 index);
void Unk124c5c_Unk_124cc4(void);
void Unk122e1c_Unk_122ff0(u32 handle);
void func_020bcfc4(void *cursor, s32 value);

/** Dispatch state-4 provider selections and input masks to cursor/state changes.
 * Evidence: e807c selection and 53800/53824 mask calls; requires valid work. */
void func_020cefac(Unk0ce578Work *work)
{
    int selected;
    if (work->unk_0000 != 4) return;
    selected = func_020e807c();
    if (selected >= 0) {
        switch (selected) {
        case 0: Unk0ce578_Unk_0cf258(work, 2); break;
        case 1:
            if (Unk0cb32c_Unk_0cb7f0() == 1) Unk0ce578_Unk_0cf258(work, 0);
            break;
        case 2:
            if (Unk0e651c_Unk_0e666c(0x705)) Unk0ce578_Unk_0cf258(work, 1);
            break;
        case 3: break;
        }
    } else if (func_02053824(0, 64)) {
        Unk0a0ce4_Unk_0a0da4(0);
        func_020bcc7c((u8 *)work + 0x98);
        func_020cf454(work);
    } else if (func_02053824(0, 128)) {
        Unk0a0ce4_Unk_0a0da4(0);
        func_020bccec((u8 *)work + 0x98);
        func_020cf454(work);
    } else if (func_02053800(0, 1024)) {
        Unk0ce578_Unk_0cf258(work, 2);
    } else if (func_02053800(0, 2048)) {
        if (Unk0cb32c_Unk_0cb7f0()) Unk0ce578_Unk_0cf258(work, 0);
    } else if (func_02053800(0, 1)) {
        switch (work->selection) {
        case 0:
            if (!Unk122e1c_Unk_122f94(work->unk_0010, 0)) {
                Unk0a0ce4_Unk_0a0da4(4);
                break;
            }
            Unk0ce578_Unk_0cf258(work, 2);
            break;
        case 1:
        case 2:
            Unk0a0ce4_Unk_0a0da4(1);
            Unk0ce578_SetState(work, 8);
            break;
        case 3:
            if (work->count == 0) {
                Unk0a0ce4_Unk_0a0da4(4);
                break;
            }
            if (work->count == 1) {
                Unk0a0ce4_Unk_0a0da4(1);
                Unk124c5c_Unk_124cc4();
                Unk122e1c_Unk_122ff0(work->unk_0010);
                work->unk_0004 = 7;
                Unk0ce578_SetState(work, 3);
            } else {
                Unk0a0ce4_Unk_0a0da4(1);
                Unk124c5c_Unk_124cc4();
                Unk122e1c_Unk_122ff0(work->unk_0010);
                work->unk_0004 = 5;
                Unk0ce578_SetState(work, 3);
            }
            break;
        case 4:
            Unk0a0ce4_Unk_0a0da4(1);
            Unk124c5c_Unk_124cc4();
            *(u8 *)&work->phase = 0;
            Unk0ce578_SetState(work, 10);
            break;
        }
    } else if (func_02053800(0, 2) && work->selection != 4) {
        Unk0a0ce4_Unk_0a0da4(0);
        func_020bcfc4((u8 *)work + 0x98, 4);
        func_020cf454(work);
    }
}

/** By-value record block; halfword alignment and 114-byte extent are ARM-proven. */
typedef struct Unk0ce578RecordBlock { u16 words[57]; } Unk0ce578RecordBlock;
void func_020deaa0(s32 kind, Unk0ce578RecordBlock records, u32 selection);
void func_020525cc(s32 value);
s32 func_02052728(void);
s32 func_020deb68(void);
void Unk122e1c_Unk_123024(u32 handle);
void Unk02cad4_Unk_02cbdc(u32 value);
s32 Unk122e1c_Unk_122f68(u32 handle);
s32 Unk122e1c_Unk_122f54(u32 handle);
s32 Unk0de678_Unk_0debf8(void);
s32 func_020fa92c(s32 index);
s32 func_020fa9a0(void);
s32 func_020decd8(void);
s32 func_0212356c(u32 handle, u8 *phase, void *cursor, s32 count);
u32 Unk0cb32c_Unk_0cb440(s32 value);
void Unk122e1c_SetUnkFields64_b0(u32 handle, s32 selection, s32 value);

/** Advance the main state machine and refresh the handle's two selected fields.
 * Evidence: +0 state switch, by-value 114-byte record calls and +0xc4 loads. */
void func_020ce868(Unk0ce578Work *work)
{
    int i;
    switch (work->unk_0000) {
    case 0:
        if (*(u8 *)&work->phase == 0) {
            if (!ImageBg_IsMode1or2()) {
                Unk0fd268_SetDir(1);
                func_02124c5c();
                func_02124ce8(1);
                func_020525cc(0);
                (*(u8 *)&work->phase)++;
            }
        } else if (!func_02052728()) {
            if (((u32 *)data_02176bd0)[1] == 0 && func_020deb68()) {
                Unk0ce578_SetState(work, 6);
                work->unk_0004 = 2;
            } else {
                Unk122e1c_Unk_123024(work->unk_0010);
                Unk0ce578_SetState(work, work->unk_0004);
                work->unk_0004 = 4;
            }
            *(u8 *)&work->phase = 0;
        }
        break;
    case 1:
        if (!func_02052728()) Unk02cad4_Unk_02cbdc(work->unk_00d8);
        break;
    case 2:
        if (Unk122e1c_Unk_122f68(work->unk_0010)) Unk0ce578_SetState(work, work->unk_0004);
        break;
    case 3:
        if (Unk122e1c_Unk_122f54(work->unk_0010)) {
            Unk0ce578_SetState(work, work->unk_0004);
            if (work->unk_0004 == 1) {
                if (Unk0de678_Unk_0debf8()) Unk0ce578_SetState(work, 6);
                else func_0205257c(0);
            } else if (work->unk_0004 == 7) {
                Unk0de678_Unk_0dec94((u8 *)work + 0x20);
                work->unk_0004 = 2;
            } else if (work->unk_0004 == 5) {
                func_020deaa0(20, *(Unk0ce578RecordBlock *)work->records, work->index = 0);
            }
        }
        break;
    case 4: break;
    case 5:
        work->index = func_020fa92c(work->index);
        if (func_020fa9a0()) {
            for (i = 0; i < Unk0de678_CountLeading(work->records); i++)
                CaveNpc_SetActive(work->items[i], 1);
        } else {
            for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
                if (i == work->index) CaveNpc_SetActive(work->items[i], 0);
                else CaveNpc_SetActive(work->items[i], 1);
            }
        }
        break;
    case 6:
        if (func_020decd8()) {
            if (work->unk_0004 == 2) {
                if (!func_020deb68()) {
                    Unk122e1c_Unk_123024(work->unk_0010);
                    Unk0ce578_SetState(work, work->unk_0004);
                    work->unk_0004 = 4;
                }
            } else if (!Unk0de678_Unk_0debf8()) {
                func_0205257c(0);
                Unk0ce578_SetState(work, work->unk_0004);
            }
        }
        break;
    case 7:
        if (func_020decd8()) {
            Unk0ce578_SetState(work, work->unk_0004);
            if (work->unk_0004 == 5)
                func_020deaa0(20, *(Unk0ce578RecordBlock *)work->records, work->index);
            else {
                Unk124c5c_Unk_124cb0();
                Unk122e1c_Unk_123048(work->unk_0010);
                work->unk_0004 = 4;
            }
        }
        break;
    case 8: func_020ced18(work); break;
    case 9: func_020cecb8(work, work->unk_000c); break;
    case 10:
        switch (func_0212356c(work->unk_0010, (u8 *)&work->phase, (u8 *)work + 0xb4, 4)) {
        case 0:
            Unk124c5c_Unk_124cb0();
            func_020cf454(work);
            Unk0ce578_SetState(work, 4);
            break;
        case 1:
            Unk0ce578_Unk_0cf29c(work, Unk0cb32c_Unk_0cb440(work->unk_00c4 + 1));
            break;
        }
        break;
    }
    if (work->unk_0010)
        Unk122e1c_SetUnkFields64_b0(work->unk_0010, work->selection, work->unk_00c4);
}
