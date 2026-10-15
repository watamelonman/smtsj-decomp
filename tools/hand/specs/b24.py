SPECS=[
('src/ImageObj.c',[
('func_020777e0','''int func_020777e0(void)
{
    Unk077Tbl *t = (Unk077Tbl *)ImageObj_Get_data_0217231c();
    int i;
    if (t == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        u8 *e = (u8 *)t->e[i];
        if (e != 0 && FIELD(u32, e, 0x48) == 0) {
            return 1;
        }
    }
    return 0;
}'''),
('func_02077a4c','''void func_02077a4c(void *o, int kind)
{
    switch (kind) {
    case 0:
        func_02013c3c(o, data_02145a54);
        break;
    case 1:
        func_02013c3c(o, data_02145a70);
        break;
    case 2:
        func_02013c3c(o, data_02145a88);
        break;
    }
}'''),
('func_02077d68','''int func_02077d68(s32 *o)
{
    if (o == 0) {
        return 0;
    }
    if (o[0] != 2) {
        return 0;
    }
    return FIELD(s32, o, 0x50) < 600;
}'''),
('func_02077d98','''void func_02077d98(u8 *o)
{
    int v;
    switch (func_02095818()) {
    case 0:
        v = 8;
        break;
    case 2:
        v = 8;
        break;
    default:
        v = 0;
        break;
    }
    Unk065e88_SetPair04(FIELD(u32, o, 0x68), 0, v);
}'''),
('func_02077efc','''void func_02077efc(u32 o)
{
    u8 *t = (u8 *)ImageObj_Get_data_0217231c();
    if (FIELD(u32, o, 0x68) == 0) {
        return;
    }
    func_02061424(FIELD(u32, o, 0x68));
    FIELD(u32, o, 0x68) = 0;
    func_020a1a24(t + 52);
}'''),
],'extern u8 data_02145a54[];\nextern u8 data_02145a70[];\nextern u8 data_02145a88[];\nvoid func_02013c3c();\nint func_02095818();\nvoid Unk065e88_SetPair04();\nvoid func_02077efc(u32 o);\nvoid func_02077ea4();\nvoid func_020a1a24();'),
('src/game/unit_020939f0.c',[('func_02093ae4','''void func_02093ae4(u8 *o)
{
    FIELD(u32, o, 0x08) = 0;
    FIELD(u8, o, 0x6c) = 0;
    FIELD(u32, o, 0x68) = 0;
    Unk0939f0_Unk_093f0c((int)o);
}''')],'void Unk0939f0_Unk_093f0c(int arg0);'),
('src/game/unit_020946e0.c',[('func_02094910','''void func_02094910(void)
{
    u8 *p = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    FIELD(s16, p, 0x00) = 0;
    FIELD(s16, p, 0x02) = 0;
    FIELD(s32, p, 0x04) = FIELD(s16, p, 0x00);
    FIELD(s32, p, 0x08) = FIELD(s16, p, 0x02);
    FIELD(u16, p, 0x10) = 256;
    FIELD(u16, p, 0x12) = 192;
    FIELD(u32, p, 0x14) = 0;
}''')],''),
]
# func_02077e74 skipped: own compare OK, objdiff 99.58% (call to later-defined func_02077efc)
