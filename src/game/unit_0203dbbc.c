#include "types.h"

/* Layouts are limited to fields accessed by the original ARM instructions. */
typedef struct Unk03dbbcSub {
    u8 pad_00[0x18];
    u32 unk_18;
} Unk03dbbcSub;
typedef struct Unk03dbbcContext {
    u8 pad_00[0xe8];
    Unk03dbbcSub *unk_e8;
} Unk03dbbcContext;
typedef struct Unk03dbbcWork {
    u8 pad_00[0x35c];
    u16 unk_35c;
} Unk03dbbcWork;

s32 func_0203ac00(s32 index);
Unk03dbbcContext *Unk03aae8_Unk_03ad14(void);
Unk03dbbcWork *Unk02e000_GetWorkArea(void);
void *Unk04bb9c_GetCtxUnka20(void);
void Unk04bb9c_Unk_04c404(s32 a, s32 b);
void func_0204c4cc(s32 a, s32 b);
void func_0204c8f4(u32 a, u32 b, u32 value);
s32 Unk04bb9c_Unk_04c98c(u32 a, u32 b, u32 value);
void func_0204c804(s32 a, u32 b, u32 c, u32 value);
void func_0204d1bc(s32 value, s32 a, s32 b);
void func_0204c564(s32 a, s32 b, s32 value);
s32 Unk02f2a8_Unk_035b08(s32 a, s32 b);

/* Preserve the original value-before-pointer evaluation order for the state write. */
static inline void Unk03dbbc_SetSubState(u32 value, Unk03dbbcSub *sub)
{
    sub->unk_18 = value;
}

/* Forward two signed 16-bit operands, set the context substate to 17, return 3. */
int Unk03dbbc_Unk_03dbbc(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    Unk04bb9c_GetCtxUnka20();
    Unk02e000_GetWorkArea();
    Unk04bb9c_Unk_04c404(a, b);
    Unk03dbbc_SetSubState(17, Unk03aae8_Unk_03ad14()->unk_e8);
    return 3;
}

/* Consume operand zero and forward operands one and two as signed halfwords. */
u32 Unk03dbbc_Unk_03dc0c(void)
{
    s16 a, b;
    func_0203ac00(0);
    a = func_0203ac00(1);
    b = func_0203ac00(2);
    func_0204c4cc(a, b);
    return 3;
}

/* Consume operand zero; the handler result is always 3. */
u32 Unk03dbbc_Unk_03dc48(void)
{
    func_0203ac00(0);
    return 3;
}

/* Submit a signed operand and byte pair only when the pair/value check returns zero. */
int func_0203dc5c(void)
{
    Unk03dbbcWork *work = Unk02e000_GetWorkArea();
    s16 a = func_0203ac00(0);
    u8 b = func_0203ac00(1);
    u32 c = (u8)func_0203ac00(2);
    u16 value = work->unk_35c;
    if (Unk04bb9c_Unk_04c98c(b, c, value) == 0) {
        func_0204c804(a, b, c, value);
    }
    return 3;
}

/* Forward two byte operands and the work area's unsigned halfword at +0x35c. */
u32 Unk03dbbc_Unk_03dccc(void)
{
    Unk03dbbcWork *work = Unk02e000_GetWorkArea();
    u8 a = func_0203ac00(0);
    u8 b = func_0203ac00(1);
    func_0204c8f4(a, b, work->unk_35c);
    return 3;
}

/* Negative lookup operands select work +0x35c; forward the value and set substate 17. */
int func_0203dd08(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    s16 c = func_0203ac00(2);
    s16 d = func_0203ac00(3);
    s32 value;
    if (a < 0 || b < 0) {
        value = Unk02e000_GetWorkArea()->unk_35c;
    } else {
        value = Unk02f2a8_Unk_035b08(a, b);
    }
    func_0204d1bc(value, c, d);
    Unk03dbbc_SetSubState(17, Unk03aae8_Unk_03ad14()->unk_e8);
    return 3;
}

/* Resolve the first signed pair and forward its signed low halfword with the second pair. */
int Unk03dbbc_Unk_03dd98(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    s16 c = func_0203ac00(2);
    s16 d = func_0203ac00(3);
    func_0204c564(c, d, (s16)Unk02f2a8_Unk_035b08(a, b));
    return 3;
}
