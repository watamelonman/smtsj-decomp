/*
 * src/game/unit_020fedd4.c: a singleton task (pointer in data_02176e28) and its setters.
 * Field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;

/* 36-byte task object created by func_020fef0c (the size it passes to func_020611dc).
 * Offsets come from the stores in Unk0fedd4_Unk_0fefc8 and the setters below. */
typedef struct Unk0fedd4Obj {
    u32 unk_00;                 /* +0x00: creation argument; 0 skips the +0x04 handle */
    u32 handle;                 /* +0x04: from func_020629ac, freed by func_020629c4 */
    u32 unk_08;                 /* +0x08: from func_0205dcd4, freed by func_0205ddb4 */
    u32 unk_0c;
    u32 unk_10;
    u32 state;                  /* +0x14: 0, 1 or 2 */
    s32 unk_18;                 /* +0x18: initialised to -1 */
    u32 unk_1c;
    u32 unk_20;                 /* +0x20: set by SetState2 */
} Unk0fedd4Obj;

extern Unk0fedd4Obj *data_02176e28;
extern u8 data_021510f4[];

void Unk05b82c_Unk_05b82c(int id);
void func_0205bb68(void);
Unk0fedd4Obj *Unk0fedd4_GetObj(void);

void Unk0fedd4_Thunk_0205bb68(void);
Unk0fedd4Obj *Unk0fedd4_Thunk_020feef0(void);
void Unk0fedd4_Unk_0fedd4(void);

/* Returns the borrowed singleton, possibly null; the original at 0x020feef0
 * loads data_02176e28 without allocating or changing ownership. */
Unk0fedd4Obj *Unk0fedd4_GetObj(void)
{
    return data_02176e28;
}

/* Tail-forwards to func_0205bb68, as evidenced by the relocation at
 * 0x020fedec; the target supplies all side effects. */
void Unk0fedd4_Thunk_0205bb68(void) { func_0205bb68(); }

/* Returns the same borrowed, possibly null singleton as GetObj; the tail
 * target is evidenced by the relocation at 0x020fef08. */
Unk0fedd4Obj *Unk0fedd4_Thunk_020feef0(void) { return Unk0fedd4_GetObj(); }

void func_02061f10(u32 handle, int a, int b, int c, u32 d);

/* Requires an allocated singleton; passes its +0x04 handle, -1, 0, 0 and arg
 * to func_02061f10 (call at 0x020fee5c). Meaning unknown. */
void Unk0fedd4_Unk_0fee38(u32 arg)
{
    func_02061f10(Unk0fedd4_Thunk_020feef0()->handle, -1, 0, 0, arg);
}

/* Requires an allocated singleton; stores a at +0x0c and b at +0x10. */
void Unk0fedd4_SetUnk0c10(u32 a, u32 b)
{
    Unk0fedd4Obj *o = Unk0fedd4_Thunk_020feef0();
    o->unk_0c = a;
    o->unk_10 = b;
}

/* Requires an allocated singleton; stores the supplied word at +0x1c
 * (str at 0x020fee90). Its higher-level meaning is unknown. */
void Unk0fedd4_SetUnk1c(u32 a)
{
    Unk0fedd4_Thunk_020feef0()->unk_1c = a;
}

/* Requires an allocated singleton; writes 1 to the state word at +0x14
 * (str at 0x020feea4). The state's higher-level meaning is unknown. */
void Unk0fedd4_SetState1(void)
{
    Unk0fedd4_Thunk_020feef0()->state = 1;
}

/* Requires an allocated singleton; writes 1 to the state word at +0x14
 * (str at 0x020feeb8). The state's higher-level meaning is unknown. */
void Unk0fedd4_SetState1b(void)
{
    Unk0fedd4_Thunk_020feef0()->state = 1;
}

/* Requires an allocated singleton; writes 0 to the state word at +0x14
 * (str at 0x020feecc). The state's higher-level meaning is unknown. */
void Unk0fedd4_SetState0(void)
{
    Unk0fedd4_Thunk_020feef0()->state = 0;
}

/* Requires an allocated singleton; writes 2 to the state word and 1 to +0x20.
 * The task update func_020ff034 tests and clears +0x20 when the state is 2. */
void Unk0fedd4_SetState2(void)
{
    Unk0fedd4Obj *o = Unk0fedd4_Thunk_020feef0();
    o->state = 2;
    o->unk_20 = 1;
}

/* Passes fixed id 0xd1 to the 05b82c helper; evidenced by mov r0 at
 * 0x020fedd8 and the target relocation at 0x020fede0. Meaning is unknown. */
void Unk0fedd4_Unk_0fedd4(void)
{
  Unk05b82c_Unk_05b82c(0xd1);
}


void func_02061424(Unk0fedd4Obj *task);
void *func_020611dc(void (*init)(void), void (*update)(Unk0fedd4Obj *), u32 arg2,
                    void (*destroy)(Unk0fedd4Obj *), u32 size, u32 arg5, u32 arg6, u32 arg7);
void Unk0ff030_Nop_0ff030(void);
void func_020ff034(Unk0fedd4Obj *o);
Unk0fedd4Obj *func_020fef0c(u32 arg);
void Unk0fedd4_Unk_0fef78(Unk0fedd4Obj *o);
void Unk0fedd4_Unk_0fefc8(Unk0fedd4Obj *o, u32 arg);

/* Creates the singleton through func_020fef0c unless one already exists. */
void Unk0fedd4_Alloc(u32 a)
{
    if (data_02176e28 != 0) {
        return;
    }
    data_02176e28 = func_020fef0c(a);
}

/* Hands the singleton to func_02061424 (the release call shared with other task
 * owners) when it exists; the destroy callback then clears data_02176e28. */
void Unk0fedd4_Unk_0fee18(void)
{
    if (data_02176e28 == 0) {
        return;
    }
    func_02061424(data_02176e28);
}

/* Creates the 36-byte task through func_020611dc with update func_020ff034 and
 * destroy Unk0fedd4_Unk_0fef78 (literal pool at 0x020fef6c), then initialises it
 * with arg. Returns the new object, or 0 when creation fails. */
Unk0fedd4Obj *func_020fef0c(u32 arg)
{
    Unk0fedd4Obj *o = func_020611dc(Unk0ff030_Nop_0ff030, func_020ff034, 0,
                                    Unk0fedd4_Unk_0fef78, 36, 3, 0, 1);
    if (o == 0) {
        return 0;
    }
    Unk0fedd4_Unk_0fefc8(o, arg);
    return o;
}

int func_0205ddb4(u32 handle);
int func_020629c4(u32 handle);
/* Task destroy callback (registered by func_020fef0c): frees the two handles
 * acquired in Unk0fedd4_Unk_0fefc8 and clears the singleton pointer. */
void Unk0fedd4_Unk_0fef78(Unk0fedd4Obj *o)
{
    if (o->unk_00 != 0) {
        func_020629c4(o->handle);
        o->handle = 0;
    }
    if (o->unk_08 != 0) {
        func_0205ddb4(o->unk_08);
        o->unk_08 = 0;
    }
    data_02176e28 = 0;
}

int func_0205dcd4(u8 *data, u32 arg1);
int func_020629ac(u32 a, u32 b, u32 c, u32 d);
/* Task init (called by func_020fef0c): clears the fields, acquires the +0x04
 * handle only when arg is non-zero, and always acquires the +0x08 handle. */
void Unk0fedd4_Unk_0fefc8(Unk0fedd4Obj *o, u32 arg)
{
    o->unk_00 = arg;
    o->handle = 0;
    o->unk_0c = 0;
    o->unk_10 = 0;
    o->state = 0;
    o->unk_18 = -1;
    o->unk_1c = 0;
    o->unk_20 = 0;
    if (o->unk_00 != 0) {
        o->handle = func_020629ac(5, 2, 1, 1);
    }
    o->unk_08 = func_0205dcd4(data_021510f4, 1);
}
