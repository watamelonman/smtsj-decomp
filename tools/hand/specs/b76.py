FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_0202f2a8.c',[
('func_02034970','''u8 *func_02034970(u8 *p, int x, int y)
{
    u8 *r = p + 572;
    u8 *o = (u8 *)func_02039160(r, x, y);
    u32 n;
    if (o != 0) {
        n = (FIELD(u32, o, 4) << 12) >> 28;
        if (n != 0) {
            s8 k = FIELD(s8, p + (n - 1), 48);
            if (k >= 0 && Unk0e5fb8_Unk_0e63c8(k) != 0) {
                r = p + 712;
            }
        }
    }
    return r;
}'''),
('func_020349c4','''int func_020349c4(u8 *p, int x, int y)
{
    int r = FIELD(u16, (u8 *)Unk02e000_GetWorkArea() + 0x300, 92);
    u8 *o = (u8 *)func_02039160(p + 572, x, y);
    u32 n;
    if (o != 0) {
        n = (FIELD(u32, o, 4) << 12) >> 28;
        if (n != 0) {
            s8 k = FIELD(s8, p + (n - 1), 48);
            if (k >= 0) {
                int m = Unk0e5fb8_Unk_0e63c8(k);
                if (m > 0) {
                    r = (m - 1) + (k * 2 + 90);
                }
            }
        }
    }
    return r;
}'''),
('func_02034b24','''int func_02034b24(void)
{
    u8 *g = (u8 *)gGameState;
    u8 *q;
    if (FIELD(u32, g + 0x7000, 992) == 1) {
        return 0;
    }
    if (FIELD(u32, g + 0x7000, 968) != 2) {
        return 0;
    }
    q = FIELD(u8 *, g, 0);
    if (FIELD(u32, q, 16) != 1) {
        return 0;
    }
    return FIELD(u32, q, 4) != 0;
}'''),
('func_020351b4','''int func_020351b4(int x, int y)
{
    int r;
    int n;
    u8 *g;
    g = (u8 *)gGameState;
    if (g == 0) {
        return 0;
    }
    if (FIELD(u32, g, 576) == 0) {
        return 0;
    }
    r = 0;
    n = Unk02f2a8_Unk_034a8c(func_02034970(g + 4, x, y), x, y);
    if (n > 0) {
        r = func_020987ac(3, FIELD(u8, FIELD(u8 *, g, 580) + n, 15));
    }
    return r;
}'''),
('func_0203550c','''int func_0203550c(void *dst, u32 n, int key)
{
    int r = 0;
    void *h;
    void *t;
    func_02008644(r, dst, n * 2);
    h = func_0204459c(38);
    if (h != 0) {
        t = func_0204fed8(func_0204fe68(h, r), key);
        if (t != 0) {
            if (n >= 5) {
                n = 5;
            }
            func_0200866c(t, dst, n * 2);
            r = 1;
        }
    }
    return r;
}'''),
('func_02035820','''int func_02035820(int a)
{
    void *h = func_020445d0(36, 0);
    u8 *t = func_0204fde0();
    u32 n = func_0204fe18(h);
    int r = 0;
    u8 i;
    for (i = 0; i < n; i++) {
        u8 *e = t + i * 40;
        if (e[24] == 1 && a == (s8)e[25]) {
            r = i;
            break;
        }
    }
    return r;
}'''),
('func_02035b08','''int func_02035b08(int a, int b)
{
    int r;
    u32 i;
    u32 n;
    u8 *t;
    void *h = func_020445d0(36, 0);
    t = func_0204fde0();
    n = func_0204fe18(h);
    r = 0;
    for (i = 0; i < n; i++, t += 40) {
        if (a == (s8)t[25] && b == (s8)t[26]) {
            r = i;
            break;
        }
    }
    return r;
}'''),
],FX+'int func_020987ac();\nvoid func_02008644();\nvoid *func_0204459c();\nvoid *func_0204fe68();\nvoid *func_0204fed8();\nvoid func_0200866c();\nu32 func_0204fe18();\nu8 *func_02034970(u8 *p, int x, int y);\n'),
]
