FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
def load(fn, mx, sz, pd, nd):
    return (fn, f'''void {fn}(int i, void *src, int n)
{{
    if (n > {mx}) {{
        return;
    }}
    if (n > 0) {{
        u32 size = n * {sz};
        Unk06dddcRec *t = (Unk06dddcRec *){pd};
        void *p;
        t[i].v = (u32)(p = func_02052fe0(size));
        func_020086bc(src, p, size);
        FIELD(u32, {nd}, i * 328) = n;
    }}
}}''')
SPECS=[
('src/game/unit_0206ae94.c',[
('func_0206b8e4','''void func_0206b8e4(Unk06ae94Pt *p, void *m)
{
    int i;
    for (i = 0; i < 4; i++, p++) {
        s32 in[3];
        s32 out[3];
        s32 z = p->z;
        s32 y = p->y;
        s32 x = p->x;
        in[0] = x;
        in[1] = y;
        in[2] = z;
        func_02000f10(in, m, out);
        p->x = out[0];
        p->y = out[1];
        p->z = out[2];
    }
}'''),
('func_0206c854','''void func_0206c854(u8 *p)
{
    u8 *e = (u8 *)func_0206e334(p[48], FIELD(u32, p, 4));
    u32 k;
    int r;
    if (e == 0) {
        return;
    }
    k = FIELD(u32, e, 8) & 0xfc0;
    if (k == 0) {
        return;
    }
    r = 0;
    switch (k) {
    case 64: r = 8; break;
    case 128: r = 5; break;
    case 256: r = 3; break;
    }
    Unk0946e0_Unk_094704(Unk0939f0_Get_data_02175d8c(), r, r, e[20], 0);
}'''),
('func_0206d4e8','''void func_0206d4e8(Unk06ae94Obj *o)
{
    int i;
    if (o == 0) {
        return;
    }
    i = 0;
    o->unk_24 = i;
    for (; i < 50; i++) {
        Unk06ae94_Unk_06c0b0(o->objs[i]);
    }
    o->unk_24 = 0;
    o->unk_28 = 0;
    o->unk_2c = 0;
    o->unk_30 = 0;
    o->unk_48 = 0;
    o->unk_4c = 0;
    o->unk_50 = 0;
    if (o->unk_250 != 0) {
        *o->unk_250 = 0;
    }
    func_02061424(o);
}'''),
],FX+'typedef struct Unk06ae94Pt {\n    s16 x;\n    s16 y;\n    s16 z;\n    u8 pad_06[14];\n} Unk06ae94Pt;\ntypedef struct Unk06ae94Obj {\n    u8 pad_00[0x24];\n    u32 unk_24;\n    u32 unk_28;\n    u32 unk_2c;\n    u32 unk_30;\n    u8 pad_34[0x14];\n    u32 unk_48;\n    u32 unk_4c;\n    u32 unk_50;\n    u8 pad_54[0x1fc];\n    u32 *unk_250;\n    u8 pad_254[4];\n    s32 unk_258;\n    s32 unk_25c;\n    u32 objs[50];\n} Unk06ae94Obj;\nvoid func_02000f10();\nint func_0206e334();\nint Unk0939f0_Get_data_02175d8c();\nvoid Unk0946e0_Unk_094704();\nvoid Unk06ae94_Unk_06c0b0();\nvoid func_02061424();\n'),
]
