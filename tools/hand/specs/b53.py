FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def arr(fn, n, off):
    return (fn, f'''int {fn}(int i)
{{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {{
        return 0;
    }}
    if (i < 0 || i >= {n}) {{
        return 0;
    }}
    return FIELD(u32, p + i * 4, {off});
}}''')
def flag(fn, off):
    return (fn, f'''int {fn}(void)
{{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {{
        return 0;
    }}
    return FIELD(u32, p, {off}) == 1;
}}''')
SPECS=[
('src/game/unit_020e78b8.c',[
('func_020e78b8','''int func_020e78b8(void)
{
    if (*data_02176cd8 == 0) {
        return 0;
    }
    return FIELD(u32, *data_02176cd8, 16) == 5;
}'''),
],FX+'extern u32 data_02176cd8[];'),
('src/game/unit_020e8228.c',[
('func_020e8260','''void func_020e8260(u32 i)
{
    u8 *base = data_02176ce4;
    if (i == 0) {
        Unk0e8228_Unk_0e9f18((u32 *)(base + 8));
        return;
    }
    if (i >= 1 && i <= 3) {
        Unk0e8228_Unk_0e9f38((u32 *)(base + 32 + (i - 1) * 24), 0);
    }
}'''),
('func_020e8374','''int func_020e8374(u32 x)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return func_020e9ca8(p, x);
}'''),
arr('func_020e83ac', 4, 48), arr('func_020e83e8', 12, 88), arr('func_020e8424', 6, 64),
('func_020e849c','''int func_020e849c(int i)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    u8 *q;
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 60) {
        return 0;
    }
    q = FIELD(u8 *, p + i * 4, 136);
    return q == 0 ? 0 : FIELD(u16, q, 32);
}'''),
flag('func_020e85a0', 4), flag('func_020e8b54', 12),
('func_020e8be8','''int func_020e8be8(void)
{
    u32 p;
    switch (func_0204a244(func_02044ec4(func_020e83ac(0)))) {
    case 1:
    case 7:
    case 11:
        return 0;
    }
    p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return func_020e9b54(p);
}'''),
('func_020e8c80','''int func_020e8c80(void)
{
    u32 p = Unk0e8228_Get_data_02176ce0();
    if (p == 0) {
        return 0;
    }
    return func_020e9748(p);
}'''),
('func_020e8ce8','''int func_020e8ce8(u32 x)
{
    u8 *v;
    if (x == 0) {
        return 0;
    }
    v = func_020982c0((s8)func_0204a244(x));
    if (v == 0) {
        return 1;
    }
    return (s8)v[2];
}'''),
],FX+'extern u8 data_02176ce4[];\nvoid Unk0e8228_Unk_0e9f18(u32 *arg0);\nvoid Unk0e8228_Unk_0e9f38(u32 *arg0, u32 arg1);\nint func_020e9ca8();\nint func_020e9b54();\nint func_020e9748();\nint func_02044ec4();\nint func_0204a244();\nu8 *func_020982c0();'),
]
