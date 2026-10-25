#include "types.h"

/* Work storage is 20 bytes, as established by the clear in 020f4ca8. */
typedef struct Unk0f4c50Work {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
} Unk0f4c50Work;

typedef struct Unk0f4c50Message Unk0f4c50Message;

/* Callback slots follow the stores in 020f4c50; slot 08 is untouched. */
typedef struct Unk0f4c50Descriptor {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*dispatch)(Unk0f4c50Work *);
    void (*unk_10)(void);
    void (*unk_14)(void);
    u32 unk_18;
    void (*unk_1c)(void);
    void (*unk_20)(Unk0f4c50Work *, Unk0f4c50Message *);
} Unk0f4c50Descriptor;

extern Unk0f4c50Work *data_02176e04;
extern void func_02008848(void *destination, int value, u32 size);
extern u32 func_020ea630(u32 value);
extern void Unk0d1c98_Unk_0d1d94(u32 value, int mode);
extern void func_020d1e94(int value);
extern int Unk0e8228_Unk_0e8c80(void);
extern void func_02044ec4(void);
extern void Unk0ea208_Unk_0ea70c(void);
extern void Unk0e8228_Unk_0e8d90(u32 arg0, u32 arg1);
extern void *Unk044904_GetSlot(int i);
extern int Unk0e8228_GetArr30(int i);
extern void Unk0e8228_Unk_0e8398(void);
extern int Unk0e8228_Unk_0e8488(void);
extern int Unk0e8228_GetArr58(int i);
extern u32 Unk0e8228_Unk_0e8dd0(u32 arg0, u32 arg1);
extern u32 Unk0e8228_Unk_0e8dfc(u32 arg0, u32 arg1);
extern void Unk0bc1a8_Unk_0bc504(Unk0f4c50Work *work, u32 mode);
extern void func_020f7e48(u32 value, int first, int second);
extern void func_020f7d14(u32 value);
extern void func_020f7de4(u32 value, int mode);
extern void Unk0bc1a8_Unk_0bc9b4(u32 value, int mode);
void func_020f4d64(Unk0f4c50Work *work, Unk0f4c50Message *message);
void Unk0f4c50_Unk_0f51b0(Unk0f4c50Work *work, int mode);
void func_020f4cfc(Unk0f4c50Work *work);

/* Empty callback, as shown by the sole return instruction at 020f4cf8. */
void Unk0f4c50_Nop_0f4cf8(void) { }

/* Empty callback, as shown by the sole return instruction at 020f4d5c. */
void Unk0f4c50_Nop_0f4d5c(void) { }

/* Empty callback, as shown by the sole return instruction at 020f4d60. */
void Unk0f4c50_Nop_0f4d60(void) { }

/* Populate the descriptor with the callback addresses stored by 020f4c50. */
void func_020f4c50(Unk0f4c50Descriptor *descriptor)
{
    descriptor->size = 0x14;
    descriptor->unk_04 = 4;
    descriptor->dispatch = func_020f4cfc;
    descriptor->unk_10 = Unk0f4c50_Nop_0f4d5c;
    descriptor->unk_14 = Unk0f4c50_Nop_0f4d60;
    descriptor->unk_18 = 0;
    descriptor->unk_1c = Unk0f4c50_Nop_0f4cf8;
    descriptor->unk_20 = func_020f4d64;
}

/* Set the four initial words; 020f4cd4 leaves the fifth word unchanged. */
void Unk0f4c50_Unk_0f4cd4(Unk0f4c50Work *work)
{
    work->unk_00 = 0x23;
    work->unk_04 = 0;
    work->unk_08 = 9;
    work->unk_0c = 1;
}

/* Clear and publish the 20-byte work area before setting its initial words. */
void Unk0f4c50_Unk_0f4ca8(Unk0f4c50Work *work)
{
    func_02008848(work, 0, 0x14);
    data_02176e04 = work;
    Unk0f4c50_Unk_0f4cd4(work);
}

/* Dispatch word 0c values 6 and 7 using word 00; other values do nothing. */
void func_020f4cfc(Unk0f4c50Work *work)
{
    switch (work->unk_0c) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: func_020f7de4(work->unk_00, 0); break;
    case 7: Unk0bc1a8_Unk_0bc9b4(work->unk_00, 0); break;
    case 8: break;
    case 9: break;
    case 10: break;
    }
}

/* Message payload words are valid only when their flag bit is set
 * (bit 0 -> +04, bit 2 -> +0c, bit 3 -> +10, bit 4 -> +14, bit 6 -> +1c,
 * bit 7 -> +20), as tested by the reads in 020f4d64. */
typedef struct Unk0f4c50Payload {
    u8 flags;
    u8 pad_01[3];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
} Unk0f4c50Payload;

/* The message type word precedes the payload, as read by 020f4d64. */
struct Unk0f4c50Message {
    u32 type;
    Unk0f4c50Payload payload;
};

/* Leaves the caller's output unchanged when payload word +04 is not flagged. */
static inline int Unk0f4c50_Payload04(Unk0f4c50Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_04;
    if (p->flags & 1) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Leaves the caller's output unchanged when payload word +0c is not flagged. */
static inline int Unk0f4c50_Payload0c(Unk0f4c50Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_0c;
    if (p->flags & 4) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Leaves the caller's output unchanged when payload word +10 is not flagged. */
static inline int Unk0f4c50_Payload10(Unk0f4c50Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_10;
    if (p->flags & 8) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Leaves the caller's output unchanged when payload word +14 is not flagged. */
static inline int Unk0f4c50_Payload14(Unk0f4c50Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_14;
    if (p->flags & 16) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Leaves the caller's output unchanged when payload word +1c is not flagged. */
static inline int Unk0f4c50_Payload1c(Unk0f4c50Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_1c;
    if (p->flags & 64) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Leaves the caller's output unchanged when payload word +20 is not flagged. */
static inline int Unk0f4c50_Payload20(Unk0f4c50Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_20;
    if (p->flags & 128) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Wrapper reads: the ROM null-checks twice and copies through a stack slot.
 * The int local passed as u32 * reproduces that slot (a u32 local is kept in
 * a register instead); the stored bits are identical. */
static inline int Unk0f4c50_Read0c(Unk0f4c50Payload *p, u32 *out)
{
    int value;
    if (p == 0) return 0;
    if (Unk0f4c50_Payload0c(p, (u32 *)&value)) {
        *out = value;
        return 1;
    }
    return 0;
}

static inline int Unk0f4c50_Read14(Unk0f4c50Payload *p, u32 *out)
{
    int value;
    if (p == 0) return 0;
    if (Unk0f4c50_Payload14(p, (u32 *)&value)) {
        *out = value;
        return 1;
    }
    return 0;
}

static inline int Unk0f4c50_Read1c(Unk0f4c50Payload *p, u32 *out)
{
    int value;
    if (p == 0) return 0;
    if (Unk0f4c50_Payload1c(p, (u32 *)&value)) {
        *out = value;
        return 1;
    }
    return 0;
}

static inline int Unk0f4c50_Read20(Unk0f4c50Payload *p, u32 *out)
{
    int value;
    if (p == 0) return 0;
    if (Unk0f4c50_Payload20(p, (u32 *)&value)) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Finishes a type-3 message: 0e8dd0/0e8dfc decide between signalling word 00
 * with 8, or resetting word 00 and handing word 04 to 020f7e48(5)/020f7d14. */
static inline void Unk0f4c50_Finish(Unk0f4c50Work *work, u32 ok)
{
    if (ok) {
        func_020f7e48(work->unk_00, 0, 8);
        return;
    }
    func_020f7e48(work->unk_00, 0, 0);
    func_020f7e48(work->unk_04, 0, 5);
    func_020f7d14(work->unk_04);
}

/* Descriptor slot-20 message handler (installed by 020f4c50). Types 1-4 act:
 * 1 calls 0bc504; 2 sets the state word 0c from payload +0c; 3 handles
 * sub-kinds 13/14 (payload +04) by matching payload ids against the 0e8228
 * table; 4 updates word 10 or advances the state word 0c. Other types only run
 * the two common calls at entry. Payload words are read only when flagged;
 * as in the ROM, `kind` (type 3) and `value` (type 2, mode 1) are left
 * unset when their flag is clear, so the original reads a stale register. */
void func_020f4d64(Unk0f4c50Work *work, Unk0f4c50Message *message)
{
    u32 type;
    Unk0f4c50Payload *p;
    Unk0e8228_Unk_0e8c80();
    func_02044ec4();
    type = message->type;
    p = &message->payload;
    switch (type) {
    case 0:
        break;
    case 3: {
        u32 kind;
        u32 found;
        u32 id;
        int i;
        Unk0ea208_Unk_0ea70c();
        Unk0f4c50_Unk_0f51b0(work, 0);
        Unk0f4c50_Payload04(p, &kind);
        switch (kind) {
        case 14:
            found = 0;
            if (Unk0f4c50_Read14(p, &id)) {
                Unk0e8228_Unk_0e8d90(6, id);
                found = 1;
                if (Unk044904_GetSlot(id) != 0) Unk0e8228_GetArr30(id);
            }
            id = 0;
            if (Unk0f4c50_Payload10(p, &id)) {
                Unk0e8228_Unk_0e8398();
                for (i = 0; i < Unk0e8228_Unk_0e8488(); i++) {
                    if (id == Unk0e8228_GetArr58(i)) Unk0e8228_Unk_0e8d90(7, i);
                }
            }
            Unk0f4c50_Finish(work, Unk0e8228_Unk_0e8dd0(found, work->unk_10));
            break;
        case 13:
            found = 0;
            if (Unk0f4c50_Payload14(p, &id)) {
                Unk0e8228_Unk_0e8398();
                for (i = 0; i < Unk0e8228_Unk_0e8488(); i++) {
                    if (id == Unk0e8228_GetArr58(i)) {
                        Unk0e8228_Unk_0e8d90(7, i);
                        found = 1;
                    }
                }
            }
            Unk0f4c50_Finish(work, Unk0e8228_Unk_0e8dfc(found, work->unk_10));
            break;
        }
        break;
    }
    case 2: {
        u32 mode = 0;
        u32 value;
        Unk0f4c50_Read0c(p, &mode);
        switch (mode) {
        case 0:
            work->unk_0c = 1;
            break;
        case 1:
            work->unk_0c = 2;
            Unk0f4c50_Payload10(p, &value);
            work->unk_04 = value;
            Unk0f4c50_Unk_0f51b0(work, 1);
            break;
        case 3:
            break;
        }
        break;
    }
    case 1:
        Unk0bc1a8_Unk_0bc504(work, 0);
        break;
    case 4: {
        u32 target = 0;
        u32 value = 0;
        Unk0f4c50_Read1c(p, &target);
        Unk0f4c50_Read20(p, &value);
        if (target != 0) {
            if (target == 1) work->unk_10 = value;
            break;
        }
        switch (value) {
        case 2:
        case 6:
        case 8:
            if (work->unk_0c == 1 || work->unk_0c == 7) break;
            work->unk_0c = 6;
            if (work->unk_04 != 0) func_020f7e48(work->unk_04, 0, value);
            break;
        case 3:
            if (work->unk_0c != 1) {
                work->unk_0c = 7;
                break;
            }
            Unk0bc1a8_Unk_0bc9b4(work->unk_00, 0);
            break;
        }
        break;
    }
    }
}

/* A nonzero mode forwards the converted fifth word; zero sends a fixed 1. */
void Unk0f4c50_Unk_0f51b0(Unk0f4c50Work *work, int mode)
{
    if (mode != 0) {
        u32 value = func_020ea630(work->unk_10);
        Unk0d1c98_Unk_0d1d94(value, -1);
        return;
    }
    func_020d1e94(1);
}
