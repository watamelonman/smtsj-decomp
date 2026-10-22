/* src/game/unit_02100810.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/*
 * Descriptor initialized by func_02100810: 0x20d8 is stored at +0, zero at +4,
 * and six callback pointers follow from +0x0c. The word at +0x08 is untouched.
 */
typedef struct Unk100810Ops {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    void (*fn_0c)();
    void (*fn_10)();
    void (*fn_14)();
    void (*fn_18)();
    void (*fn_1c)();
    void (*fn_20)();
} Unk100810Ops;

/*
 * Draw handle held at +0x38 of the work objects: func_02106f50 passes the word at +0
 * to func_020aa078, and func_021057ac stores 2 into the byte at +0x40.
 */
typedef struct Unk100810Handle {
    u32 unk_00;
    u8 pad_04[0x3c];
    u8 unk_40;
} Unk100810Handle;

/*
 * Work object passed to the state setters in this file. Layout comes from the
 * observed accesses; the byte-sized field at +0x1f34 is a toggle cleared by
 * func_021065c8 while the words after it hold handles and flags.
 */
typedef struct Unk100810Work {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    s32 unk_000c;
    u32 unk_0010;
    s32 unk_0014;
    u8 pad_0018[8];
    u32 unk_0020, unk_0024, unk_0028;
    u32 unk_002c;
    u32 unk_0030, unk_0034;
    Unk100810Handle *unk_0038;
    u32 unk_003c, unk_0040, unk_0044;
    u32 unk_0048;
    u8 pad_004c[0x08];
    u32 unk_0054;
    u8 pad_0058[0x1ed8];
    u32 unk_1f30;
    u8 unk_1f34;
    u8 pad_1f35[0x03];
    union { u32 handles[2]; struct { u32 first, second; } fields; } handles_1f38;
    u8 pad_1f40[0xc0];
    u32 unk_2000;
    u8 unk_2004[0x24];
    s8 unk_2028;
    u8 pad_2029[3];
    s32 unk_202c;
    u8 pad_2030[0x84];
    u32 unk_20b4;
    u8 pad_20b8[4];
    u32 unk_20bc;
    u32 unk_20c0;
    u32 unk_20c4;
    u32 unk_20c8;
    u32 unk_20cc;
} Unk100810Work;

/*
 * 0x1eb records of 0x10 bytes starting at +0x68, followed at +0x1f18 by a
 * u16 table indexed by (unk_0014 - unk_000c). Only the leading u16 id of each
 * record is read here; the rest of the record is opaque.
 */
typedef struct Unk100810Record {
    u16 id;
    u8 unk_02;
    u8 pad_0003[0x0d];
} Unk100810Record;

typedef struct Unk100810Table {
    u8 pad_0000[0x04];
    u32 unk_0004;
    s32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x04];
    u32 unk_0014;
    u8 pad_0018[0x0c];
    u32 unk_0024, unk_0028;
    u8 pad_002c[0x0c];
    Unk100810Handle *unk_0038;
    u32 unk_003c;
    u8 pad_0040[0x18];
    s8 unk_0058;
    u8 pad_0059[0x0f];
    Unk100810Record records[0x1eb];
    /* Scans populate up to ten entries, drawing uses nine; retain the +0x2000 word. */
    u16 unk_1f18[10];
    u8 pad_1f2c[0xd4];
    u32 unk_2000;
} Unk100810Table;

void func_02102260();
void func_02100870();
void func_02103508(Unk100810Work *work);
void func_021035a0();
void func_02104604();
void func_02104780();


/* Twelve opaque bytes copied with byte alignment. */
typedef struct Unk100810Bytes { u8 bytes[12]; } Unk100810Bytes;

/* Preserve byte alignment while copying the opaque payload. */
static inline void CopyRecordBytes(Unk100810Bytes *dest, const Unk100810Bytes *source)
{
    u8 *d = dest->bytes;
    const u8 *s = source->bytes;
    u32 n = 6;
    do {
        u8 a = s[0];
        u8 b = s[1];
        s += 2;
        d[0] = a;
        d[1] = b;
        d += 2;
    } while (--n != 0);
}

/* Record metadata returned by the two table accessors; only observed fields are named. */
typedef struct Unk100810Meta {
    u16 id;
    u8 unk_02, unk_03;
    u32 unk_04;
    union { u32 value; struct { u16 low : 1; u16 rest : 15; u16 high_low : 1; u16 high_rest : 15; } bits; } unk_08;
    u8 pad_0c[8];
    u16 unk_14;
    union { u16 value; struct { u16 low : 1; u16 second : 1; u16 rest : 14; } bits; } unk_16;
    u8 pad_18[2];
    u8 stats[5];
    u8 pad_1f[15];
    Unk100810Bytes bytes_2e;
} Unk100810Meta;

/* Working record layout consumed by func_0209786c (60 bytes). */
typedef struct Unk100810Result {
    u16 unk_00, unk_02;
    u8 stats[5];
    u8 pad_09;
    s16 unk_0a, unk_0c;
    u8 pad_0e[6];
    u16 unk_14, unk_16;
    u8 stats_18[5];
    u8 pad_1d;
    s16 unk_1e, unk_20;
    u8 pad_22[2];
    u32 unk_24;
    Unk100810Bytes bytes_28;
    u16 unk_34, id;
    u8 unk_38;
    u8 pad_39[3];
} Unk100810Result;

/* Compact saved record; field ordering is evidenced by the conversion loads. */
typedef struct Unk100810Saved {
    u8 unk_00;
    u8 stats[5];
    u8 stats_06[5];
    u8 pad_0b;
    u16 unk_0c, unk_0e;
    Unk100810Bytes bytes_10;
    u8 pad_1c[2];
    u8 unk_1e : 7;
    u8 flag_1e : 1;
    u8 pad_1f;
    u32 unk_20;
} Unk100810Saved;

/* Record with an explicit id followed by the saved fields. */
typedef struct Unk100810Input {
    u16 id;
    u8 pad_02[2];
    u8 unk_04;
    u8 stats[5];
    u8 stats_0a[5];
    u8 pad_0f;
    u16 unk_10, unk_12;
    Unk100810Bytes bytes_14;
    u8 pad_20[4];
    u32 unk_24;
} Unk100810Input;

Unk100810Meta *func_020a1428(u16 id);
Unk100810Meta *func_020a1740(u16 id);
int Unk02e000_IsRecordAvailable(u16 id);
void func_02008848(void *dest, int value, u32 size);
void func_0209786c(Unk100810Result *record);
int CampStatus_IsUnkF4F8Set(void);
void func_02057524(int mode);
void func_02057df8(void);
void func_02057534(void);
void Unk0ddeb0_Unk_0ddeb0(u32 handle, int a, int b, int c, int d, int e);

/* Draws twelve entries for state 21 when the camp flag permits it and +0x1f30 is clear. */
void func_02103508(Unk100810Work *work)
{
    int i, y;
    if (work->unk_0048 != 21) return;
    if (CampStatus_IsUnkF4F8Set() == 0) return;
    if (work->unk_1f30 != 0) return;
    func_02057524(6);
    func_02057df8();
    for (i = 0, y = 30; i < 12; i++, y += 13) {
        Unk0ddeb0_Unk_0ddeb0(work->unk_002c, 3, y, i, 12, 10);
    }
    func_02057534();
}

/*
 * Stores 0x20d8 at +0, zero at +4, and six callback pointers from +0x0c. The
 * word at +0x08 is left untouched.
 */
void func_02100810(Unk100810Ops *ops)
{
    ops->unk_00 = 0x20d8;
    ops->unk_04 = 0;
    ops->fn_0c = func_02102260;
    ops->fn_10 = func_02100870;
    ops->fn_14 = func_02103508;
    ops->fn_18 = func_021035a0;
    ops->fn_1c = func_02104604;
    ops->fn_20 = func_02104780;
}

int func_020445f4();
int func_0204fed8();
int func_02061f10();
int func_02063920();
int func_02063a30();
/*
 * Obtains a handle from func_020445f4(0xc), passes arg2, 0xcc and 0xcd to it
 * through func_0204fed8 (with func_02063a30 around each call), then calls
 * func_02061f10(arg0, -1, 0, 0, last result). arg1 is not read.
 */
void Unk100810_Unk_104f18(u32 arg0, u32 arg1, u32 arg2)
{
  u32 tmp1;
  tmp1 = func_020445f4(0xc);
  func_02063920();
  func_0204fed8(tmp1,arg2);
  func_02063a30();
  func_0204fed8(tmp1,0xcc);
  func_02063a30();
  func_0204fed8(tmp1,0xcd);
  tmp1 = func_02063a30();
  func_02061f10(arg0,0xffffffff,0,0,tmp1);
  return;
}

void Unk100810_Unk_107154(Unk100810Work *arg0, int arg1);
void Unk0bc1a8_Unk_0bc928();

/*
 * Stores 10 at +0x48 and arg1 at +0x54, clears the byte at +0x1f34, calls
 * Unk100810_Unk_107154(arg0, 0), then calls Unk0bc1a8_Unk_0bc928(7, 6, 0).
 */
void func_021065c8(Unk100810Work *arg0, u32 arg1)
{
    arg0->unk_0048 = 10;
    arg0->unk_0054 = arg1;
    arg0->unk_1f34 = 0;
    Unk100810_Unk_107154(arg0, 0);
    Unk0bc1a8_Unk_0bc928(7, 6, 0);
}

int func_020537b8();
extern u8 *data_02176e2c;
void func_02008904();
/*
 * Passes arg0, data_02176e2c + 8128 and 60 to func_02008904; does nothing
 * while the global pointer is null.
 */
void Unk100810_Unk_1069c8(u32 a)
{
    if (data_02176e2c == 0) {
        return;
    }
    func_02008904(a, data_02176e2c + 8128, 60);
}

int Unk02e000_GetRecordFlag1();
void func_020bcfc4();
/*
 * Scans the 0x1eb records for an enabled record whose id equals the u16 selected
 * at +0x1f18 by (unk_0014 - unk_000c). On a hit it passes the +4 list base and
 * the count of earlier enabled records to func_020bcfc4.
 */
void func_02106aac(Unk100810Table *arg0)
{
    u16 target;
    int n;
    int i;

    target = arg0->unk_1f18[arg0->unk_0014 - arg0->unk_000c];
    n = 0;
    for (i = 0; i < 0x1eb; i++) {
        if (Unk02e000_GetRecordFlag1(arg0->records[i].id) == 0) {
            continue;
        }
        if (target == arg0->records[i].id) {
            func_020bcfc4(&arg0->unk_0004, n);
            return;
        }
        n++;
    }
}

/*
 * Polls func_020537b8(0, mask) for masks 0x40, 0x80, 0x20 and 0x10, setting the
 * corresponding flag word at +0x20bc, +0x20c0, +0x20c4 or +0x20c8.
 */
void Unk100810_Unk_1070d8(Unk100810Work *arg0)
{
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    arg0->unk_20bc = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    arg0->unk_20c0 = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    arg0->unk_20c4 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    arg0->unk_20c8 = 1;
  }
  return;
}

int Unk065e88_SetFlag3a();
/*
 * Toggles the flag at +0x20cc and pushes the stored mode to both state handles
 * (+0x1f38 and +0x1f3c) via Unk065e88_SetFlag3a.
 */
void Unk100810_Unk_107154(Unk100810Work *arg0, int arg1)
{
  if (arg1 != 0) {
    arg0->unk_20cc = 1;
    Unk065e88_SetFlag3a(arg0->handles_1f38.fields.first);
    Unk065e88_SetFlag3a(arg0->handles_1f38.fields.second,1);
    return;
  }
  arg0->unk_20cc = 0;
  Unk065e88_SetFlag3a(arg0->handles_1f38.fields.first);
  Unk065e88_SetFlag3a(arg0->handles_1f38.fields.second,0);
  return;
}

/*
 * True when the global work pointer exists and its word at +0x50 equals 1.
 */
int Unk100810_IsField50One(void)
{
    if (data_02176e2c == 0) {
        return 0;
    }
    return FIELD(u32, data_02176e2c, 80) == 1;
}

/* Converts observed record fields to the 60-byte work record; a zero id leaves out untouched. */
void func_021066f0(Unk100810Input *input, Unk100810Result *out)
{
    if (input->id == 0) return;
    func_020a1428(input->id);
    func_02008848(out, 0, 60);
    out->unk_38 = input->unk_04;
    CopyRecordBytes(&out->bytes_28, &input->bytes_14);
    out->id = input->id;
    out->unk_24 = input->unk_24;
    out->unk_00 = input->unk_10;
    out->unk_02 = input->unk_12;
    out->stats[0] = input->stats[0];
    out->stats[1] = input->stats[2];
    out->stats[2] = input->stats[3];
    out->stats[3] = input->stats[4];
    out->stats[4] = input->stats[1];
    out->unk_14 = 0;
    out->unk_16 = 0;
    out->stats_18[0] = input->stats_0a[0];
    out->stats_18[1] = input->stats_0a[2];
    out->stats_18[2] = input->stats_0a[3];
    out->stats_18[3] = input->stats_0a[4];
    out->stats_18[4] = input->stats_0a[1];
    func_0209786c(out);
    out->unk_1e = out->unk_0a;
    out->unk_20 = out->unk_0c;
}

/* Converts observed record fields to the 60-byte work record; a zero id leaves out untouched. */
void func_021067e8(Unk100810Saved *input, u16 id, Unk100810Result *out)
{
    if (id == 0) return;
    func_020a1428(id);
    func_02008848(out, 0, 60);
    out->unk_38 = input->unk_00;
    CopyRecordBytes(&out->bytes_28, &input->bytes_10);
    out->id = id;
    out->unk_24 = input->unk_20;
    out->unk_00 = input->unk_0c;
    out->unk_02 = input->unk_0e;
    out->stats[0] = input->stats[0];
    out->stats[1] = input->stats[2];
    out->stats[2] = input->stats[3];
    out->stats[3] = input->stats[4];
    out->stats[4] = input->stats[1];
    out->unk_14 = 0;
    out->unk_16 = 0;
    out->stats_18[0] = input->stats_06[0];
    out->stats_18[1] = input->stats_06[2];
    out->stats_18[2] = input->stats_06[3];
    out->stats_18[3] = input->stats_06[4];
    out->stats_18[4] = input->stats_06[1];
    func_0209786c(out);
    out->unk_1e = out->unk_0a;
    out->unk_20 = out->unk_0c;
}

/* Converts observed record fields to the 60-byte work record; a zero id leaves out untouched. */
void func_021068dc(u16 id, Unk100810Result *out)
{
    Unk100810Meta *meta;
    if (id == 0) return;
    meta = func_020a1428(id);
    func_02008848(out, 0, 60);
    out->unk_38 = meta->unk_03;
    CopyRecordBytes(&out->bytes_28, &meta->bytes_2e);
    out->id = id;
    out->unk_24 = 0;
    out->unk_00 = meta->unk_14;
    out->unk_02 = meta->unk_16.value;
    out->stats[0] = meta->stats[0];
    out->stats[1] = meta->stats[1];
    out->stats[2] = meta->stats[2];
    out->stats[3] = meta->stats[3];
    out->stats[4] = meta->stats[4];
    out->unk_14 = 0;
    out->unk_16 = 0;
    out->stats_18[0] = meta->stats[0];
    out->stats_18[1] = meta->stats[1];
    out->stats_18[2] = meta->stats[2];
    out->stats_18[3] = meta->stats[3];
    out->stats_18[4] = meta->stats[4];
    func_0209786c(out);
    out->unk_1e = out->unk_0a;
    out->unk_20 = out->unk_0c;
}

/* Counts observed record flags and returns their percentage, clamped to 100, with a minimum of one for a nonzero numerator. */
u32 func_02106ec0(void)
{
    u32 count = 0;
    u32 total = 0;
    Unk100810Meta *meta;
    u16 i;
    for (i = 0; i < 0x1ea; i++) {
        meta = func_020a1740((u16)(i + 1));
        if (meta == 0) continue;
        if (Unk02e000_IsRecordAvailable(meta->id) != 0) count++;
        if (meta->unk_16.bits.low) total++;
    }
    {
        u32 result = count * 100 / total;
        if (result == 0 && count != 0) result = 1;
        if (result > 100) result = 100;
        return result;
    }
}

/* Counts observed record flags and returns their percentage, clamped to 100, with a minimum of one for a nonzero numerator. */
u32 func_02106e10(void)
{
    u32 count = 0;
    u32 total = 0;
    Unk100810Meta *meta;
    u16 i;
    for (i = 0; i < 0x1ea; i++) {
        meta = func_020a1428((u16)(i + 1));
        if (meta == 0) continue;
        if (Unk02e000_GetRecordFlag1(meta->id) != 0) {
            if (!meta->unk_08.bits.high_low) count++;
        }
        if (meta->unk_08.bits.low) {
            if (!meta->unk_08.bits.high_low) total++;
        }
    }
    {
        u32 result = count * 100 / total;
        if (result == 0 && count != 0) result = 1;
        if (result > 100) result = 100;
        return result;
    }
}

/* Message payload: two flag bytes and sixteen words, initialized by the wrapper. */
typedef struct Unk100810Message {
    u8 flags[2];
    u8 pad_02[2];
    u32 words[16];
} Unk100810Message;

int Unk02e000_SetRecord(u16 id, Unk100810Saved *saved);
void func_020d6cac(Unk100810Bytes *bytes);
void CampStatus_Copy12c(Unk100810Result *record);
void func_020bcbc4(int kind, Unk100810Message *message);

/* Builds the selected work record and publishes message kind 3 with word 1 set to 22. */
void func_021065fc(Unk100810Input *input)
{
    Unk100810Result result;
    Unk100810Saved saved;
    Unk100810Message message;
    int i;
    if (input->id == 0) {
        func_02008848(&result, 0, 60);
        func_020d6cac(&result.bytes_28);
    } else if (Unk100810_IsField50One()) {
        if (Unk02e000_SetRecord(input->id, &saved)) {
            func_021067e8(&saved, input->id, &result);
            func_020d6cac(&result.bytes_28);
        }
        func_021066f0(input, &result);
    } else {
        func_021066f0(input, &result);
        func_020d6cac(&result.bytes_28);
    }
    CampStatus_Copy12c(&result);
    for (i = 0; i < 2; i++) message.flags[i] = 0;
    for (i = 0; i < 16; i++) message.words[i] = 0;
    message.words[1] = 22;
    message.flags[0] |= 2;
    func_020bcbc4(3, &message);
}

/* Drawing descriptor: signed position and width fields used by the fixed point calculations. */
typedef struct Unk100810Draw {
    u8 pad_00[10];
    s16 x;
    u8 pad_0c[2];
    s16 width;
    u8 pad_10[8];
} Unk100810Draw;

const Unk100810Draw *func_0205e318(u32 handle, int index);
void func_0205e048(int kind, u32 handle, Unk100810Draw *draw, u32 arg,
                  int zero, float a, float b, int zero2, float c, int mode, int zero3);

/* Scales descriptor 105 to a 116-unit bar and positions it using signed 12-bit fixed point ratios. */
void func_021069f0(u32 handle, s32 total, s32 value, s32 offset, u32 arg)
{
    Unk100810Draw draw;
    func_02008904(func_0205e318(handle, 105), &draw, 24);
    if (total < value) total = value;
    draw.width = ((value << 12) / total * 116) >> 12;
    draw.x += (((offset << 12) / (total - value) * (116 - draw.width)) << 4) >> 16;
    func_0205e048(2, handle, &draw, arg, 0, 1.0f, 1.0f, 0, 1.0f, 4, 0);
}

/* Signed byte view of the 60-byte record, evidenced by the save-path ldrsb instructions. */
typedef struct Unk100810SaveSource {
    u8 pad_00[14];
    s8 stats[5];
    u8 pad_13[5];
    s8 stats_18[5];
    u8 pad_1d[7];
    u32 unk_24;
    Unk100810Bytes bytes_28;
    u16 unk_34, id;
    u8 unk_38;
    u8 pad_39[3];
} Unk100810SaveSource;

/* The work area has 60-byte records at +0x74 and signed slot indices at +0x348. */
typedef struct Unk100810Area {
    u8 pad_00[0x74];
    Unk100810Result records[12];
    u8 pad_344[4];
    s8 slots[15];
    u8 count;
} Unk100810Area;

/* Three 40-byte saved records begin at +0x5c08 in this accessor's object. */
typedef struct Unk100810Storage {
    u8 pad_00[0x5c08];
    Unk100810Input records[3];
} Unk100810Storage;

Unk100810Storage *Unk02e000_Unk_02e774(void);
Unk100810Area *Unk02e000_GetWorkArea(void);
Unk100810SaveSource *Unk02e000_GetAreaRecord(int index);
void Unk02e000_GetRecord(u16 id, Unk100810Saved *saved);
u32 Unk02e000_GetRecordUnk1e(u16 id);
void func_0200866c(const void *source, void *dest, u32 size);
void func_02008644(int value, void *dest, u32 size);
u32 func_0204fe68(u32 handle, int index);
void Unk0d297c_Unk_0d33ac(void *list);
void Unk0d297c_Unk_0d3308(void *list);
void func_020d33cc(void *list, u32 value);
s32 CampStatus_GetUnkField1c(void *list);
int CampStatus_Unk_0d34e4(void *list, u16 index);
void func_02053000(u32 handle);
void Unk044394_Unk_044534(int id);
void func_0205bb68(void);
void func_0205ddb4(u32 handle);
void func_0205c368(u32 handle);
void func_0205c3dc(u32 handle);
void func_020629c4(u32 handle);
void func_02061424(u32 handle);

/* Releases observed work handles and the embedded list; clears the global work pointer. */
void func_02104604(Unk100810Work *work)
{
    int i;
    Unk0d297c_Unk_0d33ac(work->unk_2004);
    func_02053000(work->unk_20b4);
    work->unk_20b4 = 0;
    Unk044394_Unk_044534(21);
    Unk044394_Unk_044534(17);
    Unk044394_Unk_044534(16);
    func_0205bb68();
    func_0205bb68();
    if (work->unk_0000) { func_0205ddb4(work->unk_0000); work->unk_0000 = 0; }
    if (work->unk_0040) { func_0205c368(work->unk_0040); work->unk_0040 = 0; }
    if (work->unk_0044) { func_0205c3dc(work->unk_0044); work->unk_0044 = 0; }
    func_020629c4(work->unk_0020);
    if (work->unk_0020) work->unk_0020 = 0;
    func_020629c4(work->unk_0024);
    if (work->unk_0024) work->unk_0024 = 0;
    func_020629c4(work->unk_0028);
    if (work->unk_0028) work->unk_0028 = 0;
    func_020629c4(work->unk_0030);
    if (work->unk_0030) work->unk_0030 = 0;
    func_020629c4(work->unk_0034);
    if (work->unk_0034) work->unk_0034 = 0;
    func_020629c4(work->unk_002c);
    if (work->unk_002c) work->unk_002c = 0;
    func_020629c4((u32)work->unk_0038);
    if (work->unk_0038) work->unk_0038 = 0;
    for (i = 0; i < 2; i++) {
        func_02061424(work->handles_1f38.handles[i]);
        work->handles_1f38.handles[i] = 0;
    }
    data_02176e2c = 0;
}

/* Builds two three-entry text lists from the saved ids and their metadata byte at +2. */
void func_02105690(Unk100810Work *work)
{
    u32 names, kinds;
    int i;
    u16 ids[3];
    u32 text;
    names = func_020445f4(18, 1);
    kinds = func_020445f4(18, 0);
    func_02008644(0, ids, 6);
    for (i = 0; i < 3; i++) {
        /* Taking the array base first matches; indexing ->records[i] directly reorders the adds. */
        Unk100810Input *records = Unk02e000_Unk_02e774()->records;
        ids[i] = records[i].id;
    }
    func_02063920();
    for (i = 0; i < 3; i++) {
        func_0204fed8(names, ids[i]);
        text = func_02063a30();
    }
    if (text) func_02061f10(work->unk_0030, -1, 0, 0, text);
    func_02063920();
    for (i = 0; i < 3; i++) {
        func_0204fed8(kinds, func_020a1428(ids[i])->unk_02);
        text = func_02063a30();
    }
    if (text) func_02061f10(work->unk_0034, -1, 0, 0, text);
}

/* Rebuilds up to twelve visible list entries; a missing key resets the embedded list to key zero. */
void func_02106d0c(Unk100810Work *work, u32 key)
{
    u32 table, text;
    int count, i;
    table = func_0204fe68(work->unk_20b4, 0);
    i = func_0204fed8(table, key);
    if (!i) {
        i = func_0204fed8(table, 0);
    }
    Unk0d297c_Unk_0d33ac(work->unk_2004);
    Unk0d297c_Unk_0d3308(work->unk_2004);
    func_020d33cc(work->unk_2004, i);
    work->unk_202c = CampStatus_GetUnkField1c(work->unk_2004);
    func_02063920();
    count = 0;
    for (i = work->unk_2028; i < work->unk_2028 + 12; i++) {
        if (i >= work->unk_202c) break;
        if (!CampStatus_Unk_0d34e4(work->unk_2004, (u16)i)) continue;
        text = func_02063a30();
        if (++count >= 12) break;
    }
    func_02061f10(work->unk_002c, -1, 0, 0, text);
}

/* Updates the saved record from its matching active slot; absent ids leave storage untouched. */
void func_02105c44(u16 id)
{
    Unk100810Area *area;
    int i;
    Unk100810SaveSource *record;
    Unk100810Saved saved;
    area = Unk02e000_GetWorkArea();
    for (i = 0; i < area->count; i++) {
        int index = area->slots[i];
        if (index < 0) continue;
        if (id == area->records[index].id) break;
    }
    if (i == area->count) return;
    record = Unk02e000_GetAreaRecord(area->slots[i]);
    if (!Unk02e000_SetRecord(id, &saved)) return;
    saved.unk_00 = record->unk_38;
    saved.unk_20 = record->unk_24;
    saved.stats[0] = record->stats[0];
    saved.stats_06[0] = record->stats_18[0];
    saved.stats[1] = record->stats[4];
    saved.stats_06[1] = record->stats_18[4];
    saved.stats[2] = record->stats[1];
    saved.stats_06[2] = record->stats_18[1];
    saved.stats[3] = record->stats[2];
    saved.stats_06[3] = record->stats_18[2];
    saved.stats[4] = record->stats[3];
    saved.stats_06[4] = record->stats_18[3];
    func_0200866c(&record->bytes_28, &saved.bytes_10, 12);
    Unk02e000_GetRecord(id, &saved);
}

/* Writes one of three saved slots from the observed signed fields; indices must be 0..2. */
void func_02105d54(Unk100810SaveSource *record, int index)
{
    Unk100810Input *slot;
    Unk100810Saved saved;
    if (index < 0) return;
    if (index >= 3) return;
    slot = &Unk02e000_Unk_02e774()->records[index];
    func_02008848(&saved, 0, 36);
    saved.unk_00 = record->unk_38;
    saved.unk_20 = record->unk_24;
    saved.stats[0] = record->stats[0];
    saved.stats_06[0] = record->stats_18[0];
    saved.stats[1] = record->stats[4];
    saved.stats_06[1] = record->stats_18[4];
    saved.stats[2] = record->stats[1];
    saved.stats_06[2] = record->stats_18[1];
    saved.stats[3] = record->stats[2];
    saved.stats_06[3] = record->stats_18[2];
    saved.stats[4] = record->stats[3];
    saved.stats_06[4] = record->stats_18[3];
    func_0200866c(&record->bytes_28, &saved.bytes_10, 12);
    saved.unk_1e = (u8)Unk02e000_GetRecordUnk1e(record->id);
    func_02008848(&slot->unk_04, 0, 36);
    slot->id = record->id;
    func_02008904(&saved, &slot->unk_04, 36);
}

extern const char data_02151230[], data_02151234[], data_02151238[], data_0215123c[];
extern const char data_02151240[], data_02151244[];
void func_020aa078(u32 handle, int kind, int x, int y, int zero,
                   int width, u32 style, const char *format, ...);

/* Draws two values (??? above 999), a two-digit field and an eight-digit hex field; formats are original strings. */
void func_02106f50(Unk100810Handle *handle, u32 a, u32 b, u32 c, u32 d, u8 row, u32 style)
{
    int y;
    if (a > 999) {
        y = row * 10;
        func_020aa078(handle->unk_00, 1, 4, y, 0, 3, style, data_02151230);
    } else {
        y = row * 10;
        func_020aa078(handle->unk_00, 1, 4, y, 0, 3, style, data_02151234, a);
    }
    if (b > 999) {
        func_020aa078(handle->unk_00, 1, 26, y, 0, 3, style, data_02151238);
    } else {
        func_020aa078(handle->unk_00, 1, 26, y, 0, 3, style, data_0215123c, b);
    }
    func_020aa078(handle->unk_00, 1, 48, y, 0, 2, style, data_02151240, c);
    func_020aa078(handle->unk_00, 1, 71, y, 0, 9, style, data_02151244, d);
}

int func_021002e8(const Unk100810Record *a, const Unk100810Record *b);
int func_02100298(const Unk100810Record *a, const Unk100810Record *b);
int Unk100208_Unk_1003d8(const Unk100810Record *a, const Unk100810Record *b);
int Unk100208_Unk_100398(const Unk100810Record *a, const Unk100810Record *b);
int Unk100414_Unk_100414(const Unk100810Record *a, const Unk100810Record *b);
int Unk100208_Unk_1003b8(const Unk100810Record *a, const Unk100810Record *b);
void func_02013c68(Unk100810Record *records, u32 count, u32 stride,
                   int (*compare)(const Unk100810Record *, const Unk100810Record *));
void func_02104f88(Unk100810Table *work);

/* Sorts 0x1eb records using the selected mode, then publishes the current selection or saved slot. */
void func_02106b24(Unk100810Table *work)
{
    Unk100810Message message;
    int i, boundary, selected;
    if (work->unk_0058 == 0) {
        if (work->unk_2000) func_02013c68(work->records, 0x1eb, 16, func_021002e8);
        else func_02013c68(work->records, 0x1eb, 16, func_02100298);
    } else if (work->unk_0058 == 1) {
        if (work->unk_2000) func_02013c68(work->records, 0x1eb, 16, Unk100208_Unk_1003d8);
        else func_02013c68(work->records, 0x1eb, 16, Unk100208_Unk_100398);
        func_02106aac(work);
    } else if (work->unk_0058 == 2) {
    } else if (work->unk_0058 == 3) {
        if (work->unk_2000) func_02013c68(work->records, 0x1eb, 16, Unk100414_Unk_100414);
        else func_02013c68(work->records, 0x1eb, 16, Unk100208_Unk_1003b8);
        func_02106aac(work);
    }
    for (i = 0; i < 2; i++) message.flags[i] = 0;
    for (i = 0; i < 16; i++) message.words[i] = 0;
    func_02104f88(work);
    boundary = work->unk_0008 - 3;
    selected = work->unk_0014;
    if (selected < boundary) {
        message.words[1] = 20;
        message.flags[0] |= 2;
        message.words[7] = work->unk_1f18[work->unk_0014 - work->unk_000c];
        message.flags[0] |= 128;
        if (work->unk_2000) {
            message.words[6] = 1;
            message.flags[0] |= 64;
        }
        func_020bcbc4(3, &message);
    } else {
        func_021065fc(&Unk02e000_Unk_02e774()->records[selected - boundary]);
    }
}

/* Populates up to ten ids at +0x1f18, then draws metadata for the first nine rows. */
void func_021057ac(Unk100810Table *work)
{
    u16 i;
    int count;
    int first;
    u32 text;
    u32 names, kinds;
    count = 0;
    first = work->unk_000c;
    func_02063920();
    text = 0;
    func_02008644(text, work->unk_1f18, 18);
    names = func_020445f4(18, 1);
    kinds = func_020445f4(18, 0);
    for (i = 0; i < 0x1eb; i++) {
        if (Unk02e000_IsRecordAvailable(work->records[i].id)) {
            if (count >= first) {
                work->unk_1f18[count - first] = work->records[i].id;
                func_0204fed8(names, work->records[i].id);
                text = func_02063a30();
            }
            count++;
            if (count - first > 9) break;
        }
    }
    if (text) func_02061f10(work->unk_0024, -1, 0, 0, text);
    func_02063920();
    {
        u16 j;
        int seen = 0;
        for (j = 0; j < 0x1eb; j++) {
            if (Unk02e000_IsRecordAvailable(work->records[j].id)) {
                if (seen >= first) {
                    func_0204fed8(kinds, work->records[j].unk_02);
                    text = func_02063a30();
                }
                seen++;
                if (seen - first > 9) break;
            }
        }
    }
    if (text) func_02061f10(work->unk_0028, -1, 0, 0, text);
    for (i = 0; i < 9; i++) {
        if (Unk02e000_IsRecordAvailable(work->unk_1f18[i])) {
            Unk100810Meta *meta = func_020a1740(work->unk_1f18[i]);
            if (meta->unk_16.bits.second) {
                func_02106f50(work->unk_0038, 1000, 1000, meta->unk_02, 0, (u8)i, work->unk_003c);
            } else {
                func_02106f50(work->unk_0038, (u16)meta->unk_04, (u16)meta->unk_08.value,
                              meta->unk_02, 0, (u8)i, work->unk_003c);
            }
        }
    }
    work->unk_0038->unk_40 = 2;
}
