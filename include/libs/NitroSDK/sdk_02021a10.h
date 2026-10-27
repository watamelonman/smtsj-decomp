#ifndef SDK_02021A10_H
#define SDK_02021A10_H
#include "types.h"
/** Borrowed texture resource prefix; keys encode eight-byte VRAM addresses. */
typedef struct {
    u32 signature, size;
    u32 texKey; u16 texSize, texReserved, texFlag, texReserved2; u32 texOffset;
    u32 tex4x4Key; u16 tex4x4Size, tex4x4Reserved, tex4x4Flag, tex4x4Reserved2;
    u32 tex4x4Offset, tex4x4IndexOffset;
    u32 plttKey; u16 plttSize, plttFlag; u16 plttDictionaryOffset, plttReserved; u32 plttOffset;
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
/** Borrowed material record; dimensions are pixels and magnification is Q12. */
typedef struct {
    u8 prefix[20]; u32 texImageParam, texMask; u16 texPlttBase, flag;
    u16 origWidth, origHeight; s32 magW, magH;
} MaterialData21a10;
/** Borrowed texture dictionary entry, including original pixel dimensions. */
typedef struct { u32 texImageParam, extraParam; } TextureData21a10;
/** Borrowed palette entry; offset is in eight-byte units. */
typedef struct { u16 offset, flag; } PaletteData21a10;
/** Borrowed model-set resource with its embedded dictionary. */
typedef struct { u32 signature, size; Dictionary21a10 dictionary; } ModelSet21a10;
/** Upload texture payloads; beginEnd brackets the GX load when nonzero. */
void func_02021a24(Texture21a10 *texture, s32 beginEnd);
/** Bind one texture entry to the material indices owned by the resource. */
void func_02021bb4(Material21a10 *material, Binding21a10 *binding, const Texture21a10 *texture, const TextureData21a10 *data);
/** Clear one texture binding and restore Q12 unit magnification. */
void func_02021ce4(Material21a10 *material, Binding21a10 *binding);
/** Bind named textures; return zero if any resource name is missing. */
s32 func_02021d9c(Model21a10 *model, const Texture21a10 *texture);
/** Bind one palette entry to the resource-owned material indices. */
void func_02021f28(Material21a10 *material, Binding21a10 *binding, const Texture21a10 *texture, const PaletteData21a10 *data);
/** Bind named palettes; return zero if any resource name is missing. */
s32 func_02022008(Model21a10 *model, const Texture21a10 *texture);
/** Bind textures and palettes for all models, returning aggregate success. */
s32 func_02022194(ModelSet21a10 *set, const Texture21a10 *texture);
/** Release texture and palette bindings for all models in a borrowed set. */
void func_02022244(ModelSet21a10 *set);
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
