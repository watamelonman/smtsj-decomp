#include "types.h"

/* Layout follows the shared counter/state and three handle accesses in this TU. */
typedef struct Unk115ca0Work {
    int frame;
    int state;
    u8 unk_08[8];
    void *unk_10;
    void *unk_14;
    void *unk_18;
} Unk115ca0Work;

extern void func_020a4f3c(void);
extern void func_0205c704(void *handle);
extern int func_02049350(int id);
extern void Unk0d1c98_Unk_0d1d94(int id, int value);
extern void Unk0a0ce4_Unk_0a0da4(int value);
extern void func_020a4eb0(int a, int b, int c);
extern int Unk0a50d4_Unk_0a50d4(void);
extern int func_0205ca48(void *handle);
extern void func_02052634(int a, int b, int c);
extern int func_02052728(void);
extern void func_02061424(Unk115ca0Work *work);
extern void func_02057524(int value);
extern void func_020580ec(int value);
extern void func_02057df8(void);
extern void func_0205789c(void);
extern void func_02057e18(u8 value);
extern void func_02057ddc(u32 value);
extern void func_02057b50(int x, int y, int width, int height, int layer);
extern void func_0205c748(int a, void *handle, int x, int y, float sx, float sy, int c, float alpha, int layer);
extern void func_02057534(void);

/* Advances the seven-state sequence; counters are frames, and handles remain owned by work. */
void func_02115ca0(Unk115ca0Work *work)
{
    func_020a4f3c();
    func_0205c704(work->unk_10);
    work->frame++;
    switch (work->state) {
    case 0:
        if (work->frame >= 32) {
            work->state++;
            work->frame = 0;
            Unk0d1c98_Unk_0d1d94(func_02049350(7), 224);
        }
        break;
    case 1:
        if (work->frame >= 30) {
            work->state++;
            work->frame = 0;
            Unk0a0ce4_Unk_0a0da4(20);
        }
        break;
    case 2:
        if (work->frame >= 30) {
            work->state++;
            work->frame = 0;
        }
        break;
    case 3:
        if (work->frame >= 180) {
            work->state++;
            work->frame = 0;
            func_020a4eb0(2, 0, 1);
        }
        break;
    case 4:
        Unk0a50d4_Unk_0a50d4();
        func_0205c704(work->unk_14);
        if (work->frame >= 50) {
            work->state++;
            work->frame = 0;
        }
        break;
    case 5:
        func_0205c704(work->unk_18);
        if (func_0205ca48(work->unk_18) == 0) {
            work->state++;
            work->frame = 0;
            func_02052634(1, 3, 32);
        }
        break;
    case 6:
        if (Unk0a50d4_Unk_0a50d4() == 0 && func_02052728() == 0)
            func_02061424(work);
        break;
    }
}

/* Draws the state-dependent handles, with a 30-frame alpha ramp in state 2. */
void func_02115e20(Unk115ca0Work *work)
{
    if (work->state == 6)
        return;
    func_02057524(7);
    func_020580ec(0);
    func_02057df8();
    switch (work->state) {
    case 0:
        func_0205789c();
        {
            int value = 31 - work->frame;
            if (value > 0) {
                func_02057e18((u8)value);
                func_02057ddc(0xbe1616ff);
                func_02057b50(0, 0, 256, 192, 5);
            }
        }
        break;
    case 1:
        break;
    case 2:
        {
            float alpha = 1.0f;
            if (work->state == 2)
                alpha = (1.0f / 30.0f) * work->frame;
            func_0205c748(2, work->unk_10, 0, 0, 1.0f, 1.0f, 0, alpha, 5);
        }
        break;
    default:
        func_0205c748(2, work->unk_10, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        if (work->state >= 4)
            func_0205c748(2, work->unk_14, 0, 0, 1.0f, 1.0f, 0, 1.0f, 6);
        if (work->state >= 5)
            func_0205c748(2, work->unk_18, 0, 0, 1.0f, 1.0f, 0, 1.0f, 6);
        break;
    }
    func_020580ec(1);
    func_02057534();
}
