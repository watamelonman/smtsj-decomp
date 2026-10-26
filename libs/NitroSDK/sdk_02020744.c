#include "libs/NitroSDK/sdk_02020744.h"

/** Binary-block prefix; the animation bank starts immediately after these two words. */
typedef struct Unk02020794Block {
    u32 signature;
    u32 size;
} Unk02020794Block;

/** Search the file for a block signature; returns null if absent. */
extern Unk02020794Block *func_02020b0c(void *file, u32 signature);
/** Resolve the bank's file-relative offsets in place. */
extern void func_020207dc(Unk02020794Bank *bank);

/** Restore saved bounds and pop the selected record and any newer records.
 * Evidence: 020206f4 saves tag/bounds/previous at offsets 0/4/8/12.
 * Also corresponds to pret/pokediamond's NNS_FndFreeByStateToFrmHeap
 * in arm9/asm/NNS_FND_frameheap.s; original link symbols are retained.
 */
int func_02020744(Unk02020744Heap *heap, u32 tag)
{
    Unk02020744Record *record = heap->saved;
    if (tag != 0 && record != 0) {
        do {
            if (record->tag == tag) {
                break;
            }
            record = record->previous;
        } while (record != 0);
    }
    if (record == 0) {
        return 0;
    }
    heap->start = record->start;
    heap->end = record->end;
    heap->saved = record->previous;
    return 1;
}

/** Load the ABNK payload in place, or clear the output on failure.
 * Evidence: pret/pokediamond arm9/asm/NNS_G2D_g2d_nan_load.s,
 * GetUnpackedAnimBankImpl_ uses the same signature and eight-byte header.
 */
int func_02020794(void *file, Unk02020794Bank **bank)
{
    Unk02020794Block *block = func_02020b0c(file, 0x41424e4b);
    if (block == 0) {
        *bank = 0;
        return 0;
    }
    func_020207dc((Unk02020794Bank *)(block + 1));
    *bank = (Unk02020794Bank *)(block + 1);
    return 1;
}

/** Forward the public loader call; pokediamond's NNS_G2dGetUnpackedAnimBank
 * likewise tail-calls GetUnpackedAnimBankImpl_ (same source cited above).
 */
int func_020207d0(void *file, Unk02020794Bank **bank)
{
    return func_02020794(file, bank);
}
