#ifndef LIB_0202162C_H
#define LIB_0202162C_H
#include "types.h"

/** Borrowed animation header; category fields select the format initializer. */
typedef struct { u8 category0, reserved; u16 category1; } AnimationHeader2162c;
/** Borrowed model prefix; counts bound the caller-owned animation mapping. */
typedef struct { u8 reserved[23]; u8 numNode, numMat; } Model2162c;
/** Opaque borrowed texture resource, retained by the animation provider. */
typedef struct Texture2162c Texture2162c;
/** Caller-owned variable-size animation object; mapData extends to numMapData. */
typedef struct Animation2162c {
    s32 frame, ratio;
    AnimationHeader2162c *resAnm;
    void *funcAnm;
    struct Animation2162c *next;
    const Texture2162c *resTex;
    u8 priority, numMapData;
    u16 mapData[1];
} Animation2162c;
/** Blend providers operate on borrowed results and animation chains. */
typedef s32 (*Blend2162c)(void *result, const Animation2162c *animation, u32 id);
/** Caller-owned 84-byte render state; hint bits cover 64 IDs per category. */
typedef struct {
    u32 flag;
    Model2162c *resMdl;
    Animation2162c *anmMat;
    Blend2162c funcBlendMat;
    Animation2162c *anmJnt;
    Blend2162c funcBlendJnt;
    Animation2162c *anmVis;
    Blend2162c funcBlendVis;
    u8 reserved[28];
    u32 hintMatAnmExist[2], hintJntAnmExist[2], hintVisAnmExist[2];
} Render2162c;
/** Required bytes, including mapping entries and four-byte alignment; null yields zero. */
u32 func_0202162c(const AnimationHeader2162c *animation, const Model2162c *model);
/** Initialize caller-owned storage, then dispatch to its registered format provider. */
void func_0202168c(Animation2162c *object, AnimationHeader2162c *animation, const Model2162c *model, const Texture2162c *texture);
/** Clear render state and install the provider-owned default blend callbacks. */
void func_0202172c(Render2162c *render, Model2162c *model);
/** Splice a caller-owned chain into the priority-ordered list without allocation. */
void func_02021780(Animation2162c **list, Animation2162c *item);
/** Accumulate existing mapping IDs in caller-owned hint words across the chain. */
void func_02021838(u32 *bits, const Animation2162c *animation);
/** Attach a borrowed animation chain to its category and update category hints. */
void func_020218a0(Render2162c *render, Animation2162c *animation);
#endif
