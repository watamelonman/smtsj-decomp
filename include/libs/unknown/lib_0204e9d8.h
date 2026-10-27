#ifndef LIB_0204E9D8_H
#define LIB_0204E9D8_H
#include "types.h"

/** Borrowed object prefix; only the identifier word is observed by this unit. */
typedef struct Unk04e9d8Object { u32 id; } Unk04e9d8Object;
/** Borrowed singleton prefix with ten provider-owned objects at offset 0x64. */
typedef struct Unk04e9d8State {
    u8 reserved[0x64];
    Unk04e9d8Object *objects[10];
} Unk04e9d8State;
/** Borrowed request prefix; mode and lookup argument occupy offsets 8 and 12. */
typedef struct Unk04e9d8Request { u32 words[2]; s32 mode; u32 argument; } Unk04e9d8Request;
/** Evaluates a borrowed object without transferring ownership of its storage. */
typedef s32 (*Unk04e9d8Callback)(Unk04e9d8Object *object, s32 argument);
/** Forwards a borrowed request and identifier to the existing request provider. */
s32 func_0204e9d8(const Unk04e9d8Request *request, u32 id);
/** Writes at most ten IDs; invert selects zero rather than nonzero callback results. */
s32 func_0204e9e4(u32 *out, s32 group, s32 argument, Unk04e9d8Callback callback, s32 invert);
/** Writes tied extrema among ten slots; maximize selects the initial bound zero. */
s32 func_0204eaac(u32 *out, s32 group, s32 argument, Unk04e9d8Callback callback, s32 maximize);
/** Resolves a group from the request and ID before selecting an ID. */
u32 func_0204ebb4(const Unk04e9d8Request *request, u32 id, u32 flags, s32 argument);
/** Selects an ID by mode; selection and fallback providers retain all object storage. */
u32 func_0204ecc8(u32 mode, s32 argument, s32 group, s32 flag_a, s32 flag_b, u32 id);
#endif
