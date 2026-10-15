def cp(fn, off):
    return (fn, f'''void {fn}(int i, void *dst)
{{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {{
        return;
    }}
    func_020086bc(dst, data_0216bac8 + i * 328 + {off}, 32);
}}''')
SPECS=[
('src/game/unit_0206e2a0.c',[cp('func_0206e418','220'),cp('func_0206e458','252'),cp('func_0206e498','284')],''),
('src/game/unit_0206e4d8.c',[
('func_0206e5a0','''void func_0206e5a0(u8 *o)
{
    FIELD(u32, o, 0x08) = 0;
    FIELD(u8, o, 0x6c) = 0;
    FIELD(u32, o, 0x68) = 0;
    Unk06e4d8_Unk_06e814((int)o);
}'''),
('func_0206ea0c','''int func_0206ea0c(int i)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return FIELD(s32, Unk06dddc_Unk_06e058(i), 0xd8) > 0;
}'''),
('func_0206ea44','''int func_0206ea44(void)
{
    if (Unk06e4d8_Get_data_02170cc8() == 0) {
        return 0;
    }
    return FIELD(u8, Unk06e4d8_Get_data_02170cc8(), 0x6c) != 0;
}'''),
],'extern u32 data_0216bac4[];\nu8 *Unk06dddc_Unk_06e058();\nvoid Unk06e4d8_Unk_06e814(int arg0);\nu32 Unk06e4d8_Get_data_02170cc8(void);'),
('src/game/unit_0206ea70.c',[
('func_0206ea70','''u32 func_0206ea70(u32 mask)
{
    int i;
    for (i = 0; i < 16; i++) {
        if ((mask & data_021457e8[i]) && data_02170cd4[i] != 0) {
            return data_02170cd4[i];
        }
    }
    return data_02170cd4[0];
}'''),
('func_0206ebb8','''int func_0206ebb8(int i)
{
    Unk06ea70Table *t = data_02170ccc.table;
    if (t == 0 || t->entry[i] == 0) {
        return -1;
    }
    return func_0206f674(i);
}'''),
],'extern u32 data_02170cd4[];\nextern u32 data_021457e8[];\nint func_0206f674();'),
]
