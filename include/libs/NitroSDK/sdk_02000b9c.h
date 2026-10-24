#ifndef SDK_02000B9C_H
#define SDK_02000B9C_H

#include "types.h"

/* Startup metadata, stored in .text for the SDK startup loader; addresses are ARM9 pointers. */
typedef struct SdkBuildInfo {
    const void *autoloadStart;
    const void *autoloadEnd;
    const void *autoloadData;
    void *staticBssStart;
    void *staticBssEnd;
    u32 compressedStaticEnd;
    u32 sdkVersion;
    u32 nitroCode;
    u32 nitroCodeReverse;
    char backupIdentifier[24];
    char mobiclipIdentifier[40];
} SdkBuildInfo;

/* Original ARM body is only bx lr; no inputs, result, or side effects. */
void func_02000b9c(void);

/* The boot loader locates this fixed-layout module record independently of C callers. */
extern const SdkBuildInfo BuildInfo;

#endif
