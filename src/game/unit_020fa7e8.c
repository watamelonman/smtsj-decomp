/* Work-state reset, callback setup and indexed lookup helpers. */
#include "types.h"



/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0faa84(void) { }


/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0fae70(void) { }


/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0fae74(void) { }


/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0fae78(void) { }

u32 func_020445f4(u32 resource, u32 index);
u32 func_0204fed8(u32 resource, u32 value);
/* Forward the supplied value with resource 0x25, entry zero (original call operands). */
void Unk0fa7e8_Unk_0fb108(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x25,0);
  func_0204fed8(value,arg0);
}

void func_020655b4(u32 value);
void func_02065604(u32 value);
void func_02065bc0(void);
/* Reset the observed fields of a writable 0x30-byte work area, then reset three helpers.
 * Offset 4 and bytes 0x1c..0x27 are deliberately preserved by the original. */
void Unk0fa7e8_Unk_0fa7e8(u32 *arg0)
{
  *arg0 = 0;
  arg0[3] = 0;
  *(u16 *)(arg0 + 10) = 0;
  arg0[2] = 0;
  arg0[0xb] = 0;
  *(u8 *)(arg0 + 4) = 0;
  *(u8 *)((int)arg0 + 0x11) = 0;
  *(u8 *)((int)arg0 + 0x12) = 0;
  *(u8 *)((int)arg0 + 0x13) = 0;
  *(u8 *)(arg0 + 5) = 0;
  *(u8 *)((int)arg0 + 0x15) = 0;
  *(u8 *)((int)arg0 + 0x16) = 0;
  *(u8 *)((int)arg0 + 0x17) = 0;
  *(u8 *)(arg0 + 6) = 0;
  *(u8 *)((int)arg0 + 0x19) = 0;
  *(u8 *)((int)arg0 + 0x1a) = 0;
  *(u8 *)((int)arg0 + 0x1b) = 0;
  func_02065604(0);
  func_02065bc0();
  func_020655b4(0);
}

int Unk095560_Unk_0957c0(u32 value);
/* Query the word at +0x10 + i*4; use ID 0x259 if the first query returns zero.
 * The caller must supply a valid indexed word in p. */
int Unk0fa7e8_Unk_0fb0e0(u8 *p, int i)
{
    int r = Unk095560_Unk_0957c0(FIELD(u32, p + i * 4, 16));
    if (r != 0) {
        return r;
    }
    return Unk095560_Unk_0957c0(0x259);
}

/* Callback addresses are stored, rather than called, by the descriptor initializer. */
void func_020faa88(void);
void func_020fae7c(void);

/* Descriptor layout follows the stores in func_020fa84c; field +8 is preserved. */
typedef struct Unk0fa7e8Descriptor {
    u32 size;
    u32 field04;
    u32 field08;
    void (*callbacks[6])(void);
} Unk0fa7e8Descriptor;

/* Initialize a writable descriptor with work size 0x30 and the six original callbacks.
 * Evidence: original literal relocations identify every callback address. */
void func_020fa84c(Unk0fa7e8Descriptor *descriptor)
{
    descriptor->size = 0x30;
    descriptor->field04 = 0;
    descriptor->callbacks[0] = func_020faa88;
    descriptor->callbacks[1] = Unk0fa7e8_Nop_0faa84;
    descriptor->callbacks[2] = Unk0fa7e8_Nop_0fae70;
    descriptor->callbacks[3] = Unk0fa7e8_Nop_0fae74;
    descriptor->callbacks[4] = Unk0fa7e8_Nop_0fae78;
    descriptor->callbacks[5] = func_020fae7c;
}
