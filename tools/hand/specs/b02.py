SPECS=[
('src/game/unit_0202d15c.c',[('func_0202dcac','''int func_0202dcac(int a, int key)
{
    u8 *rec = Unk02d15c_GetManagerRecord(a);
    u32 i;
    u8 *p;
    u32 n;
    if (rec == 0) {
        return -1;
    }
    p = FIELD(u8 *, rec, 0x0c);
    n = FIELD(u32, rec, 0x08);
    for (i = 0; i < n; i++) {
        if (key == p[0]) {
            return i;
        }
        p += 0x30;
    }
    return -1;
}''')],''),
('src/game/unit_0202dcfc.c',[('func_0202dcfc','''int func_0202dcfc(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return FIELD(s32, p, 0x50) >= 0;
}''')],''),
('src/game/unit_0202e000.c',[
('func_0202e000','''void func_0202e000(int i, u32 v)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m == 0) {
        return;
    }
    if (i < 0 || i >= 16) {
        return;
    }
    m->slots[i] = v;
}'''),
('func_0202e034','''u32 func_0202e034(int i)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m == 0) {
        return 0;
    }
    if (i < 0 || i >= 16) {
        return 0;
    }
    return m->slots[i];
}'''),
('func_0202e070','''void func_0202e070(u32 a, u32 b)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m != 0) {
        m->unk_0038 = a;
        m->unk_003c = b;
    }
}'''),
('func_0202e114','''void func_0202e114(void)
{
    if (data_0215dd24[1] != 0) {
        return;
    }
    data_0215dd24[1] = func_02052fe0(0x7718);
}'''),
('func_0202e1f8','''void func_0202e1f8(int add)
{
    Unk02e000Save *w = (Unk02e000Save *)Unk02e000_Unk_02e774();
    u32 v = w->money + add;
    if (v > 35999999) {
        w->money = 35999999;
    } else {
        w->money = v;
    }
}'''),
],'''u32 func_02052fe0();
typedef struct Unk02e000Save {\n    u8 pad_0000[0x5fc4];\n    u32 money;\n} Unk02e000Save;''')]
