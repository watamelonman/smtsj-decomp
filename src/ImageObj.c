/*
 * src/ImageObj.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct ImageObjWork {
    u8 unk_0000[0x4];
    s32 UnkField0004;
    u8 unk_0008[0x14];
    s32 UnkField001c;
    u8 unk_0020[0xc];
    s32 UnkField002c;
} ImageObjWork;


extern u32 data_0217231c[];
int func_020775a0();
int func_02077620();
int func_02077640();
int func_02077ddc();
int func_02079238();

u32 ImageObj_Get_data_0217231c(void);
void ImageObj_Unk_0775d8(void);
void ImageObj_Unk_07784c(u32 arg0);
void ImageObj_Unk_077880(int arg0);
void ImageObj_Unk_0778d4(int arg0);
u32 ImageObj_Unk_0778e8(int arg0);
void ImageObj_Unk_07916c(ImageObjWork *work);
void ImageObj_Unk_0772f8(void);

/* decompiler-derived */
u32 ImageObj_Get_data_0217231c(void)
{
  return *data_0217231c;
}

/* decompiler-derived */
void ImageObj_Unk_0775d8(void)
{
  func_02077620();
  func_020775a0();
  func_02077640();
}

/* decompiler-derived */
void ImageObj_Unk_07784c(u32 arg0)
{
  func_02079238(0,arg0);
}

/* decompiler-derived */
void ImageObj_Unk_077880(int arg0)
{
  func_02079238(1,arg0 + 1);
}

/* decompiler-derived */
void ImageObj_Unk_0778d4(int arg0)
{
  func_02079238(2,arg0 + 3);
}

/* decompiler-derived */
u32 ImageObj_Unk_0778e8(int arg0)
{
  int value;
  value = ImageObj_Get_data_0217231c();
  return *(u32 *)(value + arg0 * 4 + 4);
}

/* decompiler-derived */
void ImageObj_Unk_07916c(ImageObjWork *work)
{
  if (work->UnkField0004 == 1) {
    work->UnkField001c = 0x100 - work->UnkField002c;
  }
}

/* decompiler-derived */
void ImageObj_Unk_0772f8(void)
{
  func_02077ddc();
  *data_0217231c = 0;
}
