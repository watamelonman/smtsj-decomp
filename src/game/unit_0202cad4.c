/* Main-loop state helpers; contracts are based on the original ARM code. */
#include "types.h"


void Unk065e88_Unk_065eac(void);
/* Original at 0x0202cee0 forwards to 0x02065eac with no arguments. */
void Unk02cad4_Thunk_Unk065e88_Unk_065eac(void)
{
  Unk065e88_Unk_065eac();
}

void func_0206148c(void);
/* forwards to `func_0206148c` */
void Unk02cad4_Thunk_0206148c(void) { func_0206148c(); }

/* Three-word block at 0x0213d338; reset to -1 by Unk02cad4_ResetGlobals. */
typedef struct Unk02cad4Globals {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk02cad4Globals;

extern Unk02cad4Globals data_0213d338;

/* Original stores the unsigned -1 sentinel in the three state words. */
void Unk02cad4_ResetGlobals(void)
{
    Unk02cad4Globals *g = &data_0213d338;
    g->unk_00 = -1;
    g->unk_04 = -1;
    g->unk_08 = -1;
}

/* Returns the first state word unchanged; the reset sentinel is also valid. */
u32 Unk02cad4_GetUnk00(void)
{
    return data_0213d338.unk_00;
}

/* Stores a caller-supplied state in the word at global offset +8. */
void Unk02cad4_Unk_02cbdc(u32 arg0)
{
    data_0213d338.unk_08 = arg0;
}

int func_020537b8(int index, u32 mask);
extern u8 data_0215dd1c;

/* Original tests masks 0x200, 0x100, 4 and 8 on input index zero.
 * Returns 1 only when all tests pass and the byte latch was zero; a failed
 * test clears a latch of 1. Other nonzero latch values are preserved. */
int func_0202cdf4(void)
{
    if (func_020537b8(0, 0x200) && func_020537b8(0, 0x100) &&
        func_020537b8(0, 4) && func_020537b8(0, 8)) {
        if (data_0215dd1c == 0) {
            data_0215dd1c = 1;
            return 1;
        }
        return 0;
    }
    if (data_0215dd1c == 1) {
        return data_0215dd1c = 0;
    }
    return 0;
}

void Unk065e88_Unk_065e88(void);
void func_020e13ac(int entry);
/* Original calls 0x02065e88 before selecting entry zero at 0x020e13ac. */
void Unk02cad4_Unk_02ce80(void)
{
  Unk065e88_Unk_065e88();
  func_020e13ac(0);
}

/* Borrowed record: only the word read by 0x0202ce94 is described here. */
typedef struct Unk02cad4Record {
    u8 unknown[0x38];
    u32 unk_38;
} Unk02cad4Record;

Unk02cad4Record *Unk02e000_Unk_02e75c(int index);
int Unk0e1648_Unk_0e1648(void);
void Unk02e000_Set_data_0215dd24(u32 value);
/* If enabled, publishes the larger unsigned +0x38 word of records 0 and 1,
 * then sets the global +8 state to 1 (original calls and field loads). */
void Unk02cad4_Unk_02ce94(void)
{
  int value1;
  Unk02cad4Record *value2;
  u32 value3;
  value1 = Unk0e1648_Unk_0e1648();
  if (value1 == 0) {
    return;
  }
  value3 = 0;
  value1 = 0;
  do {
    value2 = Unk02e000_Unk_02e75c(value1);
    value1 = value1 + 1;
    if (value3 < value2->unk_38) {
      value3 = value2->unk_38;
    }
  } while (value1 < 2);
  Unk02e000_Set_data_0215dd24(value3);
  Unk02cad4_Unk_02cbdc(1);
}

/* Palette/plane name strings (".rodata" outside this TU). */
extern char data_0213d848[];
extern char data_0213d854[];
extern char data_0213d858[];
extern char data_0213d864[];
extern char data_0213d868[];
extern char data_0213d86c[];
extern char data_0213d870[];
extern char data_0213d87c[];
extern char data_0213d880[];
extern char data_0213d884[];
extern char data_0213d888[];
extern char data_0213d894[];

void Unk02e000_Unk_02e0cc(void);
void func_02051c2c(u32 a);
void func_02051dd0(int plane, const char *name);
void func_02058290(int plane, const char *name);
void func_02053fd0(int a);
void func_02051eb4(u32 a);
void Unk05b540_Init(int a, int b, int c);
void func_020552ec(int a, int b);
void func_02058300(int plane, const char *name);
void func_02054b14(int a, int b, int c, int d);
void func_02056424(int a, int b, int c);
void func_02058458(void);

/* Sets up the display for layout `mode` (0..3). */
void Unk02cad4_SetupDisplayMode(int mode, u32 unused, u32 arg)
{
    Unk02e000_Unk_02e0cc();
    switch (mode) {
    case 0:
        func_02051c2c(arg);
        func_02051dd0(0, data_0213d848);
        func_02058290(0, data_0213d854);
        func_02053fd0(1);
        func_02051eb4(arg);
        Unk05b540_Init(0, 0, 0x1000);
        func_020552ec(1, 0);
        func_020552ec(0, 1);
        break;
    case 1:
        func_02051c2c(arg);
        func_02051dd0(1, data_0213d858);
        func_02058290(0, data_0213d864);
        func_02053fd0(1);
        func_02058290(1, data_0213d868);
        func_02058300(1, data_0213d86c);
        func_02054b14(6, 1, 0, 1);
        func_02056424(1, 0, 0);
        func_02051eb4(arg);
        Unk05b540_Init(0, 0, 0x1400);
        func_020552ec(1, 0);
        func_020552ec(0, 1);
        func_020552ec(6, 1);
        func_02058458();
        break;
    case 2:
        func_02051c2c(arg);
        func_02051dd0(1, data_0213d870);
        func_02058290(0, data_0213d87c);
        func_02053fd0(1);
        func_02058290(1, data_0213d880);
        func_02058300(1, data_0213d884);
        func_02054b14(6, 1, 0, 1);
        func_02056424(1, 0, 0);
        func_02051eb4(arg);
        Unk05b540_Init(0, 0, 0x1400);
        func_020552ec(1, 0);
        func_020552ec(0, 1);
        func_020552ec(6, 1);
        break;
    case 3:
        func_02051c2c(arg);
        func_02051dd0(0, data_0213d888);
        func_02058290(0, data_0213d894);
        func_02053fd0(1);
        func_02051eb4(arg);
        Unk05b540_Init(0, 0, 0x1000);
        func_020552ec(1, 0);
        func_020552ec(0, 1);
        func_02058458();
        break;
    }
}
