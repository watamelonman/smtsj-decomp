def rng(fn, test):
    return (fn, f'''int {fn}(int id)
{{
    if (id >= 51 && id <= 110) {{
        u8 v = ((u8 *)func_02099d14(id))[45];
        if ({test}) {{
            return 1;
        }}
    }}
    return 0;
}}''')
SPECS=[
('src/game/unit_020986ac.c',[
('func_02099234','''void func_02099234(u8 *p)
{
    FIELD(s32, p, 56) -= 1;
    Unk0986ac_Unk_098aa8(p);
    if (FIELD(s32, p, 56) > 0) {
        return;
    }
    FIELD(s32, p, 24) = 0;
    FIELD(s32, p, 40) = 0;
    FIELD(s32, p, 56) = 0;
    FIELD(s32, p, 64) = 0;
    FIELD(u8, p, 68) = 0;
}'''),
('func_02099274','''void func_02099274(u8 *p)
{
    FIELD(s32, p, 20) = FIELD(s32, p, 24);
    FIELD(s32, p, 24) = -1;
    switch (FIELD(s32, p, 20)) {
    case 2:
        func_0209911c(p);
        break;
    case 3:
        Unk0986ac_Nop_099230();
        break;
    }
}'''),
('func_020992b0','''void func_020992b0(u8 *p)
{
    switch (FIELD(u32, p, 20)) {
    case 0:
        break;
    case 1:
        if (func_020a246c() == 1) {
            FIELD(s32, p, 24) = 2;
        }
        break;
    case 2:
        func_02099174(p);
        break;
    case 3:
        break;
    case 4:
        func_02099234(p);
        break;
    }
}'''),
],'void func_0209911c();\nvoid func_02099174();\nint func_020a246c();\nvoid func_02099234(u8 *p);'),
('src/game/unit_0209974c.c',[
('func_02099780','''Unk09974cEntry *func_02099780(int id)
{
    Unk09974cEntry *t = (Unk09974cEntry *)data_0213bdec;
    u32 j;
    for (j = 0; j < 10; j++) {
        if (t[j].lo <= id && id <= t[j].hi) {
            return &((Unk09974cEntry *)data_0213bdec)[j];
        }
    }
    return 0;
}'''),
('func_020998f0','''int func_020998f0(int id)
{
    Unk09974cEntry *e = func_02099780(id);
    int n;
    if (e == 0) {
        return 0;
    }
    n = func_0209993c(id);
    if (n == 0) {
        return 0;
    }
    if (e->unk_0009 == 1 && n < 99) {
        return 0;
    }
    return 1;
}'''),
('func_02099cc4','''s32 func_02099cc4(Unk09974cStat *p)
{
    u32 v = p->unk_04;
    u32 r;
    s32 q;
    if (v == 0) {
        return 0;
    }
    r = p->unk_0e;
    if (r == 0) {
        return 0;
    }
    if (r == 100) {
        return v;
    }
    q = (v * r) / 100;
    if (q <= 0) {
        q = 1;
    }
    return q;
}'''),
rng('func_0209a090', 'v != 0'),
rng('func_0209a0c0', 'v == 1 || v == 3'),
('func_0209a0f4','''int func_0209a0f4(Unk09974cKind *p)
{
    u32 v = p->kind;
    return v == 14 || v == 1;
}'''),
('func_0209a12c','''int func_0209a12c(Unk09974cFlags *f)
{
    if (Unk09974c_HasFlagsMid(f) == 0) {
        return -1;
    }
    return f->unk_04_mid - 1;
}'''),
('func_0209a1a0','''void func_0209a1a0(int id)
{
    u8 *b = (u8 *)Unk02e000_GetSubBlock3a4();
    s32 k = id - 51;
    s32 i = k >> 3;
    u8 *f;
    if (i >= 162) {
        return;
    }
    f = b + 684 + 1024;
    f[i] |= (u8)(1 << (k & 7));
}'''),
],'''extern u8 data_0213bdec[];
int func_02099d14();
int func_02099bfc();
typedef struct Unk09974cStat {
    u8 pad_0000[0x4];
    u32 unk_04 : 10;
    u32 unk_04_rest : 22;
    u8 pad_0008[0x6];
    u16 unk_0e;
} Unk09974cStat;

typedef struct Unk09974cKind {
    u8 pad_0000[0x2a];
    u8 kind : 7;
    u8 kind_hi : 1;
} Unk09974cKind;''',
[('    u8 pad_0000[0x8];\n    u8 unk_0008;\n} Unk09974cEntry;','    s32 lo;\n    s32 hi;\n    u8 unk_0008;\n    u8 unk_0009;\n    u8 pad_000a[0x2];\n} Unk09974cEntry;'),
 ('Unk09974cEntry *func_02099780(u32 id);','Unk09974cEntry *func_02099780(int id);')]),
]
# skipped: func_0209a158 (ROM keeps k in r3; 3 tries), func_0209a23c (ROM branches to a shared return 0; 3 tries)
