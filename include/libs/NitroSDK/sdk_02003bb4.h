#ifndef SDK_02003BB4_H
#define SDK_02003BB4_H

#include "types.h"

/* Main BG0 character-data base. Adds DISPCNT bits 24-26 (64 KiB character-base
 * offset) and BG0CNT bits 2-5 (16 KiB character block) to 0x06000000.
 * Evidence: G2_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003bb4(void);

/* Sub BG0 character-data base. Adds sub BG0CNT bits 2-5 (16 KiB block) to
 * 0x06200000. Evidence: G2S_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003be8(void);

/* Main BG1 character-data base. Same rule as BG0 but reads BG1CNT.
 * Evidence: G2_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003c08(void);

/* Sub BG1 character-data base. Adds sub BG1CNT bits 2-5 (16 KiB block) to
 * 0x06200000. Evidence: G2S_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003c3c(void);

/* Main BG2 character-data base, or null for display modes 5-7 when BG2CNT bit 7
 * is set. Evidence: G2_GetBG2CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003c5c(void);

/* Sub BG2 character-data base, or null for display modes 5-7 when sub BG2CNT
 * bit 7 is set. Evidence: G2S_GetBG2CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003cac(void);

/* Main BG3 character-data base, or null when BG3 is unavailable (mode >= 6, or
 * modes 3-5 with BG3CNT bit 7 set). Evidence: G2_GetBG3CharPtr in
 * pret/pokediamond GX_bgcnt.c. */
void *func_02003cec(void);

/* Sub BG3 character-data base, or null when sub BG3 is unavailable (mode >= 6,
 * or modes 3-5 with sub BG3CNT bit 7 set). Evidence: G2S_GetBG3CharPtr in
 * pret/pokediamond GX_bgcnt.c. */
void *func_02003d44(void);

#endif
