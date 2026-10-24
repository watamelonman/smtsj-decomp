/* Cave-area helpers reconstructed from ARM field accesses and call relocations. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct CaveAreaWork {
    u8 pad_0000[0x7c];
    u32 unk_007c;
    u32 unk_0080;
    u8 pad_0084[0x24];
    u8 unk_00a8;
    u8 pad_00a9[0x13];
    s32 unk_00bc;
    u8 pad_00c0[0x8];
    u8 unk_00c8;
    u8 pad_00c9[0x5b];
    s32 unk_0124;
    u8 pad_0128[0x38];
    u32 unk_0160;
} CaveAreaWork;

void func_0205bb68(void);
/* At 0x020ed354, invokes the no-argument helper twice; its wider purpose is unknown. */
void CaveArea_Unk_0ed354(void)
{
  func_0205bb68();
  func_0205bb68();
  return;
}


/* ARM stores at 0x020ec278 select byte state 2 and set the word at +0x160. */
void CaveArea_Unk_0ec278(CaveAreaWork *arg0)
{
  ((CaveAreaWork *)arg0)->unk_00c8 = 2;
  ((CaveAreaWork *)arg0)->unk_0160 = 1;
  return;
}


extern u8 data_02150d6c[];
u32 func_0205ba98(u32 size, u32 alignment, const u8 *source, u32 line);
/* 0x020ed1a8 requests 0x4000 bytes aligned to 0x200 and retains the handle at +0x80. */
void CaveArea_AllocBuf(u8 *p)
{
    FIELD(u32, p, 128) = func_0205ba98(0x4000, 0x200, data_02150d6c, 0x5a1);
}

/* 0x020ed3b4 resets words 0 and 2 and sets word 3 to 16; word 1 is preserved. */
void CaveArea_Unk_0ed3b4(u32 *arg0)
{
  *arg0 = 0;
  arg0[2] = 0;
  arg0[3] = 0x10;
  return;
}

void *func_020445f4(int index, int item);
u32 func_0204fed8(void *table, u32 index);
/* 0x020eda18 forwards the index through table (0x25, 0), discarding the result. */
void CaveArea_Unk_0eda18(u32 arg0)
{
  void *tmp1;
  tmp1 = func_020445f4(0x25,0);
  func_0204fed8(tmp1,arg0);
  return;
}


/* 0x020ed26c calls the helper only for a nonzero +0x124 flag, then clears it. */
void CaveArea_Unk_0ed26c(CaveAreaWork *arg0)
{
  if (((CaveAreaWork *)arg0)->unk_0124 == 0) {
    return;
  }
  func_0205bb68();
  ((CaveAreaWork *)arg0)->unk_0124 = 0;
  return;
}

extern u8 data_02150d78[];
extern u8 data_02150d94[];
extern u8 data_02150dac[];
int func_02013c3c();
int func_0205ae60();
int func_0205b398();
/* Loads Cave/Area/cave_area0%d (or cave_privatearmy) layout (medium). */
void CaveArea_LoadAreaLayout(int arg0)
{
  int tmp1;
  u8 auStack_48 [64];
  tmp1 = ((CaveAreaWork *)arg0)->unk_00bc;
  if (((CaveAreaWork *)arg0)->unk_00a8 == '\0') {
    if (tmp1 == 5) {
      func_02013c3c(auStack_48,data_02150d78);
    }
    else {
      func_02013c3c(auStack_48,data_02150d94,tmp1 + 1);
    }
  }
  else {
    func_02013c3c(auStack_48,data_02150dac,tmp1 + 6);
  }
  CaveArea_AllocBuf((u8 *)arg0);
  *(u8 **)(arg0 + 0x6c) = auStack_48;
  ((CaveAreaWork *)arg0)->unk_007c = 0;
  func_0205ae60(arg0 + 0x68);
  func_0205b398(((CaveAreaWork *)arg0)->unk_0080,arg0 + 0x68);
  ((CaveAreaWork *)arg0)->unk_0124 = 1;
}

void func_0205de30();
void Unk1241ec_Unk_124224();
void CaveArea_Unk_0ed364(u8 *p)
{
    u32 c = FIELD(u32, p, 188);
    if (p[168] == 0) {
        if (c == 5) {
            func_0205de30(FIELD(u32, p, 4), 8, FIELD(u32, p, 128));
            return;
        }
        func_0205de30(FIELD(u32, p, 4), c, FIELD(u32, p, 128));
        return;
    }
    func_0205de30(FIELD(u32, p, 4), c + 5, FIELD(u32, p, 128));
}

typedef struct CaveAreaUnk0ed9e8 {
    u8 pad_000[296];
    float t;
} CaveAreaUnk0ed9e8;

/* 0x020ed3cc advances the caller-owned float by 0.6, resetting at >= 32. */
void CaveArea_Unk_0ed3cc(float *p)
{
    *p += 0.6f;
    if (*p >= 32.0f) {
        *p = 0.0f;
    }
}

/* Stores at 0x020ed60c initialize three floats and the following integer word.
 * The caller must provide at least 16 writable bytes. */
void CaveArea_InitParams(float *p)
{
    p[0] = 96.0f;
    p[1] = 8.0f;
    p[2] = 0.0f;
    FIELD(u32, p, 12) = 16;
}

void CaveArea_Unk_0ed9e8(CaveAreaUnk0ed9e8 *o)
{
    o->t += 0.5f;
    if (o->t >= 192.0f) {
        o->t = 0.0f;
    }
}

void CaveArea_Unk_0edb4c(u8 *p)
{
    int x;
    s8 s = FIELD(s8, p, 356);
    int c = FIELD(int, p, 188);
    u8 b = p[168];
    if (c == s) {
        x = b == 0 ? 50 : 51;
    } else {
        x = b == 0 ? c + 10 : c + 16;
    }
    Unk1241ec_Unk_124224((u16)x);
}
