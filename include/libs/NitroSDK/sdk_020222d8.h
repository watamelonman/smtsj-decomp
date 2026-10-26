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

/** Submit the shared command and clear its two low status bits. */
void func_0202242c(void);
/** Copy a non-null three-component value and invalidate dependent cached flags. */
void func_02022468(const Unk0222d8Vector *value);
/** Return the first borrowed cached matrix, computing both when invalid. */
s32 *func_02022534(void);
/** Return the second borrowed cached matrix, computing both when invalid. */
s32 *func_0202256c(void);
/** Call the optional count hook, then increment the record's count. */
void func_02022e1c(Unk0222d8Record *record);
/** Call the optional flag hook, then set bit 5. */
void func_02022e44(Unk0222d8Record *record);
/** Wait until the asynchronous submission status clears. */
void func_02025224(void);
/** Reset the first word of a caller-owned buffer. */
void func_0202523c(u32 *buffer);
#endif
