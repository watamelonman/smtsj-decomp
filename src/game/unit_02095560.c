/*
 * unit_02095560: owner of a static manager object at 0x02175eb0
 * (Unk095560_GetManager returns it; many functions in this unit use it).
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef signed char s8;

extern unsigned char gUnkManager_02175eb0[];   /* static manager instance */

void func_0202d15c(void);
void Unk0caea8_Unk_0cb044(void);
void func_020773dc(void);
void func_020961a0(void);

/* Reads the signed byte at table[index]. */
int Unk095560_GetSignedByte(const s8 *table, int index) { return table[index]; }

/* Returns the static manager instance. */
unsigned char *Unk095560_GetManager(void) { return gUnkManager_02175eb0; }

/* Same as Unk095560_GetManager, kept as a separate entry point. */
unsigned char *Unk095560_GetManagerAlias(void) { return Unk095560_GetManager(); }

/* Returns the sub-object at offset 0x3A8 of the manager. */
unsigned char *Unk095560_GetManagerSub3a8(void) { return Unk095560_GetManager() + 0x3a8; }

/* Forwarders. */
void Unk095560_Thunk_0202d15c(void) { func_0202d15c(); }
void Unk095560_Thunk_020cb044(void) { Unk0caea8_Unk_0cb044(); }
void Unk095560_Thunk_020773dc(void) { func_020773dc(); }
void Unk095560_Thunk_020961a0(void) { func_020961a0(); }



/* decompiler-derived */
u32 Unk095560_Unk_095d2c(void)
{
  u32 *v1;
  v1 = (u32 *)Unk095560_GetManagerSub3a8();
  return *v1;
}

extern u8 data_02175ea8[];
/* decompiler-derived */
u32 Unk095560_Unk_095d3c(void)
{
  return *(u32 *)(((int)data_02175ea8) + 4);
}

int func_02065ca8();
int func_02095728();
/* decompiler-derived */
void Unk095560_Unk_096130(void)
{
  func_02095728();
  func_02065ca8();
}

int func_020445d0();
/* decompiler-derived */
void Unk095560_Unk_095764(u32 arg0)
{
  func_020445d0(0x1b,arg0);
}


int ImageObj_Unk_0775ec();
int func_02077640();
/* decompiler-derived */
void Unk095560_Unk_09615c(void)
{
  ImageObj_Unk_0775ec();
  func_02077640();
  func_02065ca8();
}

int func_02077750();
int ImageBg_Unk_0e5550();
/* decompiler-derived */
void Unk095560_Unk_0958a8(u32 arg0,u32 arg1)
{
  ImageBg_Unk_0e5550();
  func_02077750(arg0,arg1);
}


int func_0204459c();
int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk095560_Unk_095778(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x19);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk095560_Unk_09579c(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1a);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk095560_Unk_0957c0(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1a);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}

int func_020956e8();
int func_020958c8();
int func_02095950();
/* decompiler-derived */
u32 Unk095560_Unk_095af8(u32 arg0)
{
  int value;
  func_020956e8();
  value = func_02095950(0,arg0);
  if (value != 0) {
    func_020958c8(value);
    return 1;
  }
  return 0;
}

int func_02095818();
int ImageBg_Unk_0e5530();
/* decompiler-derived */
void Unk095560_Unk_096170(void)
{
  int value;
  value = func_02095818();
  if (value == 0) {
    ImageBg_Unk_0e5530();
    func_02077640();
    func_02065ca8();
  }
  else {
    ImageObj_Unk_0775d8();
  }
  Unk02d15c_Unk_02d81c();
  func_02065ca8();
}



/* decompiler-derived */
u32 Unk095560_Unk_095a2c(u32 arg0)
{
  int value;
  func_020956e8();
  value = func_02095950(1,arg0);
  if (value != 0) {
    func_020958c8(value);
    func_0202d15c();
    return 1;
  }
  return 0;
}

int func_0202dc44();
int func_0209560c();
/* decompiler-derived */
u32 Unk095560_Unk_095660(void)
{
  u32 *v1;
  int value1;
  int value2;
  value2 = 2;
  do {
    v1 = (u32 *)Unk094fe0_Unk_094fec(value2);
    value1 = func_0202dc44(value2);
    func_0209560c(value2);
    *v1 = 0xffffffff;
    value2 = value2 + 1;
    *(u32 *)(value1 + 0x50) = 0xffffffff;
  } while (value2 < 8);
  return 1;
}



int func_02052f58();
int func_02052f68();
int func_02052fe0();
int func_02052ff0();
int func_02053000();
int func_0205f508();
int func_0205f534();
int func_0205f590();
int func_0205f5f0();
int func_0205f668();
/* decompiler-derived */
u32
func_02095a60(u32 arg0,u32 arg1,u32 arg2,u32 arg3)
{
  u32 value1;
  u32 value2;
  u8 auStack_20 [12];
  u32 uStack_14;
  uStack_14 = arg3;
  func_02052f58(0);
  func_0205f508(auStack_20,arg0);
  value1 = func_0205f534(auStack_20);
  value2 = func_02052ff0();
  func_0205f590(auStack_20,value2,value1);
  func_0205f5f0(auStack_20,value2,arg1);
  value1 = func_02052fe0();
  func_02052f68();
  func_0205f668(auStack_20,value2,arg1,value1);
  func_02052f58(0);
  func_02053000(value2);
  func_02052f68();
  return value1;
}
