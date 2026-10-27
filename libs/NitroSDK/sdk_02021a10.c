/* Adapted from ntrtwl/NitroSystem libraries/g3d/src/kernel.c.
 * Original linker names are retained until human-owned symbol configuration changes. */
#include "libs/NitroSDK/sdk_02021a10.h"

/** Existing GX providers bracket palette uploads and copy caller-owned bytes. */
extern void func_0200551c(void);
extern void func_02005550(const void *source, u32 address, u32 size);
extern void func_020055bc(void);
/** Existing NitroSystem provider removes one borrowed texture binding. */
extern void func_02021ce4(Material21a10 *material, Binding21a10 *binding);

/** NNS_G3dTexSetTexKey, identified by kernel.c and stores at +8/+24. */
void func_02021a10(Texture21a10 *texture, u32 key, u32 compressedKey)
{
    if (key > 0) texture->texKey = key;
    if (compressedKey > 0) texture->tex4x4Key = compressedKey;
}

/** NNS_G3dTexReleaseTexKey in kernel.c; null outputs preserve the corresponding key. */
void func_02021adc(Texture21a10 *texture, u32 *key, u32 *compressedKey)
{
    if (key) {
        texture->texFlag &= ~1;
        *key = texture->texKey;
        texture->texKey = 0;
    }
    if (compressedKey) {
        texture->tex4x4Flag &= ~1;
        *compressedKey = texture->tex4x4Key;
        texture->tex4x4Key = 0;
    }
}

/** NNS_G3dPlttGetRequiredSize in kernel.c; sizes are stored in eight-byte units. */
u32 func_02021b28(const Texture21a10 *texture)
{
    if (texture) return texture->plttSize << 3;
    return 0;
}

/** NNS_G3dPlttSetPlttKey in kernel.c, identified by the palette key at +44. */
void func_02021b3c(Texture21a10 *texture, u32 key)
{
    texture->plttKey = key;
}

/** NNS_G3dPlttLoad in kernel.c; GX calls and the loaded bit corroborate identification. */
void func_02021b44(Texture21a10 *texture, s32 beginEnd)
{
    if (beginEnd) func_0200551c();
    {
        u32 size = (u32)texture->plttSize << 3;
        const void *data = (u8 *)texture + texture->plttOffset;
        u32 address = (texture->plttKey & 0xffff) << 3;
        func_02005550(data, address, size);
        texture->plttFlag |= 1;
    }
    if (beginEnd) func_020055bc();
}

/** NNS_G3dPlttReleasePlttKey in kernel.c; returns the key without freeing VRAM. */
u32 func_02021b94(Texture21a10 *texture)
{
    u32 result;
    texture->plttFlag &= ~1;
    result = texture->plttKey;
    texture->plttKey = 0;
    return result;
}

/** Match the SDK's checked dictionary access; returned entries remain resource-owned. */
static inline Binding21a10 *bindingAt(Dictionary21a10 *dictionary, u32 index)
{
    if (dictionary && index < dictionary->count) {
        u8 *data = (u8 *)dictionary + dictionary->dataOffset;
        return (Binding21a10 *)(data + 4 + *(u16 *)data * index);
    }
    return 0;
}

/** SDK material lookup accepts a null model or missing offset and returns null. */
static inline Material21a10 *materialOf(Model21a10 *model)
{
    return model && model->materialOffset ? (Material21a10 *)((u8 *)model + model->materialOffset) : 0;
}

/** NNS_G3dReleaseMdlTex in kernel.c; dictionary flags select the release provider. */
void func_02021e9c(Model21a10 *model)
{
    Material21a10 *material;
    Dictionary21a10 *dictionary;
    u32 i;
    material = materialOf(model);
    dictionary = (Dictionary21a10 *)((u8 *)material + material->texDictionaryOffset);
    for (i = 0; i < dictionary->count; ++i) {
        Binding21a10 *data = bindingAt(dictionary, i);
        if (data->flag & 1) func_02021ce4(material, data);
    }
}

/** NNS_G3dReleaseMdlPltt in kernel.c; palette release clears only each loaded bit. */
void func_02022110(Model21a10 *model)
{
    Material21a10 *material;
    Dictionary21a10 *dictionary;
    u32 i;
    material = materialOf(model);
    dictionary = (Dictionary21a10 *)((u8 *)material + material->plttDictionaryOffset);
    for (i = 0; i < dictionary->count; ++i) {
        Binding21a10 *data = bindingAt(dictionary, i);
        if (data->flag & 1) data->flag &= ~1;
    }
}
