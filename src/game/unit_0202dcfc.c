/*
 * unit_0202dcfc: initialiser for an object owned by the unit_02095560 system
 * (callers Unk095560_Unk_0956a8/Unk095560_Unk_0956c8/func_02095d5c).
 */
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef unsigned int u32;
typedef unsigned char u8;

/* Worker object for this TU (named fields from matched accessors). */
typedef struct Worker {
    u8  pad_0000[0x18];
    u32 unk_0018;               /* +0x18 */
    u32 unk_001c;               /* +0x1C */
    u8  pad_0020[0x20];
    u32 owner;                  /* +0x40 */
    u32 state;                  /* +0x44 */
    u32 timer;                  /* +0x48 */
    u32 sub[2];                 /* +0x4C */
    u32 field54;                /* +0x54 */
    u32 field58;                /* +0x58 */
    u8  flag5C;                 /* +0x5C */
    u8  pad_005d[3];
    u32 field60;
    u32 field64;
    u32 field68;
    u32 unk6C;
    u32 field70;                /* +0x70 */
    u32 slots[16];              /* +0x74 */
} Worker;
void func_020a2bb8(u32 *sub);

int Unk02dcfc_HasField50(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return FIELD(s32, p, 0x50) >= 0;
}

/* Resets the object and attaches it to `owner`. */
void Unk0202dcfc_InitWorker(Worker *w, u32 owner) {
    int i;

    w->owner = owner;
    w->state = 0;
    w->timer = 0;
    func_020a2bb8(w->sub);
    w->field54 = 0;
    w->field58 = 0;
    w->flag5C = 0;
    w->field60 = 0;
    w->field64 = 0;
    w->field68 = 0;
    w->field70 = 0;
    for (i = 0; i < 16; i++) {
        w->slots[i] = 0;
    }
}


Worker *Unk095560_GetManagerAlias(void);
/* forwards to `Unk095560_GetManagerAlias` */
Worker *Unk02dcfc_Thunk_Unk095560_GetManagerAlias(void) { return Unk095560_GetManagerAlias(); }


/* decompiler-derived */
void Unk02dcfc_Unk_02df00(int arg0,u32 arg1)
{
  ((Worker *)arg0)->unk_0018 = 0x15;
  ((Worker *)arg0)->unk_001c = arg1;
  return;
}


/* decompiler-derived */
void Unk02dcfc_Unk_02de58(int arg0)
{
  ((Worker *)arg0)->unk_0018 = 0xc;
  ((Worker *)arg0)->field54 = 1;
  return;
}



int func_0205e5b4();
int func_020a2c00();
/* decompiler-derived */
void Unk02dcfc_Unk_02dd9c(int arg0)
{
  int tmp1;
  ((Worker *)arg0)->unk_0018 = 0xb;
  ((Worker *)arg0)->state = 1;
  tmp1 = func_0205e5b4();
  ((Worker *)arg0)->timer = (u32)(tmp1 != -1);
  func_020a2c00(arg0 + 0x4c);
  return;
}

/* Clears state/timer and resets the sub-object. */
void Unk02dcfc_ResetWorker(Worker *w)
{
    w->timer = 0;
    w->state = 0;
    func_020a2bb8(w->sub);
}

/* Object returned by Unk03aae8_Unk_03ad14; holds the worker at +0xE8. */
typedef struct Unk02dcfcOwner {
    u8 pad_0000[0xe8];
    Worker *worker;
} Unk02dcfcOwner;

Unk02dcfcOwner *Unk03aae8_Unk_03ad14(void);
void func_020a2c90(u32 *sub);
void ScanVisor_Unk_0a2950(int a);
void Unk02dcfc_SetField70(u32 value);

u32 Unk02dcfc_GetState(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return 0;
    }
    return w->state;
}

void Unk02dcfc_Unk_02ddf4(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return;
    }
    w->unk_0018 = 1;
    func_020a2c90(w->sub);
    ScanVisor_Unk_0a2950(0);
    Unk02dcfc_SetField70(0);
}

u32 Unk02dcfc_GetTimer(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return 1;
    }
    return w->timer;
}

u32 Unk02dcfc_GetField54(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return 0;
    }
    return w->field54;
}

void Unk02dcfc_Unk_02de6c(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return;
    }
    w->unk_0018 = 1;
    w->field54 = 0;
    Unk02dcfc_SetField70(0);
}

u32 Unk02dcfc_GetField58(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return 0;
    }
    return w->field58;
}

void Unk02dcfc_Unk_02deb0(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return;
    }
    w->unk_0018 = 13;
    w->field58 = 1;
}

void Unk02dcfc_Unk_02ded4(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return;
    }
    w->unk_0018 = 1;
    w->field58 = 0;
    Unk02dcfc_SetField70(0);
}

void Unk02dcfc_SetCode7(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 7;
    }
}

void Unk02dcfc_SetCode8(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 8;
    }
}

void Unk02dcfc_SetOwnerCode22(void)
{
    u32 code = 22;
    Worker *w = Unk03aae8_Unk_03ad14()->worker;
    w->unk_0018 = code;
}

void Unk02dcfc_SetCode24(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 24;
    }
}

void Unk02dcfc_SetCode25(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 25;
    }
}

void Unk02dcfc_SetOwnerCode26(void)
{
    u32 code = 26;
    Worker *w = Unk03aae8_Unk_03ad14()->worker;
    w->unk_0018 = code;
}

void Unk02dcfc_SetField64(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->field64 = 1;
    }
}

void Unk02dcfc_SetField68(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->field68 = 1;
    }
}

u32 Unk02dcfc_GetField70(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return 0;
    }
    return w->field70;
}

void Unk02dcfc_SetField70(u32 value)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->field70 = value;
    }
}
