# +0xe8 script-handler family: the store goes through an inline setter taking (value, sub); that gives
# the ROM's register order (sub in r1, value in r0). Plain FIELD/struct stores put sub in r0.
SUB = 'FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8)'
def setter(name, T, off):
    return f'''static inline void {name}({T} v, u8 *sub)
{{
    FIELD({T}, sub, {off}) = v;
}}'''
ST = lambda tu: setter(f'Unk{tu}_SetSubState', 'u32', '0x18')
SPECS=[
('src/game/unit_0203bba4.c',[
('func_0203bba4','''int func_0203bba4(void)
{
    Unk03bba4_SetSubState(19, '''+SUB+''');
    if (func_02095818() == 3) {
        Unk116598_Unk_116810();
    }
    return 3;
}'''),
('func_0203bc40','''int func_0203bc40(void)
{
    u16 id = func_0203ac00(0);
    if (func_02065544() == 0) {
        func_02065c10();
    }
    func_02065b10(0, id);
    Unk03bba4_SetSubState(6, '''+SUB+''');
    return 3;
}''')],'int Unk03aae8_Unk_03ad14();\nint func_02095818();\nvoid Unk116598_Unk_116810();\nint func_02065544();\nvoid func_02065c10();\nvoid func_02065b10();\n'+ST('03bba4')),
('src/game/unit_0203c474.c',[('func_0203c608','''int func_0203c608(void)
{
    int v = func_0203ac00(0);
    if (v > 0) {
        Unk03c474_SetSubUnkC(v - 1, '''+SUB+''');
    }
    return 1;
}''')],setter('Unk03c474_SetSubUnkC', 'u16', '0x0c')),
('src/game/unit_0203c6a4.c',[('func_0203c718','''int func_0203c718(void)
{
    if (func_02065544() == 0) {
        return 3;
    }
    func_02065c30();
    Unk03c6a4_SetSubState(4, '''+SUB+''');
    return 3;
}''')],'int Unk03aae8_Unk_03ad14();\nvoid func_02065c30();\n'+ST('03c6a4')),
]
