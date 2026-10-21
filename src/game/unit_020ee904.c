/* src/game/unit_020ee904.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Work object behind data_02176de4 (shared with unit_020ee454/unit_020eeb20). */
typedef struct Unk0ee904Work {
    u8 pad_0000[0x40];
    u32 unk_0040; /* handle passed to func_020f7e48/func_020f7d7c */
    u8 pad_0044[0xc];
    u8 unk_0050[4]; /* sub-object initialised by Unk0f8448_Init; size guessed */
} Unk0ee904Work;

/* Object returned by func_02044ec4. */
typedef struct Unk0ee904Obj {
    u32 unk_0000;
    u8 pad_0004[0x1e4];
    u8 unk_01e8[4]; /* passed by address to func_020e8d38; size guessed */
} Unk0ee904Obj;

extern Unk0ee904Work *data_02176de4;

u32 Unk0f8448_GetUnkField10(void *obj);
int Unk0f8448_Init(void *obj, int value);
int Unk0e8228_Unk_0e8c80(void);
Unk0ee904Obj *func_02044ec4(int arg);
int func_020e8ebc(int arg);
void Unk0e8228_Unk_0e8f50(u32 arg0);
int Unk0e8228_IsField4One(void);
int func_020f7e48(u32 a, u32 b, u32 c);
int func_020f7d7c(u32 a, u32 b);
int func_020f7de4(u32 a, u32 b);
int func_0204a160(Unk0ee904Obj *obj, int arg);
int func_0204a1d0(Unk0ee904Obj *obj, int arg);
void Unk0e8228_Unk_0e8eac(void);
int Unk0feba0_Unk_0febe8(int arg);
int Unk0fd9f0_Unk_0fda58(int arg);
int func_020e8710(u32 a, u32 b, u32 c);
int Unk0e8228_Unk_0e82ac(void);
void Unk0e8228_Unk_0e8d90(u32 arg0, u32 arg1);
int Unk100208_Unk_100208(int arg);
int func_020e8d38(Unk0ee904Obj *obj, u8 *sub, u32 head, u32 kind);
int Unk0e8228_Unk_0e8d18(int arg);
int Unk0e8228_Unk_0e8c9c(void);
int func_020e852c(void);
int Unk0e8228_Thunk_02045c38(void);

/* Returns 0 when the given mode (1 or 2) is currently blocked by its 0e8228 check, else 1.
   The first argument is unused (callback signature). */
int func_020ee904(void *self, int mode)
{
    switch (mode) {
    case 1:
        if (Unk0e8228_Unk_0e8c9c() != 0) {
            return 0;
        }
        if (func_020e852c() < 1) {
            return 0;
        }
        break;
    case 2:
        if (Unk0e8228_Thunk_02045c38() != 0) {
            return 0;
        }
        break;
    }
    return 1;
}

/* Dispatches on the state field of obj (0..3) and drives the 0e8228/0f7xxx calls for that state. */
void func_020ee958(void *obj)
{
    u32 state = Unk0f8448_GetUnkField10(obj);
    Unk0ee904Work *w = data_02176de4;
    Unk0ee904Obj *o = func_02044ec4(Unk0e8228_Unk_0e8c80());
    u32 kind;

    func_020e8ebc(0);
    Unk0e8228_Unk_0e8f50(0);
    switch (state) {
    case 0:
        if (Unk0e8228_IsField4One() != 0) {
            func_020f7e48(30, 1, 1);
            func_020f7d7c(w->unk_0040, 30);
            func_0204a160(o, 0);
            Unk0e8228_Unk_0e8eac();
            func_020f7e48(30, 2, func_0204a1d0(o, 0));
            func_020f7e48(w->unk_0040, 0, 1);
            Unk0feba0_Unk_0febe8(0);
            Unk0fd9f0_Unk_0fda58(1);
        } else {
            func_020e8710(w->unk_0040, 1, 0);
            func_020f7e48(w->unk_0040, 0, 1);
            Unk0feba0_Unk_0febe8(0);
        }
        break;
    case 1:
        if (Unk0e8228_Unk_0e82ac() == 0) {
            Unk0e8228_Unk_0e8d90(4, 0);
        }
        func_020f7e48(31, 1, 2);
        func_020f7d7c(w->unk_0040, 31);
        func_020f7de4(w->unk_0040, 2);
        Unk0fd9f0_Unk_0fda58(1);
        Unk100208_Unk_100208(4);
        break;
    case 2:
    case 3:
        kind = 6;
        if (state == 3) {
            kind = 7;
        }
        if (func_020e8d38(o, o->unk_01e8, o->unk_0000, kind) == 0) {
            return;
        }
        Unk0e8228_Unk_0e8d18(0);
        func_020f7e48(w->unk_0040, 0, 8);
        break;
    }
}

/* Unless Unk0e8228_Unk_0e82ac reports set, re-initialises the work object's 0x50 sub-object;
   then calls Unk0e8228_Unk_0e8d18(1) and func_020f7e48(handle, 0, 8). */
void Unk0ee904_Unk_0eeadc(void)
{
    Unk0ee904Work *w = data_02176de4;

    if (Unk0e8228_Unk_0e82ac() == 0) {
        Unk0f8448_Init(w->unk_0050, 0);
    }
    Unk0e8228_Unk_0e8d18(1);
    func_020f7e48(w->unk_0040, 0, 8);
}
