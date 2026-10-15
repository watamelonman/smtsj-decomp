/* src/game/unit_020fd5a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020572d8();
int func_02057eb8();
typedef struct Unk0fd5a4Obj {
    u8 pad_0000[0x2c];
    s32 state;                  /* +0x2C */
} Unk0fd5a4Obj;

void func_020fd71c(Unk0fd5a4Obj *o);

void Unk0fd5a4_Unk_0fd6ec(Unk0fd5a4Obj *o)
{
    if (o->state == 0) {
        return;
    }
    func_020fd71c(o);
}

void Unk0fd5a4_Unk_0fd704(Unk0fd5a4Obj *o)
{
    if (o->state == 1) {
        return;
    }
    func_020fd71c(o);
}

/* decompiler-derived */
void Unk0fd5a4_Unk_0fd9dc(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
}

int func_02057524();
int func_02057ddc();
int func_02057e18();
int func_020580ec();
/* decompiler-derived */
void Unk0fd5a4_Unk_0fd9b4(void)
{
  func_020580ec(0);
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057524(4);
}

extern u32 data_02176e1c[];
int func_0205bb68();
int func_0205ddb4();
/* decompiler-derived */
void Unk0fd5a4_Unk_0fd5a4(int *arg0)
{
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  func_0205bb68();
  func_0205bb68();
  *data_02176e1c = 0;
}
