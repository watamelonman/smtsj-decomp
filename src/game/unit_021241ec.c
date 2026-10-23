/*
 * src/game/unit_021241ec.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void Unk0fedd4_Unk_0fedd4(void);
void Unk0fedd4_Thunk_0205bb68(void);
void Unk0fedd4_Alloc(u32 selector);
void Unk0fedd4_Unk_0fee18(void);
void Unk0fedd4_SetUnk0c10(u32 value0c, u32 value10);
void Unk0fedd4_SetUnk1c(u32 value);
void func_02124338(void);

void Unk1241ec_Thunk_02124338(void);
void Unk1241ec_Unk_124214(void);
void Unk1241ec_Unk_1241ec(void);

/** Forward to the initializer; the branch at 0x0212424c identifies the target. */
void Unk1241ec_Thunk_02124338(void) { func_02124338(); }

/** Run the two teardown helpers in the order observed at 0x02124214. */
void Unk1241ec_Unk_124214(void)
{
  Unk0fedd4_Unk_0fee18();
  Unk0fedd4_Thunk_0205bb68();
}

/** Initialize the shared object with selector 1, fields (0, 43), and field 0x1c = 5.
 * Evidence: the four calls and immediate arguments at 0x021241ec.
 */
void Unk1241ec_Unk_1241ec(void)
{
  Unk0fedd4_Unk_0fedd4();
  Unk0fedd4_Alloc(1);
  Unk0fedd4_SetUnk0c10(0,0x2b);
  Unk0fedd4_SetUnk1c(5);
}


extern u8 *data_02176e84;
int func_02061424();
int func_020cb3dc();
int Unk0cb32c_Unk_0cb4e4();
void Unk0fedd4_Unk_0fee38();
/** Forward the current byte selector and x + 200 (truncated to 16 bits). */
void Unk1241ec_Unk_124224(int x)
{
    Unk0fedd4_Unk_0fee38(Unk0cb32c_Unk_0cb4e4((u8)func_020cb3dc(), (u16)(x + 200)));
}

/** Release the optional work allocation and clear its borrowed global pointer. */
void Unk1241ec_Unk_124258(void)
{
  if (data_02176e84 == 0) {
    return;
  }
  func_02061424();
  data_02176e84 = 0;
}

/** Store an unrestricted word at work offset 0x28, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x02124284; the field meaning is unknown.
 */
void Unk1241ec_Unk_124284(u32 arg0)
{
  if (data_02176e84 != 0) {
    *(u32 *)(data_02176e84 + 0x28) = arg0;
  }
}

/** Store an unrestricted word at work offset 0x2c, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x0212429c; the field meaning is unknown.
 */
void Unk1241ec_Unk_12429c(u32 arg0)
{
  if (data_02176e84 != 0) {
    *(u32 *)(data_02176e84 + 0x2c) = arg0;
  }
}

/** Store an unrestricted word at work offset 0x30, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x021242b4; the field meaning is unknown.
 */
void Unk1241ec_Unk_1242b4(u32 arg0)
{
  if (data_02176e84 != 0) {
    *(u32 *)(data_02176e84 + 0x30) = arg0;
  }
}

/** Store an unrestricted word at work offset 0x34, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x021242cc; the field meaning is unknown.
 */
void Unk1241ec_Unk_1242cc(u32 arg0)
{
  if (data_02176e84 != 0) {
    *(u32 *)(data_02176e84 + 0x34) = arg0;
  }
}

/** Store an unrestricted word at work offset 0x38, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x021242e4; the field meaning is unknown.
 */
void Unk1241ec_Unk_1242e4(u32 arg0)
{
  if (data_02176e84 != 0) {
    *(u32 *)(data_02176e84 + 0x38) = arg0;
  }
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

/** Reset four work words when allocated, preserving the original store order. */
void Unk1241ec_Unk_1242fc(void)
{
    if (data_02176e84 == 0) {
        return;
    }
    FIELD(u32, data_02176e84, 40) = 1;
    FIELD(u32, data_02176e84, 44) = 0;
    FIELD(u32, data_02176e84, 60) = 1;
    FIELD(u32, data_02176e84, 56) = 0;
}
