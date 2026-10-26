/* src/game/unit_02039bb4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk039bb4Work {
    u8 pad_0000[0x18];
    s32 unk_0018;
    s32 unk_001c;
    u8 pad_0020[0x94];
    s32 unk_00b4;
    s32 unk_00b8;
    s32 unk_00bc;
    s32 unk_00c0;
    u8 pad_00c4[0x14];
    s32 unk_00d8;
    s32 unk_00dc;
} Unk039bb4Work;

/* The existing callers pass the work pointer as a 32-bit address. */
void func_0203a334(int workAddress, int selector);
/* Calls func_0203a334 with selector 5, then advances +0x18 and returns 1.
 * Work is borrowed and valid; reload +0x18 after any callee changes. */
u32 Unk039bb4_Unk_03a9ec(Unk039bb4Work *work)
{
  func_0203a334((int)work, 5);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 6, then advances +0x18 and returns 1.
 * Work is borrowed and valid; reload +0x18 after any callee changes. */
u32 Unk039bb4_Unk_03aa10(Unk039bb4Work *work)
{
  func_0203a334((int)work, 6);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 7, then advances +0x18 and returns 1.
 * Work is borrowed and valid; reload +0x18 after any callee changes. */
u32 Unk039bb4_Unk_03aa34(Unk039bb4Work *work)
{
  func_0203a334((int)work, 7);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 8, then advances +0x18 and returns 1.
 * Work is borrowed and valid; reload +0x18 after any callee changes. */
u32 Unk039bb4_Unk_03aa58(Unk039bb4Work *work)
{
  func_0203a334((int)work, 8);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 9, then advances +0x18 and returns 1.
 * Work is borrowed and valid; reload +0x18 after any callee changes. */
u32 Unk039bb4_Unk_03aa7c(Unk039bb4Work *work)
{
  func_0203a334((int)work, 9);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 10, then advances +0x18 and returns 1.
 * Work is borrowed and valid; reload +0x18 after any callee changes. */
u32 Unk039bb4_Unk_03aaa0(Unk039bb4Work *work)
{
  func_0203a334((int)work, 10);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 11, then advances +0x18 and returns 1.
 * Work is borrowed and valid; reload +0x18 after any callee changes. */
u32 Unk039bb4_Unk_03aac4(Unk039bb4Work *work)
{
  func_0203a334((int)work, 11);
  work->unk_0018 += 1;
  return 1;
}


/* Replaces +0x18 using the +0x18 word of a selected 0x20-byte record.
 * Work and both tables are borrowed; the current four-byte entry supplies
 * an unsigned halfword index at +2. Callers must supply valid table indices. */
u32 Unk039bb4_Unk_03a298(Unk039bb4Work *work)
{
  u16 index = *(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2);
  work->unk_0018 = *(s32 *)(work->unk_00b4 + (u32)index * 0x20 + 0x18);
  return 1;
}


void func_0203ab84(void);
/* Tail-forwards to func_0203ab84; the literal at 0x02039d0c identifies the target. */
void Unk039bb4_Thunk_0203ab84(void) { func_0203ab84(); }


/* Advances the signed field at +0x18 and returns 1; work must be valid. */
u32 Unk039bb4_Unk_03a1c8(Unk039bb4Work *work)
{
  work->unk_0018 += 1;
  return 1;
}


/* Advances the signed field at +0x18 and returns 1; work must be valid. */
u32 Unk039bb4_Unk_03a2f8(Unk039bb4Work *work)
{
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 0, then advances +0x18 and returns 1.
 * The original loads +0x18 after the call, preserving any changes made by the callee. */
u32 Unk039bb4_Unk_03a7f8(Unk039bb4Work *work)
{
  func_0203a334((int)work, 0);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 1, then advances +0x18 and returns 1.
 * The original loads +0x18 after the call, preserving any changes made by the callee. */
u32 Unk039bb4_Unk_03a81c(Unk039bb4Work *work)
{
  func_0203a334((int)work, 1);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 2, then advances +0x18 and returns 1.
 * The original loads +0x18 after the call, preserving any changes made by the callee. */
u32 Unk039bb4_Unk_03a840(Unk039bb4Work *work)
{
  func_0203a334((int)work, 2);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 3, then advances +0x18 and returns 1.
 * The original loads +0x18 after the call, preserving any changes made by the callee. */
u32 Unk039bb4_Unk_03a864(Unk039bb4Work *work)
{
  func_0203a334((int)work, 3);
  work->unk_0018 += 1;
  return 1;
}


/* Calls func_0203a334 with selector 4, then advances +0x18 and returns 1.
 * The original loads +0x18 after the call, preserving any changes made by the callee. */
u32 Unk039bb4_Unk_03a9c8(Unk039bb4Work *work)
{
  func_0203a334((int)work, 4);
  work->unk_0018 += 1;
  return 1;
}



/* Copies the +0x18 word of a selected 0x20-byte record from the +0xb8 table.
 * Work and tables are borrowed; the current entry's +2 halfword must be valid. */
u32 Unk039bb4_Unk_03a30c(Unk039bb4Work *work)
{
  u16 index = *(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2);
  work->unk_0018 = *(s32 *)(work->unk_00b8 + (u32)index * 0x20 + 0x18);
  return 1;
}


/* Appends tag 0 at +0x20 and its word at +0x3c, then advances +0x1c.
 * The borrowed work address retains the callers' 32-bit ABI; space must exist. */
void Unk039bb4_Unk_039d10(int workAddress, u32 value)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  *(u8 *)(workAddress + work->unk_001c + 0x20) = 0;
  *(u32 *)(workAddress + work->unk_001c * 4 + 0x3c) = value;
  work->unk_001c += 1;
}


/* Appends tag 1 at +0x20 and its word at +0x3c, then advances +0x1c.
 * The borrowed work address retains the callers' 32-bit ABI; space must exist. */
void Unk039bb4_Unk_039d3c(int workAddress, u32 value)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  *(u8 *)(workAddress + work->unk_001c + 0x20) = 1;
  *(u32 *)(workAddress + work->unk_001c * 4 + 0x3c) = value;
  work->unk_001c += 1;
}


/* Appends tag 5 at +0x20 and its word at +0x3c, then advances +0x1c.
 * The borrowed work address retains the callers' 32-bit ABI; space must exist. */
void Unk039bb4_Unk_039d68(int workAddress, u32 value)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  *(u8 *)(workAddress + work->unk_001c + 0x20) = 5;
  *(u32 *)(workAddress + work->unk_001c * 4 + 0x3c) = value;
  work->unk_001c += 1;
}


/* Appends tag 4 at +0x20 and its word at +0x3c, then advances +0x1c.
 * The borrowed work address retains the callers' 32-bit ABI; space must exist. */
void Unk039bb4_Unk_039d94(int workAddress, u32 value)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  *(u8 *)(workAddress + work->unk_001c + 0x20) = 4;
  *(u32 *)(workAddress + work->unk_001c * 4 + 0x3c) = value;
  work->unk_001c += 1;
}


int func_02039dc0(int workAddress);
/* When +0x1c is nonzero, sets +0x18 to the helper result plus one.
 * Work is borrowed; zero leaves it untouched and returns 0. */
u32 Unk039bb4_Unk_03a26c(Unk039bb4Work *work)
{
  if (work->unk_001c != 0) {
    int value = func_02039dc0((int)work);
    work->unk_0018 = value + 1;
    return 1;
  }
  return 0;
}

/* Appends the current entry's unsigned +2 halfword with tag zero.
 * Work and entry storage are borrowed; reload +0x18 after the helper. */
u32 Unk039bb4_Unk_039f1c(Unk039bb4Work *work)
{
  Unk039bb4_Unk_039d10((int)work,
      *(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2));
  work->unk_0018 += 1;
  return 1;
}

/* Advances to the next entry, appends its full word with tag zero, and advances again.
 * Work and entries are borrowed; both entry indices and append space must be valid. */
u32 Unk039bb4_Unk_039ee8(Unk039bb4Work *work)
{
  int next = work->unk_0018 + 1;
  work->unk_0018 = next;
  Unk039bb4_Unk_039d10((int)work, *(u32 *)(work->unk_00bc + next * 4));
  work->unk_0018 += 1;
  return 1;
}



/* Advances to the next entry and appends its word with tag 1.
 * Borrowed entries and append space must be valid; reload +0x18 after the call. */
u32 Unk039bb4_Unk_039f4c(Unk039bb4Work *work)
{
  int next = work->unk_0018 + 1;
  work->unk_0018 = next;
  Unk039bb4_Unk_039d3c((int)work, *(u32 *)(work->unk_00bc + next * 4));
  work->unk_0018 += 1;
  return 1;
}


/* Appends a word from the +0xd8 table with tag 0, then advances +0x18.
 * Borrowed tables and append space must be valid; entry +2 selects the word. */
u32 Unk039bb4_Unk_039ff8(Unk039bb4Work *work)
{
  Unk039bb4_Unk_039d10((int)work, *(u32 *)(work->unk_00d8 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4));
  work->unk_0018 += 1;
  return 1;
}


/* Appends a word from the +0xdc table with tag 1, then advances +0x18.
 * Borrowed tables and append space must be valid; entry +2 selects the word. */
u32 Unk039bb4_Unk_03a030(Unk039bb4Work *work)
{
  Unk039bb4_Unk_039d3c((int)work, *(u32 *)(work->unk_00dc +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4));
  work->unk_0018 += 1;
  return 1;
}


/* Appends the +0xc0 base plus the entry halfword with tag 5.
 * Work and entries are borrowed; append space must exist. Advances +0x18. */
u32 Unk039bb4_Unk_03a068(Unk039bb4Work *work)
{
  Unk039bb4_Unk_039d68((int)work, work->unk_00c0 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2));
  work->unk_0018 += 1;
  return 1;
}


/* Stores the helper result in the +0xd8 table, then advances +0x18.
 * Borrowed tables must be valid; read the entry index after the helper call. */
u32 Unk039bb4_Unk_03a158(Unk039bb4Work *work)
{
  u32 value = func_02039dc0((int)work);
  *(u32 *)(work->unk_00d8 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4) = value;
  work->unk_0018 += 1;
  return 1;
}

float func_02039e50(int workAddress);
/* Stores the helper result in the +0xdc table, then advances +0x18.
 * Borrowed tables must be valid; read the entry index after the helper call. */
u32 Unk039bb4_Unk_03a190(Unk039bb4Work *work)
{
  float value = func_02039e50((int)work);
  *(float *)(work->unk_00dc +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4) = value;
  work->unk_0018 += 1;
  return 1;
}


/* Appends the current +0x18 with tag 4, then replaces it from a record.
 * Borrowed tables and append space must be valid; select the record after the call. */
u32 Unk039bb4_Unk_03a2c0(Unk039bb4Work *work)
{
  Unk039bb4_Unk_039d94((int)work, work->unk_0018);
  work->unk_0018 = *(u32 *)(work->unk_00b4 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 0x20 + 0x18);
  return 1;
}

extern u8 data_0215e258[];
/* Appends a word from data_0215e258 with tag 0, then advances +0x18.
 * Borrowed entries and append space must be valid; entry +2 selects the word. */
u32 Unk039bb4_Unk_039f80(Unk039bb4Work *work)
{
  Unk039bb4_Unk_039d10((int)work, *(u32 *)(data_0215e258 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4));
  work->unk_0018 += 1;
  return 1;
}

extern u8 data_0215de58[];
/* Appends the selected global float word with tag 1 and advances the entry.
 * Evidence: indexed loads at 0x02039fbc; tables and append space are borrowed. */
u32 Unk039bb4_Unk_039fbc(Unk039bb4Work *work)
{
  Unk039bb4_Unk_039d3c((int)work, *(u32 *)(data_0215de58 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4));
  work->unk_0018 += 1;
  return 1;
}

/* Stores a popped integer into the selected global word and advances the entry.
 * Evidence: 0x0203a0e0; the entry index is read after the pop. */
u32 Unk039bb4_Unk_03a0e0(Unk039bb4Work *work)
{
  s32 value = func_02039dc0((int)work);
  *(s32 *)(data_0215e258 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4) = value;
  work->unk_0018 += 1;
  return 1;
}

/* Stores a popped float into the selected global word and advances the entry.
 * Evidence: 0x0203a11c; the entry index is read after the pop. */
u32 Unk039bb4_Unk_03a11c(Unk039bb4Work *work)
{
  float value = func_02039e50((int)work);
  *(float *)(data_0215de58 +
      (u32)*(u16 *)(work->unk_00bc + work->unk_0018 * 4 + 2) * 4) = value;
  work->unk_0018 += 1;
  return 1;
}

/* Pops a tagged value as a signed integer, converting float tags.
 * Evidence: switch and conversion calls at 0x02039dc0; stack must be nonempty. */
int func_02039dc0(int workAddress)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  int index = --work->unk_001c;
  switch (*(u8 *)(workAddress + index + 0x20)) {
  case 0:
  case 4: return *(s32 *)(workAddress + index * 4 + 0x3c);
  case 1: return (s32)*(float *)(workAddress + index * 4 + 0x3c);
  case 2: return ((s32 *)data_0215e258)[*(s32 *)(workAddress + index * 4 + 0x3c)];
  case 3: return (s32)((float *)data_0215de58)[*(s32 *)(workAddress + index * 4 + 0x3c)];
  default: return 0;
  }
}

/* Pops a tagged value as float; tag 4 yields zero.
 * Evidence: switch and conversion calls at 0x02039e50; stack must be nonempty. */
float func_02039e50(int workAddress)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  int index = --work->unk_001c;
  switch (*(u8 *)(workAddress + index + 0x20)) {
  case 0: return (float)*(s32 *)(workAddress + index * 4 + 0x3c);
  case 4: return 0.0f;
  case 1: return *(float *)(workAddress + index * 4 + 0x3c);
  case 2: return (float)((s32 *)data_0215e258)[*(s32 *)(workAddress + index * 4 + 0x3c)];
  case 3: return ((float *)data_0215de58)[*(s32 *)(workAddress + index * 4 + 0x3c)];
  default: return 0.0f;
  }
}

/* Replaces an integer or float stack value with its zero comparison, then advances.
 * Evidence: 0x0203a944; unsupported tags leave the stack unchanged. */
u32 func_0203a944(Unk039bb4Work *work)
{
  switch (*((u8 *)work + work->unk_001c + 0x1f)) {
  case 0:
  case 2:
    Unk039bb4_Unk_039d10((int)work, func_02039dc0((int)work) == 0);
    break;
  case 1:
  case 3:
    Unk039bb4_Unk_039d10((int)work, 0.0f == func_02039e50((int)work));
    break;
  case 4:
    break;
  }
  work->unk_0018 += 1;
  return 1;
}

/* Duplicates the saved tag/word at +0x3b/+0xa8 into the borrowed stack.
 * Evidence: 0x0203a0a0; caller provides space for one more value. */
/* See DEC-017 for the scoped propagation setting. */
#pragma push
#pragma opt_propagation off
u32 func_0203a0a0(Unk039bb4Work *work)
{
  u32 *slot;
  u32 value;
  *((u8 *)work + work->unk_001c + 0x20) = *((u8 *)work + 0x3b);
  slot = (u32 *)((u8 *)work + work->unk_001c * 4 + 0x3c);
  value = *(u32 *)((u8 *)work + 0xa8);
  *slot = value;
  work->unk_001c++;
  work->unk_0018++;
  return 1;
}

#pragma pop

/* Eight-byte callback records observed at 0x0212b40c; providers own storage. */
typedef struct Unk039bb4Callback {
  int (*callback)(void);
  int consumed;
} Unk039bb4Callback;
/* Borrowed +4 view of each callback record, with the same eight-byte stride. */
typedef struct Unk039bb4Count {
  s32 consumed;
  s32 nextCallback;
} Unk039bb4Count;
extern u32 data_0215de34[];

/* Dispatches the entry's callback and consumes its declared stack arguments.
 * Evidence: 0x0203a1dc; work, entries and callback records must be valid. */
/* See DEC-017 for the scoped propagation setting. */
#pragma push
#pragma opt_propagation off
u32 func_0203a1dc(Unk039bb4Work *work)
{
  Unk039bb4Callback *callbacks = (Unk039bb4Callback *)0x0212b40c;
  int previous = work->unk_0018;
  u16 index = *(u16 *)(work->unk_00bc + previous * 4 + 2);
  int (*callback)(void) = callbacks[index].callback;
  int result;
  data_0215de34[1] = (u32)work;
  result = callback == 0 ? 1 : callback();
  if (result == 0) return 2;
  if (result == 2) return 0;
  Unk039bb4Count *counts = (Unk039bb4Count *)0x0212b410;
  work->unk_001c -= counts[index].consumed;
  if (previous == work->unk_0018) work->unk_0018++;
  return result == 3 ? 2 : 1;
}

#pragma pop

/* See DEC-018 for scoped optimizer settings. */
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Selects a +0xb4 record, copies its terminated name and resets execution state.
 * Evidence: 0x02039bb4; invalid indices return zero without mutation.
 * Work/header/records are borrowed; selected names must terminate within work. */
u32 func_02039bb4(Unk039bb4Work *work, int index)
{
  int offset;
  int i;
  if (index < 0 || index >= *(s32 *)(*(u32 *)((u8 *)work + 0xb0) + 8)) return 0;
  i = 0;
  offset = index * 32;
  *(u8 *)work = *(u8 *)(work->unk_00b4 + index * 32);
  if (*(s8 *)work != 0) {
    do {
      i++;
      *((s8 *)work + i) = *(s8 *)(offset + work->unk_00b4 + i);
    } while (*((s8 *)work + i) != 0);
  }
  work->unk_0018 = *(s32 *)(work->unk_00b4 + index * 32 + 24);
  work->unk_001c = 0;
  i = 0;
  do {
    *((u8 *)work + i + 32) = 0;
    *(u32 *)((u8 *)work + i * 4 + 60) = 0;
    i++;
  } while (i < 28);
  *(s32 *)((u8 *)work + 0xc4) = index;
  *(s32 *)((u8 *)work + 0xcc) = 0;
  *(s32 *)((u8 *)work + 0xd0) = 0;
  return 1;
}


#pragma pop
/* Borrowed file directory entries; offsets/counts are established at 0x02039c60. */
typedef struct Unk039bb4DirectoryEntry {
  s32 kind;
  s32 unk_04;
  s32 count;
  s32 offset;
} Unk039bb4DirectoryEntry;
int func_020152cc(const char *left, const char *right);
/* See DEC-018 for scoped optimizer settings. */
#pragma push
#pragma opt_lifetimes off
/* Finds a named 32-byte record in directory kind zero; returns -1 if absent.
 * Evidence: directory scan and string comparison at 0x02039c60.
 * A null file returns -1; directory offsets, counts and strings must be valid. */
int func_02039c60(const u8 *file, const char *name)
{
  int count;
  const char *records = 0;
  const Unk039bb4DirectoryEntry *entries;
  int i;
  if (file == 0) return -1;
  count = *(s32 *)(file + 16);
  entries = (const Unk039bb4DirectoryEntry *)(file + 32);
  for (i = 0; i < count; i++) {
    if (entries[i].kind == 0) {
      records = (const char *)file + entries[i].offset;
      break;
    }
  }
  if (records == 0) return -1;
  {
    int recordCount = entries[i].count;
    for (count = 0; count < recordCount; count++, records += 32) {
      if (func_020152cc(records, name) == 0) return count;
    }
  }
  return -1;
}


#pragma pop
/* See DEC-018 for scoped optimizer settings. */
#pragma push
#pragma opt_lifetimes off
#pragma opt_common_subs off
/* Negates the top value in place, following global references for tags 2/3.
 * Evidence: switch at 0x0203a888; stack and referenced indices must be valid.
 * The borrowed work address retains the unit's 32-bit address ABI. */
u32 func_0203a888(int workAddress)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  int count = work->unk_001c;
  switch (*(u8 *)(workAddress + count + 31)) {
  case 0:
    *(s32 *)(workAddress + count * 4 + 56) = -*(s32 *)(workAddress + count * 4 + 56);
    break;
  case 1: {
    float value = 0.0f - *(float *)(workAddress + count * 4 + 56);
    *(float *)(workAddress + count * 4 + 56) = value;
    break;
  }
  case 2: {
    int index = *(s32 *)(workAddress + count * 4 + 56);
    ((s32 *)data_0215e258)[index] = -((s32 *)data_0215e258)[index];
    break;
  }
  case 3: {
    int index = *(s32 *)(workAddress + count * 4 + 56);
    ((float *)data_0215de58)[index] = 0.0f - ((float *)data_0215de58)[index];
    break;
  }
  case 4: break;
  }
  work->unk_0018++;
  return 1;
}


#pragma pop

/* See DEC-018 for scoped optimizer settings. */
#pragma push
#pragma opt_propagation off
/* Evaluates the selected binary operator on the top two tagged values.
 * Evidence: 0x0203a334; operand/result scratch lives in data_0215de34.
 * Work is borrowed, contains two values, and uses selectors 0 through 11.
 * Integer arithmetic must remain representable and divisors must be nonzero. */
void func_0203a334(int workAddress, int selector)
{
  Unk039bb4Work *work = (Unk039bb4Work *)workAddress;
  u8 *top = (u8 *)work + work->unk_001c;
  data_0215de34[4] = top[31];
  data_0215de34[3] = top[30];
  if ((data_0215de34[4] == 0 || data_0215de34[4] == 2) &&
      (data_0215de34[3] == 0 || data_0215de34[3] == 2)) {
    ((s32 *)data_0215de34)[2] = func_02039dc0(workAddress);
    ((s32 *)data_0215de34)[0] = func_02039dc0(workAddress);
    switch (selector) {
    case 0:
      ((s32 *)data_0215de34)[8] = ((s32 *)data_0215de34)[2] + ((s32 *)data_0215de34)[0];
      break;
    case 1:
      ((s32 *)data_0215de34)[8] = ((s32 *)data_0215de34)[2] - ((s32 *)data_0215de34)[0];
      break;
    case 2:
      ((s32 *)data_0215de34)[8] = ((s32 *)data_0215de34)[2] * ((s32 *)data_0215de34)[0];
      break;
    case 3:
      ((s32 *)data_0215de34)[8] = ((s32 *)data_0215de34)[2] / ((s32 *)data_0215de34)[0];
      break;
    case 4:
      if (((s32 *)data_0215de34)[2] || ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    case 5:
      if (((s32 *)data_0215de34)[2] && ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    case 6:
      if (((s32 *)data_0215de34)[2] == ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    case 7:
      if (((s32 *)data_0215de34)[2] != ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    case 8:
      if (((s32 *)data_0215de34)[2] < ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    case 9:
      if (((s32 *)data_0215de34)[2] > ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    case 10:
      if (((s32 *)data_0215de34)[2] <= ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    case 11:
      if (((s32 *)data_0215de34)[2] >= ((s32 *)data_0215de34)[0]) {
        ((s32 *)data_0215de34)[8] = 1;
      } else {
        ((s32 *)data_0215de34)[8] = 0;
      }
      break;
    }
    Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
  } else {
    ((float *)data_0215de34)[7] = func_02039e50(workAddress);
    ((float *)data_0215de34)[6] = func_02039e50(workAddress);
    switch (selector) {
    case 0:
      ((float *)data_0215de34)[5] = ((float *)data_0215de34)[7] + ((float *)data_0215de34)[6];
      break;
    case 1:
      ((float *)data_0215de34)[5] = ((float *)data_0215de34)[7] - ((float *)data_0215de34)[6];
      break;
    case 2:
      ((float *)data_0215de34)[5] = ((float *)data_0215de34)[7] * ((float *)data_0215de34)[6];
      break;
    case 3:
      ((float *)data_0215de34)[5] = ((float *)data_0215de34)[7] / ((float *)data_0215de34)[6];
      break;
    case 4:
      if ((0.0 != ((float *)data_0215de34)[7]) || (0.0 != ((float *)data_0215de34)[6])) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    case 5:
      if ((0.0 != ((float *)data_0215de34)[7]) && (0.0 != ((float *)data_0215de34)[6])) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    case 6:
      if (((float *)data_0215de34)[7] == ((float *)data_0215de34)[6]) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    case 7:
      if (((float *)data_0215de34)[7] != ((float *)data_0215de34)[6]) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    case 8:
      if (((float *)data_0215de34)[7] < ((float *)data_0215de34)[6]) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    case 9:
      if (((float *)data_0215de34)[7] > ((float *)data_0215de34)[6]) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    case 10:
      if (((float *)data_0215de34)[7] <= ((float *)data_0215de34)[6]) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    case 11:
      if (((float *)data_0215de34)[7] >= ((float *)data_0215de34)[6]) {
        data_0215de34[8] = 1;
      } else {
        data_0215de34[8] = 0;
      }
      Unk039bb4_Unk_039d10(workAddress, data_0215de34[8]);
      return;
    }
    Unk039bb4_Unk_039d3c(workAddress, ((u32 *)data_0215de34)[5]);
  }
}

#pragma pop
