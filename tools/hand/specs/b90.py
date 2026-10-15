FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
MSG = '''typedef struct Unk06a224Msg {
    u8 flags[2];
    u8 pad_02[2];
    u32 w[16];
} Unk06a224Msg;
'''
SPECS=[
('src/game/unit_02068f18.c',[
('func_02069888','''void func_02069888(Unk068f18Ids *p, u16 *src)
{
    int i;
    int j;
    for (i = 0; i < 6; i++) {
        u16 v = src[i];
        if (v == 0) {
            continue;
        }
        for (j = 0; j < 6; j++) {
            if (v == p->ids[j]) {
                break;
            }
            if (p->ids[j] == 0) {
                p->ids[j] = v;
                break;
            }
        }
    }
}'''),
],'typedef struct Unk068f18Ids {\n    u8 pad_0000[40];\n    u16 ids[6];\n} Unk068f18Ids;\n'),
('src/game/unit_0206a224.c',[
('func_0206aa0c','''void func_0206aa0c(void)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[1] = 24;
    m.flags[0] |= 2;
    func_020bcbc4(3, &m);
}'''),
('func_0206aafc','''void func_0206aafc(u32 x)
{
    Unk06a224Msg m;
    int i;
    for (i = 0; i < 2; i++) {
        m.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        m.w[i] = 0;
    }
    m.w[7] = x;
    m.w[1] = 2;
    m.flags[0] |= 0x82;
    func_020bcbc4(3, &m);
}'''),
],MSG+'void func_020bcbc4();\n'),
]
