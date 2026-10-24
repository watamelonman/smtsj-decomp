/*
 * src/game/unit_021241ec.c: matched functions (see docs/functions/game-unit-021241ec.md).
 * Field meanings of the work struct are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
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

/** Tail-forward to func_02124338 (branch at 0x0212424c). */
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


/* Work block behind data_02176e84. Size 0x40 comes from the allocation in func_02124338. */
typedef struct Unk1241ecWork {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008[4];
    u32 unk_0018;
    u32 unk_001c;
    s32 unk_0020;
    u32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
    u32 unk_0038;
    u32 unk_003c;
} Unk1241ecWork;

extern Unk1241ecWork *data_02176e84;
int func_02061424();
int func_020cb3dc();
int Unk0cb32c_Unk_0cb4e4();
void Unk0fedd4_Unk_0fee38();
/** Forward the current byte selector and x + 200 (truncated to 16 bits). */
void Unk1241ec_Unk_124224(int x)
{
    Unk0fedd4_Unk_0fee38(Unk0cb32c_Unk_0cb4e4((u8)func_020cb3dc(), (u16)(x + 200)));
}

/** Release the optional work allocation and clear its global pointer. */
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
    data_02176e84->unk_0028 = arg0;
  }
}

/** Store an unrestricted word at work offset 0x2c, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x0212429c; the field meaning is unknown.
 */
void Unk1241ec_Unk_12429c(u32 arg0)
{
  if (data_02176e84 != 0) {
    data_02176e84->unk_002c = arg0;
  }
}

/** Store an unrestricted word at work offset 0x30, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x021242b4; the field meaning is unknown.
 */
void Unk1241ec_Unk_1242b4(u32 arg0)
{
  if (data_02176e84 != 0) {
    data_02176e84->unk_0030 = arg0;
  }
}

/** Store an unrestricted word at work offset 0x34, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x021242cc; the field meaning is unknown.
 */
void Unk1241ec_Unk_1242cc(u32 arg0)
{
  if (data_02176e84 != 0) {
    data_02176e84->unk_0034 = arg0;
  }
}

/** Store an unrestricted word at work offset 0x38, if the work pointer exists.
 * Evidence: conditional STR in the function at 0x021242e4; the field meaning is unknown.
 */
void Unk1241ec_Unk_1242e4(u32 arg0)
{
  if (data_02176e84 != 0) {
    data_02176e84->unk_0038 = arg0;
  }
}

/** Reset four work words when allocated, preserving the original store order. */
void Unk1241ec_Unk_1242fc(void)
{
    if (data_02176e84 == 0) {
        return;
    }
    data_02176e84->unk_0028 = 1;
    data_02176e84->unk_002c = 0;
    data_02176e84->unk_003c = 1;
    data_02176e84->unk_0038 = 0;
}

extern u32 data_0213cdc0[4];
void Unk02e000_Unk_02e0cc(void);
extern u8 data_021520a4[];
extern u8 data_021520bc[];
void func_02124538(void);
void Unk12449c_Unk_124590(void);
void func_021245bc(void);
void Unk12449c_Unk_12449c(void);
Unk1241ecWork *func_020611dc(void (*a)(void), void (*b)(void), void (*c)(void), void (*d)(void),
                             u32 size, u32 e, u32 f, u32 g);
int Unk044394_HasEntry(int id);
u32 Unk044394_Unk_044428(int id);
void Unk05b82c_Unk_05b82c(u32 id);
u32 func_0205dcd4(const void *data, u32 mode);
u32 func_0205c2c4(const void *data);
u32 func_0205c3c0(void);
void func_0205c3fc(u32 handle, u32 a, u32 b);
void func_0205caa8(u32 handle, u32 index);
u32 func_020629ac(u32 a, u32 b, u32 c, u32 d);
void Unk0cb32c_Unk_0cb504(u32 handle, u32 selector, u32 c);

/** Allocate the 0x40-byte work block with four callbacks from the next TU, load its resources,
 * set its defaults, then publish it in data_02176e84 (cleared first, left 0 on failure).
 * Evidence: the call sequence and stores at 0x02124338; field meanings are unknown.
 */
void func_02124338(void)
{
    Unk1241ecWork *w;
    u32 i;
    int j;

    data_02176e84 = 0;
    w = func_020611dc(func_02124538, Unk12449c_Unk_124590, func_021245bc, Unk12449c_Unk_12449c,
                      64, 0, 0, 1);
    if (w == 0) {
        return;
    }
    w->unk_0024 = Unk044394_HasEntry(30) ? 0 : Unk044394_Unk_044428(30);
    Unk02e000_Unk_02e0cc();
    for (i = 0; i < 4; i++) {
        Unk05b82c_Unk_05b82c(data_0213cdc0[i]);
    }
    w->unk_0000 = func_0205dcd4(data_021520a4, 1);
    w->unk_0004 = func_0205c2c4(data_021520bc);
    for (j = 0; j < 4; j++) {
        w->unk_0008[j] = func_0205c3c0();
        func_0205c3fc(w->unk_0008[j], w->unk_0000, w->unk_0004);
        func_0205caa8(w->unk_0008[j], j);
    }
    w->unk_0018 = func_020629ac(5, 1, 1, 1);
    Unk0cb32c_Unk_0cb504(w->unk_0018, (u8)func_020cb3dc(), 0);
    w->unk_001c = 0;
    w->unk_0020 = -192;
    w->unk_0028 = 1;
    w->unk_002c = 1;
    w->unk_0030 = 1;
    w->unk_0038 = 1;
    w->unk_0034 = 0;
    w->unk_003c = 0;
    data_02176e84 = w;
}
