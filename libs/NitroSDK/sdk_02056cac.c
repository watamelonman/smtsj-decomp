#include "types.h"

/* Borrowed eight-byte entries; bitfields hold three callback arguments. */
typedef struct {
    void *source;
    u32 low : 11;
    u32 middle : 11;
    u32 high : 4;
    u32 flags : 6;
} Unk056cacEntry;

/* Only the prefix through the callback at +0x201c is accessed here. */
typedef struct {
    u32 active;
    u32 unknown04;
    Unk056cacEntry entries[1024];
    u8 unknown2008[20];
    u32 (*callback)(u32, u32, u32);
} Unk056cacWork;

/* Caller-independent queue packet copied synchronously by the provider. */
typedef struct {
    void *source;
    u32 value;
    u32 result;
    u32 progress;
    void (*callback)(void *);
    void *argument;
    Unk056cacEntry *entry;
} Unk056cacPacket;

/* Provider-owned parameter block: five scalar words followed by nine vector components. */
typedef struct {
    s32 scalar[5];
    s32 vectors[9];
} Unk056cacParameters;

/* Borrowed state; only bytes +0x10 through +0x12 are established here. */
typedef struct {
    u8 unknown00[16];
    u8 state;
    s8 index;
    s8 previous;
} Unk056cacState;

extern Unk056cacWork *func_02056110(int index);
extern void func_0205bfd0(Unk056cacEntry *entries);
extern void func_02056cd0(int engine, u32 slot, const void *source, u32 count);
extern void func_0205bf18(Unk056cacEntry *entries, const Unk056cacPacket *packet);
extern void func_0205c0ec(Unk056cacEntry *entries);
extern void func_02056ecc(void);
extern void func_02056f58(void);
extern Unk056cacParameters data_021683c8;
extern Unk056cacState data_0215f05c;
void func_020572d8(void);

/* Passes the selected work area's entry base (+8) to the queue-pop provider;
 * evidence: 0x02056cac calls 0x02056110 then 0x0205bfd0. */
void func_02056cac(int index)
{
    func_0205bfd0(func_02056110(index)->entries);
}

/* Submits exactly one 512-byte transfer via the neighbouring provider;
 * evidence: 0x02056cd0 shifts its fourth argument left by nine. */
void func_02056cc0(int engine, u32 slot, const void *source)
{
    func_02056cd0(engine, slot, source, 1);
}

/* Builds a borrowed-entry queue packet; the callback arguments are bits
 * 22..25, 0..10 and 11..21 of the entry word (0x02056dbc..0x02056de0).
 * The caller must supply a valid work and entry index. */
void func_02056d88(int index, int entryIndex, u32 value, void (*callback)(void *), void *argument)
{
    Unk056cacWork *work = func_02056110(index);
    Unk056cacEntry *entries = work->entries;
    Unk056cacEntry *entry = &entries[entryIndex];
    u32 result = work->callback(entry->high, entry->low, entry->middle);
    Unk056cacPacket packet;
    packet.source = entry->source;
    packet.value = value;
    packet.result = result;
    packet.progress = 0;
    packet.callback = callback;
    packet.argument = argument;
    packet.entry = entry;
    func_0205bf18(work->entries, &packet);
}

/* Services each active engine queue; evidence: the two-iteration loop and
 * the active-word test at 0x02056e20..0x02056e3c. */
void func_02056e10(void)
{
    int index;
    for (index = 0; index < 2; index++) {
        Unk056cacWork *work = func_02056110(index);
        if (work->active != 0) {
            func_0205c0ec(work->entries);
        }
    }
}

/* Clears display-control bits 13..15 on both engines; evidence: hardware
 * addresses 0x04000000 and 0x04001000 at 0x02056e44..0x02056e64. */
void func_02056e44(void)
{
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
}

/* Restores scalar defaults and Q12 vector components; evidence: the
 * fourteen word stores to data_021683c8 at 0x02056e68..0x02056eb8. */
void func_02056e68(void)
{
    data_021683c8.scalar[0] = 2048;
    data_021683c8.scalar[1] = 3547;
    data_021683c8.scalar[2] = 5461;
    data_021683c8.scalar[3] = 4096;
    data_021683c8.scalar[4] = 1638400;
    data_021683c8.vectors[0] = 0;
    data_021683c8.vectors[1] = 0;
    data_021683c8.vectors[2] = 4096;
    data_021683c8.vectors[3] = 0;
    data_021683c8.vectors[4] = 0;
    data_021683c8.vectors[5] = 0;
    data_021683c8.vectors[6] = 0;
    data_021683c8.vectors[7] = 4096;
    data_021683c8.vectors[8] = 0;
}

/* Runs the four initialization stages in their original order; evidence:
 * the call sequence at 0x020572c4..0x020572d0. */
void func_020572c0(void)
{
    func_02056e68();
    func_02056ecc();
    func_02056f58();
    func_020572d8();
}

/* Clears the state byte and sets both index bytes to the 0xff sentinel;
 * evidence: byte stores at 0x020572e0, 0x020572e8 and 0x020572ec. */
void func_020572d8(void)
{
    data_0215f05c.state = 0;
    data_0215f05c.index = -1;
    data_0215f05c.previous = -1;
}
