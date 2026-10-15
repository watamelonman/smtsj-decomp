SPECS=[
('src/game/unit_020e1648.c',[
('func_020e2db0','''int func_020e2db0(u16 *p)
{
    int a = func_0209993c(p[0]);
    int b = p[1];
    if (func_0209a1e4(p[0]) != 0) {
        return 0;
    }
    return b > a ? 1 : 2;
}'''),
('func_020e2dec','''int func_020e2dec(int x)
{
    switch (x) {
    case 177:
    case 178:
    case 179:
        return 1;
    }
    return 0;
}'''),
('func_020e2f54','''void func_020e2f54(u8 *p)
{
    if (p[3820] == 255) {
        return;
    }
    func_020e3174(p);
    Unk0e1648_Unk_0e51cc((u32)p, 0);
    p[3820] = 255;
}'''),
('func_020e4c64','''int func_020e4c64(u8 *p, u32 x)
{
    if (((u8 *)func_020f3de8(FIELD(u32, p, 104)))[3] == 0) {
        return 0;
    }
    return Unk0f3db4_Unk_0f4510(FIELD(u32, p, 104), x) != 0;
}'''),
('func_020e536c','''void func_020e536c(u8 *p)
{
    FIELD(u32, p, 3816) = 1;
    FIELD(u32, p, 3776) = FIELD(u32, p, 3780);
    func_020e5394(p);
    p[0] = 7;
}'''),
],'void Unk0e1648_Unk_0e51cc(u32 arg0, u32 arg1);\nint func_0209a1e4();\nvoid func_020e3174();\nint Unk0f3db4_Unk_0f4510();\nvoid func_020e5394();'),
('src/ImageBg.c',[
('func_020e5638','''void func_020e5638(void)
{
    if (data_02176ca4[1] == 0) {
        return;
    }
    data_02176ca4[1] = 0;
    func_0205bb68();
    Unk0e7290_Unk_0e7734();
}'''),
],'#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\nextern u8 data_02150bd4[];\nu32 func_0205ba98();\nvoid func_0205bb68();\nvoid Unk0e7290_Unk_0e7734();'),
('src/game/unit_020e5fb8.c',[
('func_020e60b4','''u32 func_020e60b4(u32 a, int b, int n)
{
    u32 bits = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (Unk094fe0_TestBit(a, b + i) != 0) {
            bits |= 1 << i;
        }
    }
    return bits;
}'''),
('func_020e6100','''void func_020e6100(int a, int n, u32 bits)
{
    int i;
    for (i = 0; i < n; i++) {
        Unk094fe0_Call_0209502c(a + i, (bits >> i) & 1);
    }
}'''),
('func_020e620c','''void func_020e620c(u32 a, u32 b)
{
    Unk0e5fb8_Unk_0e622c(Unk094fe0_Thunk_0202e8cc(), a, b);
}'''),
('func_020e62e0','''int func_020e62e0(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffset900(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}'''),
],''),
]
