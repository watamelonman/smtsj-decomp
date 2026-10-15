SPECS=[
('src/game/unit_020d297c.c',[
('func_020d3004','''int func_020d3004(void)
{
    int v;
    if (*data_02176be0 == 0) {
        return 0;
    }
    v = func_0204fe68(*data_02176be0, 0);
    return func_0204fed8(v, 0);
}'''),
('func_020d3138','''int func_020d3138(void)
{
    return Unk0e651c_Unk_0e666c(0x751);
}'''),
('func_020d3264','''void func_020d3264(Unk0d297cU16Vec *v, u16 x)
{
    if (v->n < v->cap) {
        v->buf[v->n] = x;
        v->n++;
    }
}'''),
],'int Unk0e651c_Unk_0e666c();\ntypedef struct Unk0d297cU16Vec {\n    u16 *buf;\n    int n;\n    int cap;\n} Unk0d297cU16Vec;'),
('src/CampStatus.c',[
('func_020d51cc','''void func_020d51cc(void)
{
    int i;
    for (i = 59; i <= 64; i++) {
        Unk05b82c_Unk_05b82c(i);
    }
    func_020ca5a4(0);
    func_020ca5a4(2);
}'''),
('func_020d6c88','''void func_020d6c88(void *src)
{
    func_020119a0((u8 *)data_02176be4 + 300, src, 60);
}'''),
('func_020dcaac','''void func_020dcaac(void)
{
    FIELD(u32, data_02176be4, 244) = 0;
    FIELD(s16, data_02176be4, 270) = -80;
}'''),
],'void Unk05b82c_Unk_05b82c();\nvoid func_020ca5a4();\nvoid func_020119a0();'),
('src/game/unit_020ddeb0.c',[
('func_020ddf0c','''void func_020ddf0c(u32 a)
{
    u16 t[1];
    t[0] = 0;
    func_02061f10(a, -1, 0, 0, t);
}'''),
],'void func_02061f10();\ntypedef struct Unk0ddeb0Half {\n    u16 v;\n} Unk0ddeb0Half;'),
('src/game/unit_020de678.c',[
('func_020dea70','''int func_020dea70(Unk0de678Rec *p)
{
    int n = 0;
    int i = 0;
    for (; i < 4; i++) {
        if (p[i].unk_0a == 0) {
            break;
        }
        n++;
    }
    return n;
}'''),
('func_020debf8','''int func_020debf8(u32 a)
{
    int r = func_020dec18(a);
    if (r != 0) {
        *(u32 *)(((int)data_021508d4) + 0xcc) = 0;
    }
    return r;
}'''),
],'int func_020dec18();\ntypedef struct Unk0de678Rec {\n    u8 pad_00[0xa];\n    u16 unk_0a;\n    u8 pad_0c[0xe];\n} Unk0de678Rec;'),
]
