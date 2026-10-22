/* src/game/unit_0203de08.c: state handlers for the unit at 0x0203DE08.
 * All callees return int; the +0x35C selector is an unsigned halfword inside the
 * work area shared with unit_0202f2a8 (see FIELD(u16, ..., 92) there). */
#include "types.h"

#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0203ac00();
int Unk02e000_GetWorkArea();
int Unk02e000_TestFlag();
int Unk02f2a8_Unk_035b08();
int func_0204b6f4();
int func_0204b74c();
int func_0204c804();
int func_0204c8f4();
int Unk02dcfc_SetCode24();
int Unk03aae8_Unk_03acf4();

/* Read five s16 values from func_0203ac00(0..4), then hand the last four to
 * func_0204c804. The fourth argument is the +0x35C work-area selector when either
 * of the first two values is negative, otherwise the selector computed by
 * Unk02f2a8_Unk_035b08. Sets substate 24 and returns 3.
 * Evidence: original instructions at 0x0203DE08. */
u32 func_0203de08(void)
{
    s16 v1;
    s16 v2;
    s16 v3;
    s16 v4;
    s16 v5;
    u16 selector;

    Unk02e000_GetWorkArea();
    v1 = func_0203ac00(0);
    v2 = func_0203ac00(1);
    v3 = func_0203ac00(2);
    v4 = func_0203ac00(3);
    v5 = func_0203ac00(4);
    selector = (v1 < 0 || v2 < 0)
                   ? FIELD(u16, Unk02e000_GetWorkArea(), 0x35c)
                   : Unk02f2a8_Unk_035b08(v1, v2);
    func_0204c804(v5, v3 & 0xff, v4 & 0xff, selector);
    Unk02dcfc_SetCode24();
    return 3;
}

/* Same selection as func_0203de08 but reads four s16 values and forwards the last
 * two plus the chosen selector to func_0204c8f4. Sets substate 24 and returns 3.
 * Evidence: original instructions at 0x0203DEAC. */
u32 func_0203deac(void)
{
    s16 v1;
    s16 v2;
    s16 v3;
    s16 v4;
    u16 selector;

    Unk02e000_GetWorkArea();
    v1 = func_0203ac00(0);
    v2 = func_0203ac00(1);
    v3 = func_0203ac00(2);
    v4 = func_0203ac00(3);
    selector = (v1 < 0 || v2 < 0)
                   ? FIELD(u16, Unk02e000_GetWorkArea(), 0x35c)
                   : Unk02f2a8_Unk_035b08(v1, v2);
    func_0204c8f4(v3 & 0xff, v4 & 0xff, selector);
    Unk02dcfc_SetCode24();
    return 3;
}

/* Commit the pending change via func_0204b6f4, set substate 24, return 3.
 * Evidence: original instructions at 0x0203DFCC. */
u32 Unk03de08_Unk_03dfcc(void)
{
    func_0204b6f4();
    Unk02dcfc_SetCode24();
    return 3;
}

/* Read the first two s16 argument values and pass both, plus the +0x35C work-area
 * selector, to func_0204b74c. Returns 1.
 * Evidence: original instructions at 0x0203DF88. */
u32 Unk03de08_Unk_03df88(void)
{
    s16 v1;
    s16 v2;
    int value;

    v1 = func_0203ac00(0);
    v2 = func_0203ac00(1);
    value = Unk02e000_GetWorkArea();
    func_0204b74c((int)v1, (int)v2, FIELD(u16, value, 0x35c));
    return 1;
}

/* Same arguments as Unk03de08_Unk_03df88, followed by the pending-change commit
 * and substate 24. Returns 3.
 * Evidence: original instructions at 0x0203DF3C. */
u32 Unk03de08_Unk_03df3c(void)
{
    s16 v1;
    s16 v2;
    int value;

    v1 = func_0203ac00(0);
    v2 = func_0203ac00(1);
    value = Unk02e000_GetWorkArea();
    func_0204b74c((int)v1, (int)v2, FIELD(u16, value, 0x35c));
    func_0204b6f4();
    Unk02dcfc_SetCode24();
    return 3;
}

/* Read two u8 argument values, test the result of Unk02f2a8_Unk_035b08(a, b) and
 * forward 1 or 0 to Unk03aae8_Unk_03acf4. Returns 1.
 * Evidence: original instructions at 0x0203DFE0. */
u32 Unk03de08_Unk_03dfe0(void)
{
    u8 a = func_0203ac00(0);
    u8 b = func_0203ac00(1);

    if (Unk02e000_TestFlag(Unk02f2a8_Unk_035b08(a, b))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
