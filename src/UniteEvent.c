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

void UniteEvent_SetState(UniteEvent *ev, s32 state);
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
void UniteEvent_HandleMessage(UniteEvent *ev, EventMsg *msg) {
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

extern u8 data_02151418[];
extern u8 data_02151428[];
int func_02013c3c();
int func_0206df10();
int func_0206f6e4();
int Unk071dc0_Unk_071fcc();
typedef struct UniteEventCtx {
    u8 pad_0000[0x32c];
    u32 unk_032c;
} UniteEventCtx;

extern UniteEventCtx *data_02176e48;

void func_0200866c();
void UniteEvent_CopyIds(u32 a, int n)
{
    if (data_02176e48 == 0) {
        return;
    }
    func_0200866c(a, (u8 *)data_02176e48 + 614, n * 2);
    FIELD(u8, data_02176e48, 638) = n;
}

void UniteEvent_SetId(u32 x)
{
    if (data_02176e48 == 0) {
        return;
    }
    FIELD(u32, data_02176e48, 816) = 1;
    FIELD(u16, data_02176e48, 640) = x;
}

void UniteEvent_SetCtxUnk32c(void)
{
    if (data_02176e48 != 0) {
        data_02176e48->unk_032c = 1;
    }
}

/* Loads two Data/Effect/%s effects for the fusion event (medium). */
void UniteEvent_LoadEffects(int arg0,u32 arg1,int arg2,u32 arg3)
{
  u8 tmp1;
  u8 auStack_98 [128];
  u32 uStack_18;
  uStack_18 = arg3;
  func_0206df10();
  Unk071dc0_Unk_072200();
  func_02013c3c(auStack_98,data_02151418,arg1);
  tmp1 = func_0206f6e4(auStack_98);
  *(u8 *)(arg0 + 4) = tmp1;
  func_02013c3c(auStack_98,data_02151428,arg3);
  tmp1 = func_0206f6e4(auStack_98);
  *(u8 *)(arg2 + 4) = tmp1;
  Unk071dc0_Unk_071fcc();
}

void UniteEvent_SetState(UniteEvent *ev, s32 state)
{
    ev->state = state;
    FIELD(s32, ev, 604) = 0;
}
