/*
 * src/game/unit_020bcef4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0bcef4Work {
    u8 unk_0000[0x4];
    s32 UnkField0004;
} Unk0bcef4Work;


/* Dispatches the record operation; the third argument controls its predicate check. */
int func_020bd30c(u32 arg0, u32 arg1, s32 arg2);
/* Writes the record mode at +8; mode 2 is used by the wrapper below. */
void func_020bd49c(u32 arg0, s32 mode);
u32 Unk0bcef4_Unk_0bd584(int arg0,u32 arg1);
/* Consumes the identifier loaded from the caller-owned first word. */
int Unk0bd5f0_Unk_0bd614(u32 identifier);

void Unk0bcef4_Unk_0bd2fc(u32 arg0,u32 arg1);
void Unk0bcef4_Unk_0bd388(u32 arg0,u32 *arg1);
void Unk0bcef4_Unk_0bd470(u32 *arg0);
void Unk0bcef4_Unk_0bd5c4(u32 arg0);
void Unk0bcef4_Unk_0bd3e0(Unk0bcef4Work *work);
void Unk0bcef4_Unk_0bd480(int *arg0,int arg1);

/* Forwards both arguments with a zero third argument (020bd2fc..020bd308); borrowed addresses must satisfy func_020bd30c. */
void Unk0bcef4_Unk_0bd2fc(u32 arg0,u32 arg1)
{
  func_020bd30c(arg0,arg1,0);
}

/* Forwards the borrowed count word to Unk0bcef4_Unk_0bd584 (load at 020bd38c); arg1 must be readable. */
void Unk0bcef4_Unk_0bd388(u32 arg0,u32 *arg1)
{
  Unk0bcef4_Unk_0bd584(arg0,*arg1);
}

/* Passes the first word to Unk0bd5f0_Unk_0bd614 (load at 020bd474); arg0 must be readable. */
void Unk0bcef4_Unk_0bd470(u32 *arg0)
{
  Unk0bd5f0_Unk_0bd614(*arg0);
}

/* Selects mode 2 through func_020bd49c (020bd5c4..020bd5d0); arg0 identifies its writable record. */
void Unk0bcef4_Unk_0bd5c4(u32 arg0)
{
  func_020bd49c(arg0,2);
}

/* Increments the signed word at +4 and caps it at 1 (020bd3e0..020bd3f8); work is borrowed and writable. */
void Unk0bcef4_Unk_0bd3e0(Unk0bcef4Work *work)
{
  int value;
  value = work->UnkField0004 + 1;
  work->UnkField0004 = value;
  if (1 < value) {
    work->UnkField0004 = 1;
  }
}

/* Advances the signed +4 word modulo 2 (020bd3fc..020bd414).
 * The remainder retains the dividend's sign; work is borrowed and writable.
 */
void func_020bd3fc(Unk0bcef4Work *work)
{
    work->UnkField0004++;
    work->UnkField0004 %= 2;
}

/* Stores the state and sets the next word to 1 for states 1, 4, or 6 (020bd480..020bd498); arg0 has two writable words. */
void Unk0bcef4_Unk_0bd480(int *arg0,int arg1)
{
  *arg0 = arg1;
  if ((arg1 == 1 || arg1 == 4) || arg1 == 6) {
    arg0[1] = 1;
  }
}



/* decompiler-derived */
void Unk0bcef4_Unk_0bcef4(u32 *arg0,u32 arg1,u32 arg2,u32 arg3)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = arg3;
}

int Unk0bd5f0_Unk_0bd5f0();
/* decompiler-derived */
void Unk0bcef4_Unk_0bd368(int arg0,int arg1)
{
  Unk0bd5f0_Unk_0bd5f0((*(int *)(arg1 + 0x10) - *(int *)(arg1 + 8)) * 0xc + arg0);
}


int func_020bd070();
int func_020bd54c();
/* decompiler-derived */
u32 Unk0bcef4_Unk_0bd29c(int arg0,int *arg1)
{
  int value;
  value = 0;
  if (0 < *arg1) {
    do {
      func_020bd070(arg0,1,0);
      func_020bd54c(arg0,0);
      value = value + 1;
      arg0 = arg0 + 0xc;
    } while (value < *arg1);
  }
  return 1;
}

int func_020bd398();
/* decompiler-derived */
u32 Unk0bcef4_Unk_0bd584(int arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  u32 tmp3;
  tmp2 = 0xffffffff;
  tmp3 = 0;
  if (arg1 != 0) {
    do {
      tmp1 = func_020bd398(arg0);
      if (tmp1 != 0) {
        tmp2 = tmp3;
      }
      tmp3 = tmp3 + 1;
      arg0 = arg0 + 0xc;
    } while (tmp3 < arg1);
  }
  return tmp2;
}

/* Borrowed first-word view; the comparisons at 020bd5d8..020bd5e0 identify it as a state. */
typedef struct Unk0bcef4State {
    s32 state;
} Unk0bcef4State;

/* Returns whether the first word is state 0, 1, or 5 (020bd5d4..020bd5ec),
 * which is the evidence for the existing descriptive symbol. t must be readable.
 */
int Unk0bcef4_IsState015(Unk0bcef4State *t)
{
    s32 s = t->state;
    if (s == 1 || s == 0 || s == 5) {
        return 1;
    }
    return 0;
}
