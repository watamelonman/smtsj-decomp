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
    s32 unk_018;
    char text[28];
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

/** Borrowed 16-byte lookup entry; 020853e0 compares its first twelve bytes. */
typedef struct Unk0208539cEntry {
    char key[12];
    u32 value;
} Unk0208539cEntry;

extern s32 data_02175340;
extern Unk0208539cEntry *data_02175344;
extern s32 func_020153e0(const void *first, const void *second, u32 size);
extern u32 func_02015118(const char *text);
extern void func_0208d68c(char *destination, u32 size, const char *source);
extern const char data_02147480[], data_021474a4[], data_021474c8[];
extern const char data_021475d8[];

/** Search borrowed entries by twelve-byte key; empty keys never match. */
Unk0208539cEntry *func_0208539c(const char *key)
{
    s32 i;
    Unk0208539cEntry *entry;
    s32 count;
    if (*(const s8 *)key == 0) {
        return 0;
    }
    entry = data_02175344;
    count = data_02175340;
    for (i = 0; i < count; i++, entry++) {
        if (func_020153e0(entry, key, 12) == 0) {
            return entry;
        }
    }
    return 0;
}

/** Write the matched entry's final word; absent table/key returns -1/-3. */
s32 func_02085410(const char *key, u32 *value)
{
    Unk0208539cEntry *entry;
    if (data_02175344 == 0) {
        return -1;
    }
    entry = func_0208539c(key);
    if (entry == 0) {
        return -3;
    }
    *value = entry->value;
    return 0;
}

/** Accumulate hex digits with caller's radix; end borrows the first other byte. */
u32 func_020854b0(const char *text, char **end, u32 radix)
{
    u32 value = 0;
    s32 digit;
    for (;;) {
        digit = *(const s8 *)text;
        if (digit >= '0' && digit <= '9') {
            digit -= '0';
        } else if (digit >= 'a' && digit <= 'f') {
            digit -= 'a' - 10;
        } else if (digit >= 'A' && digit <= 'F') {
            digit -= 'A' - 10;
        } else {
            break;
        }
        value = radix * value + digit;
        text++;
    }
    *end = (char *)text;
    return value;
}

/** Parse two hexadecimal words separated by one byte; second may be null. */
u32 func_0208550c(const char *text, u32 *second)
{
    char *end;
    u32 first;
    if (func_02015118(text) >= 18) {
        func_0208547c(0, 0);
    }
    end = (char *)text;
    first = func_020854b0(text, &end, 16);
    if (*(s8 *)end != 0) {
        end++;
    }
    if (second != 0) {
        *second = func_020854a4(end, &end, 16);
    }
    return first;
}

/** Borrow the first untagged slot in the ten-entry pool, or return null. */
Unk0208539cRecord *func_020855e4(void)
{
    Unk0208539cRecord *result = 0;
    s32 i;
    Unk0208539cRecord *record = data_02175350;
    for (i = 0; i < 10; i++, record++) {
        if (record->unk_000 == 0) {
            result = &data_02175350[i];
            break;
        }
    }
    return result;
}

/** Initialize a borrowed record using the second text word and 2048-byte units. */
void func_02085638(Unk0208539cRecord *record)
{
    record->unk_004 = 2048;
    record->unk_008 = func_020855d0(record->text);
    record->unk_00c = (record->unk_008 + (record->unk_004 - 1)) / record->unk_004;
    record->unk_010 = 0;
    record->unk_018 = 0;
    record->unk_014 = 0;
    record->unk_001 = 0;
    record->unk_000 = 1;
}

/** Borrow and initialize a pool slot; null text/nonzero mode report diagnostics. */
Unk0208539cRecord *func_02085688(const char *text, s32 argument, s32 mode)
{
    Unk0208539cRecord *record;
    if (text == 0) {
        func_0208547c(0, (u32)data_02147480);
        return 0;
    }
    if (mode != 0) {
        func_0208547c(0, (u32)data_021474a4);
        return 0;
    }
    record = func_020855e4();
    if (record == 0) {
        func_0208547c(0, (u32)data_021474c8);
        return 0;
    }
    func_0208d68c(record->text, 18, text);
    func_02085638(record);
    return record;
}

/** Rescale record counts through byte position; caller supplies a nonzero unit. */
void func_020859f8(Unk0208539cRecord *record, s32 unit)
{
    s32 position;
    if (record == 0) {
        func_0208547c(0, (u32)data_021475d8);
        return;
    }
    position = record->unk_010 * record->unk_004;
    record->unk_004 = unit;
    record->unk_00c = (record->unk_008 + (record->unk_004 - 1)) / record->unk_004;
    record->unk_010 = position / record->unk_004;
    record->unk_014 = record->unk_018 * unit;
}

extern const char data_021474f8[];

/** Update position +0x10 under entry/exit providers; 02085770..57bc clamp it to [0, count]. */
s32 func_02085740(Unk0208539cRecord *record, s32 offset, s32 origin)
{
    if (record == 0) {
        func_0208547c(0, (u32)data_021474f8);
        return 0;
    }
    func_0208544c();
    if (origin == 0) {
        record->unk_010 = offset;
    } else if (origin == 2) {
        record->unk_010 = record->unk_00c + offset;
    } else if (origin == 1) {
        record->unk_010 += offset;
    }
    record->unk_010 = record->unk_010 < record->unk_00c ? record->unk_010 : record->unk_00c;
    record->unk_010 = record->unk_010 > 0 ? record->unk_010 : 0;
    func_02085458();
    return record->unk_010;
}

/** Query borrowed record/text by selectors at 02085a98; text selectors need terminated input. */
s32 func_02085a88(Unk0208539cRecord *record, s32 selector)
{
    if (record == 0) return 0;
    switch (selector) {
    case 300: return record->unk_008;
    case 301: return 0;
    case 302: return record->unk_008;
    case 200: return 0;
    case 201: return func_02085a60(record);
    case 202: return 0;
    case 203: return func_020855d0((const char *)record);
    case 204: return 0;
    case 205: return func_020855d0((const char *)record);
    case 299: return 0;
    case 600: return 1;
    case 400: return 0;
    default: return -1;
    }
}
