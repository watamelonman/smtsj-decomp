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
    u8  pad_008[0x254];
    u32 unk_025c;               /* +0x25C cleared by UniteEvent_SetState */
    u8  pad_260[4];
    s16 iconId;                 /* +0x264 message 0 argument 4 */
    u16 ids[12];                /* +0x266 ids copied by UniteEvent_CopyIds */
    u8  idCount;                /* +0x27E number of valid ids */
    u8  pad_27F[1];
    u16 id;                     /* +0x280 id stored by UniteEvent_SetId */
    u8  pad_282[0xAA];
    u32 unk_032c;               /* +0x32C set by UniteEvent_SetCtxUnk32c */
    u32 unk_0330;               /* +0x330 set to 1 by UniteEvent_SetId */
    u32 unk_0334;               /* +0x334 */
    s32 skipRequested;          /* +0x338 set by message 0 argument 3 == 3 */
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
