/* src/game/unit_02124c5c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_02124e9c(void);
/* forwards to `func_02124e9c` */
void Unk124c5c_Thunk_02124e9c(void) { func_02124e9c(); }

int func_02124c5c();
int func_02124ce8();
/* decompiler-derived */
void Unk124c5c_Unk_124cb0(void)
{
  func_02124c5c();
  func_02124ce8(2);
}

extern u8 *data_02176e88;
int func_02061424();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020e7f44();
int Unk124c5c_IsKind0(void);
int Unk124c5c_IsKind31(void);
void Unk124c5c_Unk_124cc4(void)
{
    func_020e7f44(0, 0, 0, 0);
    func_02124ce8(2);
}

/* decompiler-derived */
void Unk124c5c_Unk_124d54(void)
{
  func_02061424((u32)data_02176e88);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

void func_02124d6c(u32 a, u32 b)
{
    if (data_02176e88 != 0) {
        FIELD(u32, data_02176e88, 12) = a;
        FIELD(u32, data_02176e88, 16) = b;
    }
}

void func_02124d8c(u32 a, u32 b)
{
    if (data_02176e88 != 0) {
        FIELD(u32, data_02176e88, 4) = a;
        FIELD(u8, data_02176e88, 8) = b;
    }
}

int Unk124c5c_IsKind0(void)
{
    u8 *p = data_02176e88;
    if (p != 0 && FIELD(s8, p, 8) == 0) {
        return 1;
    }
    return 0;
}

int Unk124c5c_IsKind31(void)
{
    u8 *p = data_02176e88;
    if (p != 0 && FIELD(s8, p, 8) == 31) {
        return 1;
    }
    return 0;
}

int Unk124c5c_Unk_124e04(void)
{
    u8 *p = data_02176e88;
    if (p == 0) {
        return 1;
    }
    switch (FIELD(u32, p, 4)) {
    case 0:
        return Unk124c5c_IsKind0();
    case 1:
        return Unk124c5c_IsKind31();
    }
    return 1;
}

/* decompiler-derived */
void Unk124c5c_Unk_124e50(u32 arg0)
{
  if (data_02176e88 != 0) {
    *(u32 *)(data_02176e88 + 0x14) = arg0;
  }
}
