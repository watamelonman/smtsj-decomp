/* Argument forwarding handlers; neutral names retain the ROM symbol identities. */
#include "types.h"

/* Only fields accessed by this unit are described; gaps are opaque bytes. */
typedef struct Unk03d72cSubState {
    u8 pad_0000[0x18];
    u32 unk_0018;
} Unk03d72cSubState;

/* The context owns a substate pointer at the observed offset 0xe8. */
typedef struct Unk03d72cContext {
    u8 pad_0000[0xe8];
    Unk03d72cSubState *unk_00e8;
} Unk03d72cContext;

/* The fallback selector is an unsigned halfword at offset 0x35c. */
typedef struct Unk03d72cWorkArea {
    u8 pad_0000[0x35c];
    u16 unk_035c;
} Unk03d72cWorkArea;

int func_0203ac00(int index);
int func_0209ea18(int first, int second);
int func_0209ebd0(int first, int second);
Unk03d72cContext *Unk03aae8_Unk_03ad14(void);
void Unk09d42c_Unk_09e2f4(int value);
void Unk09ee4c_Unk_09efb4(int first, int second, int third);
void func_0209ee80(int value);
void Unk09ee4c_Unk_09ef50(int value);
int Unk094fe0_Unk_095258(int first, int second, int third);
Unk03d72cWorkArea *Unk02e000_GetWorkArea(void);
int Unk02f2a8_Unk_035b08(int first, int second);
int func_0209e564(u32 selected, u32 third, u32 fourth, u32 fifth);

/* Keep the store operand order used by the four state-changing handlers. */
static inline void Unk03d72c_SetSubState(u32 value, Unk03d72cSubState *sub)
{
    sub->unk_0018 = value;
}

/* Forward argument 0 as signed 16-bit, set substate 15, and return 3.
 * Evidence: original instructions at 0x0203d72c; callee semantics remain unknown. */
int Unk03d72c_Unk_03d72c(void)
{
    Unk09d42c_Unk_09e2f4((s16)func_0203ac00(0));
    Unk03d72c_SetSubState(15, Unk03aae8_Unk_03ad14()->unk_00e8);
    return 3;
}

/* Forward three full-width arguments, set substate 15, and return 3.
 * Evidence: original instructions at 0x0203d7dc; callee semantics remain unknown. */
int Unk03d72c_Unk_03d7dc(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);
    Unk09ee4c_Unk_09efb4(a, b, func_0203ac00(2));
    Unk03d72c_SetSubState(15, Unk03aae8_Unk_03ad14()->unk_00e8);
    return 3;
}

/* Forward two signed 16-bit arguments to func_0209ea18 and return 3.
 * Evidence: original instructions at 0x0203d828; callee semantics remain unknown. */
u32 Unk03d72c_Unk_03d828(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  func_0209ea18((int)v1,(int)v2);
  return 3;
}

/* Forward two signed 16-bit arguments to func_0209ebd0 and return 3.
 * Evidence: original instructions at 0x0203d85c; callee semantics remain unknown. */
u32 Unk03d72c_Unk_03d85c(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  func_0209ebd0((int)v1,(int)v2);
  return 3;
}

/* Forward argument 0 as signed 16-bit to func_0209ee80; set substate 15.
 * Evidence: original instructions at 0x0203d890; callee semantics remain unknown. */
int Unk03d72c_Unk_03d890(void)
{
    func_0209ee80((s16)func_0203ac00(0));
    Unk03d72c_SetSubState(15, Unk03aae8_Unk_03ad14()->unk_00e8);
    return 3;
}

/* Forward argument 0 as signed 16-bit to Unk09ee4c_Unk_09ef50; set substate 15.
 * Evidence: original instructions at 0x0203d8c0; callee semantics remain unknown. */
int Unk03d72c_Unk_03d8c0(void)
{
    Unk09ee4c_Unk_09ef50((s16)func_0203ac00(0));
    Unk03d72c_SetSubState(15, Unk03aae8_Unk_03ad14()->unk_00e8);
    return 3;
}

/* Forward arguments narrowed to unsigned 8/16/8 bits and return 3.
 * Evidence: original instructions at 0x0203d8f0; callee semantics remain unknown. */
u32 Unk03d72c_Unk_03d8f0(void)
{
  u8 value1;
  u8 value2;
  u16 value3;
  value1 = func_0203ac00(0);
  value3 = func_0203ac00(1);
  value2 = func_0203ac00(2);
  Unk094fe0_Unk_095258(value1,value3,value2);
  return 3;
}

/* Resolve the first argument pair, using work field 0x35c if either is negative; forward the result and arguments 2 through 4.
 * Evidence: original instructions at 0x0203d75c; callee semantics remain unknown. */
u32 Unk03d72c_Unk_03d75c(void)
{
  int value1;
  int value2;
  u32 value3;
  u32 value4;
  u32 value5;
  u32 value6;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  value3 = func_0203ac00(2);
  value4 = func_0203ac00(3);
  value5 = func_0203ac00(4);
  if (value1 < 0 || value2 < 0) {
    value6 = Unk02e000_GetWorkArea()->unk_035c;
  }
  else {
    value6 = Unk02f2a8_Unk_035b08(value1,value2);
  }
  func_0209e564(value6,value3,value4,value5);
  return 3;
}
