def tbl(fn, k, stride):
    idx = 'base + i' if stride == 2 else 'base + i'
    return (fn, f'''u8 *{fn}(int i)
{{
    int t = func_020445d0(9, {k});
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {{
        return base;
    }}
    return base + i * {stride};
}}''')
SPECS=[
('src/game/unit_0209d42c.c',[
('func_0209d60c','''u8 func_0209d60c(int a, int b)
{
    if (a == 0) {
        return 1;
    }
    if (b != 0) {
        switch (a) {
        case 62:
            return 65;
        case 63:
            return 66;
        case 64:
            return 67;
        }
    }
    return a;
}'''),
tbl('func_0209d65c', 0, 2),
tbl('func_0209d6a4', 1, 106),
tbl('func_0209d6f0', 2, 24),
tbl('func_0209d7a8', 3, 52),
('func_0209df70','''int func_0209df70(u8 *p)
{
    int r = 0;
    u8 *cell;
    func_02052da0(p);
    cell = (u8 *)Unk02f2a8_GetCell38e8(FIELD(s8, p + 29696, 130), FIELD(s8, p + 29696, 131));
    FIELD(u16, cell, 2) += 1;
    if (Unk09a268_Unk_09a844() == 1) {
        r = 1;
    }
    return r;
}'''),
('func_0209e080','''int func_0209e080(u8 *p)
{
    int r = 1;
    int (**ent)(void) = (int (**)(void))Unk1124f0_Unk_11259c(FIELD(u32, p + 28672, 1004));
    if (ent[1] != 0) {
        r = ent[1]();
    }
    return r;
}'''),
('func_0209e274','''int func_0209e274(void)
{
    u8 *gs = (u8 *)GetGameState();
    if (gs == 0) {
        return 1;
    }
    return FIELD(s32, gs + 28672, 1000) == -1;
}'''),
],'''int func_020445d0();
int func_0204fde0();
int func_0204fe18();
void func_02052da0();
int Unk02f2a8_GetCell38e8();
int Unk09a268_Unk_09a844();
int Unk1124f0_Unk_11259c();'''),
('src/game/unit_0209ee4c.c',[
('func_0209efb4','''void func_0209efb4(u32 id)
{
    u8 *gs = (u8 *)GetGameState();
    void (**ent)(u32);
    if (gs == 0) {
        return;
    }
    ent = (void (**)(u32))Unk1124f0_Unk_11259c(id);
    if (ent[0] != 0) {
        ent[0](id);
    }
    FIELD(u32, gs + 28672, 1000) = 22;
    FIELD(u32, gs + 28672, 1004) = id;
}'''),
('func_0209eff8','''u16 func_0209eff8(void)
{
    u8 *gs = (u8 *)GetGameState();
    if (gs == 0) {
        return 0;
    }
    return (u16)((FIELD(u32, gs + 28672, 960) << 12) >> 22);
}'''),
],'int Unk1124f0_Unk_11259c();'),
]
