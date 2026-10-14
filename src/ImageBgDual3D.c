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
void func_021252f4(void) { }
void func_021252f8(void) { }
void func_021252fc(void) { }
void func_02125c3c(void) { }
void func_02125c60(void) { }
void func_02125c64(void) { }

/* Forwards to func_021255b4 with the caller's arguments. */
void func_021257e8(void) { func_021255b4(); }

/* Forwards to func_021177e0 (shared helper also used by unit_02116598). */
void func_021259ac(void) { func_021177e0(); }


void func_02117808(void);
/* forwards to `func_02117808` */
void func_021259b8(void) { func_02117808(); }

extern u32 data_02176e94[];
/* decompiler-derived */
u32 func_021259f8(void)
{
  return *data_02176e94;
}

int func_02065eac();
int func_02096130();
/* decompiler-derived */
void func_02125a80(void)
{
  func_02096130();
  func_02065eac();
  return;
}

extern u32 data_02176e8c[];
/* decompiler-derived */
void func_02125300(void)
{
  *data_02176e8c = 0;
  return;
}

int func_021172dc();
int func_021177cc();
/* decompiler-derived */
void func_02125afc(void)
{
  func_021177cc(0);
  func_021172dc();
  return;
}


/* decompiler-derived */
void func_021259e0(void)
{
  u32 *v1;
  v1 = (u32 *)func_021259f8();
  *v1 = 1;
  func_02125a80();
  return;
}
