/* src/game/unit_020b6570.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

typedef struct Unk0b6570Work {
    u8  pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u8  pad_0010[0x207c];
    u8  model[4];               /* +0x208C  title model/anim set (titleModel.*) */
} Unk0b6570Work;



extern u32 data_02176b88[];
/* decompiler-derived */
u32 Unk0b6570_Get_data_02176b88(void)
{
  return *data_02176b88;
}

int func_020df7c4();
/* decompiler-derived */
void Unk0b6570_Unk_0b65d0(Unk0b6570Work *arg0){
  int tmp1;
  arg0->unk_0008 = 1;
  arg0->unk_000c = 2;
  tmp1 = func_020df7c4();
  if (tmp1 == 0) {
    return;
  }
  arg0->unk_0008 = 2;
  arg0->unk_000c = 3;
  return;
}

int func_02058548();
int func_020588ec();
int func_02058a1c();
/* decompiler-derived */
void Unk0b6570_Unk_0b7838(int arg0)
{
  int tmp1;
  func_02058548();
  tmp1 = 0;
  do {
    func_02058a1c(arg0 + 0x208c,tmp1);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 0x80);
  func_020588ec(arg0 + 0x208c,0);
  func_020588ec(arg0 + 0x208c,1);
  func_020588ec(arg0 + 0x208c,2);
  return;
}

extern char data_021501cc[];
extern char data_021501f0[];   /* titleModel.nsbmd */
extern char data_02150214[];
extern char data_02150238[];
int func_02058528();
int func_02007ad4();
int func_020585a8();
int func_02058854();
int func_0205889c();
int func_02058a64();
int func_02058944();


/* Loads the title-screen 3D model and its animations. */
void func_020b75b0(Unk0b6570Work *w)
{
    u32 i;

    func_02058528(w, data_021501cc);
    func_02007ad4();
    func_020585a8(w);
    func_02058854(w->model);
    func_0205889c(w->model, data_021501f0, 0);
    func_0205889c(w->model, data_02150214, 1);
    func_0205889c(w->model, data_02150238, 2);
    i = 0;
    do {
        func_02058944(w->model, func_02058a64(w->model), w, i, i, 0, 1);
        func_02058944(w->model, func_02058a64(w->model), w, i, i, 1, 1);
        func_02058944(w->model, func_02058a64(w->model), w, i, i, 2, 1);
        i++;
    } while (i < 2);
}
