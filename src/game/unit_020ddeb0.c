/* Resource-15 accessors and small CampStatus helpers. */
#include "types.h"


extern u8 data_0213c640[];
/* Read an unchecked table index; the ldrb relocation identifies data_0213c640. */
u8 Unk0ddeb0_Unk_0ddfd8(int arg0)
{
  return data_0213c640[arg0];
}

void *func_020445d0(s32 resource, s32 entry);
u32 *func_0204fde0(void *resource);
/* Clamp the index to 0..14 before reading resource 15, entry 0 (call immediates). */
u32 Unk0ddeb0_Unk_0ddfe8(int arg0)
{
  u32 *value;
  if (arg0 < 0) {
    arg0 = 0;
  }
  if (0xe < arg0) {
    arg0 = 0xe;
  }
  value = func_0204fde0(func_020445d0(15, 0));
  return value[arg0];
}

void func_02059f70(u32 handle, s32 zero, u32 arg1, u32 arg2,
                   const void *descriptor, s32 zero2, u32 arg5);
void func_02060dd4(void *descriptor, u32 *object, s32 zero, u32 arg3, u32 arg4);
/* Build a temporary 16-byte descriptor, then submit it with the object first word.
 * Evidence: stack buffer at sp+12 and the two calls in 020ddeb0. */
void Unk0ddeb0_Unk_0ddeb0(u32 *arg0,u32 arg1,u32 arg2,u32 arg3,
                  u32 arg4,u32 arg5)
{
  u8 auStack_24 [16];
  func_02060dd4(auStack_24,arg0,0,arg3,arg4);
  func_02059f70(*arg0,0,arg1,arg2,auStack_24,0,arg5);
}

void func_02061f10(u32 object, s32 index, s32 zero, s32 zero2, const u16 *value);
/* Forward a single zero halfword with index -1, as shown by strh and call arguments. */
void Unk0ddeb0_Unk_0ddf0c(u32 a)
{
    u16 t[1] = {0};
    func_02061f10(a, -1, 0, 0, t);
}

/* Read word 0 of resource 15, entry 1; evidence: call immediates and ldr offset 0. */
u32 Unk0ddeb0_GetRes15Word0(void)
{
    return ((u32 *)func_0204fde0(func_020445d0(15, 1)))[0];
}

/* Read word 1 of resource 15, entry 1; evidence: call immediates and ldr offset 4. */
u32 Unk0ddeb0_GetRes15Word1(void)
{
    return ((u32 *)func_0204fde0(func_020445d0(15, 1)))[1];
}

/* Produce a byte triangular wave from signed input modulo 60. Evidence: signed
 * remainder sequence, comparison with 30, and final byte mask at 020ddf38. */
u8 func_020ddf38(s32 phase)
{
    s32 remainder = phase % 60;
    if (remainder < 30)
        return remainder / 2 + 1;
    return 30 - remainder / 2;
}

/* Produce a 1..30 wave from signed input modulo 80. CampStatus passes its
 * phase field to this helper before func_02057e18; arithmetic is 12-bit fixed point. */
u8 func_020ddf7c(s32 phase)
{
    s32 remainder = phase % 80;
    s32 value;
    u8 result;
    if (remainder <= 40)
        value = 122880 - remainder * 3072;
    else
        value = (remainder - 40) * 3072;
    result = value >> 12;
    if (result > 30)
        result = 30;
    if (result == 0)
        result = 1;
    return result;
}
