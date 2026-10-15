FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_0202f2a8.c',[
('func_02035b74','''int func_02035b74(int a)
{
    void *h = func_020445d0(36, 0);
    u8 *t = func_0204fde0();
    u32 n = func_0204fe18(h);
    int r = 0;
    u8 i;
    for (i = 0; i < n; i++) {
        if (a == (s8)(t + i * 40)[25]) {
            r++;
        }
    }
    return r;
}'''),
],FX),
('src/game/unit_020387bc.c',[
('func_020387bc','''int func_020387bc(u32 a)
{
    u8 buf[64] = {0};
    func_02015134(buf, data_02141f98[2]);
    func_0201524c(buf, a);
    return func_02051610(buf);
}'''),
],'extern u32 data_02141f98[];\nvoid func_02015134();\nvoid func_0201524c();\nint func_02051610();\n'),
('src/game/unit_02038fbc.c',[
('func_02039160','''u8 *func_02039160(u8 **o, int x, int y)
{
    u8 *h;
    int dx, dy;
    if (o == 0) {
        return 0;
    }
    h = o[0];
    if (h != 0) {
        dx = x - h[8];
        dy = y - h[9];
        if (dx >= 0 && dx < h[10] && dy >= 0 && dy < h[11]) {
            return o[2] + (h[10] * dy + dx) * 8;
        }
    }
    return 0;
}'''),
],''),
('src/game/unit_020392f8.c',[
('func_020394b8','''u8 *func_020394b8(u8 **o, int x, int y)
{
    u8 *h;
    int dx, dy;
    if (o == 0) {
        return 0;
    }
    h = o[0];
    if (h != 0) {
        dx = x - h[9];
        dy = y - h[10];
        if (dx >= 0 && dx < h[11] && dy >= 0 && dy < h[12]) {
            return o[4] + (h[11] * dy + dx) * 2;
        }
    }
    return 0;
}'''),
],''),
('src/game/unit_02039774.c',[
('func_02039774','''void func_02039774(u8 *n)
{
#define l ((u8 *)&data_0215de28)
    if (FIELD(u8 *, l, 8) == 0) {
        FIELD(u8 *, l, 0) = n;
        FIELD(u8 *, l, 8) = n;
        FIELD(u32, n, 224) = 0;
        FIELD(u32, n, 228) = 0;
    } else {
        FIELD(u8 *, n, 224) = FIELD(u8 *, l, 8);
        FIELD(u8 *, FIELD(u8 *, l, 8), 228) = n;
        FIELD(u32, n, 228) = 0;
        FIELD(u8 *, l, 8) = n;
    }
    FIELD(u32, l, 4) = FIELD(u32, l, 4) + 1;
#undef l
}'''),
],FX+'extern u8 *data_0215de28;\n'),
]
