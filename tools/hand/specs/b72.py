H = '''int Unk02e000_Unk_02e884(void);
int Unk02e000_GetTier(int x);
int Unk02e000_FindIndex_02e3e4(int a);
typedef struct Unk02e000Ent {
    u8 pad[11];
    u8 unk_0b;
    u8 pad2[16];
    u16 unk_1c;
    u8 unk_1e_lo : 7;
    u8 unk_1e_hi : 1;
    u8 unk_1f_b0 : 1;
    u8 unk_1f_rest : 7;
    u8 pad3[4];
} Unk02e000Ent;
#define ENT(i) ((Unk02e000Ent *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc) + ((i) - 1))
'''
SPECS=[
('src/game/unit_0202e000.c',[
('func_0202e468','''u8 *func_0202e468(int i)
{
    u8 *p = (u8 *)Unk02e000_Unk_02e884();
    if (i < 3) {
        return p + i * 152;
    }
    if (i - 3 < 8) {
        return p + 456 + (i - 3) * 96;
    }
    if (i - 11 < 20) {
        return p + 1224 + (i - 11) * 64;
    }
    if (i - 31 < 60) {
        return p + 2504 + (i - 31) * 32;
    }
    return 0;
}'''),
('func_0202e968','''void func_0202e968(int i, int set)
{
    u8 m;
    u8 *w;
    if (i < 0 || i >= 90) {
        return;
    }
    m = 1 << (i & 7);
    w = Unk02e000_GetWorkArea();
    if (set != 0) {
        (w + 884)[i >> 3] |= m;
    } else {
        (w + 884)[i >> 3] &= ~m;
    }
}'''),
('func_0202ea10','''int func_0202ea10(u32 id, u32 a)
{
    Unk02e000Ent *e;
    if (id > 491) {
        return 0;
    }
    e = ENT(id);
    func_02008904(a, e, 36);
    e->unk_0b |= 2;
    return 1;
}'''),
('func_0202eab8','''int func_0202eab8(u32 id, u16 v)
{
    Unk02e000Ent *e;
    if (id > 491) {
        return 0;
    }
    e = ENT(id);
    e->unk_1c = v;
    if (e->unk_1c > 500) {
        e->unk_1c = 500;
    }
    return 1;
}'''),
('func_0202eb48','''int func_0202eb48(u32 id, int v)
{
    Unk02e000Ent *e;
    if (id > 491) {
        return 0;
    }
    e = ENT(id);
    if (v > 100) {
        e->unk_1e_lo = 100;
    } else {
        e->unk_1e_lo = (u8)v;
    }
    return 1;
}'''),
('func_0202ec48','''int func_0202ec48(u32 id, int v)
{
    Unk02e000Ent *e;
    if (id > 491) {
        return 0;
    }
    e = ENT(id);
    e->unk_1f_b0 = (u8)(v != 0);
    return 1;
}'''),
],H),
]
