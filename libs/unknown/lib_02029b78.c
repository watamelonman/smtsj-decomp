/* NitroSystem frame texture/palette VRAM manager. The public reconstruction
 * (gfd_frame_tex_vram_man.c and gfd_frame_pltt_vram_man.c, linked from the
 * header) matches these instructions; callers are the NitroSDK G3D geometry
 * setup and the resource wrapper func_020587fc. Linker names remain neutral
 * because the symbol configuration is human-owned. */

#include "libs/unknown/lib_02029b78.h"

/** Five frame texture-VRAM regions, owned by the GFD texture manager. */
extern FrmTexVramRegion data_0213d610[];
/** Frame palette VRAM manager (low bound, high bound, configured size). */
extern FrmPlttVramManager data_02159ca0;
/** Default palette allocation callback. */
extern FrmPlttAllocFn data_0213d5ec;
/** Default palette release callback. */
extern FrmPlttFreeFn data_0213d5f0;
/** NNS_GfdFreeFrmTexVram: the frame texture manager has no reusable free list,
 * so every release succeeds without touching the regions. */
s32 func_02029b78(u32 key)
{
    return 0;
}

/** NNS_GfdGetFrmTexVramState: copies the head and tail of each of the five
 * texture regions into the caller's ten-word state block. */
void func_02029b80(u32 *state)
{
    s32 i;

    for (i = 0; i < 5; i++) {
        state[i * 2] = data_0213d610[i].head;
        state[i * 2 + 1] = data_0213d610[i].tail;
    }
}

/** NNS_GfdSetFrmTexVramState: restores the head and tail of each of the five
 * texture regions from the caller's ten-word state block. */
void func_02029bc0(const u32 *state)
{
    s32 i;

    for (i = 0; i < 5; i++) {
        data_0213d610[i].head = state[i * 2];
        data_0213d610[i].tail = state[i * 2 + 1];
    }
}

/** NNS_GfdInitFrmPlttVramManager: records the palette byte limit, resets the
 * allocator bounds, then installs the default alloc/free pair when requested. */
void func_02029c00(u32 szByte, int useAsDefault)
{
    data_02159ca0.szByte = szByte;
    func_02029dc8();
    if (useAsDefault != 0) {
        data_0213d5ec = func_02029c4c;
        data_0213d5f0 = func_02029d88;
    }
}

/** NNS_GfdAllocFrmPlttVram's lo-side path: bump the low bound while keeping
 * the requested alignment (8 bytes for palette, 16 for texture). Palette
 * allocations may not cross the 0x10000 byte VRAM limit. Returns 1 on success
 * and writes the aligned address to *pAddr. */
static inline s32 AllocFromLo(u32 *pAddr, u32 szByte, int b4Pltt)
{
    u32 lo = data_02159ca0.lo;
    u32 pad = b4Pltt ? ((8 - (lo & 7)) & 7) : ((16 - (lo & 15)) & 15);
    u32 need = szByte + pad;

    if (data_02159ca0.hi - lo >= need) {
        u32 end = lo + need;

        if (b4Pltt && end > 0x10000) {
            return 0;
        }
        *pAddr = lo + pad;
        data_02159ca0.lo += need;
        return 1;
    }
    return 0;
}

/** NNS_GfdAllocFrmPlttVram's hi-side path: take the block below the high
 * bound after aligning its start, then lower the bound. The palette limit
 * check mirrors the lo-side path. Returns 1 on success and writes the
 * aligned address to *pAddr. */
static inline s32 AllocFromHi(u32 *pAddr, u32 szByte, int b4Pltt)
{
    u32 hi = data_02159ca0.hi;
    u32 pad;
    u32 need;

    if (hi >= szByte) {
        pad = b4Pltt ? ((hi - szByte) & 7) : ((hi - szByte) & 15);
        need = szByte + pad;
        if (hi - data_02159ca0.lo >= need) {
            if (b4Pltt && hi > 0x10000) {
                return 0;
            }
            data_02159ca0.hi -= need;
            *pAddr = data_02159ca0.hi;
            return 1;
        }
    }
    return 0;
}

/** NNS_GfdAllocFrmPlttVram: rounds the request up to eight bytes (zero means
 * eight), rejects anything at or above the 0x7FFF8 byte VRAM ceiling, and
 * allocates from the low or high end of the palette range. The returned key
 * packs the rounded size and the eight-byte-unit address, or zero on failure;
 * zero is the documented NNS_GFD_ALLOC_ERROR_PLTTKEY value. */
u32 func_02029c4c(u32 szByte, int b4Pltt, u32 bAllocFromLo)
{
    u32 addr = 0;
    s32 result;

    szByte = (szByte == 0) ? 8 : ((szByte + 7) & ~7);
    if (szByte >= 0x7FFF8) {
        return 0;
    }
    if (bAllocFromLo == 1) {
        result = AllocFromLo(&addr, szByte, b4Pltt);
    } else {
        result = AllocFromHi(&addr, szByte, b4Pltt);
    }
    if (!result) {
        return 0;
    }
    return ((szByte >> 3) << 16) | ((addr >> 3) & 0xffff);
}

/** NNS_GfdFreeFrmPlttVram: frame palette keys are never recycled. */
s32 func_02029d88(u32 key)
{
    return 0;
}

/** NNS_GfdGetFrmPlttVramState: saves the palette allocator's low and high
 * bounds into caller-owned storage. */
void func_02029d90(FrmPlttVramManager *state)
{
    state->lo = data_02159ca0.lo;
    state->hi = data_02159ca0.hi;
}

/** NNS_GfdSetFrmPlttVramState: restores the palette allocator's low and high
 * bounds from caller-owned storage. */
void func_02029dac(const FrmPlttVramManager *state)
{
    data_02159ca0.lo = state->lo;
    data_02159ca0.hi = state->hi;
}

/** NNS_GfdResetFrmPlttVramState: empties the allocator by moving the low bound
 * to zero and the high bound to the configured byte limit. */
void func_02029dc8(void)
{
    data_02159ca0.lo = 0;
    data_02159ca0.hi = data_02159ca0.szByte;
}
