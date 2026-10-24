/* Optional scan-visor work access and forwarding helpers. */
#include "types.h"

/*
 * Work object stored in data_02176b04 (returned by ScanVisor_Get_data_02176b04).
 * Only the fields this TU reads are named; ScanVisor.c has its own local view of the
 * object and is not folded in here.
 */
typedef struct Unk0a23f4Work {
    u32 unk_0000;               /* +0x000: func_020a25e0 accepts 0 or 2 */
    u8  pad_0004[0x10];
    s32 unk_0014;               /* +0x014 */
    u8  pad_0018[0x14];
    s32 unk_002c;               /* +0x02c */
    u8  pad_0030[0x1e0];
    s32 unk_0210;               /* +0x210 */
    u8  pad_0214[0x38];
    u8  unk_024c[0x1dc];        /* +0x24c: slot block; size guessed (runs to +0x428) */
    u8  unk_0428[4];            /* +0x428: embedded block; size unknown */
} Unk0a23f4Work;

Unk0a23f4Work *ScanVisor_Get_data_02176b04(void);
int Unk0fd268_IsField8Zero(void);
int Unk0fd268_IsField8Neg81(void);
void func_02061424(void *work);
void func_020a2d0c(u32 arg0);

/* Preserve the predicate result; 0x020a2504 branches to the field-8-zero helper. */
int Unk0a23f4_Thunk_020fd428(void)
{
    return Unk0fd268_IsField8Zero();
}

/* Preserve the predicate result; 0x020a2588 branches to the field-8-minus-81 helper. */
int Unk0a23f4_Thunk_020fd450(void)
{
    return Unk0fd268_IsField8Neg81();
}

/* Pass the borrowed work pointer to 0x02061424 only when work exists. */
void Unk0a23f4_Unk_0a2414(void)
{
    Unk0a23f4Work *work = ScanVisor_Get_data_02176b04();
    if (work == 0) {
        return;
    }
    func_02061424(work);
}

extern u32 data_02176b04[];
/* The load from data_02176b04 at 0x020a242c tests whether work is present. */
int Unk0a23f4_IsSet_data_02176b04(void)
{
  return *data_02176b04 != 0;
}

/* Forward the opaque argument to 0x020a2d0c only while work is absent. */
void Unk0a23f4_Unk_0a23f4(u32 arg0)
{
  Unk0a23f4Work *value = ScanVisor_Get_data_02176b04();
  if (value != 0) {
    return;
  }
  func_020a2d0c(arg0);
}

int Unk0a7d54_HasField8(void *block);
int Unk0a7d54_IsField8Is3(void *block);
int Unk0a7d54_Unk_0a8648(void *block);
int ScanVisor_AllSlotsF28Is80(void *slots);
/* Return zero without work; otherwise query the embedded block at +0x428. */
int Unk0a23f4_Unk_0a2448(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return Unk0a7d54_HasField8(v->unk_0428);
}

/* Return zero without work; otherwise test the +0x428 block via 0x020a8628. */
int Unk0a23f4_Unk_0a246c(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return Unk0a7d54_IsField8Is3(v->unk_0428);
}

/* Return zero without work; otherwise query the +0x428 block via 0x020a8648. */
int Unk0a23f4_Unk_0a2490(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return Unk0a7d54_Unk_0a8648(v->unk_0428);
}

/* True when work exists and its +0x210 word is 0 (no work counts as false). */
int Unk0a23f4_IsField210Zero(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return v->unk_0210 == 0;
}

/* True when work exists and its +0x2c word is 0. */
int Unk0a23f4_IsField2cZero(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return v->unk_002c == 0;
}

/* True when work exists and its +0x14 word is 0. */
int Unk0a23f4_IsField14Zero(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return v->unk_0014 == 0;
}

/* True when work exists and its +0x210 word is 50. */
int Unk0a23f4_IsField210Is50(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return v->unk_0210 == 50;
}

/* True when work exists and its +0x2c word is 81. */
int Unk0a23f4_IsField2cIs81(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return v->unk_002c == 81;
}

/* True when work exists and its +0x14 word is -54. */
int Unk0a23f4_IsField14IsM54(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return v->unk_0014 == -54;
}

/* Return zero without work; otherwise query the slot block at +0x24c. */
int Unk0a23f4_Unk_0a25c0(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    return ScanVisor_AllSlotsF28Is80(v->unk_024c);
}

/*
 * True only when work exists, its +0x00 word is 0 or 2, and the five sibling checks
 * (+0x210 == 50, +0x2c == 81, the 0x020fd450 field-8 check, +0x14 == -54 and the
 * +0x24c slot query) all pass, evaluated in that order with early exit.
 */
int func_020a25e0(void)
{
    Unk0a23f4Work *v = ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 0;
    }
    if (v->unk_0000 == 0 || v->unk_0000 == 2) {
        if (!Unk0a23f4_IsField210Is50()) {
            return 0;
        }
        if (!Unk0a23f4_IsField2cIs81()) {
            return 0;
        }
        if (!Unk0a23f4_Thunk_020fd450()) {
            return 0;
        }
        if (!Unk0a23f4_IsField14IsM54()) {
            return 0;
        }
        if (!Unk0a23f4_Unk_0a25c0()) {
            return 0;
        }
        return 1;
    }
    return 0;
}
