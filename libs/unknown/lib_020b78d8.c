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
extern s32 func_0205eae0(s32 start, s32 end, s32 duration, s32 step);
extern void Unk065e88_SetUnkField28(Lib020b78d8Object *object, u32 value);
extern Lib020b78d8Task *func_020611dc(void (*update)(Lib020b78d8Task *),
    void (*draw)(Lib020b78d8Task *), void (*other)(Lib020b78d8Task *),
    void (*finish)(Lib020b78d8Task *), u32 size, u32 category, u16 priority, u32 flags);
extern void func_020615ec(Lib020b78d8Task *task, Lib020b78d8Object *object);
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

/* Interpolate from one to zero over fifteen steps, then update the borrowed
 * object. Evidence: step +4, _fmul/_fdiv/_fadd and 020b7a34 calls. */
void func_020b7a78(Lib020b78d8Task *task)
{
    float value = 1.0f;
    if (task->index != 0) {
        if (task->index >= 15) {
            value = 0.0f;
        } else {
            value = -1.0f;
            value = (value * (float)task->index) / 15.0f;
            value += 1.0f;
        }
    }
    {
        Lib020b78d8Object *object = func_020616c0(task);
        if (object != 0) func_020b7a34(object, value);
    }
}

/* Pack the interpolated intensity (minimum 76) into the upper three bytes;
 * the low byte stays 255. Evidence: shifts/masks and field +0x28 setter. */
void func_020b7ae4(Lib020b78d8Task *task)
{
    s32 value = func_0205eae0(255, 0, 15, task->index);
    u32 packed;
    Lib020b78d8Object *object;
    if (value < 76) value = 76;
    packed = (((u32)value << 8) & 0xff00) +
        ((((u32)value << 24) & 0xff000000) + (((u32)value << 16) & 0xff0000));
    object = func_020616c0(task);
    if (object != 0) Unk065e88_SetUnkField28(object, packed + 255);
}

/* Advance both effects, restoring zero and releasing the task at step 15;
 * the original terminal branch omits the packed-color update. */
void func_020b7b44(Lib020b78d8Task *task)
{
    if (++task->index >= 15) {
        Lib020b78d8Object *object = func_020616c0(task);
        if (object != 0) func_020b7a34(object, 0.0f);
        func_02061424(task);
    } else {
        func_020b7a78(task);
        func_020b7ae4(task);
    }
}

/* Allocate eight bytes of provider task state, bind the borrowed object and
 * apply step zero. The provider owns the returned task, including null failure. */
Lib020b78d8Task *func_020b7ba8(Lib020b78d8Object *object)
{
    Lib020b78d8Task *task = func_020611dc(func_020b7b44, 0, 0, func_020b7b90, 8, 4, 0, 0);
    if (task != 0) {
        func_020615ec(task, object);
        task->index = 0;
        func_020b7a78(task);
        func_020b7ae4(task);
    }
    return task;
}

/* Interpolate zero to one over fifteen steps for the associated object;
 * endpoint branches and float operations follow 020b7db4..020b7e10. */
void func_020b7db4(Lib020b78d8Task *task)
{
    float value = 0.0f;
    if (task->index != 0) {
        value = 1.0f;
        if (task->index < 15) value = (value * (float)task->index) / 15.0f;
    }
    {
        Lib020b78d8Object *object = func_020616c0(task);
        if (object != 0) func_020b7a34(object, value);
    }
}

/* Allocate provider-owned eight-byte state and initialize the rising effect;
 * object association is borrowed, and allocation failure returns null. */
Lib020b78d8Task *func_020b7e74(Lib020b78d8Object *object)
{
    Lib020b78d8Task *task = func_020611dc(func_020b7e14, 0, 0, func_020b7e58, 8, 4, 0, 0);
    if (task != 0) {
        func_020615ec(task, object);
        task->index = 0;
        func_020b7db4(task);
    }
    return task;
}

/* Borrowed singleton prefix: the original loop inspects ten slots at +0x64. */
typedef struct {
    u8 padding[0x64];
    struct Lib020b78d8Entry { u32 identifier; } *objects[10];
} Lib020b78d8State;
extern Lib020b78d8State *Unk044904_Get_data_0215ee98(void);
extern void func_020b7ee0(u32 identifier, s32 mode);

/* Submit mode six for type-two IDs other than excluded, as established by
 * the +0x64 slot loads and ID bits 16..23. Singleton storage stays borrowed. */
void func_020b801c(u32 excluded)
{
    Lib020b78d8State *state = Unk044904_Get_data_0215ee98();
    s32 i;
    for (i = 0; i < 10; i++) {
        if (state->objects[i] != 0) {
            u32 id = state->objects[i]->identifier;
            if (((id >> 16) & 255) == 2 && id != excluded) func_020b7ee0(id, 6);
        }
    }
}

/* Submit mode seven for each type-two ID in the ten borrowed object slots;
 * evidence is the ID byte extraction and 020b7ee0 call at 020b80b4. */
void func_020b8078(void)
{
    Lib020b78d8State *state = Unk044904_Get_data_0215ee98();
    s32 i;
    for (i = 0; i < 10; i++) {
        if (state->objects[i] != 0) {
            u32 id = state->objects[i]->identifier;
            if (((id >> 16) & 255) == 2) func_020b7ee0(id, 7);
        }
    }
}
