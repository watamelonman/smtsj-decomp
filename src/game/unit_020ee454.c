#include "types.h"

/* Local view of the 0xf4-byte block cleared by 020ee500; child storage is opaque. */
typedef struct Work {
    u32 unk_00, unk_04, state;
    u8 pad_0c[0x34];
    u32 id, unk_44;
    u8 pad_48[8];
    u8 child[0xa4];
} Work;

/* Opaque callback slots are passed through to the owning subsystem. */
typedef void (*Callback)(void);
/* Descriptor offsets follow the stores in 020ee4a8; +8 is not initialized here. */
typedef struct Descriptor {
    u32 size, kind, unk_08;
    void (*update)(Work *);
    Callback hook10, hook14, hook18, hook1c, hook20;
} Descriptor;

extern Work *data_02176de4;
extern void func_020ee1d4(void);
extern void Unk0ee6dc_Unk_0ee6dc(void), func_020ee70c(void);
extern void Unk0ee6dc_Thunk_020f7248(void);
extern void Unk0ee6dc_Unk_0ee880(void), Unk0ee6dc_Nop_0ee8b8(void);
extern void func_020ee8bc(void), func_020ee904(void), func_020ee958(void);
extern void Unk0ee904_Unk_0eeadc(void), Unk0eeb20_Unk_0eeb20(void);
extern void Unk0eeb20_Unk_0eeb44(void), Unk0eeb20_Unk_0eeb74(void);
extern u32 *func_020611dc(Callback, u32, u32, u32, u32, u32, u32, u32);
extern void func_020615ec(u32 *, u32 *);
extern void func_02008848(void *, u32, u32);
extern void func_020f711c(Work *, u32, s32, u32, u32, s32, u32, u32,
                         Callback, Callback, Callback);
extern void func_020f81cc(void *, u32, u32, u32, u32, u32,
                         Callback, Callback, Callback, Callback);
extern void Unk0f81a4_SetUnkFielda0(void *, Callback);
extern void Unk0f81a4_SetUnkField9c(void *, Callback);
extern void func_020f7188(Work *);
extern void Unk0bc1a8_Unk_0bc9b4(u32, u32);
extern void func_020f7de4(u32, u32), Unk100208_Unk_100208(u32);
extern s32 func_020e8628(void);
extern void func_020e86a0(void), func_020f7d14(u32);
extern void Unk0e8228_Unk_0e8684(void), func_020f8264(void *);
void func_020ee52c(Work *work);
void func_020ee60c(Work *work);
void Unk0ee454_Nop_0ee608(void);

/* Allocate a 52-byte task, clear its first word and return its exported handle. */
u32 func_020ee454(void)
{
    u32 handle;
    u32 *task = func_020611dc(func_020ee1d4, 0, 0, 0, 52, 0, 0, 1);
    *task = 0;
    func_020615ec(&handle, task);
    return handle;
}

/* Fill the descriptor's size and callback slots; slot +8 is caller-owned. */
void func_020ee4a8(Descriptor *desc)
{
    desc->size = 244;
    desc->kind = 4;
    desc->update = func_020ee60c;
    desc->hook10 = Unk0ee6dc_Unk_0ee6dc;
    desc->hook14 = func_020ee70c;
    desc->hook18 = 0;
    desc->hook1c = Unk0ee454_Nop_0ee608;
    desc->hook20 = Unk0ee6dc_Thunk_020f7248;
}

/* Clear the complete 244-byte work block, publish it and initialize its children. */
void Unk0ee454_Unk_0ee500(Work *work)
{
    func_02008848(work, 0, 0xf4);
    data_02176de4 = work;
    func_020ee52c(work);
}

/* Configure id 29 and the embedded child at +0x50 with the original callback sets. */
void func_020ee52c(Work *work)
{
    work->id = 29;
    work->unk_44 = 1;
    func_020f711c(work, work->id, -128, 0, 12, -128, 0, 0,
                 Unk0ee6dc_Unk_0ee880, Unk0ee6dc_Nop_0ee8b8, func_020ee8bc);
    func_020f81cc(work->child, 4, 4, 0, 0, 1, func_020ee904,
                 func_020ee958, Unk0ee904_Unk_0eeadc, Unk0eeb20_Unk_0eeb20);
    Unk0f81a4_SetUnkFielda0(work->child, Unk0eeb20_Unk_0eeb44);
    Unk0f81a4_SetUnkField9c(work->child, Unk0eeb20_Unk_0eeb74);
}

/* Empty callback: the descriptor explicitly installs this no-op at +0x1c. */
void Unk0ee454_Nop_0ee608(void) { }

/* Advance common work, then handle states 2, 9 and 11; other states are inert. */
void func_020ee60c(Work *work)
{
    func_020f7188(work);
    switch (work->state) {
    case 0: case 1: break;
    case 11: Unk0bc1a8_Unk_0bc9b4(work->id, 0); break;
    case 2:
        func_020f7de4(work->id, 0);
        work->state = 1;
        Unk100208_Unk_100208(4);
        switch (func_020e8628()) {
        case 0: func_020e86a0(); func_020f7d14(27); break;
        case 1: func_020f7d14(28); break;
        default: func_020f7d14(29); break;
        }
        Unk0e8228_Unk_0e8684();
        break;
    case 3: case 4: case 5: case 6: case 7: case 8: break;
    case 9: func_020f8264(work->child); work->state = 10; break;
    case 10: break;
    }
}
