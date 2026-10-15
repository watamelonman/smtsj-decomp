FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def scan(fn, lo, hi):
    return (fn, f'''int {fn}(Unk113294Ids *p)
{{
    int i;
    for (i = {lo}; i < {hi}; i++) {{
        if (func_021155bc(p->ids[i]) != 0) {{
            return 1;
        }}
    }}
    return 0;
}}''')
SPECS=[
('src/game/unit_020fedd4.c',[
('func_020fedf0','''void func_020fedf0(u32 a)
{
    if (data_02176e28 != 0) {
        return;
    }
    data_02176e28 = (Unk0fedd4Obj *)func_020fef0c(a);
}'''),
],'u32 func_020fef0c();'),
('src/game/unit_021124f0.c',[
('func_021124f0','''int func_021124f0(u16 a, u32 b, u32 c)
{
    int r = 0;
    if (a == func_02035b08(8, 10) && b == 23 && c == 10) {
        if (Unk0e651c_Unk_0e666c(344) == 1) {
            r = 1;
        }
    }
    return r;
}'''),
],'int func_02035b08();\nint Unk0e651c_Unk_0e666c();'),
('src/game/unit_02113294.c',[
('func_02113e90','''int func_02113e90(u8 *p)
{
    return FIELD(u16, p, 216) == 0 && FIELD(u32, p, 12) == 0 && FIELD(u32, p, 4) == 1;
}'''),
('func_02113eb4','''void func_02113eb4(u8 *p)
{
    p[0] = 5;
    *data_02176e54 = 0;
    Unk0a0ce4_Unk_0a0da4(2);
}'''),
('func_0211508c','''void func_0211508c(u32 a, u32 b)
{
    func_02061f10(a, -1, 0, 0, func_0204fed8(func_020445f4(42, 0), b));
}'''),
scan('func_021155e0', 0, 8), scan('func_02115618', 8, 16),
('func_02115658','''void func_02115658(u8 *p)
{
    func_02008904(p + 232, (u8 *)Unk02e000_Thunk_0202e788() + 72, 16);
    func_02008904(p + 216, (u8 *)Unk02e000_Thunk_0202e788() + 90, 16);
    func_0202efa4();
}'''),
('func_02115708','''int func_02115708(Unk113294Ids *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->ids[i] == 0) {
            return i;
        }
    }
    return 7;
}'''),
('func_02115734','''int func_02115734(u8 *p)
{
    switch (p[8]) {
    case 0:
    case 1:
        return 0;
    }
    return 1;
}'''),
],FX+'extern u32 data_02176e54[];\nint func_02061f10();\nint func_021155bc();\nint func_02115618();\nint func_021155e0();\nint Unk02e000_Thunk_0202e788();\nvoid func_02008904();\nvoid func_0202efa4();\ntypedef struct Unk113294Ids {\n    u8 pad[216];\n    u16 ids[16];\n} Unk113294Ids;'),
]
