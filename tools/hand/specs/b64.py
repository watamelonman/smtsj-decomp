FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_0210a034.c',[
('func_0210b484','''int func_0210b484(u8 *p)
{
    u8 *q;
    if (FIELD(u32, p, 24) == 0) {
        return 0;
    }
    q = FIELD(u8 *, p, 20);
    switch (FIELD(u16, q, 24)) {
    case 2:
        return FIELD(int, q, 28);
    case 3:
        return Unk10a034_Unk_10b058(FIELD(u16, q, 26));
    }
    return 0;
}'''),
],FX),
('src/game/unit_02113294.c',[
('func_021150e8','''int func_021150e8(u32 a, u32 b)
{
    u16 *q = Unk113294_Unk_1150c8(a, b);
    u32 v = q[0];
    if (v == 0xffff) {
        v = q[1] & 0xff;
    }
    return v;
}'''),
('func_02115144','''void func_02115144(u8 *p)
{
    Unk113294Pair t = {0, 0};
    t.a = Unk113294_Unk_115124((int)p);
    func_02061f10(FIELD(u32, p, 196), -1, 0, 0, &t);
}'''),
('func_021155bc','''int func_021155bc(u32 id)
{
    if (id == 0) {
        return 0;
    }
    return id != Unk113294_Unk_115110();
}'''),
],'u16 *Unk113294_Unk_1150c8(u32 arg0, u32 arg1);\nint Unk113294_Unk_115124(int arg0);\nint Unk113294_Unk_115110(void);\ntypedef struct Unk113294Pair {\n    u16 a;\n    u16 b;\n} Unk113294Pair;'),
]
