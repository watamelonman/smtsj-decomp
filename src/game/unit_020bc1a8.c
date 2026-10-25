/*
 * src/game/unit_020bc1a8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void Unk0bc1a8_Unk_0bc514(int arg0,int arg1,u32 arg2);

int Unk0bc1a8_GetConst0(void);
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1);

/* Returns the constant zero, as shown by mov r0, #0 at 020bc420. */
int Unk0bc1a8_GetConst0(void) { return 0; }

void Unk06ae94_Unk_06ae94(int mode);
void func_020580ec(int mode);
void Unk06ae94_Unk_06aeb4(int mode);
u32 Unk0bc1a8_Unk_0bcc34(int arg0);
typedef void (*Unk0bc1a8Fn)(u8 *);
/* Evidence: 020bc490 invokes callback +24 on payload +52 unless absent or
 * flag 1 is set, bracketed by mode-2 calls and 020580ec toggles. */
void Unk0bc1a8_Unk_0bc490(u8 *p)
{
    if (FIELD(u32, p, 24) == 0 || (FIELD(u32, p, 36) & 1) == 1) {
        return;
    }
    Unk06ae94_Unk_06ae94(2);
    func_020580ec(0);
    FIELD(Unk0bc1a8Fn, p, 24)(p + 52);
    func_020580ec(1);
    Unk06ae94_Unk_06aeb4(2);
}

/* Evidence: 020bc4e0 removes p through 0bcc34, then calls the optional
 * callback at +28 with the payload at +52. p must be a live object base. */
void Unk0bc1a8_Unk_0bc4e0(u8 *p)
{
    Unk0bc1a8Fn fn;
    Unk0bc1a8_Unk_0bcc34((int)p);
    fn = FIELD(Unk0bc1a8Fn, p, 28);
    if (fn != 0) {
        fn(p + 52);
    }
}

/* Evidence: 020bc504 forwards the payload address and mode to 0bc514,
 * supplying zero for its optional request argument. arg0 is a DS address. */
void Unk0bc1a8_Unk_0bc504(u32 arg0,u32 arg1)
{
  Unk0bc1a8_Unk_0bc514(arg0,arg1,0);
}


int func_020bc770(u32 slot, void *request);
int func_020bc8c8(void *request, s32 slot, u32 value, int mode);
/* Evidence: 020bc5c0 stores at payload -4 and returns success. A non-null
 * p must have a writable, word-aligned header word immediately before it. */
int Unk0bc1a8_SetPrevWord(u32 *p, u32 value)
{
    if (p == 0) {
        return 0;
    }
    p[-1] = value;
    return 1;
}

/* Evidence: 020bc9b4 builds a 72-byte request with mode 1, then passes it
 * to 0bc770 only on success. The callees borrow the stack request. */
void Unk0bc1a8_Unk_0bc9b4(u32 arg0,u32 arg1)
{
  int value;
  u8 auStack_50 [72];
  value = func_020bc8c8(auStack_50,arg0,arg1,1);
  if (value != 0) {
    func_020bc770(arg0,auStack_50);
    return;
  }
}

extern u32 data_02176ba8[];
/* Evidence: 020bcc34 searches 41 twelve-byte slots and clears the first
 * object address equal to arg0. The initialized context owns the table. */
u32 Unk0bc1a8_Unk_0bcc34(int arg0)
{
  int value;
  int *v2;
  value = 0;
  v2 = *(int **)*data_02176ba8;
  do {
    if (*v2 == arg0) {
      *v2 = 0;
      return 1;
    }
    value = value + 1;
    v2 = v2 + 3;
  } while (value < 0x29);
  return 0;
}



int func_020bc814();
/* decompiler-derived */
void Unk0bc1a8_Unk_0bc928(int arg0,u32 arg1,u32 arg2,u32 arg3)
{
  int value1;
  int value2;
  u8 auStack_58 [72];
  u32 uStack_10;
  uStack_10 = arg3;
  value1 = func_020bc8c8(auStack_58,arg0,arg2,0);
  if (value1 != 0) {
    func_020bc814(arg0,arg1);
    value1 = arg0 * 0xc;
    value2 = *(int *)*data_02176ba8;
    *(u32 *)(*(int *)(value2 + value1) + 0x24) = *(u32 *)(*(int *)(value2 + value1) + 0x24) | 4;
    *(u32 *)(*(int *)(value2 + value1) + 0x28) =
         *(u32 *)(*(int *)(value2 + value1) + 0x28) & 0xfffffff0;
    *(u32 *)(*(int *)(value2 + value1) + 0x30) = arg1;
    func_020bc770(arg0,auStack_58);
    return;
  }
}

int func_02061424(int objectAddress);
int Unk0bc1a8_GetHeaderWord4(u8 *p);
int func_020bcacc(u32 headerWord, u32 request);
/* Evidence: 020bc514 calls 02061424 on payload -52, then, for nonzero
 * arg1, forwards header -4 and arg2 to 0bcacc. arg0 is a live DS address. */
void Unk0bc1a8_Unk_0bc514(int arg0,int arg1,u32 arg2)
{
  u32 tmp1;
  func_02061424(arg0 + -0x34);
  if (arg1 == 0) {
    return;
  }
  tmp1 = Unk0bc1a8_GetHeaderWord4((u8 *)arg0);
  func_020bcacc(tmp1,arg2);
}

/* Evidence: 020bc548 clears mask 4 at payload -12 when on is nonzero,
 * and sets it otherwise. Null is ignored; non-null needs an aligned header. */
void Unk0bc1a8_SetFlag4Inv(u8 *p, int on)
{
    u8 *q;
    if (p == 0) {
        return;
    }
    q = p - 16;
    if (on) {
        FIELD(u32, q, 4) &= ~4;
    } else {
        FIELD(u32, q, 4) |= 4;
    }
}

/* Evidence: 020bc570 clears mask 1 at payload -12 when on is nonzero,
 * and sets it otherwise. Null is ignored; non-null needs an aligned header. */
void Unk0bc1a8_SetFlag1Inv(u8 *p, int on)
{
    u8 *q;
    if (p == 0) {
        return;
    }
    q = p - 16;
    if (on) {
        FIELD(u32, q, 4) &= ~1;
    } else {
        FIELD(u32, q, 4) |= 1;
    }
}

/* Evidence: 020bc598 reads the word at payload -8; null returns 0xffff.
 * A non-null p must belong to an object with that aligned header word. */
u32 Unk0bc1a8_GetHeaderWord(u8 *p)
{
    if (p == 0) {
        return 0xffff;
    }
    return FIELD(u32, p, -8);
}

extern u32 data_02176ba8[];
typedef struct Unk0bc1a8Slot {
    u8 *obj;
    u32 pad_04[2];
} Unk0bc1a8Slot;
/* Evidence: 020bc5ac reads the word at payload -4; null returns 0xffff.
 * A non-null p must belong to an object with that aligned header word. */
int Unk0bc1a8_GetHeaderWord4(u8 *p)
{
    if (p == 0) {
        return 0xffff;
    }
    return FIELD(u32, p, -4);
}

/* Evidence: 020bc6d4 stores the supplied word at global context +4.
 * The context referenced by data_02176ba8 must already be initialized. */
void Unk0bc1a8_Unk_0bc6d4(u32 arg0)
{
  *(u32 *)(*data_02176ba8 + 4) = arg0;
}

/* Evidence: 020bc6e8 reads global context +4 without interpreting its bits.
 * The context referenced by data_02176ba8 must already be initialized. */
u32 Unk0bc1a8_Unk_0bc6e8(void)
{
  return *(u32 *)(*data_02176ba8 + 4);
}

extern u8 data_0215034c[];
void *func_02052fe0(u32 size);
/* Evidence: 020bc5d4 allocates an eight-byte context only when absent,
 * sets its table to data_0215034c and its second word to 1. */
void Unk0bc1a8_Unk_0bc5d4(void)
{
  u32 tmp1;
  u32 *v2;
  if (*data_02176ba8 != 0) {
    return;
  }
  v2 = (u32 *)func_02052fe0(8);
  tmp1 = (u32)(data_0215034c);
  *data_02176ba8 = (int)v2;
  *v2 = tmp1;
  Unk0bc1a8_Unk_0bc6d4(1);
}

/* Evidence: 020bc650 returns 1 for signed indices >=41 or a null slot
 * object. Other indices require an initialized context and valid table index. */
int Unk0bc1a8_IsSlotEmpty(int i)
{
    if (i >= 41) {
        return 1;
    }
    return (*(Unk0bc1a8Slot **)*data_02176ba8)[i].obj == 0;
}

/* Evidence: 020bc688 returns 1 for index >=41, an empty slot, or flag 8
 * at object +36. Other indices require a valid initialized slot table. */
int Unk0bc1a8_IsSlotEmptyOrFlag8(int i)
{
    u8 *o;
    if (i >= 41) {
        return 1;
    }
    o = (*(Unk0bc1a8Slot **)*data_02176ba8)[i].obj;
    if (o == 0) {
        return 1;
    }
    return (FIELD(u32, o, 36) & 8) == 8;
}

/* Evidence: 020bc614 visits all 41 slots, copying object +40 to +36 for
 * occupied slots. Requires initialized context; the table and objects are borrowed.
 * Reload the context each iteration as in the original; see DEC-010. */
void func_020bc614(void)
{
    int i;
    for (i = 0; i < 41; ++i) {
        u8 *object = (*(Unk0bc1a8Slot **)*(volatile u32 *)data_02176ba8)[i].obj;
        if (object != 0) {
            FIELD(u32, object, 36) = FIELD(u32, object, 40);
        }
    }
}

int Unk03e43c_Unk_03fa28(void);
u8 *Unk044904_Get_data_0215ee98(void);
int func_0204a968(void *record, int mode);
/* Borrowed state prefix: the original reads bit 3 of the word at +64. */
typedef struct Unk0bc1a8State {
    u8 prefix[64];
    u32 unused : 3;
    u32 flag3 : 1;
    u32 remaining : 28;
} Unk0bc1a8State;

/* Evidence: 020bc1a8 requires 03fa28 success, clear state bit 3 and +92,
 * and a zero result from 04a968 for the record at +140. State is borrowed. */
int func_020bc1a8(void)
{
    u8 *state;
    if (!Unk03e43c_Unk_03fa28()) return 0;
    state = Unk044904_Get_data_0215ee98();
    if (((Unk0bc1a8State *)state)->flag3) return 0;
    if (FIELD(u32, state, 92) != 0) return 0;
    return func_0204a968(state + 140, 0) == 0;
}

/* Evidence: 020bc3bc gates callback +16 on flags 4/16 and context mode,
 * then callback +12 on flag 2. Callbacks borrow the live payload at +52. */
void func_020bc3bc(u8 *p)
{
    if (FIELD(Unk0bc1a8Fn, p, 16) != 0 &&
        (FIELD(u32, p, 36) & 4) != 4 &&
        (FIELD(u32, p, 36) & 16) != 16 && Unk0bc1a8_Unk_0bc6e8()) {
        FIELD(Unk0bc1a8Fn, p, 16)(p + 52);
    }
    if (FIELD(Unk0bc1a8Fn, p, 12) != 0 && (FIELD(u32, p, 36) & 2) != 2) {
        FIELD(Unk0bc1a8Fn, p, 12)(p + 52);
    }
}

/* Evidence: 020bc428 invokes callback +20 unless absent or flag 1 set;
 * 0bc420 controls the surrounding 0580ec toggles. Object remains live. */
void func_020bc428(u8 *p)
{
    if (FIELD(u32, p, 20) == 0 || (FIELD(u32, p, 36) & 1) == 1) return;
    Unk06ae94_Unk_06ae94(2);
    if (!Unk0bc1a8_GetConst0()) func_020580ec(0);
    FIELD(Unk0bc1a8Fn, p, 20)(p + 52);
    if (!Unk0bc1a8_GetConst0()) func_020580ec(1);
    Unk06ae94_Unk_06aeb4(2);
}

/* Request payload is copied by value; the two padding bytes are not cleared
 * by the original null-source initialization. */
typedef struct Unk0bc1a8Payload {
    u8 flags[2];
    u32 words[16];
} Unk0bc1a8Payload;

/* A null payload is ignored; indices 0..15 set a word and its presence bit.
 * Read flags before writing the word, as observed at 020bcc08..020bcc18. */
static inline void Unk0bc1a8_SetPayloadWord(Unk0bc1a8Payload *p, int index, u32 value)
{
    u32 flags;
    if (!p) return;
    flags = p->flags[index >> 3];
    p->words[index] = value;
    p->flags[index >> 3] = flags | (1 << (index & 7));
}

/* Evidence: 020bc6fc writes mode, copies 68 source bytes if present, or
 * clears two flag bytes and sixteen words. Destination owns 72 bytes. */
void func_020bc6fc(u8 *request, u32 mode, const Unk0bc1a8Payload *source)
{
    FIELD(u32, request, 0) = mode;
    if (source) {
        *(Unk0bc1a8Payload *)(request + 4) = *source;
    } else {
        int i;
        if (!(request + 4)) return;
        for (i = 0; i < 2; ++i) FIELD(u8, request + i, 4) = 0;
        for (i = 0; i < 16; ++i) ((Unk0bc1a8Payload *)(request + 4))->words[i] = 0;
    }
}

/* Evidence: 020bc8c8 initializes the borrowed request, accepts signed slots
 * below 41, and for slot 0xfffe/mode 3 calls the optional global callback. */
int func_020bc8c8(void *request, s32 slot, u32 value, int mode)
{
    func_020bc6fc(request, mode, (const Unk0bc1a8Payload *)value);
    if (slot >= 41) {
        if (slot == 0xfffe && mode == 3) {
            Unk0bc1a8Fn callback = FIELD(Unk0bc1a8Fn, data_02176ba8, 4);
            if (callback) callback(request);
        }
        return 0;
    }
    return 1;
}

/* Evidence: 020bcbc4 builds mode 4, marks a missing source with flag 1
 * and word 0xffff, then dispatches through 0bc770. Request is stack-borrowed. */
void func_020bcbc4(u32 slot, u32 source)
{
    u32 request[18];
    if (!func_020bc8c8(request, slot, source, 4)) return;
    if (!source) {
        Unk0bc1a8_SetPayloadWord((Unk0bc1a8Payload *)(request + 1), 0, 0xffff);
    }
    func_020bc770(slot, request);
}
