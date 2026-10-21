#ifndef GAME_UNIT_02126178_H
#define GAME_UNIT_02126178_H

#include "types.h"

/* Work object shared by both functions of unit_02126178 (layout from field use only). */
typedef struct Unk126178Work {
    s32 count;
    u32 unk_04;
    u8 pad_0008[4];
    u32 unk_0c;
    void *unk_10;
    u32 unk_14;
    u32 unk_18;
} Unk126178Work;

/* Passes the entry selected by w->unk_10 (plus w->unk_14/unk_18) to func_0205bf18. */
void func_02126178(Unk126178Work *w);
/* Submits each of w->count items offset by (x, y) with a and b applied. */
void func_021261d8(Unk126178Work *w, s32 x, s32 y, u32 a, u32 b);

/* Descriptive names for callers. The definitions keep the symbols.txt names because the
 * linked symbols must stay func_<addr> and the match gate looks definitions up by name. */
#define Unk126178_SubmitSelectedEntry func_02126178
#define Unk126178_DrawItems func_021261d8

#endif /* GAME_UNIT_02126178_H */
