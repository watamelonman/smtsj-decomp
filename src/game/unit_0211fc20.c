#include "types.h"

/** Partial work layout inferred from the original loads and stores; gaps are opaque. */
typedef struct Unk11fc20Work {
    s32 state;
    u32 unknown04[3];
    u32 unknown10;
    u32 unknown14;
    s32 unknown18;
    s32 unknown1c;
    u32 unknown20[2];
    s32 unknown28;
    u32 unknown2c[5];
    s32 unknown40;
    s32 unknown44;
} Unk11fc20Work;

/** Entries have a 44-byte stride, as evidenced by the loop at 02120944. */
typedef struct Unk11fc20Entry {
    s32 value;
    u32 unknown04[10];
} Unk11fc20Entry;

/** Only the entry array at offset 424 is known; its 32 elements follow the loop bound. */
typedef struct Unk11fc20Entries {
    u32 unknown00[106];
    Unk11fc20Entry entries[32];
} Unk11fc20Entries;

extern Unk11fc20Work *data_02176e7c;
extern Unk11fc20Work *func_0211fcb0(void);
extern void func_02061424(Unk11fc20Work *work);
extern void Unk0a0ce4_Unk_0a0da4(s32 value);

/** Creates the global work only when absent, following the null guard at 0211fc20. */
void Unk11fc20_Unk_11fc20(void)
{
    if (data_02176e7c != 0) return;
    data_02176e7c = func_0211fcb0();
}

/** Passes existing global work to 02061424; an absent work pointer requires no call. */
void Unk11fc20_Unk_11fc48(void)
{
    if (data_02176e7c == 0) return;
    func_02061424(data_02176e7c);
}

/** Reports absent work or state 4, evidenced by the state comparison at 0211fc68. */
s32 Unk11fc20_IsState4(void)
{
    if (data_02176e7c == 0) return 1;
    return data_02176e7c->state == 4;
}

/** Returns the word at work offset 16, or zero when no work exists. */
u32 Unk11fc20_Unk_11fc94(void)
{
    if (data_02176e7c == 0) return 0;
    return data_02176e7c->unknown10;
}

/** Clears the global pointer without releasing its target, as the sole store at 0211fd24 shows. */
void Unk11fc20_Clear_data_02176e7c(void)
{
    data_02176e7c = 0;
}

/** Requires valid work; decreases offset 40 by 4096 and reports whether it is at most 8192. */
s32 Unk11fc20_Unk_120650(Unk11fc20Work *work)
{
    work->unknown28 -= 4096;
    return work->unknown28 <= 8192;
}

/** Requires valid work; advances the offset-68 countdown and selects the next state fields. */
s32 Unk11fc20_Unk_12066c(Unk11fc20Work *work)
{
    Unk0a0ce4_Unk_0a0da4(3);
    work->unknown40 = 0;
    work->unknown44 -= 4096;
    if (work->unknown44 <= 4096) {
        work->unknown1c = 0;
        return 1;
    }
    work->unknown18 = 15;
    return 0;
}

/** Counts nonzero words across the 32 entries starting at offset 424; requires valid work. */
s32 Unk11fc20_Unk_120944(const Unk11fc20Entries *work)
{
    s32 count = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (work->entries[i].value != 0) count++;
    }
    return count;
}

/* Existing helpers outside M1-T835, retained from the previous implementation. */
int func_02120bd4();
void func_02057d54();
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void Unk11fc20_Unk_12143c(int arg0,int arg1,u32 arg2)
{
  func_02120bd4(4,0,((Unk11fc20Work *)arg0)->unknown04[2],((Unk11fc20Work *)arg0)->unknown10,0x3000,
                arg1 << 0xc,arg2,0,0);
  return;
}

void Unk11fc20_Unk_11fd38(u32 *arg0)
{
  arg0[3] = 100;
  *arg0 = 0;
  arg0[6] = 0;
  arg0[7] = 1;
  arg0[10] = 0x40000;
  arg0[0xb] = 0xb8000;
  arg0[0x11] = 0x4000;
  Unk0a0ce4_Unk_0a0da4(8);
  return;
}

void Unk11fc20_Unk_120b88(u32 arg0,u32 arg1,int arg2,int arg3,int arg4,
                  int arg5,u32 arg6,u32 arg7,u32 arg8)
{
  func_02120bd4(arg0,arg1,arg2 << 0xc,arg3 << 0xc,arg4 << 0xc,arg5 << 0xc,arg6,
                arg7,arg8);
  return;
}

int * Unk11fc20_Unk_120a58(u32 arg0)
{
  int *v1;
  int tmp2;
  tmp2 = (u32)data_02176e7c;
  switch(arg0) {
  case 0:
    break;
  case 1:
    v1 = (int *)(tmp2 + 0x48);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 8);
    break;
  case 2:
    v1 = (int *)(tmp2 + 0x728);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x10);
    break;
  case 3:
    v1 = (int *)(tmp2 + 0x1a8);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x20);
    break;
  case 4:
    v1 = (int *)(tmp2 + 0x9e8);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x80);
  }
  return (int *)0x0;
}

void Unk11fc20_Unk_120898(u32 a, int b, int c, u32 d, u32 e, u32 f)
{
    u8 *w = (u8 *)(u32)data_02176e7c;
    func_02057d54(a, b + (FIELD(int, w, 4) + 64), c + FIELD(int, w, 8), d, e, f);
}
