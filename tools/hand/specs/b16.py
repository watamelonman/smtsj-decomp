SPECS=[
('src/game/unit_02044904.c',[
('func_02046468','''int func_02046468(s16 *st)
{
    Unk044904Mgr *m = UNK044904_MGR();
    FIELD(u16, m, 0x38)++;
    FIELD(u32, m, 0x40) &= ~0x10000;
    st[0] = 2;
    return 1;
}'''),
('func_0204661c','''int func_0204661c(s16 *st)
{
    if (st[1] == 1) {
        st[0] = 2;
    } else {
        func_02045bd0(0);
    }
    return 2;
}'''),
('func_02046644','''int func_02046644(void)
{
    if (UNK044904_MGR()->flag_0040_16 && Unk044904_Unk_045460(1) != 0) {
        return 2;
    }
    func_020456d8(0);
    func_020455cc(2);
    return 1;
}'''),
],'void func_02045bd0();\nvoid func_020456d8();\nvoid func_020455cc();',[('    u32 pad_0040_11 : 7;\n','    u32 pad_0040_11 : 4;\n    u32 flag_0040_15 : 1;\n    u32 flag_0040_16 : 1;\n    u32 pad_0040_17 : 1;\n')]),
('src/game/unit_02047338.c',[('func_02047534','''int func_02047534(s16 *st)
{
    if (st[1] != 0) {
        st[0] = 2;
    } else if (func_02045ca8() != 0) {
        st[0] = 2;
    }
    return 2;
}''')],'int func_02045ca8();'),
('src/game/unit_02047568.c',[('func_02047718','''int func_02047718(void)
{
    if (func_02052728() != 0) {
        return 0;
    }
    if (func_0205e4f8(-1) != 0) {
        return 0;
    }
    func_02045480();
    func_02048ed8();
    return 1;
}''')],'int func_0205e4f8();\nvoid func_02045480();\nvoid func_02048ed8();'),
('src/game/unit_02047788.c',[('func_02047788','''int func_02047788(void)
{
    if (func_02052728() != 0) {
        return 0;
    }
    if (func_02061698(data_0215ee9c) != 0) {
        return 0;
    }
    FIELD(u32, Unk044904_Get_data_0215ee98(), 0x40) &= ~0x8000;
    func_020614b0(data_0215ee9c);
    return 1;
}''')],'extern u8 data_0215ee9c[];\nint func_02052728();\nint func_02061698();\nvoid func_020614b0();\nu32 Unk044904_Get_data_0215ee98(void);'),
]
