FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_02116598.c',[
('func_021177e0','''void func_021177e0(u32 a, u32 b)
{
    u8 *w = (u8 *)*data_02176e64;
    FIELD(u32, w, 0) = 1;
    w[8] = a;
    FIELD(u32, w, 4) = b;
    FIELD(u32, w, 12) = 0;
}'''),
],FX),
('src/StaffRoll.c',[
('func_02118174','''void func_02118174(u8 *p)
{
    u32 n = FIELD(u32, p, 180) + 1;
    FIELD(u32, p, 180) = n;
    if (FIELD(u32, p, 196) > n) {
        return;
    }
    FIELD(u32, p, 172) = 1;
    FIELD(u32, p, 180) = 0;
}'''),
('func_02118490','''void func_02118490(u8 *p)
{
    int a;
    int b;
    int c;
    FIELD(u32, p, 8)++;
    a = func_02117dd8(p);
    b = StaffRoll_Unk_1181a0((int)p);
    c = func_02118424(p);
    if (a != 0 && b != 0 && c != 0) {
        FIELD(u32, p, 0) = 2;
    }
}'''),
('func_021184d8','''void func_021184d8(u8 *p)
{
    switch (FIELD(u32, p, 0)) {
    case 0:
        FIELD(u32, p, 0) = 1;
        return;
    case 1:
        func_02118490(p);
        return;
    case 2:
        func_02061424(p);
        return;
    }
}'''),
],FX+'int func_02117dd8();\nu32 StaffRoll_Unk_1181a0(int arg0);\nint func_02118424();\nvoid func_02118490(u8 *p);\nvoid func_02061424();'),
('src/game/unit_02118b04.c',[
('func_02118b30','''void func_02118b30(int i, int f)
{
    u8 *q = (u8 *)Unk02e000_Unk_02e228() + 148;
    if (f != 0) {
        if ((q[i] & 1) == 0) {
            q[i] |= 2;
        }
        q[i] |= 1;
    } else {
        q[i] = 0;
    }
}'''),
('func_02118bcc','''void func_02118bcc(int i)
{
    u8 *q = (u8 *)Unk02e000_Unk_02e228() + 148;
    q[i] &= ~2;
}'''),
('func_02118ef4','''u8 *func_02118ef4(int i)
{
    u32 h = func_020445d0(45, 0);
    u8 *base = (u8 *)func_0204fde0(h);
    if (i >= func_0204fe18(h)) {
        return 0;
    }
    return base + i * 12;
}'''),
('func_02118f88','''int func_02118f88(u32 x)
{
    int i;
    u8 *e;
    for (i = 0; i < 106; i++) {
        e = func_02118ef4(i);
        if (e != 0 && e[9] == x) {
            if (Unk118b04_Unk_118b78(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}'''),
],'u32 func_020445d0();\nint func_0204fde0();\nint func_0204fe18();\nu8 *func_02118ef4(int i);'),
('src/BattleShowingTask.c',[
('func_021196c0','''void func_021196c0(void)
{
    *data_02176e70 = 0;
    Unk02cad4_Unk_02cbdc(1);
}'''),
],'void Unk02cad4_Unk_02cbdc();'),
('src/game/unit_0211d120.c',[
('func_0211d178','''void func_0211d178(u32 x)
{
    *data_02176e74 = x;
    func_02008848(x, 0, 176);
}'''),
],'extern u32 data_02176e74[];\nvoid func_02008848();'),
('src/game/unit_0211d520.c',[
('func_0211d7f4','''void func_0211d7f4(Unk11d520Ids *p, u32 id)
{
    int i;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (id == p->ids[i]) {
            return;
        }
    }
    p->ids[n] = id;
    p->n++;
}'''),
('func_0211dde8','''void func_0211dde8(Unk11d520Ids *p, int i, u32 v)
{
    func_0205c408(p->h[i], v);
    func_0205c6e0(p->h[i]);
}'''),
],'void func_0205c408();\nvoid func_0205c6e0();\ntypedef struct Unk11d520Ids {\n    u8 pad[180];\n    u16 ids[218];\n    u32 n;\n    u8 pad2[32];\n    u32 h[8];\n} Unk11d520Ids;'),
]
