#include "types.h"

/* Caller-owned payload, copied as three words by the original LDM/STM pair. */
typedef struct CommandWords {
    s32 selector;
    u32 value1;
    u32 value2;
} CommandWords;

/* Caller-owned payload; the original accesses each component as a halfword. */
typedef struct CommandHalfwords {
    u16 value0;
    u16 value1;
    u16 value2;
} CommandHalfwords;

/* Caller-owned message; offsets follow the stores in func_0204f0a4. */
typedef struct CommandMessage {
    u32 command;
    u32 routing[3];
    u8 enabled;
    u8 reserved[3];
    u32 argument;
    u32 remaining[8];
} CommandMessage;

/* Initializes all 56 bytes; the middle two routing inputs are passed unchanged. */
extern void func_0204f0a4(CommandMessage *message, u32 route1, u32 route2, u32 route0);
/* Submits the stack-owned message before its storage expires. */
extern void func_0204f098(CommandMessage *message);
/* Existing provider called after command 18; its domain is not established. */
extern void Unk118b04_Unk_118e50(u32 selector, u32 value);

/* Sends command 16, clearing byte +16 only when enabled is zero (original stores). */
void func_0204f520(u32 route0, u32 route, s32 enabled)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = 16;
    if (enabled == 0)
        message.enabled = 0;
    func_0204f098(&message);
}

/* Sends command 17 with both middle routing fields fixed to 65536. */
void func_0204f560(u32 route0, u32 argument)
{
    CommandMessage message;
    func_0204f0a4(&message, 65536, 65536, route0);
    message.command = 17;
    message.argument = argument;
    func_0204f098(&message);
}

/* Sends command 18, then forwards the same argument to provider selector 4. */
void func_0204f59c(u32 route0, u32 route, u32 argument)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = 18;
    message.argument = argument;
    func_0204f098(&message);
    Unk118b04_Unk_118e50(4, argument);
}

/* Sends command 19 with a word argument at +20, as in the original stores. */
void func_0204f5e0(u32 route0, u32 route, u32 argument)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = 19;
    message.argument = argument;
    func_0204f098(&message);
}

/* Sends command 20 with a word argument at +20, as in the original stores. */
void func_0204f618(u32 route0, u32 route, u32 argument)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = 20;
    message.argument = argument;
    func_0204f098(&message);
}

/* Sends the caller-selected command and word argument; no storage is retained here. */
void func_0204f650(u32 route0, u32 route, u32 argument, u32 command)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = command;
    message.argument = argument;
    func_0204f098(&message);
}

/* Sends the caller-selected command using the initializer's default payload. */
void func_0204f728(u32 route0, u32 route, u32 command)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = command;
    func_0204f098(&message);
}

/* Sends command 11 using the initializer's default payload (original command store). */
void func_0204f758(u32 route0, u32 route)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = 11;
    func_0204f098(&message);
}

/* Sends command 23 and a borrowed three-word payload. Evidence: the signed
 * comparison and both conditional stores at 0x0204f6b0..0x0204f6bc select 23;
 * the LDM/STM pair copies all twelve payload bytes without retaining input. */
void func_0204f68c(u32 route0, u32 route, const CommandWords *payload)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    /* Signed and unsigned views preserve both original stores. See DEC-035. */
    if (payload->selector >= 1) {
        message.command = 23;
    } else {
        *(s32 *)&message.command = 23;
    }
    *(CommandWords *)&message.argument = *payload;
    func_0204f098(&message);
}

/* Selects command 24 only for signed selectors 1..11; otherwise preserves
 * the initializer's command. Evidence: the two comparisons at 0x0204f6f8
 * and 0x0204f700. The caller supplies twelve readable payload bytes. */
void func_0204f6d8(u32 route0, u32 route, const CommandWords *payload)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    if (payload->selector >= 1 && payload->selector <= 11) {
        message.command = 24;
    }
    *(CommandWords *)&message.argument = *payload;
    func_0204f098(&message);
}

/* Sends command 25 with three unsigned halfwords. Evidence: the LDRH/STRH
 * sequence at 0x0204f7ac..0x0204f7c4 copies six caller-owned bytes to +20. */
void func_0204f788(u32 route0, u32 route, const CommandHalfwords *payload)
{
    CommandMessage message;
    func_0204f0a4(&message, route, route, route0);
    message.command = 25;
    /* Read both leading components before either store. See DEC-035. */
    u16 value1 = payload->value1;
    u16 value0 = payload->value0;
    ((CommandHalfwords *)&message.argument)->value1 = value1;
    ((CommandHalfwords *)&message.argument)->value0 = value0;
    ((CommandHalfwords *)&message.argument)->value2 = payload->value2;
    func_0204f098(&message);
}
