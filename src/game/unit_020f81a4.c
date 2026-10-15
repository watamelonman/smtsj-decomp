/* src/game/unit_020f81a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* set u32 at +0x98 */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0f81a4Work {
    u8 pad_0000[0x84];
    u32 unk_0084;
    u8 pad_0088[0x10];
    u32 unk_0098;
    u32 unk_009c;
    u32 unk_00a0;
} Unk0f81a4Work;

void Unk0f81a4_SetUnkField98(void *obj, u32 value) { ((Unk0f81a4Work *)obj)->unk_0098 = value; }


/* set u32 at +0x9c */
void Unk0f81a4_SetUnkField9c(void *obj, u32 value) { ((Unk0f81a4Work *)obj)->unk_009c = value; }


/* set u32 at +0xa0 */
void Unk0f81a4_SetUnkFielda0(void *obj, u32 value) { ((Unk0f81a4Work *)obj)->unk_00a0 = value; }

int func_0204afe0();
/* decompiler-derived */
void Unk0f81a4_Unk_0f81a4(int arg0)
{
  func_0204afe0(arg0,((Unk0f81a4Work *)arg0)->unk_0084);
  return;
}


/* decompiler-derived */
int Unk0f81a4_Unk_0f81b4(int arg0)
{
  return ((Unk0f81a4Work *)arg0)->unk_0084 != -1;
}

