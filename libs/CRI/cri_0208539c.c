#include "types.h"

extern void func_020821e0(void);
extern void func_020821f0(void);
extern u32 func_02016fa4(const char *text, char **end, s32 base);
extern u32 func_0208550c(const char *text, u32 *second);
extern void *func_020119c0(void *destination, s32 value, u32 size);
extern const char data_02147418[];

/** Borrowed callback pair; dispatch at 0208547c reads context before callback. */
typedef struct Unk0208539cCallbacks {
    void *context;
    void (*callback)(void *context, u32 argument, u32 value);
} Unk0208539cCallbacks;

extern Unk0208539cCallbacks data_02175348;

/** Forward to the entry provider selected by the literal at 02085454. */
void func_0208544c(void)
{
    func_020821e0();
}

/** Forward to the exit provider selected by the literal at 02085460. */
void func_02085458(void)
{
    func_020821f0();
}

/** Return the borrowed string; preserve the original read at 0212ed08. */
const char *func_02085464(void)
{
    u32 ignored = *(volatile const u32 *)0x0212ed08;
    return data_02147418;
}

/** Forward numeric conversion; 02085570 supplies text, end pointer and base 16. */
u32 func_020854a4(const char *text, char **end, s32 base)
{
    return func_02016fa4(text, end, base);
}

/** Leave the borrowed record untouched, as the sole bx lr at 02085580 does. */
void func_02085580(const char *record)
{
}

/** Register the borrowed pair read by 0208547c; context must outlive dispatch. */
void func_020855bc(void (*callback)(void *context, u32 argument, u32 value), void *context)
{
    data_02175348.callback = callback;
    data_02175348.context = context;
}

/** Return the second parsed word written by 0208550c into caller-owned storage. */
u32 func_020855d0(const char *text)
{
    u32 second;
    func_0208550c(text, &second);
    return second;
}

/** Clear a caller-owned 56-byte record through the literal-selected fill provider. */
void *func_02085624(void *record)
{
    return func_020119c0(record, 0, 56);
}

/** Borrowed 56-byte record; only instruction-established fields are exposed. */
typedef struct Unk0208539cRecord {
    s8 unk_000;
    s8 unk_001;
    u8 padding_002[2];
    s32 unk_004;
    s32 unk_008;
    s32 unk_00c;
    s32 unk_010;
    s32 unk_014;
    u8 padding_018[32];
} Unk0208539cRecord;

extern Unk0208539cRecord data_02175350[10];
extern const char data_02147514[], data_02147590[], data_021475a8[];
extern const char data_021475c0[], data_021475f0[];

/** Dispatch the registered borrowed pair: 02085494 passes context, argument, value. */
void func_0208547c(u32 value, u32 argument)
{
    if (data_02175348.callback != 0) {
        data_02175348.callback(data_02175348.context, argument, value);
    }
}

/** Visit the ten 56-byte records at 02175350; nonzero signed tags select 02085580. */
void func_02085584(void)
{
    s32 i;
    Unk0208539cRecord *record = data_02175350;
    for (i = 0; i < 10; i++, record++) {
        if (record->unk_000 != 0) {
            func_02085580((const char *)record);
        }
    }
}

/** Clear byte +1 under the entry/exit providers; null reports literal 02147590. */
void func_02085974(Unk0208539cRecord *record)
{
    if (record == 0) {
        func_0208547c(0, (u32)data_02147590);
        return;
    }
    func_0208544c();
    record->unk_001 = 0;
    func_02085458();
}

/** Reset byte +1 first, then clear a tag-one record; caller owns all 56 bytes. */
void func_02085710(Unk0208539cRecord *record)
{
    if (record == 0) {
        return;
    }
    func_02085974(record);
    if (record->unk_000 == 1) {
        record->unk_000 = 0;
        func_02085624(record);
    }
}

/** Return word +0x10; null reports literal 02147514 and returns zero. */
s32 func_020857d0(const Unk0208539cRecord *record)
{
    if (record != 0) {
        return record->unk_010;
    }
    func_0208547c(0, (u32)data_02147514);
    return 0;
}

/** Return signed byte +1; null reports literal 021475a8 and returns zero. */
s32 func_020859a8(const Unk0208539cRecord *record)
{
    if (record != 0) {
        return record->unk_001;
    }
    func_0208547c(0, (u32)data_021475a8);
    return 0;
}

/** Return word +4; null reports literal 021475c0 and returns zero. */
s32 func_020859d0(const Unk0208539cRecord *record)
{
    if (record != 0) {
        return record->unk_004;
    }
    func_0208547c(0, (u32)data_021475c0);
    return 0;
}

/** Return word +0x14; null reports literal 021475f0 and returns zero. */
s32 func_02085a60(const Unk0208539cRecord *record)
{
    if (record != 0) {
        return record->unk_014;
    }
    func_0208547c(0, (u32)data_021475f0);
    return 0;
}
