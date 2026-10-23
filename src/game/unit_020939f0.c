/* Work-area helpers; offsets and call contracts follow the original ARM code. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0939f0Work {
    u8 pad_0000[8];
    u32 unk_0008;
    u8 unk_000c;
    u8 unk_000d;
    u8 unk_000e;
    u8 pad_000f[0x1d];
    s32 unk_002c;
    s32 unk_0030;
    s32 unk_0034;
    u8 pad_0038[0x4];
    u32 unk_003c;
    u32 unk_0040;
    u32 unk_0044;
    u8 pad_0048[0x4];
    u32 unk_004c;
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[0x4];
    u32 unk_005c;
    u32 unk_0060;
    u32 unk_0064;
    u32 unk_0068;
    u8 unk_006c;
} Unk0939f0Work;

void func_02057678(void);
/* The original thunk forwards without arguments to func_02057678. */
void Unk0939f0_Thunk_02057678(void) { func_02057678(); }

extern u32 data_02175d8c[];
/* Store the shared word; the original writes directly to data_02175d8c. */
void Unk0939f0_Set_data_02175d8c(u32 arg0)
{
  *data_02175d8c = arg0;
}


/* Return the shared word, as shown by the load from data_02175d8c. */
u32 Unk0939f0_Get_data_02175d8c(void)
{
  return *data_02175d8c;
}

extern u32 data_02175d90[];
void Unk0939f0_Unk_093f0c(int arg0);
/* Clear fields +8, +0x6c and +0x68 before the original initializer call.
 * o borrows a writable work area of at least 0x70 bytes. */
void Unk0939f0_Reset(Unk0939f0Work *o)
{
    o->unk_0008 = 0;
    o->unk_006c = 0;
    o->unk_0068 = 0;
    Unk0939f0_Unk_093f0c((int)o);
}

/* Clear the shared handle word; evidence: zero store to data_02175d90. */
void Unk0939f0_Clear_data_02175d90(void)
{
  *data_02175d90 = 0;
}

void func_02070440(u8 *field_0c, u32 *field_60, u32 *field_5c,
                   u32 *field_64, s32 *field_2c, u32 *field_3c, u32 *field_4c);
typedef struct Unk0939f0Ent {
    u8 pad_00[112];
} Unk0939f0Ent;
typedef struct Unk0939f0Ents {
    Unk0939f0Ent e[19];
} Unk0939f0Ents;
void func_02093b6c(int kind, Unk0939f0Ent *entry);

/* Visit 19 writable 0x70-byte entries with kinds 0, sixteen 1s, 2, 3.
 * Evidence: the original loop bound, pointer stride and helper arguments. */
void Unk0939f0_Unk_093b14(Unk0939f0Ents *p)
{
    int i;
    Unk0939f0Ent *e;
    func_02093b6c(0, &p->e[0]);
    for (i = 0, e = &p->e[1]; i < 16; i++, e++) {
        func_02093b6c(1, e);
    }
    func_02093b6c(2, &p->e[17]);
    func_02093b6c(3, &p->e[18]);
}

/* Borrow seven fields for func_02070440 in the original argument order.
 * Evidence: ARM address additions +0xc, +0x60, +0x5c, +0x64, +0x2c,
 * +0x3c and +0x4c; no ownership is transferred. */
void Unk0939f0_Unk_093dbc(Unk0939f0Work *work)
{
    func_02070440(&work->unk_000c, &work->unk_0060, &work->unk_005c,
                 &work->unk_0064, &work->unk_002c, &work->unk_003c,
                 &work->unk_004c);
}


int func_0200219c();
/* decompiler-derived */
void Unk0939f0_Unk_093ea8(int arg0)
{
  u32 tmp1;
  if (*data_02175d90 == 0) {
    return;
  }
  tmp1 = func_0200219c(0xff000 - ((Unk0939f0Work *)arg0)->unk_002c,0xd000);
  ((Unk0939f0Work *)arg0)->unk_003c = tmp1;
  tmp1 = func_0200219c(0xff000 - ((Unk0939f0Work *)arg0)->unk_0030,0xd000);
  ((Unk0939f0Work *)arg0)->unk_0040 = tmp1;
  tmp1 = func_0200219c(0xff000 - ((Unk0939f0Work *)arg0)->unk_0034,0xd000);
  ((Unk0939f0Work *)arg0)->unk_0044 = tmp1;
  ((Unk0939f0Work *)arg0)->unk_006c = 4;
  return;
}

int func_020086a0();
/* decompiler-derived */
void Unk0939f0_Unk_093f0c(int arg0)
{
  func_020086a0(0,arg0 + 0xc,0x20);
  ((Unk0939f0Work *)arg0)->unk_000c = 0xff;
  ((Unk0939f0Work *)arg0)->unk_000d = 0xff;
  ((Unk0939f0Work *)arg0)->unk_000e = 0xff;
  ((Unk0939f0Work *)arg0)->unk_002c = 0xff000;
  ((Unk0939f0Work *)arg0)->unk_0030 = 0xff000;
  ((Unk0939f0Work *)arg0)->unk_0034 = 0xff000;
  ((Unk0939f0Work *)arg0)->unk_003c = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0040 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0044 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_004c = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0050 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0054 = 0xff;
  ((Unk0939f0Work *)arg0)->unk_0060 = 0;
  ((Unk0939f0Work *)arg0)->unk_005c = 0;
  ((Unk0939f0Work *)arg0)->unk_0064 = 0;
  return;
}

void func_02061424(u32 handle);
/* Forward the shared handle to func_02061424; the original loads
 * data_02175d90 immediately before the tail call. Meaning remains unknown. */
void Unk0939f0_Unk_093da4(void)
{
  func_02061424(*data_02175d90);
}
