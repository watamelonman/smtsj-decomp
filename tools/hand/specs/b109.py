SPECS=[
('src/game/unit_0209974c.c',[
('func_02099e40','''void *func_02099e40(int id)
{
    Unk09974cRec16 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 5);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 16, Unk09974c_Unk_0998b0);
}'''),
('func_02099ea4','''int func_02099ea4(int id)
{
    int tier = Unk02ee5c_GetTierFromField70();
    Unk09974cRec80 *r = (Unk09974cRec80 *)Unk09974c_Unk_099c60(id);
    if (r == 0) {
        return 0;
    }
    if (r->f0 && tier == 4) {
        return 1;
    }
    if (r->f2 && tier == 5) {
        return 1;
    }
    if (r->f1 && tier == 1) {
        return 1;
    }
    return 0;
}'''),
('func_02099f24','''void func_02099f24(int id)
{
    u16 *w;
    Unk09974cRec80 *r;
    if (func_02099ea4(id) == 0) {
        return;
    }
    w = (u16 *)Unk02e000_Thunk_0202e788();
    r = (Unk09974cRec80 *)Unk09974c_Unk_099c60(id);
    if (r->unk_02 == 3) {
        w[0] = id;
    }
    if (r->unk_02 == 4) {
        w[1] = id;
    }
    if (r->unk_02 == 5) {
        w[2] = id;
    }
    if (r->unk_02 == 6) {
        w[3] = id;
    }
}'''),
('func_0209a1e4','''int func_0209a1e4(int id)
{
    if (func_0209a158(id) != 0) {
        return 0;
    }
    switch (Unk09974c_GetEntryUnk08(id)) {
    case 0:
        return ((Unk09974cRec8 *)Unk09974c_Unk_099bfc(id))->unk_05;
    case 8:
    case 9:
        return 1;
    }
    return 0;
}'''),
],'int Unk02ee5c_GetTierFromField70();\nvoid *Unk02e000_Thunk_0202e788();\nint func_0209a158();\n',
[('''typedef struct Unk09974cRec80 {
    u16 id;
    u8 pad_02[78];
} Unk09974cRec80;''','''typedef struct Unk09974cRec80 {
    u16 id;
    u8 unk_02;
    u8 pad_03[20];
    u8 f0 : 1;                  /* +0x17 */
    u8 f1 : 1;
    u8 f2 : 1;
    u8 : 5;
    u8 pad_18[56];
} Unk09974cRec80;'''),('''typedef struct Unk09974cRec8 {
    u16 id;
    u8 pad_02[6];
} Unk09974cRec8;''','''typedef struct Unk09974cRec8 {
    u16 id;
    u8 pad_02[3];
    u8 unk_05;
    u8 pad_06[2];
} Unk09974cRec8;''')]),
]
