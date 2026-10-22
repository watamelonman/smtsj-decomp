/*
 * src/CampStatus.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef float f32;
/* First word of a CampStatusObj; also the handle the func_0205c* helpers take. */
typedef struct CampStatusLink {
    u8 pad_0000[0x14];
    u32 unk_0014;
} CampStatusLink;
/* Game object made by Unk065e88_Call_02065fc0 and released with func_02061424. */
typedef struct CampStatusObj {
    CampStatusLink *link;
    u8 pad_0004[0x1c];
    f32 scale;                  /* +0x20: reset to 1.0 by CampStatus_ResetAnim */
    s32 unk_0024;
    s32 unk_0028;               /* +0x28: reset to -1 by CampStatus_ResetAnim */
    u8 pad_002c[0x4];
    s32 unk_0030;
    u8 pad_0034[0x6];
    u8 flag_3a;                 /* +0x3a: written by Unk065e88_SetFlag3a */
} CampStatusObj;
/* Bust-up picture set; CampStatus_Unk_0dc6c0 builds two from "Camp/Status/st_bu_anime" and the
 * "bust_up/st_bu_en%03d" / "st_bu_mt%03d" textures (CampStatus_Unk_0db338 / _0db394). */
typedef struct CampStatusBustUp {
    u32 res;                    /* +0x00: func_0205dcd4 resource, freed by func_0205ddb4 */
    u32 anim;                   /* +0x04: func_0205c2c4 animation, freed by func_0205c368 */
    u32 unk_08;                 /* +0x08: from func_0205ba28 */
    u32 tex;                    /* +0x0c: func_02051610 texture, freed by func_02053000 */
    CampStatusObj *obj;
    u32 unk_14;
} CampStatusBustUp;
/* Byte pairs copied as a block (see CampStatus_Copy168 / CampStatus_Copy176). */
typedef struct CampStatusPair {
    u8 a;
    u8 b;
} CampStatusPair;
typedef struct CampStatusPairs6 {
    CampStatusPair p[6];
} CampStatusPairs6;
typedef struct CampStatusPairs5 {
    CampStatusPair p[5];
} CampStatusPairs5;
/* HP/MP and the five stats as shown on the status pages (also subtracted and clamped by
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

/* Text object (func_020629ac); only the fields read in this file. */
typedef struct CampStatusText {
    u8 pad_0000[0x14];
    u16 *unk_0014;              /* +0x14: glyph codes; 0x8001 ends a line (see CampStatus_Unk_0d9830) */
    u8 pad_0018[0x10];
    u32 unk_0028;
} CampStatusText;
/* Unit record at CampStatusWork.unk_00cc (also the argument of CampStatus_Unk_0ddb04). */
typedef struct CampStatusUnit {
    CampStatusStats unk_0000;   /* +0x00: stats as shown */
    CampStatusStats unk_000a;   /* +0x0a: stats with max HP/MP at +0x0a/+0x0c */
    u8 pad_0014[0xa];
    s16 unk_001e;               /* +0x1e: current HP (> 0 checked by CampStatus_Unk_0dd9d8) */
    s16 unk_0020;               /* +0x20: current MP */
    u8 pad_0022[0x2];
    u32 unk_0024;               /* +0x24: subtracted from func_020b8144's value for the level line */
    u16 unk_0028[6];            /* +0x28: id list, 0-terminated */
    u16 unk_0034;               /* +0x34: values 1 and 7 are treated alike by CampStatus_Unk_0dd9d8 */
    u16 unk_0036;               /* +0x36: id passed to func_020a1428 */
    u8 unk_0038;                /* +0x38: level */
} CampStatusUnit;

/* Camp status work; the first argument here and also *data_02176be4. */
typedef struct CampStatusWork {
    u8 unk_0000;                /* +0x00: screen mode; selects the id source in CampStatus_Unk_0dbf6c */
    u8 pad_0001[0x3];
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x4];
    u32 unk_0014;
    u32 unk_0018;               /* +0x18/+0x1c: resources (func_0205ddb4), +0x20 animation */
    u32 unk_001c;
    u32 unk_0020;
    CampStatusObj *unk_0024[22]; /* +0x24: objects; [2], [11..18] and [21] are used here */
    u32 unk_007c;
    u32 unk_0080;
    CampStatusBustUp unk_0084[2];
    CampStatusText *unk_00b4;   /* +0xb4..+0xc8: text objects (func_020629ac), drawn with */
    CampStatusText *unk_00b8;   /* CampStatus_Unk_0dde3c / Unk0ddeb0_Unk_0ddeb0, released by */
    CampStatusText *unk_00bc;   /* func_020629c4 */
    CampStatusText *unk_00c0;
    CampStatusText *unk_00c4;
    CampStatusText *unk_00c8;
    CampStatusUnit *unk_00cc;
    u16 unk_00d0;
    u16 unk_00d2[4];            /* +0xd2: id list (4 slots, filled by func_020d3680) */
    u16 unk_00da;               /* +0xda: id passed to func_020a1740 */
    u16 unk_00dc[6];            /* +0xdc: id list filled by func_020a18c8 */
    u32 unk_00e8;
    u32 unk_00ec;
    s8 unk_00f0;                /* +0xf0: record index into func_020a1740's result */
    s8 unk_00f1;
    u8 pad_00f2[0x2];
    u32 unk_00f4;
    u32 unk_00f8;
    s16 unk_00fc;
    s16 unk_00fe;
    s16 unk_0100[5];            /* +0x100: x of the five rows drawn by CampStatus_Unk_0d6e10 */
    s16 unk_010a;
    s16 unk_010c;
    s16 unk_010e;
    f32 unk_0110;               /* +0x110: alpha passed to func_0205dee8 */
    u32 unk_0114;               /* +0x114: set once unk_0118 matches the shown stats */
    s16 unk_0118[10];
    u8 pad_012c[0x3c];          /* +0x12c: 60 bytes written by CampStatus_Copy12c */
    CampStatusPairs6 unk_0168;
    u8 pad_0174[0x2];
    CampStatusPairs5 unk_0176;
    CampStatusStats unk_0180;   /* +0x180: stats with the new equipment (mode 14/18 compare) */
    u8 pad_018a[0x2];
    u32 unk_018c;               /* +0x18c: CampStatus_Unk_0d6948 draws only when set */
    u32 unk_0190;               /* +0x190: candidate id compared on the player page */
    u16 unk_0194[4];            /* +0x194: candidate ids per slot */
    s16 unk_019c;               /* +0x19c/+0x19e: candidate HP/MP */
    s16 unk_019e;
    u32 unk_01a0;
    u32 unk_01a4;               /* +0x1a4: when set, CampStatus_Unk_0d5d44 skips one frame */
    u32 unk_01a8;
    u32 unk_01ac;               /* +0x1ac/+0x1b0: hide the two tabs drawn by CampStatus_Unk_0d6120 */
    u32 unk_01b0;
    u8 pad_01b4[0x8c];
    u8 unk_0240;
    u8 unk_0241;
    u8 pad_0242[0x6];
    u16 unk_0248;               /* +0x248: id for CampStatus_Unk_0dbd04 */
    s16 unk_024a;               /* +0x24a: negative selects the icon-only path of CampStatus_Unk_0db548 */
    u8 pad_024c[0x4];
    u32 unk_0250;               /* +0x250: written to 1 by func_020dcb44 */
    u8 pad_0254[0x4];
    u32 unk_0258;
    u32 unk_025c;               /* +0x25c: selects the id list in CampStatus_Unk_0dc3b8 */
    u32 unk_0260;
    u32 unk_0264;
    s32 unk_0268;               /* +0x268: set by CampStatus_Unk_0dcad4 */
} CampStatusWork;                /* 0x26c bytes: the size CampStatus_Unk_0d3624 registers */

/* Cell returned by Unk038fbc_Unk_039160; bits 12..15 of the word at +4 select a flag. */
typedef struct CampStatusCell {
    u32 unk_00;
    u32 pad_bits : 12;
    u32 flag : 4;
    u32 pad_hi : 16;
} CampStatusCell;
/* Object handled by the four-entry table at 0x0213c1d8 (CampStatus_GetUnkField7494,
 * CampStatus_Unk_0dcb68, CampStatus_Unk_0dcc00, func_020dd0a4); a different object from CampStatusWork. */
/* Per-flag data reached from CampStatusGrid.info; one byte per 4-bit cell flag (1-based). */
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
    u32 unk_7440;               /* +0x7440: CampStatus_Unk_0dcc00 waits for it in state 5 */
    u8 pad_7444[0x3d];
    s8 unk_7481;                /* +0x7481: state of CampStatus_Unk_0dcc00 */
    s8 unk_7482;                /* +0x7482/+0x7483: (x, y) passed with unk_0240 */
    s8 unk_7483;
    s32 unk_7484;               /* +0x7484: set to 60 when a new flag is raised */
    u8 pad_7488[0xc];
    u32 unk_7494;
} CampStatusTableWork;
extern CampStatusWork *data_02176be4;
/* Record buffer filled by Unk02e000_SetRecord (36 bytes on the stack in CampStatus_Unk_0dc3b8). */
typedef struct CampStatusSavedRecord {
    u8 unk_0000;                /* +0x00: level (see CampStatus_CalcMaxHp) */
    u8 unk_0001;                /* +0x01..+0x05: the five stats; +2 feeds max MP, +3 max HP */
    u8 unk_0002;
    u8 unk_0003;
    u8 unk_0004;
    u8 unk_0005;
    u8 pad_0006[0xa];
    u16 unk_0010[6];            /* +0x10: id list, 0-terminated */
    u8 pad_001c[0x4];
    u32 unk_0020;               /* +0x20: subtracted from func_020b8144's value for the level line */
} CampStatusSavedRecord;
int Unk02e000_SetRecord(u32 id, CampStatusSavedRecord *out);
void func_0204fcb0(u32 slot, u32 v);
void func_0205bb68(void);
void func_02053000(u32 handle);
void func_0205ddb4(u32 handle);
void func_0205c368(u32 handle);
void func_02061424();
/* 16-byte descriptor copied from data_0213c590 / data_0213c5a0 for func_0205ba28. */
typedef struct CampStatusDesc {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
} CampStatusDesc;
extern const CampStatusDesc data_0213c590;
extern const CampStatusDesc data_0213c5a0;
extern char data_02150854[];
extern char data_0215086c[];
extern char data_02150884[];
extern char data_02150894[];
extern char data_021508ac[];
extern char data_021508c4[];
CampStatusObj *Unk065e88_Call_02065fc0(u32 a, u32 b, u32 c, u16 d);
void func_0205c408(CampStatusLink *link, int seq);
void func_0205c6e0(CampStatusLink *link);
u32 func_0205dcd4(const char *path, u32 a);
u32 func_0205c2c4(const char *path);
u32 func_0205ba28(CampStatusDesc *desc, const char *file, u32 line);
void func_0205de30(u32 res, u32 a, u32 b);
u32 CampStatus_Unk_0db338(CampStatusBustUp *b, u32 n);
u32 CampStatus_Unk_0db394(CampStatusBustUp *b, u32 i);
void func_0205c3dc(u32 handle);
void func_020629c4(void *text);
void Unk0c855c_Unk_0ca648(u32 a);
void Unk044394_Unk_044534(u32 a);
void func_020dab5c(CampStatusWork *work, s32 cur, s32 next, s32 add, s32 row, u32 arg5);
/* Request block sent with func_020bc9f4 / func_020bcacc (same layout as unit_020e1648's). */
typedef struct CampStatusRequest {
    u8 flags[2];
    u8 pad_0002[2];
    u32 values[16];
} CampStatusRequest;
void func_020bc9f4(u32 kind, CampStatusRequest *req);
void func_020bcacc(u32 kind, CampStatusRequest *req);
/* Opaque grey RGBA: v in all three colour bytes, alpha 0xff. */
#define CAMP_GREY(v) (((v) << 24) + ((v) << 16) + ((v) << 8) + 0xff)
/* Player-side record from Unk02e000_Thunk_0202e788 (fields as used in this file). */
typedef struct CampStatusPlayer {
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
} CampStatusPlayer;
/* Signed modifier halfword: 10-bit amount, 6-bit state code (see CampStatus_Unk_0dd500). */
typedef struct CampStatusStatMod {
    s16 value : 10;
    s16 state : 6;
} CampStatusStatMod;
/* Result halfword of CampStatus_Unk_0dd500: 10-bit total, 6-bit state code (as CampStatus_Unk_0dd88c). */
typedef struct CampStatusStateWord {
    u16 value : 10;
    u16 state : 6;
} CampStatusStateWord;
/* Record from Unk09974c_Unk_099c60. */
typedef struct CampStatusInfo {
    u8 pad_0000[0x2];
    u8 unk_0002;                /* +0x02: 3 and 4 select the slot set in CampStatus_Unk_0db910 */
    u8 pad_0003;
    u32 pad_04_0 : 10;
    u32 unk_04_10 : 10;         /* +0x04 bits 10..19: bonus summed by CampStatus_Unk_0d78bc */
    u32 unk_04_20 : 12;         /* +0x04: top 12 bits */
    u8 lo : 4;                  /* +0x08: two nibbles compared by CampStatus_Unk_0db824 */
    u8 hi : 4;
    u8 unk_0009;
    u8 pad_000a;
    u8 unk_000b;
    u8 pad_000c[0xc];
    CampStatusStatMod unk_0018[8];  /* +0x18: per-slot modifiers; 7 used (index 0..6), size guessed */
    u8 pad_0028[0x18];
    u16 unk_0040[3];            /* +0x40: id list, 0-terminated */
} CampStatusInfo;
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
void CampStatus_Unk_0db910(CampStatusInfo *info);
void CampStatus_Unk_0da710(void *obj, const u16 *ids, const u16 *ref, s32 sel);
u8 CampStatus_Unk_0db288(s32 t);
/* Record list returned by func_020a1740: three 6-byte records from +0x48. */
typedef struct CampStatusRecord {
    u16 id;
    u8 pad_02[0x4];
} CampStatusRecord;
typedef struct CampStatusRecordSet {
    u16 unk_0000;
    u8 unk_0002;
    u8 pad_0003;
    u32 unk_0004;               /* +0x04/+0x08: current/max pair shown by CampStatus_Unk_0d9830 */
    u32 unk_0008;
    u16 unk_000c[5];            /* +0x0c: five stats, copied to a CampStatusStats */
    u16 pad_16_0 : 1;           /* +0x16: flags and three small values */
    u16 unk_16_1 : 1;           /* "???" mode for func_020da2cc */
    u16 pad_16_2 : 3;
    u16 unk_16_5 : 4;
    u16 unk_16_9 : 3;
    u16 unk_16_c : 3;
    u16 pad_16_f : 1;
    u8 unk_0018;
    u8 pad_0019;
    u8 unk_001a;
    u8 pad_001b[0x7];
    CampStatusStateWord unk_0022[8];  /* +0x22: per-slot base words for func_020dd364 */
    u8 pad_0032[0x16];
    CampStatusRecord rec[3];
    u8 unk_005a;                /* +0x5a/+0x5b: marks on the 0..100 gauge of CampStatus_Unk_0d9d54 */
    u8 unk_005b;
} CampStatusRecordSet;
/* Work area from Unk02e000_GetWorkArea; only the flag-set word is used here. */
typedef struct CampStatusWorkArea {
    u8 pad_0000[0x358];
    u32 unk_0358;
    u16 unk_035c;               /* +0x35c: flag set id */
    u8 pad_035e[0x6];
    s8 unk_0364;                /* +0x364/+0x365: map position */
    s8 unk_0365;
} CampStatusWorkArea;
extern char data_021507cc[];
extern char data_021507d0[];
extern char data_021507d4[];
extern char data_021507dc[];
extern char data_021507e0[];
extern char data_021507e4[];
extern char data_021507e8[];
void CampStatus_Unk_0db3e0(s32 a, s32 b, s32 c, s32 mode);
extern u32 data_0213c568[];
void func_02057ddc(u32 color);
char *func_020a9e14(int mode, const char *format, ...);
/* Formatted number/text draw: width is a sample string sized by func_020a9e14 (or 0), fmt a
 * printf format ("%d", "%07d", "???") followed by its values. */
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 align, const char *width, u32 size, const char *fmt, ...);
int Unk09974c_Unk_0998d8(u32 id);
int func_0204faf0(u32 a, u32 b);
CampStatusRecordSet *func_020a1740(u16 id);
s32 Unk02e000_GetRecordUnk1e(u32 id);
void Unk0ddeb0_Unk_0ddf0c(void *obj);
CampStatusCell *Unk038fbc_Unk_039160(CampStatusGrid *grid, int x, int y);
CampStatusWorkArea *Unk02e000_GetWorkArea(void);
int Unk0e651c_TestFlag(u32 set, u32 bit);
void Unk0e651c_SetFlag(u32 set, u32 bit, int value);
void ScanVisor_Unk_0a2ab0(void);
void ScanVisor_Unk_0a2ae8(u32 a, int b);
u32 CampStatus_GetUnkField1c(CampStatusWork *work);
u32 CampStatus_GetUnkField7494(CampStatusTableWork *work);
/* Read the 49-byte table at data_0213c60c; an out-of-range index reads entry 0. */
extern u8 data_0213c60c[49];
extern u8 data_021507f4[];
int func_02013c3c();
int func_02051610();
int func_0205b444();
void Unk05b82c_Unk_05b82c();
void func_020ca5a4();
void func_020119a0();
/* Callback table filled by CampStatus_Unk_0d3624. */
typedef struct CampStatusOps {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*fn_0c)();
    void (*fn_10)();
    void (*fn_14)();
    void (*fn_18)();
    void (*fn_1c)();
    void (*fn_20)();
} CampStatusOps;
/* Per-frame (x, y) offset. */
typedef struct CampStatusOffset {
    s8 x;
    s8 y;
} CampStatusOffset;
/* Frame record returned by func_020616c0. */
typedef struct CampStatusFrame {
    s32 index;
    u32 unk_04;
    CampStatusOffset *offsets;
} CampStatusFrame;
/* 12-byte task state run by CampStatus_Unk_0d3510. */
typedef struct CampStatusTimer {
    s32 count;
    s32 limit;
    u32 unk_08;
} CampStatusTimer;
/* Entry returned by func_020a1428. */
typedef struct CampStatusEntry {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;                  /* +0x03: level (see CampStatus_CalcMaxHp) */
    u8 unk_04;
    u8 kind;                    /* +0x05: 4 and 5 get their own colours */
    u8 pad_06[0x4];
    u16 pad_0a_0 : 1;           /* +0x0a: three small values */
    u16 unk_0a_1 : 4;
    u16 unk_0a_5 : 3;
    u16 unk_0a_8 : 3;
    u16 pad_0a_b : 5;
    u8 unk_0c;
    u8 pad_0d;
    u8 unk_0e;
    u8 pad_0f[0xb];
    u8 unk_1a;                  /* +0x1a..+0x1e: the five stats, in CampStatusStats order */
    u8 unk_1b;
    u8 unk_1c;
    u8 unk_1d;
    u8 unk_1e;
    u8 pad_1f[0xf];
    u16 unk_002e[6];            /* +0x2e: id list, 0-terminated */
    CampStatusStateWord unk_003a[8];  /* +0x3a: per-slot base words for func_020dd364 */
} CampStatusEntry;
void func_020d5644();
void CampStatus_Unk_0d5d44();
void CampStatus_Unk_0d6120();
void CampStatus_Unk_0d6948();
void CampStatus_Unk_0d6a24();
void func_020d3680();
int func_02061698(void *obj);
CampStatusFrame *func_020616c0(void *obj);
void func_020614b0(u32 *handle);
void *func_020611dc();
void func_020615ec(u32 *handle, void *task);
s32 Unk06ae94_Unk_06aeec(void *obj);
u32 Unk06ae94_Unk_06aed4(void *obj);
void Unk09d060_Unk_09d170(void *task);
void CampStatus_Unk_0dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n);
void Unk065e88_SetFlag3a(CampStatusObj *obj, int value);
void func_0205cac0(CampStatusLink *link);
void func_0205c6f8(CampStatusLink *link);
CampStatusEntry *func_020a1428(int id);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
u32 func_020445f4(u32 a, u32 b);
void func_02063920(void);
u32 func_0204fed8(u32 tab, u32 id);
u32 func_02063a30(u32 v);
void func_02061f10();
int func_02053824(u32 player, u32 mask);
int func_02053800(u32 player, u32 mask);
void Unk0a0ce4_Unk_0a0da4(u32 se);
int Unk0e8228_IsSet_data_02176cdc(void);
int Unk0e7ac4_Unk_0e8060(void);
void Unk0e7ac4_Unk_0e8198(void);
void CampStatus_Unk_0dbf6c(CampStatusWork *work);
void CampStatus_Unk_0dc540(CampStatusWork *work);
void CampStatus_Unk_0db548(CampStatusWork *work);
void CampStatus_Unk_0dba84(CampStatusWork *work, u16 id);
extern u8 data_02150824[];
int CampStatus_GetTableByte();
int Unk0e651c_Unk_0e666c(u32 flag);
/* 24-byte draw record copied out of func_0205e318 and passed to func_0205e048. */
typedef struct CampStatusDrawParam {
    u32 unk_00;
    u32 unk_04;
    s16 unk_08;
    s16 unk_0a;                 /* +0x0a: y, moved by the scrollbar in CampStatus_Unk_0d6120 */
    s16 unk_0c;
    s16 unk_0e;                 /* +0x0e: height, set by the scrollbar in CampStatus_Unk_0d6120 */
    u32 pad_10_0 : 2;
    u32 alpha : 8;              /* +0x10 bits 2..9: overlay alpha set by CampStatus_Unk_0d9d54 */
    u32 pad_10_a : 22;
    u32 unk_14;
} CampStatusDrawParam;
int Unk02ee5c_GetRecordFlagB(u16 id);
void *func_0205e318(u32 obj, u32 idx);
void func_02008904(const void *src, void *dst, u32 size);
void func_0205e048(int screen, u32 obj, CampStatusDrawParam *param, int x, int y, float sx, float sy, int rot, float alpha, int prio, int a);
/* Eight icon ids copied from data_0213c5b0. */
typedef struct CampStatusIds8 {
    u32 v[8];
} CampStatusIds8;
extern const CampStatusIds8 data_0213c5b0;
u32 Unk0c855c_Unk_0ca690(u32 id);
/* Draw the five stat rows (order +4, +8, +5, +6, +7) via func_020dab5c, with the add values
 * when add is given. The first time all ten shown values equal unk_0118, set unk_0114 and
 * call func_020bc9f4(3, 0) / func_020bcacc(unk_0014, 0). */
void CampStatus_Unk_0da0e0(CampStatusWork *work, const CampStatusStats *cur, const CampStatusStats *next,
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
}
void CampStatus_Unk_0db824(CampStatusWork *work);
void CampStatus_Unk_0dba84(CampStatusWork *work, u16 id);
void CampStatus_Unk_0dbbbc(CampStatusWork *work, u16 id);
void CampStatus_Unk_0dbd04(CampStatusWork *work, u32 id);
void CampStatus_Unk_0dbdac(CampStatusWork *work, u32 id);
void CampStatus_Unk_0dbf24(CampStatusWork *work, u32 id);
/* Like func_020dc240 for record unk_00da: its entry byte on unk_00bc, the id on unk_00c0, and
 * the id list func_020a18c8 writes to unk_00dc (up to 6) on unk_00c4. */
/* Like func_020dc2ec, but needs the saved record for unk_00da; the id list comes from the
 * entry (+0x2e) when unk_025c is set, else from the saved record (+0x10). */
int Unk0a23f4_Unk_0a246c(void);
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
void GameState_ClearRootUnk60(void);
s32 func_020dd364(CampStatusStateWord w, const u16 *ids, s32 kind);
u32 func_020b8144(u16 id, u8 level);
void CampStatus_Unk_0da670(u32 a, u32 b);
void CampStatus_Unk_0da0e0(CampStatusWork *work, const CampStatusStats *cur, const CampStatusStats *next,
                           const CampStatusStats *add, u32 arg5);
void func_020da2cc(s32 hp, s32 mp, const s16 *ref, const s16 *max, const s16 *prev, s32 mode);
void CampStatus_Unk_0ddb9c(int id);

/* Read the unidentified work word at +0x1c; no caller evidence for a better name. */
u32 CampStatus_GetUnkField1c(CampStatusWork *work) { return work->unk_001c; }

int CampStatus_GetTableByte(u32 i)
{
    if (i >= 49) {
        i = 0;
    }
    return data_0213c60c[i];
}

/* Read the cached word at +0x7494 (shape only; purpose not evidenced). */
u32 CampStatus_GetUnkField7494(CampStatusTableWork *work)
{
  return work->unk_7494;
}

/* decompiler-derived */
int CampStatus_Unk_0d34e4(int *arg0,int arg1)
{
  if (arg1 < arg0[7]) {
    return *arg0 + *(int *)(arg0[6] + arg1 * 4) * 2;
  }
  return 0;
}

/* decompiler-derived */
void CampStatus_Unk_0d3510(int *arg0)
{
  int value;
  value = *arg0;
  *arg0 = value + 1;
  if (value + 1 < arg0[1]) {
    return;
  }
  arg0[2] = 0;
  func_02061424();
}

/* Start a 12-byte CampStatus_Unk_0d3510 task for obj and return the handle from func_020614b0. */
u32 CampStatus_Unk_0d353c(void *obj)
{
    u32 handle;
    CampStatusTimer *t;
    func_020614b0(&handle);
    t = func_020611dc(CampStatus_Unk_0d3510, 0, 0, 0, 12, 0, 0, 0);
    if (t != 0) {
        t->count = 0;
        t->limit = Unk06ae94_Unk_06aeec(obj);
        t->unk_08 = Unk06ae94_Unk_06aed4(obj);
        Unk09d060_Unk_09d170(t);
        func_020615ec(&handle, t);
    }
    return handle;
}

/* Read the current (x, y) offset pair of obj's frame, if it has one. Returns 0 when
 * func_02061698 says obj is not active (outputs stay 0), otherwise 1. */
int CampStatus_Unk_0d35c0(void *obj, s32 *x, s32 *y)
{
    CampStatusFrame *f;
    *x = 0;
    *y = 0;
    if (func_02061698(obj) == 0) {
        return 0;
    }
    f = func_020616c0(obj);
    if (f->offsets != 0) {
        CampStatusOffset *o = &f->offsets[f->index];
        *x = o->x;
        *y = o->y;
    }
    return 1;
}

/* Fill the module's callback table: work size 620, then the six handlers (0x0c..0x20). */
void CampStatus_Unk_0d3624(CampStatusOps *o)
{
    o->size = 620;
    o->unk_04 = 4;
    o->fn_0c = func_020d5644;
    o->fn_10 = CampStatus_Unk_0d5d44;
    o->fn_14 = CampStatus_Unk_0d6120;
    o->fn_18 = CampStatus_Unk_0d6948;
    o->fn_1c = CampStatus_Unk_0d6a24;
    o->fn_20 = func_020d3680;
}

void CampStatus_Unk_0d51cc(void)
{
    int i;
    for (i = 59; i <= 64; i++) {
        Unk05b82c_Unk_05b82c(i);
    }
    func_020ca5a4(0);
    func_020ca5a4(2);
}

/* Handler 0x10 of the CampStatus_Unk_0d3624 table: per-frame input. With unk_00e8 set, move
 * the 3x2 cursor unk_00f0 (keys 0x40/0x80 change rows except in modes 1 and 18, 0x20/0x10
 * columns) and confirm with 0x800 or 2; otherwise (unk_01a0 and unk_00f8 set) move between the
 * two columns of the record and confirm with 0x400 or 2. */
void CampStatus_Unk_0d5d44(CampStatusWork *work)
{
    CampStatusRequest req;
    u32 ids[6];
    s8 old;
    s32 i;
    u32 n;
    if (work->unk_00f4 == 0) {
        return;
    }
    if (work->unk_01a4 != 0) {
        work->unk_01a4 = 0;
        return;
    }
    if (work->unk_00e8 != 0) {
        old = work->unk_00f0;
        if (work->unk_0000 != 1 && work->unk_0000 != 18) {
            if (func_02053824(0, 0x40)) {
                work->unk_00f0 -= 3;
                if (work->unk_00f0 < 0) {
                    work->unk_00f0 += 6;
                }
            } else if (func_02053824(0, 0x80)) {
                work->unk_00f0 += 3;
                if (work->unk_00f0 > 5) {
                    work->unk_00f0 -= 6;
                }
            }
        }
        if (func_02053824(0, 0x20)) {
            work->unk_00f0--;
            if (work->unk_00f0 < 0 || work->unk_00f0 == 2) {
                work->unk_00f0 += 3;
            }
        } else if (func_02053824(0, 0x10)) {
            work->unk_00f0++;
            if (work->unk_00f0 == 3 || work->unk_00f0 == 6) {
                work->unk_00f0 -= 3;
            }
        }
        if (old != work->unk_00f0) {
            work->unk_0008 = 1;
            CampStatus_Unk_0dbf6c(work);
            Unk0a0ce4_Unk_0a0da4(0);
            return;
        }
        if (func_02053800(0, 0x800) == 0 && func_02053800(0, 2) == 0) {
            return;
        }
        for (i = 0; i < 2; i++) {
            req.flags[i] = 0;
        }
        for (i = 0; i < 16; i++) {
            req.values[i] = 0;
        }
        req.values[0] = 3;
        req.flags[0] |= 1;
        work->unk_00e8 = 0;
        func_020bc9f4(3, &req);
        func_020bcacc(work->unk_0014, &req);
        work->unk_0004 = 0;
        CampStatus_Unk_0db548(work);
        work->unk_0004 = 1;
        Unk0a0ce4_Unk_0a0da4(10);
        if (work->unk_0268 != 0) {
            Unk065e88_SetFlag3a(work->unk_0024[21], 1);
        }
        if (Unk0e8228_IsSet_data_02176cdc() == 0) {
            return;
        }
        if (Unk0e7ac4_Unk_0e8060() != 0) {
            return;
        }
        Unk0e7ac4_Unk_0e8198();
        return;
    }
    if (work->unk_01a0 == 0 || work->unk_00f8 == 0) {
        return;
    }
    old = work->unk_00f0;
    if (func_02053824(0, 0x20)) {
        work->unk_00f0--;
        if (work->unk_00f0 < 0 || work->unk_00f0 == 2) {
            work->unk_00f0 += 3;
        }
    } else if (func_02053824(0, 0x10)) {
        work->unk_00f0++;
        if (work->unk_00f0 == 3 || work->unk_00f0 == 6) {
            work->unk_00f0 -= 3;
        }
    }
    if (old != work->unk_00f0) {
        work->unk_0008 = 1;
        CampStatus_Unk_0dc540(work);
        Unk0a0ce4_Unk_0a0da4(0);
        return;
    }
    if (func_02053800(0, 0x400) == 0 && func_02053800(0, 2) == 0) {
        return;
    }
    work->unk_01a0 = 0;
    work->unk_00f8 = 0;
    work->unk_010c = 60;
    func_02008644(0, work->unk_00dc, 12);
    if (func_020a18c8(work->unk_00da, work->unk_00dc, 6) != 0) {
        for (n = 0; n < 6; n++) {
            if (work->unk_00dc[n] == 0) {
                break;
            }
            ids[n] = work->unk_00dc[n];
        }
        CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, n);
    }
    CampStatus_Unk_0dba84(work, work->unk_00da);
    Unk0a0ce4_Unk_0a0da4(10);
    Unk0e7ac4_Unk_0e8198();
}

/* Handler 0x18 of the CampStatus_Unk_0d3624 table: when unk_018c is set and func_020523a8()
 * is 1, draw six grey gradient bars (frame 0, 32 px apart), then run CampStatus_Unk_0d6120. */
void func_02057524(u32 v);
void func_02057534(void);
u32 func_020ddf7c(s32 t);
s32 func_02061a04(u32 a, const u16 *text, u32 c);
void CampStatus_Unk_0d78bc(CampStatusWork *work);
void func_020d80cc(CampStatusWork *work, CampStatusUnit *unit);
void CampStatus_Unk_0d8e3c(CampStatusWork *work);
void CampStatus_Unk_0d9388(CampStatusWork *work, CampStatusUnit *unit);
void CampStatus_Unk_0d9830(CampStatusWork *work);
void CampStatus_Unk_0d6e10(CampStatusWork *work);
void CampStatus_Unk_0d71bc(CampStatusWork *work);
void CampStatus_Unk_0d730c(CampStatusWork *work);
void CampStatus_Unk_0d7680(CampStatusWork *work);
void CampStatus_Unk_0d8d60(CampStatusWork *work);
void CampStatus_Unk_0d9d54(u16 id);
void CampStatus_Unk_0ddb9c(int id);
/* Handler 0x14 of the CampStatus_Unk_0d3624 table: draw the screen. Common frame and the two
 * optional tabs (unk_01a8), then the page for the screen mode in unk_0000, then the title text
 * on unk_00b8 (centred in 108 px unless unk_0268 pins it at unk_010e). */
void CampStatus_Unk_0d6120(CampStatusWork *work)
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
        if (work->unk_0008 != 0 && work->unk_00e8 == 0) {
            func_02057df8();
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
        }
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
            CampStatus_Unk_0d8e3c(work);
            CampStatus_Unk_0d9d54(work->unk_00da);
        } else
        if (work->unk_0008 != 0 && work->unk_00e8 == 0) {
            func_02057df8();
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
        }
        break;
    case 21:
        CampStatus_Unk_0d6e10(work);
        CampStatus_Unk_0d730c(work);
        if (work->unk_00f4 == 0) {
            break;
        }
        if (work->unk_0004 != 0 && work->unk_00cc->unk_0036 != 0) {
            CampStatus_Unk_0d9388(work, work->unk_00cc);
            CampStatus_Unk_0d9d54(work->unk_00cc->unk_0036);
        } else
        if (work->unk_0008 != 0 && work->unk_00e8 == 0) {
            func_02057df8();
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
        }
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
        if (work->unk_0008 != 0 && work->unk_00e8 == 0) {
            func_02057df8();
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
            Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
        }
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
}

void CampStatus_Unk_0d6948(CampStatusWork *work)
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
    CampStatus_Unk_0d6120(work);
}

/* Handler 0x1c of the CampStatus_Unk_0d3624 table: release everything the screen created
 * (resources, objects, both bust-ups, the six text objects) and unload groups 14, 13, 10. */
void CampStatus_Unk_0d6a24(CampStatusWork *work)
{
    int i;
    for (i = 59; i <= 64; i++) {
        func_0205bb68();
    }
    if (work->unk_0018 != 0) {
        func_0205ddb4(work->unk_0018);
        work->unk_0018 = 0;
    }
    if (work->unk_0020 != 0) {
        func_0205c368(work->unk_0020);
        work->unk_0020 = 0;
    }
    if (work->unk_018c != 0) {
        func_0205bb68();
        if (work->unk_001c != 0) {
            func_0205ddb4(work->unk_001c);
            work->unk_001c = 0;
        }
    }
    func_02061424(work->unk_0024[2]);
    work->unk_0024[2] = 0;
    func_02061424(work->unk_0024[18]);
    work->unk_0024[18] = 0;
    for (i = 11; i <= 17; i++) {
        func_02061424(work->unk_0024[i]);
        work->unk_0024[i] = 0;
    }
    func_02061424(work->unk_0024[21]);
    work->unk_0024[21] = 0;
    if (work->unk_007c != 0) {
        func_0205c3dc(work->unk_007c);
        work->unk_007c = 0;
    }
    if (work->unk_0080 != 0) {
        func_0205ddb4(work->unk_0080);
        work->unk_0080 = 0;
    }
    func_0205bb68();
    Unk0c855c_Unk_0ca648(0);
    Unk0c855c_Unk_0ca648(2);
    func_0205bb68();
    func_02053000(work->unk_0084[0].tex);
    work->unk_0084[0].tex = 0;
    if (work->unk_0084[0].res != 0) {
        func_0205ddb4(work->unk_0084[0].res);
        work->unk_0084[0].res = 0;
    }
    if (work->unk_0084[0].anim != 0) {
        func_0205c368(work->unk_0084[0].anim);
        work->unk_0084[0].anim = 0;
    }
    func_02061424(work->unk_0084[0].obj);
    work->unk_0084[0].obj = 0;
    func_0205bb68();
    func_02053000(work->unk_0084[1].tex);
    work->unk_0084[1].tex = 0;
    if (work->unk_0084[1].res != 0) {
        func_0205ddb4(work->unk_0084[1].res);
        work->unk_0084[1].res = 0;
    }
    if (work->unk_0084[1].anim != 0) {
        func_0205c368(work->unk_0084[1].anim);
        work->unk_0084[1].anim = 0;
    }
    func_02061424(work->unk_0084[1].obj);
    work->unk_0084[1].obj = 0;
    func_020629c4(work->unk_00b4);
    if (work->unk_00b4 != 0) {
        work->unk_00b4 = 0;
    }
    func_020629c4(work->unk_00b8);
    if (work->unk_00b8 != 0) {
        work->unk_00b8 = 0;
    }
    func_020629c4(work->unk_00bc);
    if (work->unk_00bc != 0) {
        work->unk_00bc = 0;
    }
    func_020629c4(work->unk_00c0);
    if (work->unk_00c0 != 0) {
        work->unk_00c0 = 0;
    }
    func_020629c4(work->unk_00c4);
    if (work->unk_00c4 != 0) {
        work->unk_00c4 = 0;
    }
    func_020629c4(work->unk_00c8);
    if (work->unk_00c8 != 0) {
        work->unk_00c8 = 0;
    }
    Unk044394_Unk_044534(14);
    Unk044394_Unk_044534(13);
    Unk044394_Unk_044534(10);
}

void CampStatus_Copy12c(void *src)
{
    func_020119a0((u8 *)data_02176be4 + 300, src, 60);
}

/* Copy six byte pairs into the shared work at +0x168. */
void CampStatus_Copy168(const CampStatusPairs6 *src)
{
    data_02176be4->unk_0168 = *src;
}

/* Copy five byte pairs into the shared work at +0x176. */
void CampStatus_Copy176(const CampStatusPairs5 *src)
{
    data_02176be4->unk_0176 = *src;
}

/* Load bust-up texture "st_bu_en%03d" (data_021507f4) number n into b->tex and bind it to
 * b->unk_08 (func_0205b444). Always returns 1. */
u32 CampStatus_Unk_0db338(CampStatusBustUp *b, u32 n)
{
  char path[64];
  func_02013c3c(path, data_021507f4, n);
  b->tex = func_02051610(path);
  func_0205b444(b->unk_08, b->tex);
  return 1;
}

/* Same for "st_bu_mt%03d" (data_02150824), numbered through CampStatus_GetTableByte(i). */
u32 CampStatus_Unk_0db394(CampStatusBustUp *b, u32 i)
{
  char path[64];
  func_02013c3c(path, data_02150824, CampStatus_GetTableByte(i));
  b->tex = func_02051610(path);
  func_0205b444(b->unk_08, b->tex);
  return 1;
}

/* decompiler-derived */
int CampStatus_Unk_0dd88c(int arg0,int arg1)
{
  int tmp1;
  tmp1 = arg0;
  if ((arg1 == 2) && (arg0 == 0 || arg0 == 2)) {
    tmp1 = 2;
  }
  if ((arg1 == 5) && ((arg0 == 0 || arg0 == 2) || arg0 == 5)) {
    tmp1 = 5;
  }
  if ((arg1 == 1) && (((arg0 == 0 || arg0 == 2) || arg0 == 5) || arg0 == 1)) {
    tmp1 = 1;
  }
  if ((arg1 == 3) &&
     ((((arg0 == 0 || arg0 == 2) || arg0 == 5) || arg0 == 1) || arg0 == 3)) {
    tmp1 = 3;
  }
  if ((arg1 == 4) && (arg0 != 4)) {
    tmp1 = 4;
  }
  return tmp1;
}

/* decompiler-derived: frames 0x10..0x12 of obj at (x, 0), alpha a. */
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

int CampStatus_IsUnkF4F8Set(void)
{
    CampStatusWork *w = data_02176be4;
    return w->unk_00f4 != 0 && w->unk_00f8 != 0;
}

/* Read the unidentified word at +0x1a8 in the shared work. */
u32 CampStatus_GetUnk1a8(void)
{
    return data_02176be4->unk_01a8;
}

/* Write the unidentified word at +0x1a8 in the shared work. */
void CampStatus_SetUnk1a8(u32 value)
{
    data_02176be4->unk_01a8 = value;
}

/* Read the unidentified word at +0x258 in the shared work. */
u32 CampStatus_GetUnk258(void)
{
    return data_02176be4->unk_0258;
}

/* Raise the mode flag at +0x260; see CampStatus_ResetAnim for the clear. */
void CampStatus_SetUnk260(void)
{
    data_02176be4->unk_0260 = 1;
}

void CampStatus_ResetAnim(void)
{
    data_02176be4->unk_0260 = 0;
    data_02176be4->unk_0084[0].obj->unk_0028 = -1;
    data_02176be4->unk_0084[0].obj->scale = 1.0f;
}

void CampStatus_SetUnk240(u8 a, u8 b)
{
    data_02176be4->unk_0240 = a;
    data_02176be4->unk_0241 = b;
}

void CampStatus_GetLinkUnk14(u32 *out)
{
    *out = data_02176be4->unk_0024[2]->link->unk_0014;
}

/* Draw the main status panel: frames 5, 7, 8, 12-14 and the eight icons of data_0213c5b0 at
 * x unk_00fe, the five row frames 15-19 at x unk_0100[0..4], frame 33 at y unk_010c, then the
 * five row labels of unk_00b4. */
void CampStatus_Unk_0d6e10(CampStatusWork *work)
{
    CampStatusIds8 icons;
    int i;
    func_02057fd8();
    func_02057df8();
    func_0205dee8(2, work->unk_0018, 5, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_02057e18(31);
    func_0205dee8(2, work->unk_0018, 7, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 8, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 12, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 13, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_02057e18(31);
    func_0205dee8(2, work->unk_0018, 14, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    icons = data_0213c5b0;
    for (i = 0; i < 8; i++) {
        func_02058e9c(2, Unk0c855c_Unk_0ca690(icons.v[i]), work->unk_00fe + (i * 14 + 5), 53, work->unk_0110, 0, 3);
    }
    func_0205dee8(2, work->unk_0018, 15, work->unk_0100[0], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 16, work->unk_0100[1], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 17, work->unk_0100[2], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 18, work->unk_0100[3], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 19, work->unk_0100[4], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 33, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_02057e18(31);
    func_02057fd8();
    for (i = 0; i <= 4; i++) {
        Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, work->unk_0100[i] + 4, i * 11 + 82, i, 2, 10);
    }
}

/* Draw the top panel (frames 53, 50-52 when unk_01a0 is set, else 34-39) at y unk_010c, then,
 * when unk_0004 is set (and not mode 3 with unk_0264 set), frames 26/27 at x unk_010a and
 * frame 67 when flag 0x706 is set. */
void CampStatus_Unk_0d730c(CampStatusWork *work)
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
}

/* Draw the labels on unk_00c0 (grey when Unk09974c_Unk_0998d8(unk_00d0) is 0), the list on
 * unk_00c4 (CampStatus_Unk_0da710, selection unk_00f0 when unk_00e8 is set, else -1) and, when unk_0008
 * is set, two more labels on unk_00c8. */
extern char data_02150758[];
extern char data_0215075c[];
extern char data_02150760[];
extern char data_02150768[];
u32 func_020b80c8(u8 level);
s32 Unk09974c_Unk_099cc4(CampStatusInfo *info);
void CampStatus_Unk_0dd910(void);
void CampStatus_Unk_0db478(u32 obj, u32 obj2, u32 idx);
void CampStatus_Unk_0da97c(u32 obj, s32 a, s32 b, s32 mode, u8 slot);
void CampStatus_Unk_0da8c4(void *obj, const u16 *ids, s32 sel);
CampStatusStateWord CampStatus_Unk_0dd500(const u16 *ids, s32 i, s32 extra);
/* Player page (modes 1, 14, 18): stats and HP/MP against the compared values (mode 14: base
 * vs current vs unk_0180, mode 18: current vs candidate), level line, the attack/defence lines
 * with the item bonuses, the eight slot states (mode 18 marks changed ones in orange) and the
 * id grid. */
void CampStatus_Unk_0d78bc(CampStatusWork *work)
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
}

void CampStatus_Unk_0d8d60(CampStatusWork *work)
{
    if (Unk09974c_Unk_0998d8(work->unk_00d0) == 0) {
        func_02057ddc(0x7b7b7bff);
    } else {
        func_02057df8();
    }
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 14, 0, 8, 10);
    func_02057df8();
    CampStatus_Unk_0da710(work->unk_00c4, work->unk_00d2, 0, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
    if (work->unk_0008 == 0) {
        return;
    }
    func_02057df8();
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
}

/* Record page (mode 3): stats and value bars of record unk_00da, its level line, the eight
 * slot states (or "???" icons while the gauge is below unk_005b), and either the three record
 * entries with the pulsing cursor (unk_01a0 set), the empty grid, or the id grid. */
/* Growth data returned (by value) from func_020b8804 for a unit id. */
typedef struct CampStatusBase {
    u8 hpRate;                  /* +0x00: percent of (Vi * 3) added to max HP */
    u8 mpRate;                  /* +0x01: percent of (Ma * 2) added to max MP */
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 hpBase;                 /* +0x08 */
    u16 mpBase;                 /* +0x0a */
} CampStatusBase;
CampStatusBase func_020b8804(u16 id);
void func_0209835c(CampStatusStats *stats, const u16 *ids);

/* Max HP for a level and Vi stat (capped at 999). Shared by the unit pages; the formula is
 * read from CampStatus_Unk_0d8e3c / CampStatus_Unk_0d9388 (hpBase + 6 per level + hpRate% of Vi * 3). */
static inline u16 CampStatus_CalcMaxHp(u8 level, u8 vi, CampStatusBase base)
{
    u16 r;
    s32 v = base.hpBase + (level * 6 + base.hpRate * (vi * 3) / 100);
    if (v > 999) {
        r = 999;
    } else {
        r = v;
    }
    return r;
}

/* Max MP for a level and Ma stat (capped at 999): mpBase + 3 per level + mpRate% of Ma * 2. */
static inline u16 CampStatus_CalcMaxMp(u8 level, u8 ma, CampStatusBase base)
{
    u16 r;
    s32 v = base.mpBase + (level * 3 + base.mpRate * (ma * 2) / 100);
    if (v > 999) {
        r = 999;
    } else {
        r = v;
    }
    return r;
}
extern char data_02150794[];
extern char data_02150798[];
extern char data_0215079c[];
extern char data_021507a4[];
/* Unit page (mode 20): stats, HP/MP bars and level line of unit unk_00da, from its entry
 * (unk_025c set) or from its saved record, then the eight slot states and the id grid. */
void CampStatus_Unk_0d8e3c(CampStatusWork *work)
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
}

/* Unit compare page (mode 21): the unit's stats against its saved record (max HP/MP from
 * CampStatus_CalcMaxHp/Mp, current HP/MP clamped to the new maxima), level and exp lines
 * coloured by the change, and the eight slot states (changed ones in orange). */
void CampStatus_Unk_0d9388(CampStatusWork *work, CampStatusUnit *unit)
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
}

void CampStatus_Unk_0d9830(CampStatusWork *work)
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
        CampStatus_Unk_0da710(work->unk_00c4, work->unk_00dc, 0, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
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
}

/* Draw the 0..100 gauge of record id as a 60-pixel bar (value * 6 / 10) split at the two
 * marks unk_005a/unk_005b (pieces 0x1dc1..0x1dc3, mark ticks 0x1dc4), or the full-gauge frame
 * 32 at 100. With flag 0x706 and Unk02ee5c_GetRecordFlagB(id), add frame 69 and the blinking
 * overlay (alpha ramp over a 28-tick cycle). */
void CampStatus_Unk_0d9d54(u16 id)
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
}

/* Draw two numbers (a at x 24, b at x 86, y 27) with func_020a9fd8, after resetting the colour. */
void CampStatus_Unk_0da670(u32 a, u32 b)
{
    func_02057df8();
    func_020a9fd8(1, 24, 27, 2, func_020a9e14(1, data_021507cc), 10, data_021507d0, a);
    func_020a9fd8(1, 86, 27, 2, func_020a9e14(1, data_021507d4, 0), 10, data_021507dc, b);
}

/* Draw the six slots of a 3x2 grid on obj (x 4 + 85 * col, y 140 + 13 * row) with a pulsing
 * cursor at sel when sel >= 0. With ref, each ref id not found in ids is drawn in orange
 * (0xff942100); empty slots are skipped. */
void CampStatus_Unk_0da710(void *obj, const u16 *ids, const u16 *ref, s32 sel)
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
}

/* When sel >= 0, draw the pulsing cursor bar at row sel (85 px per row, alpha from the
 * CampStatus_Unk_0db288 ramp); then draw the three slots of obj. */
void CampStatus_Unk_0da8c4(void *obj, const u16 *ids, s32 sel)
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
}

/* Draw value b (mode 1) or a (other modes) in slot `slot` with the compare colour from
 * CampStatus_Unk_0db3e0; in mode 1 a bobbing arrow (frame 48 up / 49 down, 24-tick cycle)
 * shows whether b is above or below a. */
void CampStatus_Unk_0da97c(u32 obj, s32 a, s32 b, s32 mode, u8 slot)
{
    char *width = func_020a9e14(1, data_021507e0);
    CampStatus_Unk_0db3e0(a, b, 0, mode);
    if (mode == 1) {
        func_020a9fd8(1, slot * 85 + 64, 143, 2, width, 10, data_021507e4, b);
        if (b > a) {
            s32 t = data_0215f05c.unk_0018 % 24;
            s32 dy;
            if (t < 6) {
                dy = 0;
            } else if (t < 12) {
                dy = -1;
            } else if (t < 18) {
                dy = -2;
            } else {
                dy = -1;
            }
            func_0205dee8(2, obj, 48, slot * 85, dy, 1.0f, 1.0f, 0, 1.0f, 4);
        } else if (b < a) {
            s32 t = data_0215f05c.unk_0018 % 24;
            s32 dy;
            if (t < 6) {
                dy = -2;
            } else if (t < 12) {
                dy = -1;
            } else if (t < 18) {
                dy = 0;
            } else {
                dy = -1;
            }
            func_0205dee8(2, obj, 49, slot * 85, dy, 1.0f, 1.0f, 0, 1.0f, 4);
        }
    } else {
        func_020a9fd8(1, slot * 85 + 64, 143, 2, width, 10, data_021507e8, a);
    }
    func_02057df8();
}

/* Triangle-ish ramp over a 120-tick period: 11 rising to 31 over ticks 0..45, hold 31 to 74,
 * then fall back (4.12 fixed point, slope 0x71c). */
u8 CampStatus_Unk_0db214(s32 t)
{
    s32 r = t % 120;
    s32 v = 0xb000;
    if (r <= 45) {
        v += r * 0x71c;
        return v >> 12;
    }
    if (r < 75) {
        return 31;
    }
    v += 0x14000 - (r - 75) * 0x71c;
    return v >> 12;
}

/* Ramp over a 50-tick period: 31 falling to 16 over ticks 0..40, then back up (4.12 fixed point). */
u8 CampStatus_Unk_0db288(s32 t)
{
    s32 r = t % 50;
    s32 v = 0x1f000;
    if (r <= 40) {
        v -= r * 0x600;
    } else {
        v -= 0xf000 - (r - 40) * 0x1800;
    }
    return v >> 12;
}

/* Ramp over a 40-tick period: 18 rising to 31 over ticks 0..10, then falling (4.12 fixed point). */
u8 CampStatus_Unk_0db2dc(s32 t)
{
    s32 r = t % 40;
    s32 v;
    if (r <= 10) {
        v = 0x12000;
        v += r * 0x13d7;
    } else {
        v = 0x1f000 - (r - 10) * 0x6ee;
    }
    return v >> 12;
}

/* Set the text colour for a compared value: mode 1 compares b against a, mode 3 b against c
 * (green 0x8cff4a00 when larger, red 0xff290000 when smaller), mode 2 is green when c > 0.
 * Equal values (and other modes) keep the default colour from func_02057df8. */
void CampStatus_Unk_0db3e0(s32 a, s32 b, s32 c, s32 mode)
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
}

/* For a non-zero idx: draw frame 6 of obj, the resource for Unk0ddeb0_Unk_0ddfd8(idx) at
 * (109, 13), and frame data_0213c600[idx] of obj2. */
void CampStatus_Unk_0db478(u32 obj, u32 obj2, u32 idx)
{
    if (idx == 0) {
        return;
    }
    func_0205dee8(2, obj, 6, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    func_02057e18(31);
    func_02057df8();
    func_02058e9c(2, Unk0ca69c_Unk_0ca6a4(Unk0ddeb0_Unk_0ddfd8(idx)), 109, 13, 1.0f, 0, 3);
    func_0205de40(2, obj2, data_0213c600[idx], 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
}

/* Refresh the icon line on unk_00c8 for the current screen mode: with unk_024a < 0 only the
 * placeholder icons (CampStatus_Unk_0dbf24) or a clear; otherwise the per-mode detail
 * helpers. */
void CampStatus_Unk_0db548(CampStatusWork *work)
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
}

/* For both player ids (+0x00, +0x02): pick icon 1/0 (resp. 3/2) by whether the record's two
 * nibbles differ and run CampStatus_Unk_0db910 on it; show both icons on unk_00c8 only when both ids
 * are set, else clear it. */
void CampStatus_Unk_0db824(CampStatusWork *work)
{
    u32 icons[2] = {0, 0};
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    CampStatusInfo *info;
    if (p->unk_0000[0] != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000[0])) != 0) {
        if (info->lo != info->hi) {
            icons[0] = 1;
        } else {
            icons[0] = 0;
        }
        CampStatus_Unk_0db910(info);
    }
    if (p->unk_0000[1] != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000[1])) != 0) {
        if (info->lo != info->hi) {
            icons[1] = 3;
        } else {
            icons[1] = 2;
        }
        CampStatus_Unk_0db910(info);
    }
    if (p->unk_0000[0] != 0 && p->unk_0000[1] != 0) {
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, icons, 2);
        return;
    }
    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
}

/* Push info's values into the slots via func_0204fcb0/func_0204faf0: entries of groups (14, 1),
 * (14, 2) and (14, 3) go to slots 1-3 when unk_0002 is 3 and to slots 4-6 when it is 4; the
 * nibbles go through func_0204faf0 (the high one only when it differs). */
void CampStatus_Unk_0db910(CampStatusInfo *info)
{
    u32 v;
    if (info == 0) {
        return;
    }
    v = func_0204fed8(func_020445f4(14, 1), info->unk_0009);
    if (info->unk_0002 == 3) {
        func_0204fcb0(1, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(4, v);
    }
    if (info->unk_0002 == 3) {
        func_0204faf0(1, info->lo);
        if (info->lo != info->hi) {
            func_0204faf0(2, info->hi);
        }
    }
    if (info->unk_0002 == 4) {
        func_0204faf0(3, info->lo);
        if (info->lo != info->hi) {
            func_0204faf0(4, info->hi);
        }
    }
    v = func_0204fed8(func_020445f4(14, 2), info->unk_04_20);
    if (info->unk_0002 == 3) {
        func_0204fcb0(2, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(5, v);
    }
    v = func_0204fed8(func_020445f4(14, 3), info->unk_000b);
    if (info->unk_0002 == 3) {
        func_0204fcb0(3, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(6, v);
    }
}

/* Fill slots 1-5 from entry id's values (groups (14, 1..4)) and show icon data_0213c568[4] on
 * unk_00c8, or icon 5 when the two 3-bit values at +0x0a differ. */
void CampStatus_Unk_0dba84(CampStatusWork *work, u16 id)
{
    u32 icon = data_0213c568[4];
    CampStatusEntry *e = func_020a1428(id);
    u32 tab = func_020445f4(14, 4);
    func_0204fcb0(4, func_0204fed8(tab, e->unk_04));
    func_0204fcb0(5, func_0204fed8(tab, e->kind));
    func_0204fcb0(1, func_0204fed8(func_020445f4(14, 1), e->unk_0a_1));
    func_0204faf0(1, e->unk_0a_5);
    if (e->unk_0a_5 != e->unk_0a_8) {
        icon = 5;
        func_0204faf0(2, e->unk_0a_8);
    }
    func_0204fcb0(2, func_0204fed8(func_020445f4(14, 2), e->unk_0c));
    func_0204fcb0(3, func_0204fed8(func_020445f4(14, 3), e->unk_0e));
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}

/* Like CampStatus_Unk_0dba84, but slots 1-3 and the icon test come from func_020a1740(id) (+0x16..+0x1a)
 * and the default icon is data_0213c568[1]. */
void CampStatus_Unk_0dbbbc(CampStatusWork *work, u16 id)
{
    u32 icon = data_0213c568[1];
    CampStatusEntry *e = func_020a1428(id);
    CampStatusRecordSet *rs = func_020a1740(id);
    u32 tab = func_020445f4(14, 4);
    func_0204fcb0(4, func_0204fed8(tab, e->unk_04));
    func_0204fcb0(5, func_0204fed8(tab, e->kind));
    func_0204fcb0(1, func_0204fed8(func_020445f4(14, 1), rs->unk_16_5));
    func_0204faf0(1, rs->unk_16_9);
    if (rs->unk_16_9 != rs->unk_16_c) {
        icon = 5;
        func_0204faf0(2, rs->unk_16_c);
    }
    func_0204fcb0(2, func_0204fed8(func_020445f4(14, 2), rs->unk_0018));
    func_0204fcb0(3, func_0204fed8(func_020445f4(14, 3), rs->unk_001a));
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}

/* Show icon data_0213c568[3] on unk_00c8 when Unk09974c_Unk_0998d8(unk_00d0) is 0; otherwise
 * show data_0213c568[0], or 7 after func_0204faf0(10, id) when id is not 0xffff. */
void CampStatus_Unk_0dbd04(CampStatusWork *work, u32 id)
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
}

/* Icons for record id: unk_0002 3 fills the first icon from it and the second from the
 * player's +0x02 record, 4 the other way round (player's +0x00 record); both then go to
 * unk_00c8. Other values fall back to CampStatus_Unk_0db824. */
void CampStatus_Unk_0dbdac(CampStatusWork *work, u32 id)
{
    u32 icons[2] = {0, 0};
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    CampStatusInfo *info = Unk09974c_Unk_099c60(id);
    if (info == 0) {
        return;
    }
    if (info->unk_0002 == 3) {
        if (info->lo != info->hi) {
            icons[0] = 1;
        } else {
            icons[0] = 0;
        }
        CampStatus_Unk_0db910(info);
        if (p->unk_0000[1] != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000[1])) != 0) {
            if (info->lo != info->hi) {
                icons[1] = 3;
            } else {
                icons[1] = 2;
            }
            CampStatus_Unk_0db910(info);
        }
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, icons, 2);
        return;
    }
    if (info->unk_0002 == 4) {
        if (info->lo != info->hi) {
            icons[1] = 3;
        } else {
            icons[1] = 2;
        }
        CampStatus_Unk_0db910(info);
        if (p->unk_0000[0] != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000[0])) != 0) {
            if (info->lo != info->hi) {
                icons[0] = 1;
            } else {
                icons[0] = 0;
            }
            CampStatus_Unk_0db910(info);
        }
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, icons, 2);
        return;
    }
    CampStatus_Unk_0db824(work);
}

/* For ids 8..10 only: show entry id of group (14, 0) on work->unk_00c8 via CampStatus_Unk_0dde3c. */
void CampStatus_Unk_0dbf24(CampStatusWork *work, u32 id)
{
    u32 ids[1];
    if (id < 8) {
        return;
    }
    if (id > 10) {
        return;
    }
    ids[0] = id;
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, ids, 1);
}

/* Pick the id of the selected list entry for the current screen mode (unk_0000) and show it
 * (group 10) on unk_00c8, or clear unk_00c8 when there is none. */
void CampStatus_Unk_0dbf6c(CampStatusWork *work)
{
    CampStatusSavedRecord rec;
    u32 id;
    CampStatusPlayer *p;
    CampStatusInfo *info;
    u8 mode = work->unk_0000;
    if (mode == 1) {
        p = Unk02e000_Thunk_0202e788();
        if (p->unk_0000[1] != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000[1])) != 0) {
            id = info->unk_0040[work->unk_00f0];
        }
    } else if (mode == 18) {
        info = Unk09974c_Unk_099c60(work->unk_0190);
        if (info != 0 && info->unk_0002 == 4) {
            id = info->unk_0040[work->unk_00f0];
        } else {
            p = Unk02e000_Thunk_0202e788();
            if (p->unk_0000[1] != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000[1])) != 0) {
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
}

/* Show icon 43 on unk_00bc, the player's text (+0x48) on unk_00c0, and the 0-terminated id
 * list (up to 3) of the player's second record on unk_00c4. */
void CampStatus_Unk_0dc184(CampStatusWork *work)
{
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    u32 ids[3];
    CampStatusInfo *info;
    u32 i;
    ids[0] = 43;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    func_02061f10(work->unk_00c0, -1, 0, 0, p->unk_0048);
    if (p->unk_0000[1] == 0) {
        return;
    }
    info = Unk09974c_Unk_099c60(p->unk_0000[1]);
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
}

/* Show the unit's entries: the byte at +2 of its func_020a1428 entry on unk_00bc, its id on
 * unk_00c0, and its 0-terminated id list (up to 6) on unk_00c4. */
void CampStatus_Unk_0dc240(CampStatusWork *work)
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
}

/* Like CampStatus_Unk_0dc240 for record unk_00da: its entry byte on unk_00bc, the id on unk_00c0, and
 * the id list func_020a18c8 writes to unk_00dc (up to 6) on unk_00c4. */
void CampStatus_Unk_0dc2ec(CampStatusWork *work)
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
}

/* Like CampStatus_Unk_0dc2ec, but needs the saved record for unk_00da; the id list comes from the
 * entry (+0x2e) when unk_025c is set, else from the saved record (+0x10). */
void CampStatus_Unk_0dc3b8(CampStatusWork *work)
{
    CampStatusSavedRecord rec;
    u32 ids[6];
    CampStatusEntry *e = func_020a1428(work->unk_00da);
    u32 i;
    if (Unk02e000_SetRecord(work->unk_00da, &rec) == 0) {
        return;
    }
    ids[0] = e->unk_02;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    ids[0] = work->unk_00da;
    CampStatus_Unk_0dde3c(work->unk_00c0, 18, 1, ids, 1);
    if (work->unk_025c != 0) {
        for (i = 0; i < 6; i++) {
            if (e->unk_002e[i] == 0) {
                break;
            }
            ids[i] = e->unk_002e[i];
        }
    } else {
        for (i = 0; i < 6; i++) {
            if (rec.unk_0010[i] == 0) {
                break;
            }
            ids[i] = rec.unk_0010[i];
        }
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}

/* On unk_00c4: entry 201 of group (12, 0), then each non-zero record id (up to 3) of
 * func_020a1740(unk_00da) from group (6, 0). */
void CampStatus_Unk_0dc4a8(CampStatusWork *work)
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
}

/* When unk_01a0 is set: show the selected record id (group 7) on unk_00c8 if the record exists
 * and Unk02e000_GetRecordUnk1e(unk_00da) is at least 100, else clear it via Unk0ddeb0_Unk_0ddf0c. */
void CampStatus_Unk_0dc540(CampStatusWork *work)
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
}

/* out = a - b field by field, each clamped at 0. */
void CampStatus_Unk_0dc5dc(const CampStatusStats *a, const CampStatusStats *b, CampStatusStats *out)
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
}

/* Build object [2] and both bust-ups (resource, animation, descriptor, texture, object) in the
 * shared work; objects use mode 0 when unk_018c is set, else 1. With unk_00f4 set, object [2]
 * starts on sequence 2. */
void CampStatus_Unk_0dc6c0(void)
{
    CampStatusDesc desc0;
    CampStatusDesc desc1;
    u32 mode = 1;
    if (data_02176be4->unk_018c != 0) {
        mode = 0;
    }
    data_02176be4->unk_0024[2] = Unk065e88_Call_02065fc0(data_02176be4->unk_0018, data_02176be4->unk_0020, mode, 0);
    if (data_02176be4->unk_00f4 != 0) {
        func_0205c408(data_02176be4->unk_0024[2]->link, 2);
        func_0205c6e0(data_02176be4->unk_0024[2]->link);
        data_02176be4->unk_0024[2]->unk_0030 = 6;
        data_02176be4->unk_0024[2]->unk_0024 = 10;
    }
    data_02176be4->unk_0084[0].res = func_0205dcd4(data_02150854, 0);
    data_02176be4->unk_0084[0].anim = func_0205c2c4(data_0215086c);
    desc0 = data_0213c590;
    data_02176be4->unk_0084[0].unk_08 = func_0205ba28(&desc0, data_02150884, 0x144c);
    func_0205de30(data_02176be4->unk_0084[0].res, 0, data_02176be4->unk_0084[0].unk_08);
    data_02176be4->unk_0084[0].unk_14 = CampStatus_Unk_0db338(&data_02176be4->unk_0084[0], 0);
    data_02176be4->unk_0084[0].obj = Unk065e88_Call_02065fc0(data_02176be4->unk_0084[0].res, data_02176be4->unk_0084[0].anim, mode, 0);
    data_02176be4->unk_0084[0].unk_14 = 0;
    data_02176be4->unk_0084[1].res = func_0205dcd4(data_02150894, 0);
    data_02176be4->unk_0084[1].anim = func_0205c2c4(data_021508ac);
    desc1 = data_0213c5a0;
    data_02176be4->unk_0084[1].unk_08 = func_0205ba28(&desc1, data_021508c4, 0x1458);
    func_0205de30(data_02176be4->unk_0084[1].res, 1, data_02176be4->unk_0084[1].unk_08);
    data_02176be4->unk_0084[1].unk_14 = CampStatus_Unk_0db394(&data_02176be4->unk_0084[1], 0);
    data_02176be4->unk_0084[1].obj = Unk065e88_Call_02065fc0(data_02176be4->unk_0084[1].res, data_02176be4->unk_0084[1].anim, mode, 0);
    data_02176be4->unk_0084[1].unk_14 = 0;
}

/* Release the shared work's resources (two sets of three handles plus three tasks) and clear
 * each field. */
void CampStatus_Unk_0dc908(void)
{
    func_0205bb68();
    func_02053000(data_02176be4->unk_0084[1].tex);
    data_02176be4->unk_0084[1].tex = 0;
    if (data_02176be4->unk_0084[1].res != 0) {
        func_0205ddb4(data_02176be4->unk_0084[1].res);
        data_02176be4->unk_0084[1].res = 0;
    }
    if (data_02176be4->unk_0084[1].anim != 0) {
        func_0205c368(data_02176be4->unk_0084[1].anim);
        data_02176be4->unk_0084[1].anim = 0;
    }
    func_02061424(data_02176be4->unk_0084[1].obj);
    data_02176be4->unk_0084[1].obj = 0;
    func_0205bb68();
    func_02053000(data_02176be4->unk_0084[0].tex);
    data_02176be4->unk_0084[0].tex = 0;
    if (data_02176be4->unk_0084[0].res != 0) {
        func_0205ddb4(data_02176be4->unk_0084[0].res);
        data_02176be4->unk_0084[0].res = 0;
    }
    if (data_02176be4->unk_0084[0].anim != 0) {
        func_0205c368(data_02176be4->unk_0084[0].anim);
        data_02176be4->unk_0084[0].anim = 0;
    }
    func_02061424(data_02176be4->unk_0084[0].obj);
    data_02176be4->unk_0084[0].obj = 0;
    func_02061424(data_02176be4->unk_0024[2]);
    data_02176be4->unk_0024[2] = 0;
}

/* Reset the flag at +0xf4 and the ten s16 values at +0xfc..+0x10e to their start values. */
void CampStatus_Unk_0dca50(CampStatusWork *work)
{
    work->unk_00f4 = 0;
    work->unk_00fc = -12;
    work->unk_00fe = -160;
    work->unk_0100[0] = -224;
    work->unk_0100[1] = -288;
    work->unk_0100[2] = -352;
    work->unk_0100[3] = -416;
    work->unk_0100[4] = -480;
    work->unk_010a = 80;
    work->unk_010c = 60;
    work->unk_010e = 0;
}

void CampStatus_Unk_0dcaac(void)
{
    data_02176be4->unk_00f4 = 0;
    data_02176be4->unk_010e = -80;
}

/* Store on at +0x268, then switch the unk_0078 object on (flag 0x3a set + func_0205cac0, only
 * if not already set) or off (func_0205c6f8 + flag cleared). */
void CampStatus_Unk_0dcad4(s32 on)
{
    CampStatusObj *obj;
    data_02176be4->unk_0268 = on;
    obj = data_02176be4->unk_0024[21];
    if (on != 0) {
        if (obj->flag_3a != 0) {
            return;
        }
        Unk065e88_SetFlag3a(obj, 1);
        func_0205cac0(data_02176be4->unk_0024[21]->link);
        return;
    }
    func_0205c6f8(obj->link);
    Unk065e88_SetFlag3a(data_02176be4->unk_0024[21], 0);
}

void CampStatus_Unk_0dd308(s32 *v, s32 add, int n, s32 *cnt, float *out)
{
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] > 0) {
            v[i] += add;
        }
    }
    if (*cnt >= 10) {
        return;
    }
    (*cnt)++;
    *out = *cnt / 10.0f;
}

/* Set the unidentified flag at +0x250; neutral name kept from symbols.txt. */
void func_020dcb44(void)
{
    data_02176be4->unk_0250 = 1;
}

/* Handler 2 of the table at 0x0213c1d8: look up the cell at (unk_7482, unk_7483); if its 4-bit
 * flag number n is non-zero and work-area flag n + 55 is not set yet, set it, call
 * ScanVisor_Unk_0a2ab0 and start the 60-tick unk_7484 timer. Always ends with
 * ScanVisor_Unk_0a2ae8(3, 2) and returns 1. */
int CampStatus_Unk_0dcb68(CampStatusTableWork *work)
{
    CampStatusCell *c = Unk038fbc_Unk_039160(&work->unk_0240, work->unk_7482, work->unk_7483);
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
}

/* Handler 3 of the table at 0x0213c1d8: step the event state machine in unk_7481 (0-8, and 100
 * for the cancel path) once per call; returns 1 when it has finished. */
int CampStatus_Unk_0dcc00(CampStatusTableWork *work)
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
}

/* Sum slot i of up to five records: the four ids[0..3] (each skipped when extra falls in that
 * id's 50-wide block starting at 211, 261, 311, 361) and extra itself. The total starts at 100;
 * the state codes merge through CampStatus_Unk_0dd88c, and slot 6 turns state 0/5 into 1. */
CampStatusStateWord CampStatus_Unk_0dd500(const u16 *ids, s32 i, s32 extra)
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
}

/* Colour for the player's line by tier (4, 5, other): the first colour when status +0x6c is
 * 1 or 7 or +0x1c is not positive, the second otherwise (default colour for other tiers). */
void CampStatus_Unk_0dd910(void)
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
}

/* Colour for a unit's line: grey for an empty entry; for kinds 4 and 5 the first colour when
 * status +0x34 is 1 or 7 or +0x1e is not positive, the second otherwise; other kinds grey or
 * the default colour. */
void CampStatus_Unk_0dd9d8(CampStatusUnit *unit)
{
    CampStatusEntry *e = func_020a1428(unit->unk_0036);
    if (e->unk_00 == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        return;
    }
    if (e->kind == 4) {
        if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
            func_02057dcc(0x18525aff, 0x18525aff, 0x18525aff, 0x18525aff);
        } else {
            func_02057dcc(0x39dccbff, 0x39dccbff, 0x39dccbff, 0x39dccbff);
        }
        return;
    }
    if (e->kind == 5) {
        if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
            func_02057dcc(0x5a3129ff, 0x5a3129ff, 0x5a3129ff, 0x5a3129ff);
        } else {
            func_02057dcc(0xff7b63ff, 0xff7b63ff, 0xff7b63ff, 0xff7b63ff);
        }
        return;
    }
    if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
    } else {
        func_02057df8();
    }
}

/* Like CampStatus_Unk_0ddb9c with the unit's id: grey for an empty entry, own colours for
 * kinds 4 and 5, grey otherwise. */
void CampStatus_Unk_0ddb04(CampStatusUnit *unit)
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
}

/* Pick the four-corner colour for entry id: grey when its first u16 is 0, otherwise by the
 * kind byte at +5 (4 and 5 get their own colours, anything else the default via func_02057df8). */
void CampStatus_Unk_0ddb9c(int id)
{
    CampStatusEntry *e = func_020a1428(id);
    if (e->unk_00 == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        return;
    }
    if (e->kind == 4) {
        func_02057dcc(0x39dccbff, 0x39dccbff, 0x39dccbff, 0x39dccbff);
        return;
    }
    if (e->kind == 5) {
        func_02057dcc(0xff7b63ff, 0xff7b63ff, 0xff7b63ff, 0xff7b63ff);
        return;
    }
    func_02057df8();
}

/* Draw a frame of height *rows * 13 at x: top piece (frame 5), two strips (resources 0x1d01
 * and 0x1d00), bottom piece (frame 6) at the last row. */
void CampStatus_Unk_0ddc20(u32 obj, const s32 *rows, u32 unused, int x, float alpha)
{
    func_02057fd8();
    func_0205dee8(2, obj, 5, x, 0, 1.0f, 1.0f, 0, alpha, 2);
    func_02058f10(2, 0x1d01, x, 0, 99, *rows * 13 - 1, 2);
    func_02058f10(2, 0x1d00, x, 0, 8, *rows * 13 - 1, 2);
    func_0205dee8(2, obj, 6, x, (*rows - 1) * 13, 1.0f, 1.0f, 0, alpha, 2);
}

/* Draw frame 26 of obj at (x, 0) with the given alpha, prio 2 (func_0205dee8). */
void CampStatus_Unk_0dddf4(u32 obj, int x, float alpha)
{
    func_0205dee8(2, obj, 0x1a, x, 0, 1.0f, 1.0f, 0, alpha, 2);
}

/* Look up group (a, b) and, after func_02063920, run each of the n ids through func_0204fed8 and
 * func_02063a30; the last result goes to func_02061f10 for obj. Does nothing when n is 0. */
void CampStatus_Unk_0dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n)
{
    u32 last;
    u32 tab;
    u32 i;
    if (n == 0) {
        return;
    }
    tab = func_020445f4(a, b);
    func_02063920();
    for (i = 0; i < n; i++) {
        last = func_02063a30(func_0204fed8(tab, ids[i]));
    }
    func_02061f10(obj, -1, 0, 0, last);
}
