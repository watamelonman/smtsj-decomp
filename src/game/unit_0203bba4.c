/* Command callbacks; neutral names retain the original address identities. */
#include "types.h"
#include "game/unit_0203bba4.h"

Unk02e000WorkArea *Unk02e000_GetWorkArea(void);
int Unk03aae8_Unk_03acf4(u32 value);
Unk03aae8Ctx *Unk03aae8_Unk_03ad14(void);
int func_0203ac00(int index);
int func_02095818(void);
void Unk116598_Unk_116810(void);
int func_02065544(void);
void func_02065c10(void);
void func_02065b10(u32 value, u16 id);
int func_020b8660(u32 value);
void Unk02dcfc_SetCode8(void);
void ImageObj_Unk_07784c(int value);
void ImageObj_Unk_077880(int value);
void ImageObj_Unk_07782c(int first, int second);
void ImageObj_Unk_077860(u32 first, int second);
void ScanVisor_Unk_0a2920(int on);
/* Preserve the context argument carried by this original call site. */
void Unk02dcfc_Unk_02deb0(Unk03bba4Sub *sub);
void Unk09e418_Unk_09e418(u16 first, u16 second, u16 third);

/* Writes a substate code into the context subobject. Taking the value first
 * keeps the original register order (constant loaded before the call). */
static inline void Unk03bba4_SetSubState(u32 v, Unk03bba4Sub *sub)
{
    sub->unk_0018 = v;
}

/* Stores substate 19 at context->unk_00e8->unk_0018, calls the mode-3 helper
 * only in mode 3, and returns command status 3. Evidence: original stores/calls. */
int Unk03bba4_Unk_03bba4(void)
{
    Unk03bba4_SetSubState(19, Unk03aae8_Unk_03ad14()->unk_00e8);
    if (func_02095818() == 3) {
        Unk116598_Unk_116810();
    }
    return 3;
}

/* Forwards the unsigned low halfword of argument 0 to 065b10(0, id),
 * calling 065c10 first when 065544 is zero; sets substate 6 and returns 3.
 * Evidence: original halfword shifts, conditional call and +0x18 store. */
int Unk03bba4_Unk_03bc40(void)
{
    u16 id = func_0203ac00(0);
    if (func_02065544() == 0) {
        func_02065c10();
    }
    func_02065b10(0, id);
    Unk03bba4_SetSubState(6, Unk03aae8_Unk_03ad14()->unk_00e8);
    return 3;
}

/* Publishes the signed byte work-area unk_0364; returns status 1.
 * Evidence: original ldrsb before the 03acf4 call; preserve sign extension. */
int Unk03bba4_Unk_03bc88(void)
{
    Unk03aae8_Unk_03acf4(Unk02e000_GetWorkArea()->unk_0364);
    return 1;
}

/* Publishes the signed byte work-area unk_0365; returns status 1.
 * Evidence: original ldrsb before the 03acf4 call; preserve sign extension. */
int Unk03bba4_Unk_03bca4(void)
{
    Unk03aae8_Unk_03acf4(Unk02e000_GetWorkArea()->unk_0365);
    return 1;
}

/* Publishes the work-area word unk_0358; returns status 1.
 * Evidence: original ldr at +0x358 before the 03acf4 call. */
u32 Unk03bba4_Unk_03bcc0(void)
{
  Unk02e000WorkArea *w;
  w = Unk02e000_GetWorkArea();
  Unk03aae8_Unk_03acf4(w->unk_0358);
  return 1;
}

/* Forwards only the low byte of command argument 0 to 020b8660; returns 1.
 * Evidence: original AND #255 before the call. */
u32 Unk03bba4_Unk_03bbd0(void)
{
  u8 value;
  value = func_0203ac00(0);
  func_020b8660(value);
  return 1;
}

/* Forwards signed argument 0 to ImageObj 07784c, sets code 8, and returns 3.
 * Evidence: original signed-halfword extension and ordered calls. */
u32 Unk03bba4_Unk_03bd18(void)
{
  s16 v1;
  v1 = func_0203ac00(0);
  ImageObj_Unk_07784c(v1);
  Unk02dcfc_SetCode8();
  return 3;
}

/* Forwards signed argument 0 to ImageObj 077880, sets code 8, and returns 3.
 * Evidence: original signed-halfword extension and ordered calls. */
u32 Unk03bba4_Unk_03bd7c(void)
{
  s16 v1;
  v1 = func_0203ac00(0);
  ImageObj_Unk_077880(v1);
  Unk02dcfc_SetCode8();
  return 3;
}

/* Forwards two signed command arguments to ImageObj 07782c, sets code 8,
 * clears the ScanVisor switch, and returns 3. Evidence: original ordered calls. */
u32 Unk03bba4_Unk_03bcd8(void)
{
  s16 v1;
  s16 v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  ImageObj_Unk_07782c(v1, v2);
  Unk02dcfc_SetCode8();
  ScanVisor_Unk_0a2920(0);
  return 3;
}

/* Forwards two signed low-halfword arguments to ImageObj 077860, sets
 * code 8 and clears the ScanVisor switch; returns 3. Evidence: original
 * arithmetic shifts and ordered call relocations at 0203bd3c. */
u32 Unk03bba4_Unk_03bd3c(void)
{
  s16 v1;
  s16 v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  ImageObj_Unk_077860((int)v1,(int)v2);
  Unk02dcfc_SetCode8();
  ScanVisor_Unk_0a2920(0);
  return 3;
}

/* Forwards three unsigned low-halfword arguments to 09e418, then carries
 * the borrowed context subobject into 02deb0; returns 3. Evidence: original
 * logical shifts, +0xe8 load and ordered call relocations at 0203bbec. */
u32 Unk03bba4_Unk_03bbec(void)
{
  u16 value1;
  u16 value2;
  u16 value3;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  value3 = func_0203ac00(2);
  Unk09e418_Unk_09e418(value1,value2,value3);
  Unk02dcfc_Unk_02deb0(Unk03aae8_Unk_03ad14()->unk_00e8);
  return 3;
}

int func_0206552c(void);
int ImageObj_Unk_077688(void);
int Unk09d42c_Unk_09e274(void);
u32 Unk02e000_GetSlot(int slot);
void ImageBg_Unk_0e54d4(int value);
void Unk02e000_SetSlot(int slot, u32 value);
int ImageBg_IsMode1or2(void);

/* Returns zero while any readiness check blocks progress. Once ready,
 * applies slot 0 and clears slot 1 only when slot 1 equals 1; returns whether
 * the background mode predicate differs from 1. Evidence: original branches
 * and GetSlot/SetSlot call arguments at 0203bda0. */
int Unk03bba4_Unk_03bda0(void)
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
