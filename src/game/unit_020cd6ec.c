#include "types.h"

/* Borrowed record view; the original advances records by 26 bytes. */
typedef struct Unk0cd6ecRecord {
    u8 flag;
    u8 pad_0001;
    u16 id;
    u8 pad_0004[22];
} Unk0cd6ecRecord;

/* Borrowed 0xf8-byte state; offsets agree with initialization in 020cd594. */
typedef struct Unk0cd6ecWork {
    u8 state;
    u8 substate;
    u8 saved_state;
    u8 pad_0003;
    u32 unk_0004;
    u32 unk_0008;
    void *items[4]; /* Extent inferred from the handle at +0x1c. */
    void *handle;
    u8 records[8];
    Unk0cd6ecRecord entries[4]; /* Extent inferred from following controls. */
    u8 pad_0090[4];
    u8 control_0094[16];
    u32 selection;
    u8 pad_00a8[8];
    u8 control_00b0[16];
    u32 selection_00c0;
    u8 pad_00c4[8];
    u8 control_00cc[16];
    u32 selection_00dc;
    u8 pad_00e0[8];
    u32 unk_00e8;
    u32 unk_00ec;
    u32 unk_00f0;
    u32 unk_00f4;
} Unk0cd6ecWork;

extern int func_020cb5b4(u32 value, u8 *substate);
void func_020ce2d8(Unk0cd6ecWork *work);
extern void func_020ce33c(Unk0cd6ecWork *work);
extern void Unk0a0ce4_Unk_0a0da4(int value);
extern void Unk122e1c_Unk_123294(void *handle);
extern int Unk0de678_CountLeading(void *records);
extern void func_020ffebc(void *item);
extern void Unk0cb32c_Unk_0cb754(void **handle);
extern void Unk0bc1a8_Unk_0bc9b4(int id, int value);
extern void Unk0fd268_Unk_0fd3ac(void);
extern void ImageBg_Unk_0e5530(void);
extern void func_02122e1c(void *handle);
extern void Unk0de678_Unk_0dea60(void);
extern Unk0cd6ecWork *data_02176bcc;
extern int func_021072c0(void);
extern int func_02107374(void);
extern void Unk122e1c_Unk_122fa0(void *handle, int index, u32 value);

/* Release counted non-null items and the handle, then clear the global state owner.
 * Evidence: 020cd594 creates these items and stores the state in data_02176bcc. */
void func_020cd6ec(Unk0cd6ecWork *work)
{
    int i;
    Unk0bc1a8_Unk_0bc9b4(10, 0);
    for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
        if (work->items[i] != 0) {
            func_020ffebc(work->items[i]);
            work->items[i] = 0;
        }
    }
    Unk0fd268_Unk_0fd3ac();
    ImageBg_Unk_0e5530();
    func_02122e1c(work->handle);
    work->handle = 0;
    Unk0de678_Unk_0dea60();
    data_02176bcc = 0;
}

/* Dispatch result codes 1/2 to transitions; code 3 restores the saved state. */
void Unk0cd6ec_Unk_0cddd0(Unk0cd6ecWork *work, u32 value)
{
    int result = func_020cb5b4(value, &work->substate);
    if (result == 1) {
        func_020ce2d8(work);
    } else if (result == 2) {
        func_020ce33c(work);
    } else if (result == 3) {
        work->state = work->saved_state;
    }
}

/* Set state 12 and saved state 4 after requesting helper mode 5. */
void Unk0cd6ec_Unk_0ce280(Unk0cd6ecWork *work, u32 value)
{
    Unk0a0ce4_Unk_0a0da4(5);
    work->saved_state = 4;
    work->state = 12;
    work->unk_0008 = value;
}

/* Refresh the borrowed handle and enter state 3 with a saved state of 1. */
void Unk0cd6ec_Unk_0ce2ac(Unk0cd6ecWork *work, u32 value)
{
    Unk122e1c_Unk_123294(work->handle);
    work->unk_00f0 = value;
    work->saved_state = 1;
    work->state = 3;
}

/* Release counted items and reset the handle and +0xf4 transition flag. */
void func_020ce2d8(Unk0cd6ecWork *work)
{
    int i;
    for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
        if (work->items[i] != 0) {
            func_020ffebc(work->items[i]);
            work->items[i] = 0;
        }
    }
    Unk0cb32c_Unk_0cb754(&work->handle);
    work->unk_00f4 = 0;
}

/* Callback tests +0xf4 but performs no work on either path, as at 020ce3e0. */
void func_020ce3e0(Unk0cd6ecWork *work)
{
    if (work->unk_00f4 == 0) return;
}

/* Empty callback slot, evidenced by the sole return at 020ce3ec. */
void Unk0cd6ec_Nop_0ce3ec(void) { }

/* Map the two helper predicates to handle slots 1/2 and their union to slot 0. */
void func_020ce500(Unk0cd6ecWork *work)
{
    int a = 0;
    int b = 0;
    if (func_021072c0() != 0) a = 1;
    if (func_02107374() != 0) b = 1;
    Unk122e1c_Unk_122fa0(work->handle, 1, a);
    Unk122e1c_Unk_122fa0(work->handle, 2, b);
    if (a == 0 && b == 0) {
        Unk122e1c_Unk_122fa0(work->handle, 0, 0);
    } else {
        Unk122e1c_Unk_122fa0(work->handle, 0, 1);
    }
}

extern void func_020cb78c(void **handle, int value);
extern void *func_020ffd48(u16 id, int index, int count);
extern void func_0212351c(void *handle, u32 value, int mode);
extern void Unk1241ec_Unk_124224(u16 value);
extern int Unk0bc1a8_IsSlotEmpty(int slot);
extern void Unk1241ec_Unk_1242e4(int value);
extern void Unk1241ec_Unk_124284(int value);
extern void Unk1241ec_Unk_12429c(int value);
extern void Unk1241ec_Unk_1242cc(int value);
extern void Unk124c5c_Set_124d8c(int value, int kind);
extern int Unk124c5c_IsKind0(void);
extern void func_02124ce8(int value);
extern void Unk0fc584_SetDir(int value);
extern void func_0212312c(void *handle, int a, int b);
extern void Unk124c5c_Set_124d6c(int a, int b);
extern int Unk124c5c_IsKind31(void);
extern int Unk122e1c_Unk_122f68(void *handle);
extern int func_020523a8(void);
extern void Unk0bc1a8_Unk_0bc928(int slot, int kind, int value);
extern int Unk0bc1a8_IsSlotEmptyOrFlag8(int slot);

/* Rebuild counted items from the 26-byte records, then restore handle selection.
 * Evidence: 020ce33c reads IDs at +0x2a + 26*i and stores created items at +0xc. */
void func_020ce33c(Unk0cd6ecWork *work)
{
    int count, i;
    func_020cb78c(&work->handle, work->entries[0].flag);
    count = Unk0de678_CountLeading(work->records);
    for (i = 0; i < count; i++) {
        if (work->entries[0].id == 604)
            work->items[i] = func_020ffd48(work->entries[i].id, i - 1, count - 1);
        else
            work->items[i] = func_020ffd48(work->entries[i].id, i, count);
    }
    func_0212351c(work->handle, work->unk_00e8, 1);
    Unk1241ec_Unk_124224((u16)work->selection);
    work->unk_00f4 = 1;
}

/* Advance the three-step transition through slot 19 and restore state 4.
 * Evidence: 020cdd14 polls slot 19 before changing the +1 substate. */
void func_020cdd14(Unk0cd6ecWork *work)
{
    switch (work->substate) {
    case 0:
        if (Unk0bc1a8_IsSlotEmpty(19)) work->substate++;
        break;
    case 1:
        Unk1241ec_Unk_1242e4(1);
        Unk1241ec_Unk_124284(1);
        Unk1241ec_Unk_12429c(1);
        Unk1241ec_Unk_1242cc(0);
        Unk124c5c_Set_124d8c(0, 31);
        work->substate++;
        break;
    case 2:
        if (Unk124c5c_IsKind0()) {
            work->substate = 0;
            Unk1241ec_Unk_124224((u16)work->selection);
            func_02124ce8(1);
            work->state = 4;
        }
        break;
    }
}

/* Sequence handle readiness, helper modes and slot 19 before entering state 5.
 * Evidence: the five substate cases and +0xc0 selection use at 020cdbe0. */
void func_020cdbe0(Unk0cd6ecWork *work)
{
    switch (work->substate) {
    case 0:
        Unk0fc584_SetDir(1);
        func_0212312c(work->handle, 0, 0);
        Unk124c5c_Set_124d6c(0, 1);
        Unk124c5c_Set_124d8c(1, 0);
        work->substate++;
        break;
    case 1:
        if (Unk124c5c_IsKind31() && Unk122e1c_Unk_122f68(work->handle)) work->substate++;
        break;
    case 2:
        Unk1241ec_Unk_124284(0);
        Unk1241ec_Unk_12429c(0);
        Unk1241ec_Unk_1242e4(0);
        Unk1241ec_Unk_1242cc(1);
        func_02124ce8(3);
        work->substate++;
        break;
    case 3:
        if (func_020523a8() != 1) {
            Unk0bc1a8_Unk_0bc928(19, 18, 0);
            work->substate++;
        }
        break;
    case 4:
        if (Unk0bc1a8_IsSlotEmptyOrFlag8(19)) {
            Unk1241ec_Unk_124224((u16)(work->selection_00c0 + 10));
            work->substate = 0;
            work->state = 5;
        }
        break;
    }
}

/* Borrowed event payload: bit n validates word n, as observed at 020ce448. */
typedef struct Unk0cd6ecPayload {
    u8 flags[2];
    u8 pad_0002[2];
    u32 values[16];
} Unk0cd6ecPayload;

/* Borrowed message prefix; the payload immediately follows the event kind. */
typedef struct Unk0cd6ecMessage {
    u32 kind;
    Unk0cd6ecPayload payload;
} Unk0cd6ecMessage;

/* Extract the fourth word only when the sender marks it present. */
static inline void ReadFourth(Unk0cd6ecPayload *payload, u32 *value)
{
    if (payload != 0) {
        u32 word = payload->values[3];
        if (payload->flags[0] & 8) *value = word;
    }
}

extern void Unk0de678_Unk_0dec94(void *record);
extern void CaveNpc_SetActive(void *item, int active);
extern void Unk124c5c_Unk_124cb0(void);
extern void Unk122e1c_Unk_123048(void *handle);
extern void Unk0bc1a8_Unk_0bc504(Unk0cd6ecWork *work, int value);

/* Handle message kinds 1 and 3; kind 3 selects a record or exits on index 100.
 * Evidence: 020ce3f0 dispatch table and the explicit index-100 branch. */
void func_020ce3f0(Unk0cd6ecWork *work, Unk0cd6ecMessage *message)
{
    Unk0cd6ecPayload *payload = &message->payload;
    switch (message->kind) {
    case 0: break;
    case 2: break;
    case 3: {
        u32 index[1] = {0};
        int i;
        if (work->state != 6) return;
        ReadFourth(payload, index);
        if (index[0] != 100) {
            void *record = work->entries[index[0]].pad_0004;
            work->unk_00ec = index[0];
            Unk0de678_Unk_0dec94(record);
            work->saved_state = 6;
            work->state = 8;
        } else {
            for (i = 0; i < Unk0de678_CountLeading(work->records); i++)
                CaveNpc_SetActive(work->items[i], 0);
            Unk124c5c_Unk_124cb0();
            Unk122e1c_Unk_123048(work->handle);
            work->saved_state = 4;
            work->state = 2;
        }
        break;
    }
    case 4: break;
    case 1: Unk0bc1a8_Unk_0bc504(work, 0); break;
    }
}

/* Initialize only the presence bytes and value words, preserving padding. */
static inline void InitPayload(Unk0cd6ecPayload *payload)
{
    int i;
    if (payload == 0) return;
    for (i = 0; i < 2; i++) payload->flags[i] = 0;
    for (i = 0; i < 16; i++) payload->values[i] = 0;
}

/* Presence is read before the value write to preserve the observed alias order. */
static inline void SetPayload(Unk0cd6ecPayload *payload, int index, u32 value)
{
    u32 flags;
    if (payload == 0) return;
    flags = payload->flags[index >> 3];
    payload->values[index] = value;
    payload->flags[index >> 3] = flags | (1 << (index & 7));
}

/* Borrowed handle prefix exposes the slot table tested by 020ce158. */
typedef struct Unk0cd6ecHandle {
    u8 pad_0000[200];
    void *slots[1]; /* Variable extent is owned by the handle provider. */
} Unk0cd6ecHandle;

extern int func_020e807c(void);
extern int Unk0e651c_Unk_0e666c(int value);
extern int func_02053824(int port, int mask);
extern int func_02053800(int port, int mask);
extern void func_020bcc7c(void *control);
extern void func_020bccec(void *control);
extern void func_020bcfc4(void *control, int index);
extern void Unk124c5c_Unk_124cc4(void);
extern void Unk122e1c_Unk_122ff0(void *handle);
extern void func_020bcacc(int slot, Unk0cd6ecPayload *payload);
extern void Unk122e1c_Unk_12331c(void *handle);
extern void Unk122e1c_Unk_12306c(void *handle);

/* Dispatch input in states 4/5 to controls, transitions and slot-19 messages.
 * Evidence: 020cde1c tests input masks and the handle's +0xc8 slot table. */
void func_020cde1c(Unk0cd6ecWork *work)
{
    Unk0cd6ecPayload payload;
    switch (work->state) {
    case 4: {
        int action = func_020e807c();
        if (action >= 0) {
            switch (action) {
            case 0: Unk0cd6ec_Unk_0ce280(work, 2); break;
            case 1: Unk0cd6ec_Unk_0ce280(work, 0); break;
            case 2:
                if (Unk0e651c_Unk_0e666c(0x705)) Unk0cd6ec_Unk_0ce280(work, 1);
                break;
            case 3: break;
            }
        } else if (func_02053824(0, 64)) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bcc7c(work->control_0094);
            Unk1241ec_Unk_124224((u16)work->selection);
        } else if (func_02053824(0, 128)) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bccec(work->control_0094);
            Unk1241ec_Unk_124224((u16)work->selection);
        } else if (func_02053800(0, 1024)) {
            Unk0cd6ec_Unk_0ce280(work, 2);
        } else if (func_02053800(0, 2048)) {
            Unk0cd6ec_Unk_0ce280(work, 0);
        } else if (func_02053800(0, 1)) {
            switch (work->selection) {
            case 0:
                Unk0a0ce4_Unk_0a0da4(1);
                func_020ce500(work);
                work->state = 9;
                break;
            case 1:
                if (work->unk_00e8 == 0) {
                    Unk0a0ce4_Unk_0a0da4(4);
                } else if (work->unk_00e8 == 1) {
                    Unk0a0ce4_Unk_0a0da4(1);
                    Unk124c5c_Unk_124cc4();
                    Unk122e1c_Unk_122ff0(work->handle);
                    work->saved_state = 8;
                    work->state = 3;
                } else {
                    Unk0a0ce4_Unk_0a0da4(1);
                    Unk124c5c_Unk_124cc4();
                    Unk122e1c_Unk_122ff0(work->handle);
                    work->saved_state = 6;
                    work->state = 3;
                }
                break;
            case 2:
                Unk0a0ce4_Unk_0a0da4(1);
                Unk124c5c_Unk_124cc4();
                work->substate = 0;
                work->state = 13;
                break;
            }
        } else if (func_02053800(0, 2) && work->selection != 2) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bcfc4(work->control_0094, 2);
            Unk1241ec_Unk_124224((u16)work->selection);
        }
        break;
    }
    case 5:
        if (func_02053824(0, 64)) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bcc7c(work->control_00b0);
            Unk1241ec_Unk_124224((u16)(work->selection_00c0 + 10));
        } else if (func_02053824(0, 128)) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bccec(work->control_00b0);
            Unk1241ec_Unk_124224((u16)(work->selection_00c0 + 10));
        } else if (func_02053800(0, 1)) {
            work->unk_0004 = work->selection_00c0;
            if (((Unk0cd6ecHandle *)work->handle)->slots[work->unk_0004]) {
                Unk0a0ce4_Unk_0a0da4(1);
                InitPayload(&payload);
                SetPayload(&payload, 1, work->unk_0004);
                func_020bcacc(19, &payload);
                Unk122e1c_Unk_12331c(work->handle);
                work->state = 11;
            } else {
                Unk0a0ce4_Unk_0a0da4(4);
            }
        } else if (func_02053800(0, 2)) {
            Unk0a0ce4_Unk_0a0da4(2);
            InitPayload(&payload);
            SetPayload(&payload, 3, 1);
            func_020bcacc(19, &payload);
            Unk0fc584_SetDir(0);
            Unk122e1c_Unk_12306c(work->handle);
            work->state = 10;
        }
        break;
    }
}

/* The by-value helper receives 114 bytes beginning at state +0x20, aligned to
 * two bytes; its trailing selection word is a separate argument. */
typedef struct Unk0cd6ecRecordBlock {
    u16 words[57];
} Unk0cd6ecRecordBlock;

extern int ImageBg_IsMode1or2(void);
extern void Unk0fd268_SetDir(int value);
extern void func_02124c5c(void);
extern void func_020525cc(int value);
extern int func_02052728(void);
extern int func_020deb68(void);
extern void Unk122e1c_Unk_123024(void *handle);
extern void Unk02cad4_Unk_02cbdc(u32 value);
extern int Unk122e1c_Unk_122f54(void *handle);
extern int Unk0de678_Unk_0debf8(void);
extern void func_0205257c(int value);
extern void func_020deaa0(int kind, Unk0cd6ecRecordBlock records, u32 selection);
extern u32 func_020fa92c(u32 index);
extern int func_020fa9a0(void);
extern int func_020decd8(void);
extern void Unk0fc584_Unk_0fc84c(int value);
extern void Unk122e1c_Unk_12332c(void *handle);
extern int func_0212356c(void *handle, u8 *substate, void *control, int value);
extern u32 Unk0cb32c_Unk_0cb440(u32 value);
extern void Unk122e1c_SetUnkFields64_b0(void *handle, u32 a, u32 b);

/* Advance states 0..13 and synchronize handle selections after every step.
 * Evidence: 020cd778's state table, record-copy calls and +0xa4/+0xc0/+0xdc reads. */
void func_020cd778(Unk0cd6ecWork *work)
{
    switch (work->state) {
    case 0:
        if (work->substate == 0) {
            if (!ImageBg_IsMode1or2()) {
                Unk0fd268_SetDir(1);
                func_02124c5c();
                func_02124ce8(1);
                func_020525cc(0);
                work->substate++;
            }
        } else if (!func_02052728()) {
            if (func_020deb68()) {
                work->state = 7;
                work->saved_state = 2;
            } else {
                Unk122e1c_Unk_123024(work->handle);
                work->state = work->saved_state;
                work->saved_state = 4;
            }
            work->substate = 0;
        }
        break;
    case 1:
        if (!func_02052728()) Unk02cad4_Unk_02cbdc(work->unk_00f0);
        break;
    case 2:
        if (Unk122e1c_Unk_122f68(work->handle)) work->state = work->saved_state;
        break;
    case 3:
        if (Unk122e1c_Unk_122f54(work->handle)) {
            work->state = work->saved_state;
            if (work->saved_state == 1) {
                if (Unk0de678_Unk_0debf8()) work->state = 7;
                else func_0205257c(0);
            } else if (work->saved_state == 8) {
                Unk0de678_Unk_0dec94(work->entries[0].pad_0004);
                work->saved_state = 2;
            } else if (work->saved_state == 6) {
                func_020deaa0(18, *(Unk0cd6ecRecordBlock *)work->records, work->unk_00ec = 0);
            }
        }
        break;
    case 6:
        work->unk_00ec = func_020fa92c(work->unk_00ec);
        if (func_020fa9a0()) {
            int i;
            for (i = 0; i < Unk0de678_CountLeading(work->records); i++)
                CaveNpc_SetActive(work->items[i], 1);
        } else {
            int i;
            for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
                if (i == work->unk_00ec) CaveNpc_SetActive(work->items[i], 0);
                else CaveNpc_SetActive(work->items[i], 1);
            }
        }
        break;
    case 7:
        if (func_020decd8()) {
            if (work->saved_state == 2) {
                if (!func_020deb68()) {
                    Unk122e1c_Unk_123024(work->handle);
                    work->state = work->saved_state;
                    work->saved_state = 4;
                }
            } else if (!Unk0de678_Unk_0debf8()) {
                func_0205257c(0);
                work->state = work->saved_state;
            }
        }
        break;
    case 8:
        if (func_020decd8()) {
            work->state = work->saved_state;
            if (work->saved_state == 6) {
                func_020deaa0(18, *(Unk0cd6ecRecordBlock *)work->records, work->unk_00ec);
            } else {
                Unk124c5c_Unk_124cb0();
                Unk122e1c_Unk_123048(work->handle);
                func_02124c5c();
                work->saved_state = 4;
            }
        }
        break;
    case 9: func_020cdbe0(work); break;
    case 10: func_020cdd14(work); break;
    case 11:
        if (work->substate == 0) work->substate++;
        else if (Unk0bc1a8_IsSlotEmptyOrFlag8(19)) {
            Unk0fc584_Unk_0fc84c(0);
            func_020ce500(work);
            Unk122e1c_Unk_12332c(work->handle);
            work->substate = 0;
            work->state = 5;
        }
        break;
    case 12: Unk0cd6ec_Unk_0cddd0(work, work->unk_0008); break;
    case 13:
        switch (func_0212356c(work->handle, &work->substate, work->control_00cc, 2)) {
        case 0:
            Unk124c5c_Unk_124cb0();
            Unk1241ec_Unk_124224((u16)work->selection);
            work->state = 4;
            break;
        case 1:
            Unk0cd6ec_Unk_0ce2ac(work, Unk0cb32c_Unk_0cb440(work->selection_00dc + 1));
            break;
        }
        break;
    }
    if (work->handle != 0) {
        u32 selection;
        if (work->state == 13) selection = work->selection_00dc;
        else selection = work->selection_00c0;
        Unk122e1c_SetUnkFields64_b0(work->handle, work->selection, selection);
    }
}
