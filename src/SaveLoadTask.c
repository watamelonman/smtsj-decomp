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
void func_020de678(u32 palette);
void func_02057534(void);
void func_02057df8(void);
void func_02057e18(int a);
void func_02057fd8(void);
void func_0205c748(int screen, void *obj, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_0205dee8(int screen, u32 obj, int frame, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_02060b60(int screen, u32 obj, int x, int y, int z, int prio);

/* Per-frame draw/update of the save/load screen. */
void func_020e1144(SaveLoadTask *task) {
    if (task->visible) {
        func_020580ec(0);
        func_02057524(0);
        func_020de678(task->palette);
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
