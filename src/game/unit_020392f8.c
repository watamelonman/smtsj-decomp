/* src/game/unit_020392f8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02008848();
int func_020516d0();
/* decompiler-derived */
void Unk0392f8_Unk_039454(u32 *arg0)
{
  if (arg0 == (u32 *)0x0) {
    return;
  }
  func_020516d0(*arg0);
  func_02008848(arg0,0,0x14);
}

extern char data_021420d8[];   /* "Data/Dungeon/Ydm/%s_%02d_ydm.cmp" */
extern char data_021420fc[];   /* "Data/Dungeon/Ydm/%s_dk%02d_ydm.cmp" */
extern char data_02142120[];
extern char data_02142148[];
void func_02013c3c(char *buf, const char *fmt, ...);
int func_020513d4(const char *path);
u8 *func_02051610(const char *path);

/* Dungeon YDM file header (only the counts read here). */
typedef struct YdmHeader {
    u8 pad_00[6];
    s8 count6;                  /* +6: 16-byte records */
    u8 count7;                  /* +7: 36-byte records */
    u8 count8;                  /* +8: 8-byte records */
} YdmHeader;

/* Pointers into a loaded YDM file's sections. */
typedef struct YdmFile {
    YdmHeader *header;
    u8 *sec0;
    u8 *sec1;
    u8 *sec2;
    u8 *sec3;
} YdmFile;

/* Loads Data/Dungeon/Ydm/<name>... and splits it into sections. Returns 1 on success. */
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
