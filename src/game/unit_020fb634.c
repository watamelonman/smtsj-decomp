#include "game/unit_020fb634.h"

s32 func_0205c704(u32 anim);
void func_0205c408(u32 anim, int seq);
void func_0205c6e0(u32 anim);
int func_02052728(void);
void Unk0d297c_Unk_0d33ac(void *list);
void Unk0d297c_Unk_0d3308(void *list);
void func_020d2c44(void *list, s32 arg);
u32 CampStatus_GetUnkField1c(void *list);
int CampStatus_Unk_0d34e4(void *list, int index);
void func_02063920(void);
int func_02063a30(int entry);
void func_02061f10(u32 handle, int a, int b, int c, int d);
int func_02060f40(u32 handle);

/*
 * Per-frame update of a paged list screen (see docs/functions/game-unit-020fb634.md).
 * States 0-3 play the three intro animations in turn, state 4 waits for the selected
 * source (unk_002c) to change, states 5-7 rebuild the list and fill one page of up to
 * 10 rows, and state 8 waits on the output handle before going back to state 4.
 */
void func_020fb634(Unk0fb634Work *w)
{
    func_0205c704(w->unk_004c);
    switch (w->state) {
    case 0:
        if (func_02052728() != 0) {
            return;
        }
        w->state = 1;
        func_0205c408(w->unk_0040, 5);
        func_0205c6e0(w->unk_0040);
        break;
    case 1:
        if (func_0205c704(w->unk_0040) != 0) {
            return;
        }
        func_0205c408(w->unk_0044, 6);
        func_0205c6e0(w->unk_0044);
        w->state = 2;
        break;
    case 2:
        if (func_0205c704(w->unk_0044) != 0) {
            return;
        }
        func_0205c408(w->unk_0048, 4);
        func_0205c6e0(w->unk_0048);
        w->state = 3;
        break;
    case 3:
        if (func_0205c704(w->unk_0048) == 0) {
            w->state = 4;
        }
        break;
    case 5:
        w->unk_0038 = 0;
        if (w->unk_0028 > 0) {
            Unk0d297c_Unk_0d33ac(w->list);
        }
        w->state++;
        /* fallthrough */
    case 6:
        Unk0d297c_Unk_0d3308(w->list);
        func_020d2c44(w->list, w->unk_0028);
        w->unk_003c = CampStatus_GetUnkField1c(w->list);
        w->state++;
        if (w->unk_003c <= 10) {
            w->unk_0050 = 0;
        } else {
            w->unk_0050 = 1;
        }
        break;
    case 7: {
        int last = 0;
        int rows;
        int i;
        func_02063920();
        rows = last; /* the ROM copies the zero from last (mov r6, r5) */
        for (i = w->unk_0038; i < w->unk_003c; i++) {
            last = func_02063a30(CampStatus_Unk_0d34e4(w->list, (u16)i));
            if (++rows >= 10) {
                break;
            }
        }
        if (last != 0) {
            func_02061f10(w->unk_0030, -1, 0, 0, last);
        }
        if (w->unk_003c - w->unk_0038 <= 10) {
            w->unk_0050 = 0;
        } else {
            w->unk_0050 = 1;
        }
        w->state++;
        break;
    }
    case 8:
        if (func_02060f40(w->unk_0030) == 0) {
            return;
        }
        w->state = 4;
        /* fallthrough */
    case 4:
        if (w->unk_0028 != w->unk_002c) {
            w->unk_0028 = w->unk_002c;
            w->state = 5;
        }
        break;
    }
}
