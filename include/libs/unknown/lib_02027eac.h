#ifndef LIB_02027EAC_H
#define LIB_02027EAC_H
#include "types.h"

/** Joint animation result layout used by the basic and Maya scaling rules. */
typedef struct Unk027eacVec {
    s32 x, y, z;
} Unk027eacVec;

/** Flags at offset zero, then scale, two extended scales, rotation and translation. */
typedef struct Unk027eacJointResult {
    u32 flag;
    Unk027eacVec scale;
    Unk027eacVec scaleEx0;
    Unk027eacVec scaleEx1;
    s32 rot[9];
    Unk027eacVec trans;
} Unk027eacJointResult;

/** Basic rule: copy or mark the local scale and mark both extended scales. */
void func_02027eac(Unk027eacJointResult *result, const s32 *scale,
                   const u8 *command, u32 srtflag);
/** Maya rule: submit the joint transform pieces in command-buffer order. */
void func_02027eec(const Unk027eacJointResult *result);
/** Maya rule: combine local scale, parent inverse scale and identity bits. */
void func_02027fb0(Unk027eacJointResult *result, const s32 *scale,
                   const u8 *command, u32 srtflag);

#endif
