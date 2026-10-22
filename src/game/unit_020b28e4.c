/* src/game/unit_020b28e4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object referenced by the first word of data_02176b80. Fields and embedded
   blocks follow the cleanup, dispatch, paging and setter accesses; their gameplay
   meanings are unknown. Three resource slots follow the cleanup loop bound. */
typedef struct Unk0b28e4Obj {
    u8 pad_0000[4];
    void *unk_0004;
    void *unk_0008;
    u8 pad_000c[4];
    u8 unk_0010[0x14];
    void *unk_0024;
    void *unk_0028;
    void *unk_002c;
    u8 unk_0030[0x180];
    u8 unk_01b0[0x60];
    u8 unk_0210[0xc0];
    u8 unk_02d0[0xc30 - 0x2d0];
    void *unk_0c30;
    void *unk_0c34;
    u8 pad_0c38[4];
    void *unk_0c3c[3];
    void *unk_0c48[3];
    void *unk_0c54[3];
    void *unk_0c60[3];
    s8 unk_0c6c;
    u8 pad_0c6d[11];
    s8 unk_0c78[3];
    u8 pad_0c7b[0x11];
    u32 unk_0c8c;
    u32 unk_0c90;
    u8 pad_0c94[0xc];
    u32 unk_0ca0;
    u32 unk_0ca4;
    u32 unk_0ca8;
} Unk0b28e4Obj;

/* One 12-byte table slot; no member is accessed in this translation unit. */
typedef struct Unk0b28e4Entry {
    u8 pad_00[0xc];
} Unk0b28e4Entry;

/* 44-byte block referenced by the second word of data_02176b80 (allocated with that size in
   Unk0b28e4_Unk_0b62e8). The three-entry array size is guessed from the 36-byte clear. */
typedef struct Unk0b28e4Buf {
    u8 unk_00;
    u8 pad_01;
    u16 unk_02[3];
    Unk0b28e4Entry unk_08[3];
} Unk0b28e4Buf;

/* Structure passed to Unk0b28e4_Unk_0b5e10; only the byte at +0x37 and the word at +0x2c
   are written before it is forwarded to func_0205f7f4. */
typedef struct Unk0b28e4Fields {
    u8 pad_0000[0x2c];
    u32 unk_002c;
    u8 pad_0030[7];
    s8 unk_0037;
} Unk0b28e4Fields;

typedef struct Unk0b28e4Globals {
    Unk0b28e4Obj *unk_0000;
    Unk0b28e4Buf *unk_0004;
} Unk0b28e4Globals;

extern Unk0b28e4Globals data_02176b80;

void func_020b32bc(void);
void func_020b363c(void);
void func_020b3d28(Unk0b28e4Obj *work);
void func_020b2dd0(void);
void func_0205f7f4(Unk0b28e4Fields *fields, u32 a, u32 b, u32 c);
void func_020552ec(int a, int b);
void *func_02052fe0(u32 size);
void Unk0b28e4_Unk_0b6370(void);
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 value, void *req);
void func_020516d0(void *obj);
void Unk0bc1a8_Unk_0bc9b4(u32 slot, u32 value);
void func_02008644(u32 value, void *dst, u32 size);

/* empty callback */
void Unk0b28e4_Nop_0b28e4(void) { }

/* Populates the callback table at `p`: the size word, cleared slots and four callback
   addresses. */
void Unk0b28e4_InitCallbacks(u32 *p)
{
    p[0] = 0xcac;
    p[1] = 0;
    p[3] = (u32)func_020b32bc;
    p[4] = (u32)func_020b363c;
    p[5] = 0;
    p[6] = 0;
    p[7] = (u32)func_020b3d28;
    p[8] = (u32)func_020b2dd0;
}

/* Sets the byte at +0x37 and the word at +0x2c of `fields`, then forwards `fields` and the
   first three arguments to func_0205f7f4. */
void Unk0b28e4_Unk_0b5e10(Unk0b28e4Fields *fields, u32 a, u32 b, u32 c, s8 d, u32 e)
{
    fields->unk_0037 = d;
    fields->unk_002c = e;
    func_0205f7f4(fields, a, b, c);
}

/* Allocates and clears the 44-byte cache at +0x04 when absent, then selects callback set 13. */
void Unk0b28e4_Unk_0b62e8(void)
{
    func_020552ec(6, 3);
    if (data_02176b80.unk_0004 == 0) {
        data_02176b80.unk_0004 = func_02052fe0(44);
        Unk0b28e4_Unk_0b6370();
    }
    Unk0bc1a8_Unk_0bc928(13, 0xffff, 0);
}

/* Frees the object whose address is cached at +0x04 (see Unk0b28e4_Unk_0b62e8), clears the
   cache and restores callback set 13. */
void Unk0b28e4_Unk_0b6338(void)
{
    func_020552ec(6, 1);
    func_020516d0(data_02176b80.unk_0004);
    data_02176b80.unk_0004 = 0;
    Unk0bc1a8_Unk_0bc9b4(13, 0);
}

/* Zeroes the 44-byte block cached at +0x04 (allocated by Unk0b28e4_Unk_0b62e8): byte 0 and
   the two payload areas at +2 (6 bytes) and +8 (36 bytes) are reset to zero. */
void Unk0b28e4_Unk_0b6370(void)
{
    data_02176b80.unk_0004->unk_00 = 0;
    func_02008644(0, data_02176b80.unk_0004->unk_02, 6);
    func_02008644(0, data_02176b80.unk_0004->unk_08, 36);
}

/* Returns the byte pointer cached at +0x04 advanced past its two-byte header. */
u8 *Unk0b28e4_Unk_0b64c8(void)
{
    return (u8 *)data_02176b80.unk_0004->unk_02;
}

/* Returns a pointer to entry `index` (12 bytes each) of the table whose base is the word
   at +0x04; the first entry starts 8 bytes into that block. */
Unk0b28e4Entry *func_020b64dc(int index)
{
    return &data_02176b80.unk_0004->unk_08[index];
}

/* Stores two words at +0xc8c and +0xc90 of the object referenced by the word at +0x00. */
void func_020b64f8(u32 first, u32 second)
{
    data_02176b80.unk_0000->unk_0c8c = first;
    data_02176b80.unk_0000->unk_0c90 = second;
}

/* Stores one word at +0xca0 of the object referenced by the word at +0x00. */
void func_020b6514(u32 value)
{
    data_02176b80.unk_0000->unk_0ca0 = value;
}

/* Byte view of the table indexed by Unk0b28e4_GetEntry34: the caller selects a slot with a
   12-byte index and reads the word 0x34 bytes into the selected base. */
typedef struct Unk0b28e4Indexed {
    u8 pad_0000[0x34];
    u32 unk_0034;
} Unk0b28e4Indexed;

/* Returns the word at +0x34 of slot `i` in table `p`, or 0 when `i` is outside 0..26 or
   `p` is null. */
u32 Unk0b28e4_GetEntry34(u8 *p, int i)
{
    u32 ok = i >= 0;
    if (ok == 0) {
        return 0;
    }
    ok = i < 27;
    if (ok == 0) {
        return 0;
    }
    if (p == 0) {
        return 0;
    }
    return ((Unk0b28e4Indexed *)(p + i * 12))->unk_0034;
}

void func_020629c4(void *resource);
void func_02056cac(u32 bank);
void func_02053000(void *resource);
int func_020537b8(u32 port, u32 mask);
int func_020537dc(u32 port, u32 mask);
void func_0203e93c(u32 mode, u32 x, u32 y, void *a, void *b);

/* Releases the six indexed resources and two handles after freeing four work buffers.
 * Offsets and the three-iteration bound are evidenced by 0x020b3d28's loads. */
void func_020b3d28(Unk0b28e4Obj *work)
{
    int i;
    func_020516d0(work->unk_0004);
    func_020516d0(work->unk_0024);
    func_020516d0(work->unk_0028);
    func_020516d0(work->unk_002c);
    func_020629c4(work->unk_0c30);
    if (work->unk_0c30 != 0) work->unk_0c30 = 0;
    func_020629c4(work->unk_0c34);
    if (work->unk_0c34 != 0) work->unk_0c34 = 0;
    for (i = 0; i < 3; i++) {
        func_02056cac(1);
        func_02053000(work->unk_0c54[i]);
        func_02056cac(1);
        func_02053000(work->unk_0c60[i]);
    }
}

/* Tests masks 0x200 and 0x100 while their work flags are set; dispatches the
 * corresponding embedded block, or clears the flag on the second mask test. */
void func_020b3570(Unk0b28e4Obj *work)
{
    if (work->unk_0ca4 != 0) {
        if (func_020537b8(0, 512) != 0) {
            func_0203e93c(1, 128, 96, work->unk_0010, work->unk_01b0);
        } else if (func_020537dc(0, 512) != 0) {
            work->unk_0ca4 = 0;
        }
    }
    if (work->unk_0ca8 != 0) {
        if (func_020537b8(0, 256) != 0) {
            func_0203e93c(1, 128, 96, work->unk_0010, work->unk_0210);
        } else if (func_020537dc(0, 256) != 0) {
            work->unk_0ca8 = 0;
        }
    }
}

/* Roster fields are evidenced by the byte loads at +0x348 and +0x357. */
typedef struct Unk0b28e4Roster {
    u8 pad_000[0x348];
    s8 unk_348[15];
    u8 unk_357;
} Unk0b28e4Roster;

/* The observed indexed word is +0x36c with stride 0x2e0; leading data is opaque. */
typedef struct Unk0b28e4Record {
    u8 pad_000[0x2e0];
} Unk0b28e4Record;
typedef struct Unk0b28e4RecordBase {
    u8 pad_000[0x36c];
    u32 unk_36c;
} Unk0b28e4RecordBase;
Unk0b28e4Roster *Unk02e000_GetWorkArea(void);
Unk0b28e4Record *Unk044904_Get_data_0215ee98(void);
void *func_02044ec4(u32 id);
int func_0204a244(void *record);
void func_020b5adc(Unk0b28e4Obj *work, int id, int slot);

/* Selects up to three type-1 roster entries after the work-selected page.
 * Negative roster ids terminate the scan, as in the original signed-byte test. */
void func_020b4fb4(Unk0b28e4Obj *work)
{
    int i = 0;
    int slot = 0;
    int count = 0;
    Unk0b28e4Roster *roster = Unk02e000_GetWorkArea();
    for (; slot < 3; i++) {
        if (i >= roster->unk_357) return;
        int id;
        if (roster->unk_348[i] < 0) return;
        func_02044ec4(((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[roster->unk_348[i]])->unk_36c);
        id = roster->unk_348[i];
        if ((((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[id])->unk_36c >> 16 & 255) == 1) {
            if (count >= work->unk_0c6c * 3) {
                func_020b5adc(work, id, slot);
                slot++;
            }
            count++;
        }
    }
}

/* Applies the same three-slot paging as 0x020b4fb4, additionally requiring
 * func_0204a244(record) == 1 before an entry contributes to the page. */
void func_020b5264(Unk0b28e4Obj *work)
{
    int i = 0;
    int slot = 0;
    int count = 0;
    Unk0b28e4Roster *roster = Unk02e000_GetWorkArea();
    for (; slot < 3; i++) {
        if (i >= roster->unk_357) return;
        void *record;
        if (roster->unk_348[i] < 0) return;
        record = func_02044ec4(((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[roster->unk_348[i]])->unk_36c);
        if ((((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[roster->unk_348[i]])->unk_36c >> 16 & 255) == 1 && func_0204a244(record) == 1) {
            if (count >= work->unk_0c6c * 3) {
                func_020b5adc(work, roster->unk_348[i], slot);
                slot++;
            }
            count++;
        }
    }
}

const char *Unk0a163c_Unk_0a1798(u32 id);
int func_02013c3c(char *dst, const char *format, const char *name);
void *func_02051610(const char *path);
void Unk03e43c_CopyEntry32(void *entry, u32 slot);
void Unk03e43c_Call_02056cc0(void);
void *func_02056c54(u32 a, void *data, u32 b, u32 c, u32 d);
extern const char data_0214ff94[];
extern const char data_0214ffc0[];

/* Formats two resource paths, copies two 32-byte entries to consecutive slots,
 * offsets nonzero bytes in a 512-byte resource by slot*16, and uploads it. */
void *func_020b5e2c(u32 id, u32 slot)
{
    char pathA[50];
    char pathB[50];
    void *entries;
    s8 *bytes;
    u8 offset;
    int i;
    void *result;
    func_02013c3c(pathA, data_0214ff94, Unk0a163c_Unk_0a1798(id));
    func_02013c3c(pathB, data_0214ffc0, Unk0a163c_Unk_0a1798(id));
    entries = func_02051610(pathA);
    Unk03e43c_CopyEntry32(entries, slot);
    Unk03e43c_CopyEntry32((u8 *)entries + 32, (slot + 1) & 255);
    func_020516d0(entries);
    Unk03e43c_Call_02056cc0();
    offset = slot << 4;
    bytes = func_02051610(pathB);
    for (i = 0; i < 512; i++) {
        if (bytes[i] != 0) bytes[i] += offset;
    }
    result = func_02056c54(1, bytes, 4, 32, 16);
    func_020516d0(bytes);
    return result;
}

extern const char data_021500ec[], data_02150118[];
extern const char data_02150144[], data_02150170[];
void func_02008848(void *dst, int value, u32 size);
void *func_02056d88(u32 bank, void *target, void *data, u32 mode, u32 flags);

/* Expands 128 signed packed bytes into 256 palette indices in caller-owned
 * storage, then uploads them. Paths and nibble order follow 0x020b6104. */
void *func_020b6104(const char *name, u32 slot, u8 *dst)
{
    char pathA[40];
    char pathB[40];
    void *entry;
    u8 offset;
    s8 *bytes;
    int i;
    void *result;
    func_02013c3c(pathA, data_021500ec, name);
    func_02013c3c(pathB, data_02150118, name);
    entry = func_02051610(pathA);
    Unk03e43c_CopyEntry32(entry, slot);
    func_020516d0(entry);
    Unk03e43c_Call_02056cc0();
    offset = slot << 4;
    bytes = func_02051610(pathB);
    for (i = 0; i < 256; i++) {
        if (i % 2 == 0) dst[i] = bytes[i >> 1] & 15;
        else dst[i] = (bytes[i >> 1] >> 4) & 15;
        if (dst[i] != 0) dst[i] += offset;
    }
    result = func_02056c54(1, dst, 4, 16, 16);
    func_020516d0(bytes);
    return result;
}

/* Expands the resource into the caller's 256-byte buffer and updates an
 * existing target; 0x020b61f0 clears the buffer before nibble conversion. */
void *func_020b61f0(const char *name, u32 slot, void *target, u8 *dst)
{
    char pathA[40];
    char pathB[40];
    void *entry;
    u8 offset;
    s8 *bytes;
    int i;
    func_02013c3c(pathA, data_02150144, name);
    func_02013c3c(pathB, data_02150170, name);
    entry = func_02051610(pathA);
    Unk03e43c_CopyEntry32(entry, slot);
    func_020516d0(entry);
    Unk03e43c_Call_02056cc0();
    offset = slot << 4;
    bytes = func_02051610(pathB);
    func_02008848(dst, 0, 256);
    for (i = 0; i < 256; i++) {
        if (i % 2 == 0) dst[i] = bytes[i >> 1] & 15;
        else dst[i] = (bytes[i >> 1] >> 4) & 15;
        if (dst[i] != 0) dst[i] += offset;
    }
    func_020516d0(bytes);
    return func_02056d88(1, target, dst, 0, 0);
}

/* Draws up to three decimal digits from 96-byte entries; values above 999
 * use entry 20 three times. Coordinates wrap as bytes, as at 0x020b5ccc. */
void func_020b5ccc(void *target, u8 *entries, u32 value, u8 x, u8 y, u8 align)
{
    int divisor;
    if (value > 999) {
        func_0203e93c(1, x, y, target, entries + 1920);
        func_0203e93c(1, (u8)(x + 5), y, target, entries + 1920);
        func_0203e93c(1, (u8)(x + 10), y, target, entries + 1920);
        return;
    }
    divisor = 100;
    if (value < 10) {
        divisor = 1;
        if (align == 2) x += 5;
        else if (align == 3) x += 10;
    } else if (value < 100) {
        divisor = 10;
        if (align == 3) x += 5;
    }
    for (; divisor > 0; divisor /= 10) {
        u32 digit = value / divisor;
        func_0203e93c(1, x, y, target, entries + (digit + 10) * 96);
        value -= digit * divisor;
        x += 5;
    }
}

/* Eight-byte draw request passed by address to the 0x020569e4 family. */
typedef struct Unk0b28e4DrawRequest { u32 words[2]; } Unk0b28e4DrawRequest;
void func_020569e4(Unk0b28e4DrawRequest *req, u32 bank, u32 flags, void *resource, u32 a, u32 b);
void func_02056b94(Unk0b28e4DrawRequest *req, u32 x, u32 y);
void func_02056bbc(Unk0b28e4DrawRequest *req, u32 mode);
void func_02056bec(Unk0b28e4DrawRequest *req);
void func_02056954(u32 bank, Unk0b28e4DrawRequest *req, u32 mode, u32 flags);
u32 func_02049d80(void *record, u32 field);
int Unk044904_Unk_044f4c(u32 id);

/* First record header: the type-bearing word is loaded at +0x8c by 0x020b593c. */
typedef struct Unk0b28e4FirstRecord {
    u8 pad_000[0x8c];
    u32 unk_08c;
} Unk0b28e4FirstRecord;

/* Uses the first record header at +0x8c; the draw resources are caller-owned. */
void func_020b593c(Unk0b28e4Obj *work)
{
    void *record;
    u32 a, b, c;
    int state;
    Unk0b28e4DrawRequest req;
    u32 id = ((Unk0b28e4FirstRecord *)Unk044904_Get_data_0215ee98())->unk_08c;
    if (((id >> 16) & 255) != 1) return;
    record = func_02044ec4(id);
    func_020569e4(&req, 1, 0x80004000, work->unk_0c3c[0], 0, 0);
    func_02056b94(&req, 1, 17);
    func_02056bbc(&req, 2);
    func_02056954(1, &req, 1, 0);
    a = func_02049d80(record, 2);
    b = func_02049d80(record, 0);
    c = func_02049d80(record, 1);
    func_020b5ccc(work->unk_0010, work->unk_0030, a, 49, 29, 2);
    func_020b5ccc(work->unk_0010, work->unk_0030, b, 81, 29, 3);
    func_020b5ccc(work->unk_0010, work->unk_0030, c, 121, 29, 3);
    state = func_0204a244(record);
    if (state < 1) return;
    if (state > 11) return;
    func_020569e4(&req, 1, 0x40000000, work->unk_0c48[0], 0, 0);
    func_02056bec(&req);
    func_02056b94(&req, 21, 29);
    func_02056bbc(&req, 1);
    func_02056954(1, &req, 1, 0);
}

/* Draws an indexed type-1 record in a 56-pixel row, with three numeric fields
 * and conditional markers. Evidence: 0x020b5adc's stride and draw calls. */
void func_020b5adc(Unk0b28e4Obj *work, int id, int slot)
{
    u32 key = ((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[id])->unk_36c;
    u32 *record;
    u32 a, b, c;
    int row, y, state;
    Unk0b28e4DrawRequest req;
    if (((key >> 16) & 255) != 1) return;
    record = func_02044ec4(key);
    func_020569e4(&req, 1, 0x80004000, work->unk_0c3c[slot], 0, 0);
    row = slot * 56;
    func_02056b94(&req, 1, row + 17);
    func_02056bbc(&req, 2);
    func_02056954(1, &req, 1, 0);
    a = func_02049d80(record, 2);
    b = func_02049d80(record, 0);
    c = func_02049d80(record, 1);
    y = row + 29;
    func_020b5ccc(work->unk_0010, work->unk_0030, a, 49, y, 2);
    func_020b5ccc(work->unk_0010, work->unk_0030, b, 81, y, 3);
    func_020b5ccc(work->unk_0010, work->unk_0030, c, 121, y, 3);
    if (Unk044904_Unk_044f4c(record[0]) >= 0)
        func_0203e93c(1, 128, row + 96, work->unk_0010, work->unk_02d0);
    state = func_0204a244(record);
    if (state < 1) return;
    if (state > 11) return;
    func_020569e4(&req, 1, 0x40000000, work->unk_0c48[slot], 0, 0);
    func_02056bec(&req);
    func_02056b94(&req, 21, y);
    func_02056bbc(&req, 1);
    func_02056954(1, &req, 1, 0);
}

void func_020119c0(void *dst, int value, u32 size);
void func_020b5634(Unk0b28e4Obj *work, int id, int slot);
void func_020b5338(Unk0b28e4Obj *work);
void func_0203f2d4(void *a, int x, int y, void *b, int c, int d, int width, int height);
u32 func_02049398(u32 id);
int func_02061a04(u32 bank, u32 id, u32 flags);
void Unk03e43c_Unk_03f2bc(u32 id);

/* Scans type-1 roster entries using three-entry paging, clears other rows,
 * and draws the page label. Out-of-range and negative ids clear a row. */
void func_020b4dd8(Unk0b28e4Obj *work)
{
    int i = 0;
    int slot = 0;
    int count = 0;
    Unk0b28e4Roster *roster;
    int width;
    func_020119c0(work->unk_0c78, -1, 3);
    roster = Unk02e000_GetWorkArea();
    for (; slot < 3; i++) {
        int id;
        if (i < roster->unk_357 && roster->unk_348[i] >= 0) {
        func_02044ec4(((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[roster->unk_348[i]])->unk_36c);
        id = roster->unk_348[i];
        if ((((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[id])->unk_36c >> 16 & 255) == 1) {
            if (count >= work->unk_0c6c * 3) {
                func_020b5634(work, id, slot);
                work->unk_0c78[slot] = roster->unk_348[i];
                slot++;
            }
            count++;
        }
        } else {
            func_0203f2d4(work->unk_0008, 0, slot * 56 + 16, work->unk_0004, 0, 72, 256, 56);
            slot++;
        }
    }
    width = func_02061a04(1, func_02049398(4), 0);
    func_0203f2d4(work->unk_0008, 64, 0, work->unk_0004, 0, 0, 64, 16);
    func_0203f2d4(work->unk_0008, 128, 0, work->unk_0004, 0, 0, 64, 16);
    Unk0b28e4_Unk_0b5e10(work->unk_0c30, func_02049398(4), (u8)((256-width)/2), 0, 12, 10);
    Unk03e43c_Unk_03f2bc(6);
}

/* Maps the work-selected page to three roster positions, reserving its first
 * row on page 1, then draws the label. Evidence: 0x020b49cc's index formula. */
void func_020b49cc(Unk0b28e4Obj *work)
{
    int slot;
    Unk0b28e4Roster *roster;
    int y, width;
    func_020119c0(work->unk_0c78, -1, 3);
    roster = Unk02e000_GetWorkArea();
    for (slot = 0, y = 16; slot < 3; y += 56, slot++) {
        int i = slot + (work->unk_0c6c - 1) * 3 - 1;
        if (work->unk_0c6c == 1 && slot == 0) {
            func_020b5338(work);
        } else if (i < roster->unk_357 && roster->unk_348[i] >= 0) {
            int id = roster->unk_348[i];
            Unk044904_Get_data_0215ee98();
            if ((((Unk0b28e4RecordBase *)&Unk044904_Get_data_0215ee98()[id])->unk_36c >> 16 & 255) != 1) {
                func_0203f2d4(work->unk_0008, 0, y, work->unk_0004, 0, 72, 256, 56);
            } else {
                func_020b5634(work, id, slot);
                work->unk_0c78[slot] = id;
            }
        } else {
            func_0203f2d4(work->unk_0008, 0, y, work->unk_0004, 0, 72, 256, 56);
        }
    }
    width = func_02061a04(1, func_02049398(2), 0);
    func_0203f2d4(work->unk_0008, 64, 0, work->unk_0004, 0, 0, 64, 16);
    func_0203f2d4(work->unk_0008, 128, 0, work->unk_0004, 0, 0, 64, 16);
    Unk0b28e4_Unk_0b5e10(work->unk_0c30, func_02049398(2), (u8)((256-width)/2), 0, 12, 10);
    Unk03e43c_Unk_03f2bc(6);
}
