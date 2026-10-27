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
    u8 pad_00[6];
    u16 unk_06;
    u8 pad_08[2];
    u16 unk_0a;
    u8 pad_0c[8];
    s32 state;
    u8 pad_18[0x18];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3c;
    void (*unk_40)(const void *argument, ...);
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
/* Returns allocated storage from the selected heap; flag chooses head vs tail. */
void *func_02052f7c(u32 size, u32 flag);
/* Switches the connection state and dispatches its enter/leave callbacks. */
void func_0205304c(u32 state);
/* Stores value in the connection block unless a shutdown state is active. */
void func_020530b0(u32 value);

/* Interrupt providers return/restore the previous interrupt-enable mask. */
u32 func_02007a58(void);
void func_02007a6c(u32 mask);
/* Heap storage remains owned by the selected group. */
void *func_02020470(u32 heap, u32 size, s32 alignment);
u32 func_0201ff28(void *buffer);
void func_020204a0(u32 heap, void *buffer);
/* Asynchronous providers borrow callbacks; result 2 means accepted. */
s32 func_02010a94(void (*callback)(Unk52e68Event *), u32 argument);
s32 func_02010a14(void (*callback)(Unk52e68Event *));
s32 func_02010bec(void *work);
void func_02007e94(void);
extern u8 data_0215fdc0[];
extern const u8 data_02143a34[];
void func_020531d8(Unk52e68Event *event);
void func_02053324(Unk52e68Event *event);
void func_020533ac(Unk52e68Event *event);
void func_020533e4(void);
s32 func_020531b0(void);
s32 func_02053288(void);
s32 func_02053348(void);

/* Borrowed notification tables and work remain owned by their providers. */
extern const u32 data_021439e0[];
extern const u8 data_02143a08[], data_02143a10[], data_02143a14[];
extern const u8 data_02143a50[], data_02143a6c[];
extern u8 data_0215f5a0[];
s32 func_02010c34(void *work);
s32 func_02053130(void);
s32 func_020531fc(void);
s32 func_02053230(void);

/* Callback contracts borrow the event only for the provider invocation. */
typedef void (*Unk52e68Callback)(Unk52e68Event *event);

/* Existing asynchronous providers return 2 when the request is accepted. */
s32 func_02010b7c(Unk52e68Callback callback);
s32 func_02010a54(Unk52e68Callback callback);
s32 func_020109dc(Unk52e68Callback callback);
/* Existing event callbacks retain ownership of no event storage. */
void func_02053160(Unk52e68Event *event);
void func_02053378(Unk52e68Event *event);
void func_020532b8(Unk52e68Event *event);
/* Existing follow-up and cleanup providers use the shared connection state. */
s32 func_020532ec(void);
void func_0205342c(void);

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

/* Allocates from the indexed heap under the interrupt mask; the BL to
 * 02020470 and +4 increment identify the live-buffer count. Nonzero flag
 * selects head alignment 32, zero selects tail alignment -32. */
void *func_02052f7c(u32 size, u32 flag)
{
    u32 mask;
    void *buffer;
    mask = func_02007a58();
    buffer = func_02020470(data_0215f4d8.chunks[data_0215f4d8.current], size, flag ? 32 : -32);
    if (buffer != 0) {
        data_0215f4d8.unk_04++;
    }
    func_02007a6c(mask);
    return buffer;
}

/* Allocates size bytes from the current heap preferring the head of the free
 * span (flag 1 becomes allocation mode 32 in func_02052f7c). Returns the
 * allocated storage, as used by func_020517f8 in sdk_02051378.c. */
void *func_02052fe0(u32 size)
{
    return func_02052f7c(size, 1);
}

/* Returns allocated storage with flag 0 (mode -32, tail). Evidence:
 * func_0208daa0 in cri_0208d8e8.c forwards the pointer to its caller. */
void *func_02052ff0(u32 size)
{
    return func_02052f7c(size, 0);
}

/* Frees a non-null buffer in its containing heap with interrupts masked.
 * Evidence: 0201ff28 supplies the heap to 020204a0, then +4 decrements.
 * The caller relinquishes the buffer; null leaves the count unchanged. */
void func_02053000(void *buffer)
{
    u32 mask = func_02007a58();
    if (buffer != 0) {
        func_020204a0(func_0201ff28(buffer), buffer);
        data_0215f4d8.unk_04--;
    }
    func_02007a6c(mask);
}

/* Empty hook: the delinked body is a lone return, and both callers
 * (0x020481f4 and 0x020a0e38) discard the result. */
void func_02053048(void)
{
}

/* Notifies the borrowed callback before and after changing state +0x14.
 * Evidence: BLX uses tables 02143a08/02143a10 and the state-indexed word
 * from 021439e0. State must index that provider-owned table. */
void func_0205304c(u32 state)
{
    if (data_0215f500.unk_40 != 0) {
        data_0215f500.unk_40(data_02143a08, data_021439e0[data_0215f500.state]);
    }
    data_0215f500.state = state;
    if (data_0215f500.unk_40 != 0) {
        data_0215f500.unk_40(data_02143a10, data_021439e0[state]);
    }
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

/* Submits borrowed work 0215f5a0, then requests 02053130. Evidence:
 * ordered BLs at 020530d4..020530ec. Rejection notifies with 02143a14
 * and cleans up; returns one only when both requests succeed. */
s32 func_020530cc(void)
{
    s32 result = func_02010c34(data_0215f5a0);
    if (result != 0) {
        func_020530b0(result);
        return 0;
    }
    if (!func_02053130()) {
        if (data_0215f500.unk_40 != 0) {
            data_0215f500.unk_40(data_02143a14);
        }
        func_020533e4();
        return 0;
    }
    return 1;
}

/* Requests state 3 before submitting callback 02053160 to provider 02010b7c.
 * Evidence: ordered BLs at 02053134..02053140; result 2 means accepted.
 * Other results are recorded at connection +0x30; returns acceptance as 0/1. */
s32 func_02053130(void)
{
    s32 result;
    func_0205304c(3);
    result = func_02010b7c(func_02053160);
    if (result == 2) {
        return 1;
    }
    func_020530b0(result);
    return 0;
}

/* Borrows event +2: errors are recorded before cleanup; successful events
 * run 020531b0. A rejected follow-up notifies the +0x40 callback with the
 * ROM table at 02143a34, then cleans up. Evidence: ordered BL/BLX paths. */
void func_02053160(Unk52e68Event *event)
{
    if (event->unk_02 != 0) {
        func_020530b0(event->unk_02);
        func_020533e4();
    } else if (!func_020531b0()) {
        if (data_0215f500.unk_40 != 0) {
            data_0215f500.unk_40(data_02143a34);
        }
        func_020533e4();
    }
}

/* Submits callback 020531d8 to provider 02010a54. Evidence: callback literal
 * and CMP #2 at 020531b4..020531bc. Rejected results go to +0x30. */
s32 func_020531b0(void)
{
    s32 result = func_02010a54(func_020531d8);
    if (result == 2) {
        return 1;
    }
    func_020530b0(result);
    return 0;
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

/* Clears connection halfword +0xa and requests state 3 only from state 2.
 * Evidence: LDR +0x14, CMP #2 and STRH +0xa at 02053204..0205321c.
 * Returns whether the transition was requested; shared storage stays owned. */
s32 func_020531fc(void)
{
    if (data_0215f500.state != 2) {
        return 0;
    }
    data_0215f500.unk_0a = 0;
    func_0205304c(3);
    return 1;
}

/* Requests state 3 and submits callback 020532b8 to provider 02010b7c.
 * Evidence: ordered BLs and callback literal at 0205328c..020532b4.
 * Returns 1 for provider result 2, otherwise records the result and returns 0. */
s32 func_02053288(void)
{
    s32 result;
    func_0205304c(3);
    result = func_02010b7c(func_020532b8);
    if (result == 2) {
        return 1;
    }
    func_020530b0(result);
    return 0;
}

/* Borrows event +2: nonzero records the result then invokes 0205342c;
 * zero calls 020532ec and requests state 9 if it returns zero. Evidence:
 * LDRH +2 and the ordered BL paths at 020532bc..020532e4. */
void func_020532b8(Unk52e68Event *event)
{
    if (event->unk_02 != 0) {
        func_020530b0(event->unk_02);
        func_0205342c();
    } else {
        if (!func_020532ec()) {
            func_0205304c(9);
        }
    }
}

/* Requests state 3 and submits event handler 02053324 with argument zero.
 * Evidence: ordered BLs and CMP #2. Rejections record the result and invoke
 * cleanup; the return value is one only for an accepted request. */
s32 func_020532ec(void)
{
    s32 result;
    func_0205304c(3);
    result = func_02010a94(func_02053324, 0);
    if (result == 2) return 1;
    func_020530b0(result);
    func_020533e4();
    return 0;
}

/* Borrows event +2; nonzero records the result, zero requests state 1.
 * Evidence: LDRH +2, CMP #0 and BL paths at 02053328..02053340. */
void func_02053324(Unk52e68Event *event)
{
    if (event->unk_02 != 0) {
        func_020530b0(event->unk_02);
    } else {
        func_0205304c(1);
    }
}

/* Requests state 3 before submitting callback 02053378 to provider 020109dc.
 * Evidence: ordered BLs and callback literal at 0205334c..02053374.
 * Returns 1 for result 2; otherwise records the provider result and returns 0. */
s32 func_02053348(void)
{
    s32 result;
    func_0205304c(3);
    result = func_020109dc(func_02053378);
    if (result == 2) {
        return 1;
    }
    func_020530b0(result);
    return 0;
}

/* Borrows event +2: errors request state 9 before recording the event
 * result; success requests state 1. Evidence: LDRH is repeated after the
 * state-change BL, preserving any callback change to the borrowed event. */
void func_02053378(Unk52e68Event *event)
{
    if (event->unk_02 != 0) {
        func_0205304c(9);
        func_020530b0(event->unk_02);
    } else {
        func_0205304c(1);
    }
}

/* Borrows event +2 to select state 10 for nonzero or state 0 for zero.
 * Evidence: LDRH +2 and the two 0205304c calls at 020533b0..020533cc. */
void func_020533ac(Unk52e68Event *event)
{
    if (event->unk_02 != 0) {
        func_0205304c(10);
    } else {
        func_0205304c(0);
    }
}

/* Reads the connection state word at +0x14; func_0205304c is the writer. */
s32 func_020533d4(void)
{
    return data_0215f500.state;
}

/* In state 5, submits borrowed work 0215fdc0 to 02010bec and records
 * errors. Always attempts 02053348 afterward, selecting state 10 on failure.
 * Evidence: CMP #5 and the common BL path at 0205340c. */
void func_020533e4(void)
{
    s32 result;
    if (data_0215f500.state == 5) {
        result = func_02010bec(data_0215fdc0);
        if (result != 0) func_020530b0(result);
    }
    if (!func_02053348()) func_0205304c(10);
}

/* Dispatches cleanup using state +0x14 and mode +0x38. Evidence: the
 * state comparisons and six-way jump table at 02053470..020534dc.
 * Table 02143a6c says "WH_Finalize, state = %d\n"; the callback receives
 * that state argument. Notifications can change state, requiring a reload. */
void func_0205342c(void)
{
    if (data_0215f500.state == 1) {
        if (data_0215f500.unk_40 != 0) {
            data_0215f500.unk_40(data_02143a50);
        }
        return;
    }
    if (data_0215f500.unk_40 != 0) {
        data_0215f500.unk_40(data_02143a6c, data_0215f500.state);
    }
    if (data_0215f500.state == 2) {
        if (!func_020531fc()) func_020533e4();
        return;
    }
    if (data_0215f500.state != 6 && data_0215f500.state != 5 &&
        data_0215f500.state != 4) {
        func_0205304c(3);
        func_020533e4();
        return;
    }
    func_0205304c(3);
    switch (data_0215f500.unk_38) {
    case 3:
        if (!func_02053230()) func_020533e4();
        break;
    case 5:
        if (func_02010bec(data_0215fdc0) != 0) {
            func_020533e4();
            break;
        }
    /* Fall through after successful provider cleanup. */
    case 1:
        if (!func_02053288()) func_020533e4();
        break;
    case 2:
        if (!func_020530cc()) func_020533e4();
        break;
    case 4:
        if (func_02010bec(data_0215fdc0) != 0) {
            func_020533e4();
            break;
        }
    /* Fall through after successful provider cleanup. */
    case 0:
        if (!func_02053130()) func_020533e4();
        break;
    }
}

/* Runs 02007e94 unless already in state 1, then always requests state 3
 * and submits 020533ac. Evidence: BEQ skips only the 02007e94 call.
 * Rejection requests state 9; success clears connection halfword +6. */
s32 func_02053570(void)
{
    if (data_0215f500.state != 1) func_02007e94();
    func_0205304c(3);
    if (func_02010a14(func_020533ac) != 2) {
        func_0205304c(9);
        return 0;
    }
    data_0215f500.unk_06 = 0;
    return 1;
}
