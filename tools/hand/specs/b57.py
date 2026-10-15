FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def fwd(fn, data, off):
    return (fn, f'''void {fn}(u32 a)
{{
    u32 w = *{data};
    Unk0e8228_Unk_0e8d90(FIELD(u32, w, {off}), Unk0f8448_GetUnkField10(a));
}}''')
FWD = 'int Unk0f8448_GetUnkField10();\nvoid Unk0e8228_Unk_0e8d90();'
SPECS=[
('src/game/unit_020efdf4.c',[fwd('func_020eff38','data_02176df4',76)],FX+'extern u32 data_02176df4[];\n'+FWD),
('src/game/unit_020efff4.c',[
('func_020f0078','''void func_020f0078(Unk0efff4Obj *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->unk_f8[i] = 0;
    }
}'''),
],'typedef struct Unk0efff4Obj {\n    u8 pad[0xf8];\n    u32 unk_f8[6];\n} Unk0efff4Obj;'),
('src/game/unit_020f0eac.c',[
fwd('func_020f0f08','data_02176dfc',76),
('func_020f0fe0','''int func_020f0fe0(u8 *a, u8 *b)
{
    int d = a[4] - b[4];
    if (d == 0) {
        d = FIELD(u16, a, 0) - FIELD(u16, b, 0);
    }
    return d;
}'''),
],FX+'extern u32 data_02176dfc[];\n'+FWD),
('src/game/unit_020f1128.c',[
('func_020f2d60','''void func_020f2d60(u32 x)
{
    u32 t = x;
    Unk0bd5f0_Unk_0c7f70(7, 0, &t, 1);
}'''),
],'void Unk0bd5f0_Unk_0c7f70();'),
('src/game/unit_020f3db4.c',[
('func_020f4160','''int func_020f4160(const char *s)
{
    return func_020152cc(s, data_02150e24) == 0;
}'''),
('func_020f4398','''void func_020f4398(Unk0f3db4Obj *p, int k)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->e[i].id != 0) {
            func_02099b10(p->e[i].id, k * p->e[i].n);
        }
    }
}'''),
('func_020f4448','''int func_020f4448(int id)
{
    u16 *q = (u16 *)Unk02e000_Thunk_0202e788();
    int n = func_0209993c(id);
    if (n <= 0) {
        return n;
    }
    if (id == q[0] || id == q[1] || id == q[2] || id == q[3]) {
        n--;
    }
    return n;
}'''),
],'extern char data_02150e24[];\nint func_020152cc();\nvoid func_02099b10();\nint Unk02e000_Thunk_0202e788();\nint func_0209993c();\ntypedef struct Unk0f3db4Ent {\n    u16 id;\n    u16 n;\n} Unk0f3db4Ent;\ntypedef struct Unk0f3db4Obj {\n    u8 pad[0xa];\n    Unk0f3db4Ent e[3];\n} Unk0f3db4Obj;'),
('src/game/unit_020f470c.c',[
('func_020f49f4','''void func_020f49f4(u8 *p)
{
    Unk0ea208_Unk_0ea70c();
    switch (FIELD(u32, p, 8)) {
    case 1:
    case 2:
        return;
    }
    func_020d1e94(1);
}'''),
],FX+'void func_020d1e94();'),
]
