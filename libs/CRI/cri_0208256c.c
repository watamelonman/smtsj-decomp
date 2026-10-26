#include "types.h"

extern u32 data_021742c4[2];
extern u32 data_021742bc[2];

/** A borrowed 12-byte callback entry; the third word is not read by this worker. */
typedef struct Cri0208256cEntry {
    u32 (*callback)(u32 argument);
    u32 argument;
    u32 unk08;
} Cri0208256cEntry;

extern Cri0208256cEntry data_0217403c[8][6];
extern u32 data_0217427c[8];
extern u32 data_0217429c[8];
extern u32 data_02173fe8[2];
extern u32 data_02173fe0[2];
extern u32 data_02173ff0;
extern volatile u32 data_02173fd4[2];
extern u32 data_02173ff4[2];

/* The worker combines six callback results for the supplied row index. */
extern u32 func_0208258c(u32 index);

/* Original STM stores both opaque words, in order, at data_021742c4. */
void func_0208256c(u32 first, u32 second)
{
    data_021742c4[0] = first;
    data_021742c4[1] = second;
}

/* Original STM stores both opaque words, in order, at data_021742bc. */
void func_0208257c(u32 first, u32 second)
{
    data_021742bc[0] = first;
    data_021742bc[1] = second;
}

/* Original MOV r0, #0 selects worker row 0; return its combined result. */
u32 func_02082608(void)
{
    return func_0208258c(0);
}

/* Original MOV r0, #1 selects worker row 1; return its combined result. */
u32 func_02082618(void)
{
    return func_0208258c(1);
}

/* Original MOV r0, #2 selects worker row 2; return its combined result. */
u32 func_02082628(void)
{
    return func_0208258c(2);
}

/* Original MOV r0, #3 selects worker row 3; return its combined result. */
u32 func_02082638(void)
{
    return func_0208258c(3);
}

/* Original MOV r0, #4 selects worker row 4; return its combined result. */
u32 func_02082648(void)
{
    return func_0208258c(4);
}

/* Original MOV r0, #5 selects worker row 5; return its combined result. */
u32 func_02082658(void)
{
    return func_0208258c(5);
}

/** Select row 6, as established by the immediate at 02082670. */
u32 func_02082668(void)
{
    return func_0208258c(6);
}

/** Select row 7, as established by the immediate at 02082680. */
u32 func_02082678(void)
{
    return func_0208258c(7);
}

/** Invoke six borrowed entries in row index (0..7), marking active calls and ORing results.
 * Evidence: 72-byte rows, 12-byte stride, indirect call and OR at 0208259c..020825e0.
 */
u32 func_0208258c(u32 index)
{
    int i;
    u32 result;
    Cri0208256cEntry *entry;
    entry = data_0217403c[index];
    result = 0;
    for (i = 0; i < 6; i++, entry++) {
        u32 (*callback)(u32) = entry->callback;
        u32 argument = entry->argument;
        if (callback != 0) {
            data_0217427c[index] = 1;
            result |= callback(argument);
            data_0217427c[index] = 0;
        }
    }
    data_0217429c[index]++;
    return result;
}


/** Clear the state words observed at 02082690..020826f8; callback entries remain borrowed. */
void func_02082688(void)
{
    int i;
    u32 *first = data_021742c4;
    u32 *second = data_021742bc;
    u32 *third = data_02173fe8;
    u32 *fourth = data_02173fe0;
    __builtin__clear(data_0217427c, sizeof(data_0217427c));
    __builtin__clear(first, 8);
    __builtin__clear(second, 8);
    __builtin__clear(third, 8);
    __builtin__clear(fourth, 8);
    for (i = 0; i < 6; i++) data_0217429c[i] = 0;
    data_02173ff0 = 0;
}


/** Reset on the first acquisition, then increment the word at +4 (0208271c..0208273c). */
void func_02082718(void)
{
    if (data_02173fd4[1] == 0) func_02082688();
    data_02173fd4[1]++;
}

/** Release one acquisition; the last release clears state and the final pair (02082750..02082778). */
void func_02082748(void)
{
    data_02173fd4[1]--;
    if (data_02173fd4[1] == 0) {
        func_02082688();
        __builtin__clear(data_02173ff4, sizeof(data_02173ff4));
    }
}
