#include "types.h"

/* Private 292-byte callback state; field offsets follow 02122abc's stores. */
typedef struct Unk122a78Work {
    u32 unk_000;
    u32 mode;
    u32 resource_008, resource_00c;
    u32 objects[17];
    u32 resource_054, resource_058, object_05c;
    u8 unk_060, unk_061, pad_062[2];
    s32 unk_064, count, unk_06c, unk_070, unk_074;
    u32 active[7], handles[7];
    s32 unk_0b0, unk_0b4, unk_0b8, unk_0bc, unk_0c0, unk_0c4;
    u32 active2[6], handles2[6], values2[6];
    s32 unk_110, unk_114, unk_118, last_frame;
    float frame_step;
} Unk122a78Work;

typedef void (*Unk122a78Callback)(Unk122a78Work *);
extern Unk122a78Work *func_020611dc(Unk122a78Callback, Unk122a78Callback,
    Unk122a78Callback, Unk122a78Callback, u32, u32, u32, u32);
extern void func_021236b4(Unk122a78Work *);
extern void func_02123bc8(Unk122a78Work *);
extern void func_02122e1c(Unk122a78Work *);
extern u32 func_020cb3dc(void);
extern u32 func_0205dcd4(const char *, u32);
extern u32 func_0205c2c4(const char *);
extern u32 func_0205c3c0(void);
extern void func_0205c3fc(u32, u32, u32);
extern void func_0205caa8(u32, u32);
extern void func_0205c41c(u32, u32);
extern s32 func_0205ca88(u32);
extern s32 func_02117170(void);
extern u32 func_020629ac(u32, u32, u32, u32);
extern void Unk0cb32c_Unk_0cb504(u32, u8, u8);
extern const char data_02152054[], data_0215206c[], data_02152084[], data_02152094[];
extern u32 data_0213cd70[];
extern void Unk05b82c_Unk_05b82c(s32 id);
extern void func_0205bb68(void);

/* Submit the three table IDs in order; evidence: 02122a78's indexed loads. */
void Unk122a78_Unk_122a78(void)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        Unk05b82c_Unk_05b82c(data_0213cd70[i]);
    }
}

/* Invoke 0205bb68 three times; 02122aa0 supplies no arguments or results. */
void Unk122a78_Unk_122aa0(void)
{
    u32 i = 0;
    do {
        func_0205bb68();
        i++;
    } while (i < 3);
}

/* Allocate callback-owned state and initialize its resources and handle groups.
 * Evidence: 02122abc passes size 292 to 020611dc and configures IDs 100..115.
 * Allocation is assumed successful, as in the original; caller receives the state.
 */
Unk122a78Work *func_02122abc(void)
{
    Unk122a78Work *w;
    s32 i;
    w = func_020611dc(func_021236b4, func_02123bc8, 0, func_02122e1c,
        sizeof(Unk122a78Work), 1, 0, 1);
    w->mode = func_020cb3dc();
    w->resource_008 = func_0205dcd4(data_02152054, 1);
    w->resource_00c = func_0205c2c4(data_0215206c);
    w->resource_054 = func_0205dcd4(data_02152084, 1);
    w->resource_058 = func_0205c2c4(data_02152094);
    for (i = 0; i < 17; i++) {
        w->objects[i] = func_0205c3c0();
        func_0205c3fc(w->objects[i], w->resource_008, w->resource_00c);
    }
    w->object_05c = func_0205c3c0();
    func_0205c3fc(w->object_05c, w->resource_054, w->resource_058);
    func_0205caa8(w->object_05c, 0);
    func_0205c41c(w->object_05c, 0);
    w->unk_060 = 0;
    w->unk_061 = 0;
    w->unk_064 = 0;
    w->unk_06c = -91;
    w->unk_070 = 0;
    w->unk_074 = 0;
    w->unk_0b0 = 0;
    w->unk_0b8 = -91;
    w->unk_0bc = 0;
    w->unk_0c0 = 0;
    w->unk_0c4 = 0;
    w->unk_110 = 1;
    w->unk_114 = 0;
    w->unk_118 = 0;
    switch (w->mode) {
    case 0: w->count = 5; w->unk_0b4 = 4; break;
    case 1: w->count = 5; w->unk_0b4 = 4; break;
    case 2: w->count = 3; w->unk_0b4 = 4; break;
    case 3: w->count = 5; w->unk_0b4 = 6; break;
    case 4:
        func_02117170();
        w->count = 3; w->unk_0b4 = 4; break;
    }
    func_0205caa8(w->objects[15], 3);
    w->last_frame = func_0205ca88(w->objects[15]) - 1;
    w->frame_step = 1.0f / (float)w->last_frame;
    func_0205caa8(w->objects[16], 2);
    w->unk_118 = func_0205ca88(w->objects[16]);
    if (w->mode == 4 && func_02117170() == 0) {
        for (i = 0; i < w->count; i++) {
            w->handles[i] = func_020629ac(4, 1, 1, 1);
            w->active[i] = 1;
        }
        Unk0cb32c_Unk_0cb504(w->handles[0], 4, 100);
        Unk0cb32c_Unk_0cb504(w->handles[1], 4, 101);
        Unk0cb32c_Unk_0cb504(w->handles[2], 4, 102);
    } else {
        for (i = 0; i < w->count; i++) {
            w->handles[i] = func_020629ac(4, 1, 1, 1);
            Unk0cb32c_Unk_0cb504(w->handles[i], w->mode, i + 100);
            w->active[i] = 1;
        }
    }
    for (i = 0; i < 6; i++) {
        w->handles2[i] = func_020629ac(4, 1, 1, 1);
        Unk0cb32c_Unk_0cb504(w->handles2[i], w->mode, i + 110);
        w->active2[i] = 1;
        w->values2[i] = 0;
    }
    return w;
}
