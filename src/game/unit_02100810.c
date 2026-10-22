/* src/game/unit_02100810.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/*
 * Descriptor initialized by func_02100810: 0x20d8 is stored at +0, zero at +4,
 * and six callback pointers follow from +0x0c. The word at +0x08 is untouched.
 */
typedef struct Unk100810Ops {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    void (*fn_0c)();
    void (*fn_10)();
    void (*fn_14)();
    void (*fn_18)();
    void (*fn_1c)();
    void (*fn_20)();
} Unk100810Ops;

/*
 * Work object passed to the state setters in this file. Layout comes from the
 * observed accesses; the byte-sized field at +0x1f34 is a toggle cleared by
 * func_021065c8 while the words after it hold handles and flags.
 */
typedef struct Unk100810Work {
    u8 pad_0000[0x48];
    u32 unk_0048;
    u8 pad_004c[0x08];
    u32 unk_0054;
    u8 pad_0058[0x1edc];
    u8 unk_1f34;
    u8 pad_1f35[0x03];
    u32 unk_1f38;
    u32 unk_1f3c;
    u8 pad_1f40[0x17c];
    u32 unk_20bc;
    u32 unk_20c0;
    u32 unk_20c4;
    u32 unk_20c8;
    u32 unk_20cc;
} Unk100810Work;

/*
 * 0x1eb records of 0x10 bytes starting at +0x68, followed at +0x1f18 by a
 * u16 table indexed by (unk_0014 - unk_000c). Only the leading u16 id of each
 * record is read here; the rest of the record is opaque.
 */
typedef struct Unk100810Record {
    u16 id;
    u8 pad_0002[0x0e];
} Unk100810Record;

typedef struct Unk100810Table {
    u8 pad_0000[0x04];
    u32 unk_0004;
    u8 pad_0008[0x04];
    u32 unk_000c;
    u8 pad_0010[0x04];
    u32 unk_0014;
    u8 pad_0018[0x50];
    Unk100810Record records[0x1eb];
    u16 unk_1f18[1];
} Unk100810Table;

void func_02102260();
void func_02100870();
void func_02103508();
void func_021035a0();
void func_02104604();
void func_02104780();

/*
 * Stores 0x20d8 at +0, zero at +4, and six callback pointers from +0x0c. The
 * word at +0x08 is left untouched.
 */
void func_02100810(Unk100810Ops *ops)
{
    ops->unk_00 = 0x20d8;
    ops->unk_04 = 0;
    ops->fn_0c = func_02102260;
    ops->fn_10 = func_02100870;
    ops->fn_14 = func_02103508;
    ops->fn_18 = func_021035a0;
    ops->fn_1c = func_02104604;
    ops->fn_20 = func_02104780;
}

int func_020445f4();
int func_0204fed8();
int func_02061f10();
int func_02063920();
int func_02063a30();
/*
 * Obtains a handle from func_020445f4(0xc), passes arg2, 0xcc and 0xcd to it
 * through func_0204fed8 (with func_02063a30 around each call), then calls
 * func_02061f10(arg0, -1, 0, 0, last result). arg1 is not read.
 */
void Unk100810_Unk_104f18(u32 arg0, u32 arg1, u32 arg2)
{
  u32 tmp1;
  tmp1 = func_020445f4(0xc);
  func_02063920();
  func_0204fed8(tmp1,arg2);
  func_02063a30();
  func_0204fed8(tmp1,0xcc);
  func_02063a30();
  func_0204fed8(tmp1,0xcd);
  tmp1 = func_02063a30();
  func_02061f10(arg0,0xffffffff,0,0,tmp1);
  return;
}

void Unk100810_Unk_107154(Unk100810Work *arg0, int arg1);
void Unk0bc1a8_Unk_0bc928();

/*
 * Stores 10 at +0x48 and arg1 at +0x54, clears the byte at +0x1f34, calls
 * Unk100810_Unk_107154(arg0, 0), then calls Unk0bc1a8_Unk_0bc928(7, 6, 0).
 */
void func_021065c8(Unk100810Work *arg0, u32 arg1)
{
    arg0->unk_0048 = 10;
    arg0->unk_0054 = arg1;
    arg0->unk_1f34 = 0;
    Unk100810_Unk_107154(arg0, 0);
    Unk0bc1a8_Unk_0bc928(7, 6, 0);
}

int func_020537b8();
extern u8 *data_02176e2c;
void func_02008904();
/*
 * Passes arg0, data_02176e2c + 8128 and 60 to func_02008904; does nothing
 * while the global pointer is null.
 */
void Unk100810_Unk_1069c8(u32 a)
{
    if (data_02176e2c == 0) {
        return;
    }
    func_02008904(a, data_02176e2c + 8128, 60);
}

int Unk02e000_GetRecordFlag1();
void func_020bcfc4();
/*
 * Scans the 0x1eb records for an enabled record whose id equals the u16 selected
 * at +0x1f18 by (unk_0014 - unk_000c). On a hit it passes the +4 list base and
 * the count of earlier enabled records to func_020bcfc4.
 */
void func_02106aac(Unk100810Table *arg0)
{
    u16 target;
    int n;
    int i;

    target = arg0->unk_1f18[arg0->unk_0014 - arg0->unk_000c];
    n = 0;
    for (i = 0; i < 0x1eb; i++) {
        if (Unk02e000_GetRecordFlag1(arg0->records[i].id) == 0) {
            continue;
        }
        if (target == arg0->records[i].id) {
            func_020bcfc4(&arg0->unk_0004, n);
            return;
        }
        n++;
    }
}

/*
 * Polls func_020537b8(0, mask) for masks 0x40, 0x80, 0x20 and 0x10, setting the
 * corresponding flag word at +0x20bc, +0x20c0, +0x20c4 or +0x20c8.
 */
void Unk100810_Unk_1070d8(Unk100810Work *arg0)
{
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    arg0->unk_20bc = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    arg0->unk_20c0 = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    arg0->unk_20c4 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    arg0->unk_20c8 = 1;
  }
  return;
}

int Unk065e88_SetFlag3a();
/*
 * Toggles the flag at +0x20cc and pushes the stored mode to both state handles
 * (+0x1f38 and +0x1f3c) via Unk065e88_SetFlag3a.
 */
void Unk100810_Unk_107154(Unk100810Work *arg0, int arg1)
{
  if (arg1 != 0) {
    arg0->unk_20cc = 1;
    Unk065e88_SetFlag3a(arg0->unk_1f38);
    Unk065e88_SetFlag3a(arg0->unk_1f3c,1);
    return;
  }
  arg0->unk_20cc = 0;
  Unk065e88_SetFlag3a(arg0->unk_1f38);
  Unk065e88_SetFlag3a(arg0->unk_1f3c,0);
  return;
}

/*
 * True when the global work pointer exists and its word at +0x50 equals 1.
 */
int Unk100810_IsField50One(void)
{
    if (data_02176e2c == 0) {
        return 0;
    }
    return FIELD(u32, data_02176e2c, 80) == 1;
}
