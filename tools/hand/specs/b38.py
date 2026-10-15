def find(fn, fld, ret='u8 *', sig='(u32 id)'):
    return (fn, f'''{ret}{fn}{sig}
{{
    Unk0a5680Base *b = (Unk0a5680Base *)*data_02176b14;
    int j;
    for (j = 0; j < b->count; j++) {{
        if (b->e[j].{fld} == id) {{
            return ({ret.strip()})&b->e[j];
        }}
    }}
    return 0;
}}''')
def free16(fn, off):
    return (fn, f'''int {fn}(u8 *p)
{{
    int j;
    for (j = 0; j < 16; j++) {{
        if (((u8 (*)[16])p)[j][{off}] == 0) {{
            return j;
        }}
    }}
    return -1;
}}''')
def each32(fn):
    return (fn, f'''void {fn}(u8 *p)
{{
    int j;
    u8 *e = p + 72;
    for (j = 0; j < 32; j++, e += 40) {{
        Unk0a7d54_Unk_0a7e8c((int)e);
    }}
}}''')
def st8(fn, test):
    return (fn, f'''int {fn}(u8 *p)
{{
    if (p == 0) {{
        return 0;
    }}
    return FIELD(u32, p, 8) {test};
}}''')
FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_020a50d4.c',[
('func_020a50f4','''int func_020a50f4(void)
{
    s32 v = func_02002954(0x0400106c);
    if (v == 16) {
        return 1;
    }
    return v == -16;
}'''),
('func_020a5648','''int func_020a5648(u8 *p)
{
    switch (FIELD(s8, p + 29696, 128)) {
    case 0:
        return func_020a5124(p);
    case 1:
        return func_020a5490(p);
    }
    return 1;
}'''),
],FX+'int func_02002954();\nint func_020a5124();\nint func_020a5490();'),
('src/game/unit_020a5680.c',[
('func_020a572c','''int func_020a572c(u8 *p, u32 c)
{
    s32 k = FIELD(s8, p, 18);
    if (k == -1) {
        return func_02008904(FIELD(u32, p, 28), p + 32, 512, c);
    }
    return func_0206f24c(p + 32, FIELD(u32, p, 28), 1 << (k + 13), c);
}'''),
('func_020a5778','''int func_020a5778(u8 *p, int force)
{
    s8 k = data_0213c3d4[func_0204a244(func_02044ec4(FIELD(u32, p, 12)))];
    if (FIELD(s8, p, 18) == k && force == 0) {
        return 0;
    }
    FIELD(s8, p, 18) = k;
    func_020a572c(p, 4096);
    return 1;
}'''),
('func_020a5e28','''int func_020a5e28(id)
    u32 id;
{
    u8 *e = (u8 *)func_020a5680(id);
    if (e == 0) {
        return 0;
    }
    return func_020616c0(e + 8);
}'''),
('func_020a60fc','''int func_020a60fc(u32 id)
{
    u8 *e = (u8 *)func_020a5e28(id);
    if (e != 0 && e[56] != 0) {
        return 1;
    }
    return 0;
}'''),
],FX+'''int func_02008904();
int func_0206f24c();
int func_02044ec4();
int func_0204a244();
extern s8 data_0213c3d4[];
int func_020616c0();
int func_020a572c(u8 *p, u32 c);
''',[('Unk0a5680Entry *func_020a5680(u32 a, u32 b);','Unk0a5680Entry *func_020a5680();')]),
('src/game/unit_020a6174.c',[
free16('func_020a6174', 12),
free16('func_020a61f8', 269),
('func_020a69d0','''void func_020a69d0(u8 *a, u8 *b)
{
    if (a == 0 || b == 0) {
        return;
    }
    func_02008848(a, 0, 0xe14);
    func_02008848(b, 0, 512);
}'''),
],FX+'void func_02008848();'),
('src/game/unit_020a7d54.c',[
each32('func_020a84a4'),
each32('func_020a8534'),
('func_020a855c','''int func_020a855c(u8 *p, u32 k)
{
    int j;
    u8 *e = p + 72;
    for (j = 0; j < 32; j++, e += 40) {
        if (FIELD(u32, e, 0) != 0 && FIELD(u8, e, 12) == k) {
            return (int)e;
        }
    }
    return 0;
}'''),
st8('func_020a8608', '!= 0'),
st8('func_020a8628', '== 3'),
],''),
]
# skipped: func_020a5680, func_020a56cc (ROM reloads count each iteration; mwcc hoists it), func_020a59c4 (ROM reloads *data_02176b14 after the store)
