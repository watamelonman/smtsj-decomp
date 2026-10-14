/* src/UniteEvent.c */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Message parameters: bit i of `flags` says values[i] is present. */
typedef struct EventParams {
    u8  flags;
    u8  pad[3];
    s32 values[5];
} EventParams;

typedef struct EventMsg {
    u32 type;
    EventParams params;
} EventMsg;

typedef struct UniteEvent {
    s32 state;                  /* 0x000 */
    s32 mode;                   /* 0x004 */
    u8  unk008[0x25C];
    s16 iconId;                 /* 0x264 */
    u8  unk266[0xD2];
    s32 skipRequested;          /* 0x338 */
} UniteEvent;

void func_0210f960(UniteEvent *ev, s32 state);
void func_0205257c(int a);
void func_0205e590(int a);

static inline int GetEventParam(const EventParams *p, int index, s32 *out) {
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

/* Message handler of the fusion ("Unite") event. */
void func_0210b9e8(UniteEvent *ev, EventMsg *msg) {
    EventParams *p = &msg->params;
    s32 value;

    switch (msg->type) {
    case 0:
        func_0210f960(ev, 1);
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
            func_0210f960(ev, 19);
            func_0205e590(0);
        }
        break;
    case 4:
        break;
    }
}
