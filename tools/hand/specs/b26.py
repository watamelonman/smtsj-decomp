SPECS=[
('src/game/unit_02094fe0.c',[
('func_02095178','''int func_02095178(u8 *p, int bit)
{
    if (p == 0) {
        return 0;
    }
    if (bit < 0 || bit > 31) {
        return 0;
    }
    return (FIELD(u32, p, 0x18) & (1 << bit)) != 0;
}'''),
('func_020951b0','''void func_020951b0(u8 *p, int i, u32 v)
{
    if (p == 0) {
        return;
    }
    if (i < 0 || i >= 5) {
        return;
    }
    ((u32 *)(p + 4))[i] = v;
}'''),
('func_020951d4','''u32 func_020951d4(u8 *p, int i)
{
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 5) {
        return 0;
    }
    return ((u32 *)(p + 4))[i];
}'''),
('func_02095204','''void func_02095204(u32 a, int b)
{
    if (a >= 15360) {
        return;
    }
    func_020950e4((u8 *)Unk094fe0_Thunk_0202e8cc() + 512, a, b);
}'''),
('func_02095230','''int func_02095230(Unk094fe0Work *w, u32 a)
{
    if (a >= 15360) {
        return 0;
    }
    return (FIELD(u8, (u8 *)w + (a >> 3), 512) & (1 << (a & 7))) != 0;
}'''),
('func_02095320','''int func_02095320(Unk094fe0Work *w, u32 a)
{
    u32 i = a - 1;
    u8 *bits;
    if (i >= 128) {
        return 0;
    }
    bits = (u8 *)Unk094fe0_Unk_095004((int)w);
    return (bits[i >> 3] & (1 << (i & 7))) != 0;
}'''),
('func_02095350','''void func_02095350(u32 a, int b)
{
    func_02095370(Unk094fe0_Thunk_0202e8cc(), a, b);
}'''),
('func_02095370','''void func_02095370(Unk094fe0Work *w, u32 a, int b)
{
    u32 i = a - 1;
    if (i >= 128) {
        return;
    }
    func_020950e4((u8 *)Unk094fe0_Unk_095004((int)w), i, b);
}'''),
],'''void func_020950e4();
void func_02095370(Unk094fe0Work *w, u32 a, int b);''',
[('void func_02095320(Unk094fe0Work *w, u32 a);','int func_02095320(Unk094fe0Work *w, u32 a);')]),
]
# func_020953c4 skipped: mwcc folds the +420 base into strb #2470 (ROM keeps add r1,r0,#420)
