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

/* Resolves token operands through the borrowed slots: the comparisons and
 * calls at 0204fb38 establish these mappings; other operands pass through.
 * Tokens use signed comparisons in the original secondary dispatch.
 */
u32 func_0204fb38(int token, u32 operand)
{
    if (token == 0x806c) {
        switch (operand) {
        case 1: return func_0204fb14(1);
        case 2: return func_0204fb14(2);
        case 3: return func_0204fb14(3);
        case 4: return func_0204fb14(4);
        case 5: return func_0204fb14(5);
        default: return 0;
        }
    }
    switch (operand) {
    case 0x8001: return func_0204fb14(1);
    case 0x8002: return func_0204fb14(2);
    case 0x8003: return func_0204fb14(3);
    case 0x8004: return func_0204fb14(4);
    case 0x8005: return func_0204fb14(5);
    default: return operand;
    case 0x8006:
        switch (token) {
        case 0x8067: return func_0204fb14(8);
        case 0x8068: return func_0204fb14(6);
        case 0x8069: return func_0204fb14(7);
        case 0x806a: return func_0204fb14(10);
        case 0x806b: return func_0204fb14(9);
        case 0x801f: return func_0204fb14(11);
        default: return operand;
        }
    }
}

/* Copies at most capacity halfwords and always terminates the final slot.
 * The loads/stores at 0204fa4c require readable source through its first zero
 * or capacity, and writable halfword before destination + capacity, even for capacity zero.
 */
void func_0204fa4c(const u16 *source, u16 *destination, u32 capacity)
{
    u32 i;
    for (i = 0; i < capacity; i++) {
        u16 value = source[i];
        if (value == 0) {
            destination[i] = 0;
            break;
        }
        destination[i] = value;
    }
    (destination + capacity)[-1] = 0;
}
