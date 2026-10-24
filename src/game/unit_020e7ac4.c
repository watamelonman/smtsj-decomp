#include "types.h"

/* Borrowed work view; field offsets are evidenced by ARM loads/stores in
 * 020e7f0c, 020e8000..020e8078 and 020e8198. Meanings remain unknown. */
typedef struct Unk0e7ac4Work {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 pad_0c[0x18];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 pad_34[0x1c];
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
} Unk0e7ac4Work;

extern Unk0e7ac4Work *data_02176cdc;
extern void func_0205bb68(void);
extern void func_0205ddb4(u32 value);
extern void func_020e7f44(u32 a, u32 b, u32 c, u32 d);

/* Empty callback, evidenced by the sole bx lr at 020e7b7c. */
void Unk0e7ac4_Nop_0e7b7c(void)
{
}

/* Releases the nonzero +0x54 value and clears the singleton; the caller
 * supplies live work. Evidence: calls and stores at 020e7f14..020e7f38. */
void Unk0e7ac4_Unk_0e7f0c(Unk0e7ac4Work *work)
{
    func_0205bb68();
    if (work->unk_54 != 0) {
        func_0205ddb4(work->unk_54);
        work->unk_54 = 0;
    }
    data_02176cdc = 0;
}

/* Forwards the saved four words of live singleton work to 020e7f44;
 * evidence: loads from +0x24..+0x30 at 020e81a4..020e81b0. */
void Unk0e7ac4_Unk_0e8198(void)
{
    Unk0e7ac4Work *work = data_02176cdc;
    func_020e7f44(work->unk_24, work->unk_28, work->unk_2c, work->unk_30);
}

/* Sets +4 only when +0x58 is nonzero; requires live singleton work.
 * Evidence: conditional store at 020e8024. */
void Unk0e7ac4_Unk_0e8014(u32 value)
{
    if (data_02176cdc->unk_58 != 0) {
        data_02176cdc->unk_04 = value;
    }
}

/* Sets +8 only when +0x58 is nonzero; requires live singleton work.
 * Evidence: conditional store at 020e8040. */
void Unk0e7ac4_Unk_0e8030(u32 value)
{
    if (data_02176cdc->unk_58 != 0) {
        data_02176cdc->unk_08 = value;
    }
}

/* Returns +0x58, or zero without work; evidence: conditional load at 020e8070. */
u32 Unk0e7ac4_Unk_0e8060(void)
{
    if (data_02176cdc == 0) {
        return 0;
    }
    return data_02176cdc->unk_58;
}

/* Stores +0x50 in live singleton work; evidence: str at 020e8008. */
void Unk0e7ac4_Unk_0e8000(u32 value)
{
    data_02176cdc->unk_50 = value;
}

/* Stores +0x58 in live singleton work; evidence: str at 020e8054. */
void Unk0e7ac4_Unk_0e804c(u32 value)
{
    data_02176cdc->unk_58 = value;
}
