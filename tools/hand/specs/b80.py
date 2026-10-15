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
SPECS=[
('src/game/unit_0203be10.c',[
('func_0203bf34','''int func_0203bf34(void)
{
    if (func_0206552c() != 0) {
        return 0;
    }
    if (ImageObj_Unk_077688() == 0) {
        return 0;
    }
    if (Unk02e000_GetSlot(0) == 1) {
        switch (Unk02e000_GetSlot(1)) {
        case 0:
            Unk09e72c_Unk_09e8f0();
            Unk02e000_SetSlot(1, 1);
        case 1:
            if (Unk09d42c_Unk_09e274() == 0) {
                return 0;
            }
            break;
        }
    }
    return 1;
}'''),
],'int func_0206552c();\nint ImageObj_Unk_077688();\nint Unk02e000_GetSlot();\nvoid Unk09e72c_Unk_09e8f0();\nvoid Unk02e000_SetSlot();\nint Unk09d42c_Unk_09e274();\n'),
('src/game/unit_0203c05c.c',[
('func_0203c144','''int func_0203c144(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    s16 c = func_0203ac00(2);
    u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    FIELD(u32, o, 24) = 15;
    func_0209e49c(b, c, a);
    return 3;
}'''),
],FX+'int func_0203ac00();\nu32 Unk03aae8_Unk_03ad14();\nvoid func_0209e49c();\n'),
('src/game/unit_0203c6a4.c',[
('func_0203c954','''int func_0203c954(void)
{
    s16 a = func_0203ac00(0);
    int k = func_0203ac00(1);
    int m;
    m = 0;
    switch (k) {
    case 0:
        break;
    case 1:
        m = 1;
        break;
    case 2:
        m = 2;
        break;
    }
    return func_0203c748(m, a, 0, 0, 0x101);
}'''),
('func_0203c9c0','''int func_0203c9c0(void)
{
    s16 a = func_0203ac00(0);
    int b = func_0203ac00(1);
    int k = func_0203ac00(2);
    int m;
    func_0203ac00(3);
    m = 0;
    switch (k) {
    case 0:
        break;
    case 1:
        m = 1;
        break;
    case 2:
        m = 2;
        break;
    }
    return func_0203c748(m, a, b, 0, 0);
}'''),
],'int func_0203ac00();\nint func_0203c748();\n'),
('src/game/unit_0203ca38.c',[
pick('func_0203ca80', ('Unk02e000_Thunk_0202e788()[110]','Unk0979d8_Unk_098124')),
pick('func_0203cad4', ('Unk096754_Unk_0970b4()','Unk0979d8_Unk_09813c')),
pick('func_0203cb28', ('Unk096754_Unk_0970c4()','Unk0979d8_Unk_098154')),
],'int func_0203ac00();\nint Unk03aae8_Unk_03acf4();\nu8 *Unk02e000_Thunk_0202e788();\nint Unk0979d8_Unk_098124();\nint Unk0979d8_Unk_09813c();\nint Unk0979d8_Unk_098154();\nint Unk096754_Unk_0970b4();\nint Unk096754_Unk_0970c4();\n'),
]
