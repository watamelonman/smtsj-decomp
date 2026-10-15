P='''void func_02035db8();
void func_02036318();
void func_0209e0b0();
int Unk095560_Thunk_020961a0();
void func_020305a8();
void func_020a269c();
void Unk0a4e48_Unk_0a4e9c();
int func_02035c90();
void Unk02f2a8_Unk_0306a8(int *arg0);

typedef struct Unk02f2a8Obj39160 {
    u32 unk_0000;
    u32 pad_0004_0 : 16;
    u32 unk_0004_16 : 4;
} Unk02f2a8Obj39160;'''
SPECS=[('src/game/unit_0202f2a8.c',[
('func_02030548','''void func_02030548(u8 *p)
{
    u8 *a = (u8 *)Unk02e000_GetWorkArea();
    u8 *b = (u8 *)Unk02e000_GetWorkArea();
    func_02035db8(p + 0x70, FIELD(s8, a, 0x364), FIELD(s8, b, 0x365));
}'''),
('func_02031408','''void func_02031408(GameState *gs)
{
    s8 x = FIELD(s8, gs, 0x744e);
    s8 y = FIELD(s8, gs, 0x744f);
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 t = FIELD(s32, gs, 0x7450);
    u32 v = FIELD(u32, w, 0x358);
    if (t != -1) {
        v = t;
    }
    func_02036318(x, y, v);
}'''),
('func_02032a08','''int func_02032a08(int *p)
{
    func_0209e0b0();
    if (Unk095560_Thunk_020961a0() != 0) {
        return;
    }
    Unk02f2a8_Unk_0306a8(p);
    func_020305a8(p, 1);
    func_020a269c(1);
}'''),
('func_02032df4','''void func_02032df4(GameState *gs)
{
    FIELD(u32, gs, 0x7478) = 0;
    FIELD(u8, gs, 0x7481) = 0;
    FIELD(u32, gs, 0x7484) = 0;
    Unk0a4e48_Unk_0a4e9c(2);
}'''),
('func_020333b4','''void func_020333b4(GameState *gs)
{
    FIELD(u32, gs, 0x7478) = 0;
    FIELD(u8, gs, 0x7480) = 0;
    FIELD(u8, gs, 0x7481) = 0;
    FIELD(u32, gs, 0x7484) = 0;
    FIELD(u32, gs, 0x7488) = 0;
    if (FIELD(u32, gs, 0x73dc) != 0) {
        return;
    }
    func_020a269c(0);
    func_0205257c(3);
    Unk0a4e48_Unk_0a4e9c(2);
    func_020a0da4(5);
}'''),
('func_02034a44','''u32 *func_02034a44(int a, int b)
{
    return (u32 *)gGameState->unk_38e8 + func_02035c90(a, b);
}'''),
('func_02034a68','''u32 *func_02034a68(void)
{
    return func_02034a44(FIELD(s8, gGameState, 0x7482), FIELD(s8, gGameState, 0x7483));
}'''),
('func_02034ab0','''u32 func_02034ab0(void)
{
    u32 r = 0;
    Unk02f2a8Obj39160 *o = (Unk02f2a8Obj39160 *)func_02039160();
    if (o != 0) {
        r = o->unk_0004_16;
    }
    return r;
}'''),
],P)]
