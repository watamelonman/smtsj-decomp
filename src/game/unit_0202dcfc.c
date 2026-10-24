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

/* Partial worker layout: offsets follow the original loads/stores in this TU.
 * Pointers are borrowed; callers retain ownership of the backing storage. */
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
void ScanVisor_ResetBits(u32 *sub);

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
    ScanVisor_ResetBits(w->sub);
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
/* Returns the borrowed manager alias unchanged; the original at 0x0202dd1c
 * tail-forwards to Unk095560_GetManagerAlias via a literal-loaded address. */
Worker *Unk02dcfc_Thunk_Unk095560_GetManagerAlias(void) { return Unk095560_GetManagerAlias(); }


/* Requires a live worker. Original stores at 0x0202df00 select code 21
 * at +0x18 and copy the full 32-bit argument to +0x1c; purpose is unknown. */
void Unk02dcfc_Unk_02df00(Worker *w, u32 value)
{
    w->unk_0018 = 21;
    w->unk_001c = value;
}


/* Requires a live worker. Original stores at 0x0202de58 select code 12
 * at +0x18 and set +0x54 to one; the operation remains unidentified. */
void Unk02dcfc_Unk_02de58(Worker *w)
{
    w->unk_0018 = 12;
    w->field54 = 1;
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
    ScanVisor_ResetBits(w->sub);
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

/* Returns the manager state word, or zero if absent. Evidence: original
 * 0x0202dd84 conditionally loads +0x44, the state cleared by InitWorker. */
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

/* Returns the manager timer word, or one if absent. Evidence: original
 * 0x0202de28 loads +0x48 and explicitly supplies the absent-manager value. */
u32 Unk02dcfc_GetTimer(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w == 0) {
        return 1;
    }
    return w->timer;
}

/* Returns the word at +0x54, or zero if absent; its meaning is unknown.
 * Evidence: conditional load in the original at 0x0202de40. */
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

/* Returns the word at +0x58, or zero if absent; its meaning is unknown.
 * Evidence: conditional load in the original at 0x0202de98. */
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

/* Selects code 7 at +0x18 when a manager exists. Evidence: conditional
 * store in the original at 0x0202df10; callers include unit_0203be10. */
void Unk02dcfc_SetCode7(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 7;
    }
}

/* Selects code 8 at +0x18 when a manager exists; the code's meaning is
 * unknown. Evidence: conditional store in the original at 0x0202df28. */
void Unk02dcfc_SetCode8(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 8;
    }
}

/* Unconditionally selects code 22 at +0x18 of the worker held at +0xE8 of
 * the Unk03aae8_Unk_03ad14 object; that worker must exist.
 * Evidence: unchecked store in the original at 0x0202df40. */
void Unk02dcfc_SetOwnerCode22(void)
{
    u32 code = 22;
    Worker *w = Unk03aae8_Unk_03ad14()->worker;
    w->unk_0018 = code;
}

/* Selects code 24 at +0x18 when a manager exists; the code's meaning is
 * unknown. Evidence: conditional store in the original at 0x0202df58. */
void Unk02dcfc_SetCode24(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 24;
    }
}

/* Selects code 25 at +0x18 when a manager exists; the code's meaning is
 * unknown. Evidence: conditional store in the original at 0x0202df70. */
void Unk02dcfc_SetCode25(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->unk_0018 = 25;
    }
}

/* Unconditionally selects code 26 at +0x18 of the worker held at +0xE8 of
 * the Unk03aae8_Unk_03ad14 object; that worker must exist.
 * Evidence: unchecked store in the original at 0x0202df88. */
void Unk02dcfc_SetOwnerCode26(void)
{
    u32 code = 26;
    Worker *w = Unk03aae8_Unk_03ad14()->worker;
    w->unk_0018 = code;
}

/* Sets the word at +0x64 to one when a manager exists (InitWorker clears
 * it); meaning unknown. Evidence: original at 0x0202dfa0. */
void Unk02dcfc_SetField64(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->field64 = 1;
    }
}

/* Sets the word at +0x68 to one when a manager exists (InitWorker clears
 * it); meaning unknown. Evidence: original at 0x0202dfb8. */
void Unk02dcfc_SetField68(void)
{
    Worker *w = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (w != 0) {
        w->field68 = 1;
    }
}

/* Returns the word at +0x70, or zero if absent; Unk02dcfc_SetField70 writes
 * it, meaning unknown. Evidence: original at 0x0202dfd0. */
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
