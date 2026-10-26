#include "libs/unknown/lib_02061798.h"

/* Appends a character code; returns the result object that func_02063a44
 * forwards (distinct from func_02063a50's singleton). */
extern Unk061798ResultA *func_02063954(const void *text, u32 code);
/* Large routine behind the func_0206569c wrapper; `mode` is the second
 * argument the wrapper fixes to -1. */
extern s32 func_020656ac(void *object, s32 mode);
/* Allocates a record from the arguments and stores mode at +0x28;
 * func_020629ac forwards its first, second and fourth arguments here. */
extern void *func_02060a48(u32 a, u32 b, u32 mode);
/* Frees the slot referenced by an object's +0x14 word (call site 0x02065b74
 * passes both render objects of the shared singleton). */
extern void func_02062a00(Unk061798Object *object);
/* Applies a mode to an object before func_020658b4 forwards its value. */
extern void func_02065864(void *object, s32 mode);
/* Stores a value in its own module-level state (call site 0x020658b4). */
extern void func_020bac00(u32 value);
/* Looks up the message object for `message` (call sites 0x02065a7c and
 * 0x020a07dc pass small ids); returns null when the lookup fails. */
extern void *Unk095560_Unk_095778(s32 message);
/* Stores a value in its own module-level state (called by func_02065b98). */
extern void func_020babec(u32 value);
/* State helper called by func_0206541c and func_02065438 for their 0/1 and
 * 1/2 state pairs. */
extern void func_02065374(Unk061798Object *object);
/* Applies a flag after func_0206567c has cleared the singleton's text state. */
extern void func_0206563c(s32 flag);
/* Resets shared render state before func_02065c10 sets the new mode. */
extern void func_02065bc0(void);
/* Halfword fill used to clear the shared text buffer; r0 is the fill value,
 * r1 the destination and r2 the byte count. */
extern void func_02008644(u32 value, void *dst, u32 size);
/* Tests a per-device capability mask; callers treat non-zero as available. */
extern s32 func_02053800(u32 device, u32 mask);
/* Forwards the id 25 to the sound/command layer. */
extern void Unk0bc1a8_Unk_0bc9b4(u32 id);
/* Releases the pointer stored in the slot and clears it. */
extern void Unk0d297c_FreeSlot(void **slot);

/* The +4 word of this bss object is the shared result singleton. */
typedef struct Unk061798Bss {
    u32 unk_0000;
    Unk061798ResultB *unk_0004;
} Unk061798Bss;
extern Unk061798Bss data_0216b9a8;

/* Clears the four font-registry slot ids to -1 so func_020618cc reports them
 * as unused; the original walks the array with mla and entry size 56. The
 * target keeps that indexed mla loop instead of strength-reducing it to a
 * pointer walk, which is what -O4 does here, so the two loop options that
 * cause the rewrite are scoped off for this function. See DEC-029. */
#pragma push
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
void func_02061798(void)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        data_0216b4c0[i].unk_0020 = -1;
    }
}
#pragma pop

/* Returns the first borrowed record whose +0x20 id matches, or null when
 * none of the four slots match. Byte-stride lookup and array-index return
 * preserve the original indexed loop and pointer allocation. See DEC-031. */
#pragma push
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
Unk061798Font *func_020618cc(u32 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        Unk061798Font *entry = (Unk061798Font *)
            ((u8 *)data_0216b4c0 + i * sizeof(Unk061798Font));
        if (id == entry->unk_0020) {
            return &data_0216b4c0[i];
        }
    }
    return 0;
}
#pragma pop

/* Returns the +0x28 pointer of the font record selected by id; callers
 * dereference it (call site 0x020601f4). */
Unk061798FontData *func_0206190c(u32 id)
{
    return func_020618cc(id)->unk_0028;
}

/* Selects a font record by id; callers use the returned record's glyph table
 * directly (ldrh at +0 and at +2*index, call sites 0x02060210/0x020608a0). */
Unk061798Font *func_0206191c(u32 id)
{
    return func_020618cc(id);
}

/* Returns the 4-byte table entry at index-1 of the font record's +0x2c table,
 * or entry 0 when index-1 is at or above the signed count at +0x34. The caller
 * at 0x02061b3c reads bytes +2/+3 of the returned entry. */
u32 *func_02061928(u32 id, s32 index)
{
    s32 i = index;
    Unk061798Font *font = func_020618cc(id);
    i -= 1;
    if (i >= font->unk_0034) i = 0;
    return &font->unk_002c[i];
}

/* Returns a pointer to the first header byte of the font record selected by
 * the id in r0. */
u8 *func_02061950(u32 id)
{
    return &func_020618cc(id)->unk_0024;
}

/* Returns the first header byte of the font record selected by id; callers
 * use it as a glyph offset (call sites 0x02060c54/0x02060e50). */
u8 func_02061960(u32 id)
{
    return *func_02061950(id);
}

/* Returns the second header byte of the font record selected by the id in r0;
 * callers add it to a glyph advance (call site 0x02061b9c). */
u8 func_02061970(u32 id)
{
    return func_02061950(id)[1];
}

/* Returns the second header byte of the font record selected by the id in r0;
 * callers add it to a glyph advance (call site 0x02061b9c). */
u8 func_020619f8(u32 id)
{
    return func_02061970(id);
}

/* Sets or clears bits of `mask` in the object's +0x4 word: the original
 * compares the third argument with 1 and emits OR when equal, otherwise
 * AND with the complement (call sites 0x020605c0/0x020605cc pass 0/1). */
void func_02061e98(Unk061798Object *object, u32 mask, s32 mode)
{
    if (mode == 1) {
        object->unk_0004 |= mask;
    } else {
        object->unk_0004 &= ~mask;
    }
}

/* Tests whether any bit of `mask` is set in the object's +0x4 word; callers
 * branch on the result (call sites 0x020605a8/0x020625a8/0x020632e4). */
s32 func_02061eb4(Unk061798Object *object, u32 mask)
{
    return (object->unk_0004 & mask) != 0;
}

/* Returns count times the object's glyph advance: func_02061960 supplies the
 * first header byte of the font record selected by the object's font id, and
 * the signed byte at +0x35 is added to it before the multiply. */
s32 func_0206232c(Unk061798Object *object, s32 count)
{
    s32 advance = func_02061960(object->unk_0028);
    advance += object->unk_0035;
    return count * advance;
}

/* Forwards the first, second and fourth arguments to func_02060a48 and drops
 * the third: callers set all four registers before calling (call sites
 * 0x02065f54/0x02066940/0x0211d5c0), and the original moves r3 into r2.
 * Returns the allocated record, or null when allocation failed. */
void *func_020629ac(u32 a, u32 b, u32 ignored, u32 c)
{
    void *result = func_02060a48(a, b, c);
    if (result == 0) return 0;
    return result;
}

/* Releases the object's +0x14 slot when the field is non-null and the state
 * word at +0xc is 1 or 3; func_02065b74 calls it on both singleton render
 * objects (call sites 0x02065b88/0x02065b90). */
void func_02062a00(Unk061798Object *object)
{
    if (object->unk_0014 == 0) return;
    if (object->unk_000c != 1 && object->unk_000c != 3) return;
    Unk0d297c_FreeSlot(&object->unk_0014);
}

/* Reads the font id at +0x28 of a render object and returns the +0x28 pointer
 * of the selected font record (call sites 0x02060614/0x02060a38/0x020620a8). */
Unk061798FontData *func_02062a2c(Unk061798Object *object)
{
    return func_0206190c(object->unk_0028);
}

/* True when the object's +0x10 word is neither 0 nor 1; the original tests
 * both values with `cmp #0; cmpne #1` and branches to a +1 return. */
s32 func_02062a3c(Unk061798Object *object)
{
    u32 value = object->unk_0010;
    switch (value) {
    case 0:
    case 1:
        return 0;
    default:
        return 1;
    }
}

/* Returns 1 when the object's +0x10 word is 2 or 3, else 0; the caller at
 * 0x02064224 returns early when the result is zero. The negated conjunction
 * keeps the original `cmp #2; cmpne #3` with predicated 0/1 results. */
s32 func_02062a5c(Unk061798Object *object)
{
    u32 value = object->unk_0010;
    if (value != 2 && value != 3) return 0;
    return 1;
}

/* True when the object's +0x10 word is zero; callers return early when the
 * result is non-zero (call site 0x02060b94). */
s32 func_02062a74(Unk061798Object *object)
{
    return object->unk_0010 == 0;
}

/* Clears the two halfwords at +0x4c and +0x4e of a render object; call site
 * 0x02063418 does this while resetting the object's text state. */
void func_02063490(Unk061798Object *object)
{
    object->unk_004e = 0;
    object->unk_004c = 0;
}

/* Stores the 32-bit value at +0x30 of a render object; callers use it to
 * update the active glyph record (call sites 0x02060318/0x02060550/0x02060654). */
void func_0206357c(Unk061798Object *object, u32 value)
{
    object->unk_0030 = value;
}

/* Stores the byte at +0x34 of a render object; callers store a mode
 * (0/1/2) or a count before advancing (call sites 0x02062634/0x02063640). */
void func_02063584(Unk061798Object *object, s8 value)
{
    object->unk_0034 = value;
}

/* Copies the signed byte at +0x81 of a render object into the byte at +0x34;
 * call sites 0x0206255c/0x0206258c/0x020636b8 use it to apply a stored mode. */
void func_0206358c(Unk061798Object *object)
{
    func_02063584(object, object->unk_0081);
}

/* Stores the 32-bit value at +0x48 of a render object; call site 0x02063e88
 * uses it to clear the field on the object's first pointer. */
void func_0206359c(Unk061798Object *object, u32 value)
{
    object->unk_0048 = value;
}

/* Clears the 1024-byte text buffer and re-points the descriptor at
 * data_0216b5a0 to it with a zero length; many callers reset the buffer
 * before appending (call sites 0x02067310/0x0206a2cc/0x02090d4c). */
void func_02063920(void)
{
    func_02008644(0, data_0216b5a8, sizeof(data_0216b5a8));
    data_0216b5a0.unk_0000 = data_0216b5a8;
    data_0216b5a0.unk_0004 = 0;
}

/* Tail wrapper that appends code 0x8001 to a text object and returns the
 * resulting record; call site 0x0206733c keeps it across a loop. */
Unk061798ResultA *func_02063a30(const void *text)
{
    return func_02063954(text, 0x8001);
}

/* Forwards a character append to func_02063954; callers keep the returned
 * pointer (call sites 0x0211c464/0x0211d8f8/0x0211d93c). */
Unk061798ResultA *func_02063a44(const void *text, u32 code)
{
    return func_02063954(text, code);
}

/* Returns the +4 word of data_0216b9a8, the shared result singleton; callers
 * test it for null before reading fields (call sites 0x020654d0/0x02065530). */
Unk061798ResultB *func_02063a50(void)
{
    return data_0216b9a8.unk_0004;
}

/* Returns the shared singleton through func_02063a50; callers read its fields
 * and treat null as "not initialised" (call sites 0x020641c8/0x0206545c). */
Unk061798ResultB *func_02063a60(void)
{
    return func_02063a50();
}

/* When device 0 reports mask 1, marks the object's +0x24 word as 1 and clears
 * its +0x2c word, then returns the query result; a zero query leaves the
 * object untouched and returns zero. The original keeps the result in r0
 * across the stores (call sites 0x02064150/0x0206418c/0x02064198). */
s32 func_02063f54(Unk061798Object *object)
{
    s32 result = func_02053800(0, 1);
    if (result == 0) return result;
    object->unk_0024 = 1;
    object->unk_002c = 0;
    return result;
}

/* Increments the shared singleton's +0x28 word and wraps it to zero once it
 * reaches 0xffff; the original keeps 0xffff in r1 across the compare. Call
 * site 0x02063b88 invokes it before func_020641f0. */
void func_020641c4(void)
{
    Unk061798ResultB *result = func_02063a60();
    s32 value = result->unk_0028 + 1;
    result->unk_0028 = value;
    if (value >= 0xffff) result->unk_0028 = 0;
}

/* Decrements the signed byte at +0x68 of the object, but only while the shared
 * singleton's render object makes func_0206557c return non-zero; it returns
 * without touching the object when func_0206557c returns zero. Caller
 * 0x02063b90 invokes it after func_020641c4. */
void func_020641f0(Unk061798Object *object)
{
    if (func_0206557c() == 0) return;
    if (object->unk_0068 > 0) object->unk_0068--;
}

/* True when the object's signed +0x68 byte is positive; call site 0x02064294
 * uses it to pick between two field updates. */
s32 func_020642a8(Unk061798Object *object)
{
    return object->unk_0068 > 0;
}

/* True when the object's +0x38 word is neither 1 nor 3; the original tests
 * both values with `cmp #1; cmpne #3` and branches to a +1 return. */
s32 func_0206431c(Unk061798Object *object)
{
    u32 value = object->unk_0038;
    switch (value) {
    case 1:
    case 3:
        return 0;
    default:
        return 1;
    }
}

/* True when the object's +0x44 word is neither 1 nor 3; same compare shape as
 * func_0206431c but on the +0x44 word. */
s32 func_0206433c(Unk061798Object *object)
{
    u32 value = object->unk_0044;
    switch (value) {
    case 1:
    case 3:
        return 0;
    default:
        return 1;
    }
}

/* Stores 2 at +0x8 and 5 at +0xc of the object; call site 0x02065488 resets
 * these before writing two bytes at +0x54/+0x55. */
void func_0206435c(Unk061798Object *object)
{
    object->unk_0008 = 2;
    object->unk_000c = 5;
}

/* Calls func_02065374 when the object's +0x6c word is 0 or 2 and returns
 * otherwise. The function address is loaded at 0x02065f20 for use as a
 * callback; the original keeps the word in r1 across the two compares. */
void func_0206541c(Unk061798Object *object)
{
    s32 state = object->unk_006c;
    if (state == 0 || state == 2) func_02065374(object);
}

/* Calls func_02065374 when the object's +0x6c word is 1 or 2 and returns
 * otherwise; the original keeps the word in r1 across the two compares and a
 * `popne`. */
void func_02065438(Unk061798Object *object)
{
    s32 state = object->unk_006c;
    if (state != 1 && state != 2) return;
    func_02065374(object);
}

/* Returns 1 when func_02063a50, the shared result singleton, exists; call
 * sites 0x0203bda4/0x020964b4 test the result. */
s32 func_0206552c(void)
{
    return func_02063a50() != 0;
}

/* Reads the render object at +0 of the shared result singleton and returns
 * func_02062a3c's answer for it; returns 0 when the singleton is absent. */
s32 func_0206557c(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return 0;
    return func_02062a3c(result->unk_0000);
}

/* Returns the signed word at +0x5c of the shared result singleton, or 0 when
 * the singleton is absent (call site 0x0204b1a4 compares it with 1). */
s32 func_0206559c(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return 0;
    return result->unk_005c;
}

/* Stores value at +0 of data_0216b9a8, the bss object behind the shared
 * singleton; call sites 0x020f7b4c/0x020f7b58 store a boolean. */
void func_02065604(u32 value)
{
    data_0216b9a8.unk_0000 = value;
}

/* Stores value at +0x1c of the func_02063a60 singleton; call sites
 * 0x020dfe1c/0x020dfe28 store a boolean. */
void func_02065614(u32 value)
{
    func_02063a60()->unk_001c = value;
}

/* Stores value at +0x20 of the func_02063a60 singleton; callers at
 * 0x020dfdfc/0x0211c4ac keep the argument in r4 across the call. */
void func_02065628(u32 value)
{
    func_02063a60()->unk_0020 = value;
}

/* Clears the +0x60 and +0x64 words of the func_02063a60 singleton, then
 * forwards the same zero to func_0206563c. The reused local keeps the zero in
 * r1, matching the original `mov r0, r1` before the call. */
void func_0206567c(void)
{
    Unk061798ResultB *result = func_02063a60();
    s32 zero = 0;
    result->unk_0060 = zero;
    result->unk_0064 = zero;
    func_0206563c(zero);
}

/* Tail wrapper for func_020656ac that fixes the second argument to -1; call
 * sites 0x0203c690/0x020d20dc/0x020dfe5c ignore the result. */
s32 func_0206569c(void *object)
{
    return func_020656ac(object, -1);
}

/* Tail wrapper for func_020658b4 that fixes both mode arguments to 1; call
 * site 0x021107fc passes the object held in r4. */
void func_020658a0(void *object)
{
    func_020658b4(object, 1, 1);
}

/* Applies `mode` to the object through func_02065864, then stores `value`
 * through func_020bac00 unless mode is -1. Call site 0x020658e4 forwards its
 * own first three arguments unchanged. */
void func_020658b4(void *object, s32 mode, u32 value)
{
    func_02065864(object, mode);
    if (mode == -1) return;
    func_020bac00(value);
}

/* Calls func_02063a60 with its result unused, then looks up the
 * message object for `message`; when the lookup succeeds it hands the object
 * to func_020656ac with mode -1. Call sites 0x020a07dc and 0x02065a7c pass
 * small message ids (4 and 13). */
void func_0206597c(s32 message)
{
    func_02063a60();
    void *object = Unk095560_Unk_095778(message);
    if (object == 0) return;
    func_020656ac(object, -1);
}

/* Releases both render objects of the func_02063a50 singleton through
 * func_02062a00 (the pointers at +0 and +4); does nothing when the singleton
 * is absent. Call sites 0x0204809c/0x0204813c and the two state setters
 * below call it. */
void func_02065b74(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return;
    func_02062a00(result->unk_0000);
    func_02062a00(result->unk_0004);
}

/* Marks the func_02063a60 singleton's +0x50 word as state 2, clears its +0x5c
 * word, and forwards byte +0x90 of its render object to func_020babec. Its
 * only caller 0x02065884 is inside func_02065864. */
void func_02065b98(void)
{
    Unk061798ResultB *result = func_02063a60();
    result->unk_0050 = 2;
    result->unk_005c = 0;
    func_020babec(result->unk_0000->unk_0090);
}

/* Runs func_02065bc0 and then sets the +0x8, +0xc and +0x58 words of the
 * func_02063a50 singleton to 1; the original does not null-check the
 * singleton. */
void func_02065c10(void)
{
    func_02065bc0();
    Unk061798ResultB *result = func_02063a50();
    result->unk_0008 = 1;
    result->unk_000c = 1;
    result->unk_0058 = 1;
}

/* Moves the func_02063a50 singleton to state 3/5 and then releases its render
 * objects through func_02065b74; does nothing when the singleton is absent.
 * Call site 0x020a3ec4 runs it when func_02065cd0 reports state 1. */
void func_02065c30(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return;
    result->unk_0008 = 3;
    result->unk_000c = 5;
    func_02065b74();
}

/* Moves the func_02063a50 singleton to state 4/5 and then releases its render
 * objects through func_02065b74; same null-check and tail as func_02065c30.
 * Call site 0x020a0804 follows a func_0206597c(4) message reset. */
void func_02065c58(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return;
    result->unk_0008 = 4;
    result->unk_000c = 5;
    func_02065b74();
}

/* Moves the func_02063a50 singleton to state 3/0 and then releases its render
 * objects through func_02065b74; same null-check as func_02065c30 but the
 * second state word is cleared instead of set to 5. */
void func_02065c80(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return;
    result->unk_0008 = 3;
    result->unk_000c = 0;
    func_02065b74();
}

/* Moves the func_02063a50 singleton to state 0/0, clears its +0x4c word and
 * reports id 25 through Unk0bc1a8_Unk_0bc9b4. The original keeps 25 in r0
 * after the two stores. */
void func_02065ca8(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return;
    result->unk_0008 = 0;
    result->unk_004c = 0;
    Unk0bc1a8_Unk_0bc9b4(25);
}

/* Reports whether the singleton's render object is in state 1 at +0x3c; a
 * missing singleton counts as state 1. Call site 0x020a3ec4 uses the result
 * to decide whether to run func_02065c30. */
s32 func_02065cd0(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return 1;
    return result->unk_0000->unk_003c == 1;
}

/* Provider contracts follow the register arguments at the calls below. */
extern void Unk0bc1a8_Unk_0bc504(void *object, u32 value);
extern s32 func_02053824(u32 device, u32 mask);
extern void Unk0bc1a8_Unk_0bc928(u32 id, u32 value, u32 mode);
extern void func_02060160(Unk061798Object *object);
extern void func_0205bb68(Unk061798Object *object);
extern void func_02060248(Unk061798Object *object);
extern void func_02061424(Unk061798Object *object);
extern void func_020ba964(s32 mode);

/* Dispatches only state 1 to the provider with value zero; the original
 * five-entry switch at 0x02063b58 establishes the accepted state range. */
void func_02063b4c(void *object, const u32 *state)
{
    switch (*state) {
    case 0: break;
    case 1: Unk0bc1a8_Unk_0bc504(object, 0); break;
    case 2: break;
    case 3: break;
    case 4: break;
    }
}

/* Sets the object's two flags and its child's +0x84 flag only when device
 * zero reports mask 0x400 (loads/stores at 0x02063f90..0x02063fb0). */
void func_02063f84(Unk061798Object *object)
{
    if (func_02053824(0, 0x400) == 0) return;
    object->unk_0024 = 1;
    object->unk_002c = 1;
    object->unk_0000->unk_0084 = 1;
}

/* Sends command 25 with value 0xffff only while the shared singleton is
 * absent; the original always returns one (0x020654a0..0x020654bc). */
s32 func_02065498(void)
{
    if (data_0216b9a8.unk_0004 == 0)
        Unk0bc1a8_Unk_0bc928(25, 0xffff, 0);
    return 1;
}

/* Returns a borrowed halfword entry from the optional +0x30 font table.
 * As in 0x0206199c..0x020619b0, only the upper bound is clamped.
 * Volatile preserves the observed second table-pointer load; see DEC-030. */
u16 *func_02061980(u32 id, s32 index)
{
    volatile Unk061798Font *font = func_020618cc(id);
    if (font->unk_0030 == 0) return 0;
    index--;
    if (index >= font->unk_0034) index = 0;
    return &font->unk_0030[index];
}

/* Requires a singleton, its +0x4c flag, and its +8 state to be nonzero;
 * these three guards are explicit at 0x0206554c..0x02065574. */
s32 func_02065544(void)
{
    Unk061798ResultB *result = func_02063a50();
    if (result == 0) return 0;
    if (result->unk_004c == 0) return 0;
    return result->unk_0008 != 0;
}

/* Tears down a nullable object in provider order, including its optional
 * first pointer and +0x14 slot (calls at 0x020629d0..0x020629f8). */
void func_020629c4(Unk061798Object *object)
{
    if (object == 0) return;
    func_02060160(object);
    if (object->unk_0000 != 0) func_0205bb68(object->unk_0000);
    func_02060248(object);
    func_02062a00(object);
    func_02061424(object);
}

/* Applies the requested object mode; -1 suppresses the subsequent shared
 * state and provider updates (0x0206587c..0x02065898). */
void func_02065864(void *object, s32 mode)
{
    Unk061798ResultB *result;
    func_020656ac(object, mode);
    result = func_02063a60();
    if (mode == -1) return;
    func_02065b98();
    func_020ba964(mode);
    func_020babec(result->unk_0000->unk_0090);
}
