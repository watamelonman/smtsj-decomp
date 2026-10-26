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
/** Shared submission state; completion is updated asynchronously.
 *  `useFastDma` is the third word of the delinked block (data_02159c90 + 8). */
typedef struct Unk0222d8Submission {
    u32 *buffer;
    volatile u32 busy;
    u32 useFastDma;
} Unk0222d8Submission;

/** Borrowed linked-list node; only the callback, link, count and entry array are read. */
typedef struct Unk0222d8Node Unk0222d8Node;

/** Borrowed render object seen by the draw dispatcher. The three node chains at
 *  0x08/0x10/0x18 are the material, joint and visibility animation lists, and the
 *  bitsets at 0x3c/0x44/0x4c hold their hint words. Mirrors the NNSG3dRenderObj
 *  fields read by NNS_G3dDraw (NitroSystem g3d/src/sbc.c). */
typedef struct Unk0222d8DrawObject {
    u32 flags;
    u32 unk_04;
    Unk0222d8Node *unk_08;
    u32 unk_0c;
    Unk0222d8Node *unk_10;
    u32 unk_14;
    Unk0222d8Node *unk_18;
    u32 unk_1c;
    u32 unk_20[7];
    u32 bits_a[2];
    u32 bits_b[2];
    u32 bits_c[2];
} Unk0222d8DrawObject;

/** Borrowed command state for the callback-driven SBC handler at 02022fe8. */
typedef struct Unk0222d8CallbackState Unk0222d8CallbackState;
struct Unk0222d8CallbackState {
    u8 *data;
    u32 unk_04;
    u32 flags;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    void (*callback)(Unk0222d8CallbackState *);
    u8 pad_1c[0x73];
    u8 state;
};

/** Borrowed command state for the callback-driven SBC handler at 020235ec. */
typedef struct Unk0222d8ShapeState Unk0222d8ShapeState;
struct Unk0222d8ShapeState {
    u8 *data;
    u32 unk_04;
    u32 flags;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    void (*callback)(Unk0222d8ShapeState *);
    u8 pad_24[0x6d];
    u8 state;
};

/** Borrowed command block holding a byte offset and size for 020235ec. */
typedef struct Unk0222d8CommandSource {
    u32 unk_00;
    u32 unk_04;
    u32 offset;
    u32 size;
} Unk0222d8CommandSource;

/** Borrowed resource dictionary header (NNSG3dResDict layout). */
typedef struct Unk0222d8ResourceDict {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} Unk0222d8ResourceDict;

/** Dictionary entry header; `data` starts the fixed-stride record array. */
typedef struct Unk0222d8ResourceEntryHeader {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} Unk0222d8ResourceEntryHeader;

/** Dictionary record prefix holding the byte offset from the resource base. */
typedef struct Unk0222d8ResourceEntry {
    u32 offset;
} Unk0222d8ResourceEntry;

/** Material resource; the dictionary begins four bytes into the block. */
typedef struct Unk0222d8ResourceMat {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    Unk0222d8ResourceDict dict;
} Unk0222d8ResourceMat;

/** Shape resource; the dictionary is the whole block. */
typedef struct Unk0222d8ResourceShp {
    Unk0222d8ResourceDict dict;
} Unk0222d8ResourceShp;

/** Material/shape record prefix used as the dispatch-key word. */
typedef struct Unk0222d8ResourceData {
    u16 itemTag;
    u16 size;
} Unk0222d8ResourceData;

/** Borrowed SBC state seen by the material and shape handlers. Only the command
 *  cursor, flag word, current material index and resource tables are read. */
typedef struct Unk0222d8ResourceState {
    u8 *command;
    u32 renderObject;
    u32 flags;
    u8 pad_0c[0xa0];
    u8 pad_ac;
    u8 currentMat;
    u8 pad_ae[42];
    Unk0222d8ResourceMat *resMat;
    Unk0222d8ResourceShp *resShp;
} Unk0222d8ResourceState;

/** Borrowed linked-list node; only the callback, link, count and entry array are read. */
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
/** Accumulate the callback-written bits from one node chain; returns whether any
 *  matching entry ran. Mirrors NNSi_G3d... node-chain walkers in NitroSystem sbc.c. */
u32 func_02022a6c(u32 *bits, Unk0222d8Node *node, u32 index);
/** Draw one render object, rebuilding its hint bitsets and reusing the shared
 *  render state when present. Matches NNS_G3dDraw (NitroSystem sbc.c). */
void func_02022d40(Unk0222d8DrawObject *object);
/** Run the command callback protocol for the SBC command at offset 02022fe8. */
void func_02022fe8(Unk0222d8CallbackState *object);
/** Material SBC handler; matches NNSi_G3dFuncSbc_MAT (NitroSystem sbc.c). */
void func_0202353c(Unk0222d8ResourceState *object, u32 option);
/** Shape SBC handler; matches NNSi_G3dFuncSbc_SHP (NitroSystem sbc.c). */
void func_020236c0(Unk0222d8ResourceState *object, u32 option);
/** Shape-send SBC handler that forwards a staged command block. */
void func_020235ec(Unk0222d8ShapeState *object, u32 unused,
                   Unk0222d8CommandSource *source);
/** Dispatch command callbacks until the command flags ask to stop. */
void func_02022af4(Unk0222d8Command *command);
/** Set one bit per entry whose flag word has bit 8. */
void func_02022cd8(u32 *bits, Unk0222d8Node *node);
/** Emit the packet's selected payload word as a three-word command. */
void func_02024a64(Unk0222d8Packet *packet, u32 flag);
/** Wait for the shared submission, then fill and clear its staging buffer. */
void func_020251c8(void);
/** Send a display list, using DMA for large blocks when a channel is configured.
 *  Matches NNS_G3dGeSendDL (NitroSystem g3d/src/gecom.c). */
void func_02025248(const void *source, u32 size);
/** Fetch the current position/normal matrices; matches NNS_G3dGetCurrentMtx
 *  (NitroSystem g3d/src/util.c). */
void func_020253e0(s32 *position, s32 *normal);
/** Call the optional count hook, then increment the record's count. */
void func_02022e1c(Unk0222d8Record *record);
/** Call the optional flag hook, then set bit 5. */
void func_02022e44(Unk0222d8Record *record);
/** Wait until the asynchronous submission status clears. */
void func_02025224(void);
/** Reset the first word of a caller-owned buffer. */
void func_0202523c(u32 *buffer);
#endif
