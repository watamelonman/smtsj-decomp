FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
O = 'FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232)'
SPECS=[
('src/game/unit_0203aae8.c',[
('func_0203b634','''int func_0203b634(void)
{
    int r;
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    u8 *o = %s;
    r = 0;
    switch (FIELD(s32, o, 8)) {
    case 0:
        r = Unk094fe0_Unk_094fec(FIELD(u32, o, 64));
        break;
    case 2:
        break;
    }
    Unk094fe0_SetSlot(r, a, b);
    return 1;
}''' % O),
('func_0203b694','''int func_0203b694(void)
{
    int r;
    s16 a = func_0203ac00(0);
    u8 *o = %s;
    r = 0;
    switch (FIELD(s32, o, 8)) {
    case 0:
        r = (s16)Unk094fe0_GetSlot(Unk094fe0_Unk_094fec(FIELD(u32, o, 64)), a);
        break;
    case 2:
        break;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}''' % O),
('func_0203b6ec','''int func_0203b6ec(void)
{
    s16 a = func_0203ac00(0);
    u8 *o = %s;
    switch (FIELD(s32, o, 8)) {
    case 0:
        func_0209512c(Unk094fe0_Unk_094fec(FIELD(u32, o, 64)), a, 1);
        break;
    case 1:
        FIELD(u32, o, 64) |= 1 << a;
        break;
    case 2:
        break;
    case 3:
        FIELD(u32, o, 64) |= 1 << a;
        break;
    }
    return 1;
}''' % O),
],FX+'int Unk094fe0_Unk_094fec();\nvoid Unk094fe0_SetSlot();\nint Unk094fe0_GetSlot();\nvoid func_0209512c();\nu32 Unk03aae8_Unk_03ad14(void);\n'),
('src/game/unit_0203b988.c',[
('func_0203bb2c','''int func_0203bb2c(void)
{
    func_0203ac00(0);
    func_0203ac00(1);
    func_0203ac00(2);
    func_0203ac00(3);
    func_0203ac00(4);
    if (func_020baba4() != 0) {
        Unk03aae8_Unk_03acf4(Unk11fc20_Unk_11fc94());
        Unk11fc20_Unk_11fc48();
        func_020babc8();
        return 1;
    }
    func_020babb4();
    Unk03aae8_Unk_03acf4(0);
    Unk11fc20_Unk_11fc20();
    {
        u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
        FIELD(u32, o, 24) = 27;
    }
    return 0;
}'''),
],FX+'int func_020baba4();\nint Unk11fc20_Unk_11fc94();\nvoid Unk11fc20_Unk_11fc48();\nvoid func_020babc8();\nvoid func_020babb4();\nvoid Unk11fc20_Unk_11fc20();\nu32 Unk03aae8_Unk_03ad14(void);\n'),
('src/game/unit_0203bba4.c',[
('func_0203bda0','''int func_0203bda0(void)
{
    if (func_0206552c() != 0) {
        return 0;
    }
    if (ImageObj_Unk_077688() == 0) {
        return 0;
    }
    if (Unk09d42c_Unk_09e274() == 0) {
        return 0;
    }
    if (Unk02e000_GetSlot(1) == 1) {
        ImageBg_Unk_0e54d4(Unk02e000_GetSlot(0));
        Unk02e000_SetSlot(1, 0);
    }
    if (ImageBg_IsMode1or2() == 1) {
        return 0;
    }
    return 1;
}'''),
],'int func_0206552c();\nint ImageObj_Unk_077688();\nint Unk09d42c_Unk_09e274();\nint Unk02e000_GetSlot();\nvoid ImageBg_Unk_0e54d4();\nvoid Unk02e000_SetSlot();\nint ImageBg_IsMode1or2();\n'),
]
