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
void func_020cb044(void);
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
void Unk095560_Thunk_020cb044(void) { func_020cb044(); }
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
