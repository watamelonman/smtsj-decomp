/* src/game/unit_020f81a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* set u32 at +0x98 */
void func_020f824c(void *obj, u32 value) { FIELD(u32, obj, 0x98) = value; }


/* set u32 at +0x9c */
void func_020f8254(void *obj, u32 value) { FIELD(u32, obj, 0x9c) = value; }


/* set u32 at +0xa0 */
void func_020f825c(void *obj, u32 value) { FIELD(u32, obj, 0xa0) = value; }

int func_0204afe0();
/* decompiler-derived */
void func_020f81a4(int arg0)
{
  func_0204afe0(arg0,*(u32 *)(arg0 + 0x84));
  return;
}


/* decompiler-derived */
int func_020f81b4(int arg0)
{
  return *(int *)(arg0 + 0x84) != -1;
}
