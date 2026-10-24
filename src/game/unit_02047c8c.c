#include "types.h"

/* Partial views retain the offsets used by this transition sequence. */
typedef struct Unk047c8cState {
    s16 state;
    s16 unk02[2];
    s16 step;
} Unk047c8cState;
typedef struct Unk047c8cContext {
    u8 pad00[0x40];
    u32 id;
    union {
        u32 flags;
        struct { u32 low:3; u32 mode:2; u32 middle:8; u32 submitted:1; u32 high:18; } bits;
    };
    u32 secondary;
    u32 tertiary;
    u8 pad50[0x14];
    u16 resource;
} Unk047c8cContext;
typedef struct Unk047c8cEntry {
    u32 id;
    u8 pad04[0x27e];
    struct { u8 low:2; u8 alternate:1; u8 high:5; } bits;
} Unk047c8cEntry;
typedef struct Unk047c8cGlobal {
    u8 pad00[0x50];
    u32 active;
    u32 value;
} Unk047c8cGlobal;
typedef struct Unk047c8cObject {
    u32 unk00[2];
    u32 flags;
    u32 unk0c;
    void *resource;
} Unk047c8cObject;
typedef struct Unk047c8cObjectWork {
    u32 unk00;
    u32 id;
    u8 pad08[0x7c];
    u32 flags;
} Unk047c8cObjectWork;

int Unk09d060_Unk_09d13c(void);
void Unk044904_Unk_045080(void);
int Unk0f81a4_Unk_0f81b4(void);
Unk047c8cContext *Unk044904_Unk_045048(void);
Unk047c8cEntry *func_02044ec4(u32 id);
void func_020b801c(u32 id);
Unk047c8cGlobal *Unk044904_Get_data_0215ee98(void);
void Unk0fd9f0_Unk_0fda58(int mode);
void func_020fdaa8(int mode, int frames);
void Unk044904_Unk_045bd0(int mode);
void func_0204ae84(Unk047c8cContext *context);
void Unk0bbfa4_Unk_0bc0a4(int mode);
int Unk0bbfa4_Unk_0bc17c(void);
void func_020bc0b4(int mode);
void func_0204aecc(Unk047c8cContext *context, const void *name, int mode);
void func_0204af70(Unk047c8cContext *context, Unk047c8cContext *source);
void func_0204afe0(Unk047c8cContext *context, int mode);
int func_0204b054(Unk047c8cContext *context);
void func_0204af80(Unk047c8cContext *context);
void Unk0bbfa4_Unk_0bc144(void);
void Unk039774_Unk_039b74(int mode);
void func_0202b730(int flags);
void Unk0a0ce4_Unk_0a0d30(int mode);
void func_0204f728(int layer, u32 id, int mode);
void func_020b8078(void);
Unk047c8cObject *Unk0aa118_Unk_0afb64(u32 flags);
void *Unk0aa118_Unk_0af8d8(int kind, const void *name, int mode);
Unk047c8cObjectWork *Unk0aa118_Unk_0afb90(Unk047c8cObject *object);
int Unk09974c_Unk_099bac(u16 resource);
void func_0204f108(int layer, int slot, int resource, int mode);
void func_0209fd64(Unk047c8cObject *object);
void func_020afbdc(Unk047c8cObject *object);
int func_02049f24(Unk047c8cEntry *entry, int index);
void func_0204f49c(int layer, int mode);
void func_0204f650(int layer, u32 id, int slot, int kind);
void func_0204f6d8(int layer, u32 id, const int *parameters);
extern const char data_02143314[];
extern const char data_0214332c[];

/* Poll the prerequisite, then select state 2 when the secondary predicate holds.
 * Evidence: the conditional halfword store at 02047cb4. */
int func_02047c8c(Unk047c8cState *state)
{
    if (!Unk09d060_Unk_09d13c()) return 0;
    Unk044904_Unk_045080();
    if (Unk0f81a4_Unk_0f81b4()) state->state = 2;
    return 1;
}

/* Run the two initialization steps; +6 is a signed step counter.
 * Evidence: the dispatch and increment at 02047ce4 and 02047d6c. */
int func_02047cc0(Unk047c8cState *state)
{
    Unk047c8cContext *context = Unk044904_Unk_045048();
    Unk047c8cEntry *entry = func_02044ec4(context->id);
    switch (state->step) {
    case 0:
        func_020b801c(entry->id);
        if (Unk044904_Get_data_0215ee98()->active) {
            Unk044904_Get_data_0215ee98()->value = 0;
            Unk044904_Get_data_0215ee98()->active = 0;
            Unk0fd9f0_Unk_0fda58(1);
        }
        func_020fdaa8(0, 60);
        Unk044904_Unk_045bd0(1);
        func_0204ae84(context);
        if (entry->bits.alternate) Unk0bbfa4_Unk_0bc0a4(14);
        else Unk0bbfa4_Unk_0bc0a4(Unk0bbfa4_Unk_0bc17c());
        state->step++;
        return 0;
    case 1:
        if (entry->bits.alternate) func_020bc0b4(14);
        else func_020bc0b4(Unk0bbfa4_Unk_0bc17c());
        func_0204aecc(context, data_02143314, 2);
        func_0204af70(context, context);
        func_0204afe0(context, 0);
        state->step++;
        break;
    }
    return 1;
}

/* Finish a ready transition or submit its optional resource and effect work.
 * Evidence: readiness call at 02047df4 and flag 0x2000 stores in the pending path. */
int func_02047de4(Unk047c8cState *state)
{
    Unk047c8cContext *context = Unk044904_Unk_045048();
    Unk047c8cObject *object;
    Unk047c8cObjectWork *work;
    int slot;
    int parameters[3];
    if (!func_0204b054(context)) {
        func_0204af80(context);
        Unk0bbfa4_Unk_0bc144();
        Unk039774_Unk_039b74(2);
        func_0202b730(0x400);
        Unk0a0ce4_Unk_0a0d30(2);
        if (context->bits.mode != 1) state->state = 3;
        else {
            state->state = 2;
            func_0204f728(0, context->id, 8);
        }
        Unk0fd9f0_Unk_0fda58(1);
        func_020b8078();
        return 1;
    }
    if (context->resource) {
        object = Unk0aa118_Unk_0afb64(0x10000);
        object->resource = Unk0aa118_Unk_0af8d8(2, data_0214332c, 0);
        object->flags |= 0x10;
        work = Unk0aa118_Unk_0afb90(object);
        work->id = context->id;
        work->flags = (work->flags & ~0xff) | 1;
        func_0204f108(0, 0x20, Unk09974c_Unk_099bac(context->resource), 0);
        func_0209fd64(object);
        func_020afbdc(object);
        context->flags |= 0x2000;
    }
    if (context->secondary) {
        func_0204f728(0, context->secondary, 8);
        context->flags |= 0x2000;
    }
    if (context->tertiary) {
        slot = func_02049f24(func_02044ec4(context->tertiary), 0);
        parameters[0] = 1;
        func_0204f49c(0, 1);
        func_0204f650(0, context->tertiary, slot, 0x15);
        func_0204f6d8(0, context->tertiary, parameters);
        context->flags |= 0x2000;
    }
    if (context->bits.submitted) {
        state->state = 2;
        return 1;
    }
    return 0;
}
