SPECS=[
('src/game/unit_0206e4d8.c',[
('func_0206e538','''void func_0206e538(void)
{
    u8 *p = (u8 *)func_020611dc(func_0206e5bc, 0, 0, 0, 112, 3, 0, 0);
    if (p == 0) {
        return;
    }
    func_02008848(p, 0, 112);
    *data_02170cc8 = (u32)p;
    p[108] = 0;
}'''),
('func_0206e854','''s32 func_0206e854(void)
{
    Unk06e4d8Work *w;
    if (Unk06e4d8_Get_data_02170cc8() != 0 && ((u8 *)Unk06e4d8_Get_data_02170cc8())[108] != 0) {
        w = (Unk06e4d8Work *)*data_02170cc8;
        return (((s32)w->unk_002c >> 12) << 24) | (((s32)w->unk_0030 >> 12) << 16) | (((s32)w->unk_0034 >> 12) << 8);
    }
    return -1;
}'''),
],'void *func_020611dc();\nvoid func_0206e5bc();\nvoid func_02008848();\n'),
('src/game/unit_0206ea70.c',[
('func_0206eb54','''void func_0206eb54(void)
{
    int i;
    for (i = 0; i < 16; i++) {
        data_02170cd4[i] = 0;
    }
    func_02053000(data_02170ccc.table->count);
    data_02170ccc.table->count = 0;
    func_02053000(data_02170ccc.table);
    data_02170ccc.table = 0;
    Unk06ea70_Unk_06f4e4();
}'''),
],'int func_02053000();\nvoid Unk06ea70_Unk_06f4e4(void);\n'),
]
