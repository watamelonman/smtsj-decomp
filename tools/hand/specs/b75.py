FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_0202f2a8.c',[
('func_02030704','''void func_02030704(int a, s8 *src, int unused, int c, u8 e)
{
    s8 buf[17] = {0};
    int i;
    for (i = 0; i < 16; i++) {
        buf[i] = src[i];
    }
    func_02038ff8(a, buf, c, e);
}'''),
('func_020308c0','''void func_020308c0(u8 *p)
{
    s8 buf[17] = {0};
    int i;
    for (i = 0; i < 16; i++) {
        buf[i] = FIELD(s8, p + i, 64);
    }
    func_02039520(p, buf);
}'''),
('func_020313a4','''void func_020313a4(u8 *p)
{
    int bits = Unk02f2a8_GetObj39160Bits16(p + 576, FIELD(s8, p + 0x7400, 78), FIELD(s8, p + 0x7400, 79));
    int m = Unk02e000_Unk_02e8b8();
    u16 v = FIELD(u16, (u8 *)Unk02e000_GetWorkArea() + 0x300, 92);
    func_020a7474(p + 264 + 0x5400, m, p + 576, p + 24, v, bits, 1);
}'''),
],FX+'void func_02038ff8();\nvoid func_02039520();\nint Unk02e000_Unk_02e8b8();\nvoid func_020a7474();\n'),
]
