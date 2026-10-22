/* src/game/unit_020caea8.c: matched functions from the delinked original. */
#include "types.h"

/* func_0202b730 stores its argument in the +0x90 field of the object whose
 * pointer lives at data_0215d070 (see the callee's ldr/str pair). */
void func_0202b730(u32 value);

/* func_020445f4 resolves the (group, index) table entry of a resource; the
 * unit uses group 10, entries 0..2. func_0204fed8 indexes that entry and
 * returns a pointer to the selected element. */
u32 func_020445f4(u32 group, u32 index);
u32 func_0204fed8(u32 entry, u32 index);

/* func_0204fdac resolves the index'th subtable of an object (it forwards both
 * arguments to func_0204fd4c). func_0204fe18 returns the subtable's element
 * count and func_0204fde0 its element base. */
u32 func_0204fdac(u32 object, u32 index);
u32 func_0204fe18(u32 table);
u32 func_0204fde0(u32 table);

/* Unk0a0ce4_Unk_0a0d30 swaps the object at data_02176afc and re-binds it to
 * its owner; it ignores a repeated or null argument. */
int Unk0a0ce4_Unk_0a0d30(u32 object);

/* func_02053000 releases an object and clears its owner slot. */
int func_02053000(u32 object);

/* data_02176bc0 holds the active record pointer for this unit. */
extern u32 data_02176bc0[];

/* Releases the active record pointer, if any, and clears it. The return value
 * is unconditional so callers can use it as a "done" flag. */
u32 Unk0caea8_Unk_0caf48(void)
{
    if (*data_02176bc0 != 0) {
        func_02053000(*data_02176bc0);
        *data_02176bc0 = 0;
    }
    return 1;
}

/* Sets the shared +0x90 field to 0x400. */
void Unk0caea8_Unk_0caf78(void)
{
    func_0202b730(0x400);
}

/* Sets the shared +0x90 field back to 0. */
void Unk0caea8_Unk_0caf88(void)
{
    func_0202b730(0);
}

/* Raises the shared +0x90 field to 0x400, binds arg0 to data_02176afc, then
 * restores the field. */
void Unk0caea8_Unk_0caf98(u32 arg0)
{
    func_0202b730(0x400);
    Unk0a0ce4_Unk_0a0d30(arg0);
    func_0202b730(0);
}

/* Searches the active record's first subtable for a 4-byte {u16 x; u16 y;}
 * entry matching (arg0, arg1). Returns 1 on a hit and 0 otherwise.
 * The record comes from data_02176bc0; a null record never matches. */
u32 func_020cafbc(u32 x, u32 y)
{
    int handle;
    u32 count;
    u16 *entry;
    u32 i;

    if (*data_02176bc0 == 0) {
        return 0;
    }
    handle = func_0204fdac(*data_02176bc0, 0);
    count = func_0204fe18(handle);
    entry = (u16 *)func_0204fde0(handle);
    i = 0;
    while (i < count) {
        u16 a = entry[0];
        u16 b = entry[1];
        if (a == x && b == y) {
            return 1;
        }
        if (i == count - 1) {
            break;
        }
        i++;
        entry += 2;
    }
    return 0;
}

/* Looks up element arg0 of resource entry 10/0; the pointer is discarded. */
void Unk0caea8_Unk_0cb044(u32 index)
{
    u32 entry = func_020445f4(10, 0);
    func_0204fed8(entry, index);
}

/* Looks up element arg0 of resource entry 10/1; the pointer is discarded. */
void Unk0caea8_Unk_0cb064(u32 index)
{
    u32 entry = func_020445f4(10, 1);
    func_0204fed8(entry, index);
}

/* func_0204ff30 returns a resource entry's first element index; func_0204ff64
 * returns its last element index (first + count - 1). */
u32 func_0204ff30(u32 entry);
u32 func_0204ff64(u32 entry);

/* Returns the resource entry 10/2 element at index i when i lies in the
 * entry's [first, last] range, else null. */
u32 Unk0caea8_GetInRange(u32 i)
{
    u32 entry = func_020445f4(10, 2);
    if (func_0204ff30(entry) <= i && i <= func_0204ff64(entry)) {
        return func_0204fed8(entry, i);
    }
    return 0;
}
