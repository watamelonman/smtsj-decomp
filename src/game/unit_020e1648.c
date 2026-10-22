/*
 * src/game/unit_020e1648.c: matched functions (see docs/functions/game-unit-020e1648.md).
 * Field meanings are not known yet, so layouts are modelled with typed structs and guessed
 * sizes; functions that are still decompiler-derived are marked at their definitions.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;


/* One 8-byte entry of the record table at work->unk_00d2; entry count is guessed.
 * Byte 0 is a state byte (020e33b8 draws an extra marker for state 2, which
 * state 20 of 020e1b10 promotes to 3). */
typedef struct Unk0e1648Slot {
    u8 unk_0000;
    u8 pad_0001;
    u16 unk_0002;
    u16 unk_0004;
    u16 pad_0006;
} Unk0e1648Slot;

/* One 4-byte (id, count) cost entry of a 0f3de8 record (Unk0e1648Rec.ents). */
typedef struct Unk0e1648Ent {
    u16 a;
    u16 b;
} Unk0e1648Ent;

/* 32-bit handle table at +0xc of the object; the entry count is guessed. */
typedef struct Unk0e1648Table {
    u8 pad_0000[0xc];
    u32 unk_000c[32];
} Unk0e1648Table;

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0e1648Work {
    u8 unk_0000;
    u8 unk_0001;
    u8 unk_0002;
    u8 pad_0003;
    /* Comparators use two halfword keys; render/teardown use the same word
     * as a handle, so both views must preserve the observed +0x4 layout. */
    union {
        struct {
            u16 unk_0004;
            u16 unk_0006;
        } half;
        u32 handle;
    } unk_0004;
    u32 unk_0008;
    u32 unk_000c[23]; /* handles released by func_020e1a48; count from its loop bound */
    u32 unk_0068;
    s32 unk_006c;
    s32 unk_0070;
    s32 unk_0074;
    u8 pad_0078[4];
    s32 unk_007c;
    u8 pad_0080[8];
    u32 unk_0088;
    s32 unk_008c;
    u8 pad_0090[8];
    s32 unk_0098;
    u8 pad_009c[8];
    s32 unk_00a4;
    u32 unk_00a8;
    s32 unk_00ac;
    u32 unk_00b0;
    /* Submission helpers consume this word in different typed slots. See DEC-007. */
    union { float scale; u32 bits; } unk_00b4;
    u32 unk_00b8;
    s32 unk_00bc;
    s32 unk_00c0;
    float unk_00c4;
    s32 unk_00c8;
    u32 unk_00cc;
    u16 unk_00d0;
    Unk0e1648Slot unk_00d2[440]; /* 8-byte entries; count guessed from the following fields. */
    u8 pad_0e92[2];
    u32 unk_0e94;
    u32 unk_0e98;
    u32 unk_0e9c;
    u32 unk_0ea0;
    u32 unk_0ea4[3];
    u32 unk_0eb0;
    u32 unk_0eb4;
    u8 unk_0eb8[8];
    s32 unk_0ec0;
    s32 unk_0ec4;
    u32 unk_0ec8;
    u32 unk_0ecc;
    u32 unk_0ed0;
    u8 pad_0ed4[0x10];
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

/* Forward declaration for the synchronous event callback. */
typedef struct Unk0e1648Message Unk0e1648Message;

/* Object initialised by func_020e1698; +0x8 is not written by that function.
 * The event callback receives the work and its synchronous message. */
typedef struct Unk0e1648Vtable {
    u32 unk_0000;
    u32 unk_0004;
    u32 pad_0008;
    void (*unk_000c)(Unk0e1648Work *);
    void (*unk_0010)(Unk0e1648Work *);
    void (*unk_0014)(Unk0e1648Work *);
    u32 unk_0018;
    void (*unk_001c)(Unk0e1648Work *);
    void (*unk_0020)(Unk0e1648Work *, Unk0e1648Message *);
} Unk0e1648Vtable;

void func_020e1b10(Unk0e1648Work *work);
void func_020e2190(Unk0e1648Work *work);
void func_020e28a8(Unk0e1648Work *work);
void func_020e1a48(Unk0e1648Work *work);
void func_020e2a5c(Unk0e1648Work *work, Unk0e1648Message *message);
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
  value = (u32)work->unk_0004.half.unk_0006 - (u32)other->unk_0004.half.unk_0006;
  if (value == 0) {
    value = (u32)work->unk_0004.half.unk_0004 - (u32)other->unk_0004.half.unk_0004;
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
 * Ranks a record cost entry: 1 when its count (b) exceeds the lookup value
 * for its id (a), otherwise 2. Returns 0 when the id is not present in the
 * 09974c table, as 020e2e60 treats zero as "no action".
 */
int Unk0e1648_Unk_0e2db0(Unk0e1648Ent *entry)
{
    int value = func_0209993c(entry->a);
    int limit = entry->b;
    if (Unk09974c_Unk_09a1e4(entry->a) != 0) {
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
    Unk0e1648Ent *entry = (Unk0e1648Ent *)(Unk0e1648_Unk_0e2d80(work) + 10 + work->unk_0eec * 4);
    int rank = Unk0e1648_Unk_0e2db0(entry);
    switch (rank) {
    case 0:
        func_020e50e8(work->unk_0e98, entry->a, 2);
        break;
    default:
        func_020e50e8(work->unk_0e98, entry->a, 0);
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
int func_020e49cc(u32 selector, u32 id);
/* Maps entry kinds 3/4 to selector 6 and 5/6 to selector 7, then applies channel 1. */
void Unk0e1648_Unk_0e4964(u32 arg0)
{
  u32 tmp1;
  u32 tmp2;
  tmp1 = Unk09974c_GetEntryUnk08(arg0);
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
/* Appends an accepted id and its selector-4 value; caller provides table capacity. */
void Unk0e1648_Unk_0e48a8(Unk0e1648Work *arg0,u32 arg1)
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
  arg0->unk_00d2[arg0->unk_00d0].unk_0004 = arg1;
  tmp1 = func_020e49cc(4,arg1);
  arg0->unk_00d2[arg0->unk_00d0].pad_0006 = tmp1;
  arg0->unk_00d0 = arg0->unk_00d0 + 1;
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
        Unk0e1648_Unk_0e48a8(work, first);
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

typedef struct Unk0e1648Rec {
    u16 id;
    u8 pad_02;
    u8 unk_03;
    u8 pad_04[6];
    Unk0e1648Ent ents[3];
} Unk0e1648Rec;

/* Caps 99 divided by the maximum active entry weight using the id lookup limit.
 * The +3 flag forces weight one; evidence is the entry loop at 020e4f70. */
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

/* Requires mode 1 and a nonempty first entry; rejects an already accepted slot. */
int func_020e2cc8(Unk0e1648Work *work)
{
    Unk0e1648Rec *entry;
    if (work->unk_0ec0 != 1) return 0;
    entry = (Unk0e1648Rec *)Unk0e1648_Unk_0e2d80(work);
    if (entry->ents[0].a == 0) return 0;
    if (entry->unk_03 == 0) return 1;
    return Unk0f3db4_Unk_0f4510(work->unk_0068,
        work->unk_00d2[work->unk_007c].unk_0002) == 0;
}

/* State bytes 17..19 permit the operation; state 20 also tests the +2 substate. */
int func_020e42e4(Unk0e1648Work *work)
{
    if (work->unk_0000 < 17) return 0;
    switch (work->unk_0000) {
    case 17: case 18: case 19: return 1;
    case 20:
        switch (work->unk_0002) {
        case 4: case 16: return 0;
        default: return 1;
        }
    default: return 0;
    }
}

u32 Unk0f3db4_Unk_0f44a8(u32 id);
void func_020e30f0(Unk0e1648Work *work, u32 value, u16 index);
/* Adds nonzero lookup results from count byte ids, then sorts all accumulated slots. */
void func_020e2f84(Unk0e1648Work *work, int count, const u8 *ids)
{
    int i;
    for (i = 0; i < count; i++) {
        u32 value = Unk0f3db4_Unk_0f44a8(ids[i]);
        if (value != 0) func_020e30f0(work, value, (u16)i);
    }
    func_02013c68(work->unk_00d2, work->unk_00d0, 8, Unk0e1648_Unk_0e2c90);
}

/* Accepts kind 2, an accepted id/value pair, or a record with three empty entries. */
int func_020e4ca4(Unk0e1648Work *work, u32 value)
{
    Unk0e1648Rec *entry = (Unk0e1648Rec *)func_020f3de8(work->unk_0068);
    if (entry->pad_02 == 2) return 1;
    if (Unk0e1648_Unk_0e4c64(work, value) != 0) return 1;
    return entry->ents[0].a == 0 && entry->ents[1].a == 0 && entry->ents[2].a == 0;
}

/* Stack-owned request layout observed in 020e524c; callee must consume it synchronously. */
typedef struct Unk0e1648Request {
    u8 flags[2];
    u8 pad_0002[2];
    u32 values[16];
} Unk0e1648Request;
void func_020bcbc4(u32 kind, Unk0e1648Request *request);
/* Submits a zeroed request with flag bit 1 and second value 19 to kind 3. */
void func_020e524c(void)
{
    Unk0e1648Request request;
    int i;
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.values[i] = 0;
    request.values[1] = 19;
    request.flags[0] |= 2;
    func_020bcbc4(3, &request);
}

/* Only the shared signed accumulator observed at +0x344 is modelled. */
typedef struct Unk0e1648Shared {
    u8 pad_0000[0x344];
    s32 value;
} Unk0e1648Shared;
Unk0e1648Shared *Unk02e000_GetWorkArea(void);
void Unk0fc584_Unk_0fc86c(void);
void func_02099b10(u32 id, s32 value);
/* Adds the work product to shared state, capped at 99999999, then applies the slot value. */
void func_020e41d0(Unk0e1648Work *work)
{
    s32 value = work->unk_0098;
    s32 product = work->unk_00c8 * value;
    s32 index = work->unk_007c;
    if (product + Unk02e000_GetWorkArea()->value > 99999999) {
        Unk02e000_GetWorkArea()->value = 99999999;
    } else {
        Unk02e000_GetWorkArea()->value += product;
    }
    Unk0fc584_Unk_0fc86c();
    func_02099b10(work->unk_00d2[index].unk_0004, value);
}

/* Appends a record resolved by work +0xcc and index; caller supplies slot capacity. */
void func_020e30f0(Unk0e1648Work *work, u32 value, u16 index)
{
    Unk0e1648Rec *record = (Unk0e1648Rec *)func_020f3de8(work->unk_00cc, index);
    if (func_020e49cc(2, record->id) != 0) return;
    work->unk_00d2[work->unk_00d0].unk_0000 = value;
    work->unk_00d2[work->unk_00d0].unk_0002 = index;
    work->unk_00d2[work->unk_00d0].unk_0004 = record->id;
    work->unk_00d2[work->unk_00d0].pad_0006 = func_020e49cc(4, record->id);
    work->unk_00d0++;
}

void func_02057524(u32 value);
void func_02057e58(u32 index, u32 value, u32 count);
void func_020e33b8(Unk0e1648Work *work);
void func_020e4344(Unk0e1648Work *work);
void func_02057df8(void);
void func_02057eb8(s32 value);
void func_02057fd8(void);
void func_020572d8(void);
/* For states above one, configures three ranges then dispatches by work kind. */
void func_020e28a8(Unk0e1648Work *work)
{
    if (work->unk_0000 <= 1) return;
    func_02057524(6);
    func_02057e58(0, 0, 15);
    func_02057e58(1, 15, 15);
    func_02057e58(2, 30, 15);
    if (func_020e544c(work) != 0) func_020e33b8(work);
    else func_020e4344(work);
    func_02057df8();
    func_02057eb8(-1);
    func_02057fd8();
    func_02057df8();
    func_020572d8();
}

void Unk09974c_Unk_099bac(u32 id);
/* Applies each visible slot id and restores the selected slot's two handles. */
void func_020e40a4(Unk0e1648Work *work)
{
    int first = work->unk_0074;
    int i;
    int count;
    int selected = work->unk_007c;
    func_02063920();
    i = 0;
    if (work->unk_006c > 0) do {
        Unk09974c_Unk_099bac(work->unk_00d2[first + i].unk_0004);
        func_02061f10(work->unk_0e94, -1, 0, 0, func_02063a30());
    /* Reload callback-visible count before advancing the local cursor. See DEC-006. */
        count = *(volatile s32 *)&work->unk_006c;
        i++;
    } while (i < count);
    Unk0e1648_Unk_0e4964(work->unk_00d2[selected].unk_0004);
    func_020e50e8(work->unk_0e98, work->unk_00d2[selected].unk_0004, 0);
}

void func_020bcacc(u32 kind, Unk0e1648Request *request);
/* Submits flags 0x0a and values 22/12, then resets handle zero and two subsystems. */
void func_020e52b0(Unk0e1648Table *table)
{
    Unk0e1648Request request;
    int i;
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.values[i] = 0;
    request.values[3] = 12;
    request.values[1] = 22;
    request.flags[0] |= 10;
    func_020bcacc(3, &request);
    Unk0e1648_Unk_0e5214(table, 0);
    Unk0e7ac4_Unk_0e8014(0);
    Unk0e7ac4_Unk_0e8030(0);
}

/* For selected ids 211..410, submits a synchronous request with flags 0x82. */
void func_020e4ff8(Unk0e1648Work *work)
{
    Unk0e1648Request request;
    u16 id = work->unk_00d2[work->unk_007c].unk_0004;
    int i;
    if (id < 211) return;
    if (id > 410) return;
    func_020e524c();
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.values[i] = 0;
    request.values[1] = 18;
    request.values[7] = id;
    request.flags[0] |= 130;
    func_020bcbc4(3, &request);
}

/* Advances the three-entry cursor to a nonzero id and applies its rank; returns success. */
int func_020e2eb4(Unk0e1648Work *work)
{
    int found = 0;
    Unk0e1648Rec *record = (Unk0e1648Rec *)Unk0e1648_Unk_0e2d80(work);
    int i;
    for (i = work->unk_0eec + 1; i < 3; i++) {
        if (record->ents[i].a != 0) { found = 1; break; }
    }
    if (found) {
        Unk0e1648Ent *entry;
        work->unk_0eec = i;
        entry = (Unk0e1648Ent *)(Unk0e1648_Unk_0e2d80(work) + 10 + work->unk_0eec * 4);
        switch (Unk0e1648_Unk_0e2db0(entry)) {
        case 0: func_020e50e8(work->unk_0e98, entry->a, 2); break;
        default: func_020e50e8(work->unk_0e98, entry->a, 0); break;
        }
        Unk0a0ce4_Unk_0a0da4(0);
    }
    return found;
}

void func_020e3f80(Unk0e1648Work *work, u32 value);
void Unk0cb32c_Unk_0cb57c(u32 handle);
int func_020bcc7c(s32 *value);
int Unk0bcc7c_Unk_0bcdf8(s32 *value);
/* Refreshes multi-slot state, hides unused handles through eight, and bounds the cursor. */
int func_020e4130(Unk0e1648Work *work)
{
    int result = 1;
    if (work->unk_00d0 > 1) {
        int i;
        func_020e3f80(work, 0);
        func_020e40a4(work);
        if (work->unk_00d0 < 8) {
            work->unk_00ac = work->unk_006c * 12;
            for (i = work->unk_006c; i < 8; i++) {
                Unk0cb32c_Unk_0cb57c(Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i + 13));
                work->unk_0eb8[i] = 0;
            }
            if (work->unk_007c >= work->unk_006c) func_020bcc7c(&work->unk_006c);
        }
    } else result = 0;
    return result;
}

/* External helpers used only by the functions below; prototypes follow the
 * register use observed in the delinked instructions (argument counts and
 * return values, not guessed field layouts). */
void func_020629c4(u32 handle);
void func_0205c3dc(u32 handle);
void func_0205c368(u32 handle);
void func_0205ddb4(u32 handle);
/* Sprite request record: 020e3e70 stores the selected halfword at +0xe. */
typedef struct Unk0e1648SpriteRecord {
    u8 pad_0000[0xe];
    u16 unk_000e;
} Unk0e1648SpriteRecord;
Unk0e1648SpriteRecord *func_0205e318(void *owner, int index);
void func_0205e048(u32 arg0, u32 arg1, void *arg2, u32 arg3, u32 arg4,
                   float arg5, float arg6, u32 arg7, float arg8, u32 arg9,
                   u32 arg10);
void func_02057e18(u32 value);
void func_0205de40(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4,
                   float arg5, float arg6, u32 arg7, u32 arg8, u32 arg9);
void Unk0bcef4_Unk_0bcef4(void *base, u32 arg1, u32 arg2, u32 arg3);
u8 *Unk0f3db4_Unk_0f3db4(void);

/*
 * Runs the next action step for a work object. For the ordinary kinds
 * (func_020e544c) it updates the demo/effect selectors from unk_0ec0, then
 * checks the two special action predicates and reports selector 18, 8 or 0.
 * Other kinds use the 020e3f5c predicate and report 8 or 0.
 */
void func_020e5394(Unk0e1648Work *work)
{
    if (func_020e544c(work) != 0) {
        if (work->unk_0ec0 == 0) {
            Unk0e7ac4_Unk_0e8014(5);
        } else {
            Unk0e7ac4_Unk_0e8014(6);
        }
        if (func_020e2cc8(work) != 0) {
            Unk0e7ac4_Unk_0e8030(18);
            return;
        }
        if (Unk0e1648_Unk_0e2d28(work) != 0) {
            Unk0e7ac4_Unk_0e8030(8);
            return;
        }
        Unk0e7ac4_Unk_0e8030(0);
        return;
    }
    if (Unk0e1648_Unk_0e3f5c(work) != 0) {
        Unk0e7ac4_Unk_0e8030(8);
        return;
    }
    Unk0e7ac4_Unk_0e8030(0);
}

/*
 * Builds the 0x82 request used while work kind 7 has a selected slot id in
 * the range 211..410. The 020e524c submission is also made for an id outside
 * that range (and then no range request is built), so it sits on both paths.
 */
void func_020e4238(Unk0e1648Work *work)
{
    Unk0e1648Request request;
    u16 id;
    int i;

    if (work->unk_0068 != 7) {
        return;
    }
    id = work->unk_00d2[work->unk_007c].unk_0004;
    if (id >= 211 && id <= 410) {
        func_020e524c();
        for (i = 0; i < 2; i++) {
            request.flags[i] = 0;
        }
        for (i = 0; i < 16; i++) {
            request.values[i] = 0;
        }
        request.values[1] = 18;
        request.values[7] = id;
        request.flags[0] |= 130;
        func_020bcbc4(3, &request);
        return;
    }
    func_020e524c();
}

/*
 * Applies an animation mode to one slot id. Mode 0 calls 099bac(id); mode 1
 * applies group 6 through 0e50c8. Mode 2 calls 099bac(id), then 0e50c8(10),
 * retaining the 02063a30 result. Every mode except 2 also applies group 7.
 * The captured result is the fifth argument of the 02061f10 submit call.
 */
void func_020e50e8(u32 handle, u16 id, u32 mode)
{
    u32 value;

    func_02063920();
    value = 0;
    switch (mode) {
    case 0:
        Unk09974c_Unk_099bac(id);
        func_02063a30();
        break;
    case 1:
        Unk0e1648_Unk_0e50c8(6);
        func_02063a30();
        break;
    case 2:
        Unk09974c_Unk_099bac(id);
        func_02063a30();
        Unk0e1648_Unk_0e50c8(10);
        value = func_02063a30();
        break;
    }
    if (mode != 2) {
        u32 group = func_020445f4(7, 0);
        func_0204fed8(group, id);
        value = func_02063a30();
    }
    func_02061f10(handle, -1, 0, -1, value);
}

/*
 * Releases every resource owned by a work object: the nine handle words at
 * +0xe94..+0xeb4, the 23 handles at +0xc, the two objects at +0x8/+0x4, and
 * finally the global work pointer at data_02176c80+4. The +0x4 word is the
 * pair unk_0004/unk_0006 viewed as one handle by this teardown path.
 */
void func_020e1a48(Unk0e1648Work *work)
{
    int i;

    func_020629c4(work->unk_0eb4);
    func_020629c4(work->unk_0eb0);
    for (i = 0; i < 3; i++) {
        func_020629c4(work->unk_0ea4[i]);
    }
    func_020629c4(work->unk_0ea0);
    func_020629c4(work->unk_0e98);
    func_020629c4(work->unk_0e9c);
    func_020629c4(work->unk_0e94);
    for (i = 0; i < 23; i++) {
        if (work->unk_000c[i] != 0) {
            func_0205c3dc(work->unk_000c[i]);
            work->unk_000c[i] = 0;
        }
    }
    if (work->unk_0008 != 0) {
        func_0205c368(work->unk_0008);
        work->unk_0008 = 0;
    }
    if (work->unk_0004.handle != 0) {
        func_0205ddb4(work->unk_0004.handle);
        work->unk_0004.handle = 0;
    }
    *(u32 *)(data_02176c80 + 4) = 0;
}

/*
 * Configures the three sprite slots used by a work kind: it writes the record
 * halfword at +0xe, submits an 11-argument 0205e048 request, then two
 * 10-argument 0205de40 requests that differ only by the +0xac/+0xb0 values.
 * The +0x4 pair is passed as one 32-bit handle and +0xa8 is the shared owner.
 */
void func_020e3e70(Unk0e1648Work *work)
{
    Unk0e1648SpriteRecord *object = func_0205e318((void *)work->unk_0004.handle, 29);

    object->unk_000e = (u16)work->unk_00ac;
    func_0205e048(2, work->unk_0004.handle, object, work->unk_00a8,
                  0, 1.0f, 1.0f, 0, 1.0f, 1, 1);
    func_02057e18(31);
    func_02057df8();
    func_0205de40(2, work->unk_0004.handle, 13, work->unk_00a8,
                  0, 1.0f, 1.0f, 0, work->unk_00b0, 1);
    func_0205de40(2, work->unk_0004.handle, 14, work->unk_00a8,
                  work->unk_00ac, 1.0f, 1.0f, 0,
                  work->unk_00b0, 1);
}

/*
 * Restarts the slot list for the current work kind. It saves the kind at
 * +0xcc, clears the count at +0xd0, then appends a per-kind range of ids from
 * the 0f3db4 table. When +0xee4 is clear it resets the block at +0x6c,
 * passing min(count, 8) as the range start, and finally refreshes through 020e3174.
 */
void func_020e2fe8(Unk0e1648Work *work)
{
    u8 *ids = Unk0f3db4_Unk_0f3db4();
    u16 count;

    work->unk_00cc = work->unk_0068;
    work->unk_00d0 = 0;
    switch (work->unk_0068) {
    case 0:
        func_020e2f84(work, 50, ids);
        break;
    case 1:
        func_020e2f84(work, 50, ids + 50);
        break;
    case 2:
        func_020e2f84(work, 50, ids + 100);
        break;
    case 3:
        func_020e2f84(work, 50, ids + 150);
        break;
    case 4:
        func_020e2f84(work, 100, ids + 200);
        break;
    case 5:
        func_020e2f84(work, 60, ids + 300);
        break;
    case 6:
    case 7:
    case 8:
        break;
    }
    if (work->unk_0ee4 == 0) {
        count = work->unk_00d0;
        if (count >= 8) {
            Unk0bcef4_Unk_0bcef4(&work->unk_006c, 8, count, 1);
        } else {
            Unk0bcef4_Unk_0bcef4(&work->unk_006c, count, count, 1);
        }
    }
    func_020e3174(work);
}

void func_020bcfc4(void *cursor, int index);
/* Rebuilds kind-specific slot ranges, preserving the prior cursor after removal.
 * Ranges and cursor predicates are taken from the ARM body at 020e3f80. */
void func_020e3f80(Unk0e1648Work *work, u32 value)
{
    int above, below, selected, offset;
    int count, visible;
    work->unk_00cc = work->unk_0068;
    work->unk_00d0 = 0;
    if (work->unk_00cc == 7) {
        func_020e490c(work, 211, 260);
        func_020e490c(work, 261, 310);
        func_020e490c(work, 311, 360);
        func_020e490c(work, 361, 410);
        func_020e490c(work, 51, 110);
    } else {
        func_020e490c(work, 901, 1120);
        func_020e490c(work, 1121, 1340);
    }
    offset = work->unk_0074;
    above = offset > 0;
    below = offset < work->unk_0070 - work->unk_006c;
    count = work->unk_00d0;
    selected = work->unk_007c;
    visible = count;
    if (count >= 8) visible = 8;
    Unk0bcef4_Unk_0bcef4(&work->unk_006c, visible, count, 1);
    if (value == 0) {
        if (!below && above) offset--;
        work->unk_0074 = offset;
        func_020bcfc4(&work->unk_006c, selected - 1);
    }
    func_020e40a4(work);
}

int Unk09974c_Unk_0998f0(u32 id);
/* Checks the id flags, shared unsigned budget and all three required quantities.
 * The second argument is forwarded to the existing record-acceptance predicate. */
int func_020e4d08(Unk0e1648Work *work, u32 value)
{
    Unk0e1648Rec *record = (Unk0e1648Rec *)func_020f3de8(work->unk_0068, value);
    int quantities[3] = {0, 0, 0};
    Unk0e1648Shared *shared;
    int i;
    if (Unk09974c_Unk_0998f0(record->id) != 0) return 0;
    if (Unk0e1648_Unk_0e4fd0(work->unk_0068, record->id) != 0) return 0;
    shared = Unk02e000_GetWorkArea();
    if ((u32)shared->value < (u32)func_020e49cc(0, record->id)) return 0;
    if (func_020e4ca4(work, value) != 0) return 1;
    for (i = 0; i < 3; i++) {
        if (record->ents[i].a != 0) quantities[i] = func_0209993c(record->ents[i].a);
    }
    for (i = 0; i < 3; i++) {
        if (record->ents[i].a != 0) {
            quantities[i] -= record->ents[i].b;
            if (quantities[i] < 0) return 0;
        }
    }
    return 1;
}

int func_02053824(u32 player, u32 mask);
/* Adjusts +0x98 by one or ten within [1,+0x8c] and resets the changed handle.
 * The input masks and bounds are the immediate values in 020e2774. */
int func_020e2774(Unk0e1648Work *work)
{
    int changed = 0;
    if (func_02053824(0, 64)) {
        if (work->unk_0098 < work->unk_008c) {
            work->unk_0098++;
            Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 1);
            changed = 1;
        }
    } else if (func_02053824(0, 128)) {
        if (work->unk_0098 > 1) {
            work->unk_0098--;
            Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 2);
            changed = 1;
        }
    } else if (func_02053824(0, 16)) {
        int limit = work->unk_008c;
        if (work->unk_0098 != limit) {
            if (work->unk_0098 + 10 > limit) {
                work->unk_0098 = limit;
                Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 1);
                changed = 1;
            } else {
                work->unk_0098 += 10;
                Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 1);
                changed = 1;
            }
        }
    } else if (func_02053824(0, 32) && work->unk_0098 != 1) {
        if (work->unk_0098 - 10 < 1) {
            work->unk_0098 = 1;
            Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 2);
            changed = 1;
        } else {
            work->unk_0098 -= 10;
            Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 2);
            changed = 1;
        }
    }
    return changed;
}

/* Scales sprite 30 to the visible fraction of the slot list, with height >=2.
 * Caller supplies a nonempty slot list; constants 11.5 and 92 come from the pool. */
void func_020e2930(Unk0e1648Work *work)
{
    int offset = work->unk_0074;
    Unk0e1648SpriteRecord *sprite;
    float scale;
    func_0205de40(2, work->unk_0004.handle, 17, work->unk_00a8, 0,
                  1.0f, 1.0f, 0, work->unk_00b4.bits, 1);
    sprite = func_0205e318((void *)work->unk_0004.handle, 30);
    scale = 92.0f / (11.5f * (float)work->unk_00d0);
    sprite->unk_000e = (int)(0.5f + 92.0f * scale);
    if ((s16)sprite->unk_000e <= 1) sprite->unk_000e = 2;
    func_0205e048(2, work->unk_0004.handle, sprite, work->unk_00a8,
                  (int)(0.5f + (11.5f * (float)offset) * scale),
                  1.0f, 1.0f, 0, work->unk_00b4.scale, 1, 1);
}

int Unk0f3db4_Unk_0f4490(u32 kind, u16 index);
/* Refreshes visible slot labels, the selected label, and three ingredient labels.
 * All indices must address the work slot table and the returned three-entry record. */
void func_020e3174(Unk0e1648Work *work)
{
    int first = work->unk_0074;
    int selected = work->unk_007c;
    int i;
    Unk0e1648Rec *record;
    func_02063920();
    for (i = 0; i < work->unk_006c; i++) {
        if (Unk0f3db4_Unk_0f4490(work->unk_0068, work->unk_00d2[first+i].unk_0002) != 1) {
            Unk09974c_Unk_099bac(work->unk_00d2[first+i].unk_0004);
            func_02061f10(work->unk_0e94, -1, 0, 0, func_02063a30());
        } else {
            func_0204fed8(func_020445f4(30, 3), 5);
            func_02061f10(work->unk_0e94, -1, 0, 0, func_02063a30());
        }
    }
    Unk0e1648_Unk_0e4964(work->unk_00d2[selected].unk_0004);
    if (Unk0f3db4_Unk_0f4490(work->unk_0068, work->unk_00d2[selected].unk_0002) != 1) {
        func_020e50e8(work->unk_0e98, work->unk_00d2[selected].unk_0004, 0);
    } else {
        func_020e50e8(work->unk_0e98, work->unk_00d2[selected].unk_0004, 1);
    }
    record = (Unk0e1648Rec *)func_020f3de8(work->unk_0068, work->unk_00d2[selected].unk_0002);
    for (i = 0; i < 3; i++) {
        if (record->ents[i].a != 0) {
            func_02063920();
            Unk09974c_Unk_099bac(record->ents[i].a);
            func_02061f10(work->unk_0ea4[i], -1, 0, 0, func_02063a30());
        }
    }
}

/* Lookup layouts come from the field widths in 020e49cc, not shared type identity. */
typedef struct Unk0e1648LookupA {
    u8 pad_00[3]; u8 unk_03;
    unsigned int pad_04a:10; unsigned int unk_04:10; unsigned int pad_04b:12;
    u8 pad_08[0x3e];
    unsigned short unk_46:14; unsigned short flag_46a:1; unsigned short flag_46b:1;
    u32 unk_48; u32 unk_4c;
} Unk0e1648LookupA;
typedef struct Unk0e1648LookupB {
    u8 pad_00[3]; u8 unk_03;
    unsigned short unk_04:8; unsigned short pad_04:8;
    unsigned short unk_06:8; unsigned short pad_06:6;
    unsigned short flag_06a:1; unsigned short flag_06b:1;
    u32 unk_08; u32 unk_0c;
} Unk0e1648LookupB;
typedef struct Unk0e1648LookupC {
    u8 pad_00[0x2c]; u8 unk_2c; u8 pad_2d; u8 unk_2e;
    unsigned char pad_2fa:2; unsigned char flag_2fa:1;
    unsigned char flag_2fb:1; unsigned char pad_2fb:4;
    u32 unk_30; u32 unk_34;
} Unk0e1648LookupC;
typedef struct Unk0e1648LookupD {
    u8 pad_00[3]; u8 unk_03; u16 unk_04; u8 unk_06; u8 unk_07;
    u32 unk_08; u32 unk_0c;
} Unk0e1648LookupD;
Unk0e1648LookupA *Unk09974c_Unk_099c60(u32 id);
Unk0e1648LookupB *Unk09974c_Unk_099d78(u32 id);
Unk0e1648LookupC *Unk09974c_Unk_099d14(u32 id);
Unk0e1648LookupD *Unk09974c_Unk_099ddc(u32 id);
Unk0e1648LookupD *Unk09974c_Unk_099e40(u32 id);
u32 Unk09974c_Unk_099cc4(Unk0e1648LookupA *record);
/* Returns one selected property from the id's kind-specific record, or zero.
 * Nested switches and bit widths are evidenced by 020e49cc's jump tables/loads. */
int func_020e49cc(u32 selector, u32 id)
{
    u32 kind = Unk09974c_GetEntryUnk08(id);
    u32 result = 0;
    switch (kind) {
    case 3: case 4: case 5: case 6: {
        Unk0e1648LookupA *p = Unk09974c_Unk_099c60(id);
        switch (selector) {
        case 0: result = p->unk_48; break;
        case 1: result = p->unk_4c; break;
        case 2: result = p->flag_46a; break;
        case 3: result = p->flag_46b; break;
        case 4: result = p->unk_46; break;
        case 5: result = p->unk_03; break;
        case 6: result = Unk09974c_Unk_099cc4(p); break;
        case 7: result = p->unk_04; break;
        }
        break;
    }
    case 2: {
        Unk0e1648LookupB *p = Unk09974c_Unk_099d78(id);
        switch (selector) {
        case 0: result = p->unk_08; break;
        case 1: result = p->unk_0c; break;
        case 2: result = p->flag_06a; break;
        case 3: result = p->flag_06b; break;
        case 4: result = p->unk_06; break;
        case 5: result = p->unk_03; break;
        }
        break;
    }
    case 1: {
        Unk0e1648LookupC *p = Unk09974c_Unk_099d14(id);
        switch (selector) {
        case 0: result = p->unk_30; break;
        case 1: result = p->unk_34; break;
        case 2: result = p->flag_2fa; break;
        case 3: result = p->flag_2fb; break;
        case 4: result = p->unk_2e; break;
        case 5: result = p->unk_2c; break;
        }
        break;
    }
    case 7:
        if (selector == 3) result = 1;
        break;
    case 8: {
        Unk0e1648LookupD *p = Unk09974c_Unk_099ddc(id);
        switch (selector) {
        case 0: result = p->unk_08; break;
        case 1: result = p->unk_0c; break;
        case 2: result = p->unk_06; break;
        case 3: result = p->unk_07; break;
        case 4: result = p->unk_04; break;
        case 5: result = p->unk_03; break;
        }
        break;
    }
    case 9: {
        Unk0e1648LookupD *p = Unk09974c_Unk_099e40(id);
        switch (selector) {
        case 0: result = p->unk_08; break;
        case 1: result = p->unk_0c; break;
        case 2: result = p->unk_06; break;
        case 3: result = p->unk_07; break;
        case 4: result = p->unk_04; break;
        case 5: result = p->unk_03; break;
        }
        break;
    }
    case 0:
        if (selector == 3) result = 1;
        break;
    }
    return result;
}

extern u8 data_02150b7c[], data_02150b94[];
u32 func_0205dcd4(void *data, u32 mode);
u32 func_0205c2c4(void *data);
u32 func_0205c3c0(void);
void func_0205c3fc(u32 handle, u32 owner, u32 resource);
u32 func_020629ac(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
int func_0205ca88(u32 handle);
void Unk0fc584_SetDir(u32 value);
/* Creates the work's handles and initial cursor/render state on substate zero.
 * Resource tables, handle counts and initial values are from 020e1730. */
void func_020e1730(Unk0e1648Work *work)
{
    int i;
    if (work->unk_0001 != 0) return;
    work->unk_0004.handle = func_0205dcd4(data_02150b7c, 1);
    work->unk_0008 = func_0205c2c4(data_02150b94);
    for (i = 0; i < 23; i++) {
        work->unk_000c[i] = func_0205c3c0();
        func_0205c3fc(work->unk_000c[i], work->unk_0004.handle, work->unk_0008);
    }
    work->unk_0e94 = func_020629ac(4, 4, 1, 0);
    for (i = 0; i < 8; i++) work->unk_0eb8[i] = 0;
    work->unk_0e98 = func_020629ac(5, 3, 1, 1);
    Unk0e1648_Unk_0e5090(work->unk_0e98, 1);
    work->unk_0e9c = func_020629ac(3, 1, 1, 1);
    if (work->unk_0068 == 4) Unk0e1648_Unk_0e5090(work->unk_0e9c, 9);
    else Unk0e1648_Unk_0e5090(work->unk_0e9c, 1);
    work->unk_0ea0 = func_020629ac(5, 1, 1, 1);
    Unk0e1648_Unk_0e5090(work->unk_0ea0, 2);
    for (i = 0; i < 3; i++) work->unk_0ea4[i] = func_020629ac(4, 1, 1, 1);
    work->unk_0eb0 = func_020629ac(5, 1, 1, 1);
    Unk0e1648_Unk_0e5090(work->unk_0eb0, 7);
    work->unk_0eb4 = func_020629ac(4, 1, 1, 1);
    Unk0e1648_Unk_0e5090(work->unk_0eb4, 8);
    if (work->unk_0ee4 == 0) Unk0bcef4_Unk_0bcef4(&work->unk_006c, 8, 8, 1);
    work->unk_0098 = 1;
    work->unk_00a4 = 0;
    work->unk_0002 = 0;
    work->unk_00a8 = -241;
    work->unk_00ac = 0;
    work->unk_00b0 = 0;
    work->unk_00b4.bits = 0;
    work->unk_00b8 = 0;
    work->unk_00c8 = 0;
    if (work->unk_0ec0 != 1) work->unk_0ec0 = 0;
    work->unk_0ec4 = work->unk_0ec0;
    work->unk_0ec8 = 0;
    work->unk_0ee8 = 1;
    Unk0e1648_Unk_0e51f4((Unk0e1648Table *)work, 21);
    work->unk_00c0 = func_0205ca88(Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 21)) - 1;
    work->unk_00c4 = 1.0f / (float)work->unk_00c0;
    Unk0e1648_Unk_0e51f4((Unk0e1648Table *)work, 22);
    work->unk_00bc = func_0205ca88(Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 22));
    Unk0e1648_Unk_0e51f4((Unk0e1648Table *)work, 1);
    Unk0e1648_Unk_0e51f4((Unk0e1648Table *)work, 2);
    for (i = 0; i < work->unk_006c; i++) {
        Unk0e1648_Unk_0e51f4((Unk0e1648Table *)work, i+5);
        Unk0e1648_Unk_0e51f4((Unk0e1648Table *)work, i+13);
        Unk0cb32c_Unk_0cb57c(Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i+13));
    }
    work->unk_00b8 = 0;
    if (func_020e544c(work) != 0) {
        func_020e2fe8(work);
        func_020e4ff8(work);
    } else {
        Unk0fc584_SetDir(1);
        func_020e3f80(work, 1);
        func_020e4238(work);
    }
    func_020e5394(work);
    Unk0e1648_Unk_0e533c(work);
    work->unk_0001 = 0;
    work->unk_0000 = 2;
}

/* Bit i marks values[i] as present; layout agrees with the UniteEvent messages. */
typedef struct Unk0e1648Params {
    u8 flags;
    u8 pad_01[3];
    s32 values[8];
} Unk0e1648Params;
struct Unk0e1648Message {
    u32 type;
    Unk0e1648Params params;
};
/* Missing parameters leave the caller's default intact. */
static inline int Unk0e1648_ReadParam(const Unk0e1648Params *params, int index, s32 *out)
{
    if (params == 0) return 0;
    {
        s32 value = params->values[index];
        if (params->flags & (1 << index)) {
            *out = value;
            return 1;
        }
    }
    return 0;
}
void Unk0bc1a8_Unk_0bc504(Unk0e1648Work *work, u32 value);
void func_02008904(const void *source, void *dest, u32 size);
extern u8 data_02176c88[];
/* Handles message types 0..4, restoring saved state or cursor data as requested.
 * State 19 uses flagged result parameters 2,7,6 and result codes 100..102;
 * these contracts are evidenced by 020e2a5c's branches and field accesses. */
void func_020e2a5c(Unk0e1648Work *work, Unk0e1648Message *message)
{
    Unk0e1648Params *params = &message->params;
    s32 value[1] = {0};
    switch (message->type) {
    case 0: {
        s32 kind = 0;
        Unk0e1648_ReadParam(params, 3, &kind);
        work->unk_0068 = kind;
        break;
    }
    case 3:
        switch (work->unk_0000) {
        case 19:
            Unk0e1648_ReadParam(params, 3, value);
            work->unk_0ec8 = value[0];
            work->unk_0000 = work->unk_0002;
            break;
        case 8:
            work->unk_0000 = work->unk_0002;
            if (Unk0e1648_Unk_0e2d28(work) != 0 || Unk0e1648_Unk_0e3f5c(work) != 0) {
                func_020e5394(work);
            }
            Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 0);
            break;
        }
        break;
    case 2:
        if (work->unk_0068 != 8) func_020e524c();
        work->unk_0000 = 0;
        break;
    case 1:
        if (work->unk_0068 != 8) func_020e524c();
        Unk0bc1a8_Unk_0bc504(work, 0);
        break;
    case 4:
        if (work->unk_0000 == 19) {
            s32 accepted = 0;
            s32 kind = 0;
            Unk0e1648_ReadParam(params, 2, value);
            Unk0e1648_ReadParam(params, 7, &accepted);
            Unk0e1648_ReadParam(params, 6, &kind);
            switch (value[0]) {
            case 100: break;
            case 101:
                if (accepted != 0 && kind == 1) {
                    work->unk_0ec0 = work->unk_0ec4;
                    work->unk_0ee8 = 1;
                }
                break;
            case 102:
                if (accepted != 0) {
                    work->unk_0ec0 = work->unk_0ec4;
                    work->unk_0ee8 = 1;
                }
                break;
            }
        } else {
            work->unk_0ee4 = 1;
            func_02008904(data_02176c88, &work->unk_006c, 28);
            work->unk_0ec0 = data_02176c80[0];
        }
        break;
    }
}

/* External helpers for the four large state-machine functions below. Their
 * prototypes follow the delinked register/stack use, not guessed parameter
 * meanings; constants in the callers come from the literal pools. */
void func_0205257c(u32 value);
void func_020525cc(u32 value);
int func_02052728(void);
int func_02053800(s32 player, u32 mask);
int func_02065cd0(void);
void func_02065c30(void);
int func_020654cc(void);
void func_02057ddc(u32 value);
void func_0205c748(u32 mode, u32 handle, u32 x, u32 y, float sx, float sy,
                   u32 rot, float alpha, u32 priority);
void func_0205c704(u32 handle);
void func_02058e9c(u32 mode, u32 resource, s32 x, s32 y, float alpha,
                   u32 arg5, u32 arg6);
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 arg3, u32 arg4, u32 arg5,
                   u32 resource, u32 value);
int func_020a1554(void *table, int count, u16 id);
void func_02096c8c(void);
int func_020e4e28(Unk0e1648Work *work, u32 id);
u32 Unk0ca69c_Unk_0ca69c(int id);
void Unk0cb32c_Unk_0cb488(u32 handle, s32 x, s32 y, u32 index, u32 arg4, u32 arg5);
void Unk0bc1a8_Unk_0bc9b4(u32 slot, u32 value);
int Unk09974c_Unk_099ea4(u32 id);
void Unk09974c_Unk_099f24(u32 id);
int Unk09974c_Unk_0998d8(u32 id);
int Unk0f3db4_Unk_0f44e4(u32 kind, u16 index);
void func_020fa8a8(u32 resource, void *object, u32 mode);
void func_020faa20(u32 value);
void func_020e32e8(Unk0e1648Work *work);
int Unk0fc584_Unk_0fc7f4(void);
extern u32 data_0213c65c[];
extern u8 data_02150bac[], data_02150bb0[], data_02150bb4[], data_02150bb8[];
extern u8 data_02150bbc[], data_02150bc0[], data_02150bc4[];
extern u8 data_02150bc8[], data_02150bcc[], data_02150bd0[];

/* Runs the top-level work state machine. State 1 initialises the object;
 * states 2..3 arm the slot handles and wait for the entry animation; state 4
 * releases them; state 5 saves the cursor block and resumes the prior state;
 * states 10..15 and 18..20 drive selection, enumeration and the final result.
 * The 21-entry jump table at 020e1b24 fixes the state numbers. */
void func_020e1b10(Unk0e1648Work *work)
{
    Unk0e1648Request request;
    Unk0e1648Slot *slot;
    u32 handle;
    int i;

    switch (work->unk_0000) {
    case 0:
        break;
    case 1:
        func_020e1730(work);
        break;
    case 2:
        work->unk_00a8 = 0;
        work->unk_00b0 = 0x3f800000;
        work->unk_00ac = work->unk_006c * 12;
        for (i = 0; i < work->unk_006c; i++) {
            work->unk_0eb8[i] = 1;
            Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, i + 13);
        }
        Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 3);
        Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 4);
        work->unk_00b8 = 0;
        work->unk_0001 = 0;
        work->unk_0000 = 3;
        break;
    case 3:
        work->unk_00b4.scale += work->unk_00c4;
        Unk0e1648_Unk_0e51cc((Unk0e1648Table *)work, 0);
        work->unk_00b8 = 0;
        work->unk_00b4.scale = 1.0f;
        if (func_020e544c(work) != 0) {
            if (work->unk_0ee4 != 0) {
                func_020525cc(0);
                work->unk_0000 = 6;
            } else {
                func_020e5394(work);
                work->unk_0000 = 7;
            }
        } else {
            func_020e5394(work);
            work->unk_0000 = 16;
        }
        break;
    case 4:
        work->unk_00b8 = 0;
        work->unk_00a8 = 0xffffff0f;
        work->unk_00ac = 0;
        work->unk_0001 = 0;
        work->unk_00b4.bits = 0;
        work->unk_0000 = 0;
        for (i = 0; i < 8; i++) {
            handle = Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i + 13);
            Unk0cb32c_Unk_0cb57c(handle);
            work->unk_0eb8[i] = 0;
        }
        handle = Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 3);
        func_0205c41c(handle, work->unk_00b8);
        handle = Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 3);
        func_0205c6ec(handle);
        handle = Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 4);
        func_0205c41c(handle, work->unk_00b8);
        handle = Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 4);
        func_0205c6ec(handle);
        Unk0bc1a8_Unk_0bc9b4(22, 0);
        break;
    case 5: {
        int j;
        if (func_02052728() != 0) break;
        work->unk_0000 = 0;
        for (j = 0; j < 2; j++) request.flags[j] = 0;
        for (j = 0; j < 16; j++) request.values[j] = 0;
        request.values[7] = 1;
        request.flags[0] |= 0x80;
        func_020bcbc4(21, &request);
        func_02008904(&work->unk_006c, data_02176c88, 28);
        data_02176c80[0] = (u8)work->unk_0ec4;
        break;
    }
    case 6:
        if (func_02052728() == 0) work->unk_0000 = 7;
        break;
    case 7:
    case 8:
    case 9:
        break;
    case 10:
        if (work->unk_0ec8 == 0) {
            u16 id;
            func_020e32e8(work);
            work->unk_0000 = 20;
            slot = &work->unk_00d2[work->unk_007c];
            id = slot->unk_0004;
            switch (work->unk_0068) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (Unk09974c_Unk_099ea4(id) != 0) {
                    work->unk_0002 = 19;
                } else {
                    work->unk_0002 = 7;
                }
                break;
            case 4:
                if (Unk0e1648_IsId177to179(id) != 0) {
                    work->unk_0000 = 11;
                }
                work->unk_0002 = 19;
                break;
            case 5:
                work->unk_0002 = 7;
                break;
            }
            work->unk_0098 = 1;
        } else {
            if (work->unk_0068 == 4) {
                Unk0e1648_Unk_0e536c(work);
                Unk0fc584_Unk_0fc84c(0);
            } else {
                work->unk_0000 = 9;
            }
        }
        break;
    case 11:
        if (Unk0fc584_Unk_0fc7f4() == 0) {
            Unk0fc584_Unk_0fc84c(0);
            if (func_020a1554(work->unk_0eee, 12,
                               work->unk_00d2[work->unk_007c].unk_0004) != 0) {
                work->unk_0eed = 0;
                if (func_020e2e0c(work) != 0) {
                    work->unk_0000 = 12;
                } else {
                    work->unk_0000 = 20;
                }
            } else {
                work->unk_0000 = 20;
            }
        }
        break;
    case 12:
        if (func_02065cd0() != 0 && func_020e2e0c(work) == 0) {
            work->unk_0000 = 13;
            func_02065c30();
        }
        break;
    case 13:
        if (func_020654cc() != 0) work->unk_0000 = 20;
        break;
    case 14:
        if (work->unk_0ec8 == 0) {
            if (work->unk_0068 == 4) {
                func_0205257c(0);
                work->unk_0000 = 5;
            } else {
                Unk09974c_Unk_099f24(work->unk_00d2[work->unk_007c].unk_0004);
                func_02096c8c();
                Unk0a0ce4_Unk_0a0da4(37);
                Unk0bc1a8_Unk_0bc928(23, 22, 0);
                work->unk_0ecc = work->unk_00d2[work->unk_007c].unk_0004;
                func_020fa8a8(102, &work->unk_0ecc, 0);
                func_020faa20(1);
                work->unk_0002 = 15;
                work->unk_0000 = 19;
            }
        } else {
            Unk0e1648_Unk_0e536c(work);
        }
        break;
    case 15:
        Unk0e1648_Unk_0e536c(work);
        break;
    case 16:
    case 17:
        break;
    case 18:
        if (work->unk_0ec8 == 0) {
            func_020e41d0(work);
            work->unk_0000 = 20;
            if (Unk0f3db4_Unk_0f4448(work->unk_00d2[work->unk_007c].unk_0004) == 0) {
                if (func_020e4130(work) == 0) {
                    work->unk_0002 = 4;
                } else {
                    func_020e4238(work);
                    work->unk_0002 = 16;
                }
            } else {
                work->unk_0002 = 16;
            }
            work->unk_0098 = 1;
        } else {
            work->unk_0000 = 17;
        }
        break;
    case 19:
        break;
    case 20:
        if (Unk0fc584_Unk_0fc7f4() != 0) break;
        Unk0fc584_Unk_0fc84c(0);
        if (func_020e544c(work) != 0) {
            slot = Unk0e1648_Unk_0e2da0(work);
            if (slot->unk_0000 == 2) slot->unk_0000 = 3;
            Unk0f3db4_Unk_0f44e4(work->unk_0068, slot->unk_0002);
        }
        work->unk_0000 = work->unk_0002;
        switch (work->unk_0002) {
        case 19:
            Unk0bc1a8_Unk_0bc928(23, 22, 0);
            work->unk_0ecc = work->unk_00d2[work->unk_007c].unk_0004;
            func_020fa8a8(101, &work->unk_0ecc, 1);
            func_020faa20(1);
            work->unk_0002 = 14;
            break;
        case 7:
            Unk0e1648_Unk_0e536c(work);
            break;
        case 4:
            work->unk_00b8 = work->unk_00c0 - 1;
            Unk0fc584_SetDir(0);
            break;
        case 16:
            func_020e5394(work);
            break;
        }
        break;
    }
    if (work->unk_0000 <= 1) return;
    for (i = 0; i < 23; i++) {
        handle = Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i);
        func_0205c704(handle);
    }
}

/* Advances the normal action state machine. Only states 7, 9, 16 and 17 are
 * handled; the others return. State 7 processes the primary input masks and
 * starts the selected record; state 9 and 17 consume the quantity-cursor
 * inputs and finish the shared score update; state 16 refreshes the list. */
void func_020e2190(Unk0e1648Work *work)
{
    Unk0e1648Rec *record;
    Unk0e1648Slot *slot;
    u32 id;
    int value;

    switch (work->unk_0000) {
    case 7:
        if (work->unk_0070 > 1 && Unk0bcc7c_Unk_0bcdf8(&work->unk_006c) != 0) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020e3174(work);
            func_020e4ff8(work);
            func_020e5394(work);
            Unk0e1648_Unk_0e2f54(work);
            return;
        }
        if (func_02053800(0, 0x800) != 0) {
            if (func_020e2cc8(work) != 0) {
                if (work->unk_0eec == 0xff) {
                    work->unk_0eec = 0;
                    func_020e2e60(work);
                    return;
                }
                if (func_020e2eb4(work) != 0) return;
                Unk0a0ce4_Unk_0a0da4(1);
                Unk0e1648_Unk_0e2f54(work);
                return;
            }
            if (Unk0e1648_Unk_0e2d28(work) != 0) {
                func_020e52b0((Unk0e1648Table *)work);
                work->unk_0002 = 7;
                work->unk_0000 = 8;
            }
            return;
        }
        if (func_02053800(0, 0x400) != 0) {
            Unk0a0ce4_Unk_0a0da4(1);
            Unk0e1648_Unk_0e2cb0(work);
            func_020e5394(work);
            Unk0e1648_Unk_0e2f54(work);
            return;
        }
        if (func_02053800(0, 1) != 0) {
            Unk0e1648_Unk_0e2f54(work);
            slot = &work->unk_00d2[work->unk_007c];
            id = slot->unk_0002;
            if (func_020e4d08(work, id) != 0) {
                record = (Unk0e1648Rec *)func_020f3de8(work->unk_0068, id);
                work->unk_00a4 = Unk0e1648_Unk_0e4f34(record->id,
                    func_020e4e28(work, id));
                work->unk_00c8 = func_020e49cc(0, record->id);
                Unk0fc584_Unk_0fc84c(-work->unk_00c8);
                if (work->unk_0068 == 4) {
                    Unk0bcef4_Unk_0bcef4(&work->unk_0088, 10, 1, 0);
                    Unk0bc1a8_Unk_0bc928(23, 22, 0);
                    work->unk_0ecc = work->unk_00d2[work->unk_007c].unk_0004;
                    work->unk_0ed0 = work->unk_00c8;
                    func_020fa8a8(100, &work->unk_0ecc, 1);
                    work->unk_0002 = 10;
                    work->unk_0000 = 19;
                } else {
                    Unk0bcef4_Unk_0bcef4(&work->unk_0088, 10,
                        Unk0e1648_Unk_0e4f54(record), 0);
                    work->unk_0000 = 9;
                }
                work->unk_0ec4 = work->unk_0ec0;
                work->unk_0ec0 = 1;
                Unk0e1648_Unk_0e5434();
                work->unk_0098 = 1;
                Unk0a0ce4_Unk_0a0da4(1);
                return;
            }
            if (work->unk_0ec0 == 0) {
                Unk0e1648_Unk_0e2cb0(work);
                func_020e5394(work);
            }
            Unk0a0ce4_Unk_0a0da4(4);
            return;
        }
        if (func_02053800(0, 2) != 0) {
            Unk0a0ce4_Unk_0a0da4(2);
            work->unk_00b8 = work->unk_00c0 - 1;
            work->unk_0000 = 4;
        }
        return;
    case 9:
        if (func_020e2774(work) != 0) {
            Unk0a0ce4_Unk_0a0da4(0);
        } else if (func_02053800(0, 1) != 0) {
            if (work->unk_0098 <= work->unk_00a4) {
                Unk0a0ce4_Unk_0a0da4(1);
                Unk0bc1a8_Unk_0bc928(23, 22, 0);
                work->unk_0ecc = work->unk_00d2[work->unk_007c].unk_0004;
                work->unk_0ed0 = work->unk_00c8 * work->unk_0098;
                func_020fa8a8(100, &work->unk_0ecc, 1);
                work->unk_0002 = 10;
                work->unk_0000 = 19;
            } else {
                Unk0a0ce4_Unk_0a0da4(4);
            }
        } else if (func_02053800(0, 2) != 0) {
            Unk0a0ce4_Unk_0a0da4(2);
            work->unk_0098 = 1;
            Unk0fc584_Unk_0fc84c(0);
            Unk0e1648_Unk_0e536c(work);
            return;
        }
        Unk0fc584_Unk_0fc84c(-(work->unk_00c8 * work->unk_0098));
        return;
    case 16:
        if (work->unk_0070 > 1 && Unk0bcc7c_Unk_0bcdf8(&work->unk_006c) != 0) {
            Unk0a0ce4_Unk_0a0da4(0);
            func_020e40a4(work);
            func_020e4238(work);
            func_020e5394(work);
            return;
        }
        if (func_02053800(0, 0x800) != 0) {
            if (Unk0e1648_Unk_0e3f5c(work) == 0) return;
            func_020e52b0((Unk0e1648Table *)work);
            work->unk_0002 = 16;
            work->unk_0000 = 8;
            return;
        }
        if (func_02053800(0, 1) != 0) {
            int selected;
            Unk0a0ce4_Unk_0a0da4(1);
            selected = work->unk_007c;
            work->unk_00c8 = func_020e49cc(1,
                work->unk_00d2[selected].unk_0004);
            Unk0fc584_Unk_0fc84c(work->unk_00c8);
            Unk0bcef4_Unk_0bcef4(&work->unk_0088, 10,
                Unk0f3db4_Unk_0f4448(work->unk_00d2[selected].unk_0004), 0);
            work->unk_0098 = 1;
            Unk0e1648_Unk_0e5434();
            work->unk_0000 = 17;
            return;
        }
        if (func_02053800(0, 2) != 0) {
            Unk0a0ce4_Unk_0a0da4(2);
            work->unk_00b8 = work->unk_00c0 - 1;
            Unk0fc584_SetDir(0);
            work->unk_0000 = 4;
        }
        return;
    case 17:
        if (func_020e2774(work) != 0) {
            Unk0a0ce4_Unk_0a0da4(0);
        } else if (func_02053800(0, 1) != 0) {
            Unk0a0ce4_Unk_0a0da4(1);
            Unk0bc1a8_Unk_0bc928(23, 22, 0);
            work->unk_0ecc = work->unk_00d2[work->unk_007c].unk_0004;
            work->unk_0ed0 = work->unk_00c8 * work->unk_0098;
            func_020fa8a8(103, &work->unk_0ecc, 1);
            work->unk_0002 = 18;
            work->unk_0000 = 19;
        } else if (func_02053800(0, 2) != 0) {
            Unk0a0ce4_Unk_0a0da4(2);
            work->unk_0098 = 1;
            Unk0fc584_Unk_0fc84c(0);
            func_020e5394(work);
            work->unk_0000 = 16;
            return;
        }
        Unk0fc584_Unk_0fc84c(work->unk_00c8 * work->unk_0098);
        return;
    default:
        return;
    }
}

/* func_020e33b8 and func_020e4344 stay in the delink object; their matching
 * trials are recorded in docs/functions/game-unit-020e1648.md. */

void func_02057ddc(u32 value);
void func_02057e18(u32 value);
void func_02057df8(void);
void func_02057eb8(s32 value);
void func_0205de40(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4,
                   float arg5, float arg6, u32 arg7, u32 arg8, u32 arg9);
void func_0205c748(u32 mode, u32 handle, u32 x, u32 y, float sx, float sy,
                   u32 rot, float alpha, u32 priority);
void func_02058e9c(u32 mode, u32 resource, s32 x, s32 y, float alpha,
                   u32 arg5, u32 arg6);
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 arg3, u32 arg4, u32 arg5,
                   u32 resource, u32 value);
u32 Unk0ca69c_Unk_0ca69c(int id);
void Unk0cb32c_Unk_0cb488(u32 handle, s32 x, s32 y, u32 index, u32 arg4, u32 arg5);
int Unk0f3db4_Unk_0f4490(u32 kind, u16 index);
int Unk09974c_Unk_0998d8(u32 id);
void func_020e3e70(Unk0e1648Work *work);
void func_020e2930(Unk0e1648Work *work);
int func_020e4d08(Unk0e1648Work *work, u32 value);
int func_020e49cc(u32 selector, u32 id);
extern u32 data_0213c65c[];
extern u8 data_02150bac[], data_02150bb0[], data_02150bb4[], data_02150bb8[];
extern u8 data_02150bbc[], data_02150bc0[], data_02150bc4[];

/* Draws the ordinary multi-slot list: one row per visible slot, the
 * quantity box once the work reaches state 9, then the detail panel for the
 * selected record (cost entries when +0xec0 is set). */
void func_020e33b8(Unk0e1648Work *work)
{
    int sel = work->unk_007c;
    int first = work->unk_0074;
    int qty;
    int sely = (sel - first) * 12;
    Unk0e1648Rec *rec;
    int i;
    qty = work->unk_0098;
    rec = (Unk0e1648Rec *)Unk0e1648_Unk_0e2d80(work);
    func_02057e18(31);
    func_02057df8();
    func_02057eb8(0);
    func_020e3e70(work);
    func_0205de40(2, work->unk_0004.handle, data_0213c65c[work->unk_0068], work->unk_00a8,
                  0, 1.0f, 1.0f, 0, 0x3f800000, 1);
    if (work->unk_0000 >= 7) {
        func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 0), work->unk_00a8, sely,
                      1.0f, 1.0f, 0, 1.0f, 1);
    }
    func_02057e18(31);
    func_02057df8();
    for (i = 0; i < work->unk_006c; i++) {
        u32 y = i * 12;
        func_02057eb8(1);
        func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i + 13), work->unk_00a8, y,
                      1.0f, 1.0f, 0, 1.0f, 1);
        if (work->unk_0eb8[i] == 0) {
            continue;
        }
        func_02058e9c(1, Unk0ca69c_Unk_0ca69c(func_020e49cc(5, work->unk_00d2[first + i].unk_0004)),
                      work->unk_00a8 + 16, y + 31, 1.0f, 0, 11);
        func_02057e18(31);
        if (func_020e4d08(work, work->unk_00d2[first + i].unk_0002) != 0) {
            func_02057ddc(-1);
        } else {
            func_02057ddc(0x808080ff);
        }
        Unk0cb32c_Unk_0cb488(work->unk_0e94, work->unk_00a8 + 40, y + 32, i, 8, 11);
        func_02057df8();
        if (work->unk_00d2[first + i].unk_0000 == 2) {
            func_0205de40(2, work->unk_0004.handle, 1, work->unk_00a8, y,
                          1.0f, 1.0f, 0, 0x3f800000, 1);
            func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, i + 5), work->unk_00a8, y,
                          1.0f, 1.0f, 0, 1.0f, 1);
        }
        func_02057e18(31);
        func_02057df8();
        func_0205de40(2, work->unk_0004.handle, 5, work->unk_00a8, y,
                      1.0f, 1.0f, 0, 0x3f800000, 2);
        func_02057e18(31);
        func_02057df8();
        if (Unk0f3db4_Unk_0f4490(work->unk_0068, work->unk_00d2[first + i].unk_0002) >= 2) {
            func_020a9fd8(1, work->unk_00a8 + 201, y + 33, 2, 5, 11, (u32)data_02150bac,
                          func_020e49cc(0, work->unk_00d2[first + i].unk_0004));
            func_02058e9c(1, 0x611b, work->unk_00a8 + 210, y + 33, 1.0f, 0, 11);
        }
    }
    if (work->unk_0000 >= 9 && work->unk_0068 != 4) {
        func_02057eb8(2);
        func_0205de40(2, work->unk_0004.handle, 4, work->unk_00a8, sely,
                      1.0f, 1.0f, 0, 0x3f800000, 1);
        func_02057e18(31);
        if (work->unk_0098 <= work->unk_00a4) {
            func_02057df8();
        } else {
            func_02057ddc(0x808080ff);
        }
        func_020a9fd8(1, work->unk_00a8 + 232, sely + 33, 2, 5, 15, (u32)data_02150bb0,
                      work->unk_0098);
        func_02057df8();
        if (qty < work->unk_008c) {
            func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 1), work->unk_00a8, sely,
                          1.0f, 1.0f, 0, 1.0f, 1);
        }
        if (qty > 1) {
            func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 2), work->unk_00a8, sely,
                          1.0f, 1.0f, 0, 1.0f, 1);
        }
        func_02057e18(31);
        func_02057df8();
    }
    if (work->unk_00d0 >= 8) {
        func_02057eb8(2);
        func_020e2930(work);
    }
    func_02057eb8(2);
    func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 3), 0, 0,
                  1.0f, 1.0f, 0, 1.0f, 1);
    if (work->unk_0ec0 == 0) {
        func_0205de40(2, work->unk_0004.handle, 22, 0, 0,
                      1.0f, 1.0f, 0, work->unk_00b4.bits, 1);
        if (work->unk_00b4.scale >= 1.0f) {
            func_020e5198(1, (Unk0e1648FlagObject *)work->unk_0e98, 14, 136, 0, 11);
            if (Unk0f3db4_Unk_0f4490(work->unk_0068, work->unk_00d2[sel].unk_0002) >= 2) {
                func_02057ddc(0x2994ffff);
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0e9c, 192, 138, 0, 11);
                func_02057df8();
                if (work->unk_0068 == 4) {
                    func_020a9fd8(1, 229, 141, 2, 5, 15, (u32)data_02150bb4,
                                  Unk09974c_Unk_099d78(rec->id)->unk_04);
                } else {
                    func_020a9fd8(1, 229, 141, 2, 5, 15, (u32)data_02150bb8,
                                  func_0209993c(rec->id));
                }
            }
        }
    } else {
        func_0205de40(2, work->unk_0004.handle, 21, 0, 0,
                      1.0f, 1.0f, 0, work->unk_00b4.bits, 1);
        if (work->unk_00b4.scale >= 1.0f) {
            if (Unk0e1648_IsUnkeecSet((Unk0e1648Obj *)work) != 0) {
                Unk0e1648Ent *ent = &rec->ents[work->unk_0eec];
                int have;
                switch (Unk0e1648_Unk_0e2db0(ent)) {
                case 0:
                    func_02057ddc(0xd02848ff);
                    break;
                case 1:
                    func_02057ddc(0x808080ff);
                    break;
                }
                func_020e5198(1, (Unk0e1648FlagObject *)work->unk_0e98, 14, 136, 0, 11);
                have = func_0209993c(ent->a);
                func_02057ddc(0x2994ffff);
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0e9c, 192, 138, 0, 11);
                func_02057df8();
                func_020a9fd8(1, 229, 141, 2, 5, 15, (u32)data_02150bbc, have);
            } else if (Unk09974c_GetEntryUnk08(rec->id) == 2 && Unk09974c_Unk_0998d8(rec->id) != 0
                       && work->unk_0ee8 == 1) {
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0eb4, 14, 136, 0, 11);
            } else if (rec->ents[0].a == 0) {
                func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0eb0, 14, 136, 0, 11);
            } else {
                int have;
                int need;
                int ty;
                int row;
                for (i = 0, row = 0, ty = 140; i < 3; ty += 11, row += 11, i++) {
                    u32 id = rec->ents[i].a;
                    if (id == 0) {
                        continue;
                    }
                    have = func_0209993c(id);
                    if (rec->unk_03 != 0) {
                        u16 index = work->unk_00d2[work->unk_007c].unk_0002;
                        if (work->unk_0ee8 != 0 && Unk0f3db4_Unk_0f4510(work->unk_0068, index) != 0) {
                            func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0eb0, 14, 136, 0, 11);
                            break;
                        }
                        need = rec->ents[i].b;
                    } else {
                        need = qty * rec->ents[i].b;
                    }
                    if (Unk09974c_Unk_09a1e4(id) != 0) {
                        func_02057ddc(0xd02848ff);
                    } else if (need > have) {
                        func_02057ddc(0x808080ff);
                    }
                    func_020e5198(1, (Unk0e1648FlagObject *)work->unk_0ea4[i], 34, ty - 2, 0, 11);
                    func_02057df8();
                    func_0205de40(2, work->unk_0004.handle, 20, 0, row,
                                  1.0f, 1.0f, 0, work->unk_00b4.bits, 1);
                    func_02057e18(31);
                    func_020a9fd8(1, 174, ty + 1, 2, 5, 15, (u32)data_02150bc0, have);
                    func_02057ddc(0x73ffbdff);
                    func_020a9fd8(1, 196, ty + 1, 2, 5, 15, (u32)data_02150bc4, need);
                    func_02057df8();
                }
            }
        }
    }
    func_02057eb8(2);
    func_0205c748(2, Unk0e1648_Unk_0e5240((Unk0e1648Table *)work, 4), 0, 0,
                  1.0f, 1.0f, 0, 1.0f, 1);
    func_02057e18(31);
    if (work->unk_00b4.scale >= 1.0f) {
        func_02057ddc(0x73ffbdff);
        func_02060b60(1, (Unk0e1648FlagObject *)work->unk_0ea0, 138, 179, 0, 15);
    }
}
