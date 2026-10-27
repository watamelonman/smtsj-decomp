#include "libs/NitroSDK/sdk_02027b1c.h"

/** Default material animation callback, selected by the delinked global. */
extern Sdk027b1cAnmCallback data_0213d378;
/** Dictionary data lookup by name (NNS_G3dGetResDataByName). */
extern void *func_020257ec(const Sdk027b1cDict *, const Sdk027b1cResName *);
/** Dictionary index lookup by name (NNS_G3dGetResDictIdxByName). */
extern int func_020259ac(const Sdk027b1cDict *, const Sdk027b1cResName *);
/** Texture name at a texture dictionary index (NNSi_G3dGetTexPatAnmTexNameByIdx). */
extern const Sdk027b1cResName *func_02025bc0(const Sdk027b1cResTexPatAnm *, u8);
/** Palette name at a palette dictionary index (NNSi_G3dGetTexPatAnmPlttNameByIdx). */
extern const Sdk027b1cResName *func_02025bec(const Sdk027b1cResTexPatAnm *, u8);
/** Frame value for a material index and whole frame (NNSi_G3dGetTexPatAnmFV). */
extern const Sdk027b1cTexPatAnmFV *func_02025c18(const Sdk027b1cResTexPatAnm *, u32, u32);
/** Halfword fill (MI_CpuFill16): value, destination, byte count. */
extern void func_02008644(u32, void *, u32);
/** Signed fixed-point divide used by the public source's FX_Div. */
extern s32 func_0200219c(s32, s32);

#define SDK027B1C_MAPDATA_EXIST 0x0100
#define SDK027B1C_FX32_ONE 4096
#define SDK027B1C_FX32_SHIFT 12
#define SDK027B1C_TEXKEY_ADDR_SHIFT 3
#define SDK027B1C_PLTTKEY_ADDR_SHIFT 3
#define SDK027B1C_TEXFMT_COMP4X4 5
#define SDK027B1C_TEXFMT_SHIFT 26

/** Address encoded in a texture VRAM key; mirrors NNS_GfdGetTexKeyAddr. */
static inline u32 GetTexKeyAddr(u32 key)
{
    return (u32)((0x0000ffff & key) << SDK027B1C_TEXKEY_ADDR_SHIFT);
}

/** Address encoded in a palette VRAM key; mirrors NNS_GfdGetPlttKeyAddr. */
static inline u32 GetPlttKeyAddr(u32 key)
{
    return (u32)((0x0000ffff & key) << SDK027B1C_PLTTKEY_ADDR_SHIFT);
}

/** Dictionary entry name; mirrors NNS_G3dGetResNameByIdx from the public header. */
static inline const Sdk027b1cResName *GetResNameByIdx(const Sdk027b1cDict *dict, u32 idx)
{
    Sdk027b1cDictEntryHeader *hdr;
    if (dict != 0 && idx < dict->numEntry) {
        hdr = (Sdk027b1cDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (const Sdk027b1cResName *)((u8 *)hdr + hdr->ofsName +
                                          sizeof(Sdk027b1cResName) * idx);
    }
    return 0;
}

/** Material block offset by the model header; mirrors NNS_G3dGetMat. */
static inline const Sdk027b1cResMat *GetMat(const Sdk027b1cResMdl *mdl)
{
    if (mdl != 0 && mdl->ofsMat != 0) {
        return (const Sdk027b1cResMat *)((u8 *)mdl + mdl->ofsMat);
    }
    return 0;
}

/** Material index by name; mirrors NNS_G3dGetMatIdxByName. */
static inline int GetMatIdxByName(const Sdk027b1cResMat *mat, const Sdk027b1cResName *name)
{
    if (mat != 0) {
        return func_020259ac(&mat->dict, name);
    }
    return -1;
}

/** Texture data by name; pTex->dict is at +0x3c in the public layout. */
static inline Sdk027b1cDictTexData *GetTexDataByName(const Sdk027b1cResTex *tex,
                                                     const Sdk027b1cResName *name)
{
    if (tex != 0) {
        return (Sdk027b1cDictTexData *)func_020257ec(&tex->dict, name);
    }
    return 0;
}

/** Palette data by name; the palette dictionary is selected by plttInfo.ofsDict. */
static inline Sdk027b1cDictPlttData *GetPlttDataByName(const Sdk027b1cResTex *tex,
                                                       const Sdk027b1cResName *name)
{
    if (tex != 0 && tex->plttInfo.ofsDict != 0) {
        const Sdk027b1cDict *dict =
            (const Sdk027b1cDict *)((const u8 *)tex + tex->plttInfo.ofsDict);
        return (Sdk027b1cDictPlttData *)func_020257ec(dict, name);
    }
    return 0;
}

/* NNSi_G3dAnmObjInitNsBtp: NitroSystem libraries/g3d/src/anm/nsbtp.c.
 * The model's material count sizes the trailing animation-object map. */
void func_02027b1c(Sdk027b1cAnmObj *obj, void *resAnm, const Sdk027b1cResMdl *mdl)
{
    u32 i;
    Sdk027b1cResTexPatAnm *tpAnm = (Sdk027b1cResTexPatAnm *)resAnm;
    const Sdk027b1cResMat *mat = GetMat(mdl);

    obj->funcAnm = data_0213d378;
    obj->numMapData = mdl->info.numMat;
    obj->resAnm = tpAnm;

    func_02008644(0, &obj->mapData[0], sizeof(u16) * obj->numMapData);

    for (i = 0; i < tpAnm->dict.numEntry; ++i) {
        const Sdk027b1cResName *name = GetResNameByIdx(&tpAnm->dict, i);
        int idx = GetMatIdxByName(mat, name);
        if (!(idx < 0)) {
            obj->mapData[idx] = (u16)(i | SDK027B1C_MAPDATA_EXIST);
        }
    }
}

/* SetTexParamaters_: static helper in NitroSystem libraries/g3d/src/anm/nsbtp.c.
 * Chooses the 4x4 or normal texture key and fills the image/size fields. */
void func_02027bf8(const Sdk027b1cResTex *tex, const Sdk027b1cResName *texName, Sdk027b1cMatAnmResult *result)
{
    const Sdk027b1cDictTexData *data = GetTexDataByName(tex, texName);
    u32 vramOffset =
        ((data->texImageParam & 0x1c000000) !=
         (SDK027B1C_TEXFMT_COMP4X4 << SDK027B1C_TEXFMT_SHIFT))
            ? GetTexKeyAddr(tex->texInfo.vramKey) >> SDK027B1C_TEXKEY_ADDR_SHIFT
            : GetTexKeyAddr(tex->tex4x4Info.vramKey) >> SDK027B1C_TEXKEY_ADDR_SHIFT;

    result->prmTexImage &= 0xc00f0000;
    result->prmTexImage |= data->texImageParam + vramOffset;

    result->origWidth = (u16)(data->extraParam & 0x7ff);
    result->origHeight = (u16)((data->extraParam & 0x3ff800) >> 11);

    {
        s32 w = (s32)(data->extraParam & 0x7ff);
        s32 h = (s32)((data->extraParam & 0x3ff800) >> 11);

        result->magW = (w != result->origWidth)
                           ? func_0200219c(w << SDK027B1C_FX32_SHIFT,
                                           result->origWidth << SDK027B1C_FX32_SHIFT)
                           : SDK027B1C_FX32_ONE;
        result->magH = (h != result->origHeight)
                           ? func_0200219c(h << SDK027B1C_FX32_SHIFT,
                                           result->origHeight << SDK027B1C_FX32_SHIFT)
                           : SDK027B1C_FX32_ONE;
    }
}

/* SetPlttParamaters_: static helper in NitroSystem libraries/g3d/src/anm/nsbtp.c.
 * Palette and texture-key offsets are halved for 16-color palettes. */
void func_02027cd0(const Sdk027b1cResTex *tex, const Sdk027b1cResName *plttName, Sdk027b1cMatAnmResult *result)
{
    const Sdk027b1cDictPlttData *data = GetPlttDataByName(tex, plttName);
    u16 plttBase = data->offset;
    u16 vramOffset =
        (u16)(GetPlttKeyAddr(tex->plttInfo.vramKey) >> SDK027B1C_PLTTKEY_ADDR_SHIFT);

    if (!(data->flag & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }

    result->prmTexPltt = (u32)(plttBase + vramOffset);
}

/* NNSi_G3dAnmCalcNsBtp: NitroSystem libraries/g3d/src/anm/nsbtp.c.
 * Frame is signed 20.12 fixed point and is truncated to its whole part. */
void func_02027d38(Sdk027b1cMatAnmResult *result, const Sdk027b1cAnmObj *obj, u32 dataIdx)
{
    const Sdk027b1cResTexPatAnm *patAnm = (const Sdk027b1cResTexPatAnm *)obj->resAnm;
    const Sdk027b1cTexPatAnmFV *fv =
        func_02025c18(patAnm, (u16)dataIdx, (u16)(obj->frame >> SDK027B1C_FX32_SHIFT));

    func_02027bf8(obj->resTex, func_02025bc0(patAnm, fv->idTex), result);

    if (fv->idPltt != 255) {
        func_02027cd0(obj->resTex, func_02025bec(patAnm, fv->idPltt), result);
    }
}
