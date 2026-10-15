SPECS=[
('src/game/unit_0206e2a0.c',[
('func_0206e2b8','''u32 func_0206e2b8(int i, u32 key)
{
    u32 v = 0;
    int j;
    Unk06e2a0Rec *r;
    Unk06e2a0Ent *c;
    if ((s32)(data_0216bac4[0] - 1) - i < 0) {
        return v;
    }
    r = (Unk06e2a0Rec *)data_0216bac8 + i;
    c = r->ents;
    for (j = 0; j < 6; j++, c++) {
        if (key == c->key) {
            v = *(u32 *)(data_0216bafc + i * 328 + j * 24);
            break;
        }
    }
    return v;
}'''),
('func_0206e334','''Unk06e2a0Ent *func_0206e334(int i, u32 key)
{
    Unk06e2a0Rec *r;
    int j;
    Unk06e2a0Ent *c;
    if ((s32)(data_0216bac4[0] - 1) - i < 0) {
        return 0;
    }
    r = (Unk06e2a0Rec *)data_0216bac8 + i;
    c = r->ents;
    for (j = 0; j < 6; j++, c++) {
        if (key == c->key) {
            return &r->ents[j];
        }
    }
    return 0;
}'''),
],'typedef struct Unk06e2a0Ent {\n    u32 unk_00;\n    u32 key;\n    u32 val;\n    u8 pad_0c[12];\n} Unk06e2a0Ent;\ntypedef struct Unk06e2a0Rec {\n    u8 pad_000[44];\n    Unk06e2a0Ent ents[6];\n    u8 pad_0bc[140];\n} Unk06e2a0Rec;\n'),
]
