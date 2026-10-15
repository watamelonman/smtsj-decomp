/* src/game/unit_020f7eb4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

typedef struct Unk0f7eb4Work {
    u8  pad_0000[0x44];
    u32 unk_0044;               /* +0x44  set to 1 on load */
    u32 unk_0048;
    u32 unk_004c;
    u32 unk_0050;
    u8  unk_0054;
    u8  pad_0055[0x1f];
    u32 bfData;                 /* +0x74  loaded Data/Battle/Event/%s.bf */
    u32 mbbData;                /* +0x78  loaded Data/Battle/Event/%s.mbb */
    u32 unk_007c;
    u32 unk_0080;
    u32 unk_0084;
} Unk0f7eb4Work;




/* decompiler-derived */
void Unk0f7eb4_Unk_0f8078(Unk0f7eb4Work *arg0){
  arg0->unk_0048 = 0;
  arg0->unk_004c = 0;
  arg0->unk_0050 = 0;
  arg0->unk_0084 = 0xffffffff;
  arg0->unk_0054 = 0;
  return;
}


/* decompiler-derived */
u32 Unk0f7eb4_Unk_0f7eb4(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 7;
  case 1:
    return 8;
  case 2:
    return 0;
  case 3:
    return 1;
  case 4:
    return 2;
  case 5:
    return 3;
  case 6:
    return 5;
  case 7:
    return 6;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    return 4;
  case 0x13:
    return 0xf;
  }
  return 0x12;
}

extern char data_02150e64[];
extern char data_02150e7c[];
extern char data_02150e98[];
extern char data_02150ea4[];
int func_02013c3c();
int func_0204ae84();
int func_0204aecc();
int func_0204af70();
int func_02051610();
int func_02015118();
int func_0204fdac();
int func_0204fde0();
int func_0204fe18();


/* Loads battle event script `name` (Data/Battle/Event/%s.bf / .mbb). */
void func_020f7f68(Unk0f7eb4Work *w, char *name, u32 arg2, u32 arg3)
{
    char path[64];
    int msg;

    w->unk_0044 = 1;
    func_02013c3c(path, data_02150e64, name);
    func_0204ae84(w);
    func_0204aecc(w, path, 3);
    func_0204af70(w, w);
    func_02013c3c(path, data_02150e7c, name);
    w->bfData = func_02051610(path);
    func_02013c3c(path, data_02150ea4, name + func_02015118(data_02150e98));
    w->mbbData = func_02051610(path);
    msg = func_0204fdac(w->mbbData, 0);
    w->unk_007c = func_0204fde0();
    w->unk_0080 = func_0204fe18(msg);
    Unk0f7eb4_Unk_0f8078(w);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_0204af80();
void Unk039774_Unk_039b74();
void func_02053000();
void func_020f8034(u8 *p)
{
    if (FIELD(u32, p, 68) == 0) {
        return;
    }
    func_0204af80(p);
    Unk039774_Unk_039b74(3);
    func_02053000(FIELD(u32, p, 116));
    FIELD(u32, p, 116) = 0;
    func_02053000(FIELD(u32, p, 120));
    FIELD(u32, p, 120) = 0;
}
