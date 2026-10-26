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


void func_02094750(s16 *record);
int Unk044904_Get_data_0215ee98(void);
void Unk0946e0_Unk_0949e0(int a);
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

/* Update the record at state +0x7870 and combine its signed displacement
 * with the shared origin; calls at 0x02094960–0x020949d8 apply each view. */
void Unk0946e0_Unk_094958(void)
{
  int value;
  short *v2;
  short *v3;
  value = Unk044904_Get_data_0215ee98();
  func_02094750(*(s16 **)(value + 0x7870));
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

int func_02061424(int task);
int func_02094af8(int task);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020575ac(int index, int top, int bottom, int left, int right);
/* Convert shared rectangle dimensions and position to view bounds; the
 * fixed-point conversions and func_020575ac call are at 0x020949ec–0x02094a5c. */
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
void *func_020611dc(void (*callback)(int), int a, int b, int c,
                     u32 size, int d, int e, int f);
void Unk0946e0_Unk_094b98(int arg0);
void Unk09d060_Unk_09d170(void *task);

/* Allocate a 20-byte task, convert percentage a to a 256-based target,
 * and schedule it; stores at 0x02094c10–0x02094c40 establish the layout. */
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

int func_0205eae0(int start, int end, int duration, int elapsed);
int Unk_InterpolateLinear(int start, int end, int duration, int elapsed);
int func_0205eb78(int start, int end, int duration, int elapsed);

/* Interpolate the shared dimension using task mode +16; the STRH pair at
 * 0x02094b70/+0x02094b78 keeps height at three quarters of width. */
int func_02094af8(int task)
{
    Unk0946e0Task *t = (Unk0946e0Task *)task;
    u8 *v = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    int result;
    switch (t->unk_10) {
    case 0: result = func_0205eae0(t->unk_00, t->unk_04, t->unk_0c, t->unk_08); break;
    case 1: result = Unk_InterpolateLinear(t->unk_00, t->unk_04, t->unk_0c, t->unk_08); break;
    case 2: result = func_0205eb78(t->unk_00, t->unk_04, t->unk_0c, t->unk_08); break;
    }
    FIELD(s16, v, 16) = result;
    FIELD(s16, v, 18) = result * 3 / 4;
    if (t->unk_08 >= (int)t->unk_0c) return 1;
    t->unk_08++;
    return 0;
}

/* Borrowed 28-byte task layout, established by loads at 0x02094c74–0x02094d60. */
typedef struct Unk0946e0PairTask {
    int start_x, start_y, end_x, end_y, elapsed, duration;
    u8 mode;
} Unk0946e0PairTask;

/* Interpolate two signed shared origin halfwords and advance elapsed time;
 * mode dispatch and completion comparison occur at 0x02094c80/0x02094d48. */
int func_02094c74(int task)
{
    Unk0946e0PairTask *t = (Unk0946e0PairTask *)task;
    s16 *v = (s16 *)Unk0946e0_GetAddr_data_02175d94();
    int x, y;
    switch (t->mode) {
    case 0:
        x = func_0205eae0(t->start_x,t->end_x,t->duration,t->elapsed);
        y = func_0205eae0(t->start_y,t->end_y,t->duration,t->elapsed); break;
    case 1:
        x = Unk_InterpolateLinear(t->start_x,t->end_x,t->duration,t->elapsed);
        y = Unk_InterpolateLinear(t->start_y,t->end_y,t->duration,t->elapsed); break;
    case 2:
        x = func_0205eb78(t->start_x,t->end_x,t->duration,t->elapsed);
        y = func_0205eb78(t->start_y,t->end_y,t->duration,t->elapsed); break;
    }
    v[0] = x; v[1] = y;
    if (t->elapsed >= t->duration) return 1;
    t->elapsed++;
    return 0;
}

/* Allocate and schedule a pair task with targets clamped to [-64,64];
 * task size and clamps are explicit at 0x02094da8–0x02094e1c. */
void func_02094da0(int x, int y, int b, int c)
{
    Unk0946e0PairTask *t = func_020611dc(Unk0946e0_Unk_094d64,0,0,0,28,0,0,0);
    t->elapsed = -1;
    t->duration = b;
    if (x >= 64) x = 64;
    if (x <= -64) x = -64;
    t->mode = c;
    if (y >= 64) y = 64;
    if (y <= -64) y = -64;
    t->end_x = x; t->end_y = y;
    Unk09d060_Unk_09d170(t);
}

/* Borrowed command record; byte and signed halfword accesses follow
 * 0x02094efc–0x02094fd4. The provider owns its eight readable bytes. */
typedef struct Unk0946e0Command {
    u8 mode, unk_01, duration, curve;
    s16 x, y;
} Unk0946e0Command;

/* Dispatch command modes 0–8 to the task constructors; the jump table at
 * 0x02094f0c establishes the mode mapping and mode zero is a no-op. */
void func_02094ef4(int a, int b, const Unk0946e0Command *cmd)
{
    switch (cmd->mode) {
    case 0: break;
    case 1: Unk0946e0_Unk_094bd4(cmd->x,cmd->duration,cmd->curve); break;
    case 2: func_02094da0(cmd->x,cmd->y,cmd->duration,cmd->curve); break;
    case 3: Unk0946e0_Unk_094e30(cmd->x,cmd->duration,cmd->curve); break;
    case 4: Unk0946e0_Unk_094e70(b,cmd->duration,cmd->curve); break;
    case 5: Unk0946e0_Unk_094eb8(b,cmd->duration,cmd->curve); break;
    case 6: Unk0946e0_Unk_094e70(a,cmd->duration,cmd->curve); break;
    case 7: Unk0946e0_Unk_094eb8(a,cmd->duration,cmd->curve); break;
    case 8:
        Unk0946e0_Unk_094bd4(0,cmd->duration,cmd->curve);
        func_02094da0(0,0,cmd->duration,cmd->curve); break;
    }
}

int func_02050088(int stream, u32 minimum, u32 maximum);
/* Update a writable six-halfword displacement record. The duration sentinel
 * -1, delay, final-three-frame attenuation, and signed output choices follow
 * 0x02094758–0x020948f4; the source amplitudes become unsigned before scaling. */
void func_02094750(s16 *record)
{
    u32 x, y;
    int rx, ry, sx, sy, old_x, old_y;
    if (record[4] != -1 && record[5] >= record[4]) {
        Unk0946e0_Clear12(record);
        return;
    }
    if (record[5] < 0) {
        record[5]++;
        record[2] = 0;
        record[3] = 0;
        return;
    }
    x = record[0]; y = record[1];
    if (record[4] != -1 && record[4] > 3) {
        int remaining = record[4] - record[5];
        if (remaining <= 3) {
            x = (x * remaining) >> 2;
            y = (y * remaining) >> 2;
        }
    }
    rx = func_02050088(0,x >> 1,x);
    ry = func_02050088(0,y >> 1,y);
    sx = func_02050088(0,0,1) * 2 - 1;
    sy = func_02050088(0,0,1) * 2 - 1;
    old_x = record[2] > 0 ? 1 : -1;
    old_y = record[3] > 0 ? 1 : -1;
    if (record[2] == 0 && record[3] == 0) {
        record[2] = rx * sx; record[3] = ry * sy;
    } else if (record[2] == 0) {
        record[2] = rx * sx; record[3] = ry * old_y;
    } else if (record[3] == 0) {
        record[2] = rx * old_x; record[3] = ry * sy;
    } else if (func_02050088(0,0,1) == 0) {
        record[2] = rx * sx; record[3] = ry * old_y;
    } else {
        record[2] = rx * old_x; record[3] = ry * sy;
    }
    if (record[5] < 32766) record[5]++;
}
