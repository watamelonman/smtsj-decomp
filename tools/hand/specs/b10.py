CTX = 'FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8)'
SPECS=[
('src/game/unit_0203aae8.c',[('func_0203b93c','''int func_0203b93c(void)
{
    int v = func_0203ac00(0);
    int lo = func_0203ac00(1);
    int hi = func_0203ac00(2);
    if (lo <= v && v <= hi) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}''')],''),
('src/game/unit_0203b988.c',[('func_0203bab4','''int func_0203bab4(void)
{
    int x = func_0203ac00(0);
    switch (func_02095818()) {
    case 2:
        Unk02dcfc_SetCode25(func_020df348(x));
        break;
    case 3:
        Unk02dcfc_SetCode25(Unk116598_Unk_116738(x));
        break;
    }
    return 3;
}'''),
('func_0203bb00','''int func_0203bb00(void)
{
    int a = func_0203ac00(0);
    Unk0e651c_Unk_0e66f0(func_0203ac00(1), (u8)(a - 1));
    return 1;
}''')],'int func_02095818();\nint func_020df348();\nvoid Unk02dcfc_SetCode25();\nint Unk116598_Unk_116738();\nvoid Unk0e651c_Unk_0e66f0();'),
('src/game/unit_0203ce68.c',[('func_0203cf48','''int func_0203cf48(void)
{
    int v = Unk096754_Unk_096a14(func_0203ac00(0));
    int r = 1;
    if (v == -1) {
        r = 0;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}''')],'int Unk096754_Unk_096a14();'),
]
# skipped (ad14()->+0xe8 store picks r0 for the pointer; ROM uses r1): 0203bba4 0203bc40 0203c608 0203c718
