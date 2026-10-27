#ifndef LIBS_CRI_CRI_0208D1FC_H
#define LIBS_CRI_CRI_0208D1FC_H

#include "types.h"

/** Work record used by the ACSVHL (CRI voice-handle) entry points in this unit.
 *
 * Evidence for the layout comes from the original instructions in
 * 0208d1fc..0208d5ac: func_0208d500 clears offsets 0 and 4, zeroes the 68-byte
 * buffer at offset 8, then writes offsets 0x4c, 0x50, 0x54, 0x58 and 0x5c;
 * func_0208d330 indexes a four-entry array through offset 0 and switches on the
 * signed byte at offset 0x50. The record is caller-owned, at least sizeof() =
 * 0x60 bytes (func_0208d1fc rejects sizes below 0x60). */
typedef struct AcsvhlWork {
    void *unk_000;      /* pointer indexed as a four-entry array by 0208d330 */
    void *handle;       /* worker handle handed to the ACSFDR helpers */
    u8 unk_008[68];     /* scratch buffer filled by 0208c7cc during Init */
    u32 unk_04c;        /* word cleared by 0208d2fc */
    s8 unk_050;         /* signed state byte (ldrsb in 0208d310) */
    u8 pad_051[3];
    u32 unk_054;        /* initialised to 30 by 0208d500 */
    u32 unk_058;        /* initialised to 60 by 0208d500 */
    u32 unk_05c;        /* initialised to 120 by 0208d500 */
} AcsvhlWork;

#endif
