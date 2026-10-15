FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
M = '''typedef struct Unk044904Bits {
    u8 pad_0000[0x40];
    u32 b0 : 3;
    u32 b3 : 1;
    u32 b4 : 5;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 b11 : 9;
    u32 b20 : 1;
    u32 b21 : 11;
    u8 pad_0044[0x8];
    u32 unk_004c;
} Unk044904Bits;
typedef struct Unk044904Item {
    u32 hdr;
    u8 pad[732];
} Unk044904Item;
typedef struct Unk044904Items {
    u8 pad_0000[876];
    Unk044904Item items[12];
} Unk044904Items;
'''
SPECS=[
('src/game/unit_02044904.c',[
('func_02045480','''void func_02045480(void)
{
    Unk044904Bits *m = (Unk044904Bits *)Unk044904_Get_data_0215ee98();
    Unk044904Items *it = (Unk044904Items *)m;
    int i;
    if (m->b10) {
        return;
    }
    if (m->b20) {
        return;
    }
    m->b20 = 1;
    func_02121d84();
    for (i = 0; i < 12; i++) {
        if (((it->items[i].hdr >> 16) & 0xff) == 1) {
            func_02122188(&it->items[i]);
        }
    }
    func_02122200();
}'''),
('func_02045b74','''void func_02045b74(void)
{
    Unk044904Objs *m = (Unk044904Objs *)Unk044904_Get_data_0215ee98();
    int i;
    for (i = 0; i < 10; i++) {
        u8 *o = (u8 *)m->objs[i];
        if (o != 0 && func_0204a9ec(o) != 0 && ((FIELD(u32, o, 0) >> 16) & 0xff) == 2) {
            func_0204a884(o);
        }
    }
}'''),
('func_02045bd0','''void func_02045bd0(int f)
{
    Unk044904Bits *m = (Unk044904Bits *)Unk044904_Get_data_0215ee98();
    if (m->b3) {
        f = 0;
    }
    if (f != 0) {
        if (func_0205e4f8(24) == 0) {
            func_0205e484(24, 8);
        }
    } else {
        if (func_0205e4f8(m->unk_004c) == 0) {
            func_0205e484(m->unk_004c, 8);
        }
    }
}'''),
('func_02045d38','''int func_02045d38(void)
{
    Unk044904Bits *m = (Unk044904Bits *)Unk044904_Get_data_0215ee98();
    Unk09d42c_Init_data_02176278();
    func_020458e8();
    func_020525cc(4);
    Unk0a4e48_Unk_0a4e9c(1);
    Unk05ae50_Unk_05afd8(0x4000);
    if (m->b9) {
        func_020a609c(1);
    } else {
        func_020a609c(0);
    }
    return 1;
}'''),
('func_020460ac','''int func_020460ac(void)
{
    if (func_020a4f3c() != 0) {
        return 0;
    }
    if (func_02052728() != 0) {
        return 0;
    }
    if (Unk09d060_Unk_09d13c() == 0) {
        return 0;
    }
    if (func_0205e4f8(-1) != 0) {
        return 0;
    }
    func_02045480();
    return 1;
}'''),
],FX+M+'void func_02121d84();\nvoid func_02122188();\nvoid func_02122200();\nint func_0204a9ec();\nvoid func_0204a884();\nint func_0205e4f8();\nvoid func_0205e484();\nvoid Unk09d42c_Init_data_02176278();\nvoid func_020458e8();\nvoid func_020525cc();\nvoid Unk0a4e48_Unk_0a4e9c();\nvoid Unk05ae50_Unk_05afd8();\nvoid func_020a609c();\nint func_020a4f3c();\nint func_02052728();\nint Unk09d060_Unk_09d13c();\nvoid func_02045480(void);\n'),
]
