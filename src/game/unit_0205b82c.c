/* src/game/unit_0205b82c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0205ad9c();
/* Entry returned by func_0205adb4; carries a 32-byte name at +0x2C. */
typedef struct Unk05b82cEntry {
    u8 pad_0000[0x2c];
    char name[0x20];
} Unk05b82cEntry;

/* Descriptor passed to Unk05b82c_CreateNamedEntry. */
typedef struct Unk05b82cDesc {
    u32 unk_0000;
    const char *path;           /* +0x04: base name (after the last '/') becomes the entry name */
    u8 pad_0008[0xc];
    Unk05b82cEntry *entry;      /* +0x14 */
} Unk05b82cDesc;

Unk05b82cEntry *Unk05b82c_CreateEntry();
/* decompiler-derived */
void Unk05b82c_Unk_05b82c(void)
{
  func_0205ad9c();
  Unk05b82c_CreateEntry();
}

extern char data_02143be8[];    /* "no_name" */
Unk05b82cEntry *func_0205adb4(void);
void func_02007e94(void);
char *func_02015450(const char *s, int c);
void func_02008904(const char *src, char *dst, int n);
void func_02013c14(char *dst, int n, const char *fmt);
int func_0205ae60(void);
void func_0205b900(void);
void Unk05ae50_Unk_05af3c(u32 obj);

/* Allocates an entry for `desc` and names it from desc->path, `name`, or "no_name". */
Unk05b82cEntry *Unk05b82c_CreateNamedEntry(Unk05b82cDesc *desc, int unused, const char *name)
{
    Unk05b82cEntry *e = func_0205adb4();
    const char *path;

    if (e == 0) {
        func_02007e94();
    }
    desc->entry = e;
    path = desc->path;
    if (path != 0) {
        char *slash = func_02015450(path, '/');
        if (slash != 0) {
            path = slash + 1;
        }
        func_02008904(path, e->name, 0x20);
    } else if (name != 0) {
        func_02008904(name, e->name, 0x20);
    } else {
        func_02013c14(e->name, 0x20, data_02143be8);
    }
    return e;
}

Unk05b82cEntry *Unk05b82c_CreateEntry(Unk05b82cDesc *desc)
{
    Unk05b82cEntry *ret = Unk05b82c_CreateNamedEntry(desc, func_0205ae60() + 0xc, 0);
    func_0205b900();
    Unk05ae50_Unk_05af3c((u32)desc);
    return ret;
}
