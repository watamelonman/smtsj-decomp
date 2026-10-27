#ifndef LIB_02029470_H
#define LIB_02029470_H
#include "libs/unknown/lib_020296b8.h"

/* All outputs are caller-owned: only m00/m01/m10/m11/m30/m31 are written.
 * Inputs use Q12 arithmetic; intermediate products must be representable. */
/** Build scale/translation entries with rotation fixed to identity. */
void func_02029470(Unk0296b8Matrix *out, const Unk0296b8Material *srt);
/** Build translation entries with scale and rotation fixed to identity. */
void func_020294f4(Unk0296b8Matrix *out, const Unk0296b8Material *srt);
/** Build scale/rotation entries; both texture dimensions must be nonzero. */
void func_02029548(Unk0296b8Matrix *out, const Unk0296b8Material *srt);
/** Build rotation entries with unit scale; dimensions must be nonzero. */
void func_02029614(Unk0296b8Matrix *out, const Unk0296b8Material *srt);
#endif
