#include "libs/unknown/lib_02048e90.h"

extern Unk048e90State *data_0215eea0;
extern void func_020a594c(void);
extern void func_020457e8(void);
extern void Unk0a163c_Unk_0a1ae0(void *state);
extern void BattleTask_Unk_048244(void);
extern void Unk0a23f4_Unk_0a2414(void);
extern void func_0205e590(s32 value);
extern void Unk05ae50_Unk_05afd8(u32 value);
extern void Unk0e7290_Unk_0e7734(void);
extern void func_0205bb68(void);
extern void Unk0c855c_Unk_0ca648(s32 value);
extern void func_02065ca8(void);
extern void Unk065e88_Unk_065eac(void);
extern void Unk0b28e4_Unk_0b6338(void);
extern void Unk044904_Unk_045080(void);
extern void Unk0f7eb4_Release(void);
extern void func_02053000(void *resource);
extern void Unk044394_Unk_044534(s32 value);
extern void Unk0946e0_Thunk_02053000(void *value);
extern void Unk0939f0_Set_data_02175d8c(s32 value);
extern void Unk09d060_Unk_09d10c(void);
extern void Unk044904_Unk_044ea8(void);
extern void func_020580ec(s32 value);
extern void func_020572c0(void);
extern void *func_0204fdac(void *resource, u32 index);
extern void *func_0204fde0(void *entry);
extern u32 func_0204fe18(void *entry);
extern void func_02044804(Unk048e90State *state, void *data, u16 count, const void *callback);
extern const u8 data_0214316c[];
extern void func_02052da0(void);
extern void Unk0946e0_Unk_094958(void);
extern void func_0206f508(void);
extern s32 func_0204a244(Unk048e90Object *object);
extern s32 Unk0a5680_Unk_0a60fc(u32 identifier);
extern s32 func_0204a7f4(Unk048e90Object *object, s32 value);
extern void Unk0a5680_Unk_0a611c(u32 identifier);
extern void Unk0a5680_Unk_0a6150(u32 identifier);
extern s32 Unk044904_Unk_0459ec(void);
extern s32 func_02053800(s32 index, u32 mask);
extern void Unk0fd9f0_Unk_0fda58(void);
extern void Unk0a0ce4_Unk_0a0da4(s32 value);
extern s32 func_02044868(Unk048e90State *state);
extern void func_02061424(Unk048e90State *state);

/* ARM 02048e90: +0x7a3c guards setup, +0x50 is cleared before providers run. */
void func_02048e90(Unk048e90State *state)
{
    if (state->initialized != 0) return;
    state->initialized = 1;
    state->unk_0050 = 0;
    func_020a594c();
    func_020457e8();
    Unk0a163c_Unk_0a1ae0((u8 *)state + 0x79b0);
    BattleTask_Unk_048244();
    Unk0a23f4_Unk_0a2414();
}

/* ARM 02048ed8: tail-dispatches guarded setup on the singleton. */
void func_02048ed8(void)
{
    func_02048e90(data_0215eea0);
}

/* ARM 02048ef0: ordered provider teardown, clearing each released resource slot. */
void func_02048ef0(Unk048e90State *state)
{
    s32 i;
    func_0205e590(0);
    Unk05ae50_Unk_05afd8(0x18000);
    func_02048e90(state);
    Unk0e7290_Unk_0e7734();
    func_0205bb68();
    Unk0c855c_Unk_0ca648(0);
    Unk0c855c_Unk_0ca648(1);
    func_02065ca8();
    Unk065e88_Unk_065eac();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    Unk0b28e4_Unk_0b6338();
    Unk044904_Unk_045080();
    Unk0f7eb4_Release();
    for (i = 0; i < 9; i++) {
        func_02053000(state->resources[i]);
        state->resources[i] = 0;
    }
    Unk044394_Unk_044534(3);
    Unk044394_Unk_044534(1);
    Unk044394_Unk_044534(2);
    Unk044394_Unk_044534(10);
    Unk044394_Unk_044534(11);
    Unk044394_Unk_044534(14);
    Unk044394_Unk_044534(7);
    Unk0946e0_Thunk_02053000(state->unk_7870);
    Unk0939f0_Set_data_02175d8c(0);
    Unk09d060_Unk_09d10c();
    Unk044904_Unk_044ea8();
    func_020580ec(1);
    func_020572c0();
    data_0215eea0 = 0;
}

/* ARM 02048ff4: reads table zero's data/count and submits a borrowed buffer. */
void func_02048ff4(Unk048e90State *state)
{
    void *entry = func_0204fdac(state->resources[0], 0);
    void *data = func_0204fde0(entry);
    u32 count = func_0204fe18(entry);
    func_02044804(state, data, (u16)count, data_0214316c);
}

/* ARM 02049044: identifier bits 16..23 select type two; kinds 1/2/7
 * use a separate provider transition. The +0x54 latch gates notification. */
void func_02049044(Unk048e90State *state)
{
    s32 i;
    func_02052da0();
    Unk0946e0_Unk_094958();
    func_0206f508();
    for (i = 0; i < 10; i++) {
        Unk048e90Object *object = state->objects[i];
        if (object != 0 && ((object->identifier >> 16) & 0xff) == 2) {
            s32 kind = func_0204a244(object);
            if (kind == 1 || kind == 2 || kind == 7) {
                if (Unk0a5680_Unk_0a60fc(object->identifier) != 0 &&
                    func_0204a7f4(object, 12) == 0) {
                    Unk0a5680_Unk_0a611c(object->identifier);
                }
            } else if (Unk0a5680_Unk_0a60fc(object->identifier) == 0) {
                Unk0a5680_Unk_0a6150(object->identifier);
            }
        }
    }
    if (Unk044904_Unk_0459ec() != 0 &&
        (func_02053800(0, 0x400) != 0 || func_02053800(0, 2) != 0) &&
        state->unk_0054 == 0) {
        state->unk_0054 = 1;
        Unk0fd9f0_Unk_0fda58();
        Unk0a0ce4_Unk_0a0da4(16);
    }
    if (func_02044868(state) != 0) return;
    func_02061424(state);
}
