#ifndef LIB_02048E90_H
#define LIB_02048E90_H
#include "types.h"

/* Borrowed object prefix: only the packed identifier is inspected here. */
typedef struct { u32 identifier; } Unk048e90Object;
/* Borrowed singleton layout; offsets are established by ARM loads/stores. */
typedef struct {
    u8 pad_0000[0x50];
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[12];
    Unk048e90Object *objects[10];
    u8 pad_008c[0x7870 - 0x8c];
    void *unk_7870;
    u8 pad_7874[0x798c - 0x7874];
    void *resources[9];
    u8 pad_79b0[0x7a3c - 0x79b0];
    u32 initialized;
} Unk048e90State;

/* Runs the guarded setup sequence; caller retains state storage. */
void func_02048e90(Unk048e90State *state);
/* Runs guarded setup on the provider-owned singleton. */
void func_02048ed8(void);
/* Releases nine resource slots and clears the singleton after provider teardown. */
void func_02048ef0(Unk048e90State *state);
/* Submits table zero from resource slot zero with its low 16-bit count. */
void func_02048ff4(Unk048e90State *state);
/* Updates ten borrowed objects and dispatches state processing. */
void func_02049044(Unk048e90State *state);
#endif
