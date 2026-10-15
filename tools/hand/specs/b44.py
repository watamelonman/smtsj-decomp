def bit(fn, m):
    return (fn, f'''void {fn}(u8 *p, int on)
{{
    u8 *q;
    if (p == 0) {{
        return;
    }}
    q = p - 16;
    if (on) {{
        FIELD(u32, q, 4) &= ~{m};
    }} else {{
        FIELD(u32, q, 4) |= {m};
    }}
}}''')
SPECS=[
('src/game/unit_020bbfa4.c',[
('func_020bc17c','''u32 func_020bc17c(void)
{
    u8 *r = (u8 *)func_02044ec4(FIELD(u32, Unk044904_Unk_045048(), 64));
    u32 v = FIELD(u32, func_020a1428(FIELD(u16, r + 256, 216)), 36);
    return (v << 4) >> 25;
}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk044904_Unk_045048();
int func_02044ec4();
u8 *func_020a1428(u32 id);'''),
('src/game/unit_020bc1a8.c',[
('func_020bc490','''void func_020bc490(u8 *p)
{
    if (FIELD(u32, p, 24) == 0 || (FIELD(u32, p, 36) & 1) == 1) {
        return;
    }
    Unk06ae94_Unk_06ae94(2);
    func_020580ec(0);
    FIELD(Unk0bc1a8Fn, p, 24)(p + 52);
    func_020580ec(1);
    Unk06ae94_Unk_06aeb4(2);
}'''),
('func_020bc4e0','''void func_020bc4e0(u8 *p)
{
    Unk0bc1a8Fn fn;
    Unk0bc1a8_Unk_0bcc34((int)p);
    fn = FIELD(Unk0bc1a8Fn, p, 28);
    if (fn != 0) {
        fn(p + 52);
    }
}'''),
bit('func_020bc548', 4),
bit('func_020bc570', 1),
('func_020bc598','''u32 func_020bc598(u8 *p)
{
    if (p == 0) {
        return 0xffff;
    }
    return FIELD(u32, p, -8);
}'''),
],'''void Unk06ae94_Unk_06ae94();
void func_020580ec();
void Unk06ae94_Unk_06aeb4();
u32 Unk0bc1a8_Unk_0bcc34(int arg0);
typedef void (*Unk0bc1a8Fn)(u8 *);'''),
]
