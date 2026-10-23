TU = 'src/CampStatus.c'
FIX = [
("""typedef struct CampStatusTableWork {
    u8 pad_0000[0x240];
    u8 unk_0240[0x7242];        /* +0x240: object passed to Unk038fbc_Unk_039160; size from the next field */
    s8 unk_7482;                /* +0x7482/+0x7483: (x, y) passed with unk_0240 */""",
"""/* Per-flag data reached from CampStatusGrid.info; one byte per 4-bit cell flag (1-based). */
typedef struct CampStatusGridInfo {
    u8 pad_0000[0x10];
    u8 unk_0010[15];
} CampStatusGridInfo;

/* Grid looked up by Unk038fbc_Unk_039160 (only the fields used here). */
typedef struct CampStatusGrid {
    u32 unk_0000;
    CampStatusGridInfo *info;
} CampStatusGrid;

/* Record at CampStatusTableWork.unk_03e4; +7 selects the entry ids. */
typedef struct CampStatusMapInfo {
    u8 pad_0000[0x7];
    u8 unk_0007;
} CampStatusMapInfo;

typedef struct CampStatusTableWork {
    u32 unk_0000;
    u8 unk_0004[0x23c];         /* +0x004: Unk09a268 work (Unk09a268_FindEntry); it extends past the
                                 * grid to its entry table at +0x24a8 */
    CampStatusGrid unk_0240;    /* +0x240: grid passed to Unk038fbc_Unk_039160 */
    u8 pad_0248[0x19c];
    CampStatusMapInfo *unk_03e4;
    u8 pad_03e8[0x20c0];
    u8 unk_24a8[0x4f98];        /* +0x24a8: Unk09a268 entry table (func_02058b14); size from the next field */
    u32 unk_7440;               /* +0x7440: func_020dcc00 waits for it in state 5 */
    u8 pad_7444[0x3d];
    s8 unk_7481;                /* +0x7481: state of func_020dcc00 */
    s8 unk_7482;                /* +0x7482/+0x7483: (x, y) passed with unk_0240 */"""),
("""CampStatusCell *Unk038fbc_Unk_039160(u8 *grid, int x, int y);""", """CampStatusCell *Unk038fbc_Unk_039160(CampStatusGrid *grid, int x, int y);"""),
("""    CampStatusCell *c = Unk038fbc_Unk_039160(work->unk_0240, work->unk_7482, work->unk_7483);""",
 """    CampStatusCell *c = Unk038fbc_Unk_039160(&work->unk_0240, work->unk_7482, work->unk_7483);"""),
("""typedef struct CampStatusWorkArea {
    u8 pad_0000[0x35c];
    u16 unk_035c;
} CampStatusWorkArea;""", """typedef struct CampStatusWorkArea {
    u8 pad_0000[0x358];
    u32 unk_0358;
    u16 unk_035c;               /* +0x35c: flag set id */
    u8 pad_035e[0x6];
    s8 unk_0364;                /* +0x364/+0x365: map position */
    s8 unk_0365;
} CampStatusWorkArea;"""),
]
SPECS = [(TU, [
('func_020dcc00', '''/* Handler 3 of the table at 0x0213c1d8: step the event state machine in unk_7481 (0-8, and 100
 * for the cancel path) once per call; returns 1 when it has finished. */
int func_020dcc00(CampStatusTableWork *work)
{
    int done = 0;
    switch (work->unk_7481) {
    case 0:
        if (Unk0a23f4_Unk_0a246c() == 1) {
            work->unk_7481++;
        }
        break;
    case 1:
        if (--work->unk_7484 <= 0) {
            func_02034dd0();
            work->unk_7484 = 0;
            work->unk_7481++;
        }
        break;
    case 2:
        work->unk_7484++;
        if (ScanVisor_GetConst20() < work->unk_7484 && func_020a03cc() == 1) {
            work->unk_7484 = 0;
            work->unk_7481 = 100;
            break;
        }
        if (Unk0a23f4_Unk_0a2490() == 1) {
            u8 id = work->unk_03e4->unk_0007 + 7;
            s32 e0 = Unk09a268_FindEntry(work->unk_0004, id, 0);
            s32 e1 = Unk09a268_FindEntry(work->unk_0004, id, 1);
            s32 e2 = Unk09a268_FindEntry(work->unk_0004, id, 2);
            if (e0 > -1) {
                func_02058b14(work->unk_24a8, e0, 0);
            }
            if (e1 > -1) {
                func_02058b14(work->unk_24a8, e1, 0);
            }
            if (e2 > -1) {
                func_02058b14(work->unk_24a8, e2, 0);
            }
            work->unk_7484 = 0;
            work->unk_7481++;
        }
        break;
    case 3:
        if (func_020a03cc() == 1) {
            work->unk_7481 = 100;
            break;
        }
        if (Unk0a23f4_Unk_0a2448() == 0) {
            work->unk_7484 = 0;
            work->unk_7481++;
        }
        break;
    case 4:
        if (func_02052728() == 0 && ++work->unk_7484 > 5) {
            CampStatusWorkArea *area;
            work->unk_7494 = 1;
            area = Unk02e000_GetWorkArea();
            func_02034b7c(area->unk_035c, area->unk_0364, area->unk_0365, area->unk_0358, 4, 1, 0, 0);
            work->unk_7484 = 0;
            work->unk_7481++;
        }
        break;
    case 5:
        if (work->unk_7440 != 0) {
            func_02065bc0();
            work->unk_7484 = 0;
            work->unk_7481++;
        }
        break;
    case 6:
        if (func_020654cc() == 1) {
            u8 v = 0;
            CampStatusWorkArea *a = Unk02e000_GetWorkArea();
            CampStatusWorkArea *b = Unk02e000_GetWorkArea();
            CampStatusCell *c = Unk038fbc_Unk_039160(&work->unk_0240, a->unk_0364, b->unk_0365);
            u32 n;
            if (c != 0 && (n = c->flag) != 0) {
                v = work->unk_0240.info->unk_0010[n - 1];
            }
            func_0204faf0(1, v);
            func_0206597c(6);
            work->unk_7484 = 0;
            work->unk_7481++;
        }
        break;
    case 7:
        if (func_02065cd0() == 1) {
            func_02065c58();
            work->unk_7484 = 0;
            work->unk_7481++;
        }
        break;
    case 8:
        if (func_020654cc() == 1) {
            done = 1;
        }
        break;
    case 100: {
        u8 id;
        s32 e0;
        s32 e1;
        s32 e2;
        func_0205264c(2, 4, 31, 1, 2);
        ScanVisor_Unk_0a2b7c();
        ScanVisor_Unk_0a2920(1);
        GameState_ClearRootUnk60();
        id = work->unk_03e4->unk_0007 + 7;
        e0 = Unk09a268_FindEntry(work->unk_0004, id, 0);
        e1 = Unk09a268_FindEntry(work->unk_0004, id, 1);
        e2 = Unk09a268_FindEntry(work->unk_0004, id, 2);
        if (e0 > -1) {
            func_02058b14(work->unk_24a8, e0, 80);
        }
        if (e1 > -1) {
            func_02058b14(work->unk_24a8, e1, 80);
        }
        if (e2 > -1) {
            func_02058b14(work->unk_24a8, e2, 80);
        }
        work->unk_7481 = 4;
        break;
    }
    default:
        done = 1;
        break;
    }
    return done;
}'''),
], '''int Unk0a23f4_Unk_0a246c(void);
int Unk0a23f4_Unk_0a2490(void);
int Unk0a23f4_Unk_0a2448(void);
void func_02034dd0(void);
int ScanVisor_GetConst20(void);
int func_020a03cc(void);
int Unk09a268_FindEntry(u8 *w, u32 id, u32 sub);
void func_02058b14(u8 *table, s32 i, u32 v);
int func_02052728(void);
void func_02034b7c(u16 id, int x, int y, u32 v, u32 a, u32 b, u32 c, u32 d);
void func_02065bc0(void);
int func_020654cc(void);
void func_0206597c(u32 v);
int func_02065cd0(void);
void func_02065c58(void);
void func_0205264c(u32 a, u32 b, u32 c, u32 d, u32 e);
void ScanVisor_Unk_0a2b7c(void);
void ScanVisor_Unk_0a2920(u32 a);
void GameState_ClearRootUnk60(void);''', FIX)]
