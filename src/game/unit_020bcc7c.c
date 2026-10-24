#include "types.h"

/* Seven signed words shared by the bounded selection helpers; callers own storage. */
typedef struct SelectionState {
    s32 span;
    s32 count;
    s32 start;
    s32 previous_start;
    s32 selected;
    s32 previous_selected;
    s32 wrap;
} SelectionState;

extern int func_02053824(int channel, u32 mask);
int func_020bce08(SelectionState *state, int allow_page);

/* Move one position backward, wrapping only when the caller enables it.
 * Evidence: selected/start decrements and count/span bounds in the original. */
int func_020bcc7c(SelectionState *p)
{
    p->selected--;
    if (p->selected < p->start) {
        if (--p->start < 0) {
            if (p->wrap) {
                p->selected = p->count - 1;
                p->start = p->count - p->span;
                if (p->start < 0) p->start = 0;
            } else {
                p->start = 0;
                p->selected = 0;
                return 0;
            }
        }
    }
    return 1;
}

/* Move one position forward within count, with optional wrap to zero. */
int func_020bccec(SelectionState *p)
{
    p->selected++;
    if (p->count <= p->selected) {
        if (p->wrap) {
            p->selected = 0;
            p->start = 0;
        } else {
            p->selected--;
            return 0;
        }
    }
    if (p->start + p->span <= p->selected) p->start++;
    return 1;
}

/* Shift the start backward by span minus one and preserve the prior relative
 * selection using the saved start. Requires a caller-initialized state. */
int Unk0bcc7c_Unk_0bcd58(SelectionState *p)
{
    if (p->start <= 0) return 0;
    p->start = p->start - (p->span - 1);
    if (p->start <= 0) p->start = 0;
    p->selected = p->selected + (p->start - p->previous_start);
    return 1;
}

/* Shift forward by span minus one, clamping start to count minus span. */
int func_020bcda4(SelectionState *p)
{
    if (p->count - p->span <= p->start) return 0;
    p->start = p->start + (p->span - 1);
    if (p->count - p->span <= p->start) p->start = p->count - p->span;
    p->selected = p->selected + (p->start - p->previous_start);
    return 1;
}

/* Enable page movement for the shared update; return value is discarded. */
void Unk0bcc7c_Unk_0bcdf8(SelectionState *state)
{
    func_020bce08(state, 1);
}

/* Save prior positions and dispatch masks 0x40/0x80, then optional 0x20/0x10.
 * Returns -1/1 for a successful backward/forward move, otherwise zero. */
int func_020bce08(SelectionState *p, int allow_page)
{
    p->previous_start = p->start;
    p->previous_selected = p->selected;
    if (func_02053824(0, 0x40)) return -(func_020bcc7c(p) != 0);
    if (func_02053824(0, 0x80)) return func_020bccec(p) != 0;
    if (allow_page && func_02053824(0, 0x20)) return -(Unk0bcc7c_Unk_0bcd58(p) != 0);
    if (allow_page && func_02053824(0, 0x10)) return func_020bcda4(p) != 0;
    return 0;
}
