P1='''int Unk02e000_Unk_02e774();
u8 *Unk02e000_Thunk_0202e788();

typedef struct Unk02ee5cRec {
    u8 pad_0000[0xb];
    u8 flag_000b_0 : 1;
    u8 pad_000c[0x18];
} Unk02ee5cRec;                 /* 36 bytes; same table as unit_0202e000 (work+0x16FC, ids 1..491) */'''
P3='int Unk02e000_Unk_02e774();'
B='''    if (i >= 64) {
        return%s;
    }
    if (i < 0) {
        return%s;
    }
'''
SPECS=[
('src/game/unit_0202ee5c.c',[
('func_0202eec0','''int func_0202eec0(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02ee5cRec *r = &((Unk02ee5cRec *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc))[id - 1];
        return r->flag_000b_0 ? 1 : 0;
    }
}'''),
('func_0202ef0c','''int func_0202ef0c(void)
{
    u8 v = Unk02e000_Thunk_0202e788()[0x70];
    if (v >= 160) {
        return 5;
    }
    if (v <= 95) {
        return 4;
    }
    return 1;
}'''),
],P1),
('src/game/unit_0202f078.c',[
('func_0202f104','''int func_0202f104(int i)
{
    if (i <= 0) {
        return 0;
    }
    if (i >= 37) {
        return 0;
    }
    if (((u8 *)Unk02e000_GetWorkArea() + (i >> 3))[0x380] & (u8)(1 << (i & 7))) {
        return 1;
    }
    return 0;
}'''),
('func_0202f14c','''void func_0202f14c(int i)
{
    u8 mask;
    u8 *p;
    if (i <= 0) {
        return;
    }
    if (i >= 37) {
        return;
    }
    mask = 1 << (i & 7);
    p = (u8 *)Unk02e000_GetWorkArea() + 0x380;
    if ((mask & p[i >> 3]) == 0) {
        p[i >> 3] += mask;
    }
}'''),
('func_0202f230','''void func_0202f230(int i)
{
'''+B%('','')+'''    {
        u8 *p = (u8 *)Unk02e000_Unk_02e774() + 0x5e12;
        if ((p[i] & 2) == 0) {
            p[i] = 3;
        }
    }
}'''),
('func_0202f268','''int func_0202f268(int i)
{
'''+B%(' 0',' 0')+'''    if (((u8 *)Unk02e000_Unk_02e774() + i)[0x5e12] & 1) {
        return 1;
    }
    return 0;
}'''),
],''),
('src/game/unit_0202f2a8.c',[
('func_0202f2a8','''void func_0202f2a8(int i)
{
'''+B%('','')+'''    {
        u8 *p = (u8 *)Unk02e000_Unk_02e774() + 0x5e12;
        p[i] &= ~1;
    }
}'''),
('func_0202f330','''void func_0202f330(int k, u32 v)
{
    u8 *w = (u8 *)Unk02e000_Unk_02e774();
    switch (k) {
    case 1:
        *(u32 *)(w + 0x6138) = v;
        break;
    case 2:
        *(u32 *)(w + 0x613c) = v;
        break;
    case 3:
        *(u32 *)(w + 0x6140) = v;
        break;
    }
}'''),
],P3)]
