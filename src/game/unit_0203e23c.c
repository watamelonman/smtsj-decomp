/*
 * src/game/unit_0203e23c.c: script command handlers. Each handler reads its arguments with
 * func_0203ac00(i), does one game-state query or update, and returns 1 ("command done").
 * Query handlers report their answer through Unk03aae8_Unk_03acf4 (stores the script result word).
 * func_0203e2f8 (0x74) is still linked from the delink.
 */
#include "types.h"
#include "game/unit_0203e23c.h"

int func_0203ac00(int idx);
int Unk03aae8_Unk_03acf4(u32 value);
int Unk02e000_GetRecordUnk1f(u32 id);
int Unk02e000_SetRecordUnk1f_2(u32 id, int v);
u32 Unk02e000_GetRecordUnk1e(u32 id);
/* defined with a u32 id; declared int here because the u32 form changes 03e3e4's register order */
int Unk02e000_SetRecordUnk1e(int id, int v);
int Unk096754_Unk_0969f0(void);
int Unk096754_HasEntryId(int id);
int func_02096af4(u16 id);          /* slot (0..11) holding entry `id`, or -1 */
void func_02096958(int slot);
int Unk0986ac_Unk_098978(int arg0);
int Unk0986ac_Thunk_02098714(int bit);
u16 Unk09ee4c_GetField3c0Bits(void);
int BattleTask_Unk_0481d4(void);
void func_020494d0(int id, int n);

/* Script: result = record[arg0].unk_1f. */
int Unk03e23c_Unk_03e23c(void)
{
    u16 id = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(Unk02e000_GetRecordUnk1f(id));
    return 1;
}

/* Script: record[arg0].unk_1f = arg1. */
int Unk03e23c_Unk_03e260(void)
{
    int a = func_0203ac00(0);
    Unk02e000_SetRecordUnk1f_2((u16)a, func_0203ac00(1));
    return 1;
}

/* Script: result = 1 if Unk096754_Unk_0969f0 (entry count below the work-area limit), else 0. */
int Unk03e23c_Unk_03e290(void)
{
    if (Unk096754_Unk_0969f0()) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Script: result = 1 if an occupied slot holds entry id arg0, else 0. */
int Unk03e23c_Unk_03e2bc(void)
{
    if (Unk096754_HasEntryId((u16)func_0203ac00(0))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Script: if entry id arg0 is in a slot, pass that slot to func_02096958 (clears it). */
int Unk03e23c_Unk_03e36c(void)
{
    int slot = func_02096af4((u16)func_0203ac00(0));
    if (slot >= 0) {
        func_02096958(slot);
    }
    return 1;
}

/* Script: result = 1 if flag bit (arg0 - 0x6f) is set, else 0. */
int Unk03e23c_Unk_03e398(void)
{
    if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(func_0203ac00(0)))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Script: result = Unk09ee4c_GetField3c0Bits(). */
int Unk03e23c_Unk_03e3d0(void)
{
    Unk03aae8_Unk_03acf4(Unk09ee4c_GetField3c0Bits());
    return 1;
}

/*
 * Script: record[arg0].unk_1e += arg1. While BattleTask_Unk_0481d4 is set the change is also
 * forwarded to func_020494d0 (id, delta) before the store.
 */
int Unk03e23c_Unk_03e3e4(void)
{
    u16 id;
    int n;
    u32 old;
    id = func_0203ac00(0);
    n = func_0203ac00(1);
    old = Unk02e000_GetRecordUnk1e(id);
    if (BattleTask_Unk_0481d4() != 0) {
        func_020494d0(id, n);
    }
    Unk02e000_SetRecordUnk1e(id, old + n);
    return 1;
}
