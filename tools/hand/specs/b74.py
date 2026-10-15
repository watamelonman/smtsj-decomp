FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_0202f078.c',[
('func_0202f190','''int func_0202f190(int a, int b)
{
    if (a == 0) {
        return 1;
    }
    if (b == 0) {
        return 0;
    }
    switch (a) {
    case 2:
        return 1;
    case 5:
        if (b != 2) {
            return 1;
        }
        break;
    case 1:
        if (b == 3 || b == 4) {
            return 1;
        }
        break;
    case 3:
        if (b == 4) {
            return 1;
        }
        break;
    }
    return 0;
}'''),
],''),
('src/game/unit_0202f2a8.c',[
('func_0202f2dc','''u32 func_0202f2dc(int i)
{
    u8 *w = (u8 *)Unk02e000_Unk_02e774();
    switch (i) {
    case 1: return FIELD(u32, w + 0x6000, 312);
    case 2: return FIELD(u32, w + 0x6000, 316);
    case 3: return FIELD(u32, w + 0x6000, 320);
    }
    return 0;
}'''),
('func_02030198','''int func_02030198(u8 *p)
{
    if (func_0204b4c4(p) == 0) {
        return 0;
    }
    switch (func_0204ca1c()) {
    case 0:
    case 1:
    case 2:
        FIELD(u32, p, 32) = 1;
        return 1;
    case 5:
        FIELD(u32, p, 40) = 1;
        return 1;
    case 4:
        FIELD(u32, p, 44) = 1;
        return 1;
    }
    return 0;
}'''),
('func_02030294','''void func_02030294(u8 *p)
{
    FIELD(s32, p, 16) = FIELD(s32, p, 20);
    FIELD(s32, p, 20) = -1;
    switch (FIELD(s32, p, 16)) {
    case 0:
        break;
    case 1:
        FIELD(u32, p, 92) = 1;
        FIELD(u32, p, 80) = 1;
        break;
    case 2:
        func_0202f3d8(p);
        break;
    case 3:
        Unk02f2a8_Unk_02f8ac((int)p);
        break;
    case 4:
        Unk02f2a8_Unk_02fc10((int)p);
        break;
    }
}'''),
('func_0203034c','''void func_0203034c(u8 *p)
{
    u8 *w1;
    u8 *w2;
    if (FIELD(s32, p, 20) != -1) {
        if (func_0204b710() == 1 || func_0204ca1c() == -1) {
            func_02030294(p);
        }
    }
    Unk02f2a8_Unk_0302f4((int)p);
    Unk02f2a8_Unk_02f378((int)p);
    w1 = (u8 *)Unk02e000_GetWorkArea();
    w2 = (u8 *)Unk02e000_GetWorkArea();
    func_0209aca0(FIELD(u32, p, 0), FIELD(s8, w1 + 0x300, 100), FIELD(s8, w2 + 0x300, 101));
    func_02116598();
}'''),
],FX+'int func_0204b4c4();\nint func_0204ca1c();\nint func_0204b710();\nvoid func_0202f3d8();\nvoid func_0209aca0();\nvoid func_02116598();\nvoid func_02030294(u8 *p);\nvoid Unk02f2a8_Unk_02fc10(int arg0);\nvoid Unk02f2a8_Unk_02f8ac(int arg0);\nvoid Unk02f2a8_Unk_0302f4(int arg0);\nvoid Unk02f2a8_Unk_02f378(int arg0);\n'),
]
