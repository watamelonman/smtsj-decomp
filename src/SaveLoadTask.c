#include "types.h"
/* src/SaveLoadTask.c */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

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



/* decompiler-derived */
void func_020e006c(int arg0,u32 arg1,u32 arg2)
{
  *(u32 *)(arg0 + 8) = 8;
  *(u32 *)(arg0 + 0xc) = arg1;
  *(u32 *)(arg0 + 0x10) = arg2;
  return;
}

int func_020dfd9c();
/* decompiler-derived */
void func_020dfed4(u32 arg0,u32 arg1)
{
  func_020dfd9c(arg0,arg1,1,0,0);
  return;
}

extern u8 data_02176bf0[];
/* decompiler-derived */
int func_020df7f8(int arg0)
{
  return *(int *)(((int)data_02176bf0) + arg0 * 0x18) * 3;
}


/* decompiler-derived */
void func_020dffec(int arg0,int arg1)
{
  *(int *)(arg0 + 0x18) = arg1 + 1;
  *(int *)(arg0 + 0x1c) = arg1 + 4;
  *(u32 *)(arg0 + 0x20) = 6;
  *(u32 *)(arg0 + 0x34) = 0;
  return;
}


/* decompiler-derived */
void func_020e0010(int arg0)
{
  *(u32 *)(arg0 + 0x18) = 1;
  *(u32 *)(arg0 + 0x1c) = 2;
  *(u32 *)(arg0 + 0x20) = 6;
  *(u32 *)(arg0 + 0x34) = 0;
  return;
}

extern u8 data_02176c78[];
int func_02053000();
int func_020bc6d4();
/* decompiler-derived */
void func_020e137c(int arg0)
{
  int tmp1;
  func_020bc6d4(1);
  func_02053000(*(u32 *)(arg0 + 0xe8));
  tmp1 = ((int)data_02176c78);
  *(u32 *)(arg0 + 0xe8) = 0;
  *(u32 *)(tmp1 + 4) = 0;
  return;
}
