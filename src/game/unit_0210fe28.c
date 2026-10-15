/* src/game/unit_0210fe28.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

typedef struct Unk10fe28Work {
    u8  pad_0000[0x8];
    u32 unk_0008;
    s32 unk_000c;
    u8  pad_0010[0x8];
    u32 unk_0018;
    u32 unk_001c;
    u32 unk_0020;
    u32 unk_0024;
    u32 unk_0028[10];
    u32 unk_0050;
    u32 unk_0054;
} Unk10fe28Work;



int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk10fe28_Unk_10fe28(Unk10fe28Work *arg0){
  u32 tmp1;
  tmp1 = func_0204fe68(arg0->unk_0018,1);
  func_0204fed8(tmp1,arg0->unk_0008);
  return;
}

int func_02053000();
int func_0210ff80();
/* decompiler-derived */
void Unk10fe28_Unk_1113e0(Unk10fe28Work *arg0){
  func_0210ff80();
  func_02053000(arg0->unk_0018);
  arg0->unk_0018 = 0;
  return;
}

extern u32 data_02151438[];
extern u8 data_021514b0[];
extern u8 data_02151540[];
extern u8 data_02151548[];
extern u8 data_02151550[];
void func_0202e0cc(void);
void func_0205ad2c(u32 a);
void func_0205b8c8(void *a);
u32 func_0205c2c4(void *a);
u32 func_0205c3c0(void);
void func_0205c3fc(u32 a, u32 b, u32 c);
u32 func_0205dcd4(void *a, int b);
void func_02061e98(u32 a, int b, int c);
void func_02061f10(u32 a, int b, int c, int d, u32 e);
u32 func_020629ac(int a, int b, int c, int d);
void Unk065e88_Unk_065e88(void);
void Unk05b82c_Unk_05b82c(int a);

/* Config screen (Data/Tex/Config/) object. */

void func_0210fe48(Unk10fe28Work *w)
{
    s32 i;
    u32 n;
    u8 *p;
    u32 font;

    func_0205ad2c(*data_02151438);
        n = 0;
    p = data_021514b0;
    do {
        func_0205b8c8(p);
        n++;
        p += 0x18;
    } while (n < 6);
    w->unk_001c = func_0205dcd4(data_02151540, 1);
    w->unk_0020 = func_0205c2c4(data_02151548);
    w->unk_0050 = func_020629ac(3, 1, 0, 1);
    func_02061e98(w->unk_0050, 0x10, 1);
    font = func_0204fed8(func_0204fe68(w->unk_0018, 1), 10);
    func_02061f10(w->unk_0050, -1, 0, 0, font);
    w->unk_0054 = func_020629ac(5, 2, 0, 1);
    func_02061e98(w->unk_0054, 0x10, 1);
    if (w->unk_000c == 1) {
        Unk065e88_Unk_065e88();
    }
    for (i = 0; i < 10; i++) {
        w->unk_0028[i] = func_0205c3c0();
        func_0205c3fc(w->unk_0028[i], w->unk_001c, w->unk_0020);
    }

    func_0202e0cc();
    Unk05b82c_Unk_05b82c(0x39);
    w->unk_0024 = func_0205dcd4(data_02151550, 1);

}
