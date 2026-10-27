/* Script request wrappers and command-slot builders; evidence: the ARM
 * instruction streams at each entry address below. */
#include "types.h"

/* Submits a request with three word arguments; returns the runtime result. */
extern s32 func_020b8b38(s32 request, s32 first, s32 second, s32 third);
/* Reads a zero-based operand from the implicit current script context. */
extern s32 func_0203ac00(s32 index);
/* Publishes the implicit script result; see game/unit_0203aae8. */
extern void Unk03aae8_Unk_03acf4(s32 value);

/* ARM 0x020ba678: submits request 120 with zero arguments, publishes the
 * result and returns completion 1. No incoming argument is consumed. */
s32 func_020ba678(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(120, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba69c: submits request 121 with zero arguments, publishes the
 * result and returns completion 1. No incoming argument is consumed. */
s32 func_020ba69c(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(121, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba6c0: submits request 122 with zero arguments, publishes the
 * result and returns completion 1. No incoming argument is consumed. */
s32 func_020ba6c0(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(122, 0, 0, 0));
    return 1;
}

/* ARM 0x020ba6e4: submits request 123 with operand 0 as its first argument,
 * publishes the result and returns completion 1. */
s32 func_020ba6e4(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(123, value, 0, 0));
    return 1;
}

/* ARM 0x020ba710: submits request 124 with operand 0 as its first argument,
 * publishes the result and returns completion 1. */
s32 func_020ba710(void)
{
    s32 value = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(func_020b8b38(124, value, 0, 0));
    return 1;
}

/* One 24-byte command slot at entry +0x1e8; offsets follow the original
 * stores. The entry and its command area are borrowed from the caller. */
typedef struct Unk020ba678Command {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
} Unk020ba678Command;

/* Borrowed entry prefix: the ID word at +0 and the two command slots at
 * +0x1e8. Only these fields are touched by this unit. */
typedef struct Unk020ba678Entry {
    u32 unk_00;
    u8 pad_04[0x1e4];
    Unk020ba678Command commands[2];
} Unk020ba678Entry;

/* Borrowed shared record at Unk044904_Unk_045064() + 4. The low halfword at
 * +0x0c carries the flag bits and the word at +0x10 is a command operand;
 * meanings remain unresolved beyond their use at the call sites. */
typedef struct Unk020ba678Sub {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u16 unk_0c;
    u16 pad_0e;
    u32 unk_10;
} Unk020ba678Sub;

/* Borrowed shared record at Unk044904_Unk_045064() + 0; word 0 is the
 * selected entry ID and the sub-record follows at +4. */
typedef struct Unk020ba678Storage {
    u32 id;
    Unk020ba678Sub sub;
} Unk020ba678Storage;

/* Borrowed state view at entry +0x294 (func_0204acdc). +0x44 holds flag
 * bits, +0x48 is the current command slot and +0x4a a command operand. */
typedef struct Unk020ba678State {
    u8 pad_00[0x44];
    u32 unk_44;
    s16 index;
    u16 unk_4a;
} Unk020ba678State;

/* Returns the borrowed shared record; word 0 is the selected entry ID. */
extern Unk020ba678Storage *Unk044904_Unk_045064(void);
/* Returns the borrowed +4 sub-record of the shared record. */
extern Unk020ba678Sub *func_020b8ac8(void);
/* Resolves an entry by its word ID; the result is borrowed from the manager. */
extern Unk020ba678Entry *func_02044ec4(u32 id);
/* Returns the borrowed state at entry +0x294. */
extern Unk020ba678State *func_0204acdc(Unk020ba678Entry *entry);
/* Selects a record by index for the state's command source; zero is valid. */
extern void func_0204afe0(Unk020ba678State *state, s32 value);
/* Advances the state's command source once. */
extern void func_0204b044(Unk020ba678State *state);
/* Builds the ID-tagged token stored in command word 5; value is a timeout. */
extern u32 func_020b0874(u32 id, s32 value);
/* Submits command to the command list with explicit flags and argument. */
extern u32 func_0204ebb4(Unk020ba678Command *command, u32 id, u16 flags,
                         u32 arg);
/* Returns the borrowed command list accepted by func_020aa188. */
extern s32 Unk044904_Unk_044fd8(void);
/* Appends a built command to the given list; both are caller-owned. */
extern void func_020aa188(s32 list, Unk020ba678Command *command);
/* Appends one command for the shared record; see its definition. */
void func_020ba78c(s32 arg);
/* Fills one command from the shared sub-record and returns its token. */
u32 func_020ba838(Unk020ba678Sub *sub, Unk020ba678Entry *entry,
                  Unk020ba678Command *command, s32 arg);

/* ARM 0x020ba73c: selects the entry named by the caller's first word,
 * resets its command slot state and submits the first command through
 * func_020ba78c. The entry pointer is borrowed and must address a word ID. */
void func_020ba73c(Unk020ba678Entry *entry)
{
    Unk020ba678Storage *storage = Unk044904_Unk_045064();
    Unk020ba678Entry *selected = func_02044ec4(entry->unk_00);
    Unk020ba678State *state = func_0204acdc(selected);

    storage->id = entry->unk_00;
    state->index = 0;
    state->unk_4a = 100;
    func_0204afe0(state, 0);
    func_0204b044(state);
    func_020ba78c(0);
}

/* ARM 0x020ba78c: appends one command for the selected shared-record ID.
 * `arg` becomes the record's +0x4a operand after the command is built. The
 * command slots wrap from index 2 back to 1, so index 0 is only used first. */
void func_020ba78c(s32 arg)
{
    Unk020ba678Storage *storage = Unk044904_Unk_045064();
    Unk020ba678Entry *entry = func_02044ec4(storage->id);
    Unk020ba678State *state = func_0204acdc(entry);
    Unk020ba678Command *command = &entry->commands[state->index];

    if (state->unk_44 & 1) {
        Unk020ba678Sub *sub = func_020b8ac8();
        sub->unk_0c |= 0x80;
    }
    command->unk_00 = storage->id;
    command->unk_14 = func_020ba838(func_020b8ac8(), entry, command,
                                    state->unk_4a);
    state->unk_4a = arg;
    if (state->index != 0) {
        func_020aa188(Unk044904_Unk_044fd8(), command);
    }
    state->index++;
    if (state->index >= 2) {
        state->index = 1;
    }
}

/* ARM 0x020ba838: fills one 24-byte command from the shared sub-record and
 * returns the ID-tagged token for +0x14. Kind selects the command layout;
 * kinds outside 1..5 leave only that token. All pointers are borrowed. */
u32 func_020ba838(Unk020ba678Sub *sub, Unk020ba678Entry *entry,
                  Unk020ba678Command *command, s32 arg)
{
    u32 token = func_020b0874(entry->unk_00, arg) | 0x50000000;

    switch (sub->unk_00) {
    case 1:
        command->unk_08 = 1;
        command->unk_04 = func_0204ebb4(command, entry->unk_00,
                                        sub->unk_0c, sub->unk_10);
        break;
    case 2:
        command->unk_08 = 6;
        command->unk_0c = sub->unk_04;
        command->unk_04 = func_0204ebb4(command, entry->unk_00,
                                        sub->unk_0c, sub->unk_10);
        break;
    case 3:
        command->unk_08 = 4;
        command->unk_04 = entry->unk_00;
        break;
    case 4:
        command->unk_08 = 2;
        command->unk_04 = entry->unk_00;
        break;
    case 5:
        command->unk_08 = 0;
        break;
    /* Case 6 is an empty entry in the original seven-slot jump table; kinds 0
     * and 6 both fall through to the return without touching the command. */
    case 6:
        break;
    }
    return token;
}
