#include "types.h"

/** Borrowed CRI state; its layout is private to the provider. */
typedef struct Unk0208a978State Unk0208a978State;
/** Borrowed CRI argument block; wrappers pass it through without inspecting it. */
typedef struct Unk0208a978Argument Unk0208a978Argument;

extern s32 data_02148da4;
extern Unk0208a978State *data_02148da8;

extern s32 func_02083708(void);
extern void func_0208ae78(void);
extern void func_0208ae7c(void);
extern s32 func_0208ae80(Unk0208a978State *state, s32 argument);
extern void func_0208af40(Unk0208a978State *state);
extern void func_0208b0c4(Unk0208a978State *state, Unk0208a978Argument *argument);
extern s32 func_0208b10c(Unk0208a978State *state, Unk0208a978Argument *argument);
extern void func_0208ab44(Unk0208a978Argument *argument);
extern s32 func_0208ab84(Unk0208a978Argument *argument);

/** Store the opaque mode word; the STR at 0208a97c establishes the destination. */
void func_0208a978(s32 mode)
{
    data_02148da4 = mode;
}

/** Preserve explicit modes; resolve -1 to 2 or 1 from the probe at 0208aa78. */
s32 func_0208aa68(s32 mode)
{
    if (mode != -1) return mode;
    return func_02083708() == 1 ? 2 : 1;
}

/** Forward the borrowed state and global word, as loaded at 0208aa98..0208aa9c. */
s32 func_0208aa8c(void)
{
    /* See DEC-028: the original literal has no symbol relocation. */
    return func_0208ae80(data_02148da8, *(s32 *)0x0212ed94);
}

/** Forward the borrowed global state to the provider selected at 0208aab4. */
void func_0208aab0(void)
{
    func_0208af40(data_02148da8);
}

/** Bracket argument forwarding with the ordered helper pair (0208ab30..0208ab3c). */
void func_0208ab28(Unk0208a978Argument *argument)
{
    func_0208ae78();
    func_0208ab44(argument);
    func_0208ae7c();
}

/** Supply the global state before the borrowed argument (0208ab4c..0208ab54). */
void func_0208ab44(Unk0208a978Argument *argument)
{
    func_0208b0c4(data_02148da8, argument);
}

/** Preserve the provider result across the trailing helper (0208ab74..0208ab7c). */
s32 func_0208ab60(Unk0208a978Argument *argument)
{
    s32 result;
    func_0208ae78();
    result = func_0208ab84(argument);
    func_0208ae7c();
    return result;
}

/** Supply global state and return the provider word (0208ab8c..0208ab94). */
s32 func_0208ab84(Unk0208a978Argument *argument)
{
    return func_0208b10c(data_02148da8, argument);
}
