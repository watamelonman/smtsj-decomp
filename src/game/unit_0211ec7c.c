/* State callbacks with work-area offsets preserved from the original code. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses.
 * Total size 0x31c: func_0211eccc stores that value as the descriptor's work size. */
typedef struct Unk11ec7cWork {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    s32 unk_000c;
    s32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    s32 unk_001c;
    float unk_0020;             /* func_0211ee10 stores (float)n / 10.0f */
    s16 unk_0024;
    u8 pad_0026[0x82];
    u32 unk_00a8;
    u8 pad_00ac[0x4];
    u32 unk_00b0;
    u8 pad_00b4[0x1b4];
    u32 unk_0268;
    u32 unk_026c;
    u32 unk_0270;
    s32 unk_0274;
    u8 pad_0278[0x6c];
    u32 unk_02e4;
    u8 pad_02e8[0x30];
    u32 unk_0318;
} Unk11ec7cWork;

/* Callback slot in Unk11ec7cDesc; Unk11ec7c_Unk_11ec7c (slot +0x1c) takes the work area. */
typedef void (*Unk11ec7cCallback)(Unk11ec7cWork *work);

/* Descriptor filled by func_0211eccc: work size, a flag word and six callbacks. */
typedef struct Unk11ec7cDesc {
    u32 unk_0000;               /* work size (0x31c == sizeof(Unk11ec7cWork)) */
    u32 unk_0004;
    u8 pad_0008[0x4];
    Unk11ec7cCallback unk_000c;
    Unk11ec7cCallback unk_0010;
    Unk11ec7cCallback unk_0014;
    Unk11ec7cCallback unk_0018;
    Unk11ec7cCallback unk_001c;
    Unk11ec7cCallback unk_0020;
} Unk11ec7cDesc;

/* Sprite-like record returned by func_0205e318; only +0xc is read here. */
typedef struct Unk11ec7cRecord {
    u8 pad_0000[0xc];
    s16 unk_000c;
} Unk11ec7cRecord;

int Unk044394_Unk_044534();
void func_02053000(u32 handle);
/* Releases the handles at +0x26c, +0xa8 and +0xb0 through func_02053000 and clears
 * them; when +0x274 is set (func_0211ed28 registered entry 0x24) calls 0x02044534(0x24). */
void Unk11ec7c_Unk_11ec7c(Unk11ec7cWork *arg0)
{
  func_02053000(arg0->unk_026c);
  arg0->unk_026c = 0;
  func_02053000(arg0->unk_00a8);
  arg0->unk_00a8 = 0;
  func_02053000(arg0->unk_00b0);
  arg0->unk_00b0 = 0;
  if (arg0->unk_0274 == 0) {
    return;
  }
  Unk044394_Unk_044534(0x24);
  return;
}

void func_0211dc74(Unk11ec7cWork *work);
void func_0211de14(Unk11ec7cWork *work);
void func_0211e0ec(Unk11ec7cWork *work);
void func_0211e260(Unk11ec7cWork *work);
void func_0211e6b8(Unk11ec7cWork *work);
/* Fills a descriptor: work size 0x31c, +4 = 1 and the six callbacks
 * (0x0211de14, 0x0211e0ec, 0x0211e260, 0x0211e6b8, Unk11ec7c_Unk_11ec7c, 0x0211dc74). */
void func_0211eccc(Unk11ec7cDesc *desc)
{
    desc->unk_0000 = sizeof(Unk11ec7cWork);
    desc->unk_0004 = 1;
    desc->unk_000c = func_0211de14;
    desc->unk_0010 = func_0211e0ec;
    desc->unk_0014 = func_0211e260;
    desc->unk_0018 = func_0211e6b8;
    desc->unk_001c = Unk11ec7c_Unk_11ec7c;
    desc->unk_0020 = func_0211dc74;
}

extern u8 data_02151f98[];
int Unk044394_HasEntry(u32 id);
void Unk044394_Unk_044428(u32 id);
u32 func_0204459c(u32 id);
u32 func_02051610(const void *path);
void func_02119390(void);
/* Initialises the work area: registers entry 0x24 unless it already exists (+0x274
 * records whether it did), stores func_0204459c(0x26) at +0x270, loads data_02151f98
 * into +0x26c and clears the other handles before calling 0x02119390. */
void func_0211ed28(Unk11ec7cWork *work)
{
    s32 registered;

    work->unk_0000 = 0;
    if (Unk044394_HasEntry(0x24)) {
        registered = 0;
    } else {
        Unk044394_Unk_044428(0x24);
        registered = 1;
    }
    work->unk_0274 = registered;
    work->unk_0270 = func_0204459c(0x26);
    work->unk_0004 = 0;
    work->unk_02e4 = 0;
    work->unk_026c = func_02051610(data_02151f98);
    work->unk_0268 = 0;
    work->unk_00a8 = 0;
    work->unk_00b0 = 0;
    work->unk_0318 = 0;
    func_02119390();
}

/* Global work area; only the halfword at +0x35c is read here. */
typedef struct Unk11ec7cGlobal {
    u8 pad_0000[0x35c];
    u16 unk_035c;
} Unk11ec7cGlobal;

Unk11ec7cGlobal *Unk02e000_GetWorkArea(void);
int func_0203546c(u16 *buf, int len, u32 id);
void func_02061f10(u32 handle, int a, int b, int c, u16 *value);
/* Formats the global +0x35c value into a zeroed 16-halfword buffer with
 * func_0203546c, then passes it to func_02061f10(handle, -1, 0, 0, buf). */
void func_0211eda0(u32 handle)
{
    u16 buf[16] = {0};

    func_0203546c(buf, 16, Unk02e000_GetWorkArea()->unk_035c);
    func_02061f10(handle, -1, 0, 0, buf);
}

Unk11ec7cRecord *func_0205e318(u32 handle, int index);
/* Uses n = +0x1c - 2: when positive, fetches record 1 of handle +4, sets +0x24 to
 * record->unk_000c * n / 10 if scale == 1, and +0x20 to n / 10.0f; otherwise clears both. */
void func_0211ee10(Unk11ec7cWork *work, int scale)
{
    s32 n = work->unk_001c - 2;
    Unk11ec7cRecord *record;

    if (n > 0) {
        record = func_0205e318(work->unk_0004, 1);
        if (scale == 1) {
            work->unk_0024 = record->unk_000c * n / 10;
        }
        work->unk_0020 = (float)n / 10.0f;
        return;
    }
    work->unk_0024 = 0;
    work->unk_0020 = 0;
}

int func_0205dde4();
/* Requires a valid borrowed work area; forwards the words at +4 and +8 to helpers. */
void Unk11ec7c_Unk_11ee8c(Unk11ec7cWork *arg0)
{
  func_0205dde4(arg0->unk_0004);
  func_0211eda0(arg0->unk_0008);
  return;
}

/* State 1 tick: increments +0x1c and rescales; at 12 it queues state 2, resets
 * +0x18, clamps +0x1c to 12 and sets +0x24 to the record value and +0x20 to 1.0f. */
void func_0211eea8(Unk11ec7cWork *work)
{
    Unk11ec7cRecord *record;

    work->unk_001c = work->unk_001c + 1;
    func_0211ee10(work, 1);
    if (work->unk_001c < 12) {
        return;
    }
    record = func_0205e318(work->unk_0004, 1);
    work->unk_0010 = 2;
    work->unk_0018 = 0;
    work->unk_001c = 12;
    work->unk_0024 = record->unk_000c;
    work->unk_0020 = 1.0f;
}

/* Empty entry callback: the original at 0x0211ef08 only returns. */
void Unk11ec7c_Nop_11ef08(void) { }

/* Increments +0x18 with unsigned wrap; queues state 3 when it exceeds +0x14. */
void Unk11ec7c_Unk_11ef0c(Unk11ec7cWork *arg0)
{
  u32 tmp1;
  tmp1 = arg0->unk_0018 + 1;
  arg0->unk_0018 = tmp1;
  if (arg0->unk_0014 < tmp1) {
    arg0->unk_0010 = 3;
  }
  return;
}

/* Decrements +0x1c, calls 0x0211ee10 with zero, then clears state fields if expired. */
void Unk11ec7c_Unk_11ef2c(Unk11ec7cWork *arg0)
{
  arg0->unk_001c = arg0->unk_001c + -1;
  func_0211ee10(arg0,0);
  if (0 < arg0->unk_001c) {
    return;
  }
  arg0->unk_0010 = 0;
  arg0->unk_0014 = 0;
  arg0->unk_0018 = 0;
  arg0->unk_001c = 0;
  arg0->unk_0024 = 0;
  arg0->unk_0020 = 0;
  return;
}

/* Applies the queued state. Evidence: copies +0x10 to +0xc, resets +0x10
 * to -1 and invokes the entry callback. Requires a valid borrowed work area. */
void Unk11ec7c_ApplyNext(Unk11ec7cWork *p)
{
    p->unk_000c = p->unk_0010;
    p->unk_0010 = -1;
    switch (p->unk_000c) {
    case 1:
        Unk11ec7c_Unk_11ee8c(p);
        return;
    case 2:
        Unk11ec7c_Nop_11ef08();
        return;
    }
}

/* Dispatches the current state. Evidence: the +0xc switch calls one of
 * three callbacks. Requires a valid borrowed work area; other states do nothing. */
void Unk11ec7c_Dispatch(Unk11ec7cWork *p)
{
    switch ((u32)p->unk_000c) {
    case 0:
        break;
    case 1:
        func_0211eea8(p);
        break;
    case 2:
        Unk11ec7c_Unk_11ef0c(p);
        break;
    case 3:
        Unk11ec7c_Unk_11ef2c(p);
        break;
    }
}

int Unk02e000_Unk_02e0cc();
int Unk05b82c_Unk_05b82c();
/* Calls 0x0202e0cc then 0x0205b82c with 0xd2; always returns 1. */
u32 Unk11ec7c_Unk_11efec(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xd2);
  return 1;
}

extern u8 data_02151fb4[];
void func_02008848(void *dst, int value, u32 size);
int func_0205dcd4();
int func_020629ac();
/* Activates the work area once: zero-fills its first 0x28 bytes, sets +0 to 1,
 * clears the state words, and loads the handles at +4 and +8. */
void Unk11ec7c_Unk_11f004(Unk11ec7cWork *arg0)
{
  if (arg0->unk_0000 == 1) {
    return;
  }
  func_02008848(arg0,0,0x28);
  arg0->unk_0000 = 1;
  arg0->unk_000c = 0;
  arg0->unk_0010 = 0;
  Unk02e000_Unk_02e0cc();
  arg0->unk_0004 = func_0205dcd4(data_02151fb4,1);
  arg0->unk_0008 = func_020629ac(5,1,1,1);
  return;
}

/* Updates an active work area. Evidence: +0 gates ApplyNext and Dispatch.
 * The queued-state sentinel is -1; the caller retains ownership of p. */
void Unk11ec7c_Update(Unk11ec7cWork *p)
{
    if (p->unk_0000 == 0) {
        return;
    }
    if (p->unk_0010 != -1) {
        Unk11ec7c_ApplyNext(p);
    }
    Unk11ec7c_Dispatch(p);
}
