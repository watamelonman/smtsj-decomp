FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def st(fn, data, k):
    return (fn, f'''int {fn}(void)
{{
    u8 *p = (u8 *)*{data};
    if (p == 0) {{
        return 1;
    }}
    return FIELD(int, p, 0) == {k};
}}''')
SPECS=[
('src/game/unit_0211ec7c.c',[
('func_0211ef74','''void func_0211ef74(u8 *p)
{
    FIELD(int, p, 12) = FIELD(int, p, 16);
    FIELD(int, p, 16) = -1;
    switch (FIELD(int, p, 12)) {
    case 1:
        Unk11ec7c_Unk_11ee8c((int)p);
        return;
    case 2:
        Unk11ec7c_Nop_11ef08();
        return;
    }
}'''),
('func_0211efb0','''void func_0211efb0(u8 *p)
{
    switch (FIELD(u32, p, 12)) {
    case 0:
        break;
    case 1:
        func_0211eea8(p);
        break;
    case 2:
        Unk11ec7c_Unk_11ef0c((int)p);
        break;
    case 3:
        Unk11ec7c_Unk_11ef2c((int)p);
        break;
    }
}'''),
('func_0211f06c','''void func_0211f06c(u8 *p)
{
    if (FIELD(u32, p, 0) == 0) {
        return;
    }
    if (FIELD(int, p, 16) != -1) {
        func_0211ef74(p);
    }
    func_0211efb0(p);
}'''),
],FX+'void Unk11ec7c_Unk_11ee8c(int arg0);\nvoid Unk11ec7c_Nop_11ef08(void);\nvoid Unk11ec7c_Unk_11ef0c(int arg0);\nvoid Unk11ec7c_Unk_11ef2c(int arg0);\nvoid func_0211eea8();\nvoid func_0211ef74(u8 *p);\nvoid func_0211efb0(u8 *p);'),
('src/game/unit_0211f2d0.c',[
('func_0211f334','''int func_0211f334(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p, 12) != 0;
}'''),
st('func_0211f39c', 'data_02176e78', 7),
],FX),
('src/game/unit_0211fc20.c',[
st('func_0211fc68', 'data_02176e7c', 4),
('func_02120650','''int func_02120650(u8 *p)
{
    int v = FIELD(int, p, 40) - 4096;
    FIELD(int, p, 40) = v;
    return v <= 8192;
}'''),
('func_0212066c','''int func_0212066c(u8 *p)
{
    int v;
    Unk0a0ce4_Unk_0a0da4(3);
    FIELD(u32, p, 64) = 0;
    v = FIELD(int, p, 68) - 4096;
    FIELD(int, p, 68) = v;
    if (v <= 4096) {
        FIELD(u32, p, 28) = 0;
        return 1;
    }
    FIELD(u32, p, 24) = 15;
    return 0;
}'''),
('func_02120898','''void func_02120898(u32 a, int b, int c, u32 d, u32 e, u32 f)
{
    u8 *w = (u8 *)*data_02176e7c;
    func_02057d54(a, b + (FIELD(int, w, 4) + 64), c + FIELD(int, w, 8), d, e, f);
}'''),
],FX+'void func_02057d54();'),
('src/game/unit_02122a78.c',[
('func_02122a78','''void func_02122a78(void)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        Unk05b82c_Unk_05b82c(data_0213cd70[i]);
    }
}'''),
],'extern u32 data_0213cd70[];\nvoid Unk05b82c_Unk_05b82c();'),
('src/game/unit_02122e1c.c',[
('func_02122fac','''void func_02122fac(Unk122e1cObj *p, int i, u32 v)
{
    if (p == 0) {
        return;
    }
    if (i < 0 || i >= 6) {
        return;
    }
    p->slot[i] = v;
}'''),
('func_02122fd0','''void func_02122fd0(Unk122e1cObj *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->slot[i] = 0;
    }
}'''),
('func_02123534','''void func_02123534(Unk122e1cObj *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        Unk0cb32c_Unk_0cb504(p->h[i], (u8)p->unk4, (u8)(i + 110));
    }
}'''),
],'typedef struct Unk122e1cObj {\n    u32 pad0;\n    u32 unk4;\n    u8 pad[216];\n    u32 h[6];\n    u32 slot[6];\n} Unk122e1cObj;\nvoid Unk0cb32c_Unk_0cb504();'),
]
