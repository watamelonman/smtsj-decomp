def half(fn, a):
    return (fn, f'''u8 *{fn}(u32 x)
{{
    int t = func_020af7f8({a}, 0);
    int k = 0;
    u8 *base = (u8 *)func_0204fde0(t);
    u32 n = func_0204fe18(t);
    if (((x >> 16) & 0xff) == 1) {{
        k += n >> 1;
    }}
    return base + k * 22;
}}''')
OLD824 = '''void Unk0aa118_Unk_0af824(void)
{
  u8 *v1;
  v1 = (u8 *)func_020af780();
  if (v1 != (u8 *)0x0) {
    func_020af7f8(*v1,v1[1]);
    func_0204fde0();
    return;
  }
  func_020af7f8(0,0);
  func_0204fde0();
}'''
NEW824 = '''/* returns the table base for the record found by func_020af780 (or for record 0,0) */
int Unk0aa118_Unk_0af824(u32 id)
{
    u8 *v = func_020af780(id);
    if (v != 0) {
        return func_0204fde0(func_020af7f8(v[0], v[1]));
    }
    return func_0204fde0(func_020af7f8(0, 0));
}'''
SPECS=[
('src/game/unit_020aa118.c',[
('func_020ab34c','''void func_020ab34c(void)
{
    func_020aa4f4(2, 0, 0, 0);
    func_020ae1e8(data_02176b18);
}'''),
('func_020ab468','''void func_020ab468(u32 x)
{
    u32 *t = (u32 *)Unk044904_Unk_04509c();
    s32 j;
    s32 n = t[6];
    if (n >= 6) {
        return;
    }
    for (j = 0; j < n; j++) {
        if (x == t[j]) {
            return;
        }
    }
    t[n] = x;
    t[6]++;
}'''),
('func_020ab8f8','''void func_020ab8f8(u32 p)
{
    u32 v = FIELD(u32, Unk044904_Get_data_0215ee98(), 64);
    if (((v << 20) >> 31) == 0) {
        return;
    }
    if (func_020b081c(2) != 0) {
        FIELD(u32, p, 8) |= 8;
    }
}'''),
('func_020ab930','''u8 func_020ab930(u8 *p, u32 id)
{
    switch (func_0204add4(id)) {
    case 4:
        return p[58];
    case 1:
        return p[59];
    case 5:
        return p[60];
    }
    return 0;
}'''),
('func_020acb28','''void func_020acb28(void)
{
    Unk0aa118Ptrs *g = (Unk0aa118Ptrs *)Unk044904_Get_data_0215ee98();
    int j;
    for (j = 0; j < 10; j++) {
        u32 *e = g->e[j];
        if (e != 0 && ((e[0] >> 16) & 0xff) != 0) {
            func_0204a7b4(e, 2);
        }
    }
}'''),
('func_020adaf4','''u32 func_020adaf4(int k, int i)
{
    int b = 0;
    switch (k) {
    case 1:
        break;
    case 2:
        b = 3;
        break;
    case 3:
        b = 6;
        break;
    }
    return data_0214d2f4[b + (i - 1)];
}'''),
('func_020af780','''u8 *func_020af780(u32 id)
{
    u8 *e = data_0214d398;
    u32 j;
    for (j = 0; j < 0x146; j++, e += 34) {
        if (func_020152cc(id, e + 2) == 0) {
            return e;
        }
    }
    return 0;
}'''),
('func_020af7cc','''int func_020af7cc(u32 i)
{
    int t = func_020491b4(i);
    if (i >= (u32)func_0205f2e4(t)) {
        i = 0;
    }
    return func_0205f41c(t, i);
}'''),
('func_020af7f8','''int func_020af7f8(u32 a, u32 b)
{
    int t = func_020af7cc(a);
    if (b >= (u32)func_0204fd18(t)) {
        b = 0;
    }
    return func_0204fdac(t, b);
}'''),
('func_020af8d8','''u8 *func_020af8d8(int a, u32 id, int c)
{
    u8 *base = (u8 *)Unk0aa118_Unk_0af824(id);
    int k = 0;
    if (a == 1) {
        k = 1;
    }
    if (c != 0) {
        k = 1 - k;
    }
    return base + k * 412;
}'''),
('func_020afa60','''u8 *func_020afa60(int a, u32 id, int c)
{
    u32 e = func_02099d14(id);
    if (e != 0) {
        if (func_020152cc(e, data_0214fef8) == 0) {
            return 0;
        }
        return func_020af8d8(a, e, c);
    }
    return 0;
}'''),
half('func_020afab0', 39),
half('func_020afaf8', 0),
('func_020afb40','''int func_020afb40(int i)
{
    if (i == 0) {
        return 0;
    }
    return Unk0aa118_Unk_0af824(data_0214d380[i]);
}'''),
],'''void func_020aa4f4();
void func_020ae1e8();
extern u8 data_02176b18[];
int Unk044904_Get_data_0215ee98();
int func_020b081c();
int func_0204add4();
void func_0204a7b4();
extern u32 data_0214d2f4[];
extern u8 data_0214d398[];
int func_020152cc();
int func_020491b4();
int func_0205f2e4();
int func_0205f41c();
int func_0204fd18();
int func_0204fdac();
int func_0204fe18();
int func_02099d14();
extern u8 data_0214fef8[];
extern u32 data_0214d380[];
int func_0204fde0(int t);
u8 *func_020af780(u32 id);
int func_020af7cc(u32 i);
int func_020af7f8(u32 a, u32 b);
int Unk0aa118_Unk_0af824(u32 id);
u8 *func_020af8d8(int a, u32 id, int c);
typedef struct Unk0aa118Ptrs {
    u8 pad_00[0x64];
    u32 *e[10];
} Unk0aa118Ptrs;''',
[(OLD824, NEW824),
 ('int func_0204fde0();\nint func_020af780();\nint func_020af7f8();\n',''),
 ('void func_020af8d8(void);\n','u8 *func_020af8d8(int a, u32 id, int c);\n'),
 ('void Unk0aa118_Thunk_020af8d8(void);','u8 *Unk0aa118_Thunk_020af8d8(int a, u32 id, int c);'),
 ('void Unk0aa118_Thunk_020af8d8(void) { func_020af8d8(); }','u8 *Unk0aa118_Thunk_020af8d8(int a, u32 id, int c) { return func_020af8d8(a, id, c); }')]),
]
# skipped: func_020ab4d4 (ROM builds the mask in r2 then r1; 4 tries)
