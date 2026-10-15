def boolh(fn, cond, pre=''):
    return (fn, f'''int {fn}(void)
{{
{pre}    if ({cond}) {{
        Unk03aae8_Unk_03acf4(1);
    }} else {{
        Unk03aae8_Unk_03acf4(0);
    }}
    return 1;
}}''')
SPECS=[
('src/game/unit_0203de08.c',[boolh('func_0203dfe0','Unk02e000_TestFlag(func_02035b08(a, b))','''    u8 a = func_0203ac00(0);
    u8 b = func_0203ac00(1);
''')],'int Unk03aae8_Unk_03acf4();\nint func_02035b08();\nint Unk02e000_TestFlag();'),
('src/game/unit_0203e23c.c',[
('func_0203e260','''int func_0203e260(void)
{
    int a = func_0203ac00(0);
    func_0202eda8((u16)a, func_0203ac00(1));
    return 1;
}'''),
boolh('func_0203e290','Unk096754_Unk_0969f0()'),
boolh('func_0203e2bc','func_02096a60((u16)func_0203ac00(0))'),
('func_0203e36c','''int func_0203e36c(void)
{
    if (func_02096af4((u16)func_0203ac00(0)) >= 0) {
        func_02096958();
    }
    return 1;
}'''),
boolh('func_0203e398','Unk0986ac_Thunk_02098714()','''    Unk0986ac_Unk_098978(func_0203ac00(0));
'''),
],'void func_0202eda8();\nint Unk096754_Unk_0969f0();\nint func_02096a60();\nint func_02096af4();\nvoid func_02096958();\nvoid Unk0986ac_Unk_098978();\nint Unk0986ac_Thunk_02098714();'),
('src/game/unit_0203e43c.c',[
('func_0203e7cc','''void func_0203e7cc(u8 *src, int idx)
{
    int i;
    for (i = 0; i < 32; i += 2) {
        data_0215e85c[idx * 32 + i + 2] = src[i];
        data_0215e85c[idx * 32 + i + 3] = src[i + 1];
    }
}'''),
('func_0203e804','''void func_0203e804(u8 *src)
{
    int i;
    for (i = 0; i < 512; i += 2) {
        if (src[i] != 0 || src[i + 1] != 0) {
            data_0215e85c[i + 2] = src[i];
            data_0215e85c[i + 3] = src[i + 1];
        }
    }
}'''),
],'extern u8 data_0215e85c[];'),
]
