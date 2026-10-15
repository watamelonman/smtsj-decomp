SPECS=[
('src/game/unit_0206a224.c',[
('func_0206ab64','''void func_0206ab64(void)
{
    Unk06a224Msg m;
    int i;
    CampStatus_Copy12c();
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[1] = 11;
    m.flags[0] |= 2;
    func_020bcbc4(3, &m);
}'''),
('func_0206ac54','''void func_0206ac54(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 20;
    m.w[6] = 1;
    m.flags[0] |= 0x82;
    m.flags[0] |= 0x40;
    func_020bcbc4(3, &m);
}'''),
('func_0206accc','''void func_0206accc(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 10;
    m.flags[0] |= 0x82;
    func_020bcbc4(3, &m);
}'''),
('func_0206ad40','''void func_0206ad40(void)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[3] = 12;
    m.w[1] = 11;
    m.flags[0] |= 10;
    func_020bcacc(3, &m);
    func_020bc9f4(11, 0);
    CampStatus_SetUnk1a8(0);
}'''),
('func_0206adc0','''void func_0206adc0(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 25;
    m.flags[0] |= 0x82;
    func_020bcbc4(3, &m);
}'''),
],'void func_020bcbc4();\nvoid func_020bcacc();\nvoid func_020bc9f4();\nvoid CampStatus_SetUnk1a8();\nvoid CampStatus_Copy12c();\n'),
]
