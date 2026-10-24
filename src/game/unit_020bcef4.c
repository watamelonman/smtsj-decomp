/*
 * src/game/unit_020bcef4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0bcef4Work {
    s32 state;
    s32 UnkField0004;
    s32 mode;
} Unk0bcef4Work;


/* Dispatches the record operation; the third argument controls its predicate check. */
int func_020bd30c(u32 arg0, u32 arg1, s32 arg2);
/* Writes the record mode at +8; mode 2 is used by the wrapper below. */
void func_020bd49c(u32 arg0, s32 mode);
u32 Unk0bcef4_Unk_0bd584(int arg0,u32 arg1);
/* Consumes the identifier loaded from the caller-owned first word. */
int Unk0bd5f0_Unk_0bd614(u32 identifier);

void Unk0bcef4_Unk_0bd2fc(u32 arg0,u32 arg1);
void Unk0bcef4_Unk_0bd388(u32 arg0,u32 *arg1);
void Unk0bcef4_Unk_0bd470(u32 *arg0);
void Unk0bcef4_Unk_0bd5c4(u32 arg0);
void Unk0bcef4_Unk_0bd3e0(Unk0bcef4Work *work);
void Unk0bcef4_Unk_0bd480(int *arg0,int arg1);

/* Forwards both arguments with a zero third argument (020bd2fc..020bd308); borrowed addresses must satisfy func_020bd30c. */
void Unk0bcef4_Unk_0bd2fc(u32 arg0,u32 arg1)
{
  func_020bd30c(arg0,arg1,0);
}

/* Forwards the borrowed count word to Unk0bcef4_Unk_0bd584 (load at 020bd38c); arg1 must be readable. */
void Unk0bcef4_Unk_0bd388(u32 arg0,u32 *arg1)
{
  Unk0bcef4_Unk_0bd584(arg0,*arg1);
}

/* Passes the first word to Unk0bd5f0_Unk_0bd614 (load at 020bd474); arg0 must be readable. */
void Unk0bcef4_Unk_0bd470(u32 *arg0)
{
  Unk0bd5f0_Unk_0bd614(*arg0);
}

/* Selects mode 2 through func_020bd49c (020bd5c4..020bd5d0); arg0 identifies its writable record. */
void Unk0bcef4_Unk_0bd5c4(u32 arg0)
{
  func_020bd49c(arg0,2);
}

/* Increments the signed word at +4 and caps it at 1 (020bd3e0..020bd3f8); work is borrowed and writable. */
void Unk0bcef4_Unk_0bd3e0(Unk0bcef4Work *work)
{
  int value;
  value = work->UnkField0004 + 1;
  work->UnkField0004 = value;
  if (1 < value) {
    work->UnkField0004 = 1;
  }
}

/* Advances the signed +4 word modulo 2 (020bd3fc..020bd414).
 * The remainder retains the dividend's sign; work is borrowed and writable.
 */
void func_020bd3fc(Unk0bcef4Work *work)
{
    work->UnkField0004++;
    work->UnkField0004 %= 2;
}

/* Stores the state and sets the next word to 1 for states 1, 4, or 6 (020bd480..020bd498); arg0 has two writable words. */
void Unk0bcef4_Unk_0bd480(int *arg0,int arg1)
{
  *arg0 = arg1;
  if ((arg1 == 1 || arg1 == 4) || arg1 == 6) {
    arg0[1] = 1;
  }
}



/* Initializes seven caller-owned words; the four position words start at zero. */
void Unk0bcef4_Unk_0bcef4(u32 *arg0,u32 arg1,u32 arg2,u32 arg3)
{
  *arg0 = arg1;
  arg0[1] = arg2;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[5] = 0;
  arg0[6] = arg3;
}

/* Seven signed selection words, matching accesses at +8 and +16. */
typedef struct Unk0bcef4Selection {
    s32 span, count, start, previous_start, selected, previous_selected, wrap;
} Unk0bcef4Selection;

extern void Unk0bd5f0_Unk_0bd5f0(Unk0bcef4Work *record);
/* Forwards the selected record relative to start; caller supplies a valid index. */
void Unk0bcef4_Unk_0bd368(Unk0bcef4Work *records, Unk0bcef4Selection *selection)
{
    Unk0bd5f0_Unk_0bd5f0(records + (selection->selected - selection->start));
}


int func_020bd070();
void func_020bd54c(Unk0bcef4Work *work, int enabled);
/* decompiler-derived */
u32 Unk0bcef4_Unk_0bd29c(int arg0,int *arg1)
{
  int value;
  value = 0;
  if (0 < *arg1) {
    do {
      func_020bd070(arg0,1,0);
      func_020bd54c((Unk0bcef4Work *)arg0,0);
      value = value + 1;
      arg0 = arg0 + 0xc;
    } while (value < *arg1);
  }
  return 1;
}

int func_020bd398(Unk0bcef4Work *work);
/* Updates each of count contiguous 12-byte records; returns the last completed
 * index, or UINT_MAX when none completes. Storage is borrowed and writable. */
u32 Unk0bcef4_Unk_0bd584(int record_address, u32 count)
{
    int completed;
    u32 last_completed = (u32)-1;
    u32 index = 0;
    if (count != 0) {
        do {
            completed = func_020bd398((Unk0bcef4Work *)record_address);
            if (completed != 0) {
                last_completed = index;
            }
            index++;
            record_address += sizeof(Unk0bcef4Work);
        } while (index < count);
    }
    return last_completed;
}

/* Borrowed first-word view; the comparisons at 020bd5d8..020bd5e0 identify it as a state. */
typedef struct Unk0bcef4State {
    s32 state;
} Unk0bcef4State;

/* Returns whether the first word is state 0, 1, or 5 (020bd5d4..020bd5ec),
 * which is the evidence for the existing descriptive symbol. t must be readable.
 */
int Unk0bcef4_IsState015(Unk0bcef4State *t)
{
    s32 s = t->state;
    if (s == 1 || s == 0 || s == 5) {
        return 1;
    }
    return 0;
}

/* Selects the counter reset from enabled and mode; mode 2 also sets state 2. */
void func_020bd54c(Unk0bcef4Work *work, int enabled)
{
    if (enabled) {
        if (work->mode != 2) {
            work->UnkField0004 = 0;
            return;
        }
        work->UnkField0004 = 2;
        work->state = 2;
    } else {
        work->UnkField0004 = 1;
    }
}

/* Moves start to selected and caps it to count minus span when a page fits. */
int func_020bd034(Unk0bcef4Selection *selection)
{
    int delta;
    if (selection->count < selection->span) return 1;
    delta = selection->selected - selection->start;
    selection->start += delta;
    if (selection->count - selection->span < selection->start)
        selection->start = selection->count - selection->span;
    return 1;
}

int func_020bd418(Unk0bcef4Work *work);
/* Advances counter to 1 while state is 1, then changes state to 2. Other
 * states complete when the counter reaches 2, which is also its upper cap. */
int func_020bd418(Unk0bcef4Work *work)
{
    if (work->state == 1) {
        work->UnkField0004++;
        if (work->UnkField0004 >= 1) {
            work->UnkField0004 = 1;
            work->state = 2;
        }
    } else {
        work->UnkField0004++;
        if (work->UnkField0004 >= 2) {
            work->UnkField0004 = 2;
            return 1;
        }
    }
    return 0;
}

/* Applies mode 2 to the selected record, requiring state 0/1/5 unless forced.
 * Address arguments refer to borrowed records and a readable selection view. */
int func_020bd30c(u32 records, u32 selection, s32 force)
{
    Unk0bcef4Work *base = (Unk0bcef4Work *)records;
    Unk0bcef4Selection *sel = (Unk0bcef4Selection *)selection;
    if (force || Unk0bcef4_IsState015((Unk0bcef4State *)(base + (sel->selected - sel->start)))) {
        Unk0bcef4_Unk_0bd5c4((u32)(base + (sel->selected - sel->start)));
        return 1;
    }
    return 0;
}

/* Dispatches by the mode word; only mode 2 forwards completion to the caller. */
int func_020bd398(Unk0bcef4Work *work)
{
    int result = 0;
    switch (work->mode) {
    case 0: Unk0bcef4_Unk_0bd3e0(work); break;
    case 1: func_020bd3fc(work); break;
    case 2: result = func_020bd418(work); break;
    }
    return result;
}
