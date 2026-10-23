#include "types.h"

/* Borrowed 0xf8-byte state; offsets agree with initialization in 020cd594. */
typedef struct Unk0cd6ecWork {
    u8 state;
    u8 substate;
    u8 saved_state;
    u8 pad_0003;
    u32 unk_0004;
    u32 unk_0008;
    void *items[4]; /* Extent inferred from the handle at +0x1c. */
    void *handle;
    u8 records[0xd0]; /* Opaque embedded records and controls, through +0xef. */
    u32 unk_00f0;
    u32 unk_00f4;
} Unk0cd6ecWork;

extern int func_020cb5b4(u32 value, u8 *substate);
void func_020ce2d8(Unk0cd6ecWork *work);
extern void func_020ce33c(Unk0cd6ecWork *work);
extern void Unk0a0ce4_Unk_0a0da4(int value);
extern void Unk122e1c_Unk_123294(void *handle);
extern int Unk0de678_CountLeading(void *records);
extern void func_020ffebc(void *item);
extern void Unk0cb32c_Unk_0cb754(void **handle);
extern void Unk0bc1a8_Unk_0bc9b4(int id, int value);
extern void Unk0fd268_Unk_0fd3ac(void);
extern void ImageBg_Unk_0e5530(void);
extern void func_02122e1c(void *handle);
extern void Unk0de678_Unk_0dea60(void);
extern Unk0cd6ecWork *data_02176bcc;
extern int func_021072c0(void);
extern int func_02107374(void);
extern void Unk122e1c_Unk_122fa0(void *handle, int index, u32 value);

/* Release counted non-null items and the handle, then clear the global state owner.
 * Evidence: 020cd594 creates these items and stores the state in data_02176bcc. */
void func_020cd6ec(Unk0cd6ecWork *work)
{
    int i;
    Unk0bc1a8_Unk_0bc9b4(10, 0);
    for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
        if (work->items[i] != 0) {
            func_020ffebc(work->items[i]);
            work->items[i] = 0;
        }
    }
    Unk0fd268_Unk_0fd3ac();
    ImageBg_Unk_0e5530();
    func_02122e1c(work->handle);
    work->handle = 0;
    Unk0de678_Unk_0dea60();
    data_02176bcc = 0;
}

/* Dispatch result codes 1/2 to transitions; code 3 restores the saved state. */
void Unk0cd6ec_Unk_0cddd0(Unk0cd6ecWork *work, u32 value)
{
    int result = func_020cb5b4(value, &work->substate);
    if (result == 1) {
        func_020ce2d8(work);
    } else if (result == 2) {
        func_020ce33c(work);
    } else if (result == 3) {
        work->state = work->saved_state;
    }
}

/* Set state 12 and saved state 4 after requesting helper mode 5. */
void Unk0cd6ec_Unk_0ce280(Unk0cd6ecWork *work, u32 value)
{
    Unk0a0ce4_Unk_0a0da4(5);
    work->saved_state = 4;
    work->state = 12;
    work->unk_0008 = value;
}

/* Refresh the borrowed handle and enter state 3 with a saved state of 1. */
void Unk0cd6ec_Unk_0ce2ac(Unk0cd6ecWork *work, u32 value)
{
    Unk122e1c_Unk_123294(work->handle);
    work->unk_00f0 = value;
    work->saved_state = 1;
    work->state = 3;
}

/* Release counted items and reset the handle and +0xf4 transition flag. */
void func_020ce2d8(Unk0cd6ecWork *work)
{
    int i;
    for (i = 0; i < Unk0de678_CountLeading(work->records); i++) {
        if (work->items[i] != 0) {
            func_020ffebc(work->items[i]);
            work->items[i] = 0;
        }
    }
    Unk0cb32c_Unk_0cb754(&work->handle);
    work->unk_00f4 = 0;
}

/* Callback tests +0xf4 but performs no work on either path, as at 020ce3e0. */
void func_020ce3e0(Unk0cd6ecWork *work)
{
    if (work->unk_00f4 == 0) return;
}

/* Empty callback slot, evidenced by the sole return at 020ce3ec. */
void Unk0cd6ec_Nop_0ce3ec(void) { }

/* Map the two helper predicates to handle slots 1/2 and their union to slot 0. */
void func_020ce500(Unk0cd6ecWork *work)
{
    int a = 0;
    int b = 0;
    if (func_021072c0() != 0) a = 1;
    if (func_02107374() != 0) b = 1;
    Unk122e1c_Unk_122fa0(work->handle, 1, a);
    Unk122e1c_Unk_122fa0(work->handle, 2, b);
    if (a == 0 && b == 0) {
        Unk122e1c_Unk_122fa0(work->handle, 0, 0);
    } else {
        Unk122e1c_Unk_122fa0(work->handle, 0, 1);
    }
}
