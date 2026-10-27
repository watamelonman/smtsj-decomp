/* Small CRI registry/accessor helpers from the translation unit that spans
 * 0x02086b70..0x02087268. Only fields established by the original ARM
 * instructions are exposed; all storage remains owned by the caller or by the
 * library globals declared below. */
#include "types.h"

/** Borrowed object prefix; 02086b70/02086b84 read the two halfwords at +0x1c
 * and +0x1e. The rest of the object is opaque here. */
typedef struct Cri02086b70Object {
    u8 pad_00[0x1c];
    u16 unk_1c;
    u16 unk_1e;
} Cri02086b70Object;

/** Library-global record beginning at data_02175a08. Offset +0xc is written
 * by 02086e24 and read by 02086f34; the refcount at +0x10 is maintained by
 * the surrounding unit (02086e4c/02086e7c). */
typedef struct Cri02086b70Library {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    s32 unk_10;
} Cri02086b70Library;

/** Word shared by the getter/setter pair 02086c38/02086c28. */
extern u32 data_02175a04;
/** Library record whose +0xc slot is written by 02086e24. */
extern Cri02086b70Library data_02175a08;

extern void func_0208995c(void *value);
extern void func_0208996c(void *value);

/** Returns half of the halfword at +0x1c of the object, or zero for a null
 * object. Callers at 020849dc and 02084ff4 pass the word loaded from their
 * own +0x20 slot, so the result is a derived rate/size value. */
u32 func_02086b70(const Cri02086b70Object *object)
{
    if (object == 0) return 0;
    return (u32)object->unk_1c >> 1;
}

/** Same as 02086b70 but for the second halfword at +0x1e (called from
 * 020849f8). */
u32 func_02086b84(const Cri02086b70Object *object)
{
    if (object == 0) return 0;
    return (u32)object->unk_1e >> 1;
}

/** Stores a word into the library global at data_02175a04. */
void func_02086c28(void *value)
{
    data_02175a04 = (u32)value;
}

/** Copies the library word to *value and returns 30. The caller at 02087550
 * supplies zero for the first argument and the destination in r1, so the
 * first parameter is not used by this implementation. */
s32 func_02086c38(s32 unused, u32 *value)
{
    *value = data_02175a04;
    return 30;
}

/** Forwards the value to the neighbouring setter at 02086c28; the original
 * is a single interworking tail call. */
void func_02086e18(void *value)
{
    func_02086c28(value);
}

/** Stores a word into the library record's +0xc slot (02086e24). */
void func_02086e24(void *value)
{
    data_02175a08.unk_0c = value;
}

/** Forwards the value to func_0208995c, which stores it in its own global;
 * the original is a single interworking tail call. */
void func_02086e34(void *value)
{
    func_0208995c(value);
}

/** Forwards the value to func_0208996c, which stores it in its own global;
 * the original is a single interworking tail call. */
void func_02086e40(void *value)
{
    func_0208996c(value);
}
