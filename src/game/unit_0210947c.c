/* src/game/unit_0210947c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* set u32 at +0x5c */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk10947cWork {
    u8 pad_0000[0x5c];
    u32 unk_005c;
} Unk10947cWork;

void Unk10947c_SetUnkField5c(void *obj, u32 value) { ((Unk10947cWork *)obj)->unk_005c = value; }

void func_021099fc(void);
/* forwards to `func_021099fc` */
void Unk10947c_Thunk_021099fc(void) { func_021099fc(); }
