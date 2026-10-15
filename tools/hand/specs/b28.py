BF = '''typedef struct Unk09727cPair {
    u16 lo : 10;
    u16 hi : 6;
} Unk09727cPair;

void func_02097340(Unk09727cPair *out, void *area);'''
def pair(fn, f):
    return (fn, f'''int {fn}(int i)
{{
    Unk09727cPair buf[20];
    func_02097340(buf, Unk02e000_Thunk_0202e788());
    return buf[i].{f};
}}''')
SPECS=[
('src/game/unit_02095560.c',[
('func_02095568','''u32 func_02095568(const u8 *p, int o)
{
    return p[o] | (p[o + 1] << 8) | (p[o + 2] << 16) | (p[o + 3] << 24);
}'''),
('func_02095b28','''int func_02095b28(u32 x)
{
    return Unk095560_Unk_095950(8, x) != 0;
}'''),
('func_02095cd8','''int func_02095cd8(u32 a, u32 b, u32 c, u32 d)
{
    u32 *q;
    ((u32 *)data_02175ea8)[0] = c;
    ((u32 *)data_02175ea8)[1] = d;
    q = (u32 *)Unk095560_GetManagerSub3a8();
    q[1] = a;
    q[0] = b;
    q[2] = -1;
    return 1;
}'''),
],''),
('src/game/unit_0209727c.c',[
('func_02097308','''int func_02097308(int i)
{
    int t = func_020445d0(48, 0);
    u16 *a;
    func_0204fe18(t);
    a = (u16 *)func_0204fde0(t);
    if (i == 18) {
        return 100;
    }
    return a[i];
}'''),
pair('func_020974a4', 'lo'),
pair('func_020974dc', 'hi'),
],'int func_020445d0();\nvoid func_0204fe18();\nint func_0204fde0();\n' + BF),
]

# func_02097824 skipped: ROM indexes as add #8; add #23552; ldrh [r0, i*40]; mwcc gives mla / ldrh #8 (4 layouts tried)
