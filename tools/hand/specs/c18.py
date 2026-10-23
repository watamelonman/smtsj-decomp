TU = 'src/CampStatus.c'
STATS_OLD = """/* Values subtracted and clamped at 0 by CampStatus_Unk_0dc5dc. */
typedef struct CampStatusStats {
    s16 unk_00;
    s16 unk_02;
    s8 unk_04;
    s8 unk_05;
    s8 unk_06;
    s8 unk_07;
    s8 unk_08;
} CampStatusStats;
"""
STATS_NEW = """/* HP/MP and the five stats as shown on the status pages (also subtracted and clamped by
 * CampStatus_Unk_0dc5dc). unk_05 feeds max HP and unk_08 max MP (CampStatus_CalcMaxHp/Mp). */
typedef struct CampStatusStats {
    s16 unk_00;                 /* +0x00: HP (max HP on the unit pages) */
    s16 unk_02;                 /* +0x02: MP */
    s8 unk_04;
    s8 unk_05;
    s8 unk_06;
    s8 unk_07;
    s8 unk_08;
} CampStatusStats;

"""
FIX = [
("""void func_020a9fd8(u32 mode, s32 x, s32 y, u32 arg3, u32 arg4, u32 arg5, u32 resource, u32 count);""",
 """/* Formatted number/text draw: width is a sample string sized by func_020a9e14 (or 0), fmt a
 * printf format ("%d", "%07d", "???") followed by its values. */
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 align, const char *width, u32 size, const char *fmt, ...);"""),
("""    func_020a9fd8(1, 24, 27, 2, (u32)func_020a9e14(1, data_021507cc), 10, (u32)data_021507d0, a);
    func_020a9fd8(1, 86, 27, 2, (u32)func_020a9e14(1, data_021507d4, 0), 10, (u32)data_021507dc, b);""",
 """    func_020a9fd8(1, 24, 27, 2, func_020a9e14(1, data_021507cc), 10, data_021507d0, a);
    func_020a9fd8(1, 86, 27, 2, func_020a9e14(1, data_021507d4, 0), 10, data_021507dc, b);"""),
("""        func_020a9fd8(1, slot * 85 + 64, 143, 2, (u32)width, 10, (u32)data_021507e4, b);""",
 """        func_020a9fd8(1, slot * 85 + 64, 143, 2, width, 10, data_021507e4, b);"""),
("""        func_020a9fd8(1, slot * 85 + 64, 143, 2, (u32)width, 10, (u32)data_021507e8, a);""",
 """        func_020a9fd8(1, slot * 85 + 64, 143, 2, width, 10, data_021507e8, a);"""),
(STATS_OLD, ""),
("""/* Camp status work; the first argument here and also *data_02176be4. */""", STATS_NEW + """/* Camp status work; the first argument here and also *data_02176be4. */"""),
("""    u8 pad_0180[0xc];
    u32 unk_018c;""", """    CampStatusStats unk_0180;   /* +0x180: stats with the new equipment (mode 14/18 compare) */
    u8 pad_018a[0x2];
    u32 unk_018c;"""),
("""    u32 unk_0190;
    u8 pad_0194[0xc];""", """    u32 unk_0190;               /* +0x190: candidate id compared on the player page */
    u16 unk_0194[4];            /* +0x194: candidate ids per slot */
    s16 unk_019c;               /* +0x19c/+0x19e: candidate HP/MP */
    s16 unk_019e;"""),
("""    u32 pad_04_0 : 20;""", """    u32 pad_04_0 : 10;
    u32 unk_04_10 : 10;         /* +0x04 bits 10..19: bonus summed by func_020d78bc */"""),
("""typedef struct CampStatusPlayer {
    u16 unk_0000;               /* +0x00/+0x02: ids passed to Unk09974c_Unk_099c60 */
    u16 unk_0002;
    u8 pad_0004[0x18];
    s16 unk_001c;               /* +0x1c: compared > 0 by CampStatus_Unk_0dd910 */
    u8 pad_001e[0x2a];
    char unk_0048[0x24];        /* +0x48: text passed to func_02061f10; size guessed */
    u16 unk_006c;               /* +0x6c: values 1 and 7 are treated alike by CampStatus_Unk_0dd910 */
} CampStatusPlayer;""", """typedef struct CampStatusPlayer {
    u16 unk_0000[4];            /* +0x00: four ids passed to Unk09974c_Unk_099c60 (equipment?) */
    CampStatusStats unk_0008;   /* +0x08: base stats */
    CampStatusStats unk_0012;   /* +0x12: current stats */
    s16 unk_001c;               /* +0x1c/+0x1e: current HP/MP; HP compared > 0 by CampStatus_Unk_0dd910 */
    s16 unk_001e;
    u32 unk_0020;               /* +0x20: subtracted from func_020b80c8(level) for the level line */
    u8 pad_0024[0x24];
    char unk_0048[0x24];        /* +0x48: text passed to func_02061f10; size guessed */
    u16 unk_006c;               /* +0x6c: values 1 and 7 are treated alike by CampStatus_Unk_0dd910 */
    u8 unk_006e;                /* +0x6e: level */
} CampStatusPlayer;"""),
("void CampStatus_Unk_0da8c4(void *obj, u32 unused, s32 sel)", "void CampStatus_Unk_0da8c4(void *obj, const u16 *ids, s32 sel)"),
]
import re
SRC = open('~/sj-decomp/' + TU).read()
TIDY = open('/tmp/claude-0/sp/tidy_out.c').read()
FIX.insert(0, (SRC, TIDY))
SRC = TIDY
# the player's first two ids become an array
NEWSRC = re.sub(r'p->unk_0000\b', 'p->unk_0000[0]', SRC)
NEWSRC = re.sub(r'p->unk_0002\b', 'p->unk_0000[1]', NEWSRC)
FIX.insert(1, (SRC, NEWSRC))
SLOTLOOP = '''        for (i = 0; i <= 7; i++) {
'''
SPECS = [(TU, [
('func_020d78bc', '''/* Player page (modes 1, 14, 18): stats and HP/MP against the compared values (mode 14: base
 * vs current vs unk_0180, mode 18: current vs candidate), level line, the attack/defence lines
 * with the item bonuses, the eight slot states (mode 18 marks changed ones in orange) and the
 * id grid. */
void func_020d78bc(CampStatusWork *work)
{
    CampStatusPlayer *p;
    CampStatusStateWord w0;
    CampStatusStateWord w1;
    CampStatusStateWord w;
    CampStatusInfo *info;
    s32 s0;
    s32 s1;
    s32 i;
    func_02057fd8();
    func_02057df8();
    CampStatus_Unk_0dd910();
    Unk0ddeb0_Unk_0ddeb0(work->unk_00bc, 2, 15, 0, 5, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 15, 0, 8, 10);
    func_02057df8();
    p = Unk02e000_Thunk_0202e788();
    if (work->unk_0000 == 14) {
        CampStatus_Unk_0da0e0(work, &p->unk_0008, &p->unk_0012, &work->unk_0180, 2);
    } else if (work->unk_0000 == 18) {
        CampStatus_Unk_0da0e0(work, &p->unk_0012, &work->unk_0180, 0, 1);
    } else {
        CampStatus_Unk_0da0e0(work, &p->unk_0008, &p->unk_0012, 0, 0);
    }
    if (work->unk_0000 == 14) {
        func_020da2cc(p->unk_001c, p->unk_001e, &p->unk_0008.unk_00, &p->unk_0012.unk_00, &work->unk_0180.unk_00, 2);
    } else if (work->unk_0000 == 18) {
        func_020da2cc(work->unk_019c, work->unk_019e, &p->unk_0012.unk_00, &work->unk_0180.unk_00, 0, 1);
    } else {
        func_020da2cc(p->unk_001c, p->unk_001e, &p->unk_0008.unk_00, &p->unk_0012.unk_00, 0, 0);
    }
    if (work->unk_0000 == 14) {
        char *width;
        func_02057ddc(0x8cff4a00);
        func_020a9fd8(1, 24, 27, 2, func_020a9e14(1, data_02150758), 10, data_0215075c, p->unk_006e);
        width = func_020a9e14(1, data_02150760, 0);
        func_020a9fd8(1, 86, 27, 2, width, 10, data_02150768, func_020b80c8(p->unk_006e) - p->unk_0020);
        func_02057df8();
    } else {
        CampStatus_Unk_0da670(p->unk_006e, func_020b80c8(p->unk_006e) - p->unk_0020);
    }
    CampStatus_Unk_0db478(work->unk_0018, work->unk_0080, p->unk_006c);
    if (work->unk_0000 == 18) {
        CampStatusInfo *n0;
        CampStatusInfo *n1;
        CampStatusInfo *o0;
        CampStatusInfo *o1;
        s32 oldv;
        s32 newv;
        u32 id;
        n0 = Unk09974c_Unk_099c60(work->unk_0194[0]);
        o0 = Unk09974c_Unk_099c60(p->unk_0000[0]);
        oldv = 0;
        newv = 0;
        if (o0 != 0) {
            oldv += Unk09974c_Unk_099cc4(o0);
        }
        if (n0 != 0) {
            newv += Unk09974c_Unk_099cc4(n0);
        }
        CampStatus_Unk_0da97c(work->unk_0018, (s16)(oldv + p->unk_0012.unk_04), (s16)(newv + work->unk_0180.unk_04), 1, 0);
        n0 = Unk09974c_Unk_099c60(work->unk_0194[1]);
        o0 = Unk09974c_Unk_099c60(p->unk_0000[1]);
        oldv = 0;
        newv = 0;
        if (o0 != 0) {
            oldv += Unk09974c_Unk_099cc4(o0);
        }
        if (n0 != 0) {
            newv += Unk09974c_Unk_099cc4(n0);
        }
        CampStatus_Unk_0da97c(work->unk_0018, (s16)(oldv + p->unk_0012.unk_04), (s16)(newv + work->unk_0180.unk_04), 1, 1);
        n0 = Unk09974c_Unk_099c60(work->unk_0194[2]);
        n1 = Unk09974c_Unk_099c60(work->unk_0194[3]);
        o0 = Unk09974c_Unk_099c60(p->unk_0000[2]);
        o1 = Unk09974c_Unk_099c60(p->unk_0000[3]);
        oldv = 0;
        newv = 0;
        if (o0 != 0) {
            oldv += o0->unk_04_10;
        }
        if (o1 != 0) {
            oldv += o1->unk_04_10;
        }
        if (n0 != 0) {
            newv += n0->unk_04_10;
        }
        if (n1 != 0) {
            newv += n1->unk_04_10;
        }
        CampStatus_Unk_0da97c(work->unk_0018, (s16)(oldv + p->unk_0012.unk_05), (s16)(newv + work->unk_0180.unk_05), 1, 2);
        id = work->unk_0190;
        for (i = 0; i <= 7; i++) {
            w0 = CampStatus_Unk_0dd500(p->unk_0000, i, 0);
            s0 = func_020dd364(w0, 0, i);
            w1 = CampStatus_Unk_0dd500(p->unk_0000, i, id);
            s1 = func_020dd364(w1, 0, i);
            if (s0 != s1) {
                func_02057ddc(0xff942100);
            } else {
                func_02057df8();
            }
            Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, i * 14 + 7, 67, s1 + 5, 2, 10);
        }
    } else {
        s32 j;
        CampStatusInfo *o0;
        CampStatusInfo *o1;
        s32 v;
        o0 = Unk09974c_Unk_099c60(p->unk_0000[0]);
        if (o0 != 0) {
            CampStatus_Unk_0da97c(work->unk_0018, (s16)(p->unk_0012.unk_04 + Unk09974c_Unk_099cc4(o0)), 0, 0, 0);
        } else {
            CampStatus_Unk_0da97c(work->unk_0018, p->unk_0012.unk_04, 0, 0, 0);
        }
        o0 = Unk09974c_Unk_099c60(p->unk_0000[1]);
        if (o0 != 0) {
            CampStatus_Unk_0da97c(work->unk_0018, (s16)(p->unk_0012.unk_04 + Unk09974c_Unk_099cc4(o0)), 0, 0, 1);
        } else {
            CampStatus_Unk_0da97c(work->unk_0018, 0, 0, 0, 1);
        }
        o0 = Unk09974c_Unk_099c60(p->unk_0000[2]);
        o1 = Unk09974c_Unk_099c60(p->unk_0000[3]);
        v = 0;
        if (o0 != 0) {
            v += o0->unk_04_10;
        }
        if (o1 != 0) {
            v += o1->unk_04_10;
        }
        CampStatus_Unk_0da97c(work->unk_0018, (s16)(v + p->unk_0012.unk_05), 0, 0, 2);
        for (j = 0; j <= 7; j++) {
            w = CampStatus_Unk_0dd500(p->unk_0000, j, 0);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, j * 14 + 7, 67, func_020dd364(w, 0, j) + 5, 2, 10);
        }
    }
    if (p->unk_0000[1] != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000[1])) != 0) {
        CampStatus_Unk_0da8c4(work->unk_00c4, info->unk_0040, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
    }
    if (work->unk_0008 == 0) {
        return;
    }
    func_02057df8();
    if (work->unk_00e8 == 0 && work->unk_0000 == 18) {
        info = Unk09974c_Unk_099c60(work->unk_0190);
        if (info == 0) {
            return;
        }
        if (info->unk_0002 == 3) {
            func_02057ddc(0xff942100);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
            func_02057df8();
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
            return;
        }
        if (info->unk_0002 == 4) {
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
            func_02057ddc(0xff942100);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
            return;
        }
        Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
        Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
        return;
    }
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
}'''),
], '''extern char data_02150758[];
extern char data_0215075c[];
extern char data_02150760[];
extern char data_02150768[];
u32 func_020b80c8(u8 level);
s32 Unk09974c_Unk_099cc4(CampStatusInfo *info);
void CampStatus_Unk_0dd910(void);
void CampStatus_Unk_0db478(u32 obj, u32 obj2, u32 idx);
void CampStatus_Unk_0da97c(u32 obj, s32 a, s32 b, s32 mode, u8 slot);
void CampStatus_Unk_0da8c4(void *obj, const u16 *ids, s32 sel);
CampStatusStateWord CampStatus_Unk_0dd500(const u16 *ids, s32 i, s32 extra);''', FIX)]
