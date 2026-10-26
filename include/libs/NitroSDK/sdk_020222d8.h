#ifndef SDK_020222D8_H
#define SDK_020222D8_H
#include "types.h"

/** Three signed fixed-point components copied without conversion. */
typedef struct Unk0222d8Vector { s32 x, y, z; } Unk0222d8Vector;
/** Borrowed shared-state prefix; the flag word is at byte 252. */
typedef struct Unk0222d8State {
    u32 command;
    u32 parameters[62];
    u32 flags;
} Unk0222d8State;
/** Borrowed callback record; callbacks may update the record before flags/count change. */
typedef struct Unk0222d8Record Unk0222d8Record;
struct Unk0222d8Record {
    u32 count;
    u32 unk_04;
    u32 flags;
    void (*on_count)(Unk0222d8Record *);
    void (*on_flag)(Unk0222d8Record *);
};
/** Shared submission state; completion is updated asynchronously. */
typedef struct Unk0222d8Submission {
    u32 *buffer;
    volatile u32 busy;
} Unk0222d8Submission;

/** Borrowed linked-list node; only the callback, link, count and entry array are read. */
typedef struct Unk0222d8Node Unk0222d8Node;
struct Unk0222d8Node {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    int (*callback)(void *, Unk0222d8Node *, u32);
    Unk0222d8Node *next;
    u32 unk_14;
    u8 unk_18;
    u8 count;
    u16 entries[];
};

/** Borrowed command stream prefix; the dispatch byte is the first byte of `data`. */
typedef struct Unk0222d8Command {
    const u8 *data;
    u32 unk_04;
    u32 flags;
} Unk0222d8Command;

/** Borrowed packet cursor; only the cursor word, flags and two payload words are used. */
typedef struct Unk0222d8Packet {
    u32 unk_00;
    u32 unk_04;
    u32 flags;
    u8 pad_0c[0xd4];
    s32 unk_e0;
    s32 unk_e4;
} Unk0222d8Packet;

/** Copy a non-null three-component value and invalidate dependent cached flags. */
void func_02022468(const Unk0222d8Vector *value);
/** Build the shared output block from the shared input once, then return it. */
u8 *func_02022498(void);
/** Rebuild both cached matrices from the shared state and input block. */
void func_020224dc(void);
/** Return the first borrowed cached matrix, computing both when invalid. */
s32 *func_02022534(void);
/** Return the second borrowed cached matrix, computing both when invalid. */
s32 *func_0202256c(void);
/** Walk the node chain, call matching entry callbacks, and report whether any ran. */
int func_020225a4(void *context, Unk0222d8Node *node, u32 index);
/** Accumulate a scaled or constant three-component value into `dst`. */
void func_02022610(s32 *dst, const s32 *src, s32 value, u32 additive);
/** Dispatch command callbacks until the command flags ask to stop. */
void func_02022af4(Unk0222d8Command *command);
/** Set one bit per entry whose flag word has bit 8. */
void func_02022cd8(u32 *bits, Unk0222d8Node *node);
/** Emit the packet's selected payload word as a three-word command. */
void func_02024a64(Unk0222d8Packet *packet, u32 flag);
/** Wait for the shared submission, then fill and clear its staging buffer. */
void func_020251c8(void);
/** Call the optional count hook, then increment the record's count. */
void func_02022e1c(Unk0222d8Record *record);
/** Call the optional flag hook, then set bit 5. */
void func_02022e44(Unk0222d8Record *record);
/** Wait until the asynchronous submission status clears. */
void func_02025224(void);
/** Reset the first word of a caller-owned buffer. */
void func_0202523c(u32 *buffer);
#endif
