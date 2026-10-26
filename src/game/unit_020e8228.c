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
int func_020e9c00();
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


int func_020e8628();
int func_020ea0ec();
int func_020ea160();
/* decompiler-derived */
void Unk0e8228_Unk_0e9728(void)
{
  int value;
  value = func_020e8628();
  if (value == 1) {
    func_020ea0ec();
    return;
  }
  func_020ea160();
}


/* decompiler-derived */
void Unk0e8228_Unk_0e9f18(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
}


/* decompiler-derived */
void Unk0e8228_Unk_0e9f38(u32 *arg0,u32 arg1)
{
  *arg0 = arg1;
  arg0[1] = 0;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
}

int Unk0e8228_GetArr30();
int Unk0e8228_Unk_0e8ce8();
/* decompiler-derived */
int Unk0e8228_Unk_0e8bc4(void)
{
  int value;
  func_02044ec4(Unk0e8228_GetArr30(0));
  value = Unk0e8228_Unk_0e8ce8();
  return value != 0;
}


/* decompiler-derived */
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


int func_020e9900();
/* decompiler-derived */
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

int func_020e9aa0();
/* decompiler-derived */
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
int func_020e9060();
/* decompiler-derived */
void Unk0e8228_Unk_0e9fa4(u32 arg0)
{
  func_02008848(arg0,0,0x1cc);
  *data_02176ce0 = arg0;
  func_020e9060(arg0);
}



int Unk044904_Unk_0459fc();
int func_02053800();
int func_020e82c8();
int Unk0e8228_IsField4One();
int Unk0fd9f0_Unk_0fda58();
int Unk100208_Unk_100208();
/* decompiler-derived */
u32 Unk0e8228_Unk_0e85c8(void)
{
  int value;
  value = Unk0e8228_Get_data_02176ce0();
  if (value == 0) {
    return 0;
  }
  value = Unk0e8228_IsField4One(value);
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
int func_020e9ca8();
int func_020e9b54();
u8 *func_020982c0();
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

int Unk0e8228_Unk_0e8374(u32 x)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return func_020e9ca8(p, x);
}

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

int Unk0e8228_IsField4One(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 4) == 1;
}

int Unk0e8228_IsFieldCOne(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 12) == 1;
}

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

int func_020e9de4();
/* decompiler-derived */
void Unk0e8228_Unk_0e8d90(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = Unk0e8228_Get_data_02176ce0();
  if (tmp1 == 0) {
    return;
  }
  func_020e9de4(tmp1,arg0,arg1);
}

int func_020cb1a0();
typedef struct Unk0e8228Sel {
    u8 a[2];
    u8 pad[2];
    u32 b[16];
} Unk0e8228Sel;
typedef struct Unk0e8228SelHost {
    u8 pad[392];
    Unk0e8228Sel sel;
} Unk0e8228SelHost;
int Unk0e8228_IsState3(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 0) == 3;
}

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
