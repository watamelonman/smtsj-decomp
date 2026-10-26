/* src/game/unit_020c855c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0c855cWork {
    u8 pad_0000[0x1c];
    u32 unk_001c;
    u8 pad_0020[0x10];
    s32 unk_0030;
    u8 pad_0034[0x6];
    u16 unk_003a;
    u8 pad_003c[0x16c];
    u32 unk_01a8;
    u32 unk_01ac;
    u32 unk_01b0;
    u32 unk_01b4;
} Unk0c855cWork;

/* Return the subregion at byte offset 0x6180; original uses two adds. */
u8 *Unk0c855c_Unk_0ca690(u8 *arg0)
{
  return arg0 + 0x6180;
}


/* Clear words 0, 5, 6 and 7; caller must provide at least eight words. */
void Unk0c855c_Unk_0ca58c(u32 *arg0)
{
  *arg0 = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  arg0[7] = 0;
}

int func_020c98ec(int record, u32 value, u32 mode);
/* Forward value with mode zero for the selected 0x60-byte record. */
int Unk0c855c_Unk_0c9b90(int arg0,int arg1,u32 arg2)
{
  return func_020c98ec(arg1 * 0x60 + arg0,arg2,0);
}


/* Set word 0x1c on each of four records whose word 0x30 is nonzero. */
void Unk0c855c_Unk_0c9d8c(u8 *arg0)
{
  int value;
  value = 0;
  do {
    value = value + 1;
    if (((Unk0c855cWork *)arg0)->unk_0030 != 0) {
      ((Unk0c855cWork *)arg0)->unk_001c = 1;
    }
    arg0 = arg0 + 0x60;
  } while (value < 4);
}


/* Return one only when word 0x30 is nonzero in all four records. */
u32 Unk0c855c_Unk_0c9bac(u8 *arg0)
{
  int value;
  value = 0;
  do {
    if (((Unk0c855cWork *)arg0)->unk_0030 == 0) {
      return 0;
    }
    value = value + 1;
    arg0 = arg0 + 0x60;
  } while (value < 4);
  return 1;
}


int Unk02e000_Unk_02e0cc(void);
u32 func_02057fd8(void);
int func_020c92f0(u32 work, u32 value, int index, u32 a, u32 b, u32 c);
/* Original 020c9890 obtains three provider values, then passes them to each
 * of four indexed records. The caller retains ownership of work at arg0. */
void Unk0c855c_Unk_0c9890(u32 arg0,u32 arg1)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  int tmp4;
  Unk02e000_Unk_02e0cc();
  tmp1 = func_02057fd8();
  tmp2 = func_02057fd8();
  tmp3 = func_02057fd8();
  tmp4 = 0;
  do {
    func_020c92f0(arg0,arg1,tmp4,tmp1,tmp2,tmp3);
    tmp4 = tmp4 + 1;
  } while (tmp4 < 4);
  return;
}


/* Original 020c9c5c dispatches value 2 for state-3 records, then value 3
 * for a nonnegative selected index; arg0 covers four 0x60-byte records. */
void Unk0c855c_Unk_0c9c5c(int arg0,int arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = 0;
  tmp2 = arg0;
  do {
    if (*(int *)(tmp2 + 4) == 3) {
      Unk0c855c_Unk_0c9b90(arg0,tmp1,2);
    }
    tmp1 = tmp1 + 1;
    tmp2 = tmp2 + 0x60;
  } while (tmp1 < 4);
  if (arg1 < 0) {
    return;
  }
  Unk0c855c_Unk_0c9b90(arg0,arg1,3);
  return;
}

int func_020537b8(int group, u32 mask);
/* Original 020c855c tests masks 0x40, 0x80, 0x20 and 0x10, latching
 * their nonzero results into work words 0x1a8 through 0x1b4. */
void Unk0c855c_Unk_0c855c(int arg0)
{
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01a8 = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01ac = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01b0 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01b4 = 1;
  }
  return;
}

extern u8 data_0213c54c[];
void Unk0ca69c_Unk_0ca6a4(u32 value);
/* Dispatch the byte table entry indexed by the unsigned halfword at 0x3a. */
void Unk0c855c_Unk_0c92c0(Unk0c855cWork *arg0)
{
  Unk0ca69c_Unk_0ca6a4(*(u8 *)(data_0213c54c + (u32)((Unk0c855cWork *)arg0)->unk_003a));
}

extern u8 data_0213c51c[];
/* Return the word table entry; the halfword at 0x3a must be a valid index. */
u32 Unk0c855c_Unk_0c92dc(Unk0c855cWork *arg0)
{
  return *(u32 *)(data_0213c51c + (u32)((Unk0c855cWork *)arg0)->unk_003a * 4);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u32 CampStatus_Unk_0d353c();
void func_020616c0();
void func_020ca2e4();
void func_020c9ee0();
void func_0205bb68(void);
/* Original 020ca550 initializes a nine-word callback descriptor; word 2
 * is preserved. Callback identities follow its two address relocations. */
void Unk0c855c_InitCallbacks(u32 *p)
{
    p[0] = 32;
    p[1] = 0;
    p[3] = 0;
    p[4] = (u32)func_020ca2e4;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = (u32)func_020c9ee0;
}

/* Original 020ca648 invokes the provider once for selectors 0 and 1,
 * twelve times for 2, and leaves other selectors without side effects. */
void Unk0c855c_Unk_0ca648(int k)
{
    int j;
    switch (k) {
    case 0:
        func_0205bb68();
        break;
    case 1:
        func_0205bb68();
        break;
    case 2:
        for (j = 0; j < 12; j++) {
            func_0205bb68();
        }
        break;
    }
}

void func_020c9030(u8 *work, int index);
void func_020c8a24(u8 *work);
/* Original 020c9234 advances signed word 0x198 toward the supplied bounds,
 * clears velocity 0x19c at a bound, and updates four records. Work must
 * extend through word 0x1a0, whose nonzero value enables the final call. */
void func_020c9234(u8 *work, int lower, int upper)
{
    int i;
    if (FIELD(int, work, 0x19c) < 0) {
        FIELD(int, work, 0x198) += FIELD(int, work, 0x19c);
        if (FIELD(int, work, 0x198) <= lower) {
            FIELD(int, work, 0x198) = lower;
            FIELD(int, work, 0x19c) = 0;
        }
    }
    if (FIELD(int, work, 0x19c) > 0) {
        FIELD(int, work, 0x198) += FIELD(int, work, 0x19c);
        if (FIELD(int, work, 0x198) >= upper) {
            FIELD(int, work, 0x198) = upper;
            FIELD(int, work, 0x19c) = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        func_020c9030(work, i);
    }
    if (FIELD(int, work, 0x1a0) != 0) {
        func_020c8a24(work);
    }
}

/* Original 020c9bd8 dispatches value 2 for state-2 records, retaining the
 * last result as mode for the selected record. A negative index disables
 * that final dispatch; otherwise it must index the borrowed record array. */
void func_020c9bd8(int base, int selected)
{
    int result = 0;
    int i = 0;
    int record = base;
    do {
        if (*(int *)(record + 4) == 2) {
            result = Unk0c855c_Unk_0c9b90(base, i, 2);
        }
        i++;
        record += 0x60;
    } while (i < 4);
    if (selected < 0) {
        return;
    }
    if (result != 0) {
        func_020c98ec(base + selected * 0x60, 1, result);
    } else {
        Unk0c855c_Unk_0c9b90(base, selected, 1);
    }
}

void Unk05b82c_Unk_05b82c(int id);
/* Original 020ca5a4 resets the provider, then dispatches IDs 195 or 196
 * for selectors 0 or 1, or the twelve IDs 197..208 for selector 2. */
void func_020ca5a4(int selector)
{
    Unk02e000_Unk_02e0cc();
    switch (selector) {
    case 0: Unk05b82c_Unk_05b82c(195); break;
    case 1: Unk05b82c_Unk_05b82c(196); break;
    case 2:
        Unk05b82c_Unk_05b82c(197);
        Unk05b82c_Unk_05b82c(198);
        Unk05b82c_Unk_05b82c(199);
        Unk05b82c_Unk_05b82c(200);
        Unk05b82c_Unk_05b82c(201);
        Unk05b82c_Unk_05b82c(202);
        Unk05b82c_Unk_05b82c(203);
        Unk05b82c_Unk_05b82c(204);
        Unk05b82c_Unk_05b82c(205);
        Unk05b82c_Unk_05b82c(206);
        Unk05b82c_Unk_05b82c(207);
        Unk05b82c_Unk_05b82c(208);
        break;
    }
}
