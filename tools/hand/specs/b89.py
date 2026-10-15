FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_02065e88.c',[
('func_0206646c','''void func_0206646c(u32 *p)
{
    p[0] = 1104;
    p[1] = 4;
    p[3] = 0;
    p[4] = (u32)func_020667d0;
    p[5] = (u32)Unk065e88_Nop_066c90;
    p[6] = (u32)func_02066c94;
    p[7] = (u32)func_02066d30;
    p[8] = (u32)func_020664c4;
}'''),
('func_020672fc','''void func_020672fc(u8 *p, int a, u32 n)
{
    int r;
    int h;
    u32 i;
    func_02063920();
    h = func_020445f4(12, a);
    for (i = 0; i < n; i++) {
        r = func_02063a30(func_0204fed8(h, i));
    }
    func_02061f10(FIELD(u32, p, 264), -1, 0, 0, r);
}'''),
],FX+'void func_020667d0();\nvoid Unk065e88_Nop_066c90();\nvoid func_02066c94();\nvoid func_02066d30();\nvoid func_020664c4();\nvoid func_02063920();\nint func_020445f4();\nint func_0204fed8();\nint func_02063a30();\nvoid func_02061f10();\n'),
('src/game/unit_02068f18.c',[
('func_0206a1a8','''int func_0206a1a8(u8 *p, int key)
{
    int r;
    u8 *w;
    s8 i;
    if (p[178] == 0) {
        return -1;
    }
    r = -1;
    w = (u8 *)Unk02e000_GetWorkArea();
    for (i = 0; i < p[178]; i++) {
        s8 k = FIELD(s8, w + i + 0x300, 72);
        if (k >= 0 && key == FIELD(u16, FIELD(u8 *, p + k * 4, 288), 54)) {
            r = k;
            break;
        }
    }
    return r;
}'''),
],FX+'int Unk02e000_GetWorkArea();\n'),
('src/game/unit_0206a224.c',[
('func_0206a998','''void func_0206a998(Unk06a224Ctl *c, int i)
{
    u8 *p = (u8 *)c;
    if (c->slots[i] != 0) {
        func_02099b10(*c->slots[i], 1);
    }
    {
        c->slots[i] = 0;
        FIELD(u16, p + 0x100, 84) = 0;
        FIELD(u16, p + 0x100, 86) = 0;
        func_02067d54(p);
        FIELD(s16, p + 0x100, 88) = Unk06a224_CountUsedSlots();
        FIELD(s16, p + 0x100, 88)++;
    }
}'''),
],'typedef struct Unk06a224Ctl {\n    u8 pad_0000[348];\n    u16 *slots[4];\n} Unk06a224Ctl;\nvoid func_02099b10();\nvoid func_02067d54();\ns16 Unk06a224_CountUsedSlots(void);\n'),
]
