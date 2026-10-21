/*
 * unit_020b7898: two small hooks with no direct callers. Their addresses sit in
 * consecutive words of a function-pointer table at 0x0213d6f8 (entries 0 and 1;
 * entry 2 points at 0x020b78d8 in the next TU), so they are callbacks of one
 * table-driven object.
 */
#include "types.h"

void func_02052634(int a, int b, int c);
void Unk111400_Unk_111474(int a, int b, int c);
void func_02111494(void);
void Unk02cad4_Unk_02cbdc(u32 arg0);

/*
 * Table entry 0: forwards the constant arguments (1, 0, 31) to func_02052634.
 * 31 is the largest 5-bit value (the DS brightness/alpha range), but the callee
 * is not decompiled yet, so the meaning of the arguments is unconfirmed.
 */
void Unk0b7898_Call_02052634(void) { func_02052634(1, 0, 31); }

/*
 * Table entry 1: calls Unk111400_Unk_111474(4, 0xC03, 0) and func_02111494(),
 * then stores 1 in data_0213d338.unk_08 through Unk02cad4_Unk_02cbdc.
 */
void Unk0b7898_Unk_0b78b0(void) {
    Unk111400_Unk_111474(4, 0xc03, 0);
    func_02111494();
    Unk02cad4_Unk_02cbdc(1);
}
