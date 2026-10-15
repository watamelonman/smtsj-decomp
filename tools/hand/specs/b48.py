FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def enter(fn, k, extra=''):
    return (fn, f'''void {fn}(void)
{{
    func_020cb3dc();
    Unk095560_Unk_095a2c();
    if (func_020de8b0(0) != 0) {{
        return;
    }}
{extra}    Unk0bc1a8_Unk_0bc928({k}, 0xffff, 0);
}}''')
ENTER = 'void func_020cb3dc();\nvoid Unk095560_Unk_095a2c();\nint func_020de8b0();\nvoid Unk0cb32c_Unk_0cb32c();\nvoid Unk0bc1a8_Unk_0bc928();'
SPECS=[
('src/game/unit_020cce38.c',[enter('func_020cce38', 17, '    Unk0cb32c_Unk_0cb32c();\n')],ENTER),
('src/game/unit_020cd470.c',[enter('func_020cd4d0', 18, '    Unk0cb32c_Unk_0cb32c();\n')],ENTER),
('src/game/unit_020cd6ec.c',[
('func_020cddd0','''void func_020cddd0(u8 *p, u32 a)
{
    int r = func_020cb5b4(a, p + 1);
    if (r == 1) {
        func_020ce2d8(p);
    } else if (r == 2) {
        func_020ce33c(p);
    } else if (r == 3) {
        p[0] = p[2];
    }
}'''),
],'int func_020cb5b4();\nvoid func_020ce2d8();\nvoid func_020ce33c();'),
('src/game/unit_020ce578.c',[
('func_020cf238','''void func_020cf238(Unk0ce578Work *p, int k)
{
    if (k == 2) {
        Unk0ce578_Unk_0cec98(p);
    }
    FIELD(int, p, 0) = k;
}'''),
],FX),
('src/game/unit_020cf5e8.c',[
enter('func_020cf5e8', 21, '    func_02044428(30);\n    func_02122a78();\n    Unk1241ec_Unk_1241ec();\n'),
('func_020d1908','''void func_020d1908(Unk0cf5e8Slots *p)
{
    int j;
    for (j = 0; j < 6; j++) {
        p->slot[j] = func_020f4560(j);
    }
    for (j = 0; j < 6; j++) {
        func_02122fac(p->h, j, p->slot[j]);
    }
}'''),
],'void func_020cb3dc();\nvoid Unk095560_Unk_095a2c();\nint func_020de8b0();\nvoid Unk0bc1a8_Unk_0bc928();\nvoid func_02044428();\nvoid func_02122a78();\nvoid Unk1241ec_Unk_1241ec();\nu32 func_020f4560();\nvoid func_02122fac();\ntypedef struct Unk0cf5e8Slots {\n    u8 pad_000[0x20];\n    u32 h;\n    u8 pad_024[0x348];\n    u32 slot[6];\n} Unk0cf5e8Slots;'),
('src/game/unit_020d1c98.c',[
('func_020d1d4c','''void func_020d1d4c(void)
{
    if (data_02176bdc == 0) {
        return;
    }
    func_020629c4(data_02176bdc->unk_0004);
    data_02176bdc->unk_0004 = 0;
    func_02061424(data_02176bdc);
    data_02176bdc = 0;
}'''),
],FX+'extern Unk0d1c98Work *data_02176bdc;\nvoid func_02061424();'),
]
