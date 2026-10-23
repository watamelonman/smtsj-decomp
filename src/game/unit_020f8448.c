/* Layout and behavior evidence: original ARM loads/calls; see the unit doc. */
#include "types.h"

/* Only observed offsets are named; the intervening storage is opaque. */
typedef struct Unk0f8448Work Unk0f8448Work;

/* Callback at +0x94 receives the same live work object after setup. */
typedef void (*Unk0f8448Fn)(Unk0f8448Work *work);

/* Storage must extend through the callback at +0x94 before initialization. */
struct Unk0f8448Work {
    u32 unk_0000;
    u32 unk_0004;
    s32 unk_0008;
    u8 pad_000c[0x4];
    s32 unk_0010;
    u8 pad_0014[0x8];
    u8 unk_001c[0x48];
    u32 unk_0064[0xC]; /* Extent inferred from the callback offset. */
    Unk0f8448Fn unk_0094;
};

void func_020bcc7c(void);
void func_020bccec(void);

u32 Unk0f8448_GetUnkField10(void *obj);
u32 Unk0f8448_GetUnkField0(void *obj);
u32 Unk0f8448_GetUnkField4(void *obj);
u32 Unk0f8448_GetUnkField8(void *obj);
void Unk0f8448_Thunk_020bcc7c(void);
void Unk0f8448_Thunk_020bccec(void);
int Unk0f8448_Unk_0f8468(Unk0f8448Work *work);

/* Original load at +0x10: obj must point to live work storage. */
u32 Unk0f8448_GetUnkField10(void *obj) { return ((Unk0f8448Work *)obj)->unk_0010; }

/* Original load at +0x00: callers use this as the visible entry count. */
u32 Unk0f8448_GetUnkField0(void *obj) { return ((Unk0f8448Work *)obj)->unk_0000; }

/* Original load at +0x04: preserve the word without interpreting its value. */
u32 Unk0f8448_GetUnkField4(void *obj) { return ((Unk0f8448Work *)obj)->unk_0004; }

/* Original load at +0x08: expose its bits through the existing unsigned API. */
u32 Unk0f8448_GetUnkField8(void *obj) { return ((Unk0f8448Work *)obj)->unk_0008; }

/* Original BL identifies the target; preserve its no-argument call boundary. */
void Unk0f8448_Thunk_020bcc7c(void) { func_020bcc7c(); }

/* Original BL identifies the target; preserve its no-argument call boundary. */
void Unk0f8448_Thunk_020bccec(void) { func_020bccec(); }

/* Original loads/subtract return field +0x10 minus field +0x08. */
int Unk0f8448_Unk_0f8468(Unk0f8448Work *work)
{
  return work->unk_0010 - work->unk_0008;
}

void func_020bcfc4(Unk0f8448Work *work, s32 value);
s32 func_020bd1a8(void *entries, Unk0f8448Work *work, u32 *values, s32 flag);

/* Original call sequence sets the index, updates entry storage, then invokes
 * the +0x94 callback. The caller supplies initialized fields and a valid callback. */
void Unk0f8448_Init(Unk0f8448Work *work, s32 value)
{
    func_020bcfc4(work, value);
    func_020bd1a8(work->unk_001c, work, work->unk_0064, 1);
    work->unk_0094(work);
}

u32 Unk0f8448_GetEntry(u8 *p, int i)
{
    if (i < 0 || (int)Unk0f8448_GetUnkField0(p) <= i) {
        return 0;
    }
    return FIELD(u32, p + i * 12, 28);
}
