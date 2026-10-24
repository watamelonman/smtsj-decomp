/*
 * src/game/unit_020946e0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02175d94[];
void func_02008848(void *destination, int value, u32 size);
void *func_02052ff0(u32 size);
void func_02053000(void);
void func_02057628(u32 index, s32 x, s32 y);
void func_02057678(u32 index, s32 x, s32 y);

int Unk0946e0_Unk_0948fc(int arg0);
void Unk0946e0_Thunk_02053000(void);
u32 Unk0946e0_GetAddr_data_02175d94(void);
void Unk0946e0_Unk_094ae0(int *arg0);
u32 Unk0946e0_Unk_0946e0(void);
void Unk0946e0_Unk_094c50(int *arg0);
void Unk0946e0_Unk_094a64(u32 arg0);

/* Clear the caller-owned 12-byte record; the null guard is present at 0x02094734. */
void Unk0946e0_Clear12(void *p)
{
    if (p == 0) {
        return;
    }
    func_02008848(p, 0, 12);
}

/* Return the address four bytes into a record (ADD r0, r0, #4 at 0x020948fc).
 * Addresses use the DS 32-bit integer representation; no fields are read here. */
int Unk0946e0_Unk_0948fc(int arg0)
{
  return arg0 + 4;
}

/* Forward to func_02053000 without arguments, as the sole BL at 0x02094908 shows. */
void Unk0946e0_Thunk_02053000(void) { func_02053000(); }

/* Expose the shared record address; the literal at 0x02094954 names data_02175d94.
 * The returned address remains owned by this module. */
u32 Unk0946e0_GetAddr_data_02175d94(void)
{
  return ((int)data_02175d94);
}

/* Copy the signed halfword at shared-record offset 0x10 into a non-null output.
 * LDRSH at 0x02094aec establishes the signed widening contract. */
void Unk0946e0_Unk_094ae0(int *arg0)
{
  int value;
  value = Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*(short *)(value + 0x10);
}

/* Allocate and zero 12 bytes, returning the allocator address to the caller.
 * The size and unconditional clear follow the calls at 0x020946e8 and 0x020946f8. */
u32 Unk0946e0_Unk_0946e0(void)
{
  u32 value;
  value = (u32)func_02052ff0(0xc);
  func_02008848((void *)value,0,0xc);
  return value;
}

/* Copy shared-record halfwords at offsets 0 and 2 to two signed word outputs.
 * The two LDRSH instructions at 0x02094c5c/0x02094c68 establish sign extension. */
void Unk0946e0_Unk_094c50(int *arg0)
{
  short *v1;
  int value;
  v1 = (short *)Unk0946e0_GetAddr_data_02175d94();
  *arg0 = (int)*v1;
  value = Unk0946e0_GetAddr_data_02175d94();
  arg0[1] = (int)*(short *)(value + 2);
}

/* Forward shared-record words at +4/+8 to func_02057678, then pass zeroes to
 * func_02057628 for the same index (calls at 0x02094a78/0x02094a88). */
void Unk0946e0_Unk_094a64(u32 arg0)
{
  int value;
  value = Unk0946e0_GetAddr_data_02175d94();
  func_02057678(arg0,*(u32 *)(value + 4),*(u32 *)(value + 8));
  func_02057628(arg0,0,0);
}



/* Initialize a nullable 12-byte record with three halfword values and a negated
 * delay; STRH offsets at 0x02094710–0x0209472c establish the layout. */
void Unk0946e0_Unk_094704(u16 *arg0,u16 arg1,u16 arg2,u16 arg3,
                  short arg4)
{
  if (arg0 == (u16 *)0x0) {
    return;
  }
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[4] = arg3;
  arg0[5] = -arg4;
  arg0[2] = 0;
  arg0[3] = 0;
}


int func_02094750();
void Unk0946e0_Unk_0949e0();
void Unk0946e0_ApplyRect(int a);
/* Reset the shared rectangle to origin and 256 by 192; stores at
 * 0x0209491c–0x02094944 establish the dimensions and cleared trailing word. */
void Unk0946e0_ResetRect(void)
{
    u8 *p = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    FIELD(s16, p, 0x00) = 0;
    FIELD(s16, p, 0x02) = 0;
    FIELD(s32, p, 0x04) = FIELD(s16, p, 0x00);
    FIELD(s32, p, 0x08) = FIELD(s16, p, 0x02);
    FIELD(u16, p, 0x10) = 256;
    FIELD(u16, p, 0x12) = 192;
    FIELD(u32, p, 0x14) = 0;
}

/* decompiler-derived */
void Unk0946e0_Unk_094958(void)
{
  int value;
  short *v2;
  short *v3;
  value = Unk044904_Get_data_0215ee98();
  func_02094750(*(u32 *)(value + 0x7870));
  v2 = (short *)Unk0946e0_GetAddr_data_02175d94();
  value = Unk044904_Get_data_0215ee98();
  v3 = (short *)Unk0946e0_Unk_0948fc(*(u32 *)(value + 0x7870));
  *(int *)(v2 + 2) = (int)*v2 + (int)*v3;
  value = Unk044904_Get_data_0215ee98();
  value = Unk0946e0_Unk_0948fc(*(u32 *)(value + 0x7870));
  *(int *)(v2 + 4) = (int)v2[1] + (int)*(short *)(value + 2);
  Unk0946e0_ApplyRect(0);
  Unk0946e0_Unk_0949e0(1);
  Unk0946e0_ApplyRect(2);
  Unk0946e0_Unk_0949e0(3);
  Unk0946e0_Unk_094a64(6);
}

int func_02061424();
int func_02094af8(int task);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020575ac();
void Unk0946e0_Unk_0949e0(int a)
{
    u8 *v = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    s32 x = (FIELD(s32, v, 4) << 12) / 32;
    s32 y = (FIELD(s32, v, 8) << 12) / 32;
    s32 w = (FIELD(s16, v, 16) << 14) / 256;
    s32 h = (FIELD(s16, v, 18) * 12288) / 192;
    func_020575ac(a, h - y, -(h + y), x - w, x + w);
}

/* Apply shared position and half the dimension differences from 256 by 192,
 * in 12-bit fixed point; calls at 0x02094aa8/0x02094ad8 support this name. */
void Unk0946e0_ApplyRect(int a)
{
    u8 *v = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    func_02057678(a, FIELD(u32, v, 4), FIELD(u32, v, 8));
    func_02057628(a, ((FIELD(s16, v, 16) - 256) / 2) << 12, ((FIELD(s16, v, 18) - 192) / 2) << 12);
}

/* On a negative counter at +8, initialize it and capture the shared halfword;
 * otherwise update this task and release it on completion (0x02094ba8–0x02094bcc).
 * arg0 is a non-null writable task address in the DS 32-bit address space. */
void Unk0946e0_Unk_094b98(int arg0)
{
  int tmp1;
  if (*(int *)(arg0 + 8) < 0) {
    *(u32 *)(arg0 + 8) = 0;
    Unk0946e0_Unk_094ae0((int *)arg0);
    return;
  }
  tmp1 = func_02094af8(arg0);
  if (tmp1 == 0) {
    return;
  }
  func_02061424(arg0);
}

int func_02094c74(int task);
typedef struct Unk0946e0Task {
    u32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u32 unk_0c;
    u8 unk_10;
} Unk0946e0Task;
void *func_020611dc();
void Unk0946e0_Unk_094b98(int arg0);
void Unk09d060_Unk_09d170();

void Unk0946e0_Unk_094bd4(int a, u32 b, u8 c)
{
    Unk0946e0Task *t = (Unk0946e0Task *)func_020611dc(Unk0946e0_Unk_094b98, 0, 0, 0, 20, 0, 0, 0);
    t->unk_08 = -1;
    t->unk_0c = b;
    t->unk_04 = ((100 - a) << 8) / 100;
    t->unk_10 = c;
    Unk09d060_Unk_09d170(t);
}

/* Initialize a negative counter at +0x10 and capture the shared pair, or update
 * and release the task on completion (0x02094d74–0x02094d98).
 * arg0 is a non-null writable task address in the DS 32-bit address space. */
void Unk0946e0_Unk_094d64(int arg0)
{
  int tmp1;
  if (*(int *)(arg0 + 0x10) < 0) {
    *(u32 *)(arg0 + 0x10) = 0;
    Unk0946e0_Unk_094c50((int *)arg0);
    return;
  }
  tmp1 = func_02094c74(arg0);
  if (tmp1 == 0) {
    return;
  }
  func_02061424(arg0);
}

/* Signed halfword output pair written by func_02049c28; caller owns storage. */
typedef struct Unk0946e0Pt {
    s16 x;
    s16 y;
} Unk0946e0Pt;

void func_02094da0(int x, int y, int b, int c);
int func_02044ec4(int key);
void func_02049c28(int address, Unk0946e0Pt *point);
/* Clamp x to [-64, 64] and forward it with shared signed y and two parameters;
 * comparisons and shared LDRSH at 0x02094e38–0x02094e58 establish the contract. */
void Unk0946e0_Unk_094e30(int x, int b, int c)
{
    if (x >= 64) {
        x = 64;
    }
    if (x <= -64) {
        x = -64;
    }
    func_02094da0(x, FIELD(s16, Unk0946e0_GetAddr_data_02175d94(), 2), b, c);
}

/* Resolve key a to a halfword pair, subtract (128, 96), and forward the signed
 * wrapped pair with b/c; stack STRH/LDRSH at 0x02094e9c–0x02094eb0 preserve wrapping. */
void Unk0946e0_Unk_094e70(int a, int b, int c)
{
    Unk0946e0Pt pt;
    func_02049c28(func_02044ec4(a), &pt);
    pt.x -= 128;
    pt.y -= 96;
    func_02094da0(pt.x, pt.y, b, c);
}

/* Resolve key a, subtract 128 from the first halfword, and forward it with zero
 * y and b/c; STRH/LDRSH at 0x02094ee0/0x02094ee4 establish signed wrapping. */
void Unk0946e0_Unk_094eb8(int a, int b, int c)
{
    Unk0946e0Pt pt;
    func_02049c28(func_02044ec4(a), &pt);
    pt.x -= 128;
    func_02094da0(pt.x, 0, b, c);
}
