P='''int Unk095560_Unk_095d1c();
int func_0202d668();
int Unk094fe0_Call_020950b4();
void ImageObj_Unk_077894();
void Unk02dcfc_SetField68();
void func_02095cd8();
void Unk095560_Unk_095d08();
s32 *Unk094fe0_Unk_094fec();'''
SPECS=[('src/game/unit_0202d15c.c',[
('func_0202d30c','''int func_0202d30c(int a)
{
    return func_0202d668(Unk095560_Unk_095d1c(), a, 0, 0, -1) == 1;
}'''),
('func_0202d348','''int func_0202d348(int a)
{
    if (a < 0) {
        return 1;
    }
    return Unk094fe0_Call_020950b4(a) == 1;
}'''),
('func_0202d36c','''int func_0202d36c(int a)
{
    if (a < 0) {
        return 1;
    }
    return Unk094fe0_Call_020950b4(a) == 0;
}'''),
('func_0202d7f4','''void func_0202d7f4(void)
{
    if ((s32)data_0213d898[0] == -1) {
        return;
    }
    ImageObj_Unk_077894(data_0213d898[0], 0);
}'''),
('func_0202d830','''int func_0202d830(int a)
{
    return func_0202d668(Unk095560_Unk_095d1c(), 0, 1, a, -1) == 1;
}'''),
('func_0202d86c','''int func_0202d86c(int a, int b, int c, int d)
{
    Unk02dcfc_SetField68();
    func_02095cd8(a, c, b, 0);
    Unk095560_Unk_095d08(d);
    return 1;
}'''),
('func_0202dc60','''int func_0202dc60(int a, s32 b)
{
    u8 *rec = Unk02d15c_GetManagerRecord(a);
    s32 *p = Unk094fe0_Unk_094fec(a);
    int i;
    p[6] = 0;
    p[0] = b;
    FIELD(s32, rec, 0x50) = b;
    for (i = 0; i < 5; i++) {
        p[1 + i] = 0;
    }
    return 1;
}'''),
],P)]
