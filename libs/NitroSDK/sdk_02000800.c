#include "libs/NitroSDK/sdk_02000800.h"

/* Post-autoload hook reached by the tail branch at the end of do_autoload.
 * Evidence: pret/pokediamond arm9/lib/NitroSDK/src/crt0.c defines
 * _start_AutoloadDoneCallback as an empty body; the original here is only
 * bx lr, so there is no work to reproduce. */
void AutoloadCallback(void)
{
}

/* No-op helper called from Entry between _fp_init and
 * __call_static_initializers. Evidence: the original body at 0x02000b98 is
 * only bx lr and both neighbouring calls are unconditional, so C can express
 * the whole observed behaviour as an empty body. */
void func_02000b98(void)
{
}
