FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_020e7290.c',[
('func_020e7770','''void func_020e7770(u32 a, u32 b)
{
    if (data_02176cd8 != 0) {
        FIELD(u32, data_02176cd8, 0) = a;
        FIELD(u32, data_02176cd8, 4) = b;
    }
}'''),
('func_020e77f0','''int func_020e77f0(u32 a)
{
    u32 k;
    if (data_02176cd8 == 0) {
        return 0;
    }
    k = FIELD(u32, data_02176cd8, 16);
    if (k != 5 && k != 0) {
        return 0;
    }
    FIELD(u32, data_02176cd8, 8) = 0;
    FIELD(u32, data_02176cd8, 12) = a;
    FIELD(u32, data_02176cd8, 16) = 0;
    return 1;
}'''),
],FX),
('src/game/unit_021241ec.c',[
('func_021242fc','''void func_021242fc(void)
{
    if (data_02176e84 == 0) {
        return;
    }
    FIELD(u32, data_02176e84, 40) = 1;
    FIELD(u32, data_02176e84, 44) = 0;
    FIELD(u32, data_02176e84, 60) = 1;
    FIELD(u32, data_02176e84, 56) = 0;
}'''),
],FX),
('src/game/unit_02124c5c.c',[
('func_02124d6c','''void func_02124d6c(u32 a, u32 b)
{
    if (data_02176e88 != 0) {
        FIELD(u32, data_02176e88, 12) = a;
        FIELD(u32, data_02176e88, 16) = b;
    }
}'''),
('func_02124d8c','''void func_02124d8c(u32 a, u32 b)
{
    if (data_02176e88 != 0) {
        FIELD(u32, data_02176e88, 4) = a;
        FIELD(u8, data_02176e88, 8) = b;
    }
}'''),
],FX),
]
