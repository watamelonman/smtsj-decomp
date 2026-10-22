/* src/game/unit_0203b988.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int func_0204fb14();
/* Reads selection 0, applies it through func_0204fb14, then runs the
 * unit 03aae8 callback; reports success (1). */
u32 Unk03b988_Unk_03b9b8(void)
{
  u16 value;
  value = func_0203ac00(0);
  func_0204fb14(value);
  Unk03aae8_Unk_03acf4();
  return 1;
}

int Unk0e651c_Unk_0e666c();
void Unk118b04_Set_data_02151b28();
void Unk02dcfc_SetCode25();
int Unk09e72c_Unk_09e72c();
int func_020df330();
int Unk116598_Unk_116700();
int Unk116598_Unk_117968();
int ImageBgDual3D_Unk_1259c4();

/* Returns 3 after dispatching on the current mode; also writes the mode's
 * save-data flag (0x404/0x405) when the active party index is 12. */
int func_0203b9dc(void)
{
    int index = func_0203ac00(0);

    if (index == 12) {
        if (Unk0e651c_Unk_0e666c(0x404)) {
            Unk118b04_Set_data_02151b28(0);
        } else if (Unk0e651c_Unk_0e666c(0x405)) {
            Unk118b04_Set_data_02151b28(2);
        } else {
            Unk118b04_Set_data_02151b28(1);
        }
    }
    switch (func_02095818()) {
    case 0:
        Unk09e72c_Unk_09e72c(index);
        break;
    case 2:
        func_020df330(index);
        break;
    case 3:
        Unk116598_Unk_116700(index);
        break;
    case 4:
        Unk116598_Unk_117968(index);
        break;
    case 5:
        ImageBgDual3D_Unk_1259c4(index);
        break;
    default:
        return 3;
    }
    Unk02dcfc_SetCode25();
    return 3;
}

int func_0204faf0();
/* Reads selections 0 and 1 and passes both to func_0204faf0;
 * reports success (1). */
u32 Unk03b988_Unk_03b988(void)
{
  u16 value1;
  u32 value2;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  func_0204faf0(value1,value2);
  return 1;
}

int func_02095818();
int Unk0de678_Unk_0df348();
void Unk02dcfc_SetCode25();
int Unk116598_Unk_116738();
void Unk0e651c_Unk_0e66f0();
/* Reads selection 0 and, for modes 2 and 3, forwards it through the
 * matching Unk0de678/Unk116598 helper into Unk02dcfc_SetCode25; returns 3. */
int Unk03b988_Unk_03bab4(void)
{
    int x = func_0203ac00(0);
    switch (func_02095818()) {
    case 2:
        Unk02dcfc_SetCode25(Unk0de678_Unk_0df348(x));
        break;
    case 3:
        Unk02dcfc_SetCode25(Unk116598_Unk_116738(x));
        break;
    }
    return 3;
}

/* Reads selections 0 and 1 and forwards selection 1 plus the low byte of
 * (selection 0 - 1) to Unk0e651c_Unk_0e66f0; reports success (1). */
int Unk03b988_Call_0e66f0(void)
{
    int a = func_0203ac00(0);
    Unk0e651c_Unk_0e66f0(func_0203ac00(1), (u8)(a - 1));
    return 1;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_020baba4();
int Unk11fc20_Unk_11fc94();
void Unk11fc20_Unk_11fc48();
void func_020babc8();
void func_020babb4();
void Unk11fc20_Unk_11fc20();
u32 Unk03aae8_Unk_03ad14(void);

/* Reads selections 0..4. When func_020baba4() is set, restores the
 * Unk11fc20 state and returns 1; otherwise clears it, stores 27 at offset
 * +24 of the object from Unk03aae8_Unk_03ad14()+232, and returns 0. */
int Unk03b988_Unk_03bb2c(void)
{
    func_0203ac00(0);
    func_0203ac00(1);
    func_0203ac00(2);
    func_0203ac00(3);
    func_0203ac00(4);
    if (func_020baba4() != 0) {
        Unk03aae8_Unk_03acf4(Unk11fc20_Unk_11fc94());
        Unk11fc20_Unk_11fc48();
        func_020babc8();
        return 1;
    }
    func_020babb4();
    Unk03aae8_Unk_03acf4(0);
    Unk11fc20_Unk_11fc20();
    {
        u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
        FIELD(u32, o, 24) = 27;
    }
    return 0;
}
