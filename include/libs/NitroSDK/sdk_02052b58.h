#ifndef SDK_02052B58_H
#define SDK_02052B58_H

#include "types.h"

/* Borrowed state prefix established by loads/stores at 0x02052d14..0x02052df8.
 * The provider owns the state; pairs points to caller-owned two-byte records. */
typedef struct Unk02052b58State {
    int index;
    int count;
    int flag;
    s8 *pairs;
} Unk02052b58State;

/* Returns provider-owned state without transferring ownership. */
Unk02052b58State *func_02052c30(void);

#endif
