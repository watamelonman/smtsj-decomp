/*
 * src/game/unit_020cb32c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#include "game/unit_020cb32c.h"

void func_0205e484(u32 arg0, u32 group);
u32 func_020cb3dc(void);
int Unk0cb32c_Unk_0cb4e4(u32 arg0, u32 arg1);
int Unk0cb32c_Unk_0cb564(u32 arg0, u32 unused);
void Unk122a78_Unk_122a78(void);
void Unk122a78_Unk_122aa0(void);
void Unk1241ec_Unk_1241ec(void);
void Unk1241ec_Unk_124214(void);
void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_124258(void);

void Unk0cb32c_Nop_0cba74(void);
void Unk0cb32c_Nop_0cccc0(void);
void Unk0cb32c_Unk_0cb35c(u32 arg0);
void Unk0cb32c_Unk_0cb57c(u32 arg0);
u32 Unk0cb32c_Unk_0cb32c(void);
u32 Unk0cb32c_Unk_0cb344(void);
u32 Unk0cb32c_Unk_0cb54c(void);

/* Original 020cba74 is only BX LR: this callback has no side effects. */
void Unk0cb32c_Nop_0cba74(void) { }

/* Original 020cccc0 is only BX LR: this callback has no side effects. */
void Unk0cb32c_Nop_0cccc0(void) { }

/* Forward arg0 with group 30 to 0205e484; original 020cb35c sets r1 to 30. */
void Unk0cb32c_Unk_0cb35c(u32 arg0)
{
  func_0205e484(arg0,0x1e);
}

/* Forward arg0 to 020cb564; original 020cb57c also clears unused r1. */
void Unk0cb32c_Unk_0cb57c(u32 arg0)
{
  Unk0cb32c_Unk_0cb564(arg0, 0);
}

/* Call 122a78, 124338 and 1241ec in that order, then return 1; evidenced by the three BL instructions at 020cb330..020cb338. */
u32 Unk0cb32c_Unk_0cb32c(void)
{
  Unk122a78_Unk_122a78();
  Unk1241ec_Thunk_02124338();
  Unk1241ec_Unk_1241ec();
  return 1;
}

/* Call 124214, 124258 and 122aa0 in that order, then return 1; evidenced by the three BL instructions at 020cb348..020cb350. */
u32 Unk0cb32c_Unk_0cb344(void)
{
  Unk1241ec_Unk_124214();
  Unk1241ec_Unk_124258();
  Unk122a78_Unk_122aa0();
  return 1;
}

/* Pass only the low byte returned by 020cb3dc to 020cb4e4 with index 0; original 020cb554 masks r0 with 255. */
u32 Unk0cb32c_Unk_0cb54c(void)
{
  u8 value;
  value = func_020cb3dc();
  return Unk0cb32c_Unk_0cb4e4(value,0);
}

int Unk0cb32c_Unk_0cca80(u8 *work);
/* Store the new state after calling 0cca80 on the same borrowed work when
 * state is 2; evidenced by the conditional BL and STR at 020ccac0. */
void Unk0cb32c_Unk_0ccaa8(int *arg0,int arg1)
{
  if (arg1 == 2) {
    Unk0cb32c_Unk_0cca80((u8 *)arg0);
  }
  *arg0 = arg1;
}

void Unk095560_Unk_0956c8(void);
int Unk0de678_Get_data_021508d4(void);
int Unk0bc1a8_Unk_0bc9b4(u32 value, u32 flags);
void Unk0de678_Unk_0de870(void);
/* If the 1508d4 getter returns zero, call 0bc9b4(15, 0) then 0cb344;
 * always call 0de870 and 0956c8 afterward (BL order at 020cba7c..020cbaa0). */
void Unk0cb32c_Unk_0cba78(void)
{
  int value;
  value = Unk0de678_Get_data_021508d4();
  if (value == 0) {
    Unk0bc1a8_Unk_0bc9b4(0xf,0);
    Unk0cb32c_Unk_0cb344();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
}

void func_02122e1c(u32 handle);
void ImageBg_Unk_0e5530(void);
void Unk0fd268_Unk_0fd3ac(void);
/* Release the borrowed handle and clear its slot before the four cleanup calls;
 * evidence: LDR/BL/STR and BL order at 020cb754..020cb788. */
void Unk0cb32c_Unk_0cb754(u32 *arg0)
{
  Unk0bc1a8_Unk_0bc9b4(10,0);
  func_02122e1c(*arg0);
  *arg0 = 0;
  ImageBg_Unk_0e5530();
  Unk0fd268_Unk_0fd3ac();
  Unk0cb32c_Unk_0cb344();
  Unk0de678_Unk_0de870();
}

/* Map selectors 0..4 to 6,8,7,9,5; preserve other unsigned values.
 * Evidence: unsigned jump-table bound and MOV returns at 020cb440. */
u32 Unk0cb32c_Unk_0cb440(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 6;
  case 1:
    return 8;
  case 2:
    return 7;
  case 3:
    return 9;
  case 4:
    return 5;
  default:
    return arg0;
  }
}

void func_02059f70(u32 handle, u32 zero, s32 x, s32 y, void *descriptor, u32 flags, u32 value);
void func_02060dd4(void *descriptor, const u32 *handle, u32 zero, u32 index, u32 value);
/* Build a 16-byte descriptor and submit it with the borrowed handle and coordinates;
 * evidence: stack buffer and two BLs at 020cb488..020cb4e0. */
void Unk0cb32c_Unk_0cb488(u32 *arg0,s32 arg1,s32 arg2,u32 arg3,
                  u32 arg4,u32 arg5)
{
  u8 auStack_24 [16];
  func_02060dd4(auStack_24,arg0,0,arg3,arg4);
  func_02059f70(*arg0,0,arg1,arg2,auStack_24,0,arg5);
}

int func_020445f4(u32 group, u32 index);
int func_0204fed8(int handle, u32 index);
/* Resolve group 30 and arg0, then forward the result and arg1 to 04fed8;
 * constants and call order follow 020cb4e4..020cb500. */
int Unk0cb32c_Unk_0cb4e4(u32 arg0, u32 arg1)
{
    return func_0204fed8(func_020445f4(0x1e, arg0), arg1);
}

int Unk0a0ce4_Unk_0a0da4(u32 value);
void func_02063920(u32 handle);
int func_02063a30(int handle);
void func_02061f10(u32 handle, int index, u32 zero, u32 flags, int value);
int func_0205caa0(u32 value);
int func_0205ca88(u32 value);
int Unk0e651c_Unk_0e666c(u32 index);
int Unk122e1c_Unk_122f88(u32 handle, u32 index, int value);
/* Reset a handle, resolve (b,c), then submit its converted value with index -1;
 * evidence: four ordered BLs and stack fifth argument at 020cb504. */
void Unk0cb32c_Unk_0cb504(u32 a, u32 b, u32 c)
{
    func_02063920(a);
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk0cb32c_Unk_0cb4e4(b, c)));
}

/* Borrow writable work through +0x0c: call 0a0da4(5), set +8 to 4,
 * enter state 13, then store arg1 at +0x0c; original STR/BL order is retained. */
void Unk0cb32c_Unk_0ccac8(u8 *arg0,u32 arg1)
{
  Unk0a0ce4_Unk_0a0da4(5);
  *(u32 *)(arg0 + 8) = 4;
  Unk0cb32c_Unk_0ccaa8((int *)arg0, (int)0xd);
  *(u32 *)(arg0 + 0xc) = arg1;
}

/* Borrowed, word-aligned work prefix used by the two target state helpers.
 * Padding exposes only offsets established by their original LDR/STRs. */
typedef struct Unk0cb32cStateWork {
    s32 state;
    u32 reserved_004;
    u32 field_008;
    u8 reserved_00c[0x88];
    u32 handle_094;
    u8 reserved_098[0x10];
    u32 selector_0a8;
    u8 reserved_0ac[0x2c];
    u32 field_0d8;
} Unk0cb32cStateWork;

void Unk122e1c_Unk_123294(u32 handle);
/* Clear the +0x94 handle through its provider, store the new +0xd8 value,
 * set +8 to 1 and enter state 3; STR/BL evidence at 020ccaf8. */
void Unk0cb32c_Unk_0ccaf8(Unk0cb32cStateWork *arg0,u32 arg1)
{
  Unk122e1c_Unk_123294(arg0->handle_094);
  arg0->field_0d8 = arg1;
  arg0->field_008 = 1;
  Unk0cb32c_Unk_0ccaa8((int *)arg0, (int)3);
}

void func_0205c41c(void);
int func_0205c6ec(u32 value);
/* Call 05c41c then forward arg0 to 05c6ec; 020cb564 preserves arg0 in r4.
 * The wrapper at 020cb57c supplies an unused second register argument. */
int Unk0cb32c_Unk_0cb564(u32 arg0, u32 unused)
{
  func_0205c41c();
  return func_0205c6ec(arg0);
}

/* Return the signed >= comparison of 05caa0(x) and 05ca88(x);
 * original CMP uses MOVGE/MOVLT at 020cb5a8..020cb5b0. */
int Unk0cb32c_Unk_0cb58c(u32 x)
{
    return func_0205caa0(x) >= func_0205ca88(x);
}

/* Test whether provider entry 0x752 is zero (literal and CMP at 020cb7f4..020cb800). */
int Unk0cb32c_Unk_0cb7f0(void)
{
    return Unk0e651c_Unk_0e666c(0x752) == 0;
}

/* Borrow readable work through +0x94; pass that word, zero and provider
 * entry 0x5f1 to 122f88, following LDR/MOV/BL at 020cca88..020cca9c. */
int Unk0cb32c_Unk_0cca80(u8 *p)
{
    return Unk122e1c_Unk_122f88(FIELD(u32, p, 148), 0, Unk0e651c_Unk_0e666c(0x5f1));
}

/* Inspect +0x124 without changing work; original LDR/CMP/BX has no branch or
 * store. Both paths return without changing the work. */
void func_020cccb4(const Unk0cb32cWork *work)
{
    if (work->field_124 != 0) {
        return;
    }
}

u32 Unk095560_Unk_095a2c(u32 value);
int func_020de8b0(int bypass);
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 value, u32 source);
void func_020bc9f4(u32 slot, u32 source);
/* Forward the current selector, then initialize slots only when de8b0(0)
 * returns zero; evidence: conditional return and BL order at 020cba20. */
void func_020cba20(void)
{
    Unk095560_Unk_095a2c(func_020cb3dc());
    if (func_020de8b0(0) != 0) return;
    Unk0cb32c_Unk_0cb32c();
    Unk0bc1a8_Unk_0bc928(15, 65535, 0);
    Unk0bc1a8_Unk_0bc928(16, 15, 0);
    func_020bc9f4(16, 0);
}

void Unk1241ec_Unk_124224(u32 value);
/* Select a provider mode from the low halfword at +0xa8; selector zero
 * also tests entry 0x5f1. Evidence: shifts, branches and BLs at 020ccc64. */
void func_020ccc64(const Unk0cb32cStateWork *work)
{
    u32 value;
    switch ((u16)work->selector_0a8) {
    case 0: value = Unk0e651c_Unk_0e666c(0x5f1) ? 0 : 3; break;
    case 1: value = 1; break;
    default: value = 2; break;
    }
    Unk1241ec_Unk_124224(value);
}

/* Borrowed descriptor prefix; callback signatures remain opaque because this
 * initializer only stores their addresses and never invokes them. */
typedef struct Unk0cb32cDescriptor {
    u32 size;
    u32 flags;
    u32 reserved_008;
    void (*callbacks[6])(void);
} Unk0cb32cDescriptor;
void func_020cbce4(Unk0cb32cFullWork *work);
void func_020cc5d8(Unk0cb32cFullWork *work);
void func_020cbc50(Unk0cb32cFullWork *work);
void func_020cccc4(Unk0cb32cFullWork *work, const void *event);
/* Fill the descriptor size, flags and six callback addresses, leaving +8 intact;
 * evidence: STR offsets and relocated literals at 020cbaa4..020cbafc. */
void func_020cbaa4(Unk0cb32cDescriptor *descriptor)
{
    descriptor->size = 0x130;
    descriptor->flags = 0;
    descriptor->callbacks[0] = (void (*)(void))func_020cbce4;
    descriptor->callbacks[1] = (void (*)(void))func_020cc5d8;
    descriptor->callbacks[2] = (void (*)(void))func_020cccb4;
    descriptor->callbacks[3] = Unk0cb32c_Nop_0cccc0;
    descriptor->callbacks[4] = (void (*)(void))func_020cbc50;
    descriptor->callbacks[5] = (void (*)(void))func_020cccc4;
}

/* Map provider selectors 8,7,9,5 to 1,2,3,4; the original jump table
 * at 020cb3f0 defaults all other unsigned selectors to 1. */
u32 func_020cb3dc(void)
{
    switch (Unk02cad4_GetUnk00()) {
    case 8: return 1;
    case 7: return 2;
    case 9: return 3;
    case 5: return 4;
    default: return 1;
    }
}

/* Release each nonzero list handle, then the display slot, and clear +0x124;
 * list bounds are re-read each iteration as in 020ccb28. Work is borrowed. */
void func_020ccb28(Unk0cb32cFullWork *work)
{
    int i;
    Unk0bc1a8_Unk_0bc9b4(16,0);
    Unk044394_Unk_044534(37);
    for (i=0; i<Unk0de678_CountLeading(work->list); i++) {
        if (work->handles[i]) {
            func_020ffebc(work->handles[i]);
            work->handles[i]=0;
        }
    }
    Unk0cb32c_Unk_0cb754((u32 *)&work->display);
    work->field_124=0;
}

/* Dispatch provider results 1/2/3 to teardown, paired updates, or the saved
 * state respectively; CMP/BL evidence at 020cc21c. Work remains borrowed. */
void func_020cc21c(Unk0cb32cFullWork *work, u32 value)
{
    switch(func_020cb5b4(value,&work->field_004)) {
    case 1: func_020ccb28(work); break;
    case 2: func_020ccba0(work); Unk0cb32c_Unk_0cca80((u8 *)work); break;
    case 3: Unk0cb32c_Unk_0ccaa8((int *)work,work->field_008); break;
    }
}

/* Draw paired passes from nested +0xe0, offsetting the first y by one;
 * 020cb8f8 guards the global work pointer and brackets the first pass. */
void func_020cb8f8(s32 x, s32 y, u32 value)
{
    if (!data_02176bc4) return;
    func_02057ddc(255);
    func_02060b60(1,data_02176bc4->display->field_0e0,x,y+1,0,value);
    func_02057df8();
    func_02060b60(1,data_02176bc4->display->field_0e0,x,y,0,value);
}

/* Same paired provider calls using nested +0xe4; original loads and BL order
 * at 020cb98c establish the field and the first-pass y offset. */
void func_020cb98c(s32 x, s32 y, u32 value)
{
    if (!data_02176bc4) return;
    func_02057ddc(255);
    func_02060b60(1,data_02176bc4->display->field_0e4,x,y+1,0,value);
    func_02057df8();
    func_02060b60(1,data_02176bc4->display->field_0e4,x,y,0,value);
}

/* Release list handles, providers and display, then detach global work;
 * ownership and cleanup order follow the STRs and BLs at 020cbc50. */
void func_020cbc50(Unk0cb32cFullWork *work)
{
    int i;
    Unk044394_Unk_044534(37);
    Unk0bc1a8_Unk_0bc9b4(10,0);
    for (i=0; i<Unk0de678_CountLeading(work->list); i++) {
        if (work->handles[i]) {
            func_020ffebc(work->handles[i]);
            work->handles[i]=0;
        }
    }
    Unk0fd268_Unk_0fd3ac();
    ImageBg_Unk_0e5530();
    func_02122e1c((u32)work->display);
    work->display=0;
    Unk0de678_Unk_0dea60();
    data_02176bc4=0;
}

/* Build the 68-byte provider descriptor: two flag bytes, sixteen words,
 * low flag 0x80 and selector at +0x20; evidenced by 020cb36c's loops/STRs. */
void func_020cb36c(void)
{
    struct { u8 flags[2]; u16 reserved; u32 words[16]; } descriptor;
    int i;
    for (i=0;i<2;i++) descriptor.flags[i]=0;
    for (i=0;i<16;i++) descriptor.words[i]=0;
    descriptor.words[7]=Unk0cb32c_Unk_0cb54c();
    descriptor.flags[0] |= 0x80;
    Unk0bc1a8_Unk_0bc928(36,65535,(u32)&descriptor);
}

/* Each original list record occupies 26 bytes, with its ID at +2. */
typedef struct Unk0cb32cRecord { u8 bytes[2]; u16 id; u8 rest[22]; } Unk0cb32cRecord;
/* Borrowed list prefix: four records start at work +0x28. */
typedef struct Unk0cb32cListView { u8 prefix[0x28]; Unk0cb32cRecord records[4]; } Unk0cb32cListView;

void func_020cb78c(void *slot, u32 selector);
u32 func_020ffd48(u32 entry, int index, int count);
int func_02117170(void);
void func_0212351c(void *display, int count, u32 value);
void Unk044394_Unk_044428(u32 selector);
/* func_020ccba0 remains undefined here: the target instruction stream is
 * reproduced in C, but mwccarm assigns work=+r4/count=+r6 instead of the
 * original work=+r7/count=+r4. The delinked original supplies it; see
 * docs/functions/game-unit-020cb32c.md (hard list). */

/* Select nested +0x94/+0x98 using +0x64, then draw two passes;
 * evidence: branch and paired provider BLs at 020cb810. */
void func_020cb810(s32 x,s32 y,u32 value)
{
    if(!data_02176bc4) return;
    func_02057ddc(255);
    if(FIELD(u32,data_02176bc4->display,0x64)==0) {
        func_02060b60(1,FIELD(u32,data_02176bc4->display,0x94),x,y+1,0,value);
        func_02057df8();
        func_02060b60(1,FIELD(u32,data_02176bc4->display,0x94),x,y,0,value);
    } else {
        func_02060b60(1,FIELD(u32,data_02176bc4->display,0x98),x,y+1,0,value);
        func_02057df8();
        func_02060b60(1,FIELD(u32,data_02176bc4->display,0x98),x,y,0,value);
    }
}

void Unk122e1c_Unk_122ff0(void *display);
void Unk0fedd4_SetState1b(void);
void Unk124c5c_Set_124d6c(u32 a,u32 b);
void Unk124c5c_Set_124d8c(u32 a,u32 b);
int Unk124c5c_IsKind31(void);
int Unk122e1c_Unk_122f54(void *display);
void func_020e7f44(u32 a,u32 b,u32 c,u32 d);
int func_020523a8(void);
void func_020bcacc(u32 slot,void *descriptor);
void Unk1241ec_Unk_1242b4(u32 value);
int Unk0bc1a8_IsSlotEmptyOrFlag8(u32 slot);
void func_02124c5c(void);
void Unk122e1c_Unk_123048(void *display);
int Unk124c5c_IsKind0(void);
int Unk122e1c_Unk_122f68(void *display);
/* Advance the byte substate only after each provider completes; borrowed work
 * must cover +0xdc. Evidence: five-way switch and BL guards at 020cc27c. */
void func_020cc27c(Unk0cb32cFullWork *work)
{
    switch(FIELD(u8,work,4)) {
    case 0:
        Unk122e1c_Unk_122ff0(work->display);
        Unk0fedd4_SetState1b();
        Unk124c5c_Set_124d6c(0,1);
        Unk124c5c_Set_124d8c(1,0);
        FIELD(u8,work,4)++;
        break;
    case 1:
        if(!Unk124c5c_IsKind31()) return;
        if(!Unk122e1c_Unk_122f54(work->display)) return;
        func_020e7f44(0,0,0,0);
        FIELD(u8,work,4)++;
        break;
    case 2:
        if(func_020523a8()==1) return;
        func_020bcacc(16,(u8 *)work+0xdc);
        Unk1241ec_Unk_1242b4(0);
        FIELD(u8,work,4)++;
        break;
    case 3:
        if(!Unk0bc1a8_IsSlotEmptyOrFlag8(16)) return;
        func_02124c5c();
        Unk122e1c_Unk_123048(work->display);
        Unk1241ec_Unk_1242b4(1);
        Unk124c5c_Set_124d8c(0,31);
        FIELD(u8,work,4)++;
        break;
    case 4:
        if(!Unk124c5c_IsKind0()) return;
        if(!Unk122e1c_Unk_122f68(work->display)) return;
        FIELD(u8,work,4)=0;
        Unk0cb32c_Unk_0ccaa8((int *)work,4);
        break;
    }
}

void func_0205257c(u32 value);
int func_02052728(void);
void func_0209b774(u32 value);
void func_0209b960(void);
void func_020bcbc4(u32 value,void *descriptor);
int Unk09a268_Unk_09bb38(void);
int Unk0bc1a8_IsSlotEmpty(u32 slot);
int ImageBg_IsMode1or2(void);
void func_020525cc(u32 value);
/* Drive the six byte substates, returning completion codes 1/2/3; evidence:
 * original 020cb5b4 switch, descriptor loops and guarded byte writeback. */
int func_020cb5b4(u32 value,u32 *field)
{
    u8 state=*(u8 *)field;
    int result=0;
    struct { u8 flags[2]; u16 reserved; u32 words[16]; } descriptor;
    int i;
    switch(state) {
    case 0:
        func_0205257c(0);
        state++;
        break;
    case 1:
        if(!func_02052728()) { state++; result=1; }
        break;
    case 2:
        switch(value) {
        case 0: func_0209b774(2); break;
        case 1:
            func_0209b960();
            for(i=0;i<2;i++) descriptor.flags[i]=0;
            for(i=0;i<16;i++) descriptor.words[i]=0;
            descriptor.words[7]=3;
            descriptor.flags[0]|=128;
            func_020bcbc4(2,&descriptor);
            break;
        case 2:
            Unk044394_Unk_044428(30);
            func_020cb36c();
            break;
        }
        state++;
        break;
    case 3:
        switch(value) {
        case 0: case 1:
            if(Unk09a268_Unk_09bb38()) { state++; result=2; }
            break;
        case 2:
            if(Unk0bc1a8_IsSlotEmpty(36)) {
                Unk044394_Unk_044534(30);
                state++;
                result=2;
            }
            break;
        }
        break;
    case 4:
        if(!ImageBg_IsMode1or2()) { func_020525cc(0); state++; }
        break;
    case 5:
        if(!func_02052728()) { result=3; state=0; }
        break;
    }
    *(u8 *)field=state;
    return result;
}

void func_020de960(void *list,u32 value);
void *func_02122abc(void);
void ImageBg_Unk_0e54d4(u32 selector);
void Unk0fd268_Unk_0fd380(u32 value);
void Unk0bcef4_Unk_0bcef4(void *work,u32 a,u32 b,u32 c);
void func_02052634(u32 a,u32 b,u32 c);
/* Initialize the borrowed 0x130-byte work and its owned handles; evidence:
 * list stride 26, provider BLs and explicit stores at 020cbb00. */
void func_020cbb00(Unk0cb32cFullWork *work)
{
    int i;
    func_020de960(work->list,4);
    work->display=func_02122abc();
    ImageBg_Unk_0e54d4(FIELD(u8,work,0x28));
    Unk0fd268_Unk_0fd380(2);
    FIELD(int,work,0xd0)=Unk0de678_CountLeading(work->list);
    for(i=0;i<FIELD(int,work,0xd0);i++) {
        u32 handle;
        if(FIELD(u16,work,0x2a)==604)
            handle=func_020ffd48(((Unk0cb32cListView *)work)->records[i].id,i-1,FIELD(int,work,0xd0)-1);
        else
            handle=func_020ffd48(((Unk0cb32cListView *)work)->records[i].id,i,FIELD(int,work,0xd0));
        work->handles[i]=handle;
    }
    FIELD(u32,work,0xd4)=0;
    func_02117170();
    func_0212351c(work->display,FIELD(int,work,0xd0),1);
    Unk0bc1a8_Unk_0bc928(10,15,0);
    Unk044394_Unk_044428(37);
    func_02117170();
    Unk0bcef4_Unk_0bcef4((u8 *)work+0x98,3,3,1);
    Unk0bcef4_Unk_0bcef4((u8 *)work+0xb4,4,4,1);
    data_02176bc4=work;
    FIELD(u8,work,4)=0;
    FIELD(u32,work,0xd8)=5;
    work->state=0;
    work->field_008=2;
    FIELD(u32,work,0x120)=0;
    work->field_124=1;
    work->field_00c=0;
    FIELD(u32,work,0x12c)=0;
    func_020ccc64((Unk0cb32cStateWork *)work);
    Unk0cb32c_Unk_0cb35c(FIELD(u8,work,0x29));
    func_02052634(1,0,31);
}

/* Providers use this nullable, borrowed 68-byte descriptor; bit n marks
 * words[n] as present. Original accesses preserve unused bytes +2/+3. */
typedef struct Unk0cb32cParams { u8 flags[2]; u16 reserved; u32 words[16]; } Unk0cb32cParams;
/* Typed view of the descriptor fields inside the work allocation; using a
 * struct keeps the original scaled-index addressing (work + i, work + i*4).
 * See DEC-021. */
typedef struct Unk0cb32cWorkParams {
    u8 reserved_000[0xdc];
    u8 flags[2];
    u16 reserved_0de;
    u32 words[16];
} Unk0cb32cWorkParams;
static inline void ClearWorkParams(u8 *work)
{
    Unk0cb32cWorkParams *p=(Unk0cb32cWorkParams *)work;
    int i;
    if(work+0xdc) {
        for(i=0;i<2;i++) p->flags[i]=0;
        for(i=0;i<16;i++) p->words[i]=0;
    }
}
static inline void SetWorkParam(u8 *work,int index,u32 value)
{
    Unk0cb32cWorkParams *p=(Unk0cb32cWorkParams *)work;
    if(work+0xdc) {
        p->words[index]=value;
        p->flags[index/8]|=1<<(index%8);
    }
}
static inline void GetParam(const Unk0cb32cParams *p,int index,u32 *value)
{
    if(value && p) {
        u32 word=p->words[index];
        if(p->flags[index/8] & (1<<(index%8))) *value=word;
    }
}
u32 func_0211708c(void);
void func_02124ce8(u32 value);
void Unk122e1c_Unk_123024(void *display);
/* Advance the five byte substates and construct slot 16 parameters in borrowed
 * work +0xdc; evidence: descriptor flags and guarded BLs at 020cc3c0. */
void func_020cc3c0(Unk0cb32cFullWork *work)
{
    u32 value;
    switch(FIELD(u8,work,4)) {
    case 0:
        if(FIELD(u32,work,0x12c)) {
            Unk124c5c_Set_124d6c(0,1);
            Unk124c5c_Set_124d8c(1,0);
            FIELD(u8,work,4)++;
        } else {
            func_020e7f44(0,0,0,0);
            FIELD(u8,work,4)=2;
        }
        break;
    case 1:
        if(!Unk124c5c_IsKind31()) return;
        func_020e7f44(0,0,0,0);
        FIELD(u8,work,4)++;
        break;
    case 2:
        value=func_0211708c();
        ClearWorkParams((u8 *)work);
        if(value<=4 || value==8) SetWorkParam((u8 *)work,1,0);
        else SetWorkParam((u8 *)work,1,1);
        if(FIELD(u32,work,0x12c)) SetWorkParam((u8 *)work,3,2);
        else SetWorkParam((u8 *)work,3,1);
        func_020bcacc(16,(u8 *)work+0xdc);
        Unk1241ec_Unk_1242b4(0);
        FIELD(u8,work,4)++;
        break;
    case 3:
        if(!Unk0bc1a8_IsSlotEmptyOrFlag8(16)) return;
        Unk1241ec_Unk_1242b4(1);
        Unk124c5c_Set_124d8c(0,31);
        FIELD(u8,work,4)++;
        break;
    case 4:
        if(!Unk124c5c_IsKind0()) return;
        func_02124c5c();
        func_02124ce8(1);
        Unk122e1c_Unk_123024(work->display);
        FIELD(u8,work,4)=0;
        work->field_008=4;
        Unk0cb32c_Unk_0ccaa8((int *)work,2);
        break;
    }
}
void Unk0de678_Unk_0dec94(void *entry);
void CaveNpc_SetActive(u32 handle,u32 active);
void Unk124c5c_Unk_124cb0(void);
void Unk0bc1a8_Unk_0bc504(void *work,u32 value);
/* Interpret event kinds 1/3/4, hide list handles or select a stride-26 entry;
 * the one-element index array preserves the original zero-store order before
 * the state load (see DEC-021). Evidence: event jump table and flag tests at
 * 020cccc4. */
void func_020cccc4(Unk0cb32cFullWork *work,const void *event)
{
    const Unk0cb32cParams *params=(const Unk0cb32cParams *)((const u8 *)event+4);
    int i;
    switch(*(const u32 *)event) {
    case 0:
    case 2:
        break;
    case 3:
        {
        u32 index[1]={0};
        u32 value;
        if(work->state!=5) return;
        GetParam(params,3,index);
        value=index[0];
        if(value!=100) {
            FIELD(u32,work,0xd4)=value;
            Unk0de678_Unk_0dec94((u8 *)work+0x2c+value*26);
            work->field_008=5;
            Unk0cb32c_Unk_0ccaa8((int *)work,11);
        } else {
            for(i=0;i<Unk0de678_CountLeading(work->list);i++)
                CaveNpc_SetActive(work->handles[i],0);
            Unk124c5c_Unk_124cb0();
            Unk122e1c_Unk_123048(work->display);
            work->field_008=4;
            Unk0cb32c_Unk_0ccaa8((int *)work,2);
        }
        }
        break;
    case 1:
        Unk0bc1a8_Unk_0bc504(work,0);
        break;
    case 4:
        GetParam(params,7,&FIELD(u32,work,0x120));
        if(FIELD(u32,work,0x120)==100) {
            FIELD(u32,work,0x120)=0;
            func_020ccc64((Unk0cb32cStateWork *)work);
        } else {
            work->field_008=9;
            Unk0cb32c_Unk_0ccaa8((int *)work,7);
        }
        break;
    }
}

int func_020e807c(void);
int func_02053824(u32 device,u32 mask);
int func_02053800(u32 device,u32 mask);
void func_020bcc7c(void *selector);
void func_020bccec(void *selector);
void func_020bcfc4(void *selector,u32 value);
int Unk122e1c_Unk_122f94(void *display,u32 index);
void Unk122e1c_Unk_123534(void *display);
int func_02117208(void);
u32 func_02117250(void);
void Unk124c5c_Unk_124cc4(void);
/* Handle provider selection and input only in state 4, preparing nullable
 * descriptor fields for state 6; evidence: branches/BLs at 020cc5d8.
 * Work is borrowed and must cover the original 0x130-byte allocation. */
void func_020cc5d8(Unk0cb32cFullWork *work)
{
    int selection;
    u8 flag;
    u32 value;
    if(work->state!=4) return;
    selection=func_020e807c();
    if(selection>=0) {
        switch(selection) {
        case 0: Unk0cb32c_Unk_0ccac8((u8 *)work,2); break;
        case 1: Unk0cb32c_Unk_0ccac8((u8 *)work,0); break;
        case 2:
            if(Unk0e651c_Unk_0e666c(0x705))
                Unk0cb32c_Unk_0ccac8((u8 *)work,1);
            break;
        case 3: break;
        }
    } else {
        if(func_02053824(0,64)) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bcc7c((u8 *)work+0x98);
            func_020ccc64((Unk0cb32cStateWork *)work);
            return;
        }
        if(func_02053824(0,128)) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bccec((u8 *)work+0x98);
            func_020ccc64((Unk0cb32cStateWork *)work);
            return;
        }
        if(func_02053800(0,1024)) {
            Unk0cb32c_Unk_0ccac8((u8 *)work,2);
            return;
        }
        if(func_02053800(0,2048)) {
            Unk0cb32c_Unk_0ccac8((u8 *)work,0);
            return;
        }
        if(func_02053800(0,1)) {
            if(func_02117170()) {
                switch(FIELD(u32,work,0xa8)) {
                case 0:
                    if(!Unk122e1c_Unk_122f94(work->display,0)) {
                        Unk0a0ce4_Unk_0a0da4(4);
                        return;
                    }
                    Unk122e1c_Unk_123534(work->display);
                    Unk0a0ce4_Unk_0a0da4(1);
                    ClearWorkParams((u8 *)work);
                    SetWorkParam((u8 *)work,3,0);
                    flag=func_02117208()==0;
                    value=func_02117250();
                    SetWorkParam((u8 *)work,1,flag);
                    SetWorkParam((u8 *)work,2,value);
                    Unk0cb32c_Unk_0ccaa8((int *)work,6);
                    break;
                case 1:
                    if(FIELD(u32,work,0xd0)==0) {
                        Unk0a0ce4_Unk_0a0da4(4);
                        Unk0cb32c_Unk_0ccaa8((int *)work,4);
                    } else if(FIELD(u32,work,0xd0)==1) {
                        Unk0a0ce4_Unk_0a0da4(1);
                        Unk124c5c_Unk_124cc4();
                        Unk122e1c_Unk_122ff0(work->display);
                        work->field_008=11;
                        Unk0cb32c_Unk_0ccaa8((int *)work,3);
                    } else {
                        Unk0a0ce4_Unk_0a0da4(1);
                        Unk124c5c_Unk_124cc4();
                        Unk122e1c_Unk_122ff0(work->display);
                        work->field_008=5;
                        Unk0cb32c_Unk_0ccaa8((int *)work,3);
                    }
                    break;
                case 2:
                    Unk0a0ce4_Unk_0a0da4(1);
                    Unk124c5c_Unk_124cc4();
                    FIELD(u8,work,4)=0;
                    Unk0cb32c_Unk_0ccaa8((int *)work,14);
                    break;
                }
            } else {
                switch(FIELD(u32,work,0xa8)) {
                case 0:
                    if(!Unk122e1c_Unk_122f94(work->display,0)) {
                        Unk0a0ce4_Unk_0a0da4(4);
                        return;
                    }
                    Unk0a0ce4_Unk_0a0da4(1);
                    ClearWorkParams((u8 *)work);
                    SetWorkParam((u8 *)work,3,0);
                    value=func_02117250();
                    SetWorkParam((u8 *)work,1,0);
                    SetWorkParam((u8 *)work,2,value);
                    Unk0cb32c_Unk_0ccaa8((int *)work,6);
                    break;
                case 1:
                    if(FIELD(u32,work,0xd0)==0) {
                        Unk0a0ce4_Unk_0a0da4(4);
                        Unk0cb32c_Unk_0ccaa8((int *)work,4);
                    } else if(FIELD(u32,work,0xd0)==1) {
                        Unk0a0ce4_Unk_0a0da4(1);
                        Unk124c5c_Unk_124cc4();
                        Unk122e1c_Unk_122ff0(work->display);
                        work->field_008=11;
                        Unk0cb32c_Unk_0ccaa8((int *)work,3);
                    } else {
                        Unk0a0ce4_Unk_0a0da4(1);
                        Unk124c5c_Unk_124cc4();
                        Unk122e1c_Unk_122ff0(work->display);
                        work->field_008=5;
                        Unk0cb32c_Unk_0ccaa8((int *)work,3);
                    }
                    break;
                case 2:
                    Unk0a0ce4_Unk_0a0da4(1);
                    Unk124c5c_Unk_124cc4();
                    FIELD(u8,work,4)=0;
                    Unk0cb32c_Unk_0ccaa8((int *)work,14);
                    break;
                }
            }
            return;
        }
        if(func_02053800(0,2) && FIELD(u32,work,0xa8)!=2) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020bcfc4((u8 *)work+0x98,2);
            func_020ccc64((Unk0cb32cStateWork *)work);
        }
    }
}

/* Halfword alignment and 114-byte extent follow the original paired LDRH
 * copy at 020cbef8; the provider receives a value, not a borrowed pointer. */
typedef struct Unk0cb32cListValue { u16 words[57]; } Unk0cb32cListValue;
void Unk0fd268_SetDir(u32 value);
int func_020deb68(void);
int Unk116598_Unk_117114(void);
void Unk02cad4_Unk_02cbdc(u32 value);
int Unk0de678_Unk_0debf8(void);
void Unk0de678_Unk_0dec94(void *record);
void func_020deaa0(u32 slot, Unk0cb32cListValue list, u32 index);
u32 func_020fa92c(u32 index);
int func_020fa9a0(void);
int func_020dec18(void);
void func_0205e590(u32 value);
void func_02095f94(void);
void Unk02f2a8_Unk_035440(u32 value);
int func_020decd8(void);
void Unk124c5c_Unk_124cb0(void);
int func_0212356c(void *display, void *substate, void *params, u32 selector);
void Unk122e1c_SetUnkFields64_b0(void *display,u32 selector,u32 value);
/* Advance the 15-state callback and update the live display's two selectors.
 * Evidence: original jump table at 020cbd00, provider BL order, and the final
 * display guard at 020cc1f8. Work is borrowed and covers 0x130 bytes. */
void func_020cbce4(Unk0cb32cFullWork *work)
{
    int i;
    switch(work->state) {
    case 0:
        if(FIELD(u8,work,4)==0) {
            if(ImageBg_IsMode1or2()) break;
            Unk0fd268_SetDir(1);
            if(func_020deb68()) {
                func_02124c5c();
                func_02124ce8(1);
                func_020525cc(0);
                FIELD(u32,work,0x12c)=1;
                FIELD(u8,work,4)++;
            } else if(Unk116598_Unk_117114()) {
                Unk0cb32c_Unk_0ccaa8((int *)work,12);
            } else {
                func_02124c5c();
                func_02124ce8(1);
                func_020525cc(0);
                FIELD(u8,work,4)++;
            }
        } else if(!func_02052728()) {
            if(FIELD(u32,work,0x12c)) {
                Unk0cb32c_Unk_0ccaa8((int *)work,10);
                work->field_008=2;
            } else {
                Unk122e1c_Unk_123024(work->display);
                Unk0cb32c_Unk_0ccaa8((int *)work,work->field_008);
                work->field_008=4;
            }
            FIELD(u8,work,4)=0;
        }
        break;
    case 1:
        if(!func_02052728()) Unk02cad4_Unk_02cbdc(FIELD(u32,work,0xd8));
        break;
    case 2:
        if(Unk122e1c_Unk_122f68(work->display)) {
            func_020ccc64((Unk0cb32cStateWork *)work);
            Unk0cb32c_Unk_0ccaa8((int *)work,work->field_008);
        }
        break;
    case 3:
        if(!Unk122e1c_Unk_122f54(work->display)) break;
        Unk0cb32c_Unk_0ccaa8((int *)work,work->field_008);
        if(work->field_008==1) {
            if(Unk0de678_Unk_0debf8()) Unk0cb32c_Unk_0ccaa8((int *)work,10);
            else func_0205257c(0);
        } else if(work->field_008==11) {
            Unk0de678_Unk_0dec94((u8 *)work+0x2c);
            work->field_008=2;
        } else if(work->field_008==5) {
            /* Keep the reset in the index argument; See DEC-022. */
            func_020deaa0(15,*(Unk0cb32cListValue *)work->list,FIELD(u32,work,0xd4)=0);
        }
        break;
    case 5:
        FIELD(u32,work,0xd4)=func_020fa92c(FIELD(u32,work,0xd4));
        if(func_020fa9a0()) {
            for(i=0;i<Unk0de678_CountLeading(work->list);i++) CaveNpc_SetActive(work->handles[i],1);
        } else {
            for(i=0;i<Unk0de678_CountLeading(work->list);i++) {
                if(i==FIELD(u32,work,0xd4)) CaveNpc_SetActive(work->handles[i],0);
                else CaveNpc_SetActive(work->handles[i],1);
            }
        }
        break;
    case 6: func_020cc27c(work); break;
    case 7:
        if(func_020dec18()) {
            func_020bcacc(16,0);
            Unk0cb32c_Unk_0ccaa8((int *)work,8);
        } else {
            func_0205e590(10);
            func_0205257c(0);
            Unk0cb32c_Unk_0ccaa8((int *)work,9);
        }
        break;
    case 8:
        if(Unk0bc1a8_IsSlotEmpty(16)) {
            func_02095f94();
            Unk0cb32c_Unk_0ccaa8((int *)work,10);
        }
        break;
    case 9:
        if(!func_02052728()) {
            Unk02f2a8_Unk_035440(FIELD(u32,work,0x120)+1);
            Unk02cad4_Unk_02cbdc(3);
        }
        break;
    case 10:
        if(!func_020decd8()) break;
        if(work->field_008==2) {
            if(func_020deb68()) break;
            if(Unk116598_Unk_117114()) Unk0cb32c_Unk_0ccaa8((int *)work,12);
            else {
                Unk122e1c_Unk_123024(work->display);
                Unk0cb32c_Unk_0ccaa8((int *)work,work->field_008);
                work->field_008=4;
            }
        } else {
            if(Unk0de678_Unk_0debf8()) break;
            func_0205257c(0);
            Unk0cb32c_Unk_0ccaa8((int *)work,work->field_008);
        }
        break;
    case 11:
        if(!func_020decd8()) break;
        Unk0cb32c_Unk_0ccaa8((int *)work,work->field_008);
        if(work->field_008==5) {
            func_020deaa0(15,*(Unk0cb32cListValue *)work->list,FIELD(u32,work,0xd4));
        } else {
            Unk124c5c_Unk_124cb0();
            Unk122e1c_Unk_123048(work->display);
            work->field_008=4;
        }
        break;
    case 12: func_020cc3c0(work); break;
    case 13: func_020cc21c(work,work->field_00c); break;
    case 14:
        switch(func_0212356c(work->display,(u8 *)work+4,(u8 *)work+0xb4,FIELD(u32,work,0xa8))) {
        case 0:
            Unk124c5c_Unk_124cb0();
            func_020ccc64((Unk0cb32cStateWork *)work);
            Unk0cb32c_Unk_0ccaa8((int *)work,4);
            break;
        case 1:
            Unk0cb32c_Unk_0ccaf8((Unk0cb32cStateWork *)work,Unk0cb32c_Unk_0cb440(FIELD(u32,work,0xc4)+1));
            break;
        }
        break;
    }
    if(work->display) Unk122e1c_SetUnkFields64_b0(work->display,FIELD(u32,work,0xa8),FIELD(u32,work,0xc4));
}
