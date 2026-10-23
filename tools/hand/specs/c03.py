TU = 'src/CampStatus.c'
SRC = open('~/sj-decomp/' + TU).read()
PRE = '''/* Opaque grey RGBA: v in all three colour bytes, alpha 0xff. */
#define CAMP_GREY(v) (((v) << 24) + ((v) << 16) + ((v) << 8) + 0xff)
/* Player-side record from Unk02e000_Thunk_0202e788 (fields as used in this file). */
typedef struct CampStatusPlayer {
    u16 unk_0000;               /* +0x00/+0x02: ids passed to Unk09974c_Unk_099c60 */
    u16 unk_0002;
    u8 pad_0004[0x18];
    s16 unk_001c;               /* +0x1c: compared > 0 by func_020dd910 */
    u8 pad_001e[0x2a];
    char unk_0048[0x24];        /* +0x48: text passed to func_02061f10; size guessed */
    u16 unk_006c;               /* +0x6c: values 1 and 7 are treated alike by func_020dd910 */
} CampStatusPlayer;
/* Record from Unk09974c_Unk_099c60. */
typedef struct CampStatusInfo {
    u8 pad_0000[0x2];
    u8 unk_0002;
    u8 pad_0003[0x5];
    u8 lo : 4;                  /* +0x08: two nibbles compared by func_020db824 */
    u8 hi : 4;
    u8 unk_0009;
    u8 pad_000a[0x36];
    u16 unk_0040[3];            /* +0x40: id list, 0-terminated */
} CampStatusInfo;
/* Values subtracted and clamped at 0 by func_020dc5dc. */
typedef struct CampStatusStats {
    s16 unk_00;
    s16 unk_02;
    s8 unk_04;
    s8 unk_05;
    s8 unk_06;
    s8 unk_07;
    s8 unk_08;
} CampStatusStats;
/* Global at data_0215f05c; +0x18 is a running tick count fed to the ramp helpers. */
typedef struct CampStatusTicker {
    u8 pad_0000[0x18];
    s32 unk_0018;
} CampStatusTicker;
extern CampStatusTicker data_0215f05c;
extern u8 data_0213c600[];
void func_02057fd8(void);
void func_02057df8(void);
void func_02057e18(u32 alpha);
void func_02057eb8(s32 v);
void func_0205dee8(int screen, u32 obj, int frame, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_0205de40(int screen, u32 obj, int frame, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_02058e9c(int screen, u32 res, int x, int y, float scale, int a, int b);
void func_02058f10(int screen, u32 res, int x, int y, int w, int h, int c);
CampStatusPlayer *Unk02e000_Thunk_0202e788(void);
CampStatusInfo *Unk09974c_Unk_099c60(u32 id);
void func_02008644(u32 value, void *dst, u32 size);
int func_020a18c8(u16 id, u16 *out, u32 n);
void Unk0ddeb0_Unk_0ddeb0(void *obj, int a, int b, int c, int d, int e);
s32 Unk02ee5c_GetTierFromField70(void);
int func_020523a8(void);
u32 Unk0ddeb0_Unk_0ddfd8(u32 i);
u32 Unk0ca69c_Unk_0ca6a4(u32 v);
void func_020db910(CampStatusInfo *info);
void func_020da710();
u8 CampStatus_Unk_0db288(s32 t);
'''
OLD_DRAW = SRC[SRC.index('int func_02057fd8();\nint func_0205dee8();'):SRC.index('int CampStatus_IsUnkF4F8Set(void)')]
NEW_DRAW = '''/* decompiler-derived: frames 0x10..0x12 of obj at (x, 0), alpha a. */
void CampStatus_Unk_0ddd2c(u32 obj, int x, float alpha)
{
  func_0205dee8(2, obj, 0x10, x, 0, 1.0f, 1.0f, 0, alpha, 2);
  func_02057fd8();
  func_0205dee8(2, obj, 0x11, x, 0, 1.0f, 1.0f, 0, alpha, 3);
  func_02057fd8();
  func_0205dee8(2, obj, 0x12, x, 0, 1.0f, 1.0f, 0, alpha, 4);
}

/* decompiler-derived */
void CampStatus_Unk_0d71bc(CampStatusWork *work)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2, work->unk_0018, 0x2b, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x2c, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x2d, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_02057e18(0x1f);
  func_0205dee8(2, work->unk_0018, 0x2e, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x2f, 0, work->unk_010c, 1.0f, 1.0f, 0, 1.0f, 3);
}

/* decompiler-derived */
void CampStatus_Unk_0d7680(CampStatusWork *work)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2, work->unk_0018, 5, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x41, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 3);
  func_0205dee8(2, work->unk_0018, 0x22, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x23, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x24, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x25, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x26, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x27, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x21, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_02057e18(0x1f);
}

'''
FIX = [
("""    u8 pad_0180[0x20];
""", """    u8 pad_0180[0xc];
    u32 unk_018c;               /* +0x18c: func_020d6948 draws only when set */
    u8 pad_0190[0x10];
"""),
("""extern CampStatusWork *data_02176be4;
""", """extern CampStatusWork *data_02176be4;

""" + PRE),
(OLD_DRAW, NEW_DRAW),
("""    u32 unk_0110;
""", """    f32 unk_0110;               /* +0x110: alpha passed to func_0205dee8 */
"""),
("""    u16 unk_00d0;
    u8 pad_00d2[0x8];
    u16 unk_00da;               /* +0xda: id passed to func_020a1740 */
    u8 pad_00dc[0x14];
    s8 unk_00f0;""", """    u16 unk_00d0;
    u8 unk_00d2[0x8];           /* +0xd2: passed to func_020da710; size from the next field */
    u16 unk_00da;               /* +0xda: id passed to func_020a1740 */
    u16 unk_00dc[6];            /* +0xdc: id list filled by func_020a18c8 */
    u32 unk_00e8;
    u8 pad_00ec[0x4];
    s8 unk_00f0;"""),
("""void CampStatus_Unk_0dddf4(u32 obj, int x, u32 alpha)
{
    func_0205dee8(2, obj, 0x1a, x, 0, 0x3f800000, 0x3f800000, 0, alpha, 2);
}""", """void CampStatus_Unk_0dddf4(u32 obj, int x, float alpha)
{
    func_0205dee8(2, obj, 0x1a, x, 0, 1.0f, 1.0f, 0, alpha, 2);
}"""),
]
SPECS = [(TU, [
('func_020d6948', '''/* Handler 0x18 of the CampStatus_Unk_0d3624 table: when unk_018c is set and func_020523a8()
 * is 1, draw six grey gradient bars (frame 0, 32 px apart), then run func_020d6120. */
void func_020d6948(CampStatusWork *work)
{
    int i;
    if (work->unk_018c == 0) {
        return;
    }
    if (func_020523a8() != 1) {
        return;
    }
    func_02057eb8(-1);
    func_02057fd8();
    func_02057df8();
    for (i = 0; i < 6; i++) {
        /* bar i fades from shade i (top) to shade i + 1 (bottom); shade n = 25 + 38 * n */
        u32 top = CAMP_GREY(i * 38 + 25);
        u32 bottom = CAMP_GREY((i + 1) * 38 + 25);
        func_02057dcc(top, bottom, bottom, top);
        func_0205dee8(2, work->unk_001c, 0, 0, i * 32, 1.0f, 1.0f, 0, 1.0f, 0);
    }
    func_020d6120(work);
}'''),
('func_020d8d60', '''/* Draw the labels on unk_00c0 (grey when Unk09974c_Unk_0998d8(unk_00d0) is 0), the list on
 * unk_00c4 (func_020da710, selection unk_00f0 when unk_00e8 is set, else -1) and, when unk_0008
 * is set, two more labels on unk_00c8. */
void func_020d8d60(CampStatusWork *work)
{
    if (Unk09974c_Unk_0998d8(work->unk_00d0) == 0) {
        func_02057ddc(0x7b7b7bff);
    } else {
        func_02057df8();
    }
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 14, 0, 8, 10);
    func_02057df8();
    func_020da710(work->unk_00c4, work->unk_00d2, 0, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
    if (work->unk_0008 == 0) {
        return;
    }
    func_02057df8();
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
}'''),
('func_020da8c4', '''/* When sel >= 0, draw the pulsing cursor bar at row sel (85 px per row, alpha from the
 * CampStatus_Unk_0db288 ramp); then draw the three slots of obj. */
void func_020da8c4(void *obj, u32 unused, s32 sel)
{
    s32 i;
    if (sel >= 0) {
        func_02057df8();
        func_02057e18(CampStatus_Unk_0db288(data_0215f05c.unk_0018));
        func_02058f10(2, 0x1dd4, sel * 85, 13, 83, 12, 9);
        func_02057e18(31);
    }
    func_02057fd8();
    for (i = 0; i < 3; i++) {
        func_02057df8();
        Unk0ddeb0_Unk_0ddeb0(obj, i * 85 + 4, 153, i, 8, 10);
    }
}'''),
('func_020db478', '''/* For a non-zero idx: draw frame 6 of obj, the resource for Unk0ddeb0_Unk_0ddfd8(idx) at
 * (109, 13), and frame data_0213c600[idx] of obj2. */
void func_020db478(u32 obj, u32 obj2, u32 idx)
{
    if (idx == 0) {
        return;
    }
    func_0205dee8(2, obj, 6, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    func_02057e18(31);
    func_02057df8();
    func_02058e9c(2, Unk0ca69c_Unk_0ca6a4(Unk0ddeb0_Unk_0ddfd8(idx)), 109, 13, 1.0f, 0, 3);
    func_0205de40(2, obj2, data_0213c600[idx], 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
}'''),
('func_020db824', '''/* For both player ids (+0x00, +0x02): pick icon 1/0 (resp. 3/2) by whether the record's two
 * nibbles differ and run func_020db910 on it; show both icons on unk_00c8 only when both ids
 * are set, else clear it. */
void func_020db824(CampStatusWork *work)
{
    u32 icons[2] = {0, 0};
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    CampStatusInfo *info;
    if (p->unk_0000 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000)) != 0) {
        if (info->lo != info->hi) {
            icons[0] = 1;
        } else {
            icons[0] = 0;
        }
        func_020db910(info);
    }
    if (p->unk_0002 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0002)) != 0) {
        if (info->lo != info->hi) {
            icons[1] = 3;
        } else {
            icons[1] = 2;
        }
        func_020db910(info);
    }
    if (p->unk_0000 != 0 && p->unk_0002 != 0) {
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, icons, 2);
        return;
    }
    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
}'''),
('func_020dc184', '''/* Show icon 43 on unk_00bc, the player's text (+0x48) on unk_00c0, and the 0-terminated id
 * list (up to 3) of the player's second record on unk_00c4. */
void func_020dc184(CampStatusWork *work)
{
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    u32 ids[3];
    CampStatusInfo *info;
    u32 i;
    ids[0] = 43;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    func_02061f10(work->unk_00c0, -1, 0, 0, p->unk_0048);
    if (p->unk_0002 == 0) {
        return;
    }
    info = Unk09974c_Unk_099c60(p->unk_0002);
    if (info == 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (info->unk_0040[i] == 0) {
            break;
        }
        ids[i] = info->unk_0040[i];
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}'''),
('func_020dc2ec', '''/* Like func_020dc240 for record unk_00da: its entry byte on unk_00bc, the id on unk_00c0, and
 * the id list func_020a18c8 writes to unk_00dc (up to 6) on unk_00c4. */
void func_020dc2ec(CampStatusWork *work)
{
    u32 ids[6];
    u32 i;
    ids[0] = func_020a1428(work->unk_00da)->unk_02;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    ids[0] = work->unk_00da;
    CampStatus_Unk_0dde3c(work->unk_00c0, 18, 1, ids, 1);
    func_02008644(0, work->unk_00dc, 12);
    if (func_020a18c8(work->unk_00da, work->unk_00dc, 6) == 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        if (work->unk_00dc[i] == 0) {
            break;
        }
        ids[i] = work->unk_00dc[i];
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}'''),
('func_020dc5dc', '''/* out = a - b field by field, each clamped at 0. */
void func_020dc5dc(const CampStatusStats *a, const CampStatusStats *b, CampStatusStats *out)
{
    out->unk_00 = a->unk_00 - b->unk_00;
    if (out->unk_00 < 0) {
        out->unk_00 = 0;
    }
    out->unk_02 = a->unk_02 - b->unk_02;
    if (out->unk_02 < 0) {
        out->unk_02 = 0;
    }
    out->unk_04 = a->unk_04 - b->unk_04;
    if (out->unk_04 < 0) {
        out->unk_04 = 0;
    }
    out->unk_08 = a->unk_08 - b->unk_08;
    if (out->unk_08 < 0) {
        out->unk_08 = 0;
    }
    out->unk_05 = a->unk_05 - b->unk_05;
    if (out->unk_05 < 0) {
        out->unk_05 = 0;
    }
    out->unk_06 = a->unk_06 - b->unk_06;
    if (out->unk_06 < 0) {
        out->unk_06 = 0;
    }
    out->unk_07 = a->unk_07 - b->unk_07;
    if (out->unk_07 < 0) {
        out->unk_07 = 0;
    }
}'''),
('func_020dd910', '''/* Colour for the player's line by tier (4, 5, other): the first colour when status +0x6c is
 * 1 or 7 or +0x1c is not positive, the second otherwise (default colour for other tiers). */
void func_020dd910(void)
{
    s32 tier = Unk02ee5c_GetTierFromField70();
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    if (tier == 4) {
        if (p->unk_006c == 1 || p->unk_006c == 7 || p->unk_001c <= 0) {
            func_02057ddc(0x18525aff);
        } else {
            func_02057ddc(0x39dccbff);
        }
        return;
    }
    if (tier == 5) {
        if (p->unk_006c == 1 || p->unk_006c == 7 || p->unk_001c <= 0) {
            func_02057ddc(0x5a3129ff);
        } else {
            func_02057ddc(0xff7b63ff);
        }
        return;
    }
    if (p->unk_006c == 1 || p->unk_006c == 7 || p->unk_001c <= 0) {
        func_02057ddc(0x7b7b7bff);
    } else {
        func_02057df8();
    }
}'''),
], '', FIX)]
