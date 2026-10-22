import re
TU = 'src/CampStatus.c'
SRC = open('~/sj-decomp/' + TU).read()
def body(name):
    m = re.search(r'^[^\n]*\b' + name + r'\([^)]*\)\n\{\n.*?\n\}\n', SRC, re.S | re.M)
    return m.group(0)
FIX = [
("/* decompiler-derived */\n" + body('CampStatus_Unk_0db338').split('\n', 1)[0], body('CampStatus_Unk_0db338').split('\n', 1)[0]),
("/* decompiler-derived */\n" + body('CampStatus_Unk_0db394').split('\n', 1)[0], body('CampStatus_Unk_0db394').split('\n', 1)[0]),
("""/* Reached through two pointers from CampStatusWork.unk_002c. */
typedef struct CampStatusLink {
    u8 pad_0000[0x14];
    u32 unk_0014;
} CampStatusLink;

/* Animation/scale block at CampStatusWork.unk_0094. */
typedef struct CampStatusAnim {
    u8 pad_0000[0x20];
    f32 scale;                  /* +0x20: reset to 1.0 */
    u8 pad_0024[0x4];
    s32 unk_0028;               /* +0x28: reset to -1 */
} CampStatusAnim;
""", """/* First word of a CampStatusObj; also the handle the func_0205c* helpers take. */
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

/* Bust-up picture set; func_020dc6c0 builds two from "Camp/Status/st_bu_anime" and the
 * "bust_up/st_bu_en%03d" / "st_bu_mt%03d" textures (CampStatus_Unk_0db338 / _0db394). */
typedef struct CampStatusBustUp {
    u32 res;                    /* +0x00: func_0205dcd4 resource, freed by func_0205ddb4 */
    u32 anim;                   /* +0x04: func_0205c2c4 animation, freed by func_0205c368 */
    u32 unk_08;                 /* +0x08: from func_0205ba28 */
    u32 tex;                    /* +0x0c: func_02051610 texture, freed by func_02053000 */
    CampStatusObj *obj;
    u32 unk_14;
} CampStatusBustUp;
"""),
("""/* Object at CampStatusWork.unk_0078; +0x3a is the flag Unk065e88_SetFlag3a writes. */
typedef struct CampStatusFlagObj {
    u32 handle;
    u8 pad_0004[0x36];
    u8 flag_3a;
} CampStatusFlagObj;

""", ""),
("""    u32 unk_0018;
    u32 unk_001c;
    u8 pad_0020[0xc];
    CampStatusLink **unk_002c;
    u8 pad_0030[0x48];
    CampStatusFlagObj *unk_0078;
    u8 pad_007c[0x8];
    u32 unk_0084;               /* +0x84/+0x88/+0x90: handles released by CampStatus_Unk_0dc908 */
    u32 unk_0088;
    u8 pad_008c[0x4];
    u32 unk_0090;
    CampStatusAnim *unk_0094;
    u8 pad_0098[0x4];
    u32 unk_009c;               /* +0x9c/+0xa0/+0xa8/+0xac: released by CampStatus_Unk_0dc908 */
    u32 unk_00a0;
    u8 pad_00a4[0x4];
    u32 unk_00a8;
    void *unk_00ac;
    u8 pad_00b0[0xc];
""", """    u32 unk_0018;               /* +0x18/+0x1c: resources (func_0205ddb4), +0x20 animation */
    u32 unk_001c;
    u32 unk_0020;
    CampStatusObj *unk_0024[22]; /* +0x24: objects; [2], [11..18] and [21] are used here */
    u32 unk_007c;
    u32 unk_0080;
    CampStatusBustUp unk_0084[2];
    void *unk_00b4;             /* +0xb4..+0xc8: text objects released by func_020629c4 */
    void *unk_00b8;
"""),
(body('CampStatus_ResetAnim'), """void CampStatus_ResetAnim(void)
{
    data_02176be4->unk_0260 = 0;
    data_02176be4->unk_0084[0].obj->unk_0028 = -1;
    data_02176be4->unk_0084[0].obj->scale = 1.0f;
}
"""),
(body('CampStatus_GetLinkUnk14'), """void CampStatus_GetLinkUnk14(u32 *out)
{
    *out = data_02176be4->unk_0024[2]->link->unk_0014;
}
"""),
(body('CampStatus_Unk_0dcad4'), """void CampStatus_Unk_0dcad4(s32 on)
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
"""),
(body('CampStatus_Unk_0dc908'), """void CampStatus_Unk_0dc908(void)
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
"""),
(body('CampStatus_Unk_0db338'), """/* Load bust-up texture "st_bu_en%03d" (data_021507f4) number n into b->tex and bind it to
 * b->unk_08 (func_0205b444). Always returns 1. */
u32 CampStatus_Unk_0db338(CampStatusBustUp *b, u32 n)
{
  char path[64];
  func_02013c3c(path, data_021507f4, n);
  b->tex = func_02051610(path);
  func_0205b444(b->unk_08, b->tex);
  return 1;
}
"""),
(body('CampStatus_Unk_0db394'), """/* Same for "st_bu_mt%03d" (data_02150824), numbered through CampStatus_GetTableByte(i). */
u32 CampStatus_Unk_0db394(CampStatusBustUp *b, u32 i)
{
  char path[64];
  func_02013c3c(path, data_02150824, CampStatus_GetTableByte(i));
  b->tex = func_02051610(path);
  func_0205b444(b->unk_08, b->tex);
  return 1;
}
"""),
("""void Unk065e88_SetFlag3a(CampStatusFlagObj *obj, int value);
void func_0205cac0(u32 handle);
void func_0205c6f8(u32 handle);""", """void Unk065e88_SetFlag3a(CampStatusObj *obj, int value);
void func_0205cac0(CampStatusLink *link);
void func_0205c6f8(CampStatusLink *link);"""),
("""void func_02061424();
""", """void func_02061424();
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
"""),
]
SPECS = [(TU, [
('func_020d6a24', '''/* Handler 0x1c of the CampStatus_Unk_0d3624 table: release everything the screen created
 * (resources, objects, both bust-ups, the six text objects) and unload groups 14, 13, 10. */
void func_020d6a24(CampStatusWork *work)
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
}'''),
('func_020dc6c0', '''/* Build object [2] and both bust-ups (resource, animation, descriptor, texture, object) in the
 * shared work; objects use mode 0 when unk_018c is set, else 1. With unk_00f4 set, object [2]
 * starts on sequence 2. */
void func_020dc6c0(void)
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
}'''),
], '', FIX)]
