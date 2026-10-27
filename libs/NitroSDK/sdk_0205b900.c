#include "types.h"

/** Borrowed resource work; offsets follow the original word and byte accesses. */
typedef struct {
    u32 first, second, unk_08;
    u32 source_first, source_second, unk_14;
    u8 bounds[20];
    char name[32];
    u8 pad_4c[12];
    u8 flag_58, ready;
} Unk05b900Work;

/** Caller-owned transfer descriptor, including the queue's callback storage. */
typedef struct {
    u32 transfer[6];
    u32 unk_18;
    void (*callback)(Unk05b900Work *);
    Unk05b900Work *argument;
} Unk05b900Transfer;

/** Borrowed stack prefix; its provider owns all 256 entry slots. */
typedef struct {
    Unk05b900Work *entries[256];
    u32 count;
} Unk05b900Stack;

extern void func_0205aa78(void *bounds, u32 *first, u32 *second, s16 *a, s16 *b);
extern void func_0205b598(Unk05b900Work *work, u32 first, u32 second);
extern void Unk05ae50_WaitVCountThen_05af64(u32 *transfer);
extern Unk05b900Work *func_0205ad9c(void);
extern Unk05b900Work *func_0205adb4(Unk05b900Work *parent, const void *data);
extern void Unk05ae50_Unk_05b228(Unk05b900Work *work);
extern void func_0205b234(Unk05b900Transfer *transfer, void (*callback)(Unk05b900Work *), Unk05b900Work *work);
extern int func_02013c14(char *destination, u32 size, const char *format, ...);
extern Unk05b900Work *func_0205aa08(void);
extern u32 func_0205accc(const void *resource);
extern u32 func_0205acd4(const void *resource);
extern Unk05b900Work *func_0205b724(void);
extern void func_0205aa54(Unk05b900Work *work);
extern Unk05b900Stack *Unk05b540_GetAddr_data_0216a730(void);
extern const char data_02143bf0[], data_02143bf8[], data_02143c00[];

/** Original calls reserve the bounds sizes and transfer six words before setting +0x59. */
void func_0205b900(Unk05b900Work *work)
{
    Unk05b900Transfer transfer;
    u32 first, second;
    func_0205aa78(work->bounds, &first, &second, 0, 0);
    func_0205b598(work, first, second);
    transfer.transfer[0] = work->source_first;
    transfer.transfer[1] = work->first;
    transfer.transfer[2] = first;
    transfer.transfer[3] = work->source_second;
    transfer.transfer[4] = work->second;
    transfer.transfer[5] = second;
    Unk05ae50_WaitVCountThen_05af64(transfer.transfer);
    work->ready = 1;
}

/** Original +0x10 pointer and +12 adjustment select the singleton's payload. */
Unk05b900Work *func_0205b97c(void)
{
    Unk05b900Work *parent = func_0205ad9c();
    Unk05b900Work *work = func_0205adb4(parent, (const u8 *)parent->source_second + 12);
    func_0205b900(work);
    return work;
}

/** Original queue callback sets +0x59 after this helper submits the transfer. */
void func_0205b9a0(Unk05b900Work *work)
{
    Unk05b900Transfer transfer;
    u32 first, second;
    func_0205aa78(work->bounds, &first, &second, 0, 0);
    func_0205b598(work, first, second);
    transfer.transfer[0] = work->source_first;
    transfer.transfer[1] = work->first;
    transfer.transfer[2] = first;
    transfer.transfer[3] = work->source_second;
    transfer.transfer[4] = work->second;
    transfer.transfer[5] = second;
    work->ready = 0;
    func_0205b234(&transfer, Unk05ae50_Unk_05b228, work);
}

/** Formats a bounded label (data_02143bf0: =%s(%d)) and reserves the bounds sizes. */
Unk05b900Work *func_0205ba28(const void *data, const char *name, int number)
{
    Unk05b900Work *work = func_0205adb4(0, data);
    u32 first, second;
    func_02013c14(work->name, 32, data_02143bf0, name, number);
    func_0205aa78(work->bounds, &first, &second, 0, 0);
    func_0205b598(work, first, second);
    return work;
}

/** Original nullable allocation sets +0x58 after reserving caller-supplied sizes. */
Unk05b900Work *func_0205ba98(u32 first, u32 second, const char *name, int number)
{
    Unk05b900Work *work = func_0205aa08();
    if (work == 0) return 0;
    func_02013c14(work->name, 32, data_02143bf8, name, number);
    func_0205b598(work, first, second);
    work->flag_58 = 1;
    return work;
}

/** Resource helper calls establish the two source words before immediate transfer. */
Unk05b900Work *func_0205bb04(const void *resource, const char *name, int number)
{
    Unk05b900Work *work = func_0205adb4(0, (const u8 *)resource + 12);
    work->source_first = func_0205accc(resource);
    work->source_second = func_0205acd4(resource);
    func_02013c14(work->name, 32, data_02143c00, name, number);
    func_0205b900(work);
    return work;
}

/** The original pop result is released only when non-null. */
void func_0205bb68(void)
{
    Unk05b900Work *work = func_0205b724();
    if (work == 0) return;
    func_0205aa54(work);
}

/** Snapshot the provider's +0x400 count and pop exactly that many entries. */
void func_0205bb80(void)
{
    u32 count = Unk05b540_GetAddr_data_0216a730()->count;
    u32 i;
    for (i = 0; i < count; i++) func_0205bb68();
}
