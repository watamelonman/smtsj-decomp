/* Matching routines; instruction evidence is recorded in
 * docs/functions/game-unit-020a0ce4.md. Unknown field meanings stay neutral.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0a0ce4Work {
    u8 unk_0000[0x1c];
    u32 UnkField001c;
} Unk0a0ce4Work;


extern u32 data_02176afc[];
int func_020445d0(int arg0, int arg1);
int func_0204fde0(void);
int func_02052528(int arg0);
int func_02053048(void);
int func_0205e590(int arg0);
int func_020a1318(void);
int func_020b72a8(void);

void Unk0a0ce4_Nop_0a0e94(void);
void Unk0a0ce4_Nop_0a0eb4(void);
void Unk0a0ce4_Nop_0a0eb8(void);
u32 Unk0a0ce4_Get_data_02176afc(void);
void Unk0a0ce4_Unk_0a0e34(void);
void Unk0a0ce4_Unk_0a0e98(void);
int Unk0a0ce4_Unk_0a0ce4(int arg0);

/* Intentionally does nothing: the original entry consists only of bx lr. */
void Unk0a0ce4_Nop_0a0e94(void) { }

/* Intentionally does nothing: the original entry consists only of bx lr. */
void Unk0a0ce4_Nop_0a0eb4(void) { }

/* Intentionally does nothing: the original entry consists only of bx lr. */
void Unk0a0ce4_Nop_0a0eb8(void) { }

/* Returns the shared word: original 0x020a0d94 loads data_02176afc once. */
u32 Unk0a0ce4_Get_data_02176afc(void)
{
  return *data_02176afc;
}

/* Calls 02053048 then 020b72a8; the original forwards no arguments. */
void Unk0a0ce4_Unk_0a0e34(void)
{
  func_02053048();
  func_020b72a8();
}

/* Original call sequence supplies -1 to 02052528, then zero to 0205e590,
 * and finally calls 020a1318. Their broader purpose remains unknown. */
void Unk0a0ce4_Unk_0a0e98(void)
{
  func_02052528(-1);
  func_0205e590(0);
  func_020a1318();
}

/* Returns the base from 0204fde0 plus a 32-byte index offset after calling
 * 020445d0(0, 0); evidence: original add r0, r0, r4, lsl #5.
 * Callers 020a0da4/020a0dd8 validate indices and read bytes of this address. */
int Unk0a0ce4_Unk_0a0ce4(int arg0)
{
  int value;
  func_020445d0(0,0);
  value = func_0204fde0();
  return value + arg0 * 0x20;
}


void func_0205e5ec(int value);
void func_0205e63c(void);
/* Calls 0205e5ec(0), 0205e63c(), then 0205e5ec(1) and records 1.
 * Evidence: calls and data_02176afc store at 020a0d04..020a0d40. */
void Unk0a0ce4_Unk_0a0d04(void)
{
  func_0205e5ec(0);
  func_0205e63c();
  func_0205e5ec(1);
  *data_02176afc = 1;
}

extern u32 data_02176b00[];
void func_0205bb68(void);
void func_020629c4(u32 handle);
/* Scales a by scale/1024, preserving a for scale == 1024. Evidence:
 * 020a1140 compares against 0 and 1024, then multiplies and arithmetic-shifts
 * the low 32 product bits by 10. Callers 020a115c/020a1214 use the low byte.
 * Callers must keep the signed product representable; negatives round down. */
int Unk0a0ce4_ScaleFx10(int a, int scale)
{
    if (scale == 0) {
        return 0;
    }
    if (scale != 1024) {
        a = (a * scale) >> 10;
    }
    return a;
}

/* Calls 0205bb68 three times, forwards the borrowed work word at +0x1c
 * to 020629c4, then clears data_02176b00 (020a12e8..020a1310).
 * The work pointer must be valid; ownership of the word is unknown. */
void Unk0a0ce4_Unk_0a12e8(Unk0a0ce4Work *work)
{
  func_0205bb68();
  func_0205bb68();
  func_0205bb68();
  func_020629c4(work->UnkField001c);
  *data_02176b00 = 0;
}

void func_0205e65c(void);
/* Ignores zero and the current shared value; otherwise calls 0205e65c,
 * records the argument and forwards it to 0205e5ec. Evidence: conditional
 * return and data_02176afc accesses at 020a0d30..020a0d60. */
void Unk0a0ce4_Unk_0a0d30(int arg0)
{
  if (*data_02176afc == arg0 || arg0 == 0) {
    return;
  }
  func_0205e65c();
  *data_02176afc = arg0;
  func_0205e5ec(arg0);
}

int func_0205e6c0(int byte1, int byte0);
int func_0205e740(int byte1, int byte0);
extern u32 data_0214cc84[];
u32 Unk0b6570_Get_data_02176b88(void);
void func_020967a4(int value);
void Unk02cad4_Unk_02cbdc(u32 value);
/* Calls 0205e65c, records 5, then forwards 5 and the preserved argument
 * to 0205e5ec; evidence: 020a0d68..020a0d8c. */
void Unk0a0ce4_Unk_0a0d68(int x)
{
    func_0205e65c();
    *data_02176afc = 5;
    func_0205e5ec(5);
    func_0205e5ec(x);
}

/* Rejects indices outside 0..299 with -1; otherwise forwards unsigned
 * entry bytes +1, +0 to 0205e6c0 (ldrb evidence at 020a0dc8/020a0dcc). */
int Unk0a0ce4_Unk_0a0da4(int i)
{
    u8 *p;
    if (i < 0 || i >= 300) {
        return -1;
    }
    p = (u8 *)Unk0a0ce4_Unk_0a0ce4(i);
    return func_0205e6c0(p[1], p[0]);
}

/* Rejects indices outside 0..299 with -1; otherwise forwards unsigned
 * entry bytes +1, +0 to 0205e740 (ldrb evidence at 020a0dfc/020a0e00). */
int Unk0a0ce4_Unk_0a0dd8(int i)
{
    u8 *p;
    if (i < 0 || i >= 300) {
        return -1;
    }
    p = (u8 *)Unk0a0ce4_Unk_0a0ce4(i);
    return func_0205e740(p[1], p[0]);
}

/* Returns table word i for 0..28, otherwise word zero. Evidence: signed
 * bounds checks and indexed data_0214cc84 load at 020a0e0c..020a0e2c. */
u32 Unk0a0ce4_GetTableEntry(int i)
{
    if (i >= 0 && i < 29) {
        return data_0214cc84[i];
    }
    return data_0214cc84[0];
}

/* Dispatches shared values 2/3/4 to 02cbdc(10/15/1); value 2 first calls
 * 020967a4(0). Other values have no effect (020a0e44..020a0e90). */
void Unk0a0ce4_Unk_0a0e44(void)
{
    switch (Unk0b6570_Get_data_02176b88()) {
    case 2:
        func_020967a4(0);
        Unk02cad4_Unk_02cbdc(10);
        break;
    case 3:
        Unk02cad4_Unk_02cbdc(15);
        break;
    case 4:
        Unk02cad4_Unk_02cbdc(1);
        break;
    }
}
