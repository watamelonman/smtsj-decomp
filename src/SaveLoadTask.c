#include "types.h"
/* src/SaveLoadTask.c */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Partial work layout evidenced by original loads/stores; callers own at least 0xec bytes. */
typedef struct SaveLoadTaskWork {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 unk_0014[0x4];
    s32 unk_0018;
    s32 unk_001c;
    u32 unk_0020;
    u8 unk_0024[0x10];
    u32 unk_0034;
    u8 unk_0038[0xb0];
    u32 unk_00e8;
} SaveLoadTaskWork;


typedef struct SaveLoadSprite { u8 unk00[0x18]; s32 height; } SaveLoadSprite;
typedef struct SaveLoadTask {
    u32 unk00;
    u32 unk04;
    u32 state;                  /* 0x08 */
    u8  unk0C[0x3C];
    u32 itemCount;              /* 0x48 */
    u32 cursor;                 /* 0x4C */
    u8  unk50[0x9C];
    s32 visible;                /* 0xEC */
    u32 window;                 /* 0xF0 */
    u32 unkF4;
    u32 palette;                /* 0xF8 */
    SaveLoadSprite *sprites[2]; /* 0xFC */
    u8  unk104[0x24];
    u32 cursorObj;              /* 0x128 */
    u32 arrowObj;               /* 0x12C */
} SaveLoadTask;

void func_020580ec(int enable);
void func_02057524(int a);
void Unk_LoadPalette_020de678(u32 palette);
void func_02057534(void);
void func_02057df8(void);
void func_02057e18(int a);
void func_02057fd8(void);
void func_0205c748(int screen, void *obj, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_0205dee8(int screen, u32 obj, int frame, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_02060b60(int screen, u32 obj, int x, int y, int z, int prio);

int func_02050628(int selector);
/* Return whether selector 4 or 5 is active; evidenced by the two original calls. */
int SaveLoadTask_Unk_0df7c4(void)
{
    if (func_02050628(4) != 0 || func_02050628(5) != 0) {
        return 1;
    }
    return 0;
}

/* Per-frame draw/update of the save/load screen. */
void SaveLoadTask_Draw(SaveLoadTask *task) {
    if (task->visible) {
        func_020580ec(0);
        func_02057524(0);
        Unk_LoadPalette_020de678(task->palette);
        func_02057534();
        func_02057df8();
        if (task->state != 0 && task->state != 1) {
            if (task->state == 2) {
                int i;
                for (i = 0; i < 2; i++) {
                    func_0205c748(2, task->sprites[i], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
                }
                func_02057e18(31);
                func_02060b60(2, task->cursorObj, 2, task->sprites[0]->height - 2, 0, 6);
            } else {
                func_0205c748(2, task->sprites[0], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
                func_02057fd8();
                func_0205dee8(2, task->window, 6, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
                func_02057fd8();
                func_0205dee8(2, task->window, 11, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
                func_02057df8();
                func_02057e18(31);
                func_02060b60(2, task->cursorObj, 2, -2, 0, 6);
                func_02060b60(2, task->arrowObj, 13, 168, 0, 6);
            }
        }
        func_020580ec(1);
    }
    switch (task->state) {
    case 8:
    case 10:
    case 12:
    case 13:
    case 15:
        if (!task->visible) {
            return;
        }
        if (task->cursor > task->itemCount) {
            task->cursor = task->itemCount;
        }
        break;
    case 9:
    case 11:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
        break;
    }
}



/* Original stores select state 8 and retain both caller-supplied transition words. */
void SaveLoadTask_Unk_0e006c(SaveLoadTaskWork *work,u32 arg1,u32 arg2)
{
  work->unk_0008 = 8;
  work->unk_000c = arg1;
  work->unk_0010 = arg2;
}

void func_020dfd9c(SaveLoadTaskWork *work, u32 selector, int flag2, int flag3, int flag4);
/* Forward a work block and selector with flags (1, 0, 0), as in the original call. */
void SaveLoadTask_Unk_0dfed4(SaveLoadTaskWork *arg0,u32 arg1)
{
  func_020dfd9c(arg0,arg1,1,0,0);
}

/* Original comparisons suppress flag4 for selectors 17/20 in work kind 3.
 * The work block must expose its first word and the fields used by func_020dfd9c. */
void func_020dfeec(SaveLoadTaskWork *work, u32 selector)
{
    int flag = 1;
    if (selector == 20 || selector == 17) {
        if (work->unk_0000 == 3) {
            flag = 0;
        }
    }
    func_020dfd9c(work, selector, 1, 1, flag);
}

extern u8 data_02176bf0[];
/* Original indexing uses 24-byte records: return three times the signed first
 * word. The caller must supply a valid table index. */
int SaveLoadTask_Unk_0df7f8(int arg0)
{
  return *(int *)(((int)data_02176bf0) + arg0 * 0x18) * 3;
}


/* Original stores set two words relative to arg1, word 0x20 to 6, and clear 0x34. */
void SaveLoadTask_Unk_0dffec(SaveLoadTaskWork *work,int arg1)
{
  work->unk_0018 = arg1 + 1;
  work->unk_001c = arg1 + 4;
  work->unk_0020 = 6;
  work->unk_0034 = 0;
}


/* Original stores set words 0x18/0x1c to 1/2, word 0x20 to 6, and clear 0x34. */
void SaveLoadTask_Unk_0e0010(SaveLoadTaskWork *arg0)
{
  arg0->unk_0018 = 1;
  arg0->unk_001c = 2;
  arg0->unk_0020 = 6;
  arg0->unk_0034 = 0;
}

extern u8 data_02176c78[];
void func_02053000(u32 handle);
void Unk0bc1a8_Unk_0bc6d4(int flag);
/* Original calls pass flag 1 then the handle at 0xe8; clear that handle and
 * global word +4 afterward. The broader callee semantics are unconfirmed. */
void SaveLoadTask_Unk_0e137c(SaveLoadTaskWork *work)
{
  int value;
  Unk0bc1a8_Unk_0bc6d4(1);
  func_02053000(work->unk_00e8);
  value = ((int)data_02176c78);
  work->unk_00e8 = 0;
  *(u32 *)(value + 4) = 0;
}


int Unk02cad4_GetUnk00(void);
void SaveLoadTask_Unk_0df814(void);
int Unk124c5c_IsKind0(void);
/* Original kind switch suppresses the helper call for kinds 5..9 when
 * Unk124c5c_IsKind0 is nonzero; all other kinds invoke it unconditionally. */
void SaveLoadTask_Unk_0df94c(void)
{
    switch ((u32)Unk02cad4_GetUnk00()) {
    case 0: case 1: case 2: case 3: case 4:
        break;
    case 5: case 6: case 7: case 8: case 9:
        if (Unk124c5c_IsKind0()) {
            return;
        }
    }
    SaveLoadTask_Unk_0df814();
}

void func_0205257c(int selector);
void Unk124c5c_Set_124d8c(int kind, int value);
/* Original kind switch sends (1, 0) to the kind provider for kinds 5..9;
 * other kinds send selector 3 to func_0205257c. */
void SaveLoadTask_Unk_0df86c(void)
{
    switch ((u32)Unk02cad4_GetUnk00()) {
    case 0: case 1: case 2: case 3: case 4:
        break;
    case 5: case 6: case 7: case 8: case 9:
        Unk124c5c_Set_124d8c(1, 0);
        return;
    }
    func_0205257c(3);
}

void func_0204faf0(int group, int value);
int func_020dff20(SaveLoadTaskWork *work);
/* Original scan result selects transition 12 for slot 0, otherwise 13;
 * slots 1/4 and 2/5 also update provider group 1. Work is borrowed. */
u32 SaveLoadTask_Unk_0dff68(SaveLoadTaskWork *arg0)
{
    int slot = func_020dff20(arg0);
    u32 selector;
    if (slot < 0) {
        return 0;
    }
    selector = 13;
    switch (slot) {
    case 0:
        selector = 12;
        break;
    case 1: case 4:
        func_0204faf0(1, 1);
        break;
    case 2: case 5:
        func_0204faf0(1, 2);
        break;
    case 3:
        break;
    }
    func_020dfd9c(arg0, selector, 1, 0, 0);
    return 1;
}
void func_020e1490(u32 entry, int a, int b);
void Unk02e000_Unk_02e144(void);
void Unk02f078_Unk_02f0b0(int kind);
void func_02119390(void);
void Unk108bc8_Alloc(void);

void SaveLoadTask_SelectEntry(u32 entry)
{
    switch (entry) {
    case 0:
        func_020e1490(entry, 0, 0);
        return;
    case 1:
        Unk02e000_Unk_02e144();
        func_020e1490(entry, 3, 4);
        return;
    case 2:
    case 3:
        Unk108bc8_Alloc();
        func_020e1490(entry, 2, 4);
        return;
    case 4:
        func_020e1490(entry, 1, 0);
        return;
    case 5:
        Unk02f078_Unk_02f0b0(1);
        func_02119390();
        func_020e1490(entry, 1, 4);
        return;
    case 6:
        Unk02f078_Unk_02f0b0(2);
        func_02119390();
        func_020e1490(entry, 1, 4);
        return;
    case 7:
        Unk02f078_Unk_02f0b0(3);
        func_02119390();
        func_020e1490(entry, 1, 4);
        return;
    }
}

void func_020525cc(int selector);
/* Original kind switch sends (0, 31) to the kind provider for kinds 5..9;
 * other kinds send selector 3 to func_020525cc. */
void SaveLoadTask_Unk_0df814(void)
{
    switch ((u32)Unk02cad4_GetUnk00()) {
    case 0: case 1: case 2: case 3: case 4:
        break;
    case 5: case 6: case 7: case 8: case 9:
        Unk124c5c_Set_124d8c(0, 31);
        return;
    }
    func_020525cc(3);
}


int Unk124c5c_IsKind31(void);
int func_02052728(void);
/* Original kind switch tests the complementary provider predicate selected by
 * flag for kinds 5..9, and func_02052728 for other kinds. Returns boolean 0/1. */
int func_020df8c4(int flag)
{
    switch ((u32)Unk02cad4_GetUnk00()) {
    case 0: case 1: case 2: case 3: case 4:
        break;
    case 5: case 6: case 7: case 8: case 9:
        if (flag) {
            if (!Unk124c5c_IsKind0()) {
                return 1;
            }
        } else {
            if (!Unk124c5c_IsKind31()) {
                return 1;
            }
        }
        goto inactive;
    }
    if (func_02052728()) {
        return 1;
    }
inactive:
    return 0;
}

/* Borrowed layout views preserve the indexed access widths from the original. */
typedef struct SaveLoadScanView {
    u8 prefix[0xdc];
    s32 index;
    u8 flags[6];
} SaveLoadScanView;

/* Borrowed transition words occupy offsets 0x18 through 0x2c. */
typedef struct SaveLoadTransitionView {
    u8 prefix[0x18];
    s32 words[6];
} SaveLoadTransitionView;

/* Original signed scan advances work +0xdc, searches six byte flags at +0xe0,
 * and retains the next flagged index, or -1 on exhaustion. Work is borrowed;
 * its current index must be at least -1 to keep accesses within the flag array. */
int func_020dff20(SaveLoadTaskWork *work)
{
    int i;
    FIELD(s32, work, 0xdc)++;
    for (i = FIELD(s32, work, 0xdc); i < 6; i++) {
        if (((SaveLoadScanView *)((u32)work + i))->flags[0]) {
            FIELD(s32, work, 0xdc) = i;
            return i;
        }
    }
    FIELD(s32, work, 0xdc) = -1;
    return -1;
}

int func_02109f94(u32 *cursor, u32 *count, u32 window, u32 value);
void func_020616ec(SaveLoadTaskWork *work, int value);
/* Original selectors 2/6 prepare the cursor/count pair using words +0xf0/+0xf4
 * before dispatching with three zero flags. Work must expose at least 0xf8 bytes. */
void func_020dfe80(SaveLoadTaskWork *work, u32 selector)
{
    if (selector == 2 || selector == 6) {
        func_020616ec(work, func_02109f94(&FIELD(u32, work, 0x4c),
            &FIELD(u32, work, 0x48), FIELD(u32, work, 0xf0), FIELD(u32, work, 0xf4)));
    }
    func_020dfd9c(work, selector, 0, 0, 0);
}

/* Original loop fills six words at +0x18 with 1..6 and clears +0x34.
 * The caller retains ownership of the writable work block. */
void func_020e0034(SaveLoadTaskWork *work)
{
    int i = 0;
    int value;
    for (value = 1; value <= 5; value++) {
        ((SaveLoadTransitionView *)work)->words[i] = value;
        i++;
    }
    ((SaveLoadTransitionView *)work)->words[i] = 6;
    work->unk_0034 = 0;
}
