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

/* Main-loop global view; only its first three words receive the -1 sentinel. */
typedef struct Unk02cad4Globals {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 phase;
    u32 unknown_10;
    u32 frame_counter;
    u32 unk_18;
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

/* Sets up display layout mode (0..3), without taking ownership of arguments.
 * Evidence: the original selects named palette/plane resources and display calls. */
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

/* Borrowed 28-byte entries: callback and layout offsets follow the original loads. */
typedef struct Unk02cad4Entry {
    void (*enter)(void);
    void (*update)(void);
    void (*leave)(void);
    int setup_display;
    int cleanup;
    int mode;
    u32 display_arg;
} Unk02cad4Entry;
extern Unk02cad4Entry data_0213d688[];

/* Advances the three-phase callback dispatcher; -1 denotes no selected entry.
 * Evidence: the original indexes the 28-byte table and calls offsets 0, 4, 8. */
void func_0202cad4(void)
{
    Unk02cad4Globals *g = &data_0213d338;
    Unk02cad4Entry *entry = 0;
    if (g->unk_00 != (u32)-1) {
        entry = &data_0213d688[g->unk_00];
    }
    switch (g->phase) {
    case 0:
        if (entry) {
            if (entry->setup_display) {
                Unk02cad4_SetupDisplayMode(entry->mode, entry->display_arg, 0);
            }
            entry->enter();
        }
        g->phase = 1;
        break;
    case 1:
        if (entry) {
            entry->update();
        }
        if (g->unk_08 != (u32)-1) {
            g->phase = 2;
        }
        break;
    case 2:
        if (entry) {
            entry->leave();
            if (entry->cleanup) {
                Unk02cad4_Thunk_0206148c();
            }
        }
        g->unk_04 = g->unk_00;
        g->unk_00 = g->unk_08;
        g->unk_08 = -1;
        g->phase = 0;
        break;
    }
}

void Unk02e000_Unk_02e0ac(void);
void func_02061798(void);
void func_020662d4(int slot, int value);
void func_02044488(void);
void func_020a163c(void);
int func_0200e940(s32 *values);
void func_0205002c(int slot, u32 value);
void func_02007dc4(u32 *values);
void Unk02e000_EnsureAlloc7718(void);
void Unk02e000_Unk_02e144(void);
u32 func_020df6a8(void);
void func_0205ebd8(u32 a, u32 b, u32 c, int d);
void Unk095560_Unk_095598(void);
void Unk0bc1a8_Unk_0bc5d4(void);
void func_020ba918(void);
void func_020967a4(int value);

/* Initializes main-loop services and seeds two slots from startup data.
 * Caller evidence: main invokes this once before its frame loop. Returns 1. */
int func_0202cbfc(void)
{
    s32 values[3];
    u32 words[8];
    u32 seed;
    u32 i;
    Unk02cad4_ResetGlobals();
    Unk02e000_Unk_02e0ac();
    func_02061798();
    func_020662d4(0, 36);
    func_020662d4(1, 37);
    func_020662d4(2, 38);
    func_02044488();
    func_020a163c();
    if (func_0200e940(values) == 0) {
        s32 product = values[2] * (values[0] + 1);
        s32 factor = values[1] + 1;
        func_0205002c(1, product * factor);
    } else {
        func_0205002c(1, 2048);
    }
    seed = 0;
    func_02007dc4(words);
    for (i = 0; i < 8; i++) {
        seed ^= words[i];
    }
    func_0205002c(0, seed);
    Unk02e000_EnsureAlloc7718();
    Unk02e000_Unk_02e144();
    func_0205ebd8(0x1001, 0x4a53444d, func_020df6a8(), 6);
    Unk095560_Unk_095598();
    Unk0bc1a8_Unk_0bc5d4();
    func_020ba918();
    func_020967a4(0);
    Unk02cad4_Unk_02cbdc(0);
    data_0215dd1c = 0;
    return 1;
}

int func_0205ecc8(void);
int Unk0e1648_Unk_0e1664(void);
void func_020539dc(void);
void func_020bc614(void);
int func_02053bc8(void);
void func_0206135c(u32 value);
extern u32 data_0215dd20;
int func_02051b18(u32 *state, int a, int b, int c, int d);
void Unk02e000_AddCounter5fc4(int value);
void func_02007ba4(int value);
void func_02061404(void);

/* Runs one main-loop update, with the original input latch and geometry-busy wait.
 * Evidence: main calls this every frame; 0x04000600 bit 27 is GXSTAT busy. */
int func_0202cd14(void)
{
    if (!func_0205ecc8() && !Unk0e1648_Unk_0e1664()) {
        func_020539dc();
    }
    func_020bc614();
    func_0202cad4();
    if (func_02053bc8() == 3 || func_02053bc8() == 2) {
        func_0206135c(data_0213d338.unk_18);
        if (Unk0e1648_Unk_0e1648() == 1) {
            if (func_02051b18(&data_0215dd20, 1, 0, 60, 2) == 1) {
                Unk02e000_AddCounter5fc4(1);
            }
        }
        if (!func_0205ecc8() && !Unk0e1648_Unk_0e1664() && func_0202cdf4() == 1) {
            func_02007ba4(0);
            return 1;
        }
    }
    func_02061404();
    while (*(volatile u32 *)0x04000600 & 0x08000000) {
        /* Wait for the geometry engine to finish before the next frame. */
    }
    return 1;
}
