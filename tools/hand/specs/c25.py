import re
TU = 'src/CampStatus.c'
SRC = open('~/sj-decomp/' + TU).read()
# +0xfc..+0x10e become one s16[10] array (func_020d5644 loops over it)
NEW = SRC.replace("""    s16 unk_00fc;
    s16 unk_00fe;
    s16 unk_0100[5];            /* +0x100: x of the five rows drawn by CampStatus_Unk_0d6e10 */
    s16 unk_010a;
    s16 unk_010c;
    s16 unk_010e;
""", """    s16 unk_00fc[10];           /* +0xfc: slide-in offsets, all moved to 0 by func_020d5644: [0] y of the
                                 * frame, [1] x of the status panel, [2..6] x of the five rows,
                                 * [7] x of the top bar, [8] y of the top panel, [9] title x */
""")
assert NEW != SRC
for a, b in [('unk_00fe', 'unk_00fc[1]'), ('unk_010a', 'unk_00fc[7]'), ('unk_010c', 'unk_00fc[8]'), ('unk_010e', 'unk_00fc[9]')]:
    NEW = re.sub(r'\b' + a + r'\b', b, NEW)
NEW = re.sub(r'\bunk_00fc\b(?!\[)', 'unk_00fc[0]', NEW)
NEW = re.sub(r'\bunk_0100\[(\d)\]', lambda m: 'unk_00fc[%d]' % (int(m[1]) + 2), NEW)
NEW = re.sub(r'\bunk_0100\[i\]', 'unk_00fc[i + 2]', NEW)
NEW = NEW.replace('unk_0100[0..4]', 'unk_00fc[2..6]')
assert 'unk_0100' not in NEW, [l for l in NEW.split('\n') if 'unk_0100' in l]
FIX = [
(SRC, NEW),
("""    u32 unk_000c;
    s32 unk_0010;               /* +0x10""", """    s16 unk_000c;               /* +0x0c: bust-up texture to load (0: first, > 0: number, < 0: loaded) */
    s16 unk_000e;               /* +0x0e: frame delay before loading it */
    s32 unk_0010;               /* +0x10"""),
("""typedef struct CampStatusLink {
    u8 pad_0000[0x14];
    u32 unk_0014;
} CampStatusLink;""", """typedef struct CampStatusLink {
    u8 pad_0000[0x14];
    u32 unk_0014;
    u8 pad_0018[0x10];
    u32 unk_0028;               /* +0x28: copied between the two bust-up animations */
} CampStatusLink;"""),
("""    CampStatusLink *link;
    u8 pad_0004[0x1c];
    f32 scale;""", """    CampStatusLink *link;
    u32 unk_0004;               /* +0x04/+0x08: position (set together, see Unk065e88_SetPair04) */
    s32 unk_0008;
    u32 unk_000c;
    s32 unk_0010;
    u8 pad_0014[0xc];
    f32 scale;"""),
("""    u32 unk_08;                 /* +0x08: from func_0205ba28 */""", """    CampStatusTexSlot *unk_08;  /* +0x08: from func_0205ba28 */"""),
("""typedef struct CampStatusBustUp {""", """/* Texture slot made by func_0205ba28; +0x59 is set once the texture is ready. */
typedef struct CampStatusTexSlot {
    u8 pad_0000[0x59];
    u8 unk_59;
} CampStatusTexSlot;

typedef struct CampStatusBustUp {"""),
("""u32 func_0205ba28(CampStatusDesc *desc, const char *file, u32 line);""", """CampStatusTexSlot *func_0205ba28(CampStatusDesc *desc, const char *file, u32 line);"""),
("""    u32 unk_007c;""", """    CampStatusLink *unk_007c;   /* +0x7c: overlay animation (func_0205c3c0) */"""),
("""void func_0205c3dc(u32 handle);""", """void func_0205c3dc(CampStatusLink *link);"""),
("""void func_0205de30(u32 res, u32 a, u32 b);""", """void func_0205de30(u32 res, u32 a, CampStatusTexSlot *slot);"""),
("""    u8 pad_01b4[0x8c];""", """    u8 unk_01b4[0x8c];          /* +0x1b4: object for func_020a208c / func_020a22e0 / func_020a2250 */"""),
("""    u8 pad_0242[0x6];""", """    u8 pad_0242[0x2];
    CampStatusObj *unk_0244;    /* +0x244: object from func_020a22e0 (mode 5) */"""),
("""    u8 pad_0254[0x4];""", """    u32 unk_0254;               /* +0x254: object [18] is hidden once its animation ends */"""),
]
SPECS = [(TU, [
('func_020d5644', '''/* Handler 0x0c of the CampStatus_Unk_0d3624 table: per-frame update. Slides the panels in and
 * fades in (unk_0110) until every offset is 0, then starts object [2]; loads and shows the
 * bust-up textures; handles the overlay animation, the top-panel slide and its request, the two
 * tab toggles (keys 0x200/0x100), mode 5's object, and in modes 6/8 the random idle animation. */
void func_020d5644(CampStatusWork *work)
{
    CampStatusRequest req;
    s32 i;
    if (func_02052728() != 0) {
        return;
    }
    if (work->unk_00f4 == 0) {
        if (work->unk_00fc[0] < 0) {
            work->unk_00fc[0]++;
            work->unk_0024[21]->unk_0010 = work->unk_00fc[0];
        }
        if (work->unk_00fc[1] < 0) {
            work->unk_00fc[1] += 16;
        }
        if (work->unk_00fc[2] < 0) {
            work->unk_00fc[2] += 16;
        }
        if (work->unk_00fc[3] < 0) {
            work->unk_00fc[3] += 16;
        }
        if (work->unk_00fc[4] < 0) {
            work->unk_00fc[4] += 16;
        }
        if (work->unk_00fc[5] < 0) {
            work->unk_00fc[5] += 16;
        }
        if (work->unk_00fc[6] < 0) {
            work->unk_00fc[6] += 16;
        }
        if (work->unk_00fc[7] > 0) {
            work->unk_00fc[7] -= 8;
        }
        if (work->unk_00fc[8] > 0) {
            work->unk_00fc[8] -= 6;
        }
        if (work->unk_00fc[9] < 0) {
            work->unk_00fc[9] += 8;
        }
        for (i = 0; i < 10; i++) {
            if (work->unk_00fc[i] != 0) {
                break;
            }
        }
        if (work->unk_0010 < 10) {
            work->unk_0110 = ++work->unk_0010 / 10.0f;
        }
        if (i == 10 && work->unk_0010 >= 10) {
            work->unk_00f4 = 1;
            work->unk_0010 = 0;
            work->unk_0110 = 1.0f;
            func_0205c408(work->unk_0024[2]->link, 2);
            func_0205c6e0(work->unk_0024[2]->link);
            work->unk_0024[2]->unk_0030 = 6;
            work->unk_0024[2]->unk_0024 = 10;
        }
    }
    if (work->unk_0114 != 0) {
        work->unk_0010++;
    }
    if (work->unk_0084[0].unk_14 != 0) {
        if (work->unk_000c == 0) {
            if (work->unk_000e < 1) {
                work->unk_000e++;
            } else {
                char path[64];
                func_02013c3c(path, data_021506f8, 1);
                work->unk_0084[0].tex = func_02051610(path);
                func_0205b444(work->unk_0084[0].unk_08, work->unk_0084[0].tex);
                work->unk_000c = -1;
                work->unk_000e = 0;
            }
        } else if (work->unk_000c > 0) {
            if (work->unk_000e < 1) {
                work->unk_000e++;
            } else {
                char path[64];
                func_02013c3c(path, data_02150728, work->unk_000c);
                work->unk_0084[0].tex = func_02051610(path);
                func_0205b444(work->unk_0084[0].unk_08, work->unk_0084[0].tex);
                work->unk_000c = -1;
                work->unk_000e = 0;
            }
        } else if (work->unk_0084[0].unk_08->unk_59 != 0) {
            func_0205c408(work->unk_0084[0].obj->link, 0);
            func_0205cac0(work->unk_0084[0].obj->link);
            Unk065e88_SetFlag3a(work->unk_0084[0].obj, 1);
            work->unk_0084[1].obj->unk_0030 = 2;
            work->unk_0084[0].obj->unk_0024 = 1;
            work->unk_0084[0].unk_14 = 0;
            work->unk_0004 = 1;
            work->unk_0008 = 1;
        }
    }
    if (work->unk_0084[1].unk_14 != 0) {
        if (work->unk_0084[1].unk_08->unk_59 != 0 && work->unk_0084[0].unk_14 == 0) {
            func_0205c408(work->unk_0084[1].obj->link, 1);
            func_0205cac0(work->unk_0084[1].obj->link);
            Unk065e88_SetFlag3a(work->unk_0084[1].obj, 1);
            work->unk_0084[1].obj->unk_0030 = 2;
            work->unk_0084[1].obj->unk_0024 = 2;
            work->unk_0084[1].unk_14 = 0;
            Unk065e88_SetUnkFieldsc_10(work->unk_0084[1].obj, work->unk_0084[0].obj->link->unk_0014, 0);
            work->unk_0084[1].obj->link->unk_0028 = work->unk_0084[0].obj->link->unk_0028;
        }
    } else if (work->unk_0000 == 10 && work->unk_0004 != 0) {
        s32 frame = work->unk_0084[0].obj->link->unk_0014;
        Unk065e88_SetUnkFieldsc_10(work->unk_0084[1].obj, frame, 0);
        if (frame > 0) {
            work->unk_0084[1].obj->link->unk_0028 = work->unk_0084[0].obj->link->unk_0028;
        }
    }
    if (work->unk_00ec != 0 && func_0205c704(work->unk_007c) == 0) {
        func_0205c408(work->unk_007c, 6);
        func_0205c41c(work->unk_007c, 0);
        func_0205c6e0(work->unk_007c);
    }
    if (work->unk_00f8 == 0) {
        if (work->unk_00fc[8] > 0) {
            work->unk_00fc[8] -= 6;
        }
        if (work->unk_00fc[8] <= 0) {
            work->unk_00fc[8] = 0;
            work->unk_00f8 = 1;
            if (work->unk_01a0 == 0) {
                for (i = 0; i < 2; i++) {
                    req.flags[i] = 0;
                }
                for (i = 0; i < 16; i++) {
                    req.values[i] = 0;
                }
                req.values[0] = 3;
                req.flags[0] |= 1;
                func_020bc9f4(3, &req);
                func_020bcacc(work->unk_0014, &req);
            }
        }
    }
    if (work->unk_01a8 != 0) {
        if (func_020537b8(0, 0x200)) {
            work->unk_01ac = 1;
        } else if (func_020537dc(0, 0x200)) {
            work->unk_01ac = 0;
        }
        if (func_020537b8(0, 0x100)) {
            work->unk_01b0 = 1;
        } else if (func_020537dc(0, 0x100)) {
            work->unk_01b0 = 0;
        }
    }
    if (work->unk_0254 != 0 && func_0205ca48(work->unk_0024[18]->link) == 0) {
        Unk065e88_SetFlag3a(work->unk_0024[18], 0);
        work->unk_0254 = 0;
    }
    if (work->unk_0000 == 5 && (work->unk_0258 = Unk0a163c_Thunk_020a208c(work->unk_01b4)) != 0) {
        Unk05ae50_Unk_05afd8(0x18000);
        if (work->unk_0250 != 0) {
            work->unk_0244 = func_020a22e0(work->unk_01b4, work->unk_00cc->unk_0036, 1);
        } else {
            work->unk_0244 = func_020a22e0(work->unk_01b4, work->unk_00da, 1);
        }
        if (work->unk_0244 != 0) {
            CampStatusDemonData *d;
            func_0205c408(work->unk_0244->link, 0);
            func_0205c41c(work->unk_0244->link, 0);
            func_0205cac0(work->unk_0244->link);
            Unk065e88_SetFlag3a(work->unk_0244, 1);
            work->unk_0244->unk_0024 = 8;
            work->unk_0244->unk_0030 = 2;
            if (work->unk_0250 != 0) {
                d = func_020a2250(work->unk_01b4, work->unk_00cc->unk_0036);
            } else {
                d = func_020a2250(work->unk_01b4, work->unk_00da);
            }
            work->unk_0244->unk_0008 = d->unk_018c->unk_06 + 8;
            work->unk_0244->unk_0004 = 64;
            func_0205caa8(work->unk_0084[0].obj->link, 0);
            work->unk_0000 = 6;
        }
    }
    if (work->unk_0000 != 6 && work->unk_0000 != 8) {
        return;
    }
    if (work->unk_0000 == 6) {
        work->unk_0244->unk_000c = work->unk_0084[0].obj->link->unk_0014;
    }
    {
        s32 pick = func_02050074(1, 99);
        for (i = 12; i <= 17; i++) {
            if (pick == i && func_0205ca48(work->unk_0024[i]->link) == 0) {
                Unk065e88_SetFlag3a(work->unk_0024[i], 1);
                func_0205cac0(work->unk_0024[i]->link);
            }
        }
    }
}'''),
], '''/* Records reached from func_020a2250's result. */
typedef struct CampStatusPos {
    u8 pad_0000[0x6];
    s16 unk_06;
} CampStatusPos;
typedef struct CampStatusDemonData {
    u8 pad_0000[0x18c];
    CampStatusPos *unk_018c;
} CampStatusDemonData;
extern char data_021506f8[];
extern char data_02150728[];
int func_0205c704(CampStatusLink *link);
void func_0205c41c(CampStatusLink *link, u32 v);
int func_020537b8(u32 port, u32 mask);
int func_020537dc(u32 port, u32 mask);
int func_0205ca48(CampStatusLink *link);
u32 Unk0a163c_Thunk_020a208c(u8 *obj);
void Unk05ae50_Unk_05afd8(u32 v);
CampStatusObj *func_020a22e0(u8 *obj, u16 id, u32 a);
CampStatusDemonData *func_020a2250(u8 *obj, u16 id);
void func_0205caa8(CampStatusLink *link, u32 v);
int func_02050074(int first, int last);
void Unk065e88_SetUnkFieldsc_10(CampStatusObj *obj, u32 v, u32 w);''', FIX)]
