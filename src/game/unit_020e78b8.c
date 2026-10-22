#include "types.h"

/* Partial work layout, established by the word accesses in this TU. */
typedef struct Unk0e78b8Work {
    u8 state;
    u8 pad_0001[3];
    u32 unk_0004[4];
    u32 unk_0014[4];
    u32 unk_0024[4];
    u32 unk_0034;
    u32 unk_0038;
    u32 unk_003c;
    u32 unk_0040[4];
    u32 unk_0050;
    u32 unk_0054;
    u32 unk_0058;
} Unk0e78b8Work;

/* Only the state word of this separate object's layout is known here. */
typedef struct Unk0e78b8State {
    u8 pad_0000[16];
    u32 state;
} Unk0e78b8State;

typedef struct Unk0e78b8Payload {
    u8 flags;
    u8 pad_0001[7];
    u32 value;
} Unk0e78b8Payload;

typedef struct Unk0e78b8Message {
    u32 type;
    Unk0e78b8Payload payload;
} Unk0e78b8Message;

/* Callback slots have distinct uses; their other signatures remain external. */
typedef struct Unk0e78b8Descriptor {
    u32 size;
    u32 kind;
    u32 unk_0008;
    void (*unk_000c)(Unk0e78b8Work *);
    void (*unk_0010)(Unk0e78b8Work *);
    void (*unk_0014)(Unk0e78b8Work *);
    void (*unk_0018)(Unk0e78b8Work *);
    void (*unk_001c)(Unk0e78b8Work *);
    void (*unk_0020)(Unk0e78b8Work *, Unk0e78b8Message *);
} Unk0e78b8Descriptor;

extern Unk0e78b8State *data_02176cd8;
extern Unk0e78b8Work *data_02176cdc;
extern u8 data_02150bf4[];
void func_020086a0(u32 value, void *dest, u32 size);
void Unk05b82c_Unk_05b82c(u32 value);
u32 func_0205dcd4(const void *data, u32 mode);
void Unk0bc1a8_Unk_0bc504(Unk0e78b8Work *work, u32 value);
void func_020e7ac4(Unk0e78b8Work *work);
void Unk0e7ac4_Nop_0e7b7c(Unk0e78b8Work *work);
void func_020e7b80(Unk0e78b8Work *work);
void func_020e7d40(Unk0e78b8Work *work);
void Unk0e7ac4_Unk_0e7f0c(Unk0e78b8Work *work);
void func_020e7940(Unk0e78b8Work *work, Unk0e78b8Message *message);

/* Tests the active object's +0x10 state against 5; the name follows that comparison. */
int Unk0e78b8_IsState5(void)
{
    if (data_02176cd8 == 0) {
        return 0;
    }
    return data_02176cd8->state == 5;
}

/* Registers the 0x5c-byte work allocation and its six callback slots. */
void func_020e78e4(Unk0e78b8Descriptor *desc)
{
    desc->size = 0x5c;
    desc->kind = 4;
    desc->unk_000c = func_020e7ac4;
    desc->unk_0010 = Unk0e7ac4_Nop_0e7b7c;
    desc->unk_0014 = func_020e7b80;
    desc->unk_0018 = func_020e7d40;
    desc->unk_001c = Unk0e7ac4_Unk_0e7f0c;
    desc->unk_0020 = func_020e7940;
}

/* Extracts the value only when the payload's second flag bit is present. */
static inline int Unk0e78b8_GetValue(Unk0e78b8Payload *payload, u32 *out)
{
    u32 value;
    if (payload == 0) {
        return 0;
    }
    value = payload->value;
    if (payload->flags & 2) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Type 1 forwards the work; type 4 applies state 1 or 3 from a flagged payload. */
void func_020e7940(Unk0e78b8Work *work, Unk0e78b8Message *message)
{
    struct { u32 value; } result = {0};
    u32 type;
    Unk0e78b8Payload *payload;
    type = message->type;
    payload = &message->payload;
    switch (type) {
    case 1:
        Unk0bc1a8_Unk_0bc504(work, 0);
        break;
    case 4:
        if (!Unk0e78b8_GetValue(payload, &result.value)) {
            return;
        }
        if (result.value == 1) {
            work->state = result.value;
            work->unk_0034 = 26;
            work->unk_0038 = 0;
            func_020086a0(0, work->unk_0004, 16);
            work->unk_0004[0] = work->unk_0014[0];
            work->unk_0004[1] = work->unk_0014[1];
            work->unk_0004[2] = work->unk_0014[2];
            work->unk_0004[3] = work->unk_0014[3];
        } else if (result.value == 3) {
            work->state = result.value;
            work->unk_0034 = 26;
            work->unk_0038 = 0;
        }
        break;
    case 0:
    case 2:
    case 3:
        break;
    }
}

/* Publishes and initializes work, then stores the handle returned for data_02150bf4. */
void Unk0e78b8_Unk_0e7a30(Unk0e78b8Work *work)
{
    data_02176cdc = work;
    work->state = 0;
    work->unk_0034 = 26;
    work->unk_0038 = 0;
    work->unk_003c = 0;
    work->unk_0058 = 0;
    work->unk_0050 = 1;
    func_020086a0(0, work->unk_0004, 16);
    func_020086a0(0, work->unk_0014, 16);
    func_020086a0(0, work->unk_0024, 16);
    func_020086a0(0, work->unk_0040, 16);
    Unk05b82c_Unk_05b82c(65);
    work->unk_0054 = func_0205dcd4(data_02150bf4, 1);
}
