/* src/ImageBg.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176ca4[];
/* decompiler-derived */
u32 ImageBg_Get_data_02176ca4(void)
{
  return *data_02176ca4;
}


/* decompiler-derived */
int ImageBg_IsSet_data_02176ca4(void)
{
  return *data_02176ca4 != 0;
}

int func_020e5638();
/* decompiler-derived */
void ImageBg_Unk_0e56f4(void)
{
  func_020e5638();
  *data_02176ca4 = 0;
}

int func_02061424();
/* decompiler-derived */
void ImageBg_Unk_0e5530(void)
{
  int value;
  value = ImageBg_Get_data_02176ca4();
  if (value == 0) {
    func_020e5638();
    return;
  }
  func_02061424();
}


/* decompiler-derived */
void ImageBg_Unk_0e5550(u32 arg0,u32 arg1)
{
  int value;
  value = ImageBg_Get_data_02176ca4();
  if (value != 0) {
    *(u32 *)(value + 0xc) = arg0;
    *(u32 *)(value + 0x10) = arg1;
  }
}

int func_020e7790();
/* decompiler-derived */
void ImageBg_Unk_0e550c(void)
{
  int value;
  value = ImageBg_Get_data_02176ca4();
  if (value == 0) {
    return;
  }
  *(u32 *)(value + 4) = 0;
  func_020e7790(0);
}


int func_020e5484();
int func_020e5580();
int func_020e55fc();
/* decompiler-derived */
void ImageBg_Unk_0e54d4(u32 arg0)
{
  int value;
  u32 *v2;
  func_020e7790(0xffffffff);
  value = func_020e5484();
  if (value != 0) {
    return;
  }
  func_020e55fc();
  func_020e5580();
  v2 = (u32 *)ImageBg_Get_data_02176ca4();
  *v2 = arg0;
  v2[1] = 1;
}
