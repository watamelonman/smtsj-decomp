def two(fn, off, k=0):
    return (fn, f'''int {fn}(u32 a, u32 b)
{{
    int o = Unk0e5fb8_GetOffset{off}(b);
    int lo = Unk094fe0_TestBit(a, o{" + %d" % k if k else ""});
    return (u8)(lo | (Unk094fe0_TestBit(a, o + {k+1}) << 1));
}}''')
LIM = 'LIMIT'
SPECS=[
('src/game/unit_020e5fb8.c',[two('func_020e6360','B00'),two('func_020e63e0','D00'),two('func_020e6460','D80'),two('func_020e64e0','D80',2)],
 'int Unk094fe0_TestBit();'),
('src/game/unit_020e651c.c',[
('func_020e6574','''int func_020e6574(u32 a, u32 b)
{
    return func_020e6594(Unk094fe0_Thunk_0202e8cc(), a, b);
}'''),
('func_020e6594','''int func_020e6594(u32 a, u32 b, u32 c)
{
    if (c >= 64) {
        return 0;
    }
    return Unk094fe0_TestBit200(a, c + b * 128);
}'''),
('func_020e65b0','''void func_020e65b0(u32 b, u32 c, u32 v)
{
    if (c >= 64) {
        return;
    }
    Unk094fe0_Unk_095204(c + b * 128, v);
}'''),
('func_020e65cc','''int func_020e65cc(u32 a, u32 b)
{
    return func_020e65ec(Unk094fe0_Thunk_0202e8cc(), a, b);
}'''),
('func_020e65ec','''int func_020e65ec(u32 a, u32 b, u32 c)
{
    int o;
    int lo;
    if (c >= 32) {
        return 0;
    }
    o = b * 128 + 64 + c * 2;
    lo = Unk094fe0_TestBit200(a, o);
    return (u8)(lo | (Unk094fe0_TestBit200(a, o + 1) << 1));
}'''),
('func_020e6630','''void func_020e6630(u32 b, u32 c, int v)
{
    int o;
    if (c >= 32) {
        return;
    }
    o = b * 128 + 64 + c * 2;
    Unk094fe0_Unk_095204(o, v & 1);
    Unk094fe0_Unk_095204(o + 1, (v & 2) >> 1);
}'''),
('func_020e6684','''int func_020e6684(u32 a, u32 b)
{
    if (b > 0x7ff) {
        return 0;
    }
    return Unk094fe0_TestBit(a, b);
}'''),
('func_020e66a4','''void func_020e66a4(u32 i, u32 v)
{
    if (i > 0x7ff) {
        return;
    }
    Unk094fe0_Call_0209502c(i, v);
}'''),
],'int func_020e6594(u32 a, u32 b, u32 c);\nint func_020e65ec(u32 a, u32 b, u32 c);\nint Unk094fe0_TestBit200();\nvoid Unk094fe0_Unk_095204();\nint Unk094fe0_TestBit();'),
]
