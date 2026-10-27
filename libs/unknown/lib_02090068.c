/* Mobiclip stream wrapper helpers reconstructed from the delinked ARM code at
 * 0x02090068..0x020901dc. The six small entry points are complete; the large
 * colour-conversion blit at 0x020901e0 is still supplied by the original
 * object (see docs/functions/libs-unknown-lib-02090068.md). */
#include "libs/unknown/lib_02090068.h"

/* The file helpers are the NitroSDK FS close/seek/read primitives used by the
 * neighbouring resource units; see docs/functions/libs-nitrosdk-sdk-02051378.md. */
extern void func_0200bdec(void *file);
extern int func_0200bf14(void *file, u32 offset, u32 origin);
extern int func_0200bf04(void *file, void *buffer, u32 size);
extern int func_0200bef4(void *file, void *buffer, u32 size);

/* Seek the wrapped file to `size` and make it the new position. The open flag
 * is cleared first so a previous read window is not reused. Evidence: the
 * close call at 02090084, the seek call at 0209009c with origin 0, and the
 * conditional store of `size` to +8 at 020900a8. */
int func_02090068(Lib02090068Stream *stream, u32 size)
{
    if (stream->open_10 == 1) {
        func_0200bdec(stream->file_0c);
        stream->open_10 = 0;
    }
    if (func_0200bf14(stream->file_0c, size, 0) == 0) {
        return 0;
    }
    stream->position_08 = size;
    return 1;
}

/* Read `size` bytes into `buffer` at the recorded position and advance that
 * position. The stored position is re-seeked before reading because the open
 * flag marks a read window left by func_02090124. Evidence: the seek of +8 at
 * 020900e4 and the +8 increment at 0209011c. */
int func_020900b4(Lib02090068Stream *stream, void *buffer, u32 size)
{
    if (stream->open_10 == 1) {
        func_0200bdec(stream->file_0c);
        func_0200bf14(stream->file_0c, stream->position_08, 0);
        stream->open_10 = 0;
    }
    if (func_0200bf04(stream->file_0c, buffer, size) == -1) {
        return 0;
    }
    stream->position_08 += size;
    return 1;
}

/* Read the 0x200-byte aligned block covering the recorded position, returning
 * the byte offset of the position inside that block. The direct read fills the
 * caller's buffer with the rounded-up block; the open flag then tells
 * func_020900b4 to re-seek on its next call. Evidence: the 0xfffffe00 mask and
 * the `(total & ~mask) + 0x200` rounding at 0209012c..02090154, the seek to the
 * block base at 02090160, the direct read at 02090170, and the +8 increment and
 * open-byte store at 02090184..02090198. */
int func_02090124(Lib02090068Stream *stream, void *buffer, u32 size)
{
    u32 position = stream->position_08;
    u32 mask = 0xfffffe00;
    u32 aligned = position & mask;
    u32 offset = position - aligned;
    u32 total = size + offset;

    if ((total & ~mask) != 0) {
        total = (total & mask) + 0x200;
    }
    func_0200bf14(stream->file_0c, aligned, 0);
    if (func_0200bef4(stream->file_0c, buffer, total) == -1) {
        return 0;
    }
    stream->position_08 += size;
    stream->open_10 = 1;
    return offset;
}

/* Close the wrapped file if the open byte is set, then clear the byte even
 * when it was already clear. Evidence: the conditional close at 020901b4 and
 * the unconditional byte store at 020901c0. */
void func_020901a0(Lib02090068Stream *stream)
{
    if (stream->open_10 == 1) {
        func_0200bdec(stream->file_0c);
    }
    stream->open_10 = 0;
}

/* Virtual dispatch: the object's +0x00 word points at the method table whose
 * slot 5 (byte offset 0x14) is called with the object unchanged. Evidence: the
 * double load and `blx r1` at 020901cc..020901d4; the sibling table at
 * 0x0214c684 lists the other wrapper methods, so this is a vtable call. */
void func_020901c8(Lib02090068Stream *stream)
{
    stream->vtable_00[5](stream);
}

/* Empty function: the delinked body is exactly `bx lr`. */
void func_020901dc(void)
{
}
