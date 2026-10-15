FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_02044904.c',[
('func_020465c0','''int func_020465c0(u16 *p)
{
    int f;
    if (Unk044904_Unk_045460(1) != 0 && FIELD(u16, Unk044904_Get_data_0215ee98(), 56) == 0) {
        f = 1;
    } else {
        f = 0;
    }
    func_020ae0d8(FIELD(u32, Unk044904_Get_data_0215ee98(), 140), f, 0);
    *p = 2;
    Unk044904_Unk_044fd8();
    Unk0aa118_Clear814();
    return 1;
}'''),
],FX+'int Unk044904_Unk_045460();\nvoid func_020ae0d8();\nint Unk044904_Unk_044fd8();\nint Unk0aa118_Clear814();\n'),
('src/game/unit_02047338.c',[
('func_020474a0','''int func_020474a0(u16 *p)
{
    u32 *it;
    int o;
    if (Unk09d060_Unk_09d13c() == 0) {
        return 0;
    }
    it = (u32 *)Unk0aa118_PeekItem(Unk044904_Unk_044fd8());
    if (it != 0) {
        o = func_02044ec4(it[0]);
        if (o != 0) {
            func_0204a780(o, 6);
        }
        if (func_020f8098(Unk044904_Unk_045080(), 2, it[0]) != 0) {
            *p = 2;
        }
    }
    return 2;
}'''),
],'int Unk09d060_Unk_09d13c();\nint Unk044904_Unk_044fd8();\nint Unk0aa118_PeekItem();\nint func_02044ec4();\nvoid func_0204a780();\nint Unk044904_Unk_045080();\nint func_020f8098();\n'),
('src/game/unit_0204bb9c.c',[
('func_0204c404','''void func_0204c404(int x, int y)
{
    u8 *a;
    u8 *b;
    if (data_0215eea4 == 0) {
        return;
    }
    a = (u8 *)GameState_GetBody();
    b = (u8 *)GameState_GetBody();
    Unk04bb9c_SetCtxUnk0c((s16)(x - FIELD(u8, FIELD(u8 *, a, 852), 8)), (s16)(y - FIELD(u8, FIELD(u8 *, b, 852), 9)), 20);
}'''),
],FX+'int GameState_GetBody();\nvoid Unk04bb9c_SetCtxUnk0c(s16 a, s16 b, u16 c);\n'),
]
