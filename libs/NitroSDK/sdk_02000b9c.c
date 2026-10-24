#include "libs/NitroSDK/sdk_02000b9c.h"

extern u8 data_021527c0[];
extern u8 data_021527d8[];
extern u8 data_021521a0[];

/* No-op entry: the entire original body at 0x02000b9c is bx lr. */
void func_02000b9c(void)
{
}

#pragma arm section rodata=".text"
/* Evidence: BuildInfo's relocation quartet and SDK signatures at 0x02000ba0.
 * The BSS end is a linker boundary with no relocation in the original object. */
const SdkBuildInfo BuildInfo = {
    data_021527c0,
    data_021527d8,
    data_021521a0,
    data_021521a0,
    (void *)0x02176ea0,
    0,
    0x04027539,
    0xdec00621,
    0x2106c0de,
    "[SDK+NINTENDO:BACKUP]",
    "[SDK+Actimagine:Mobiclip SDK V1.1.0]"
};
