/* Singleton work accessors; field offsets are evidenced by the original ARM loads/stores. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0fd268Work {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0x8];
    u32 unk_001c;
    u8 pad_0020[0x4];
    u32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
} Unk0fd268Work;



extern Unk0fd268Work *data_02176e1c;
/* Only the first word of this separate singleton is inspected here. */
extern int *data_02176e18;

/* Object passed to func_020fd268/func_020fd2fc; byte fields from observed ldrb/strb. */
typedef struct Unk0fd268Fade {
    u32 unk_0000;
    u32 unk_0004;
    u8 unk_0008; /* counter, reset when it reaches unk_0009 */
    u8 unk_0009;
    u8 unk_000a; /* toggled each time unk_0008 wraps */
    u8 unk_000b;
    u8 unk_000c; /* state: 0 = counting, 1 = release */
} Unk0fd268Fade;
/* Returns the first word of data_02176e18, or -1 when absent (ARM 020fd364). */
int Unk0fd268_GetField0(void)
{
    if (data_02176e18 != 0) {
        return *data_02176e18;
    }
    return -1;
}

/* Returns the borrowed singleton pointer; ARM 020fd4b4 loads data_02176e1c. */
Unk0fd268Work *Unk0fd268_Get_data_02176e1c(void)
{
  return data_02176e1c;
}

/* Takes the object handle returned by func_020611dc; both work types are passed here. */
void func_02061424(void *obj);
/* Forwards a present singleton to func_02061424 (ARM 020fd3ac); does not clear it. */
void Unk0fd268_Unk_0fd3ac(void)
{
  Unk0fd268Work *value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value == 0) {
    return;
  }
  func_02061424(value);
}


/* Clears offset 0x2c when the singleton exists (ARM 020fd47c). */
void Unk0fd268_Unk_0fd47c(void)
{
  Unk0fd268Work *value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    value->unk_002c = 0;
  }
}


/* Stores the supplied words at offsets 0x30 and 0x34 if present (ARM 020fd494). */
void Unk0fd268_Unk_0fd494(u32 arg0,u32 arg1)
{
  Unk0fd268Work *value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    value->unk_0030 = arg0;
    value->unk_0034 = arg1;
  }
}

Unk0fd268Work *func_020fd4c4(u32 arg0);
/* Creates and stores work only when absent; forwards arg0 unchanged (ARM 020fd380). */
void Unk0fd268_Unk_0fd380(u32 arg0)
{
  Unk0fd268Work *value1;
  Unk0fd268Work *value2;
  value1 = Unk0fd268_Get_data_02176e1c();
  if (value1 != 0) {
    return;
  }
  value2 = func_020fd4c4(arg0);
  data_02176e1c = value2;
}


extern u8 data_021510a4[];
int Unk05b82c_Unk_05b82c();
int func_0205dcd4();
/* Writes +3 for nonzero flag, -3 otherwise, at offset 0x10 (ARM 020fd3c4). */
void Unk0fd268_SetDir(int flag)
{
    Unk0fd268Work *p = Unk0fd268_Get_data_02176e1c();
    if (p == 0) {
        return;
    }
    if (flag != 0) {
        p->unk_0010 = 3;
    } else {
        p->unk_0010 = -3;
    }
}

/* Calls Unk05b82c_Unk_05b82c(13) and (14), then stores func_0205dcd4(data_021510a4, 1) in word 0 (ARM 020fd574). */
void Unk0fd268_Unk_0fd574(Unk0fd268Work *arg0)
{
  u32 tmp1;
  Unk05b82c_Unk_05b82c(0xd);
  Unk05b82c_Unk_05b82c(0xe);
  tmp1 = func_0205dcd4(((int)data_021510a4),1);
  arg0->unk_0000 = tmp1;
  return;
}


/* Initialises a fresh work: word 8 = -81, word 0x1c = arg1, word 0x2c = 1, other observed words 0 (ARM 020fd540). */
void Unk0fd268_Unk_0fd540(Unk0fd268Work *arg0, u32 arg1){
  arg0->unk_0008 = 0xffffffaf;
  arg0->unk_000c = 0;
  arg0->unk_0010 = 0;
  arg0->unk_001c = arg1;
  arg0->unk_0024 = 0;
  arg0->unk_0028 = 0;
  arg0->unk_002c = 1;
  arg0->unk_0030 = 0;
  arg0->unk_0034 = 0;
  return;
}


/* If present: arg0 != 0 clears word 8; else sets word 8 to -81 and clears word 0x10 (ARM 020fd3f0). */
void Unk0fd268_Unk_0fd3f0(int arg0)
{
  Unk0fd268Work *tmp1;
  tmp1 = Unk0fd268_Get_data_02176e1c();
  if (tmp1 == 0) {
    return;
  }
  if (arg0 == 0) {
    tmp1->unk_0008 = 0xffffffaf;
    tmp1->unk_0010 = 0;
    return;
  }
  tmp1->unk_0008 = 0;
  return;
}

/* Tests offset 8 for zero; an absent singleton returns false (ARM 020fd428). */
int Unk0fd268_IsField8Zero(void)
{
    Unk0fd268Work *p = Unk0fd268_Get_data_02176e1c();
    if (p == 0) {
        return 0;
    }
    return p->unk_0008 == 0;
}

/* Tests offset 8 for -81 (the value Unk_0fd540 initialises); absent returns false (ARM 020fd450). */
int Unk0fd268_IsField8Neg81(void)
{
    Unk0fd268Work *p = Unk0fd268_Get_data_02176e1c();
    if (p == 0) {
        return 0;
    }
    return p->unk_0008 == -81;
}

/* Steps the object's state at offset 0xc. State 0 counts unk_0008 up to unk_0009, then
 * resets it and toggles unk_000a, decrementing unk_000b on every second wrap; when both
 * reach zero it advances to state 1. State 1 releases the object via func_02061424 and
 * clears the data_02176e18 singleton (ARM 020fd268). */
void func_020fd268(Unk0fd268Fade *obj)
{
    int next;

    switch (obj->unk_000c) {
    case 0:
        if (obj->unk_0008 >= obj->unk_0009) {
            obj->unk_000a ^= 1;
            if (obj->unk_000a == 0) {
                obj->unk_000b--;
            }
            next = 0;
        } else {
            next = obj->unk_0008 + 1;
        }
        obj->unk_0008 = next;
        if (obj->unk_000a == 0 && obj->unk_000b == 0) {
            obj->unk_000c++;
        }
        break;
    case 1:
        func_02061424(obj);
        data_02176e18 = 0;
        break;
    }
}

void func_02057524(int a);
void func_02057e30(int a);
void func_02057e18(int a);
void func_02057ddc(u32 value);
void func_02057b50(int x, int y, int w, int h, int a4);
void func_02057df8(void);
void func_020572d8(void);
/* While unk_000a is set, issues one draw sequence through the func_02057xxx helpers with
 * word 4 as the colour-like argument and a 256x192 (full screen) rectangle (ARM 020fd2fc). */
void func_020fd2fc(Unk0fd268Fade *obj)
{
    if (obj->unk_000a == 0) {
        return;
    }
    func_02057524(7);
    func_02057e30(0);
    func_02057e18(31);
    func_02057ddc(obj->unk_0004);
    func_02057b50(0, 0, 256, 192, 22);
    func_02057df8();
    func_020572d8();
}

void func_020fd68c(void);
void Unk0fd5a4_Unk_0fd6ec(void);
void Unk0fd5a4_Unk_0fd704(void);
void Unk0fd5a4_Unk_0fd5a4(void);
Unk0fd268Work *func_020611dc(void (*cb0)(void), void (*cb1)(void), void (*cb2)(void),
                             void (*cb3)(void), u32 size, u32 arg5, u32 arg6, u32 arg7);
/* Creates a 0x38-byte work through func_020611dc with the unit_020fd5a4 callbacks, then
 * initialises it (Unk_0fd540 with arg0, Unk_0fd574); returns 0 on failure (ARM 020fd4c4). */
Unk0fd268Work *func_020fd4c4(u32 arg0)
{
    Unk0fd268Work *work;

    work = func_020611dc(func_020fd68c, Unk0fd5a4_Unk_0fd6ec, Unk0fd5a4_Unk_0fd704,
                         Unk0fd5a4_Unk_0fd5a4, sizeof(Unk0fd268Work), 3, 0, 1);
    if (work == 0) {
        return 0;
    }
    Unk0fd268_Unk_0fd540(work, arg0);
    Unk0fd268_Unk_0fd574(work);
    return work;
}
