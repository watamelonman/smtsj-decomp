def arr(fn, n, off):
    return (fn, f'''u32 {fn}(int i)
{{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {{
        return 0;
    }}
    if (FIELD(u32, p, 460) == 0) {{
        return 0;
    }}
    if (i < 0 || i >= {n}) {{
        return 0;
    }}
    return FIELD(u32, p + i * 4, {off});
}}''')
def fed(fn, k):
    return (fn, f'''int {fn}(void)
{{
    return func_0204fed8(func_020445f4(39, {k}), 1);
}}''')
SPECS=[
('src/game/unit_020ea208.c',[
arr('func_020ea524', 6, 36),
('func_020ea570','''u32 func_020ea570(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p == 0) {
        return 0;
    }
    if (FIELD(u32, p, 460) == 0) {
        return 0;
    }
    return FIELD(u32, p, 60);
}'''),
arr('func_020ea598', 6, 64), arr('func_020ea5e4', 6, 88),
('func_020ea70c','''void func_020ea70c(void)
{
    u32 p = Unk0ea208_Get_data_02176ddc();
    if (p != 0 && FIELD(u32, p, 460) != 0) {
        func_020eb2a4((u8 *)p);
    }
}'''),
('func_020ea828','''void func_020ea828(void)
{
    int n = Unk0e8228_Unk_0e8460();
    int i;
    for (i = 0; i < n; i++) {
        func_020ea744(Unk0e8228_GetArr40(i));
    }
}'''),
fed('func_020ea85c', 3), fed('func_020eac24', 4),
('func_020eac40','''void func_020eac40(u8 *p)
{
    func_02061f10(FIELD(u32, p, 60), -1, 0, 3, func_0204fed8(func_020445f4(39, 2), 1));
}'''),
('func_020eb2a4','''void func_020eb2a4(u8 *p)
{
    int i;
    u8 *q = p + 112;
    for (i = 0; i < 6; i++) {
        func_020eb034(q);
        q += 56;
    }
}'''),
],'void func_020eb2a4(u8 *p);\nvoid func_020eb034();\nvoid func_020ea744();\nint Unk0e8228_Unk_0e8460();\nint Unk0e8228_GetArr40();\nint func_020445f4();\nint func_0204fed8();'),
('src/CaveArea.c',[
('func_020ed1a8','''void func_020ed1a8(u8 *p)
{
    FIELD(u32, p, 128) = func_0205ba98(0x4000, 0x200, data_02150d6c, 0x5a1);
}'''),
],'extern u8 data_02150d6c[];\nu32 func_0205ba98();'),
]
