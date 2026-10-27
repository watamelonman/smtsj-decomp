#ifndef LIB_02028578_H
#define LIB_02028578_H
#include "types.h"
#include "libs/unknown/lib_020296b8.h"

/* Layout of the joint animation result submitted by the Maya SRT sender. The
 * offsets are the ones the original instructions use: flag at 0, the local
 * scale at 4, the parent inverse scale at 16, an extra scale at 28, the 3x3
 * rotation at 40 and the translation at 76. All fixed-point values use twelve
 * fractional bits. The view is borrowed for the duration of the call. */
typedef struct Unk028578Vec {
    s32 x, y, z;
} Unk028578Vec;

typedef struct Unk028578JointResult {
    u32 flag;
    Unk028578Vec scale;
    Unk028578Vec scaleEx0;
    Unk028578Vec scaleEx1;
    s32 rot[9];
    Unk028578Vec trans;
} Unk028578JointResult;

/** Write the identity texture matrix; the remaining entries stay untouched. */
void func_02028578(Unk0296b8Matrix *matrix);
/** Build and submit a material's texture matrix, applying texel magnification. */
void func_0202859c(const Unk0296b8Material *material);
/** Submit a Maya joint's translation, rotation and scale commands. */
void func_020286e4(const Unk028578JointResult *result);

#endif
