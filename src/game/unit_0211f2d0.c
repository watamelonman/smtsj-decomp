/* Work-record helpers and singleton state queries. */
#include "types.h"



/* decompiler-derived */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11f2d0Work {
    s32 state;
    s32 countdown;
    u32 field8;
    s16 timer;
    u16 pad_E;
    s32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    u32 unk_0020;
    s32 unk_0024;
    s32 unk_0028;
    s32 unk_002c;
    s32 unk_0030;
} Unk11f2d0Work;

/* Borrowed 0x28-byte record; offsets follow loads/stores at 0x0211f2d0. */
typedef struct Unk11f2d0Record {
    u32 active;
    u32 field4;
    u32 field8;
    u32 fieldC;
    u32 state;
    u32 argument;
    u8 reserved[0x10];
} Unk11f2d0Record;

/* Initial prefix of the singleton work area, observed at 0x0211f664. */
typedef struct Unk11f2d0Prefix {
    s32 state;
    u32 field4;
    u32 field8;
    u16 fieldC;
} Unk11f2d0Prefix;

extern u32 data_02176e78[];
void func_02061424(u32 work);
u32 func_0211f3c8(void);
void func_02008848(void *destination, int value, u32 size);
void func_0205ddb4(u32 value);
void func_020629c4(u32 value);

/* At 0x0211f320, request state 3 only for an active, non-null record. */
void Unk11f2d0_Unk_11f320(Unk11f2d0Record *record)
{
    if (record->active != 0) {
        record->state = 3;
    }
}

/* At 0x0211f308, latch the argument before requesting state 1 if active. */
void Unk11f2d0_Unk_11f308(Unk11f2d0Record *record, u32 argument)
{
    if (record->active != 0) {
        record->argument = argument;
        record->state = 1;
    }
}

/* Initialize only the prefix fields written at 0x0211f664; retain the tail. */
void Unk11f2d0_Unk_11f664(Unk11f2d0Prefix *work)
{
    work->state = 0;
    work->field4 = 11;
    work->field8 = 0;
    work->fieldC = 0;
}

/* Forward the existing singleton to 0x02061424, as seen at 0x0211f37c. */
void Unk11f2d0_Unk_11f37c(void)
{
    if (*data_02176e78 == 0) {
        return;
    }
    func_02061424(*data_02176e78);
}

/* At 0x0211f354, publish the factory result only while the singleton is absent. */
void Unk11f2d0_Unk_11f354(void)
{
    u32 value;
    if (*data_02176e78 != 0) {
        return;
    }
    value = func_0211f3c8();
    *data_02176e78 = value;
}

/* At 0x0211f2d0, release fields 4/8 in order, then clear the active record. */
void Unk11f2d0_Unk_11f2d0(Unk11f2d0Record *record)
{
    if (record->active == 0) {
        return;
    }
    func_0205ddb4(record->field4);
    func_020629c4(record->field8);
    func_02008848(record, 0, 0x28);
}

void func_0205c408(u32 object, int index);
void func_0205c6e0(u32 object);
u32 *Unk065e88_Call_02065fc0(u32 resource, u32 context, int mode, int flags);

/* The load at 0x0211f340 tests word +0xC; a null record returns false. */
int Unk11f2d0_IsFieldCSet(const Unk11f2d0Record *record)
{
    if (record == 0) {
        return 0;
    }
    return record->fieldC != 0;
}

/* The compare at 0x0211f3b4 tests state 7; an absent singleton is also ready. */
int Unk11f2d0_IsState7(void)
{
    const Unk11f2d0Prefix *work = (const Unk11f2d0Prefix *)*data_02176e78;
    if (work == 0) {
        return 1;
    }
    return work->state == 7;
}

/* At 0x0211f544, create slot +0x24 once, select index 0, then start it. */
void Unk11f2d0_Unk_11f544(Unk11f2d0Work *work)
{
    u32 *object;
    if (work->unk_0024 != 0) {
        return;
    }
    object = Unk065e88_Call_02065fc0(work->unk_0014, work->unk_001c, 1, 0);
    work->unk_0024 = (s32)object;
    func_0205c408(*object, 0);
    func_0205c6e0(*(u32 *)work->unk_0024);
}


/* At 0x0211f58c, create slot +0x28 once, select index 1, then start it. */
void Unk11f2d0_Unk_11f58c(Unk11f2d0Work *work)
{
    u32 *object;
    if (work->unk_0028 != 0) {
        return;
    }
    object = Unk065e88_Call_02065fc0(work->unk_0014, work->unk_001c, 1, 0);
    work->unk_0028 = (s32)object;
    func_0205c408(*object, 1);
    func_0205c6e0(*(u32 *)work->unk_0028);
}


/* At 0x0211f5d4, create slot +0x2c once, select index 2, then start it. */
void Unk11f2d0_Unk_11f5d4(Unk11f2d0Work *work)
{
    u32 *object;
    if (work->unk_002c != 0) {
        return;
    }
    object = Unk065e88_Call_02065fc0(work->unk_0014, work->unk_001c, 1, 0);
    work->unk_002c = (s32)object;
    func_0205c408(*object, 2);
    func_0205c6e0(*(u32 *)work->unk_002c);
}


/* At 0x0211f61c, create slot +0x30 once, select index 0, then start it. */
void Unk11f2d0_Unk_11f61c(Unk11f2d0Work *work)
{
    u32 *object;
    if (work->unk_0030 != 0) {
        return;
    }
    object = Unk065e88_Call_02065fc0(work->unk_0018, work->unk_0020, 0, 0);
    work->unk_0030 = (s32)object;
    func_0205c408(*object, 0);
    func_0205c6e0(*(u32 *)work->unk_0030);
}

void func_0205bb68(void);
void func_0205c368(u32 context);
/* Release nonzero slots and resources in observed order, then clear the singleton. */
void Unk11f2d0_Unk_11f43c(Unk11f2d0Work *arg0)
{
  u32 tmp1;
  if (((Unk11f2d0Work *)arg0)->unk_0024 != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_0024);
    ((Unk11f2d0Work *)arg0)->unk_0024 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0028 != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_0028);
    ((Unk11f2d0Work *)arg0)->unk_0028 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_002c != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_002c);
    ((Unk11f2d0Work *)arg0)->unk_002c = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0030 != 0) {
    func_02061424(((Unk11f2d0Work *)arg0)->unk_0030);
    ((Unk11f2d0Work *)arg0)->unk_0030 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_001c != 0) {
    func_0205c368(arg0->unk_001c);
    ((Unk11f2d0Work *)arg0)->unk_001c = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0020 != 0) {
    func_0205c368(arg0->unk_0020);
    ((Unk11f2d0Work *)arg0)->unk_0020 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0010 != 0) {
    func_0205ddb4(((Unk11f2d0Work *)arg0)->unk_0010);
    ((Unk11f2d0Work *)arg0)->unk_0010 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0014 != 0) {
    func_0205ddb4(((Unk11f2d0Work *)arg0)->unk_0014);
    ((Unk11f2d0Work *)arg0)->unk_0014 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0018 != 0) {
    func_0205ddb4(((Unk11f2d0Work *)arg0)->unk_0018);
    ((Unk11f2d0Work *)arg0)->unk_0018 = 0;
  }
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 5);
  *data_02176e78 = 0;
  return;
}

extern u32 data_0213cd2c[];
extern const char data_02151fc4[], data_02151fd4[], data_02151ff0[];
extern const char data_0215200c[], data_02152028[];
void Unk05b82c_Unk_05b82c(u32 value);
u32 func_0205dcd4(const char *path, int mode);
u32 func_0205c2c4(const char *path);
void Unk0a0ce4_Unk_0a0da4(int value);
int func_02053800(int index, int mask);
void func_0211f894(Unk11f2d0Work *work);
void func_0211f974(Unk11f2d0Work *work);
void func_0211f704(Unk11f2d0Work *work);
u32 func_020611dc(void (*update)(Unk11f2d0Work *),
    void (*callback1)(Unk11f2d0Work *), void (*callback2)(Unk11f2d0Work *),
    void (*destroy)(Unk11f2d0Work *), u32 size, int alignment, int flags, int mode);

/* At 0x0211f67c, register five table entries and load the five work resources. */
void func_0211f67c(Unk11f2d0Work *work)
{
    u32 i;
    for (i = 0; i < 5; i++) {
        Unk05b82c_Unk_05b82c(data_0213cd2c[i]);
    }
    work->unk_0010 = func_0205dcd4(data_02151fc4, 1);
    work->unk_0014 = func_0205dcd4(data_02151fd4, 1);
    work->unk_0018 = func_0205dcd4(data_02151ff0, 1);
    work->unk_001c = func_0205c2c4(data_0215200c);
    work->unk_0020 = func_0205c2c4(data_02152028);
}

/* Allocate 0x34 bytes with the four observed callbacks; initialize only on success. */
u32 func_0211f3c8(void)
{
    Unk11f2d0Work *work = (Unk11f2d0Work *)func_020611dc(func_0211f704,
        func_0211f894, func_0211f974, Unk11f2d0_Unk_11f43c, 0x34, 4, 0, 1);
    if (work == 0) {
        return 0;
    }
    Unk11f2d0_Unk_11f664((Unk11f2d0Prefix *)work);
    func_0211f67c(work);
    return (u32)work;
}

/* Advance states 0..7 using call-count delays and the signed halfword timeout.
 * Evidence: dispatch and field accesses at 0x0211f704..0x0211f88c. */
void func_0211f704(Unk11f2d0Work *work)
{
    int finished;
    switch (work->state) {
    case 0:
        if (--work->countdown < 1) {
            work->state = 1;
            work->countdown = 2;
            Unk11f2d0_Unk_11f544(work);
        }
        break;
    case 1:
        if (--work->countdown < 1) {
            work->state = 2;
            work->countdown = 8;
            Unk0a0ce4_Unk_0a0da4(41);
        }
        break;
    case 2:
        if (--work->countdown < 1) {
            work->state = 3;
            work->countdown = 20;
            Unk11f2d0_Unk_11f58c(work);
        }
        break;
    case 3:
        if (--work->countdown < 1) {
            work->state = 4;
            work->countdown = 30;
            Unk11f2d0_Unk_11f61c(work);
        }
        break;
    case 4:
        if (--work->countdown < 1) {
            work->state = 5;
            work->timer = 600;
            Unk11f2d0_Unk_11f5d4(work);
        }
        break;
    case 5:
        finished = 0;
        if (--work->timer < 1) {
            finished = 1;
        }
        if (func_02053800(0, 0xc03)) {
            Unk0a0ce4_Unk_0a0da4(1);
            finished = 1;
        }
        if (finished) {
            work->countdown = 11;
            work->state = 6;
        }
        break;
    case 6:
        if (--work->countdown < 1) {
            work->state = 7;
        }
        break;
    case 7:
        break;
    }
}
