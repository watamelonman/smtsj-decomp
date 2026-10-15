FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
H='int func_0203ac00();\nint Unk03aae8_Unk_03acf4();\n'
SPECS=[
('src/game/unit_0203ce68.c',[
('func_0203ced0','''int func_0203ced0(void)
{
    u16 v;
    u16 *w;
    func_0203ac00(0);
    v = func_0203ac00(1);
    w = (u16 *)Unk02e000_Thunk_0202e788();
    switch (Unk09974c_GetEntryUnk08(v)) {
    case 0:
    case 1:
    case 2:
        break;
    case 3: w[0] = v; break;
    case 4: w[1] = v; break;
    case 5: w[2] = v; break;
    case 6: w[3] = v; break;
    }
    return 1;
}'''),
('func_0203d0f0','''int func_0203d0f0(void)
{
    int k = func_0203ac00(0);
    int x = func_0203ac00(1);
    int y = func_0203ac00(2);
    u32 e = Unk03ce68_Unk_03d038(x);
    if (k == 0) {
        func_02097220(e, (s16)y);
    } else if (k >= 1 && k <= 3) {
        Unk0981dc_Unk_0981f4((u8)(k - 1), e, (s16)y);
    }
    return 1;
}'''),
],H+'u8 *Unk02e000_Thunk_0202e788();\nint Unk09974c_GetEntryUnk08();\nvoid func_02097220();\nvoid Unk0981dc_Unk_0981f4();\nu32 Unk03ce68_Unk_03d038(u32 arg0);\n'),
('src/game/unit_0203d930.c',[
('func_0203da10','''int func_0203da10(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    u8 *o;
    func_020d2b98(a, (u8)b);
    Unk10a034_Unk_10af40(a);
    if (func_02065544() == 0) {
        func_02065c10();
    }
    func_020656ac(Unk0d297c_Unk_0d2f98(24), -1);
    o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    FIELD(u32, o, 24) = 30;
    Unk0caea8_Unk_0caf98(1);
    Unk0a0ce4_Unk_0a0da4(40);
    return 3;
}'''),
],FX+'void func_020d2b98();\nint Unk10a034_Unk_10af40();\nint Unk0d297c_Unk_0d2f98();\n'),
]
