/*
 * ScanVisor.c (file name from an assert string in this TU); presumably the
 * in-dungeon scan visor UI.
 * Small getters/setters and constant queries.
 */
typedef unsigned int u32;

typedef struct ScanVisor {
    u32 unk00[5];
    u32 field14;            /* 0x14 */
    u32 unk18;
    u32 rangeA;             /* 0x1C: set together with rangeB */
    u32 rangeB;             /* 0x20 */
    u32 unk24[103];
    u32 slots[16];          /* 0x1C0: indexed table */
} ScanVisor;

void func_020fc6b8(void);

/* Empty callbacks (called from func_020a3114). */
void func_020a34a4(void) { }
void func_020a34a8(void) { }

/* Constant: 20 (used by six different systems). */
int func_020a2bb0(void) { return 20; }

/* Constant: 6. */
int func_020a4e40(void) { return 6; }

u32 func_020a45f8(ScanVisor *sv) { return sv->field14; }

/* Forwards to func_020fc6b8. */
void func_020a28e8(void) { func_020fc6b8(); }

/* Reads entry `index` of the slot table at 0x1C0. */
u32 func_020a42b8(ScanVisor *sv, int index) { return sv->slots[index]; }

/* Sets the 0x1C/0x20 pair. */
void func_020a43dc(ScanVisor *sv, u32 a, u32 b) {
    sv->rangeA = a;
    sv->rangeB = b;
}
