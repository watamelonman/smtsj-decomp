#include "libs/NitroSDK/sdk_020116a8.h"

extern void func_02008848(void *destination, int value, u32 size);
extern u32 func_02007a58(void);
extern void func_02007a6c(u32 state);
extern void func_02006428(u32 value);
extern void func_02006318(void);
extern s32 func_0201cfd8(void *block);

/** Message pump: waits for the work slot at +0xc0, copies the 36-byte message,
 * restores interrupts for the handlers, then clears the slot and repeats while
 * the global word at data_02155908 stays nonzero. The copy is a struct
 * assignment, which the original implements as two ldm/stm pairs and one word.
 */
void func_020116a8(Unk116a8_Work *work)
{
    Unk116a8_Message message;
    void (*callback2)(Unk116a8_Message *message);
    u32 state;

    for (;;) {
        func_02008848(&message, 0, sizeof(message));
        state = func_02007a58();
        while (work->message == 0)
            func_02006428(0);
        message = *work->message;
        func_02007a6c(state);
        if (message.callback != 0)
            message.result = message.callback(&message);
        state = func_02007a58();
        callback2 = message.callback2;
        data_02155908.field_26 = 0;
        if (callback2 != 0)
            callback2(&message);
        if (data_02155908.flag != 0) {
            work->message = 0;
            func_02007a6c(state);
        } else {
            func_02006318();
            return;
        }
    }
}

/** Byte comparison; the original returns the unsigned byte difference at the
 * first mismatch and reaches the shared zero result through the loop guard.
 */
int func_02011798(const u8 *a, const u8 *b, int n)
{
    int i;

    if (n == 0)
        goto done;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i])
            return a[i] - b[i];
    }
done:
    return 0;
}

/** Returns the float value at data_0213cf94, which the original stores as
 * 0x7fffffff and widens through the MSL float-to-double entry point _f2d.
 */
double func_020117d8(void)
{
    return data_0213cf94;
}

/** Release helper: the original only calls func_0201cfd8 for a non-null block
 * and discards its result, matching the documented MSL arena free path.
 */
void func_020117f0(void *block)
{
    if (block == 0)
        return;
    func_0201cfd8(block);
}

/** Signed magnitude helper; the original negates only negative inputs. */
s32 func_02011804(s32 value)
{
    if (value < 0)
        value = -value;
    return value;
}

/** Sorted-array search: compares the key with the first record, then narrows
 * the inclusive [1, count-1] range by half. The comparator owns the ordering
 * contract; count and size are unsigned because the original uses lsr/mul.
 */
void *func_02011810(const void *key, const void *base, u32 count, u32 size,
                    Unk116a8_Compare compare)
{
    u32 low;
    u32 high;
    u32 middle;
    u32 offset;
    int result;

    if (key == 0 || base == 0 || count == 0 || size == 0 || compare == 0)
        return 0;
    result = compare(key, base);
    if (result == 0)
        return (void *)base;
    if (result < 0)
        return 0;
    low = 1;
    high = count - 1;
    while (low <= high) {
        middle = (low + high) / 2;
        offset = size * middle;
        result = compare(key, (const u8 *)base + offset);
        if (result == 0)
            return (void *)((const u8 *)base + offset);
        if (result < 0)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return 0;
}

/** Locale thunk: data_0213cff4+8 selects the active codeset, whose first entry
 * is the multibyte-to-wide converter. Arguments pass through unchanged.
 */
int func_020118a4(u16 *pwc, const s8 *s, u32 n)
{
    return data_0213cff4.codeset->mbtowc(pwc, s, n);
}

/** Single-byte mbtowc implementation; the paired table entry at data_0213cfb0
 * is the inverse wctomb, which stores one byte and returns one. A null source
 * reports the stateless encoding as zero and a zero length reports an error.
 */
int func_020118c0(u16 *pwc, const s8 *s, u32 n)
{
    if (s == 0)
        return 0;
    if (n == 0)
        return -1;
    if (pwc != 0)
        *pwc = (u8)*s;
    if (*s == 0)
        return 0;
    return 1;
}
