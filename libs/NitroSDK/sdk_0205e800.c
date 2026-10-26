#include "types.h"

/* Only the byte written by func_0205e800 is known in this global record. */
typedef struct Unk05e800Global {
    u8 pad_0000[0xa5];
    u8 unk_00a5;
} Unk05e800Global;

extern Unk05e800Global data_0216b348;
extern u32 data_0216b3f0[8];
extern void func_0202a0d4(u32 *entry, int value);
extern int func_02053824(int index, u32 mask);
int func_0205e870(int *value, int lower, int upper, int wrap, u32 direction, int step);

/* Store an unsigned value capped at 127; evidence: unsigned compare and byte store at +0xa5. */
void func_0205e800(u32 value)
{
    if (value > 127) value = 127;
    data_0216b348.unk_00a5 = value;
}

/* Apply the same helper argument to eight consecutive global words; their meaning is unknown. */
void func_0205e818(int value)
{
    int i;
    u32 *entry = data_0216b3f0;
    for (i = 0; i < 8; i++, entry++) {
        func_0202a0d4(entry, value);
    }
}

/* Forward a bounded adjustment with unit step; value points to a writable signed integer. */
int func_0205e84c(int *value, int lower, int upper, int wrap, u32 direction)
{
    return func_0205e870(value, lower, upper, wrap, direction, 1);
}

/* Adjust *value using the selected mask pair; clamp or wrap inclusively to [lower, upper].
 * Evidence: calls with masks 0x40/0x80 or 0x20/0x10 and inclusive range arithmetic.
 * Returns 0 without input, 1 on change, or -1 when input leaves the value unchanged.
 * Wrapping requires an ordered range and arithmetic that fits signed int.
 */
int func_0205e870(int *value, int lower, int upper, int wrap, u32 direction, int step)
{
    int current = *value;
    int delta = 0;
    switch (direction) {
    case 0:
        if (func_02053824(0, 64)) delta--;
        else if (func_02053824(0, 128)) delta++;
        break;
    case 2:
        if (func_02053824(0, 64)) delta++;
        else if (func_02053824(0, 128)) delta--;
        break;
    case 1:
        if (func_02053824(0, 32)) delta--;
        else if (func_02053824(0, 16)) delta++;
        break;
    case 3:
        if (func_02053824(0, 32)) delta++;
        else if (func_02053824(0, 16)) delta--;
        break;
    }
    if (delta == 0) return 0;
    current += delta * step;
    if (current < lower) {
        if (wrap) {
            int range = upper - lower + 1;
            if (range != 0) {
                while (current < lower) current += range;
            } else current = lower;
        } else current = lower;
    } else if (current > upper) {
        if (wrap) {
            int range = upper - lower + 1;
            if (range != 0) {
                while (current > upper) current -= range;
            } else current = upper;
        } else current = upper;
    }
    if (current != *value) {
        *value = current;
        return 1;
    }
    return -1;
}
