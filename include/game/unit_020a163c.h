#ifndef GAME_UNIT_020A163C_H
#define GAME_UNIT_020A163C_H

#include "types.h"

/* Private borrowed layouts and provider declarations for this matching TU.
 * Offsets reflect original ARM accesses; no complete provider ABI is implied. */

/* Prefix view for forwarding callbacks; func_020a208c requires full list storage. */
typedef struct Unk0a163cWork {
    u32 unk_0000[3];
    u32 unk_000c;
} Unk0a163cWork;

/* Borrowed resource record: offsets 0x5a and 0x6a are established by loads. */
typedef struct Unk0a163cRecord {
    u16 id;
    u8 unk_0002[88];
    u8 unk_005a;
    u8 unk_005b[15];
    s16 unk_006a;
    u8 unk_006c[20];
} Unk0a163cRecord;

/* Signed offsets belong to the borrowed entry metadata. */
typedef struct Unk0a163cMetadata {
    u16 unk_0000;
    s16 unk_0002;
    s16 unk_0004;
} Unk0a163cMetadata;

/* Four words copied together by 0x020a1d00; interpretation is unknown. */
typedef struct Unk0a163cVector { u32 words[4]; } Unk0a163cVector;

/* Inline output stride 92 and its fields follow 0x020a1d00's stores. */
typedef struct Unk0a163cInline {
    s32 x;
    s32 y;
    u32 unk_0008;
    s32 unk_000c;
    s32 unk_0010;
    u32 unk_0014;
    Unk0a163cVector vector;
    s16 unk_0028;
    s16 unk_002a;
    char name[44];
    u8 unk_0058;
    u8 ready;
    u8 unk_005a[2];
} Unk0a163cInline;

/* Entry stride 0x3a0 and the three pointers follow the original list loads. */
typedef struct Unk0a163cEntry {
    u16 id;
    u16 unk_0002;
    void *unk_0004;
    u32 unk_0008;
    Unk0a163cInline outputs[4];
    Unk0a163cInline *output_ptrs[4];
    Unk0a163cMetadata *unk_018c;
    void *unk_0190;
    void *unk_0194;
    u8 unk_0198[520];
} Unk0a163cEntry;

/* Output routines write coordinates at +0xc and +0x10. */
typedef struct Unk0a163cOutput {
    u32 unk_0000[3];
    s32 unk_000c;
    s32 unk_0010;
} Unk0a163cOutput;

/* The original list routines read a count and a borrowed entry buffer. */
typedef struct Unk0a163cList {
    u32 count;
    Unk0a163cEntry *entries;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u32 unk_0014[1];
} Unk0a163cList;
extern void *func_020445d0(int group, int table);
extern void *func_020445f4(int group, int table);
extern u32 func_0204fe18(void *resource);
extern void *func_0204fed8(void *resource, u32 index);
extern int func_020a1b08(Unk0a163cList *list, u16 id, u32 value);
extern int func_020a208c(Unk0a163cWork *work);
extern Unk0a163cEntry *func_020a2218(Unk0a163cList *list, u16 id);
extern void func_020a1a24(Unk0a163cList *list);
extern void func_02053000(void *allocation);
extern void *func_0204fde0(void *resource);
extern void *func_02011810(const void *key, const void *base, u32 count,
                          u32 stride, int (*compare)(const u16 *, const u16 *));
extern s32 func_02011804(s32 value);
extern s32 Unk02e000_GetRecordUnk1e(u16 id);
extern const u8 data_0213c258[];
extern const u8 data_0213c244[];
extern Unk0a163cEntry *func_020a2250(Unk0a163cList *list, u16 id);
extern Unk0a163cOutput *func_02065fc0(void *a, void *b, u32 value, int mode, int flags);
extern Unk0a163cOutput *func_0205f41c(void *object, u32 argument);
extern Unk0a163cOutput *func_0205adb4(int mode, s32 *coordinates);
extern s32 func_0205accc(Unk0a163cOutput *object);
extern s32 func_0205acd4(Unk0a163cOutput *object);
extern void func_0205b9a0(Unk0a163cOutput *object);
extern void func_0205b900(Unk0a163cOutput *object);
extern void *func_02052fe0(u32 size);
extern void func_02008848(void *buffer, int value, u32 size);
extern void *func_020519e8(void *context);
extern u32 func_0205f2e4(void *object);
extern int func_02013c3c(char *buffer, const char *format, ...);
extern void func_020516dc(void *context, const char *name, int a, int b);
extern void *func_02051610(const char *name);
extern int func_020a1d00(Unk0a163cList *list, int flag);
extern const char data_0214cd28[];
extern const char data_0214cd48[];

/* Resource (19, 0) has 100-byte records with six halfword slots at +0x2e. */
typedef struct Unk0a163cSortRecord {
    u8 unk_0000[46];
    u16 slots[6];
    u8 unk_003a[42];
} Unk0a163cSortRecord;

/* Loaded resource begins with a signed count followed by halfword values. */
typedef struct Unk0a163cValues {
    s32 count;
    u16 values[1];
} Unk0a163cValues;
extern void func_02008904(const void *source, void *destination, u32 size);
extern int func_020513d4(const char *name);
extern const char data_0214cd10[];
extern void func_0205bb68(void);
extern void func_0205ddb4(void *object);
extern void func_0205c368(void *object);
extern int func_02051844(void *context, int value);

/* The container count at +8 and item link at +0x30 are borrowed views. */
typedef struct Unk0a163cContainer {
    u32 unk_0000[2];
    u32 count;
} Unk0a163cContainer;

/* Names begin at item +0x10; matching installs a borrowed inline output. */
typedef struct Unk0a163cItem {
    u32 unk_0000[4];
    char name[32];
    Unk0a163cInline *output;
} Unk0a163cItem;
extern void func_0205aa78(void *vector, s32 *x, s32 *y, s16 *a, s16 *b);
extern void func_0205b444(Unk0a163cInline *output, Unk0a163cOutput *view);
extern void func_0205b4c4(Unk0a163cInline *output, Unk0a163cOutput *view);
extern Unk0a163cContainer *func_0205dd58(Unk0a163cOutput *view, int mode);
extern Unk0a163cItem *func_0205e33c(void *container, u32 index);
extern int func_020152cc(const char *left, const char *right);
extern void *func_0205c328(Unk0a163cOutput *view);
extern const char data_0214cd64[], data_0214cd70[], data_0214cd7c[];
extern const char data_0214cd8c[], data_0214cd94[], data_0214cd9c[];

#endif
