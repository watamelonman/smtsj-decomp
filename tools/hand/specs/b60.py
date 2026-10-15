FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
CMPID = lambda fn: (fn, f'''int {fn}(u16 *a, u16 *b)
{{
    int d = ((u8 *)a)[2] - ((u8 *)b)[2];
    u8 *ra;
    if (d == 0) {{
        ra = (u8 *)func_020a1428(a[0]);
        d = ((u8 *)func_020a1428(b[0]))[3] - ra[3];
        if (d == 0) {{
            d = a[0] - b[0];
        }}
    }}
    return d;
}}''')
SPECS=[
('src/game/unit_020fd9f0.c',[
('func_020fde0c','''void func_020fde0c(u8 *p)
{
    switch (FIELD(u32, p, 44)) {
    case 0:
        return;
    case 1:
        func_020fde4c(p);
        func_020fe004(p);
        return;
    case 2:
        func_020fe1f8(p);
        return;
    }
}'''),
('func_020fe1c8','''u32 func_020fe1c8(int x)
{
    switch (x) {
    case 1:
        return 0xff0000;
    case 2:
        return 0xff000000;
    }
    return 0x299ce700;
}'''),
],'void Unk0fd9f0_Unk_0fdc0c();\nvoid Unk0fd9f0_Unk_0fe33c();\nvoid func_020fde4c();\nvoid func_020fe004();\nvoid func_020fe1f8();'),
('src/game/unit_020feba0.c',[
('func_020fec64','''void func_020fec64(u32 *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    Unk0feba0_Unk_0fed7c(p);
}'''),
('func_020fed54','''void func_020fed54(int *p)
{
    if (p[3] == 0) {
        return;
    }
    func_020f51dc(p[0], p[1], p[3], 100 - p[5]);
}'''),
],'void Unk0feba0_Unk_0fed7c();\nvoid func_020f51dc();'),
('src/game/unit_020fedd4.c',[
],'u32 func_020fef0c();'),
('src/game/unit_020ff030.c',[
],'int func_02057eb8();\nvoid func_020572d8();'),
('src/CaveNpc.c',[
('func_020ffd14','''void func_020ffd14(u8 *p, int f)
{
    if (f != 0) {
        if (FIELD(u32, p, 16) != 0) {
            return;
        }
        p[12] = 5;
        FIELD(u32, p, 16) = 1;
    } else {
        FIELD(u32, p, 16) = 0;
    }
}'''),
],''),
('src/game/unit_02100810.c',[
('func_021069c8','''void func_021069c8(u32 a)
{
    if (data_02176e2c == 0) {
        return;
    }
    func_02008904(a, data_02176e2c + 8128, 60);
}'''),
('func_021071b8','''int func_021071b8(void)
{
    if (data_02176e2c == 0) {
        return 0;
    }
    return FIELD(u32, data_02176e2c, 80) == 1;
}'''),
],'extern u8 *data_02176e2c;\nvoid Unk100810_Unk_107154();\nvoid Unk0bc1a8_Unk_0bc928();\nvoid func_02008904();'),
]
