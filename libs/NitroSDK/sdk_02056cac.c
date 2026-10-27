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

/* Private 184-byte geometry record; only the words written by the reset
 * helper are named. The untouched hole at +0x24..+0x83 stays a pad. */
typedef struct {
    s32 unk_0000;
    s32 unk_0004;
    s32 unk_0008;
    s32 unk_000c;
    s32 unk_0010;
    s32 unk_0014;
    s32 unk_0018;
    s32 unk_001c;
    s32 unk_0020;
    s32 pad_0024[24];
    s32 unk_0084;
    s32 unk_0088;
    s32 unk_008c;
    s32 unk_0090;
    s32 unk_0094;
    s32 unk_0098;
    s32 unk_009c;
    s32 unk_00a0;
    s32 unk_00a4;
    s32 unk_00a8;
    s32 unk_00ac;
    s32 unk_00b0;
    u16 unk_00b4;
    u16 unk_00b6;
} Unk056cacSlot;

extern Unk056cacWork *func_02056110(int index);
extern void func_0205bfd0(Unk056cacEntry *entries);
extern void func_02056cd0(int engine, u32 slot, void *source, u32 count);
extern u32 func_020038ac(void);
extern u32 func_0200390c(void);
extern void func_02006c94(void *source, u32 bytes);
extern void func_020050c4(void);
extern void func_0200510c(void *source, u32 offset, u32 bytes);
extern void func_02005178(void);
extern void func_02004760(void *source, u32 offset, u32 bytes);
extern void func_02005278(void);
extern void func_02005290(void *source, u32 offset, u32 bytes);
extern void func_020052f4(void);
extern void func_020047b8(void *source, u32 offset, u32 bytes);
extern void func_0205bf18(Unk056cacEntry *entries, const Unk056cacPacket *packet);
extern void func_0205c0ec(Unk056cacEntry *entries);
/* The 872-byte eight-record initializer remains delinked; see the TU's
 * docs/functions page for the attempted source forms and hard-list entry. */
extern void func_02056f58(void);
extern Unk056cacParameters data_021683c8;
extern Unk056cacSlot data_0216846c;
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
void func_02056cc0(int engine, u32 slot, void *source)
{
    func_02056cd0(engine, slot, source, 1);
}

/* Uploads the caller-owned buffer to main (engine zero) or sub OBJ palette
 * memory. A nonzero allocated extended-palette bank mask from func_020038ac
 * or func_0200390c selects the extended upload with begin/end calls;
 * otherwise func_02004760/020047b8 target standard OBJ palettes at
 * 0x05000200/0x05000600. Evidence: those destination addresses and the
 * extended-palette loaders func_0200510c/02005290. `slot` is the destination
 * offset and `count` the upload length, both in 512-byte units. */
void func_02056cd0(int engine, u32 slot, void *source, u32 count)
{
    u32 ready = 1;
    u32 status;

    if (engine == 0)
        status = func_020038ac();
    else
        status = func_0200390c();
    if (status == 0)
        ready = 0;
    func_02006c94(source, count << 9);
    if (engine == 0) {
        if (ready != 0) {
            func_020050c4();
            func_0200510c(source, slot << 9, count << 9);
            func_02005178();
        } else {
            func_02004760(source, slot << 9, count << 9);
        }
    } else {
        if (ready != 0) {
            func_02005278();
            func_02005290(source, slot << 9, count << 9);
            func_020052f4();
        } else {
            func_020047b8(source, slot << 9, count << 9);
        }
    }
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

/* Resets the first 184-byte geometry record to its identity/default ranges:
 * a signed extent pair at +0x08/+0x14, a 0x1000 step at +0x1c, and the
 * scale/bounds block at +0x84..+0xb6. The remaining records (+0xb8 each)
 * are handled by func_02056f58. Evidence: the stores to data_0216846c at
 * 0x02056ecc..0x02056f50 and the 0xb8 stride used by the 020572f8 unit. */
void func_02056ecc(void)
{
    data_0216846c.unk_0000 = 0;
    data_0216846c.unk_0004 = 0;
    data_0216846c.unk_0008 = 0x400000;
    data_0216846c.unk_000c = 0;
    data_0216846c.unk_0010 = 0;
    data_0216846c.unk_0014 = -0x400000;
    data_0216846c.unk_0018 = 0;
    data_0216846c.unk_001c = 0x1000;
    data_0216846c.unk_0020 = 0;
    data_0216846c.unk_0084 = 0;
    data_0216846c.unk_0088 = 0xc0000;
    data_0216846c.unk_008c = 0;
    data_0216846c.unk_0090 = 0x100000;
    data_0216846c.unk_0094 = 0;
    data_0216846c.unk_0098 = 0x800000;
    data_0216846c.unk_00a4 = 0;
    data_0216846c.unk_00a8 = 0;
    data_0216846c.unk_00ac = 0;
    data_0216846c.unk_00b0 = 0;
    data_0216846c.unk_00b4 = 0;
    data_0216846c.unk_00b6 = 0;
    data_0216846c.unk_009c = -500;
    data_0216846c.unk_00a0 = 10;
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
