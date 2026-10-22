TU = 'src/CampStatus.c'
c17 = open('~/sj-decomp/wip/c17.py').read()
i = c17.index("FIX = [\n") + len("FIX = [\n"); j = c17.index("]\nSPECS")
exec("FIX = [\n" + c17[i:j] + "]")
k = c17.index("], '''/* Growth data"); PRE = c17[k + len("], '''"):c17.rindex("''', FIX)]")]
for _n, _f in (('hp', '6'), ('mp', '3')):
    PRE = PRE.replace("""    u16 r = 999;
    if (v <= 999) {
        r = v;
    }
    return r;""", """    if (v > 999) {
        r = 999;
    } else {
        r = v;
    }
    return r;""", 1)
PRE = PRE.replace("    s32 v = base.hpBase", "    u16 r;\n    s32 v = base.hpBase").replace("    s32 v = base.mpBase", "    u16 r;\n    s32 v = base.mpBase")
FIX += [
('/* HP/MP and the five stats as shown on the status pages (also subtracted and clamped by\n * CampStatus_Unk_0dc5dc). unk_05 feeds max HP and unk_08 max MP (CampStatus_CalcMaxHp/Mp). */\ntypedef struct CampStatusStats {\n    s16 unk_00;                 /* +0x00: HP (max HP on the unit pages) */\n    s16 unk_02;                 /* +0x02: MP */\n    s8 unk_04;\n    s8 unk_05;\n    s8 unk_06;\n    s8 unk_07;\n    s8 unk_08;\n} CampStatusStats;\n', ''),
("/* Text object (func_020629ac)", '/* HP/MP and the five stats as shown on the status pages (also subtracted and clamped by\n * CampStatus_Unk_0dc5dc). unk_05 feeds max HP and unk_08 max MP (CampStatus_CalcMaxHp/Mp). */\ntypedef struct CampStatusStats {\n    s16 unk_00;                 /* +0x00: HP (max HP on the unit pages) */\n    s16 unk_02;                 /* +0x02: MP */\n    s8 unk_04;\n    s8 unk_05;\n    s8 unk_06;\n    s8 unk_07;\n    s8 unk_08;\n} CampStatusStats;\n' + "\n/* Text object (func_020629ac)"),
("""typedef struct CampStatusUnit {
    u8 pad_0000[0x1e];
    s16 unk_001e;               /* +0x1e: compared > 0 by CampStatus_Unk_0dd9d8 */
    u8 pad_0020[0x8];""", """typedef struct CampStatusUnit {
    CampStatusStats unk_0000;   /* +0x00: stats as shown */
    CampStatusStats unk_000a;   /* +0x0a: stats with max HP/MP at +0x0a/+0x0c */
    u8 pad_0014[0xa];
    s16 unk_001e;               /* +0x1e: current HP (> 0 checked by CampStatus_Unk_0dd9d8) */
    s16 unk_0020;               /* +0x20: current MP */
    u8 pad_0022[0x2];
    u32 unk_0024;               /* +0x24: subtracted from func_020b8144's value for the level line */"""),
("""    u16 unk_0036;               /* +0x36: id passed to func_020a1428 */
} CampStatusUnit;""", """    u16 unk_0036;               /* +0x36: id passed to func_020a1428 */
    u8 unk_0038;                /* +0x38: level */
} CampStatusUnit;"""),
]
SPECS = [(TU, [
('func_020d8e3c', '''/* Unit page (mode 20): stats, HP/MP bars and level line of unit unk_00da, from its entry
 * (unk_025c set) or from its saved record, then the eight slot states and the id grid. */
void func_020d8e3c(CampStatusWork *work)
{
    CampStatusStats stats;
    CampStatusBase base;
    CampStatusSavedRecord rec;
    CampStatusStats stats2;
    CampStatusBase base2;
    CampStatusEntry *e;
    CampStatusEntry *e2;
    s32 i;
    func_02057fd8();
    CampStatus_Unk_0ddb9c(work->unk_00da);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00bc, 2, 15, 0, 5, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 15, 0, 8, 10);
    func_02057df8();
    if (work->unk_025c != 0) {
        e = func_020a1428(work->unk_00da);
        stats.unk_04 = e->unk_1a;
        stats.unk_05 = e->unk_1b;
        stats.unk_06 = e->unk_1c;
        stats.unk_07 = e->unk_1d;
        stats.unk_08 = e->unk_1e;
        CampStatus_Unk_0da0e0(work, &stats, &stats, 0, 0);
        /* stored through a pointer: the call result goes to a temporary first, as in the ROM */
        /* stored through a pointer: the call result goes to a temporary first, as in the ROM */
    { CampStatusBase *p = &base; *p = func_020b8804(work->unk_00da); }
        stats.unk_00 = CampStatus_CalcMaxHp(e->unk_03, e->unk_1b, base);
        stats.unk_02 = CampStatus_CalcMaxMp(e->unk_03, e->unk_1e, base);
        func_0209835c(&stats, e->unk_002e);
        func_020da2cc(stats.unk_00, stats.unk_02, &stats.unk_00, &stats.unk_00, 0, 0);
        CampStatus_Unk_0da670(e->unk_03, func_020b8144(work->unk_00da, e->unk_03));
        e2 = func_020a1428(work->unk_00da);
        for (i = 0; i <= 7; i++) {
            Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, i * 14 + 7, 67, func_020dd364(e2->unk_003a[i], e->unk_002e, i) + 5, 2, 10);
        }
        CampStatus_Unk_0da710(work->unk_00c4, e->unk_002e, 0, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
    } else {
        CampStatusEntry *e3;
        s32 j;
        Unk02e000_SetRecord(work->unk_00da, &rec);
        stats2.unk_04 = rec.unk_0001;
        stats2.unk_05 = rec.unk_0003;
        stats2.unk_06 = rec.unk_0004;
        stats2.unk_07 = rec.unk_0005;
        stats2.unk_08 = rec.unk_0002;
        CampStatus_Unk_0da0e0(work, &stats2, &stats2, 0, 0);
        { CampStatusBase *p = &base2; *p = func_020b8804(work->unk_00da); }
        stats2.unk_00 = CampStatus_CalcMaxHp(rec.unk_0000, rec.unk_0003, base2);
        stats2.unk_02 = CampStatus_CalcMaxMp(rec.unk_0000, rec.unk_0002, base2);
        func_0209835c(&stats2, rec.unk_0010);
        func_020da2cc(stats2.unk_00, stats2.unk_02, &stats2.unk_00, &stats2.unk_00, 0, 0);
        CampStatus_Unk_0da670(rec.unk_0000, func_020b8144(work->unk_00da, rec.unk_0000) - rec.unk_0020);
        e3 = func_020a1428(work->unk_00da);
        for (j = 0; j <= 7; j++) {
            Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, j * 14 + 7, 67, func_020dd364(e3->unk_003a[j], rec.unk_0010, j) + 5, 2, 10);
        }
        CampStatus_Unk_0da710(work->unk_00c4, rec.unk_0010, 0, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
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
('func_020d9388', '''/* Unit compare page (mode 21): the unit's stats against its saved record (max HP/MP from
 * CampStatus_CalcMaxHp/Mp, current HP/MP clamped to the new maxima), level and exp lines
 * coloured by the change, and the eight slot states (changed ones in orange). */
void func_020d9388(CampStatusWork *work, CampStatusUnit *unit)
{
    CampStatusSavedRecord rec;
    CampStatusStats stats;
    CampStatusBase base;
    CampStatusEntry *e;
    char *width;
    s32 s0;
    s32 s1;
    s32 i;
    func_02057fd8();
    CampStatus_Unk_0ddb9c(work->unk_00cc->unk_0036);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00bc, 2, 15, 0, 5, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 15, 0, 8, 10);
    func_02057df8();
    Unk02e000_SetRecord(unit->unk_0036, &rec);
    /* stored through a pointer: the call result goes to a temporary first, as in the ROM */
    { CampStatusBase *p = &base; *p = func_020b8804(unit->unk_0036); }
    stats.unk_00 = CampStatus_CalcMaxHp(rec.unk_0000, rec.unk_0003, base);
    stats.unk_02 = CampStatus_CalcMaxMp(rec.unk_0000, rec.unk_0002, base);
    stats.unk_04 = rec.unk_0001;
    stats.unk_05 = rec.unk_0003;
    stats.unk_06 = rec.unk_0004;
    stats.unk_07 = rec.unk_0005;
    stats.unk_08 = rec.unk_0002;
    func_0209835c(&stats, rec.unk_0010);
    if (unit->unk_001e > unit->unk_000a.unk_00) {
        unit->unk_001e = unit->unk_000a.unk_00;
    }
    if (unit->unk_0020 > unit->unk_000a.unk_02) {
        unit->unk_0020 = unit->unk_000a.unk_02;
    }
    CampStatus_Unk_0da0e0(work, &unit->unk_0000, &unit->unk_000a, &stats, 3);
    func_020da2cc(unit->unk_000a.unk_00, unit->unk_000a.unk_02, &unit->unk_0000.unk_00, &unit->unk_000a.unk_00, &stats.unk_00, 3);
    func_02057df8();
    if (unit->unk_0038 > rec.unk_0000) {
        func_02057ddc(0x8cff4a00);
    } else if (unit->unk_0038 < rec.unk_0000) {
        func_02057ddc(0xff290000);
    }
    func_020a9fd8(1, 24, 27, 2, func_020a9e14(1, data_02150794), 10, data_02150798, unit->unk_0038);
    func_02057df8();
    if (unit->unk_0038 > rec.unk_0000 || (unit->unk_0038 == rec.unk_0000 && unit->unk_0024 > rec.unk_0020)) {
        func_02057ddc(0x8cff4a00);
    } else if (unit->unk_0038 < rec.unk_0000 || (unit->unk_0038 == rec.unk_0000 && unit->unk_0024 < rec.unk_0020)) {
        func_02057ddc(0xff290000);
    }
    width = func_020a9e14(1, data_0215079c, 0);
    func_020a9fd8(1, 86, 27, 2, width, 10, data_021507a4, func_020b8144(unit->unk_0036, unit->unk_0038) - unit->unk_0024);
    func_02057df8();
    e = func_020a1428(unit->unk_0036);
    for (i = 0; i <= 7; i++) {
        s0 = func_020dd364(e->unk_003a[i], unit->unk_0028, i);
        s1 = func_020dd364(e->unk_003a[i], rec.unk_0010, i);
        if (s0 != s1) {
            func_02057ddc(0xff942100);
        } else {
            func_02057df8();
        }
        Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, i * 14 + 7, 67, s0 + 5, 2, 10);
    }
    CampStatus_Unk_0da710(work->unk_00c4, rec.unk_0010, unit->unk_0028, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
    if (work->unk_0008 == 0) {
        return;
    }
    if (work->unk_00e8 != 0 || work->unk_01a0 != 0) {
        func_02057df8();
    } else {
        CampStatus_Unk_0ddb9c(work->unk_00cc->unk_0036);
    }
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
    func_02057df8();
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
}'''),
], PRE + '''
extern char data_02150794[];
extern char data_02150798[];
extern char data_0215079c[];
extern char data_021507a4[];''', FIX)]
