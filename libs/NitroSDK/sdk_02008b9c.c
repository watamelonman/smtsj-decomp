#include "types.h"

extern void func_02008284(u32 channel, u32 timing);
extern void func_02008308(u32 channel, u32 source, u32 size, u32 source_mode);
extern void func_01ff8480(u32 channel, u32 source, u32 destination, u32 control);

/* MIi_CardDmaCopy32, identified by pret/pokediamond's MI_dma_card.c and
 * the card DMA control word 0xaf000001. Source/destination remain borrowed;
 * size is in bytes and a zero-sized request only performs conflict checks. */
void func_02008d60(u32 channel, const void *source, void *destination, u32 size)
{
    volatile u32 *control;
    func_02008284(channel, ~0U);
    func_02008308(channel, (u32)source, size, 0x01000000);
    if (size == 0) {
        return;
    }
    control = &((volatile u32 *)0x040000b0)[channel * 3 + 2];
    while (*control & 0x80000000) {
    }
    func_01ff8480(channel, (u32)source, (u32)destination, 0xaf000001);
}
