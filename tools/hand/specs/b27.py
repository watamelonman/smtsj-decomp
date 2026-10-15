B = 'u8 *base = (u8 *)Unk02e000_GetWorkArea();'
def clamp(fn, lim, dst):
    return (fn, f'''void {fn}(int v)
{{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    s32 m = FIELD(s16, p, {lim});
    if (v <= m) {{
        if (v < 1) {{
            v = 1;
        }}
        m = v;
    }}
    FIELD(s16, p, {dst}) = m;
}}''')
def clampp(fn, lim, dst):
    return (fn, f'''int {fn}(u8 *p, int v)
{{
    s32 m;
    if (p == 0) {{
        return 0;
    }}
    m = FIELD(s16, p, {lim});
    if (v <= m) {{
        if (v < 1) {{
            v = 1;
        }}
        m = v;
    }}
    FIELD(s16, p, {dst}) = m;
    return FIELD(s16, p, {dst});
}}''')
SPECS=[
('src/game/unit_02096754.c',[
('func_02096754',f'''int func_02096754(u32 i)
{{
    u8 *base;
    s8 *t;
    int j;
    if (i >= 3) {{
        return 0;
    }}
    base = (u8 *)Unk02e000_GetWorkArea();
    t = (s8 *)(base + 852);
    for (j = 0; j < 3; j++) {{
        if (t[j] >= 0 && i == j) {{
            return Unk02e000_GetAreaRecord();
        }}
    }}
    return 0;
}}'''),
('func_02096898',f'''int func_02096898(void)
{{
    {B}
    int n = 0;
    int j;
    for (j = 0; j < 12; j++) {{
        if (FIELD(s8, base + j + 768, 72) < 0) {{
            break;
        }}
        n++;
    }}
    return n;
}}'''),
('func_02096a60',f'''int func_02096a60(int id)
{{
    {B}
    int j;
    for (j = 0; j < 12; j++) {{
        s32 v = FIELD(s8, base + j + 768, 72);
        if (v >= 0 && id == FIELD(u16, base + v * 60, 170)) {{
            return 1;
        }}
    }}
    return 0;
}}'''),
('func_02096ab0',f'''int func_02096ab0(int i)
{{
    {B}
    u16 v;
    if (i < 0 || i >= 12) {{
        return 1;
    }}
    v = FIELD(u16, base + i * 60, 168);
    if (v == 1 || v == 7) {{
        return 0;
    }}
    return 1;
}}'''),
('func_02096b44','''int func_02096b44(int id)
{
    if (Unk096754_Unk_0969f0() == 0) {
        return 0;
    }
    return func_02096a60(id) != 1;
}'''),
('func_02096f28','''void func_02096f28(void)
{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    FIELD(s16, p, 108) = 0;
    Unk096754_CopyAreaPos();
    FIELD(s16, p, 28) = FIELD(s16, p, 18);
    FIELD(s16, p, 30) = FIELD(s16, p, 20);
}'''),
clamp('func_020970d4', 18, 28),
clamp('func_02097120', 20, 30),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02e000_GetAreaRecord();
int func_02096a60(int id);'''),
('src/game/unit_020979d8.c',[
('func_020979d8','''int func_020979d8(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    FIELD(s16, p, 30) = FIELD(s16, p, 10);
    FIELD(s16, p, 32) = FIELD(s16, p, 12);
    return 1;
}'''),
clampp('func_02097b54', 10, 30),
clampp('func_02097b84', 12, 32),
('func_02097bb4','''int func_02097bb4(u8 *p, int id)
{
    int j;
    if (p == 0) {
        return 0;
    }
    for (j = 0; j < 6; j++) {
        if (id == ((u16 *)(p + 40))[j]) {
            return 1;
        }
    }
    return 0;
}'''),
('func_02097bec','''void func_02097bec(u8 *p, u16 *out)
{
    int j;
    if (p == 0) {
        return;
    }
    for (j = 0; j < 6; j++) {
        out[j] = ((u16 *)(p + 40))[j];
    }
}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif'''),
]
# func_02096af4 skipped: compare operand order (ROM cmp r2,r4) would not flip in 3 tries
