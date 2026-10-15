SPECS=[
('src/game/unit_0206ae94.c',[
('func_0206c0b0','''void func_0206c0b0(u32 o)
{
    u32 *p;
    if (o == 0) {
        return;
    }
    p = FIELD(u32 *, o, 0x360);
    if (p != 0) {
        *p = 0;
    }
    func_02061424(o);
}'''),
('func_0206c0d4','''int func_0206c0d4(u32 *a, u32 *b)
{
    if (*a < *b) {
        return -1;
    }
    return *a > *b;
}'''),
('func_0206c0f4','''void func_0206c0f4(int a, int b, int c, int d, int e, int f, int g, int h)
{
    func_0206c130(a, b, c, d, e, f, 0, g, h);
}'''),
('func_0206c8f8','''int func_0206c8f8(int x)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (func_0206e39c(x, i) & 0x1fffe000) {
            return 1;
        }
    }
    return 0;
}'''),
('func_0206ca30','''void func_0206ca30(int a, int b, int c, int d, int e, int f, int g)
{
    func_0206c938(a, b, c, d, e, 0, f, g);
}'''),
],'void func_02061424();\nvoid func_0206c130();\nu32 func_0206e39c();\nvoid func_0206c938();',[('int func_0206c0b0();\n','void func_0206c0b0();\n')]),
('src/game/unit_0206dddc.c',[('func_0206dddc','''u32 func_0206dddc(int i)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return *(u32 *)(data_0216baec + i * 328);
}''')],'extern u8 data_0216baec[];'),
('src/game/unit_0206e2a0.c',[
('func_0206e39c','''u32 func_0206e39c(int i, int j)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return *(u32 *)(data_0216bafc + i * 328 + j * 24);
}'''),
('func_0206e3d8','''void func_0206e3d8(int i, void *dst)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return;
    }
    func_020086bc(dst, data_0216bac8 + i * 328 + 188, 32);
}'''),
],'extern u32 data_0216bac4[];\nextern u8 data_0216bafc[];\nint func_020086bc();'),
]
