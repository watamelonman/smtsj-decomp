#include "types.h"

/* Evidence: 020b8b18 stores selector as a halfword at shared-record +0x0c
 * and value as a word at +0x10. Selector meanings remain unidentified. */
extern void func_020b8b18(u32 selector, u32 value);

/* Evidence: original 0x020ba0a4 passes (1, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0a4(void)
{
    func_020b8b18(1, 0);
    return 1;
}

/* Evidence: original 0x020ba0bc passes (2, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0bc(void)
{
    func_020b8b18(2, 0);
    return 1;
}

/* Evidence: original 0x020ba0d4 passes (3, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0d4(void)
{
    func_020b8b18(3, 0);
    return 1;
}

/* Evidence: original 0x020ba0ec passes (4, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba0ec(void)
{
    func_020b8b18(4, 0);
    return 1;
}

/* Evidence: original 0x020ba104 passes (5, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba104(void)
{
    func_020b8b18(5, 0);
    return 1;
}

/* Evidence: original 0x020ba11c passes (6, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba11c(void)
{
    func_020b8b18(6, 0);
    return 1;
}

/* Evidence: original 0x020ba1b4 passes (11, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba1b4(void)
{
    func_020b8b18(11, 0);
    return 1;
}

/* Evidence: original 0x020ba1cc passes (12, 0) to 020b8b18 and returns 1.
 * No incoming arguments are consumed; the helper's result is ignored. */
s32 func_020ba1cc(void)
{
    func_020b8b18(12, 0);
    return 1;
}
