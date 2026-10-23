/* ImageBg work-state helpers, verified against the delinked ARM object. */
#include "types.h"


/* The callback at 0x020e5664 reads mode at +4 and the pair at +12/+16.
 * Unidentified words retain neutral names; this view owns no storage. */
typedef struct ImageBgWork {
    u32 field00;
    u32 mode;
    u32 field08;
    u32 field0c;
    u32 field10;
} ImageBgWork;

extern u32 data_02176ca4[];
/* Return the borrowed work address (zero when absent): 0x020e5570 loads
 * data_02176ca4[0] directly. The integer return preserves the existing ABI. */
u32 ImageBg_Get_data_02176ca4(void)
{
  return *data_02176ca4;
}


/* Report work presence as 0/1; 0x020e54b8 compares the global word to zero. */
int ImageBg_IsSet_data_02176ca4(void)
{
  return *data_02176ca4 != 0;
}

void ImageBg_Release(void);
/* Cleanup callback: 0x020e56f4 calls Release before clearing the work address.
 * func_020e5580 registers this callback as its teardown handler. */
void ImageBg_Unk_0e56f4(void)
{
  ImageBg_Release();
  *data_02176ca4 = 0;
}

void func_02061424(ImageBgWork *work);
/* At 0x020e5530, absent work selects Release; present work selects
 * func_02061424. Its wider lifecycle purpose is not established. */
void ImageBg_Unk_0e5530(void)
{
  int value;
  value = ImageBg_Get_data_02176ca4();
  if (value == 0) {
    ImageBg_Release();
    return;
  }
  func_02061424((ImageBgWork *)value);
}


/* Store the pair consumed by callback mode 3 (0x020e56e4, offsets +12/+16).
 * Values are opaque words; absent work makes this a no-op. */
void ImageBg_Unk_0e5550(u32 arg0,u32 arg1)
{
  int value;
  value = ImageBg_Get_data_02176ca4();
  if (value != 0) {
    ((ImageBgWork *)value)->field0c = arg0;
    ((ImageBgWork *)value)->field10 = arg1;
  }
}

void Unk0e7290_Unk_0e7790(u32 value);
/* Clear the work mode and forward zero to 0x020e7790, as at 0x020e550c.
 * No work means no state change and no forwarding call. */
void ImageBg_Unk_0e550c(void)
{
  int value;
  value = ImageBg_Get_data_02176ca4();
  if (value == 0) {
    return;
  }
  ((ImageBgWork *)value)->mode = 0;
  Unk0e7290_Unk_0e7790(0);
}


int ImageBg_IsMode1or2(void);
void func_020e5580(void);
void ImageBg_AllocBuf(void);
/* Start mode 1 with an opaque first word, unless mode 1 or 2 is active. */
void ImageBg_Unk_0e54d4(u32 arg0)
{
  int value;
  u32 *v2;
  Unk0e7290_Unk_0e7790(0xffffffff);
  value = ImageBg_IsMode1or2();
  if (value != 0) {
    return;
  }
  ImageBg_AllocBuf();
  func_020e5580();
  v2 = (u32 *)ImageBg_Get_data_02176ca4();
  *v2 = arg0;
  v2[1] = 1;
}

extern u8 data_02150bd4[];
u32 func_0205ba98(u32 size, u32 alignment, const void *source, u32 line);
void func_0205bb68(void);
void Unk0e7290_Unk_0e7734(void);
/* Release only when the second global word is set. At 0x020e5638 it is
 * cleared before calls to 0x0205bb68 and 0x020e7734; repeated calls are inert. */
void ImageBg_Release(void)
{
    if (data_02176ca4[1] == 0) {
        return;
    }
    data_02176ca4[1] = 0;
    func_0205bb68();
    Unk0e7290_Unk_0e7734();
}

/* Test the +4 mode word for 1 or 2 (comparisons at 0x020e549c/54a0).
 * Absent work returns false without dereferencing its address. */
int ImageBg_IsMode1or2(void)
{
    u32 p = ImageBg_Get_data_02176ca4();
    if (p == 0) {
        return 0;
    }
    switch (((ImageBgWork *)p)->mode) {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}

/* Populate the second global word once, using the original allocation tuple. */
void ImageBg_AllocBuf(void)
{
    if (data_02176ca4[1] != 0) {
        return;
    }
    data_02176ca4[1] = func_0205ba98(0x1e000, 0x800, data_02150bd4, 216);
}
