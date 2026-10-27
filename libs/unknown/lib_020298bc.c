/* NitroSystem GFD frame texture manager, reconstructed public source:
 * https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/gfd_frame_tex_vram_man.c
 * The region layouts, search order and packed keys identify these routines. */
#include "libs/unknown/lib_020298bc.h"

extern FrameTextureRegion *data_0213d5f4[];
extern FrameTextureRegion data_0213d610[5];
extern u16 data_02159c9c;
extern u32 (*data_0213d5e4)(u32, int, u32);
extern s32 (*data_0213d5e8)(u32);
extern s32 func_02029b78(u32 key);

/** Unidentified adjacent failure callback: assembly returns -1 unconditionally. */
s32 func_020298bc(void)
{
    return -1;
}

/** NNSi_GfdSetTexNrmSearchArray: set normal search priority (public source above). */
void func_020298c4(int first, int second, int third, int fourth, int fifth) {
    FrameTextureRegion *regions = data_0213d610;
    (&data_0213d5f4[2])[0] = &regions[first];
    (&data_0213d5f4[2])[1] = &regions[second];
    (&data_0213d5f4[2])[2] = &regions[third];
    (&data_0213d5f4[2])[3] = &regions[fourth];
    (&data_0213d5f4[2])[4] = &regions[fifth];
}

/** NNS_GfdInitFrmTexVramManager: configure slots and defaults (public source above). */
void func_0202990c(u16 numSlot, int useAsDefault) {
    if (numSlot <= 2) {
        func_020298c4(4, 3, 2, 0, 1);
    } else {
        func_020298c4(4, 3, 0, 2, 1);
    }
    data_02159c9c = numSlot;
    func_02029994();
    if (useAsDefault) {
        data_0213d5e4 = func_02029a08;
        data_0213d5e8 = func_02029b78;
    }
}

/** NNS_GfdResetFrmTexVramState: reset borrowed region bounds (public source above). */
void func_02029994(void) {
    int i = 0;
    FrameTextureRegion *region = data_0213d610;
    u32 numActive = data_02159c9c;
    if (numActive > 1) {
        numActive++;
    }
    for (i = 0; i < 5; i++, region++) {
        if (i < (int)numActive) {
            region->active = 1;
        } else {
            region->active = 0;
        }
        if (region->is4x4Region) {
            region->head = 0;
            region->tail = 0x10000;
        } else {
            region->head = 0;
            region->tail = 0x20000;
        }
    }
}

