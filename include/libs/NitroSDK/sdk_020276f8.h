#ifndef SDK_020276F8_H
#define SDK_020276F8_H
#include "types.h"
#include "libs/unknown/lib_02028d00.h"

typedef s32 fx32;
typedef s16 fx16;
#define FX32_ONE 4096
#define FX_Whole(x) ((x) >> 12)
#define NNS_G3D_TEXSRTANM_ELEM_CONST 0x20000000
#define NNS_G3D_TEXSRTANM_ELEM_STEP_MASK 0xc0000000
#define NNS_G3D_TEXSRTANM_ELEM_STEP_2 0x40000000
#define NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_MASK 0xffff
#define NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_SHIFT 0
#define NNS_G3D_TEXSRTANM_ELEM_FX16 0x10000000
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE 1
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO 2
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO 4
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET 8
#define NNS_G3D_ANMOBJ_MAPDATA_EXIST 0x100
#define REG_G3_TEXIMAGE_PARAM_TGEN_MASK 0xc0000000
#define REG_G3_TEXIMAGE_PARAM_TGEN_SHIFT 30
#define GX_TEXGEN_TEXCOORD 1

/** Borrowed dictionary prefix; entry/name offsets are relative to their owning headers. */
typedef struct {
    u8 revision, numEntry;
    u16 sizeDict, dummy, ofsEntry;
} NNSG3dResDict;
/** Borrowed variable-length dictionary payload, with byte stride sizeUnit. */
typedef struct {
    u16 sizeUnit, ofsName;
    u8 data[1];
} NNSG3dResDictEntryHeader;
/** Fixed 16-byte resource name, owned by its dictionary. */
typedef struct { char name[16]; } NNSG3dResName;
/** Borrowed texture SRT animation; track data offsets are relative to this resource. */
typedef struct {
    u32 anmHeader;
    u16 numFrame;
    u8 flag, texMtxMode;
    NNSG3dResDict dict;
} NNSG3dResTexSRTAnm;
/** Five texture tracks, each encoded by flags plus a constant or resource-relative offset. */
typedef struct {
    u32 scaleS, scaleSEx, scaleT, scaleTEx, rot, rotEx;
    u32 transS, transSEx, transT, transTEx;
} NNSG3dResDictTexSRTAnmData;
typedef MaterialAnimation028d00 NNSG3dMatAnmResult;
typedef u32 NNSG3dMatAnmResultFlag;
/** Borrowed model-material prefix; dictionary follows the four-byte header. */
typedef struct { u32 header; NNSG3dResDict dict; } NNSG3dResMat;
/** Borrowed model prefix sufficient for its material offset and material count. */
typedef struct {
    u32 size, ofsNode, ofsMat;
    u8 pad_0c[12];
    struct { u8 numMat; } info;
} NNSG3dResMdl;
/** Caller-owned animation object with trailing numMapData halfwords. Resource is borrowed. */
typedef struct NNSG3dAnmObj {
    fx32 frame, ratio;
    void *resAnm;
    void *funcAnm;
    struct NNSG3dAnmObj *next;
    const void *resTex;
    u8 priority, numMapData;
    u16 mapData[1];
} NNSG3dAnmObj;

/** Registry callback slot remains owned by the animation kernel. */
extern void *data_0213d374;
#define NNS_G3dFuncAnmMatNsBtaDefault data_0213d374
/** Fill an even byte count in caller-owned aligned halfword storage. */
void func_02008644(u16 value, void *dst, u32 size);
#define MI_CpuClear16(dst, size) func_02008644(0, dst, size)
/** Find the material's dictionary name; returns a negative index when absent. */
int func_020259ac(const NNSG3dResDict *dict, const NNSG3dResName *name);

/** Return borrowed entry storage, or 0 for an invalid dictionary/index. */
static inline void *NNS_G3dGetResDataByIdx(const NNSG3dResDict *dict, u32 idx)
{
    NNSG3dResDictEntryHeader *hdr;
    if (dict != 0 && idx < dict->numEntry) {
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return &hdr->data[0] + hdr->sizeUnit * idx;
    } else return 0;
}
/** Return a borrowed fixed-size name, or 0 for an invalid dictionary/index. */
static inline const NNSG3dResName *NNS_G3dGetResNameByIdx(const NNSG3dResDict *dict, u32 idx)
{
    NNSG3dResDictEntryHeader *hdr;
    if (dict != 0 && idx < dict->numEntry) {
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (NNSG3dResName *)((u8 *)hdr + hdr->ofsName + sizeof(NNSG3dResName) * idx);
    } else return 0;
}
/** Borrow the optional material block from its model-relative offset. */
static inline NNSG3dResMat *NNS_G3dGetMat(const NNSG3dResMdl *mdl)
{
    if (mdl && mdl->ofsMat != 0) return (NNSG3dResMat *)((u8 *)mdl + mdl->ofsMat);
    else return 0;
}
/** Preserve the SDK's negative result for models without materials. */
static inline int NNS_G3dGetMatIdxByName(const NNSG3dResMat *mat, const NNSG3dResName *name)
{
    if (mat) return func_020259ac(&mat->dict, name);
    else return -1;
}
/** Evaluate a scalar track in Q12 at a whole frame index. */
fx32 func_020276f8(const NNSG3dResTexSRTAnm *, u32 info, u32 data, u32 frame);
/** Evaluate packed sine/cosine Q12 halfwords at a whole frame index. */
u32 func_020277f8(const NNSG3dResTexSRTAnm *, u32 info, u32 data, u32 frame);
/** Write the indexed SRT tracks and identity flags into caller-owned result storage. */
void func_02027904(const NNSG3dResTexSRTAnm *, u16 idx, u32 frame, NNSG3dMatAnmResult *);
/** Initialize material mappings; object must contain enough trailing map halfwords. */
void func_02027a04(NNSG3dAnmObj *, void *resource, const NNSG3dResMdl *);
/** Apply the current whole frame to caller-owned result storage. */
void func_02027ad8(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32 dataIdx);
#endif
