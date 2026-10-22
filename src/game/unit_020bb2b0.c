/* Field meanings remain unknown; layouts follow the original ARM loads. */
#include "types.h"


/* Only the +0x40 field of the caller-owned work is established here. */
typedef struct Unk0bb2b0Work {
    u8 pad_00[0x40];
    u32 unk_40;
} Unk0bb2b0Work;

/* The original reads a halfword at +0x1d8 of this borrowed record. */
typedef struct Unk0bb2b0Record {
    u8 pad_000[0x1d8];
    u16 unk_1d8;
} Unk0bb2b0Record;

/* Partial lookup record; byte and halfword widths follow ldrb/ldrh. */
typedef struct Unk0bb2b0Lookup {
    u8 pad_00[2];
    u8 unk_02;
    u8 pad_03[9];
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
} Unk0bb2b0Lookup;

/* Borrowed lookup; only offsets evidenced by this unit are represented. */
typedef struct Unk0bb2b0ByteLookup {
    u8 pad_00[4];
    u8 unk_04;
    u8 unk_05;
    u8 pad_06[0x1e];
    u32 unk_24;
} Unk0bb2b0ByteLookup;

Unk0bb2b0ByteLookup *func_020a1428(u32 id);
Unk0bb2b0Lookup *func_020a1740(u32 id);
Unk0bb2b0Record *Unk0bac80_Thunk_02044ec4(u32 id);
Unk0bb2b0Work *Unk0bac80_Unk_0badc0(void);
u32 func_0203ac00(u32 index);
u32 Unk02e000_GetRecordUnk1c(u32 id);
void Unk03aae8_Unk_03acf4(u32 value);
/* The original caller passes a full word sum; the callee stores its low halfword. See DEC-001. */
int Unk02e000_SetRecordUnk1c(u32 id, u32 value);
/* Forward the work-selected record's +0x1d8 halfword; return status 1. */
u32 Unk0bb2b0_Unk_0bb2b0(void)
{
    Unk03aae8_Unk_03acf4(Unk0bac80_Thunk_02044ec4(Unk0bac80_Unk_0badc0()->unk_40)->unk_1d8);
    return 1;
}

/* Preserve the id and borrowed record pointer when forwarding to 0x020a1428. */
Unk0bb2b0ByteLookup *Unk0bb2b0_Thunk_020a1428(u32 id) { return func_020a1428(id); }

/* Preserve the id and borrowed record pointer when forwarding to 0x020a1740. */
Unk0bb2b0Lookup *Unk0bb2b0_Thunk_020a1740(u32 id) { return func_020a1740(id); }

/* Truncate argument 0 to a 16-bit id; forward lookup +0x02; return 1. */
u32 Unk0bb2b0_Unk_0bb2ec(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0))->unk_02);
    return 1;
}

/* Truncate argument 0 to a 16-bit id; forward lookup +0x0c; return 1. */
u32 Unk0bb2b0_Unk_0bb314(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0))->unk_0c);
    return 1;
}

/* Truncate argument 0 to a 16-bit id; forward lookup +0x14; return 1. */
u32 Unk0bb2b0_Unk_0bb33c(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0))->unk_14);
    return 1;
}

/* Truncate argument 0 to a 16-bit id; forward lookup +0x0e; return 1. */
u32 Unk0bb2b0_Unk_0bb364(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0))->unk_0e);
    return 1;
}

/* Forward lookup +0x10 for the truncated argument-0 id; return 1. */
u32 Unk0bb2b0_Unk_0bb38c(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0))->unk_10);
    return 1;
}

/* Forward lookup +0x12 for the truncated argument-0 id; return 1. */
u32 Unk0bb2b0_Unk_0bb3b4(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0))->unk_12);
    return 1;
}

/* Forward lookup +0x04 for the truncated argument-0 id; return 1. */
u32 Unk0bb2b0_Unk_0bb3dc(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1428((u16)func_0203ac00(0))->unk_04);
    return 1;
}

/* Forward lookup +0x05 for the truncated argument-0 id; return 1. */
u32 Unk0bb2b0_Unk_0bb404(void)
{
    Unk03aae8_Unk_03acf4(Unk0bb2b0_Thunk_020a1428((u16)func_0203ac00(0))->unk_05);
    return 1;
}

/* Forward GetRecordUnk1c for the 16-bit argument-0 id; return status 1. */
u32 Unk0bb2b0_Unk_0bb42c(void)
{
  u16 value;
  value = func_0203ac00(0);
  Unk03aae8_Unk_03acf4(Unk02e000_GetRecordUnk1c(value));
  return 1;
}


/* Add argument 1 to the selected record value; the setter receives a word sum. */
u32 Unk0bb2b0_Unk_0bb450(void)
{
    u16 id;
    u32 delta;
    u32 value;
    id = func_0203ac00(0);
    delta = func_0203ac00(1);
    value = Unk02e000_GetRecordUnk1c(id);
    Unk02e000_SetRecordUnk1c(id, delta + value);
    return 1;
}

/* Forward bits 21..27 of lookup +0x24 for the 16-bit argument-0 id; return 1. */
u32 Unk0bb2b0_Unk_0bb490(void)
{
    u32 value = Unk0bb2b0_Thunk_020a1428((u16)func_0203ac00(0))->unk_24;
    Unk03aae8_Unk_03acf4((value << 4) >> 25);
    return 1;
}
