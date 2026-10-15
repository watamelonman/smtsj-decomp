FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_0210a034.c',[
('func_0210af8c','''u32 func_0210af8c(int i)
{
    u32 p;
    if (i < 0 || i >= 4) {
        return 0;
    }
    p = Unk10a034_Unk_10af7c();
    return p == 0 ? 0 : p + 32 + i * 8;
}'''),
('func_0210afd8','''void func_0210afd8(u32 a, u32 b)
{
    if (*data_02176e44 != 0) {
        return;
    }
    *data_02176e44 = func_0210b080(a, b);
}'''),
('func_0210b030','''int func_0210b030(void)
{
    u32 p = Unk10a034_Get_data_02176e44();
    if (p == 0) {
        return 1;
    }
    return FIELD(u32, p, 8) == 10;
}'''),
],'u32 func_0210b080();'),
('src/game/unit_0210b4d0.c',[
('func_0210b7bc','''int func_0210b7bc(void)
{
    int r = 0;
    if (func_0210b4d0(FIELD(u16, Unk02e000_GetWorkArea(), 860)) == 1) {
        r = 1;
    }
    return r;
}'''),
],FX),
('src/UniteEvent.c',[
('func_0210f970','''void func_0210f970(u32 a, int n)
{
    if (data_02176e48 == 0) {
        return;
    }
    func_0200866c(a, (u8 *)data_02176e48 + 614, n * 2);
    FIELD(u8, data_02176e48, 638) = n;
}'''),
('func_0210f9ac','''void func_0210f9ac(u32 x)
{
    if (data_02176e48 == 0) {
        return;
    }
    FIELD(u32, data_02176e48, 816) = 1;
    FIELD(u16, data_02176e48, 640) = x;
}'''),
],'void func_0200866c();'),
('src/game/unit_0210fe28.c',[
('func_02110048','''void func_02110048(Unk10fe28Work *w, int i, u32 v)
{
    func_0205c408(w->unk_0028[i], v);
    func_0205c6e0(w->unk_0028[i]);
}'''),
('func_02110074','''void func_02110074(Unk10fe28Work *w)
{
    int i;
    func_02110048(w, 0, 0);
    func_02110048(w, 1, 2);
    for (i = 2; i <= 7; i++) {
        func_02110048(w, i, 6);
    }
}'''),
('func_021102d4','''void func_021102d4(Unk10fe28Work *w)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0205c704(w->unk_0028[data_0213ca70[i]]);
    }
}'''),
],'void func_02110048(Unk10fe28Work *w, int i, u32 v);\nvoid func_0205c408();\nvoid func_0205c6e0();\nvoid func_0205c704();\nextern s16 data_0213ca70[];'),
('src/game/unit_021122bc.c',[
('func_021122bc','''int func_021122bc(int x)
{
    if (x == func_02035b08(8, 4)) {
        if (Unk0e651c_Unk_0e666c(0x159) == 1) {
            return 1;
        }
    }
    return 0;
}'''),
('func_02112438','''int func_02112438(int x)
{
    int r = 0;
    if (x == func_02035b08(8, 4)) {
        r = 1;
    }
    return r;
}'''),
('func_021124a0','''int func_021124a0(void)
{
    int r = 1;
    if (func_021122bc(FIELD(u16, Unk02e000_GetWorkArea(), 860)) == 1) {
        r = 0;
    }
    return r;
}'''),
],FX+'int func_02035b08();\nint Unk0e651c_Unk_0e666c();'),
]
