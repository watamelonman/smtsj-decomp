E_ = '((Unk09a268Ent *)((u8 *)w + 164 + 9216))'
SPECS=[
('src/game/unit_0209a268.c',[
('func_0209a3a0',f'''int func_0209a3a0(u8 *w, u32 id, u32 sub)
{{
    int j;
    for (j = 0; j < 128; j++) {{
        if ({E_}[j].id == id && {E_}[j].sub == sub) {{
            return func_02058af8((u8 *)w + 164 + 9216, j);
        }}
    }}
    return 1;
}}'''),
('func_0209a458','''void func_0209a458(u8 *w, u32 a, u32 b, u32 c, u8 d, u32 e)
{
    int i = func_0209a3ec(w, a, b, c, d);
    func_02058b14(w + 164 + 9216, i, e);
}'''),
('func_0209a4a0','''void func_0209a4a0(u32 p, int bit, int on)
{
    if (on == 1) {
        *(u8 *)p |= 1 << bit;
    } else {
        *(u8 *)p &= ~(1 << bit);
    }
}'''),
('func_0209a4c4',f'''int func_0209a4c4(u8 *w, u32 id, u32 sub)
{{
    int j;
    for (j = 0; j < 128; j++) {{
        if ({E_}[j].id == id && {E_}[j].sub == sub) {{
            return j;
        }}
    }}
    return -1;
}}'''),
('func_0209a77c','''u8 func_0209a77c(void *p)
{
    u8 r = 0;
    u8 j;
    for (j = 0; j < 3; j++) {
        if (func_0209a48c(p, j) == 1) {
            r = j;
            break;
        }
    }
    return r;
}'''),
('func_0209a7bc','''void func_0209a7bc(u32 p, u32 v)
{
    u32 j;
    for (j = 0; j < 3; j++) {
        func_0209a4a0(p, j, v == j ? 1 : 0);
    }
}'''),
('func_0209b754','''void func_0209b754(u32 a, u32 b)
{
    if (data_02176270 != 0) {
        FIELD(u32, data_02176270, 44) = a;
        FIELD(u32, data_02176270, 48) = b;
    }
}'''),
('func_0209c4a8','''int func_0209c4a8(u32 h, u32 a, u32 b)
{
    int r;
    u8 *e;
    if (h == 0) {
        return 0;
    }
    r = 0;
    e = func_02039160(h, a, b);
    if (e != 0) {
        r = func_0209bb68(*e);
    }
    return Unk09a268_Unk_09c484(r);
}'''),
('func_0209c528','''int func_0209c528(const u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return *p == 1;
}'''),
],'''typedef struct Unk09a268Ent {
    s32 *val;
    u32 pad_04;
    u32 id;
    u32 pad_0c;
    u32 sub;
    u32 pad_14;
} Unk09a268Ent;

int func_02058af8();
int func_0209a3ec();
void func_02058b14();
void func_02058a1c();
u8 *func_02039160(u32 h, u32 a, u32 b);''',
[('int func_0209a4a0();','void func_0209a4a0();')]),
('src/game/unit_0209d060.c',[
('func_0209d13c','''int func_0209d13c(void)
{
    if (func_020a2980() == 0) {
        return 0;
    }
    return func_02061750(*data_02176274) == 0;
}'''),
('func_0209d170','''void func_0209d170(u32 a)
{
    if (*data_02176274 != 0) {
        func_020616ec(*data_02176274, a);
    }
}'''),
],'int func_020a2980();\nint func_02061750();\nvoid func_020616ec();'),
('src/game/unit_0209d42c.c',[
('func_0209d42c','''void func_0209d42c(void)
{
    func_02008848(data_02176278, 0, 0x884);
}'''),
('func_0209d4bc','''int func_0209d4bc(void)
{
    *(int *)(data_02176278 + 0x808) = 0;
    return *(int *)(data_02176278 + 0x800) > *(int *)(data_02176278 + 0x804);
}'''),
],'extern u8 data_02176278[];\nvoid func_02008848();'),
]
# skipped: func_0209a4fc, func_0209a53c (register allocation of loop cursor/base; 3 tries each); func_0209c4e0 not tried (jump table targets)
