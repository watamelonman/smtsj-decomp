/* src/StaffRoll.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */

typedef struct StaffRollWork {
    u8  pad_0000[0x4];
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u8  pad_0010[0x4];
    s32 unk_0014;
    s32 unk_0018;
    u8  pad_001c[0x90];
    u32 unk_00ac;
    u8  pad_00b0[0x8];
    u32 unk_00b8;
    s32 unk_00bc;
    s32 unk_00c0;
    s32 unk_00c4;
    u8  pad_00c8[0xc];
    s32 unk_00d4;
    s32 unk_00d8;
    s32 scrollY;                /* +0xDC  starts at 0x1F0, grows per text line */
    s32 unk_00e0;
    u32 firstTextCmd;           /* +0xE4 */
    u8  pad_00e8[0x214];
    struct StaffRollCmd *cmds;  /* +0x2FC */
    u32 cmdCount;               /* +0x300 */
} StaffRollWork;

void StaffRoll_Nop_117cf4(void) { }


/* empty callback */
void StaffRoll_Nop_117cf8(void) { }


/* decompiler-derived */
void StaffRoll_Unk_11825c(int arg0)
{
  ((StaffRollWork *)arg0)->unk_0004 = 0;
  ((StaffRollWork *)arg0)->unk_0008 = 0;
  ((StaffRollWork *)arg0)->unk_000c = 0;
  return;
}



/* decompiler-derived */
void StaffRoll_Unk_1182a4(int arg0)
{
  int tmp1;
  int tmp2;
  tmp2 = arg0 + 0xf8;
  tmp1 = 0;
  do {
    if ((*(int *)(tmp2 + 4) == 1) && (*(int *)(tmp2 + 8) + 0x10 < ((StaffRollWork *)arg0)->unk_00e0)) {
      StaffRoll_Unk_11825c(tmp2);
    }
    tmp1 = tmp1 + 1;
    tmp2 = tmp2 + 0x10;
  } while (tmp1 < 0x20);
  return;
}

int func_02117f94();
int func_021180e4();
int func_02118174();
/* decompiler-derived */
u32 StaffRoll_Unk_1181a0(int arg0)
{
  u32 tmp1;
  tmp1 = 0;
  switch(((StaffRollWork *)arg0)->unk_00ac) {
  case 0:
    if (((StaffRollWork *)arg0)->unk_00b8 <= ((StaffRollWork *)arg0)->unk_0008) {
      ((StaffRollWork *)arg0)->unk_00ac = 3;
    }
    break;
  case 1:
    func_02117f94();
    break;
  case 2:
    func_021180e4();
    break;
  case 3:
    func_02118174();
    break;
  case 4:
    tmp1 = 1;
  }
  return tmp1;
}

/* Staff-roll script entry (20 bytes). */
typedef struct StaffRollCmd {
    u32 type;
    s32 arg[4];
} StaffRollCmd;


int func_02117d5c(StaffRollWork *w, u32 cmd, int line);

/* Parses the staff-roll command list and lays out its text lines. */
void func_0211882c(StaffRollWork *w)
{
    int found = 0;
    int line;
    u32 i;
    StaffRollCmd *c;
    int j;

    w->scrollY = 0x1f0;
    line = 0;
    for (i = 0; i < w->cmdCount; i++) {
        c = &w->cmds[i];
        switch (c->type) {
        case 0:
            break;
        case 1:
            w->unk_0014 = c->arg[0] < 0 ? 0 : c->arg[0];
            w->unk_0018 = c->arg[1] < 1 ? 1 : c->arg[1];
            break;
        case 2:
            w->unk_00b8 = c->arg[0] < 0 ? 0 : c->arg[0];
            w->unk_00bc = c->arg[1] < 1 ? 1 : c->arg[1];
            w->unk_00c0 = c->arg[2] < 1 ? 1 : c->arg[2];
            w->unk_00c4 = c->arg[3] < 1 ? 1 : c->arg[3];
            break;
        case 3:
            w->unk_00d4 = c->arg[0] < 0 ? 0 : c->arg[0];
            w->unk_00d8 = c->arg[1] < 1 ? 1 : c->arg[1];
            break;
        case 4:
            if (!found) {
                w->firstTextCmd = i;
                found = 1;
            }
            for (j = 0; j < c->arg[0]; j++) {
                w->scrollY += func_02117d5c(w, i, line);
                line++;
            }
            break;
        }
    }
}

extern u8 data_0213cc08[];
int func_020572d8();
int func_02057524();
int func_0205789c();
int func_02057df8();
int func_02057e18();
int func_02057e30();
int func_02058d04();
int func_02118518();
int func_02118584();
/* decompiler-derived */
void StaffRoll_Unk_118620(int arg0)
{
  func_02057524(0);
  func_0205789c();
  func_02057df8();
  func_02057e30(0);
  func_02057e18(0x1f);
  if (*(int *)(arg0 + 0xac) == 2) {
    func_02058d04(*(u32 *)(arg0 + 0x9c),0,0,0,0x3f800000,0,0,0);

    func_02058d04(*(u32 *)(arg0 + 0xa0),0,*(u32 *)(data_0213cc08 + 0xc),
                  *(u32 *)(data_0213cc08 + 0x10),0x3f800000,0,0,0);
  }
  func_02118518(arg0);
  func_02118584(arg0,0);
  func_020572d8();
}

extern u8 data_0213cc1c[];
extern u8 data_0213cc30[];
/* decompiler-derived */
void StaffRoll_Unk_1186cc(int arg0)
{
  func_02057524(0);
  func_0205789c();
  func_02057df8();
  func_02057e30(0);
  func_02057e18(0x1f);
  if (*(int *)(arg0 + 0xac) == 2) {
    func_02058d04(*(u32 *)(arg0 + 0xa4),0,*(u32 *)(data_0213cc1c + 0xc),
                  *(u32 *)(data_0213cc1c + 0x10),0x3f800000,0,0,0);

    func_02058d04(*(u32 *)(arg0 + 0xa8),0,*(u32 *)(data_0213cc30 + 0xc),
                  *(u32 *)(data_0213cc30 + 0x10),0x3f800000,0,0,0);
  }
  func_02118518(arg0);
  func_02118584(arg0,1);
  func_020572d8();
}
