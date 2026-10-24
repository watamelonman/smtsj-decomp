PRE = r'''/* View of the Unk02e000_Thunk_0202e788 work area used by func_0202efa4. */
typedef struct Unk02ee5cLists {
    u8 pad_00[0x24];
    u16 out[18];                /* 0x24: combined list */
    u16 second[8];              /* 0x48: copied after the separator */
    u8 pad_58[2];
    u16 first[8];               /* 0x5a: copied first */
} Unk02ee5cLists;
'''

FEFA4 = r'''/* Builds the 18-entry list at +0x24: the zero-terminated list at +0x5a
 * (at most eight ids), separator 1 in place of its terminator, the list at
 * +0x48 the same way, then zeros through entry 17. */
void func_0202efa4(void)
{
    Unk02ee5cLists *w = (Unk02ee5cLists *)Unk02e000_Thunk_0202e788();
    int n = 0;
    int i;

    for (i = 0; i < 8; i++, n++) {
        w->out[n] = w->first[i];
        if (w->first[i] == 0) {
            break;
        }
    }
    w->out[n] = 1;
    n++;
    for (i = 0; i < 8; i++, n++) {
        w->out[n] = w->second[i];
        if (w->second[i] == 0) {
            break;
        }
    }
    for (; n <= 17; n++) {
        w->out[n] = 0;
    }
}'''

PRE210 = PRE


PRE211 = r'''/* Script context from Unk03aae8_Unk_03ad14; only the +0xe8 subobject is used. */
typedef struct Unk03cc58Sub {
    u8 pad_00[0x18];
    s32 unk_18;                 /* 0x18: set to 5 after a positive change */
} Unk03cc58Sub;
typedef struct Unk03cc58Context {
    u8 pad_00[0xe8];
    Unk03cc58Sub *unk_e8;
} Unk03cc58Context;
s32 func_02095818(void);
void func_02065c10(void);
void func_02065aa4(s32 entry, s32 amount);
void func_020659a4(s32 entry, s32 amount);
void func_02099a28(s32 entry, s32 amount);
Unk03cc58Context *Unk03aae8_Unk_03ad14(void);
/* Keeps the value-then-subobject operand order of the original store. */
static inline void Unk03cc58_SetSubState(s32 value, Unk03cc58Sub *sub)
{
    sub->unk_18 = value;
}
u8 *Unk02e000_Thunk_0202e788(void);
s32 Unk09974c_GetEntryUnk08(s32 entry);
void func_02099b10(s32 entry, s32 amount);
'''

FCD50 = r'''/* Changes entry `entry` by `amount`. A positive amount goes through
 * func_02065aa4 (mode 0) or func_020659a4, then func_02099a28, sets the
 * context subobject's +0x18 to 5 and returns 3. Otherwise entries of kinds
 * 3..6 are left alone and the rest are reduced through func_02099b10;
 * returns 1. */
s32 func_0203cd50(s32 entry, s32 amount, s32 mode)
{
    if (amount > 0) {
        /* The original calls func_02065c10 separately for result 1 and for
         * any other result (two calls in the ROM). */
        switch (func_02095818()) {
        case 1:
            func_02065c10();
            break;
        default:
            func_02065c10();
            break;
        }
        if (mode == 0) {
            func_02065aa4(entry, amount);
        } else {
            func_020659a4(entry, amount);
        }
        func_02099a28(entry, amount);
        Unk03cc58_SetSubState(5, Unk03aae8_Unk_03ad14()->unk_e8);
        return 3;
    }
    Unk02e000_Thunk_0202e788();
    switch (Unk09974c_GetEntryUnk08(entry)) {
    case 3:
    case 4:
    case 5:
    case 6:
        return 1;
    }
    func_02099b10(entry, -amount);
    return 1;
}'''

SPECS = [('src/game/unit_0203cc58.c', [('func_0203cd50', FCD50)], PRE211)]
