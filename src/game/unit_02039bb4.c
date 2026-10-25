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
int func_0203a334(int workAddress, int selector);
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


int func_02039dc0();
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

int func_02039e50();
/* Stores the helper result in the +0xdc table, then advances +0x18.
 * Borrowed tables must be valid; read the entry index after the helper call. */
u32 Unk039bb4_Unk_03a190(Unk039bb4Work *work)
{
  u32 value = func_02039e50((int)work);
  *(u32 *)(work->unk_00dc +
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
/* decompiler-derived */
u32 Unk039bb4_Unk_039fbc(int arg0)
{
  Unk039bb4_Unk_039d3c(arg0,*(u32 *)
                         (data_0215de58 +
                         (u32)*(u16 *)
                                (((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 4));
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}

/* decompiler-derived */
u32 Unk039bb4_Unk_03a0e0(int arg0)
{
  u32 tmp1;
  tmp1 = func_02039dc0();
  *(u32 *)
   (data_0215e258 +
   (u32)*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 4) = tmp1;
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}

/* decompiler-derived */
u32 Unk039bb4_Unk_03a11c(int arg0)
{
  u32 tmp1;
  tmp1 = func_02039e50();
  *(u32 *)
   (data_0215de58 +
   (u32)*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 4) = tmp1;
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}
