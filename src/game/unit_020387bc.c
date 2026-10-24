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
 * Evidence: original 0x02038820 null check and single helper call; handle ownership is unknown.
 * Caller 0x02038c58 supplies an unused resource context in r1. */
u32 Unk0387bc_Unk_038820(int arg0, const void *context)
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

/* Halfword alignment is observed in the original 40-byte copy loops. */
typedef struct { u16 values[20]; } Unk0387bc_Record40;
/* Borrowed destination view: the second record begins at byte 512. */
typedef struct {
    Unk0387bc_Record40 first;
    u8 pad_0028[472];
    Unk0387bc_Record40 second;
} Unk0387bc_CopyWork;
int func_020445d0(int resource, int index);
/* Copy a bounded resource-36 record to offset 0 or 512 of caller storage.
 * Evidence: 0x02038888 checks the unsigned index and copies 40 bytes;
 * selector 1 chooses offset 512. Null output or invalid index returns 0. */
u32 func_02038888(Unk0387bc_CopyWork *out, u32 index, int selector)
{
    int entry;
    u32 result;
    if (out == 0) return 0;
    result = 0;
    entry = func_020445d0(36, 0);
    if (index < func_0204fe18(entry)) {
        Unk0387bc_Record40 *records = (Unk0387bc_Record40 *)func_0204fde0(entry);
        if (selector == 1) out->second = records[index];
        else out->first = records[index];
        result = 1;
    }
    return result;
}

/* These views preserve the byte/halfword/word copy alignment in 0x02038934. */
typedef struct { s8 values[4]; } Unk0387bc_Selection;
typedef struct {
    u16 values[11];
    s8 section;
    u8 unk_0017;
} Unk0387bc_Record24;
typedef struct { u8 values[32]; } Unk0387bc_Record32;
typedef struct { u32 values[10]; } Unk0387bc_Words40;
typedef struct { u8 values[2]; } Unk0387bc_Pair;
/* Caller-owned output; list counts are capped to the 60 available pairs. */
typedef struct {
    u8 pad_0000[40];
    Unk0387bc_Selection selection;
    Unk0387bc_Record24 record24;
    Unk0387bc_Record32 record32;
    Unk0387bc_Words40 words40;
    u32 count_a;
    Unk0387bc_Pair list_a[60];
    u32 count_b;
    Unk0387bc_Pair list_b[60];
    u32 count_c;
    Unk0387bc_Pair list_c[60];
} Unk0387bc_Output;
extern u8 data_02141ffc[];
extern u8 data_02142010[];
/* Populate selected records and three bounded lists from resource 0x02141ffc.
 * Evidence: 0x02038934 indexes sections 0/1/2 for selection, 3/4/5 for
 * records, then the selected section and sections 11/10 for lists. Caller
 * supplies valid selection indices and writable output; null returns 0. */
u32 func_02038934(Unk0387bc_Output *out, u32 index, int column,
                  int variant, int alternate, int mode)
{
    Unk0387bc_Words40 *source40, *destination40;
    u32 i;
    u32 result;
    int handle, entry;
    Unk0387bc_Pair *pairs;
    if (out == 0) return 0;
    result = 0;
    handle = Unk0387bc_Unk_0387bc((u32)data_02141ffc);
    if (handle != 0) {
        entry = func_0204fdac(handle, 0);
        if (index < func_0204fe18(entry)) {
            if (mode == 0 || variant == 0) {
                out->selection = ((Unk0387bc_Selection *)func_0204fde0(entry))[index * 4 + column];
            } else if (mode == 1) {
                entry = alternate != 0 ? 1 : 0;
                out->selection = ((Unk0387bc_Selection *)func_0204fde0(func_0204fdac(handle, 1)))[(variant - 1) * 2 + entry];
            } else {
                entry = func_0204fdac(handle, 2);
                out->selection = (((Unk0387bc_Selection *)func_0204fde0(entry)) + variant)[-1];
            }
            entry = func_0204fdac(handle, 3);
            entry = func_0204fde0(entry);
            out->record24 = ((Unk0387bc_Record24 *)entry)[out->selection.values[0]];
            out->record32 = ((Unk0387bc_Record32 *)func_0204fde0(func_0204fdac(handle, 4)))[out->selection.values[1]];
            source40 = &((Unk0387bc_Words40 *)func_0204fde0(func_0204fdac(handle, 5)))[out->selection.values[2]];
            destination40 = &out->words40;
            *destination40 = *source40;
            entry = func_0204fdac(handle, ((Unk0387bc_Record24 *)entry)[out->selection.values[0]].section + 6);
            pairs = (Unk0387bc_Pair *)func_0204fde0(entry);
            out->count_a = func_0204fe18(entry);
            if (out->count_a > 60) out->count_a = 60;
            for (i = 0; i < out->count_a; i++) out->list_a[i] = pairs[i];
            entry = func_0204fdac(handle, 11);
            pairs = (Unk0387bc_Pair *)func_0204fde0(entry);
            out->count_b = func_0204fe18(entry);
            if (out->count_b > 60) out->count_b = 60;
            for (i = 0; i < out->count_b; i++) out->list_b[i] = pairs[i];
            entry = func_0204fdac(handle, 10);
            pairs = (Unk0387bc_Pair *)func_0204fde0(entry);
            out->count_c = func_0204fe18(entry);
            if (out->count_c > 60) out->count_c = 60;
            for (i = 0; i < out->count_c; i++) out->list_c[i] = pairs[i];
            result = 1;
        }
        Unk0387bc_Unk_038820(handle, data_02142010);
    }
    return result;
}
