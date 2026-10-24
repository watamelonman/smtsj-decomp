typedef unsigned int u32;
typedef unsigned char u8;

/* Borrowed work object; only fields observed in this draw callback are exposed. */
typedef struct Unk099494Work {
    u32 unk_00;
    u8 pad_04[12];
    void *unk_10;
    u32 unk_14;
    u8 pad_18[40];
    u32 unk_40;
    u8 unk_44;
} Unk099494Work;

void func_02057524(int mode);
void func_020580ec(int enabled);
void func_02057df8(void);
void func_02057e18(int value);
void func_02057fd8(void);
u32 func_02059c70(u32 id, int dimension);
void func_02058e9c(u32 mode, u32 id, int x, int y, float scale, int flags, int depth);
void func_02058f10(u32 mode, u32 id, int x, int y, u32 width, u32 height, int depth);
void func_02057e30(int value);
void func_02060b60(u32 mode, void *text, int x, int y, int flags, int depth);
void func_020572d8(void);

/* Draw the centered three-part strip and optional payload. Evidence: the original
 * calls the dimension query with IDs 0x5f80..0x5f82, then the sprite and text
 * helpers. The caller owns work and its payload; unknown semantics retain names. */
void func_02099494(Unk099494Work *work)
{
    int x;
    u32 a, b, c, d;
    if (!work->unk_00 || !work->unk_10 || !work->unk_40 || !work->unk_44) {
        return;
    }
    func_02057524(4);
    func_020580ec(0);
    func_02057df8();
    func_02057e18(work->unk_44);
    func_02057fd8();
    x = 128 - (work->unk_40 >> 1);
    a = func_02059c70(0x5f80, 2);
    if (a + func_02059c70(0x5f81, 2) < work->unk_40) {
        func_02058e9c(0x4000001, 0x5f80, x,
            107 + (func_02059c70(0x5f80, 3) >> 1), 1.0f, 0, 20);
        x += func_02059c70(0x5f80, 2);
        a = func_02059c70(0x5f80, 3);
        b = func_02059c70(0x5f80, 2);
        c = func_02059c70(0x5f81, 2);
        d = func_02059c70(0x5f82, 3);
        func_02058f10(0x4000001, 0x5f82, x, 107 + (a >> 1),
            work->unk_40 - (b + c), d, 20);
        a = func_02059c70(0x5f80, 2);
        b = func_02059c70(0x5f81, 2);
        c = work->unk_40 - (a + b);
        d = func_02059c70(0x5f80, 3);
        func_02058e9c(0x4004001, 0x5f81, x + c, 107 + (d >> 1), 1.0f, 0, 20);
    } else {
        a = func_02059c70(0x5f80, 3);
        b = func_02059c70(0x5f80, 3);
        func_02058f10(0x4000001, 0x5f80, x, 107 + (a >> 1), work->unk_40 >> 1, b, 20);
        x += work->unk_40 >> 1;
        a = func_02059c70(0x5f80, 3);
        b = func_02059c70(0x5f81, 3);
        func_02058f10(0x4004001, 0x5f81, x, 107 + (a >> 1), work->unk_40 >> 1, b, 20);
    }
    func_02057e30(0);
    func_02057e18(31);
    if (work->unk_14 == 3) {
        a = func_02059c70(0x5f80, 3);
        func_02060b60(0x5000001, work->unk_10, 128, 107 + (a >> 1), 0, 21);
    }
    func_020580ec(1);
    func_020572d8();
}
