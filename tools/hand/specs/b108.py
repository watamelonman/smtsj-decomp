SPECS=[
('src/game/unit_020986ac.c',[
('func_0209911c','''void func_0209911c(Unk09911cObj *p)
{
    Unk09911cState *gs = (Unk09911cState *)GetGameState();
    if (gs == 0) {
        return;
    }
    Unk11f2d0_Unk_11f320((u8 *)gs + 30104);
    Unk0986ac_Unk_0989a4(p->unk_10, (u8 *)p->unk_04, p->unk_28);
    if (p->unk_28 == 1 || gs->hdr->unk_10 == 1) {
        p->unk_38 = 1;
    } else {
        p->unk_38 = 0;
    }
}'''),
],'''typedef struct Unk09911cHdr {
    u8 pad_00[16];
    s32 unk_10;
} Unk09911cHdr;
typedef struct Unk09911cState {
    Unk09911cHdr *hdr;
} Unk09911cState;
typedef struct Unk09911cObj {
    u8 pad_00[4];
    u32 unk_04;
    u8 pad_08[8];
    s32 unk_10;
    u8 pad_14[20];
    s32 unk_28;
    u8 pad_2c[12];
    s32 unk_38;
} Unk09911cObj;
void *GetGameState();
void Unk11f2d0_Unk_11f320();
int Unk09974c_Unk_0998d8();
''',[('        func_0209911c(p);','        func_0209911c((void *)p);')]),
('src/game/unit_0209974c.c',[
('func_020999d4','''u32 func_020999d4(int id)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    u16 *buf;
    int off;
    if (e == 0) {
        return 0;
    }
    buf = (u16 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0:
    case 1:
        break;
    case 2:
        return buf[off];
    }
    return 0;
}'''),
('func_02099abc','''void func_02099abc(int id, u16 v)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    u16 *buf;
    int off;
    if (e == 0 || v == 0) {
        return;
    }
    buf = (u16 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0:
    case 1:
        break;
    case 2:
        buf[off] = v;
        break;
    }
    Unk09974c_SetBit6ac(id);
}'''),
],'void Unk09974c_SetBit6ac(int id);\n'),
]
