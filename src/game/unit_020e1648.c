/*
 * src/game/unit_020e1648.c: matched functions (see docs/functions/game-unit-020e1648.md).
 * Field meanings are not known yet, so layouts are modelled with typed structs and guessed
 * sizes; functions that are still decompiler-derived are marked at their definitions.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;


/* One 8-byte entry of the record table at work->unk_00d2; entry count is guessed. */
typedef struct Unk0e1648Slot {
    u16 unk_0000;
    u16 unk_0002;
    u16 unk_0004;
    u16 pad_0006;
} Unk0e1648Slot;

/* 32-bit handle table at +0xc of the object; the entry count is guessed. */
typedef struct Unk0e1648Table {
    u8 pad_0000[0xc];
    u32 unk_000c[32];
} Unk0e1648Table;

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0e1648Work {
    u8 unk_0000;
    u8 unk_0001;
    u8 pad_0002[2];
    u16 unk_0004;
    u16 unk_0006;
    u8 pad_0008[0x60];
    u32 unk_0068;
    u8 pad_006c[0x10];
    s32 unk_007c;
    u8 pad_0080[0x50];
    u16 unk_00d0;
    Unk0e1648Slot unk_00d2[440]; /* 8-byte entries; count guessed from the following fields. */
    u8 pad_0e92[6];
    u32 unk_0e98;
    u8 pad_0e9c[4];
    u32 unk_0ea0;
    u8 pad_0ea4[0x1c];
    s32 unk_0ec0;
    s32 unk_0ec4;
    u8 pad_0ec8[0x1c];
    u32 unk_0ee4;
    u32 unk_0ee8;
    u8 unk_0eec;
    u8 unk_0eed;
    u16 unk_0eee[12]; /* halfword table at +0xeee read by func_020e2e0c */
} Unk0e1648Work;

extern u32 data_02176c78[];
void Unk0e7ac4_Unk_0e8014(u32 arg0);
void Unk0e7ac4_Unk_0e8030(u32 arg0);

u32 Unk0e1648_Unk_0e5240(Unk0e1648Table *table, int index);
u32 Unk0e1648_Get_data_02176c78(void);
Unk0e1648Slot *Unk0e1648_Unk_0e2da0(Unk0e1648Work *work);
void Unk0e1648_Unk_0e2cb0(Unk0e1648Work *work);
void Unk0e1648_Unk_0e5434(void);
int Unk0e1648_Unk_0e1648(void);
int Unk0e1648_Unk_0e2c90(Unk0e1648Work *work,Unk0e1648Work *other);

typedef struct Unk0e1648Obj {
    u8 pad_0000[0xeec];
    u8 unk_0eec;
} Unk0e1648Obj;

/*
 * Reports whether the byte at +0xeec is still in use. Both the initialiser
 * (Unk0e1648_Unk_0e16f0) and the teardown path (Unk0e1648_Unk_0e2f54) store
 * 0xff there, so 0xff is the "cleared" marker and any other value means set.
 */
int Unk0e1648_IsUnkeecSet(Unk0e1648Obj *o)
{
    return o->unk_0eec != 0xff;
}

/*
 * Reads entry `index` of the Unk0e1648Table handle array. The 0e51cc/0e51f4/
 * 0e5214 helpers all use this to fetch the handle they pass to the
 * 0205c41c/0205caa8/0205c6ec functions.
 */
u32 Unk0e1648_Unk_0e5240(Unk0e1648Table *table,int index)
{
  return table->unk_000c[index];
}

/*
 * Returns word 0 of the global state block data_02176c78. Word 1 of the same
 * block is treated as a pointer by Unk0e1648_Unk_0e1664, so this is the plain
 * first-word accessor.
 */
u32 Unk0e1648_Get_data_02176c78(void)
{
  return *data_02176c78;
}

/*
 * Returns the Unk0e1648Slot selected by work->unk_007c. Callers read its
 * unk_0002/unk_0004 fields; Unk0e1648_Unk_0e2d80, for example, passes
 * unk_0002 to func_020f3de8.
 */
Unk0e1648Slot *Unk0e1648_Unk_0e2da0(Unk0e1648Work *work)
{
  return &work->unk_00d2[work->unk_007c];
}

/*
 * Flips the boolean stored at work->unk_0ec0: zero becomes one and any non-zero
 * value becomes zero.
 */
void Unk0e1648_Unk_0e2cb0(Unk0e1648Work *work)
{
  work->unk_0ec0 = (u32)(work->unk_0ec0 == 0);
}

/*
 * Forwards zero to both Unk0e7ac4_Unk_0e8014 and Unk0e7ac4_Unk_0e8030, i.e. it
 * clears/resets those two subsystems in sequence.
 */
void Unk0e1648_Unk_0e5434(void)
{
  Unk0e7ac4_Unk_0e8014(0);
  Unk0e7ac4_Unk_0e8030(0);
}

/*
 * Returns 1 when word 1 of data_02176c78 is null, else 0. Unk0e1648_Unk_0e1664
 * uses this as a guard before dereferencing that word.
 */
int Unk0e1648_Unk_0e1648(void)
{
  return data_02176c78[1] == 0;
}

/* Pointee of global word 1; only the observed +0x58 word is modelled. */
typedef struct Unk0e1648State {
    u8 pad_0000[0x58];
    u32 unk_0058;
} Unk0e1648State;

/* Returns the global pointee's +0x58 word, or zero while the global is null. */
u32 Unk0e1648_Unk_0e1664(void)
{
    if (Unk0e1648_Unk_0e1648() != 0) {
        return 0;
    }
    return ((Unk0e1648State *)data_02176c78[1])->unk_0058;
}

/* Object initialised by func_020e1698; +0x8 is not written by that function. */
typedef struct Unk0e1648Vtable {
    u32 unk_0000;
    u32 unk_0004;
    u32 pad_0008;
    void (*unk_000c)(void);
    void (*unk_0010)(void);
    void (*unk_0014)(void);
    u32 unk_0018;
    void (*unk_001c)(void);
    void (*unk_0020)(void);
} Unk0e1648Vtable;

void func_020e1b10(void);
void func_020e2190(void);
void func_020e28a8(void);
void func_020e1a48(void);
void func_020e2a5c(void);
/*
 * Fills the command/state table at `table`: constant 0xf08 in word 0, zeros in
 * words 1 and 6, and the 020e1b10/02190/028a8/01a48/02a5c handlers in the
 * remaining slots. Word 2 is left untouched because no store writes +0x8.
 */
void func_020e1698(Unk0e1648Vtable *table)
{
    table->unk_0000 = 0xf08;
    table->unk_0004 = 0;
    table->unk_000c = func_020e1b10;
    table->unk_0010 = func_020e2190;
    table->unk_0014 = func_020e28a8;
    table->unk_0018 = 0;
    table->unk_001c = func_020e1a48;
    table->unk_0020 = func_020e2a5c;
}

/*
 * Lexicographic comparison of two work objects. Returns the difference of the
 * unk_0006 words, or, when those are equal, the difference of the unk_0004
 * words. A zero result therefore means both keys match.
 */
int Unk0e1648_Unk_0e2c90(Unk0e1648Work *work,Unk0e1648Work *other)
{
  int value;
  value = (u32)work->unk_0006 - (u32)other->unk_0006;
  if (value == 0) {
    value = (u32)work->unk_0004 - (u32)other->unk_0004;
  }
  return value;
}


int func_020f3de8();
/* Forwards +0x68 and the selected slot's +2 halfword to func_020f3de8.
 * The caller must supply a work object with a valid selected slot index.
 * Returns func_020f3de8's result (020e2e60 adds to it). */
int Unk0e1648_Unk_0e2d80(Unk0e1648Work *work)
{
  return func_020f3de8(work->unk_0068, work->unk_00d2[work->unk_007c].unk_0002);
}

int func_0209993c(u32 id);
/* Caps the requested signed increment so the lookup value plus it is at most 99. */
int Unk0e1648_Unk_0e4f34(u32 arg0,int arg1)
{
  int value;
  value = func_0209993c(arg0);
  if (99 < value + arg1) {
    arg1 = 99 - value;
  }
  return arg1;
}

u32 func_020445f4(u32 selector, u32 kind);
void func_0204fed8(u32 handle, u32 value);
/* Passes the supplied value to the handle obtained with selectors 30 and 3. */
void Unk0e1648_Unk_0e50c8(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x1e,3);
  func_0204fed8(value,arg0);
}

int Unk09974c_GetEntryUnk08();
/* Tests whether the selected slot's +4 halfword maps to entry field value 4.
 * The selected slot index must be valid for work. */
int Unk0e1648_Unk_0e3f5c(Unk0e1648Work *work)
{
  int value;
  value = Unk09974c_GetEntryUnk08(work->unk_00d2[work->unk_007c].unk_0004);
  return value == 4;
}


/* Returns one only for kind 4 with a positive signed lookup result. */
u32 Unk0e1648_Unk_0e4fd0(int arg0,u32 arg1)
{
  int value;
  if ((arg0 == 4) && (value = func_0209993c(arg1), 0 < value)) {
    return 1;
  }
  return 0;
}


void Unk0e1648_Unk_0e5090(u32 arg0,u32 arg1);
int func_020e544c(Unk0e1648Work *work);
/* Selects value 2 or 3 for the +0xea0 handle using the work-kind predicate. */
void Unk0e1648_Unk_0e533c(Unk0e1648Work *arg0)
{
  int tmp1;
  tmp1 = func_020e544c(arg0);
  if (tmp1 != 0) {
    Unk0e1648_Unk_0e5090(arg0->unk_0ea0,2);
    return;
  }
  Unk0e1648_Unk_0e5090(arg0->unk_0ea0,3);
  return;
}


extern u8 data_02176c80[];
int Unk02e000_Unk_02e0cc();
int Unk0fc584_Unk_0fc84c();
/*
 * Initialises a work object: publishes it in the global at data_02176c80+4,
 * resets the 02e000 subsystem and 0fc584, clears the +0xee4 word and the
 * state bytes, sets state 1 and marks +0xeec idle (0xff).
 */
void Unk0e1648_Unk_0e16f0(Unk0e1648Work *work)
{
  *(u8 **)(((int)data_02176c80) + 4) = (u8 *)work;
  Unk02e000_Unk_02e0cc();
  Unk0fc584_Unk_0fc84c(0);
  work->unk_0ee4 = 0;
  work->unk_0001 = 0;
  work->unk_0000 = 1;
  work->unk_0eec = 0xff;
  return;
}


/*
 * Requires state kind 1, then looks up the selected slot's id in the 0f3de8
 * table and reports whether its 09974c entry kind is 4. Returns 0 for any
 * other state kind (or a missing entry).
 */
int Unk0e1648_Unk_0e2d28(Unk0e1648Work *work)
{
    u16 *entry;
    if (work->unk_0068 != 1) {
        return 0;
    }
    entry = (u16 *)func_020f3de8(1, work->unk_00d2[work->unk_007c].unk_0002);
    return Unk09974c_GetEntryUnk08(*entry) == 4;
}

void Unk0e1648_Unk_0e51cc(Unk0e1648Table *arg0, int arg1);
int Unk09974c_Unk_09a1e4();
void func_020e3174(Unk0e1648Work *work);
int Unk0f3db4_Unk_0f4510();
void func_020e5394(Unk0e1648Work *work);
/*
 * Ranks a selected record slot: 1 when its limit (unk_0002) exceeds the
 * lookup value for its id (unk_0000), otherwise 2. Returns 0 when the id is
 * not present in the 09974c table, as 020e2e60 treats zero as "no action".
 */
int Unk0e1648_Unk_0e2db0(Unk0e1648Slot *slot)
{
    int value = func_0209993c(slot->unk_0000);
    int limit = slot->unk_0002;
    if (Unk09974c_Unk_09a1e4(slot->unk_0000) != 0) {
        return 0;
    }
    return limit > value ? 1 : 2;
}

void func_02065c10(void);
void func_02065b10(u32 arg0, u16 arg1);
/*
 * Advances the +0xeed cursor through the 12-entry halfword table at +0xeee.
 * Returns 0 at the end of the table or on a zero entry; otherwise arms 02065b10
 * with a fresh 02065c10 context and returns 1.
 */
int func_020e2e0c(Unk0e1648Work *work)
{
    u8 index = work->unk_0eed;
    u16 value;
    if (index >= 12) {
        return 0;
    }
    value = work->unk_0eee[index];
    if (value == 0) {
        return 0;
    }
    func_02065c10();
    func_02065b10(0, value);
    work->unk_0eed = work->unk_0eed + 1;
    return 1;
}

void func_020e50e8(u32 arg0, u16 arg1, u32 arg2);
void Unk0a0ce4_Unk_0a0da4(u32 arg0);
/*
 * Selects a 4-byte entry from the 0f3de8 table using the +0xeec index, applies
 * it through the object at +0xe98 (mode 2 for rank 0, otherwise 0), then
 * requests animation id 1.
 */
void func_020e2e60(Unk0e1648Work *work)
{
    Unk0e1648Slot *entry = (Unk0e1648Slot *)(Unk0e1648_Unk_0e2d80(work) + 10 + work->unk_0eec * 4);
    int rank = Unk0e1648_Unk_0e2db0(entry);
    switch (rank) {
    case 0:
        func_020e50e8(work->unk_0e98, entry->unk_0000, 2);
        break;
    default:
        func_020e50e8(work->unk_0e98, entry->unk_0000, 0);
        break;
    }
    Unk0a0ce4_Unk_0a0da4(1);
}

/* The three immediate comparisons at 020e2dec test IDs 177, 178 and 179. */
int Unk0e1648_IsId177to179(int x)
{
    switch (x) {
    case 177:
    case 178:
    case 179:
        return 1;
    }
    return 0;
}

/* Clears the +0xeec marker after cleanup and handle-zero reset; 0xff is idle. */
void Unk0e1648_Unk_0e2f54(Unk0e1648Work *p)
{
    if (p->unk_0eec == 255) {
        return;
    }
    func_020e3174(p);
    Unk0e1648_Unk_0e51cc((Unk0e1648Table *)p, 0);
    p->unk_0eec = 255;
}

int func_0204faf0();
int func_020e49cc();
/* decompiler-derived */
void Unk0e1648_Unk_0e4964(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  tmp1 = Unk09974c_GetEntryUnk08();
  tmp2 = 0;
  switch(tmp1) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020e499c;
  case 4:
LAB_020e499c:
    tmp2 = func_020e49cc(6,arg0);
    break;
  case 5:
    goto LAB_020e49b0;
  case 6:
LAB_020e49b0:
    tmp2 = func_020e49cc(7,arg0);
  }
  func_0204faf0(1,tmp2);
  return;
}

extern u32 data_0213c674[];
void func_0205caa8(u32 handle, u32 value);
/* Applies the indexed global word to the corresponding object handle.
 * index must be valid for both the handle array and data_0213c674. */
void Unk0e1648_Unk_0e51f4(Unk0e1648Table *table,int index)
{
  u32 tmp1;
  tmp1 = Unk0e1648_Unk_0e5240(table, index);
  func_0205caa8(tmp1, data_0213c674[index]);
}

void func_0205c41c(u32 handle, u32 value);
/* Clears the indexed handle through 0205c41c, then reapplies its table value. */
void Unk0e1648_Unk_0e51cc(Unk0e1648Table *arg0,int arg1)
{
  u32 tmp1;
  tmp1 = Unk0e1648_Unk_0e5240(arg0, arg1);
  func_0205c41c(tmp1,0);
  Unk0e1648_Unk_0e51f4(arg0,arg1);
}

void func_0205c6ec(u32 handle);
/* Clears the indexed handle, then fetches it again for 0205c6ec. */
void Unk0e1648_Unk_0e5214(Unk0e1648Table *arg0,int arg1)
{
  u32 tmp1;
  tmp1 = Unk0e1648_Unk_0e5240(arg0, arg1);
  func_0205c41c(tmp1,0);
  tmp1 = Unk0e1648_Unk_0e5240(arg0, arg1);
  func_0205c6ec(tmp1);
}

void func_02061f10(u32 handle, s32 arg1, u32 arg2, u32 arg3, u32 arg4);
void func_02063920(void);
u32 func_02063a30(void);
/* Resets the shared state, applies the value, and submits its result to handle. */
void Unk0e1648_Unk_0e5090(u32 arg0,u32 arg1)
{
  u32 tmp1;
  func_02063920();
  Unk0e1648_Unk_0e50c8(arg1);
  tmp1 = func_02063a30();
  func_02061f10(arg0,0xffffffff,0,0,tmp1);
}

int Unk0f3db4_Unk_0f4448();
/* decompiler-derived */
void Unk0e1648_Unk_0e48a8(int arg0,u32 arg1)
{
  u16 tmp1;
  int tmp2;
  tmp2 = Unk0f3db4_Unk_0f4448(arg1);
  if (tmp2 < 1) {
    return;
  }
  tmp2 = func_020e49cc(3,arg1);
  if (tmp2 != 0) {
    return;
  }
  *(short *)(arg0 + (u32)((Unk0e1648Work *)arg0)->unk_00d0 * 8 + 0xd6) = (short)arg1;
  tmp1 = func_020e49cc(4,arg1);
  *(u16 *)(arg0 + (u32)((Unk0e1648Work *)arg0)->unk_00d0 * 8 + 0xd8) = tmp1;
  ((Unk0e1648Work *)arg0)->unk_00d0 = ((Unk0e1648Work *)arg0)->unk_00d0 + 1;
}

void func_02013c68(void *base, int count, int size,
                   int (*compare)(Unk0e1648Work *, Unk0e1648Work *));
/*
 * Appends entries first..last through Unk0e1648_Unk_0e48a8, then sorts the newly
 * appended range with func_02013c68 (record size 8) using the 0e2c90 comparator.
 */
void func_020e490c(Unk0e1648Work *work, int first, int last)
{
    u16 start = work->unk_00d0;
    while (first <= last) {
        Unk0e1648_Unk_0e48a8((int)work, first);
        first++;
    }
    func_02013c68(&work->unk_00d2[start], work->unk_00d0 - start, 8,
                  Unk0e1648_Unk_0e2c90);
}

/*
 * Looks up the work's +0x68 id through func_020f3de8 and returns 0 when the
 * resulting object's +3 byte is clear; otherwise forwards the same id and the
 * supplied value to Unk0f3db4_Unk_0f4510 and reports whether it accepted them.
 */
int Unk0e1648_Unk_0e4c64(Unk0e1648Work *work, u32 value)
{
    if (((u8 *)func_020f3de8(work->unk_0068))[3] == 0) {
        return 0;
    }
    return Unk0f3db4_Unk_0f4510(work->unk_0068, value) != 0;
}

typedef struct Unk0e1648Ent {
    u16 a;
    u16 b;
} Unk0e1648Ent;
typedef struct Unk0e1648Rec {
    u16 id;
    u8 pad_02;
    u8 unk_03;
    u8 pad_04[6];
    Unk0e1648Ent ents[3];
} Unk0e1648Rec;

int Unk0e1648_Unk_0e4f54(Unk0e1648Rec *p)
{
    int m = 0;
    int r;
    int i;
    int c;
    if (p->unk_03 != 0) {
        m = 1;
    } else {
        for (i = 0; i < 3; i++) {
            if (p->ents[i].a != 0 && m < p->ents[i].b) {
                m = p->ents[i].b;
            }
        }
    }
    if (m <= 0) {
        r = 99;
    } else {
        r = 99 / m;
    }
    c = Unk0e1648_Unk_0e4f34(p->id, 99);
    if (r > c) {
        r = c;
    }
    return r;
}

/* Restores the saved +0xec4 state, updates the work, then enters state 7. */
void Unk0e1648_Unk_0e536c(Unk0e1648Work *p)
{
    p->unk_0ee8 = 1;
    p->unk_0ec0 = p->unk_0ec4;
    func_020e5394(p);
    p->unk_0000 = 7;
}

/* Only the signed flag observed by 020e5198 is modelled; callers own the object. */
typedef struct Unk0e1648FlagObject {
    u8 pad_0000[0x40];
    s8 unk_0040;
} Unk0e1648FlagObject;

void func_02060b60(u32 arg0, Unk0e1648FlagObject *object, u32 arg2,
                   u32 arg3, u32 arg4, u32 arg5);
/* Forwards all six arguments only while the object's signed +0x40 flag is zero. */
void func_020e5198(u32 arg0, Unk0e1648FlagObject *object, u32 arg2, u32 arg3, u32 arg4, u32 arg5)
{
    if (object->unk_0040 != 0) {
        return;
    }
    func_02060b60(arg0, object, arg2, arg3, arg4, arg5);
}

/* Tests work +0x68 against kinds 0 through 5, as the original jump table does. */
int func_020e544c(Unk0e1648Work *work)
{
    switch (work->unk_0068) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}
