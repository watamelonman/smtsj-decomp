# func_0210bc2c candidate (UniteEvent state machine, not matched)

This is not merged code. It is the cloud giants batch candidate for `func_0210bc2c`, kept so
the work can continue after a `data_0212629c` (FX_SinCosTable_) entry is added to
`config/arm9/symbols.txt`. The remaining differences are listed in
`docs/functions/uniteevent.md`. The layout block replaces `UniteEvent` and its helpers in
`src/UniteEvent.c`. The existing matched functions then need `->base` instead of
`*(u32 *)handle` and `&ev->work_1e0` instead of `ev->work_1e0`. The function block goes
after `func_0210baf8`.

## Layout

```c
/* Draw resource offsets read by func_0210e324. */
typedef struct UniteDrawBase {
    u8 pad_00[0x14];
    s32 x, y;
} UniteDrawBase;

/* UI element handle (from Unk065e88_Call_02065fc0/func_02065fc0): drawing resource,
   position and the per-element draw parameters the state machine sets. */
typedef struct UniteDrawHandle {
    UniteDrawBase *base;        /* +0x00 passed to func_0205c408/0205cac0/0205c6f8 */
    s32 unk_04;                 /* +0x04 */
    s32 unk_08;                 /* +0x08 */
    s32 x, y;                   /* +0x0C base-relative position */
    u8 pad_14[0x0c];
    float scale;                /* +0x20 ramped to 1.0 by func_0210bc2c */
    s32 unk_24;                 /* +0x24 */
    u32 color;                  /* +0x28 RGBA */
    u8 pad_2c[4];
    s32 unk_30;                 /* +0x30 */
    u8 pad_34[6];
    u8 visible;                 /* +0x3A */
} UniteDrawHandle;

/* Work slot passed to func_0210fa60 (event object +0x1E0 or +0x21C, 60 bytes). */
typedef struct Unk10fa60Work {
    UniteDrawHandle *unk_00;    /* +0x00 loader result, forwarded to Unk06ae94_SetPair */
    u8  unk_04;                 /* +0x04 effect id (UniteEvent_LoadEffects), loader index */
    u8  pad_05[3];
    u8  unk_08[8];              /* +0x08 address passed as a loader stack argument */
    u8  pad_10[4];
    u32 unk_14;                 /* +0x14 zeroed before loading */
    u32 unk_18;                 /* +0x18 zeroed before loading */
    u32 unk_1c;                 /* +0x1C zeroed before loading */
    u8  pad_20[0x1c];
} Unk10fa60Work;

/* Text/portrait loader work at UniteEvent +0x284 (Unk0a163c helpers). */
typedef struct UniteTextWork {
    u8  pad_00[0x0c];
    u32 unk_0c;                 /* +0x0C cleared before func_020a1a24 */
    u8  pad_10[0x7c];
} UniteTextWork;

/* Texture slot returned by func_0205ba28 (same layout as CampStatusTexSlot). */
typedef struct UniteTexSlot {
    u8 pad_00[0x59];
    u8 unk_59;                  /* +0x59 nonzero once loaded */
} UniteTexSlot;

/* Fusion event object (also *data_02176e48). */
typedef struct UniteEvent {
    s32 state;                  /* +0x000 event state (messages 0 and 3) */
    s32 mode;                   /* +0x004 fusion mode; 3 requests a skip */
    u32 unk_008, unk_00c, unk_010, unk_014;
    UniteDrawHandle *handles_018[26];
    UniteDrawHandle *handles_080[3];
    UniteDrawHandle *unk_08c;
    UniteDrawHandle *handles_090[2], *handles_098[2], *handles_0a0[9];
    UniteDrawHandle *unk_0c4;
    UniteDrawHandle *handles_0c8[9];
    UniteDrawHandle *unk_0ec;
    u32 handles_0f0[9];
    s32 work_114[9], work_138[9], work_15c[9];
    s32 unk_180;
    float scales_184[9];
    s32 alpha_1a8[9];
    s32 unk_1cc;
    s32 work_1d0[4];
    Unk10fa60Work work_1e0, work_21c;
    s32 unk_258;                /* +0x258 func_0210fa60 result */
    s32 unk_025c;               /* +0x25C frames in the current state; cleared by UniteEvent_SetState */
    s32 unk_260;
    u16 iconId;                 /* +0x264 message 0 argument 4 */
    u16 ids[12];                /* +0x266 ids copied by UniteEvent_CopyIds */
    u8  idCount;                /* +0x27E number of valid ids */
    u8  pad_27F[1];
    u16 id;                     /* +0x280 id stored by UniteEvent_SetId */
    u8 unk_282;
    u8 pad_283;
    UniteTextWork work_284;
    UniteDrawHandle *unk_310;
    u32 unk_314, unk_318;
    UniteTexSlot *unk_31c;
    u32 unk_320, unk_324, unk_328;
    u32 unk_032c;               /* +0x32C set by UniteEvent_SetCtxUnk32c */
    u32 unk_0330;               /* +0x330 set to 1 by UniteEvent_SetId */
    u32 unk_0334;               /* +0x334 */
    s32 skipRequested;          /* +0x338 set by message 0 argument 3 == 3 */
    s32 work_33c[4];
    s32 unk_34c, unk_350;
} UniteEvent;
```

## Function

```c
/* Optional request arguments sent with Unk0bc1a8_Unk_0bc928/0bc514: bit i of flags
   (byte i / 8) says values[i] is present. */
typedef struct UniteRequest {
    u8  flags[2];
    u8  pad_02[2];
    s32 values[16];
} UniteRequest;

/* Definition record returned by func_020a1428 (fields read by func_0210bc2c). */
typedef struct UniteDemonDef {
    u8  pad_00[2];
    u8  unk_02;                 /* +0x02 key for CampStatus_GetTableByte */
    u8  pad_03[0x21];
    u32 pad_24_0 : 21;
    u32 unk_24 : 7;             /* +0x24 bits 21-27, item passed to func_0204fed8 */
    u32 pad_24_28 : 4;
    u8  pad_28[0x38];
    u16 unk_60;                 /* +0x60 formatted into the icon path */
} UniteDemonDef;

/* Portrait position read through func_020a2250(...)->unk_18c. */
typedef struct UniteIconPos {
    u8  pad_00[6];
    s16 unk_06, unk_08;
} UniteIconPos;

typedef struct UniteIconRes {
    u8  pad_000[0x18c];
    UniteIconPos *unk_18c;
} UniteIconRes;

/* Texture descriptor copied from data_0213ca5c before func_0205ba28. */
typedef struct UniteTexDesc {
    u32 unk_00, unk_04, unk_08, unk_0c;
} UniteTexDesc;

/* NitroSDK FX_SinCosTable_ (sin, cos pairs, 1.0 = 0x1000) at 0x0212629c. */
extern const s16 data_0212629c[];

extern char data_021512c4[], data_021512d8[], data_021512ec[], data_02151300[];
extern char data_02151314[], data_0215132c[], data_02151344[], data_02151370[];
extern char data_02151380[], data_021513a8[], data_021513b8[], data_021513c8[];
extern char data_021513d8[], data_021513e8[];
extern const UniteTexDesc data_0213ca5c;

void func_02061424(UniteDrawHandle *handle);
void Unk0a163c_Unk_0a1ae0(UniteTextWork *work);
void func_0205bb68(void);
void func_02053000(u32 handle);
void func_0205c408(UniteDrawBase *base, int value);
void func_0205cac0(UniteDrawBase *base);
void Unk065e88_SetFlag3a(UniteDrawHandle *handle, int value);
void func_0205c6f8(UniteDrawBase *base);
void func_0205c6e0(UniteDrawBase *base);
int func_0205ca48(UniteDrawBase *base);
void func_0210fb04(u8 count, int extra, s32 *x, s32 *y);
void Unk05b82c_Unk_05b82c(int id);
u32 func_0205dcd4(const char *path, u32 mode);
u32 func_0205c2c4(const char *path);
UniteDrawHandle *Unk065e88_Call_02065fc0(u32 a, u32 b, u32 c, u16 d);
UniteDrawHandle *func_02065fc0(u32 a, u32 b, u32 c, int d, u16 e);
void Unk065e88_SetUnkField2C(UniteDrawHandle *handle, u32 value);
s32 func_020024f8(s32 y, s32 x);
UniteDemonDef *func_020a1428(u16 id);
u32 func_02051610(const char *path);
u32 func_0205bb04(u32 res, const char *file, u32 line);
void func_020525cc(u32 value);
void func_0205e484(int a, int b);
int func_02052728(void);
int Unk071dc0_GetMode604Sign(void);
void func_02072068(void);
u32 Unk0a0ce4_Unk_0a0da4(int se);
UniteTexSlot *func_0205ba28(UniteTexDesc *desc, const char *file, u32 line);
int CampStatus_GetTableByte(u32 i);
void func_0205b444(UniteTexSlot *slot, u32 res);
void func_0205de30(u32 res, u32 a, UniteTexSlot *slot);
void func_020a19b4(UniteTextWork *work, u32 arg);
void func_020a1a24(UniteTextWork *work);
void func_020a1b68(UniteTextWork *work, u16 id, u32 arg);
void Unk0a163c_Unk_0a21f8(UniteTextWork *work);
int Unk0a163c_Thunk_020a208c(UniteTextWork *work);
UniteDrawHandle *func_020a22e0(UniteTextWork *work, u16 id, u32 a);
UniteDrawHandle *func_020a2334(UniteTextWork *work, u16 id, u32 a, u32 b, u32 c);
UniteIconRes *func_020a2250(UniteTextWork *work, u16 id);
void func_0205c41c(UniteDrawBase *base, u32 value);
void Unk0bc1a8_Unk_0bc928(u32 a, u32 b, UniteRequest *req);
int Unk0bc1a8_IsSlotEmpty(int i);
void Unk0bc1a8_Unk_0bc514(UniteEvent *ev, int a, UniteRequest *req);
u32 func_020445f4(u32 group, u32 index);
u32 func_0204fed8(u32 table, u32 item);
void func_020f7c64(u32 a, u16 id, u32 b);
void func_020f7c10(u32 a, u32 b, u32 c);
void Unk0f7188_Call_02065cfc(u16 id);

/* Clears a request: no arguments present. */
static inline void InitRequest(UniteRequest *req)
{
    int i;
    for (i = 0; i < 2; i++) {
        req->flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        req->values[i] = 0;
    }
}

/* Sets request argument `index` and its presence bit. */
static inline void SetRequestParam(UniteRequest *req, int index, s32 value)
{
    const s32 *src = &value;
    req->values[index] = *src;
    req->flags[index / 8] |= 1 << (index % 8);
}

/*
 * Per-frame update of the fusion event (descriptor handler 0). States: 1 loads the
 * resources and builds the UI handles, 2..5 open the panels, 6..10 bring in each fused
 * id (portrait load, scale-in, slot fill), 11..13 spin the ids around the centre,
 * 14..17 show the result and send the follow-up requests, 19 closes. After the state
 * switch it scrolls the background stripes and advances unk_025c (frames in state).
 */
void func_0210bc2c(UniteEvent *ev, EventMsg *msg)
{
    int i;
    UniteDrawHandle *h;

    switch (ev->state) {
    case 0:
    case 18:
        break;
    case 1: {
        char path[64];
        if (ev->unk_025c <= 5) {
            break;
        }
        Unk044394_Unk_044428(40);
        Unk05b82c_Unk_05b82c(49);
        Unk05b82c_Unk_05b82c(50);
        Unk05b82c_Unk_05b82c(51);
        Unk05b82c_Unk_05b82c(52);
        Unk05b82c_Unk_05b82c(53);
        Unk05b82c_Unk_05b82c(54);
        Unk05b82c_Unk_05b82c(55);
        Unk05b82c_Unk_05b82c(56);
        ev->unk_008 = func_0205dcd4(data_021512c4, 1);
        ev->unk_00c = func_0205c2c4(data_021512d8);
        ev->unk_010 = func_0205dcd4(data_021512ec, 1);
        ev->unk_014 = func_0205c2c4(data_02151300);
        ev->unk_314 = func_0205dcd4(data_02151314, 0);
        ev->unk_318 = func_0205c2c4(data_0215132c);
        for (i = 0; i <= 25; i++) {
            ev->handles_018[i] = Unk065e88_Call_02065fc0(ev->unk_008, ev->unk_00c, 0, 0);
        }
        func_0205c408(ev->handles_018[0]->base, 0);
        Unk065e88_SetFlag3a(ev->handles_018[0], 0);
        func_0205c6f8(ev->handles_018[0]->base);
        func_0205c408(ev->handles_018[1]->base, 1);
        Unk065e88_SetFlag3a(ev->handles_018[1], 0);
        func_0205c6f8(ev->handles_018[1]->base);
        func_0205c408(ev->handles_018[7]->base, 7);
        Unk065e88_SetFlag3a(ev->handles_018[7], 0);
        func_0205c6f8(ev->handles_018[7]->base);
        func_0205c408(ev->handles_018[9]->base, 9);
        Unk065e88_SetFlag3a(ev->handles_018[9], 0);
        func_0205c6f8(ev->handles_018[9]->base);
        func_0205c408(ev->handles_018[10]->base, 10);
        Unk065e88_SetFlag3a(ev->handles_018[10], 0);
        func_0205c6f8(ev->handles_018[10]->base);
        func_0205c408(ev->handles_018[12]->base, 12);
        Unk065e88_SetFlag3a(ev->handles_018[12], 0);
        func_0205c6f8(ev->handles_018[12]->base);
        func_0205c408(ev->handles_018[21]->base, 21);
        Unk065e88_SetFlag3a(ev->handles_018[21], 1);
        func_0205cac0(ev->handles_018[21]->base);
        ev->handles_018[21]->unk_24 = 18;
        ev->handles_018[21]->unk_30 = 6;
        ev->handles_018[21]->color = 0xff0000ff;
        ev->handles_018[21]->scale = 0.0f;
        for (i = 0; i < 3; i++) {
            ev->handles_080[i] = Unk065e88_Call_02065fc0(ev->unk_008, ev->unk_00c, 0, 0);
            ev->handles_080[i]->unk_24 = 18;
            ev->handles_080[i]->unk_30 = 6;
            ev->handles_080[i]->y -= i * 11;
        }
        func_0210fb04(ev->idCount, ev->unk_0330, ev->work_114, ev->work_138);
        for (i = 0; i < 9; i++) {
            if (ev->work_114[i] > 0 && ev->work_138[i] > 0) {
                ev->work_15c[i] = func_020024f8((ev->work_138[i] >> 12) - 96,
                                                (ev->work_114[i] >> 12) - 128);
                ev->scales_184[i] = 0.0f;
                ev->alpha_1a8[i] = 0;
            }
        }
        for (i = 0; i < 4; i++) {
            ev->work_1d0[i] = (i * 64 + 256) << 12;
        }
        ev->unk_08c = func_02065fc0(ev->unk_010, ev->unk_014, 1, 2, 0);
        func_0205c408(ev->unk_08c->base, 0);
        Unk065e88_SetFlag3a(ev->unk_08c, 0);
        func_0205c6f8(ev->unk_08c->base);
        ev->unk_08c->unk_24 = 0;
        ev->unk_08c->unk_30 = 2;
        ev->unk_08c->color = 0x1052adff;
        Unk065e88_SetUnkField2C(ev->unk_08c, 0);
        for (i = 0; i < 2; i++) {
            ev->handles_090[i] = Unk065e88_Call_02065fc0(ev->unk_010, ev->unk_014, 1, 0);
            Unk065e88_SetFlag3a(ev->handles_090[i], 0);
            func_0205c6f8(ev->handles_090[i]->base);
            ev->handles_090[i]->unk_30 = 2;
            Unk065e88_SetUnkField2C(ev->handles_090[i], 0);
        }
        func_0205c408(ev->handles_090[0]->base, 2);
        ev->handles_090[0]->unk_24 = 2;
        func_0205c408(ev->handles_090[1]->base, 4);
        ev->handles_090[1]->unk_24 = 4;
        for (i = 0; i < 2; i++) {
            ev->handles_098[i] = Unk065e88_Call_02065fc0(ev->unk_010, ev->unk_014, 1, 0);
            func_0205c408(ev->handles_098[i]->base, i + 6);
            Unk065e88_SetFlag3a(ev->handles_098[i], 0);
            func_0205c6f8(ev->handles_098[i]->base);
            ev->handles_098[i]->unk_30 = 2;
            ev->handles_098[i]->unk_24 = 6;
            Unk065e88_SetUnkField2C(ev->handles_098[i], 0);
        }
        for (i = 0; i < 9; i++) {
            ev->handles_0a0[i] = func_02065fc0(ev->unk_010, ev->unk_014, 1, 2, 0);
            func_0205c408(ev->handles_0a0[i]->base, 9);
            Unk065e88_SetFlag3a(ev->handles_0a0[i], 0);
            func_0205c6f8(ev->handles_0a0[i]->base);
            ev->handles_0a0[i]->unk_30 = 2;
            ev->handles_0a0[i]->unk_24 = 6;
            ev->handles_0a0[i]->y = i * 19;
            Unk065e88_SetUnkField2C(ev->handles_0a0[i], 0);
        }
        ev->unk_0c4 = Unk065e88_Call_02065fc0(ev->unk_010, ev->unk_014, 1, 0);
        func_0205c408(ev->unk_0c4->base, 10);
        Unk065e88_SetFlag3a(ev->unk_0c4, 0);
        func_0205c6f8(ev->unk_0c4->base);
        ev->unk_0c4->unk_30 = 4;
        ev->unk_0c4->unk_24 = 2;
        Unk065e88_SetUnkField2C(ev->unk_0c4, 0);
        for (i = 0; i < 9; i++) {
            ev->handles_0c8[i] = func_02065fc0(ev->unk_010, ev->unk_014, 1, 2, 0);
            func_0205c408(ev->handles_0c8[i]->base, 11);
            Unk065e88_SetFlag3a(ev->handles_0c8[i], 0);
            func_0205c6f8(ev->handles_0c8[i]->base);
            ev->handles_0c8[i]->unk_30 = 2;
            ev->handles_0c8[i]->unk_24 = 8;
            ev->handles_0c8[i]->y = i * 19;
            Unk065e88_SetUnkField2C(ev->handles_0c8[i], 0);
        }
        ev->unk_0ec = Unk065e88_Call_02065fc0(ev->unk_010, ev->unk_014, 1, 0);
        func_0205c408(ev->unk_0ec->base, 16);
        Unk065e88_SetFlag3a(ev->unk_0ec, 0);
        func_0205c6f8(ev->unk_0ec->base);
        ev->unk_0ec->unk_30 = 2;
        ev->unk_0ec->unk_24 = 6;
        Unk065e88_SetUnkField2C(ev->unk_0ec, 0);
        for (i = 0; i < ev->idCount; i++) {
            u32 res;
            func_02013c3c(path, data_02151344, func_020a1428(ev->ids[i])->unk_60);
            res = func_02051610(path);
            ev->handles_0f0[i] = func_0205bb04(res, data_02151370, 489);
            func_02053000(res);
        }
        if (ev->unk_0330) {
            u32 res;
            func_02013c3c(path, data_02151380);
            res = func_02051610(path);
            ev->handles_0f0[ev->idCount] = func_0205bb04(res, data_021513a8, 497);
            func_02053000(res);
        }
        ev->unk_258 = 0;
        UniteEvent_LoadEffects(&ev->work_1e0, data_021513b8, &ev->work_21c, data_021513c8);
        func_020525cc(0);
        UniteEvent_SetState(ev, 2);
        func_0205e484(27, 8);
        break;
    }
    case 2:
        if (func_02052728()) {
            break;
        }
        if (Unk071dc0_GetMode604Sign() == 0) {
            func_02072068();
            break;
        }
        UniteEvent_SetState(ev, 3);
        func_0205cac0(ev->unk_08c->base);
        Unk065e88_SetFlag3a(ev->unk_08c, 1);
        ev->unk_350 = Unk0a0ce4_Unk_0a0da4(153);
        ev->unk_282 = 0;
        ev->unk_324 = 1;
        break;
    case 3:
        if (func_0205ca48(ev->unk_08c->base)) {
            break;
        }
        func_0205c408(ev->unk_08c->base, 1);
        func_0205cac0(ev->unk_08c->base);
        Unk065e88_SetFlag3a(ev->unk_08c, 1);
        func_0205cac0(ev->handles_090[0]->base);
        Unk065e88_SetFlag3a(ev->handles_090[0], 1);
        UniteEvent_SetState(ev, 4);
        break;
    case 4:
        if (func_0205ca48(ev->handles_090[0]->base)) {
            break;
        }
        func_0205cac0(ev->handles_090[1]->base);
        Unk065e88_SetFlag3a(ev->handles_090[1], 1);
        UniteEvent_SetState(ev, 5);
        break;
    case 5:
        if (ev->unk_025c < 90) {
            break;
        }
        func_0205c408(ev->handles_090[0]->base, 3);
        func_0205cac0(ev->handles_090[0]->base);
        Unk065e88_SetFlag3a(ev->handles_090[0], 1);
        Unk065e88_SetFlag3a(ev->handles_090[1], 0);
        func_0205cac0(ev->handles_098[0]->base);
        Unk065e88_SetFlag3a(ev->handles_098[0], 1);
        func_0205cac0(ev->handles_098[1]->base);
        Unk065e88_SetFlag3a(ev->handles_098[1], 1);
        ev->unk_350 = Unk0a0ce4_Unk_0a0da4(152);
        UniteEvent_SetState(ev, 6);
        break;
    case 6:
        if (ev->unk_0334) {
            if (ev->unk_324) {
                char path[64];
                UniteDemonDef *def = func_020a1428(ev->id - 410);
                UniteTexDesc desc = data_0213ca5c;
                ev->unk_31c = func_0205ba28(&desc, data_021513d8, 614);
                func_02013c3c(path, data_021513e8, CampStatus_GetTableByte(def->unk_02));
                ev->unk_320 = func_02051610(path);
                func_0205b444(ev->unk_31c, ev->unk_320);
                ev->unk_324 = 0;
            } else if (ev->unk_31c->unk_59) {
                func_0205de30(ev->unk_314, 1, ev->unk_31c);
                ev->unk_310 = Unk065e88_Call_02065fc0(ev->unk_314, ev->unk_318, 0, 0);
                func_0205c408(ev->unk_310->base, 1);
                func_0205c6e0(ev->unk_310->base);
                Unk065e88_SetFlag3a(ev->unk_310, 1);
                ev->unk_310->unk_24 = 0;
                ev->unk_310->unk_30 = 2;
                ev->unk_310->unk_08 = 22;
                ev->unk_310->scale = 0.0f;
                func_0205cac0(ev->handles_0a0[ev->unk_282]->base);
                Unk065e88_SetFlag3a(ev->handles_0a0[ev->unk_282], 1);
                UniteEvent_SetState(ev, 7);
            }
        } else if (ev->unk_324) {
            func_020a19b4(&ev->work_284, 1);
            ev->work_284.unk_0c = 0;
            func_020a1a24(&ev->work_284);
            func_020a1b68(&ev->work_284, ev->ids[ev->unk_282], 0);
            Unk0a163c_Unk_0a21f8(&ev->work_284);
            ev->unk_324 = 0;
        } else if (Unk0a163c_Thunk_020a208c(&ev->work_284)) {
            ev->unk_310 = func_020a22e0(&ev->work_284, ev->ids[ev->unk_282], 0);
            func_0205c408(ev->unk_310->base, 0);
            func_0205c41c(ev->unk_310->base, 0);
            func_0205c6e0(ev->unk_310->base);
            Unk065e88_SetFlag3a(ev->unk_310, 1);
            ev->unk_310->unk_24 = 0;
            ev->unk_310->unk_30 = 2;
            ev->unk_310->unk_08 = func_020a2250(&ev->work_284, ev->ids[ev->unk_282])->unk_18c->unk_06 + 22;
            ev->unk_310->unk_04 = 185;
            ev->unk_310->scale = 0.0f;
            func_0205cac0(ev->handles_0a0[ev->unk_282]->base);
            Unk065e88_SetFlag3a(ev->handles_0a0[ev->unk_282], 1);
            if (ev->unk_282 == 0) {
                UniteEvent_SetState(ev, 8);
            } else {
                UniteEvent_SetState(ev, 7);
            }
        }
        break;
    case 8:
        if (ev->unk_025c == 32) {
            UniteEvent_SetState(ev, 7);
        }
        break;
    case 7:
        h = ev->unk_310;
        if (h->scale < 1.0f) {
            h->scale += 0.1f;
            break;
        }
        UniteEvent_SetState(ev, 9);
        ev->work_33c[0] = 0;
        ev->work_33c[3] = 0;
        func_0205c408(ev->handles_018[4]->base, 4);
        Unk065e88_SetFlag3a(ev->handles_018[4], 0);
        func_0205c6f8(ev->handles_018[4]->base);
        func_0205c408(ev->handles_018[5]->base, 5);
        Unk065e88_SetFlag3a(ev->handles_018[5], 0);
        func_0205c6f8(ev->handles_018[5]->base);
        func_0205c408(ev->handles_018[6]->base, 6);
        Unk065e88_SetFlag3a(ev->handles_018[6], 0);
        func_0205c6f8(ev->handles_018[6]->base);
        func_0205c408(ev->handles_018[2]->base, 2);
        Unk065e88_SetFlag3a(ev->handles_018[2], 0);
        func_0205c6f8(ev->handles_018[2]->base);
        for (i = 0; i < 3; i++) {
            func_0205c408(ev->handles_080[i]->base, 22);
            Unk065e88_SetFlag3a(ev->handles_080[i], 0);
            func_0205c6f8(ev->handles_080[i]->base);
        }
        if (ev->unk_282 == 0) {
            func_0205cac0(ev->handles_018[0]->base);
            Unk065e88_SetFlag3a(ev->handles_018[0], 1);
            ev->handles_018[0]->unk_24 = 10;
            ev->handles_018[0]->unk_30 = 6;
            func_0205cac0(ev->handles_018[1]->base);
            Unk065e88_SetFlag3a(ev->handles_018[1], 1);
            ev->handles_018[1]->unk_24 = 10;
            ev->handles_018[1]->unk_30 = 6;
        }
        func_0205cac0(ev->handles_018[4]->base);
        Unk065e88_SetFlag3a(ev->handles_018[4], 1);
        ev->handles_018[4]->unk_24 = 16;
        ev->handles_018[4]->unk_30 = 4;
        func_0205cac0(ev->handles_018[6]->base);
        Unk065e88_SetFlag3a(ev->handles_018[6], 1);
        ev->handles_018[6]->unk_24 = 10;
        ev->handles_018[6]->unk_30 = 4;
        ev->handles_018[6]->color = 0x29efffff;
        func_0205cac0(ev->handles_018[2]->base);
        Unk065e88_SetFlag3a(ev->handles_018[2], 1);
        ev->handles_018[2]->unk_24 = 16;
        ev->handles_018[2]->unk_30 = 4;
        func_0205cac0(ev->handles_080[0]->base);
        Unk065e88_SetFlag3a(ev->handles_080[0], 1);
        ev->unk_350 = Unk0a0ce4_Unk_0a0da4(158);
        ev->unk_282++;
        break;
    case 9:
        h = ev->handles_018[21];
        if (h->scale < 1.0f) {
            h->scale += 0.25f;
        }
        if (ev->unk_025c < 90) {
            ev->work_33c[0] -= 0x16b8;
        }
        if (ev->unk_025c == 30) {
            func_0205c408(ev->handles_080[0]->base, 23);
            func_0205cac0(ev->handles_080[0]->base);
            Unk065e88_SetFlag3a(ev->handles_080[0], 1);
            func_0205cac0(ev->handles_080[1]->base);
            Unk065e88_SetFlag3a(ev->handles_080[1], 1);
        }
        if (ev->unk_025c == 60) {
            func_0205c408(ev->handles_080[1]->base, 23);
            func_0205cac0(ev->handles_080[1]->base);
            Unk065e88_SetFlag3a(ev->handles_080[1], 1);
            func_0205cac0(ev->handles_080[2]->base);
            Unk065e88_SetFlag3a(ev->handles_080[2], 1);
        }
        if (ev->unk_025c == 90) {
            func_0205c408(ev->handles_080[2]->base, 23);
            func_0205cac0(ev->handles_080[2]->base);
            Unk065e88_SetFlag3a(ev->handles_080[2], 1);
        }
        if (ev->unk_025c == 102) {
            func_0205c408(ev->handles_018[4]->base, 5);
            func_0205cac0(ev->handles_018[4]->base);
            func_0205c408(ev->handles_018[2]->base, 3);
            func_0205cac0(ev->handles_018[2]->base);
            func_02061424(ev->unk_310);
            ev->unk_310 = 0;
            if (ev->unk_0334) {
                func_0205bb68();
                func_02053000(ev->unk_320);
                ev->unk_320 = 0;
            } else {
                Unk0a163c_Unk_0a1ae0(&ev->work_284);
            }
            ev->unk_0c4->y = ev->handles_0a0[ev->unk_282 - 1]->y;
            func_0205cac0(ev->unk_0c4->base);
            Unk065e88_SetFlag3a(ev->unk_0c4, 1);
            func_0205cac0(ev->handles_0c8[ev->unk_282 - 1]->base);
            Unk065e88_SetFlag3a(ev->handles_0c8[ev->unk_282 - 1], 1);
            ev->unk_350 = Unk0a0ce4_Unk_0a0da4(159);
        }
        if (ev->unk_025c >= 102 && ev->unk_025c < 110) {
            ev->alpha_1a8[ev->unk_282 - 1] += 0x3e00;
            if (ev->alpha_1a8[ev->unk_282 - 1] > 0x1f000) {
                ev->alpha_1a8[ev->unk_282 - 1] = 0x1f000;
            }
        }
        if (ev->unk_025c == 126) {
            for (i = 0; i < 3; i++) {
                func_0205c408(ev->handles_080[i]->base, 24);
                func_0205c6e0(ev->handles_080[i]->base);
                Unk065e88_SetFlag3a(ev->handles_080[i], 1);
            }
            func_0205c6f8(ev->unk_0c4->base);
            Unk065e88_SetFlag3a(ev->unk_0c4, 0);
            UniteEvent_SetState(ev, 10);
            if (ev->unk_0334) {
                ev->unk_0330 = 0;
                ev->unk_0334 = 0;
            }
        }
        break;
    case 10:
        if (ev->unk_282 < ev->idCount) {
            if (ev->unk_025c >= 60) {
                ev->unk_324 = 1;
                UniteEvent_SetState(ev, 6);
            }
        } else if (ev->unk_0330) {
            if (ev->unk_025c >= 60) {
                ev->unk_0334 = 1;
                ev->unk_324 = 1;
                UniteEvent_SetState(ev, 6);
            }
        } else if (ev->unk_025c >= 60) {
            ev->unk_260 = 0;
            for (i = 0; i < ev->unk_282; i++) {
                func_0205c408(ev->handles_0a0[i]->base, 12);
                func_0205cac0(ev->handles_0a0[i]->base);
                Unk065e88_SetFlag3a(ev->handles_0a0[i], 1);
            }
            UniteEvent_SetState(ev, 11);
            ev->unk_350 = Unk0a0ce4_Unk_0a0da4(151);
        }
        break;
    case 11:
        if (ev->unk_025c < 30) {
            if (ev->unk_1cc < 64) {
                ev->unk_1cc += 8;
            }
            for (i = 0; i < ev->unk_282; i++) {
                ev->handles_0c8[i]->x = ev->handles_0a0[i]->base->x;
            }
        }
        if (ev->unk_025c == 30) {
            for (i = 0; i < 9; i++) {
                Unk065e88_SetFlag3a(ev->handles_0a0[i], 0);
                func_0205c6f8(ev->handles_0a0[i]->base);
                Unk065e88_SetFlag3a(ev->handles_0c8[i], 0);
                func_0205c6f8(ev->handles_0c8[i]->base);
            }
            func_0205cac0(ev->unk_0ec->base);
            Unk065e88_SetFlag3a(ev->unk_0ec, 1);
        }
        if (ev->unk_025c == 80) {
            func_0205c408(ev->unk_0ec->base, 8);
            func_0205c6f8(ev->unk_0ec->base);
            for (i = 0; i < 9; i++) {
                ev->alpha_1a8[i] = 0;
            }
            UniteEvent_SetState(ev, 12);
        }
        break;
    case 12: {
        int start = 0;
        for (i = 0; i < ev->unk_282; i++, start += 15) {
            int t = ev->unk_025c - 1;
            if (t >= start && t < start + 20) {
                if (t < start + 15) {
                    ev->scales_184[i] += 0.1f;
                } else {
                    ev->scales_184[i] -= 0.1f;
                }
                ev->alpha_1a8[i] += 0x18cd;
                if (ev->alpha_1a8[i] > 0x1f000) {
                    ev->alpha_1a8[i] = 0x1f000;
                }
            }
            if (ev->unk_025c - 1 == start) {
                ev->unk_350 = Unk0a0ce4_Unk_0a0da4(154);
            }
        }
        if (ev->unk_025c - 1 == (ev->unk_282 - 1) * 15 + 20) {
            func_0205cac0(ev->unk_0ec->base);
        }
        if (ev->unk_025c - 1 == (ev->unk_282 - 1) * 15 + 35) {
            ev->unk_260 = 0;
            UniteEvent_SetState(ev, 13);
            for (i = 0; i < ev->unk_282; i++) {
                ev->scales_184[i] = 1.0f;
                ev->alpha_1a8[i] = 0x1f000;
            }
            ev->unk_350 = Unk0a0ce4_Unk_0a0da4(155);
        }
        break;
    }
    case 13:
        if (ev->unk_025c == 260) {
            ev->unk_258 = func_0210fa60(&ev->work_1e0);
        }
        if (ev->unk_025c <= 260) {
            s32 step = ev->unk_025c * 6;
            if (step > 0x578) {
                step = 0x578;
            }
            for (i = 0; i < ev->unk_282; i++) {
                ev->work_15c[i] += step;
                if (ev->work_15c[i] >= 0x10000) {
                    ev->work_15c[i] -= 0x10000;
                }
                ev->work_114[i] = data_0212629c[((ev->work_15c[i] >> 4) << 1) + 1] * (ev->unk_180 >> 12) + 0x80000;
                ev->work_138[i] = data_0212629c[(ev->work_15c[i] >> 4) << 1] * (ev->unk_180 >> 12) + 0x60000;
            }
        } else if (ev->unk_025c <= 380) {
            s32 step;
            ev->unk_180 -= 2000;
            if (ev->unk_180 < 0) {
                ev->unk_180 = 0;
            }
            step = 0x578 + (ev->unk_025c - 260) * 18;
            for (i = 0; i < ev->unk_282; i++) {
                ev->work_15c[i] += step;
                if (ev->work_15c[i] >= 0x10000) {
                    ev->work_15c[i] -= 0x10000;
                }
                if ((ev->unk_025c - 260) % 12 == 0) {
                    ev->scales_184[i] -= 0.1f;
                }
                ev->work_114[i] = data_0212629c[((ev->work_15c[i] >> 4) << 1) + 1] * (ev->unk_180 >> 12) + 0x80000;
                ev->work_138[i] = data_0212629c[(ev->work_15c[i] >> 4) << 1] * (ev->unk_180 >> 12) + 0x60000;
            }
        }
        if (ev->unk_025c == 480) {
            UniteEvent_SetState(ev, 14);
        }
        break;
    case 14:
        if (ev->unk_032c) {
            if (ev->unk_025c == 1) {
                Unk065e88_SetFlag3a(ev->handles_098[0], 1);
                func_0205c408(ev->handles_098[0]->base, 14);
                func_0205cac0(ev->handles_098[0]->base);
                Unk065e88_SetFlag3a(ev->handles_098[1], 1);
                func_0205c408(ev->handles_098[1]->base, 15);
                func_0205cac0(ev->handles_098[1]->base);
                Unk065e88_SetFlag3a(ev->unk_0ec, 1);
                func_0205c408(ev->unk_0ec->base, 17);
                func_0205cac0(ev->unk_0ec->base);
                func_0205cac0(ev->handles_018[10]->base);
                Unk065e88_SetFlag3a(ev->handles_018[10], 1);
                ev->handles_018[10]->unk_24 = 10;
                ev->handles_018[10]->unk_30 = 7;
                ev->handles_018[10]->color = 0xde0000ff;
                ev->unk_08c->color = 0xbd1821ff;
                ev->unk_350 = Unk0a0ce4_Unk_0a0da4(157);
            }
            if (ev->unk_025c == 12) {
                for (i = 0; i < 2; i++) {
                    Unk065e88_SetFlag3a(ev->handles_098[i], 0);
                    func_0205c6f8(ev->handles_098[i]->base);
                }
                Unk065e88_SetFlag3a(ev->unk_0ec, 0);
                func_0205c6f8(ev->unk_0ec->base);
                func_0205c408(ev->handles_018[10]->base, 11);
                func_0205cac0(ev->handles_018[10]->base);
                Unk065e88_SetFlag3a(ev->handles_018[10], 1);
                func_0205cac0(ev->handles_018[12]->base);
                Unk065e88_SetFlag3a(ev->handles_018[12], 1);
                ev->handles_018[12]->unk_24 = 11;
                ev->handles_018[12]->unk_30 = 7;
                ev->handles_018[12]->color = 0xff0000ff;
            }
            if (ev->unk_025c == 90) {
                ev->unk_258 = 0;
                UniteEvent_SetState(ev, 16);
            }
        } else {
            if (ev->unk_025c == 1) {
                Unk065e88_SetFlag3a(ev->handles_098[0], 1);
                func_0205c408(ev->handles_098[0]->base, 14);
                func_0205cac0(ev->handles_098[0]->base);
                Unk065e88_SetFlag3a(ev->handles_098[1], 1);
                func_0205c408(ev->handles_098[1]->base, 15);
                func_0205cac0(ev->handles_098[1]->base);
                Unk065e88_SetFlag3a(ev->unk_0ec, 1);
                func_0205c408(ev->unk_0ec->base, 17);
                func_0205cac0(ev->unk_0ec->base);
            }
            if (ev->unk_025c == 12) {
                for (i = 0; i < 2; i++) {
                    Unk065e88_SetFlag3a(ev->handles_098[i], 0);
                    func_0205c6f8(ev->handles_098[i]->base);
                }
                Unk065e88_SetFlag3a(ev->unk_0ec, 0);
                func_0205c6f8(ev->unk_0ec->base);
            }
            if (ev->unk_025c == 30) {
                ev->unk_258 = 0;
                UniteEvent_SetState(ev, 15);
            }
        }
        break;
    case 15:
        if (ev->unk_258 == 0) {
            ev->unk_324 = 1;
            ev->unk_258 = func_0210fa60(&ev->work_21c);
            ev->unk_260 = ev->unk_025c;
        }
        if (ev->unk_258 && ev->unk_324 && ev->unk_025c >= ev->unk_260) {
            if (ev->unk_025c == ev->unk_260) {
                func_020a19b4(&ev->work_284, 1);
                ev->work_284.unk_0c = 0;
                func_020a1a24(&ev->work_284);
                func_020a1b68(&ev->work_284, ev->iconId, 0);
                Unk0a163c_Unk_0a21f8(&ev->work_284);
            }
            if (Unk0a163c_Thunk_020a208c(&ev->work_284)) {
                ev->unk_310 = func_020a2334(&ev->work_284, ev->iconId, 1, 3, 10);
                func_0205c408(ev->unk_310->base, 0);
                func_0205c41c(ev->unk_310->base, 0);
                func_0205c6f8(ev->unk_310->base);
                Unk065e88_SetFlag3a(ev->unk_310, 0);
                ev->unk_310->unk_24 = 0;
                ev->unk_310->unk_30 = 4;
                ev->unk_310->unk_08 = func_020a2250(&ev->work_284, ev->iconId)->unk_18c->unk_08 + 96;
                ev->unk_310->unk_04 = 128;
                ev->unk_310->scale = 0.0f;
                ev->unk_324 = 0;
            }
        }
        if (ev->unk_025c == ev->unk_260 + 20) {
            func_0205c6e0(ev->unk_310->base);
            Unk065e88_SetFlag3a(ev->unk_310, 1);
        }
        if (ev->unk_025c >= ev->unk_260 + 20) {
            h = ev->unk_310;
            if (h->scale < 1.0f) {
                h->scale += 0.1f;
            }
        }
        if (ev->unk_025c == ev->unk_260 + 38) {
            func_0205cac0(ev->handles_018[7]->base);
            Unk065e88_SetFlag3a(ev->handles_018[7], 1);
            ev->handles_018[7]->unk_24 = 10;
            ev->handles_018[7]->unk_30 = 7;
            ev->handles_018[7]->color = 0x20be9dff;
        }
        if (ev->unk_025c >= ev->unk_260 + 38) {
            h = ev->handles_018[21];
            if (h->scale > 0.0f) {
                h->scale -= 0.25f;
            }
        }
        if (ev->unk_025c == ev->unk_260 + 50) {
            Unk065e88_SetFlag3a(ev->handles_018[0], 0);
            func_0205c6f8(ev->handles_018[0]->base);
            Unk065e88_SetFlag3a(ev->handles_018[1], 0);
            func_0205c6f8(ev->handles_018[1]->base);
            func_0205c408(ev->handles_018[7]->base, 8);
            func_0205cac0(ev->handles_018[7]->base);
            Unk065e88_SetFlag3a(ev->handles_018[7], 1);
            func_0205cac0(ev->handles_018[9]->base);
            Unk065e88_SetFlag3a(ev->handles_018[9], 1);
            ev->handles_018[9]->unk_24 = 11;
            ev->handles_018[9]->unk_30 = 7;
            ev->handles_018[9]->color = 0x2affe0ff;
            ev->unk_350 = Unk0a0ce4_Unk_0a0da4(18);
        }
        if (ev->unk_025c == ev->unk_260 + 80) {
            func_0205c6f8(ev->handles_018[9]->base);
            Unk065e88_SetFlag3a(ev->handles_018[9], 0);
        }
        if (ev->unk_025c == ev->unk_260 + 200) {
            if (ev->skipRequested) {
                func_0205257c(0);
                UniteEvent_SetState(ev, 19);
                func_0205e590(0);
            } else {
                UniteRequest req;
                UniteDemonDef *def;
                InitRequest(&req);
                SetRequestParam(&req, 4, 1);
                Unk0bc1a8_Unk_0bc928(7, 12, &req);
                def = func_020a1428(ev->iconId);
                func_020f7c64(func_0204fed8(func_020445f4(40, 0), def->unk_24), ev->iconId, 0);
                Unk0f7188_Call_02065cfc(ev->iconId);
                UniteEvent_SetState(ev, 18);
            }
        }
        break;
    case 16:
        if (ev->unk_258 == 0) {
            ev->unk_324 = 1;
            ev->unk_258 = func_0210fa60(&ev->work_21c);
            ev->unk_260 = ev->unk_025c;
        }
        if (ev->unk_258 && ev->unk_324 && ev->unk_025c >= ev->unk_260) {
            if (ev->unk_025c == ev->unk_260) {
                func_020a19b4(&ev->work_284, 1);
                ev->work_284.unk_0c = 0;
                func_020a1a24(&ev->work_284);
                func_020a1b68(&ev->work_284, ev->iconId, 0);
                Unk0a163c_Unk_0a21f8(&ev->work_284);
            }
            if (Unk0a163c_Thunk_020a208c(&ev->work_284)) {
                ev->unk_310 = func_020a2334(&ev->work_284, ev->iconId, 1, 3, 10);
                func_0205c408(ev->unk_310->base, 0);
                func_0205c41c(ev->unk_310->base, 0);
                func_0205c6f8(ev->unk_310->base);
                Unk065e88_SetFlag3a(ev->unk_310, 0);
                ev->unk_310->unk_24 = 0;
                ev->unk_310->unk_30 = 4;
                ev->unk_310->unk_08 = func_020a2250(&ev->work_284, ev->iconId)->unk_18c->unk_06;
                ev->unk_310->unk_04 = 128;
                ev->unk_310->scale = 0.0f;
                ev->unk_324 = 0;
                ev->unk_260 = ev->unk_025c;
            }
        }
        if (ev->unk_025c == ev->unk_260 + 20) {
            func_0205c6e0(ev->unk_310->base);
            Unk065e88_SetFlag3a(ev->unk_310, 1);
        }
        if (ev->unk_025c >= ev->unk_260 + 20) {
            h = ev->unk_310;
            if (h->scale < 1.0f) {
                h->scale += 0.1f;
            }
        }
        if (ev->unk_025c >= ev->unk_260 + 38) {
            h = ev->handles_018[21];
            if (h->scale > 0.0f) {
                h->scale -= 0.25f;
            }
        }
        if (ev->unk_025c == ev->unk_260 + 40) {
            Unk065e88_SetFlag3a(ev->handles_018[0], 0);
            func_0205c6f8(ev->handles_018[0]->base);
            Unk065e88_SetFlag3a(ev->handles_018[1], 0);
            func_0205c6f8(ev->handles_018[1]->base);
            func_0205cac0(ev->handles_018[12]->base);
            Unk065e88_SetFlag3a(ev->handles_018[12], 1);
            ev->handles_018[12]->unk_24 = 11;
            ev->handles_018[12]->unk_30 = 7;
            ev->handles_018[12]->color = 0xff0000ff;
            ev->unk_350 = Unk0a0ce4_Unk_0a0da4(18);
        }
        if (ev->unk_025c == ev->unk_260 + 80) {
            func_0205c6f8(ev->handles_018[12]->base);
            Unk065e88_SetFlag3a(ev->handles_018[12], 0);
        }
        if (ev->unk_025c == ev->unk_260 + 200) {
            UniteRequest req;
            InitRequest(&req);
            SetRequestParam(&req, 4, 1);
            Unk0bc1a8_Unk_0bc928(7, 12, &req);
            func_020f7c10(15, 0, 0);
            UniteEvent_SetState(ev, 17);
        }
        break;
    case 17:
        if (Unk0bc1a8_IsSlotEmpty(7)) {
            UniteRequest req;
            UniteDemonDef *def;
            InitRequest(&req);
            SetRequestParam(&req, 4, 1);
            Unk0bc1a8_Unk_0bc928(7, 12, &req);
            def = func_020a1428(ev->iconId);
            func_020f7c64(func_0204fed8(func_020445f4(40, 0), def->unk_24), ev->iconId, 0);
            Unk0f7188_Call_02065cfc(ev->iconId);
            UniteEvent_SetState(ev, 18);
        }
        break;
    case 19:
        if (func_02052728() == 0) {
            UniteRequest req;
            Unk0a0ce4_Unk_0a0d30(1);
            InitRequest(&req);
            SetRequestParam(&req, 0, 12);
            Unk0bc1a8_Unk_0bc514(ev, 1, &req);
        }
        break;
    }
    if (ev->state == 9 || ev->state == 10 ||
        (ev->state == 7 && ev->unk_282 != 0) ||
        (ev->state == 6 && ev->unk_282 != 0)) {
        for (i = 0; i < 4; i++) {
            ev->work_1d0[i] -= 0x2222;
            if (ev->work_1d0[i] < 0) {
                ev->work_1d0[i] = 0x100000;
            }
        }
    }
    if (ev->state >= 6 && ev->state <= 16 &&
        (ev->state != 15 || ev->unk_025c < ev->unk_260 + 80) &&
        (ev->state != 16 || (ev->unk_025c >= 108 && (ev->unk_260 <= 0 || ev->unk_025c < ev->unk_260 + 80)))) {
        if ((ev->unk_34c >= 0 && ev->unk_34c < 90) || (ev->unk_34c >= 102 && ev->unk_34c < 112) ||
            (ev->unk_34c >= 124 && ev->unk_34c < 194) || (ev->unk_34c >= 206 && ev->unk_34c < 220) ||
            (ev->unk_34c >= 228 && ev->unk_34c < 244)) {
            ev->work_33c[1] -= 0xa3d;
            if (ev->work_33c[1] < -0x80000) {
                ev->work_33c[1] = 0;
            }
        }
        ev->unk_34c++;
        if (ev->unk_34c > 252) {
            ev->unk_34c = 0;
        }
    }
    if (ev->state == 9 || ev->state == 10) {
        ev->work_33c[3] -= 0x869;
        if (ev->work_33c[3] < -0x33000) {
            ev->work_33c[3] = 0;
        }
    }
    ev->unk_025c++;
}
```
