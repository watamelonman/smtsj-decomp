#include "libs/NitroSDK/sdk_0200454c.h"

extern s32 data_0213ce44;
extern void func_02007fb0(u32 channel, const void *source, void *destination, u32 size);
extern void func_0200866c(const void *source, void *destination, u32 size);

#define MATRIX_MULT33 (*(volatile u32 *)0x04000468)

/* G3_RotX: the 0x04000468 FIFO receives the X-axis matrix, as in NitroSDK G3_RotZ. */
void func_0200454c(u32 sine, u32 cosine)
{
    MATRIX_MULT33 = 4096;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = cosine;
    MATRIX_MULT33 = sine;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = -sine;
    MATRIX_MULT33 = cosine;
}

/* G3_RotY: the 0x04000468 FIFO receives the Y-axis matrix; see the reference in the TU doc. */
void func_02004588(u32 sine, u32 cosine)
{
    MATRIX_MULT33 = cosine;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = -sine;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = 4096;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = sine;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = cosine;
}

/* G3_RotZ: identical matrix ordering to nitro-decomp/nitro src/gx/g3.c. */
void func_020045c4(u32 sine, u32 cosine)
{
    MATRIX_MULT33 = cosine;
    MATRIX_MULT33 = sine;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = -sine;
    MATRIX_MULT33 = cosine;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = 0;
    MATRIX_MULT33 = 4096;
}

/* Texture mode (3) at 0x04000440 and LOAD_4x4 at +0x18 identify the command.
 * The final two rows are scaled by sixteen for texture coordinate units. */
void func_02004600(const Sdk0454cMatrix44 *matrix)
{
    volatile u32 *commands = (volatile u32 *)0x04000440;
    commands[0] = 3;
    commands[6] = matrix->element[0];
    commands[6] = matrix->element[1];
    commands[6] = matrix->element[2];
    commands[6] = matrix->element[3];
    commands[6] = matrix->element[4];
    commands[6] = matrix->element[5];
    commands[6] = matrix->element[6];
    commands[6] = matrix->element[7];
    commands[6] = matrix->element[8] << 4;
    commands[6] = matrix->element[9] << 4;
    commands[6] = matrix->element[10] << 4;
    commands[6] = matrix->element[11] << 4;
    commands[6] = matrix->element[12] << 4;
    commands[6] = matrix->element[13] << 4;
    commands[6] = matrix->element[14] << 4;
    commands[6] = matrix->element[15] << 4;
}

/* GX_LoadBGPltt: NitroSDK gx_load.c uses DMA above 28 bytes unless disabled (-1). */
void func_020046b4(const void *source, u32 offset, u32 size)
{
    if (data_0213ce44 != -1 && size > 28) {
        func_02007fb0(data_0213ce44, source, (void *)(0x05000000 + offset), size);
    } else {
        func_0200866c(source, (void *)(0x05000000 + offset), size);
    }
}

/* GXS_LoadBGPltt: the +0x400 palette base selects the sub engine (NitroSDK gx_load.c). */
void func_02004708(const void *source, u32 offset, u32 size)
{
    if (data_0213ce44 != -1 && size > 28) {
        func_02007fb0(data_0213ce44, source, (void *)(0x05000000 + (offset + 0x400)), size);
    } else {
        func_0200866c(source, (void *)(0x05000000 + (offset + 0x400)), size);
    }
}
