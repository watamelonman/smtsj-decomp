SPECS=[
('src/game/unit_0202f2a8.c',[
('func_020366dc','''int func_020366dc(int v)
{
    int r = (int)(0.1f * v);
    int a = Unk0986ac_Unk_098978(152);
    int b = Unk0986ac_Unk_098978(163);
    if (Unk0986ac_Thunk_02098714(a) == 1) {
        r /= 2;
    }
    if (Unk0986ac_Thunk_02098714(b) == 1) {
        r /= 3;
    }
    if (r < 1) {
        r = 1;
    }
    return r;
}'''),
],'int Unk0986ac_Unk_098978();\nint Unk0986ac_Thunk_02098714();\n'),
('src/game/unit_020a6174.c',[
('func_020a6548','''Unk0a6174Slot *func_020a6548(Unk0a6174Slot *p)
{
    u32 sum = 0;
    u8 acc;
    u32 r;
    int i;
    for (i = 0; i < 8; i++) {
        sum += p[i].weight;
    }
    if ((s32)sum <= 0) {
        return 0;
    }
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < 8; i++) {
        acc += p[i].weight;
        if (r < acc) {
            return &p[i];
        }
    }
    return 0;
}'''),
],'typedef struct Unk0a6174Slot {\n    u8 pad_00[2];\n    u8 weight;\n    u8 pad_03;\n} Unk0a6174Slot;\nint func_02050074();\n'),
('src/game/unit_020e1648.c',[
('func_020e4f54','''int func_020e4f54(Unk0e1648Rec *p)
{
    int m = 0;
    int r;
    int i;
    int c;
    if (p->unk_03 != 0) {
        m = 1;
    } else {
        for (i = 0; i < 3; i++) {
            if (p->ents[i].a != 0 && m < p->ents[i].b) {
                m = p->ents[i].b;
            }
        }
    }
    if (m <= 0) {
        r = 99;
    } else {
        r = 99 / m;
    }
    c = Unk0e1648_Unk_0e4f34(p->id, 99);
    if (r > c) {
        r = c;
    }
    return r;
}'''),
],'typedef struct Unk0e1648Ent {\n    u16 a;\n    u16 b;\n} Unk0e1648Ent;\ntypedef struct Unk0e1648Rec {\n    u16 id;\n    u8 pad_02;\n    u8 unk_03;\n    u8 pad_04[6];\n    Unk0e1648Ent ents[3];\n} Unk0e1648Rec;\n'),
]
