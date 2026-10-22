TU = 'src/CampStatus.c'
FIX = [
("""    u8 pad_000c[0x34];""", """    u8 pad_000c[0xc];
    CampStatusStatMod unk_0018[8];  /* +0x18: per-slot modifiers; 7 used (index 0..6), size guessed */
    u8 pad_0028[0x18];"""),
("""/* Record from Unk09974c_Unk_099c60. */""", """/* Signed modifier halfword: 10-bit amount, 6-bit state code (see func_020dd500). */
typedef struct CampStatusStatMod {
    s16 value : 10;
    s16 state : 6;
} CampStatusStatMod;
/* Result halfword of func_020dd500: 10-bit total, 6-bit state code (as CampStatus_Unk_0dd88c). */
typedef struct CampStatusStateWord {
    u16 value : 10;
    u16 state : 6;
} CampStatusStateWord;
/* Record from Unk09974c_Unk_099c60. */"""),
("""    CampStatusRecord rec[3];
} CampStatusRecordSet;""", """    CampStatusRecord rec[3];
    u8 unk_005a;                /* +0x5a/+0x5b: marks on the 0..100 gauge of func_020d9d54 */
    u8 unk_005b;
} CampStatusRecordSet;"""),
("""    u8 pad_0264[0x4];""", """    u32 unk_0264;"""),
]
SPECS = [(TU, [
('func_020d730c', '''/* Draw the top panel (frames 53, 50-52 when unk_01a0 is set, else 34-39) at y unk_010c, then,
 * when unk_0004 is set (and not mode 3 with unk_0264 set), frames 26/27 at x unk_010a and
 * frame 67 when flag 0x706 is set. */
void func_020d730c(CampStatusWork *work)
{
    func_02057fd8();
    func_02057df8();
    if (work->unk_01a0 != 0) {
        func_0205dee8(2, work->unk_0018, 53, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 50, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 51, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 52, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
    } else {
        func_0205dee8(2, work->unk_0018, 34, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 35, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 36, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 37, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 38, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
        func_0205dee8(2, work->unk_0018, 39, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
    }
    func_02057e18(31);
    if (work->unk_0004 == 0) {
        return;
    }
    if (work->unk_0000 == 3 && work->unk_0264 != 0) {
        return;
    }
    func_0205dee8(2, work->unk_0018, 26, work->unk_010a, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 27, work->unk_010a, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    if (Unk0e651c_Unk_0e666c(0x706) == 0) {
        return;
    }
    func_0205dee8(2, work->unk_0018, 67, work->unk_010a, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
}'''),
('func_020d9d54', '''/* Draw the 0..100 gauge of record id as a 60-pixel bar (value * 6 / 10) split at the two
 * marks unk_005a/unk_005b (pieces 0x1dc1..0x1dc3, mark ticks 0x1dc4), or the full-gauge frame
 * 32 at 100. With flag 0x706 and Unk02ee5c_GetRecordFlagB(id), add frame 69 and the blinking
 * overlay (alpha ramp over a 28-tick cycle). */
void func_020d9d54(u16 id)
{
    CampStatusRecordSet *rs;
    s32 filled;
    u16 markA;
    u16 markB;
    s16 w0;
    s16 w1;
    s16 w2;
    CampStatusDrawParam param;
    s32 t;
    func_02057df8();
    rs = func_020a1740(id);
    filled = (Unk02e000_GetRecordUnk1e(id) << 12) / 10 * 6 >> 12;
    markA = (rs->unk_005a << 12) / 10 * 6 >> 12;
    markB = (rs->unk_005b << 12) / 10 * 6 >> 12;
    if (filled <= 0) {
        return;
    }
    if (Unk02e000_GetRecordUnk1e(id) >= 100) {
        func_0205de40(2, data_02176be4->unk_0018, 32, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    } else {
        if (filled < markA) {
            w0 = filled;
        } else {
            w0 = markA - 1;
            func_02058f10(2, 0x1dc4, markA + 193, 135, 1, 3, 3);
        }
        if (filled >= markB) {
            w1 = markB - markA - 1;
            func_02058f10(2, 0x1dc4, markB + 193, 135, 1, 3, 3);
        } else {
            w1 = filled - markA;
        }
        w2 = filled - markB;
        if (w0 > 0) {
            func_02058f10(2, 0x1dc1, 0, 0, w0, 3, 3);
        }
        if (w1 > 0) {
            func_02058f10(2, 0x1dc2, markA, 0, w1, 3, 3);
        }
        if (w2 > 0) {
            func_02058f10(2, 0x1dc3, markB, 0, w2, 3, 3);
        }
    }
    if (Unk0e651c_Unk_0e666c(0x706) == 0) {
        return;
    }
    if (Unk02ee5c_GetRecordFlagB(id) == 0) {
        return;
    }
    func_0205de40(2, data_02176be4->unk_0018, 69, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
    func_02008904(func_0205e318(data_02176be4->unk_0018, 148), &param, sizeof(param));
    t = data_0215f05c.unk_0018 % 28;
    if (t % 2 == 1) {
        t++;
    }
    if (t >= 28) {
        t = 0;
    }
    if (t < 8) {
        param.alpha = (0xff000 - t * 0x1fe00) >> 12;
    } else {
        param.alpha = ((t - 8) * 0xcc00) >> 12;
    }
    func_0205e048(2, data_02176be4->unk_0018, &param, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5, 1);
    func_02057e18(31);
}'''),
('func_020dd500', '''/* Sum slot i of up to five records: the four ids[0..3] (each skipped when extra falls in that
 * id's 50-wide block starting at 211, 261, 311, 361) and extra itself. The total starts at 100;
 * the state codes merge through CampStatus_Unk_0dd88c, and slot 6 turns state 0/5 into 1. */
CampStatusStateWord func_020dd500(const u16 *ids, s32 i, s32 extra)
{
    CampStatusStateWord w;
    CampStatusInfo *info;
    w.value = 100;
    w.state = 0;
    info = Unk09974c_Unk_099c60(ids[0]);
    if (info != 0 && (extra < 211 || extra > 260)) {
        w.value += info->unk_0018[i].value;
        w.state = (u16)CampStatus_Unk_0dd88c(w.state, info->unk_0018[i].state);
    }
    info = Unk09974c_Unk_099c60(ids[1]);
    if (info != 0 && (extra < 261 || extra > 310)) {
        w.value += info->unk_0018[i].value;
        w.state = (u16)CampStatus_Unk_0dd88c(w.state, info->unk_0018[i].state);
    }
    info = Unk09974c_Unk_099c60(ids[2]);
    if (info != 0 && (extra < 311 || extra > 360)) {
        w.value += info->unk_0018[i].value;
        w.state = (u16)CampStatus_Unk_0dd88c(w.state, info->unk_0018[i].state);
    }
    info = Unk09974c_Unk_099c60(ids[3]);
    if (info != 0 && (extra < 361 || extra > 410)) {
        w.value += info->unk_0018[i].value;
        w.state = (u16)CampStatus_Unk_0dd88c(w.state, info->unk_0018[i].state);
    }
    if (extra != 0 && (info = Unk09974c_Unk_099c60(extra)) != 0) {
        w.value += info->unk_0018[i].value;
        w.state = (u16)CampStatus_Unk_0dd88c(w.state, info->unk_0018[i].state);
    }
    if (i == 6 && (w.state == 0 || w.state == 5)) {
        w.state = 1;
    }
    return w;
}'''),
], '''int Unk0e651c_Unk_0e666c(u32 flag);
/* 24-byte draw record copied out of func_0205e318 and passed to func_0205e048. */
typedef struct CampStatusDrawParam {
    u32 unk_00[4];
    u32 pad_10_0 : 2;
    u32 alpha : 8;              /* +0x10 bits 2..9: overlay alpha set by func_020d9d54 */
    u32 pad_10_a : 22;
    u32 unk_14;
} CampStatusDrawParam;
int Unk02ee5c_GetRecordFlagB(u16 id);
void *func_0205e318(u32 obj, u32 idx);
void func_02008904(const void *src, void *dst, u32 size);
void func_0205e048(int screen, u32 obj, CampStatusDrawParam *param, int x, int y, float sx, float sy, int rot, float alpha, int prio, int a);''', FIX)]
