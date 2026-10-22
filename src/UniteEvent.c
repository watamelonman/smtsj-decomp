/*
 * src/UniteEvent.c: demon fusion ("Unite") event handlers.
 *
 * Layouts come from matched field accesses in this TU. UniteEvent is also the object
 * reached through data_02176e48 (UniteEvent_CopyIds/SetId/SetCtxUnk32c write the same
 * object that UniteEvent_HandleMessage receives).
 */
#include "types.h"

/* One optional message argument: bit i of flags says values[i] is present. */
typedef struct EventParams {
    u8  flags;                  /* +0x00 presence bits */
    u8  pad_01[3];
    s32 values[5];              /* +0x04 argument values */
} EventParams;

/* Event message; handlers switch on type and read optional arguments from params. */
typedef struct EventMsg {
    u32         type;           /* +0x00 message id (0..4 used here) */
    EventParams params;         /* +0x04 */
} EventMsg;

/* Fusion event object (also *data_02176e48). */
typedef struct UniteEvent {
    s32 state;                  /* +0x000 event state (messages 0 and 3) */
    s32 mode;                   /* +0x004 fusion mode; 3 requests a skip */
    u32 unk_008, unk_00c, unk_010, unk_014;
    u32 handles_018[26];
    u32 handles_080[3];
    u32 unk_08c;
    u32 handles_090[2], handles_098[2], handles_0a0[9];
    u32 unk_0c4;
    u32 handles_0c8[9];
    u32 unk_0ec;
    u32 handles_0f0[9];
    s32 work_114[9], work_138[9], work_15c[9];
    u32 unk_180;
    float scales_184[9];
    s32 alpha_1a8[9];
    u32 unk_1cc;
    s32 work_1d0[4];
    u32 work_1e0[15], work_21c[15];
    u8 pad_258[4];
    s32 unk_025c;               /* +0x25C cleared by UniteEvent_SetState */
    s32 unk_260;
    s16 iconId;                 /* +0x264 message 0 argument 4 */
    u16 ids[12];                /* +0x266 ids copied by UniteEvent_CopyIds */
    u8  idCount;                /* +0x27E number of valid ids */
    u8  pad_27F[1];
    u16 id;                     /* +0x280 id stored by UniteEvent_SetId */
    u8 unk_282;
    u8 pad_283;
    u8 work_284[0x8c];
    u32 unk_310, unk_314, unk_318, unk_31c, unk_320, unk_324, unk_328;
    u32 unk_032c;               /* +0x32C set by UniteEvent_SetCtxUnk32c */
    u32 unk_0330;               /* +0x330 set to 1 by UniteEvent_SetId */
    u32 unk_0334;               /* +0x334 */
    s32 skipRequested;          /* +0x338 set by message 0 argument 3 == 3 */
    u32 work_33c[4];
    u32 unk_34c, unk_350;
} UniteEvent;

/* Descriptor filled by func_0210b98c; its address is the table entry at 0x021503E0. */
typedef struct UniteEventDescriptor {
    u32 unk_00;                 /* +0x00 set to 852 */
    u32 unk_04;                 /* +0x04 set to 3 */
    u32 unk_08;                 /* +0x08 not written here */
    void (*handler_0)(struct UniteEvent *, struct EventMsg *);  /* +0x0C */
    void (*handler_1)(struct UniteEvent *, struct EventMsg *);  /* +0x10 */
    void (*handler_2)(struct UniteEvent *, struct EventMsg *);  /* +0x14 */
    void (*handler_3)(struct UniteEvent *, struct EventMsg *);  /* +0x18 */
    void (*handler_4)(struct UniteEvent *, struct EventMsg *);  /* +0x1C */
    void (*handler_5)(struct UniteEvent *, struct EventMsg *);  /* +0x20 */
} UniteEventDescriptor;

/* Work slot passed to func_0210fa60 (event object +0x1E0 or +0x21C). */
typedef struct Unk10fa60Work {
    u32 unk_00;                 /* +0x00 loader result, forwarded to Unk06ae94_SetPair */
    u8  unk_04;                 /* +0x04 index passed to the loader and entry lookup */
    u8  pad_05[3];
    u8  unk_08[8];              /* +0x08 address passed as a loader stack argument */
    u8  pad_10[4];
    u32 unk_14;                 /* +0x14 zeroed before loading */
    u32 unk_18;                 /* +0x18 zeroed before loading */
    u32 unk_1c;                 /* +0x1C zeroed before loading */
} Unk10fa60Work;

/* Entry returned by func_02044618; two optional pairs start at +0x10. */
typedef struct Unk10fa60Entry {
    u8  pad_00[0x10];
    u16 unk_10;                 /* +0x10 first pair id (0 = absent) */
    u16 unk_12;                 /* +0x12 first pair value */
    u16 unk_14;                 /* +0x14 second pair id (0 = absent) */
    u16 unk_16;                 /* +0x16 second pair value */
} Unk10fa60Entry;

/* Effect destination: only the id byte at +4 is written here. */
typedef struct Unk0f9f4Target {
    u8 pad_00[4];
    u8 unk_04;                  /* +0x04 effect id */
} Unk0f9f4Target;

extern UniteEvent *data_02176e48;
extern u8 data_02151418[];      /* "Data/Effect/%s" */
extern u8 data_02151428[];      /* "Data/Effect/%s" */

void func_0210bc2c(UniteEvent *ev, EventMsg *msg);
void func_0210e064(UniteEvent *ev, EventMsg *msg);
void func_0210e324(UniteEvent *ev, EventMsg *msg);
void func_0210e944(UniteEvent *ev, EventMsg *msg);
void func_0210f6cc(UniteEvent *ev, EventMsg *msg);
void UniteEvent_HandleMessage(UniteEvent *ev, EventMsg *msg);
void UniteEvent_SetState(UniteEvent *ev, s32 state);

void func_0200866c(u32 src, void *dst, int size);
void func_0205257c(int a);
void func_0205e590(int a);
void func_0206df10(void);
void func_02013c3c(void *dst, u8 *format, u32 arg);
u8 func_0206f6e4(void *buf);
void Unk071dc0_Unk_072200(void);
void Unk071dc0_Unk_071fcc(void);

u32 Unk06ae94_Call_06c130(u32 a, u32 b, u32 c, u32 d, u32 e, void *f, u32 g, u32 h);
u8 *Unk06dddc_Unk_06e0c4(u32 a);
Unk10fa60Entry *func_02044618(u8 *key);
void Unk06ae94_SetPair(void *pairs, u32 a, u32 b, int i);

/* Reads optional message argument `index`; flags bit `index` gates the value. */
static inline int GetEventParam(const EventParams *p, int index, s32 *out)
{
    if (p == 0) {
        return 0;
    }
    {
        s32 v = p->values[index];
        if (p->flags & (1 << index)) {
            *out = v;
            return 1;
        }
    }
    return 0;
}

/*
 * Fills the UniteEvent descriptor passed in: two constants (+0x00 = 852, +0x04 = 3)
 * followed by six handler pointers at +0x0C..+0x20. The load relocation at
 * 0x021503E0 references this function, so it initialises a table entry.
 */
void func_0210b98c(UniteEventDescriptor *desc)
{
    desc->unk_00 = 852;
    desc->unk_04 = 3;
    desc->handler_0 = func_0210bc2c;
    desc->handler_1 = func_0210e064;
    desc->handler_2 = func_0210e324;
    desc->handler_3 = func_0210e944;
    desc->handler_4 = func_0210f6cc;
    desc->handler_5 = UniteEvent_HandleMessage;
}

/*
 * Message handler of the fusion ("Unite") event. Message 0 starts the event and
 * takes mode (argument 3) and icon (argument 4); message 3 advances state 18 to 19
 * when argument 0 is 7.
 */
void UniteEvent_HandleMessage(UniteEvent *ev, EventMsg *msg)
{
    EventParams *p = &msg->params;
    s32 value;

    switch (msg->type) {
    case 0:
        UniteEvent_SetState(ev, 1);
        if (GetEventParam(p, 3, &value)) {
            ev->mode = value;
            if (value == 3) {
                ev->skipRequested = 1;
                ev->mode = 0;
            }
        }
        if (GetEventParam(p, 4, &value)) {
            ev->iconId = value;
        }
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        if (GetEventParam(p, 0, &value) && value == 7 && ev->state == 18) {
            func_0205257c(0);
            UniteEvent_SetState(ev, 19);
            func_0205e590(0);
        }
        break;
    case 4:
        break;
    }
}

/* Copies n 16-bit ids to the event and records their count. */
void UniteEvent_CopyIds(u32 src, int n)
{
    if (data_02176e48 == 0) {
        return;
    }
    func_0200866c(src, data_02176e48->ids, n * 2);
    data_02176e48->idCount = n;
}

/* Stores one 16-bit id and marks it valid. */
void UniteEvent_SetId(u32 id)
{
    if (data_02176e48 == 0) {
        return;
    }
    data_02176e48->unk_0330 = 1;
    data_02176e48->id = id;
}

/* Marks the event context's +0x32C flag. */
void UniteEvent_SetCtxUnk32c(void)
{
    if (data_02176e48 != 0) {
        data_02176e48->unk_032c = 1;
    }
}

/*
 * Loads the two effect ids selected by `medium` and `effect` into the destination
 * bytes at +4. Both format strings are "Data/Effect/%s".
 */
void UniteEvent_LoadEffects(Unk0f9f4Target *first, u32 medium, Unk0f9f4Target *second, u32 effect)
{
    u8 tmp;
    u8 buf[128];

    func_0206df10();
    Unk071dc0_Unk_072200();
    func_02013c3c(buf, data_02151418, medium);
    tmp = func_0206f6e4(buf);
    first->unk_04 = tmp;
    func_02013c3c(buf, data_02151428, effect);
    tmp = func_0206f6e4(buf);
    second->unk_04 = tmp;
    Unk071dc0_Unk_071fcc();
}

/*
 * Loads the resource for one fusion-effect work slot and applies up to two pairs
 * from the looked-up entry. The state machine in func_0210bc2c calls this with the
 * slots at UniteEvent+0x1E0 and +0x21C (call sites 0x0210D1A4, 0x0210D654,
 * 0x0210DA58). Always reports success.
 */
u32 func_0210fa60(Unk10fa60Work *work)
{
    Unk10fa60Entry *entry;

    work->unk_14 = 0;
    work->unk_18 = 0;
    work->unk_1c = 0;
    work->unk_00 = Unk06ae94_Call_06c130(work->unk_04, work->unk_14, work->unk_18,
                                         work->unk_1c, 0x3F800000, work->unk_08, 0, 5);
    entry = func_02044618(Unk06dddc_Unk_06e0c4(work->unk_04));
    if (entry != 0) {
        if (entry->unk_10 != 0) {
            Unk06ae94_SetPair((void *)work->unk_00, entry->unk_10, entry->unk_12, 0);
        }
        if (entry->unk_14 != 0) {
            Unk06ae94_SetPair((void *)work->unk_00, entry->unk_14, entry->unk_16, 1);
        }
    }
    return 1;
}

/* Clears the event state and the +0x25C progress field. */
void UniteEvent_SetState(UniteEvent *ev, s32 state)
{
    ev->state = state;
    ev->unk_025c = 0;
}

void func_02008644(u32 value, void *dst, int size);
void func_020086a0(u32 value, void *dst, int size);
void func_02008848(void *dst, u32 value, int size);
void Unk06e4d8_Unk_06e538(void);
void func_0206eab4(void);
void func_02093a1c(void);
void Unk044394_Unk_044428(int kind);
void Unk0a0ce4_Unk_0a0d30(int kind);

/* Initialises the event and its work slots; stores the owner at data_02176e48.
 * Evidence: stores at 0x0210BAF8..0x0210BC24 and the descriptor's owner size 852.
 */
void func_0210baf8(UniteEvent *ev)
{
    int i;
    data_02176e48 = ev;
    ev->unk_025c = 0;
    ev->state = 0;
    ev->mode = 0;
    ev->iconId = 0;
    func_02008644(0, ev->ids, 24);
    ev->id = 0;
    func_020086a0(0, ev->work_33c, 16);
    ev->work_33c[2] = 0x40000;
    ev->unk_34c = 0;
    ev->idCount = 0;
    ev->unk_282 = 0;
    ev->unk_260 = 0;
    ev->unk_324 = 0;
    ev->unk_032c = 0;
    ev->unk_0330 = 0;
    ev->unk_0334 = 0;
    ev->unk_310 = 0;
    ev->unk_350 = 0;
    ev->skipRequested = 0;
    ev->unk_320 = 0;
    func_02008848(ev->work_1e0, 0, 60);
    func_02008848(ev->work_21c, 0, 60);
    func_020086a0(0, ev->work_114, 36);
    func_020086a0(0, ev->work_138, 36);
    func_020086a0(0, ev->work_15c, 36);
    ev->unk_180 = 0x40000;
    ev->unk_1cc = 0;
    func_020086a0(0, ev->work_1d0, 16);
    for (i = 0; i < 9; i++) {
        ev->handles_0f0[i] = 0;
    }
    Unk06e4d8_Unk_06e538();
    func_0206eab4();
    func_02093a1c();
    Unk044394_Unk_044428(3);
    Unk0a0ce4_Unk_0a0d30(3);
}

/* Writes up to nine fixed-point coordinate pairs for a count in 0..9.
 * Evidence: 0x0210FB04 clears two 36-byte arrays, selects constants by count,
 * then adds the (16,8) origin and converts positive entries to 20.12 units.
 * Callers supply room for nine signed words in each output array.
 */
void func_0210fb04(u8 count, int extra, s32 *x, s32 *y)
{
    int i;
    func_020086a0(0, x, 36);
    func_020086a0(0, y, 36);
    if (extra != 0) count++;
    switch (count) {
    case 0:
    case 1:
        break;
    case 2:
        x[0] = 49; y[0] = 88;
        x[1] = 175; y[1] = 88;
        break;
    case 3:
        x[0] = 57; y[0] = 57;
        x[1] = 167; y[1] = 57;
        x[2] = 112; y[2] = 151;
        break;
    case 4:
        x[0] = 49; y[0] = 88;
        x[1] = 112; y[1] = 25;
        x[2] = 175; y[2] = 88;
        x[3] = 112; y[3] = 151;
        break;
    case 5:
        x[0] = 52; y[0] = 107;
        x[1] = 75; y[1] = 37;
        x[2] = 149; y[2] = 37;
        x[3] = 172; y[3] = 107;
        x[4] = 112; y[4] = 151;
        break;
    case 6:
        x[0] = 57; y[0] = 119;
        x[1] = 57; y[1] = 57;
        x[2] = 112; y[2] = 25;
        x[3] = 167; y[3] = 57;
        x[4] = 167; y[4] = 119;
        x[5] = 112; y[5] = 151;
        break;
    case 7:
        x[0] = 63; y[0] = 127;
        x[1] = 51; y[1] = 74;
        x[2] = 85; y[2] = 31;
        x[3] = 139; y[3] = 31;
        x[4] = 173; y[4] = 74;
        x[5] = 161; y[5] = 127;
        x[6] = 112; y[6] = 151;
        break;
    case 8:
        x[0] = 67; y[0] = 133;
        x[1] = 49; y[1] = 88;
        x[2] = 67; y[2] = 43;
        x[3] = 112; y[3] = 25;
        x[4] = 157; y[4] = 43;
        x[5] = 175; y[5] = 88;
        x[6] = 157; y[6] = 133;
        x[7] = 112; y[7] = 151;
        break;
    case 9:
        x[0] = 71; y[0] = 136;
        x[1] = 50; y[1] = 99;
        x[2] = 57; y[2] = 56;
        x[3] = 90; y[3] = 29;
        x[4] = 134; y[4] = 29;
        x[5] = 167; y[5] = 56;
        x[6] = 174; y[6] = 99;
        x[7] = 153; y[7] = 136;
        x[8] = 112; y[8] = 151;
        break;
    }
    for (i = 0; i < 9; i++) {
        if (x[i] > 0) x[i] = (x[i] + 16) << 12;
        if (y[i] > 0) y[i] = (y[i] + 8) << 12;
    }
}

void Unk044394_Unk_044534(int kind);
void func_02061424(u32 handle);
void func_0205bb68(void);
void Unk0a163c_Unk_0a1ae0(void *work);
void func_0205ddb4(u32 handle);
void func_0205c368(u32 handle);
void Unk06ea70_Unk_06eb54(void);
void Unk06e4d8_Unk_06e680(void);
void Unk0939f0_Unk_093da4(void);

/* Releases the event's resource groups and clears the global owner.
 * Evidence: descriptor callback 4 and calls at 0x0210F6CC..0x0210F95C.
 * The message argument belongs to the shared callback ABI and is unused here.
 */
void func_0210f6cc(UniteEvent *ev, EventMsg *msg)
{
    int i;
    Unk044394_Unk_044534(3);
    for (i = 0; i <= 25; i++) {
        func_02061424(ev->handles_018[i]);
        ev->handles_018[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        func_02061424(ev->handles_080[i]);
        ev->handles_080[i] = 0;
    }
    func_02061424(ev->unk_08c);
    ev->unk_08c = 0;
    for (i = 0; i < 2; i++) {
        func_02061424(ev->handles_090[i]);
        ev->handles_090[i] = 0;
    }
    for (i = 0; i < 2; i++) {
        func_02061424(ev->handles_098[i]);
        ev->handles_098[i] = 0;
    }
    for (i = 0; i < 9; i++) {
        func_02061424(ev->handles_0a0[i]);
        ev->handles_0a0[i] = 0;
    }
    func_02061424(ev->unk_0c4);
    ev->unk_0c4 = 0;
    for (i = 0; i < 9; i++) {
        func_02061424(ev->handles_0c8[i]);
        ev->handles_0c8[i] = 0;
    }
    func_02061424(ev->unk_0ec);
    ev->unk_0ec = 0;
    for (i = 0; i < ev->idCount; i++) {
        if (ev->handles_0f0[i] != 0) {
            func_0205bb68();
            ev->handles_0f0[i] = 0;
        }
    }
    if (ev->handles_0f0[ev->idCount] != 0) {
        func_0205bb68();
        ev->handles_0f0[ev->idCount] = 0;
    }
    func_02061424(ev->unk_310);
    Unk0a163c_Unk_0a1ae0(ev->work_284);
    ev->unk_310 = 0;
    if (ev->unk_008 != 0) {
        func_0205ddb4(ev->unk_008);
        ev->unk_008 = 0;
    }
    if (ev->unk_00c != 0) {
        func_0205c368(ev->unk_00c);
        ev->unk_00c = 0;
    }
    if (ev->unk_010 != 0) {
        func_0205ddb4(ev->unk_010);
        ev->unk_010 = 0;
    }
    if (ev->unk_014 != 0) {
        func_0205c368(ev->unk_014);
        ev->unk_014 = 0;
    }
    if (ev->unk_314 != 0) {
        func_0205ddb4(ev->unk_314);
        ev->unk_314 = 0;
    }
    if (ev->unk_318 != 0) {
        func_0205c368(ev->unk_318);
        ev->unk_318 = 0;
    }
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_02061424(ev->work_1e0[0]);
    ev->work_1e0[0] = 0;
    func_02061424(ev->work_21c[0]);
    ev->work_21c[0] = 0;
    Unk06ea70_Unk_06eb54();
    func_0206df10();
    Unk071dc0_Unk_072200();
    Unk06e4d8_Unk_06e680();
    Unk0939f0_Unk_093da4();
    Unk044394_Unk_044534(40);
    data_02176e48 = 0;
}

int func_02053800(int port, int mask);
void func_02053000(u32 handle);
int Unk06ae94_GetUnkField4c(u32 handle);
void Unk06ae94_Unk_06c76c(u32 handle);
void func_0205c408(u32 handle, int value);
void func_0205cac0(u32 handle);
void Unk065e88_SetFlag3a(u32 handle, int value);
void func_0205c6f8(u32 handle);
void func_0205c6e0(u32 handle);
void func_0205e764(u32 handle, int value);

/* Handles an input-triggered transition from states 3..13 to state 14.
 * Evidence: input masks 1/2 and state range tests at 0x0210E064..0x0210E0F8;
 * the remaining calls reset active effects and restore the retained UI groups.
 */
void func_0210e064(UniteEvent *ev, EventMsg *msg)
{
    int i;
    if (!func_02053800(0, 1) && !func_02053800(0, 2)) return;
    if (ev->skipRequested) return;
    if (ev->state <= 2 || ev->state >= 14) return;
    ev->unk_282 = ev->idCount;
    if (ev->unk_0330) ev->unk_282++;
    UniteEvent_SetState(ev, 14);
    if (ev->unk_310) {
        func_02061424(ev->unk_310);
        ev->unk_310 = 0;
        if (ev->unk_0334) {
            func_0205bb68();
            func_02053000(ev->unk_320);
            ev->unk_320 = 0;
        } else {
            Unk0a163c_Unk_0a1ae0(ev->work_284);
        }
    }
    if (ev->work_1e0[0] && !Unk06ae94_GetUnkField4c(ev->work_1e0[0])) {
        Unk06ae94_Unk_06c76c(ev->work_1e0[0]);
        func_02061424(ev->work_1e0[0]);
        ev->work_1e0[0] = 0;
    }
    if (ev->work_21c[0] && !Unk06ae94_GetUnkField4c(ev->work_21c[0])) {
        Unk06ae94_Unk_06c76c(ev->work_21c[0]);
        func_02061424(ev->work_21c[0]);
        ev->work_21c[0] = 0;
    }
    func_0205c408(*(u32 *)ev->unk_08c, 1);
    func_0205cac0(*(u32 *)ev->unk_08c);
    Unk065e88_SetFlag3a(ev->unk_08c, 1);
    for (i = 0; i < 2; i++) {
        Unk065e88_SetFlag3a(ev->handles_090[i], 0);
        func_0205c6f8(*(u32 *)ev->handles_090[i]);
    }
    for (i = 0; i < 9; i++) {
        Unk065e88_SetFlag3a(ev->handles_0a0[i], 0);
        func_0205c6f8(*(u32 *)ev->handles_0a0[i]);
        Unk065e88_SetFlag3a(ev->handles_0c8[i], 0);
        func_0205c6f8(*(u32 *)ev->handles_0c8[i]);
    }
    Unk065e88_SetFlag3a(ev->unk_0c4, 0);
    func_0205c6f8(*(u32 *)ev->unk_0c4);
    Unk065e88_SetFlag3a(ev->handles_018[4], 0);
    func_0205c6f8(*(u32 *)ev->handles_018[4]);
    Unk065e88_SetFlag3a(ev->handles_018[5], 0);
    func_0205c6f8(*(u32 *)ev->handles_018[5]);
    Unk065e88_SetFlag3a(ev->handles_018[6], 0);
    func_0205c6f8(*(u32 *)ev->handles_018[6]);
    Unk065e88_SetFlag3a(ev->handles_018[2], 0);
    func_0205c6f8(*(u32 *)ev->handles_018[2]);
    for (i = 0; i < 3; i++) {
        func_0205c408(*(u32 *)ev->handles_080[i], 24);
        func_0205c6e0(*(u32 *)ev->handles_080[i]);
        Unk065e88_SetFlag3a(ev->handles_080[i], 1);
    }
    if (ev->unk_0330 || ev->unk_0334) {
        ev->unk_0330 = 0;
        ev->unk_0334 = 0;
    }
    func_0205e764(ev->unk_350, 0);
}

/* Mutable clipping rectangle returned by resource lookup, in pixels. */
typedef struct UniteClip {
    u16 x, y, width, height;
} UniteClip;

/* Resource frame copied by draw callbacks; its rectangle uses signed pixels. */
typedef struct UniteFrame {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
    s16 x, y;
    s16 width;
    s16 height;
    u32 unk_10, unk_14;
} UniteFrame;
/* Draw resource offsets read by func_0210e324. */
typedef struct UniteDrawBase {
    u8 pad_00[0x14];
    s32 x, y;
} UniteDrawBase;
/* UI handle view: base-relative position and visibility byte. */
typedef struct UniteDrawHandle {
    UniteDrawBase *base;
    u8 pad_04[8];
    s32 x, y;
    u8 pad_14[0x26];
    u8 visible;
} UniteDrawHandle;
void func_02057524(int layer);
void func_02057fd8(void);
void func_02057df8(void);
void func_02057e18(u8 alpha);
void func_02057ddc(u32 color);
void func_02057534(void);
void func_0205dee8(int layer, u32 handle, int frame, int x, int y,
                   float sx, float sy, int angle, float scale, int flags);
UniteFrame *func_0205e318(u32 handle, int frame);
void func_02008904(const void *src, void *dst, int size);
UniteClip *func_0205e328(u32 handle, u32 a, u32 b);
void func_0205e048(int layer, u32 handle, UniteFrame *frame, int x, int y,
                  float sx, float sy, int angle, float scale, int flags, int extra);
void func_02057d54(u32 color, int x, int y, int width, int height, int flags);
void func_02058d04(u32 handle, int kind, int x, int y, float scale,
                  int angle, int flags, int extra);

/* Draws state-dependent fusion effects and the nine retained id slots.
 * Evidence: state switch and draw submissions at 0x0210E324..0x0210E940;
 * positions use 20.12 units; draw opacity is narrowed to a byte at submission.
 */
void func_0210e324(UniteEvent *ev, EventMsg *msg)
{
    UniteFrame frame, overlay;
    UniteClip *original;
    int y;
    int i, index;
    u16 alpha;
    u8 fade;
    if (ev->state == 1) return;
    func_02057524(0);
    func_02057fd8();
    switch (ev->state) {
    case 0: case 1: case 2: case 3: case 4:
    case 6: case 7: case 8: case 10: case 12: case 13:
        break;
    case 5:
        func_02057524(2);
        func_0205dee8(1, ev->unk_010, 2, 0, 0, 1.0f, 1.0f, 0, 1.0f, 4);
        func_02057e18(31);
        break;
    case 9:
        func_02057524(2);
        func_02057fd8();
        func_02057df8();
        if (ev->unk_025c < 102) {
            if (ev->unk_025c >= 90) alpha = 23;
            else alpha = (ev->unk_025c * 0x416) >> 12;
            index = (ev->unk_025c / 4) % 6;
            func_02008904(func_0205e318(ev->unk_010, index + 66), &frame, 24);
            original = func_0205e328(ev->unk_010, frame.unk_00,
                                    ((u32 *)&frame)[1]);
            original->width = alpha;
            frame.width = alpha;
            func_0205e048(2, ev->unk_010, &frame, 0, (ev->unk_282 - 1) * 19,
                          1.0f, 1.0f, 0, 1.0f, 8, 0);
            original->width = 23;
        }
        break;
    case 11:
        func_02057524(6);
        func_02057fd8();
        func_02057df8();
        if (ev->unk_025c >= 0 && ev->unk_025c < 60) {
            if (ev->unk_025c < 30) fade = ev->unk_025c * 31 / 30;
            else fade = (60 - ev->unk_025c) * 31 / 30;
            func_02057e18(fade);
            func_02057d54(-1, 0, 0, 256, 192, 21);
            func_02057e18(31);
        }
        break;
    case 14:
        func_02057524(6);
        func_02057fd8();
        func_02057df8();
        if (ev->unk_032c) {
            if (ev->unk_025c >= 0 && ev->unk_025c < 90) {
                fade = 1;
                if (ev->unk_025c < 30) fade += (u8)((30-ev->unk_025c)*30/30);
                else if (ev->unk_025c < 60) fade += (u8)((60-ev->unk_025c)*30/30);
                else if (ev->unk_025c < 90) fade += (u8)((90-ev->unk_025c)*30/30);
                func_02057e18(fade);
                func_02057d54(0xbd1821ff, 0, 0, 256, 192, 21);
                func_02057e18(31);
            }
        } else if (ev->unk_025c >= 0 && ev->unk_025c < 30) {
            func_02057e18((u8)((30-ev->unk_025c)*31/30));
            func_02057d54(-1, 0, 0, 256, 192, 21);
            func_02057e18(31);
        }
        break;
    }
    if (ev->state == 9 || ev->state == 10 || ev->state == 11 ||
        (ev->state == 7 && ev->unk_282 != 0) ||
        (ev->state == 6 && ev->unk_282 != 0)) {
        func_02057524(2);
        func_02057fd8();
        func_02057ddc(0x182952ff);
        func_02057e18(31);
        for (i = 0; i < 4; i++) {
            y = (ev->work_1d0[i] >> 12) - 64;
            if (y >= -64 && y < 192) {
                func_02008904(func_0205e318(ev->unk_010, 8), &overlay, 24);
                func_0205e048(2, ev->unk_010, &overlay, ev->unk_1cc, y-128,
                              1.0f, 1.0f, 0, 1.0f, 8, 0);
            }
        }
        func_02057df8();
    }
    if ((ev->state == 11 && ev->unk_025c < 30) || ev->state <= 10) {
        func_02057524(2);
        func_02057fd8();
        func_02057df8();
        func_02057e18(31);
        for (i = 0; i < 9; i++) {
            if (((UniteDrawHandle *)ev->handles_0a0[i])->visible && ev->alpha_1a8[i] > 0) {
                UniteDrawHandle *h;
                func_02057e18((u8)(ev->alpha_1a8[i] >> 12));
                h = (UniteDrawHandle *)ev->handles_0a0[i];
                func_02058d04(ev->handles_0f0[i], 0, h->x + 2 + h->base->x,
                              h->y + 21 + h->base->y, 1.0f, 0, 10, 0);
            }
        }
        func_02057e18(31);
    } else if (ev->state == 12 || ev->state == 13) {
        func_02057524(2);
        func_02057fd8();
        func_02057df8();
        for (i = 0; i < ev->unk_282; i++) {
            func_02057e18((u8)(ev->alpha_1a8[i] >> 12));
            func_02058d04(ev->handles_0f0[i], 0, (ev->work_114[i] >> 12)-16,
                          (ev->work_138[i] >> 12)-8, ev->scales_184[i], 0, 10, 0);
        }
        func_02057e18(31);
    }
    func_02057534();
}

int func_0205ca48(u32 handle);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);

/* Submits the background and clipped overlays selected by the fusion state.
 * Evidence: frame ids, rectangle writes and color ramps at 0x0210E944..0x0210F6C8.
 * Frame copies are local because clipping changes each submitted rectangle.
 */
void func_0210e944(UniteEvent *ev, EventMsg *msg)
{
    UniteFrame f0, f1, f2, f3, f4, f5, f6, f7, f8, f9;
    UniteFrame *source;
    UniteClip *clip;
    int y;
    u32 color;
    u8 fade;
    if (ev->state == 1) return;
    func_02057524(6);
    func_02057fd8();
    func_02057df8();
    func_0205dee8(1, ev->unk_008, 38, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    func_0205dee8(1, ev->unk_008, 16, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    func_0205dee8(1, ev->unk_008, 18, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    func_0205dee8(1, ev->unk_008, 20, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    func_0205dee8(1, ev->unk_008, 24, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    func_0205dee8(1, ev->unk_008, 27, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    if (!func_0205ca48(*(u32 *)ev->handles_018[0]))
        func_0205dee8(1, ev->unk_008, 0, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    if (!func_0205ca48(*(u32 *)ev->handles_018[1]))
        func_0205dee8(1, ev->unk_008, 11, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    if (ev->state < 7 && ev->unk_282 == 0) {
        func_02057ddc(0x484848ff);
    } else if (ev->state == 7 && ev->unk_282 == 0) {
        color = 0x484848ff;
        if (ev->unk_025c >= 2 && ev->unk_025c <= 10) {
            s16 r, g;
            r = 72;
            r += (ev->unk_025c - 2) * 23;
            if (r > 255) r = 255;
            g = 72;
            g -= (ev->unk_025c - 2) * 14;
            if (g < 0) g = 0;
            color = (r << 24) + (g << 16) + (g << 8) + 255;
        } else if (ev->unk_025c > 10) color = 0xff0000ff;
        func_02057ddc(color);
    } else if (ev->state >= 15) {
        color = 0xff0000ff;
        if (ev->state == 15) {
            if (ev->unk_025c >= ev->unk_260 + 68 && ev->unk_025c < ev->unk_260 + 80) {
                s16 r, g;
                r = 255 - (ev->unk_025c - 68) * 15;
                if (r < 72) r = 72;
                g = 0;
                g += (ev->unk_025c - 68) * 6;
                if (g > 72) g = 72;
                color = (r << 24) + (g << 16) + (g << 8) + 255;
            } else if (ev->unk_025c >= ev->unk_260 + 80) color = 0x484848ff;
        } else color = 0x484848ff;
        func_02057ddc(color);
    } else {
        func_02057ddc(0xff0000ff);
    }
    func_0205dee8(1, ev->unk_008, 33, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    func_02057524(4);
    func_02057fd8();
    func_02057df8();
    func_0205dee8(1, ev->unk_008, 30, 0, 0, 1.0f, 1.0f, 0, 1.0f, 18);
    func_02057524(6);
    if (ev->state >= 6 && ev->state <= 16) {
        source = func_0205e318(ev->unk_008, 0x121);
        func_02008904(source, &f0, 24);
        func_02008904(source, &f1, 24);
        clip = func_0205e328(ev->unk_008, f0.unk_00, ((u32 *)&f0)[1]);
        y = (s32)ev->work_33c[1] >> 12;
        clip->x = 0; clip->y = 0;
        if (y >= -128) {
            if (y >= -64) {
                clip->height = -y;
                f0.height = -y;
            } else {
                clip->y = -64-y;
                clip->height = 64-clip->y;
                if (clip->height > 64) clip->height = 64;
                f0.y += clip->y;
                f0.height = clip->height;
            }
            func_02057ddc(0x317bdeff);
            func_0205e048(1, ev->unk_008, &f0, 0, y, 1.0f, 1.0f, 0, 1.0f, 4, 0);
        }
    }
    if (ev->state >= 9 && ev->state <= 10) {
        func_02008904(func_0205e318(ev->unk_008, 0x13e), &f2, 24);
        clip = func_0205e328(ev->unk_008, f2.unk_00, ((u32 *)&f2)[1]);
        y = (s32)ev->work_33c[3] >> 12;
        clip->x = 0; clip->y = 0;
        if (y >= -6) {
            clip->height = -y;
            f2.height = -y;
        } else {
            clip->y = -6-y;
            clip->height = 45-clip->y;
            if (clip->height > 6) clip->height = 6;
            f2.y += clip->y;
            f2.height = clip->height;
        }
        if (clip->y < 45) {
            func_02057ddc(0x299ce7ff);
            func_0205e048(1, ev->unk_008, &f2, 0, y, 1.0f, 1.0f, 0, 1.0f, 4, 0);
        }
    }
    switch (ev->state) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 10: case 11: case 12: case 13:
        break;
    case 9:
        source = func_0205e318(ev->unk_008, 0x11a);
        func_02008904(source, &f3, 24);
        func_02008904(source, &f4, 24);
        clip = func_0205e328(ev->unk_008, f3.unk_00, ((u32 *)&f3)[1]);
        y = (s32)ev->work_33c[0] >> 12;
        clip->x = 0; clip->y = 0;
        if (y >= -88) {
            if (y >= -24) {
                clip->height = -y;
                f3.height = -y;
            } else {
                clip->y = -24-y;
                clip->height = 64-clip->y;
                if (clip->height > 24) clip->height = 24;
                f3.y += clip->y;
                f3.height = clip->height;
            }
            func_02057ddc(0x105294ff);
            func_0205e048(1, ev->unk_008, &f3, 0, y, 1.0f, 1.0f, 0, 1.0f, 4, 0);
        }
        clip->x = 0; clip->y = 0;
        if (y < -64) {
            if (y >= -88) {
                clip->height = -64-y;
                f4.height = -64-y;
            } else {
                clip->y = -88-y;
                clip->height = 40-clip->y;
                if (clip->height > 24) clip->height = 24;
                f4.y += clip->y;
                f4.height = clip->height;
            }
            func_02057ddc(0x105294ff);
            func_0205e048(1, ev->unk_008, &f4, 0, y+64, 1.0f, 1.0f, 0, 1.0f, 4, 0);
        }
        func_02057df8();
        func_02008904(func_0205e318(ev->unk_008, 0x15e), &f5, 24);
        y = (*(UniteDrawBase **)ev->handles_018[2])->y;
        f5.height = -y;
        color = ((11 + ((f5.height*0x1c2c)>>12))<<24) +
                ((26 - ((f5.height*0x2e6)>>12))<<16) +
                ((85 - ((f5.height*0x5e9)>>12))<<8) + 255;
        func_02057dcc(color, 0x0b1a55ff, 0x0b1a55ff, color);
        func_0205e048(1, ev->unk_008, &f5, 0, y+137, 1.0f, 1.0f, 0, 1.0f, 4, 0);
        func_02057df8();
        if (ev->unk_025c >= 30) {
            func_02057ddc(0x42fff7ff);
            func_0205dee8(1, ev->unk_008, 23, 0, 0, 1.0f, 1.0f, 0, 1.0f, 4);
        } else if (ev->unk_025c >= 0) {
            func_02057ddc(0xffff42ff);
            func_02008904(func_0205e318(ev->unk_008, 0x144), &f6, 24);
            y = (*(UniteDrawBase **)ev->handles_080[0])->x;
            f6.width = -y;
            func_0205e048(1, ev->unk_008, &f6, y+76, 0, 1.0f, 1.0f, 0, 1.0f, 10, 0);
        }
        if (ev->unk_025c >= 60) {
            func_02057ddc(0x42fff7ff);
            func_0205dee8(1, ev->unk_008, 23, 0, -11, 1.0f, 1.0f, 0, 1.0f, 4);
        } else if (ev->unk_025c >= 30) {
            func_02057ddc(0xffff42ff);
            func_02008904(func_0205e318(ev->unk_008, 0x144), &f7, 24);
            y = (*(UniteDrawBase **)ev->handles_080[1])->x;
            f7.width = -y;
            func_0205e048(1, ev->unk_008, &f7, y+76, -11, 1.0f, 1.0f, 0, 1.0f, 10, 0);
        }
        if (ev->unk_025c >= 90) {
            func_02057ddc(0x42fff7ff);
            func_0205dee8(1, ev->unk_008, 23, 0, -22, 1.0f, 1.0f, 0, 1.0f, 4);
        } else if (ev->unk_025c >= 60) {
            func_02057ddc(0xffff42ff);
            func_02008904(func_0205e318(ev->unk_008, 0x144), &f8, 24);
            y = (*(UniteDrawBase **)ev->handles_080[2])->x;
            f8.width = -y;
            func_0205e048(1, ev->unk_008, &f8, y+76, -22, 1.0f, 1.0f, 0, 1.0f, 10, 0);
        }
        func_02057df8();
        func_02057524(4);
        if (func_0205ca48(*(u32 *)ev->handles_018[4])) {
            func_02008904(func_0205e318(ev->unk_008, 0x16d), &f9, 24);
            y = (*(UniteDrawBase **)ev->handles_018[4])->y;
            f9.y += f9.height;
            f9.height = -y;
            func_0205e048(1, ev->unk_008, &f9, 0, y, 1.0f, 1.0f, 0, 1.0f, 10, 0);
        } else {
            func_0205dee8(1, ev->unk_008, 31, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
        }
        break;
    case 14:
        if (ev->unk_032c) {
            func_02057fd8();
            func_02057df8();
            func_02057e18(15);
            func_02057d54(0xff000000, 0, 0, 256, 192, 21);
            func_02057e18(31);
        }
        break;
    case 16:
        func_02057fd8();
        func_02057df8();
        func_02057e18(15);
        func_02057d54(0xff000000, 0, 0, 256, 192, 21);
        func_02057e18(31);
        break;
    case 15:
        func_02057fd8();
        func_02057df8();
        if (ev->unk_025c >= ev->unk_260 + 68) {
            int elapsed = ev->unk_025c - (ev->unk_260 + 68);
            if (elapsed > 12) elapsed = 12;
            fade = elapsed * 24 / 12;
            if (fade >= 1) {
                func_02057e18(fade);
                func_02057d54(0, 0, 0, 256, 192, 21);
                func_02057e18(31);
            }
        }
        break;
    case 17: case 18: case 19:
        func_02057fd8();
        func_02057df8();
        if (ev->unk_032c) {
            func_02057e18(15);
            func_02057d54(0xff000000, 0, 0, 256, 192, 21);
            func_02057e18(31);
        } else {
            func_02057e18(24);
            func_02057d54(0, 0, 0, 256, 192, 21);
            func_02057e18(31);
        }
        break;
    }
    func_02057534();
}
