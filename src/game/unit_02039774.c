/* src/game/unit_02039774.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk039774Work {
    u8 pad_0000[0xd4];
    s32 unk_00d4;
    s32 unk_00d8;
    s32 unk_00dc;
} Unk039774Work;

int func_020399f4();
/* decompiler-derived */
void Unk039774_Unk_039b00(u32 arg0)
{
  func_020399f4(arg0,0);
}

int func_020397cc();
int func_02053000();
/* decompiler-derived */
void Unk039774_Unk_039b10(int arg0)
{
  if (((Unk039774Work *)arg0)->unk_00d8 != 0) {
    func_02053000();
    ((Unk039774Work *)arg0)->unk_00d8 = 0;
  }
  if (((Unk039774Work *)arg0)->unk_00dc != 0) {
    func_02053000();
    ((Unk039774Work *)arg0)->unk_00dc = 0;
  }
  if (((Unk039774Work *)arg0)->unk_00d4 != 0) {
    func_02053000();
    ((Unk039774Work *)arg0)->unk_00d4 = 0;
  }
  func_020397cc(arg0);
  func_02053000(arg0);
}

extern u8 *data_0215de28;
void Unk039774_Unk_039b10(int arg0);
void func_02039b74(u32 key)
{
    u8 *o = data_0215de28;
    u8 *next;
    if (o == 0) {
        return;
    }
    do {
        next = FIELD(u8 *, o, 0xe4);
        if (FIELD(u32, o, 0xf4) == key) {
            Unk039774_Unk_039b10((int)o);
        }
        o = next;
    } while (o != 0);
}
