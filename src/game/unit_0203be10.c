/* src/game/unit_0203be10.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020773dc();
/* decompiler-derived */
u32 Unk03be10_Unk_03be40(void)
{
  func_020773dc(2);
  return 1;
}


/* decompiler-derived */
u32 Unk03be10_Unk_03bfa8(void)
{
  func_020773dc(1);
  return 1;
}

int ImageBg_IsMode1or2();
/* decompiler-derived */
int Unk03be10_Unk_03be10(void)
{
  int value;
  value = ImageBg_IsMode1or2();
  return value != 1;
}


/* decompiler-derived */
int Unk03be10_Unk_03be28(void)
{
  int value;
  value = ImageBgDual3D_Unk_125ca4();
  return value != 1;
}

int func_0206552c();
int ImageObj_Unk_077688();
int Unk02e000_GetSlot();
void Unk09e72c_Unk_09e8f0();
void Unk02e000_SetSlot();
int Unk09d42c_Unk_09e274();

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
        case 1:
            if (Unk09d42c_Unk_09e274() == 0) {
                return 0;
            }
            break;
        }
    }
    return 1;
}
