def lim(fn, k, third):
    return (fn, f'''int {fn}(int a, int l)
{{
    int x = func_02049f24(a, {k});
    int y = func_02049d80(a, {k});
    int r = x - (y - {third}(a));
    if (r < l) {{
        l = r;
    }}
    return l;
}}''')
SPECS=[
('src/game/unit_020afc28.c',[
('func_020afc38','''void func_020afc38(u8 *p, Unk0afc28Pos12 *src)
{
    u32 cur = FIELD(u32, p, 36);
    if (cur != 0 && Unk0981dc_Unk_098324((s8)src->w[0], (s8)cur) == 0) {
        return;
    }
    *(Unk0afc28Pos12 *)(p + 36) = *src;
}'''),
('func_020afd60','''int func_020afd60(int a, int b)
{
    int n = a * b * 2;
    return (func_02050074(0, n) - n / 2) / 100;
}'''),
('func_020afd98','''int func_020afd98(int a, int b, int c)
{
    int r;
    if (a <= c) {
        r = func_02050074(0, c - 1) + 1;
    } else {
        r = func_020afd60(a, b);
        r += a;
    }
    if (r <= 0) {
        r = 1;
    }
    return r;
}'''),
('func_020b0654','''int func_020b0654(u32 id)
{
    Unk0afc28Ptrs *g = (Unk0afc28Ptrs *)Unk044904_Get_data_0215ee98();
    int n = 0;
    int j;
    for (j = 0; j < 10; j++) {
        u32 *e = g->e[j];
        if (e != 0 && id == ((e[0] >> 16) & 0xff)) {
            n++;
        }
    }
    return n;
}'''),
('func_020b0930','''int func_020b0930(u32 *p, u32 a, u16 b, u32 c)
{
    Unk0afc28Pos *r = (Unk0afc28Pos *)func_020982c0((s8)c);
    if (r == 0) {
        return 0;
    }
    p[0] = c;
    p[1] = a;
    FIELD(u16, p, 10) = b;
    FIELD(u16, p, 8) = Unk0afc28_IsOrigin(r);
    return 1;
}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk0afc28Pos12 {
    u32 w[3];
} Unk0afc28Pos12;

typedef struct Unk0afc28Ptrs {
    u8 pad_00[0x64];
    u32 *e[10];
} Unk0afc28Ptrs;

int Unk0981dc_Unk_098324(int a, int b);
int func_02050074();
int func_020afd60(int a, int b);
int Unk044904_Get_data_0215ee98();
int func_020982c0();
typedef struct Unk0afc28Pos Unk0afc28Pos;
int Unk0afc28_IsOrigin(Unk0afc28Pos *p);''',
[('typedef struct Unk0afc28Pos {','struct Unk0afc28Pos {'),('} Unk0afc28Pos;','};')]),
('src/game/unit_020b0b5c.c',[
lim('func_020b0c30', 0, 'func_0204ab98'),
lim('func_020b0cac', 1, 'func_0204ab14'),
],'int func_02049f24();\nint func_02049d80();\nint func_0204ab98();\nint func_0204ab14();'),
('src/game/unit_020b28e4.c',[
('func_020b2d84','''void func_020b2d84(u32 *p)
{
    p[0] = 0xcac;
    p[1] = 0;
    p[3] = (u32)func_020b32bc;
    p[4] = (u32)func_020b363c;
    p[5] = 0;
    p[6] = 0;
    p[7] = (u32)func_020b3d28;
    p[8] = (u32)func_020b2dd0;
}'''),
('func_020b5e10','''void func_020b5e10(u8 *p, u32 a, u32 b, u32 c, s8 d, u32 e)
{
    FIELD(s8, p, 55) = d;
    FIELD(u32, p, 44) = e;
    func_0205f7f4(p, a, b, c);
}'''),
('func_020b62e8','''void func_020b62e8(void)
{
    func_020552ec(6, 3);
    if (FIELD(u32, data_02176b80, 4) == 0) {
        FIELD(u32, data_02176b80, 4) = func_02052fe0(44);
        func_020b6370();
    }
    Unk0bc1a8_Unk_0bc928(13, 0xffff, 0);
}'''),
('func_020b6338','''void func_020b6338(void)
{
    func_020552ec(6, 1);
    func_020516d0(FIELD(u32, data_02176b80, 4));
    FIELD(u32, data_02176b80, 4) = 0;
    Unk0bc1a8_Unk_0bc9b4(13, 0);
}'''),
('func_020b6370','''void func_020b6370(void)
{
    *FIELD(u8 *, data_02176b80, 4) = 0;
    func_02008644(0, FIELD(u8 *, data_02176b80, 4) + 2, 6);
    func_02008644(0, FIELD(u8 *, data_02176b80, 4) + 8, 36);
}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020b32bc();
void func_020b363c();
void func_020b3d28();
void func_020b2dd0();
void func_0205f7f4();
void func_020552ec();
int func_02052fe0();
void func_020b6370(void);
void Unk0bc1a8_Unk_0bc928();
void func_020516d0();
void Unk0bc1a8_Unk_0bc9b4();
void func_02008644();'''),
]
