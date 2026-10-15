SUB = 'FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8)'
def ST(tu):
    return f'''int Unk03aae8_Unk_03ad14();
static inline void Unk{tu}_SetSubState(u32 v, u8 *sub)
{{
    FIELD(u32, sub, 0x18) = v;
}}'''
def h1(fn, tu, callee, st=15):  # (s16)arg0 -> callee; state st; return 3
    return (fn, f'''int {fn}(void)
{{
    {callee}((s16)func_0203ac00(0));
    Unk{tu}_SetSubState({st}, {SUB});
    return 3;
}}''')
SPECS=[
('src/game/unit_0203ce68.c',[('func_0203cfd4','''int func_0203cfd4(void)
{
    func_0203ac00(0);
    Unk03aae8_Unk_03acf4(Unk02e000_Thunk_0202e788()[0x70]);
    return 1;
}''')],'u8 *Unk02e000_Thunk_0202e788();'),
('src/game/unit_0203d72c.c',[
h1('func_0203d72c','03d72c','Unk09d42c_Unk_09e2f4'),
('func_0203d7dc','''int func_0203d7dc(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);
    func_0209efb4(a, b, func_0203ac00(2));
    Unk03d72c_SetSubState(15, '''+SUB+''');
    return 3;
}'''),
h1('func_0203d890','03d72c','func_0209ee80'),
h1('func_0203d8c0','03d72c','Unk09ee4c_Unk_09ef50'),
],ST('03d72c')+'\nvoid Unk09d42c_Unk_09e2f4();\nvoid func_0209efb4();\nvoid func_0209ee80();\nvoid Unk09ee4c_Unk_09ef50();'),
('src/game/unit_0203d930.c',[
('func_0203d930','''int func_0203d930(void)
{
    if (FIELD(u32, Unk095560_GetManager(), 0x3bc) == 0) {
        return 0;
    }
    Unk09ee4c_Unk_09ef80(90);
    Unk03d930_SetSubState(15, '''+SUB+''');
    return 3;
}'''),
h1('func_0203d968','03d930','Unk09d42c_Unk_09e2a4'),
],ST('03d930')+'\nu8 *Unk095560_GetManager();\nvoid Unk09ee4c_Unk_09ef80();\nvoid Unk09d42c_Unk_09e2a4();'),
('src/game/unit_0203dbbc.c',[('func_0203dbbc','''int func_0203dbbc(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    func_0204cbc8();
    Unk02e000_GetWorkArea();
    func_0204c404(a, b);
    Unk03dbbc_SetSubState(17, '''+SUB+''');
    return 3;
}''')],ST('03dbbc')+'\nvoid func_0204cbc8();\nvoid func_0204c404();'),
]
