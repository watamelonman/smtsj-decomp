FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def cell(fn, off, grid):
    return (fn, f'''u8 {fn}(int x, int y)
{{
    u8 *g = (u8 *)GetGameState();
    u8 *a = (u8 *)GameState_GetBody();
    u8 *b = (u8 *)GameState_GetBody();
    u8 *o = Unk038fbc_Unk_039160((u8 **)(g + {grid}), x + FIELD(u8, FIELD(u8 *, a, {off}), 8), y + FIELD(u8, FIELD(u8 *, b, {off}), 9));
    if (o == 0) {{
        return 0;
    }}
    return (FIELD(u32, o, 4) << 12) >> 28;
}}''')
SPECS=[
('src/game/unit_0204bb9c.c',[
('func_0204c98c','''int func_0204c98c(int a, int b, int c)
{
    s8 i;
    for (i = 0; i < 96; i++) {
        Unk04bb9cEnt *e = Unk02e000_Unk_02e89c(i);
        if (e->a == a && e->b == b && e->c == (c == 980 ? 0 : c)) {
            return e->kind;
        }
    }
    return 0;
}'''),
cell('func_0204cbe8', 572, 576),
cell('func_0204cc4c', 852, 856),
],FX+'typedef struct Unk04bb9cEnt {\n    u8 kind : 6;\n    u8 hi : 2;\n    u8 a;\n    u8 b;\n    u8 c;\n} Unk04bb9cEnt;\nUnk04bb9cEnt *Unk02e000_Unk_02e89c(int i);\nint GetGameState();\nint GameState_GetBody();\nu8 *Unk038fbc_Unk_039160(u8 **o, int x, int y);\n'),
('src/game/unit_02065e88.c',[
('func_02065ec0','''void func_02065ec0(u32 *p)
{
    p[0] = 120;
    func_02095818();
    p[1] = 4;
    FIELD(u16, p, 8) = 100;
    p[3] = (u32)func_02063b80;
    p[4] = (u32)func_020640c0;
    p[5] = (u32)func_0206541c;
    p[6] = (u32)func_02065438;
    p[7] = (u32)func_02063b08;
    p[8] = (u32)func_02063b4c;
}'''),
('func_02066078','''void func_02066078(u8 *p)
{
    if (p[56] != 0) {
        func_0205c704(FIELD(u32, p, 0));
    }
    if (p[57] == 0) {
        return;
    }
    {
        int n = func_0205ca88(FIELD(u32, p, 0));
        if (func_0205caa0(FIELD(u32, p, 0)) >= n - 1) {
            p[56] = 0;
            p[57] = 0;
        }
    }
}'''),
],FX+'void func_02095818();\nvoid func_02063b80();\nvoid func_020640c0();\nvoid func_0206541c();\nvoid func_02065438();\nvoid func_02063b08();\nvoid func_02063b4c();\nvoid func_0205c704();\nint func_0205ca88();\nint func_0205caa0();\n'),
]
