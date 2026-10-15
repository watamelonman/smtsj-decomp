SPECS=[
('src/game/unit_020a7d54.c',[
('func_020a8ad0','''void func_020a8ad0(u8 *p)
{
    if (p == 0 || FIELD(u32, p, 8) == 0) {
        return;
    }
    func_02057e18(31);
    func_02057ddc(-1);
    Unk0a7d54_Unk_0a8500((int)p);
}'''),
('func_020a8b00','''void func_020a8b00(u32 *p, u32 a, s32 b)
{
    if (p == 0) {
        return;
    }
    if (p[2] != 0 && p[2] != 11) {
        return;
    }
    p[1] = 0;
    p[0] = a;
    p[3] = b + 1;
    p[4] = 0;
    if (p[2] == 11) {
        p[17] = 1;
    } else {
        p[2] = 1;
    }
}'''),
('func_020a8b70','''void func_020a8b70(u8 *p)
{
    if (p == 0 || FIELD(u32, p, 8) == 0) {
        return;
    }
    FIELD(u32, p, 68) = 0;
    if (Unk0a7d54_Unk_0a9204((int)p) != 0) {
        FIELD(u32, p, 8) = 11;
        return;
    }
    Unk0a7d54_Unk_0a8bac((int)p);
}'''),
('func_020a8c04','''int func_020a8c04(u8 *p)
{
    u32 v;
    if (Unk0a7d54_Unk_0a9204((int)p) == 1) {
        return 0;
    }
    v = FIELD(u32, p, 8);
    switch (v) {
    case 9:
    case 10:
    case 11:
        return 0;
    }
    return 1;
}'''),
('func_020a91d4','''void func_020a91d4(Unk0a7d54Slots *p, u32 x)
{
    int j;
    p->flag = 1;
    for (j = 0; j < 8; j++) {
        if (p->slot[j] == 0) {
            p->slot[j] = x;
            return;
        }
    }
}'''),
('func_020a9390','''void func_020a9390(u8 *p)
{
    if (FIELD(s32, p, 28) <= 0) {
        return;
    }
    func_0205bb68(FIELD(s32, p, 28));
    FIELD(s32, p, 28) -= 1;
}'''),
('func_020a93b8','''void func_020a93b8(u8 *p)
{
    s32 n = FIELD(s32, p, 28);
    int j;
    for (j = 0; j < n; j++) {
        func_020a9390(p);
    }
}'''),
],'''void func_02057e18();
void func_02057ddc();
void Unk0a7d54_Unk_0a8500(int arg0);
void Unk0a7d54_Unk_0a8bac(int arg0);
void func_0205bb68();
typedef struct Unk0a7d54Slots {
    u8 pad_00[0x20];
    u32 flag;
    u32 slot[8];
} Unk0a7d54Slots;'''),
('src/game/unit_020aa118.c',[
('func_020aa118','''void func_020aa118(void *p)
{
    func_02008848(p, 0, 0x814);
}'''),
('func_020aa1e0','''int func_020aa1e0(u32 **a, u32 **b)
{
    if ((*b)[5] == (*a)[5]) {
        if ((*a)[0] == (*b)[0]) {
            return 0;
        }
        return (*a)[0] > (*b)[0] ? 1 : -1;
    }
    return (*b)[5] > (*a)[5] ? 1 : -1;
}'''),
('func_020aa224','''void func_020aa224(Unk0aa118List *l)
{
    func_02013c68(&l->item[l->pos], l->count - l->pos, 4, func_020aa1e0);
}'''),
('func_020aa264','''int func_020aa264(Unk0aa118List *l)
{
    l->pos++;
    func_020aa130(l);
    if (l->pos >= l->count) {
        l->pos = l->count;
        return 0;
    }
    return 1;
}'''),
],'''void func_02013c68();
void func_020aa130();'''),
]
