SPECS=[
('src/game/unit_020981dc.c',[
('func_02098324','''int func_02098324(int a, int b)
{
    if (b != 0) {
        s8 *pa = (s8 *)func_020982c0(a);
        if (((s8 *)func_020982c0(b))[1] <= pa[1]) {
            return 0;
        }
    }
    return 1;
}'''),
],'int func_020982c0();'),
('src/game/unit_020986ac.c',[
('func_020986d4','''void func_020986d4(int bit, int on)
{
    u8 *p = (u8 *)Unk0986ac_Unk_0986c0(bit);
    u8 m = 1 << (bit & 7);
    if (on) {
        *p |= m;
    } else {
        *p &= ~m;
    }
}'''),
('func_02098714','''int func_02098714(int bit)
{
    u8 *p = (u8 *)Unk0986ac_Unk_0986c0(bit);
    return (*p & (u8)(1 << (bit & 7))) != 0;
}'''),
('func_020989a4','''void func_020989a4(int a, u8 *p, int c)
{
    func_02061f10(a, -1, 0, 0, func_0204fed8(FIELD(u32, p, 4), c));
}'''),
('func_020989dc','typedef struct Unk0986acPair {\n    s8 a;\n    s8 b;\n} Unk0986acPair;\n\n'+'''u32 func_020989dc(const Unk0986acPair *t)
{
    u32 j;
    for (j = 0; j < 23; j++) {
        if (t[j].a == 0) {
            return j;
        }
    }
    return 23;
}'''),
('func_02098aa8','''void func_02098aa8(u8 *p)
{
    s32 n = FIELD(s32, p, 56);
    if (n <= 0) {
        FIELD(s32, p, 64) = 0;
        FIELD(u8, p, 68) = 0;
        return;
    }
    FIELD(s32, p, 64) = (FIELD(s32, p, 60) - 16) * n + 16;
    FIELD(u8, p, 68) = n * 31;
}'''),
('func_02098ae0','''int func_02098ae0(u8 *p)
{
    u32 v = FIELD(u32, p, 44);
    int r = 0;
    switch (v) {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        r = 1;
        break;
    }
    return r;
}'''),
],'int func_0204fed8();\nvoid func_02061f10();',[('void func_02098714(void);','int func_02098714(int bit);'),('void Unk0986ac_Thunk_02098714(void);\n','int Unk0986ac_Thunk_02098714(int bit);\n'),('void Unk0986ac_Thunk_02098714(void) { func_02098714(); }','int Unk0986ac_Thunk_02098714(int bit) { return func_02098714(bit); }')]),
]
