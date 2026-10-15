/* src/game/unit_02111400.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk111400Work {
    u8 pad_0000[0x18];
    u32 unk_0018;
} Unk111400Work;




/* decompiler-derived */
int Unk111400_Unk_112254(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

extern u8 data_02151560[];
int func_02051610();
/* decompiler-derived */
void Unk111400_Unk_111458(Unk111400Work *arg0){
  u32 tmp1;
  tmp1 = func_02051610(((int)data_02151560));
  arg0->unk_0018 = tmp1;
  return;
}

int func_0201fba8();
int func_0208dc78();
int func_0208f020();
int func_0208f038();
int func_0208f044();
/* decompiler-derived */
u32 Unk111400_Unk_111508(u32 arg0,u32 arg1,u32 arg2)
{
  func_0208f020();
  func_0208f044(arg0,arg1,arg2);
  func_0208f038();
  func_0201fba8();
  func_0208dc78();
  return 0;
}

extern u32 data_02176e4c[];
extern u8 data_02151580[];
/* decompiler-derived */
void Unk111400_Unk_111474(u32 arg0,u16 arg1,u32 arg2)
{
  u32 *v1;
  u16 *v2;
  v2 = (u16 *)(data_02151580);
  v1 = data_02176e4c;
  *data_02176e4c = arg0;
  *v2 = arg1;
  v1[1] = arg2;
}
