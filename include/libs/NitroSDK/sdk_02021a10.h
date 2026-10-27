#ifndef SDK_02021A10_H
#define SDK_02021A10_H
#include "types.h"
/** Borrowed texture resource prefix; keys encode eight-byte VRAM addresses. */
typedef struct {
    u32 signature, size;
    u32 texKey; u16 texSize, texReserved, texFlag, texReserved2; u32 texOffset;
    u32 tex4x4Key; u16 tex4x4Size, tex4x4Reserved, tex4x4Flag, tex4x4Reserved2;
    u32 tex4x4Offset, tex4x4IndexOffset;
    u32 plttKey; u16 plttSize, plttFlag; u32 plttReserved, plttOffset;
} Texture21a10;
/** Borrowed model prefix; materialOffset is relative to this resource. */
typedef struct { u32 size, nodeOffset, materialOffset; } Model21a10;
/** Borrowed material prefix; dictionary offsets are relative to this block. */
typedef struct { u16 texDictionaryOffset, plttDictionaryOffset; } Material21a10;
/** Borrowed resource dictionary; dataOffset locates stride and entry data.
 * Volatile count preserves the original accessor reads; see DEC-042. */
typedef struct { u8 revision; volatile u8 count; u16 size, reserved, dataOffset; } Dictionary21a10;
/** Borrowed four-byte material binding entry, followed by model-owned indices. */
typedef struct { u16 offset; u8 count, flag; } Binding21a10;
/** Assign nonzero texture keys without transferring resource ownership. */
void func_02021a10(Texture21a10 *texture, u32 key, u32 compressedKey);
/** Release selected texture keys into caller-owned output words. */
void func_02021adc(Texture21a10 *texture, u32 *key, u32 *compressedKey);
/** Return required palette bytes, or zero for a null resource. */
u32 func_02021b28(const Texture21a10 *texture);
/** Assign the palette key to a caller-owned resource. */
void func_02021b3c(Texture21a10 *texture, u32 key);
/** Upload palette bytes; nonzero beginEnd brackets the GX load. */
void func_02021b44(Texture21a10 *texture, s32 beginEnd);
/** Clear the loaded palette flag and return its former key. */
u32 func_02021b94(Texture21a10 *texture);
/** Release every active texture binding in a borrowed model. */
void func_02021e9c(Model21a10 *model);
/** Clear every active palette binding in a borrowed model. */
void func_02022110(Model21a10 *model);
#endif
