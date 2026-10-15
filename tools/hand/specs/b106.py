SPECS=[
('src/game/unit_02095560.c',[
('func_02096484','''int func_02096484(void)
{
    switch (func_02095818()) {
    case 0:
        return func_0206552c() == 0;
    case 2:
        return func_0206552c() == 0;
    case 3:
        return func_0206552c() == 0;
    case 1:
    case 4:
    case 5:
    case 6:
    default:
        return 1;
    }
}'''),
],'int func_0206552c();\n'),
('src/game/unit_02096754.c',[
('func_02097220','''void func_02097220(int i, u8 v)
{
    Unk096754Work *w = (Unk096754Work *)Unk02e000_Thunk_0202e788();
    switch (i) {
    case 0:
        w->unk_16 = v;
        break;
    case 1:
        w->unk_17 = v;
        break;
    case 2:
        w->unk_18 = v;
        break;
    case 3:
        w->unk_19 = v;
        break;
    case 4:
        w->unk_1a = v;
        break;
    }
    func_02096c8c();
}'''),
],'typedef struct Unk096754Work {\n    u8 pad_00[22];\n    u8 unk_16;\n    u8 unk_17;\n    u8 unk_18;\n    u8 unk_19;\n    u8 unk_1a;\n} Unk096754Work;\nvoid func_02096c8c();\n'),
('src/game/unit_020981dc.c',[
('func_02098258','''s8 func_02098258(int a, int i)
{
    Unk0981dcRec *r = (Unk0981dcRec *)Unk096754_GetAreaRecordIf(a);
    if (r == 0) {
        return 0;
    }
    switch (i) {
    case 0:
        return r->unk_0e;
    case 1:
        return r->unk_0f;
    case 2:
        return r->unk_10;
    case 3:
        return r->unk_11;
    case 4:
        return r->unk_12;
    }
    return 0;
}'''),
],'typedef struct Unk0981dcRec {\n    u8 pad_00[14];\n    s8 unk_0e;\n    s8 unk_0f;\n    s8 unk_10;\n    s8 unk_11;\n    s8 unk_12;\n} Unk0981dcRec;\n'),
]
