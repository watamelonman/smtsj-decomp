/*
 * ScanVisor.c (file name from an assert string in this TU); presumably the
 * in-dungeon scan visor UI.
 * Small getters/setters and constant queries.
 */
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef unsigned int u32;


/* Scan visor UI object (name from assert). Named fields from matched accessors. */
typedef struct ScanVisor {
    u32 mode;                   /* +0x00: 0..3, selects the draw path */
    u8  pad_0004[0x4];
    u32 unk_0008;               /* +0x08 */
    u8  pad_000c[0x4];
    u32 unk_0010;               /* +0x10 */
    u32 field14;                /* +0x14 */
    u8  pad_0018[0x4];
    u32 rangeA;                 /* +0x1C */
    u32 rangeB;                 /* +0x20 */
    u32 unk_0024;               /* +0x24 */
    u32 unk_0028;               /* +0x28 */
    u8  pad_002c[0x14];
    u32 unk_0040;               /* +0x40 */
    u8  pad_0044[0x18];
    u32 unk_005c;               /* +0x5C */
    u8  pad_0060[0x138];
    u32 unk_0198;               /* +0x198 */
    u8  pad_019c[0x20];
    u32 unk_01bc;               /* +0x1BC */
    u32 slots[16];              /* +0x1C0 */
    u8  pad_0200[0x4c];
    u32 unk_024c;               /* +0x24C */
} ScanVisor;

/* One 52-byte entry of the seven-entry scan list starting at +0x20. The
 * leading word marks occupancy; other users of this layout are FindSlotByKey,
 * AnySlotField14 and AllSlotsF28Is80. */
typedef struct ScanVisorSlot {
    u32 active;
    u32 key;
    u8 pad_08[0x14];
    u32 f28;
    u8 pad_20[0x14];
} ScanVisorSlot;

void Unk0fc584_SetDir(void);

/** No-op draw callback: original 0x020a34a4 is only bx lr; Draw passes sv. */
void ScanVisor_Nop_0a34a4(ScanVisor *sv) { }

/** No-op draw callback: original 0x020a34a8 is only bx lr; Draw passes sv. */
void ScanVisor_Nop_0a34a8(ScanVisor *sv) { }

/** Return the fixed query value; original 0x020a2bb0 moves immediate 20 into r0. */
int ScanVisor_GetConst20(void) { return 20; }

/** Return the fixed query value; original 0x020a4e40 moves immediate 6 into r0. */
int ScanVisor_GetConst6(void) { return 6; }

/** Read word +0x14 from a valid object (ldr at 0x020a45f8); meaning unknown. */
u32 ScanVisor_Unk_0a45f8(ScanVisor *sv) { return sv->field14; }

/** Forward the no-argument call; original 0x020a28e8 branches through the
 * Unk0fc584_SetDir literal relocation, without a local stack frame. */
void ScanVisor_Thunk_020fc6b8(void) { Unk0fc584_SetDir(); }

/** Read the caller-selected word from a valid object, without bounds checks.
 * Original 0x020a42b8 adds index * 4 then loads +0x1c0 (the slot table). */
u32 ScanVisor_GetSlot(ScanVisor *sv, int index) { return sv->slots[index]; }

/** Store the caller's pair in a valid record; original 0x020a43dc writes
 * +0x1c then +0x20. Range units and ordering constraints remain unknown. */
void ScanVisor_SetRange(ScanVisor *sv, u32 a, u32 b) {
    sv->rangeA = a;
    sv->rangeB = b;
}



/* Store a caller-supplied value pair in the slot record at +0x24/+0x28.
 * Original 0x020a43e8: str r1,[r0,#36]; str r2,[r0,#40]; bx lr. Callers
 * pass slot records and either (8, 0) or (0, 0); the value units are unknown. */
void ScanVisor_SetUnkFields24_28(ScanVisor *sv, u32 a, u32 b) {
    sv->unk_0024 = a;
    sv->unk_0028 = b;
}


/* Set the word at +0x1bc to 1. Original 0x020a4904: mov r1,#1;
 * str r1,[r0,#444]; bx lr. Callers pass the list object at base+0x24c. */
void ScanVisor_Unk_0a4904(ScanVisor *sv)
{
  sv->unk_01bc = 1;
}


/* Reset the word at +0x198 to 0. Original 0x020a4988: mov r1,#0;
 * str r1,[r0,#408]; bx lr. Callers pass the list object at base+0x24c. */
void ScanVisor_ClearUnkField198(ScanVisor *sv)
{
  sv->unk_0198 = 0;
}

int ScanVisor_AnySlotField14(u8 *p);
/* Borrow the list pointer and return the callee's 0/1 query result. Original
 * 0x020a49cc tail-branches to 0x020a4600; the caller at 0x020a35bc passes
 * base+0x24c and compares the returned r0 with zero at 0x020a35c4. */
int ScanVisor_Thunk_020a4600(u8 *p) { return ScanVisor_AnySlotField14(p); }

extern u32 data_02176b04[];
/* Return the word at data_02176b04 (bss). Original 0x020a2cfc: ldr r0,
 * literal; ldr r0,[r0]; bx lr. Callers null-check the result before using
 * it as the work-object base. */
u32 ScanVisor_Get_data_02176b04(void)
{
  return *data_02176b04;
}

void ScanVisor_Unk_0a4a44(ScanVisor *list);
/* Forward the list at base+0x24c to ScanVisor_Unk_0a4a44. Original
 * 0x020a3620: ldr ip,[pc,#4]; add r0,r0,#588; bx ip. */
void ScanVisor_Unk_0a3620(ScanVisor *sv)
{
  ScanVisor_Unk_0a4a44((ScanVisor *)((u8 *)sv + 0x24c));
}


/* Clear the two words at +0x10 and +0x14. Original 0x020a465c: mov r1,#0;
 * str r1,[r0,#16]; str r1,[r0,#20]; bx lr. ScanVisor_SetById passes the
 * idle slot record returned by ScanVisor_FindSlotByKey. */
void ScanVisor_Unk_0a465c(ScanVisor *sv)
{
  sv->unk_0010 = 0;
  sv->field14 = 0;
}

void ScanVisor_Unk_0a4950(int arg0,u32 arg1,int arg2);
/* Forward the list object at base+0x24c to ScanVisor_Unk_0a4950 with
 * arguments (1, 1). Original 0x020a4a30: ldr ip,[pc,#8]; mov r1,#1;
 * mov r2,r1; bx ip; .word 0x020a4950. The callee owns all stores. */
void ScanVisor_Unk_0a4a30(u32 obj)
{
  ScanVisor_Unk_0a4950(obj,1,1);
}



/* Mark a slot record as active: store 1 at +0x14 unconditionally and, when
 * `on` is non-zero, store 13 at +0x10 first. Original 0x020a4644: cmp r1,#0;
 * movne r1,#13; strne r1,[r0,#16]; mov r1,#1; str r1,[r0,#20]; bx lr.
 * ScanVisor_SetById supplies a valid slot from ScanVisor_FindSlotByKey and
 * passes its own `on` flag here after the SE-28 call. */
void ScanVisor_Unk_0a4644(ScanVisor *sv, int on)
{
  if (on != 0) {
    sv->unk_0010 = 0xd;
  }
  sv->field14 = 1;
  return;
}

int Unk0c855c_Unk_0c9d8c();
/* Forward the work object's +0x78 sub-object to Unk0c855c_Unk_0c9d8c. The
 * work object comes from ScanVisor_Get_data_02176b04; when it is null the
 * helper returns without calling. Original 0x020a2a1c: load the bss word,
 * test it, add 0x78 and branch-link to the external callee. */
void ScanVisor_Unk_0a2a1c(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0c855c_Unk_0c9d8c(tmp1 + 0x78);
  return;
}


/* Apply the fixed (1, 1) state update to the visor list at work+0x24c through
 * ScanVisor_Unk_0a4a30. The work object comes from
 * ScanVisor_Get_data_02176b04; a null work object makes this a no-op. Original
 * 0x020a2ab0: load the bss word, test it, add 0x24c and branch-link. */
void ScanVisor_Unk_0a2ab0(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  ScanVisor_Unk_0a4a30(tmp1 + 0x24c);
  return;
}


/* Clear the visor list's +0x198 word through ScanVisor_ClearUnkField198. The
 * list lives at work+0x24c and the work object comes from
 * ScanVisor_Get_data_02176b04; a null work object makes this a no-op. Original
 * 0x020a2acc: load the bss word, test it, add 0x24c and branch-link. */
void ScanVisor_Unk_0a2acc(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  ScanVisor_ClearUnkField198((ScanVisor *)(tmp1 + 0x24c));
  return;
}

int Unk0fd268_SetDir();
/* Forward the caller's direction value to Unk0fd268_SetDir only when the work
 * object from ScanVisor_Get_data_02176b04 exists. Original 0x020a27e0 stores
 * the argument in r4 across the getter call, then forwards it; callers pass 0
 * (ScanVisor_Unk_0a2660) or the same value used by the sibling 0x020a2800
 * (ScanVisor_Unk_0a273c). */
void ScanVisor_Unk_0a27e0(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0fd268_SetDir(arg0);
  return;
}

int Unk0fd268_Unk_0fd3f0();
/* Forward the caller's value to Unk0fd268_Unk_0fd3f0 only when the work object
 * from ScanVisor_Get_data_02176b04 exists. Original 0x020a2800 stores the
 * argument in r4 across the getter call, then forwards it; ScanVisor_Unk_0a273c
 * passes the same value it gives the sibling helper at 0x020a27e0. */
void ScanVisor_Unk_0a2800(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0fd268_Unk_0fd3f0(arg0);
  return;
}


int Unk0a7d54_Unk_0a8b44(u32 object);
/* Forward work+0x428 to Unk0a7d54_Unk_0a8b44 when work exists.
 * Original 0x020a2b18 null-checks the getter result before adding 0x28
 * and 0x400; the borrowed sub-object remains owned by the work provider. */
void ScanVisor_Unk_0a2b18(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0a7d54_Unk_0a8b44(tmp1 + 0x428);
  return;
}

int Unk0a7d54_Unk_0a8b70(u32 object);
/* Forward work+0x428 to Unk0a7d54_Unk_0a8b70 when work exists.
 * Original 0x020a2b38 null-checks the getter result before the two adds
 * and call; the sub-object semantics remain unknown. */
void ScanVisor_Unk_0a2b38(void)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0a7d54_Unk_0a8b70(tmp1 + 0x428);
  return;
}

int func_020c9bd8(u32 object, u32 value);
/* Forward the caller value and borrowed work+0x78 to func_020c9bd8.
 * Original 0x020a29a0 preserves r0 across the getter, passes it in r1,
 * and returns without calling if the work pointer is null. */
void ScanVisor_Unk_0a29a0(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  func_020c9bd8(tmp1 + 0x78,arg0);
  return;
}

int Unk0c855c_Unk_0c9c5c(u32 object, u32 value);
/* Forward the caller value and borrowed work+0x78 to
 * Unk0c855c_Unk_0c9c5c. Original 0x020a29c4 preserves the argument in
 * r4 across the getter and skips the call for null work; units unknown. */
void ScanVisor_Unk_0a29c4(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  Unk0c855c_Unk_0c9c5c(tmp1 + 0x78,arg0);
  return;
}

void ScanVisor_Unk_0a4a18(u32 list, u32 id);
/* Clear the slot selected by the caller id on the list at work+0x24c.
 * Original 0x020a2a8c forwards the id in r1 to ScanVisor_Unk_0a4a18,
 * whose lookup and clear establish this behavior. Null work is a no-op. */
void ScanVisor_Unk_0a2a8c(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  ScanVisor_Unk_0a4a18(tmp1 + 0x24c,arg0);
  return;
}

void ScanVisor_SetById(u32 list, u32 id, int on);
/* Activate the caller-selected slot on the list at work+0x24c.
 * Original 0x020a2a38 forwards the id in r1 and fixed 1 in r2 to
 * ScanVisor_SetById; null work returns without calling. */
void ScanVisor_Unk_0a2a38(u32 arg0)
{
  int tmp1;
  tmp1 = ScanVisor_Get_data_02176b04();
  if (tmp1 == 0) {
    return;
  }
  ScanVisor_SetById(tmp1 + 0x24c,arg0,1);
  return;
}


int Unk0fd9f0_SetDir();
/* Forward the caller's value to Unk0fd9f0_SetDir only when the work object
 * exists and its +0x00 mode word is 1. Original 0x020a28f4: load the work
 * word, return on null, load [work], compare against 1, return on mismatch,
 * then move the saved argument to r0 and call. The value units are unknown. */
void ScanVisor_Unk_0a28f4(u32 arg0)
{
  u32 *work;
  work = (u32 *)ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  if (work[0] != 1) {
    return;
  }
  Unk0fd9f0_SetDir(arg0);
  return;
}


/* Activate the caller-selected slot on the list at work+0x24c. Original
 * 0x020a2a60: save both arguments, load the work word, return on null, then
 * add 0x24c and call ScanVisor_SetById(id, on). The caller at
 * unit_0202f2a8 passes (i, mode), matching the SetById contract. */
void ScanVisor_Unk_0a2a60(u32 id,u32 on)
{
  u32 *work;
  work = (u32 *)ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  ScanVisor_SetById((u32)((u8 *)work + 0x24c),id,on);
  return;
}


/* Return the first free 52-byte entry among the seven starting at +0x20, or
 * null when all seven are occupied. Original 0x020a42c4: add 0x20, then loop
 * seven times over [entry] != 0 with +52 per entry and return the pointer.
 * ScanVisor_Unk_0a42f0 uses the result to fill a new entry. */
ScanVisorSlot *ScanVisor_Unk_0a42c4(int base)
{
  ScanVisorSlot *entry;
  int i;
  entry = (ScanVisorSlot *)((u8 *)base + 0x20);
  i = 0;
  do {
    if (entry->active == 0) {
      return entry;
    }
    i = i + 1;
    entry++;
  } while (i < 7);
  return 0;
}


int Unk0a7d54_Unk_0a8b00(u32 object, u32 a, u32 b);
/* Forward two opaque values to borrowed work+0x428 when work exists.
 * Original 0x020a2ae8 preserves both arguments across the getter and calls
 * Unk0a7d54_Unk_0a8b00; a null work pointer returns without calling. */
void ScanVisor_Unk_0a2ae8(u32 arg0,u32 arg1)
{
  int work;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  Unk0a7d54_Unk_0a8b00(work + 0x428,arg0,arg1);
  return;
}

int func_020c9cbc(u32 object, u32 a, u32 b, u32 c);
/* Forward three opaque values to borrowed work+0x78 when work exists.
 * Original 0x020a29e8 preserves r0-r2 across the getter, then supplies them
 * as r1-r3 to func_020c9cbc; null work is a no-op. */
void ScanVisor_Unk_0a29e8(u32 arg0,u32 arg1,u32 arg2)
{
  int work;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  func_020c9cbc(work + 0x78,arg0,arg1,arg2);
  return;
}

int ScanVisor_Unk_0a2b58(void);
int Unk0a7d54_Unk_0a8c40(u32 object);
/* Call the +0x428 helper and clear the list field only when work exists
 * and ScanVisor_Unk_0a2b58 returns nonzero. Original 0x020a2b7c calls
 * Unk0a7d54_Unk_0a8c40 before ClearUnkField198 on work+0x24c. */
void ScanVisor_Unk_0a2b7c(void)
{
  int work;
  int ready;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  ready = ScanVisor_Unk_0a2b58();
  if (ready == 0) {
    return;
  }
  Unk0a7d54_Unk_0a8c40(work + 0x428);
  ScanVisor_ClearUnkField198((ScanVisor *)(work + 0x24c));
  return;
}

int func_020a4370(ScanVisorSlot *entry);
/* Visit occupied entries in the borrowed seven-slot list. Original
 * 0x020a4544 starts at +0x20, advances 52 bytes and calls func_020a4370
 * only for a nonzero leading word; the caller must supply the full list. */
void ScanVisor_Unk_0a4544(u8 *list)
{
  int i;
  ScanVisorSlot *entry = (ScanVisorSlot *)(list + 0x20);
  i = 0;
  do {
    if (entry->active != 0) {
      func_020a4370(entry);
    }
    i = i + 1;
    entry++;
  } while (i < 7);
}


/* Select the work words at +0x2c/+0x34; null work is a no-op.
 * Original 0x020a27a8 stores zero at +0x2c for a nonzero argument, otherwise
 * stores 0x51 at +0x2c and zero at +0x34. Value units remain unknown. */
void ScanVisor_Unk_0a27a8(int arg0)
{
  int work;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  if (arg0 == 0) {
    *(u32 *)(work + 0x2c) = 0x51;
    *(u32 *)(work + 0x34) = 0;
    return;
  }
  *(u32 *)(work + 0x2c) = 0;
  return;
}



/* Null work is a no-op. Original 0x020a284c stores zero at work+0x14
 * for nonzero on; zero on stores -54 at +0x14 and zero at +0x1c.
 * The stores establish field behavior only; units remain unknown. */
void ScanVisor_Unk_0a284c(int on)
{
  int work;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  if (on == 0) {
    *(u32 *)(work + 0x14) = 0xffffffca;
    *(u32 *)(work + 0x1c) = 0;
    return;
  }
  *(u32 *)(work + 0x14) = 0;
  return;
}


/* Null work is a no-op. Original 0x020a28b0 stores zero at work+0x210
 * for nonzero on; zero on stores 50 at +0x210 and zero at +0x214.
 * Field units remain unknown. */
void ScanVisor_Unk_0a28b0(int on)
{
  int work;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  if (on == 0) {
    *(u32 *)(work + 0x210) = 0x32;
    *(u32 *)(work + 0x214) = 0;
    return;
  }
  *(u32 *)(work + 0x210) = 0;
  return;
}

void ScanVisor_SetField34(int on);
void ScanVisor_SetRangeA(int on);
void ScanVisor_SetField214(int on);
void ScanVisor_Unk_0a4864(int list);
/* Apply four zero-argument updates, then refresh the borrowed list at
 * work+0x24c. Original 0x020a2660 preserves work across the four calls
 * in the order below; null work returns before any update. */
void ScanVisor_Unk_0a2660(void)
{
  int work;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  ScanVisor_SetField34(0);
  ScanVisor_Unk_0a27e0(0);
  ScanVisor_SetRangeA(0);
  ScanVisor_SetField214(0);
  ScanVisor_Unk_0a4864(work + 0x24c);
  return;
}

void ScanVisor_Unk_0a2950(int on);
/* Forward one opaque value through five helpers in the order below.
 * Original 0x020a273c preserves it in r4 across the calls and returns
 * without calling when the work getter is null. */
void ScanVisor_Unk_0a273c(u32 value)
{
  int work;
  work = ScanVisor_Get_data_02176b04();
  if (work == 0) {
    return;
  }
  ScanVisor_Unk_0a27a8(value);
  ScanVisor_Unk_0a2800(value);
  ScanVisor_Unk_0a284c(value);
  ScanVisor_Unk_0a28b0(value);
  ScanVisor_Unk_0a2950(value);
  return;
}




int Unk02e000_Unk_02e0cc();
int Unk05ae50_Unk_05af2c();
int func_0205bb68();
int func_0205ddb4();
int Unk0a7d54_Unk_0a8bac();
int func_020c8f08();
int Unk0c855c_Unk_0ca648();
int Unk0fc584_Unk_0fc6a0();
int Unk0fd9f0_Unk_0fda14();
void ScanVisor_Unk_0a4864(int list);
void ScanVisor_Unk_0a4910(int list);
void ScanVisor_Unk_0a48b4(int list);
/* Select the work object's +0x34 value: -3 for on, 3 for off. Original
 * 0x020a277c: getter, null return, then cmp r4,#0 with mvnne #2 / moveq #3
 * before storing +0x34. The callers in unit_0203c474 use the flag pair to
 * switch this field, and the configured symbol keeps the Field34 name. */
void ScanVisor_SetField34(int on)
{
    u8 *work = (u8 *)ScanVisor_Get_data_02176b04();
    if (work == 0) {
        return;
    }
    if (on) {
        FIELD(s32, work, 52) = -3;
    } else {
        FIELD(s32, work, 52) = 3;
    }
}

/* Select the work object's +0x1c value: 2 for on, -2 for off. Original
 * 0x020a2820: getter, null return, then cmp r4,#0 with movne #2 / mvneq #1
 * (the encoded -2) before storing +0x1c. unit_0203c474 calls both arms. */
void ScanVisor_SetRangeA(int on)
{
    u8 *work = (u8 *)ScanVisor_Get_data_02176b04();
    if (work == 0) {
        return;
    }
    if (on) {
        FIELD(s32, work, 28) = 2;
    } else {
        FIELD(s32, work, 28) = -2;
    }
}

/* Select the work object's +0x214 value: -3 for on, 3 for off. Original
 * 0x020a2884: getter, null return, then cmp r4,#0 with mvnne #2 / moveq #3
 * before storing +0x214. unit_0203c474 calls both arms. */
void ScanVisor_SetField214(int on)
{
    u8 *work = (u8 *)ScanVisor_Get_data_02176b04();
    if (work == 0) {
        return;
    }
    if (on) {
        FIELD(s32, work, 532) = -3;
    } else {
        FIELD(s32, work, 532) = 3;
    }
}

/* Toggle the list at work+0x24c: on selects ScanVisor_Unk_0a4904, which sets
 * the list's +0x1bc word to 1; off selects ScanVisor_Unk_0a4864, which writes
 * (8, 0) into the +0x24/+0x28 fields of every occupied entry and then stores 0
 * at +0x1bc. Original 0x020a2920 is 48 bytes: getter, null return, add 0x24c,
 * then either branch-linked helper. Callers in CampStatus and several game
 * units pass 0/1 as an enable flag. */
void ScanVisor_Unk_0a2920(int on)
{
    u8 *work = (u8 *)ScanVisor_Get_data_02176b04();
    if (work == 0) {
        return;
    }
    if (on) {
        ScanVisor_Unk_0a4904((ScanVisor *)(work + 588));
    } else {
        ScanVisor_Unk_0a4864((int)(work + 588));
    }
}

/* Select one of two list helpers on borrowed work+0x24c; null work is a
 * no-op. Original 0x020a2950 calls 0x020a4910 for nonzero on and
 * 0x020a48b4 otherwise. Their higher-level purpose is not established. */
void ScanVisor_Unk_0a2950(int on)
{
    u8 *work = (u8 *)ScanVisor_Get_data_02176b04();
    if (work == 0) {
        return;
    }
    if (on) {
        ScanVisor_Unk_0a4910((int)(work + 588));
    } else {
        ScanVisor_Unk_0a48b4((int)(work + 588));
    }
}

typedef struct ScanVisorEnt20 {
    u32 id;
    u8 pad_04[0x10];
} ScanVisorEnt20;

typedef struct ScanVisorBits {
    u32 word;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b67 : 2;
} ScanVisorBits;

extern u8 data_0214ce2c[];
int Unk0c855c_Unk_0c9bac();
int Unk0a7d54_Unk_0a8c04(u8 *object);
void Unk0c855c_Unk_0c9890(u8 *object, int value);
int func_020c9db4(u8 *object, u32 a, u32 b, u32 c);
int func_020c9eb0(u8 *object, u32 a, u32 b);
void func_020616ec(u32 object, int value);
int func_02057eb8();
void func_020a43f4();
/* Query the work object's +0x78 sub-object through Unk0c855c_Unk_0c9bac and
 * return its integer result. A null work object from
 * ScanVisor_Get_data_02176b04 returns 1 without calling. Original 0x020a2980:
 * moveq r0,#1 then pop, otherwise add 0x78 and branch-link. */
int ScanVisor_Unk_0a2980(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 1;
    }
    return Unk0c855c_Unk_0c9bac(v + 120);
}

/* Return 1 for null work, otherwise return the query on borrowed work+0x428.
 * Original 0x020a2b58 uses moveq r0,#1 on the null path and forwards
 * the non-null sub-object to Unk0a7d54_Unk_0a8c04. */
int ScanVisor_Unk_0a2b58(void)
{
    u8 *v = (u8 *)ScanVisor_Get_data_02176b04();
    if (v == 0) {
        return 1;
    }
    return Unk0a7d54_Unk_0a8c04(v + 40 + 1024);
}

void ScanVisor_ResetBits(ScanVisorBits *p)
{
    p->word = 0;
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b3 = 0;
    p->b4 = 0;
    p->b67 = 0;
}

/* decompiler-derived */
void ScanVisor_Unk_0a2e5c(int arg0)
{
  int tmp1;
  if (((ScanVisor *)arg0)->unk_0008 != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_0008 = 0;
  }
  if (((ScanVisor *)arg0)->unk_0024 != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_0024 = 0;
  }
  if (((ScanVisor *)arg0)->unk_0040 != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_0040 = 0;
  }
  ((ScanVisor *)arg0)->unk_005c = 0;
  if (((ScanVisor *)arg0)->unk_024c != 0) {
    func_0205ddb4();
    ((ScanVisor *)arg0)->unk_024c = 0;
  }
  Unk0a7d54_Unk_0a8bac(arg0 + 0x428);
  Unk0fc584_Unk_0fc6a0();
  Unk0fd268_Unk_0fd3ac();
  Unk0fd9f0_Unk_0fda14();
  func_020c8f08(arg0 + 0x78);
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 10);
  func_0205bb68();
  func_0205bb68();
  func_0205bb68();
  func_0205bb68();
  Unk0c855c_Unk_0ca648(2);
  Unk02e000_Unk_02e0cc();
  Unk05ae50_Unk_05af2c(0xc2);
  func_0205bb68();
  *data_02176b04 = 0;
  return;
}

extern u8 data_0214cddc[];
extern u8 data_0214cdf0[];
extern u8 data_0214ce08[];
int func_0205dcd4();
int func_020c8ce0();
/* Loads Visor/e_appearance + search_parts01/02 (medium). */
void ScanVisor_LoadSearchParts(int arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = func_0205dcd4(data_0214cddc);
  ((ScanVisor *)arg0)->unk_0008 = tmp1;
  tmp1 = func_0205dcd4(data_0214cdf0,arg1);
  ((ScanVisor *)arg0)->unk_0024 = tmp1;
  tmp1 = func_0205dcd4(data_0214ce08,arg1);
  ((ScanVisor *)arg0)->unk_024c = tmp1;
  func_020c8ce0(arg0 + 0x78,arg1);
}

int func_02057eb8();
void ScanVisor_Unk_0a4578();
int func_020a4a70();
/* Refresh the list: call ScanVisor_Unk_0a4578 first, then, only when the
 * list's +0x198 word is non-zero, call func_02057eb8(1) and func_020a4a70 on
 * the same list. Original 0x020a4a44: zero-argument first call, load
 * [list+0x198], pop on zero, else two branch-linked calls. The caller at
 * 0x020a3620 passes the visor's list at base+0x24c; the list's meaning beyond
 * that word is unknown. */
void ScanVisor_Unk_0a4a44(ScanVisor *list)
{
  ScanVisor_Unk_0a4578();
  if (list->unk_0198 == 0) {
    return;
  }
  func_02057eb8(1);
  func_020a4a70((int)list);
}

/* Store the caller value at list+0x190. Original 0x020a4950 stores
 * (1, GetConst6()) at +0x198/+0x194 for nonzero on, otherwise (2, 4096).
 * Caller supplies a valid writable list; state units remain unknown. */
void ScanVisor_Unk_0a4950(int list,u32 value,int on)
{
  u32 count;
  *(u32 *)(list + 400) = value;
  if (on != 0) {
    ((ScanVisor *)list)->unk_0198 = 1;
    count = ScanVisor_GetConst6();
    *(u32 *)(list + 0x194) = count;
    return;
  }
  ((ScanVisor *)list)->unk_0198 = 2;
  *(u32 *)(list + 0x194) = 0x1000;
}

/* decompiler-derived */
void ScanVisor_Unk_0a4864(int arg0)
{
  int tmp1;
  int *v2;
  tmp1 = 0;
  v2 = (int *)(arg0 + 0x20);
  do {
    if (*v2 != 0) {
      ScanVisor_SetUnkFields24_28((ScanVisor *)v2,8,0);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xd;
  } while (tmp1 < 7);
  ((ScanVisor *)arg0)->unk_01bc = 0;
}

/* decompiler-derived */
void ScanVisor_Unk_0a4910(int arg0)
{
  int tmp1;
  int *v2;
  tmp1 = 0;
  v2 = (int *)(arg0 + 0x20);
  do {
    if (*v2 != 0) {
      ScanVisor_SetRange((ScanVisor *)v2, (u32)0, (u32)0);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xd;
  } while (tmp1 < 7);
}

/* decompiler-derived */
void ScanVisor_Unk_0a48b4(int arg0)
{
  int tmp1;
  int *v2;
  tmp1 = 0;
  v2 = (int *)(arg0 + 0x20);
  do {
    if (*v2 != 0) {
      ScanVisor_SetRange((ScanVisor *)v2, (u32)0x50, (u32)0);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 0xd;
  } while (tmp1 < 7);
  *(u32 *)(arg0 + 0x1bc) = 0;
}

int ScanVisor_FindEnt20(u32 id);
/* decompiler-derived */
u32 * ScanVisor_Unk_0a42f0(int arg0,u32 arg1)
{
  u32 *v1;
  int tmp2;
  v1 = (u32 *)ScanVisor_Unk_0a42c4((int)arg0);
  if (v1 != (u32 *)0x0) {
    *v1 = 1;
    *(u8 *)(v1 + 6) = *(u8 *)(arg0 + 0x1c);
    v1[1] = arg1;
    tmp2 = ScanVisor_FindEnt20(arg1);
    v1[2] = *(u32 *)(tmp2 + 0xc);
    v1[3] = *(u32 *)(tmp2 + 0x10);
    v1[0xb] = *(u32 *)(tmp2 + 4);
    v1[0xc] = *(u32 *)(tmp2 + 8);
    ScanVisor_SetRange((ScanVisor *)v1, (u32)0x50, (u32)0);
    ScanVisor_SetUnkFields24_28((ScanVisor *)v1,0,0);
    return v1;
  }
  return (u32 *)0x0;
}

void func_020580ec(int on);
void func_02057e18(int a);
void func_02057ddc(int a);
void func_02057524(int a);
void func_02057e58(int a, int b, int c);
void ScanVisor_Unk_0a3254(ScanVisor *sv);
void func_020a32cc(ScanVisor *sv);
void func_020a34ac(ScanVisor *sv);
void Unk0a7d54_Unk_0a8ad0(void *p);
void func_020572d8(void);

/* Draws the visor layers; modes 1/3 use layer 2, modes 0/2 layer 1. */
void ScanVisor_Draw(ScanVisor *sv)
{
    func_020580ec(0);
    func_02057e18(31);
    func_02057ddc(-1);
    func_02057524(4);
    switch (sv->mode) {
    case 1:
    case 3:
        func_02057e58(2, 48, 10);
        func_02057eb8(2);
        ScanVisor_Unk_0a3254(sv);
        func_02057eb8(2);
        ScanVisor_Nop_0a34a4(sv);
        func_02057eb8(2);
        ScanVisor_Nop_0a34a8(sv);
        func_02057eb8(2);
        func_020a34ac(sv);
        func_02057eb8(-1);
        break;
    case 0:
    case 2:
        func_02057e58(1, 40, 10);
        func_02057eb8(1);
        func_020a32cc(sv);
        func_02057eb8(1);
        ScanVisor_Unk_0a3254(sv);
        func_02057eb8(1);
        ScanVisor_Nop_0a34a4(sv);
        func_02057eb8(1);
        ScanVisor_Nop_0a34a8(sv);
        func_02057eb8(1);
        func_020a34ac(sv);
        func_02057eb8(1);
        Unk0a7d54_Unk_0a8ad0((u8 *)sv + 0x428);
        func_02057eb8(1);
        ScanVisor_Unk_0a3620(sv);
        func_02057eb8(-1);
        break;
    }
    func_020572d8();
    func_020580ec(1);
}

ScanVisor *ScanVisor_FindSlotByKey(u32 list, u32 id);
void Unk0a0ce4_Unk_0a0da4(int se);

/* For a valid borrowed visor, call Unk0c855c_Unk_0c9890 on +0x78 with
 * value 12 only while signed word +0x210 is below 50. Original 0x020a3254
 * uses ldr/cmp #50/popge; neither the threshold units nor meaning is known. */
void ScanVisor_Unk_0a3254(ScanVisor *p)
{
    if (FIELD(s32, p, 528) >= 50) {
        return;
    }
    Unk0c855c_Unk_0c9890((u8 *)p + 120, 12);
}

int GameState_Exists();
void *Unk02e000_GetWorkArea();

s8 ScanVisor_Unk_0a3274(void)
{
    u8 *w;
    s16 a;
    s16 b;
    s32 r;
    if (GameState_Exists() == 0) {
        return 0;
    }
    w = (u8 *)Unk02e000_GetWorkArea();
    b = *(s16 *)(w + 2804);
    a = (s16)(*(s16 *)(w + 2802) * 100);
    if (b <= 0) {
        return 0;
    }
    r = a / b;
    if (r >= 100) {
        r = 99;
    }
    return r;
}

/* Submit the work+0x78 provider result with three opaque caller values.
 * Original 0x020a3760 reloads data_02176b04 after func_020c9db4 before
 * calling func_020616ec; valid work is required, with no null guard. */
void ScanVisor_Unk_0a3760(u32 a, u32 b, u32 c)
{
    func_020616ec(*data_02176b04, func_020c9db4((u8 *)*data_02176b04 + 120, a, b, c));
}

/* Submit the +0x78 provider result to func_020616ec on the current work.
 * Original 0x020a379c reloads data_02176b04 after func_020c9eb0, so that
 * provider may change the work pointer. Both providers require valid work. */
void ScanVisor_Unk_0a379c(u32 a, u32 b)
{
    func_020616ec(*data_02176b04, func_020c9eb0((u8 *)*data_02176b04 + 120, a, b));
}

/* Find the first matching ID in the six borrowed 20-byte records, or zero.
 * Original 0x020a4284 loads data_0214ce2c and compares each leading word;
 * the configured FindEnt20 name describes this observed table traversal. */
int ScanVisor_FindEnt20(u32 id)
{
    u32 j;
    ScanVisorEnt20 *e = (ScanVisorEnt20 *)data_0214ce2c;
    for (j = 0; j < 6; j++, e++) {
        if (id == e->id) {
            return (int)e;
        }
    }
    return 0;
}

void ScanVisor_Unk_0a4578(u32 *p)
{
    int j;
    ScanVisorSlot *e = (ScanVisorSlot *)((u8 *)p + 32);
    for (j = 0; j < 7; j++, e++) {
        if (e->active != 0) {
            func_02057eb8(2);
            func_020a43f4(e, p[0]);
        }
    }
}

/* Borrow the first occupied slot whose key matches, or return null.
 * Original 0x020a45c0 scans seven 52-byte records at list+0x20, testing
 * +0x00 occupancy and +0x04 key; this supports the configured name. */
ScanVisor *ScanVisor_FindSlotByKey(u32 p, u32 k)
{
    int j;
    ScanVisorSlot *e = (ScanVisorSlot *)((u8 *)p + 32);
    for (j = 0; j < 7; j++, e++) {
        if (e->active != 0 && e->key == k) {
            return (ScanVisor *)e;
        }
    }
    return 0;
}

int ScanVisor_AnySlotField14(u8 *p)
{
    int j;
    ScanVisorSlot *e = (ScanVisorSlot *)((u8 *)p + 32);
    for (j = 0; j < 7; j++, e++) {
        if (e->active != 0 && ScanVisor_Unk_0a45f8((ScanVisor *)e) != 0) {
            return 1;
        }
    }
    return 0;
}

/* Return 1 when every occupied slot has word +0x1c equal to 80.
 * Original 0x020a4994 visits seven 52-byte entries at list+0x20; empty
 * slots are ignored, so an empty list also returns 1. F28 denotes decimal 28. */
int ScanVisor_AllSlotsF28Is80(u8 *p)
{
    int j;
    ScanVisorSlot *e = (ScanVisorSlot *)((u8 *)p + 32);
    for (j = 0; j < 7; j++, e++) {
        if (e->active != 0 && e->f28 != 80) {
            return 0;
        }
    }
    return 1;
}

/* Looks up the visor entry; if idle, (optionally with SE 28) applies `on`. */
void ScanVisor_SetById(u32 list, u32 id, int on)
{
    ScanVisor *sv = ScanVisor_FindSlotByKey(list, id);
    if (sv == 0) {
        return;
    }
    if (ScanVisor_Unk_0a45f8(sv) != 0) {
        return;
    }
    if (on != 0) {
        Unk0a0ce4_Unk_0a0da4(28);
    }
    ScanVisor_Unk_0a4644(sv, on);
}

/* Look up the slot whose key is `id` inside the list at work+0x24c, then clear
 * its +0x10/+0x14 words through ScanVisor_Unk_0a465c (deactivate it). A missing
 * slot leaves the list untouched. Original 0x020a4a18: branch-link to
 * ScanVisor_FindSlotByKey, test r0, then branch-link to 0x020a465c. The caller
 * at 0x020a2a8c passes work+0x24c and its own id argument. */
void ScanVisor_Unk_0a4a18(u32 list, u32 id)
{
    ScanVisor *sv = ScanVisor_FindSlotByKey(list, id);
    if (sv == 0) {
        return;
    }
    ScanVisor_Unk_0a465c(sv);
}
