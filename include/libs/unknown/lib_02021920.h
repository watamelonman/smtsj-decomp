#ifndef LIBS_UNKNOWN_LIB_02021920_H
#define LIBS_UNKNOWN_LIB_02021920_H

/* Prefix of NitroSystem's animation object; the remaining fields are not accessed here. */
typedef struct G3dAnimationLink {
    int frame;
    int ratio;
    void *resource;
    void *calculate;
    struct G3dAnimationLink *next;
} G3dAnimationLink;

/* Render-object prefix through its three independently linked animation lists. */
typedef struct G3dRenderLists {
    unsigned int flags;
    void *model;
    G3dAnimationLink *material;
    void *blendMaterial;
    G3dAnimationLink *joint;
    void *blendJoint;
    G3dAnimationLink *visibility;
} G3dRenderLists;

/* Texture resource prefix: both size fields count eight-byte units. */
typedef struct G3dTextureSizes {
    unsigned int blockKind;
    unsigned int blockSize;
    unsigned int textureKey;
    unsigned short textureSize;
    unsigned short textureDictionary;
    unsigned short textureFlags;
    unsigned short texturePadding;
    unsigned int textureOffset;
    unsigned int compressedKey;
    unsigned short compressedSize;
} G3dTextureSizes;

/* Unlinks item by identity, clearing its next pointer only on success; head must be valid. */
int func_02021920(G3dAnimationLink **head, G3dAnimationLink *item);
/* Removes a registered animation and invalidates list hints only when found. */
void func_02021994(G3dRenderLists *render, G3dAnimationLink *item);
/* Returns ordinary texture bytes, or zero for a null resource. */
unsigned int func_020219e8(const G3dTextureSizes *texture);
/* Returns compressed texture bytes, or zero for a null resource. */
unsigned int func_020219fc(const G3dTextureSizes *texture);

#endif
