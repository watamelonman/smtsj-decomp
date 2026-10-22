/* Partial work layout recovered from the ARM loads and stores in this unit. */
#include "types.h"


/* Only observed fields are named; offsets and signedness follow the original accesses. */
typedef struct Unk124c5cWork {
    u32 unk_00;
    u32 unk_04;
    s8 kind;
    u8 padding_09[3];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
} Unk124c5cWork;

void func_02124e9c(void);
/* Forward to func_02124e9c; the original thunk has no arguments. */
void Unk124c5c_Thunk_02124e9c(void) { func_02124e9c(); }

void func_02124c5c(void);
void func_02124ce8(u32 value);
/* Run func_02124c5c before forwarding value 2 to func_02124ce8. */
void Unk124c5c_Unk_124cb0(void)
{
  func_02124c5c();
  func_02124ce8(2);
}

extern Unk124c5cWork *data_02176e88;
void func_02061424(void *work);
void func_020e7f44(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
int Unk124c5c_IsKind0(void);
int Unk124c5c_IsKind31(void);
/* Pass four zero words to func_020e7f44, then forward value 2. */
void Unk124c5c_Unk_124cc4(void)
{
    func_020e7f44(0, 0, 0, 0);
    func_02124ce8(2);
}

/* Forward the current work pointer, including null, to func_02061424. */
void Unk124c5c_Unk_124d54(void)
{
  func_02061424(data_02176e88);
}


/* Store words at +0x0c and +0x10 when work exists (original STR offsets). */
void Unk124c5c_Set_124d6c(u32 a, u32 b)
{
    if (data_02176e88 != 0) {
        data_02176e88->unk_0c = a;
        data_02176e88->unk_10 = b;
    }
}

/* Store +4 and the low byte at +8 when work exists (original STR/STRB). */
void Unk124c5c_Set_124d8c(u32 a, u32 b)
{
    if (data_02176e88 != 0) {
        data_02176e88->unk_04 = a;
        data_02176e88->kind = b;
    }
}

/* Return a boolean for signed byte +8 == 0; LDRSB/CMP supports IsKind0. */
int Unk124c5c_IsKind0(void)
{
    Unk124c5cWork *p = data_02176e88;
    if (p != 0 && p->kind == 0) {
        return 1;
    }
    return 0;
}

/* Return a boolean for signed byte +8 == 31, as in the original LDRSB/CMP. */
int Unk124c5c_IsKind31(void)
{
    Unk124c5cWork *p = data_02176e88;
    if (p != 0 && p->kind == 31) {
        return 1;
    }
    return 0;
}

/* Select the byte predicate by word +4; absent or other states return true. */
int Unk124c5c_Unk_124e04(void)
{
    Unk124c5cWork *p = data_02176e88;
    if (p == 0) {
        return 1;
    }
    switch (p->unk_04) {
    case 0:
        return Unk124c5c_IsKind0();
    case 1:
        return Unk124c5c_IsKind31();
    }
    return 1;
}

/* Store the word at +0x14 only when work exists (original conditional STR). */
void Unk124c5c_Unk_124e50(u32 arg0)
{
  if (data_02176e88 != 0) {
    data_02176e88->unk_14 = arg0;
  }
}

int Unk0d297c_Unk_0d3138(void);
int Unk0e651c_Unk_0e666c(u32 flag);
int Unk0cb32c_Unk_0cb7f0(void);

/* Select three arguments from predicate results; call relocations and 0x705
 * in the original establish the order and flag, but not their higher-level use. */
void func_02124c5c(void)
{
    u32 a = 13;
    u32 b = 7;
    u32 c = 10;
    if (Unk0d297c_Unk_0d3138() == 0) {
        a = 0;
    }
    if (Unk0e651c_Unk_0e666c(0x705) == 0) {
        c = 0;
    }
    if (Unk0cb32c_Unk_0cb7f0() == 0) {
        b = 0;
    }
    func_020e7f44(a, b, c, 0);
}

/* Stack payload layout follows STRB at +0/+1 and sixteen STRs at +4..+64. */
typedef struct Unk124c5cPayload {
    u8 flags[2];
    u8 padding_02[2];
    u32 words[16];
} Unk124c5cPayload;

void func_020bcbc4(u32 kind, const Unk124c5cPayload *payload);

/* Forward value in payload word 1 with flag bit 1 and kind 10; the original
 * stack stores and call relocation establish the payload fields and callee. */
void func_02124ce8(u32 value)
{
    Unk124c5cPayload payload;
    int i;
    for (i = 0; i < 2; i++) {
        payload.flags[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        payload.words[i] = 0;
    }
    payload.flags[0] |= 2;
    payload.words[1] = value;
    func_020bcbc4(10, &payload);
}
