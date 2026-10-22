#include "types.h"


/* Four-word records are evidenced by the indexed loads in this unit. */
typedef struct Unk044394Entry {
    u32 unk_00;
    u32 handle;
    u32 unk_08;
    u32 unk_0c;
} Unk044394Entry;

extern Unk044394Entry data_0214283c[];
u32 func_02051610(u32 id);
u32 func_02052fe0(void);
int func_0205f460(u32 id);
int func_0205f4b0(u32 id, u32 handle, int value);
void func_02053000(u32 handle);
int func_02050088(int mode, int lower, int upper);

/* Initializes the record handle, trying the offset-12 path before the fallback. */
void Unk044394_Unk_044394(Unk044394Entry *arg0)
{
  int value1;
  u32 value2;
  if ((arg0->unk_0c != 0) && (value1 = func_0205f460(arg0->unk_00), value1 != 0)) {
    value2 = func_02052fe0();
    arg0->handle = value2;
    value1 = func_0205f4b0(arg0->unk_00,arg0->handle,value1);
    if (value1 != 0) {
      return;
    }
  }
  value2 = func_02051610(arg0->unk_00);
  arg0->handle = value2;
}


/* Tests handle presence; evidence: the indexed record word at offset 4.
 * Out-of-range indices return zero; the table has 49 entries. */
int Unk044394_HasEntry(int i)
{
    int ok;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    return ((Unk044394Entry *)((u8 *)data_0214283c + i * 16))->handle != 0;
}

/* Initializes an absent handle unless offset 8 blocks it; invalid indices fail. */
int Unk044394_Unk_044428(int i)
{
    int ok;
    Unk044394Entry *e;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    e = &data_0214283c[i];
    if (e->handle != 0) {
        return 1;
    }
    if (e->unk_08 != 0) {
        return 0;
    }
    Unk044394_Unk_044394(e);
    return 1;
}

/* Visits all 49 records in shuffled order, initializing flagged absent handles.
 * The random helper receives mode 1 and an inclusive index range. */
int func_02044488(void)
{
    int j;
    u8 *cursor;
    int i;
    u8 order[49];
    int other;
    u8 saved;
    u8 chosen;
    for (i = 0; i < 49; i++) {
        order[i] = i;
    }
    for (cursor = order, j = 0; j < 24; j++, cursor++) {
        other = func_02050088(1, j + 1, 48);
        chosen = order[other];
        saved = *cursor;
        *cursor = chosen;
        order[other] = saved;
    }
    for (i = 0; i < 49; i++) {
        Unk044394Entry *e = &data_0214283c[order[i]];
        if (e->handle == 0 && e->unk_08 != 0) {
            Unk044394_Unk_044394(e);
        }
    }
    return 1;
}

/* Releases and clears a present handle unless offset 8 blocks it. */
int Unk044394_Unk_044534(int i)
{
    int ok;
    Unk044394Entry *e;
    if (i >= 0 && i < 49) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    e = &data_0214283c[i];
    if (e->handle == 0) {
        return 1;
    }
    if (e->unk_08 != 0) {
        return 0;
    }
    func_02053000(e->handle);
    e->handle = 0;
    return 1;
}
