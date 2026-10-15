SPECS=[
('src/game/unit_02095560.c',[
('func_0209560c','''int func_0209560c(int i)
{
    Unk095560Rec *r = (Unk095560Rec *)Unk02d15c_GetManagerRecord(i);
    s32 *slot = (s32 *)Unk094fe0_Unk_094fec(i);
    if (r->buf != 0) {
        func_02053000(r->buf);
        r->buf = 0;
        r->unk_14 = 0;
    }
    r->id = -1;
    *slot = -1;
    func_0204af80(&r->unk_10);
    return 1;
}'''),
('func_0209596c','''int func_0209596c(u32 a)
{
    s32 slot = -1;
    switch (func_020959d0(a, &slot)) {
    case 0:
        return 0;
    case 1:
        break;
    case 2:
        return 1;
    }
    return Unk095560_Unk_095950(slot, a);
}'''),
('func_020959d0','''int func_020959d0(s32 a, s32 *out)
{
    int i;
    for (i = 2; i < 8; i++) {
        Unk095560Rec *r = (Unk095560Rec *)Unk02d15c_GetManagerRecord(i);
        Unk094fe0_Unk_094fec(i);
        if (r->id == a) {
            return 2;
        }
        if (r->id == -1) {
            *out = i;
            return 1;
        }
    }
    return 0;
}'''),
],'typedef struct Unk095560Rec {\n    u32 buf;\n    u8 pad_04[12];\n    u8 unk_10[4];\n    u32 unk_14;\n    u8 pad_18[56];\n    s32 id;\n} Unk095560Rec;\nint func_02053000();\nint func_020959d0(s32 a, s32 *out);\n'),
]
