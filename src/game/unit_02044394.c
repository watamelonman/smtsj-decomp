/* src/game/unit_02044394.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02051610();
int func_02052fe0();
int func_0205f460();
int func_0205f4b0();
/* decompiler-derived */
void Unk044394_Unk_044394(u32 *arg0)
{
  int value1;
  u32 value2;
  if ((arg0[3] != 0) && (value1 = func_0205f460(*arg0), value1 != 0)) {
    value2 = func_02052fe0();
    arg0[1] = value2;
    value1 = func_0205f4b0(*arg0,arg0[1],value1);
    if (value1 != 0) {
      return;
    }
  }
  value2 = func_02051610(*arg0);
  arg0[1] = value2;
}

extern u8 data_0214283c[];
int Unk044394_HasEntry(int i)
{
    int ok;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    return FIELD(u32, data_0214283c + i * 16, 4) != 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u8 data_0214283c[];
void Unk044394_Unk_044394(u32 *arg0);
void func_02053000();

int func_02044428(int i)
{
    int ok;
    u8 *e;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    e = data_0214283c + i * 16;
    if (FIELD(u32, e, 4) != 0) {
        return 1;
    }
    if (FIELD(u32, e, 8) != 0) {
        return 0;
    }
    Unk044394_Unk_044394((u32 *)e);
    return 1;
}

int func_02044534(int i)
{
    int ok;
    u8 *e;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    e = data_0214283c + i * 16;
    if (FIELD(u32, e, 4) == 0) {
        return 1;
    }
    if (FIELD(u32, e, 8) != 0) {
        return 0;
    }
    func_02053000(FIELD(u32, e, 4));
    FIELD(u32, e, 4) = 0;
    return 1;
}
