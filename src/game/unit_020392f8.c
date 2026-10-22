/* src/game/unit_020392f8.c: YDM dungeon resource loading and section accessors.
 *
 * YDM files are the per-dungeon resources named by the "Data/Dungeon/Ydm/..."
 * strings below.  This TU builds the requested path, maps the file, and keeps
 * pointers to the file's four variable-length sections.
 */
#include "types.h"


int func_02008848();
int func_020516d0();

/* Releases the mapped file held in *arg0 and then clears the whole 20-byte
 * YdmFile object (the object is passed as its first word).  A null object is
 * a no-op, matching the callers that release an optional resource. */
void Unk0392f8_Unk_039454(u32 *arg0)
{
  if (arg0 == (u32 *)0x0) {
    return;
  }
  func_020516d0(*arg0);
  func_02008848(arg0,0,0x14);
}

/* Path format strings, read from the retail ARM9 image at these addresses. */
extern char data_021420d8[];   /* "Data/Dungeon/Ydm/%s_%02d_ydm.cmp" */
extern char data_021420fc[];   /* "Data/Dungeon/Ydm/%s_dk%02d_ydm.cmp" */
extern char data_02142120[];   /* "Data/Dungeon/Ydm/Map_dk_dummy_ydm.cmp" */
extern char data_02142148[];   /* "Data/Dungeon/Ydm/%s_dm%02d_%02d_ydm.cmp" */
void func_02013c3c(char *buf, const char *fmt, ...);
int func_020513d4(const char *path);
u8 *func_02051610(const char *path);

/* Header of a mapped YDM file.  The counts are read by func_020392f8 to walk
 * the sections; the grid rectangle is used by Unk0392f8_Unk_0394b8. */
typedef struct YdmHeader {
    u8 pad_00[6];
    s8 count6;                  /* +6: number of 16-byte records */
    u8 count7;                  /* +7: number of 36-byte records */
    u8 count8;                  /* +8: number of 8-byte records */
    u8 gridX;                   /* +9: section-3 grid origin */
    u8 gridY;                   /* +10 */
    u8 gridW;                   /* +11 */
    u8 gridH;                   /* +12 */
} YdmHeader;

/* A mapped YDM file: header first, then the four section base pointers.
 * Every section starts after the preceding section's records plus a 4-byte
 * terminator, as computed by func_020392f8. */
typedef struct YdmFile {
    YdmHeader *header;          /* +0x00 */
    u8 *sec0;                   /* +0x04: 16-byte records */
    u8 *sec1;                   /* +0x08: 36-byte records */
    u8 *sec2;                   /* +0x0C: 8-byte records */
    u8 *sec3;                   /* +0x10: 16-bit grid */
} YdmFile;

/* Builds the YDM path selected by kind, maps it, and fills ydm's header and
 * section pointers.  Returns 1 on success and 0 for a null output, a missing
 * file, or a failed map.  kind 0 selects the stage file; kind 1 selects the
 * dark stage when dark == 1 and the dummy map otherwise; kind 2 selects the
 * two-index file using both floor and extra. */
int func_020392f8(YdmFile *ydm, const char *name, int floor, int extra, int dark, int kind)
{
    char path[64];
    int i;
    u8 *data;
    u8 *p;

    if (ydm == 0) {
        return 0;
    }
    { u32 n = 16; char *q = path;
    do { q[0] = 0; q[1] = 0; q[2] = 0; q[3] = 0; q += 4; } while (--n != 0); }
    switch (kind) {
    case 0:
        func_02013c3c(path, data_021420d8, name, floor);
        break;
    case 1:
        if (dark == 1) {
            func_02013c3c(path, data_021420fc, name, floor);
        } else {
            func_02013c3c(path, data_02142120);
        }
        break;
    case 2:
        func_02013c3c(path, data_02142148, name, floor, extra);
        break;
    }
    if (func_020513d4(path) == 0) {
        return 0;
    }
    data = func_02051610(path);
    if (data == 0) {
        return 0;
    }
    ydm->header = (YdmHeader *)data;
    p = data + 0x14;
    ydm->sec0 = p;
    p = p + ydm->header->count6 * 0x10 + 4;
    ydm->sec1 = p;
    p = p + ydm->header->count7 * 0x24 + 4;
    ydm->sec2 = p;
    ydm->sec3 = p + ydm->header->count8 * 8 + 4;
    return 1;
}

typedef struct Unk0392f8Entry {
    u32 unk_00;
    u32 unk_04;
} Unk0392f8Entry;

/* Returns the i-th 36-byte record of section 1, or NULL when i is past the
 * header's section-1 count (byte at +7). */
u8 *Unk0392f8_GetEntry36(YdmFile *ydm, u32 i)
{
    if (ydm->header->count7 <= i) {
        return 0;
    }
    return ydm->sec1 + i * 36;
}

/* Returns the i-th 8-byte record of section 2, or NULL when i is past the
 * header's section-2 count (byte at +8). */
Unk0392f8Entry *Unk0392f8_GetEntry(YdmFile *ydm, u32 i)
{
    if (ydm->header->count8 <= i) {
        return 0;
    }
    return (Unk0392f8Entry *)ydm->sec2 + i;
}

/* Converts grid coordinates to the 16-bit map cell in section 3, or returns
 * NULL when the object/file is null or (x, y) lies outside the header's grid
 * rectangle.  dx/dy are relative to the grid origin at header +9/+10. */
u8 *Unk0392f8_Unk_0394b8(YdmFile *ydm, int x, int y)
{
    YdmHeader *h;
    int dx, dy;
    if (ydm == 0) {
        return 0;
    }
    h = ydm->header;
    if (h != 0) {
        dx = x - h->gridX;
        dy = y - h->gridY;
        if (dx >= 0 && dx < h->gridW && dy >= 0 && dy < h->gridH) {
            return ydm->sec3 + (h->gridW * dy + dx) * 2;
        }
    }
    return 0;
}
