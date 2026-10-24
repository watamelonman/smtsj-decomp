#include "types.h"

/* Local views follow the 16-byte handle records and eight-byte signed rows. */
typedef struct HandleEntry { u32 id; void *handle; u32 flags; u32 extra; } HandleEntry;
typedef struct Row { s16 id; s16 next[3]; } Row;
typedef struct CallbackEntry { int (*call)(s16 *state); u32 extra; } CallbackEntry;
typedef struct Work {
    s16 id;
    s16 index;
    s16 stack[16];
    u16 count;
    s16 state[5];
    Row *rows;
    CallbackEntry *callbacks;
} Work;
extern HandleEntry data_0214283c[];
void *func_0204fdac(void *handle, int index);
void *func_0204fe68(void *handle, int index);
void *func_0204fde0(void *handle);
u32 func_0204fe18(void *handle);
int func_020152cc(const char *left, const char *right);
void func_02008848(void *dest, int value, u32 size);

/* Returns the borrowed handle at offset four; indices outside 0..48 fail. */
void *func_0204459c(int index)
{
    int valid;
    if (index >= 0 && index < 49) valid = 1;
    else valid = 0;
    if (!valid) return 0;
    return ((HandleEntry *)((u8 *)data_0214283c + index * 16))->handle;
}

/* Forwards an indexed request only when the table handle exists. */
void *func_020445d0(int index, int item)
{
    void *handle = func_0204459c(index);
    if (!handle) return 0;
    return func_0204fdac(handle, item);
}

/* Forwards the alternate indexed request through the same handle table. */
void *func_020445f4(int index, int item)
{
    void *handle = func_0204459c(index);
    if (!handle) return 0;
    return func_0204fe68(handle, item);
}

/* Searches the 24-byte records from handle three by their leading string. */
void *func_02044618(const char *name)
{
    void *handle = func_020445d0(3, 0);
    char *record = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    u32 i;
    for (i = 0; i < count; i++, record += 24) {
        if (func_020152cc(record, name) == 0) return record;
    }
    return 0;
}

/* Finds a signed row ID, stripping the greater-than-1000 call marker. */
int func_0204467c(int id, Row *rows, u32 count)
{
    u32 i;
    if (id > 1000) id = (s16)(id - 1000);
    for (i = 0; i < count; i++) {
        if (id == rows[i].id) return (s16)i;
    }
    return -1;
}

/* Selects a row transition; -2 pops saved continuations and -1 stops. */
int func_020446c4(Work *work, u32 choice)
{
    Row *rows;
    int index;
    int save;
    int continuation;
    index = work->index;
    rows = work->rows;
    Row *row = &rows[index];
    continuation = index + 1;
    save = 0;
    int id;
    switch (choice) {
    default:
    case 0:
    case 1:
        id = rows[continuation].id;
        continuation = index + 2;
        break;
    case 2: id = row->next[0]; break;
    case 3: id = row->next[1]; break;
    case 4: id = row->next[2]; break;
    }
    if (id < 0) {
        if (id == -2) {
            do {
                int i = 16;
                while (--i >= 0) {
                    int saved = work->stack[i];
                    if (saved != -1) {
                        id = work->rows[saved].id;
                        continuation = saved + 1;
                        work->stack[i] = -1;
                        break;
                    }
                }
            } while (id == -2);
        } else if (id == -1) return 0;
    }
    if (id > 1000) save = 1;
    id = func_0204467c(id, work->rows, work->count);
    if (id < 0 || id >= work->count) return 0;
    if (save) {
        int i;
        for (i = 0; i < 16; i++) {
            if (work->stack[i] == -1) {
                work->stack[i] = continuation;
                break;
            }
        }
    }
    work->index = id;
    return 1;
}

/* Initializes the 56-byte work block and marks all continuation slots empty. */
void func_02044804(Work *work, Row *rows, u16 count, CallbackEntry *callbacks)
{
    int i;
    func_02008848(work, 0, 56);
    work->rows = rows;
    work->count = count;
    work->callbacks = callbacks;
    work->index = 0;
    for (i = 0; i < 16; i++) work->stack[i] = -1;
    work->id = work->rows[work->index].id;
}

/* Runs the current callback; result two immediately processes the next row. */
int func_02044868(Work *work)
{
    int result = 0;
    int (*callback)(s16 *) = work->callbacks[work->id].call;
    if (callback) result = callback(work->state);
    if (result == 1 || result == 2) {
        work->state[3] = 0;
        if (!func_020446c4(work, work->state[0])) return 0;
        work->id = work->rows[work->index].id;
        if (!work->callbacks[work->id].call) return 0;
        work->state[0] = 0;
    }
    if (result != 2) return 1;
    return func_02044868(work);
}
