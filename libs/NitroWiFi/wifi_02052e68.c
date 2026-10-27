#include "types.h"

/* Buffer-group bookkeeping shared by the WiFi transfer helpers. Evidence:
 * func_02052e68 stores the arena-2 span at +0xc and the heap array at +8,
 * func_02052f7c indexes that array by the halfword at +0, and func_02053000
 * decrements the word at +4. No public NitroWiFi source was available, so the
 * fields keep offset-based names. */
typedef struct Unk52e68State {
    u16 current;       /* heap index used by func_02052f7c */
    u16 saved;         /* value restored by func_02052f68 */
    u32 unk_04;        /* live-buffer counter changed by 02052f7c/02053000 */
    u32 *chunks;       /* heap descriptor array, one entry per chunk + 1 */
    u32 arena2_size;   /* bytes that arena 2 contributes to the group */
} Unk52e68State;

/* Connection state block. func_0205304c changes the word at +0x14 and calls
 * the +0x40 callback, so only those offsets are named here. */
typedef struct Unk52e68Conn {
    u8 pad_00[0x14];
    s32 state;
    u8 pad_18[0x18];
    u32 unk_30;
    u8 pad_34[0x0c];
    u32 unk_40;
} Unk52e68Conn;

/* Event block passed to func_020531d8: the halfword at +2 is the state value
 * forwarded to func_020530b0, and zero selects the func_0205304c path. */
typedef struct Unk52e68Event {
    u16 unk_00;
    u16 unk_02;
} Unk52e68Event;

extern Unk52e68State data_0215f4d8;
extern Unk52e68Conn data_0215f500;

/* Arena bound queries: func_02006ed8 yields the base used for allocation and
 * func_02006ec4 the matching end, so the difference is the available span. */
u32 func_02006ed8(u32 arena);
u32 func_02006ec4(u32 arena);
/* Builds a heap descriptor at base for size bytes (mode selects the heap
 * variant) and returns its address; 0 when the aligned span is under 0x4c. */
u32 func_02020438(u32 base, u32 size, u32 mode);
/* Allocates one buffer from the selected heap; flag chooses head vs tail. */
u32 func_02052f7c(u32 size, u32 flag);
/* Switches the connection state and dispatches its enter/leave callbacks. */
void func_0205304c(u32 state);
/* Stores value in the connection block unless a shutdown state is active. */
void func_020530b0(u32 value);

/* Builds a group of heaps for count transfer chunks. Evidence: two arena
 * spans are summed (arena 2 also recorded at +0xc), an aligned (count + 1)-word
 * descriptor array is taken at the arena-0 base, then each requested size is
 * rounded up to 32 bytes and given its own heap from the remaining span. The
 * last slot receives whatever is left. Sizes must be nonnegative; count 0 and
 * a null sizes pointer both produce just the trailing heap. Returns 1. */
int func_02052e68(u32 *sizes, u16 count)
{
    u32 start;
    u32 end;
    u32 total;
    u32 size;
    u32 heap;
    u32 cursor;
    int i;
    u32 chunk_size;

    start = func_02006ed8(0);
    end = func_02006ec4(0);
    total = end - start;
    start = func_02006ed8(2);
    end = func_02006ec4(2);
    size = end - start;
    data_0215f4d8.arena2_size = size;
    total += size;
    heap = func_02006ed8(0);
    size = ((count + 1) * 4 + 31) & ~31;
    data_0215f4d8.chunks = (u32 *)heap;
    cursor = heap + size;
    total -= size;
    if (sizes != 0) {
        for (i = 0; i < count; i++) {
            chunk_size = (sizes[i] + 31) & ~31;
            data_0215f4d8.chunks[i] = func_02020438(cursor, chunk_size, 2);
            cursor += chunk_size;
            total -= chunk_size;
        }
    }
    data_0215f4d8.chunks[count] = func_02020438(cursor, total, 2);
    data_0215f4d8.current = count;
    data_0215f4d8.saved = count;
    return 1;
}

/* Selects the heap index used by func_02052f7c. The stored field is a u16, so
 * values above 0xffff are truncated. */
void func_02052f58(u32 value)
{
    data_0215f4d8.current = value;
}

/* Restores the heap index saved at +2. Caller func_020caea8 brackets a record
 * load with func_02052f58(0) / func_02052f68, which is the evidence for the
 * save/restore pairing. */
void func_02052f68(void)
{
    data_0215f4d8.current = data_0215f4d8.saved;
}

/* Allocates size bytes from the current heap preferring the head of the free
 * span (flag 1 becomes allocation mode 32 in func_02052f7c). */
void func_02052fe0(u32 size)
{
    func_02052f7c(size, 1);
}

/* Same allocation with flag 0; func_02052f7c turns that into mode -32 (tail). */
void func_02052ff0(u32 size)
{
    func_02052f7c(size, 0);
}

/* Empty hook: the delinked body is a lone return, and both callers
 * (0x020481f4 and 0x020a0e38) discard the result. */
void func_02053048(void)
{
}

/* Records a pending state value unless the connection is in state 9 or 10.
 * Evidence: the ROM subtracts 9 and uses an unsigned "> 1" test, i.e. the
 * store is skipped only for exactly 9 and 10. The value lands at +0x30 of the
 * connection block, next to the state field at +0x14. */
void func_020530b0(u32 value)
{
    if ((u32)(data_0215f500.state - 9) > 1) {
        data_0215f500.unk_30 = value;
    }
}

/* Handles one event: a nonzero event value (already loaded from +2) is passed
 * to func_020530b0, while zero asks func_0205304c for state 1. The state
 * machine wrapper func_020531b0 is the only caller. */
void func_020531d8(Unk52e68Event *event)
{
    if (event->unk_02 != 0) {
        func_020530b0(event->unk_02);
    } else {
        func_0205304c(1);
    }
}

/* Reads the connection state word at +0x14; func_0205304c is the writer. */
s32 func_020533d4(void)
{
    return data_0215f500.state;
}
