PRE = r'''/* Kind entry returned by func_020a1428; only the two bytes read here are named. */
typedef struct Unk0b28e4Kind {
    u8 pad_00[2];
    u8 unk_02;                  /* 0x02: label index in resource (18, 0) */
    u8 pad_03[2];
    u8 unk_05;                  /* 0x05: 4 and 5 select label styles 3 and 5 */
} Unk0b28e4Kind;
/* 16-bit text copied from data_0213c468 ("   ") and data_0213c4a0. */
typedef struct Unk0b28e4Text4 { u16 c[4]; } Unk0b28e4Text4;
typedef struct Unk0b28e4Text8 { u16 c[8]; } Unk0b28e4Text8;
extern const Unk0b28e4Text4 data_0213c468;
extern const Unk0b28e4Text8 data_0213c4a0;
Unk0b28e4Kind *func_020a1428(u32 id);
s32 Unk02e000_GetRecordUnk1e(u32 id);
s32 func_020dd364(Unk0b28e4StateWord w, const u16 *ids, s32 kind);
'''

F4040 = r'''/* Draws the three roster rows of Unk0b28e4_Unk_0b64c8(): an empty strip for a zero
 * id, otherwise the row background, icon, two labels, the bar (or a blank
 * strip when record flag bit 2 is set), then either a blank category/button
 * grid (while Unk02e000_GetRecordUnk1e is below record->unk_5b) or the
 * func_020b64dc categories and eight func_020dd364 button labels. Ends with
 * the centred title label and returns the row count (3). */
int func_020b4040(Unk0b28e4Obj *work)
{
    u32 res0 = func_020445f4(18, 0);
    u32 res1 = func_020445f4(18, 1);
    Unk0b28e4Text4 blank;
    Unk0b28e4Text8 alt;
    u16 *list;
    u8 i;
    Unk0b28e4IconRecord *record;
    Unk0b28e4Kind *kind;
    int tier;
    u8 row;
    u8 col;
    Unk0b28e4Entry *cats;
    int width;

    Unk044904_Get_data_0215ee98();
    blank = data_0213c468;
    alt = data_0213c4a0;
    func_020119c0(work->unk_0c78, -1, 3);
    list = (u16 *)Unk0b28e4_Unk_0b64c8();
    for (i = 0; i < 3; i++) {
        if (list[i] == 0) {
            func_0203f2d4(work->unk_0008, 0, i * 56 + 16, work->unk_0004, 0, 72, 256, 56);
            continue;
        }
        record = func_020a1740(list[i]);
        kind = func_020a1428(list[i]);
        func_0203f2d4(work->unk_0008, 0, i * 56 + 16, work->unk_0004, 0, 16, 256, 56);
        if (Unk0a163c_Unk_0a17d8(list[i]) != 0) {
            func_020b5f08(list[i], (u8)(i * 2 + 7), work->unk_0c3c[i], 0, 0, 1, work->unk_0c54[i]);
            Unk0b28e4_Unk_0b5e10(work->unk_0c34, blank.c, 34, (u8)(i * 56 + 19), 8, 1);
            Unk0b28e4_Unk_0b5e10(work->unk_0c34, alt.c, 74, (u8)(i * 56 + 19), 16, 1);
        } else {
            int ly;
            func_020b5f08(record->unk_6a, (u8)(i * 2 + 7), work->unk_0c3c[i], 0, 0, 0, work->unk_0c54[i]);
            tier = 1;
            if (kind->unk_05 == 4) tier = 3;
            if (kind->unk_05 == 5) tier = 5;
            ly = i * 56 + 19;
            Unk0b28e4_Unk_0b5e10(work->unk_0c34, func_0204fed8(res0, kind->unk_02), 34, ly, 8, tier);
            tier = 1;
            if (kind->unk_05 == 4) tier = 3;
            if (kind->unk_05 == 5) tier = 5;
            Unk0b28e4_Unk_0b5e10(work->unk_0c34, func_0204fed8(res1, list[i]), 74, ly, 16, tier);
            if (((u32)record->unk_16 << 29) >> 31 != 0) {
                func_0203f2d4(work->unk_0008, 32, (u8)(i * 56 + 37), work->unk_0004, 32, 93, 104, 7);
            } else {
                func_020b3dc4(list[i], work->unk_0004, work->unk_0008, 75, (u8)(i * 56 + 39));
            }
        }
        if (Unk02e000_GetRecordUnk1e(list[i]) < record->unk_5b) {
            for (row = 0; row < 2; row++) {
                for (col = 0; col < 3; col++) {
                    Unk0b28e4_Unk_0b5e10(work->unk_0c30, blank.c, (u8)(col * 83 + 6),
                                         (u8)(i * 56 + 44 + row * 12), 16, 7);
                }
            }
            for (col = 0; col <= 7; col++) {
                Unk0b28e4_Unk_0b5e10(work->unk_0c34, blank.c, (u8)(col * 14 + 143), (u8)(i * 56 + 32), 2, 1);
            }
        } else {
            cats = func_020b64dc(i);
            for (row = 0; row < 2; row++) {
                for (col = 0; col < 3; col++) {
                    if (cats->ids[row * 3 + col] != 0) {
                        Unk0b28e4_Unk_0b5e10(work->unk_0c30, Unk0caea8_Unk_0cb044(cats->ids[row * 3 + col]),
                                             (u8)(col * 83 + 6), (u8)(i * 56 + 44 + row * 12), 16, 7);
                    }
                }
            }
            for (col = 0; col <= 7; col++) {
                Unk0b28e4_Unk_0b5e10(work->unk_0c34,
                                     func_02049398((u8)func_020dd364(record->unk_22[col], cats->ids, col) + 5),
                                     (u8)(col * 14 + 143), (u8)(i * 56 + 32), 2, 1);
            }
        }
    }
    width = func_02061a04(1, func_02049398(1), 0);
    func_0203f2d4(work->unk_0008, 64, 0, work->unk_0004, 0, 0, 64, 16);
    func_0203f2d4(work->unk_0008, 128, 0, work->unk_0004, 0, 0, 64, 16);
    Unk0b28e4_Unk_0b5e10(work->unk_0c30, func_02049398(1), (u8)((256 - width) / 2), 0, 14, 8);
    Unk03e43c_Unk_03f2bc(6);
    return i;
}'''

FIX = [
    ('''/* Rebuild result bounds row drawing in states 1 and 5; work is borrowed.
 * Implementation remains in the delink; see the M1-T1041 hard list. */''', '''/* Rebuild result bounds row drawing in states 1 and 5; work is borrowed. */'''),
    ('void func_0205f7f4(Unk0b28e4Fields *fields, u32 a, u32 b, u32 c);',
     'void func_0205f7f4(Unk0b28e4Fields *fields, const u16 *text, u32 x, u32 y);'),
    ('void Unk0b28e4_Unk_0b5e10(Unk0b28e4Fields *fields, u32 a, u32 b, u32 c, s8 d, u32 e)\n{\n    fields->unk_0037 = d;\n    fields->unk_002c = e;\n    func_0205f7f4(fields, a, b, c);',
     'void Unk0b28e4_Unk_0b5e10(Unk0b28e4Fields *fields, const u16 *text, u8 x, u8 y, s8 d, u32 e)\n{\n    fields->unk_0037 = d;\n    fields->unk_002c = e;\n    func_0205f7f4(fields, text, x, y);'),
    ('u32 func_02049398(u32 id);\nint func_02061a04(u32 bank, u32 id, u32 flags);',
     'const u16 *func_02049398(u32 id);\nint func_02061a04(u32 bank, const u16 *text, u32 flags);'),
    ('u32 func_0204fed8(u32 resource, u32 value);', 'const u16 *func_0204fed8(u32 resource, u32 value);'),
    ('u32 Unk0caea8_Unk_0cb044(u32 value);', 'const u16 *Unk0caea8_Unk_0cb044(u32 value);'),
    ('    u8 unk_48[4];               /* 0x48: label source; extent unknown */',
     '    u16 unk_48[2];              /* 0x48: label text (16-bit characters); extent unknown */'),
    ('    u32 label;\n', '    const u16 *label;\n'),
    ('(u32)Unk02e000_Thunk_0202e788()->unk_48', 'Unk02e000_Thunk_0202e788()->unk_48'),
    # Entry: two rows of three category ids (func_020b4040).
    ('''/* One 12-byte table slot; no member is accessed in this translation unit. */
typedef struct Unk0b28e4Entry {
    u8 pad_00[0xc];
} Unk0b28e4Entry;''', '''/* One 12-byte table slot: two rows of three category ids (func_020b4040). */
typedef struct Unk0b28e4Entry {
    u16 ids[6];
} Unk0b28e4Entry;'''),
    ('''    u8 pad_0c[0xa];
    u16 unk_16;                 /* 0x16: bit 1 selects the alternative number layout */
} Unk0b28e4IconRecord;''', '''    u8 pad_0c[0xa];
    u16 unk_16;                 /* 0x16: bit 1 selects the alternative number layout,
                                   bit 2 hides the bar in func_020b4040 */
    u8 pad_18[0xa];
    Unk0b28e4StateWord unk_22[8]; /* 0x22: per-button words for func_020dd364 */
    u8 pad_32[0x28];
    u8 unk_5a;                  /* 0x5a/0x5b: bar thresholds (func_020b3dc4) */
    u8 unk_5b;
    u8 pad_5c[0xe];
    u16 unk_6a;                 /* 0x6a: icon id used when the id has no direct icon */
} Unk0b28e4IconRecord;'''),
    ('''/* Record returned by func_020a1740. Only the fields this TU reads are named. */''',
     '''/* 10-bit value and 6-bit state, passed by value to func_020dd364 (as CampStatusStateWord). */
typedef struct Unk0b28e4StateWord {
    u16 value : 10;
    u16 state : 6;
} Unk0b28e4StateWord;

/* Record returned by func_020a1740. Only the fields this TU reads are named. */'''),
]

SPECS = [('src/game/unit_020b28e4.c', [('func_020b4040', F4040)], PRE, FIX)]
