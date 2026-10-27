/* Partial task-effect helpers; layouts and contracts follow the original ARM loads. */
#include "types.h"

/* Borrowed provider object: its representation is not accessed by this unit. */
typedef struct Lib020b78d8Object Lib020b78d8Object;

/* Signed displacement record; components retain the original byte units. */
typedef struct Lib020b78d8Offset {
    s8 x;
    s8 y;
} Lib020b78d8Offset;

/* Caller/provider-owned task prefix. Offsets are established by 020b78dc
 * and 020b7920; each displacement record is two signed bytes. */
typedef struct Lib020b78d8Task {
    u32 unknown_00;
    s32 index;
    s32 count;
    const Lib020b78d8Offset *offsets;
    s32 origin_x;
    s32 origin_y;
} Lib020b78d8Task;

extern Lib020b78d8Object *func_020616c0(Lib020b78d8Task *task);
extern void func_02061424(void *object);
extern void Unk065e88_SetPair04(Lib020b78d8Object *object, s32 x, s32 y);
extern void Unk065e88_SetUnkField2C(Lib020b78d8Object *object, s32 value);
extern void Unk065e88_SetUnkField20(Lib020b78d8Object *object, float value);
extern void func_020b7db4(Lib020b78d8Task *task);

/* The original entry point is only bx lr; it accepts no observed arguments. */
void func_020b78d8(void)
{
}

/* Apply the indexed signed-byte pair relative to the stored origin when the
 * task has an object. Evidence: +0xc table and +0x10/+0x14 additions at 020b78f0. */
void func_020b78dc(Lib020b78d8Task *task)
{
    Lib020b78d8Object *object = func_020616c0(task);
    if (object != 0) {
        const Lib020b78d8Offset *offset = &task->offsets[task->index];
        Unk065e88_SetPair04(object, task->origin_x + offset->x,
            task->origin_y + offset->y);
    }
}

/* Advance one displacement record; on reaching count restore the origin and
 * finish the task. Evidence: signed count comparison and 02061424 call. */
void func_020b7920(Lib020b78d8Task *task)
{
    if (++task->index >= task->count) {
        Lib020b78d8Object *object = func_020616c0(task);
        if (object != 0) {
            Unk065e88_SetPair04(object, task->origin_x, task->origin_y);
        }
        func_02061424(task);
    } else {
        func_020b78dc(task);
    }
}

/* Restore the borrowed object's original pair if present; +0x10/+0x14 are
 * forwarded unchanged in the original body at 020b797c. */
void func_020b796c(Lib020b78d8Task *task)
{
    Lib020b78d8Object *object = func_020616c0(task);
    if (object != 0) {
        Unk065e88_SetPair04(object, task->origin_x, task->origin_y);
    }
}

/* Set the +0x2c flag according to value < 1, then forward value to +0x20.
 * Evidence: _fls against 1.0 and the two field setters at 020b7a34..020b7a74.
 * The float is forwarded without clamping, including unordered values. */
void func_020b7a34(Lib020b78d8Object *object, float value)
{
    if (value < 1.0f) {
        Unk065e88_SetUnkField2C(object, 1);
    } else {
        Unk065e88_SetUnkField2C(object, 0);
    }
    Unk065e88_SetUnkField20(object, value);
}

/* Finish the associated object when present. Evidence: 020b7b90 forwards
 * the lookup result, rather than the incoming task, to 02061424. */
void func_020b7b90(Lib020b78d8Task *task)
{
    Lib020b78d8Object *object = func_020616c0(task);
    if (object != 0) {
        func_02061424(object);
    }
}

/* Advance the fifteen-step effect; finalize the value at 1.0 and finish the
 * task at step 15, otherwise let the existing interpolation provider update it. */
void func_020b7e14(Lib020b78d8Task *task)
{
    if (++task->index >= 15) {
        Lib020b78d8Object *object = func_020616c0(task);
        if (object != 0) {
            func_020b7a34(object, 1.0f);
        }
        func_02061424(task);
    } else {
        func_020b7db4(task);
    }
}

/* Restore value 1.0 on the associated object if present; evidence is the
 * literal 0x3f800000 passed to 020b7a34 at 020b7e68. */
void func_020b7e58(Lib020b78d8Task *task)
{
    Lib020b78d8Object *object = func_020616c0(task);
    if (object != 0) {
        func_020b7a34(object, 1.0f);
    }
}
