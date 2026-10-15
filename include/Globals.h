/* Frequently accessed scalar / pointer BSS and data symbols.
 * Names are hedged (gUnk_*) until meaning is known; see docs/structs.md.
 */
#ifndef RE_FORGE_GLOBALS_H
#define RE_FORGE_GLOBALS_H

#include "types.h"

/* --- BSS scalars (often flags / mode words) --- */
extern u32 data_0215dd24;       /* near gGameState; get/set in unit_0202e000 */
extern u32 data_0215ee98;       /* cleared by Unk044904_* */
extern u32 data_02176e24;
extern u32 data_02176e7c;
extern u32 data_02176274;
extern u32 data_02176be0;
extern u32 data_02176afc;
extern u32 data_02176e78;
extern u32 data_02176e34;
extern u32 data_02176e94;
extern u32 data_02176e98;
extern u32 data_02176b04;
extern u32 data_0217231c;
extern u32 data_02176ca4;
extern u32 data_02143334;
extern u32 data_02176e5c;
extern u32 data_02176e68;
extern u32 data_02176ce0;
extern u32 data_02176e3c;
extern u32 data_02176e1c;
extern u32 data_02176e00;
extern u32 data_02176e14;
extern u32 data_02170cc8;
extern u32 data_02176de4;
extern u32 data_02176dfc;

/* --- data section --- */
extern u8  data_02140ac8[];     /* address returned by Unk02e000_GetAddr_data_02140ac8 */

#endif
