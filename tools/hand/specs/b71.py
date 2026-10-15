SPECS=[
('src/game/unit_0202d15c.c',[
('func_0202d22c','''int func_0202d22c(int x)
{
    switch (x) {
    case 0: return 0;
    case 2: return 1;
    case 1: return 2;
    case 3: return 5;
    case 4: return 6;
    case 5: return 7;
    case 7: return 4;
    case 9: break;
    }
    return 0;
}'''),
('func_0202d2a0','''int func_0202d2a0(int x)
{
    switch (x) {
    case 0: return 0;
    case 1: return 2;
    case 2: return 1;
    case 5: return 3;
    case 6: return 4;
    case 7: return 5;
    case 4: return 7;
    }
    return 0;
}'''),
('func_0202d794','''int func_0202d794(u32 a, u32 b)
{
    struct { u32 w[8]; } s;
    s.w[0] = Unk095560_Unk_095d1c();
    s.w[1] = -1;
    s.w[2] = 1;
    s.w[3] = 13;
    s.w[4] = -1;
    s.w[5] = Unk02d15c_Unk_02d944();
    s.w[6] = a;
    s.w[7] = b;
    return func_0202d390(&s) != 0;
}'''),
('func_0202d8a8','''int func_0202d8a8(int a, int b, int c)
{
    u8 *r = Unk02d15c_GetManagerRecord(a);
    int i, e;
    if (r == 0) {
        return 0;
    }
    i = func_0204b01c(r + 16, c);
    if (i < 0) {
        return 0;
    }
    e = Unk02d15c_FindRecordEntry(a, i);
    if (e < 0) {
        Unk02d15c_Setup(a, b, -1, i);
        return 1;
    }
    return Unk02d15c_Setup(a, b, e, -1);
}'''),
('func_0202d954','''int func_0202d954(u8 *p)
{
    u16 v;
    if (FIELD(s16, p, 20) == 0) {
        return 1;
    }
    v = FIELD(u16, Unk02e000_GetWorkArea() + 0x300, 0x5c);
    if (FIELD(s16, p, 20) == 1) {
        s16 k = FIELD(s16, p, 24);
        int r = Unk02f2a8_Unk_035c14(v, FIELD(s16, p, 22));
        if (r == k) {
            return 1;
        }
        return 0;
    }
    return 1;
}'''),
],'u8 *Unk02d15c_GetManagerRecord(int i);\nint Unk02d15c_FindRecordEntry(int a, int key);\nint func_0202d390();\nint func_0204b01c();\nu8 *Unk02e000_GetWorkArea();\nint Unk02f2a8_Unk_035c14();'),
('src/game/unit_0202e000.c',[
('func_0202e3e4','''int func_0202e3e4(int a)
{
    int h = func_020445d0(35, 0);
    s16 *t = func_0204fde0();
    u32 n = func_0204fe18(h);
    u32 i;
    for (i = 0; i < n; i++) {
        if (a == t[i]) {
            return i;
        }
    }
    return -1;
}'''),
],'int func_020445d0();\ns16 *func_0204fde0();\nu32 func_0204fe18();'),
]
