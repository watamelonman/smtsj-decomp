G = 'u8 *p = (u8 *)Unk0946e0_GetAddr_data_02175d94();'
def pt(fn, body, call):
    return (fn, f'''void {fn}(int a, int b, int c)
{{
    Unk0946e0Pt pt;
    func_02049c28(func_02044ec4(a), &pt);
{body}    func_02094da0({call}, b, c);
}}''')
SPECS=[
('src/game/unit_020946e0.c',[
('func_02094e30','''void func_02094e30(int x, int b, int c)
{
    if (x >= 64) {
        x = 64;
    }
    if (x <= -64) {
        x = -64;
    }
    func_02094da0(x, FIELD(s16, Unk0946e0_GetAddr_data_02175d94(), 2), b, c);
}'''),
pt('func_02094e70','    pt.x -= 128;\n    pt.y -= 96;\n','pt.x, pt.y'),
pt('func_02094eb8','    pt.x -= 128;\n','pt.x, 0'),
],'''typedef struct Unk0946e0Pt {
    s16 x;
    s16 y;
} Unk0946e0Pt;

void func_02094da0();
int func_02044ec4();
void func_02049c28();'''),
('src/game/unit_02094fe0.c',[
('func_0209500c','''void func_0209500c(int a, int b)
{
    func_0209502c(Unk094fe0_Thunk_0202e8cc(), a, b);
}'''),
('func_020950b4','''int func_020950b4(Unk094fe0Work *w, u32 bit)
{
    u32 sh = bit & 7;
    u32 idx = bit >> 3;
    u8 *bits = Unk094fe0_Nop_095000(w);
    if (idx >= 512) {
        return 0;
    }
    return (bits[idx] & (1 << sh)) != 0;
}'''),
],'void func_0209502c();',[
('void Unk094fe0_Nop_095000(void);\n','u8 *Unk094fe0_Nop_095000(Unk094fe0Work *w);\n'),
('/* empty callback */\nvoid Unk094fe0_Nop_095000(void) { }','/* returns its argument (the ROM body is just `bx lr`) */\nu8 *Unk094fe0_Nop_095000(Unk094fe0Work *w) { return (u8 *)w; }'),
('void func_020950b4(Unk094fe0Work *w, u32 a);','int func_020950b4(Unk094fe0Work *w, u32 a);'),
('void Unk094fe0_Call_020950b4(u32 a)\n{\n    func_020950b4(','int Unk094fe0_Call_020950b4(u32 a)\n{\n    return func_020950b4('),
]),
]
# skipped (register choice after 3 tries): func_020950e4, func_0209512c
# func_02094a90 skipped: matches, but its existing caller Unk0946e0_Unk_094958 drops to 99.71% in objdiff
# although bytes and relocations are identical (same effect as func_02077e74 in b24). Unresolved.
