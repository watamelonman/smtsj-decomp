#include "types.h"

extern u32 data_0213ce44;
extern void func_02006d0c(void);
extern void func_020026a0(void);
extern void func_020026a4(void);
extern void func_02002824(void);
extern void func_0200e860(void);
extern void func_020535cc(void);
extern void func_02053c08(void);
extern void func_02052e68(u32 first, u32 second);
extern void func_02051378(void);
extern void func_02007460(void);
void func_0205002c(u32 stream, u32 seed);

/* Runs the observed startup call sequence; forwards both words unchanged to 02052e68.
 * The original stores the startup flag and seeds both streams with 1192. */
u32 func_0204ffa8(u32 first, u32 second)
{
    func_02006d0c();
    func_020026a0();
    data_0213ce44 = 1;
    func_020026a4();
    func_02002824();
    *(volatile u32 *)0x04001000 &= ~0x10000;
    func_0200e860();
    func_020535cc();
    func_02053c08();
    func_02052e68(first, second);
    func_02051378();
    func_0205002c(0, 1192);
    func_0205002c(1, 1192);
    func_02007460();
    return 1;
}

/* Borrowed MTBL prefix; offsets and signature come from 0204ff30/0204ff64. */
typedef struct TableHeader {
    u32 signature;
    u32 reserved[2];
    u32 count;
    u32 first;
} TableHeader;

extern u32 data_0215f008[];
u32 func_02050088(u32 stream, u32 minimum, u32 maximum);

/* Centralizes the MTBL signature contract shared by both index accessors. */
static inline _Bool valid_table(const TableHeader *table)
{
    if (table->signature == 0x4c42544d) return 1;
    return 0;
}

/* Reads the first index at offset 16; null or non-MTBL headers yield zero. */
u32 func_0204ff30(const TableHeader *table)
{
    if (table == 0) return 0;
    if (valid_table(table) == 0) return 0;
    return table->first;
}

/* Returns the inclusive last index, using MTBL count/first at offsets 12/16. */
u32 func_0204ff64(const TableHeader *table)
{
    if (table == 0) return 0;
    if (valid_table(table) == 0) return 0;
    return table->first + table->count - 1;
}

/* Seeds a caller-selected stream; the original truncates to the low 16 bits. */
void func_0205002c(u32 stream, u32 seed)
{
    data_0215f008[stream] = (u16)seed;
}

/* Advances the 16-bit LCG: multiplier 109 and increment 1021 are original constants. */
u32 func_02050044(u32 stream)
{
    u32 value = (u16)(data_0215f008[stream] * 109 + 1021);
    data_0215f008[stream] = value;
    return value;
}

/* Samples the inclusive zero-based range through the original range helper. */
u32 func_02050074(u32 stream, u32 maximum)
{
    return func_02050088(stream, 0, maximum);
}

/* Scales one 16-bit sample into the inclusive bounds; arithmetic wraps at 32 bits. */
u32 func_02050088(u32 stream, u32 minimum, u32 maximum)
{
    u32 value = func_02050044(stream);
    u32 range = maximum - minimum + 1;
    return minimum + ((range * value) >> 16);
}

/* Reads the selected stream without advancing it; caller supplies a valid index. */
u32 func_020500ac(u32 stream)
{
    return data_0215f008[stream];
}

/* Multiplies exponent times, returning one for nonpositive exponents (02050138 loop). */
u32 func_02050138(u32 base, s32 exponent)
{
    u32 result = 1;
    while (exponent > 0) {
        result = result * base;
        exponent--;
    }
    return result;
}
