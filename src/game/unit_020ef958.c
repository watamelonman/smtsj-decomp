#include "types.h"

/* Only fields accessed by this unit are named; the complete work block is 0xf4 bytes. */
typedef struct Unk0ef958Work {
    u8 pad_00[8];
    u32 unk_08;
    u8 pad_0c[0x34];
    s32 unk_40;
    u8 pad_44[8];
    s32 unk_4c;
    u8 unk_50[0xa4];
} Unk0ef958Work;

typedef void (*WorkCallback)(Unk0ef958Work *);
/* Descriptor offsets follow the stores in func_020ef958. */
typedef struct Unk0ef958Descriptor {
    u32 size, count, unk_08;
    WorkCallback callbacks[6];
} Unk0ef958Descriptor;

extern Unk0ef958Work *data_02176df4;
extern void func_02008848(void *, int, u32);
extern void Unk0efb90_Unk_0efb90(Unk0ef958Work *);
extern void func_020efbc0(Unk0ef958Work *);
extern void Unk0efb90_Thunk_020f7248(Unk0ef958Work *);
extern void Unk0efb90_Unk_0efce8(Unk0ef958Work *);
extern void Unk0efb90_Nop_0efd18(Unk0ef958Work *);
extern void func_020efd1c(Unk0ef958Work *);
extern void func_020efd64(Unk0ef958Work *);
extern void func_020efdf4(Unk0ef958Work *);
extern void Unk0efdf4_Unk_0eff1c(Unk0ef958Work *);
extern void Unk0efdf4_Unk_0eff38(Unk0ef958Work *);
extern void Unk0efdf4_Unk_0eff5c(Unk0ef958Work *);
extern void func_020eff8c(Unk0ef958Work *);
extern void func_020f711c(Unk0ef958Work *, int, int, int, int, int, int, int, WorkCallback, WorkCallback, WorkCallback);
extern void func_020f81cc(void *, int, int, int, int, int, WorkCallback, WorkCallback, WorkCallback, WorkCallback);
extern void Unk0f81a4_SetUnkFielda0(void *, WorkCallback);
extern void Unk0f81a4_SetUnkField9c(void *, WorkCallback);
extern void func_020f7188(Unk0ef958Work *);
extern void Unk0bc1a8_Unk_0bc9b4(int, int);
extern void func_020f7de4(int, int);
extern void Unk100208_Unk_100208(int);
extern int func_020e8628(void);
extern void func_020f7d14(int);
extern void Unk0feba0_Unk_0febe8(int);
extern void func_020e82c8(void);
extern void Unk0e8228_Unk_0e8684(void);
extern void func_020f8264(void *);
void func_020efab4(Unk0ef958Work *work);
void Unk0ef958_Nop_0efab0(Unk0ef958Work *work);
void func_020ef9dc(Unk0ef958Work *work);

/* Populate the descriptor with the observed work size and callback slots. */
void func_020ef958(Unk0ef958Descriptor *descriptor)
{
    descriptor->size = 0xf4;
    descriptor->count = 4;
    descriptor->callbacks[0] = func_020efab4;
    descriptor->callbacks[1] = Unk0efb90_Unk_0efb90;
    descriptor->callbacks[2] = func_020efbc0;
    descriptor->callbacks[3] = 0;
    descriptor->callbacks[4] = Unk0ef958_Nop_0efab0;
    descriptor->callbacks[5] = Unk0efb90_Thunk_020f7248;
}

/* Clear the caller-owned 0xf4-byte work block, publish it, then configure it. */
void Unk0ef958_Unk_0ef9b0(Unk0ef958Work *work)
{
    func_02008848(work, 0, 0xf4);
    data_02176df4 = work;
    func_020ef9dc(work);
}

/* Install the callbacks and initial values observed in the two setup calls. */
void func_020ef9dc(Unk0ef958Work *work)
{
    work->unk_40 = 27;
    work->unk_4c = 0;
    func_020f711c(work, work->unk_40, -128, 0, 12, -128, 0, 0,
        Unk0efb90_Unk_0efce8, Unk0efb90_Nop_0efd18, func_020efd1c);
    func_020f81cc(work->unk_50, 3, 3, 0, 0, 1,
        func_020efd64, func_020efdf4, Unk0efdf4_Unk_0eff1c, Unk0efdf4_Unk_0eff38);
    Unk0f81a4_SetUnkFielda0(work->unk_50, Unk0efdf4_Unk_0eff5c);
    Unk0f81a4_SetUnkField9c(work->unk_50, func_020eff8c);
}

/* Empty callback slot: the original consists solely of bx lr. */
void Unk0ef958_Nop_0efab0(Unk0ef958Work *work)
{
}

/* Advance the shared handler, then dispatch the observed states at work offset 8. */
void func_020efab4(Unk0ef958Work *work)
{
    func_020f7188(work);
    switch (work->unk_08) {
    case 11:
        Unk0bc1a8_Unk_0bc9b4(work->unk_40, 0);
        break;
    case 0: case 1: break;
    case 2:
        func_020f7de4(work->unk_40, 0);
        Unk100208_Unk_100208(4);
        switch (func_020e8628()) {
        case 0: func_020f7d14(27); break;
        case 1: func_020f7d14(28); break;
        case 2: func_020f7d14(29); break;
        default:
            Unk0feba0_Unk_0febe8(0);
            func_020e82c8();
            break;
        }
        Unk0e8228_Unk_0e8684();
        break;
    case 3: case 4: case 5: case 6: case 7: case 8: break;
    case 9:
        work->unk_08 = 10;
        func_020f8264(work->unk_50);
        break;
    case 10: break;
    }
}
