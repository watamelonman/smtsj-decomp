FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def pick(fn, call):
    return (fn, f'''int {fn}(void)
{{
    int k = func_0203ac00(0);
    int r = 0;
    if (k == 0) {{
        r = {call[0]};
    }} else if (k >= 1 && k <= 3) {{
        r = {call[1]}((u8)(k - 1));
    }}
    Unk03aae8_Unk_03acf4(r);
    return 1;
}}''')
H='int func_0203ac00();\nint Unk03aae8_Unk_03acf4();\n'
SPECS=[
('src/game/unit_0203ca38.c',[pick('func_0203cc04',('Unk096754_Unk_097100()','Unk0979d8_Unk_09818c'))],H+'int Unk096754_Unk_097100();\nint Unk0979d8_Unk_09818c();\n'),
('src/game/unit_0203cc58.c',[pick('func_0203cc58',('Unk096754_Unk_097110()','Unk0979d8_Unk_0981a4'))],H+'int Unk096754_Unk_097110();\nint Unk0979d8_Unk_0981a4();\n'),
('src/game/unit_0203ce68.c',[
('func_0203ce68','''int func_0203ce68(void)
{
    int k = func_0203ac00(0);
    u16 *w;
    int r;
    func_0203ac00(1);
    w = (u16 *)Unk02e000_Thunk_0202e788();
    r = 0;
    switch (k) {
    case 0: r = w[0]; break;
    case 1: r = w[1]; break;
    case 2: r = w[2]; break;
    case 3: r = w[3]; break;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}'''),
('func_0203d088','''int func_0203d088(void)
{
    int k = func_0203ac00(0);
    u32 y = Unk03ce68_Unk_03d038(func_0203ac00(1));
    int r = 0;
    if (k == 0) {
        r = Unk09727c_GetAreaS8(y);
    } else if (k >= 1 && k <= 3) {
        r = func_02098258((u8)(k - 1), y);
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}'''),
],H+'u8 *Unk02e000_Thunk_0202e788();\nint Unk09727c_GetAreaS8();\nint func_02098258();\nu32 Unk03ce68_Unk_03d038(u32 arg0);\n'),
('src/game/unit_0203d494.c',[
('func_0203d618','''int func_0203d618(void)
{
    s16 a, b, c;
    u8 *o;
    func_0203ac00(0);
    a = func_0203ac00(1);
    b = func_0203ac00(2);
    c = func_0203ac00(3);
    func_0209e33c(FIELD(u16, Unk02e000_GetWorkArea() + 0x300, 92), a, b, c);
    o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    FIELD(u32, o, 24) = 15;
    return 3;
}'''),
],FX+H+'u8 *Unk02e000_GetWorkArea();\nvoid func_0209e33c();\nu32 Unk03aae8_Unk_03ad14();\n'),
]
