C = 'data_02176bb4'
def scan(fn, test):
    return (fn, f'''int {fn}(void)
{{
    u32 id;
    for (id = 111; id <= 210; id++) {{
        int r = func_02099d78(id);
        if (Unk09974c_Unk_0998d8(id) != 0 && {test}) {{
            return 1;
        }}
    }}
    return 0;
}}''')
SPECS=[
('src/game/unit_020bd5f0.c',[
('func_020c1870','''int func_020c1870(int i)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < FIELD(u8, w, 855); j++) {
        if (FIELD(s8, w + j + 768, 72) == FIELD(s8, w + i + 768, 84)) {
            break;
        }
    }
    return j;
}'''),
('func_020c1918','''int func_020c1918(int i)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    s32 k = FIELD(s8, w + i + 768, 72);
    u8 *e;
    if (k >= 0) {
        e = w + k * 60;
        if (FIELD(u16, e, 168) == 1 || FIELD(s16, e, 146) <= 0) {
            return 1;
        }
    }
    return 0;
}'''),
('func_020c20bc','''int func_020c20bc(void)
{
    if (func_020537b8(0, 64) != 0) {
        return 0;
    }
    return func_020537b8(0, 128) == 0;
}'''),
scan('func_020c7c44', 'Unk09974c_HasFlagsMid(r) != 0'),
scan('func_020c7c90', 'Unk09974c_HasFlagsMid(r) == 0'),
('func_020c7f70',f'''void func_020c7f70(u32 a, u32 b, u32 c, u32 d)
{{
    if ({C} == 0) {{
        return;
    }}
    func_020dde3c(FIELD(u32, {C}, 264), a, b, c, d);
}}'''),
('func_020c7fbc',f'''void func_020c7fbc(void)
{{
    if ({C} == 0) {{
        return;
    }}
    FIELD(s32, {C}, 0) = 20;
    FIELD(s32, {C}, 4) = 22;
    FIELD(s32, {C}, 280) = -110;
    FIELD(s32, {C}, 288) = 0;
    FIELD(s32, {C}, 284) = 0;
}}'''),
('func_020c842c',f'''void func_020c842c(void)
{{
    u8 *c = (u8 *){C};
    if (c == 0) {{
        return;
    }}
    Unk0ddeb0_Unk_0ddeb0(FIELD(u32, c, 256), FIELD(s32, c, 276) + 3, -2, 0, 12, 10);
}}'''),
('func_020c8478',f'''int func_020c8478(void)
{{
    s32 v;
    if ({C} == 0) {{
        return 0;
    }}
    v = FIELD(s32, {C}, 0);
    return v == 22 || v == 24;
}}'''),
('func_020c8510','''void func_020c8510(s32 *p, s32 b)
{
    func_020c72a4(p[64], FIELD(u8, p, 272), 0);
    p[0] = 20;
    p[1] = b;
    p[69] = -110;
}'''),
],'''int Unk02e000_GetWorkArea();
int func_02099d78();
int Unk09974c_Unk_0998d8();
int Unk09974c_HasFlagsMid();
void func_020dde3c();
void Unk0ddeb0_Unk_0ddeb0();
void func_020c72a4();'''),
]
