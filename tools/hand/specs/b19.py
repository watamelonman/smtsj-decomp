def cmp3(fn, a, b):
    return (fn, f'''int {fn}(u8 *a, u8 *b)
{{
    int d = {b}[2] - {a}[2];
    if (d == 0) {{
        d = {a}[3] - {b}[3];
    }}
    if (d == 0) {{
        d = *(u16 *){a} - *(u16 *){b};
    }}
    return d;
}}''')
SPECS=[
('src/game/unit_02065e88.c',[
('func_020672b4','''void func_020672b4(s32 *o, s32 v, int notify)
{
    o[0] = v;
    if (notify == 0) {
        return;
    }
    switch (o[0]) {
    case 1:
        func_02072238(o);
        break;
    case 2:
        FIELD(u32, o, 0x220) = 1;
        break;
    case 4:
        FIELD(u32, o, 0x2f0) = 1;
        break;
    }
}'''),
('func_02068564', """int func_02068564(Unk065e88Obj24 *o)
{
    if (!o->flag_0024_28 && (o->unk_002a == 0 || Unk0e651c_Unk_0e666c(o->unk_002a) != 0) && func_020684c0(o) != 0) {
        return 1;
    }
    return 0;
}"""),
],'''typedef struct Unk065e88Obj24 {
    u8 pad_0000[0x24];
    u32 pad_0024_0 : 28;
    u32 flag_0024_28 : 1;
    u8 pad_0028[2];
    u16 unk_002a;
} Unk065e88Obj24;

'''+'void func_02072238();\nint Unk0e651c_Unk_0e666c();\nint func_020684c0();'),
('src/game/unit_02068f18.c',[cmp3('func_02068f18','a','b'),cmp3('func_02068f48','b','a')],''),
('src/game/unit_0206a224.c',[
('func_0206a264','''s16 func_0206a264(void)
{
    s16 n = 0;
    int i;
    for (i = 0; i < 489; i++) {
        if (FIELD(Unk06a224Slot *, data_0216b9b0.unk_04, 0x408)[i].id != 0) {
            n++;
        }
    }
    return n;
}'''),
('func_0206a374','''int func_0206a374(u8 *o)
{
    if (FIELD(s16, o, 0x154) % 2 != 0) {
        return 1;
    }
    return FIELD(s16, o, 0x156) > 0;
}'''),
('func_0206a3a4','''int func_0206a3a4(u8 *o)
{
    s16 a = FIELD(s16, o, 0x154);
    if (a % 2 == 0) {
        if (a < FIELD(s16, o, 0x158) - 1) {
            return 1;
        }
    } else if (FIELD(s16, o, 0x156) + 24 < FIELD(s16, o, 0x158)) {
        return 1;
    }
    return 0;
}'''),
],'typedef struct Unk06a224Slot {\n    u16 id;\n    u16 pad_0002;\n} Unk06a224Slot;'),
('src/game/unit_0206ae94.c',[('func_0206b0ac','''void func_0206b0ac(int a, int b, int c, int d, int e, int f, u8 g, int h, int i)
{
    func_0206af04(a, b, c, d, e, f, 0, g, h, i);
}''')],'void func_0206af04();'),
]
