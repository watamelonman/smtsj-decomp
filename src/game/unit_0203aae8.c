/* src/game/unit_0203aae8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"
#include "game/unit_0203aae8.h"



/* Intentionally empty callback: the original consists solely of a return. */
void Unk03aae8_Nop_03ae0c(void) { }

extern u8 data_0215de34[];
/* Return the borrowed active-work address stored at singleton offset +4. */
u32 Unk03aae8_Unk_03ad14(void)
{
  return *(u32 *)(((int)data_0215de34) + 4);
}

int func_0203ac00(int argumentIndex);
int Unk094fe0_Call_0209502c(int value, int mode);
/* Forward argument zero as a signed 16-bit value with mode zero; return status 1. */
u32 Unk03aae8_Unk_03aef0(void)
{
  short v1;
  v1 = func_0203ac00(0);
  Unk094fe0_Call_0209502c((int)v1,0);
  return 1;
}

void Unk03aae8_Unk_03acf4(u32 value);
int func_02050074(int selector, int index);
int Unk094fe0_Call_020950b4(int value);
/* Store whether the signed 16-bit argument query is nonzero; return status 1. */
int Unk03aae8_Unk_03af14(void)
{
    if (Unk094fe0_Call_020950b4((s16)func_0203ac00(0))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Query selector zero using the one-based argument minus one and store its result. */
u32 Unk03aae8_Unk_03b878(void)
{
  int value;
  value = func_0203ac00(0);
  Unk03aae8_Unk_03acf4(func_02050074(0, value - 1));
  return 1;
}


void Unk02dcfc_Unk_02df00(u32 work, int value);

/* Forward work field +0xe8 and signed 16-bit argument zero; return status 3. */
u32 Unk03aae8_Unk_03af50(void)
{
  short v1;
  int value1;
  u32 value2;
  value1 = Unk03aae8_Unk_03ad14();
  value2 = *(u32 *)(value1 + 0xe8);
  v1 = func_0203ac00(0);
  Unk02dcfc_Unk_02df00(value2,(int)v1);
  return 3;
}



/* Read a borrowed stack word only for tag 5; arg0 counts backward from the top. */
u32 Unk03aae8_Unk_03ac9c(int arg0)
{
  int value1;
  int value2;
  value2 = *(int *)(((int)data_0215de34) + 4);
  value1 = *(int *)(value2 + 0x1c) - (arg0 + 1);
  switch(*(u8 *)(value2 + value1 + 0x20)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    return *(u32 *)(value2 + value1 * 4 + 0x3c);
  }
  return 0;
}


int func_020b8660(int index);
/* Forward signed argument zero with mode 1; values 0x733..0x737 also
 * select indices 0..4 through 020b8660, as shown by the original jump table. */
u32 Unk03aae8_Unk_03ae68(void)
{
  short v1;
  v1 = func_0203ac00(0);
  Unk094fe0_Call_0209502c((int)v1,1);
  switch((int)v1) {
  case 0x733:
    func_020b8660(0);
    break;
  case 0x734:
    func_020b8660(1);
    break;
  case 0x735:
    func_020b8660(2);
    break;
  case 0x736:
    func_020b8660(3);
    break;
  case 0x737:
    func_020b8660(4);
  }
  return 1;
}

/* Clear active-work byte +0x3b, then store the full result word at +0xa8.
 * Reload the singleton pointer between writes, as in the original. */
void Unk03aae8_Unk_03acf4(u32 arg0)
{
  int tmp1;
  tmp1 = (int)(data_0215de34);
  *(u8 *)(*(int *)(data_0215de34 + 4) + 0x3b) = 0;
  *(u32 *)(*(int *)(tmp1 + 4) + 0xa8) = arg0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef int (*Unk03aae8StepFn)(u8 *);
extern u8 data_02142170[];
void func_02095b48(u8 *buffer, u32 value);
void func_0204b344(u8 *object, const u8 *buffer);
void *func_0204b3cc(u8 *object, int key);
void *func_0204fe68(u32 handle, void *context);
void *func_0204fed8(void *object, int key);
void *Unk095560_Unk_095778(int key);
int _s32_div_f();

/* For kind 0, populate a zeroed 64-byte temporary from field +0x40 and apply it.
 * The borrowed object must expose its kind at +8. */
void Unk03aae8_Unk_03ad24(u8 *p)
{
    switch (FIELD(s32, p, 8)) {
    case 0: {
        u8 buf[64] = {0};
        func_02095b48(buf, FIELD(u32, p, 64));
        func_0204b344(p, buf);
        break;
    }
    case 1:
    case 2:
    case 3:
        break;
    }
}

/* Resolve key through the kind-specific borrowed handle at +0x5c or +0x74.
 * Kind 0 delegates directly; unsupported kinds return null. */
void *Unk03aae8_Unk_03ad98(u8 *p, int key)
{
    void *r = 0;
    switch (FIELD(s32, p, 8)) {
    case 0:
        r = func_0204b3cc(p, key);
        break;
    case 1:
        break;
    case 2:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 92), r), key);
        break;
    case 3:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 116), r), key);
        break;
    }
    return r;
}

/* Resolve key globally for kind 0 or through borrowed field +0x50 for kind 2.
 * Other kinds return null; evidence is the original kind jump table. */
void *Unk03aae8_Unk_03ae10(u8 *p, int key)
{
    void *r = 0;
    switch (FIELD(s32, p, 8)) {
    case 0:
        r = Unk095560_Unk_095778(key);
        break;
    case 1:
        break;
    case 2:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 80), r), key);
        break;
    case 3:
        break;
    }
    return r;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk094fe0_Unk_094fec(u32 value);
void Unk094fe0_SetSlot(int owner, int slot, int value);
int Unk094fe0_GetSlot(int owner, int slot);
void func_0209512c(int owner, int bit, int enabled);
u32 Unk03aae8_Unk_03ad14(void);

/* Write a slot using signed 16-bit arguments; kind 0 resolves field +0x40,
 * while other kinds pass owner zero. Return script status 1. */
int Unk03aae8_Unk_03b634(void)
{
    int r;
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    r = 0;
    switch (FIELD(s32, o, 8)) {
    case 0:
        r = Unk094fe0_Unk_094fec(FIELD(u32, o, 64));
        break;
    case 2:
        break;
    }
    Unk094fe0_SetSlot(r, a, b);
    return 1;
}

/* Read a signed 16-bit slot for kind 0, otherwise store zero; return status 1. */
int Unk03aae8_Unk_03b694(void)
{
    int r;
    s16 a = func_0203ac00(0);
    u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    r = 0;
    switch (FIELD(s32, o, 8)) {
    case 0:
        r = (s16)Unk094fe0_GetSlot(Unk094fe0_Unk_094fec(FIELD(u32, o, 64)), a);
        break;
    case 2:
        break;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

/* Set the argument-selected bit through the kind-0 provider or field +0x40
 * for kinds 1 and 3. The borrowed object comes from active work +0xe8. */
int Unk03aae8_Unk_03b6ec(void)
{
    s16 a = func_0203ac00(0);
    u8 *o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    switch (FIELD(s32, o, 8)) {
    case 0:
        func_0209512c(Unk094fe0_Unk_094fec(FIELD(u32, o, 64)), a, 1);
        break;
    case 1:
        FIELD(u32, o, 64) |= 1 << a;
        break;
    case 2:
        break;
    case 3:
        FIELD(u32, o, 64) |= 1 << a;
        break;
    }
    return 1;
}

/* Store the unsigned comparison of argument zero against the indexed query.
 * Argument one is a one-based index; both result branches return status 1. */
int Unk03aae8_Unk_03b89c(void)
{
    u32 a = func_0203ac00(0);
    int b = func_0203ac00(1);
    if (a > (u32)func_02050074(0, b - 1)) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Store whether argument 0 lies within the inclusive signed bounds in arguments
 * 1 and 2; the original comparisons establish signed ordering. */
int Unk03aae8_Unk_03b93c(void)
{
    int v = func_0203ac00(0);
    int lo = func_0203ac00(1);
    int hi = func_0203ac00(2);
    if (lo <= v && v <= hi) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

int func_02050088(int stream, u32 lower, u32 upper);
/* Query stream zero with bounds scaled by 1024, divide its unsigned result by
 * 100, multiply by argument 0 with word wrapping, then arithmetic-shift by 10.
 * The original umull reciprocal sequence establishes unsigned division. */
int func_0203b8e4(void)
{
    int scale = func_0203ac00(0);
    u32 lower = func_0203ac00(1);
    u32 upper = func_0203ac00(2);
    u32 value = (u32)func_02050088(0, lower << 10, upper << 10) / 100;
    Unk03aae8_Unk_03acf4((s32)((u32)scale * value) >> 10);
    return 1;
}

int func_02039dc0(u8 *work);
float func_02039e50(u8 *work);
extern int data_0215e258[];
extern float data_0215de58[];
int Unk094fe0_TestFlag18(int owner, int bit);

/* Test the top stack value by its byte tag; advance the instruction index for
 * true, otherwise load the destination from the indexed 32-byte record. */
int func_0203aae8(u8 *work)
{
    int value;
    switch (FIELD(u8, work + FIELD(int, work, 28), 31)) {
    case 0:
    case 2:
        value = func_02039dc0(work);
        break;
    case 1:
    case 3:
        if (0.0f == func_02039e50(work)) {
            value = 0;
        } else {
            value = 1;
        }
        break;
    case 4:
        value = 0;
        break;
    default:
        value = 0;
        break;
    }
    if (value) {
        FIELD(int, work, 24) = FIELD(int, work, 24) + 1;
    } else {
        FIELD(int, work, 24) = FIELD(int, FIELD(u8 *, work, 184) +
            FIELD(u16, FIELD(u8 *, work, 188) + FIELD(int, work, 24) * 4, 2) * 32, 24);
    }
    return 1;
}

/* Dispatch borrowed work through the opcode table until status 0 or 2.
 * Status 1 clears the consecutive-yield counter; status 2 increments both counters. */
int func_0203ab84(u8 *work)
{
    for (;;) {
        int status = ((Unk03aae8StepFn *)data_02142170)[
            FIELD(u16, FIELD(u8 *, work, 188), FIELD(int, work, 24) * 4)](work);
        if (status == 0) {
            FIELD(int, work, 208) = 0;
            return 2;
        }
        if (status == 2) {
            break;
        }
        if (status == 1) {
            FIELD(int, work, 208) = 0;
        }
    }
    FIELD(int, work, 208)++;
    FIELD(int, work, 204)++;
    return 1;
}

/* Read the argument counted backward from the borrowed stack. Tags 1 and 3
 * convert floats to integers; tags 2 and 3 index the external value tables. */
int func_0203ac00(int argumentIndex)
{
    u8 *work = FIELD(u8 *, data_0215de34, 4);
    int index = FIELD(int, work, 28) - (argumentIndex + 1);
    switch (FIELD(u8, work + index, 32)) {
    case 0:
    case 4:
        return FIELD(int, work + index * 4, 60);
    case 1:
        return (int)FIELD(float, work + index * 4, 60);
    case 2:
        return data_0215e258[FIELD(int, work + index * 4, 60)];
    case 3:
        return (int)data_0215de58[FIELD(int, work + index * 4, 60)];
    }
    return 0;
}

/* Initialize the borrowed eight-byte record, dividing 32 among at most 32
 * positive parts. Byte zero and the residual word at +4 are each at least 1. */
void func_0203af7c(u8 *record, int parts)
{
    FIELD(u8, record, 0) = 32;
    FIELD(u8, record, 1) = 1;
    FIELD(int, record, 4) = 1;
    if (parts <= 0) return;
    if (parts > 32) parts = 32;
    FIELD(u8, record, 0) /= parts;
    if (FIELD(u8, record, 0) < 1) FIELD(u8, record, 0) = 1;
    FIELD(int, record, 4) = 32 - parts * FIELD(u8, record, 0);
    FIELD(int, record, 4)++;
    if (FIELD(int, record, 4) < 1) FIELD(int, record, 4) = 1;
}

/* Clear the argument-selected bit using the kind-0 provider or the borrowed
 * object's field +0x40 for kinds 1 and 3. Return script status 1. */
int func_0203b76c(void)
{
    s16 bit = func_0203ac00(0);
    u8 *object = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    switch (FIELD(int, object, 8)) {
    case 0:
        func_0209512c(Unk094fe0_Unk_094fec(FIELD(u32, object, 64)), bit, 0);
        break;
    case 1:
        FIELD(u32, object, 64) &= ~(1 << bit);
        break;
    case 2:
        break;
    case 3:
        FIELD(u32, object, 64) &= ~(1 << bit);
        break;
    }
    return 1;
}

/* Store the selected bit's state using the kind-0 provider or field +0x40
 * for kinds 1 and 3; other kinds store zero. Return script status 1. */
int func_0203b7f4(void)
{
    s16 bit = func_0203ac00(0);
    u8 *object = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    int result = 0;
    switch (FIELD(int, object, 8)) {
    case 0:
        result = Unk094fe0_TestFlag18(Unk094fe0_Unk_094fec(FIELD(u32, object, 64)), bit);
        break;
    case 1:
        if (FIELD(u32, object, 64) & (1 << bit)) result = 1;
        break;
    case 2:
        break;
    case 3:
        if (FIELD(u32, object, 64) & (1 << bit)) result = 1;
        break;
    }
    Unk03aae8_Unk_03acf4(result);
    return 1;
}

int func_02095818(void);
void func_0209e75c(int first, int second, int mode, int flag);
void func_0209e7fc(int first, int second, int mode, int flag);
void func_020df374(int first, int second, int mode, int step, int count);
void func_020df420(int first, int second, int mode, int step, int count);
void Unk116598_Call_02117360(int first, int second, int mode, int step, int count);
void Unk116598_Call_02117360b(int first, int second, int mode, int step, int count);
void Unk116598_Call_02117400(int first, int second, int mode, int step, int count);
void Unk116598_Call_02117400b(int first, int second, int mode, int step, int count);
void ImageBgDual3D_Call_02117360(int first, int second, int mode, int step, int count);
void ImageBgDual3D_Call_02117400(int first, int second, int mode, int step, int count);
void Unk02dcfc_SetField70(int value);

/* Dispatch two signed arguments to the kind-selected provider, storing status
 * and residual count in the valid borrowed object; clear provider field 0x70. */
int func_0203aff0(void)
{
    Unk03aae8Object *object = FIELD(Unk03aae8Object *, Unk03aae8_Unk_03ad14(), 232);
    int mode = (s16)func_0203ac00(0);
    int parts = (s16)func_0203ac00(1);
    Unk03aae8Record record;
    object->argument = mode;
    if (mode == 0) mode = 0;
    else mode = 2;
    func_0203af7c((u8 *)&record, parts);
    switch (func_02095818()) {
    case 0:
        func_0209e75c(record.step, record.count, mode, 0);
        object->status = 16;
        object->residual = record.residual;
        break;
    case 2:
        func_020df374(1, 0, mode, record.step, record.count);
        object->status = 18;
        object->residual = record.residual;
        break;
    case 3:
        Unk116598_Call_02117360(1, 0, mode, record.step, record.count);
        object->status = 19;
        object->residual = record.residual;
        break;
    case 4:
        Unk116598_Call_02117360b(1, 0, mode, record.step, record.count);
        object->status = 20;
        object->residual = record.residual;
        break;
    case 5:
        ImageBgDual3D_Call_02117360(1, 0, mode, record.step, record.count);
        object->status = 20;
        object->residual = record.residual;
        break;
    }
    Unk02dcfc_SetField70(0);
    return 3;
}

/* Dispatch two signed arguments to the alternate providers; kinds 3..5 also
 * set field 0x70 to 2 for zero mode or 1 otherwise. Object storage is borrowed. */
int func_0203b158(void)
{
    Unk03aae8Object *object = FIELD(Unk03aae8Object *, Unk03aae8_Unk_03ad14(), 232);
    int mode = (s16)func_0203ac00(0);
    int parts = (s16)func_0203ac00(1);
    Unk03aae8Record record;
    object->argument = mode;
    if (mode == 0) mode = 0;
    else mode = 2;
    func_0203af7c((u8 *)&record, parts);
    switch (func_02095818()) {
    case 0:
        func_0209e7fc(record.step, record.count, mode, 0);
        object->status = 16;
        object->residual = record.residual;
        break;
    case 2:
        func_020df420(1, 0, mode, record.step, record.count);
        object->status = 18;
        object->residual = record.residual;
        break;
    case 3:
        Unk116598_Call_02117400(1, 0, mode, record.step, record.count);
        object->status = 19;
        object->residual = record.residual;
        if (mode == 0) Unk02dcfc_SetField70(2);
        else Unk02dcfc_SetField70(1);
        break;
    case 4:
        Unk116598_Call_02117400b(1, 0, mode, record.step, record.count);
        object->status = 20;
        object->residual = record.residual;
        if (mode == 0) Unk02dcfc_SetField70(2);
        else Unk02dcfc_SetField70(1);
        break;
    case 5:
        ImageBgDual3D_Call_02117400(1, 0, mode, record.step, record.count);
        object->status = 20;
        object->residual = record.residual;
        if (mode == 0) Unk02dcfc_SetField70(2);
        else Unk02dcfc_SetField70(1);
        break;
    }
    return 3;
}

/* Dispatch three signed arguments for kinds 0, 2 and 5. Argument 2 selects
 * provider flags; kind 5 updates field 0x70. The active object must be valid. */
int func_0203b30c(void)
{
    Unk03aae8Object *object = FIELD(Unk03aae8Object *, Unk03aae8_Unk_03ad14(), 232);
    int mode = (s16)func_0203ac00(0);
    int parts = (s16)func_0203ac00(1);
    int selection = (s16)func_0203ac00(2);
    int flag;
    int first;
    int second;
    Unk03aae8Record record;
    object->argument = mode;
    if (mode == 0) mode = 0;
    else mode = 2;
    flag = selection == 0;
    first = 0;
    second = 0;
    func_0203af7c((u8 *)&record, parts);
    switch (func_02095818()) {
    case 0:
        func_0209e75c(record.step, record.count, mode, flag);
        object->status = 16;
        object->residual = record.residual;
        break;
    case 2:
        switch (selection) {
        case 0: first = 1; second = 1; break;
        case 1: first = 1; break;
        case 2: second = 1; break;
        }
        func_020df374(first, second, mode, record.step, record.count);
        object->status = 18;
        object->residual = record.residual;
        break;
    case 5:
        switch (selection) {
        case 0: first = 1; second = 1; break;
        case 1: first = 1; break;
        case 2: second = 1; break;
        }
        ImageBgDual3D_Call_02117360(first, second, mode, record.step, record.count);
        object->status = 20;
        object->residual = record.residual;
        if (mode == 0) Unk02dcfc_SetField70(2);
        else Unk02dcfc_SetField70(1);
        break;
    }
    return 3;
}

/* Dispatch three signed arguments to the alternate kind-0/2/5 providers,
 * preserving argument-selected flags and the borrowed object status fields. */
int func_0203b4a0(void)
{
    Unk03aae8Object *object = FIELD(Unk03aae8Object *, Unk03aae8_Unk_03ad14(), 232);
    int mode = (s16)func_0203ac00(0);
    int parts = (s16)func_0203ac00(1);
    int selection = (s16)func_0203ac00(2);
    int flag;
    int first;
    int second;
    Unk03aae8Record record;
    object->argument = mode;
    if (mode == 0) mode = 0;
    else mode = 2;
    flag = selection == 0;
    first = 0;
    second = 0;
    func_0203af7c((u8 *)&record, parts);
    switch (func_02095818()) {
    case 0:
        func_0209e7fc(record.step, record.count, mode, flag);
        object->status = 16;
        object->residual = record.residual;
        break;
    case 2:
        switch (selection) {
        case 0: first = 1; second = 1; break;
        case 1: first = 1; break;
        case 2: second = 1; break;
        }
        func_020df420(first, second, mode, record.step, record.count);
        object->status = 18;
        object->residual = record.residual;
        break;
    case 5:
        switch (selection) {
        case 0: first = 1; second = 1; break;
        case 1: first = 1; break;
        case 2: second = 1; break;
        }
        ImageBgDual3D_Call_02117400(first, second, mode, record.step, record.count);
        object->status = 20;
        object->residual = record.residual;
        if (mode == 0) Unk02dcfc_SetField70(2);
        else Unk02dcfc_SetField70(1);
        break;
    }
    return 3;
}
