SPECS=[('src/game/unit_0202e000.c',[
('func_0202e440','''int func_0202e440(int x)
{
    if (x - 3 < 0) {
        return 0;
    }
    if (x - 11 < 0) {
        return 1;
    }
    if (x - 31 < 0) {
        return 2;
    }
    return 3;
}'''),
('func_0202e5a8','''int func_0202e5a8(void)
{
    return func_02008848(Unk02e000_Unk_02e884(), 0, 0x1148);
}'''),
('func_0202e7c0','''u8 *func_0202e7c0(int i)
{
    u8 *w = Unk02e000_GetWorkArea();
    s8 idx = (w + i + 0x300)[0x54];
    u8 *r = 0;
    if (idx >= 0) {
        r = w + 0x74 + idx * 60;
    }
    return r;
}'''),
('func_0202e7f4','''int func_0202e7f4(u8 *p)
{
    u8 *e;
    int i;
    if (p == 0) {
        return -1;
    }
    e = Unk02e000_GetWorkArea() + 0x74;
    for (i = 0; i < 12; i++) {
        if (e == p) {
            return i;
        }
        if (e[58] == p[58]) {
            return i;
        }
        e += 60;
    }
    return -1;
}'''),
('func_0202e840','''int func_0202e840(u8 *p)
{
    int idx = func_0202e7f4(p);
    s8 *arr = (s8 *)(Unk02e000_GetWorkArea() + 0x354);
    int i;
    for (i = 0; i < 3; i++) {
        if (arr[i] >= 0 && idx == arr[i]) {
            return 1;
        }
    }
    return 0;
}'''),
('func_0202e904','''int func_0202e904(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return FIELD(u16, p, 0x36) != 0;
}'''),
('func_0202e924','''int func_0202e924(int i)
{
    if (i < 0) {
        return 0;
    }
    if (i >= 90) {
        return 0;
    }
    if ((Unk02e000_GetWorkArea() + (i >> 3))[0x374] & (u8)(1 << (i & 7))) {
        return 1;
    }
    return 0;
}'''),
],'')]
