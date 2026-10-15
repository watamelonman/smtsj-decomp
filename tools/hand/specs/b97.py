SPECS=[
('src/ImageObj.c',[

('func_02077ea4','''void func_02077ea4(ImageObjNode *n)
{
    if (n->unk_68 == 0) {
        return;
    }
    if (n->unk_68 != 0) {
        func_02061424(n->unk_68);
        n->unk_68 = 0;
    }
    if (n->unk_60 != 0) {
        func_0205ddb4(n->unk_60);
        n->unk_60 = 0;
    }
    if (n->unk_64 != 0) {
        func_0205c368(n->unk_64);
        n->unk_64 = 0;
    }
}'''),

],'''void func_0205c368();
''',[('''typedef struct ImageObjNode {
    u8 pad_00[0x38];''','''typedef struct ImageObjNode {
    u8 pad_00[0x30];
    s32 unk_30;
    u8 pad_34[4];'''),('''    u8 pad_39[0x17];
    u32 unk_50;
    u8 pad_54[0x14];
    u32 unk_68;''','''    u8 pad_39[0x17];
    u32 unk_50;
    u8 pad_54[0xc];
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;''')]),
]
