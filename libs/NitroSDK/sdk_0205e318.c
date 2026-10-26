#include "types.h"

/* Partial record views; callers must supply valid indices and loaded pointers. */
typedef struct Unk05e318Record { u32 unk_00[6]; } Unk05e318Record;
typedef struct Unk05e318Item {
    u8 pad_00[0x34];
    u32 unk_34[][2];
} Unk05e318Item;
typedef struct Unk05e318Collection {
    u32 unk_00;
    Unk05e318Item **unk_04;
    u8 pad_08[0xc];
    Unk05e318Record *unk_14;
} Unk05e318Collection;

/* Only fields evidenced by loads/stores in this TU are represented. */
typedef struct Unk05e318State {
    u8 pad_00[0x94];
    void *unk_94;
    u32 unk_98;
    /* The original explicitly reloads this allocation slot after writing it. */
    void * volatile unk_9c;
    u32 unk_a0;
    u8 pad_a4[0x28];
    int unk_cc;
    int unk_d0;
    u32 unk_d4;
    u32 unk_d8;
    int unk_dc;
} Unk05e318State;
extern Unk05e318State data_0216b348;
void *func_02052ff0(u32 id);
void *func_0202b768(void *resource, u32 id);
void func_0202b124(Unk05e318State *state, void *buffer, void *resource, int mode);
void func_0202c4ec(void *resource);
u32 func_0202b914(void *resource);
void func_02029e6c(void);
const void *Unk0a0ce4_GetTableEntry(int id);
void func_0208df48(int channel, int flag, int mode, const void *entry);
int func_0208e164(int channel);
int func_0205e484(int id, int mode);
int func_0205e4f8(int id);

/* Returns the indexed 24-byte record (ldr +0x14 and mla stride 24). */
Unk05e318Record *func_0205e318(Unk05e318Collection *collection, u32 index)
{
    return &collection->unk_14[index];
}

/* Returns an eight-byte entry after the item's 0x34-byte header; indices are unchecked. */
u32 *func_0205e328(Unk05e318Collection *collection, u32 item, u32 index)
{
    return collection->unk_04[item]->unk_34[index];
}

/* Returns the unchecked item pointer from the table at +4. */
Unk05e318Item *func_0205e33c(Unk05e318Collection *collection, u32 index)
{
    return collection->unk_04[index];
}

/* Binds a nonzero resource id, initializes its state and marks +0xdc active.
 * Evidence: calls 02052ff0/0202b768 and the field stores at 0205e3f8..0205e458.
 * The first argument is unused; a zero id reuses the previous allocation without initializing it. */
void func_0205e3e4(u32 unused, u32 id, void *buffer)
{
    Unk05e318State *state = &data_0216b348;
    void *resource;
    state->unk_a0 = id;
    if (id != 0) {
        state->unk_9c = func_02052ff0(id);
    }
    resource = state->unk_9c;
    if (resource != 0) {
        state->unk_94 = func_0202b768(resource, id);
    }
    if (id != 0) {
        func_0202b124(state, buffer, state->unk_94, 0);
        func_0202c4ec(state->unk_94);
        state->unk_98 = func_0202b914(state->unk_94);
    }
    data_0216b348.unk_dc = 1;
}

/* Runs 02029e6c only while the state flag at +0xdc is set. */
void func_0205e464(void)
{
    if (data_0216b348.unk_dc != 0) {
        func_02029e6c();
    }
}

/* Submits an inactive id on channel zero and remembers it at +0xcc/+0xd0.
 * Evidence: table lookup and 0208df48 call at 0205e4a4..0205e4d0;
 * id 25 clears the second call argument. Returns whether submission occurred. */
int func_0205e484(int id, int mode)
{
    const void *entry;
    if (func_0205e4f8(id)) {
        return 0;
    }
    entry = Unk0a0ce4_GetTableEntry(id);
    func_0208df48(0, id != 25, mode, entry);
    data_0216b348.unk_d0 = id;
    data_0216b348.unk_cc = id;
    return 1;
}

/* Reuses the remembered +0xcc id with a new mode (tail call at 0205e4ec). */
int func_0205e4dc(int mode)
{
    return func_0205e484(data_0216b348.unk_cc, mode);
}

/* Tests channel zero; negative ids accept any active id, otherwise +0xd0 must match. */
int func_0205e4f8(int id)
{
    if (func_0208e164(0)) {
        if (id < 0) {
            return 1;
        }
        if (data_0216b348.unk_d0 == id) {
            return 1;
        }
    }
    return 0;
}
