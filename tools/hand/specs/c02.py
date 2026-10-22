TU = 'src/CampStatus.c'
PRE = '''/* Record list returned by func_020a1740: three 6-byte records from +0x48. */
typedef struct CampStatusRecord {
    u16 id;
    u8 pad_02[0x4];
} CampStatusRecord;
typedef struct CampStatusRecordSet {
    u8 pad_0000[0x48];
    CampStatusRecord rec[3];
} CampStatusRecordSet;
/* Work area from Unk02e000_GetWorkArea; only the flag-set word is used here. */
typedef struct CampStatusWorkArea {
    u8 pad_0000[0x35c];
    u16 unk_035c;
} CampStatusWorkArea;
extern char data_021507cc[];
extern char data_021507d0[];
extern char data_021507d4[];
extern char data_021507dc[];
extern u32 data_0213c568[];
void func_02057ddc(u32 color);
char *func_020a9e14(int mode, const char *format, ...);
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 arg3, u32 arg4, u32 arg5, u32 resource, u32 count);
int Unk09974c_Unk_0998d8(u32 id);
int func_0204faf0(u32 a, u32 b);
CampStatusRecordSet *func_020a1740(u16 id);
s32 Unk02e000_GetRecordUnk1e(u32 id);
void Unk0ddeb0_Unk_0ddf0c(void *obj);
CampStatusCell *Unk038fbc_Unk_039160(u8 *grid, int x, int y);
CampStatusWorkArea *Unk02e000_GetWorkArea(void);
int Unk0e651c_TestFlag(u32 set, u32 bit);
void Unk0e651c_SetFlag(u32 set, u32 bit, int value);
void ScanVisor_Unk_0a2ab0(void);
void ScanVisor_Unk_0a2ae8(u32 a, int b);'''
FIX = [
("""extern CampStatusWork *data_02176be4;
""", """extern CampStatusWork *data_02176be4;

""" + PRE + """
"""),
("""    CampStatusAnim *unk_0094;
    u8 pad_0098[0x30];
    void *unk_00c8;
    u8 pad_00cc[0x28];
    u32 unk_00f4;""", """    CampStatusAnim *unk_0094;
    u8 pad_0098[0x24];
    void *unk_00bc;             /* +0xbc..+0xc8: draw objects passed to CampStatus_Unk_0dde3c */
    void *unk_00c0;
    void *unk_00c4;
    void *unk_00c8;
    CampStatusUnit *unk_00cc;
    u16 unk_00d0;
    u8 pad_00d2[0x8];
    u16 unk_00da;               /* +0xda: id passed to func_020a1740 */
    u8 pad_00dc[0x14];
    s8 unk_00f0;                /* +0xf0: record index into func_020a1740's result */
    u8 pad_00f1[0x3];
    u32 unk_00f4;"""),
("""    u32 unk_0110;
    u8 pad_0114[0x54];""", """    u32 unk_0110;
    u8 pad_0114[0x54];"""),
("""    u8 pad_0180[0x28];
    u32 unk_01a8;""", """    u8 pad_0180[0x20];
    u32 unk_01a0;
    u8 pad_01a4[0x4];
    u32 unk_01a8;"""),
("""    s32 unk_0268;               /* +0x268: set by CampStatus_Unk_0dcad4 */
    u8 pad_026c[0x7228];
    u32 unk_7494;
} CampStatusWork;
""", """    s32 unk_0268;               /* +0x268: set by CampStatus_Unk_0dcad4 */
} CampStatusWork;                /* 0x26c bytes: the size CampStatus_Unk_0d3624 registers */

/* Cell returned by Unk038fbc_Unk_039160; bits 12..15 of the word at +4 select a flag. */
typedef struct CampStatusCell {
    u32 unk_00;
    u32 pad_bits : 12;
    u32 flag : 4;
    u32 pad_hi : 16;
} CampStatusCell;

/* Object handled by the four-entry table at 0x0213c1d8 (CampStatus_GetUnkField7494,
 * func_020dcb68, func_020dcc00, func_020dd0a4); a different object from CampStatusWork. */
typedef struct CampStatusTableWork {
    u8 pad_0000[0x240];
    u8 unk_0240[0x7242];        /* +0x240: object passed to Unk038fbc_Unk_039160; size from the next field */
    s8 unk_7482;                /* +0x7482/+0x7483: (x, y) passed with unk_0240 */
    s8 unk_7483;
    s32 unk_7484;               /* +0x7484: set to 60 when a new flag is raised */
    u8 pad_7488[0xc];
    u32 unk_7494;
} CampStatusTableWork;
"""),
("""u32 CampStatus_GetUnkField7494(CampStatusWork *work);""", """u32 CampStatus_GetUnkField7494(CampStatusTableWork *work);"""),
("""u32 CampStatus_GetUnkField7494(CampStatusWork *work)
{""", """u32 CampStatus_GetUnkField7494(CampStatusTableWork *work)
{"""),
("""/* Camp status work; the first argument here and also *data_02176be4. */""",
"""/* Unit record at CampStatusWork.unk_00cc (also the argument of func_020ddb04). */
typedef struct CampStatusUnit {
    u8 pad_0000[0x28];
    u16 unk_0028[6];            /* +0x28: id list, 0-terminated */
    u8 pad_0034[0x2];
    u16 unk_0036;               /* +0x36: id passed to func_020a1428 */
} CampStatusUnit;

/* Camp status work; the first argument here and also *data_02176be4. */"""),
("""typedef struct CampStatusEntry {
    u16 unk_00;
    u8 pad_02[0x3];
    u8 kind;
} CampStatusEntry;""", """typedef struct CampStatusEntry {
    u16 unk_00;
    u8 unk_02;
    u8 pad_03[0x2];
    u8 kind;
} CampStatusEntry;"""),
]
SPECS = [(TU, [
('func_020db3e0', '''/* Set the text colour for a compared value: mode 1 compares b against a, mode 3 b against c
 * (green 0x8cff4a00 when larger, red 0xff290000 when smaller), mode 2 is green when c > 0.
 * Equal values (and other modes) keep the default colour from func_02057df8. */
void func_020db3e0(s32 a, s32 b, s32 c, s32 mode)
{
    func_02057df8();
    if (mode == 1) {
        if (b > a) {
            func_02057ddc(0x8cff4a00);
        } else if (b < a) {
            func_02057ddc(0xff290000);
        }
        return;
    }
    if (mode == 2) {
        if (c > 0) {
            func_02057ddc(0x8cff4a00);
        }
        return;
    }
    if (mode == 3) {
        if (b > c) {
            func_02057ddc(0x8cff4a00);
        } else if (b < c) {
            func_02057ddc(0xff290000);
        }
    }
}'''),
('func_020da670', '''/* Draw two numbers (a at x 24, b at x 86, y 27) with func_020a9fd8, after resetting the colour. */
void func_020da670(u32 a, u32 b)
{
    func_02057df8();
    func_020a9fd8(1, 24, 27, 2, (u32)func_020a9e14(1, data_021507cc), 10, (u32)data_021507d0, a);
    func_020a9fd8(1, 86, 27, 2, (u32)func_020a9e14(1, data_021507d4, 0), 10, (u32)data_021507dc, b);
}'''),
('func_020dbd04', '''/* Show icon data_0213c568[3] on unk_00c8 when Unk09974c_Unk_0998d8(unk_00d0) is 0; otherwise
 * show data_0213c568[0], or 7 after func_0204faf0(10, id) when id is not 0xffff. */
void func_020dbd04(CampStatusWork *work, u32 id)
{
    u32 other;
    u32 icon;
    if (Unk09974c_Unk_0998d8(work->unk_00d0) == 0) {
        other = data_0213c568[3];
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &other, 1);
        return;
    }
    icon = data_0213c568[0];
    if (id != 0xffff) {
        icon = 7;
        func_0204faf0(10, id);
    }
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}'''),
('func_020dc240', '''/* Show the unit's entries: the byte at +2 of its func_020a1428 entry on unk_00bc, its id on
 * unk_00c0, and its 0-terminated id list (up to 6) on unk_00c4. */
void func_020dc240(CampStatusWork *work)
{
    u32 ids[6];
    u32 i;
    ids[0] = func_020a1428(work->unk_00cc->unk_0036)->unk_02;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    ids[0] = work->unk_00cc->unk_0036;
    CampStatus_Unk_0dde3c(work->unk_00c0, 18, 1, ids, 1);
    for (i = 0; i < 6; i++) {
        if (work->unk_00cc->unk_0028[i] == 0) {
            break;
        }
        ids[i] = work->unk_00cc->unk_0028[i];
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}'''),
('func_020dc4a8', '''/* On unk_00c4: entry 201 of group (12, 0), then each non-zero record id (up to 3) of
 * func_020a1740(unk_00da) from group (6, 0). */
void func_020dc4a8(CampStatusWork *work)
{
    u32 tabA = func_020445f4(6, 0);
    u32 tabB = func_020445f4(12, 0);
    CampStatusRecordSet *rs = func_020a1740(work->unk_00da);
    u32 last;
    u32 i;
    func_02063920();
    last = func_02063a30(func_0204fed8(tabB, 201));
    if (rs != 0) {
        for (i = 0; i < 3; i++) {
            if (rs->rec[i].id != 0) {
                last = func_02063a30(func_0204fed8(tabA, rs->rec[i].id));
            }
        }
    }
    func_02061f10(work->unk_00c4, -1, 0, 0, last);
}'''),
('func_020dc540', '''/* When unk_01a0 is set: show the selected record id (group 7) on unk_00c8 if the record exists
 * and Unk02e000_GetRecordUnk1e(unk_00da) is at least 100, else clear it via Unk0ddeb0_Unk_0ddf0c. */
void func_020dc540(CampStatusWork *work)
{
    CampStatusRecordSet *rs;
    u32 ids[1];
    if (work->unk_01a0 == 0) {
        return;
    }
    rs = func_020a1740(work->unk_00da);
    if (rs != 0 && rs->rec[work->unk_00f0].id != 0 && Unk02e000_GetRecordUnk1e(work->unk_00da) >= 100) {
        ids[0] = rs->rec[work->unk_00f0].id;
        CampStatus_Unk_0dde3c(work->unk_00c8, 7, 0, ids, 1);
        return;
    }
    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
}'''),
('func_020dcb68', '''/* Handler 2 of the table at 0x0213c1d8: look up the cell at (unk_7482, unk_7483); if its 4-bit
 * flag number n is non-zero and work-area flag n + 55 is not set yet, set it, call
 * ScanVisor_Unk_0a2ab0 and start the 60-tick unk_7484 timer. Always ends with
 * ScanVisor_Unk_0a2ae8(3, 2) and returns 1. */
int func_020dcb68(CampStatusTableWork *work)
{
    CampStatusCell *c = Unk038fbc_Unk_039160(work->unk_0240, work->unk_7482, work->unk_7483);
    u32 n;
    work->unk_7484 = 0;
    if (c != 0 && (n = c->flag) != 0) {
        if (Unk0e651c_TestFlag(Unk02e000_GetWorkArea()->unk_035c, n + 55) == 0) {
            Unk0e651c_SetFlag(Unk02e000_GetWorkArea()->unk_035c, n + 55, 1);
            ScanVisor_Unk_0a2ab0();
            work->unk_7484 = 60;
        }
    }
    ScanVisor_Unk_0a2ae8(3, 2);
    return 1;
}'''),
('func_020ddb04', '''/* Like CampStatus_Unk_0ddb9c with the unit's id: grey for an empty entry, own colours for
 * kinds 4 and 5, grey otherwise. */
void func_020ddb04(CampStatusUnit *unit)
{
    CampStatusEntry *e = func_020a1428(unit->unk_0036);
    if (e->unk_00 == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        return;
    }
    if (e->kind == 4) {
        func_02057dcc(0x18525aff, 0x18525aff, 0x18525aff, 0x18525aff);
        return;
    }
    if (e->kind == 5) {
        func_02057dcc(0x5a3129ff, 0x5a3129ff, 0x5a3129ff, 0x5a3129ff);
        return;
    }
    func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
}'''),
], '', FIX)]
