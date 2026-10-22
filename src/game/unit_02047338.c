/* src/game/unit_02047338.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020b8078();
/* Step handler (Ghidra-derived body, cleaned): refreshes the scan visor via
   ScanVisor_Unk_0a29c4(-1), then asks Unk0f81a4_Unk_0f81b4 whether something is
   pending; when it is, *arg0 = 2 signals the task runner. Always returns 2. */
u32 Unk047338_Unk_047470(u16 *arg0)
{
  int value;
  func_020b8078();
  ScanVisor_Unk_0a29c4(0xffffffff);
  Unk044904_Unk_045080();
  value = Unk0f81a4_Unk_0f81b4();
  if (value != 0) {
    *arg0 = 2;
  }
  return 2;
}

int Unk0aa118_SortRemaining();
int Unk0aa118_Advance();
int Unk09d060_Unk_09d13c();
int Unk044904_Unk_044fd8();
int Unk0aa118_PeekItem();
int func_02044ec4();
void func_0204a780();
int Unk044904_Unk_045080();
int func_020f8098();

/* Step handler: gates on Unk09d060_Unk_09d13c(), takes the current item of the
   0x0aa118 list (Unk0aa118_PeekItem), resolves it with func_02044ec4 and, when
   found, marks it with func_0204a780(item, 6); when func_020f8098(.., 2, id)
   succeeds, *p = 2 signals the task runner. Always returns 2. */
int Unk047338_Unk_0474a0(u16 *p)
{
    u32 *it;
    int o;
    if (Unk09d060_Unk_09d13c() == 0) {
        return 0;
    }
    it = (u32 *)Unk0aa118_PeekItem(Unk044904_Unk_044fd8());
    if (it != 0) {
        o = func_02044ec4(it[0]);
        if (o != 0) {
            func_0204a780(o, 6);
        }
        if (func_020f8098(Unk044904_Unk_045080(), 2, it[0]) != 0) {
            *p = 2;
        }
    }
    return 2;
}

/* Step handler (Ghidra-derived body, cleaned): advances the 0x0aa118 list and,
   when Unk0aa118_Advance reports a change, re-sorts it and sets *arg0 = 2 for the
   task runner. Always returns 2. */
u32 Unk047338_Unk_047504(u16 *arg0)
{
  int value;
  Unk044904_Unk_044fd8();
  value = Unk0aa118_Advance();
  if (value != 0) {
    Unk044904_Unk_044fd8();
    Unk0aa118_SortRemaining();
    *arg0 = 2;
  }
  return 2;
}

int Unk09d060_Unk_09d13c();
u32 Unk044904_Get_data_0215ee98();
int Unk06e4d8_GetFlag6c();
int func_0204a244();
int func_020a6038();
int func_0206e790();
int func_02049724();
int func_020494f0();
int Unk044904_Unk_044ff4();
void Unk044904_Unk_045c98();
void Unk044904_Unk_045b74();

/* Manager object reached through Unk044904_Get_data_0215ee98: ten object slots at +0x64. */
typedef struct Unk047338Mgr {
    u8 pad_0000[100];
    u32 *objs[10];
} Unk047338Mgr;

/* Task step function, dispatching on p[3] (state). 0: wait for
   Unk09d060_Unk_09d13c, then walk the ten object slots at +0x64 of the manager
   returned by Unk044904_Get_data_0215ee98 (same layout as Unk044904Objs in
   src/game/unit_02044904.c); entries whose word has bits 16..23 == 2 and that
   func_0204a244 accepts are handed to func_020a6038(id, 0) and the state becomes
   3. 1: if Unk06e4d8_GetFlag6c is set, run func_0206e790 and switch to state 2.
   2: wait for that flag to clear, then state 100. 3/4: count up and idle.
   p[0] = 2/returns 2 is the task runner's "run again" signal; 0 means wait. */
int func_02047338(s16 *p)
{
    Unk047338Mgr *mgr;
    int i;
    u32 *obj;

    switch (p[3]) {
    case 0:
        if (Unk09d060_Unk_09d13c() == 0) {
            return 0;
        }
        p[3] = 1;
        mgr = (Unk047338Mgr *)Unk044904_Get_data_0215ee98();
        for (i = 0; i < 10; i++) {
            obj = mgr->objs[i];
            if (obj != 0 && ((*obj >> 16) & 0xff) == 2 && func_0204a244(obj) != 0) {
                func_020a6038(*obj, 0);
                p[3] = 3;
            }
        }
        /* fall through */
    case 1:
        if (Unk06e4d8_GetFlag6c() != 0) {
            func_0206e790();
            p[3] = 2;
            return 0;
        }
        if (p[3] != 3) {
            break;
        }
        return 0;
    case 2:
        if (Unk06e4d8_GetFlag6c() != 0) {
            return 0;
        }
        p[3] = 100;
        break;
    case 3:
    case 4:
        p[3] = p[3] + 1;
        return 0;
    }
    Unk044904_Unk_045c98();
    Unk044904_Unk_044ff4();
    if (func_02049724() != 0) {
        p[0] = 2;
    } else {
        Unk044904_Unk_044ff4();
        func_020494f0();
        Unk044904_Unk_045b74();
    }
    return 2;
}

int func_02045ca8();
/* Step handler: sets st[0] = 2 (task runner signal) when st[1] is non-zero or
   func_02045ca8() succeeds. Always returns 2. */
int Unk047338_Unk_047534(s16 *st)
{
    if (st[1] != 0) {
        st[0] = 2;
    } else if (func_02045ca8() != 0) {
        st[0] = 2;
    }
    return 2;
}
