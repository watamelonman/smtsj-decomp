/* src/game/unit_020f81a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* set u32 at +0x98 */
void Unk0f81a4_SetUnkField98(void *obj, u32 value) { FIELD(u32, obj, 0x98) = value; }


/* set u32 at +0x9c */
void Unk0f81a4_SetUnkField9c(void *obj, u32 value) { FIELD(u32, obj, 0x9c) = value; }


/* set u32 at +0xa0 */
void Unk0f81a4_SetUnkFielda0(void *obj, u32 value) { FIELD(u32, obj, 0xa0) = value; }

int func_0204afe0();
/* decompiler-derived */
void Unk0f81a4_Unk_0f81a4(int arg0)
{
  func_0204afe0(arg0,*(u32 *)(arg0 + 0x84));
  return;
}


/* decompiler-derived */
int Unk0f81a4_Unk_0f81b4(int arg0)
{
  return *(int *)(arg0 + 0x84) != -1;
}

