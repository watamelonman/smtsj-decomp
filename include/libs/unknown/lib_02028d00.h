#ifndef LIB_02028D00_H
#define LIB_02028D00_H
#include "types.h"

/** Caller-owned 4x4 fixed-point matrix; helpers write only texture SRT entries. */
typedef struct TextureMatrix028d00 {
    s32 _00, _01, _02, _03;
    s32 _10, _11, _12, _13;
    s32 _20, _21, _22, _23;
    s32 _30, _31, _32, _33;
} TextureMatrix028d00;

/** Borrowed NitroSystem material animation prefix; scales/translations use 12 fractional bits. */
typedef struct MaterialAnimation028d00 {
    u32 flag, prmMatColor0, prmMatColor1, prmPolygonAttr, prmTexImage, prmTexPltt;
    s32 scaleS, scaleT;
    s16 sinR, cosR;
    s32 transS, transT;
    u16 origWidth, origHeight;
    s32 magW, magH;
} MaterialAnimation028d00;

/** Build the unit-scale 3ds Max texture SRT entries in caller-owned storage. */
void func_02028d00(TextureMatrix028d00 *m, const MaterialAnimation028d00 *anm);
/** Build the zero-rotation 3ds Max texture SRT entries in caller-owned storage. */
void func_02028de8(TextureMatrix028d00 *m, const MaterialAnimation028d00 *anm);
/** Build translation-only 3ds Max texture entries in caller-owned storage. */
void func_02028e68(TextureMatrix028d00 *m, const MaterialAnimation028d00 *anm);
/** Build zero-translation 3ds Max texture SRT entries in caller-owned storage. */
void func_02028eb0(TextureMatrix028d00 *m, const MaterialAnimation028d00 *anm);
#endif
