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
