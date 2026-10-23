/* src/game/unit_0206ea70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Globals at 0x02170ccc. */
typedef struct Unk06ea70Table {
    u32 count;                  /* +0x00 (assumed) */
    u32 entry[1];               /* +0x04, variable length */
} Unk06ea70Table;

typedef struct Unk06ea70Globals {
    Unk06ea70Table *table;      /* +0x00 */
    u32 unk_04;                 /* +0x04 */
} Unk06ea70Globals;

extern Unk06ea70Globals data_02170ccc;



extern u32 data_02170cd4[];
extern u32 data_021457e8[];
u8 *Unk06ea70_GetBuf04Slot(int i);
/* Return the first nonzero slot selected by the 16-entry bit table, or slot zero when no selected entry exists. */
u32 Unk06ea70_FindByMask(u32 mask)
{
    int i;
    for (i = 0; i < 16; i++) {
        if ((mask & data_021457e8[i]) && data_02170cd4[i] != 0) {
            return data_02170cd4[i];
        }
    }
    return data_02170cd4[0];
}

int func_02053000();
void Unk06ea70_Unk_06f4e4(void);

/* Clear the sixteen global entries and release both global allocations through the original cleanup sequence. */
void Unk06ea70_Unk_06eb54(void)
{
    int i;
    for (i = 0; i < 16; i++) {
        data_02170cd4[i] = 0;
    }
    func_02053000(data_02170ccc.table->count);
    data_02170ccc.table->count = 0;
    func_02053000(data_02170ccc.table);
    data_02170ccc.table = 0;
    Unk06ea70_Unk_06f4e4();
}

/* Return -1 for an absent table or entry; otherwise borrow its buffer-04 slot. Caller supplies an in-range index. */
int Unk06ea70_Unk_06ebb8(int i)
{
    Unk06ea70Table *t = data_02170ccc.table;
    if (t == 0 || t->entry[i] == 0) {
        return -1;
    }
    return (int)Unk06ea70_GetBuf04Slot(i);
}

typedef struct Unk06ea70Bufs {
    u8 *buf_00;                 /* 512-byte slots */
    u8 *buf_04;                 /* 512-byte slots */
    u8 pad_0008[4];
    u32 mask_0c;
    u32 mask_10;
} Unk06ea70Bufs;

void func_02061424();
void Unk06ea70_SetMask0cBit(int i);
/* Release a nonzero table entry through func_02061424 and clear its slot. Caller supplies a valid table index. */
void Unk06ea70_ReleaseEntry(int i)
{
    if (data_02170ccc.table->entry[i] == 0) {
        return;
    }
    func_02061424(data_02170ccc.table->entry[i]);
    data_02170ccc.table->entry[i] = 0;
}

/* Store a nonzero entry and mark its slot in mask_0c (stores at 0x0206ec40, call at 0x0206ec44). Caller supplies a valid table index. */
void Unk06ea70_SetEntry(int i, u32 p)
{
    if (p == 0) {
        return;
    }
    data_02170ccc.table->entry[i] = p;
    Unk06ea70_SetMask0cBit(i);
}

/* Read table + 4 + i * 4, as at 0x0206ec58..0x0206ec5c. The table must be initialized and i must be in range. */
u32 Unk06ea70_GetTableEntry(int i)
{
    return data_02170ccc.table->entry[i];
}

/* Expand 256 packed RGB555 words into three caller-owned component arrays, with each five-bit component shifted left by 15. */
void Unk06ea70_Unk_06edf4(int *arg0,int *arg1,int *arg2,u16 *arg3)
{
  u32 value1;
  int value2;
  value2 = 0;
  do {
    value1 = (u32)*arg3;
    value2 = value2 + 1;
    *arg0 = (value1 & 0x1f) << 0xf;
    *arg1 = ((int)value1 >> 5 & 0x1fU) << 0xf;
    *arg2 = ((int)value1 >> 10 & 0x1fU) << 0xf;
    arg0 = arg0 + 1;
    arg1 = arg1 + 1;
    arg2 = arg2 + 1;
    arg3 = arg3 + 1;
  } while (value2 < 0x100);
}


int func_02053000();
/* Pass the state address at global +0x04 to func_02053000, then clear it (0x0206f4ec..0x0206f4fc). The helper ownership semantics remain unidentified. */
void Unk06ea70_Unk_06f4e4(void)
{
  func_02053000(data_02170ccc.unk_04);
  data_02170ccc.unk_04 = 0;
}

/* Set slot i in the word at buffer-state +0x0c (0x0206f634..0x0206f63c). Negative indices are ignored; other indices must be below 32. */
void Unk06ea70_SetMask0cBit(int i)
{
    if (i < 0) {
        return;
    }
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->mask_0c |= 1u << i;
}

/* Clear slot i in the word at buffer-state +0x0c (0x0206f65c..0x0206f66c). Negative indices are ignored; other indices must be below 32. */
void Unk06ea70_ClearMask0cBit(int i)
{
    if (i < 0) {
        return;
    }
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->mask_0c &= ~(1u << i);
}

/* Borrow a 512-byte slot from buffer-state +0x04: 0x0206f688..0x0206f690 loads that base and shifts i by nine. Negative i returns null; other indices must fit the allocation. */
u8 *Unk06ea70_GetBuf04Slot(int i)
{
    if (i < 0) {
        return 0;
    }
    return ((Unk06ea70Bufs *)data_02170ccc.unk_04)->buf_04 + i * 512;
}

/* Borrow a 512-byte slot from buffer-state +0x00: 0x0206f6ac..0x0206f6b4 loads that base and shifts i by nine. Negative i returns null; other indices must fit the allocation. */
u8 *Unk06ea70_GetBuf00Slot(int i)
{
    if (i < 0) {
        return 0;
    }
    return ((Unk06ea70Bufs *)data_02170ccc.unk_04)->buf_00 + i * 512;
}

/* Set slot i in the word at buffer-state +0x10 (0x0206f6d0..0x0206f6d8). Negative indices are ignored; other indices must be below 32. */
void Unk06ea70_SetMask10Bit(int i)
{
    if (i < 0) {
        return;
    }
    ((Unk06ea70Bufs *)data_02170ccc.unk_04)->mask_10 |= 1u << i;
}
