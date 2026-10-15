def fwd(fn, callee):
    return (fn, f'''void {fn}(int a, int b, int c, int d, int e, int f, int g)
{{
    {callee}(a, b, c, d, e, 0, f, g);
}}''')
T = 'Unk077Tbl *t = (Unk077Tbl *)ImageObj_Get_data_0217231c();'
SPECS=[
('src/game/unit_0206fb70.c',[
fwd('func_02071508','func_0207142c'),
fwd('func_02071974','func_02071898'),
('func_02071d28','''void func_02071d28(u8 *o)
{
    func_020703b4(o + 364, o + 44, o + 40, o + 48, o, o + 12, o + 24, o + 52);
}'''),
],'void func_0207142c();\nvoid func_02071898();\nvoid func_020703b4();'),
('src/game/unit_02071dc0.c',[
('func_02071e24','''void func_02071e24(void)
{
    func_02008848(data_02170d14, 0, 0x1608);
}'''),
('func_02072030','''int func_02072030(void)
{
    switch (FIELD(s32, data_02171d14, 0x604)) {
    case 4:
        return 1;
    case 5:
        return -1;
    }
    return 0;
}'''),
],'extern u8 data_02170d14[];\nint func_02008848();'),
('src/ImageObj.c',[
('func_02077478','''int func_02077478(int i, int b)
{
    '''+T+'''
    if (t->e[i] != 0) {
        return t->e[i];
    }
    return t->e[i] = func_02077900(i, b);
}'''),
('func_02077554','''void func_02077554(int i)
{
    '''+T+'''
    u32 o;
    if (t == 0 || (o = t->e[i]) == 0) {
        return;
    }
    if (func_02077a9c(o) != 0) {
        t->unk_00c4 = 1;
        return;
    }
    func_02077e74(o);
    ImageObj_Unk_079184(i);
}'''),
('func_02077708','''int func_02077708(void)
{
    int i;
    if (ImageObj_Get_data_0217231c() == 0) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        u32 *p = (u32 *)ImageObj_Unk_0778e8(i);
        if (p != 0 && p[1] != 0) {
            return 0;
        }
    }
    return 1;
}'''),
],'typedef struct Unk077Tbl {\n    u32 unk_0000;\n    u32 e[48];                  /* +0x04 */\n    u32 unk_00c4;\n} Unk077Tbl;\n\nu32 func_02077900();\nint func_02077a9c();\nvoid func_02077e74();\nvoid ImageObj_Unk_079184(int arg0);'),
]
