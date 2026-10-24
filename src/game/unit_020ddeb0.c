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

/* Local record view: the resolver copies 36 bytes; offsets follow the original loads. */
typedef struct Unk0ddeb0Record {
    u8 unk00;
    u8 values[5];
    u8 pad06[10];
    u16 entries[6];
    u16 unk1c;
    u8 value1e : 7;
    u8 flag1e : 1;
    u8 pad1f[5];
} Unk0ddeb0Record;

/* Borrowed metadata view; only the bytes and halfwords used here are named. */
typedef struct Unk0ddeb0Meta {
    u8 pad00[26];
    u8 values[5];
    u8 pad1f[13];
    u16 coefficient;
    u16 entries[6];
} Unk0ddeb0Meta;

int Unk02e000_SetRecord(u32 id, Unk0ddeb0Record *record);
Unk0ddeb0Meta *func_020a1428(u32 id);
const u8 *func_020e6874(u32 id);

/* Calculate a capped unsigned value from a resolved record and metadata.
 * Evidence: byte sum at 1..5, six-entry exclusion scan, resource 15 calls,
 * and reciprocal division sequences for 1000 and 200 at 020de04c. */
u32 func_020de04c(u32 id)
{
    Unk0ddeb0Record record;
    u32 result = 0;
    if (Unk02e000_SetRecord(id, &record)) {
        Unk0ddeb0Meta *meta = func_020a1428(id);
        s32 sum = record.values[0] + record.values[1] + record.values[2] + record.values[3] + record.values[4];
        u32 coefficient = meta->coefficient;
        u32 multiplier = 2;
        s32 maximum = 0;
        s32 i;
        u32 extra, scale, base;
        for (i = 0; i < 6; i++) {
            if (record.entries[i]) {
                s32 j;
                s32 value = func_020e6874(record.entries[i])[3];
                if (value > maximum) {
                    for (j = 0; j < 6; j++) {
                        if (meta->entries[j] && record.entries[i] == meta->entries[j])
                            break;
                    }
                    if (j == 6)
                        maximum = value;
                }
            }
        }
        extra = Unk0ddeb0_Unk_0ddfe8(maximum);
        if (record.value1e >= 100)
            multiplier = 1;
        scale = Unk0ddeb0_GetRes15Word0();
        base = Unk0ddeb0_GetRes15Word1();
        result = scale * (multiplier * (base + (extra + coefficient * sum * sum * sum / 1000))) / 200;
        if (result > 99999999)
            result = 99999999;
    }
    return result;
}

/* Resolve a 36-byte record, then calculate a capped value from metadata bytes
 * 26..30 and coefficient 44. Evidence: loads, resource calls and divisions in
 * 020de194; a failed resolver returns zero. */
u32 func_020de194(u32 id)
{
    Unk0ddeb0Record record;
    u32 result = 0;
    if (Unk02e000_SetRecord(id, &record)) {
        Unk0ddeb0Meta *meta = func_020a1428(id);
        u32 coefficient = meta->coefficient;
        s32 sum = meta->values[0] + meta->values[4] + meta->values[1] + meta->values[2] + meta->values[3];
        u32 multiplier = 2;
        u32 scale, base;
        if (record.value1e >= 100)
            multiplier = 1;
        scale = Unk0ddeb0_GetRes15Word0();
        base = Unk0ddeb0_GetRes15Word1();
        result = scale * (multiplier * (base + coefficient * sum * sum * sum / 1000)) / 200;
        if (result > 99999999)
            result = 99999999;
    }
    return result;
}

/* Calculate the same six-entry adjusted value using a caller-owned record.
 * Evidence: 020de258 reads the second argument directly and compares its entries
 * against metadata at offset 46; both pointers must remain valid during calls. */
u32 func_020de258(u32 id, const Unk0ddeb0Record *record)
{
    Unk0ddeb0Meta *meta = func_020a1428(id);
    s32 sum = record->values[0] + record->values[1] + record->values[2] + record->values[3] + record->values[4];
    u32 coefficient = meta->coefficient;
    u32 multiplier = 2;
    s32 maximum = 0;
    s32 i;
    u32 extra, scale, base, result;
    for (i = 0; i < 6; i++) {
        if (record->entries[i]) {
            s32 j;
            s32 value = func_020e6874(record->entries[i])[3];
            if (value > maximum) {
                for (j = 0; j < 6; j++) {
                    if (meta->entries[j] && record->entries[i] == meta->entries[j])
                        break;
                }
                if (j == 6)
                    maximum = value;
            }
        }
    }
    extra = Unk0ddeb0_Unk_0ddfe8(maximum);
    if (record->value1e >= 100)
        multiplier = 1;
    scale = Unk0ddeb0_GetRes15Word0();
    base = Unk0ddeb0_GetRes15Word1();
    result = scale * (multiplier * (base + (extra + coefficient * sum * sum * sum / 1000))) / 200;
    if (result > 99999999)
        result = 99999999;
    return result;
}
