TU = 'src/CampStatus.c'
SRC = open('~/sj-decomp/' + TU).read()
FIX = [
("""typedef struct CampStatusDrawParam {
    u32 unk_00[4];""", """typedef struct CampStatusDrawParam {
    u32 unk_00;
    u32 unk_04;
    s16 unk_08;
    s16 unk_0a;                 /* +0x0a: y, moved by the scrollbar in func_020d6120 */
    s16 unk_0c;
    s16 unk_0e;                 /* +0x0e: height, set by the scrollbar in func_020d6120 */"""),
("""    u8 pad_01ac[0x94];""", """    u32 unk_01ac;               /* +0x1ac/+0x1b0: hide the two tabs drawn by func_020d6120 */
    u32 unk_01b0;
    u8 pad_01b4[0x8c];"""),
]
LABELS = '''        if (work->unk_0008 != 0 && work->unk_00e8 == 0) {
            func_02057df8();
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
        }'''
SPECS = [(TU, [
('func_020d6120', '''/* Handler 0x14 of the CampStatus_Unk_0d3624 table: draw the screen. Common frame and the two
 * optional tabs (unk_01a8), then the page for the screen mode in unk_0000, then the title text
 * on unk_00b8 (centred in 108 px unless unk_0268 pins it at unk_010e). */
void func_020d6120(CampStatusWork *work)
{
    CampStatusDrawParam param;
    if (work->unk_018c != 0 && func_020523a8() == 0) {
        return;
    }
    func_02057eb8(-1);
    func_02057fd8();
    func_02057df8();
    func_02057524(4);
    func_02057e18(31);
    func_0205dee8(2, work->unk_0018, 0, 0, work->unk_00fc, 1.0f, 1.0f, 0, work->unk_0110, 2);
    if (work->unk_01a8 != 0) {
        func_02057fd8();
        func_02057ddc(0x00ffffff);
        func_0205dee8(2, work->unk_0018, 1, 0, work->unk_00fc, 1.0f, 1.0f, 0, work->unk_0110, 3);
        func_0205dee8(2, work->unk_0018, 2, 0, work->unk_00fc, 1.0f, 1.0f, 0, work->unk_0110, 3);
        func_02057fd8();
        func_02057df8();
        if (work->unk_01ac == 0) {
            if (work->unk_0110 == 1.0f) {
                func_02057e18(func_020ddf7c(data_0215f05c.unk_0018));
            }
            func_02058e9c(2, 0x1e80, 0, work->unk_00fc, 1.0f, 0, 4);
            func_02057e18(31);
        }
        if (work->unk_01b0 == 0) {
            if (work->unk_0110 == 1.0f) {
                func_02057e18(func_020ddf7c(data_0215f05c.unk_0018));
            }
            func_02058e9c(0x1002, 0x1e82, 0, work->unk_00fc, 1.0f, 0, 4);
            func_02057e18(31);
        }
    }
    switch (work->unk_0000) {
    case 1:
    case 14:
    case 18:
        CampStatus_Unk_0d6e10(work);
        CampStatus_Unk_0d71bc(work);
        if (work->unk_0004 != 0 && work->unk_00f4 != 0) {
            CampStatus_Unk_0d78bc(work);
        }
        break;
    case 2:
    case 11:
    case 15:
        CampStatus_Unk_0d6e10(work);
        CampStatus_Unk_0d730c(work);
        if (work->unk_00f4 == 0) {
            break;
        }
        if (work->unk_0004 != 0 && work->unk_00cc->unk_0036 != 0) {
            func_020d80cc(work, work->unk_00cc);
            CampStatus_Unk_0d9d54(work->unk_00cc->unk_0036);
        } else
''' + LABELS + '''
        break;
    case 10:
        CampStatus_Unk_0d7680(work);
        if (work->unk_0004 != 0 && work->unk_00f4 != 0) {
            CampStatus_Unk_0d8d60(work);
        }
        break;
    case 20:
        CampStatus_Unk_0d6e10(work);
        CampStatus_Unk_0d730c(work);
        if (work->unk_00f4 == 0) {
            break;
        }
        if (work->unk_0004 != 0 && work->unk_00da != 0) {
            func_020d8e3c(work);
            CampStatus_Unk_0d9d54(work->unk_00da);
        } else
''' + LABELS + '''
        break;
    case 21:
        CampStatus_Unk_0d6e10(work);
        CampStatus_Unk_0d730c(work);
        if (work->unk_00f4 == 0) {
            break;
        }
        if (work->unk_0004 != 0 && work->unk_00cc->unk_0036 != 0) {
            func_020d9388(work, work->unk_00cc);
            CampStatus_Unk_0d9d54(work->unk_00cc->unk_0036);
        } else
''' + LABELS + '''
        break;
    case 3:
        CampStatus_Unk_0d6e10(work);
        CampStatus_Unk_0d730c(work);
        if (work->unk_00f4 == 0) {
            break;
        }
        if (work->unk_0004 != 0 && work->unk_00da != 0) {
            CampStatus_Unk_0d9830(work);
            if (work->unk_0264 == 0) {
                CampStatus_Unk_0d9d54(work->unk_00da);
            }
        } else
''' + LABELS + '''
        break;
    case 5:
    case 6:
    case 8: {
        s32 pages;
        func_02057df8();
        func_02057dcc(0x052f62ff, 0x052f62ff, 0x186bdeff, 0x186bdeff);
        func_02057fd8();
        func_0205dee8(2, work->unk_0018, 54, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_02057df8();
        func_02057fd8();
        func_0205dee8(2, work->unk_0018, 55, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 3);
        func_02008904(func_0205e318(work->unk_0018, 130), &param, sizeof(param));
        /* scrollbar: 145 px track, one page per 12 entries */
        if (work->unk_0240 < 1) {
            work->unk_0240 = 1;
        }
        pages = (work->unk_0240 - 1) / 12 + 1;
        if (pages < 1) {
            pages = 1;
        }
        param.unk_0e = (0x1000 / pages * 145) >> 12;
        param.unk_0a += (s16)(((145 - param.unk_0e) * ((work->unk_0241 / 12 << 12) / (pages - 1))) >> 12);
        func_0205e048(2, work->unk_0018, &param, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 4, 0);
        func_0205dee8(2, work->unk_0018, 57, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 4);
        if (work->unk_0000 != 8 && work->unk_00f4 != 0 && (work->unk_00da != 0 || work->unk_0250 != 0)) {
            if (work->unk_0250 != 0) {
                CampStatus_Unk_0ddb9c(work->unk_00cc->unk_0036);
            } else {
                CampStatus_Unk_0ddb9c(work->unk_00da);
            }
            Unk0ddeb0_Unk_0ddeb0(work->unk_00bc, 2, 15, 0, 5, 10);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 15, 0, 8, 10);
        }
        break;
    }
    }
    func_02057fd8();
    func_02057df8();
    {
        s32 x = (108 - func_02061a04(work->unk_00b8->unk_0028, work->unk_00b8->unk_0014, 0)) / 2;
        if (work->unk_0268 != 0) {
            x = work->unk_010e;
        }
        Unk0ddeb0_Unk_0ddeb0(work->unk_00b8, x + 2, work->unk_00fc - 2, 0, 11, 10);
    }
    func_02057534();
}'''),
], '''void func_02057524(u32 v);
void func_02057534(void);
u32 func_020ddf7c(s32 t);
s32 func_02061a04(u32 a, const u16 *text, u32 c);
void CampStatus_Unk_0d78bc(CampStatusWork *work);
void func_020d80cc(CampStatusWork *work, CampStatusUnit *unit);
void func_020d8e3c(CampStatusWork *work);
void func_020d9388(CampStatusWork *work, CampStatusUnit *unit);
void CampStatus_Unk_0d9830(CampStatusWork *work);
void CampStatus_Unk_0d6e10(CampStatusWork *work);
void CampStatus_Unk_0d71bc(CampStatusWork *work);
void CampStatus_Unk_0d730c(CampStatusWork *work);
void CampStatus_Unk_0d7680(CampStatusWork *work);
void CampStatus_Unk_0d8d60(CampStatusWork *work);
void CampStatus_Unk_0d9d54(u16 id);
void CampStatus_Unk_0ddb9c(int id);''', FIX)]
