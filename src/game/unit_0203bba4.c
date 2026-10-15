/* src/game/unit_0203bba4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02e000_GetWorkArea();
int Unk03aae8_Unk_03acf4();
int Unk03aae8_Unk_03ad14();
int func_02095818();
void Unk116598_Unk_116810();
int func_02065544();
void func_02065c10();
void func_02065b10();
static inline void Unk03bba4_SetSubState(u32 v, u8 *sub)
{
    FIELD(u32, sub, 0x18) = v;
}
int Unk03bba4_Unk_03bba4(void)
{
    Unk03bba4_SetSubState(19, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    if (func_02095818() == 3) {
        Unk116598_Unk_116810();
    }
    return 3;
}

int Unk03bba4_Unk_03bc40(void)
{
    u16 id = func_0203ac00(0);
    if (func_02065544() == 0) {
        func_02065c10();
    }
    func_02065b10(0, id);
    Unk03bba4_SetSubState(6, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

int Unk03bba4_Unk_03bc88(void)
{
    Unk03aae8_Unk_03acf4(((s8 *)(u8 *)Unk02e000_GetWorkArea())[0x364]);
    return 1;
}

int Unk03bba4_Unk_03bca4(void)
{
    Unk03aae8_Unk_03acf4(((s8 *)(u8 *)Unk02e000_GetWorkArea())[0x365]);
    return 1;
}

/* decompiler-derived */
u32 Unk03bba4_Unk_03bcc0(void)
{
  int value;
  value = Unk02e000_GetWorkArea();
  Unk03aae8_Unk_03acf4(*(u32 *)(value + 0x358));
  return 1;
}

int func_0203ac00();
int func_020b8660();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bbd0(void)
{
  u8 value;
  value = func_0203ac00(0);
  func_020b8660(value);
  return 1;
}

int Unk02dcfc_SetCode8();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bd18(void)
{
  short v1;
  v1 = func_0203ac00(0);
  ImageObj_Unk_07784c((int)v1);
  Unk02dcfc_SetCode8();
  return 3;
}


/* decompiler-derived */
u32 Unk03bba4_Unk_03bd7c(void)
{
  short v1;
  v1 = func_0203ac00(0);
  ImageObj_Unk_077880((int)v1);
  Unk02dcfc_SetCode8();
  return 3;
}

int ImageObj_Unk_07782c();
int ScanVisor_Unk_0a2920();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bcd8(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  ImageObj_Unk_07782c((int)v1,(int)v2);
  Unk02dcfc_SetCode8();
  ScanVisor_Unk_0a2920(0);
  return 3;
}


int ImageObj_Unk_077860();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bd3c(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  ImageObj_Unk_077860((int)v1,(int)v2);
  Unk02dcfc_SetCode8();
  ScanVisor_Unk_0a2920(0);
  return 3;
}

int Unk02dcfc_Unk_02deb0();
int Unk03aae8_Unk_03ad14();
int Unk09e418_Unk_09e418();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bbec(void)
{
  u16 value1;
  u16 value2;
  u16 value3;
  int value4;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  value3 = func_0203ac00(2);
  Unk09e418_Unk_09e418(value1,value2,value3);
  value4 = Unk03aae8_Unk_03ad14();
  Unk02dcfc_Unk_02deb0(*(u32 *)(value4 + 0xe8));
  return 3;
}

int func_0206552c();
int ImageObj_Unk_077688();
int Unk09d42c_Unk_09e274();
int Unk02e000_GetSlot();
void ImageBg_Unk_0e54d4();
void Unk02e000_SetSlot();
int ImageBg_IsMode1or2();

int func_0203bda0(void)
{
    if (func_0206552c() != 0) {
        return 0;
    }
    if (ImageObj_Unk_077688() == 0) {
        return 0;
    }
    if (Unk09d42c_Unk_09e274() == 0) {
        return 0;
    }
    if (Unk02e000_GetSlot(1) == 1) {
        ImageBg_Unk_0e54d4(Unk02e000_GetSlot(0));
        Unk02e000_SetSlot(1, 0);
    }
    if (ImageBg_IsMode1or2() == 1) {
        return 0;
    }
    return 1;
}
