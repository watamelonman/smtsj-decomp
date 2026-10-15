SPECS=[('src/game/unit_0202f2a8.c',[
('func_02035c14','''int func_02035c14(int i, int j)
{
    Unk02f2a8Res36 *e = &UNK02F2A8_RES36()[i];
    s8 v = e->unk_001b[j];
    int r = 0;
    if (v >= 0) {
        r = Unk0e5fb8_Unk_0e63c8(v);
    }
    return r;
}'''),
('func_02035c5c','''int func_02035c5c(int x, int y)
{
    if (x < 0) {
        return 0;
    }
    if (x >= 45) {
        return 0;
    }
    if (y < 0) {
        return 0;
    }
    return y < 40;
}'''),
('func_02035c90','''int func_02035c90(int x, int y)
{
    if (func_02035c5c(x, y) == 0) {
        return 0;
    }
    return y * 45 + x;
}'''),
('func_020360d8','''int func_020360d8(int dir)
{
    switch (dir) {
    case 1:
        return 0;
    case 2:
        return 0x4000;
    case 3:
        return 0x8000;
    case 0:
        return 0xc000;
    }
    return 0;
}'''),
('func_020362c8','''int func_020362c8(u32 id)
{
    u8 *w;
    if (id >= 90) {
        return 0;
    }
    w = (u8 *)Unk02e000_GetWorkArea();
    FIELD(u16, w, 0x35c) = id;
    if (Unk02e000_TestFlag(FIELD(u16, w, 0x35c)) != 0) {
        return 0;
    }
    func_0202e968(FIELD(u16, w, 0x35c), 1);
    return 1;
}'''),
('func_02036318','''int func_02036318(int x, int y, u32 v)
{
    u8 *w;
    if (func_02035c5c(x, y) == 0) {
        return 0;
    }
    w = (u8 *)Unk02e000_GetWorkArea();
    FIELD(s8, w, 0x364) = x;
    FIELD(s8, w, 0x365) = y;
    FIELD(s8, w, 0x366) = x;
    FIELD(s8, w, 0x367) = y;
    FIELD(u32, w, 0x358) = v;
    return 1;
}'''),
],'''int Unk0e5fb8_Unk_0e63c8();
int Unk02e000_TestFlag();
void func_0202e968();''',[('void func_02036318();\n','int func_02036318();\n'),('void func_020362c8();\n','int func_020362c8();\n')]),
('src/game/unit_020387bc.c',[
('func_02038d94','''u8 *func_02038d94(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[1]) <= i) {
        return 0;
    }
    return (u8 *)p[2] + i * 32;
}'''),
('func_02038dc4','''u8 *func_02038dc4(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[3]) <= i) {
        return 0;
    }
    return (u8 *)p[4] + i * 36;
}'''),
],'u32 func_0204fe18();')]
