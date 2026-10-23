#include "types.h"

/* The shared slot owns a six-word work record; callers must check it before use. */
extern s32 *data_02176e24;

void func_02061424(void);
s32 *func_020fec84(void);
void func_020f51dc(s32 value0, s32 value1, s32 mode, s32 amount);

/* Select a mode in a six-word record. Original stores establish the mode and
 * transition fields, but do not establish a descriptive subsystem name. */
void Unk0feba0_Unk_0fed7c(s32 *work, u32 mode)
{
    switch (mode) {
    case 0:
        work[0] = -66;
        work[2] = 0;
        break;
    case 1:
        work[2] = 20;
        break;
    case 2:
    case 3:
    case 4:
        work[0] = 0;
        work[5] = 100;
        break;
    }
    work[3] = mode;
}

/* Return the shared work pointer, which may be null (data_02176e24 load). */
s32 *Unk0feba0_Get_data_02176e24(void)
{
    return data_02176e24;
}

/* Release the shared reference; the original callback only clears the slot. */
void Unk0feba0_Clear_data_02176e24(void)
{
    data_02176e24 = 0;
}

/* Forward to the cleanup helper only while the shared slot is populated. */
void Unk0feba0_Unk_0febc8(void)
{
    if (data_02176e24 == 0) {
        return;
    }
    func_02061424();
}

/* Lazily populate the shared slot using the record factory at 020fec84. */
void Unk0feba0_Unk_0feba0(void)
{
    s32 *work;
    if (data_02176e24 != 0) {
        return;
    }
    work = func_020fec84();
    data_02176e24 = work;
}

/* Forward a mode to the shared record; the caller must ensure it exists. */
void Unk0feba0_Unk_0febe8(u32 mode)
{
    s32 *work = Unk0feba0_Get_data_02176e24();
    Unk0feba0_Unk_0fed7c(work, mode);
}

/* Report completion for absent/inactive work, or when both signed transition
 * values have reached their terminal ranges (original +0 and +0x14 tests). */
s32 func_020fec00(void)
{
    s32 *work;
    if (data_02176e24 == 0) {
        return 1;
    }
    work = Unk0feba0_Get_data_02176e24();
    if (work[3] == 0) {
        return 1;
    }
    if (work[0] < 0) {
        return 0;
    }
    return work[5] <= 0;
}

/* Initialize the first four words and select mode zero. The record must have
 * six words, as required by the mode helper's other modes. */
void Unk0feba0_Reset(s32 *work)
{
    work[0] = 0;
    work[1] = 0;
    work[2] = 0;
    work[3] = 0;
    Unk0feba0_Unk_0fed7c(work, 0);
}

/* Submit active work to 020f51dc with the complement of its percentage field;
 * evidence is the original +0x0c mode test and 100 - [+0x14] argument. */
void Unk0feba0_Unk_0fed54(s32 *work)
{
    if (work[3] == 0) {
        return;
    }
    func_020f51dc(work[0], work[1], work[3], 100 - work[5]);
}
