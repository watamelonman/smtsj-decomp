#ifndef SDK_02027B1C_H
#define SDK_02027B1C_H

#include "types.h"

/** Borrowed NitroSystem dictionary header (NNSG3dResDict). */
typedef struct Sdk027b1cDict Sdk027b1cDict;
typedef struct Sdk027b1cDictNode {
    u8 refBit;
    u8 idxLeft;
    u8 idxRight;
    u8 idxEntry;
} Sdk027b1cDictNode;

struct Sdk027b1cDict {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
    Sdk027b1cDictNode node[1];
};

/** Dictionary entry table; names start at hdr + ofsName. */
typedef struct Sdk027b1cDictEntryHeader {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} Sdk027b1cDictEntryHeader;

/** Sixteen-byte resource key shared by every dictionary name. */
typedef union Sdk027b1cResName {
    char name[16];
    u32 val[4];
} Sdk027b1cResName;

/** Animation object prefix; the caller owns the trailing map entries.
 *  Layout matches NNSG3dAnmObj in nnsys/g3d/kernel.h. */
typedef struct Sdk027b1cAnmObj Sdk027b1cAnmObj;
typedef void (*Sdk027b1cAnmCallback)(void *, const Sdk027b1cAnmObj *, u32);

struct Sdk027b1cAnmObj {
    s32 frame;
    s32 ratio;
    void *resAnm;
    Sdk027b1cAnmCallback funcAnm;
    Sdk027b1cAnmObj *next;
    const struct Sdk027b1cResTex *resTex;
    u8 priority;
    u8 numMapData;
    u16 mapData[1];
};

/** Model header through the material count; layout mirrors NNSG3dResMdl. */
typedef struct Sdk027b1cMdlInfo {
    u8 sbcType;
    u8 scalingRule;
    u8 texMtxMode;
    u8 numNode;
    u8 numMat;
    u8 numShp;
    u8 firstUnusedMtxStackID;
    u8 dummy_;
} Sdk027b1cMdlInfo;

typedef struct Sdk027b1cResMdl {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u32 ofsShp;
    u32 ofsEvpMtx;
    Sdk027b1cMdlInfo info;
} Sdk027b1cResMdl;

/** Material resource prefix; the dictionary starts after the two list offsets. */
typedef struct Sdk027b1cResMat {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    Sdk027b1cDict dict;
} Sdk027b1cResMat;

/** Texture/palette animation header; the dictionary follows the name offsets.
 *  Layout matches NNSG3dResTexPatAnm in nnsys/g3d/binres/res_struct.h. */
typedef struct Sdk027b1cAnmHeader {
    u8 category0;
    u8 revision;
    u16 category1;
} Sdk027b1cAnmHeader;

typedef struct Sdk027b1cResTexPatAnm {
    Sdk027b1cAnmHeader anmHeader;
    u16 numFrame;
    u8 numTex;
    u8 numPltt;
    u16 ofsTexName;
    u16 ofsPlttName;
    Sdk027b1cDict dict;
} Sdk027b1cResTexPatAnm;

/** One texture/palette frame value selected by the animation frame. */
typedef struct Sdk027b1cTexPatAnmFV {
    u16 idxFrame;
    u8 idTex;
    u8 idPltt;
} Sdk027b1cTexPatAnmFV;

/** Texture record returned by the texture dictionary. */
typedef struct Sdk027b1cDictTexData {
    u32 texImageParam;
    u32 extraParam;
} Sdk027b1cDictTexData;

/** Palette record returned by the palette dictionary. */
typedef struct Sdk027b1cDictPlttData {
    u16 offset;
    u16 flag;
} Sdk027b1cDictPlttData;

/** Texture and palette key/size blocks; dict starts at byte 0x3c. */
typedef struct Sdk027b1cResTexInfo {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
} Sdk027b1cResTexInfo;

typedef struct Sdk027b1cResTex4x4Info {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
    u32 ofsTexPlttIdx;
} Sdk027b1cResTex4x4Info;

typedef struct Sdk027b1cResPlttInfo {
    u32 vramKey;
    u16 sizePltt;
    u16 flag;
    u16 ofsDict;
    u16 dummy_;
    u32 ofsPlttData;
} Sdk027b1cResPlttInfo;

typedef struct Sdk027b1cResTex {
    u32 header;
    u32 headerSize;
    Sdk027b1cResTexInfo texInfo;
    Sdk027b1cResTex4x4Info tex4x4Info;
    Sdk027b1cResPlttInfo plttInfo;
    Sdk027b1cDict dict;
} Sdk027b1cResTex;

/** Material animation result; only texture image/palette and size fields are used. */
typedef struct Sdk027b1cMatAnmResult {
    u32 flag;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmTexImage;
    u32 prmTexPltt;
    s32 scaleS;
    s32 scaleT;
    s16 sinR;
    s16 cosR;
    s32 transS;
    s32 transT;
    u16 origWidth;
    u16 origHeight;
    s32 magW;
    s32 magH;
} Sdk027b1cMatAnmResult;

/** Install the texture/palette animation callback and map its dictionary names
 *  onto material indices. Caller allocates numMapData trailing map entries. */
void func_02027b1c(Sdk027b1cAnmObj *, void *, const Sdk027b1cResMdl *);
/** Write the texture image parameters for one texture/palette animation value. */
void func_02027bf8(const Sdk027b1cResTex *, const Sdk027b1cResName *,
                   Sdk027b1cMatAnmResult *);
/** Write the palette base for one texture/palette animation value. */
void func_02027cd0(const Sdk027b1cResTex *, const Sdk027b1cResName *,
                   Sdk027b1cMatAnmResult *);
/** Sample a valid material index and frame; the resource must cover both. */
void func_02027d38(Sdk027b1cMatAnmResult *, const Sdk027b1cAnmObj *, u32);

#endif
