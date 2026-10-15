/* src/game/unit_020d1c98.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0d1c98Work {
    u8 pad_0000[0x4];
    u32 unk_0004;
} Unk0d1c98Work;



int func_020d1da4();
/* decompiler-derived */
void Unk0d1c98_Unk_0d1d94(u32 arg0,u32 arg1)
{
  func_020d1da4(arg0,arg1,0);
  return;
}

int func_020629c4();
/* decompiler-derived */
void Unk0d1c98_Unk_0d1c98(Unk0d1c98Work *arg0){
  func_020629c4(arg0->unk_0004);
  arg0->unk_0004 = 0;
  return;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern Unk0d1c98Work *data_02176bdc;
void func_02061424();
void Unk0d1c98_Release(void)
{
    if (data_02176bdc == 0) {
        return;
    }
    func_020629c4(data_02176bdc->unk_0004);
    data_02176bdc->unk_0004 = 0;
    func_02061424(data_02176bdc);
    data_02176bdc = 0;
}
