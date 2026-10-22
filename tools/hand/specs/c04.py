TU = 'src/CampStatus.c'
PRE = '''/* Record buffer filled by Unk02e000_SetRecord (36 bytes on the stack in func_020dc3b8). */
typedef struct CampStatusSavedRecord {
    u8 pad_0000[0x10];
    u16 unk_0010[6];            /* +0x10: id list, 0-terminated */
    u8 pad_001c[0x8];
} CampStatusSavedRecord;
int Unk02e000_SetRecord(u32 id, CampStatusSavedRecord *out);
void func_0204fcb0(u32 slot, u32 v);
void func_0205bb68(void);
void func_02053000(u32 handle);
void func_0205ddb4(u32 handle);
void func_0205c368(u32 handle);
void func_02061424();
'''
FIX = [
("""extern CampStatusWork *data_02176be4;
""", """extern CampStatusWork *data_02176be4;

""" + PRE),
("int func_02061424();\n", ""),
("""typedef struct CampStatusEntry {
    u16 unk_00;
    u8 unk_02;
    u8 pad_03[0x2];
    u8 kind;
} CampStatusEntry;""", """typedef struct CampStatusEntry {
    u16 unk_00;
    u8 unk_02;
    u8 pad_03;
    u8 unk_04;
    u8 kind;                    /* +0x05: 4 and 5 get their own colours */
    u8 pad_06[0x4];
    u16 pad_0a_0 : 1;           /* +0x0a: three small values */
    u16 unk_0a_1 : 4;
    u16 unk_0a_5 : 3;
    u16 unk_0a_8 : 3;
    u16 pad_0a_b : 5;
    u8 unk_0c;
    u8 pad_0d;
    u8 unk_0e;
    u8 pad_0f[0x1f];
    u16 unk_002e[6];            /* +0x2e: id list, 0-terminated */
} CampStatusEntry;"""),
("""typedef struct CampStatusRecordSet {
    u8 pad_0000[0x48];
    CampStatusRecord rec[3];
} CampStatusRecordSet;""", """typedef struct CampStatusRecordSet {
    u8 pad_0000[0x16];
    u16 pad_16_0 : 5;           /* +0x16: three small values */
    u16 unk_16_5 : 4;
    u16 unk_16_9 : 3;
    u16 unk_16_c : 3;
    u16 pad_16_f : 1;
    u8 unk_0018;
    u8 pad_0019;
    u8 unk_001a;
    u8 pad_001b[0x2d];
    CampStatusRecord rec[3];
} CampStatusRecordSet;"""),
("""typedef struct CampStatusInfo {
    u8 pad_0000[0x2];
    u8 unk_0002;
    u8 pad_0003[0x5];
    u8 lo : 4;                  /* +0x08: two nibbles compared by CampStatus_Unk_0db824 */
    u8 hi : 4;
    u8 unk_0009;
    u8 pad_000a[0x36];""", """typedef struct CampStatusInfo {
    u8 pad_0000[0x2];
    u8 unk_0002;                /* +0x02: 3 and 4 select the slot set in func_020db910 */
    u8 pad_0003;
    u32 pad_04_0 : 20;
    u32 unk_04_20 : 12;         /* +0x04: top 12 bits */
    u8 lo : 4;                  /* +0x08: two nibbles compared by CampStatus_Unk_0db824 */
    u8 hi : 4;
    u8 unk_0009;
    u8 pad_000a;
    u8 unk_000b;
    u8 pad_000c[0x34];"""),
("""typedef struct CampStatusUnit {
    u8 pad_0000[0x28];
    u16 unk_0028[6];            /* +0x28: id list, 0-terminated */
    u8 pad_0034[0x2];
    u16 unk_0036;""", """typedef struct CampStatusUnit {
    u8 pad_0000[0x1e];
    s16 unk_001e;               /* +0x1e: compared > 0 by func_020dd9d8 */
    u8 pad_0020[0x8];
    u16 unk_0028[6];            /* +0x28: id list, 0-terminated */
    u16 unk_0034;               /* +0x34: values 1 and 7 are treated alike by func_020dd9d8 */
    u16 unk_0036;"""),
("""    CampStatusFlagObj *unk_0078;
    u8 pad_007c[0x18];
    CampStatusAnim *unk_0094;
    u8 pad_0098[0x24];""", """    CampStatusFlagObj *unk_0078;
    u8 pad_007c[0x8];
    u32 unk_0084;               /* +0x84/+0x88/+0x90: handles released by func_020dc908 */
    u32 unk_0088;
    u8 pad_008c[0x4];
    u32 unk_0090;
    CampStatusAnim *unk_0094;
    u8 pad_0098[0x4];
    u32 unk_009c;               /* +0x9c/+0xa0/+0xa8/+0xac: released by func_020dc908 */
    u32 unk_00a0;
    u8 pad_00a4[0x4];
    u32 unk_00a8;
    void *unk_00ac;
    u8 pad_00b0[0xc];"""),
("""    u32 unk_0258;
    u8 pad_025c[0x4];""", """    u32 unk_0258;
    u32 unk_025c;               /* +0x25c: selects the id list in func_020dc3b8 */"""),
]
SPECS = [(TU, [
('func_020db910', '''/* Push info's values into the slots via func_0204fcb0/func_0204faf0: entries of groups (14, 1),
 * (14, 2) and (14, 3) go to slots 1-3 when unk_0002 is 3 and to slots 4-6 when it is 4; the
 * nibbles go through func_0204faf0 (the high one only when it differs). */
void func_020db910(CampStatusInfo *info)
{
    u32 v;
    if (info == 0) {
        return;
    }
    v = func_0204fed8(func_020445f4(14, 1), info->unk_0009);
    if (info->unk_0002 == 3) {
        func_0204fcb0(1, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(4, v);
    }
    if (info->unk_0002 == 3) {
        func_0204faf0(1, info->lo);
        if (info->lo != info->hi) {
            func_0204faf0(2, info->hi);
        }
    }
    if (info->unk_0002 == 4) {
        func_0204faf0(3, info->lo);
        if (info->lo != info->hi) {
            func_0204faf0(4, info->hi);
        }
    }
    v = func_0204fed8(func_020445f4(14, 2), info->unk_04_20);
    if (info->unk_0002 == 3) {
        func_0204fcb0(2, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(5, v);
    }
    v = func_0204fed8(func_020445f4(14, 3), info->unk_000b);
    if (info->unk_0002 == 3) {
        func_0204fcb0(3, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(6, v);
    }
}'''),
('func_020dba84', '''/* Fill slots 1-5 from entry id's values (groups (14, 1..4)) and show icon data_0213c568[4] on
 * unk_00c8, or icon 5 when the two 3-bit values at +0x0a differ. */
void func_020dba84(CampStatusWork *work, u16 id)
{
    u32 icon = data_0213c568[4];
    CampStatusEntry *e = func_020a1428(id);
    u32 tab = func_020445f4(14, 4);
    func_0204fcb0(4, func_0204fed8(tab, e->unk_04));
    func_0204fcb0(5, func_0204fed8(tab, e->kind));
    func_0204fcb0(1, func_0204fed8(func_020445f4(14, 1), e->unk_0a_1));
    func_0204faf0(1, e->unk_0a_5);
    if (e->unk_0a_5 != e->unk_0a_8) {
        icon = 5;
        func_0204faf0(2, e->unk_0a_8);
    }
    func_0204fcb0(2, func_0204fed8(func_020445f4(14, 2), e->unk_0c));
    func_0204fcb0(3, func_0204fed8(func_020445f4(14, 3), e->unk_0e));
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}'''),
('func_020dbbbc', '''/* Like func_020dba84, but slots 1-3 and the icon test come from func_020a1740(id) (+0x16..+0x1a)
 * and the default icon is data_0213c568[1]. */
void func_020dbbbc(CampStatusWork *work, u16 id)
{
    u32 icon = data_0213c568[1];
    CampStatusEntry *e = func_020a1428(id);
    CampStatusRecordSet *rs = func_020a1740(id);
    u32 tab = func_020445f4(14, 4);
    func_0204fcb0(4, func_0204fed8(tab, e->unk_04));
    func_0204fcb0(5, func_0204fed8(tab, e->kind));
    func_0204fcb0(1, func_0204fed8(func_020445f4(14, 1), rs->unk_16_5));
    func_0204faf0(1, rs->unk_16_9);
    if (rs->unk_16_9 != rs->unk_16_c) {
        icon = 5;
        func_0204faf0(2, rs->unk_16_c);
    }
    func_0204fcb0(2, func_0204fed8(func_020445f4(14, 2), rs->unk_0018));
    func_0204fcb0(3, func_0204fed8(func_020445f4(14, 3), rs->unk_001a));
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}'''),
('func_020dc3b8', '''/* Like func_020dc2ec, but needs the saved record for unk_00da; the id list comes from the
 * entry (+0x2e) when unk_025c is set, else from the saved record (+0x10). */
void func_020dc3b8(CampStatusWork *work)
{
    CampStatusSavedRecord rec;
    u32 ids[6];
    CampStatusEntry *e = func_020a1428(work->unk_00da);
    u32 i;
    if (Unk02e000_SetRecord(work->unk_00da, &rec) == 0) {
        return;
    }
    ids[0] = e->unk_02;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    ids[0] = work->unk_00da;
    CampStatus_Unk_0dde3c(work->unk_00c0, 18, 1, ids, 1);
    if (work->unk_025c != 0) {
        for (i = 0; i < 6; i++) {
            if (e->unk_002e[i] == 0) {
                break;
            }
            ids[i] = e->unk_002e[i];
        }
    } else {
        for (i = 0; i < 6; i++) {
            if (rec.unk_0010[i] == 0) {
                break;
            }
            ids[i] = rec.unk_0010[i];
        }
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}'''),
('func_020dc908', '''/* Release the shared work's resources (two sets of three handles plus three tasks) and clear
 * each field. */
void func_020dc908(void)
{
    func_0205bb68();
    func_02053000(data_02176be4->unk_00a8);
    data_02176be4->unk_00a8 = 0;
    if (data_02176be4->unk_009c != 0) {
        func_0205ddb4(data_02176be4->unk_009c);
        data_02176be4->unk_009c = 0;
    }
    if (data_02176be4->unk_00a0 != 0) {
        func_0205c368(data_02176be4->unk_00a0);
        data_02176be4->unk_00a0 = 0;
    }
    func_02061424(data_02176be4->unk_00ac);
    data_02176be4->unk_00ac = 0;
    func_0205bb68();
    func_02053000(data_02176be4->unk_0090);
    data_02176be4->unk_0090 = 0;
    if (data_02176be4->unk_0084 != 0) {
        func_0205ddb4(data_02176be4->unk_0084);
        data_02176be4->unk_0084 = 0;
    }
    if (data_02176be4->unk_0088 != 0) {
        func_0205c368(data_02176be4->unk_0088);
        data_02176be4->unk_0088 = 0;
    }
    func_02061424(data_02176be4->unk_0094);
    data_02176be4->unk_0094 = 0;
    func_02061424(data_02176be4->unk_002c);
    data_02176be4->unk_002c = 0;
}'''),
('func_020dd9d8', '''/* Colour for a unit's line: grey for an empty entry; for kinds 4 and 5 the first colour when
 * status +0x34 is 1 or 7 or +0x1e is not positive, the second otherwise; other kinds grey or
 * the default colour. */
void func_020dd9d8(CampStatusUnit *unit)
{
    CampStatusEntry *e = func_020a1428(unit->unk_0036);
    if (e->unk_00 == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        return;
    }
    if (e->kind == 4) {
        if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
            func_02057dcc(0x18525aff, 0x18525aff, 0x18525aff, 0x18525aff);
        } else {
            func_02057dcc(0x39dccbff, 0x39dccbff, 0x39dccbff, 0x39dccbff);
        }
        return;
    }
    if (e->kind == 5) {
        if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
            func_02057dcc(0x5a3129ff, 0x5a3129ff, 0x5a3129ff, 0x5a3129ff);
        } else {
            func_02057dcc(0xff7b63ff, 0xff7b63ff, 0xff7b63ff, 0xff7b63ff);
        }
        return;
    }
    if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
    } else {
        func_02057df8();
    }
}'''),
('func_020ddc20', '''/* Draw a frame of height *rows * 13 at x: top piece (frame 5), two strips (resources 0x1d01
 * and 0x1d00), bottom piece (frame 6) at the last row. */
void func_020ddc20(u32 obj, const s32 *rows, u32 unused, int x, float alpha)
{
    func_02057fd8();
    func_0205dee8(2, obj, 5, x, 0, 1.0f, 1.0f, 0, alpha, 2);
    func_02058f10(2, 0x1d01, x, 0, 99, *rows * 13 - 1, 2);
    func_02058f10(2, 0x1d00, x, 0, 8, *rows * 13 - 1, 2);
    func_0205dee8(2, obj, 6, x, (*rows - 1) * 13, 1.0f, 1.0f, 0, alpha, 2);
}'''),
], '', FIX)]
