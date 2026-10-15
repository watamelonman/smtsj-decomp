/* src/game/unit_0209d060.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void Unk09d060_Unk_09d060(int *arg0)
{
  *arg0 = *arg0 + 1;
}

extern u32 data_02176274[];
/* decompiler-derived */
void Unk09d060_Clear_data_02176274(void)
{
  *data_02176274 = 0;
}


typedef struct Unk09d060Ctx {
    u32 unk_00;
} Unk09d060Ctx;

u32 Unk09d060_GetCtxUnk00(void)
{
    Unk09d060Ctx *c = *(Unk09d060Ctx **)data_02176274;
    if (c != 0) {
        return c->unk_00;
    }
    return 0;
}

/* decompiler-derived */
void Unk09d060_Unk_09d1b0(void)
{
  if ((u32 *)*data_02176274 != (u32 *)0x0) {
    *(u32 *)*data_02176274 = 0;
  }
}

int func_02061424();
int func_020d1d4c();
/* decompiler-derived */
void Unk09d060_Unk_09d10c(void)
{
  if (*data_02176274 != 0) {
    func_02061424();
    *data_02176274 = 0;
  }
  func_020d1d4c();
}

