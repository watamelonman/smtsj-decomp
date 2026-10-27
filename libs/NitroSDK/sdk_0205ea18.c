#include "types.h"

/* Borrowed state; offsets are established by the loads/stores in 0205ecc8-0205ee80. */
typedef struct Unk05ea18State {
    int enabled;
    int busy;
    int phase;
    int result;
    void *records;
    u32 count;
} Unk05ea18State;
extern Unk05ea18State data_0216b428;

/* Triangular interpolation: signed comparisons order endpoints, then abs/mod/div
 * fold the phase. Period must be at least two; intermediate arithmetic must fit. */
int func_0205ea18(int a, int b, int period, int phase, int reverse)
{
    int high = a;
    int half, range, value;
    if (a < b) { high = b; b = a; }
    if (period == 0) return high;
    range = high - b;
    half = period / 2;
    value = (range * (((phase < 0 ? -phase : phase) % period) - half)) / half;
    if (value < 0)
        value = -((range * (((phase < 0 ? -phase : phase) % period) - half)) / half);
    else
        value = (range * (((phase < 0 ? -phase : phase) % period) - half)) / half;
    if (reverse) return high - (range - value);
    return high - value;
}

/* Linear interpolation with endpoint clamping, evidenced by the multiply/divide.
 * Duration and position use the same units; intermediate products must fit int. */
int func_0205eae0(int start, int end, int duration, int position)
{
    if (duration == 0) return end;
    if (position <= 0) return start;
    if (position >= duration) return end;
    end -= start;
    position = (end * position) / duration;
    return position + start;
}

/* Return the borrowed state's +4 word; no ownership or meaning is inferred. */
int func_0205ecc8(void)
{
    return data_0216b428.busy;
}

/* Return the borrowed state's +0 word, as established by the original load. */
int func_0205ecd8(void)
{
    return data_0216b428.enabled;
}

/* Reset the phase before clearing busy; other provider-owned fields are retained. */
void func_0205ece8(void)
{
    data_0216b428.phase = 0;
    data_0216b428.busy = 0;
}

