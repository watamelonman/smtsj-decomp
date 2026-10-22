TU = 'src/CampStatus.c'
FIX = [
("""    u8 pad_0001[0x7];""", """    u8 pad_0001[0x3];
    u32 unk_0004;"""),
("""    u8 pad_0242[0xe];""", """    u8 pad_0242[0x6];
    u16 unk_0248;               /* +0x248: id for CampStatus_Unk_0dbd04 */
    s16 unk_024a;               /* +0x24a: negative selects the icon-only path of func_020db548 */
    u8 pad_024c[0x4];"""),
]
SPECS = [(TU, [
('func_020db548', '''/* Refresh the icon line on unk_00c8 for the current screen mode: with unk_024a < 0 only the
 * placeholder icons (CampStatus_Unk_0dbf24) or a clear; otherwise the per-mode detail
 * helpers. */
void func_020db548(CampStatusWork *work)
{
    if (work->unk_024a < 0) {
        if (work->unk_0008 != 0) {
            switch (work->unk_0000) {
            case 2:
                if (work->unk_00cc->unk_0036 == 0) {
                    CampStatus_Unk_0dbf24(work, 9);
                } else {
                    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
                }
                break;
            case 11:
                if (work->unk_00cc->unk_0036 == 0) {
                    if (work->unk_0250 != 0) {
                        CampStatus_Unk_0dbf24(work, 10);
                    } else {
                        CampStatus_Unk_0dbf24(work, 8);
                    }
                } else {
                    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
                }
                break;
            case 21:
                if (work->unk_00cc->unk_0036 == 0) {
                    CampStatus_Unk_0dbf24(work, 9);
                } else {
                    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
                }
                break;
            case 20:
                if (work->unk_00da == 0) {
                    CampStatus_Unk_0dbf24(work, 9);
                } else {
                    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
                }
                break;
            case 3:
                if (work->unk_00da == 0) {
                    CampStatus_Unk_0dbf24(work, 9);
                } else {
                    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
                }
                break;
            default:
                Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
                break;
            }
        } else {
            Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
        }
    } else if (work->unk_0004 == 0) {
        switch (work->unk_0000) {
        case 0:
            break;
        case 1:
            CampStatus_Unk_0db824(work);
            break;
        case 2:
            if (work->unk_00cc->unk_0036 == 0) {
                CampStatus_Unk_0dbf24(work, 9);
            } else {
                CampStatus_Unk_0dba84(work, work->unk_00cc->unk_0036);
            }
            break;
        case 11:
            if (work->unk_00cc->unk_0036 == 0) {
                if (work->unk_0250 != 0) {
                    CampStatus_Unk_0dbf24(work, 10);
                } else {
                    CampStatus_Unk_0dbf24(work, 8);
                }
            } else {
                CampStatus_Unk_0dba84(work, work->unk_00cc->unk_0036);
            }
            break;
        case 21:
            if (work->unk_00cc->unk_0036 == 0) {
                CampStatus_Unk_0dbf24(work, 9);
            } else {
                CampStatus_Unk_0dba84(work, work->unk_00cc->unk_0036);
            }
            break;
        case 20:
            if (work->unk_00da == 0) {
                CampStatus_Unk_0dbf24(work, 9);
            } else {
                CampStatus_Unk_0dba84(work, work->unk_00da);
            }
            break;
        case 3:
            if (work->unk_00da == 0) {
                CampStatus_Unk_0dbf24(work, 9);
            } else {
                CampStatus_Unk_0dbbbc(work, work->unk_00da);
            }
            break;
        case 10:
            CampStatus_Unk_0dbd04(work, work->unk_0248);
            break;
        case 18:
            CampStatus_Unk_0dbdac(work, (u16)work->unk_0190);
            break;
        }
    } else if (work->unk_0000 == 18) {
        CampStatus_Unk_0dbdac(work, (u16)work->unk_0190);
    }
}'''),
], '''void CampStatus_Unk_0db824(CampStatusWork *work);
void CampStatus_Unk_0dba84(CampStatusWork *work, u16 id);
void CampStatus_Unk_0dbbbc(CampStatusWork *work, u16 id);
void CampStatus_Unk_0dbd04(CampStatusWork *work, u32 id);
void CampStatus_Unk_0dbdac(CampStatusWork *work, u32 id);
void CampStatus_Unk_0dbf24(CampStatusWork *work, u32 id);''', FIX)]
