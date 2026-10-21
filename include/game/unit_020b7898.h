#ifndef GAME_UNIT_020B7898_H
#define GAME_UNIT_020B7898_H

#include "types.h"

/* Table entry 0 at 0x0213d6f8: calls func_02052634(1, 0, 31). */
void Unk0b7898_Call_02052634(void);
/* Table entry 1 at 0x0213d6f8: calls Unk111400_Unk_111474(4, 0xC03, 0), func_02111494(),
 * then Unk02cad4_Unk_02cbdc(1). */
void Unk0b7898_Unk_0b78b0(void);

/* Descriptive names for callers. The definitions keep the symbols.txt names because the
 * linked symbols must stay as they are and the match gate looks definitions up by name.
 * The aliases describe the observed call sequence only; the callees are not identified. */
#define Unk0b7898_TableHook0_Call02052634With1_0_31 Unk0b7898_Call_02052634
#define Unk0b7898_TableHook1_Call111474Then02111494ThenSet02cbdc Unk0b7898_Unk_0b78b0

#endif /* GAME_UNIT_020B7898_H */
