#include "types.h"

/* Only fields evidenced by this unit's loads and stores are named. */
typedef struct Entry {
    u32 first;
    u32 second;
    u8 pad08[0xc];
    u32 slot;
    u32 kind;
    u8 pad1c[0x10];
    char name[0x20];
    u8 pad4c[0xc];
    u8 flag;
} Entry;

/* Shared stack has 256 entries; the alternate mode limits it to 64.
 * Count reloads and size-table access ordering preserve the original; see DEC-008.
 * Entry addresses remain 32-bit words, as in the original indexed stores. */
typedef struct Stack {
    u32 entries[256];
    volatile u32 count;
    u32 first;
    u32 second;
    u8 pad40c[0x800];
    u32 initial_first;
    u32 initial_second;
    u32 base;
} Stack;

extern Stack data_0216a730;
extern volatile u32 data_0216ab3c[], data_0216af3c[];
extern char data_02143bdc[];
extern u32 (*data_0213d5e4)(u32 size, int kind, int flags);
extern u32 (*data_0213d5ec)(u32 size, int kind, int flags);
void func_02008848(void *dst, int value, u32 size);
int func_02051bb4(void);
void func_02007e94(void);
void func_020038bc(void);
u32 func_02058420(void);
void func_020587fc(void);
void func_02058824(u32 slot);
Entry *func_0205aa08(void);
void func_02013c14(char *dst, int size, const char *format);
Stack *Unk05b540_GetAddr_data_0216a730(void);

/* Clear the entire 0xc18-byte stack state (the size is explicit in the original). */
void Unk05b540_Clear(void)
{
    func_02008848(&data_0216a730, 0, 0xc18);
}

/* Set the initial cursors and saved base; stores at +0x404/+0xc0c evidence the pairs. */
void Unk05b540_Init(u32 a, u32 b, u32 c)
{
    Unk05b540_Clear();
    data_0216a730.initial_first = a;
    data_0216a730.initial_second = b + c;
    data_0216a730.base = b;
    data_0216a730.first = a;
    data_0216a730.second = b + c;
}

/* Push a borrowed entry, reserving two sizes; kind 2 bypasses 16-byte alignment. */
void func_0205b598(Entry *entry, u32 first_size, u32 second_size)
{
    if (func_02051bb4() == 0) {
        u32 first, second;
        if (data_0216a730.count >= 256) {
            func_02007e94();
            return;
        }
        first = data_0216a730.first;
        second = data_0216a730.second;
        if (entry->kind != 2) {
            if (second & 15) second = (second + 16) & ~15;
        }
        entry->first = first;
        entry->second = second;
        data_0216a730.first = first + first_size;
        data_0216a730.second = second + second_size;
        data_0216ab3c[data_0216a730.count] = first_size;
        data_0216af3c[data_0216a730.count] = second_size;
        func_020038bc();
        if (data_0216a730.first >= func_02058420()) {
            Stack *stack = Unk05b540_GetAddr_data_0216a730();
            u32 i;
            for (i = 0; i < stack->count; i++) {
                if (stack->entries[i] == 0) break;
            }
            func_02007e94();
        }
    } else {
        if (data_0216a730.count >= 64) {
            func_02007e94();
            return;
        }
        func_020587fc();
        entry->slot = data_0216a730.count;
        if (first_size != 0) {
            u32 first = data_0213d5e4(first_size, 0, 0);
            u32 second = data_0213d5ec(second_size, entry->kind == 2, 0);
            entry->first = (u16)first * 8;
            entry->second = (u16)second * 8;
        }
    }
    data_0216a730.entries[data_0216a730.count] = (u32)entry;
    data_0216a730.count++;
}

/* Pop a borrowed entry, restoring cursors or releasing its alternate-mode slot. */
Entry *func_0205b724(void)
{
    Entry *entry = 0;
    u32 count = data_0216a730.count;
    if (count != 0) {
        count--;
        data_0216a730.count = count;
        entry = (Entry *)data_0216a730.entries[count];
        if (func_02051bb4() == 0) {
            count = data_0216a730.count;
            if (count != 0) {
                data_0216a730.first -= data_0216ab3c[count];
                data_0216a730.second -= data_0216af3c[count];
            } else {
                data_0216a730.first = data_0216a730.initial_first;
                data_0216a730.second = data_0216a730.initial_second;
            }
        } else {
            func_02058824(entry->slot);
        }
    }
    return entry;
}

/* Return the stack depth, evidenced by the shared push/pop counter at +0x400. */
u32 Unk05b540_Unk_05b7c0(void)
{
    return data_0216a730.count;
}

/* Return the saved base supplied to Init, without transferring ownership. */
u32 Unk05b540_Unk_05b7d0(void)
{
    return data_0216a730.base;
}

/* Expose the borrowed shared stack address for callers inspecting its entries. */
Stack *Unk05b540_GetAddr_data_0216a730(void)
{
    return &data_0216a730;
}

/* Name and flag the optional entry returned by 0205aa08, then push zero sizes. */
void Unk05b540_Unk_05b7ec(void)
{
    Entry *entry = func_0205aa08();
    if (entry == 0) return;
    func_02013c14(entry->name, 0x20, data_02143bdc);
    entry->flag = 1;
    func_0205b598(entry, 0, 0);
}
