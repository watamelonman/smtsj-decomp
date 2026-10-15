FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def g(fn, off):
    return (fn, f'''u32 {fn}(void)
{{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {{
        return 0;
    }}
    if (FIELD(u32, p, 460) == 0) {{
        return 0;
    }}
    return FIELD(u32, p, {off});
}}''')
SPECS=[
('src/game/unit_020e8228.c',[
('func_020e8e28','''int func_020e8e28(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 0) == 3;
}'''),
('func_020e8fe4','''int func_020e8fe4(u32 x)
{
    u32 h;
    if (x == 0) {
        return 0;
    }
    h = FIELD(u16, func_02099d14(x), 34);
    if (h == 0) {
        return 0;
    }
    return FIELD(u8, func_020cb1a0(h), 35) == 7;
}'''),
('func_020e9748','''int func_020e9748(u8 *p)
{
    int i = FIELD(int, p, 8);
    if (i <= -1) {
        i = 0;
    }
    if (Unk0e8228_IsField4One() != 0) {
        return FIELD(u32, p + i * 4, 48);
    }
    return FIELD(u32, p + i * 4, 64);
}'''),
('func_020e9bc0','''void func_020e9bc0(Unk0e8228SelHost *p)
{
    int j;
    int k;
    if (&p->sel == 0) {
        return;
    }
    for (j = 0; j < 2; j++) {
        p->sel.a[j] = 0;
    }
    for (k = 0; k < 16; k++) {
        p->sel.b[k] = 0;
    }
}'''),
],'int func_020cb1a0();\ntypedef struct Unk0e8228Sel {\n    u8 a[2];\n    u8 pad[2];\n    u32 b[16];\n} Unk0e8228Sel;\ntypedef struct Unk0e8228SelHost {\n    u8 pad[392];\n    Unk0e8228Sel sel;\n} Unk0e8228SelHost;'),
('src/game/unit_020ea208.c',[
('func_020ea390','''void func_020ea390(int i, u32 x)
{
    if (i < 0) {
        return;
    }
    if (i >= 6) {
        return;
    }
    func_02061f10(FIELD(u32, Unk0ea208_Get_data_02176ddc() + i * 4, 36), -1, 0, 0, x);
}'''),
g('func_020ea438', 0), g('func_020ea460', 4), g('func_020ea488', 8), g('func_020ea4b0', 12),
('func_020ea4d8','''u32 func_020ea4d8(int i)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    if (i < 0 || i >= 5) {
        return 0;
    }
    return FIELD(u32, p + i * 4, 16);
}'''),
],FX+'void func_02061f10();'),
]
