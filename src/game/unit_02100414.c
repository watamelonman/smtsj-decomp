#include "types.h"

/* Borrowed record view; the comparator reads only the key and score. */
typedef struct Unk100414Record {
    u16 key;
    u8 pad_0002[6];
    s32 score;
} Unk100414Record;

/* Orders records by descending score, then ascending key (loads at +8/+0).
 * Both arguments must point to complete records; neutral name retains unknown use. */
int Unk100414_Unk_100414(const Unk100414Record *a, const Unk100414Record *b)
{
    int value = b->score - a->score;
    if (value == 0) value = (u32)a->key - (u32)b->key;
    return value;
}
