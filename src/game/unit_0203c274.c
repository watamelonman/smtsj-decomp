/* src/game/unit_0203c274.c: script command handlers (read args via func_0203ac00). */
#include "game/unit_0203c274.h"

/* Object returned by Unk03aae8_Unk_03ad14; only the pointer at +0xE8 is used here. */
typedef struct Unk03c274Owner {
    u8 pad_0000[0xe8];
    void *unk_00e8;
} Unk03c274Owner;

Unk03c274Owner *Unk03aae8_Unk_03ad14(void);
int func_0203ac00(int idx);
void func_020fd190(u32 rgba, int a, int b);
void Unk02dcfc_Unk_02df00(void *w, s16 v);
int func_02095818(void);
void Unk09e96c_Unk_09e9cc(void);
void Unk09e96c_Unk_09e96c(u8 id, int on);
void Unk0de678_Unk_0df4f0(void);
void Unk0de678_Unk_0df4cc(u8 id, int on);
void Unk116598_Unk_1166f4(void);
void Unk116598_Thunk_021177e0(u8 id, int on);
void Unk116598_Thunk_02117808(void);
void Unk116598_Unk_117950(u8 id, int on);
void ImageBgDual3D_Thunk_02117808(void);
void ImageBgDual3D_Thunk_021177e0(u8 id, int on);
void Unk0a0ce4_Unk_0a0da4(int se);
void Unk0caea8_Unk_0caf98(int v);

/* Script command: reads a BGR555 colour and two byte args (a, b), converts the colour to RGBA8888
 * (alpha 0xFF) and passes it on with a and b; b is clamped to 2 when a <= 10. Then hands (a + 1) * b
 * to the owner's +0xE8 object. Skipped entirely when b is 0. Returns 3 like other wait-style handlers. */
int func_0203c274(void)
{
    void *w = Unk03aae8_Unk_03ad14()->unk_00e8;
    u16 color = func_0203ac00(0);
    u8 a = func_0203ac00(1);
    u8 b = func_0203ac00(2);
    if (b != 0) {
        u8 r, g, bl;
        if (a <= 10 && b >= 3) {
            b = 2;
        }
        r = (color >> 10) & 0x1f;
        g = (color >> 5) & 0x1f;
        bl = color & 0x1f;
        func_020fd190((((r << 3) << 24) & 0xff000000) + (((g << 3) << 16) & 0xff0000) + (((bl << 3) << 8) & 0xff00) + 0xff, a, b);
        Unk02dcfc_Unk_02df00(w, (s16)((a + 1) * b));
    }
    return 3;
}

/* Script command: reads an id and an on/off flag and calls the mode-specific routine for the current
 * mode (func_02095818): id 0 calls the mode's no-arg variant, otherwise the (id, flag != 0) one.
 * Mode 1 does nothing. */
int func_0203c320(void)
{
    u8 id = func_0203ac00(0);
    s16 on = func_0203ac00(1);
    switch (func_02095818()) {
    case 0:
        if (id == 0) {
            Unk09e96c_Unk_09e9cc();
        } else {
            Unk09e96c_Unk_09e96c(id, on != 0);
        }
        break;
    case 1:
        break;
    case 2:
        if (id == 0) {
            Unk0de678_Unk_0df4f0();
        } else {
            Unk0de678_Unk_0df4cc(id, on != 0);
        }
        break;
    case 3:
        if (id == 0) {
            Unk116598_Unk_1166f4();
        } else {
            Unk116598_Thunk_021177e0(id, on != 0);
        }
        break;
    case 4:
        if (id == 0) {
            Unk116598_Thunk_02117808();
        } else {
            Unk116598_Unk_117950(id, on != 0);
        }
        break;
    case 5:
        if (id == 0) {
            ImageBgDual3D_Thunk_02117808();
        } else {
            ImageBgDual3D_Thunk_021177e0(id, on != 0);
        }
        break;
    }
    return 1;
}

/* Script command: forwards arg 0 to Unk0a0ce4_Unk_0a0da4; arg 1 is read and ignored. */
int Unk03c274_Unk_03c434(void)
{
    int se = func_0203ac00(0);
    func_0203ac00(1);
    Unk0a0ce4_Unk_0a0da4(se);
    return 1;
}

/* Script command: forwards arg 0 to Unk0caea8_Unk_0caf98. */
int Unk03c274_Unk_03c45c(void)
{
    Unk0caea8_Unk_0caf98(func_0203ac00(0));
    return 1;
}
