/*
 * src/game/unit_020bb6e8.c: script handlers that read arguments with func_0203ac00
 * and report their result through Unk03aae8_Unk_03acf4. Field meanings are not
 * established; names and layout follow the original ARM accesses.
 */
#include "types.h"

/* Script-argument accessor: argument index in, value out. */
s32 func_0203ac00(s32 index);
/* Borrowed record selected by the id stored in the shared work object. */
u8 *Unk0bac80_Thunk_02044ec4(u32 id);
/* Writes the handler result consumed by the script interpreter. */
void Unk03aae8_Unk_03acf4(s32 value);

/* Record flags at +0x282; bit 1 is read and written by the handlers below.
 * Evidence: ldrb/strb at [record + 642] with a single-bit mask. */
typedef struct Unk0bb6e8Flags {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Unk0bb6e8Flags;

/* Partial view of the shared work object returned by Unk0bac80_Unk_0badc0.
 * Only the flag word at +0x44 is used here; bit 5 starts an 8-bit field that
 * Unk0bb6e8_Unk_0bb880 extracts (evidence: lsl #19 / lsr #24). */
typedef struct Unk0bb6e8Work {
    u8 pad_0000[0x44];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3_4 : 2;
    u32 field_5 : 8;
    u32 rest : 19;
} Unk0bb6e8Work;

Unk0bb6e8Work *Unk0bac80_Unk_0badc0(void);

int Unk02e000_GetRecordFlag0(u32 id);
int Unk02e000_SetRecordFlag1f(u32 id, int v);
/* 020e6254's result is tested by callers even though its own TU declares it
 * void; the original ROM here tests r0 after the call. */
int Unk0e5fb8_Unk_0e6254(s32 arg0);
void Unk0e5fb8_Unk_0e628c(s32 arg0);

/* Report bit 1 of the record flag byte at +0x282; return status 1. */
u32 Unk0bb6e8_GetFlag282b1(void)
{
    if (((Unk0bb6e8Flags *)(Unk0bac80_Thunk_02044ec4(func_0203ac00(0)) + 642))->b1) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Store argument 1 (non-zero) into bit 1 of the +0x282 record flag byte. */
u32 Unk0bb6e8_SetFlag282b1(void)
{
    int a = func_0203ac00(0);
    int on = func_0203ac00(1) != 0;
    ((Unk0bb6e8Flags *)(Unk0bac80_Thunk_02044ec4(a) + 642))->b1 = on;
    return 1;
}

/* Report record flag 0 for the 16-bit id in argument 0; return status 1. */
u32 Unk0bb6e8_Unk_0bb770(void)
{
    if (Unk02e000_GetRecordFlag0((u16)func_0203ac00(0)) != 0) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Set record flag 1f for the 16-bit id in argument 0 to argument 1 != 0. */
u32 Unk0bb6e8_Unk_0bb7ac(void)
{
    int on = func_0203ac00(1) != 0;
    Unk02e000_SetRecordFlag1f((u16)func_0203ac00(0), on);
    return 1;
}

/* Script handler: clear the five low flag bits at +0x44 of the shared work
 * object, then set them from script arguments 0, 1 and 2. Argument 0 == 1
 * selects value 1 for the 2-bit field; argument 1 == 2 and == 3 set bits 1
 * and 2; argument 2 == 5 sets bit 0. Returns status 1. */
u32 func_020bb7e4(void)
{
    Unk0bb6e8Work *work = Unk0bac80_Unk_0badc0();
    s32 a0;
    s32 a1;
    s32 a2;

    work->b0 = 0;
    work->b1 = 0;
    work->b2 = 0;
    work->b3_4 = 0;

    a0 = func_0203ac00(0);
    a1 = func_0203ac00(1);
    a2 = func_0203ac00(2);

    if (a0 == 1) {
        work->b3_4 = 1;
    }
    if (a1 == 2) {
        work->b1 = 1;
    }
    if (a1 == 3) {
        work->b2 = 1;
    }
    if (a2 == 5) {
        work->b0 = 1;
    }
    return 1;
}

/* Report the 8-bit field at bits 5..12 of the +0x44 work flag word. */
u32 Unk0bb6e8_Unk_0bb880(void)
{
    Unk0bb6e8Work *work = Unk0bac80_Unk_0badc0();
    Unk03aae8_Unk_03acf4(work->field_5);
    return 1;
}

/* For argument 0 below 15, invoke 020e628c with that argument; return status 1. */
u32 Unk0bb6e8_Unk_0bb8a0(void)
{
    s32 value = func_0203ac00(0);
    if (value < 0xf) {
        Unk0e5fb8_Unk_0e628c(value);
    }
    return 1;
}

/* Report whether 020e6254 succeeds for argument 0 when it is below 15; an
 * out-of-range argument reports 0. Returns status 1. */
u32 Unk0bb6e8_Unk_0bb8c0(void)
{
    s32 a = func_0203ac00(0);
    if (a < 15) {
        if (Unk0e5fb8_Unk_0e6254(a) != 0) {
            Unk03aae8_Unk_03acf4(1);
        } else {
            Unk03aae8_Unk_03acf4(0);
        }
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
