#include "types.h"

/* Partial layouts: only fields accessed by this unit are established. */
typedef struct Unk03c05cWork {
    u8 pad_0000[0x18];
    u32 code;
    u32 unk_001c;
} Unk03c05cWork;

/* The context owns the work pointer at +0xe8; no lifetime is transferred. */
typedef struct Unk03c05cContext {
    u8 pad_0000[0xe8];
    Unk03c05cWork *work;
} Unk03c05cContext;

s32 func_0203ac00(u32 index);
u32 func_02095818(void);
Unk03c05cContext *Unk03aae8_Unk_03ad14(void);
void Unk09ee4c_Unk_09ee4c(void);
void ImageObj_Unk_0778d4(s32 a);
void ImageObj_Unk_077894(s32 a, s32 b);
void ImageBgDual3D_Unk_125d10(u32 a);
void Unk02dcfc_SetCode8(void);
void ScanVisor_Unk_0a2920(u32 a);
void func_0209ed78(s32 a, s32 b, s32 c);
void func_0209e49c(s32 a, s32 b, s32 c);
void Unk111400_Unk_111474(s32 a, u32 flags, u32 c);
void Unk09e418_Unk_09e468(void);
void Unk02dcfc_Unk_02de58(Unk03c05cWork *work);
void Unk0de678_Unk_0df584(void);
void Unk116598_Unk_11671c(void);
void Unk116598_Unk_117984(void);
void ImageBgDual3D_Unk_1259e0(void);

/* Call 0209ee4c and return handler result 3. */
u32 Unk03c05c_Unk_03c134(void)
{
  Unk09ee4c_Unk_09ee4c();
  return 3;
}

/* Forward argument 0 as signed 16 bits to 020778d4, then set code 8. */
u32 Unk03c05c_Unk_03c0c8(void)
{
  short v1;
  v1 = func_0203ac00(0);
  ImageObj_Unk_0778d4((int)v1);
  Unk02dcfc_SetCode8();
  return 3;
}

/* Forward the full argument 0 to 02125d10 only when mode 02095818 is 5. */
u32 Unk03c05c_Unk_03c05c(void)
{
  u32 value1;
  int value2;
  value1 = func_0203ac00(0);
  value2 = func_02095818();
  if (value2 == 5) {
    ImageBgDual3D_Unk_125d10(value1);
  }
  return 1;
}

/* Forward two signed 16-bit arguments to 02077894, set code 8, and call 020a2920 with zero. */
u32 Unk03c05c_Unk_03c088(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  ImageObj_Unk_077894((int)v1,(int)v2);
  Unk02dcfc_SetCode8();
  ScanVisor_Unk_0a2920(0);
  return 3;
}

/* Forward three signed 16-bit arguments to 0209ed78 and return handler result 3. */
u32 Unk03c05c_Unk_03c0ec(void)
{
  short v1;
  short v2;
  short v3;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  v3 = func_0203ac00(2);
  func_0209ed78((int)v1,(int)v2,(int)v3);
  return 3;
}

/* Read three signed 16-bit arguments, set work code 15, and forward in 1,2,0 order. */
u32 Unk03c05c_Unk_03c144(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    s16 c = func_0203ac00(2);
    Unk03c05cWork *work = Unk03aae8_Unk_03ad14()->work;
    work->code = 15;
    func_0209e49c(b, c, a);
    return 3;
}

/* Dispatch on the mode from 02095818; work codes and callees follow 0203c1e0-0203c268. */
u32 func_0203c1a0(void)
{
    s8 a = func_0203ac00(0);
    s32 b = func_0203ac00(1);
    u32 flags = 0;
    Unk03c05cWork *work;
    if (b != 0) {
        flags = 8;
    }
    work = Unk03aae8_Unk_03ad14()->work;
    Unk111400_Unk_111474(a, flags, 0);
    switch (func_02095818()) {
    case 0:
        Unk09e418_Unk_09e468();
        Unk02dcfc_Unk_02de58(work);
        break;
    case 2:
        Unk0de678_Unk_0df584();
        Unk02dcfc_Unk_02de58(work);
        break;
    case 3:
        Unk116598_Unk_11671c();
        work->code = 19;
        work->unk_001c = 0;
        break;
    case 4:
        Unk116598_Unk_117984();
        work->code = 20;
        work->unk_001c = 0;
        break;
    case 5:
        ImageBgDual3D_Unk_1259e0();
        work->code = 20;
        work->unk_001c = 0;
        break;
    }
    return 3;
}
