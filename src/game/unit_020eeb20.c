#include "types.h"

/* Only fields accessed by this unit are described; the work allocation is 0x50 bytes. */
typedef struct Unk0eeb20Work {
    u32 size;
    u32 unk_04;
    u32 state;
    void (*unk_0c)(struct Unk0eeb20Work *);
    void (*unk_10)(void);
    void (*unk_14)(void);
    u32 unk_18;
    void (*unk_1c)(void);
    void (*unk_20)(void);
    u8 pad_24[0x40 - 0x24];
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
} Unk0eeb20Work;

/* Shared pointer layout is limited to the two handles consumed by this unit. */
typedef struct Unk0eeb20Shared {
    u8 pad_00[0x40];
    u32 unk_40;
    u32 unk_44;
} Unk0eeb20Shared;

extern Unk0eeb20Shared *data_02176de4;
extern Unk0eeb20Work *data_02176de8;
extern u32 Unk0f8448_GetUnkField10(void *);
extern void Unk0e8228_Unk_0e8d90(u32, u32);
extern void func_020f7e48(u32, u32, u32);
extern void func_020f7d7c(u32, u32);
extern void func_020ea3cc(u32);
extern void func_02008848(void *, u32, u32);
extern void func_020eed24(void);
extern void func_020eed80(void);
extern void Unk0eed24_Thunk_020f7248(void);
extern void Unk0eed24_Unk_0eee94(void);
extern void Unk0eed24_Unk_0eeebc(void);
extern void func_020f711c(Unk0eeb20Work *, u32, s32, u32, u32, s32,
                         u32, u32, void (*)(void), void (*)(void), u32);
extern void func_020f7188(Unk0eeb20Work *);
extern void Unk0bc1a8_Unk_0bc9b4(u32, u32);
void func_020eec4c(Unk0eeb20Work *work);
void func_020eecbc(Unk0eeb20Work *work);
void Unk0eeb20_Nop_0eecb8(void);

/* Forward the argument's field 0x10 to the shared field 0x44 object's handler. */
void Unk0eeb20_Unk_0eeb20(void *arg)
{
    Unk0eeb20Shared *shared = data_02176de4;
    u32 value = Unk0f8448_GetUnkField10(arg);
    Unk0e8228_Unk_0e8d90(shared->unk_44, value);
}

/* Apply the two observed operations to the shared field 0x40 handle. */
void Unk0eeb20_Unk_0eeb44(void)
{
    Unk0eeb20Shared *shared = data_02176de4;
    func_020f7e48(shared->unk_40, 0, 7);
    func_020f7d7c(shared->unk_40, 0x22);
}

/* Map field 0x10 values 0..3 to the four observed handler arguments. */
void Unk0eeb20_Unk_0eeb74(void *arg)
{
    switch (Unk0f8448_GetUnkField10(arg)) {
    case 0: func_020ea3cc(9); return;
    case 1: func_020ea3cc(10); return;
    case 2: func_020ea3cc(11); return;
    case 3: func_020ea3cc(8); return;
    default: return;
    }
}

/* Install the callback slots and allocation size observed in the work header. */
void func_020eebc8(Unk0eeb20Work *work)
{
    work->size = 0x50;
    work->unk_04 = 4;
    work->unk_0c = func_020eecbc;
    work->unk_10 = func_020eed24;
    work->unk_14 = func_020eed80;
    work->unk_18 = 0;
    work->unk_1c = Unk0eeb20_Nop_0eecb8;
    work->unk_20 = Unk0eed24_Thunk_020f7248;
}

/* Clear the entire 0x50-byte allocation before publishing and initializing it. */
void Unk0eeb20_Unk_0eec20(Unk0eeb20Work *work)
{
    func_02008848(work, 0, 0x50);
    data_02176de8 = work;
    func_020eec4c(work);
}

/* Initialize handle 0x22 with the observed callbacks and clear the trailing state. */
void func_020eec4c(Unk0eeb20Work *work)
{
    work->unk_40 = 0x22;
    func_020f711c(work, work->unk_40, -10, 0, 2, -2, 0, 0,
                 Unk0eed24_Unk_0eee94, Unk0eed24_Unk_0eeebc, 0);
    work->unk_44 = 0;
    work->unk_48 = 0;
    work->unk_4c = 0;
}

/* Deliberately empty callback, as shown by the original's sole return instruction. */
void Unk0eeb20_Nop_0eecb8(void) { }

/* Run the common update, then handle states 9 and 11; other states are inert. */
void func_020eecbc(Unk0eeb20Work *work)
{
    func_020f7188(work);
    switch (work->state) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    case 8: break;
    case 11: Unk0bc1a8_Unk_0bc9b4(work->unk_40, 0); break;
    case 10: break;
    case 9: work->state = 10; break;
    default: break;
    }
}
