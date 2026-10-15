FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_020c855c.c',[
('func_020ca550','''void func_020ca550(u32 *p)
{
    p[0] = 32;
    p[1] = 0;
    p[3] = 0;
    p[4] = (u32)func_020ca2e4;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = (u32)func_020c9ee0;
}'''),
('func_020ca648','''void func_020ca648(int k)
{
    int j;
    switch (k) {
    case 0:
        func_0205bb68();
        break;
    case 1:
        func_0205bb68();
        break;
    case 2:
        for (j = 0; j < 12; j++) {
            func_0205bb68();
        }
        break;
    }
}'''),
],FX+'u32 func_020d353c();\nvoid func_020616c0();\nvoid func_020ca2e4();\nvoid func_020c9ee0();\nvoid func_0205bb68();'),
('src/game/unit_020ca69c.c',[
('func_020cae84','''int func_020cae84(u8 *p)
{
    if (FIELD(s8, p + 29696, 128) == 1) {
        return func_020ca6b0(p);
    }
    return func_020cab28(p);
}'''),
],FX+'int func_020ca6b0();\nint func_020cab28();'),
('src/game/unit_020caea8.c',[
('func_020cb084','''int func_020cb084(u32 i)
{
    int t = func_020445f4(10, 2);
    if ((u32)func_0204ff30(t) <= i && i <= (u32)func_0204ff64(t)) {
        return func_0204fed8(t, i);
    }
    return 0;
}'''),
],'int func_0204ff30();\nint func_0204ff64();'),
('src/game/unit_020cb0d0.c',[
('func_020cb274','''int func_020cb274(u8 *p)
{
    u32 k = ((u32)FIELD(u16, p, 50) << 16) >> 28;
    if (k == 14 || k == 1) {
        u8 b = p[35];
        if (b == 3 || b == 7) {
            return 1;
        }
    }
    return 0;
}'''),
('func_020cb2ec','''int func_020cb2ec(s32 x)
{
    return x > 0x15e;
}'''),
],FX),
('src/game/unit_020cb32c.c',[
('func_020cb504','''void func_020cb504(u32 a, u32 b, u32 c)
{
    func_02063920(a);
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk0cb32c_Unk_0cb4e4(b, c)));
}'''),
('func_020cb58c','''int func_020cb58c(u32 x)
{
    return func_0205caa0(x) >= func_0205ca88(x);
}'''),
('func_020cb7f0','''int func_020cb7f0(void)
{
    return Unk0e651c_Unk_0e666c(0x752) == 0;
}'''),
('func_020cca80','''int func_020cca80(u8 *p)
{
    return Unk122e1c_Unk_122f88(FIELD(u32, p, 148), 0, Unk0e651c_Unk_0e666c(0x5f1));
}'''),
],'void func_02063920();\nint func_02063a30();\nvoid func_02061f10();\nint func_0205caa0();\nint func_0205ca88();\nint Unk0e651c_Unk_0e666c();\nint Unk122e1c_Unk_122f88();',
[('void Unk0cb32c_Unk_0cb4e4(u32 arg0,u32 arg1);','int Unk0cb32c_Unk_0cb4e4(u32 arg0, u32 arg1);'),
 ('''void Unk0cb32c_Unk_0cb4e4(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = func_020445f4(0x1e,arg0);
  func_0204fed8(tmp1,arg1);
}''','''int Unk0cb32c_Unk_0cb4e4(u32 arg0, u32 arg1)
{
    return func_0204fed8(func_020445f4(0x1e, arg0), arg1);
}''')]),
]
# skipped: func_020c9eb0 (ROM also spills the result to [sp]; unexplained)
