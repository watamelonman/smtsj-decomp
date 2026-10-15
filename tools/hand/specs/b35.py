def bounded(fn, callee):
    return (fn, f'''int {fn}(int i)
{{
    u8 *p;
    if (i < 0 || i >= 300) {{
        return -1;
    }}
    p = (u8 *)Unk0a0ce4_Unk_0a0ce4(i);
    return {callee}(p[1], p[0]);
}}''')
SPECS=[
('src/game/unit_0209ee4c.c',[
('func_0209f5d8','''int func_0209f5d8(u32 a, u32 id)
{
    u8 *e;
    if (((id >> 16) & 0xff) != 2) {
        return -1;
    }
    e = (u8 *)func_02044ec4(id);
    e = (u8 *)func_020a1740(FIELD(u16, e + 256, 216));
    return func_0209f550(a, id, e[3], 0);
}'''),
('func_0209fd14','''void func_0209fd14(u32 a, u32 b)
{
    int j;
    Unk044904_ClearSlotsUnk1de(a);
    for (j = 0; j < 4; j++) {
        func_0209f034(0, a, a, b, 1);
        b += 22;
    }
}'''),
],'int func_02044ec4();\nint func_020a1740();\nint func_0209f550();\nvoid Unk044904_ClearSlotsUnk1de();\nvoid func_0209f034();'),
('src/game/unit_020a0ce4.c',[
('func_020a0d68','''void func_020a0d68(int x)
{
    func_0205e65c();
    *data_02176afc = 5;
    func_0205e5ec(5);
    func_0205e5ec(x);
}'''),
bounded('func_020a0da4', 'func_0205e6c0'),
bounded('func_020a0dd8', 'func_0205e740'),
('func_020a0e0c','''u32 func_020a0e0c(int i)
{
    if (i >= 0 && i < 29) {
        return data_0214cc84[i];
    }
    return data_0214cc84[0];
}'''),
('func_020a0e44','''void func_020a0e44(void)
{
    switch (Unk0b6570_Get_data_02176b88()) {
    case 2:
        func_020967a4(0);
        Unk02cad4_Unk_02cbdc(10);
        break;
    case 3:
        Unk02cad4_Unk_02cbdc(15);
        break;
    case 4:
        Unk02cad4_Unk_02cbdc(1);
        break;
    }
}'''),
],'''int func_0205e65c();
int func_0205e5ec();
int func_0205e6c0();
int func_0205e740();
extern u32 data_0214cc84[];
int Unk0b6570_Get_data_02176b88();
void func_020967a4();
void Unk02cad4_Unk_02cbdc();'''),
('src/game/unit_020a163c.c',[
('func_020a1798','''u16 func_020a1798(u32 id)
{
    s32 v = FIELD(s16, func_020a1740(id), 106);
    if (v < 0) {
        return func_02011804(v);
    }
    return data_0213c244[data_0213c258[v]];
}'''),
('func_020a17d8','''int func_020a17d8(u32 id)
{
    u8 *e = (u8 *)func_020a1740(id);
    if (FIELD(s16, e, 106) < 0) {
        return 1;
    }
    return Unk02e000_GetRecordUnk1e(id) < e[90];
}'''),
('func_020a21f8','''void func_020a21f8(u8 *p)
{
    FIELD(u32, p, 12) = 1;
    func_020a208c();
}'''),
],'''int func_020a1740();
int func_02011804();
extern u8 data_0213c258[];
extern u8 data_0213c244[];
int Unk02e000_GetRecordUnk1e();'''),
]
# skipped: func_020a1b68 (needs a 3-arg u16 prototype for func_020a1b08 that conflicts with an existing 2-arg caller); func_0209f298 not tried
