SPECS=[
('src/game/unit_02071dc0.c',[
('func_02071fcc','''int func_02071fcc(void)
{
    int i;
    FIELD(s32, data_02171d14, 0x604) = 0;
    for (i = 0; i < FIELD(s32, data_02171d14, 0x600); i++) {
        if (func_0205b36c(&((Unk071dc0Rec *)data_02170d14)[i]) == 0) {
            return 1;
        }
    }
    FIELD(s32, data_02171d14, 0x604) = 4;
    return 0;
}'''),
],'typedef struct Unk071dc0Rec {\n    u8 pad_00[24];\n} Unk071dc0Rec;\nint func_0205b36c();\n'),
('src/ImageObj.c',[
('func_020779f4','''void func_020779f4(ImageObjNode *n)
{
    s32 v;
    u32 c;
    if (n == 0 || n->unk_68 == 0) {
        return;
    }
    v = n->unk_38;
    c = -1;
    if (v < 31) {
        v = v * 255 / 31;
        c = (v << 24) | (v << 16) | (v << 8);
    }
    Unk065e88_SetUnkField28(n->unk_68, c);
}'''),
('func_02077c30','''void func_02077c30(ImageObjNode *n)
{
    ImageObjWork *w = (ImageObjWork *)ImageObj_Get_data_0217231c();
    if (n == 0) {
        return;
    }
    if (n->unk_70 != 0) {
        Unk0a163c_Call_020a1b08(w->unk_0034, Unk0a163c_Unk_0a1798((u16)n->unk_50), w->unk_0010);
    } else {
        func_020a1b68(w->unk_0034, (u16)n->unk_50, w->unk_0010);
    }
    Unk0a163c_Unk_0a21f8(w->unk_0034);
    n->unk_6c = 1;
}'''),
],'typedef struct ImageObjNode {\n    u8 pad_00[0x38];\n    s8 unk_38;\n    u8 pad_39[0x17];\n    u32 unk_50;\n    u8 pad_54[0x14];\n    u32 unk_68;\n    u32 unk_6c;\n    u32 unk_70;\n} ImageObjNode;\nvoid Unk065e88_SetUnkField28();\nint Unk0a163c_Unk_0a1798();\nvoid Unk0a163c_Call_020a1b08();\nvoid func_020a1b68();\nvoid Unk0a163c_Unk_0a21f8();\n'),
]
