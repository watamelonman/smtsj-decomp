/* src/game/unit_0211d520.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11d520Work {
    u8 pad_0000[0x18];
    s32 unk_0018;
    u8 pad_001c[0x8c];
    s32 unk_00a8;
    u8 pad_00ac[0x1c0];
    u32 unk_026c;
    u32 unk_0270;
} Unk11d520Work;




/* decompiler-derived */
u32 Unk11d520_Unk_11da60(Unk11d520Work *arg0){
  return *(u32 *)(arg0->unk_00a8 + arg0->unk_0018 * 4);
}

int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk11d520_Unk_11d520(Unk11d520Work *arg0, u32 arg1, u32 arg2){
  u32 tmp1;
  tmp1 = func_0204fe68(arg0->unk_026c,arg2);
  func_0204fed8(tmp1,arg1);
  return;
}


void func_0205c408();
void func_0205c6e0();
typedef struct Unk11d520Ids {
    u8 pad[180];
    u16 ids[218];
    u32 n;
    u8 pad2[32];
    u32 h[8];
} Unk11d520Ids;
void func_0211d7f4(Unk11d520Ids *p, u32 id)
{
    int i;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (id == p->ids[i]) {
            return;
        }
    }
    p->ids[n] = id;
    p->n++;
}

/* decompiler-derived */
void Unk11d520_Unk_11d838(Unk11d520Work *arg0, u32 arg1){
  u32 tmp1;
  tmp1 = func_0204fe68(arg0->unk_026c,4);
  func_0204fed8(tmp1,arg1);
  return;
}

extern u8 data_02151d18[];
/* decompiler-derived */
int Unk11d520_Unk_11d858(Unk11d520Work *arg0, u32 arg1){
  u32 tmp1;
  int tmp2;
  tmp1 = func_0204fe68(arg0->unk_0270,0);
  tmp2 = func_0204fed8(tmp1,arg1);
  if (tmp2 == 0) {
    tmp2 = ((int)data_02151d18);
  }
  return tmp2;
}

void func_0211dde8(Unk11d520Ids *p, int i, u32 v)
{
    func_0205c408(p->h[i], v);
    func_0205c6e0(p->h[i]);
}
