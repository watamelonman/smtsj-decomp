/* src/game/unit_02039774.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk039774Work {
    u8 pad_0000[0xd4];
    s32 unk_00d4;
    s32 unk_00d8;
    s32 unk_00dc;
} Unk039774Work;

/* intrusive list of objects: prev at +0xe0, next at +0xe4. */
typedef struct Unk039774List {
    u8 *head;
    s32 count;
    u8 *tail;
} Unk039774List;
extern Unk039774List data_0215de28;

int func_020399f4();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

void Unk039774_ListAppend(u8 *n)
{
    if (data_0215de28.tail == 0) {
        data_0215de28.head = n;
        data_0215de28.tail = n;
        FIELD(u8 *, n, 224) = 0;
        FIELD(u8 *, n, 228) = 0;
    } else {
        FIELD(u8 *, n, 224) = data_0215de28.tail;
        FIELD(u8 *, data_0215de28.tail, 228) = n;
        FIELD(u8 *, n, 228) = 0;
        data_0215de28.tail = n;
    }
    data_0215de28.count++;
}

void Unk039774_ListRemove(u8 *n)
{
    if (data_0215de28.head == n) {
        data_0215de28.head = FIELD(u8 *, n, 228);
    } else {
        FIELD(u8 *, FIELD(u8 *, n, 224), 228) = FIELD(u8 *, n, 228);
    }
    if (data_0215de28.tail == n) {
        data_0215de28.tail = FIELD(u8 *, n, 224);
    } else {
        FIELD(u8 *, FIELD(u8 *, n, 228), 224) = FIELD(u8 *, n, 224);
    }
    FIELD(u8 *, n, 224) = 0;
    FIELD(u8 *, n, 228) = 0;
    data_0215de28.count--;
}

/* decompiler-derived */
void Unk039774_Unk_039b00(u32 arg0)
{
  func_020399f4(arg0,0);
}

void Unk039774_ListRemove();
int func_02053000();
/* decompiler-derived */
void Unk039774_Unk_039b10(int arg0)
{
  if (((Unk039774Work *)arg0)->unk_00d8 != 0) {
    func_02053000();
    ((Unk039774Work *)arg0)->unk_00d8 = 0;
  }
  if (((Unk039774Work *)arg0)->unk_00dc != 0) {
    func_02053000();
    ((Unk039774Work *)arg0)->unk_00dc = 0;
  }
  if (((Unk039774Work *)arg0)->unk_00d4 != 0) {
    func_02053000();
    ((Unk039774Work *)arg0)->unk_00d4 = 0;
  }
  Unk039774_ListRemove(arg0);
  func_02053000(arg0);
}

void Unk039774_Unk_039b10(int arg0);
void Unk039774_Unk_039b74(u32 key)
{
    u8 *o = data_0215de28.head;
    u8 *next;
    if (o == 0) {
        return;
    }
    do {
        next = FIELD(u8 *, o, 0xe4);
        if (FIELD(u32, o, 0xf4) == key) {
            Unk039774_Unk_039b10((int)o);
        }
        o = next;
    } while (o != 0);
}
