FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def lut(fn, tab):
    return (fn, f'''int {fn}(u32 x)
{{
    return {tab}[(s32)(x & 0xc000) >> 14][(x & 0xc0000000) >> 30];
}}''')
SPECS=[
('src/game/unit_021241ec.c',[
('func_02124224','''void func_02124224(int x)
{
    Unk0fedd4_Unk_0fee38(Unk0cb32c_Unk_0cb4e4((u8)func_020cb3dc(), (u16)(x + 200)));
}'''),
],'int func_020cb3dc();\nint Unk0cb32c_Unk_0cb4e4();\nvoid Unk0fedd4_Unk_0fee38();'),
('src/game/unit_0212449c.c',[
('func_02124590','''void func_02124590(u8 *p)
{
    if (FIELD(u32, p, 60) == 0) {
        return;
    }
    FIELD(u32, p, 40) = 0;
    func_021245bc(p);
    FIELD(u32, p, 40) = 1;
}'''),
],FX+'void func_021245bc();'),
('src/game/unit_02124c5c.c',[
('func_02124cc4','''void func_02124cc4(void)
{
    func_020e7f44(0, 0, 0, 0);
    func_02124ce8(2);
}'''),
('func_02124dac','''int func_02124dac(void)
{
    u8 *p = (u8 *)*data_02176e88;
    if (p != 0 && FIELD(s8, p, 8) == 0) {
        return 1;
    }
    return 0;
}'''),
('func_02124dd8','''int func_02124dd8(void)
{
    u8 *p = (u8 *)*data_02176e88;
    if (p != 0 && FIELD(s8, p, 8) == 31) {
        return 1;
    }
    return 0;
}'''),
('func_02124e04','''int func_02124e04(void)
{
    u8 *p = (u8 *)*data_02176e88;
    if (p == 0) {
        return 1;
    }
    switch (FIELD(u32, p, 4)) {
    case 0:
        return func_02124dac();
    case 1:
        return func_02124dd8();
    }
    return 1;
}'''),
],FX+'void func_020e7f44();\nint func_02124dac(void);\nint func_02124dd8(void);'),
('src/game/unit_02124e68.c',[
('func_02124e68','''void func_02124e68(u32 a, u32 b, u32 c)
{
    data_02176e88->unk_00 = a;
    data_02176e88->unk_18 = b;
    data_02176e88->unk_19 = c;
    data_02176e88->unk_1a = 0;
}'''),
],'typedef struct Unk124e68Obj {\n    u32 unk_00;\n    u8 pad[0x14];\n    u8 unk_18;\n    u8 unk_19;\n    u8 unk_1a;\n} Unk124e68Obj;\nextern Unk124e68Obj *data_02176e88;'),
('src/ImageBgDual3D.c',[
('func_02125910','''void func_02125910(u32 x)
{
    u8 *q;
    if (func_02061698(data_02176e90) == 0) {
        return;
    }
    q = (u8 *)func_020616c0(data_02176e90);
    ImageBgDual3D_Thunk_021255b4();
    FIELD(u32, q, 128) = x;
    FIELD(u32, q, 0) = 0;
}'''),
('func_02125c68','''void func_02125c68(void)
{
    if (*data_02176e98 != 0) {
        return;
    }
    *data_02176e98 = func_0205ba98(0x28000, 0x800, data_02152180, 22);
}'''),
],'#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\nextern u8 data_02176e90[];\nint func_02061698();\nint func_020616c0();\nextern u8 data_02152180[];\nu32 func_0205ba98();\nvoid ImageBgDual3D_Thunk_021255b4(void);'),
]
