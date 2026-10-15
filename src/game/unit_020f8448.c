/*
 * src/game/unit_020f8448.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0f8448Work {
    u32 unk_0000;
    u32 unk_0004;
    s32 unk_0008;
    u8 pad_000c[0x4];
    s32 unk_0010;
} Unk0f8448Work;

void func_020bcc7c(void);
void func_020bccec(void);

u32 Unk0f8448_GetUnkField10(void *obj);
u32 Unk0f8448_GetUnkField0(void *obj);
u32 Unk0f8448_GetUnkField4(void *obj);
u32 Unk0f8448_GetUnkField8(void *obj);
void Unk0f8448_Thunk_020bcc7c(void);
void Unk0f8448_Thunk_020bccec(void);
int Unk0f8448_Unk_0f8468(Unk0f8448Work *work);

/* get u32 at +0x10 */
u32 Unk0f8448_GetUnkField10(void *obj) { return ((Unk0f8448Work *)obj)->unk_0010; }

/* get u32 at +0x0 */
u32 Unk0f8448_GetUnkField0(void *obj) { return ((Unk0f8448Work *)obj)->unk_0000; }

/* get u32 at +0x4 */
u32 Unk0f8448_GetUnkField4(void *obj) { return ((Unk0f8448Work *)obj)->unk_0004; }

/* get u32 at +0x8 */
u32 Unk0f8448_GetUnkField8(void *obj) { return ((Unk0f8448Work *)obj)->unk_0008; }

/* forwards to `func_020bcc7c` */
void Unk0f8448_Thunk_020bcc7c(void) { func_020bcc7c(); }

/* forwards to `func_020bccec` */
void Unk0f8448_Thunk_020bccec(void) { func_020bccec(); }

/* decompiler-derived */
int Unk0f8448_Unk_0f8468(Unk0f8448Work *work)
{
  return work->unk_0010 - work->unk_0008;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef void (*Unk0f8448Fn)(u8 *);
void func_020bcfc4();
void func_020bd1a8();
void Unk0f8448_Init(u8 *p, u32 a)
{
    func_020bcfc4(p, a);
    func_020bd1a8(p + 28, p, p + 100, 1);
    FIELD(Unk0f8448Fn, p, 148)(p);
}

u32 Unk0f8448_GetEntry(u8 *p, int i)
{
    if (i < 0 || (int)Unk0f8448_GetUnkField0(p) <= i) {
        return 0;
    }
    return FIELD(u32, p + i * 12, 28);
}
