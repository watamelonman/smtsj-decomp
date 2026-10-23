#include "types.h"

typedef int (*TransitionCallback)(void);

void func_020773dc(int mode);
int ImageBg_IsMode1or2(void);
int ImageBgDual3D_Unk_125ca4(void);
int func_0206552c(void);
int ImageObj_Unk_077688(void);
int Unk02e000_GetSlot(int slot);
void Unk09e72c_Unk_09e8f0(void);
void Unk02e000_SetSlot(int slot, int value);
int Unk09d42c_Unk_09e274(void);
int func_0203ac00(int index);
void Unk02e000_ClearMgrUnk38(void);
int func_02095818(void);
void func_02065ca8(void);
void Unk09e72c_Unk_09e89c(void);
void Unk095560_Unk_095728(void);
void Unk02e000_SetMgrUnk38(TransitionCallback first, TransitionCallback second);
int Unk03bba4_Unk_03bda0(void);
void ImageBg_Unk_0e54d4(int value);
void ImageBgDual3D_Unk_125cd4(int value);
void Unk02dcfc_SetCode7(void);
int ImageBg_IsSet_data_02176ca4(void);
void ImageBg_Unk_0e5530(void);
void ImageBg_Unk_0e550c(void);
void ImageBgDual3D_Unk_125d30(void);

/* Poll the background mode; the transition is ready when its result differs from 1. */
int Unk03be10_Unk_03be10(void)
{
    return ImageBg_IsMode1or2() != 1;
}

/* Poll the dual-3D background counterpart using the same readiness contract. */
int Unk03be10_Unk_03be28(void)
{
    return ImageBgDual3D_Unk_125ca4() != 1;
}

/* Finish the callback by passing mode 2 to the shared helper and reporting success. */
int Unk03be10_Unk_03be40(void)
{
    func_020773dc(2);
    return 1;
}

/* Start a mode-dependent transition, preserving the signed 16-bit script value in slot 0. */
int func_0203be54(void)
{
    s16 value = func_0203ac00(0);
    Unk02e000_ClearMgrUnk38();
    switch (func_02095818()) {
    case 0:
        func_02065ca8();
        Unk09e72c_Unk_09e89c();
        Unk095560_Unk_095728();
        Unk02e000_SetMgrUnk38(Unk03bba4_Unk_03bda0, Unk03be10_Unk_03be40);
        Unk02e000_SetSlot(0, value);
        Unk02e000_SetSlot(1, 1);
        break;
    case 2:
    case 3:
    case 4:
        ImageBg_Unk_0e54d4(value);
        Unk02e000_SetSlot(1, 0);
        Unk02e000_SetMgrUnk38(Unk03be10_Unk_03be10, 0);
        break;
    case 5:
        ImageBgDual3D_Unk_125cd4(value);
        Unk02e000_SetSlot(1, 0);
        Unk02e000_SetMgrUnk38(Unk03be10_Unk_03be28, 0);
        break;
    default:
        return 3;
    }
    Unk02dcfc_SetCode7();
    return 3;
}

/* Wait for both readiness checks, then advance slot 1 once and poll completion. */
int Unk03be10_Unk_03bf34(void)
{
    if (func_0206552c() != 0) {
        return 0;
    }
    if (ImageObj_Unk_077688() == 0) {
        return 0;
    }
    if (Unk02e000_GetSlot(0) == 1) {
        switch (Unk02e000_GetSlot(1)) {
        case 0:
            Unk09e72c_Unk_09e8f0();
            Unk02e000_SetSlot(1, 1);
            /* Continue polling immediately after the one-time setup. */
        case 1:
            if (Unk09d42c_Unk_09e274() == 0) {
                return 0;
            }
            break;
        }
    }
    return 1;
}

/* Finish the paired transition with helper mode 1 and report success. */
int Unk03be10_Unk_03bfa8(void)
{
    func_020773dc(1);
    return 1;
}

/* Start the reverse mode-dependent transition; mode 0 can complete immediately. */
int func_0203bfbc(void)
{
    Unk02e000_ClearMgrUnk38();
    switch (func_02095818()) {
    case 0:
        if (ImageBg_IsSet_data_02176ca4() == 0) {
            return 1;
        }
        func_02065ca8();
        Unk095560_Unk_095728();
        Unk02e000_SetMgrUnk38(Unk03be10_Unk_03bf34, Unk03be10_Unk_03bfa8);
        ImageBg_Unk_0e5530();
        Unk02e000_SetSlot(0, 1);
        Unk02e000_SetSlot(1, 0);
        break;
    case 2:
    case 3:
    case 4:
        ImageBg_Unk_0e550c();
        break;
    case 5:
        ImageBgDual3D_Unk_125d30();
        break;
    default:
        return 3;
    }
    Unk02dcfc_SetCode7();
    return 3;
}
