FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_021071e4.c',[
('func_021088fc','''void func_021088fc(u8 *p)
{
    if (FIELD(u32, p, 32) == 0) {
        Unk096754_CopyAreaPos(p);
        return;
    }
    Unk0979d8_ResetFields(Unk02e000_GetAreaRecord(FIELD(s8, p + FIELD(u32, p, 32), 59)));
}'''),
('func_02108aec','''int func_02108aec(int x)
{
    switch (x) {
    case 1:
    case 7:
        return 0;
    }
    return 1;
}'''),
('func_02108b08','''void func_02108b08(Unk1071e4Obj *p, int i)
{
    func_0205c41c(p->h[i], 0);
    func_0205caa8(p->h[i], data_0213c9ac[i]);
}'''),
('func_02108b94','''void func_02108b94(u32 a)
{
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk09727c_GetAreaSub48(a)));
}'''),
],FX+'typedef struct Unk1071e4Obj {\n    u8 pad[8];\n    u32 h[1];\n} Unk1071e4Obj;\nvoid Unk096754_CopyAreaPos();\nint Unk02e000_GetAreaRecord();\nvoid Unk0979d8_ResetFields();\nvoid func_0205c41c();\nvoid func_0205caa8();\nextern u32 data_0213c9ac[];\nint Unk09727c_GetAreaSub48();\nint func_02063a30();\nvoid func_02061f10();'),
('src/game/unit_02108bc8.c',[
('func_02108bc8','''void func_02108bc8(u32 a, u32 b)
{
    func_02061f10(a, -1, 0, 0, func_02063a30(Unk0a163c_Unk_0a1814(b)));
}'''),
('func_02108c00','''u32 func_02108c00(void)
{
    return 0x5bfc;
}'''),
('func_02108c0c','''void func_02108c0c(void)
{
    if (*data_02176e34 != 0) {
        return;
    }
    *data_02176e34 = func_02052fe0(0x5ffc);
}'''),
('func_02108c88','''u32 func_02108c88(void)
{
    if (*data_02176e34 != 0) {
        return *(u16 *)*data_02176e34;
    }
    return 0;
}'''),
],'int Unk0a163c_Unk_0a1814();\nint func_02063a30();\nvoid func_02061f10();\nu32 func_02052fe0();'),
('src/game/unit_0210a034.c',[
('func_0210a08c','''int func_0210a08c(void)
{
    u32 p = Unk10a034_Get_data_02176e38();
    if (p == 0) {
        return 1;
    }
    return FIELD(u32, p, 8) == 18;
}'''),
('func_0210ae84','''int func_0210ae84(Unk10a034Obj *p, u32 x)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (x == p->ids[i]) {
            return 1;
        }
    }
    return 0;
}'''),
('func_0210aed0','''void func_0210aed0(u8 *p, u32 id)
{
    int i;
    Unk10a034Ent *e = (Unk10a034Ent *)(p + 36);
    for (i = 0; i < 12; i++) {
        if (e->used != 0 && e->id == id) {
            e->val = 0;
            return;
        }
        e++;
    }
}'''),
],FX+'typedef struct Unk10a034Ent {\n    u16 id;\n    u16 pad;\n    u32 used;\n    u32 val;\n} Unk10a034Ent;\ntypedef struct Unk10a034Obj {\n    u8 pad[200];\n    u16 ids[4];\n} Unk10a034Obj;'),
]
