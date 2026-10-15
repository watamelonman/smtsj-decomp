FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_020ea208.c',[
('func_020ead64','''void func_020ead64(void)
{
    u8 *q = (u8 *)func_02044ec4(Unk0e8228_GetArr40(Unk0e8228_Unk_0e8374(5)));
    if (((u32)(q[642] << 29) >> 31) != 0) {
        Unk0a163c_Unk_0a1814(0x17d);
        return;
    }
    Unk0a163c_Unk_0a1814(FIELD(u16, q, 472));
}'''),
],'int Unk0e8228_GetArr40();\nint func_02044ec4();\nvoid Unk0a163c_Unk_0a1814();'),
('src/CaveArea.c',[
('func_020ed364','''void func_020ed364(u8 *p)
{
    u32 c = FIELD(u32, p, 188);
    if (p[168] == 0) {
        if (c == 5) {
            func_0205de30(FIELD(u32, p, 4), 8, FIELD(u32, p, 128));
            return;
        }
        func_0205de30(FIELD(u32, p, 4), c, FIELD(u32, p, 128));
        return;
    }
    func_0205de30(FIELD(u32, p, 4), c + 5, FIELD(u32, p, 128));
}'''),
('func_020ed60c','''void func_020ed60c(float *p)
{
    p[0] = 96.0f;
    p[1] = 8.0f;
    p[2] = 0.0f;
    FIELD(u32, p, 12) = 16;
}'''),
('func_020edb4c','''void func_020edb4c(u8 *p)
{
    int x;
    s8 s = FIELD(s8, p, 356);
    int c = FIELD(int, p, 188);
    u8 b = p[168];
    if (c == s) {
        x = b == 0 ? 50 : 51;
    } else {
        x = b == 0 ? c + 10 : c + 16;
    }
    func_02124224((u16)x);
}'''),
],'void func_0205de30();\nvoid func_02124224();'),
('src/game/unit_020eeb20.c',[
('func_020eeb20','''void func_020eeb20(u32 a)
{
    u32 w = *data_02176de4;
    Unk0e8228_Unk_0e8d90(FIELD(u32, w, 68), Unk0f8448_GetUnkField10(a));
}'''),
],FX+'extern u32 data_02176de4[];\nint Unk0f8448_GetUnkField10();\nvoid Unk0e8228_Unk_0e8d90();'),
('src/game/unit_020ef248.c',[
('func_020ef2cc','''void func_020ef2cc(Unk0ef248Obj *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->unk_f4[i] = 0;
    }
}'''),
('func_020ef6fc','''void func_020ef6fc(u8 *p)
{
    func_020f8478(p + 80, Unk0e8228_Unk_0e8374(FIELD(u32, p, 68)));
    func_020ef8d0(p + 80);
    if (Unk0e8228_Unk_0e84e4() >= 6) {
        Unk0feba0_Unk_0febe8(3);
    } else {
        Unk0feba0_Unk_0febe8(2);
    }
    func_020ef2cc((Unk0ef248Obj *)p);
}'''),
('func_020ef74c','''int func_020ef74c(u32 a, u32 b)
{
    if (Unk0e8228_Thunk_02045c38(a) != 0 || func_020e8f74() != 0) {
        if (Unk0e8228_Unk_0e8fe4(Unk0e8228_GetArr88Field20(b)) == 1) {
            return 0;
        }
    }
    return 1;
}'''),
],FX+'typedef struct Unk0ef248Obj {\n    u8 pad[0xf4];\n    u32 unk_f4[6];\n} Unk0ef248Obj;\nint Unk0e8228_Unk_0e8374();\nvoid func_020f8478();\nvoid func_020ef8d0();\nu32 Unk0e8228_Unk_0e84e4();\nvoid Unk0feba0_Unk_0febe8();\nint Unk0e8228_Thunk_02045c38();\nint func_020e8f74();\nint Unk0e8228_Unk_0e8fe4();\nint Unk0e8228_GetArr88Field20();'),
]
