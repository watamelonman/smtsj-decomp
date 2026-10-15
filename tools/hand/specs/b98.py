SPECS=[
('src/game/unit_020939f0.c',[
('func_02093b14','''void func_02093b14(Unk0939f0Ents *p)
{
    int i;
    Unk0939f0Ent *e;
    func_02093b6c(0, &p->e[0]);
    for (i = 0, e = &p->e[1]; i < 16; i++, e++) {
        func_02093b6c(1, e);
    }
    func_02093b6c(2, &p->e[17]);
    func_02093b6c(3, &p->e[18]);
}'''),
],'typedef struct Unk0939f0Ent {\n    u8 pad_00[112];\n} Unk0939f0Ent;\ntypedef struct Unk0939f0Ents {\n    Unk0939f0Ent e[19];\n} Unk0939f0Ents;\nvoid func_02093b6c();\n'),
('src/game/unit_020946e0.c',[
('func_02094bd4','''void func_02094bd4(int a, u32 b, u8 c)
{
    Unk0946e0Task *t = (Unk0946e0Task *)func_020611dc(Unk0946e0_Unk_094b98, 0, 0, 0, 20, 0, 0, 0);
    t->unk_08 = -1;
    t->unk_0c = b;
    t->unk_04 = ((100 - a) << 8) / 100;
    t->unk_10 = c;
    Unk09d060_Unk_09d170(t);
}'''),
],'typedef struct Unk0946e0Task {\n    u32 unk_00;\n    s32 unk_04;\n    s32 unk_08;\n    u32 unk_0c;\n    u8 unk_10;\n} Unk0946e0Task;\nvoid *func_020611dc();\nvoid Unk0946e0_Unk_094b98(int arg0);\nvoid Unk09d060_Unk_09d170();\n'),
('src/game/unit_02094fe0.c',[
('func_0209502c','''void func_0209502c(Unk094fe0Work *w, int a, int b)
{
    u8 v;
    func_020950e4(Unk094fe0_Nop_095000(w), a, b);
    func_020e6708(a, b);
    v = ((u8 *)Unk02e000_GetWorkArea())[855];
    switch (a) {
    case 0x70c:
        if (v < 10) {
            v = 10;
        }
        break;
    case 0x70d:
        if (v < 12) {
            v = 12;
        }
        break;
    }
    ((u8 *)Unk02e000_GetWorkArea())[855] = v;
}'''),
],'void func_020950e4();\nvoid func_020e6708();\nvoid *Unk02e000_GetWorkArea();\n'),
]
