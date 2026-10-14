/*
 * ImageBgDual3D.c (name from the assert string at 0x02125c68):
 * a dual-screen 3D image background used by the ending/event scenes
 * (neighbouring code loads "Data/Tex/Event/ED/").
 * These are its empty callbacks and two thin forwarders.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_021255b4(void);
void func_021177e0(void);

/* Empty per-frame / lifecycle callbacks (no direct callers; table entries). */
void ImageBgDual3D_Nop_1252f4(void) { }
void ImageBgDual3D_Nop_1252f8(void) { }
void ImageBgDual3D_Nop_1252fc(void) { }
void ImageBgDual3D_Nop_125c3c(void) { }
void ImageBgDual3D_Nop_125c60(void) { }
void ImageBgDual3D_Nop_125c64(void) { }

/* Forwards to func_021255b4 with the caller's arguments. */
void ImageBgDual3D_Thunk_021255b4(void) { func_021255b4(); }

/* Forwards to func_021177e0 (shared helper also used by unit_02116598). */
void ImageBgDual3D_Thunk_021177e0(void) { func_021177e0(); }


void func_02117808(void);
/* forwards to `func_02117808` */
void ImageBgDual3D_Thunk_02117808(void) { func_02117808(); }

extern u32 data_02176e94[];
/* decompiler-derived */
u32 ImageBgDual3D_Get_data_02176e94(void)
{
  return *data_02176e94;
}

int Unk065e88_Unk_065eac();
int Unk095560_Unk_096130();
/* decompiler-derived */
void ImageBgDual3D_Unk_125a80(void)
{
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
}

extern u32 data_02176e8c[];
/* decompiler-derived */
void ImageBgDual3D_Clear_data_02176e8c(void)
{
  *data_02176e8c = 0;
}

int func_021172dc();
int func_021177cc();
/* decompiler-derived */
void ImageBgDual3D_Unk_125afc(void)
{
  func_021177cc(0);
  func_021172dc();
}


/* decompiler-derived */
void ImageBgDual3D_Unk_1259e0(void)
{
  u32 *v1;
  v1 = (u32 *)ImageBgDual3D_Get_data_02176e94();
  *v1 = 1;
  ImageBgDual3D_Unk_125a80();
}


int func_02065e88();
int func_020773dc();
int func_02125c68();
/* decompiler-derived */
void func_02125a68(void)
{
  func_02125c68();
  func_02065e88();
  func_020773dc(1);
  return;
}

int func_0212594c();
/* decompiler-derived */
int func_02125ca4(void)
{
  int tmp1;
  tmp1 = func_0212594c();
  return tmp1 == 0;
}


/* decompiler-derived */
int func_02125cbc(void)
{
  int tmp1;
  tmp1 = func_0212594c();
  return tmp1 == 1;
}

int func_021258e8();
/* decompiler-derived */
void func_02125d30(void)
{
  int tmp1;
  tmp1 = func_02125cbc();
  if (tmp1 == 0) {
    return;
  }
  func_021258e8();
  return;
}


/* decompiler-derived */
void func_021259c4(u32 arg0)
{
  int tmp1;
  tmp1 = ImageBgDual3D_Get_data_02176e94();
  *(u32 *)(tmp1 + 4) = arg0;
  *(u32 *)(tmp1 + 0xc) = 1;
  return;
}

int func_02117294();
int func_02117790();
int func_02125a08();
/* decompiler-derived */
void func_02125c40(void)
{
  u32 tmp1;
  func_02117790();
  func_02117294();
  tmp1 = func_02125a08();
  *data_02176e94 = tmp1;
  return;
}

int func_021258a0();
/* decompiler-derived */
void func_02125d10(u32 arg0)
{
  int tmp1;
  tmp1 = func_02125cbc();
  if (tmp1 == 0) {
    return;
  }
  func_021258a0(arg0);
  return;
}

int func_0205c408();
int func_0205c6e0();
/* decompiler-derived */
void func_02125650(int arg0)
{
  func_0205c408(*(u32 *)(arg0 + 0x8c),0);
  func_0205c6e0(*(u32 *)(arg0 + 0x8c));
  *(u32 *)(arg0 + 0x208) = 0;
  return;
}
