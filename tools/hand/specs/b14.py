SPECS=[
('src/game/unit_0203e43c.c',[
('func_0203e848','''void func_0203e848(void)
{
    func_02020f8c();
    func_02008848(data_0215e85e, 0, 512);
    *(u16 *)data_0215e85c = 0;
}'''),
('func_0203e894','''void func_0203e894(u8 *o, int b, int c, int d)
{
    func_020211d8(o, func_0202092c(c, (u16)d), b);
    FIELD(u16, o, 0x58) = 0;
}'''),
('func_0203fa08','''int func_0203fa08(int x)
{
    int r = x / 10;
    if (r >= 16) {
        r = -1;
    }
    return r;
}'''),
('func_0203fa58','''void func_0203fa58(void)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 v = ++w[0x360];
    if (v >= 160) {
        w[0x360] -= 160;
    }
}'''),
('func_02041d70','''void func_02041d70(int mode)
{
    FIELD(s32, data_0215ee60, 0x30) = mode;
    if (mode == 1 && FIELD(u32, data_0215ee60, 0x34) == 0) {
        func_0204b6d0();
    }
}'''),
('func_02043410','''void func_02043410(u8 *o)
{
    s16 x = FIELD(s16, o, 0x18);
    s16 y = FIELD(s16, o, 0x1a);
    func_02043450(o + 0x18, o + 0x1a, FIELD(u32, o, 0x28dc));
    if (FIELD(s16, o, 0x18) != x || FIELD(s16, o, 0x1a) != y) {
        FIELD(u32, o, 0x04) = 1;
    }
}'''),
],'void func_02020f8c();\nvoid func_02008848();\nint func_0202092c();\nvoid func_020211d8();\nvoid func_0204b6d0();\nvoid func_02043450();\nextern u8 data_0215ee60[];'),
('src/game/unit_02044394.c',[('func_020443e4','''int func_020443e4(int i)
{
    int ok;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    return FIELD(u32, data_0214283c + i * 16, 4) != 0;
}''')],'extern u8 data_0214283c[];'),
('src/game/unit_02044904.c',[('func_02044904','''typedef struct Unk044904Entry {
    u16 id;
    u8 pad_0002[10];
} Unk044904Entry;

Unk044904Entry *func_02044904(Unk044904Entry *tbl, u16 key)
{
    u32 i;
    Unk044904Entry *e;
    for (i = 0; i < FIELD(u32, tbl, 0x60); i++) {
        e = &tbl[i];
        if (key == e->id) {
            return &tbl[i];
        }
    }
    return 0;
}''')],''),
]
