#include "types.h"

/* Preserve the four 64-slot banks and inclusive byte bounds observed in the
 * global accesses; callers must configure bounds within 0..63. */
typedef struct Unk06d950Slots {
    u8 used[4][64];
    u8 first;
    u8 last;
} Unk06d950Slots;

extern Unk06d950Slots data_0216b9c0;
void func_02008848(void *dest, s32 value, u32 size);
void func_02057e30(u32 slot);

/* Add a signed step to a borrowed halfword, clamping toward the supplied limit. */
void func_0206d950(s16 *value, s32 step, s32 limit)
{
    s32 next = *value + step;
    if (step >= 0) {
        if (next > limit) next = limit;
    } else {
        if (next < limit) next = limit;
    }
    *value = next;
}

/* Reset the flag banks and notify each slot in the caller's byte-sized range.
 * A nonempty range must fit within the 64 slots without byte wraparound. */
void func_0206d97c(u8 first, s32 count)
{
    s32 end;
    func_02008848(&data_0216b9c0, 0, 0x102);
    end = first + count;
    data_0216b9c0.first = first;
    data_0216b9c0.last = end - 1;
    for (; first < end; first++) func_02057e30(first);
}

/* Claim the first free slot in a bank; banks 1/2 search backward, 0/3 forward.
 * Returns and notifies slot 63 when no slot is available. */
u32 func_0206d9d8(u32 bank)
{
    u8 slot;
    switch (bank) {
    case 0:
    case 3:
        for (slot = data_0216b9c0.first; slot <= data_0216b9c0.last; slot++) {
            if (!data_0216b9c0.used[bank][slot]) {
                data_0216b9c0.used[bank][slot] = 1;
                func_02057e30(slot);
                return slot;
            }
        }
        break;
    case 1:
    case 2:
        for (slot = data_0216b9c0.last; slot >= data_0216b9c0.first; slot--) {
            if (!data_0216b9c0.used[bank][slot]) {
                data_0216b9c0.used[bank][slot] = 1;
                func_02057e30(slot);
                return slot;
            }
        }
        break;
    }
    func_02057e30(63);
    return 63;
}

/* Clear flags only within the configured inclusive range in all four banks. */
void func_0206daa8(void)
{
    u8 bank;
    u8 slot;
    for (bank = 0; bank < 4; bank++) {
        for (slot = data_0216b9c0.first; slot <= data_0216b9c0.last; slot++)
            data_0216b9c0.used[bank][slot] = 0;
    }
}

/* Preserve the observed 0x148-byte stride and byte-field offsets so the
 * initializer can address a record without guessing the fields' meanings.
 * The array capacity is unknown; callers own the capacity check. See DEC-008. */
typedef struct Unk06d950Record {
    u8 unk_0000;
    char name[31];
    u8 pad_0020[0x9c];
    u8 unk_00bc;
    u8 unk_00bd;
    u8 unk_00be;
    u8 pad_00bf[0x5];
    u8 unk_00c4;
    u8 unk_00c5;
    u8 unk_00c6;
    u8 pad_00c7[0x5];
    u8 unk_00cc;
    u8 unk_00cd;
    u8 unk_00ce;
    u8 pad_00cf[0x5];
    u8 unk_00d4;
    u8 unk_00d5;
    u8 unk_00d6;
    u8 pad_00d7[0x5];
    u8 unk_00dc;
    u8 unk_00dd;
    u8 unk_00de;
    u8 pad_00df[0x5];
    u8 unk_00e4;
    u8 unk_00e5;
    u8 unk_00e6;
    u8 pad_00e7[0x5];
    u8 unk_00ec;
    u8 unk_00ed;
    u8 unk_00ee;
    u8 pad_00ef[0x5];
    u8 unk_00f4;
    u8 unk_00f5;
    u8 unk_00f6;
    u8 pad_00f7[0x5];
    u8 unk_00fc;
    u8 unk_00fd;
    u8 unk_00fe;
    u8 pad_00ff[0x5];
    u8 unk_0104;
    u8 unk_0105;
    u8 unk_0106;
    u8 pad_0107[0x5];
    u8 unk_010c;
    u8 unk_010d;
    u8 unk_010e;
    u8 pad_010f[0x5];
    u8 unk_0114;
    u8 unk_0115;
    u8 unk_0116;
    u8 pad_0117[0x5];
    u8 unk_011c;
    u8 unk_011d;
    u8 unk_011e;
    u8 pad_011f[0x5];
    u8 unk_0124;
    u8 unk_0125;
    u8 unk_0126;
    u8 pad_0127[0x5];
    u8 unk_012c;
    u8 unk_012d;
    u8 unk_012e;
    u8 pad_012f[0x5];
    u8 unk_0134;
    u8 unk_0135;
    u8 unk_0136;
    u8 pad_0137[0x11];
} Unk06d950Record;

extern s32 data_0216bac4;
extern Unk06d950Record data_0216bac8[];
extern const char data_021457e4[];
void func_020086a0(u32 value, void *dest, u32 size);
s32 func_02013c14(char *dest, u32 size, const char *format, ...);
char *func_02015450(const char *text, s32 character);

/* Append a cleared record, retaining at most 30 name bytes before the first dot.
 * The "%s" format at 0x021457e4 and the '.' search establish the string handling;
 * the meaning of the byte fields and the table's capacity remain unknown.
 * Caller must provide a valid string and ensure that the table has room. */
u8 func_0206dafc(const char *name)
{
    Unk06d950Record *record;
    char *dot;
    func_020086a0(0, &data_0216bac8[data_0216bac4], 0x148);
    record = &data_0216bac8[data_0216bac4];
    func_02013c14(record->name, 31, data_021457e4, name);
    dot = func_02015450(record->name, '.');
    if (dot) *dot = 0;
    data_0216bac8[data_0216bac4].unk_00bc =
    data_0216bac8[data_0216bac4].unk_00bd =
    data_0216bac8[data_0216bac4].unk_00be =
    data_0216bac8[data_0216bac4].unk_00c4 =
    data_0216bac8[data_0216bac4].unk_00c5 =
    data_0216bac8[data_0216bac4].unk_00c6 =
    data_0216bac8[data_0216bac4].unk_00cc =
    data_0216bac8[data_0216bac4].unk_00cd =
    data_0216bac8[data_0216bac4].unk_00ce =
    data_0216bac8[data_0216bac4].unk_00d4 =
    data_0216bac8[data_0216bac4].unk_00d5 =
    data_0216bac8[data_0216bac4].unk_00d6 =
    data_0216bac8[data_0216bac4].unk_00dc =
    data_0216bac8[data_0216bac4].unk_00dd =
    data_0216bac8[data_0216bac4].unk_00de =
    data_0216bac8[data_0216bac4].unk_00e4 =
    data_0216bac8[data_0216bac4].unk_00e5 =
    data_0216bac8[data_0216bac4].unk_00e6 =
    data_0216bac8[data_0216bac4].unk_00ec =
    data_0216bac8[data_0216bac4].unk_00ed =
    data_0216bac8[data_0216bac4].unk_00ee =
    data_0216bac8[data_0216bac4].unk_00f4 =
    data_0216bac8[data_0216bac4].unk_00f5 =
    data_0216bac8[data_0216bac4].unk_00f6 =
    data_0216bac8[data_0216bac4].unk_00fc =
    data_0216bac8[data_0216bac4].unk_00fd =
    data_0216bac8[data_0216bac4].unk_00fe =
    data_0216bac8[data_0216bac4].unk_0104 =
    data_0216bac8[data_0216bac4].unk_0105 =
    data_0216bac8[data_0216bac4].unk_0106 =
    data_0216bac8[data_0216bac4].unk_010c =
    data_0216bac8[data_0216bac4].unk_010d =
    data_0216bac8[data_0216bac4].unk_010e =
    data_0216bac8[data_0216bac4].unk_0114 =
    data_0216bac8[data_0216bac4].unk_0115 =
    data_0216bac8[data_0216bac4].unk_0116 =
    data_0216bac8[data_0216bac4].unk_011c =
    data_0216bac8[data_0216bac4].unk_011d =
    data_0216bac8[data_0216bac4].unk_011e =
    data_0216bac8[data_0216bac4].unk_0124 =
    data_0216bac8[data_0216bac4].unk_0125 =
    data_0216bac8[data_0216bac4].unk_0126 =
    data_0216bac8[data_0216bac4].unk_012c =
    data_0216bac8[data_0216bac4].unk_012d =
    data_0216bac8[data_0216bac4].unk_012e =
    data_0216bac8[data_0216bac4].unk_0134 =
    data_0216bac8[data_0216bac4].unk_0135 =
    data_0216bac8[data_0216bac4].unk_0136 =
        255;
    data_0216bac4++;
    return data_0216bac4 - 1;
}
