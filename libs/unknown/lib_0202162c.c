/* Adapted from ntrtwl/NitroSystem libraries/g3d/src/kernel.c.
 * Preserve the original linker names while symbol configuration is human-owned. */
#include "libs/unknown/lib_0202162c.h"

/** Registered format signature and initializer; resources remain provider-owned. */
typedef struct {
    u8 category0, reserved;
    u16 category1;
    void (*func)(Animation2162c *, AnimationHeader2162c *, const Model2162c *);
} Initializer2162c;
/** Callback view starts four bytes into the same eight-byte registry entries. */
typedef struct {
    void (*func)(Animation2162c *, AnimationHeader2162c *, const Model2162c *);
    u32 nextSignature;
} InitializerCallback2162c;
extern InitializerCallback2162c data_0213d390[];
extern u32 data_0213d368;
extern Initializer2162c data_0213d38c[];
extern Blend2162c data_0213d388, data_0213d384, data_0213d380;
/** Fill a word-aligned caller buffer with the supplied word for size bytes. */
extern void func_020086a0(u32 value, void *destination, u32 size);

/** Calculate animation storage; identified by the corresponding NitroSystem kernel.c implementation. */
u32 func_0202162c (const AnimationHeader2162c * pAnm, const Model2162c * pMdl)
{
    const AnimationHeader2162c * hdr;

    if (!pAnm || !pMdl)
        return 0;

    hdr = (const AnimationHeader2162c *)pAnm;
    switch (hdr->category0) {
    case 'M':
        return ((sizeof(Animation2162c) + sizeof(u16) * pMdl->numMat) & ~3);
        break;
    case 'J':
    case 'V':
        return ((sizeof(Animation2162c) + sizeof(u16) * pMdl->numNode) & ~3);
        break;
    default:
        return 0;
        break;
    }
}

/** Initialize animation storage; identified by the corresponding NitroSystem kernel.c implementation. */
void func_0202168c (Animation2162c * pAnmObj, AnimationHeader2162c * pResAnm, const Model2162c * pResMdl, const Texture2162c * pResTex)
{
    const AnimationHeader2162c * hdr;
    u32 i;

    pAnmObj->frame = 0;
    pAnmObj->resAnm = pResAnm;

    pAnmObj->next = 0;
    pAnmObj->priority = 127;
    pAnmObj->ratio = 4096;
    pAnmObj->resTex = pResTex;
    pAnmObj->numMapData = 0;
    pAnmObj->funcAnm = 0;

    hdr = (const AnimationHeader2162c *)pResAnm;

    for (i = 0; i < data_0213d368; ++i) {
        if (data_0213d38c[i].category0 == hdr->category0 &&
            data_0213d38c[i].category1 == hdr->category1) {
            if (data_0213d390[i].func) {
                (*data_0213d390[i].func)(pAnmObj, pResAnm, pResMdl);
            }
            break;
        }
    }
}

/** Initialize render state; identified by the corresponding NitroSystem kernel.c implementation. */
void func_0202172c (Render2162c * pRenderObj, Model2162c * pResMdl)
{
    func_020086a0(0, pRenderObj, sizeof(Render2162c));

    pRenderObj->funcBlendMat = data_0213d388;
    pRenderObj->funcBlendJnt = data_0213d384;
    pRenderObj->funcBlendVis = data_0213d380;

    pRenderObj->resMdl = pResMdl;
}

/** Insert an animation chain by priority; identified by the corresponding NitroSystem kernel.c implementation. */
void func_02021780 (Animation2162c ** l, Animation2162c * item)
{
    if (!(*l)) {
        *l = item;
    } else if (!((*l)->next))   {
        if ((*l)->priority > item->priority) {
            Animation2162c * p = item;
            while (p->next) {
                p = p->next;
            }
            p->next = (*l);
            *l = item;
        } else {
            (*l)->next = item;
        }
    } else {
        Animation2162c * p = *l;
        Animation2162c * x = (*l)->next;

        while (x) {
            if (x->priority >= item->priority) {
                Animation2162c * pp = item;
                while (pp->next) {
                    pp = pp->next;
                }
                p->next = item;
                pp->next = x;
                return;
            }
            p = x;
            x = x->next;
        }

        p->next = item;
    }
}

/** Accumulate mapping hints; identified by the corresponding NitroSystem kernel.c implementation. */
void func_02021838 (u32 * pVec, const Animation2162c * pAnmObj)
{
    const Animation2162c * p = pAnmObj;
    while (p) {
        int i;
        for (i = 0; i < p->numMapData; ++i) {
            if (p->mapData[i] & 0x100) {
                pVec[i >> 5] |= 1 << (i & 31);
            }
        }
        p = p->next;
    }
}

/** Attach animation and update hints; identified by the corresponding NitroSystem kernel.c implementation. */
void func_020218a0 (Render2162c * pRenderObj, Animation2162c * pAnmObj)
{
    const AnimationHeader2162c * hdr;

    if (pAnmObj && pAnmObj->resAnm) {
        hdr = (const AnimationHeader2162c *)pAnmObj->resAnm;

        switch (hdr->category0) {
        case 'M':
            func_02021838(&pRenderObj->hintMatAnmExist[0], pAnmObj);
            func_02021780(&pRenderObj->anmMat, pAnmObj);
            break;
        case 'J':
            func_02021838(&pRenderObj->hintJntAnmExist[0], pAnmObj);
            func_02021780(&pRenderObj->anmJnt, pAnmObj);
            break;
        case 'V':
            func_02021838(&pRenderObj->hintVisAnmExist[0], pAnmObj);
            func_02021780(&pRenderObj->anmVis, pAnmObj);
            break;
        default:
            break;
        }
    }
}

