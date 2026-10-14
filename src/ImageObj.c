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



/* decompiler-derived */
int ImageObj_Unk_079028(void)
{
  int value;
  value = ImageObj_Get_data_0217231c();
  return *(int *)(value + 0x14) == 4;
}


/* decompiler-derived */
void ImageObj_Unk_0773bc(void)
{
  int value;
  value = *data_0217231c;
  if (value != 0) {
    *(u32 *)(value + 0xc0) = 1;
    *(u32 *)(value + 0xc4) = 1;
  }
}

int func_020791a8();
/* decompiler-derived */
void ImageObj_Unk_07782c(u32 arg0,u32 arg1)
{
  func_020791a8(0,arg0,arg1,0);
}


/* decompiler-derived */
void ImageObj_Unk_077860(u32 arg0,int arg1)
{
  func_020791a8(1,arg0,arg1 + 1,0);
}


/* decompiler-derived */
void ImageObj_Unk_077894(u32 arg0,int arg1)
{
  func_020791a8(2,arg0,arg1 + 3,0);
}


/* decompiler-derived */
void ImageObj_Unk_0778b4(u32 arg0,int arg1)
{
  func_020791a8(2,arg0,arg1 + 3,1);
}

int func_02061424();
/* decompiler-derived */
void ImageObj_Unk_079184(int arg0)
{
  int value;
  value = ImageObj_Get_data_0217231c();
  if (*(int *)(value + arg0 * 4 + 4) == 0) {
    return;
  }
  func_02061424();
}


int func_02077554();
/* decompiler-derived */
void func_020775ec(void)
{
  int tmp1;
  int tmp2;
  tmp1 = ImageObj_Get_data_0217231c();
  if (tmp1 == 0) {
    return;
  }
  tmp2 = 0;
  do {
    if (tmp1 != 0) {
      func_02077554(tmp2);
    }
    tmp2 = tmp2 + 1;
  } while (tmp2 < 3);
  return;
}

int func_02077a9c();
/* decompiler-derived */
u32 func_020776d4(void)
{
  int tmp1;
  int tmp2;
  tmp2 = 0;
  do {
    ImageObj_Unk_0778e8(tmp2);
    tmp1 = func_02077a9c();
    if (tmp1 != 0) {
      return 1;
    }
    tmp2 = tmp2 + 1;
  } while (tmp2 < 3);
  return 0;
}



/* decompiler-derived */
u32 func_02077228(void)
{
  int tmp1;
  int tmp2;
  tmp2 = 0;
  do {
    tmp1 = ImageObj_Unk_0778e8(tmp2);
    if (tmp1 != 0) {
      tmp1 = func_02077a9c();
      if (tmp1 != 0) {
        return 0;
      }
      func_02077554(tmp2);
    }
    tmp2 = tmp2 + 1;
  } while (tmp2 < 3);
  return 1;
}


/* decompiler-derived */
int func_02077688(void)
{
  int tmp1;
  int tmp2;
  int tmp3;
  tmp1 = ImageObj_Get_data_0217231c();
  if (tmp1 == 0) {
    return 1;
  }
  tmp3 = 0;
  do {
    tmp2 = ImageObj_Unk_0778e8(tmp3);
    if (tmp2 != 0) {
      return 0;
    }
    tmp3 = tmp3 + 1;
  } while (tmp3 < 3);
  return *(int *)(tmp1 + 0x10) == 0;
}
