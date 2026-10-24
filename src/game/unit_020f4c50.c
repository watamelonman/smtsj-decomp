#include "types.h"

/* Work storage is 20 bytes, as established by the clear in 020f4ca8. */
typedef struct Unk0f4c50Work {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
} Unk0f4c50Work;

/* Callback slots follow the stores in 020f4c50; slot 08 is untouched. */
typedef struct Unk0f4c50Descriptor {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*dispatch)(Unk0f4c50Work *);
    void (*unk_10)(void);
    void (*unk_14)(void);
    u32 unk_18;
    void (*unk_1c)(void);
    void (*unk_20)(Unk0f4c50Work *, u32 *);
} Unk0f4c50Descriptor;

extern Unk0f4c50Work *data_02176e04;
extern void func_02008848(void *destination, int value, u32 size);
extern u32 func_020ea630(u32 value);
extern void Unk0d1c98_Unk_0d1d94(u32 value, int mode);
extern void func_020d1e94(int value);
extern void func_020f7de4(u32 value, int mode);
extern void Unk0bc1a8_Unk_0bc9b4(u32 value, int mode);
extern void func_020f4d64(Unk0f4c50Work *work, u32 *args);
void func_020f4cfc(Unk0f4c50Work *work);

/* Empty callback, as shown by the sole return instruction at 020f4cf8. */
void Unk0f4c50_Nop_0f4cf8(void) { }

/* Empty callback, as shown by the sole return instruction at 020f4d5c. */
void Unk0f4c50_Nop_0f4d5c(void) { }

/* Empty callback, as shown by the sole return instruction at 020f4d60. */
void Unk0f4c50_Nop_0f4d60(void) { }

/* Populate the descriptor with the callback addresses stored by 020f4c50. */
void func_020f4c50(Unk0f4c50Descriptor *descriptor)
{
    descriptor->size = 0x14;
    descriptor->unk_04 = 4;
    descriptor->dispatch = func_020f4cfc;
    descriptor->unk_10 = Unk0f4c50_Nop_0f4d5c;
    descriptor->unk_14 = Unk0f4c50_Nop_0f4d60;
    descriptor->unk_18 = 0;
    descriptor->unk_1c = Unk0f4c50_Nop_0f4cf8;
    descriptor->unk_20 = func_020f4d64;
}

/* Set the four initial words; 020f4cd4 leaves the fifth word unchanged. */
void Unk0f4c50_Unk_0f4cd4(Unk0f4c50Work *work)
{
    work->unk_00 = 0x23;
    work->unk_04 = 0;
    work->unk_08 = 9;
    work->unk_0c = 1;
}

/* Clear and publish the 20-byte work area before setting its initial words. */
void Unk0f4c50_Unk_0f4ca8(Unk0f4c50Work *work)
{
    func_02008848(work, 0, 0x14);
    data_02176e04 = work;
    Unk0f4c50_Unk_0f4cd4(work);
}

/* Dispatch word 0c values 6 and 7 using word 00; other values do nothing. */
void func_020f4cfc(Unk0f4c50Work *work)
{
    switch (work->unk_0c) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: func_020f7de4(work->unk_00, 0); break;
    case 7: Unk0bc1a8_Unk_0bc9b4(work->unk_00, 0); break;
    case 8: break;
    case 9: break;
    case 10: break;
    }
}

/* A nonzero mode forwards the converted fifth word; zero sends a fixed 1. */
void Unk0f4c50_Unk_0f51b0(Unk0f4c50Work *work, int mode)
{
    if (mode != 0) {
        u32 value = func_020ea630(work->unk_10);
        Unk0d1c98_Unk_0d1d94(value, -1);
        return;
    }
    func_020d1e94(1);
}
