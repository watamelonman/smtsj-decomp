D = 'data_021508d4'
SPECS=[
('src/game/unit_020de678.c',[
('func_020dedf8',f'''void func_020dedf8(u8 *out)
{{
    if (FIELD(u32, {D}, 16) != 0) {{
        out[0] = FIELD(u32, {D}, 32);
        out[1] = FIELD(u32, {D}, 36);
        return;
    }}
    out[0] = 0;
    out[1] = 0;
}}'''),
('func_020df348',f'''void func_020df348(u32 a)
{{
    FIELD(u32, {D}, 4) = 1;
    func_020df330(3);
    FIELD(u32, {D}, 12) = a;
}}'''),
('func_020df4cc',f'''void func_020df4cc(u32 a, u32 b)
{{
    FIELD(u32, {D}, 16) = 1;
    FIELD(u8, {D}, 24) = a;
    FIELD(u32, {D}, 20) = b;
    FIELD(u32, {D}, 28) = 0;
}}'''),
('func_020df4f0',f'''void func_020df4f0(void)
{{
    FIELD(u32, {D}, 32) = 0;
    FIELD(u32, {D}, 36) = 0;
    Unk095560_Unk_0958a8(0, 0);
    FIELD(u32, {D}, 16) = 0;
}}'''),
],'void Unk0bc1a8_Unk_0bc9b4();\nvoid func_020df330();\nvoid Unk095560_Unk_0958a8();'),
('src/game/unit_020df5b8.c',[
('func_020df5b8','''u8 *func_020df5b8(int i)
{
    u32 r = func_020445d0(32, 0);
    func_0204fe18(r);
    return func_0204fde0(r) + i * 42;
}'''),
],'u32 func_020445d0();\nvoid func_0204fe18();\nu8 *func_0204fde0();'),
('src/SaveLoadTask.c',[
('func_020df7c4','''int func_020df7c4(void)
{
    if (func_02050628(4) != 0 || func_02050628(5) != 0) {
        return 1;
    }
    return 0;
}'''),
],'int func_02050628();'),
('src/game/unit_020e1648.c',[
('func_020e1664','''u32 func_020e1664(void)
{
    if (Unk0e1648_Unk_0e1648() != 0) {
        return 0;
    }
    return FIELD(u32, FIELD(u8 *, data_02176c78, 4), 88);
}'''),
('func_020e2d28','''int func_020e2d28(u8 *p)
{
    u16 *e;
    if (FIELD(u32, p, 104) != 1) {
        return 0;
    }
    e = (u16 *)func_020f3de8(1, FIELD(u16, p + FIELD(u32, p, 124) * 8, 212));
    return Unk09974c_GetEntryUnk08(*e) == 4;
}'''),
],'int Unk09974c_GetEntryUnk08();'),
]
