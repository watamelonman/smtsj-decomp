/* Resource descriptors; neutral names retain unknown resource semantics. */
#include "types.h"


int func_020516d0(int handle);
extern u32 data_02141f98[];
void func_02015134(void *buffer, u32 context);
void func_0201524c(void *buffer, u32 source);
int func_02051610(void *buffer);

/* Build a handle using a zeroed 64-byte temporary and global context word 2.
 * Evidence: 0x020387bc clears the temporary before the three helper calls. */
int Unk0387bc_Unk_0387bc(u32 a)
{
    u8 buf[64] = {0};
    func_02015134(buf, data_02141f98[2]);
    func_0201524c(buf, a);
    return func_02051610(buf);
}

/* Pass a nonzero handle to func_020516d0; return whether a call occurred.
 * Evidence: original 0x02038820 null check and single helper call; handle ownership is unknown. */
u32 Unk0387bc_Unk_038820(int arg0)
{
  if (arg0 != 0) {
    func_020516d0(arg0);
    return 1;
  }
  return 0;
}

int func_02008848(void *destination, int value, u32 size);
/* Pass the first word to func_020516d0, then clear all 12 descriptor bytes.
 * Evidence: original 0x02038cbc calls func_02008848 with zero and size 12.
 * A null descriptor or zero first word returns 0 without clearing; success returns 1. */
u32 Unk0387bc_Unk_038cbc(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0xc);
    return 1;
  }
  return 0;
}


/* Pass the first word to func_020516d0, then clear all 20 descriptor bytes.
 * Evidence: original 0x02038d58 calls func_02008848 with zero and size 20.
 * A null descriptor or zero first word returns 0 without clearing; success returns 1. */
u32 Unk0387bc_Unk_038d58(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0x14);
    return 1;
  }
  return 0;
}


u32 func_0204fe18(u32 descriptor);
/* Return a borrowed 32-byte entry, or null for a null descriptor or out-of-range index.
 * Evidence: original 0x02038d94 uses descriptor words 1 and 2 for count input
 * and base, with an unsigned bound check and 32-byte stride; caller retains storage. */
u8 *Unk0387bc_GetEntry32(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[1]) <= i) {
        return 0;
    }
    return (u8 *)p[2] + i * 32;
}

/* Return a borrowed 36-byte entry, or null for a null descriptor or out-of-range index.
 * Evidence: original 0x02038dc4 uses descriptor words 3 and 4 for count input
 * and base, with an unsigned bound check and 36-byte stride; caller retains storage. */
u8 *Unk0387bc_GetEntry36(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[3]) <= i) {
        return 0;
    }
    return (u8 *)p[4] + i * 36;
}

/* Pass the first word to func_020516d0, then clear all 12 descriptor bytes.
 * Evidence: original 0x02038e40 calls func_02008848 with zero and size 12.
 * A null descriptor or zero first word returns 0 without clearing; success returns 1. */
u32 Unk0387bc_Unk_038e40(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0xc);
    return 1;
  }
  return 0;
}



/* Release a nonzero descriptor handle and clear all 20 caller-owned bytes.
 * Evidence: 0x02038edc checks both pointers and calls the clear helper with 20.
 * Return 0 without clearing on either failed check, otherwise return 1. */
u32 Unk0387bc_Unk_038edc(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0x14);
    return 1;
  }
  return 0;
}

extern u8 data_02142064[];
int func_0204fe68(int handle, int index);
/* Return a borrowed 32-byte entry, or null for a null descriptor or out-of-range index.
 * Evidence: original 0x02038f18 uses descriptor words 1 and 2 for count input
 * and base, with an unsigned bound check and 32-byte stride; caller retains storage. */
u8 *Unk0387bc_GetEntry32b(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[1]) <= i) {
        return 0;
    }
    return (u8 *)p[2] + i * 32;
}

/* Return a borrowed 36-byte entry, or null for a null descriptor or out-of-range index.
 * Evidence: original 0x02038f48 uses descriptor words 3 and 4 for count input
 * and base, with an unsigned bound check and 36-byte stride; caller retains storage. */
u8 *Unk0387bc_GetEntry36b(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[3]) <= i) {
        return 0;
    }
    return (u8 *)p[4] + i * 36;
}

/* Populate two writable descriptor words from the fixed resource at 0x02142064.
 * Evidence: 0x02038f7c stores the handle and helper result for index 0.
 * Null output or failed handle creation returns 0; success returns 1. */
u32 Unk0387bc_Unk_038f7c(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = Unk0387bc_Unk_0387bc(((int)data_02142064));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fe68(value,0);
    arg0[1] = value;
    return 1;
  }
  return 0;
}

extern u8 data_02142024[];
int func_0204fdac(int handle, int index);
int func_0204fde0(int entry);
/* Populate three writable descriptor words from resource 0x02142024.
 * Evidence: 0x02038c74 stores a handle, index-0 entry, and its derived value.
 * Null output or failed handle creation returns 0 without writing; else 1. */
u32 Unk0387bc_Unk_038c74(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = Unk0387bc_Unk_0387bc(((int)data_02142024));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,0);
    arg0[1] = value;
    value = func_0204fde0(value);
    arg0[2] = value;
    return 1;
  }
  return 0;
}

extern u8 data_02142048[];
/* Populate three writable descriptor words from resource 0x02142048.
 * Evidence: 0x02038df8 stores a handle, index-0 entry, and its derived value.
 * Null output or failed handle creation returns 0 without writing; else 1. */
u32 Unk0387bc_Unk_038df8(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = Unk0387bc_Unk_0387bc(((int)data_02142048));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,0);
    arg0[1] = value;
    value = func_0204fde0(value);
    arg0[2] = value;
    return 1;
  }
  return 0;
}

extern u32 data_02141f98[];
int func_0205ad2c(u32 context);
int Unk05b82c_CreateEntry(int *work);
/* Initialize work and copy two halfwords into the object at arg1 offsets 4/6.
 * Evidence: 0x0203883c reads them from work word 5 at offsets 0x28/0x2a
 * after CreateEntry. Both objects and the resulting word-5 pointer must be valid. */
void Unk0387bc_Unk_03883c(int *arg0,int arg1,int arg2)
{
  func_0205ad2c(*data_02141f98);
  arg0[1] = arg2;
  *arg0 = arg1;
  Unk05b82c_CreateEntry(arg0);
  *(u16 *)(arg1 + 4) = *(u16 *)(arg0[5] + 0x28);
  *(u16 *)(arg1 + 6) = *(u16 *)(arg0[5] + 0x2a);
}

extern u8 data_02142034[];
/* Populate five writable descriptor words from resource 0x02142034.
 * Evidence: 0x02038cf8 stores the handle then entry/derived pairs for indices 1, 0.
 * Null output or failed handle creation returns 0 without writing; else 1. */
u32 Unk0387bc_Unk_038cf8(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = Unk0387bc_Unk_0387bc(((int)data_02142034));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,1);
    arg0[1] = value;
    value = func_0204fde0(value);
    arg0[2] = value;
    value = func_0204fdac(*arg0,0);
    arg0[3] = value;
    value = func_0204fde0(value);
    arg0[4] = value;
    return 1;
  }
  return 0;
}

extern u8 data_02142054[];
/* Populate five writable descriptor words from resource 0x02142054.
 * Evidence: 0x02038e7c stores the handle then entry/derived pairs for indices 1, 0.
 * Null output or failed handle creation returns 0 without writing; else 1. */
u32 Unk0387bc_Unk_038e7c(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = Unk0387bc_Unk_0387bc(((int)data_02142054));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,1);
    arg0[1] = value;
    value = func_0204fde0(value);
    arg0[2] = value;
    value = func_0204fdac(*arg0,0);
    arg0[3] = value;
    value = func_0204fde0(value);
    arg0[4] = value;
    return 1;
  }
  return 0;
}

