V = '*(volatile u16 *)0x04000006'
SPECS=[
('src/game/unit_0205ae50.c',[
('func_0205afec','''int func_0205afec(int x)
{
    s32 vc = '''+V+''';
    int lim;
    if (vc < 191 || vc > 213) {
        return 0;
    }
    lim = FIELD(s32, data_0216a184, 0x5a8);
    if (lim < x) {
        x = lim;
    }
    return x & ~3;
}'''),
('func_0205b200','''void func_0205b200(void)
{
    func_02008848(data_0216a184, 0, 0x5ac);
    Unk05ae50_Unk_05afd8(0x18000);
}'''),
('func_0205b30c','''void func_0205b30c(int *x)
{
    if (func_02052624() < 31) {
        while ((s32)'''+V+''' < 191 || (s32)'''+V+''' > 213) {
        }
        Unk05ae50_Unk_05af64(x);
    } else {
        Unk05ae50_Unk_05af64(x);
    }
}'''),
],'int func_02008848();\nint func_02052624();\nvoid Unk05ae50_Unk_05af64(int *arg0);'),
('src/game/unit_0205b540.c',[
('func_0205b540','''void func_0205b540(void)
{
    func_02008848(data_0216a730, 0, 0xc18);
}'''),
('func_0205b560','''void func_0205b560(u32 a, u32 b, u32 c)
{
    func_0205b540();
    FIELD(u32, data_0216a730, 0xc0c) = a;
    FIELD(u32, data_0216a730, 0xc10) = b + c;
    FIELD(u32, data_0216a730, 0xc14) = b;
    FIELD(u32, data_0216a730, 0x404) = a;
    FIELD(u32, data_0216a730, 0x408) = b + c;
}'''),
],'int func_02008848();'),
('src/game/unit_02065e88.c',[
('func_020663d8','''u32 *func_020663d8(int i)
{
    if (i == 0) {
        return (u32 *)data_0214544c;
    }
    if (i == 1) {
        return (u32 *)data_02144e44;
    }
    /* no return for other i: the ROM falls through with i still in r0 */
}'''),
('func_020663f8','''int func_020663f8(int i)
{
    int n = 0;
    switch (i) {
    case 0:
        n = 193;
        break;
    case 1:
        n = 193;
        break;
    }
    return n;
}'''),
('func_0206641c','''u32 *func_0206641c(int i, int n)
{
    n--;
    if (n >= func_020663f8(i) - 1) {
        n = 0;
    }
    return func_020663d8(i) + n;
}'''),
],'extern u8 data_0214544c[];\nextern u8 data_02144e44[];'),
]
