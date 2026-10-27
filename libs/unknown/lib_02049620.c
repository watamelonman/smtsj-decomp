#include "libs/unknown/lib_02049620.h"

/* SDK byte-fill helper and the name-registration helper used by the queue scan. */
extern void func_02008848(void *destination, u32 value, u32 size);
extern void func_0209d44c(const char *name);

/* ARM 02049620: normalizes the queue before the consumer reads it. A record
 * whose +0x10 byte is zero has its +4 word made relative to the first such
 * record (the baseline, kept in `base`); any other record retires itself when
 * its kind is 2, 3, 4, 13 or 17, resets the baseline when the (still) kind is
 * 1, and clears +4. Evidence: the signed switch tree comparing +0 against
 * 13/17/4/3/2, the +0x10 byte load, and the `ldreq`/`sub`/`str` baseline in
 * the zero-byte path. */
void func_02049620(Unk049620List *list)
{
    Unk049620Record *record = list->records;
    u32 base = 0;
    u32 i;

    for (i = 0; i < list->count; i++) {
        if (record->unk_10 == 0) {
            if (base == 0) base = record->unk_04;
            record->unk_04 -= base;
        } else {
            switch (record->kind) {
            case 2:
            case 3:
            case 4:
            case 13:
            case 17:
                record->kind = 0;
                break;
            }
            if (record->kind == 1) base = 0;
            record->unk_04 = 0;
        }
        record++;
    }
}

/* ARM 020496d0: walks the queue from its cursor while the cursor is below the
 * live count. A word-1 record terminates the scan without advancing, and a
 * word-2 record hands its +0x14 name to func_0209d44c. Other kinds are skipped.
 * Evidence: the +0 kind compares, the +0x14 argument and the count reload after
 * the call in the original loop. */
void func_020496d0(Unk049620List *list)
{
    u32 i = list->index;
    if (i >= list->count) return;
    do {
        Unk049620Record *record = &list->records[i];
        if (record->kind == 1) return;
        if (record->kind == 2) func_0209d44c(record->name);
        i++;
    } while (i < list->count);
}

/* ARM 02049724: returns the record at the cursor, or null once the cursor has
 * reached the count. Evidence: the unsigned cursor/count compare. */
Unk049620Record *func_02049724(Unk049620List *list)
{
    u32 i = list->index;
    if (i >= list->count) return 0;
    return &list->records[i];
}

/* ARM 02049744: advances the cursor. At or past the end it clamps the cursor to
 * the count and returns 0; otherwise it returns 1. Evidence: the conditional
 * count store and the 0/1 returns in the original. */
s32 func_02049744(Unk049620List *list)
{
    list->index++;
    if (list->index >= list->count) {
        list->index = list->count;
        return 0;
    }
    return 1;
}

/* ARM 0204976c: clears count 12-byte slots, starting at the newest one. The
 * leading word is zeroed once more after the fill, matching the two stores in
 * the original (memset plus a redundant word store). The countdown loop form is
 * what makes the original's pre-test and bottom-test decrements agree. */
void func_0204976c(Unk049620Slot12 *base, s32 count)
{
    while (--count >= 0) {
        func_02008848(base, 0, 12);
        base->unk_00 = 0;
        base++;
    }
}

/* ARM 020497ac: clears a single 12-byte slot. Evidence: the tail call to
 * func_0204976c with a count of one. */
void func_020497ac(Unk049620Slot12 *base)
{
    func_0204976c(base, 1);
}

/* ARM 020497bc: clears a single 6-byte slot. Evidence: the tail call to the SDK
 * byte fill with value zero and size six. */
void func_020497bc(Unk049620Slot6 *base)
{
    func_02008848(base, 0, 6);
}

/* ARM 020497d0: clears count 6-byte slots, starting at the newest one.
 * Evidence: the +6 cursor step, the countdown loop and the call to
 * func_020497bc. */
void func_020497d0(Unk049620Slot6 *base, s32 count)
{
    while (--count >= 0) {
        func_020497bc(base);
        base++;
    }
}

/* ARM 020497fc: clears a single 6-byte slot. Evidence: the tail call to
 * func_020497d0 with a count of one. */
void func_020497fc(Unk049620Slot6 *base)
{
    func_020497d0(base, 1);
}

/* ARM 0204980c: applies a per-axis update to `state` from `update`. A -5
 * byte stops positive motion (a positive axis is cleared) and -6 stops
 * negative motion (a negative axis is cleared); other nonzero bytes are added
 * to the axis and the result is clamped to [-4, 4]. The packed halfword at +4
 * is then merged field by field, but only for nonzero source fields. Evidence:
 * the ldrsb compares against the constants built from `mvn #3` (-4, -5, -6),
 * the clamp compares against 4 and -4, and the seven guarded field copies. */
void func_0204980c(Unk04980cState *state, Unk04980cState *update)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        s8 v = update->axis[i];
        if (v == -5) {
            if (state->axis[i] > 0) state->axis[i] = 0;
        } else if (v == -6) {
            if (state->axis[i] < 0) state->axis[i] = 0;
        } else if (v != 0) {
            state->axis[i] += v;
            if (state->axis[i] > 4) state->axis[i] = 4;
            if (state->axis[i] < -4) state->axis[i] = -4;
        }
    }
    if (update->b0) state->b0 = update->b0;
    if (update->b1) state->b1 = update->b1;
    if (update->b2) state->b2 = update->b2;
    if (update->b3) state->b3 = update->b3;
    if (update->b4) state->b4 = update->b4;
    if (update->b5) state->b5 = update->b5;
    if (update->b6) state->b6 = update->b6;
}
