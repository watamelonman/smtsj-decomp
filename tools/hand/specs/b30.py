def pair(fn, f):
    return (fn, f'''int {fn}(u8 *p, int i)
{{
    Unk0979d8Pair buf[20];
    func_02097c18(buf, func_020a1428(FIELD(u16, p, 54)), p + 40);
    return buf[i].{f};
}}''')
def clampall(fn, outer, inner):
    return (fn, f'''void {fn}(int v)
{{
    u8 *w;
    int j;
    {outer}(v);
    w = (u8 *)Unk02e000_GetWorkArea();
    for (j = 0; j < 12; j++) {{
        s32 k = FIELD(s8, w + j + 768, 72);
        if (k < 0) {{
            return;
        }}
        {inner}(w + 116 + k * 60, v);
    }}
}}''')
SPECS=[
('src/game/unit_020979d8.c',[
pair('func_02097d54', 'lo'),
pair('func_02097d98', 'hi'),
('func_02097ddc','''void func_02097ddc(void)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < 12; j++) {
        s32 k = FIELD(s8, w + j + 768, 72);
        if (k < 0) {
            break;
        }
        Unk0979d8_Unk_0979fc((Unk0979d8Work *)Unk02e000_GetAreaRecord(k));
    }
    func_02097ebc();
}'''),
clampall('func_02097e1c', 'Unk096754_ClampField1c', 'Unk0979d8_ClampField1e'),
clampall('func_02097e6c', 'Unk096754_ClampField1e', 'Unk0979d8_ClampField20'),
('func_02097ebc','''void func_02097ebc(void)
{
    s8 *t = (s8 *)((u8 *)Unk02e000_GetWorkArea() + 852);
    int j;
    for (j = 0; j < 3; j++) {
        if (t[j] >= 0) {
            u8 *r = (u8 *)Unk02e000_GetAreaRecord(t[j]);
            if (FIELD(u16, r, 52) != 1) {
                Unk0979d8_ResetFields(r);
            }
        }
    }
    Unk096754_ResetAreaPos();
}'''),
('func_020980e8','''s32 func_020980e8(s32 d)
{
    u8 *w = (u8 *)Unk02e000_GetWorkArea();
    FIELD(s32, w, 836) += d;
    if (FIELD(s32, w, 836) < 0) {
        FIELD(s32, w, 836) = 0;
    }
    if (FIELD(s32, w, 836) >= 99999999) {
        FIELD(s32, w, 836) = 99999999;
    }
    return FIELD(s32, w, 836);
}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk0979d8Pair {
    u16 lo : 10;
    u16 hi : 6;
} Unk0979d8Pair;

int func_020a1428();
void func_02097c18(Unk0979d8Pair *out, int a, u8 *b);
int Unk02e000_GetWorkArea();
int Unk02e000_GetAreaRecord();
u32 Unk0979d8_Unk_0979fc(Unk0979d8Work *arg0);
void func_02097ebc(void);
int Unk096754_ClampField1c();
int Unk096754_ClampField1e();
void Unk096754_ResetAreaPos(void);'''),
]
