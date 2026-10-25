#include "types.h"

/* Snapshot copied as 0x48 bytes by func_021099fc; names preserve unknown semantics. */
typedef struct Unk10947cData {
    u16 unk_0004;
    char unk_0006[0x24];
    u8 unk_002a, unk_002b, unk_002c, unk_002d;
    u16 unk_002e[4];
    u8 pad_0036[2];
    u32 unk_0038;
    u8 pad_003c[0x10];
} Unk10947cData;

/* Private work layout: offsets are established by the original ARM accesses. */
typedef struct Unk10947cWork {
    u32 unk_0000;
    Unk10947cData data;
    s32 unk_004c;
    s32 unk_0050;
    u32 unk_0054;
    s32 unk_0058;
    u32 unk_005c;
    s16 unk_0060[3];
    u8 pad_0066[2];
    s32 unk_0068;
    s32 unk_006c;
    void *unk_0070;
    void *unk_0074;
    void *unk_0078;
    void *unk_007c[4];
    void *unk_008c;
    void *unk_0090[3];
    void *unk_009c[3];
    void *unk_00a8;
    s32 unk_00ac;
    s32 unk_00b0;
} Unk10947cWork;

extern s32 Unk_InterpolateLinear(s32 from, s32 to, u32 frames, s32 frame);
extern void func_0205c704(void *resource);
extern void func_0205c3dc(void *resource);
extern void func_020629c4(void *resource);
extern void func_02053000(void *resource);
extern void func_021099fc(Unk10947cWork *work);

extern void func_02109538(Unk10947cWork *work);
extern Unk10947cWork *func_020611dc(void (*update)(Unk10947cWork *),
    void (*draw)(Unk10947cWork *), int arg2, void (*destroy)(Unk10947cWork *),
    u32 size, int arg5, int arg6, int arg7);
extern void *func_020629ac(int a, int b, int c, int d);
extern void func_02061e98(void *resource, int a, int b);
extern void *func_0205c3c0(void);
extern void func_0205c3fc(void *resource, void *a, void *b);
extern void func_0205c408(void *resource, int index);
extern void func_0205c6e0(void *resource);
extern const int data_0213ca50[3];

/* Only the accessed resource fields are modeled; other bytes belong to its owner. */
typedef struct Unk10947cText {
    void *unk_0000;
    u8 pad_0004[0x24];
    void *unk_0028;
} Unk10947cText;
/* The lookup supplies a halfword identifier at +0x60. */
typedef struct Unk10947cEntry {
    u8 pad_0000[0x60];
    u16 unk_0060;
} Unk10947cEntry;
extern const Unk10947cData *Unk02e000_Unk_02e75c(u32 mode);
extern void func_02063920(void);
extern s32 func_02061a04(void *font, const char *text, int arg2);
extern int func_02063a30(const char *text);
extern void *func_0204fe68(void *resource, int index);
extern const char *func_0204fed8(void *resource, int index);
extern void func_02035578(char *buffer, int size, u16 id);
extern void func_02061f10(void *resource, int a, int b, int c, int length);
extern const Unk10947cEntry *func_020a1428(u16 id);
extern int func_02013c3c(char *buffer, const char *format, ...);
extern void *func_02051610(const char *name);
extern void func_0205b444(void *resource, void *data);
extern const char data_02151298[];

extern void func_020580ec(int enabled);
extern void func_02057524(int mode);
extern void func_02057534(void);
extern void func_02057fd8(void);
extern void func_02057df8(void);
extern void func_02057e18(int value);
extern void func_02057ddc(u32 color);
extern void func_0205dee8(int a, void *resource, int index, s32 x, s32 y,
    float sx, float sy, int arg7, float alpha, int layer);
extern void func_0205c848(int a, void *resource, s32 x, s32 y,
    float sx, float sy, int arg6, float alpha, int layer);
extern void func_020a9fd8(int a, s32 x, s32 y, int b, int c, int d,
    const char *format, int value);
extern void func_020a9eb4(int a, s32 x, s32 y, int b, const char *format,
    int c, int d, int e);
extern void func_02058d04(void *resource, int a, s32 x, s32 y,
    float scale, int b, int layer, int c);
extern void func_02060dd4(void *rect, void *resource, int a, int b, int index);
extern void func_02059f70(void *resource, int a, s32 x, s32 y, const void *rect,
    int b, int layer);
extern const char data_02151284[];
extern const char data_02151288[];

extern int Unk10947c_IsUnk4cAtLeast2(Unk10947cWork *work);

/* Advances the two timed states and updates four resources; +0x54 is in frames. */
void func_0210947c(Unk10947cWork *work)
{
    int i;
    switch (work->unk_004c) {
    case 0:
        work->unk_0068 = Unk_InterpolateLinear(work->unk_0050, 0,
                                              work->unk_0054, work->unk_0058);
        if (++work->unk_0058 >= work->unk_0054) {
            work->unk_004c++;
            work->unk_0058 = 0;
            work->unk_0068 = 0;
            work->unk_0054 = 15;
        }
        break;
    case 1:
        if (++work->unk_0058 >= work->unk_0054)
            work->unk_004c++;
        break;
    }
    func_0205c704(work->unk_008c);
    for (i = 0; i < 3; i++)
        func_0205c704(work->unk_0090[i]);
}

/* Draws work resources at the animated coordinates; state 1 fades the final layer in. */
void func_02109538(Unk10947cWork *work)
{
    s32 rect[4];
    int i, x, y, j;
    float alpha;
    func_020580ec(0);
    func_02057524(7);
    func_02057fd8();
    if (work->data.unk_002c == 0) {
        func_0205dee8(2, work->unk_0070, 10, work->unk_0068, work->unk_006c,
                      1.0f, 1.0f, 0, 1.0f, 10);
    } else {
        func_0205dee8(2, work->unk_0070, 9, work->unk_0068, work->unk_006c,
                      1.0f, 1.0f, 0, 1.0f, 10);
        func_02057fd8();
        func_0205dee8(2, work->unk_0070, 12, work->unk_0068, work->unk_006c,
                      1.0f, 1.0f, 0, 1.0f, 10);
    }
    if (work->unk_005c && Unk10947c_IsUnk4cAtLeast2(work)) {
        func_02057fd8();
        func_0205c848(2, work->unk_008c, work->unk_0068, work->unk_006c,
                      1.0f, 1.0f, 0, 1.0f, 10);
    }
    if (work->data.unk_002c) {
        func_02057df8();
        func_02057e18(31);
        func_020a9fd8(1, work->unk_0068 + 228, work->unk_006c + 27,
                      2, 10, 11, data_02151284, work->data.unk_002a);
        func_020a9eb4(1, work->unk_0068 + 182, work->unk_006c + 60,
                      11, data_02151288, work->unk_0060[0],
                      work->unk_0060[1], work->unk_0060[2]);
        func_02057fd8();
        if (work->unk_004c) {
            for (i = 0, x = 0; i < 4; i++, x += 34) {
                if (i == 0 || work->data.unk_002e[i]) {
                    func_02058d04(work->unk_007c[i], 0,
                        work->unk_0068 + 101 + x, work->unk_006c + 70,
                        1.0f, 0, 12, 0);
                }
            }
        }
        func_02057e18(31);
        switch (work->data.unk_002d) {
        case 4: func_02057ddc(0x39dccbff); break;
        case 5: func_02057ddc(0xff7b63ff); break;
        default: func_02057ddc(0xffffffff); break;
        }
        func_02060dd4(rect, work->unk_00a8, 0, 0, 16);
        func_02059f70(((Unk10947cText *)work->unk_00a8)->unk_0000, 1,
            work->unk_0068 + 200 - work->unk_00ac, work->unk_006c + 24, rect, 0, 11);
        func_02057df8();
        func_02060dd4(rect, work->unk_00a8, 0, 1, 17);
        func_02059f70(((Unk10947cText *)work->unk_00a8)->unk_0000, 1,
            work->unk_0068 + 232 - work->unk_00b0, work->unk_006c + 41, rect, 0, 11);
        func_02057fd8();
        for (y = 0, j = 0; j < 3; j++) {
            if (work->data.unk_002b & (1 << j)) {
                func_0205c848(2, work->unk_0090[j], work->unk_0068 + y,
                    work->unk_006c, 1.0f, 1.0f, 0, 1.0f, 10);
                y += 17;
            }
        }
    }
    if (!work->unk_005c && work->unk_004c) {
        func_02057fd8();
        alpha = 1.0f;
        if (work->unk_004c == 1)
            alpha = (float)work->unk_0058 / (float)work->unk_0054;
        func_0205dee8(2, work->unk_0070, 13, work->unk_0068, work->unk_006c,
                      1.0f, 1.0f, 0, alpha, 10);
    }
    func_02057534();
    func_020580ec(1);
}

/* Releases owned resources; nullable slots are cleared after release. */
void func_02109978(Unk10947cWork *work)
{
    int i;
    if (work->unk_008c) {
        func_0205c3dc(work->unk_008c);
        work->unk_008c = 0;
    }
    for (i = 0; i < 3; i++) {
        if (work->unk_0090[i]) {
            func_0205c3dc(work->unk_0090[i]);
            work->unk_0090[i] = 0;
        }
    }
    func_020629c4(work->unk_00a8);
    for (i = 0; i < 3; i++) {
        func_02053000(work->unk_009c[i]);
        work->unk_009c[i] = 0;
    }
}

/* Refreshes the snapshot, splits its unsigned time into base-60 fields, and reloads labels. */
void func_021099fc(Unk10947cWork *work)
{
    char text[40];
    char name[64];
    const char *label;
    void *resource;
    int length;
    int i;
    u32 time;
    work->data = *Unk02e000_Unk_02e75c(work->unk_0000);
    time = work->data.unk_0038;
    work->unk_0060[2] = time % 60;
    work->unk_0060[1] = (time / 60) % 60;
    work->unk_0060[0] = (time / 60) / 60;
    func_02063920();
    work->unk_00ac = func_02061a04(((Unk10947cText *)work->unk_00a8)->unk_0028,
                                  work->data.unk_0006, 0);
    length = func_02063a30(work->data.unk_0006);
    resource = func_0204fe68(work->unk_0078, 1);
    switch (work->data.unk_002c) {
    case 1:
        label = func_0204fed8(resource, 2);
        work->unk_00b0 = func_02061a04(((Unk10947cText *)work->unk_00a8)->unk_0028, label, 0);
        length = func_02063a30(label);
        break;
    case 2:
        func_02035578(text, 20, work->data.unk_002e[0]);
        work->unk_00b0 = func_02061a04(((Unk10947cText *)work->unk_00a8)->unk_0028, text, 0);
        length = func_02063a30(text);
        break;
    case 3:
        label = func_0204fed8(resource, 3);
        work->unk_00b0 = func_02061a04(((Unk10947cText *)work->unk_00a8)->unk_0028, label, 0);
        length = func_02063a30(label);
        break;
    }
    func_02061f10(work->unk_00a8, -1, 0, 0, length);
    for (i = 0; i < 3; i++) {
        if (work->data.unk_002e[i + 1]) {
            const Unk10947cEntry *entry = func_020a1428(work->data.unk_002e[i + 1]);
            func_02013c3c(name, data_02151298, entry->unk_0060);
            func_02053000(work->unk_009c[i]);
            work->unk_009c[i] = 0;
            work->unk_009c[i] = func_02051610(name);
            func_0205b444(work->unk_007c[i + 1], work->unk_009c[i]);
        }
    }
}

/* Allocates the callback work and its resources; mode selects initial slide coordinates. */
Unk10947cWork *func_02109c04(u32 mode, void *a, void *b, void *c,
    void *d, void *e, void *f, void *g)
{
    Unk10947cWork *work;
    int i;
    work = func_020611dc(func_0210947c, func_02109538, 0, func_02109978,
                        0xb4, 4, 0, 1);
    work->unk_0000 = mode;
    work->unk_00a8 = func_020629ac(5, 2, 0, 1);
    func_02061e98(work->unk_00a8, 16, 1);
    work->unk_007c[0] = d;
    work->unk_007c[1] = e;
    work->unk_007c[2] = f;
    work->unk_007c[3] = g;
    for (i = 0; i < 3; i++)
        work->unk_009c[i] = 0;
    work->unk_004c = 0;
    work->unk_0070 = a;
    work->unk_0074 = b;
    work->unk_0078 = c;
    if (mode == 0) {
        work->unk_0068 = work->unk_0050 = -244;
        work->unk_0054 = 8;
        work->unk_006c = 0;
    } else {
        work->unk_0068 = work->unk_0050 = -360;
        work->unk_0054 = 12;
        work->unk_006c = 76;
    }
    work->unk_005c = 0;
    work->unk_008c = func_0205c3c0();
    func_0205c3fc(work->unk_008c, work->unk_0070, work->unk_0074);
    func_0205c408(work->unk_008c, 8);
    func_0205c6e0(work->unk_008c);
    for (i = 0; i < 3; i++) {
        work->unk_0090[i] = func_0205c3c0();
        func_0205c3fc(work->unk_0090[i], work->unk_0070, work->unk_0074);
        func_0205c408(work->unk_0090[i], data_0213ca50[i]);
        func_0205c6e0(work->unk_0090[i]);
    }
    func_021099fc(work);
    return work;
}

/* Stores the +0x5c flag; evidence: the original has one STR at offset 0x5c. */
void Unk10947c_SetUnkField5c(Unk10947cWork *work, u32 value)
{
    work->unk_005c = value;
}

/* Forwards the work pointer unchanged; evidence: original BX to func_021099fc. */
void Unk10947c_Thunk_021099fc(Unk10947cWork *work)
{
    func_021099fc(work);
}

/* Tests signed state >= 2; evidence: original CMP #2 followed by MOVGE/MOVLT. */
int Unk10947c_IsUnk4cAtLeast2(Unk10947cWork *work)
{
    return work->unk_004c >= 2;
}
