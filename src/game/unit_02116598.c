/*
 * unit_02116598: empty callbacks and thin forwarders. func_021166e8 and
 * func_021166f4 are called back-to-back from func_0203c320.
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

void func_021177e0(void);
void func_02117808(void);
void func_021172fc(void);

/* Empty callbacks (no direct callers; function-table slots). */
void func_02116b44(void) { }
void func_02116b68(void) { }
void func_02116b6c(void) { }
void func_02117cd0(void) { }

/* Forwarders: pass the caller's arguments straight through. */
void func_021166e8(void) { func_021177e0(); }
void func_021166f4(void) { func_02117808(); }
void func_02116804(void) { func_021172fc(); }
void func_02117950(void) { func_021177e0(); }



/* forwards to `func_02117808` */
void func_0211795c(void) { func_02117808(); }


/* forwards to `func_021172fc` */
void func_02117a4c(void) { func_021172fc(); }

extern u32 data_02176e5c[];
/* decompiler-derived */
u32 func_0211682c(void)
{
  return *data_02176e5c;
}

extern u32 data_02176e68[];
/* decompiler-derived */
u32 func_02117a58(void)
{
  return *data_02176e68;
}

int func_02065eac();
int func_02096130();
int func_020a2414();
/* decompiler-derived */
void func_021168b8(void)
{
  func_02096130();
  func_02065eac();
  func_020a2414();
  return;
}

int func_021172dc();
int func_021177cc();
/* decompiler-derived */
void func_02116954(void)
{
  func_021177cc(0);
  func_021172dc();
  return;
}


extern u32 data_02176e60[];
/* decompiler-derived */
void func_0211753c(void)
{
  *data_02176e60 = 0;
  return;
}

extern u32 data_02176e64[];
/* decompiler-derived */
void func_02117914(void)
{
  *data_02176e64 = 0;
  return;
}


/* decompiler-derived */
void func_02117ae4(void)
{
  func_02096130();
  func_02065eac();
  func_020a2414();
  return;
}


/* decompiler-derived */
void func_02117b80(void)
{
  func_021177cc(0);
  func_021172dc();
  return;
}
