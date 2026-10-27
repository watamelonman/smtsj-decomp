#include "types.h"

/* Caller-owned registration record; only instruction-observed words are named. */
typedef struct Unk05ea18Record {
    u32 value0;
    u32 value4;
    u32 unused8;
    u32 value12;
    u32 value16;
    u32 selected;
} Unk05ea18Record;

/* Borrowed state; offsets are established by the loads/stores in 0205ecc8-0205ee80. */
typedef struct Unk05ea18State {
    int enabled;
    int busy;
    int phase;
    int result;
    Unk05ea18Record *records;
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


/* Existing provider operations; all record and handle storage remains borrowed. */
extern int func_02050df4(void);
extern int func_0200fa98(const void *resource);
extern void func_02050e80(void);
extern int func_02050ee8(const void *resource, int value, u32 count);
extern void *func_02050864(u32 index);
extern void func_02050770(u32 index, void *slot, u32 value0, u32 value4,
                          u32 value12, u32 value16);
extern int func_02051040(void);
extern int func_020510f4(u32 index);

/* Registers borrowed 24-byte records after provider/resource checks; evidence:
 * the original loads +0/+4/+12/+16 and advances by 24. Returns zero on failure.
 * Records must contain count entries and outlive subsequent provider updates. */
int func_0205ebd8(const void *resource, int value, Unk05ea18Record *records, u32 count)
{
    u32 i;
    data_0216b428.result = 0;
    data_0216b428.enabled = 0;
    data_0216b428.records = records;
    data_0216b428.count = count;
    func_0205ece8();
    if (!func_02050df4()) return 0;
    if (!func_0200fa98(resource)) {
        func_02050e80();
        return 0;
    }
    func_02050e80();
    data_0216b428.enabled = 1;
    if (!func_02050ee8(resource, value, count)) return 0;
    for (i = 0; i < count; i++, records++) {
        void *slot = func_02050864(i);
        func_02050770(i, slot, records->value0, records->value4,
                     records->value12, records->value16);
    }
    func_0205ece8();
    return 1;
}

/* Runs selected records through the provider, then shuts it down next call.
 * Evidence: phase +8, busy +4, result +12, and record selection word +20.
 * Returns zero after processing, one when unavailable or shutdown is complete. */
int func_0205ed00(void)
{
    u32 i;
    if (data_0216b428.phase == 0) {
        data_0216b428.result = 0;
        if (!func_0205ecd8()) return 1;
        if (!func_02050df4()) return 1;
        data_0216b428.busy = 1;
        data_0216b428.result = func_02051040();
        if (data_0216b428.result != 3 && data_0216b428.result != 4) {
            for (i = 0; i < data_0216b428.count; i++) {
                if (data_0216b428.records[i].selected) {
                    data_0216b428.result = func_020510f4(i);
                    if (data_0216b428.result != 1) break;
                }
            }
        }
        data_0216b428.phase++;
    } else {
        func_02050e80();
        data_0216b428.busy = 0;
        return 1;
    }
    return 0;
}
