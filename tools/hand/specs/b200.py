PRE = '''void func_02057ddc(u32 value);
void func_02057e18(u32 value);
void func_02057df8(void);
void func_02057eb8(s32 value);
void func_0205de40(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4,
                   float arg5, float arg6, u32 arg7, u32 arg8, u32 arg9);
void func_0205c748(u32 mode, u32 handle, u32 x, u32 y, float sx, float sy,
                   u32 rot, float alpha, u32 priority);
void func_02058e9c(u32 mode, u32 resource, s32 x, s32 y, float alpha,
                   u32 arg5, u32 arg6);
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 arg3, u32 arg4, u32 arg5,
                   u32 resource, u32 value);
u32 Unk0ca69c_Unk_0ca69c(int id);
void Unk0cb32c_Unk_0cb488(u32 handle, s32 x, s32 y, u32 index, u32 arg4, u32 arg5);
int Unk0f3db4_Unk_0f4490(u32 kind, u16 index);
int Unk09974c_Unk_0998d8(u32 id);
void func_020e3e70(Unk0e1648Work *work);
void func_020e2930(Unk0e1648Work *work);
int func_020e4d08(Unk0e1648Work *work, u32 value);
int func_020e49cc(u32 selector, u32 id);
extern u32 data_0213c65c[];
extern u8 data_02150bac[], data_02150bb0[], data_02150bb4[], data_02150bb8[];
extern u8 data_02150bbc[], data_02150bc0[], data_02150bc4[];
'''

F33B8 = r'''/* Draws the ordinary multi-slot list: one row per visible slot, the
 * quantity box once the work reaches state 9, then the detail panel for the
 * selected record (cost entries when +0xec0 is set). */
void func_020e33b8(Unk0e1648Work *work)
{
    int sel = work->unk_007c;
    int first = work->unk_0074;
    int qty;
    int sely = (sel - first) * 12;
    Unk0e1648Rec *rec;
    int i;
    qty = work->unk_0098;
    rec = (Unk0e1648Rec *)Unk0e1648_Unk_0e2d80(work);
    func_02057e18(31);
    func_02057df8();
    func_02057eb8(0);
    func_020e3e70(work);
    func_0205de40(2, work->unk_0004.handle, data_0213c65c[work->unk_0068], work->unk_00a8,
                  0, 1.0f, 1.0f, 0, 0x3f800000, 1);
    if (work->unk_0000 >= 7) {
        func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 0), work->unk_00a8, sely,
                      1.0f, 1.0f, 0, 1.0f, 1);
    }
    func_02057e18(31);
    func_02057df8();
    for (i = 0; i < work->unk_006c; i++) {
        u32 y = i * 12;
        func_02057eb8(1);
        func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i + 13), work->unk_00a8, y,
                      1.0f, 1.0f, 0, 1.0f, 1);
        if (work->unk_0eb8[i] == 0) {
            continue;
        }
        func_02058e9c(1, Unk0ca69c_Unk_0ca69c(func_020e49cc(5, work->unk_00d2[first + i].unk_0004)),
                      work->unk_00a8 + 16, y + 31, 1.0f, 0, 11);
        func_02057e18(31);
        if (func_020e4d08(work, work->unk_00d2[first + i].unk_0002) != 0) {
            func_02057ddc(-1);
        } else {
            func_02057ddc(0x808080ff);
        }
        Unk0cb32c_Unk_0cb488(work->unk_0e94, work->unk_00a8 + 40, y + 32, i, 8, 11);
        func_02057df8();
        if (work->unk_00d2[first + i].unk_0000 == 2) {
            func_0205de40(2, work->unk_0004.handle, 1, work->unk_00a8, y,
                          1.0f, 1.0f, 0, 0x3f800000, 1);
            func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i + 5), work->unk_00a8, y,
                          1.0f, 1.0f, 0, 1.0f, 1);
        }
        func_02057e18(31);
        func_02057df8();
        func_0205de40(2, work->unk_0004.handle, 5, work->unk_00a8, y,
                      1.0f, 1.0f, 0, 0x3f800000, 2);
        func_02057e18(31);
        func_02057df8();
        if (Unk0f3db4_Unk_0f4490(work->unk_0068, work->unk_00d2[first + i].unk_0002) >= 2) {
            func_020a9fd8(1, work->unk_00a8 + 201, y + 33, 2, 5, 11, (u32)data_02150bac,
                          func_020e49cc(0, work->unk_00d2[first + i].unk_0004));
            func_02058e9c(1, 0x611b, work->unk_00a8 + 210, y + 33, 1.0f, 0, 11);
        }
    }
    if (work->unk_0000 >= 9 && work->unk_0068 != 4) {
        func_02057eb8(2);
        func_0205de40(2, work->unk_0004.handle, 4, work->unk_00a8, sely,
                      1.0f, 1.0f, 0, 0x3f800000, 1);
        func_02057e18(31);
        if (work->unk_0098 <= work->unk_00a4) {
            func_02057df8();
        } else {
            func_02057ddc(0x808080ff);
        }
        func_020a9fd8(1, work->unk_00a8 + 232, sely + 33, 2, 5, 15, (u32)data_02150bb0,
                      work->unk_0098);
        func_02057df8();
        if (qty < work->unk_008c) {
            func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 1), work->unk_00a8, sely,
                          1.0f, 1.0f, 0, 1.0f, 1);
        }
        if (qty > 1) {
            func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 2), work->unk_00a8, sely,
                          1.0f, 1.0f, 0, 1.0f, 1);
        }
        func_02057e18(31);
        func_02057df8();
    }
    if (work->unk_00d0 >= 8) {
        func_02057eb8(2);
        func_020e2930(work);
    }
    func_02057eb8(2);
    func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 3), 0, 0,
                  1.0f, 1.0f, 0, 1.0f, 1);
    if (work->unk_0ec0 == 0) {
        func_0205de40(2, work->unk_0004.handle, 22, 0, 0,
                      1.0f, 1.0f, 0, work->unk_00b4.bits, 1);
        if (work->unk_00b4.scale >= 1.0f) {
            func_020e5198(1, (Unk0e1648FlagObject *)work->unk_0e98, 14, 136, 0, 11);
            if (Unk0f3db4_Unk_0f4490(work->unk_0068, work->unk_00d2[sel].unk_0002) >= 2) {
                func_02057ddc(0x2994ffff);
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0e9c, 192, 138, 0, 11);
                func_02057df8();
                if (work->unk_0068 == 4) {
                    func_020a9fd8(1, 229, 141, 2, 5, 15, (u32)data_02150bb4,
                                  Unk09974c_Unk_099d78(rec->id)->unk_04);
                } else {
                    func_020a9fd8(1, 229, 141, 2, 5, 15, (u32)data_02150bb8,
                                  func_0209993c(rec->id));
                }
            }
        }
    } else {
        func_0205de40(2, work->unk_0004.handle, 21, 0, 0,
                      1.0f, 1.0f, 0, work->unk_00b4.bits, 1);
        if (work->unk_00b4.scale >= 1.0f) {
            if (Unk0e1648_IsUnkeecSet((Unk0e1648Obj *)work) != 0) {
                Unk0e1648Ent *ent = &rec->ents[work->unk_0eec];
                int have;
                switch (Unk0e1648_Unk_0e2db0(ent)) {
                case 0:
                    func_02057ddc(0xd02848ff);
                    break;
                case 1:
                    func_02057ddc(0x808080ff);
                    break;
                }
                func_020e5198(1, (Unk0e1648FlagObject *)work->unk_0e98, 14, 136, 0, 11);
                have = func_0209993c(ent->a);
                func_02057ddc(0x2994ffff);
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0e9c, 192, 138, 0, 11);
                func_02057df8();
                func_020a9fd8(1, 229, 141, 2, 5, 15, (u32)data_02150bbc, have);
            } else if (Unk09974c_GetEntryUnk08(rec->id) == 2 && Unk09974c_Unk_0998d8(rec->id) != 0
                       && work->unk_0ee8 == 1) {
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0eb4, 14, 136, 0, 11);
            } else if (rec->ents[0].a == 0) {
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0eb0, 14, 136, 0, 11);
            } else {
                int have;
                int need;
                int ty;
                int row;
                for (i = 0, row = 0, ty = 140; i < 3; ty += 11, row += 11, i++) {
                    u32 id = rec->ents[i].a;
                    if (id == 0) {
                        continue;
                    }
                    have = func_0209993c(id);
                    if (rec->unk_03 != 0) {
                        u16 index = work->unk_00d2[work->unk_007c].unk_0002;
                        if (work->unk_0ee8 != 0 && Unk0f3db4_Unk_0f4510(work->unk_0068, index) != 0) {
                            func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0eb0, 14, 136, 0, 11);
                            break;
                        }
                        need = rec->ents[i].b;
                    } else {
                        need = qty * rec->ents[i].b;
                    }
                    if (Unk09974c_Unk_09a1e4(id) != 0) {
                        func_02057ddc(0xd02848ff);
                    } else if (need > have) {
                        func_02057ddc(0x808080ff);
                    }
                    func_020e5198(1, (Unk0e1648FlagObject *)work->unk_0ea4[i], 34, ty - 2, 0, 11);
                    func_02057df8();
                    func_0205de40(2, work->unk_0004.handle, 20, 0, row,
                                  1.0f, 1.0f, 0, work->unk_00b4.bits, 1);
                    func_02057e18(31);
                    func_020a9fd8(1, 174, ty + 1, 2, 5, 15, (u32)data_02150bc0, have);
                    func_02057ddc(0x73ffbdff);
                    func_020a9fd8(1, 196, ty + 1, 2, 5, 15, (u32)data_02150bc4, need);
                    func_02057df8();
                }
            }
        }
    }
    func_02057eb8(2);
    func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 4), 0, 0,
                  1.0f, 1.0f, 0, 1.0f, 1);
    func_02057e18(31);
    if (work->unk_00b4.scale >= 1.0f) {
        func_02057ddc(0x73ffbdff);
        func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0ea0, 138, 179, 0, 15);
    }
}'''

FIX = [
    ('u32 Unk0ca69c_Unk_0ca69c(void);', 'u32 Unk0ca69c_Unk_0ca69c(int id);'),
    ('void Unk0cb32c_Unk_0cb488(u32 handle, u32 resource, s32 x, s32 y);',
     'void Unk0cb32c_Unk_0cb488(u32 handle, s32 x, s32 y, u32 index, u32 arg4, u32 arg5);'),
    ('u8 pad_00[3]; u8 unk_03; u16 pad_04;\n', 'u8 pad_00[3]; u8 unk_03;\n    unsigned short unk_04:8; unsigned short pad_04:8;\n'),
    # Slot byte 0 is a state byte: 020e33b8 reads it with ldrb at the same base as
    # the +2/+4 halfwords, and state 20 of 020e1b10 promotes 2 to 3.
    ("""/* One 8-byte entry of the record table at work->unk_00d2; entry count is guessed. */
typedef struct Unk0e1648Slot {
    u16 unk_0000;
    u16 unk_0002;
    u16 unk_0004;
    u16 pad_0006;
} Unk0e1648Slot;
""", """/* One 8-byte entry of the record table at work->unk_00d2; entry count is guessed.
 * Byte 0 is a state byte (020e33b8 draws an extra marker for state 2, which
 * state 20 of 020e1b10 promotes to 3). */
typedef struct Unk0e1648Slot {
    u8 unk_0000;
    u8 pad_0001;
    u16 unk_0002;
    u16 unk_0004;
    u16 pad_0006;
} Unk0e1648Slot;

/* One 4-byte (id, count) cost entry of a 0f3de8 record (Unk0e1648Rec.ents). */
typedef struct Unk0e1648Ent {
    u16 a;
    u16 b;
} Unk0e1648Ent;
"""),
    ("""typedef struct Unk0e1648Ent {
    u16 a;
    u16 b;
} Unk0e1648Ent;
typedef struct Unk0e1648Rec {""", "typedef struct Unk0e1648Rec {"),
    ("""/*
 * Ranks a selected record slot: 1 when its limit (unk_0002) exceeds the
 * lookup value for its id (unk_0000), otherwise 2. Returns 0 when the id is
 * not present in the 09974c table, as 020e2e60 treats zero as "no action".
 */
int Unk0e1648_Unk_0e2db0(Unk0e1648Slot *slot)
{
    int value = func_0209993c(slot->unk_0000);
    int limit = slot->unk_0002;
    if (Unk09974c_Unk_09a1e4(slot->unk_0000) != 0) {""", """/*
 * Ranks a record cost entry: 1 when its count (b) exceeds the lookup value
 * for its id (a), otherwise 2. Returns 0 when the id is not present in the
 * 09974c table, as 020e2e60 treats zero as "no action".
 */
int Unk0e1648_Unk_0e2db0(Unk0e1648Ent *entry)
{
    int value = func_0209993c(entry->a);
    int limit = entry->b;
    if (Unk09974c_Unk_09a1e4(entry->a) != 0) {"""),
    ("""    Unk0e1648Slot *entry = (Unk0e1648Slot *)(Unk0e1648_Unk_0e2d80(work) + 10 + work->unk_0eec * 4);
    int rank = Unk0e1648_Unk_0e2db0(entry);
    switch (rank) {
    case 0:
        func_020e50e8(work->unk_0e98, entry->unk_0000, 2);
        break;
    default:
        func_020e50e8(work->unk_0e98, entry->unk_0000, 0);""", """    Unk0e1648Ent *entry = (Unk0e1648Ent *)(Unk0e1648_Unk_0e2d80(work) + 10 + work->unk_0eec * 4);
    int rank = Unk0e1648_Unk_0e2db0(entry);
    switch (rank) {
    case 0:
        func_020e50e8(work->unk_0e98, entry->a, 2);
        break;
    default:
        func_020e50e8(work->unk_0e98, entry->a, 0);"""),
    ("""        Unk0e1648Slot *entry;
        work->unk_0eec = i;
        entry = (Unk0e1648Slot *)(Unk0e1648_Unk_0e2d80(work) + 10 + work->unk_0eec * 4);
        switch (Unk0e1648_Unk_0e2db0(entry)) {
        case 0: func_020e50e8(work->unk_0e98, entry->unk_0000, 2); break;
        default: func_020e50e8(work->unk_0e98, entry->unk_0000, 0); break;""", """        Unk0e1648Ent *entry;
        work->unk_0eec = i;
        entry = (Unk0e1648Ent *)(Unk0e1648_Unk_0e2d80(work) + 10 + work->unk_0eec * 4);
        switch (Unk0e1648_Unk_0e2db0(entry)) {
        case 0: func_020e50e8(work->unk_0e98, entry->a, 2); break;
        default: func_020e50e8(work->unk_0e98, entry->a, 0); break;"""),
    ("*(u8 *)&work->unk_00d2[work->unk_00d0].unk_0000 = value;", "work->unk_00d2[work->unk_00d0].unk_0000 = value;"),
    ("if (*(u8 *)&slot->unk_0000 == 2) *(u8 *)&slot->unk_0000 = 3;", "if (slot->unk_0000 == 2) slot->unk_0000 = 3;"),
]

SPECS = [('src/game/unit_020e1648.c', [('func_020e33b8', F33B8)], PRE, FIX)]
