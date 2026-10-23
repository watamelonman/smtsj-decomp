TU = 'src/CampStatus.c'
FIX = [
("""    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x8];""", """    u8 unk_0000;                /* +0x00: screen mode; selects the id source in func_020dbf6c */
    u8 pad_0001[0x7];
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x4];
    u32 unk_0014;"""),
("""    u8 pad_00ec[0x4];
    s8 unk_00f0;                /* +0xf0: record index into func_020a1740's result */
    u8 pad_00f1[0x3];""", """    u32 unk_00ec;
    s8 unk_00f0;                /* +0xf0: record index into func_020a1740's result */
    s8 unk_00f1;
    u8 pad_00f2[0x2];"""),
("""    u8 pad_0114[0x54];""", """    u32 unk_0114;               /* +0x114: set once unk_0118 matches the shown stats */
    s16 unk_0118[10];
    u8 pad_012c[0x3c];          /* +0x12c: 60 bytes written by CampStatus_Copy12c */"""),
("""    u8 pad_0190[0x10];""", """    u32 unk_0190;
    u8 pad_0194[0xc];"""),
("""void func_02061424();
""", """void func_02061424();
void func_020dab5c(CampStatusWork *work, s32 cur, s32 next, s32 add, s32 row, u32 arg5);
void func_020bc9f4(u32 a, u32 b);
void func_020bcacc(u32 a, u32 b);
"""),
]
SPECS = [(TU, [
('func_020da0e0', '''/* Draw the five stat rows (order +4, +8, +5, +6, +7) via func_020dab5c, with the add values
 * when add is given. The first time all ten shown values equal unk_0118, set unk_0114 and
 * call func_020bc9f4(3, 0) / func_020bcacc(unk_0014, 0). */
void func_020da0e0(CampStatusWork *work, const CampStatusStats *cur, const CampStatusStats *next,
                   const CampStatusStats *add, u32 arg5)
{
    if (add == 0) {
        func_020dab5c(work, cur->unk_04, next->unk_04, 0, 0, arg5);
        func_020dab5c(work, cur->unk_08, next->unk_08, 0, 1, arg5);
        func_020dab5c(work, cur->unk_05, next->unk_05, 0, 2, arg5);
        func_020dab5c(work, cur->unk_06, next->unk_06, 0, 3, arg5);
        func_020dab5c(work, cur->unk_07, next->unk_07, 0, 4, arg5);
    } else {
        func_020dab5c(work, cur->unk_04, next->unk_04, add->unk_04, 0, arg5);
        func_020dab5c(work, cur->unk_08, next->unk_08, add->unk_08, 1, arg5);
        func_020dab5c(work, cur->unk_05, next->unk_05, add->unk_05, 2, arg5);
        func_020dab5c(work, cur->unk_06, next->unk_06, add->unk_06, 3, arg5);
        func_020dab5c(work, cur->unk_07, next->unk_07, add->unk_07, 4, arg5);
    }
    if (work->unk_0114 != 0) {
        return;
    }
    if (work->unk_0118[0] == cur->unk_04 && work->unk_0118[1] == cur->unk_08 &&
        work->unk_0118[2] == cur->unk_05 && work->unk_0118[3] == cur->unk_06 &&
        work->unk_0118[4] == cur->unk_07 && work->unk_0118[5] == next->unk_04 &&
        work->unk_0118[6] == next->unk_08 && work->unk_0118[7] == next->unk_05 &&
        work->unk_0118[8] == next->unk_06 && work->unk_0118[9] == next->unk_07) {
        work->unk_0114 = 1;
        func_020bc9f4(3, 0);
        func_020bcacc(work->unk_0014, 0);
    }
}'''),
('func_020dbf6c', '''/* Pick the id of the selected list entry for the current screen mode (unk_0000) and show it
 * (group 10) on unk_00c8, or clear unk_00c8 when there is none. */
void func_020dbf6c(CampStatusWork *work)
{
    CampStatusSavedRecord rec;
    u32 id;
    CampStatusPlayer *p;
    CampStatusInfo *info;
    u8 mode = work->unk_0000;
    if (mode == 1) {
        p = Unk02e000_Thunk_0202e788();
        if (p->unk_0002 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0002)) != 0) {
            id = info->unk_0040[work->unk_00f0];
        }
    } else if (mode == 18) {
        info = Unk09974c_Unk_099c60(work->unk_0190);
        if (info != 0 && info->unk_0002 == 4) {
            id = info->unk_0040[work->unk_00f0];
        } else {
            p = Unk02e000_Thunk_0202e788();
            if (p->unk_0002 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0002)) != 0) {
                id = info->unk_0040[work->unk_00f0];
            }
        }
    } else if (mode == 2 || mode == 11 || mode == 15 || mode == 21) {
        id = work->unk_00cc->unk_0028[work->unk_00f0];
    } else if (mode == 10) {
        if (work->unk_00f0 >= 4) {
            id = 0;
        } else {
            id = work->unk_00d2[work->unk_00f0];
        }
    } else if (work->unk_00ec != 0) {
        if (work->unk_00e8 != 0) {
            id = work->unk_00cc->unk_0028[work->unk_00f0];
        } else {
            id = work->unk_00cc->unk_0028[work->unk_00f1];
        }
    } else if (mode == 20) {
        id = 0;
        if (work->unk_00da != 0 && Unk02e000_SetRecord(work->unk_00da, &rec) != 0) {
            if (work->unk_025c != 0) {
                id = func_020a1428(work->unk_00da)->unk_002e[work->unk_00f0];
            } else {
                id = rec.unk_0010[work->unk_00f0];
            }
        }
    } else if (mode == 3) {
        id = work->unk_00dc[work->unk_00f0];
    }
    if (id != 0) {
        func_0204faf0(10, id);
        CampStatus_Unk_0dde3c(work->unk_00c8, 10, 1, &id, 1);
        return;
    }
    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
}'''),
], '', FIX)]
