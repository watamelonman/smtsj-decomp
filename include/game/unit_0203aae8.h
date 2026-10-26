#ifndef GAME_UNIT_0203AAE8_H
#define GAME_UNIT_0203AAE8_H
#include "types.h"

/* Borrowed object prefix; only fields observed in the dispatch instructions. */
typedef struct Unk03aae8Object {
    u8 pad_0000[24];
    int status;
    int residual;
    u8 pad_0020[16];
    int argument;
} Unk03aae8Object;

/* Eight-byte division record initialized by 0203af7c; padding is unobserved. */
typedef struct Unk03aae8Record {
    u8 count;
    u8 step;
    u8 pad_0002[2];
    int residual;
} Unk03aae8Record;
#endif
