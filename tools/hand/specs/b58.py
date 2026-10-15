FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_020f470c.c',[
('func_020f4a1c','''void func_020f4a1c(u8 *p, int a, int b)
{
    if (a != 2) {
        return;
    }
    switch (b) {
    case 1:
    case 5:
    case 6:
        FIELD(u32, p, 80) = 1;
        Unk0e8228_Unk_0e8f50(1);
        return;
    }
    FIELD(u32, p, 80) = 0;
    Unk0e8228_Unk_0e8f50(0);
}'''),
],FX+'void Unk0e8228_Unk_0e8f50();'),
('src/game/unit_020f51dc.c',[
('func_020f57d4','''void func_020f57d4(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    func_020f58bc(a, b, c, d, e, 0, 8, 0);
}'''),
],'void func_020f58bc();'),
('src/game/unit_020f7188.c',[
('func_020f7210','''int func_020f7210(u8 *p)
{
    if (FIELD(u32, p, 8) != 10) {
        return 0;
    }
    if (FIELD(u32, p, 20) != 0) {
        return 0;
    }
    return FIELD(int, p, 16) >= FIELD(int, p, 28);
}'''),
],FX),
('src/game/unit_020f7eb4.c',[
('func_020f8034','''void func_020f8034(u8 *p)
{
    if (FIELD(u32, p, 68) == 0) {
        return;
    }
    func_0204af80(p);
    Unk039774_Unk_039b74(3);
    func_02053000(FIELD(u32, p, 116));
    FIELD(u32, p, 116) = 0;
    func_02053000(FIELD(u32, p, 120));
    FIELD(u32, p, 120) = 0;
}'''),
],FX+'void func_0204af80();\nvoid Unk039774_Unk_039b74();\nvoid func_02053000();'),
('src/game/unit_020f81a4.c',[
('func_020f8224','''void func_020f8224(u8 *p, u32 b, u32 c)
{
    Unk0bcef4_Unk_0bcef4(p, b, c, 1);
    Unk0bcef4_Unk_0bd29c(p + 28, p);
    func_020f8264(p);
}'''),
],'void Unk0bcef4_Unk_0bcef4();\nvoid Unk0bcef4_Unk_0bd29c();\nvoid func_020f8264();'),
('src/game/unit_020f8448.c',[
('func_020f8478','''void func_020f8478(u8 *p, u32 a)
{
    func_020bcfc4(p, a);
    func_020bd1a8(p + 28, p, p + 100, 1);
    FIELD(Unk0f8448Fn, p, 148)(p);
}'''),
('func_020f84c0','''u32 func_020f84c0(u8 *p, int i)
{
    if (i < 0 || (int)Unk0f8448_GetUnkField0(p) <= i) {
        return 0;
    }
    return FIELD(u32, p + i * 12, 28);
}'''),
],FX+'typedef void (*Unk0f8448Fn)(u8 *);\nvoid func_020bcfc4();\nvoid func_020bd1a8();'),
('src/game/unit_020f90dc.c',[
('func_020f90dc','''int func_020f90dc(int a, u32 b)
{
    u8 *e;
    int v;
    int r = 0;
    e = (u8 *)func_020cb1a0(b);
    if (a < 0) {
        v = FIELD(s16, Unk02e000_Thunk_0202e788(), 30);
    } else {
        v = FIELD(s16, Unk02e000_GetAreaRecord(a), 32);
    }
    if (v >= e[34]) {
        r = 1;
    }
    return r;
}'''),
],FX+'int func_020cb1a0();\nint Unk02e000_Thunk_0202e788();\nint Unk02e000_GetAreaRecord();'),
('src/game/unit_020fa7e8.c',[
('func_020fb0e0','''int func_020fb0e0(u8 *p, int i)
{
    int r = Unk095560_Unk_0957c0(FIELD(u32, p + i * 4, 16));
    if (r != 0) {
        return r;
    }
    return Unk095560_Unk_0957c0(0x259);
}'''),
],FX+'int Unk095560_Unk_0957c0();'),
('src/game/unit_020fb128.c',[
('func_020fb614','''int func_020fb614(u8 *p)
{
    if (FIELD(s8, p, 0x7400 + 128) != 1) {
        return 1;
    }
    return func_020fb324(p);
}'''),
],FX+'void func_020fd0c8();\nint func_020fb324();'),
('src/game/unit_020fbc74.c',[
('func_020fbd30','''int func_020fbd30(u8 *p)
{
    if (FIELD(u32, p, 0) != 4) {
        return 0;
    }
    if (FIELD(u16, p, 56) == 0) {
        return 1;
    }
    FIELD(u16, p, 56) = 0;
    FIELD(u32, p, 0) = 7;
    Unk0a0ce4_Unk_0a0da4(2);
    return 0;
}'''),
],FX+'void Unk0a0ce4_Unk_0a0da4();'),
]
