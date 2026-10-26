#ifndef LIB_020296B8_H
#define LIB_020296B8_H
#include "types.h"

/** Material-animation view; fixed-point fields use twelve fractional bits. */
typedef struct Unk0296b8Material {
    u32 flags;
    u32 parameters[5];
    s32 scaleS, scaleT;
    s16 sinR, cosR;
    s32 transS, transT;
    u16 origWidth, origHeight;
    s32 magW, magH;
} Unk0296b8Material;

/** Four-column texture matrix, with signed fixed-point components. */
typedef struct Unk0296b8Matrix {
    s32 m00, m01, m02, m03;
    s32 m10, m11, m12, m13;
    s32 m20, m21, m22, m23;
    s32 m30, m31, m32, m33;
} Unk0296b8Matrix;

/** Fill the scale-only texture matrix fields; other fields belong to the caller. */
void func_020296b8(Unk0296b8Matrix *matrix, const Unk0296b8Material *material);
/** Fill identity scale and zero translation fields; preserve the remaining fields. */
void func_020296f8(Unk0296b8Matrix *matrix);
/** Submit a texture matrix; normalizes flagged material fields in place. */
void func_0202971c(Unk0296b8Material *material);
/** Return the constant zero; no input or side effects are observed. */
s32 func_020298a4(void);
/** Return the constant minus one; no input or side effects are observed. */
s32 func_020298ac(void);
/** Return the constant zero; no input or side effects are observed. */
s32 func_020298b4(void);
#endif
