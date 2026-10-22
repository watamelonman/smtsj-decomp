/* src/game/unit_02122850.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk122850Work Unk122850Work;
struct Unk122850Work {
    u32 unk_0000;
    s32 unk_0004;
    u8 pad_0008[0x4];
    void (*unk_000c)(Unk122850Work *self);
    void (*unk_0010)(void);
    void (*unk_0014)(void);
    void (*unk_0018)(u32 *arg);
    void (*unk_001c)(s32 *arg);
    void (*unk_0020)(Unk122850Work *self, u32 *state);
};

void func_021228ac(Unk122850Work *self, u32 *state);
void Unk122850_Unk_12292c(Unk122850Work *arg0);
void Unk122850_Nop_122960(void);
void Unk122850_Nop_122964(void);
void Unk122850_Unk_122968(u32 *arg0);
void Unk122850_Unk_122978(s32 *arg0);

int Unk0bc1a8_IsSlotEmpty();
void Unk0bc1a8_Unk_0bc504();
int Unk_LoadPalette_020de678();
extern u32 data_02176e80[];
int func_0205bb68();
int func_0205ddb4();
extern u8 data_02152044[];
int func_02052634();
int func_0205dcd4();
void Unk05b82c_Unk_05b82c();

/* Fills the work object's callback table with kind 8, state 0 and the six
 * handlers at 0x0c..0x20. Its address is stored in the function table at
 * 0x021503b0 (relocs.txt: load to 0x02122850) next to InitCampBG; nothing
 * else names it, so the name stays neutral. */
void func_02122850(Unk122850Work *self)
{
    self->unk_0000 = 8;
    self->unk_0004 = 0;
    self->unk_000c = Unk122850_Unk_12292c;
    self->unk_0010 = Unk122850_Nop_122960;
    self->unk_0014 = Unk122850_Nop_122964;
    self->unk_0018 = Unk122850_Unk_122968;
    self->unk_001c = Unk122850_Unk_122978;
    self->unk_0020 = func_021228ac;
}

/* Dispatches on the state word at *state (0..4) as installed at +0x20 by
 * func_02122850; only state 1 calls Unk0bc1a8_Unk_0bc504(self, 0). */
void func_021228ac(Unk122850Work *self, u32 *state)
{
    switch (*state) {
    case 0:
        break;
    case 1:
        Unk0bc1a8_Unk_0bc504(self, 0);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

/* Registers the object in data_02176e80, clears its state word, loads the
 * "Camp/camp_BG" resource (data_02152044) with mode 1 via func_0205dcd4 and
 * applies parameters 1/0/31 to func_02052634. */
void Unk122850_InitCampBG(Unk122850Work *self)
{
    *data_02176e80 = (u32)self;
    self->unk_0004 = 0;
    Unk05b82c_Unk_05b82c(0x39, 0);
    self->unk_0000 = func_0205dcd4(data_02152044, 1);
    func_02052634(1, 0, 0x1f);
}

/* Returns unless the state word is nonzero and the probe of slot 0x0c is
 * non-empty, then forwards self and 0 to Unk0bc1a8_Unk_0bc504. */
void Unk122850_Unk_12292c(Unk122850Work *arg0)
{
    int value;
    if (arg0->unk_0004 == 0) {
        return;
    }
    value = Unk0bc1a8_IsSlotEmpty(0xc);
    if (value == 0) {
        return;
    }
    Unk0bc1a8_Unk_0bc504(arg0, 0);
}

/* Empty callback installed at +0x10 by func_02122850. */
void Unk122850_Nop_122960(void) { }

/* Empty callback installed at +0x14 by func_02122850. */
void Unk122850_Nop_122964(void) { }

/* Loads the palette whose handle is the word at *arg0; installed at +0x18. */
void Unk122850_Unk_122968(u32 *arg0)
{
  Unk_LoadPalette_020de678(*arg0);
}

/* Releases the resource handle in *arg0 via func_0205ddb4, calls
 * func_0205bb68, then clears the registered object pointer; installed at +0x1c. */
void Unk122850_Unk_122978(s32 *arg0)
{
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  func_0205bb68();
  *data_02176e80 = 0;
}
