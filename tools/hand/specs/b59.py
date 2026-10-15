FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def cmpf(fn, get, off, op, k):
    return (fn, f'''int {fn}(void)
{{
    u32 p = {get}();
    if (p == 0) {{
        return 0;
    }}
    return FIELD(int, p, {off}) {op} {k};
}}''')
def sgn(fn, get, off, a, b):
    return (fn, f'''void {fn}(int flag)
{{
    u32 p = {get}();
    if (p == 0) {{
        return;
    }}
    if (flag != 0) {{
        FIELD(int, p, {off}) = {a};
    }} else {{
        FIELD(int, p, {off}) = {b};
    }}
}}''')
G1='Unk0fc584_Get_data_02176e14'; G2='Unk0fd268_Get_data_02176e1c'; G3='Unk0fd9f0_Get_data_02176e20'
SPECS=[
('src/game/unit_020fbc74.c',[
('func_020fbd74','''int func_020fbd74(u8 *p)
{
    u16 old;
    if (FIELD(u32, p, 0) != 4) {
        return 0;
    }
    old = FIELD(u16, p, 56);
    FIELD(u16, p, 56) = old + 10;
    if (FIELD(u16, p, 56) >= FIELD(int, p, 60)) {
        FIELD(u16, p, 56) = 0;
    }
    if (FIELD(u16, p, 56) != old) {
        FIELD(u32, p, 0) = 7;
        return 1;
    }
    return 0;
}'''),
],''),
('src/game/unit_020fc584.c',[
('func_020fc638','''void func_020fc638(u32 x)
{
    if (data_02176e10 != 0) {
        FIELD(u32, data_02176e10, 0x2000 + 2236) = x;
    }
}'''),
('func_020fc654','''u32 func_020fc654(void)
{
    if (data_02176e10 == 0) {
        return 0;
    }
    return FIELD(u32, data_02176e10, 0x2000 + 2236);
}'''),
('func_020fc6b8','''void func_020fc6b8(int flag)
{
    u32 p = Unk0fc584_Get_data_02176e14();
    if (p == 0) {
        return;
    }
    if (flag != 0) {
        FIELD(int, p, 20) = FIELD(int, p, 28);
    } else {
        FIELD(int, p, 20) = -FIELD(int, p, 28);
    }
}'''),
cmpf('func_020fc6e4', G1, 12, '<', 64), cmpf('func_020fc70c', G1, 12, '==', 0),
('func_020fc7f4','''int func_020fc7f4(void)
{
    u32 p;
    if (func_020fc6e4() == 0) {
        return 0;
    }
    p = Unk0fc584_Get_data_02176e14();
    return FIELD(int, p, 32) != FIELD(int, p, 36);
}'''),
('func_020fc86c','''void func_020fc86c(void)
{
    u32 p = Unk0fc584_Get_data_02176e14();
    if (p != 0 && FIELD(u32, p, 48) != 0 && FIELD(u32, p, 44) != 0) {
        func_020fc734(FIELD(u32, p, 44));
    }
}'''),
],'extern u8 *data_02176e10;\nvoid func_020a4e48();\nvoid func_020a4eb0();\nint func_020fc6e4(void);'),
('src/game/unit_020fd268.c',[
('func_020fd364','''int func_020fd364(void)
{
    if (data_02176e18 != 0) {
        return FIELD(int, data_02176e18, 0);
    }
    return -1;
}'''),
sgn('func_020fd3c4', G2, 16, 3, -3),
cmpf('func_020fd428', G2, 8, '==', 0), cmpf('func_020fd450', G2, 8, '==', -81),
],FX+'extern u8 *data_02176e18;'),
('src/game/unit_020fd9f0.c',[sgn('func_020fda2c', G3, 20, 1, -1)],FX),
]
