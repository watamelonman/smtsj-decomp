#include "types.h"

/* Only fields evidenced by this unit's loads and stores are named by offset. */
typedef struct ScriptWork {
    u8 reserved00[0x40];
    u32 field40;
    u32 reserved44;
    u32 field48;
    u32 field4c;
    u8 reserved50[0x14];
    u16 field64;
} ScriptWork;

/* Two halfwords are passed as one aggregate; preserve their order and width. */
typedef struct Pair {
    u16 first;
    u16 second;
} Pair;

/* Search records occupy 0x2e0 bytes; the ID is a halfword at +0x1d8. */
typedef struct Record {
    u32 key;
    u8 reserved04[0x1d4];
    u16 id;
    u8 reserved1da[0x106];
} Record;

extern ScriptWork *Unk0bac80_Unk_0badc0(void);
extern u32 Unk0bac80_Unk_0badd0(int table);
extern int func_0204fe18(void);
extern u16 *func_0204fde0(u32 handle);
extern int func_0203ac00(int argument);
extern int func_02050074(int lower, int upper);
extern void Unk03aae8_Unk_03acf4(int value);
extern void func_020fdaa8(int selector, int value);
extern void *func_02044ec4(u32 key);
extern void func_02049c28(void *record, Pair *out);
extern void func_020b1f48(Pair value, int zero, int kind);
extern u8 *Unk044904_Get_data_0215ee98(void);

/* Original calls select table 3, offset its generated index by argument 0,
 * clamp to [0, count-1], and publish the selected halfword. Count must be positive. */
u32 func_020bbd6c(void)
{
    u32 handle = Unk0bac80_Unk_0badd0(3);
    int count = func_0204fe18();
    u16 *table = func_0204fde0(handle);
    int offset = func_0203ac00(0);
    int index = func_02050074(0, count - 1);
    index += offset;
    if (index >= count) index = count - 1;
    if (index < 0) index = 0;
    Unk03aae8_Unk_03acf4(table[index]);
    return 1;
}

/* Original stores command argument 0 as a word at work offset 0x48. */
u32 Unk0bbd6c_Unk_0bbdd0(void)
{
    ScriptWork *work = Unk0bac80_Unk_0badc0();
    work->field48 = func_0203ac00(0);
    return 3;
}

/* Original stores the low halfword of argument 0 at work offset 0x64. */
u32 Unk0bbd6c_Unk_0bbdf0(void)
{
    ScriptWork *work = Unk0bac80_Unk_0badc0();
    work->field64 = func_0203ac00(0);
    return 3;
}

/* Original forwards argument 0 with selector 1 to func_020fdaa8. */
u32 Unk0bbd6c_Unk_0bbe10(void)
{
    int value = func_0203ac00(0);
    func_020fdaa8(1, value);
    return 1;
}

/* Original forwards argument 0 with selector 2 to func_020fdaa8. */
u32 Unk0bbd6c_Unk_0bbe30(void)
{
    int value = func_0203ac00(0);
    func_020fdaa8(2, value);
    return 1;
}

/* Original resolves work key +0x40, extracts two halfwords, then passes them
 * by value with a flag indicating whether key bits 16..23 equal 1. */
u32 func_020bbe50(void)
{
    ScriptWork *work = Unk0bac80_Unk_0badc0();
    void *record = func_02044ec4(work->field40);
    Pair pair = {0, 0};
    func_02049c28(record, &pair);
    func_020b1f48(pair, 0, ((work->field40 >> 16) & 255) == 1);
    return 1;
}

/* Original publishes zero through the same result channel as nearby handlers. */
u32 Unk0bbd6c_Unk_0bbec0(void)
{
    Unk03aae8_Unk_03acf4(0);
    return 1;
}

/* Original searches twelve 0x2e0-byte records starting at global +0x36c.
 * The first kind-1 record with matching low-16-bit argument ID supplies work +0x4c. */
u32 func_020bbf44(void)
{
    ScriptWork *work = Unk0bac80_Unk_0badc0();
    u16 id = func_0203ac00(0);
    int i;
    Record *record = (Record *)(Unk044904_Get_data_0215ee98() + 0x36c);
    for (i = 0; i < 12; i++, record++) {
        u32 key = record->key;
        if (((key >> 16) & 255) == 1 && record->id == id) {
            work->field4c = key;
            break;
        }
    }
    return 1;
}
