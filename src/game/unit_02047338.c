/* src/game/unit_02047338.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020b8078();
/* decompiler-derived */
u32 Unk047338_Unk_047470(u16 *arg0)
{
  int value;
  func_020b8078();
  ScanVisor_Unk_0a29c4(0xffffffff);
  Unk044904_Unk_045080();
  value = Unk0f81a4_Unk_0f81b4();
  if (value != 0) {
    *arg0 = 2;
  }
  return 2;
}

int func_020aa224();
int func_020aa264();
/* decompiler-derived */
u32 Unk047338_Unk_047504(u16 *arg0)
{
  int value;
  Unk044904_Unk_044fd8();
  value = func_020aa264();
  if (value != 0) {
    Unk044904_Unk_044fd8();
    func_020aa224();
    *arg0 = 2;
  }
  return 2;
}

int func_02045ca8();
int func_02047534(s16 *st)
{
    if (st[1] != 0) {
        st[0] = 2;
    } else if (func_02045ca8() != 0) {
        st[0] = 2;
    }
    return 2;
}
