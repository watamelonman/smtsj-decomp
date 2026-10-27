#ifndef LIB_02028FA8_H
#define LIB_02028FA8_H
#include "libs/unknown/lib_020296b8.h"

/* The texture-matrix views and the material layout are shared with the
 * neighbouring XSI texture-matrix unit. All outputs are caller-owned: only
 * m00/m01/m10/m11/m30/m31 are written, so the caller must initialize the
 * remaining matrix entries. The fixed-point products must stay representable
 * in the declared intermediates; rotating variants require nonzero texture
 * dimensions and exclusive use of the SDK hardware divider until its result
 * has been retrieved. */
/** Build rotation entries with unit scale and zero input translation. */
void func_02028fa8(Unk0296b8Matrix *out, const Unk0296b8Material *srt);
/** Build scale entries with rotation fixed to identity and zero translation. */
void func_02029080(Unk0296b8Matrix *out, const Unk0296b8Material *srt);
/** Write unit scale and zero off-diagonal/translation entries. */
void func_020290d0(Unk0296b8Matrix *out);
/** Submit a texture matrix and apply the material's texel magnification. */
void func_020290f4(Unk0296b8Material *material);
#endif
