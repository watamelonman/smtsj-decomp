#ifndef LIB_02029B78_H
#define LIB_02029B78_H
#include "types.h"

/* This translation unit is the frame texture/palette VRAM manager from
 * NitroSystem. The public reconstruction identifies the five 24-byte texture
 * regions and the three-word palette manager:
 * https://github.com/ctrl-cheeb-del/pokeheartgold/tree/master/lib/NitroSystem/src
 * (gfd_frame_tex_vram_man.c and gfd_frame_pltt_vram_man.c). Linker names stay
 * neutral because config/arm9/symbols.txt is human-owned. */

/** Borrowed frame texture-VRAM region; only head and tail are observed here. */
typedef struct FrmTexVramRegion {
    u32 head;
    u32 tail;
    u32 pad_08[4];
} FrmTexVramRegion;

/** Borrowed frame palette-VRAM allocator; szByte is the configured byte limit. */
typedef struct FrmPlttVramManager {
    u32 lo;
    u32 hi;
    u32 szByte;
} FrmPlttVramManager;

/** Frame palette allocator installed by the geometry initializer. */
typedef u32 (*FrmPlttAllocFn)(u32 szByte, int b4Pltt, u32 bAllocFromLo);
/** Frame palette release callback installed with the allocator. */
typedef s32 (*FrmPlttFreeFn)(u32 key);

/** NNS_GfdFreeFrmTexVram: texture VRAM release; the frame manager has no free list. */
s32 func_02029b78(u32 key);
/** NNS_GfdGetFrmTexVramState: save each texture region's head and tail. */
void func_02029b80(u32 *state);
/** NNS_GfdSetFrmTexVramState: restore each texture region's head and tail. */
void func_02029bc0(const u32 *state);
/** NNS_GfdInitFrmPlttVramManager: set the palette byte limit, reset state and
 * optionally install the default allocator/free pair. */
void func_02029c00(u32 szByte, int useAsDefault);
/** NNS_GfdAllocFrmPlttVram: reserve szByte from the palette range, from the low
 * end when bAllocFromLo is 1 and from the high end otherwise. Returns the
 * packed size/address key, or zero when the request fails. */
u32 func_02029c4c(u32 szByte, int b4Pltt, u32 bAllocFromLo);
/** NNS_GfdFreeFrmPlttVram: palette keys are not recycled, so this returns zero. */
s32 func_02029d88(u32 key);
/** NNS_GfdGetFrmPlttVramState: save the palette allocator's low/high bounds. */
void func_02029d90(FrmPlttVramManager *state);
/** NNS_GfdSetFrmPlttVramState: restore the palette allocator's low/high bounds. */
void func_02029dac(const FrmPlttVramManager *state);
/** NNS_GfdResetFrmPlttVramState: empty the allocator and start high at the limit. */
void func_02029dc8(void);

#endif
