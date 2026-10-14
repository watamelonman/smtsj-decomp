/*
 * src/game/unit_020f8448.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk0f8448Work {
    u8 unk_0000[0x8];
    s32 UnkField0008;
    u8 unk_000c[0x4];
    s32 UnkField0010;
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
u32 Unk0f8448_GetUnkField10(void *obj) { return FIELD(u32, obj, 0x10); }

/* get u32 at +0x0 */
u32 Unk0f8448_GetUnkField0(void *obj) { return FIELD(u32, obj, 0x0); }

/* get u32 at +0x4 */
u32 Unk0f8448_GetUnkField4(void *obj) { return FIELD(u32, obj, 0x4); }

/* get u32 at +0x8 */
u32 Unk0f8448_GetUnkField8(void *obj) { return FIELD(u32, obj, 0x8); }

/* forwards to `func_020bcc7c` */
void Unk0f8448_Thunk_020bcc7c(void) { func_020bcc7c(); }

/* forwards to `func_020bccec` */
void Unk0f8448_Thunk_020bccec(void) { func_020bccec(); }

/* decompiler-derived */
int Unk0f8448_Unk_0f8468(Unk0f8448Work *work)
{
  return work->UnkField0010 - work->UnkField0008;
}
