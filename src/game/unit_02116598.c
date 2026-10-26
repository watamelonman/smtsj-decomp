/*
 * unit_02116598: empty callbacks and thin forwarders. Unk116598_Thunk_021177e0 and
 * Unk116598_Unk_1166f4 are called back-to-back from func_0203c320.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
/* Object passed as first arg; +0x13 is byte3 of unk_0010 (LE). */
typedef struct Unk116598Work {
    u32 unk_0000;
    s32 unk_0004;
    u32 unk_0008;
    s32 unk_000c;
    s32 unk_0010;
    u32 unk_0014;
    s32 unk_0018;
} Unk116598Work;
void Unk116598_Set(u32 a, u32 b);
void Unk116598_Reset(void);
int func_021172fc(void);

void func_02117360(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_02117400(u32 a, u32 b, u32 c, u32 d, u8 e);

/* Original 0x021166c0 reloads the byte fifth argument from the caller's stack
   (ldrb ip, [sp, #8]; str ip, [sp]) and calls func_02117360 with four word
   arguments plus that byte, returning whatever the callee leaves in r0. */
void Unk116598_Call_02117360(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117360(a, b, c, d, e);
}

/* Original 0x021166d4 is the same fifth-stack-argument forwarder as 0x021166c0,
   but calls func_02117400. */
void Unk116598_Call_02117400(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117400(a, b, c, d, e);
}

/* Original 0x02116b44 is only bx lr: return without changing caller state. */
void Unk116598_Nop_116b44(void) { }
/* Original 0x02116b68 is only bx lr: return without changing caller state. */
void Unk116598_Nop_116b68(void) { }
/* Original 0x02116b6c is only bx lr: return without changing caller state. */
void Unk116598_Nop_116b6c(void) { }
/* Original 0x02117928 pushes {r3, lr}, reloads the byte fifth argument from the
   incoming stack slot (ldrb ip, [sp, #8]), places it as the outgoing fifth
   argument (str ip, [sp]) and calls 0x02117360 with four words plus that byte. */
void Unk116598_Call_02117360b(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117360(a, b, c, d, e);
}

/* Same fifth-stack-argument forwarder as Unk116598_Call_02117360b, at
   0x0211793c, but calls 0x02117400. */
void Unk116598_Call_02117400b(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117400(a, b, c, d, e);
}

/* Original 0x02117cd0 is only bx lr: return without changing caller state. */
void Unk116598_Nop_117cd0(void) { }

/* Original literal at 0x021166f0 targets Set; forward both words unchanged. */
void Unk116598_Thunk_021177e0(u32 a, u32 b) { Unk116598_Set(a, b); }
/* Original literal at 0x021166fc targets Reset; preserve its no-argument contract. */
void Unk116598_Unk_1166f4(void) { Unk116598_Reset(); }
/* Original literal at 0x0211680c targets func_021172fc; forward control unchanged. */
void Unk116598_Unk_116804(void) { func_021172fc(); }
/* Original literal at 0x02117958 targets Set; forward both words unchanged. */
void Unk116598_Unk_117950(u32 a, u32 b) { Unk116598_Set(a, b); }



/* Original 0x0211795c loads the literal 0x02117808 and branches through it, so it
   tail-calls Unk116598_Reset with the caller's registers untouched. */
void Unk116598_Thunk_02117808(void) { Unk116598_Reset(); }

/* Original 0x02117a4c loads the literal 0x021172fc and branches through it, so it
   tail-calls func_021172fc with no arguments. */
void Unk116598_Thunk_021172fc(void) { func_021172fc(); }

/* data_02176e5c is a word-sized BSS cell (relocation at 0x02116838); the original at
   0x0211682c loads the cell's address, then the pointer stored in it, and returns that. */
extern u32 data_02176e5c[];
u32 Unk116598_Get_data_02176e5c(void)
{
    return *data_02176e5c;
}

/* Sibling of Unk116598_Get_data_02176e5c for the BSS cell at 0x02176e68 (the literal at
   0x02117a64); the original at 0x02117a58 returns the pointer stored there. */
extern u32 data_02176e68[];
u32 Unk116598_Get_data_02176e68(void)
{
    return *data_02176e68;
}

int Unk065e88_Unk_065eac();
int Unk095560_Unk_096130();
int Unk0a23f4_Unk_0a2414();
/* Original 0x021168b8 calls 0x02096130, 0x02065eac and 0x020a2414 in that order and
   discards their results; no argument setup or state is visible in this routine. */
void Unk116598_Unk_1168b8(void)
{
    Unk095560_Unk_096130();
    Unk065e88_Unk_065eac();
    Unk0a23f4_Unk_0a2414();
}

void Unk116598_Unk_1172dc(void);
void Unk116598_Unk_1177cc(u32 arg0);
/* Original 0x02116954 overwrites r0 with 0 before calling 0x021177cc, then calls
   0x021172dc. The caller (0x0211694c) still passes the work pointer in r0, so the
   parameter is kept for the call site's register setup even though it is not read. */
void Unk116598_Unk_116954(Unk116598Work *work)
{
    Unk116598_Unk_1177cc(0);
    Unk116598_Unk_1172dc();
}


extern u32 data_02176e60[];
/* Original 0x0211753c stores zero to the word-sized BSS cell data_02176e60
   (literal at 0x0211754c) and returns no value. */
void Unk116598_Clear_data_02176e60(void)
{
    *data_02176e60 = 0;
}

extern u32 data_02176e64[];
/* Original 0x02117914 stores zero to the word-sized BSS cell data_02176e64
   (literal at 0x02117924) and returns no value. */
void Unk116598_Clear_data_02176e64(void)
{
    *data_02176e64 = 0;
}


/* Original 0x02117ae4 pushes {r3, lr}, calls 0x02096130, 0x02065eac and
   0x020a2414 in that order, then returns through pop {r3, pc}. Results are
   discarded; the three callees' purposes are not evidence for this wrapper. */
void Unk116598_Unk_117ae4(void)
{
    Unk095560_Unk_096130();
    Unk065e88_Unk_065eac();
    Unk0a23f4_Unk_0a2414();
}


/* Original 0x02117b80 pushes {r3, lr}, overwrites r0 with zero and calls
   0x021177cc, then tail-returns after calling 0x021172dc. The work pointer is
   kept in the parameter list because its only caller (the call at 0x02117b78,
   inside Unk116598_Unk_117af8) passes it in r0, but this routine never reads it. */
void Unk116598_Unk_117b80(Unk116598Work *work)
{
    Unk116598_Unk_1177cc(0);
    Unk116598_Unk_1172dc();
}


int Unk116598_Unk_1171c8(int arg0, int arg1);
/* This call site passes a full register; the provider stores only its low byte.
   Use the observed word-wide ABI here to avoid caller narrowing. See DEC-020. */
void Unk02f078_Unk_02f20c(u32 value);
/* ARM 0x0211727c forwards both signed arguments to 0x021171c8, sends the
   mapped result to the byte setter at 0x0202f20c, and returns the full result. */
u32 Unk116598_Unk_11727c(int arg0, int arg1)
{
    u32 value = Unk116598_Unk_1171c8(arg0, arg1);
    Unk02f078_Unk_02f20c(value);
    return value;
}


/* ARM 0x02116700 writes the argument at +4 and one at +0xc in the
   work returned by 0x0211682c; the work pointer must be initialized. */
void Unk116598_Unk_116700(u32 arg0)
{
    Unk116598Work *work = (Unk116598Work *)Unk116598_Get_data_02176e5c();
    work->unk_0004 = arg0;
    work->unk_000c = 1;
}

void Unk116598_Unk_1167e0(void);
/* ARM 0x0211671c stores 1 at work +0, then calls 0x021167e0 and
   0x021168b8 in order. The global work cell must hold a valid pointer. */
void Unk116598_Unk_11671c(void)
{
    Unk116598Work *work = (Unk116598Work *)Unk116598_Get_data_02176e5c();
    work->unk_0000 = 1;
    Unk116598_Unk_1167e0();
    Unk116598_Unk_1168b8();
}


/* ARM 0x02116810 stores 2 at work +0, then calls 0x021167e0 and
   0x021168b8 in order. The global work cell must hold a valid pointer. */
void Unk116598_Unk_116810(void)
{
    Unk116598Work *work = (Unk116598Work *)Unk116598_Get_data_02176e5c();
    work->unk_0000 = 2;
    Unk116598_Unk_1167e0();
    Unk116598_Unk_1168b8();
}

int Unk065e88_Unk_065e88(void);
int func_020773dc(int arg0);
int Unk0a23f4_Unk_0a23f4(int arg0);
/* ARM 0x0211689c calls 0x020a23f4(2), 0x02065e88(), then
   0x020773dc(1), discarding results. No broader purpose is established. */
void Unk116598_Unk_11689c(void)
{
  Unk0a23f4_Unk_0a23f4(2);
  Unk065e88_Unk_065e88();
  func_020773dc(1);
}


/* ARM 0x02117968 writes the argument at +4 and one at +0xc in the
   work returned by 0x02117a58; the work pointer must be initialized. */
void Unk116598_Unk_117968(u32 arg0)
{
    Unk116598Work *work = (Unk116598Work *)Unk116598_Get_data_02176e68();
    work->unk_0004 = arg0;
    work->unk_000c = 1;
}


void Unk116598_Unk_117a28(void);
/* ARM 0x02117984 writes 1 at secondary work +0, then calls 0x02117a28
   and 0x02117ae4 in order. The global work pointer must be initialized. */
void Unk116598_Unk_117984(void)
{
  Unk116598Work *work = (Unk116598Work *)Unk116598_Get_data_02176e68();
  work->unk_0000 = 1;
  Unk116598_Unk_117a28();
  Unk116598_Unk_117ae4();
}


/* ARM 0x02117ac8 calls 0x020a23f4(2), 0x02065e88(), then
   0x020773dc(1), discarding results; no broader purpose is established. */
void Unk116598_Unk_117ac8(void)
{
  Unk0a23f4_Unk_0a23f4(2);
  Unk065e88_Unk_065e88();
  func_020773dc(1);
}


/* ARM 0x02116738 stores 3, the supplied word, and 1 at primary work
   offsets +4, +8 and +0xc. The global work pointer must be initialized. */
void Unk116598_Unk_116738(u32 arg0)
{
  Unk116598Work *work = (Unk116598Work *)Unk116598_Get_data_02176e5c();
  work->unk_0004 = 3;
  work->unk_0008 = arg0;
  work->unk_000c = 1;
}

u32 func_0211683c(void);
void Unk116598_Unk_117294(void);
void Unk116598_Unk_117790(void);
/* ARM 0x02116b48 calls 0x02117790 and 0x02117294, then replaces the
   primary work cell with the word returned by 0x0211683c. */
void Unk116598_Unk_116b48(void)
{
  u32 value;
  Unk116598_Unk_117790();
  Unk116598_Unk_117294();
  value = func_0211683c();
  *data_02176e5c = value;
}


int Unk02e000_Unk_02e774(void);
/* ARM 0x021171a8 tests the unsigned byte at provider work +0x5fc2 for
   equality to 1. The provider must return valid storage through that offset. */
int Unk116598_Unk_1171a8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return *(u8 *)(value + 0x5fc2) == 1;
}


/* ARM 0x021171c8 maps 5 to 8 when arg0 is zero; otherwise adds 5.
   Other values pass through in the zero case; parameters retain the signed-word interface. */
int Unk116598_Unk_1171c8(int arg0,int arg1)
{
  if (arg0 == 0) {
    if (arg1 == 5) {
      arg1 = 8;
    }
    return arg1;
  }
  return arg1 + 5;
}


/* ARM 0x021171e8 maps 8 to 5 when arg0 is zero; otherwise subtracts 5.
   Other values pass through in the zero case; parameters retain the signed-word interface. */
int Unk116598_Unk_1171e8(int arg0,int arg1)
{
  if (arg0 == 0) {
    if (arg1 == 8) {
      arg1 = 5;
    }
    return arg1;
  }
  return arg1 - 5;
}

int func_02061424(void);
/* ARM 0x021172bc calls 0x02061424 only while the BSS word at
   data_02176e60 is zero; a nonzero word returns without calling it. */
void Unk116598_Unk_1172bc(void)
{
  if (*data_02176e60 != 0) {
    return;
  }
  func_02061424();
}


int func_02117a68(void);
/* ARM 0x02117cd4 initializes both shared work cells, calls 0x02117a68,
   and stores its returned word in secondary work cell data_02176e68. */
void Unk116598_Unk_117cd4(void)
{
  u32 value;
  Unk116598_Unk_117790();
  Unk116598_Unk_117294();
  value = func_02117a68();
  *data_02176e68 = value;
}


int Unk02e000_GetWorkArea(void);
int func_02116c20(u16 id, u32 a, u32 b, int mode);
/* ARM 0x02117050 reads provider halfword +0x35c and calls 0x02116c20
   with mode 1; returns 2 only for result 1, otherwise 0. */
u32 Unk116598_Unk_117050(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = Unk02e000_GetWorkArea();
  value1 = func_02116c20(*(u16 *)(value1 + 0x35c),arg0,arg1,1);
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}

int func_02057524(u32 value);
int func_02057534(void);
void func_021176c0(u32 value, u8 byte, int mode);
/* ARM 0x02117620 requires borrowed work: +0x18 must be zero, +0xc
   must be 1 or 2, and +4 nonzero; brackets the mode-22 call with providers. */
void Unk116598_Unk_117620(Unk116598Work *work)
{
  if (work->unk_0018 != 0) {
    return;
  }
  if (work->unk_000c != 1 && work->unk_000c != 2) {
    return;
  }
  if (work->unk_0004 == 0) {
    return;
  }
  func_02057524(work->unk_0014);
  func_021176c0(work->unk_0008,((u8 *)&work->unk_0010)[3],0x16);
  func_02057534();
}


/* ARM 0x02117670 uses the same borrowed-work contract as 0x02117620,
   but accepts +0xc values 1 or 3; forwards +8 and byte +0x13. */
void Unk116598_Unk_117670(Unk116598Work *work)
{
  if (work->unk_0018 != 0) {
    return;
  }
  if (work->unk_000c != 1 && work->unk_000c != 3) {
    return;
  }
  if (work->unk_0004 == 0) {
    return;
  }
  func_02057524(work->unk_0014);
  func_021176c0(work->unk_0008,((u8 *)&work->unk_0010)[3],0x16);
  func_02057534();
}



int Unk0de678_Unk_0dee2c(int id);
/* ARM 0x02117114 marks the first available provider slot (0..8) whose byte
   at +0x5fba is zero; returns one on a new mark, zero otherwise. */
u32 Unk116598_Unk_117114(void)
{
  int value1;
  int value2;
  value2 = 0;
  do {
    value1 = Unk0de678_Unk_0dee2c(value2);
    if (value1 != 0) {
      value1 = Unk02e000_Unk_02e774();
      if (*(u8 *)(value1 + value2 + 0x5fba) == '\0') {
        value1 = Unk02e000_Unk_02e774();
        *(u8 *)(value1 + value2 + 0x5fba) = 1;
        return 1;
      }
    }
    value2 = value2 + 1;
  } while (value2 < 9);
  return 0;
}

int Unk02f2a8_Unk_035440(u32 value);
void Unk02cad4_Unk_02cbdc(s32 value);
int Unk044394_Unk_044534(int id);
int Unk095560_Unk_0956e8(void);
void func_021177b8(void);
/* ARM 02116968 tears down the borrowed work, clears global cell data_02176e5c
   and forwards +4 (and +8 when +4 is 3) to providers. Work must remain valid. */
void Unk116598_Unk_116968(Unk116598Work *work)
{
  Unk116598_Unk_1167e0();
  Unk095560_Unk_0956e8();
  Unk116598_Unk_1168b8();
  if (work->unk_0010 != 0) {
    Unk044394_Unk_044534(0x1e);
  }
  Unk116598_Unk_1172bc();
  func_021177b8();
  *data_02176e5c = 0;
  if (work->unk_0004 == 3) {
    Unk02f2a8_Unk_035440(work->unk_0008);
  }
  Unk02cad4_Unk_02cbdc(work->unk_0004);
}


/* ARM 02117b94 tears down the borrowed work, clears global cell data_02176e68
   and forwards +4 (and +8 when +4 is 3) to providers. Work must remain valid. */
void Unk116598_Unk_117b94(Unk116598Work *work)
{
  Unk116598_Unk_117a28();
  Unk095560_Unk_0956e8();
  Unk116598_Unk_117ae4();
  if (work->unk_0010 != 0) {
    Unk044394_Unk_044534(0x1e);
  }
  Unk116598_Unk_1172bc();
  func_021177b8();
  *data_02176e68 = 0;
  if (work->unk_0004 == 3) {
    Unk02f2a8_Unk_035440(work->unk_0008);
  }
  Unk02cad4_Unk_02cbdc(work->unk_0004);
}

/* Original 0x021177cc stores the word argument through the pointer held by
   BSS cell data_02176e64 (literal at 0x021177dc); no value is returned. */
void Unk116598_Unk_1177cc(u32 arg0)
{
    *(u32 *)*data_02176e64 = arg0;
}

void func_02117550(Unk116598Work *work);
/* ARM 0x021172dc calls 0x02117550 only when data_02176e60 is nonzero. */
void Unk116598_Unk_1172dc(void)
{
  if (*data_02176e60 == 0) {
    return;
  }
  func_02117550((Unk116598Work *)*data_02176e60);
}

int Unk0bc1a8_IsSlotEmpty(int slot);
void Unk0bc1a8_Unk_0bc9b4(int slot, int value);
/* ARM 0x021167e0 calls 0x020bc9b4(24, 0) only when the slot-empty
   predicate at 0x020bc650 returns zero. No work pointer is required. */
void Unk116598_Unk_1167e0(void)
{
  int tmp1;
  tmp1 = Unk0bc1a8_IsSlotEmpty(0x18);
  if (tmp1 != 0) {
    return;
  }
  Unk0bc1a8_Unk_0bc9b4(0x18,0);
}

/* ARM 0x02117a28 repeats the slot-24 predicate and conditional call
   to 0x020bc9b4(24, 0); no wider purpose is established. */
void Unk116598_Unk_117a28(void)
{
  int tmp1;
  tmp1 = Unk0bc1a8_IsSlotEmpty(0x18);
  if (tmp1 != 0) {
    return;
  }
  Unk0bc1a8_Unk_0bc9b4(0x18,0);
}

int func_021174d0(void);
/* ARM 0x02117294 populates data_02176e60 from 0x021174d0 only if
   the cell is zero; existing borrowed work is preserved. */
void Unk116598_Unk_117294(void)
{
  int tmp1;
  if (*data_02176e60 != 0) {
    return;
  }
  tmp1 = func_021174d0();
  *data_02176e60 = tmp1;
}

int func_021178c0(void);
/* ARM 0x02117790 populates data_02176e64 from 0x021178c0 only if
   the cell is zero; existing borrowed work is preserved. */
void Unk116598_Unk_117790(void)
{
  int tmp1;
  if (*data_02176e64 != 0) {
    return;
  }
  tmp1 = func_021178c0();
  *data_02176e64 = tmp1;
}

/* ARM 0x021174a0 stores 1 at +0x18 through BSS cell data_02176e60;
   the cell must contain a valid work pointer (literal at 0x021174b4). */
void Unk116598_Unk_1174a0(void)
{
    Unk116598Work *work = (Unk116598Work *)*data_02176e60;
    work->unk_0018 = 1;
}

/* ARM 0x021174b8 stores 0 at +0x18 through BSS cell data_02176e60;
   the cell must contain a valid work pointer (literal at 0x021174cc). */
void Unk116598_Unk_1174b8(void)
{
    Unk116598Work *work = (Unk116598Work *)*data_02176e60;
    work->unk_0018 = 0;
}

void func_02077314(void);
int Unk044394_HasEntry(int id);
s32 Unk044394_Unk_044428(int id);
int Unk095560_Unk_095b28(int id);
void Unk02d15c_Unk_02d91c(int a, int b);
void Unk02d15c_Setup(int a, int b, int c, int d);
void func_02095f94(void);

/* ARM 0x021168cc initializes primary borrowed work after provider setup;
   entry-30 allocation and provider mode 1 determine the stored fields. */
void Unk116598_Unk_1168cc(Unk116598Work *work)
{
    func_02077314();
    Unk116598_Unk_11689c();
    if (Unk044394_HasEntry(30) == 0) {
        work->unk_0010 = Unk044394_Unk_044428(30);
    }
    if (Unk095560_Unk_095b28(1) == 0) {
        return;
    }
    Unk02d15c_Unk_02d91c(8, 1);
    Unk02d15c_Setup(8, 41, 0, -1);
    func_02095f94();
    work->unk_0000 = 0;
    work->unk_0004 = 3;
    work->unk_0008 = 1;
    work->unk_000c = 0;
    Unk116598_Unk_116954(work);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk0de678_Unk_0dee2c(int id);
int Unk02e000_Unk_02e774(void);
int Unk02f078_Unk_02f220(void);
int func_02117208(void);
int func_02051ba4(void);
void Unk095560_Unk_0958a8(int a, int b);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

/* ARM 0x021177e0 stores 1, the low byte of a, b, and 0 at offsets
   +0, +8, +4, +12 through data_02176e64. Requires initialized work.
   The existing Set symbol is supported by these direct field writes. */
void Unk116598_Set(u32 a, u32 b)
{
    u8 *w = (u8 *)*data_02176e64;
    FIELD(u32, w, 0) = 1;
    w[8] = a;
    FIELD(u32, w, 4) = b;
    FIELD(u32, w, 12) = 0;
}

/* ARM 0x02117808 clears work words +0, +0x10 and +0x14, then calls
   0x020958a8(0, 0). Requires initialized data_02176e64. */
void Unk116598_Reset(void)
{
    u8 *w = (u8 *)*data_02176e64;
    FIELD(u32, w, 0) = 0;
    FIELD(u32, w, 16) = 0;
    FIELD(u32, w, 20) = 0;
    Unk095560_Unk_0958a8(0, 0);
}

/* ARM 0x02117af8 initializes secondary borrowed work using provider mode 2;
   requires writable work through +0x10. */
void Unk116598_Unk_117af8(Unk116598Work *work)
{
    func_02077314();
    Unk116598_Unk_117ac8();
    if (Unk044394_HasEntry(30) == 0) {
        work->unk_0010 = Unk044394_Unk_044428(30);
    }
    if (Unk095560_Unk_095b28(2) == 0) {
        return;
    }
    Unk02d15c_Unk_02d91c(8, 2);
    Unk02d15c_Setup(8, 42, 0, -1);
    func_02095f94();
    work->unk_0000 = 0;
    work->unk_0004 = 13;
    work->unk_0008 = 1;
    work->unk_000c = 0;
    Unk116598_Unk_117b80(work);
}

/* Original 0x021177b8 loads the pointer stored in BSS cell data_02176e64
   (relocation at 0x021177c8), compares it with zero and returns, leaving that
   pointer in r0 and the comparison flags set. All three call sites (0x02116994,
   0x02117bc0, 0x02125b2c) ignore both, so the routine is only a null guard:
   it returns immediately whether or not the cell is set. Defined last because
   objdiff scores its caller Unk116598_Unk_117b94 lower when the definition sits
   in that caller's address-order slot (tools/hand/README.md, wave b64). */
void func_021177b8(void)
{
    if (*data_02176e64 == 0)
        return;
}

/* ARM 0x02117170 returns 1 when provider 0x020dee2c(5) is nonzero
   or provider byte +0x5fbf is 1; provider work must be initialized. */
int func_02117170(void)
{
    if (Unk0de678_Unk_0dee2c(5) != 0 ||
        FIELD(u8, Unk02e000_Unk_02e774(), 0x5fbf) == 1) {
        return 1;
    }
    return 0;
}

/* ARM 0x02117208 dispatches provider IDs 0..8 through a jump table;
   only IDs 5, 6 and 7 return zero; all other IDs return one. */
int func_02117208(void)
{
    switch (Unk02f078_Unk_02f220()) {
    case 5: case 6: case 7:
        return 0;
    case 0: case 1: case 2: case 3: case 4: case 8:
    default:
        return 1;
    }
}

/* ARM 0x02117744 maps nonzero input flags to work +0xc: both=1,
   first=2, second=3. If +0 is zero, resulting state 1 becomes 2.
   Both flags zero preserve +0xc before that final adjustment. */
void func_02117744(Unk116598Work *work, int first, int second)
{
    if (first != 0 && second != 0) {
        work->unk_000c = 1;
    } else if (first != 0) {
        work->unk_000c = 2;
    } else if (second != 0) {
        work->unk_000c = 3;
    }
    if (work->unk_0000 == 0 && work->unk_000c == 1) {
        work->unk_000c = 2;
    }
}

/* Callback addresses are the four register arguments to 0x020611dc; the
   trailing words are the original allocation descriptor, not owned storage. */
typedef void (*Unk116598Callback)(Unk116598Work *work);
Unk116598Work *func_020611dc(Unk116598Callback a, Unk116598Callback b,
    Unk116598Callback c, Unk116598Callback d, u32 size, u32 mode,
    u32 value, u32 enabled);
void func_021169c8(Unk116598Work *work);
void func_02117bf4(Unk116598Work *work);
void func_02117594(Unk116598Work *work);

/* ARM 0x021178c0 requests 24 bytes with mode 2 and the clear callback;
   on success clears the first word. Returns zero on allocation failure. */
int func_021178c0(void)
{
    Unk116598Work *work = func_020611dc(0, 0, 0,
        (Unk116598Callback)Unk116598_Clear_data_02176e64, 24, 2, 0, 1);
    if (work == 0) return 0;
    work->unk_0000 = 0;
    return (int)work;
}

/* ARM 0x0211683c requests 20 bytes and the observed primary callbacks;
   initializes successful work with 0x021168cc, returning zero on failure. */
u32 func_0211683c(void)
{
    Unk116598Work *work = func_020611dc(func_021169c8,
        (Unk116598Callback)Unk116598_Nop_116b44, 0,
        Unk116598_Unk_116968, 20, 0, 0, 1);
    if (work == 0) return 0;
    Unk116598_Unk_1168cc(work);
    return (u32)work;
}

/* ARM 0x02117a68 is the secondary 20-byte allocation; calls 0x02117af8
   only on success and returns zero on failure. */
int func_02117a68(void)
{
    Unk116598Work *work = func_020611dc(func_02117bf4,
        (Unk116598Callback)Unk116598_Nop_117cd0, 0,
        Unk116598_Unk_117b94, 20, 0, 0, 1);
    if (work == 0) return 0;
    Unk116598_Unk_117af8(work);
    return (int)work;
}

/* ARM 0x021172fc tests signed byte +0x13 for states 1 and 2; other
   states return one. The global work cell must be initialized. */
int func_021172fc(void)
{
    Unk116598Work *work = (Unk116598Work *)*data_02176e60;
    switch (work->unk_0004) {
    case 0: return 1;
    case 1: return FIELD(s8, work, 0x13) == 0;
    case 2: return FIELD(s8, work, 0x13) == 31;
    default: return 1;
    }
}

/* ARM 0x021174d0 requests 28 bytes with mode 4 and four callbacks;
   initializes successful work with 0x02117550, returning zero on failure. */
int func_021174d0(void)
{
    Unk116598Work *work = func_020611dc(func_02117594,
        Unk116598_Unk_117620, Unk116598_Unk_117670,
        (Unk116598Callback)Unk116598_Clear_data_02176e60, 28, 4, 0, 1);
    if (work == 0) return 0;
    func_02117550(work);
    return (int)work;
}

void func_02057e18(u32 value);
void func_02057fd8(void);
void func_02057dcc(int a, int b, int c, int d);
void func_02057b50(int x, int y, int width, int height, int mode);
void func_02057df8(void);
void func_02057e30(int value);
/* ARM 0x021176c0 brackets a 256 by 192 provider operation with byte setup;
   a zero byte suppresses all calls, and value selects 255 or -1 components. */
void func_021176c0(u32 value, u8 byte, int mode)
{
    if (byte == 0) return;
    func_02057e18(byte);
    func_02057fd8();
    if (value == 0) func_02057dcc(255, 255, 255, 255);
    else func_02057dcc(-1, -1, -1, -1);
    func_02057b50(0, 0, 256, 192, mode);
    func_02057df8();
    func_02057e30(0);
    func_02057e18(31);
}

void Unk0bc1a8_Unk_0bc928(int slot, int value, int zero);
int func_020445f4(int id, int value);
void func_0204fed8(int value, int zero);
void func_020fc5d4(void);
/* ARM 0x02116758 initializes empty slot 24 with 65535, maps IDs 0..4
   through an explicit switch, and forwards the entry-30 result to providers. */
void func_02116758(u32 id)
{
    int value;
    if (Unk0bc1a8_IsSlotEmpty(24) != 0)
        Unk0bc1a8_Unk_0bc928(24, 65535, 0);
    value = 0;
    switch (id) {
    case 0: value = 0; break;
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 4: value = 4; break;
    }
    func_0204fed8(func_020445f4(30, value), 0);
    func_020fc5d4();
}
/* ARM 0x021179a0 initializes empty slot 24 with 65535, maps IDs 0..4
   through an explicit switch, and forwards the entry-30 result to providers. */
void func_021179a0(u32 id)
{
    int value;
    if (Unk0bc1a8_IsSlotEmpty(24) != 0)
        Unk0bc1a8_Unk_0bc928(24, 65535, 0);
    value = 0;
    switch (id) {
    case 0: value = 0; break;
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 4: value = 4; break;
    }
    func_0204fed8(func_020445f4(30, value), 0);
    func_020fc5d4();
}

/* ARM 0x0211708c scans marked provider bytes in descending order; the
   predicate selects IDs 7..6 plus fallback 8/5, or IDs 5..0 plus fallback 0. */
int func_0211708c(void)
{
    int i;
    if (Unk116598_Unk_1171a8()) {
        for (i = 7; i >= 6; --i) {
            if (((u8 *)Unk02e000_Unk_02e774())[i + 0x5fba] == 1) return i;
        }
        return *(u8 *)(Unk02e000_Unk_02e774() + 0x5fc2) == 1 ? 8 : 5;
    }
    for (i = 5; i >= 0; --i) {
        if (((u8 *)Unk02e000_Unk_02e774())[i + 0x5fba] == 1) return i;
    }
    return 0;
}

/* ARM 0x02117594 advances byte +0x12 until its unsigned threshold,
   then adjusts signed byte +0x13 by +0x11, clamping to 0 or 31 by state. */
void func_02117594(Unk116598Work *work)
{
    u8 *bytes = (u8 *)work;
    if (bytes[18] >= bytes[16]) {
        switch (work->unk_0004) {
        case 1:
            bytes[19] = (s8)bytes[19] - bytes[17];
            if ((s8)bytes[19] < 0) {
                bytes[19] = 0;
                work->unk_0004 = 0;
            }
            break;
        case 2:
            bytes[19] = (s8)bytes[19] + bytes[17];
            if ((s8)bytes[19] > 31) bytes[19] = 31;
            break;
        }
        bytes[18] = 0;
    } else {
        bytes[18]++;
    }
}

int Unk095560_Unk_095764(u8 id);
s8 *func_0204fde0(int value);
u32 func_0204fe18(int value);
/* ARM 0x02117834 consumes a signed-byte pair from provider data, then
   advances its unsigned index; the loop flag selects restart or Reset. */
void func_02117834(void)
{
    int value;
    u8 *work = (u8 *)*data_02176e64;
    s8 *table;
    if (FIELD(u32, work, 0) == 0) return;
    value = Unk095560_Unk_095764(work[8]);
    table = func_0204fde0(value);
    table += FIELD(u32, work, 12) * 2;
    FIELD(s32, work, 16) = table[0];
    FIELD(s32, work, 20) = table[1];
    Unk095560_Unk_0958a8(FIELD(s32, work, 16), FIELD(s32, work, 20));
    FIELD(u32, work, 12)++;
    if (FIELD(u32, work, 12) < func_0204fe18(value)) return;
    if (FIELD(u32, work, 4) != 0) {
        FIELD(u32, work, 12) = 0;
        return;
    }
    Unk116598_Reset();
}

int Unk02f2a8_Unk_035b08(int a, int b);
int Unk0e651c_Unk_0e666c(int id);
void func_020fc584(int mode, u32 threshold, u8 step);
/* ARM 02116b70 selects coordinates for IDs 8..11, applies the observed
   direction adjustment, and returns whether the direction is absent (-1). */
int func_02116b70(int *x, int *y, u32 id)
{
    int a = 22, b = 26, direction = 2;
    switch (id) {
    case 8: a = 22; b = 26; direction = 2; break;
    case 9: a = 14; b = 8; direction = 0; break;
    case 10: a = 29; b = 7; direction = 1; break;
    case 11: a = b; direction -= 3; break;
    }
    switch (direction) {
    case 0: --b; break;
    case 2: ++b; break;
    case 3: --a; break;
    case 1: ++a; break;
    }
    *x = a;
    *y = b;
    return direction == -1;
}
/* ARM 02116f84 checks four provider-coordinate combinations against event
   predicates; any matching combination with an unset predicate rejects it. */
int func_02116f84(int id, int x, int y)
{
    int result = 1;
    if (id == Unk02f2a8_Unk_035b08(6,8) && x == 22 && y == 26)
        if (!Unk0e651c_Unk_0e666c(237)) result = 0;
    if (id == Unk02f2a8_Unk_035b08(6,3) && x == 14 && y == 8)
        if (!Unk0e651c_Unk_0e666c(238)) result = 0;
    if (id == Unk02f2a8_Unk_035b08(6,3) && x == 29 && y == 7)
        if (!Unk0e651c_Unk_0e666c(239)) result = 0;
    if (id == Unk02f2a8_Unk_035b08(1,3) && x == 26 && y == 26)
        if (!Unk0e651c_Unk_0e666c(1568)) result = 0;
    return result;
}
/* ARM 02117360 sets the descending byte transition and conditionally starts
   provider mode 0/1; borrowed shared work must already be initialized. */
void func_02117360(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    Unk116598Work *work = (Unk116598Work *)*data_02176e60;
    int mode;
    if (a) {
        work->unk_0004 = 1;
        work->unk_0008 = c;
        ((u8 *)work)[16] = d;
        ((u8 *)work)[17] = e;
        ((u8 *)work)[18] = 0;
        ((u8 *)work)[19] = 31;
    }
    if (b && work->unk_0000 == 0) {
        mode = 0;
        switch (c) {
        case 0: case 1: case 3: mode = 0; break;
        case 2: case 4: mode = 1; break;
        }
        func_020fc584(mode, d, e);
    }
    func_02117744(work, a, b);
}
/* ARM 02117400 initializes the ascending counterpart of 02117360,
   selecting provider modes 2/3 from IDs 0..4. Requires shared work. */
void func_02117400(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    Unk116598Work *work = (Unk116598Work *)*data_02176e60;
    int mode;
    if (a) {
        work->unk_0004 = 2;
        work->unk_0008 = c;
        ((u8 *)work)[16] = d;
        ((u8 *)work)[17] = e;
        ((u8 *)work)[18] = 0;
        ((u8 *)work)[19] = 0;
    }
    if (b && work->unk_0000 == 0) {
        mode = 0;
        switch (c) {
        case 0: case 1: case 3: mode = 2; break;
        case 2: case 4: mode = 3; break;
        }
        func_020fc584(mode, d, e);
    }
    func_02117744(work, a, b);
}

u8 *GetGameState(void);
u8 *Unk09a268_Unk_09c484(int id);
u8 *Unk02f2a8_GetCell38e8(int x, int y);
void func_0209a884(void *a, void *b);
void Unk09a268_Unk_09a80c(u8 *cell, int value);
void Unk09a268_Unk_09a830(u8 *cell, int value);
void Unk09a268_Unk_09a870(u8 *cell, int value);
void Unk09a268_SetOnlyBit(u8 *cell, int value);
int Unk09a268_Unk_09a844(u8 *cell);
/* ARM 02116dc4 resolves ID coordinates, copies provider state into the
   game area and initializes the borrowed cell's flags and counter. */
void func_02116dc4(u32 id)
{
    u8 *provider = Unk09a268_Unk_09c484(1);
    u8 *game = GetGameState();
    int x = 0, y = 0;
    u8 *cell;
    func_02116b70(&x, &y, id);
    cell = Unk02f2a8_GetCell38e8(x,y);
    func_0209a884(game + 0x38e8, game + 4);
    Unk09a268_Unk_09a80c(cell,1);
    Unk09a268_Unk_09a830(cell,0);
    Unk09a268_SetOnlyBit(cell,provider[25]);
    cell[1] = 1;
    FIELD(u16,cell,2) = 0;
}
int func_020961a0(Unk116598Work *work);
int Unk095560_Unk_096484(void);
int Unk0a23f4_IsSet_data_02176b04(void);
void func_02111494(void);
void Unk02cad4_SetupDisplayMode(int a, int b, int c);
/* ARM 02117bf4 advances secondary work states 0/1/2 after provider
   readiness checks; work storage is borrowed from the callback owner. */
void func_02117bf4(Unk116598Work *work)
{
    switch (work->unk_0000) {
    case 0:
        if (!func_020961a0(work)) work->unk_000c = 1;
        func_02117834();
        if (work->unk_000c) work->unk_0000 = 2;
        break;
    case 1:
        if (!Unk095560_Unk_096484()) return;
        if (Unk0a23f4_IsSet_data_02176b04()) return;
        if (!Unk0bc1a8_IsSlotEmpty(24)) return;
        func_02111494();
        Unk02cad4_SetupDisplayMode(2,1,0);
        Unk116598_Unk_117ac8();
        work->unk_0000 = 0;
        func_02117400(1,1,0,0,31);
        break;
    case 2: func_02061424(); break;
    }
}
/* ARM 02116598 updates the special (36,18) cell for provider map (8,6).
   State 1 activates flags, state 3 clears them, and pending calls count ticks. */
void func_02116598(void)
{
    u8 *cell;
    int id;
    if (!GetGameState()) return;
    Unk09a268_Unk_09c484(11);
    cell = 0;
    id = *(u16 *)(Unk02e000_GetWorkArea() + 0x35c);
    if (id == Unk02f2a8_Unk_035b08(8,6)) cell = Unk02f2a8_GetCell38e8(36,18);
    if (!cell) return;
    if (cell[1] == 1) {
        if (Unk09a268_Unk_09a844(cell) == 1) {
            Unk09a268_Unk_09a80c(cell,1);
            Unk09a268_Unk_09a830(cell,1);
            Unk09a268_Unk_09a870(cell,0);
            Unk09a268_SetOnlyBit(cell,0);
            cell[1] = 2;
            FIELD(u16,cell,2) = 0;
        } else FIELD(u16,cell,2)++;
    } else if (cell[1] == 3) {
        if (Unk09a268_Unk_09a844(cell) == 1) {
            Unk09a268_Unk_09a80c(cell,0);
            Unk09a268_Unk_09a830(cell,0);
            Unk09a268_Unk_09a870(cell,0);
            Unk09a268_SetOnlyBit(cell,0);
            cell[1] = 0;
            FIELD(u16,cell,2) = 0;
        } else FIELD(u16,cell,2)++;
    }
}

void *Unk02f2a8_Unk_034970(void *area, int x, int y);
u8 *Unk038fbc_Unk_039160(void *area, int x, int y);
u32 *Unk038fbc_GetElement(void *area, int kind, int index);
void *Unk02f2a8_Unk_0349c4(void *area, int x, int y);
void Unk0e651c_Set2Bits(void *area, u32 value, int flag);
/* Borrowed element word: only its low eight bits are consumed here. */
typedef struct Unk116598Element { u32 value:8; } Unk116598Element;
void func_0204b6f4(void);
/* ARM 02116e5c advances the selected cell counter, completes its flags
   on provider readiness, and for ID 11 copies an element's low byte to bits.
   Game, provider and cell storage must be initialized. Returns completion. */
int func_02116e5c(void)
{
    int result = 0;
    u8 *provider = Unk09a268_Unk_09c484(1);
    u8 *game = GetGameState();
    int x = 0, y = 0;
    int special = func_02116b70(&x, &y, FIELD(u32,game,0x73ec));
    u8 *cell = Unk02f2a8_GetCell38e8(x,y);
    FIELD(u16,cell,2)++;
    if (Unk09a268_Unk_09a844(cell) == 1) {
        Unk09a268_Unk_09a80c(cell,1);
        Unk09a268_Unk_09a830(cell,1);
        Unk09a268_SetOnlyBit(cell,provider[25]);
        cell[1] = 2;
        FIELD(u16,cell,2) = 0;
        if (special == 1) {
            u8 *entry = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(game+4,x,y),x,y);
            u32 *element = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(game+4,x,y),11,entry[1]);
            Unk0e651c_Set2Bits(Unk02f2a8_Unk_0349c4(game+4,x,y), ((Unk116598Element *)element)->value,1);
        }
        func_0204b6f4();
        result = 1;
    }
    return result;
}
