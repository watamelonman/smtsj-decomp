/*
 * src/game/unit_020e8228.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02150c30[];
extern u32 data_02176cdc[];
extern u32 data_02176ce0[];
int Unk044904_GetFlag18(void);
void func_02057524(int value);
void func_02057534(void);
void func_02057eb8(int value);
void func_02061424(u32 handle);
void *Unk09974c_Unk_099d14(int id);
void ScanVisor_Unk_0a29a0(u32 value);
int Unk0e8228_Unk_0e8374(u32 x);
int Unk0e8228_GetArr88Field20(int i);
void Unk0e8228_Unk_0e8d90(u32 arg0,u32 arg1);
void Unk0e8228_Unk_0e8e8c(u32 arg0);
void func_020e9c00(u32 work,int index,u32 value);
int Unk0ea208_GetArr58();
int Unk0ea208_Get_data_02176ddc();
int Unk02e000_Unk_02e8f0(void);
void func_020e942c(u32 work, u32 value);
void func_020e9778(u32 work, u32 value);
void Unk0feba0_Unk_0febc8(void);
u32 func_02044ec4(u32 key);
int func_0204a244(u32 entry);
int Unk0e8228_GetCurEntry(u8 *work);
int Unk0e8228_Unk_0e8c80(void);

void Unk0e8228_Nop_0e93d4(void);
void Unk0e8228_Thunk_02057534(void);
int Unk0e8228_Thunk_02045c38(void);
void Unk0e8228_Unk_0e8cd8(void);
void Unk0e8228_Unk_0e8e50(void);
void Unk0e8228_Unk_0e8e6c(void);
void Unk0e8228_Unk_0e8e7c(void);
void Unk0e8228_Unk_0e8eac(u32 arg0);
u32 Unk0e8228_Get_data_02176ce0(void);
void Unk0e8228_Unk_0e8398(void);
int Unk0e8228_Unk_0e8460(void);
int Unk0e8228_Unk_0e8474(void);
int Unk0e8228_Unk_0e8488(void);
void Unk0e8228_Unk_0e9c94(u32 arg0,u32 arg1);
u32 Unk0e8228_Unk_0e84e4(void);
void *Unk0e8228_Unk_0e84fc(void);
u16 Unk0e8228_Unk_0e8514(void);
void Unk0e8228_Unk_0e8b7c(void);
void Unk0e8228_Unk_0e8b94(void);
u32 Unk0e8228_Unk_0e8bac(void);
void Unk0e8228_Unk_0e8c50(u32 arg0);
u32 Unk0e8228_Unk_0e8c68(void);
void Unk0e8228_Unk_0e8db8(void);
u32 Unk0e8228_Unk_0e8f20(void);
u32 Unk0e8228_Unk_0e8f38(void);
void Unk0e8228_Unk_0e8f50(u32 arg0);
void Unk0e8228_Unk_0e9020(u32 arg0);
struct Unk0e8228SortRecord;
int Unk0e8228_Unk_0e9048(const struct Unk0e8228SortRecord *const *arg0,
                                const struct Unk0e8228SortRecord *const *arg1);
void Unk0e8228_Unk_0ea028(void);
u32 Unk0e8228_Unk_0ea040(void);
int Unk0e8228_IsSet_data_02176cdc(void);

/* At 020e93d4, bx lr returns immediately: this callback has no work. */
void Unk0e8228_Nop_0e93d4(void) { }

/* At 020e8e60, the literal target and bx ip forward to func_02057534. */
void Unk0e8228_Thunk_02057534(void) { func_02057534(); }

/* At 020e8f68, bx ip forwards the flag getter result unchanged to the caller. */
int Unk0e8228_Thunk_02045c38(void) { return Unk044904_GetFlag18(); }

/* At 020e8cd8, mvn r0, #0 forwards the unsigned sentinel to ScanVisor_Unk_0a29a0. */
void Unk0e8228_Unk_0e8cd8(void)
{
  ScanVisor_Unk_0a29a0(0xffffffff);
}

/* At 020e8e50, mov r0, #4 forwards the fixed value to func_02057524. */
void Unk0e8228_Unk_0e8e50(void)
{
  func_02057524(4);
}

/* At 020e8e6c, mov r0, #2 forwards the fixed value to func_02057eb8. */
void Unk0e8228_Unk_0e8e6c(void)
{
  func_02057eb8(2);
}

/* At 020e8e7c, mvn r0, #0 forwards the signed sentinel -1 to func_02057eb8. */
void Unk0e8228_Unk_0e8e7c(void)
{
  func_02057eb8(-1);
}

/* At 020e8eac, add r0, r0, #8 offsets the value modulo 2^32 before forwarding. */
void Unk0e8228_Unk_0e8eac(u32 arg0)
{
  Unk0e8228_Unk_0e8e8c(arg0 + 8);
}

/* At 020e9038, loads the global object pointer stored in data_02176ce0. The
 * name comes from that data symbol; callers use the result as the shared work
 * object (see Unk0e8228_Unk_0e84e4). */
u32 Unk0e8228_Get_data_02176ce0(void)
{
  return *data_02176ce0;
}

/* At 020e8398, forwards the fixed selector 7 and the unsigned sentinel -1 to
 * Unk0e8228_Unk_0e8d90. Callers invoke it before scanning the entries counted
 * by Unk0e8228_Unk_0e8488; the callee is opaque, so the name stays neutral. */
void Unk0e8228_Unk_0e8398(void)
{
  Unk0e8228_Unk_0e8d90(7,0xffffffff);
}

/* At 020e8460, returns the word stored at data_02150c30 + 0x2c plus one.
 * Callers use the result as an exclusive loop bound (src/game/unit_020eed24.c);
 * the meaning of the stored word itself is not established. */
int Unk0e8228_Unk_0e8460(void)
{
  return *(int *)(((int)data_02150c30) + 0x2c) + 1;
}

/* At 020e8474, returns the word at data_02150c30 + 0x34 plus one. Callers use
 * it as an exclusive loop bound over 64-byte records (unit_020eed24.c). */
int Unk0e8228_Unk_0e8474(void)
{
  return *(int *)(((int)data_02150c30) + 0x34) + 1;
}

/* At 020e8488, returns the word at data_02150c30 + 0x3c plus one. Callers use
 * it as an exclusive loop bound and treat a value below one as empty
 * (unit_020f0be0.c, unit_020f4c50.c). */
int Unk0e8228_Unk_0e8488(void)
{
  return *(int *)(((int)data_02150c30) + 0x3c) + 1;
}

/* At 020e9c94, reorders its two arguments and tail-calls func_020e9c00 with
 * the constant selector 2 in between: (arg0, 2, arg1). */
void Unk0e8228_Unk_0e9c94(u32 arg0,u32 arg1)
{
  func_020e9c00(arg0,2,arg1);
}

/* At 020e84e4, returns the word at offset 0x178 of the shared work object, or
 * zero when Get_data_02176ce0 reports no object. Callers use the result as a
 * record count (unit_020ef248.c). */
u32 Unk0e8228_Unk_0e84e4(void)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 == 0) {
    value2 = 0;
  }
  else {
    value2 = *(u32 *)(value1 + 0x178);
  }
  return value2;
}

/* At 020e84fc, runs the sequence select-8 (Unk_0e8374), refreshes one row-88
 * record, then performs the Unk09974c lookup, returning that lookup result.
 * Argument flow per the original assembly: the selector-8 result is forwarded
 * to GetArr88Field20, and its result is in turn forwarded to Unk09974c_Unk_099d14
 * as the lookup id. unit_020ef248.c consumes the returned pointer as a borrowed
 * record. */
void *Unk0e8228_Unk_0e84fc(void)
{
  int index = Unk0e8228_Unk_0e8374(8);
  int row = Unk0e8228_GetArr88Field20(index);
  return Unk09974c_Unk_099d14(row);
}

/* Borrowed field views: offsets are established by the loads/stores at
 * 020e8514, 020e8b7c, 020e8c50, 020e8db8 and 020e8f20. Providers own storage. */
typedef struct Unk0e8228WorkFields {
  u8 pad_0000[0x10];
  u32 unk_0010;
  u8 pad_0014[4];
  u32 unk_0018;
  u8 pad_001c[8];
  u32 unk_0024;
  u32 unk_0028;
  u8 pad_002c[0x150];
  u32 unk_017c;
  u32 unk_0180;
  u32 unk_0184;
} Unk0e8228WorkFields;

/* Borrowed provider record; only its halfword at offset 0x20 is established. */
typedef struct Unk0e8228RecordFields {
  u8 pad_0000[0x20];
  u16 unk_0020;
} Unk0e8228RecordFields;

/* Original 020e8514 reads the provider's halfword at 0x20, or zero when
 * no record exists. Its domain meaning is unknown, so the name stays neutral. */
u16 Unk0e8228_Unk_0e8514(void)
{
  Unk0e8228RecordFields *record = (Unk0e8228RecordFields *)Unk0ea208_GetArr58();
  if (record == 0) {
    return 0;
  }
  return record->unk_0020;
}

/* Original 020e8b7c sets the work word at 0x18 to one when work exists. */
void Unk0e8228_Unk_0e8b7c(void)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work != 0) {
    work->unk_0018 = 1;
  }
}

/* Original 020e8b94 clears the same word at 0x18 when work exists. */
void Unk0e8228_Unk_0e8b94(void)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work != 0) {
    work->unk_0018 = 0;
  }
}

/* Original 020e8bac returns the work word at 0x18, or zero without work. */
u32 Unk0e8228_Unk_0e8bac(void)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work == 0) {
    return 0;
  }
  return work->unk_0018;
}

/* Original 020e8c50 stores the full 32-bit argument at work offset 0x24;
 * an absent work object leaves storage untouched. */
void Unk0e8228_Unk_0e8c50(u32 arg0)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work != 0) {
    work->unk_0024 = arg0;
  }
}

/* Original 020e8c68 returns the work word at 0x24, or zero without work. */
u32 Unk0e8228_Unk_0e8c68(void)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work == 0) {
    return 0;
  }
  return work->unk_0024;
}

/* Original 020e8db8 sets the work word at 0x184 to one when work exists. */
void Unk0e8228_Unk_0e8db8(void)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work != 0) {
    work->unk_0184 = 1;
  }
}

/* Original 020e8f20 returns the work word at 0x180, using 27 when absent;
 * the field's domain meaning is not established by this accessor. */
u32 Unk0e8228_Unk_0e8f20(void)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work == 0) {
    return 27;
  }
  return work->unk_0180;
}

/* Original 020e8f38 returns the work word at 0x17c, or zero without work. */
u32 Unk0e8228_Unk_0e8f38(void)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work == 0) {
    return 0;
  }
  return work->unk_017c;
}

/* Original 020e8f50 stores the full argument at work offset 0x28 if present. */
void Unk0e8228_Unk_0e8f50(u32 arg0)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work != 0) {
    work->unk_0028 = arg0;
  }
}

/* Original 020e9020 stores the full argument at work offset 0x10 if present. */
void Unk0e8228_Unk_0e9020(u32 arg0)
{
  Unk0e8228WorkFields *work = (Unk0e8228WorkFields *)Unk0e8228_Get_data_02176ce0();
  if (work != 0) {
    work->unk_0010 = arg0;
  }
}

/* Borrowed comparison records; original 020e9048 observes only byte 0x2e. */
typedef struct Unk0e8228SortRecord {
  u8 pad_0000[0x2e];
  u8 unk_002e;
} Unk0e8228SortRecord;

/* Original 020e9048 subtracts unsigned bytes at 0x2e, yielding -255..255.
 * Both arguments must point to valid record pointers; no null checks exist. */
int Unk0e8228_Unk_0e9048(const Unk0e8228SortRecord *const *arg0,
                                const Unk0e8228SortRecord *const *arg1)
{
  return (int)(*arg0)->unk_002e - (int)(*arg1)->unk_002e;
}

/* Original 020ea028 releases the provider through func_02061424 only when it is
 * present: the provider pointer is returned in r0 and stays there unchanged
 * across the `cmp r0,#0; popeq` guard, so it becomes the call's first (and
 * only) argument. The typed declaration matches src/game/unit_020ea208.c:122,
 * and docs/functions/game-unit-020fedd4.md calls func_02061424 the task
 * release call. */
void Unk0e8228_Unk_0ea028(void)
{
  void *provider = (void *)Unk0ea208_Get_data_02176ddc();
  if (provider == 0) {
    return;
  }
  func_02061424((u32)provider);
}

/* Borrowed provider view; only the word at 0x1cc is established by 020ea040. */
typedef struct Unk0e8228ProviderFields {
  u8 pad_0000[0x1cc];
  u32 unk_01cc;
} Unk0e8228ProviderFields;

/* Original 020ea040 returns the provider word at 0x1cc, or zero if absent. */
u32 Unk0e8228_Unk_0ea040(void)
{
  Unk0e8228ProviderFields *provider =
      (Unk0e8228ProviderFields *)Unk0ea208_Get_data_02176ddc();
  if (provider == 0) {
    return 0;
  }
  return provider->unk_01cc;
}

/* Original 020e8228 tests the word at data_02176cdc and returns exactly 0 or 1;
 * the global relocation establishes the descriptive name. */
int Unk0e8228_IsSet_data_02176cdc(void)
{
  return *data_02176cdc != 0;
}



/* At 020e82ac, calls Unk02e000_Unk_02e8f0 (allocation word + 0x90), reads the
 * unsigned byte at +3 and returns 1 when it is zero, else 0. Callers use the
 * result as a state flag (unit_020ee904.c), so the name stays neutral. */
int Unk0e8228_Unk_0e82ac(void)
{
  u8 *work = (u8 *)Unk02e000_Unk_02e8f0();
  return work[3] == 0;
}

/* At 020e8684, forwards the shared work object and its word at +0x10 to
 * func_020e942c, which stores the second argument at work + 0x0c. Does nothing
 * when no work object exists. */
void Unk0e8228_Unk_0e8684(void)
{
  u32 work = Unk0e8228_Get_data_02176ce0();
  if (work == 0) {
    return;
  }
  func_020e942c(work,FIELD(u32, work, 0x10));
}

/* At 020e8cbc, tail-forwards the shared work object's word at +8 to
 * ScanVisor_Unk_0a29a0. Does nothing when no work object exists. */
void Unk0e8228_Unk_0e8cbc(void)
{
  u32 work = Unk0e8228_Get_data_02176ce0();
  if (work == 0) {
    return;
  }
  ScanVisor_Unk_0a29a0(FIELD(u32, work, 8));
}

/* At 020e8c9c, resolves the current entry id (0e8c80) through
 * func_02044ec4, then reports whether func_0204a244 returns state 6. */
int Unk0e8228_Unk_0e8c9c(void)
{
  return func_0204a244(func_02044ec4(Unk0e8228_Unk_0e8c80())) == 6;
}

/* At 020e8d18, forwards the caller's selector to func_020e9778 together with
 * the shared work object. Does nothing when no work object exists. Callers
 * pass 0 or 1 (unit_020ee904.c, unit_020efdf4.c). */
void Unk0e8228_Unk_0e8d18(u32 arg0)
{
  u32 work = Unk0e8228_Get_data_02176ce0();
  if (work == 0) {
    return;
  }
  func_020e9778(work,arg0);
}

/* At 020e940c, releases the provider (0ea028), resets the 0x020feba0 state,
 * then clears the shared work pointer data_02176ce0. */
void Unk0e8228_Unk_0e940c(void)
{
  Unk0e8228_Unk_0ea028();
  Unk0feba0_Unk_0febc8();
  *data_02176ce0 = 0;
}


int func_020e8628(void);
void func_020ea0ec(void);
void func_020ea160(void);
/* Original 020e9728 calls 0ea0ec when 0e8628 returns exactly one; otherwise
 * calls 0ea160. The initializer forwards work in r0, which this callee ignores.
 * Callee meanings are unestablished, so the name stays neutral. */
void Unk0e8228_Unk_0e9728(u32 unusedWork)
{
  int value;
  value = func_020e8628();
  if (value == 1) {
    func_020ea0ec();
    return;
  }
  func_020ea160();
}


/* Original 020e9f18 clears six consecutive words. The caller must supply
 * writable storage for all 24 bytes; 020e8260 uses a global table row. */
void Unk0e8228_Unk_0e9f18(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
}


/* Original 020e9f38 stores arg1 in the first word and clears the next five.
 * The caller owns the writable 24-byte row (see 020e8260). */
void Unk0e8228_Unk_0e9f38(u32 *arg0,u32 arg1)
{
  *arg0 = arg1;
  arg0[1] = 0;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
}

int Unk0e8228_GetArr30(int i);
int Unk0e8228_Unk_0e8ce8(u32 x);
/* Original 020e8bc4 resolves slot zero through 02044ec4, forwards its result
 * to 0e8ce8, and normalizes the returned value to exactly zero or one. */
int Unk0e8228_Unk_0e8bc4(void)
{
  int value;
  u32 entry = func_02044ec4(Unk0e8228_GetArr30(0));
  value = Unk0e8228_Unk_0e8ce8(entry);
  return value != 0;
}


/* Original 020e8c2c stores one at work +0x1c and 180 at +0x20 when work
 * exists. The units and meanings of these words are not established. */
void Unk0e8228_Unk_0e8c2c(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return;
  }
  *(u32 *)(value + 0x1c) = 1;
  *(u32 *)(value + 0x20) = 0xb4;
}


u32 func_020e9900(u32 arg0, u32 work, u32 arg1);
/* Original 020e8dd0 forwards both words around the borrowed work address to
 * 020e9900, returning zero when work is absent. Argument meanings are unknown. */
u32 Unk0e8228_Unk_0e8dd0(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 != 0) {
    value2 = func_020e9900(arg0,value1,arg1);
    return value2;
  }
  return 0;
}

u32 func_020e9aa0(u32 arg0, u32 work, u32 arg1);
/* Original 020e8dfc forwards both words around the borrowed work address to
 * 020e9aa0, returning zero when work is absent. Argument meanings are unknown. */
u32 Unk0e8228_Unk_0e8dfc(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Get_data_02176ce0();
  if (value1 != 0) {
    value2 = func_020e9aa0(arg0,value1,arg1);
    return value2;
  }
  return 0;
}

int func_02008848(u32 buffer, u32 value, u32 size);
void func_020e9060(u32 work);
/* Original 020e9fa4 clears 0x1cc writable bytes, publishes the caller-owned
 * work address in data_02176ce0, then initializes it through 020e9060. */
void Unk0e8228_Unk_0e9fa4(u32 arg0)
{
  func_02008848(arg0,0,0x1cc);
  *data_02176ce0 = arg0;
  func_020e9060(arg0);
}



int Unk044904_Unk_0459fc(void);
int func_02053800(u32 selector, u32 mask);
void func_020e82c8(void);
int Unk0e8228_IsField4One(void);
int Unk0fd9f0_Unk_0fda58(u32 value);
int Unk100208_Unk_100208(u32 value);
/* Original 020e85c8 requires work, field +4 equal to one and a nonzero
 * 02053800(0, 0x400) result, then performs five calls in order and returns
 * one. Otherwise returns zero; opaque selectors retain their literal values. */
u32 Unk0e8228_Unk_0e85c8(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return 0;
  }
  value = Unk0e8228_IsField4One();
  if ((value != 0) && (value = func_02053800(0,0x400), value != 0)) {
    Unk044904_Unk_0459fc();
    Unk0e8228_Unk_0e8cd8();
    func_020e82c8();
    Unk0fd9f0_Unk_0fda58(2);
    Unk100208_Unk_100208(7);
    return 1;
  }
  return 0;
}

extern u8 data_02176ce4[];
/* Original 020e8244 tail-calls func_02008848(data_02176ce4, 0, 0xf8).
 * The relocation and fixed arguments establish the Call name. */
void Unk0e8228_Call_02008848(void)
{
  func_02008848((u32)data_02176ce4,0,0xf8);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u8 data_02176ce4[];
void Unk0e8228_Unk_0e9f18(u32 *arg0);
void Unk0e8228_Unk_0e9f38(u32 *arg0, u32 arg1);
int func_020e9ca8(u32 work, u32 selector);
int func_020e9b54(u32 work);
u8 *func_020982c0(int value);
/* Original 020e8260 clears the 24-byte global row at +8 for selector zero,
 * or initializes rows at +32 with value zero for selectors 1..3.
 * Other unsigned selectors leave the global table unchanged. */
void Unk0e8228_Unk_0e8260(u32 i)
{
    u8 *base = data_02176ce4;
    if (i == 0) {
        Unk0e8228_Unk_0e9f18((u32 *)(base + 8));
        return;
    }
    if (i >= 1 && i <= 3) {
        Unk0e8228_Unk_0e9f38((u32 *)(base + 32 + (i - 1) * 24), 0);
    }
}

/* Original 020e8374 forwards the shared work and selector to 0e9ca8, or
 * returns zero without work. Selector semantics are not established. */
int Unk0e8228_Unk_0e8374(u32 x)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return func_020e9ca8(p, x);
}

/* Original 020e83ac returns entry i of the four-word table at work +0x30.
 * Null work and indices outside 0..3 return zero. The table's meaning is not
 * established, so the name stays neutral. */
int Unk0e8228_GetArr30(int i)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 4) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 48);
}

/* Original 020e83e8 returns entry i of the twelve-word table at work +0x58.
 * Null work and indices outside 0..11 return zero. */
int Unk0e8228_GetArr58(int i)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 12) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 88);
}

/* Original 020e8424 returns entry i of the six-word table at work +0x40.
 * Null work and indices outside 0..5 return zero. */
int Unk0e8228_GetArr40(int i)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 6) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 64);
}

/* Original 020e849c bounds-checks index 0..59 in the pointer table at +0x88,
 * then returns the record halfword at +0x20. Missing work/record returns zero.
 * These observed offsets support the existing accessor name. */
int Unk0e8228_GetArr88Field20(int i)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    u8 *q;
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 60) {
        return 0;
    }
    q = FIELD(u8 *, p + i * 4, 136);
    return q == 0 ? 0 : FIELD(u16, q, 32);
}

/* Original 020e85a0 tests work +4 for exactly one, returning zero without
 * work. The load offset and comparison establish the descriptive name. */
int Unk0e8228_IsField4One(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 4) == 1;
}

/* Original 020e8b54 tests work +0x0c for exactly one, returning zero without
 * work. The load offset and comparison establish the descriptive name. */
int Unk0e8228_IsFieldCOne(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 12) == 1;
}

/* Original 020e8be8 resolves slot zero's state and returns zero for states
 * 1, 7 and 11. Otherwise it returns func_020e9b54(work), or zero when the
 * shared work object is absent; neither callee meaning is established. */
int Unk0e8228_Unk_0e8be8(void)
{
    u32 p;
    switch (func_0204a244(func_02044ec4(Unk0e8228_GetArr30(0)))) {
    case 1:
    case 7:
    case 11:
        return 0;
    }
    p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return func_020e9b54(p);
}

/* At 020e8c80, returns the current entry id from the shared work object, or 0
 * when no work object exists. Callers pass the result to func_02044ec4 as an
 * entry key (unit_020ea208.c, unit_020efdf4.c). */
int Unk0e8228_Unk_0e8c80(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return Unk0e8228_GetCurEntry((u8 *)p);
}

/* Original 020e8ce8 returns zero for a null entry, otherwise looks up its
 * signed-byte category via 0204a244/020982c0. Missing records return one;
 * existing records supply the signed byte at +2. */
int Unk0e8228_Unk_0e8ce8(u32 x)
{
    u8 *v;
    if (x == 0) {
        return 0;
    }
    v = func_020982c0((s8)func_0204a244(x));
    if (v == 0) {
        return 1;
    }
    return (s8)v[2];
}

/* At 020e8e8c, clears the shared work object's word at +0x17c and stores the
 * caller's selector at +0x180. Both stores happen only when work exists; the
 * pair is read back by 0e8f20/0e8f38. Names stay neutral because callers only
 * pass 0 or 1. */
void Unk0e8228_Unk_0e8e8c(u32 arg0)
{
  u32 work = Unk0e8228_Get_data_02176ce0();
  if (work != 0) {
    FIELD(u32, work, 0x17c) = 0;
    FIELD(u32, work, 0x180) = arg0;
  }
}

void func_020e9de4(u32 work, u32 arg0, u32 arg1);
/* Original 020e8d90 calls 020e9de4 with the borrowed work address and the
 * two opaque words only when work exists. Ownership stays with its provider. */
void Unk0e8228_Unk_0e8d90(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = Unk0e8228_Get_data_02176ce0();
  if (tmp1 == 0) {
    return;
  }
  func_020e9de4(tmp1,arg0,arg1);
}

int func_020cb1a0(u32 key);
typedef struct Unk0e8228Sel {
    u8 a[2];
    u8 pad[2];
    u32 b[16];
} Unk0e8228Sel;
typedef struct Unk0e8228SelHost {
    u8 pad[392];
    Unk0e8228Sel sel;
} Unk0e8228SelHost;
/* Evidence for IsState3: 020e8e3c loads work +0 and compares it with 3.
 * A missing work object returns false; the borrowed object is never modified. */
int Unk0e8228_IsState3(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 0) == 3;
}

/* Original 020e8fe4 looks up x through Unk09974c_Unk_099d14, reads the
 * unsigned halfword at +0x22, and, when nonzero, passes it to func_020cb1a0
 * and reports whether the byte at +0x23 is exactly 7. A null argument or
 * zero halfword returns zero. */
int Unk0e8228_Unk_0e8fe4(u32 x)
{
    u32 h;
    if (x == 0) {
        return 0;
    }
    h = FIELD(u16, Unk09974c_Unk_099d14(x), 34);
    if (h == 0) {
        return 0;
    }
    return FIELD(u8, func_020cb1a0(h), 35) == 7;
}

/* Evidence for GetCurEntry: 020e9750 reads the signed selection at +8,
 * clamps negative indices to zero, and selects the +0x30/+0x40 entry bank
 * through IsField4One. Caller supplies valid work and an in-range index. */
int Unk0e8228_GetCurEntry(u8 *p)
{
    int i = FIELD(int, p, 8);
    if (i <= -1) {
        i = 0;
    }
    if (Unk0e8228_IsField4One() != 0) {
        return FIELD(u32, p + i * 4, 48);
    }
    return FIELD(u32, p + i * 4, 64);
}

/* Original 020e9bc0 tests the embedded selection at host +392 and returns
 * when that address is null, then clears its two flag bytes and sixteen
 * words. The caller owns the host storage; the layout records only the
 * offsets observed by the original instructions. */
void Unk0e8228_ClearSel(Unk0e8228SelHost *p)
{
    int j;
    int k;
    if (&p->sel == 0) {
        return;
    }
    for (j = 0; j < 2; j++) {
        p->sel.a[j] = 0;
    }
    for (k = 0; k < 16; k++) {
        p->sel.b[k] = 0;
    }
}

void Unk0bc1a8_Unk_0bc504(u32 object, u32 value);
/* Original 020e93dc reads the caller-provided state word. The five-slot
 * switch invokes 020bc504(object, 0) only for state 1; other states do nothing.
 * The object address is borrowed and forwarded unchanged. */
void func_020e93d8(u32 object, const u32 *state)
{
    switch (*state) {
    case 0: break;
    case 1: Unk0bc1a8_Unk_0bc504(object, 0); break;
    case 2: break;
    case 3: break;
    case 4: break;
    }
}

extern u32 data_02150c0c[];
int Unk0bc1a8_IsSlotEmptyOrFlag8(int i);
int ScanVisor_Unk_0a2980(void);
void func_020ea058(void);

/* Original 020e942c stores the selector at work +0x0c, then dispatches:
 * selector 0 calls 020ea058; selector 1 calls 020e8628 and invokes 020ea0ec
 * only when that returns exactly one, otherwise 020ea160; other selectors
 * return without a call. */
void func_020e942c(u32 work, u32 value)
{
  FIELD(u32, work, 12) = value;
  switch (value) {
  case 0:
    func_020ea058();
    return;
  case 1:
    if (func_020e8628() == 1) {
      func_020ea0ec();
      return;
    }
    func_020ea160();
    return;
  }
}

/* Original 020e9b10 scans the first nine words of data_02150c0c through
 * Unk0bc1a8_IsSlotEmptyOrFlag8. A false result returns zero immediately;
 * when all nine are true it returns whether ScanVisor_Unk_0a2980 is nonzero. */
int func_020e9b10(void)
{
  u32 i;
  for (i = 0; i < 9; i++) {
    if (Unk0bc1a8_IsSlotEmptyOrFlag8(data_02150c0c[i]) == 0) {
      return 0;
    }
  }
  return ScanVisor_Unk_0a2980() != 0;
}

/* Original 020e8628 returns 3 without work and 2 unless work +4 equals one.
 * With that flag, +8 selects zero for -1, one for zero, and two otherwise. */
int func_020e8628(void)
{
    u32 work = Unk0e8228_Get_data_02176ce0();
    if (work == 0) {
        return 3;
    }
    if (FIELD(u32, work, 4) != 1) {
        return 2;
    }
    switch (FIELD(s32, work, 8)) {
    case -1: return 0;
    case 0: return 1;
    case 10: break;
    }
    return 2;
}

u32 func_020e946c(u32 work, u32 arg0, u32 arg2);
u32 func_020e94d8(u32 work, u32 arg0, u32 arg1, u32 value, u32 arg3);
/* Original 020e8d38 returns zero without work. Otherwise resolves a value
 * with 020e946c(work, arg0, arg2), then forwards it and the remaining words
 * to 020e94d8. All selectors remain opaque; work is borrowed. */
u32 func_020e8d38(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    u32 work = Unk0e8228_Get_data_02176ce0();
    u32 value;
    if (work == 0) {
        return 0;
    }
    value = func_020e946c(work, arg0, arg2);
    return func_020e94d8(work, arg0, arg1, value, arg3);
}

/* Original 020e8ebc stores the selector at work +0x17c. Zero or a record
 * byte +0x23 equal to 4/8 sets +0x180 to 27; otherwise bits 12..16 of the
 * record word +0x24 select values 8..39. Null work leaves storage untouched. */
void func_020e8ebc(u32 selector)
{
    u32 work = Unk0e8228_Get_data_02176ce0();
    u32 record;
    u32 kind;
    if (work == 0) {
        return;
    }
    FIELD(u32, work, 0x17c) = selector;
    if (selector == 0) {
        FIELD(u32, work, 0x180) = 27;
        return;
    }
    record = func_020cb1a0(FIELD(u32, work, 0x17c));
    kind = FIELD(u8, record, 0x23);
    switch (kind) {
    case 4:
    case 8:
        FIELD(u32, work, 0x180) = 27;
        break;
    default:
        FIELD(u32, work, 0x180) = ((FIELD(u32, record, 0x24) << 15) >> 27) + 8;
        break;
    }
}

void func_020e92a8(u32 object);
/* Original 020e9f58 initializes selected words of a caller-owned descriptor;
 * relocations establish four callback addresses. Offset +8 is preserved.
 * The caller must supply at least 36 writable bytes. */
void func_020e9f58(u32 *descriptor)
{
    descriptor[0] = 0x1cc;
    descriptor[1] = 0;
    descriptor[3] = (u32)func_020e92a8;
    descriptor[4] = 0;
    descriptor[5] = (u32)Unk0e8228_Nop_0e93d4;
    descriptor[6] = 0;
    descriptor[7] = (u32)Unk0e8228_Unk_0e940c;
    descriptor[8] = (u32)func_020e93d8;
}

void func_020eb488(u32 object);
void Unk0ea208_Unk_0eb6cc(u32 object);
void func_020eb6e4(u32 object);
void Unk0ea208_Unk_0eb308(u32 object);
u32 func_020611dc(void (*callback0)(u32), void (*callback1)(u32), u32 value,
                  void (*callback3)(u32), u32 size, u32 flag0, u32 zero, u32 flag1);
extern u32 data_02176ddc[];
/* Original 020e9fd0 allocates through 020611dc with three relocated callbacks,
 * 0x1d8 bytes and flags 1/0/1, publishes the handle in data_02176ddc, then
 * forwards it to 020eb308. Provider ownership follows those external calls. */
void func_020e9fd0(void)
{
    u32 handle = func_020611dc(func_020eb488, Unk0ea208_Unk_0eb6cc, 0,
                              func_020eb6e4, 0x1d8, 1, 0, 1);
    *data_02176ddc = handle;
    Unk0ea208_Unk_0eb308(handle);
}

/* Original 020e946c uses work +0x28 to select a packed low-half sentinel
 * and byte selector, or returns the caller's fallback. Addresses are borrowed. */
u32 func_020e946c(u32 work, u32 arg0, u32 arg2)
{
    u32 base;
    u32 value;
    switch (FIELD(u32, work, 0x28)) {
    case 1:
        value = (FIELD(u32, arg0, 0) >> 16) & 255;
        if (value == 1) value = 2;
        else if (value == 2) value = 1;
        else value = 0;
        base = 0xfffe;
        value <<= 24;
        base |= value >> 8;
        return base;
    case 2:
        value = FIELD(u32, work, 4);
        base = 0xfffe;
        value <<= 24;
        base |= value >> 8;
        return base;
    }
    return arg2;
}

/* Original 020e9b54 scans bank +0x30, or +0x40 for state two, and
 * reports any nonzero 0e8ce8 result. Work and table entries must be valid. */
int func_020e9b54(u32 work)
{
    int count = FIELD(s32, data_02150c30, 0x34) + 1;
    u32 *bank = (u32 *)(work + 0x30);
    int i;
    if (FIELD(u32, work, 4) == 2) {
        count = FIELD(s32, data_02150c30, 0x2c) + 1;
        bank = (u32 *)(work + 0x40);
    }
    for (i = 0; i < count; i++) {
        if (bank[i] != 0 && Unk0e8228_Unk_0e8ce8(func_02044ec4(bank[i])) != 0)
            return 1;
    }
    return 0;
}

void func_0204a7b4(u32 entry, u32 selector);
/* Original 020e86a0 resets the visor, forwards selector four for each
 * resolved nonzero bank +0x30 entry, then clears work +0x10 via its setter. */
void func_020e86a0(void)
{
    u32 work = Unk0e8228_Get_data_02176ce0();
    int count;
    u32 *bank;
    int i;
    if (work == 0) return;
    Unk0e8228_Unk_0e8cd8();
    count = FIELD(s32, data_02150c30, 0x34) + 1;
    bank = (u32 *)(work + 0x30);
    for (i = 0; i < count; i++) {
        if (bank[i] != 0) {
            u32 entry = func_02044ec4(bank[i]);
            if (entry != 0) func_0204a7b4(entry, 4);
        }
    }
    Unk0e8228_Unk_0e9020(0);
}

/* Original 020e8f74 counts state-seven entries after slot zero in bank
 * +0x30; exactly three yields one. Missing shared work yields zero. */
int func_020e8f74(void)
{
    u32 work = Unk0e8228_Get_data_02176ce0();
    int count;
    u32 *bank;
    int total, i;
    if (work == 0) return 0;
    count = FIELD(s32, data_02150c30, 0x34) + 1;
    bank = (u32 *)(work + 0x30);
    total = 0;
    for (i = 1; i < count; i++) {
        if (bank[i] != 0 && func_0204a244(func_02044ec4(bank[i])) == 7)
            total++;
    }
    return total == 3;
}

/* Original 020e9814 finds the next bank slot accepted by 0e8ce8 after
 * the supplied index, returning ten when absent. Caller supplies valid work. */
int func_020e9814(u32 work, int index)
{
    int result = 10;
    int count = FIELD(s32, data_02150c30, 0x34) + 1;
    u32 *bank = (u32 *)(work + 0x30);
    int i;
    if (FIELD(u32, work, 4) == 2) {
        count = FIELD(s32, data_02150c30, 0x2c) + 1;
        bank = (u32 *)(work + 0x40);
    }
    for (i = index + 1; i < count; i++) {
        if (bank[i] != 0 && Unk0e8228_Unk_0e8ce8(func_02044ec4(bank[i])) != 0) {
            result = i;
            break;
        }
    }
    return result;
}

/* Original 020e9aa0 resolves selector seven and dispatches the current
 * entry with its +0x1e8 record and selected +0x58 word; success resets selector. */
u32 func_020e9aa0(u32 arg0, u32 work, u32 arg1)
{
    int index = func_020e9ca8(work, 7);
    if (index != -1 && arg0 != 0) {
        u32 entry = func_02044ec4(Unk0e8228_Unk_0e8c80());
        if (func_020e8d38(entry, entry + 0x1e8,
                         FIELD(u32, work + index * 4, 0x58), arg1) == 0)
            arg0 = 0;
        else
            Unk0e8228_Unk_0e8d18(0);
    } else {
        arg0 = 0;
    }
    return arg0;
}

u16 *func_0204a0d8(u32 entry);
int Unk0cb0d0_IsAbove15e(u32 value);
/* Original 020e852c counts up to six nonzero provider halfwords not accepted
 * by IsAbove15e, adding one (capped at six) when work +0x24 is nonzero. */
int func_020e852c(void)
{
    u16 *values;
    int count, i;
    if (Unk0e8228_Get_data_02176ce0() == 0) return 0;
    values = func_0204a0d8(func_02044ec4(Unk0e8228_Unk_0e8c80()));
    count = 0;
    for (i = 0; i < 6; i++) {
        if (values[i] == 0) break;
        if (Unk0cb0d0_IsAbove15e(values[i]) != 1) count++;
    }
    if (Unk0e8228_Unk_0e8c68() != 0) {
        count++;
        if (count > 6) count = 6;
    }
    return count;
}

extern u8 data_02150ca0[];
void func_02061f10(u32 handle, u32 selector, u32 arg2, u32 arg3, u32 value);
/* Original 020ea0ec requires provider +0x1cc, updates five handles using
 * eight-byte descriptors, then clears byte +0x1c0. Provider owns all storage. */
void func_020ea0ec(void)
{
    u32 provider = Unk0ea208_Get_data_02176ddc();
    unsigned int i;
    if (provider == 0 || FIELD(u32, provider, 0x1cc) == 0) return;
    for (i = 0; i < 5; i++) {
        func_02061f10(((u32 *)provider)[i + 4], -1, 0, 0,
                      ((u32 (*)[2])data_02150ca0)[i][1]);
    }
    FIELD(u8, provider, 0x1c0) = 0;
}

void func_02057e58(int a, int b, int c);
void func_020f7e48(u32 kind, u32 first, u32 second);
void func_020bcacc(u32 kind, const void *request);
int Unk0bc1a8_IsSlotEmpty(u32 slot);
void Unk0bc1a8_Unk_0bc9b4(u32 slot, u32 value);
u32 func_020ea630(u32 value);
u32 Unk0ea208_Unk_0eac24(void);
void Unk0d1c98_Unk_0d1d94(u32 value, s32 mode);
void func_020d1e94(u32 value);
int func_020e9814(u32 work, int index);
int Unk0e8228_IsField4One(void);
void Unk0e8228_Unk_0e8cbc(void);
void Unk0e8228_Unk_0e8cd8(void);
void Unk0e8228_Unk_0e9020(u32 arg0);
int Unk0e8228_Unk_0e8ce8(u32 x);

/* Original 020e9884 selects the +0x30 or +0x40 entry bank from work +4,
 * scans downward from index-1 for the first entry accepted by 0e8ce8, and
 * reports it after applying selector four to the entry at the supplied index.
 * Returns -1 when no lower entry qualifies. Work and bank entries are borrowed. */
int func_020e9884(u32 work, int index)
{
    int found = -1;
    u32 *bank = (u32 *)(work + 0x30);
    int i;
    if (FIELD(u32, work, 4) == 2) bank = (u32 *)(work + 0x40);
    for (i = index - 1; i >= 0; i--) {
        if (bank[i] != 0 && Unk0e8228_Unk_0e8ce8(func_02044ec4(bank[i])) != 0) {
            found = i;
            break;
        }
    }
    if (found == -1) return found;
    {
        u32 entry = func_02044ec4(bank[index]);
        if (entry != 0) func_0204a7b4(entry, 4);
    }
    return found;
}

/* Original 020e9c00 stores value in one of the sixteen words after the
 * two-byte flag block at work +392 and sets the matching flag bit. Signed
 * indices outside 0..15 and a null flag block leave storage untouched. */
void func_020e9c00(u32 work, int index, u32 value)
{
    Unk0e8228SelHost *host = (Unk0e8228SelHost *)work;
    /* The original spills its third argument for the guarded store below. */
    volatile u32 saved = value;
    int nonneg;
    int below16;
    if (&host->sel == 0) return;
    nonneg = index >= 0;
    if (nonneg == 0) return;
    below16 = index < 16;
    if (below16 == 0) return;
    {
        u32 stored = saved;
        if (&host->sel != 0 && nonneg != 0 && below16 != 0) {
            u32 flags;
            int byte = index / 8;
            int bit = index % 8;
            host->sel.b[index] = stored;
            flags = host->sel.a[byte];
            host->sel.a[byte] = flags | (1 << bit);
        }
    }
}


/* Original 020e82c8 stores state three, applies request (slot, zero, three) to
 * every nonempty slot in the nine-word data_02150c0c table, then tears down
 * through one of three mutually exclusive provider paths before notifying
 * 020fda58 with one. Missing shared work does nothing. */
void func_020e82c8(void)
{
    u32 work = Unk0e8228_Get_data_02176ce0();
    u32 i;
    if (work == 0) return;
    FIELD(u32, work, 0) = 3;
    for (i = 0; i < 9; i++) {
        u32 slot = data_02150c0c[i];
        if (Unk0bc1a8_IsSlotEmpty(slot) == 0)
            func_020f7e48(slot, 0, 3);
    }
    if (FIELD(u32, work, 0x1c) != 0) {
        Unk0d1c98_Unk_0d1d94(func_020ea630(9), -1);
    }
    else if (FIELD(u32, work, 0x2c) != 0) {
        Unk0d1c98_Unk_0d1d94(Unk0ea208_Unk_0eac24(), -1);
    }
    else {
        func_020d1e94(1);
    }
    Unk0fd9f0_Unk_0fda58(1);
}

/* Original 020e92a8 configures three display ranges, then dispatches on the
 * object state. State one waits for the provider word at +0x1cc and either
 * records submenu one or submits kind 27. State three releases one of two
 * teardown paths, counts down a positive +0x20 word, and advances to state
 * four when 020e9b10 reports ready. States zero, two and four return. */
void func_020e92a8(u32 object)
{
    func_02057e58(2, 48, 10);
    switch (FIELD(u32, object, 0)) {
    case 1:
        if (Unk0e8228_Unk_0ea040() == 0) return;
        FIELD(u32, object, 0) = 2;
        if (Unk0e8228_IsField4One() == 0) {
            FIELD(u32, object, 0x0c) = 1;
            return;
        }
        func_020bcacc(27, 0);
        func_020ea058();
        return;
    case 3:
        if (FIELD(u32, object, 0x2c) != 0) {
            if (func_02053800(0, 0xc03) == 0) return;
            Unk100208_Unk_100208(0);
            Unk044904_Unk_045bd0(0);
            func_020d1e94(0);
        }
        if (FIELD(u32, object, 0x1c) != 0 && FIELD(s32, object, 0x20) > 0) {
            if (func_02053800(0, 0xc03) != 0) FIELD(u32, object, 0x20) = 0;
            FIELD(s32, object, 0x20) = FIELD(s32, object, 0x20) - 1;
            if (FIELD(s32, object, 0x20) > 0) return;
            Unk100208_Unk_100208(0);
            func_020d1e94(0);
        }
        if (func_020e9b10() == 0) return;
        Unk0bc1a8_Unk_0bc9b4(26, 0);
        FIELD(u32, object, 0) = 4;
        return;
    case 0:
    case 2:
    case 4:
        return;
    }
}

/* Original 020e9778 advances the signed work index either forward through the
 * next accepted bank slot (selector zero) or backward through the previous one
 * (selector one). Both paths flag the selection at +0x14 and refresh the visor
 * view for state-one work; selector zero also handles an exhausted scan by
 * resetting state and running 020e82c8. Other selectors do nothing. */
void func_020e9778(u32 work, u32 selector)
{
    int index;
    switch (selector) {
    case 0:
        index = func_020e9814(work, FIELD(s32, work, 8));
        FIELD(s32, work, 8) = index;
        if (index >= 10) {
            if (Unk0e8228_IsField4One()) Unk0e8228_Unk_0e8cd8();
            func_020e82c8();
            return;
        }
        Unk0e8228_Unk_0e9020(1);
        FIELD(u32, work, 0x14) = 1;
        if (Unk0e8228_IsField4One()) Unk0e8228_Unk_0e8cbc();
        return;
    case 1:
        index = func_020e9884(work, FIELD(s32, work, 8));
        FIELD(s32, work, 8) = index;
        Unk0e8228_Unk_0e9020(1);
        FIELD(u32, work, 0x14) = 1;
        if (Unk0e8228_IsField4One()) Unk0e8228_Unk_0e8cbc();
        return;
    }
}

u32 func_020445f4(int index, int item);
u32 func_0204fed8(u32 resource, int index);
int Unk0e651c_Unk_0e666c(u32 flag);
extern u32 data_02150c80[][2];
/* Original 020ea058 updates three provider handles from resource 39. Flag
 * 0x707 selects entry 2 versus 13; provider storage remains borrowed. */
void func_020ea058(void)
{
    u32 provider = Unk0ea208_Get_data_02176ddc();
    u32 resource;
    int i;
    if (provider == 0 || FIELD(u32, provider, 0x1cc) == 0) return;
    resource = func_020445f4(39, 0);
    for (i = 0; i < 3; i++) {
        int selector = i + 1;
        if (selector == 2 && Unk0e651c_Unk_0e666c(0x707) == 0) selector = 13;
        func_02061f10(((u32 *)provider)[i + 4], -1, 0, 0,
                      func_0204fed8(resource, selector));
    }
}
/* func_020ea160 is intentionally left to the delinked object. Its original
 * object uses two literal-pool words that both resolve to data_02150c80, but
 * the delink cannot distinguish the source alias that produced the second
 * word, so this TU cannot reproduce it without a new symbol. See the function
 * document. */

/* Request layout submitted to 020bc9f4/020bcacc: two flag bytes and sixteen
 * one-word records, as in the builders in unit_020f7188.c. See DEC-013. */
typedef struct Unk0e8228RequestWord {
    u32 value;
} Unk0e8228RequestWord;
typedef struct Unk0e8228Request {
    u8 flags[2];
    u8 pad[2];
    Unk0e8228RequestWord words[16];
} Unk0e8228Request;

/* Clear the request; inlining reproduces the original two loops at both call
 * sites. See DEC-013. */
static inline void Unk0e8228_ClearRequest(Unk0e8228Request *p)
{
    int j;
    for (j = 0; j < 2; j++) p->flags[j] = 0;
    for (j = 0; j < 16; j++) p->words[j].value = 0;
}

void func_020bc9f4(u32 kind, const void *request);
/* Original 020e8a30 submits two stack-owned requests for kind 35, then clears
 * work +0x184. The first passes words 2/3 through one-word records; the second
 * passes word 0 and a flag selected by work +0x184. Consumers run synchronously. */
void func_020e8a30(u32 value, u32 mode)
{
    Unk0e8228Request request;
    Unk0e8228RequestWord enabled;
    Unk0e8228RequestWord selected;
    u32 work;
    int i;
    work = Unk0e8228_Get_data_02176ce0();
    if (work == 0) return;
    func_020f7e48(35, 1, mode);
    Unk0e8228_ClearRequest(&request);
    enabled.value = 1;
    request.words[2] = enabled;
    selected.value = value;
    request.words[3] = selected;
    request.flags[0] |= 12;
    func_020bc9f4(35, &request);
    Unk0e8228_ClearRequest(&request);
    request.words[0].value = 35;
    request.flags[0] |= 1;
    if (FIELD(u32, work, 0x184) != 0) {
        request.words[1].value = 1;
        request.flags[0] |= 2;
    } else {
        request.words[1].value = 0;
        request.flags[0] |= 2;
    }
    FIELD(u32, work, 0x184) = 0;
    func_020bcacc(13, &request);
}

extern u32 data_02176cec[];
extern u32 data_02176d04[][6];

/* Original 020e9ca8 selects a global six-word row using work +8.
 * Selector zero uses the common word; selector five can use its override.
 * Storage is borrowed and work must be readable. */
int func_020e9ca8(u32 work, u32 selector)
{
  int index;
  u32 *row;
  if (FIELD(s32, work, 8) >= 10) { return 0; }
  if (selector == 0) { return FIELD(u32, data_02176ce4, 0); }
  if (selector == 5 && Unk0e8228_Unk_0e8bac() != 0) { return FIELD(u32, data_02176ce4, 4); }
  index = FIELD(s32, work, 8);
  if (index == 0) {
    row = data_02176cec;
    switch (selector) {
    case 1: return row[0];
    case 3: case 4: return row[1];
    case 8: return row[2];
    case 5: return row[3];
    case 6: return row[4];
    case 7: return row[5];
    }
  } else if (index != -1) {
    row = data_02176d04[index - 1];
    switch (selector) {
    case 1: return row[1];
    case 4: return row[2];
    case 5: return row[3];
    case 6: return row[4];
    case 7: return row[5];
    }
  }
  return 0;
}

/* Original 020e9de4 selects a global six-word row using work +8.
 * Selector zero uses the common word; selector five can use its override.
 * Storage is borrowed and work must be readable. */
void func_020e9de4(u32 work, u32 selector, u32 value)
{
  int index;
  u32 *row;
  if (FIELD(s32, work, 8) >= 10) { return; }
  if (selector == 0) { FIELD(u32, data_02176ce4, 0) = value; return; }
  if (selector == 5 && Unk0e8228_Unk_0e8bac() != 0) { FIELD(u32, data_02176ce4, 4) = value; return; }
  index = FIELD(s32, work, 8);
  if (index == 0) {
    row = data_02176cec;
    switch (selector) {
    case 1: row[0] = value; return;
    case 3: case 4: row[1] = value; return;
    case 8: row[2] = value; return;
    case 5: row[3] = value; return;
    case 6: row[4] = value; return;
    case 7: row[5] = value; return;
    }
  } else if (index != -1) {
    row = data_02176d04[index - 1];
    switch (selector) {
    case 1: row[1] = value; return;
    case 4: row[2] = value; return;
    case 5: row[3] = value; return;
    case 6: row[4] = value; return;
    case 7: row[5] = value; return;
    }
  }
  return;
}

/* Original 020e9900 dispatches entry actions for selectors two through five.
 * It preserves the nonzero input token on success and returns zero on failure.
 * Bank offsets and provider byte 0x23 follow the original ARM loads. */
u32 func_020e9900(u32 token, u32 work, u32 selector)
{
    u32 entry;
    u32 record;
    u32 key;
    int index;
    if (token != 0) {
        entry = func_02044ec4(Unk0e8228_Unk_0e8c80());
        switch (selector) {
        case 5:
            index = func_020e9ca8(work, 7);
            if (index == -1) { token = 0; break; }
            if (func_020e8d38(entry, entry + 0x1e8,
                            FIELD(u32, work + index * 4, 0x58), 5) == 0) {
                token = 0; break;
            }
            Unk0e8228_Unk_0e8d18(0);
            break;
        case 2: case 3:
            func_020e9ca8(work, 4);
            record = func_020cb1a0(Unk0e8228_Unk_0e8514());
            key = FIELD(u32, work + func_020e9ca8(work, 6) * 4, 0x30);
            if (FIELD(u8, record, 0x23) == 7) {
                index = func_020e9ca8(work, 7);
                if (index == -1) { token = 0; break; }
                key = FIELD(u32, work + index * 4, 0x58);
            }
            if (func_020e8d38(entry, entry + 0x1e8, key, selector) == 0) {
                token = 0; break;
            }
            Unk0e8228_Unk_0e8d18(0);
            break;
        case 4:
            record = FIELD(u32, work + func_020e9ca8(work, 6) * 4, 0x30);
            if (Unk0e8228_Unk_0e8fe4(Unk0e8228_GetArr88Field20(func_020e9ca8(work, 8))) == 1) {
                index = func_020e9ca8(work, 7);
                if (index == -1) { token = 0; break; }
                record = FIELD(u32, work + index * 4, 0x58);
            }
            if (func_020e8d38(entry, entry + 0x1e8, record, selector) == 0) {
                token = 0; break;
            }
            Unk0e8228_Unk_0e8d18(0);
            break;
        }
    } else {
        token = 0;
    }
    return token;
}

u32 func_020b0874(u32 key, u32 scale);
u32 Unk044904_Unk_044fd8(void);
void func_020aa188(u32 provider, const void *request);
void func_0204a780(u32 entry, u32 state);

/* Original 020e94d8 fills six request words at the supplied writable address.
 * The source key and packed value seed the request; selector-specific provider
 * fields determine the remaining words. Successful requests are submitted
 * synchronously and mark the resolved entry with state four. */
u32 func_020e94d8(u32 work, u32 source, u32 request, u32 value, u32 selector)
{
    u32 record = FIELD(u32, source, 0);
    u32 *out = (u32 *)request;
    int valid = 1;
    out[0] = record;
    out[1] = value;
    switch (selector) {
    case 0: case 1:
        out[2] = 1;
        out[5] = func_020b0874(out[0], 100) | 0x50000000;
        if (((value >> 16) & 255) == 0) valid = 0;
        break;
    case 3:
        if (func_020e9ca8(work, 3) == 0) {
            out[2] = 7;
            out[5] = func_020b0874(out[0], 100) | 0x50000000;
            if (((value >> 16) & 255) == 0) valid = 0;
            break;
        }
    case 2:
        func_020e9ca8(work, 4);
        record = func_020cb1a0(Unk0e8228_Unk_0e8514());
        out[3] = FIELD(u16, record, 0x20);
        out[2] = 6;
        out[5] = func_020b0874(out[0], 100) | 0x50000000;
        if (FIELD(u8, record, 0x23) == 7) out[4] = func_020e9ca8(work, 6);
        if (((value >> 16) & 255) == 0) valid = 0;
        break;
    case 7:
        out[2] = 2;
        out[1] = out[0];
        out[5] = func_020b0874(out[0], 100) | 0xe0000000;
        break;
    case 4:
        record = Unk0e8228_GetArr88Field20(func_020e9ca8(work, 8));
        out[2] = 5;
        out[3] = record;
        out[5] = func_020b0874(out[0], 100) | 0xd8000000;
        if (Unk0e8228_Unk_0e8fe4(record) == 1) out[4] = func_020e9ca8(work, 6);
        if (((value >> 16) & 255) == 0) valid = 0;
        break;
    case 6:
        out[2] = 3;
        out[1] = out[0];
        out[5] = func_020b0874(out[0], 100) | 0xe8000000;
        break;
    case 5:
        out[2] = 3;
        out[1] = out[0];
        record = func_020e9ca8(work, 6);
        if (record == 0) { valid = 0; break; }
        out[3] = record;
        out[4] = (u16)FIELD(u32, work + func_020e9ca8(work, 7) * 4, 0x58);
        out[5] = func_020b0874(out[0], 100) | 0xf0000000;
        break;
    }
    if (valid != 0) {
        func_020aa188(Unk044904_Unk_044fd8(), out);
        func_0204a780(func_02044ec4(out[0]), 4);
    }
    return valid;
}

void Unk0feba0_Unk_0feba0(void);
u32 Unk044904_Get_data_0215ee98(void);
int func_0209993c(u32 id);
void func_02013c68(void *base, int count, int size,
                  int (*compare)(const Unk0e8228SortRecord *const *, const Unk0e8228SortRecord *const *));
int Unk0cb0d0_Unk_0cb1f8(void);
void Unk044394_Unk_044428(u32 id);
void Unk044394_Unk_044534(u32 id);
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 kind, const void *request);

/* Borrowed bank layout established by 020e9060's indexed stores. */
typedef struct Unk0e8228InitBanks {
    u8 prefix[0x30];
    u32 bank30[4];
    u32 bank40[6];
    u32 bank58[12];
    u32 bank88[60];
} Unk0e8228InitBanks;
/* Provider prefix exposes only the ten pointers read by initialization. */
typedef struct Unk0e8228InitProvider {
    u8 prefix[0x64];
    u32 entries[10];
} Unk0e8228InitProvider;

/* Original 020e9060 initializes borrowed work and gathers keys from provider
 * tables, sorts eligible records by byte 0x2e, then starts the provider path
 * when a usable entry exists. All offsets and bounds come from ARM loads. */
void func_020e9060(u32 work)
{
    int count2, count1, count3, count4, id;
    Unk0e8228InitBanks *banks = (Unk0e8228InitBanks *)work;
    u32 provider, record;
    FIELD(u32, work, 0) = 1;
    FIELD(u32, work, 4) = 1;
    FIELD(s32, work, 8) = -1;
    Unk0e8228_Unk_0e8b94();
    FIELD(u32, work, 0x10) = 0;
    FIELD(u32, work, 0x14) = 0;
    FIELD(u32, work, 0x1c) = 0;
    FIELD(u32, work, 0x20) = 0;
    FIELD(u32, work, 0x24) = 0;
    FIELD(u32, work, 0x28) = 0;
    FIELD(u32, work, 0x2c) = 0;
    FIELD(u32, work, 0x184) = 0;
    FIELD(u32, work, 0x17c) = 0;
    FIELD(u32, work, 0x180) = 27;
    Unk0feba0_Unk_0feba0();
    Unk0e8228_ClearSel((Unk0e8228SelHost *)work);
    provider = Unk044904_Get_data_0215ee98();
    count2 = 0; count1 = 0; count3 = 0;
    for (int i = 0; i < 4; i++, count1++) {
        record = ((Unk0e8228InitProvider *)provider)->entries[i];
        if (record != 0) banks->bank30[count1] = FIELD(u32, record, 0);
        else banks->bank30[count1] = 0;
    }
    for (int i = 0; i < 10; i++) {
        record = ((Unk0e8228InitProvider *)provider)->entries[i];
        if (record != 0) {
            u32 key = FIELD(u32, record, 0);
            if (((key >> 16) & 255) == 2) {
                banks->bank40[count2] = key;
                count2++;
            }
        }
    }
    int j;
    u32 *cursor = (u32 *)(provider + 0x36c);
    for (j = 0; j < 12; j++, cursor += 0xb8) {
        u32 key = *cursor;
        if (((key >> 16) & 255) == 1) {
            banks->bank58[count3] = key;
            count3++;
        }
    }
    count4 = 0;
    for (id = 0; id < 60; id++) {
        record = (u32)Unk09974c_Unk_099d14(id + 51);
        switch (FIELD(u8, record, 0x2d)) {
        case 2: case 3:
            if (func_0209993c(id + 51) > 0) {
                banks->bank88[count4] = record;
                count4++;
            }
            break;
        }
    }
    FIELD(u32, work, 0x178) = count4;
    func_02013c68((void *)(work + 0x88), count4, 4, Unk0e8228_Unk_0e9048);
    FIELD(s32, data_02150c30, 0x34) = count1 - 1;
    FIELD(s32, data_02150c30, 0x2c) = count2 - 1;
    FIELD(s32, data_02150c30, 0x3c) = count3 - 1;
    FIELD(s32, data_02150c30, 0x24) = Unk0cb0d0_Unk_0cb1f8() - 1;
    Unk0e8228_Unk_0e9728(work);
    if (func_020e9b54(work) == 0) {
        FIELD(u32, work, 0x2c) = 1;
        Unk044394_Unk_044428(39);
        func_020e82c8();
        Unk044394_Unk_044534(39);
        return;
    }
    func_020e9fd0();
    Unk0e8228_Unk_0e9c94(work, 0);
    for (u32 i = 0; i < 9; i++) {
        u32 slot = data_02150c0c[i];
        Unk0bc1a8_Unk_0bc928(slot, 26, 0);
        func_020bc9f4(slot, (void *)(work + 392));
    }
    if (Unk0e8228_Unk_0e82ac() != 0) return;
    Unk0e8228_Call_02008848();
}

void Unk0ea208_Unk_0ea70c(void);
void Unk0ea208_Unk_0ea828(void);
/* Borrowed bitfield views follow the original shift pairs: record bits 5..8
 * and provider byte 0x2a bit seven. */
typedef struct Unk0e8228ActionRecord {
    u8 prefix[0x24];
    u32 low : 5;
    u32 kind : 4;
    u32 high : 23;
} Unk0e8228ActionRecord;
typedef struct Unk0e8228ActionFlag {
    u8 prefix[0x2a];
    u8 low : 7;
    u8 flag : 1;
} Unk0e8228ActionFlag;

/* Original 020e8710 submits kind-35 requests using a stack-owned flag/word
 * descriptor. Selector, record kind and work +0x184 choose the action and
 * optional word four; the provider consumes the descriptor synchronously.
 * See DEC-013 for the stack-owned one-word request records. */
void func_020e8710(u32 value, u32 selector, u32 record)
{
    Unk0e8228Request request;
    Unk0e8228RequestWord enabled, selected;
    Unk0e8228RequestWord word4, word5, word6, word7, word8, word9, word10;
    u32 work;
    u32 action;
    u32 kind;
    work = Unk0e8228_Get_data_02176ce0();
    if (work == 0) return;
    func_020f7e48(35, 1, selector);
    Unk0e8228_ClearRequest(&request);
    enabled.value = 1;
    request.words[2] = enabled;
    selected.value = value;
    request.words[3] = selected;
    request.flags[0] |= 12;
    func_020bc9f4(35, &request);
    Unk0e8228_ClearRequest(&request);
    action = 0;
    switch (selector) {
    case 0: case 1: action = 0; break;
    case 4:
        if (FIELD(u32, work, 0x184) != 0) { action = 2; break; }
        if (record != 0) {
            kind = ((Unk0e8228ActionRecord *)record)->kind;
            switch (kind) {
            case 3: case 8: action = 4; break;
            case 4: {
                action = 5;
                word4.value = FIELD(u32, work, 8);
                request.words[4] = word4;
                request.flags[0] |= 16;
                break;
            }
            default:
                record = Unk0e8228_Unk_0e8374(6);
                if (Unk0e8228_Unk_0e82ac() == 0) record = 0;
                word5.value = record;
                request.words[4] = word5;
                request.flags[0] |= 16;
                break;
            }
        } else {
            if (((Unk0e8228ActionFlag *)Unk0e8228_Unk_0e84fc())->flag) { action = 4; break; }
            action = 0;
            record = Unk0e8228_Unk_0e8374(6);
            if (Unk0e8228_Unk_0e82ac() == 0) record = 0;
            word6.value = record;
            request.words[4] = word6;
            request.flags[0] |= 16;
        }
        break;
    case 2: case 3:
        if (FIELD(u32, work, 0x184) != 0) { action = 2; break; }
        if (FIELD(u8, record, 0x23) == 7) { action = 3; break; }
        switch (((Unk0e8228ActionRecord *)record)->kind) {
        case 5:
            Unk0ea208_Unk_0ea70c();
            Unk0ea208_Unk_0ea828();
        case 3: case 8:
            action = 4;
            break;
        case 4:
            action = 5;
            word7.value = FIELD(u32, work, 8);
            request.words[4] = word7;
            request.flags[0] |= 16;
            break;
        default:
            action = 0;
            record = Unk0e8228_Unk_0e8374(6);
            if (Unk0e8228_Unk_0e82ac() == 0) record = 0;
            word8.value = record;
            request.words[4] = word8;
            request.flags[0] |= 16;
            break;
        }
        break;
    case 5:
        action = Unk0e8228_Unk_0e8374(6);
        if (Unk0e8228_Unk_0e82ac() == 0) action = 0;
        word9.value = action;
        request.words[4] = word9;
        request.flags[0] |= 16;
        action = 1;
        break;
    case 6: case 7:
        action = 5;
        word10.value = FIELD(u32, work, 8);
        request.words[4] = word10;
        request.flags[0] |= 16;
        break;
    }
    selected.value = action;
    request.words[3] = selected;
    request.flags[0] |= 8;
    FIELD(u32, work, 0x184) = 0;
    Unk0bc1a8_Unk_0bc928(14, 35, &request);
}
