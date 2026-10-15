def getn(fn, cnt, base, sz, sh=''):
    return (fn, f'''u8 *{fn}(u32 *p, u32 i)
{{
    if (p == 0) {{
        return 0;
    }}
    if (func_0204fe18(p[{cnt}]) <= i) {{
        return 0;
    }}
    return (u8 *)p[{base}] + i * {sz};
}}''')
SPECS=[
('src/game/unit_020387bc.c',[getn('func_02038f18',1,2,32),getn('func_02038f48',3,4,36)],''),
('src/game/unit_02038fbc.c',[('func_02039204','''u8 *func_02039204(u32 *p, u32 i, u32 j)
{
    if (p == 0) {
        return 0;
    }
    if (((u8 *)p[0] + i)[12] <= j) {
        return 0;
    }
    {
        u8 *base = (u8 *)(p + i)[3];
        return base + j * Unk038fbc_Unk_039248(i);
    }
}''')],'u32 Unk038fbc_Unk_039248(u32 arg0);'),
('src/game/unit_020392f8.c',[('func_0203947c','''u8 *func_0203947c(u32 *p, u32 i)
{
    if (((u8 *)p[0])[7] <= i) {
        return 0;
    }
    return (u8 *)p[2] + i * 36;
}''')],''),
('src/game/unit_02039774.c',[('func_02039b74','''void func_02039b74(u32 key)
{
    u8 *o = data_0215de28;
    u8 *next;
    if (o == 0) {
        return;
    }
    do {
        next = FIELD(u8 *, o, 0xe4);
        if (FIELD(u32, o, 0xf4) == key) {
            Unk039774_Unk_039b10((int)o);
        }
        o = next;
    } while (o != 0);
}''')],'extern u8 *data_0215de28;\nvoid Unk039774_Unk_039b10(int arg0);'),
('src/game/unit_0203aae8.c',[
('func_0203af14','''int func_0203af14(void)
{
    if (Unk094fe0_Call_020950b4((s16)func_0203ac00(0))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}'''),
('func_0203b89c','''int func_0203b89c(void)
{
    u32 a = func_0203ac00(0);
    int b = func_0203ac00(1);
    if (a > (u32)func_02050074(0, b - 1)) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}''')],'int Unk094fe0_Call_020950b4();'),
]
