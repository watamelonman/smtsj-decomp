/*
 * unit_02116598: empty callbacks and thin forwarders. Unk116598_Thunk_021177e0 and
 * Unk116598_Unk_1166f4 are called back-to-back from func_0203c320.
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
void Unk116598_Nop_116b44(void) { }
void Unk116598_Nop_116b68(void) { }
void Unk116598_Nop_116b6c(void) { }
void Unk116598_Nop_117cd0(void) { }

/* Forwarders: pass the caller's arguments straight through. */
void Unk116598_Thunk_021177e0(void) { func_021177e0(); }
void Unk116598_Unk_1166f4(void) { func_02117808(); }
void Unk116598_Unk_116804(void) { func_021172fc(); }
void Unk116598_Unk_117950(void) { func_021177e0(); }



/* forwards to `func_02117808` */
void Unk116598_Thunk_02117808(void) { func_02117808(); }


/* forwards to `func_021172fc` */
void Unk116598_Thunk_021172fc(void) { func_021172fc(); }

extern u32 data_02176e5c[];
/* decompiler-derived */
u32 Unk116598_Get_data_02176e5c(void)
{
  return *data_02176e5c;
}

extern u32 data_02176e68[];
/* decompiler-derived */
u32 Unk116598_Get_data_02176e68(void)
{
  return *data_02176e68;
}

int Unk065e88_Unk_065eac();
int Unk095560_Unk_096130();
int func_020a2414();
/* decompiler-derived */
void Unk116598_Unk_1168b8(void)
{
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
  func_020a2414();
  return;
}

int func_021172dc();
int func_021177cc();
/* decompiler-derived */
void Unk116598_Unk_116954(void)
{
  func_021177cc(0);
  func_021172dc();
  return;
}


extern u32 data_02176e60[];
/* decompiler-derived */
void Unk116598_Clear_data_02176e60(void)
{
  *data_02176e60 = 0;
  return;
}

extern u32 data_02176e64[];
/* decompiler-derived */
void Unk116598_Clear_data_02176e64(void)
{
  *data_02176e64 = 0;
  return;
}


/* decompiler-derived */
void Unk116598_Unk_117ae4(void)
{
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
  func_020a2414();
  return;
}


/* decompiler-derived */
void Unk116598_Unk_117b80(void)
{
  func_021177cc(0);
  func_021172dc();
  return;
}
