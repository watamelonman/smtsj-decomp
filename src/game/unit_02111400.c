#include "types.h"

/* Layout follows the word accesses in func_02111400; slot 8 is untouched. */
typedef struct Unk111400Work {
    u32 size;
    u32 enabled;
    u32 unk_08;
    void (*callback_0c)(void);
    void (*callback_10)(void);
    void (*callback_14)(void);
    u32 unk_18;
    void (*callback_1c)(void);
    void (*callback_20)(void);
} Unk111400Work;

extern void func_0211030c(void), func_02110658(void), func_02110fc8(void);
extern void Unk10fe28_Unk_1113e0(void), func_021100c0(void);
extern u8 data_02151560[], data_02151584[];
extern u16 data_02151580;
extern u32 data_02176e4c[2];
extern u32 func_02051610(const void *);
extern void func_0208f020(void), func_0208f038(void);
extern void func_0201fba8(void), func_0208dc78(void);
extern void func_0208f044(const void *, u32, u32);
extern int func_02013c3c(char *, const void *, ...);
extern void *func_020445d0(u32, u32);
extern void *func_0204fde0(void *);
extern u32 func_0204fe18(void *);
extern void *func_02011810(void *, const void *, u32, u32,
                         int (*)(const u16 *, const u16 *));
extern void func_02008848(void *, int, u32);
extern void func_02008644(int, void *, u32);
extern void func_02111ac4(void *, u32);
extern void func_02111fb4(void *, u32, const void *, u32);
extern void func_02061c28(u32, u32, const void *);

/* Installs the callbacks identified by the original's five symbol relocations. */
void func_02111400(Unk111400Work *work)
{
    work->size = 0x60;
    work->enabled = 1;
    work->callback_0c = func_0211030c;
    work->callback_10 = func_02110658;
    work->callback_14 = func_02110fc8;
    work->unk_18 = 0;
    work->callback_1c = Unk10fe28_Unk_1113e0;
    work->callback_20 = func_021100c0;
}

/* Stores the resource lookup result in the observed word at offset 0x18. */
void Unk111400_Unk_111458(Unk111400Work *work)
{
    work->unk_18 = func_02051610(data_02151560);
}

/* Saves the three arguments in the original shared word/halfword slots. */
void Unk111400_Unk_111474(u32 first, u16 second, u32 third)
{
    u32 *words = data_02176e4c;
    u16 *half = &data_02151580;
    words[0] = first;
    *half = second;
    words[1] = third;
}

/* Brackets the three-argument operation with the original setup and teardown calls. */
u32 Unk111400_Unk_111508(const void *first, u32 second, u32 third)
{
    func_0208f020();
    func_0208f044(first, second, third);
    func_0208f038();
    func_0201fba8();
    func_0208dc78();
    return 0;
}

/* Formats the saved first argument into a 16-byte buffer before dispatch. */
u32 func_02111494(void)
{
    char buffer[16] = {0};
    func_02013c3c(buffer, data_02151584, data_02176e4c[0]);
    Unk111400_Unk_111508(buffer, data_02151580, data_02176e4c[1]);
    return 0;
}

/* Encodes a 24-byte value and submits a terminated 32-halfword buffer. */
void func_02111540(u32 first, u32 second)
{
    u8 value[24];
    u16 *buffer;
    func_02008848(value, 0, sizeof(value));
    u32 length = 33;
    u16 storage[length];
    buffer = storage;
    func_02008644(0, buffer, 66);
    func_02111ac4(value, second);
    func_02111fb4(buffer, 32, value, sizeof(value));
    buffer[32] = 0;
    func_02061c28(1, first, buffer);
}

/* Compares the unsigned leading halfwords; callers provide readable halfwords. */
int Unk111400_Unk_112254(const u16 *first, const u16 *second)
{
    return (u32)*first - (u32)*second;
}

/* Searches the resource's 24-byte records using a halfword key comparator. */
void *func_02112264(u16 key)
{
    u8 record[24];
    void *resource = func_020445d0(17, 0);
    void *records = func_0204fde0(resource);
    u32 count = func_0204fe18(resource);
    *(u16 *)record = key;
    return func_02011810(record, records, count, 24, Unk111400_Unk_112254);
}
