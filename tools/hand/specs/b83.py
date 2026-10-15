FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_0203dbbc.c',[
('func_0203dd98','''int func_0203dd98(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    s16 c = func_0203ac00(2);
    s16 d = func_0203ac00(3);
    func_0204c564(c, d, (s16)Unk02f2a8_Unk_035b08(a, b));
    return 3;
}'''),
],FX+'int func_0203ac00();\nint Unk02e000_GetWorkArea();\nint func_0204c98c();\nvoid func_0204c804();\nvoid func_0204c564();\nint Unk02f2a8_Unk_035b08();\n'),
('src/game/unit_0203e23c.c',[
('func_0203e3e4','''int func_0203e3e4(void)
{
    u16 id;
    int n;
    u32 old;
    id = func_0203ac00(0);
    n = func_0203ac00(1);
    old = Unk02e000_GetRecordUnk1e(id);
    if (BattleTask_Unk_0481d4() != 0) {
        func_020494d0(id, n);
    }
    Unk02e000_SetRecordUnk1e(id, old + n);
    return 1;
}'''),
],'int func_0203ac00();\nint Unk096754_Unk_096a14();\nint BattleTask_Unk_0481d4();\nu32 Unk02e000_GetRecordUnk1e(u32 id);\nint Unk02e000_SetRecordUnk1e();\nvoid Unk097514_Unk_0977f0();\nvoid func_020494d0();\n'),
('src/game/unit_0203e43c.c',[
('func_0203e8cc','''typedef struct Unk03e43cEnt { u8 pad[4]; u16 unk_04; u8 pad2[2]; } Unk03e43cEnt;
typedef struct Unk03e43cTab { u16 n; u8 pad[10]; Unk03e43cEnt *ents; } Unk03e43cTab;
int func_0203e8cc(u8 *p)
{
    Unk03e43cTab *q = FIELD(Unk03e43cTab *, p, 28);
    u32 sum = 0;
    u32 i;
    for (i = 0; i < q->n; i++) {
        sum += q->ents[i].unk_04;
    }
    if (FIELD(u16, p, 88) >= sum) {
        return 1;
    }
    FIELD(u16, p, 88)++;
    return 0;
}'''),
('func_0203f234','''void func_0203f234(s16 *a, s16 *b, int x, int y)
{
    int v = *a;
    int d = x - v;
    if (d < 0) {
        d = -d;
    }
    if (d > 256) {
        if (v < x) {
            *a += 512;
        } else if (v > x) {
            *a -= 512;
        }
    }
    v = *b;
    d = y - v;
    if (d < 0) {
        d = -d;
    }
    if (d > 128) {
        if (v < y) {
            *b += 256;
        } else if (v > y) {
            *b -= 256;
        }
    }
}'''),
],FX),
]
