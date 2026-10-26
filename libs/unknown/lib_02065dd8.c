#include "types.h"

/* Partial views: only fields read or written by this unit are identified. */
typedef struct Unk065dd8Child {
    u8 pad_0000[0x10];
    s32 unk_0010;
} Unk065dd8Child;

typedef struct Unk065dd8Work {
    Unk065dd8Child *unk_0000;
    u32 unk_0004;
    s32 unk_0008;
    s32 unk_000c;
    u8 pad_0010[8];
    s32 unk_0018;
    u8 pad_001c[8];
    s32 unk_0024;
} Unk065dd8Work;

/* Returns the nullable singleton view used by the original loads. */
extern Unk065dd8Work *func_02063a50(void);
/* Nonzero selects mode 2; zero selects mode 1 in this unit. */
extern s32 func_020bab80(void);
/* Returns the value forwarded unchanged by func_02065e1c. */
extern s32 func_020babdc(void);
/* Receives the mode selected by func_02065dd8. */
extern void Unk0a0ce4_Unk_0a0da4(s32 mode);

/* ARM stores at 0x02065dec/df4 establish fields 8=5 and 12=10;
 * a missing singleton has no effect. The following calls select mode 1 or 2. */
void func_02065dd8(void)
{
    Unk065dd8Work *work = func_02063a50();
    if (work == 0) return;
    work->unk_0008 = 5;
    work->unk_000c = 10;
    if (func_020bab80()) {
        Unk0a0ce4_Unk_0a0da4(2);
    } else {
        Unk0a0ce4_Unk_0a0da4(1);
    }
}

/* Tail-forwards the signed result; the literal at 0x02065e24 names the callee. */
s32 func_02065e1c(void)
{
    return func_020babdc();
}

/* ARM loads at 0x02065e3c/48/68 establish this predicate: requires a singleton,
 * nonzero field 0x18, zero field 0x24, and child field 0x10 equal to 2 or 3.
 * The child pointer must be valid when both field guards pass. */
s32 func_02065e28(void)
{
    Unk065dd8Work *work = func_02063a50();
    if (work == 0) return 0;
    if (work->unk_0018 != 0) {
        if (work->unk_0024 != 0) return 0;
    } else {
        return 0;
    }
    switch (work->unk_0000->unk_0010) {
    case 2:
    case 3:
        return 1;
    }
    return 0;
}
