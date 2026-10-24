/* ARM callback and work-area layouts inferred from the original accesses. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0cce38Work {
    u8 unk_0000;
    u8 unk_0001;
    u8 unk_0002;
    u8 unk_0003;
    u32 unk_0004;
    u8 pad_0008[0x74];
    u32 unk_007c;
    u8 pad_0080[0x38];
    u32 unk_00b8;
    u32 unk_00bc;
    u32 unk_00c0;
} Unk0cce38Work;

void func_020cb3dc(void);
void Unk095560_Unk_095a2c(void);
int func_020de8b0(int mode);
void Unk0cb32c_Unk_0cb32c(void);
void Unk0bc1a8_Unk_0bc928(int id, int value, int flags);
/* 020cce38: entry sequence; the mode query gates setup of id 17. */
void Unk0cce38_Enter(void)
{
    func_020cb3dc();
    Unk095560_Unk_095a2c();
    if (func_020de8b0(0) != 0) {
        return;
    }
    Unk0cb32c_Unk_0cb32c();
    Unk0bc1a8_Unk_0bc928(17, 0xffff, 0);
}

/* 020cce70: the original callback returns immediately without side effects. */
void Unk0cce38_Nop_0cce70(void) { }

/* 020cd46c: the original callback returns immediately without side effects. */
void Unk0cce38_Nop_0cd46c(void) { }

void Unk0cb32c_Unk_0cb754(u32 *slot);
/* 020cd45c: forward the address of the borrowed work handle slot at +0x7c. */
void Unk0cce38_Unk_0cd45c(Unk0cce38Work *work)
{
    Unk0cb32c_Unk_0cb754(&work->unk_007c);
}

void Unk095560_Unk_0956c8(void);
void Unk0bc1a8_Unk_0bc9b4(int id, int value);
void Unk0de678_Unk_0de870(void);
int Unk0de678_Get_data_021508d4(void);
void Unk0cb32c_Unk_0cb344(void);
/* 020cce74: conditionally finish id 17, then run both unconditional helpers. */
void Unk0cce38_Unk_0cce74(void)
{
    if (Unk0de678_Get_data_021508d4() == 0) {
        Unk0bc1a8_Unk_0bc9b4(17, 0);
        Unk0cb32c_Unk_0cb344();
    }
    Unk0de678_Unk_0de870();
    Unk095560_Unk_0956c8();
}

void Unk122e1c_Unk_122ff0(u32 handle);
/* 020cd430: notify the +0x7c handle, latch the argument, and set state bytes. */
void Unk0cce38_Unk_0cd430(Unk0cce38Work *work, u32 value)
{
    Unk122e1c_Unk_122ff0(work->unk_007c);
    work->unk_00b8 = value;
    work->unk_0002 = 1;
    work->unk_0000 = 3;
}

extern u32 data_02176bc8[];
void ImageBg_Unk_0e5530(void);
void Unk0de678_Unk_0dea60(void);
void func_02122e1c(u32 handle);
/* 020ccfac: release the work handle, run teardown helpers, and clear the singleton. */
void Unk0cce38_Unk_0ccfac(Unk0cce38Work *work)
{
    func_02122e1c(work->unk_007c);
    work->unk_007c = 0;
    ImageBg_Unk_0e5530();
    Unk0de678_Unk_0dea60();
    *data_02176bc8 = 0;
}

void func_020525cc(int value);
void func_02052634(int a, int b, int c);
void func_020de960(void *records, int mode);
u32 Unk0de678_CountLeading(void *records);
void func_02122abc(u32 handle);
void ImageBg_Unk_0e54d4(u32 value);
void Unk0bcef4_Unk_0bcef4(void *control, int a, int b, int c);
void Unk0cb32c_Unk_0cb35c(u32 value);
/* 020ccefc: existing work initializer; record/control offsets follow original stores. */
void Unk0cce38_Unk_0ccefc(u8 *arg0)
{
  u32 tmp1;
  func_020de960(arg0 + 8,0);
  ImageBg_Unk_0e54d4(arg0[0x10]);
  func_02122abc(((Unk0cce38Work *)arg0)->unk_007c);
  Unk0bcef4_Unk_0bcef4(arg0 + 0x80,5,5,1);
  tmp1 = Unk0de678_CountLeading(arg0 + 8);
  Unk0bcef4_Unk_0bcef4(arg0 + 0x9c,tmp1,tmp1,1);
  *data_02176bc8 = (u32)(arg0);
  func_02052634(1,0,0x1f);
  func_020525cc(0);
  ((Unk0cce38Work *)arg0)->unk_00b8 = 8;
  *arg0 = 0;
  arg0[2] = 2;
  arg0[1] = 0;
  ((Unk0cce38Work *)arg0)->unk_00bc = 0;
  ((Unk0cce38Work *)arg0)->unk_00c0 = 1;
  ((Unk0cce38Work *)arg0)->unk_0004 = 1;
  Unk0cb32c_Unk_0cb35c(arg0[0x11]);
}

/* Borrowed descriptor; +8 is deliberately preserved by the original writer. */
typedef struct Unk0cce38Descriptor {
    u32 work_size;
    u32 unk_0004;
    u32 unk_0008;
    void (*callback_000c)(void *);
    void (*callback_0010)(void *);
    void (*callback_0014)(void *);
    void (*callback_0018)(void *);
    void (*callback_001c)(Unk0cce38Work *);
    void (*callback_0020)(void *, const u32 *);
} Unk0cce38Descriptor;

void func_020ccfe0(void *work);
void func_020cd200(void *work);
void Unk0cd470_Unk_0cd470(void *work);
void func_020cd490(void *work);
void func_020cd49c(void *work, const u32 *event);

/* 020ccea0: descriptor stores prove a 0xc4-byte work size and six callback slots;
 * preserve +8 because the original never writes it. Ownership stays with caller. */
void func_020ccea0(Unk0cce38Descriptor *descriptor)
{
    descriptor->work_size = 0xc4;
    descriptor->unk_0004 = 0;
    descriptor->callback_000c = func_020ccfe0;
    descriptor->callback_0010 = func_020cd200;
    descriptor->callback_0014 = Unk0cd470_Unk_0cd470;
    descriptor->callback_0018 = func_020cd490;
    descriptor->callback_001c = Unk0cce38_Unk_0ccfac;
    descriptor->callback_0020 = func_020cd49c;
}
