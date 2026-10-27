#ifndef SDK_02000800_H
#define SDK_02000800_H

/* Startup hooks retained from the NitroSDK boot path at 0x02000800..0x02000b9c. */

/* Post-autoload hook. The original body is only bx lr, so it has no inputs,
 * result, or observable side effects. */
void AutoloadCallback(void);

/* Empty helper called between the SDK runtime init routines in Entry. */
void func_02000b98(void);

#endif
