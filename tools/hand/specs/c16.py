TU = 'src/CampStatus.c'
SRC = open('~/sj-decomp/' + TU).read()
TIDY = open('/tmp/claude-0/sp/tidy_out.c').read()
FIX = [
(SRC, TIDY),
("""    void *unk_00b4;             /* +0xb4..+0xc8: text objects released by func_020629c4 */
    void *unk_00b8;
    void *unk_00bc;             /* +0xbc..+0xc8: draw objects passed to CampStatus_Unk_0dde3c */
    void *unk_00c0;
    void *unk_00c4;
    void *unk_00c8;""", """    CampStatusText *unk_00b4;   /* +0xb4..+0xc8: text objects (func_020629ac), drawn with */
    CampStatusText *unk_00b8;   /* CampStatus_Unk_0dde3c / Unk0ddeb0_Unk_0ddeb0, released by */
    CampStatusText *unk_00bc;   /* func_020629c4 */
    CampStatusText *unk_00c0;
    CampStatusText *unk_00c4;
    CampStatusText *unk_00c8;"""),
("""/* Unit record at CampStatusWork.unk_00cc""", """/* Text object (func_020629ac); only the fields read in this file. */
typedef struct CampStatusText {
    u8 pad_0000[0x14];
    u16 *unk_0014;              /* +0x14: glyph codes; 0x8001 ends a line (see func_020d9830) */
    u8 pad_0018[0x10];
    u32 unk_0028;
} CampStatusText;

/* Unit record at CampStatusWork.unk_00cc"""),
("""typedef struct CampStatusRecordSet {
    u8 pad_0000[0x16];
    u16 pad_16_0 : 5;           /* +0x16: three small values */""", """typedef struct CampStatusRecordSet {
    u16 unk_0000;
    u8 unk_0002;
    u8 pad_0003;
    u32 unk_0004;               /* +0x04/+0x08: current/max pair shown by func_020d9830 */
    u32 unk_0008;
    u16 unk_000c[5];            /* +0x0c: five stats, copied to a CampStatusStats */
    u16 pad_16_0 : 1;           /* +0x16: flags and three small values */
    u16 unk_16_1 : 1;           /* "???" mode for func_020da2cc */
    u16 pad_16_2 : 3;"""),
("""    u8 unk_001a;
    u8 pad_001b[0x2d];
    CampStatusRecord rec[3];""", """    u8 unk_001a;
    u8 pad_001b[0x7];
    CampStatusStateWord unk_0022[8];  /* +0x22: per-slot base words for func_020dd364 */
    u8 pad_0032[0x16];
    CampStatusRecord rec[3];"""),
]
SPECS = [(TU, [
('func_020d9830', '''/* Record page (mode 3): stats and value bars of record unk_00da, its level line, the eight
 * slot states (or "???" icons while the gauge is below unk_005b), and either the three record
 * entries with the pulsing cursor (unk_01a0 set), the empty grid, or the id grid. */
void func_020d9830(CampStatusWork *work)
{
    CampStatusRecordSet *rs;
    CampStatusStats stats;
    s32 i;
    func_02057fd8();
    CampStatus_Unk_0ddb9c(work->unk_00da);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00bc, 2, 15, 0, 5, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 15, 0, 8, 10);
    func_02057df8();
    rs = func_020a1740(work->unk_00da);
    stats.unk_00 = rs->unk_0004;
    stats.unk_02 = rs->unk_0008;
    stats.unk_04 = rs->unk_000c[0];
    stats.unk_05 = rs->unk_000c[1];
    stats.unk_06 = rs->unk_000c[2];
    stats.unk_07 = rs->unk_000c[3];
    stats.unk_08 = rs->unk_000c[4];
    CampStatus_Unk_0da0e0(work, &stats, &stats, 0, 0);
    if (rs->unk_16_1) {
        func_020da2cc(stats.unk_00, stats.unk_02, &stats.unk_00, &stats.unk_00, 0, 4);
    } else {
        func_020da2cc(stats.unk_00, stats.unk_02, &stats.unk_00, &stats.unk_00, 0, 0);
    }
    CampStatus_Unk_0da670(rs->unk_0002, func_020b8144(rs->unk_0000, rs->unk_0002));
    for (i = 0; i <= 7; i++) {
        if (Unk02e000_GetRecordUnk1e(work->unk_00da) < rs->unk_005b) {
            Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, i * 14 + 7, 67, 11, 1, 10);
        } else {
            Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, i * 14 + 7, 67, func_020dd364(rs->unk_0022[i], work->unk_00dc, i) + 5, 2, 10);
        }
    }
    if (work->unk_00f8 == 0) {
        return;
    }
    if (work->unk_01a0 != 0) {
        s32 n = 0;
        s32 k;
        s8 len;
        s32 j;
        for (k = 0; k < 3; k++) {
            if (Unk02e000_GetRecordUnk1e(work->unk_00da) < 100) {
                if (rs->rec[k].id != 0) {
                    n++;
                }
                Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, k * 85 + 4, 155, 11, 1, 10);
                Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, k * 85 + 14, 155, 11, 1, 10);
                Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, k * 85 + 24, 155, 11, 1, 10);
            } else if (rs->rec[k].id != 0) {
                Unk0ddeb0_Unk_0ddeb0(work->unk_00c4, n * 85 + 4, 155, n + 1, 8, 10);
                n++;
            }
        }
        len = 0;
        for (j = 0; j < 10; j++) {
            if (work->unk_00c4->unk_0014[j] == 0x8001) {
                break;
            }
            len++;
        }
        Unk0ddeb0_Unk_0ddeb0(work->unk_00c4, 128 - len * 10 / 2, 142, 0, 10, 10);
        func_02057fd8();
        func_02057df8();
        func_02057e18(CampStatus_Unk_0db288(data_0215f05c.unk_0018));
        func_02058f10(2, 0x1dd4, (work->unk_00f0 % 3) * 85, 13, 83, 12, 9);
        func_02057e18(31);
    } else if (Unk02e000_GetRecordUnk1e(work->unk_00da) < rs->unk_005b) {
        /* "???" in every grid slot: x0..x2 are the three glyph columns of slot k */
        s32 row;
        s32 k;
        s32 x0;
        s32 x1;
        s32 x2;
        s32 y;
        for (row = 0, y = 140; row < 2; row++, y += 13) {
            for (k = 0, x0 = 4, x1 = 14, x2 = 24; k < 3; x0 += 85, x1 += 85, x2 += 85, k++) {
                Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, x0, y, 11, 1, 10);
                Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, x1, y, 11, 1, 10);
                Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, x2, y, 11, 1, 10);
            }
        }
    } else {
        func_020da710(work->unk_00c4, work->unk_00dc, 0, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
    }
    if (work->unk_0008 == 0) {
        return;
    }
    if (work->unk_00e8 != 0 || work->unk_01a0 != 0) {
        func_02057df8();
    } else {
        CampStatus_Unk_0ddb9c(work->unk_00da);
    }
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
    func_02057df8();
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
}'''),
('func_020da710', '''/* Draw the six slots of a 3x2 grid on obj (x 4 + 85 * col, y 140 + 13 * row) with a pulsing
 * cursor at sel when sel >= 0. With ref, each ref id not found in ids is drawn in orange
 * (0xff942100); empty slots are skipped. */
void func_020da710(void *obj, const u16 *ids, const u16 *ref, s32 sel)
{
    s32 row;
    s32 col;
    s32 k;
    s32 b;                      /* row * 3: index of the row's first slot */
    s32 x;
    s32 y;
    if (sel >= 0) {
        func_02057fd8();
        func_02057df8();
        func_02057e18(CampStatus_Unk_0db288(data_0215f05c.unk_0018));
        func_02058f10(2, 0x1dd4, (sel % 3) * 85, (sel / 3) * 13, 83, 12, 9);
        func_02057e18(31);
    }
    func_02057fd8();
    for (row = 0, b = 0, y = 140; row < 2; row++, b += 3, y += 13) {
        for (col = 0, x = 4; col < 3; x += 85, col++) {
            func_02057df8();
            if (ref != 0) {
                for (k = 0; k < 6; k++) {
                    if (ids[k] == ref[b + col]) {
                        break;
                    }
                }
                if (k == 6) {
                    func_02057ddc(0xff942100);
                }
                if (ref[b + col] != 0) {
                    Unk0ddeb0_Unk_0ddeb0(obj, x, y, col + b, 8, 10);
                }
            } else if (ids != 0) {
                if (ids[b + col] != 0) {
                    Unk0ddeb0_Unk_0ddeb0(obj, x, y, col + b, 8, 10);
                }
            }
        }
    }
}'''),
], '''s32 func_020dd364(CampStatusStateWord w, const u16 *ids, s32 kind);
u32 func_020b8144(u16 id, u8 level);
void CampStatus_Unk_0da670(u32 a, u32 b);
void CampStatus_Unk_0da0e0(CampStatusWork *work, const CampStatusStats *cur, const CampStatusStats *next,
                           const CampStatusStats *add, u32 arg5);
void func_020da2cc(s32 hp, s32 mp, const s16 *ref, const s16 *max, const s16 *prev, s32 mode);
void CampStatus_Unk_0ddb9c(int id);''', FIX)]
