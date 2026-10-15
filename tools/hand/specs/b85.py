FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
CHK = '''    int ok;
    u8 *e;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    e = data_0214283c + i * 16;
'''
SPECS=[
('src/game/unit_02044394.c',[
('func_02044428','''int func_02044428(int i)
{
''' + CHK + '''    if (FIELD(u32, e, 4) != 0) {
        return 1;
    }
    if (FIELD(u32, e, 8) != 0) {
        return 0;
    }
    Unk044394_Unk_044394((u32 *)e);
    return 1;
}'''),
('func_02044534','''int func_02044534(int i)
{
''' + CHK + '''    if (FIELD(u32, e, 4) == 0) {
        return 1;
    }
    if (FIELD(u32, e, 8) != 0) {
        return 0;
    }
    func_02053000(FIELD(u32, e, 4));
    FIELD(u32, e, 4) = 0;
    return 1;
}'''),
],FX+'extern u8 data_0214283c[];\nvoid Unk044394_Unk_044394(u32 *arg0);\nvoid func_02053000();\n'),
('src/game/unit_02044904.c',[
('func_02044948','''Unk044904Rec *func_02044948(u32 a, u32 key)
{
    u8 *p = (u8 *)a;
    u32 n = FIELD(u32, p, 96);
    u32 i;
    u8 *e;
    typedef struct Unk044904Slot { u16 id; u8 pad[10]; } Unk044904Slot;
    for (i = 0; i < n; i++) {
        if (key == ((Unk044904Slot *)p)[i].id) {
            return (Unk044904Rec *)(p + i * 12);
        }
    }
    if (n >= 8) {
        return 0;
    }
    e = p + n * 12;
    func_02008848(e, 0, 12);
    FIELD(u16, e, 0) = key;
    FIELD(u32, p, 96)++;
    return (Unk044904Rec *)e;
}'''),
('func_02044f4c','''int func_02044f4c(u32 k)
{
    typedef struct Unk044904Objs { u8 pad[100]; u32 objs[10]; } Unk044904Objs;
    u8 *t = (u8 *)Unk044904_Get_data_0215ee98();
    int i;
    if (t == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        u32 o = ((Unk044904Objs *)t)->objs[i];
        if (o != 0 && func_02049a84(o, k) != 0) {
            return i;
        }
    }
    return -1;
}'''),
('func_020453dc','''void func_020453dc(void)
{
    typedef struct Unk044904Objs { u8 pad[100]; u32 objs[10]; } Unk044904Objs;
    int i;
    int one = 1;
    for (i = 0; i < 10; i++) {
        u8 *o = (u8 *)((Unk044904Objs *)Unk044904_Get_data_0215ee98())->objs[i];
        if (o != 0 && ((FIELD(u32, o, 0) >> 16) & 0xff) != 0) {
            func_0204a8cc(o, one);
        }
    }
    FIELD(u32, Unk044904_Get_data_0215ee98(), 88) = 0;
}'''),
],FX+'u32 Unk044904_Get_data_0215ee98(void);\nvoid func_02008848();\nint func_02049a84();\nvoid func_0204a8cc();\n'),
]
