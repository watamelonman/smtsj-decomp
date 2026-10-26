#ifndef SDK_02020744_H
#define SDK_02020744_H

#include "types.h"

/** Saved allocation bounds; the preceding routine at 020206f4 builds this chain. */
typedef struct Unk02020744Record {
    u32 tag;
    void *start;
    void *end;
    struct Unk02020744Record *previous;
} Unk02020744Record;

/** Partial heap view: only the bounds and saved-state head are accessed here. */
typedef struct Unk02020744Heap {
    u8 unknown[0x24];
    void *start;
    void *end;
    Unk02020744Record *saved;
} Unk02020744Heap;

/** Opaque animation bank; unpacking owns interpretation of its internal offsets. */
typedef struct Unk02020794Bank Unk02020794Bank;

/** Restore a saved heap state by tag; zero selects the newest state. Returns success. */
int func_02020744(Unk02020744Heap *heap, u32 tag);

/** Find and unpack ABNK in a writable file; output is null when the block is absent. */
int func_02020794(void *file, Unk02020794Bank **bank);

/** Public animation-bank loader entry, with the same ownership contract as 02020794. */
int func_020207d0(void *file, Unk02020794Bank **bank);

#endif
