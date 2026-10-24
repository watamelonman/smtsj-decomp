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


int Unk02cad4_GetUnk00();
void SaveLoadTask_Unk_0df814(void);
int Unk124c5c_IsKind0();
/* decompiler-derived */
void SaveLoadTask_Unk_0df94c(void)
{
  u32 tmp1;
  int tmp2;
  tmp1 = Unk02cad4_GetUnk00();
  switch(tmp1) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    goto LAB_020df988;
  case 6:
    goto LAB_020df988;
  case 7:
    goto LAB_020df988;
  case 8:
    goto LAB_020df988;
  case 9:
LAB_020df988:
    tmp2 = Unk124c5c_IsKind0();
    if (tmp2 != 0) {
      return;
    }
  }
  SaveLoadTask_Unk_0df814();
  return;
}

int func_0205257c();
int Unk124c5c_Set_124d8c();
/* decompiler-derived */
void SaveLoadTask_Unk_0df86c(void)
{
  u32 tmp1;
  tmp1 = Unk02cad4_GetUnk00();
  switch(tmp1) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    goto LAB_020df8a8;
  case 6:
    goto LAB_020df8a8;
  case 7:
    goto LAB_020df8a8;
  case 8:
    goto LAB_020df8a8;
  case 9:
LAB_020df8a8:
    Unk124c5c_Set_124d8c(1,0);
    return;
  }
  func_0205257c(3);
  return;
}

int func_0204faf0();
int func_020dff20();
/* decompiler-derived */
u32 SaveLoadTask_Unk_0dff68(u32 arg0)
{
  int tmp1;
  u32 tmp2;
  tmp1 = func_020dff20();
  if (tmp1 < 0) {
    return 0;
  }
  tmp2 = 0xd;
  switch(tmp1) {
  case 0:
    tmp2 = 0xc;
    break;
  case 1:
    goto LAB_020dffb0;
  case 2:
    goto LAB_020dffc0;
  case 3:
    break;
  case 4:
LAB_020dffb0:
    func_0204faf0(1,1);
    break;
  case 5:
LAB_020dffc0:
    func_0204faf0(1,2);
  }
  func_020dfd9c((SaveLoadTaskWork *)arg0,tmp2,1,0,0);
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

int func_020525cc();
/* decompiler-derived */
void SaveLoadTask_Unk_0df814(void)
{
  u32 tmp1;
  tmp1 = Unk02cad4_GetUnk00();
  switch(tmp1) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    goto LAB_020df850;
  case 6:
    goto LAB_020df850;
  case 7:
    goto LAB_020df850;
  case 8:
    goto LAB_020df850;
  case 9:
LAB_020df850:
    Unk124c5c_Set_124d8c(0,0x1f);
    return;
  }
  func_020525cc(3);
}
