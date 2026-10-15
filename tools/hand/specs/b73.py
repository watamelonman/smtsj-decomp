S = '''typedef struct Unk02e000Ent2 {
    u8 pad[11];
    u8 unk_0b_b0 : 1;
    u8 unk_0b_rest : 7;
    u8 pad2[19];
    u8 unk_1f_b0 : 1;
    u8 unk_1f_b1 : 1;
    u8 unk_1f_hi : 6;
    u8 pad3[4];
} Unk02e000Ent2;
#define ENT2(i) ((Unk02e000Ent2 *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc) + ((i) - 1))
'''
def setter(fn, body):
    return (fn, f'''int {fn}(u32 id, int v)
{{
    Unk02e000Ent2 *e;
    if (id > 491) {{
        return 0;
    }}
    e = ENT2(id);
{body}
    return 1;
}}''')
SPECS=[
('src/game/unit_0202e000.c',[
setter('func_0202ecf8','    e->unk_1f_b1 = (u8)(v != 0);'),
setter('func_0202eda8','''    if (v > 63) {
        e->unk_1f_hi = 63;
    } else {
        e->unk_1f_hi = (u8)v;
    }'''),
],S),
('src/game/unit_0202ee5c.c',[
setter('func_0202ee5c','    e->unk_0b_b0 = (u8)(v != 0);'),
('func_0202ef34','''void func_0202ef34(int d)
{
    u8 *w;
    s16 v;
    if (Unk0e651c_Unk_0e666c(0x404) != 0) {
        return;
    }
    if (Unk0e651c_Unk_0e666c(0x405) != 0) {
        return;
    }
    if (Unk0e651c_Unk_0e666c(0x406) != 0) {
        return;
    }
    w = Unk02e000_Thunk_0202e788();
    v = w[112] + d;
    if (v > 255) {
        v = 255;
    }
    if (v < 0) {
        v = 0;
    }
    w[112] = v;
}'''),
],'int Unk02e000_Unk_02e774(void);\nint Unk0e651c_Unk_0e666c();\nu8 *Unk02e000_Thunk_0202e788(void);\n'+S),
]
