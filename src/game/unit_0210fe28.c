/* Work state and resource operations for this unit. */
#include "types.h"

/* Private layout; the ten handles at 0x28 are initialized and released together. */
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



u32 func_0204fe68(u32 handle, int index);
u32 func_0204fed8(u32 handle, u32 index);
/* Resolve the selected entry through the resource stored at 0x18. */
void Unk10fe28_Unk_10fe28(Unk10fe28Work *arg0){
  u32 tmp1;
  tmp1 = func_0204fe68(arg0->unk_0018,1);
  func_0204fed8(tmp1,arg0->unk_0008);
  return;
}

void func_02053000(u32 handle);
void func_0210ff80(Unk10fe28Work *w);
/* Release this work state before releasing its owning resource. */
void Unk10fe28_Unk_1113e0(Unk10fe28Work *arg0){
  func_0210ff80(arg0);
  func_02053000(arg0->unk_0018);
  arg0->unk_0018 = 0;
  return;
}

extern u32 data_02151438[];
extern u8 data_021514b0[];
extern u8 data_02151540[];
extern u8 data_02151548[];
extern u8 data_02151550[];
void Unk02e000_Unk_02e0cc(void);
void func_0205ad2c(u32 a);
void Unk05b82c_CreateEntry(void *a);
u32 func_0205c2c4(void *a);
u32 func_0205c3c0(void);
void func_0205c3fc(u32 a, u32 b, u32 c);
u32 func_0205dcd4(void *a, int b);
void func_02061e98(u32 a, int b, int c);
void func_02061f10(u32 a, int b, int c, int d, u32 e);
u32 func_020629ac(int a, int b, int c, int d);
void Unk065e88_Unk_065e88(void);
void Unk05b82c_Unk_05b82c(int a);

/* Initialize the resource handles and ten entries owned by this work state. */

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
        Unk05b82c_CreateEntry(p);
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

    Unk02e000_Unk_02e0cc();
    Unk05b82c_Unk_05b82c(0x39);
    w->unk_0024 = func_0205dcd4(data_02151550, 1);

}

void Unk10fe28_Unk_110048(Unk10fe28Work *w, int i, u32 v);
void func_0205c408(u32 handle, u32 value);
void func_0205c6e0(u32 handle);
void func_0205c704(u32 handle);
extern s16 data_0213ca70[];
/* Set and refresh entry i; callers supply an index within the ten handles. */
void Unk10fe28_Unk_110048(Unk10fe28Work *w, int i, u32 v)
{
    func_0205c408(w->unk_0028[i], v);
    func_0205c6e0(w->unk_0028[i]);
}

/* Assign the initial values to entries zero through seven. */
void Unk10fe28_Unk_110074(Unk10fe28Work *w)
{
    int i;
    Unk10fe28_Unk_110048(w, 0, 0);
    Unk10fe28_Unk_110048(w, 1, 2);
    for (i = 2; i <= 7; i++) {
        Unk10fe28_Unk_110048(w, i, 6);
    }
}

/* Apply the operation to four entries selected by the signed index table. */
void Unk10fe28_Unk_1102d4(Unk10fe28Work *w)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0205c704(w->unk_0028[data_0213ca70[i]]);
    }
}

void func_0205ddb4(u32 handle);
void func_0205bb68(void);
void func_020629c4(u32 handle);
void func_0205c3dc(u32 handle);
void func_0205c368(u32 handle);
void Unk065e88_Unk_065eac(void);

/* Release owned handles, clearing each slot so it cannot be reused accidentally. */
void func_0210ff80(Unk10fe28Work *w)
{
    int i;
    u32 n;
    if (w->unk_0024 != 0) {
        func_0205ddb4(w->unk_0024);
        w->unk_0024 = 0;
    }
    func_0205bb68();
    func_020629c4(w->unk_0050);
    w->unk_0050 = 0;
    func_020629c4(w->unk_0054);
    w->unk_0054 = 0;
    for (i = 0; i < 10; i++) {
        if (w->unk_0028[i] != 0) {
            func_0205c3dc(w->unk_0028[i]);
            w->unk_0028[i] = 0;
        }
    }
    if (w->unk_000c == 1) {
        Unk065e88_Unk_065eac();
    }
    if (w->unk_001c != 0) {
        func_0205ddb4(w->unk_001c);
        w->unk_001c = 0;
    }
    if (w->unk_0020 != 0) {
        func_0205c368(w->unk_0020);
        w->unk_0020 = 0;
    }
    for (n = 0; n < 6; n++) {
        func_0205bb68();
    }
}

extern s16 data_0213ca88[];
void func_02057ddc(u32 value);
void func_02057df8(void);
void func_0205de40(int mode, u32 handle, int entry, int x, int y,
                   float scaleX, float scaleY, int z, float scaleZ, int flags);

/* Process six table entries, omitting entry four in mode one and marking selection. */
void func_02110f08(Unk10fe28Work *w, int selected)
{
    u32 i;
    func_02057ddc(0xaddeffff);
    for (i = 0; i < 6; i++) {
        if (w->unk_000c == 1 && data_0213ca88[i] == 4) {
            continue;
        }
        if (selected) {
            if (w->unk_0008 == i) {
                func_02057ddc(~0x3900U);
            } else {
                func_02057ddc(0xaddeffff);
            }
        }
        func_0205de40(2, w->unk_001c, data_0213ca88[i], 0, 0,
                       1.0f, 1.0f, 0, 1.0f, 5);
    }
    func_02057df8();
}
