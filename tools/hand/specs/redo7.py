SPECS=[
('src/game/unit_020cf5e8.c',[('func_020d1454','''typedef struct Unk0cf5e8Obj {
    u8 pad_0000[0x98];
    s32 unk_0098;
    s32 unk_009c;
    u8 pad_00a0[0x1f0];
    s32 unk_0290;
    s32 unk_0294;
} Unk0cf5e8Obj;

int func_020d1454(Unk0cf5e8Obj *o)
{
    return o->unk_009c == 1 && o->unk_0290 == 0;
}'''),('func_020d1490','''int func_020d1490(Unk0cf5e8Obj *o)
{
    return o->unk_0098 == 1 && o->unk_0294 == 0;
}''')],''),
('src/game/unit_020e5fb8.c',[('func_020e613c','''int func_020e613c(int row, u32 col)
{
    int base = row * 10;
    if (col >= 10) {
        col = 0;
    }
    return col + (base + 0x800);
}''')],''),
('src/game/unit_020bcef4.c',[('func_020bd5d4','''typedef struct Unk0bcef4State {
    s32 state;
} Unk0bcef4State;

int func_020bd5d4(Unk0bcef4State *t)
{
    s32 s = t->state;
    if (s == 1 || s == 0 || s == 5) {
        return 1;
    }
    return 0;
}''')],''),
('src/game/unit_020bd5f0.c',[('func_020c8540','''int func_020c8540(int id)
{
    if (id == 8 || id == 5 || id == 6 || id == 22) {
        return 1;
    }
    return 0;
}''')],''),
('src/game/unit_020ddeb0.c',[('func_020de014','''u32 func_020de014(void)
{
    return ((u32 *)func_0204fde0(func_020445d0(15, 1)))[0];
}'''),('func_020de030','''u32 func_020de030(void)
{
    return ((u32 *)func_0204fde0(func_020445d0(15, 1)))[1];
}''')],''),
]
