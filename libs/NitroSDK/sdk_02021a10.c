/* Adapted from ntrtwl/NitroSystem libraries/g3d/src/kernel.c.
 * Original linker names are retained until human-owned symbol configuration changes. */
#include "libs/NitroSDK/sdk_02021a10.h"

/** Existing GX providers bracket palette uploads and copy caller-owned bytes. */
extern void func_0200551c(void);
extern void func_02005550(const void *source, u32 address, u32 size);
extern void func_020055bc(void);
/** Existing GX providers borrow upload bytes for synchronous submission. */
extern void func_02005334(void);
extern void func_02005390(const void *source, u32 address, u32 size);
extern void func_020054d0(void);
/** Existing SDK division returns the Q12 ratio of Q12 operands. */
extern s32 func_0200219c(s32 numerator, s32 denominator);
/** Existing dictionary provider returns a borrowed entry matching a 16-byte name. */
extern void *func_020257ec(const Dictionary21a10 *dictionary, const void *name);

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
    struct Header { u16 stride, nameOffset; u8 data[1]; } *header;
    if (dictionary && index < dictionary->count) {
        header = (struct Header *)((u8 *)dictionary + dictionary->dataOffset);
        return (Binding21a10 *)(header->data + header->stride * index);
    }
    return 0;
}

/** SDK material lookup accepts a null model or missing offset and returns null. */
static inline Material21a10 *materialOf(Model21a10 *model)
{
    if (model && model->materialOffset) return (Material21a10 *)((u8 *)model + model->materialOffset);
    return 0;
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

/** NNS_G3dTexLoad in kernel.c; separate payloads and GX calls identify this routine. */
void func_02021a24(Texture21a10 *texture, s32 beginEnd)
{
    if (beginEnd) func_02005334();
    {
        u32 size = (u32)texture->texSize << 3;
        if (size > 0) {
            const void *data = (u8 *)texture + texture->texOffset;
            u32 address = (texture->texKey & 0xffff) << 3;
            func_02005390(data, address, size);
            texture->texFlag |= 1;
        }
    }
    {
        u32 size = (u32)texture->tex4x4Size << 3;
        if (size > 0) {
            const void *data = (u8 *)texture + texture->tex4x4Offset;
            const void *indices = (u8 *)texture + texture->tex4x4IndexOffset;
            u32 address = (texture->tex4x4Key & 0xffff) << 3;
            func_02005390(data, address, size);
            func_02005390(indices, 0x20000 + ((address & 0x1ffff) >> 1) + ((address & 0x40000) >> 2), size >> 1);
            texture->tex4x4Flag |= 1;
        }
    }
    if (beginEnd) func_020054d0();
}

/** Checked SDK material accessor; offsets remain relative to the material block. */
static inline MaterialData21a10 *materialAt(Material21a10 *material, u32 index)
{
    if (material) {
        u32 *offset = (u32 *)bindingAt((Dictionary21a10 *)((u8 *)material + 4), index);
        if (offset) return (MaterialData21a10 *)((u8 *)material + *offset);
    }
    return 0;
}

/** Decode the SDK key's eight-byte address units before binding. */
static inline u32 textureAddress(u32 key)
{
    /* SDK address arithmetic uses unsigned long before conversion to u32. */
    return (u32)((unsigned long)(key & 0xffff) << 3);
}

/** bindMdlTex_Internal_ in kernel.c; texture format selects the VRAM key. */
void func_02021bb4(Material21a10 *material, Binding21a10 *binding, const Texture21a10 *texture, const TextureData21a10 *data)
{
    u8 *base = (u8 *)material + binding->offset;
    u32 vramOffset;
    u32 j;
    if ((data->texImageParam & 0x1c000000) != 0x14000000)
        vramOffset = textureAddress(texture->texKey) >> 3;
    else
        vramOffset = textureAddress(texture->tex4x4Key) >> 3;
    for (j = 0; j < binding->count; ++j) {
        s32 w, h;
        MaterialData21a10 *mat = materialAt(material, base[j]);
        mat->texImageParam |= data->texImageParam + vramOffset;
        w = data->extraParam & 0x7ff;
        h = (data->extraParam & (0x7ff << 11)) >> 11;
        mat->magW = w != mat->origWidth ? func_0200219c(w << 12, mat->origWidth << 12) : 4096;
        mat->magH = h != mat->origHeight ? func_0200219c(h << 12, mat->origHeight << 12) : 4096;
    }
    binding->flag |= 1;
}

/** releaseMdlTex_Internal_ in kernel.c; retain texture transform and repeat bits. */
void func_02021ce4(Material21a10 *material, Binding21a10 *binding)
{
    u8 *base = (u8 *)material + binding->offset;
    u32 j;
    for (j = 0; j < binding->count; ++j) {
        MaterialData21a10 *mat = materialAt(material, base[j]);
        mat->texImageParam &= 0xc00f0000;
        mat->magH = mat->magW = 4096;
    }
    binding->flag &= ~1;
}

/** Borrowed fixed 16-byte SDK resource identifier. */
typedef struct { u32 words[4]; } ResourceName21a10;

/** SDK checked name accessor; names remain dictionary-owned. */
static inline const ResourceName21a10 *nameAt(Dictionary21a10 *dictionary, u32 index)
{
    struct EntryHeader { u16 stride, nameOffset; u8 data[1]; } *header;
    if (dictionary && index < dictionary->count) {
        header = (struct EntryHeader *)((u8 *)dictionary + dictionary->dataOffset);
        return (ResourceName21a10 *)((u8 *)header + header->nameOffset + sizeof(ResourceName21a10) * index);
    }
    return 0;
}

/** SDK null-checked texture dictionary lookup; result remains resource-owned. */
static inline const TextureData21a10 *textureByName(const Texture21a10 *texture, const ResourceName21a10 *name)
{
    if (texture) return func_020257ec((Dictionary21a10 *)((u8 *)texture + 60), name);
    return 0;
}

/** SDK null/offset-checked palette lookup; result remains resource-owned. */
static inline const PaletteData21a10 *paletteByName(const Texture21a10 *texture, const ResourceName21a10 *name)
{
    Dictionary21a10 *dictionary;
    if (texture && texture->plttDictionaryOffset) {
        dictionary = (Dictionary21a10 *)((u8 *)texture + texture->plttDictionaryOffset);
        return func_020257ec(dictionary, name);
    }
    return 0;
}

/** NNS_G3dBindMdlTex in kernel.c; named dictionary lookup supplies each binding. */
s32 func_02021d9c(Model21a10 *model, const Texture21a10 *texture)
{
    Material21a10 *material;
    Dictionary21a10 *dictionary;
    u32 i;
    s32 result = 1;
    material = materialOf(model);
    dictionary = (Dictionary21a10 *)((u8 *)material + material->texDictionaryOffset);
    for (i = 0; i < dictionary->count; ++i) {
        const ResourceName21a10 *name = nameAt(dictionary, i);
        const TextureData21a10 *texData = textureByName(texture, name);
        if (texData) {
            Binding21a10 *data = bindingAt(dictionary, i);
            if (!(data->flag & 1)) func_02021bb4(material, data, texture, texData);
        } else result = 0;
    }
    return result;
}

/** bindMdlPltt_Internal_ in kernel.c; palette format chooses eight/sixteen-byte addressing. */
void func_02021f28(Material21a10 *material, Binding21a10 *binding, const Texture21a10 *texture, const PaletteData21a10 *data)
{
    u8 *base = (u8 *)material + binding->offset;
    u16 plttBase = data->offset;
    u16 vramOffset = (u16)(textureAddress(texture->plttKey) >> 3);
    u32 j;
    if (!(data->flag & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }
    for (j = 0; j < binding->count; ++j) {
        MaterialData21a10 *mat = materialAt(material, base[j]);
        mat->texPlttBase = (u16)(plttBase + vramOffset);
    }
    binding->flag |= 1;
}

/** NNS_G3dBindMdlPltt in kernel.c; palette dictionary offset is texture-relative. */
s32 func_02022008(Model21a10 *model, const Texture21a10 *texture)
{
    Material21a10 *material;
    Dictionary21a10 *dictionary;
    u32 i;
    s32 result = 1;
    material = materialOf(model);
    dictionary = (Dictionary21a10 *)((u8 *)material + material->plttDictionaryOffset);
    for (i = 0; i < dictionary->count; ++i) {
        const ResourceName21a10 *name = nameAt(dictionary, i);
        const PaletteData21a10 *plttData = paletteByName(texture, name);
        if (plttData) {
            Binding21a10 *data = bindingAt(dictionary, i);
            if (!(data->flag & 1)) func_02021f28(material, data, texture, plttData);
        } else result = 0;
    }
    return result;
}

/** SDK checked model-set accessor; models remain owned by the resource. */
static inline Model21a10 *modelAt(ModelSet21a10 *set, u32 index)
{
    if (set) {
        u32 *offset = (u32 *)bindingAt(&set->dictionary, index);
        if (offset) return (Model21a10 *)((u8 *)set + *offset);
    }
    return 0;
}

/** NNS_G3dBindMdlSet in kernel.c; aggregate both binding results for every model. */
s32 func_02022194(ModelSet21a10 *set, const Texture21a10 *texture)
{
    u32 i;
    s32 result = 1;
    for (i = 0; i < set->dictionary.count; ++i) {
        Model21a10 *model = modelAt(set, i);
        result &= func_02021d9c(model, texture);
        result &= func_02022008(model, texture);
    }
    return result;
}

/** NNS_G3dReleaseMdlSet in kernel.c; release both binding classes per model. */
void func_02022244(ModelSet21a10 *set)
{
    u32 i;
    for (i = 0; i < set->dictionary.count; ++i) {
        Model21a10 *model = modelAt(set, i);
        func_02021e9c(model);
        func_02022110(model);
    }
}
