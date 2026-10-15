/* src/CaveNpc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct CaveNpcWork {
    u8 pad_0000[0x2c];
    s32 unk_002c;
} CaveNpcWork;

void CaveNpc_SetActive(u8 *p, int f)
{
    if (f != 0) {
        if (FIELD(u32, p, 16) != 0) {
            return;
        }
        p[12] = 5;
        FIELD(u32, p, 16) = 1;
    } else {
        FIELD(u32, p, 16) = 0;
    }
}

void CaveNpc_Nop_0fff3c(void) { }

extern u8 data_02151180[];
int func_0205ba98();
/* decompiler-derived */
void CaveNpc_Unk_1000d0(int arg0)
{
  u32 tmp1;
  if (((CaveNpcWork *)arg0)->unk_002c != 0) {
    return;
  }
  tmp1 = func_0205ba98(0x2000,0x200,((int)data_02151180),0x11e);
  ((CaveNpcWork *)arg0)->unk_002c = tmp1;
  return;
}

/* NPC list scroll state; +8 = vertical scroll offset in pixels. */
typedef struct CaveNpcList {
    u8  pad_0000[8];
    s32 scrollY;                /* +0x08 */
} CaveNpcList;

/* Sets the list scroll offset for row `row` of a list with `count` visible rows. */
void func_02100104(CaveNpcList *list, int row, u32 count)
{
    switch (count) {
    case 0:
        break;
    case 1:
        list->scrollY = 0;
        break;
    case 2:
        if (row == 0) {
            list->scrollY = -0x22;
        } else {
            list->scrollY = 0x22;
        }
        break;
    case 3:
        switch (row) {
        case 0:
            list->scrollY = -0x44;
            break;
        case 1:
            list->scrollY = 0;
            break;
        case 2:
            list->scrollY = 0x44;
            break;
        }
        break;
    case 4:
        switch (row) {
        case 0:
            list->scrollY = -0x44;
            break;
        case 1:
            list->scrollY = 0;
            break;
        case 2:
            list->scrollY = 0x44;
            break;
        case 3:
            list->scrollY = 0;
            break;
        }
        break;
    }
}
