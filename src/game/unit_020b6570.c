#include "types.h"

/* Only the accessed fields are known; embedded renderer storage remains opaque. */
typedef struct Work {
    int state;
    u8 pad04[4];
    int field08, field0c;
    u32 field10;
    struct Work *previous;
    u8 pad18[4];
    u8 field1c;
    u8 pad1d[3];
    void *field20, *field24, *field28, *field2c, *field30;
    void *entries[7];
    u32 field50;
    u32 bounds[3][4];
    /* Partial opaque extent; full storage size is unknown and never allocated here. */
    u8 storage[0x2118];
} Work;
extern Work *data_02176b88;
extern int func_02053e44(u32, u32, u32, u32, int, int);
extern int SaveLoadTask_Unk_0df7c4(void);
extern void func_02058548(void *);
extern void func_02058a1c(void *, int);
extern void func_020588ec(void *, int);
extern void func_02058c3c(int, int, int, int, float, int, int);
extern void func_02057df8(void);
extern void func_02057e18(int);
extern void func_02057524(int);
extern void func_02057534(void);
extern void func_02057fd8(void);
extern void func_02061424(void *);
extern void func_0205ddb4(void *);
extern void func_0205c368(void *);
extern void func_0205bb68(void);
void func_020b76cc(Work *, int);
void Unk0b6570_Unk_0b7838(void *);

/* Probe three four-word bounds with the common query; return the first hit or -1. */
int func_020b6570(Work *w)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (func_02053e44(w->bounds[i][0], w->bounds[i][1],
                         w->bounds[i][2], w->bounds[i][3], 1, 0))
            return i;
    }
    return -1;
}

/* Set the two status fields according to the save/load task query. */
void Unk0b6570_Unk_0b65d0(Work *w)
{
    w->field08 = 1;
    w->field0c = 2;
    if (SaveLoadTask_Unk_0df7c4()) {
        w->field08 = 2;
        w->field0c = 3;
    }
}

/* Dispatch the state-dependent draw setup; field 0x1c supplies the saved selection. */
void func_020b7148(Work *w)
{
    if (w->state == 5 || w->state == 8) return;
    if (w->state == 12 || w->state == 13) {
        func_02058c3c(1, 10, 0, 0, 1.0f, 0, 4);
        return;
    }
    func_02057df8();
    func_02057e18(w->field1c);
    func_02057524(0);
    func_020b76cc(w, 1);
    func_02057534();
    func_02057e18(31);
    func_02057fd8();
}

/* Release the owned handles and restore the previous singleton work pointer. */
void func_020b71d8(Work *w)
{
    int i;
    Unk0b6570_Unk_0b7838(w->storage);
    func_02061424(w->field28);
    w->field28 = 0;
    for (i = 0; i <= 6; i++) {
        func_02061424(w->entries[i]);
        w->entries[i] = 0;
    }
    if (w->field20) { func_0205ddb4(w->field20); w->field20 = 0; }
    if (w->field24) { func_0205c368(w->field24); w->field24 = 0; }
    if (w->field2c) { func_0205ddb4(w->field2c); w->field2c = 0; }
    if (w->field30) { func_0205c368(w->field30); w->field30 = 0; }
    func_0205bb68(); func_0205bb68(); func_0205bb68();
    func_0205bb68(); func_0205bb68(); func_0205bb68();
    data_02176b88 = w->previous;
}

/* Borrow the singleton pointer; the literal relocation identifies data_02176b88. */
Work *Unk0b6570_Get_data_02176b88(void)
{
    return data_02176b88;
}

/* Clear all 128 entries and the three associated slots in the embedded storage. */
void Unk0b6570_Unk_0b7838(void *storage)
{
    int i;
    u8 *p = storage;
    func_02058548(p);
    for (i = 0; i < 128; i++) func_02058a1c(p + 0x208c, i);
    func_020588ec(p + 0x208c, 0);
    func_020588ec(p + 0x208c, 1);
    func_020588ec(p + 0x208c, 2);
}

extern const u8 data_021501cc[], data_021501f0[], data_02150214[], data_02150238[];
extern void *func_02058528(void *, const void *);
extern void func_02007ad4(void *);
extern void func_020585a8(void *);
extern void func_02058854(void *);
extern void func_0205889c(void *, const void *, int);
extern int func_02058a64(void *);
extern void func_02058944(void *, int, void *, int, int, int, int);

/* Load the four referenced resources and register two sets of three slot records. */
void func_020b75b0(void *storage)
{
    u8 *p = storage;
    u32 i;
    func_02007ad4(func_02058528(p, data_021501cc));
    func_020585a8(p);
    func_02058854(p + 0x208c);
    func_0205889c(p + 0x208c, data_021501f0, 0);
    func_0205889c(p + 0x208c, data_02150214, 1);
    func_0205889c(p + 0x208c, data_02150238, 2);
    for (i = 0; i < 2; i++) {
        func_02058944(p + 0x208c, func_02058a64(p + 0x208c), p, i, i, 0, 1);
        func_02058944(p + 0x208c, func_02058a64(p + 0x208c), p, i, i, 1, 1);
        func_02058944(p + 0x208c, func_02058a64(p + 0x208c), p, i, i, 2, 1);
    }
}

/* Fixed-point vector and matrix contracts follow the shared graphics call sites. */
typedef struct Vector { s32 x, y, z; } Vector;
typedef struct Matrix { s32 v[9]; } Matrix;
/* Sixteen-word graphics scratch area, filled before it is consumed. */
typedef struct Context { u32 v[16]; } Context;
/* Only the graphics flags at 0xfc are exposed by this borrowed global view. */
typedef struct GraphicsGlobal { u8 pad[0xfc]; u32 flags; } GraphicsGlobal;
extern Matrix data_02156de4;
extern GraphicsGlobal data_02156d28;
extern void func_02058a90(void *, int);
extern void func_02058724(Vector *, Vector *);
extern void func_020586d0(s32, s32, s32, s32, s32);
extern void func_02057494(Vector *, Vector *);
extern void func_02022468(Vector *);
extern void func_02000edc(Matrix *, s32, s32);
extern void func_020087dc(Matrix *, Matrix *);
extern void func_0202242c(void);
extern void func_02022d40(void *);
extern void func_020572d8(void);
extern void func_020222d8(void);
extern void func_020251c8(void);
extern void func_02001784(Context *);
extern void func_02004600(Context *);

/* Select three consecutive graphics slots and submit the indexed 92-byte record.
 * Evidence: graphics register writes and the shared matrix/vector setup callees. */
void func_020b76cc(Work *w, int index)
{
    Vector a, b;
    func_02058a90(w->storage + 0x208c, index * 3);
    func_02058a90(w->storage + 0x208c, index * 3 + 1);
    func_02058a90(w->storage + 0x208c, index * 3 + 2);
    a.x = 0; a.z = 0; b.x = 0; b.z = -0x2000;
    a.y = 0x8cc; b.y = 0x8cc;
    func_02058724(&a, &b);
    func_020586d0(0x579, 0xf09, 0x1555, 0x1000, 0x190000);
    func_02057494(&a, &b);
    Vector zero = {0, 0, 0};
    func_02022468(&zero);
    Matrix matrix = {{0}};
    *(volatile u32 *)0x04000444 = 0;
    func_02000edc(&matrix, 0, 0x1000);
    func_020087dc(&matrix, &data_02156de4);
    data_02156d28.flags &= ~0xa4;
    func_0202242c();
    func_02022d40(w->storage + index * 92);
    *(volatile u32 *)0x04000448 = 1;
    func_020572d8();
    func_02057df8();
    func_020222d8();
    func_020251c8();
    Context context;
    func_02001784(&context);
    func_02004600(&context);
}
