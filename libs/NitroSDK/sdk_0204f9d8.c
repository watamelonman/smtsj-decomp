typedef unsigned int u32;
typedef unsigned short u16;

/* Borrowed 25-halfword buffers; stride is established by 0204fcb0. */
typedef struct HalfwordBuffer { u16 values[25]; } HalfwordBuffer;
extern u32 data_0215eeac[12];
extern HalfwordBuffer data_0215eedc[6];
extern u32 Unk09727c_GetAreaSub24(void);
extern u32 Unk09727c_GetAreaSub5a(void);
extern u32 Unk09727c_GetAreaSub48(void);
extern void func_0204fa4c(const u16 *source, u16 *destination, u32 capacity);

/* Tests the token interval (0x8000, 0x83e9), from the original comparisons. */
int func_0204f9d8(u32 token)
{
    if (token > 0x8000 && token < 0x83e9) return 1;
    return 0;
}

/* Recognizes the zero stream terminator, also used by 020d33cc. */
int func_0204f9fc(u32 token)
{
    return token == 0;
}

/* Selects an area field through the three existing area accessors. */
u32 func_0204fa0c(u32 selector)
{
    switch (selector) {
    case 1: return Unk09727c_GetAreaSub24();
    case 2: return Unk09727c_GetAreaSub5a();
    case 3: return Unk09727c_GetAreaSub48();
    default: return 0;
    }
}

/* Clears twelve slots and terminates six borrowed buffers without clearing tails. */
void func_0204fa94(void)
{
    int i;
    int zero = 0;
    for (i = 0; i < 12; i++) data_0215eeac[i] = zero;
    for (i = 0; i < 6; i++) data_0215eedc[i].values[0] = 0;
}

/* Slot zero is reserved; only indices 1 through 11 are accepted. */
int func_0204fad4(u32 index)
{
    if (index != 0 && index < 12) return 1;
    return 0;
}

/* Stores a slot value only when its index passes the original guard. */
void func_0204faf0(u32 index, u32 value)
{
    if (func_0204fad4(index)) data_0215eeac[index] = value;
}

/* Returns zero for reserved/out-of-range slots; storage remains provider-owned. */
u32 func_0204fb14(u32 index)
{
    return func_0204fad4(index) == 0 ? 0 : data_0215eeac[index];
}

/* Copies into a one-based buffer slot using the existing 25-halfword bounded copier. */
void func_0204fcb0(u32 index, const u16 *source)
{
    if (index < 1 || index >= 7) return;
    func_0204fa4c(source, data_0215eedc[index - 1].values, 25);
}
