#ifndef SDK_020116A8_H
#define SDK_020116A8_H

#include "types.h"

/** Single-byte conversion entry points; the active locale selects the pair. */
typedef int (*Unk116a8_Mbtowc)(u16 *pwc, const s8 *s, u32 n);

/** Locale conversion table; only the two entry points used here are known. */
typedef struct {
    Unk116a8_Mbtowc mbtowc;
    Unk116a8_Mbtowc wctomb;
} Unk116a8_Codeset;

/** Borrowed locale prefix; +8 points at the active codeset table. */
typedef struct {
    u32 *unk_00;
    u32 *unk_04;
    Unk116a8_Codeset *codeset;
} Unk116a8_Locale;

/** Borrowed 36-byte message; handlers at +0/+4 operate on the message itself. */
typedef struct Unk116a8_Message Unk116a8_Message;
struct Unk116a8_Message {
    u32 (*callback)(Unk116a8_Message *message);
    void (*callback2)(Unk116a8_Message *message);
    u32 result;
    u32 unk_0c[6];
};

/** Borrowed work object; the volatile +0xc0 slot hands a message to the loop. */
typedef struct {
    u8 pad_00[0xc0];
    Unk116a8_Message *volatile message;
} Unk116a8_Work;

/** Borrowed global view; the word at +0 controls the loop and +0x26 is cleared. */
typedef struct {
    u32 flag;
    u8 pad_04[0x22];
    u8 field_26;
} Unk116a8_Global;

/** Comparator passed to the array search; returns sign of the key/record order. */
typedef int (*Unk116a8_Compare)(const void *key, const void *record);

extern Unk116a8_Locale data_0213cff4;
extern Unk116a8_Global data_02155908;
extern float data_0213cf94;

/** Processes dispatched messages until the global control word becomes zero. */
void func_020116a8(Unk116a8_Work *work);

/** Compares up to n bytes, returning the first difference or zero. */
int func_02011798(const u8 *a, const u8 *b, int n);

/** Returns the float NaN constant at data_0213cf94 widened to double. */
double func_020117d8(void);

/** Releases a non-null block through the MSL arena free entry point. */
void func_020117f0(void *block);

/** Returns the absolute value of a signed word. */
s32 func_02011804(s32 value);

/** Searches a sorted record array and returns the matching record or null.
 * key, base and comparator are borrowed; count is the record count and size
 * is the record stride in bytes.
 */
void *func_02011810(const void *key, const void *base, u32 count, u32 size,
                    Unk116a8_Compare compare);

/** Dispatches multibyte-to-wide conversion through the active locale. */
int func_020118a4(u16 *pwc, const s8 *s, u32 n);

/** Converts one byte to a wide character for the single-byte locale. */
int func_020118c0(u16 *pwc, const s8 *s, u32 n);

#endif
