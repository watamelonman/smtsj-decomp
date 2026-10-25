/* Work-area accesses and helper calls recovered from the ARM object. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0ce578Work {
    s32 unk_0000;
    u32 unk_0004;
    u8 pad_0008[0x4];
    s32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0xc4];
    u32 unk_00d8;
} Unk0ce578Work;


/** Empty callback: the original consists solely of a return instruction. */
void Unk0ce578_Nop_0ce5e4(void) { }

s32 Unk0d297c_Unk_0d3138(void);
void Unk122e1c_Unk_122f88(u32 handle, s32 zero, s32 value);
/** Forward the global query to helper 122f88 with the borrowed +0x10 handle. */
void Unk0ce578_Unk_0cec98(Unk0ce578Work *arg0){
  u32 tmp1;
  tmp1 = Unk0d297c_Unk_0d3138();
  Unk122e1c_Unk_122f88(arg0->unk_0010,0,tmp1);
  return;
}

void Unk0ce578_SetState(Unk0ce578Work *work, s32 state);
void Unk122e1c_Unk_123294(u32 handle);
/** Reset the +0x10 handle, save the supplied value at +0xd8, and enter state 3. */
void Unk0ce578_Unk_0cf29c(Unk0ce578Work *arg0, u32 arg1){
  Unk122e1c_Unk_123294(arg0->unk_0010);
  arg0->unk_00d8 = arg1;
  arg0->unk_0004 = 1;
  Unk0ce578_SetState(arg0,3);
  return;
}

extern u8 data_02176bd0[];
void Unk095560_Unk_0956c8(void);
void Unk0bc1a8_Unk_0bc9b4(s32 value, s32 zero);
s32 Unk0de678_Get_data_021508d4(void);
void Unk0de678_Unk_0de870(void);
void Unk122a78_Unk_122aa0(void);
void Unk1241ec_Unk_124258(void);
/** Run the observed teardown sequence and clear the global word at +4. */
void Unk0ce578_Unk_0ce5e8(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    Unk0bc1a8_Unk_0bc9b4(0x14,0);
    Unk1241ec_Unk_124258();
    Unk122a78_Unk_122aa0();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
  ((u32 *)data_02176bd0)[1] = 0;
  return;
}

void Unk0a0ce4_Unk_0a0da4(s32 value);

/** Set the state word at +0; ARM callers and the conditional state-2 hook
 * support the existing SetState name. The work area remains caller-owned. */
void Unk0ce578_SetState(Unk0ce578Work *p, int k)
{
    if (k == 2) {
        Unk0ce578_Unk_0cec98(p);
    }
    p->unk_0000 = k;
}

/** Enter state 9 with the supplied value unless value 2 fails the global query. */
void Unk0ce578_Unk_0cf258(Unk0ce578Work *arg0, int arg1){
  int tmp1;
  if ((arg1 == 2) && (tmp1 = Unk0d297c_Unk_0d3138(), tmp1 == 0)) {
    return;
  }
  Unk0a0ce4_Unk_0a0da4(5);
  arg0->unk_0004 = 4;
  Unk0ce578_SetState(arg0,9);
  arg0->unk_000c = arg1;
  return;
}


