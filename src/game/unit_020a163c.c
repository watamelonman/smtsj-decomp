#include "types.h"

/* Only the state word at +0x0c is accessed by these callbacks. */
typedef struct Unk0a163cWork {
    u32 unk_0000[3];
    u32 unk_000c;
} Unk0a163cWork;

/* The original list routines read a count and a borrowed entry buffer. */
typedef struct Unk0a163cList {
    u32 count;
    void *entries;
} Unk0a163cList;

extern void *func_020445d0(int group, int table);
extern void *func_020445f4(int group, int table);
extern u32 func_0204fe18(void *resource);
extern void *func_0204fed8(void *resource, u32 index);
extern int func_020a1b08(Unk0a163cList *list, u16 id, u32 value);
extern int func_020a208c(Unk0a163cWork *work);
extern void *func_020a2218(Unk0a163cList *list, u16 id);

/* ARM 0x020a1718: compare the first unsigned halfword of two records.
 * The subtraction promotes both values to int, giving a signed ordering. */
int Unk0a163c_Unk_0a1718(const u16 *left, const u16 *right)
{
    return *left - *right;
}

/* ARM 0x020a1728: return the size/count query for resource (19, 1).
 * The two calls establish the resource selection; its content is unknown. */
u32 Unk0a163c_Unk_0a1728(void)
{
    return func_0204fe18(func_020445d0(19, 1));
}

/* ARM 0x020a1814: return a borrowed entry from resource (18, 1).
 * Index validation and entry lifetime belong to the resource routines. */
void *Unk0a163c_Unk_0a1814(u32 index)
{
    return func_0204fed8(func_020445f4(18, 1), index);
}

/* ARM 0x020a1834: return a borrowed entry from resource (18, 0).
 * Index validation and entry lifetime belong to the resource routines. */
void *Unk0a163c_Unk_0a1834(u32 index)
{
    return func_0204fed8(func_020445f4(18, 0), index);
}

/* ARM 0x020a1ba0: add 500 to the caller's id, wrapping to 16 bits,
 * then forward the list and value to func_020a1b08. */
int Unk0a163c_Call_020a1b08(Unk0a163cList *list, u16 id, u32 value)
{
    return func_020a1b08(list, (u16)(id + 500), value);
}

/* ARM 0x020a21f8: set the state word to 1 before running the shared
 * callback. The caller retains ownership of the work object. */
int Unk0a163c_Unk_0a21f8(Unk0a163cWork *work)
{
    work->unk_000c = 1;
    return func_020a208c(work);
}

/* ARM 0x020a220c: forward the borrowed work object to the shared callback
 * and return its result without modifying the object first. */
int Unk0a163c_Thunk_020a208c(Unk0a163cWork *work)
{
    return func_020a208c(work);
}

/* ARM 0x020a22c8: add 500 to the id, wrapping to 16 bits, and return
 * the matching borrowed list entry (or the callee's null result). */
void *Unk0a163c_Call_020a2218(Unk0a163cList *list, u16 id)
{
    return func_020a2218(list, (u16)(id + 500));
}
