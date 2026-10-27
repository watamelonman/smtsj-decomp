#include "libs/NitroSDK/sdk_020580ec.h"

/** Module state at 0x02168b24; bit 15 is the flag changed by func_020580ec. */
extern u32 data_02168b24;

/** Name marker separating character flags from palette flags; the pointer word is at
 * 0x02143ba4 and points at the literal "Plt:". */
extern const char *data_02143ba4;

/** Byte-array substring search, same contract as strstr. */
extern const char *func_02015498(const char *text, const char *needle);
/** Byte-array length, same contract as strlen. */
extern int func_02015118(const char *text);
/** Fatal SDK termination; the original never returns. */
extern void func_02007e94(void);

extern void func_0200303c(u32 flags);
extern void func_02003214(u32 flags);
extern void func_02002ab0(u32 flags);
extern void func_02002e90(u32 flags);
extern void func_0200331c(u32 flags);
extern void func_020033c4(u32 flags);
extern void func_02002d40(u32 flags);
extern void func_02002f90(u32 flags);
extern void func_02003434(u32 flags);
extern void func_020034b4(u32 flags);

/** Sets bit 15 of the module state when enable is exactly one; any other value clears
 * it. Callers pass zero and one around graphics setup. */
void func_020580ec(int enable)
{
    if (enable == 1) {
        data_02168b24 |= 0x8000;
    } else {
        data_02168b24 &= ~0x8000;
    }
}

/** Parses resource-name flags. Letters A-I set bits 0-8 in the current flag word; the
 * word switches from flags to paletteFlags after the "Plt:" marker, which is skipped.
 * Returns one when the marker exists. See DEC-034 for the volatile character reads that
 * preserve the original load schedule. */
int func_0205811c(const char *name, u32 *flags, u32 *paletteFlags)
{
    const char *markerText;
    const char *marker;
    const volatile s8 *cursor;
    u32 *destination;

    markerText = data_02143ba4;
    marker = func_02015498(name, markerText);
    cursor = (const volatile s8 *)name;
    destination = flags;
    *flags = 0;
    *paletteFlags = 0;
    while (*cursor != 0) {
        switch (*cursor) {
        case 'A':
            *destination |= 0x001;
            break;
        case 'B':
            *destination |= 0x002;
            break;
        case 'C':
            *destination |= 0x004;
            break;
        case 'D':
            *destination |= 0x008;
            break;
        case 'E':
            *destination |= 0x010;
            break;
        case 'F':
            *destination |= 0x020;
            break;
        case 'G':
            *destination |= 0x040;
            break;
        case 'H':
            *destination |= 0x080;
            break;
        case 'I':
            *destination |= 0x100;
            break;
        }
        cursor++;
        if ((const s8 *)marker == cursor) {
            destination = paletteFlags;
            cursor += func_02015118(markerText);
        }
    }
    return marker != 0;
}

/** Applies a name's character and palette flags to the first accessor pair. A name without
 * the "Plt:" marker is fatal because the resource would have no palette assignment. */
void func_02058258(const char *name)
{
    u32 flags;
    u32 paletteFlags;

    if (!func_0205811c(name, &flags, &paletteFlags)) {
        func_02007e94();
    }
    func_0200303c(flags);
    func_02003214(paletteFlags);
}

/** Applies a name's flags through the accessor pair selected by mode. The character half is
 * always applied; the palette half needs the "Plt:" marker that fills paletteFlags. */
void func_02058290(int mode, const char *name)
{
    u32 flags;
    u32 paletteFlags;
    int hasMarker;

    hasMarker = func_0205811c(name, &flags, &paletteFlags);
    if (mode == 0) {
        func_02002ab0(flags);
        if (!hasMarker) {
            return;
        }
        func_02002e90(paletteFlags);
    } else {
        func_0200331c(flags);
        if (!hasMarker) {
            return;
        }
        func_020033c4(paletteFlags);
    }
}

/** Same flag application as func_02058290, using the second character/palette accessor
 * pair. */
void func_02058300(int mode, const char *name)
{
    u32 flags;
    u32 paletteFlags;
    int hasMarker;

    hasMarker = func_0205811c(name, &flags, &paletteFlags);
    if (mode == 0) {
        func_02002d40(flags);
        if (!hasMarker) {
            return;
        }
        func_02002f90(paletteFlags);
    } else {
        func_02003434(flags);
        if (!hasMarker) {
            return;
        }
        func_020034b4(paletteFlags);
    }
}
