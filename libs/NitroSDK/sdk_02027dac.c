#include "libs/NitroSDK/sdk_02027dac.h"

extern Sdk027dacVisCallback data_0213d36c;
/** Geometry buffer consumes count 32-bit parameters for the given command. */
extern void func_020252fc(unsigned int command, const int *parameters, unsigned int count);

/* NNSi_G3dAnmObjInitNsBva: NitroSystem libraries/g3d/src/anm/nsbva.c.
 * The model's node count requires equally many writable trailing map entries. */
void func_02027dac(Sdk027dacAnmObj *obj, const Sdk027dacVisResource *resource, const Sdk027dacModel *model)
{
    unsigned int i;
    obj->funcAnm = data_0213d36c;
    obj->numMapData = model->numNode;
    obj->resAnm = resource;
    for (i = 0; i < obj->numMapData; ++i) {
        obj->mapData[i] = (unsigned short)(i | 0x100);
    }
}

/* NNSi_G3dAnmCalcNsBva: NitroSystem libraries/g3d/src/anm/nsbva.c.
 * Frame is signed 20.12 fixed point; output retains the visibility bit mask. */
void func_02027df8(Sdk027dacVisResult *result, const Sdk027dacAnmObj *obj, unsigned int dataIdx)
{
    unsigned int frame = (unsigned int)(obj->frame >> 12);
    const Sdk027dacVisResource *resource = obj->resAnm;
    unsigned int pos = frame * resource->numNode + dataIdx;
    unsigned int n = pos >> 5;
    unsigned int mask = 1U << (pos & 31);
    result->isVisible = resource->visData[n] & mask;
}

/* NNSi_G3dSendJointSRTBasic: NitroSystem libraries/g3d/src/cgtool/basic.c.
 * Flags 4/2/1 denote zero translation/rotation and unit scale respectively. */
void func_02027e30(const Sdk027dacJointResult *result)
{
    if (!(result->flag & 4)) {
        if (!(result->flag & 2)) {
            func_020252fc(25, result->rot, 12);
        } else {
            func_020252fc(28, result->trans, 3);
        }
    } else {
        if (!(result->flag & 2)) {
            func_020252fc(26, result->rot, 9);
        }
    }
    if (!(result->flag & 1)) {
        func_020252fc(27, result->scale, 3);
    }
}
