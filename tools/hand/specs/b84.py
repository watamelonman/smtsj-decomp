G = 'FIELD(u8 *, data_0215ee60, 52)'
SPECS=[
('src/game/unit_0203e43c.c',[
('func_02041ce4','''void func_02041ce4(u8 *p)
{
    func_020516d0(FIELD(u32, p, 12));
    func_020516d0(FIELD(u32, p + 0x2000, 2228));
    func_020516d0(FIELD(u32, p + 0x2000, 2232));
    func_020516d0(FIELD(u32, p + 0x2000, 2236));
    if (FIELD(s32, data_0215ee60, 48) == 1) {
        func_0204b6d0();
    }
    func_020629c4(FIELD(u32, p + 0x2000, 2444));
    if (FIELD(u32, p + 0x2000, 2444) != 0) {
        FIELD(u32, p + 0x2000, 2444) = 0;
    }
    FIELD(u32, data_0215ee60, 48) = 0;
    FIELD(u32, data_0215ee60, 52) = 0;
}'''),
('func_02043450','''void func_02043450(s16 *x, s16 *y)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    *x = 128 - ((s8)(FIELD(s8, w + 0x300, 100) - GameState_GetUnkField74f4()) << 3);
    w = (u8 *)Unk02e000_GetWorkArea();
    *y = 96 - ((s8)(FIELD(s8, w + 0x300, 101) - GameState_GetUnkField74f6()) << 3);
}'''),
('func_02043560','''int func_02043560(void)
{
    int n = 0;
    int i;
    for (i = 0; i < 37; i++) {
        if (Unk02f078_TestFlag380(i) != 0) {
            n++;
        }
    }
    if (n > 20) {
        return 48;
    }
    if (n > 16) {
        return 24;
    }
    if (n > 12) {
        return 23;
    }
    if (n > 8) {
        return 22;
    }
    if (n > 4) {
        return 21;
    }
    return 20;
}'''),
('func_02044194','''void func_02044194(u8 *p)
{
    u16 *t;
    int i;
    for (i = 0; i < 7; i++) {
        FIELD(u8, p + i + 0x2000, 2434) = 0;
    }
    t = (u16 *)Unk03e43c_Unk_03f2ac(0);
    for (i = 0; i <= 3; i++) {
        t[i + 1] = 0x73f5;
    }
    Unk03e43c_MergeTable((u8 *)t);
    Unk03e43c_Call_02056cc0();
}'''),
('func_020441ec','''void func_020441ec(void)
{
    FIELD(u8, %s + 0x2000, 2438) = 0;
    FIELD(u8, %s + 0x2000, 2439) = 0;
    FIELD(u32, %s + 0x2000, 2252) = 0;
    func_02044194(%s);
    Unk04bb9c_SetCtxUnka14(-1);
    FIELD(u8, %s + 0x2000, 2275) = 0;
    FIELD(u32, %s, 4) = 0;
    FIELD(u32, %s, 16) = 0;
    FIELD(u32, %s + 0x2000, 2244) = 0;
}''' % ((G,)*8)),
],'void func_020629c4();\nint GameState_GetUnkField74f4();\nint GameState_GetUnkField74f6();\nint Unk02f078_TestFlag380();\nvoid Unk04bb9c_SetCtxUnka14();\nvoid func_02044194(u8 *p);\nvoid Unk03e43c_MergeTable(u8 *src);\nvoid Unk03e43c_Call_02056cc0(void);\n'),
]
