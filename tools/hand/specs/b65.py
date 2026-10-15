FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_020ddeb0.c',[
('func_020ddf0c','''void func_020ddf0c(u32 a)
{
    u16 t[1] = {0};
    func_02061f10(a, -1, 0, 0, t);
}'''),
],'void func_02061f10();'),
('src/game/unit_021159f8.c',[
('func_02115bcc','''int func_02115bcc(int x)
{
    int r = 0;
    if (x == func_02035b08(8, 3)) {
        r = 1;
    }
    return r;
}'''),
],'int func_02035b08();'),
('src/game/unit_02116360.c',[
('func_02116360','''int func_02116360(int a, int b, int c)
{
    int r = 0;
    if (Unk03e43c_Unk_03fa28() == 0) {
        if (a == func_02035b08(8, 6) && b == 36 && c == 18) {
            r = 1;
        }
    }
    return r;
}'''),
],'int func_02035b08();'),
('src/game/unit_02116598.c',[
('func_02117808','''void func_02117808(void)
{
    u8 *w = (u8 *)*data_02176e64;
    FIELD(u32, w, 0) = 0;
    FIELD(u32, w, 16) = 0;
    FIELD(u32, w, 20) = 0;
    Unk095560_Unk_0958a8(0, 0);
}'''),
],FX+'int Unk0de678_Unk_0dee2c();\nint Unk02e000_Unk_02e774();\nint Unk02f078_Unk_02f220();\nint func_02117208();\nint func_02051ba4();\nvoid Unk095560_Unk_0958a8();'),
('src/StaffRoll.c',[
('func_02117cfc','''u32 func_02117cfc(u16 *p)
{
    u32 v = 0;
    if (*p == 0x8082) {
        v = *p;
    }
    return v;
}'''),
('func_02117d18','''u32 func_02117d18(u8 *p)
{
    u16 *q = (u16 *)func_0204fed8(FIELD(u32, p, 772));
    if (q == 0) {
        return 0;
    }
    return func_02117cfc(q);
}'''),
('func_02117d38','''int func_02117d38(u16 *p)
{
    if (func_02117cfc(p) == 0x8082) {
        return 0x739cd6ff;
    }
    return -1;
}'''),
],'int func_0204fed8();\nu32 func_02117cfc(u16 *p);'),
]
