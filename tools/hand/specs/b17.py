SPECS=[
('src/game/unit_02047788.c',[
('func_020477e4','''int func_020477e4(void)
{
    FIELD(u32, Unk044904_Get_data_0215ee98(), 0x50) = 0;
    func_020b6514(1);
    if (func_0205e4f8(-1) != 0) {
        return 0;
    }
    func_02116028();
    return 1;
}'''),
('func_02047834','''void func_02047834(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        u32 *o = ((Unk047788Mgr *)Unk044904_Get_data_0215ee98())->slots[i];
        if (o != 0) {
            u32 w = o[0];
            if ((w >> 16 & 0xff) == 2) {
                func_020a5fc8(Unk0a5680_GetEntryUnk14(w), 0);
            }
        }
    }
}'''),
],'typedef struct Unk047788Mgr {\n    u8 pad_0000[0x64];\n    u32 *slots[10];\n} Unk047788Mgr;\n\nvoid func_020b6514();\nint func_0205e4f8();\nvoid func_02116028();\nint Unk0a5680_GetEntryUnk14();\nvoid func_020a5fc8();',[('int func_02047834();\n','void func_02047834();\n')]),
('src/BattleTask.c',[('func_020484d0','''int func_020484d0(u32 *a, u32 *b)
{
    s16 x = 256;
    s16 y = 256;
    struct { s16 v; s16 pad; } tx, ty;
    if (*a != 0) {
        func_02049c28(*a, &tx);
        x = tx.v;
    }
    if (*b != 0) {
        func_02049c28(*b, &ty);
        y = ty.v;
    }
    return x - y;
}''')],'void func_02049c28();'),
('src/game/unit_0204bb9c.c',[
('func_0204c13c','''int func_0204c13c(int x)
{
    if (x == 2 || x == 0 || (u32)(x - 32) <= 2) {
        return 1;
    }
    return 0;
}'''),
('func_0204c464','''void func_0204c464(u16 a, u16 b, u16 c)
{
    if (data_0215eea4 == 0) {
        return;
    }
    data_0215eea4->unk_0008 = 1;
    data_0215eea4->unk_000c = a;
    data_0215eea4->unk_000e = b;
    data_0215eea4->unk_0010 = c;
}'''),
('func_0204c4a0','''int func_0204c4a0(void)
{
    if (data_0215eea4 == 0) {
        return 1;
    }
    return data_0215eea4->unk_0008 == 0;
}'''),
('func_0204cbc8','''u16 func_0204cbc8(void)
{
    if (data_0215eea4 == 0) {
        return 0;
    }
    return data_0215eea4->unk_0a20;
}'''),
],'',[('    u8 pad_0000[0xa14];\n    u32 unk_0a14;\n','''    u8 pad_0000[0x8];
    u32 unk_0008;
    u16 unk_000c;
    u16 unk_000e;
    u16 unk_0010;
    u8 pad_0012[0xa02];
    u32 unk_0a14;
    u8 pad_0a18[0x8];
    u16 unk_0a20;
''')]),
]
