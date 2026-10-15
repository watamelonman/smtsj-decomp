def h(fn, thunk, T, off):
    return (fn, f'''u32 {fn}(void)
{{
    Unk03aae8_Unk_03acf4(FIELD({T}, {thunk}((u16)func_0203ac00(0)), {off}));
    return 1;
}}''')
H40 = 'Unk0bb2b0_Thunk_020a1740'
H28 = 'Unk0bb2b0_Thunk_020a1428'
SPECS=[
('src/game/unit_020b28e4.c',[
('func_020b6528','''u32 func_020b6528(u8 *p, int i)
{
    u32 ok = i >= 0;
    if (ok == 0) {
        return 0;
    }
    ok = i < 27;
    if (ok == 0) {
        return 0;
    }
    if (p == 0) {
        return 0;
    }
    return FIELD(u32, p + i * 12, 52);
}'''),
],''),
('src/game/unit_020bac80.c',[
('func_020bb144','''u32 func_020bb144(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);
    if (a < 15) {
        u16 *t = (u16 *)((u8 *)Unk02e000_GetWorkArea() + 134 + 768);
        t[a] += b;
    }
    return 1;
}'''),
],'int func_0203ac00();\nint Unk02e000_GetWorkArea();'),
('src/game/unit_020bb2b0.c',[
('func_020bb2b0','''u32 func_020bb2b0(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u16, Unk0bac80_Thunk_02044ec4(FIELD(u32, Unk0bac80_Unk_0badc0(), 64)) + 256, 216));
    return 1;
}'''),
h('func_020bb2ec', H40, 'u8', 2),
h('func_020bb314', H40, 'u16', 12),
h('func_020bb33c', H40, 'u16', 20),
h('func_020bb364', H40, 'u16', 14),
h('func_020bb38c', H40, 'u16', 16),
h('func_020bb3b4', H40, 'u16', 18),
h('func_020bb3dc', H28, 'u8', 4),
h('func_020bb404', H28, 'u8', 5),
('func_020bb490',f'''u32 func_020bb490(void)
{{
    u32 v = FIELD(u32, {H28}((u16)func_0203ac00(0)), 36);
    Unk03aae8_Unk_03acf4((v << 4) >> 25);
    return 1;
}}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u8 *Unk0bac80_Thunk_02044ec4(u32 id);
u32 Unk0bac80_Unk_0badc0(void);''',
[('void func_020a1428(void);','u8 *func_020a1428(u32 id);'),
 ('void Unk0bb2b0_Thunk_020a1428(void) { func_020a1428(); }','u8 *Unk0bb2b0_Thunk_020a1428(u32 id) { return func_020a1428(id); }'),
 ('void func_020a1740(void);','u8 *func_020a1740(u32 id);'),
 ('void Unk0bb2b0_Thunk_020a1740(void) { func_020a1740(); }','u8 *Unk0bb2b0_Thunk_020a1740(u32 id) { return func_020a1740(id); }')]),
('src/game/unit_020bb6e8.c',[
('func_020bb6e8','''u32 func_020bb6e8(void)
{
    if (((Unk0bb6e8Flags *)(Unk0bac80_Thunk_02044ec4(func_0203ac00(0)) + 642))->b1) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}'''),
('func_020bb724','''u32 func_020bb724(void)
{
    int a = func_0203ac00(0);
    int on = func_0203ac00(1) != 0;
    ((Unk0bb6e8Flags *)(Unk0bac80_Thunk_02044ec4(a) + 642))->b1 = on;
    return 1;
}'''),
],'''u8 *Unk0bac80_Thunk_02044ec4(u32 id);
void Unk03aae8_Unk_03acf4();
typedef struct Unk0bb6e8Flags {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Unk0bb6e8Flags;'''),
]
