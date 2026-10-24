#include "types.h"

/* Only the accessed record bytes are known; records have a 68-byte stride. */
typedef struct Unk0fa520Record {
    u8 id;
    u8 pad_01[2];
    u8 category;
    u8 pad_04[64];
} Unk0fa520Record;

/* Allocated output records preserve category order and contain no borrowed pointers. */
typedef struct Unk0fa520Group {
    u32 count;
    u32 category;
    u32 flag;
} Unk0fa520Group;

/* Borrowed work area: unexamined subobjects retain their original byte extents. */
typedef struct Unk0fa520Work {
    u32 unk_00;
    Unk0fa520Record *records;
    u32 record_count;
    void *unk_0c;
    u8 unk_10[28];
    u8 unk_2c[36];
    Unk0fa520Group *groups;
    u32 group_count;
    u8 pad_58[148];
    u32 unk_ec;
    u32 pad_f0;
    u32 unk_f4;
    u16 *unk_f8;
    u32 unk_fc;
    u32 unk_100;
    u32 unk_104;
    u8 pad_108[68];
    u32 unk_14c;
} Unk0fa520Work;

/* Descriptor offsets follow the original initializer; the word at +8 is untouched. */
typedef struct Unk0fa520Descriptor {
    u32 size;
    u32 kind;
    u32 unk_08;
    void (*callback_0c)(Unk0fa520Work *);
    void (*callback_10)(Unk0fa520Work *);
    void (*callback_14)(void);
    void (*callback_18)(Unk0fa520Work *);
    void (*callback_1c)(Unk0fa520Work *);
    void (*callback_20)(Unk0fa520Work *);
} Unk0fa520Descriptor;

void func_020f9900(Unk0fa520Work *w);
void func_020f9b4c(Unk0fa520Work *w);
void Unk0f90dc_Nop_0f9ce4(void);
void func_020f9efc(Unk0fa520Work *w);
void Unk0f90dc_Unk_0fa4cc(Unk0fa520Work *w);
void func_020f9644(Unk0fa520Work *w);
int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(int id);
int Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(int id);
void *func_02052fe0(u32 size);
void Unk0d297c_LoadMissionLog(void);
u32 func_020629ac(int a, int b, int c, int d);
void func_02061e98(u32 handle, int a, int b);
u32 Unk0d297c_Unk_0d3004(void);
void func_02061f10(u32 handle, int a, int b, int c, u32 d);
void *func_020445d0(int id, int selector);
Unk0fa520Record *func_0204fde0(void *resource);
u32 func_0204fe18(void *resource);
void *func_020445f4(int id, int selector);
void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_1242fc(void);
void Unk0bcef4_Unk_0bcef4(void *object, int a, u32 count, int b);
void Unk0bcef4_Unk_0bd29c(void *object, void *source);
void func_020bd1a8(void *object, void *source, int a, int b);

/* Populate the descriptor with a 344-byte work size and the six callbacks whose
 * addresses appear in the original literal pool; unk_08 remains caller-owned. */
void func_020fa520(Unk0fa520Descriptor *descriptor)
{
    descriptor->size = 344;
    descriptor->kind = 1;
    descriptor->callback_0c = func_020f9900;
    descriptor->callback_10 = func_020f9b4c;
    descriptor->callback_14 = Unk0f90dc_Nop_0f9ce4;
    descriptor->callback_18 = func_020f9efc;
    descriptor->callback_1c = Unk0f90dc_Unk_0fa4cc;
    descriptor->callback_20 = func_020f9644;
}

/* Count eligible records by category and allocate compact count/category/flag
 * triples. Eligible records must have a low-seven-bit category in 1..3. */
void func_020fa57c(Unk0fa520Work *w)
{
    u32 counts[3];
    u32 flags[3];
    int i;
    u32 j;
    int out;
    for (i = 0; i < 3; i++) {
        counts[i] = 0;
        flags[i] = 0;
    }
    for (j = 0; j < w->record_count; j++) {
        int id = w->records[j].id;
        if (Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e6448(id)) {
            counts[(w->records[j].category & 0x7f) - 1]++;
            if (Unk0d297c_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Thunk_Unk0e5fb8_Unk_0e64c8(id)) {
                flags[(w->records[j].category & 0x7f) - 1] = 1;
            }
        }
    }
    w->group_count = 0;
    for (i = 0; i < 3; i++) {
        if (counts[i]) w->group_count++;
    }
    w->groups = func_02052fe0(w->group_count * sizeof(Unk0fa520Group));
    int category_index;
    out = 0;
    for (category_index = 0; category_index < 3; category_index++) {
        if (counts[category_index]) {
            w->groups[out].count = counts[category_index];
            w->groups[out].category = category_index + 1;
            w->groups[out].flag = flags[category_index];
            out++;
        }
    }
}

/* Initialize the work area's resources and UI subobjects. Resource IDs 28/29
 * and the call to LoadMissionLog are direct instruction/callee evidence. */
void func_020fa6d8(Unk0fa520Work *w)
{
    void *resource;
    Unk0d297c_LoadMissionLog();
    w->unk_100 = func_020629ac(5, 5, 0, 1);
    func_02061e98(w->unk_100, 16, 1);
    w->unk_104 = func_020629ac(4, 1, 0, 1);
    func_02061e98(w->unk_104, 16, 1);
    func_02061f10(w->unk_104, -1, 0, 0, Unk0d297c_Unk_0d3004());
    resource = func_020445d0(28, 0);
    w->records = func_0204fde0(resource);
    w->record_count = func_0204fe18(resource);
    w->unk_f8 = func_02052fe0(w->record_count * 2);
    w->unk_fc = 0;
    w->unk_0c = func_020445f4(29, 0);
    w->unk_ec = 0;
    w->unk_f4 = 0;
    func_020fa57c(w);
    Unk1241ec_Thunk_02124338();
    Unk1241ec_Unk_1242fc();
    Unk0bcef4_Unk_0bcef4(w->unk_10, 3, w->group_count, 1);
    Unk0bcef4_Unk_0bd29c(w->unk_2c, w->unk_10);
    func_020bd1a8(w->unk_2c, w->unk_10, 0, 1);
    w->unk_14c = 0;
}
