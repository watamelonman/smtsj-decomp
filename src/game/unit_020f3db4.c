/*
 * src/game/unit_020f3db4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774(void);
int Unk044394_Unk_044428(int index);
int Unk044394_Unk_044534(int index);
int Unk0f3db4_Unk_0f3ec8(u32 arg0);

u32 Unk0f3db4_Unk_0f44a8(u32 arg0);
void Unk0f3db4_Unk_0f3dc8(void);
void Unk0f3db4_Unk_0f3dd8(void);
int Unk0f3db4_Unk_0f4528(u32 arg0);
void Unk0f3db4_Unk_0f4550(u8 *arg0);
int Unk0f3db4_Unk_0f3db4(void);
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1);
u32 Unk0f3db4_Unk_0f4490(u32 arg0,int arg1);

/* Extract the low two packed state bits; higher bits do not affect the result. */
u32 Unk0f3db4_Unk_0f44a8(u32 arg0)
{
  return arg0 & 3;
}

/* Forward fixed index 8 to 044428, discarding its result (020f3dc8 assembly). */
void Unk0f3db4_Unk_0f3dc8(void)
{
  Unk044394_Unk_044428(8);
}

/* Forward fixed index 8 to 044534, discarding its result (020f3dd8 assembly). */
void Unk0f3db4_Unk_0f3dd8(void)
{
  Unk044394_Unk_044534(8);
}

/* Return a normalized boolean for packed flag bit 2, independent of other bits. */
int Unk0f3db4_Unk_0f4528(u32 arg0)
{
  return (arg0 & 4) != 0;
}

/* Set packed flag bit 2 in a writable byte, preserving every other bit. */
void Unk0f3db4_Unk_0f4550(u8 *arg0)
{
  *arg0 = *arg0 | 4;
}

/* Return the borrowed work address at base + 0x5e52 (020f3db4 assembly). */
int Unk0f3db4_Unk_0f3db4(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5e52;
}

/* Replace a writable packed byte with its old bit 2 OR arg1; arg1 is unmasked. */
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1)
{
  *arg0 = (*arg0 & 4) | arg1;
}

/* Read low state bits at arg1 in the table selected by arg0; caller bounds it. */
u32 Unk0f3db4_Unk_0f4490(u32 arg0,int arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8(arg0);
  return Unk0f3db4_Unk_0f44a8(*(u8 *)(value + arg1));
}



/* Return flag bit 2 at the caller-bounded table offset (020f4510 LDRB/call). */
int Unk0f3db4_Unk_0f4510(u32 arg0,int arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8(arg0);
  return Unk0f3db4_Unk_0f4528(*(u8 *)(value + arg1));
}




/* decompiler-derived */
u32 Unk0f3db4_Unk_0f3e6c(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x32;
  case 1:
    return 0x32;
  case 2:
    return 0x32;
  case 3:
    return 0x32;
  case 4:
    return 100;
  case 5:
    return 0x3c;
  default:
    return 0;
  }
}


/* decompiler-derived */
int Unk0f3db4_Unk_0f3ec8(u32 arg0)
{
  int value;
  value = Unk0f3db4_Unk_0f3db4();
  switch(arg0) {
  case 0:
    return value;
  case 1:
    return value + 0x32;
  case 2:
    return value + 100;
  case 3:
    return value + 0x96;
  case 4:
    return value + 200;
  case 5:
    return value + 300;
  default:
    return 0;
  }
}


extern char data_02150e24[];
int func_020152cc(const char *left, const char *right);
void func_02099b10(int id, int amount);
u16 *Unk02e000_Thunk_0202e788(void);
int func_0209993c(int id);
/* Borrowed four-byte entry: halfwords at record offsets 10 and 12. */
typedef struct Unk0f3db4Ent {
    u16 id;
    u16 n;
} Unk0f3db4Ent;
/* Prefix view used by the three-entry loops at 020f4070 and 020f4398. */
typedef struct Unk0f3db4Obj {
    u8 pad[0xa];
    Unk0f3db4Ent e[3];
} Unk0f3db4Obj;
/* Test equality with data_02150e24 using the comparison call at 020f4160;
 * the existing IsName symbol supports the name. s is a terminated string. */
int Unk0f3db4_IsName(const char *s)
{
    return func_020152cc(s, data_02150e24) == 0;
}

/* Submit each nonzero entry ID with its count times k; 020f4398 loads
 * halfwords at +10/+12 with stride four before calling 02099b10. */
void Unk0f3db4_Unk_0f4398(Unk0f3db4Obj *p, int k)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->e[i].id != 0) {
            func_02099b10(p->e[i].id, k * p->e[i].n);
        }
    }
}

/* Subtract one from a positive query result when id occurs in the four
 * borrowed halfwords returned by 0202e788 (020f4448 comparison chain). */
int Unk0f3db4_Unk_0f4448(int id)
{
    u16 *q = (u16 *)Unk02e000_Thunk_0202e788();
    int n = func_0209993c(id);
    if (n <= 0) {
        return n;
    }
    if (id == q[0] || id == q[1] || id == q[2] || id == q[3]) {
        n--;
    }
    return n;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4674(int arg0,int arg1)
{
  u8 value1;
  int value2;
  int value3;
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3));
    *(u8 *)(arg0 + value3) = value1;
    value3 = value3 + 1;
  } while (value3 < 100);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 100));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 100) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 0x96));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 0x96) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 300));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 300) = value1;
  } while (value3 < 0x3c);
}

/* Set flag bit 2 at a caller-bounded table offset (020f4538 ADD/call). */
void Unk0f3db4_Unk_0f4538(u32 arg0,int arg1)
{
  int tmp1;
  tmp1 = Unk0f3db4_Unk_0f3ec8((u32)arg0);
  Unk0f3db4_Unk_0f4550((u8 *)tmp1 + arg1);
}

/* Forwards (base + offset, value) to Unk0f3db4_Unk_0f44d0. */
void Unk0f3db4_Unk_0f44b0(u32 arg0, int offset, u8 value)
{
    Unk0f3db4_Unk_0f44d0((u8 *)Unk0f3db4_Unk_0f3ec8(arg0) + offset, value);
}

/* Promotes state 2 to state 3. */
void Unk0f3db4_Unk_0f44e4(u32 arg0, int offset)
{
    if (Unk0f3db4_Unk_0f4490(arg0, offset) != 2) {
        return;
    }
    Unk0f3db4_Unk_0f44b0(arg0, offset, 3);
}

/* Query up to three entries, stopping at a zero ID or insufficient count.
 * 020f4070 returns 0 for shortage at entry zero, 1 for later shortage, and
 * 2 when the scan ends without shortage; p borrows the observed prefix. */
int func_020f4070(const Unk0f3db4Obj *p)
{
    int result = 2;
    int i;
    for (i = 0; i < 3; i++) {
        if (p->e[i].id == 0) {
            break;
        }
        if (func_0209993c(p->e[i].id) < p->e[i].n) {
            if (i == 0) {
                result = 0;
            } else {
                result = 1;
            }
            break;
        }
    }
    return result;
}
