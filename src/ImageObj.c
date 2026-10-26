/*
 * src/ImageObj.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct ImageObjWork {
    u32 unk_0000;
    s32 UnkField0004;
    u8 unk_0008[0x8];
    s32 unk_0010;               /* nonzero while loaded */
    u8 unk_0014[0x8];
    s32 UnkField001c;
    u8 unk_0020[0xc];
    s32 UnkField002c;
    u8 unk_0030[0x4];
    u8 unk_0034[4];             /* sub-object released by Unk0a163c_Unk_0a1ae0 */
} ImageObjWork;

/* Per-slot effect object reached through the singleton table. Field meanings are
 * unknown; the offsets come from the original loads and stores. */
typedef struct ImageObjNode {
    u8 pad_00[0x30];
    s32 unk_30;
    u8 pad_34[4];
    s8 unk_38;
    u8 pad_39[0x17];
    u32 unk_50;
    u8 pad_54[0xc];
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6c;
    u32 unk_70;
} ImageObjNode;


extern u32 data_0217231c[];
void ImageObj_Unk_0775a0(void);
void ImageObj_Unk_077620(void);
void ImageObj_Unk_077640(void);
void ImageObj_Release(ImageObjWork *work);
int func_02079238(u32 slot, s32 value);

u32 ImageObj_Get_data_0217231c(void);
void ImageObj_Unk_0775d8(void);
void ImageObj_Unk_07784c(u32 arg0);
void ImageObj_Unk_077880(int arg0);
void ImageObj_Unk_0778d4(int arg0);
u32 ImageObj_Unk_0778e8(int arg0);
void ImageObj_Unk_07916c(ImageObjWork *work);
void ImageObj_Unk_0772f8(ImageObjWork *work);

/* Returns the singleton word: 02077218 loads through data_0217231c. */
u32 ImageObj_Get_data_0217231c(void)
{
  return *data_0217231c;
}

/* Runs the three maintenance helpers in the order of BLs at 020775dc..020775e4. */
void ImageObj_Unk_0775d8(void)
{
  ImageObj_Unk_077620();
  ImageObj_Unk_0775a0();
  ImageObj_Unk_077640();
}

/* Forwards value to slot 0; MOV operands at 02077850..02077854 are the evidence. */
void ImageObj_Unk_07784c(u32 arg0)
{
  func_02079238(0,arg0);
}

/* Forwards value + 1 to slot 1, as encoded at 02077884..02077888. */
void ImageObj_Unk_077880(int arg0)
{
  func_02079238(1,arg0 + 1);
}

/* Forwards value + 3 to slot 2, as encoded at 020778d8..020778dc. */
void ImageObj_Unk_0778d4(int arg0)
{
  func_02079238(2,arg0 + 3);
}

/* Reads the indexed word at singleton + 4; caller supplies a valid live table index.
 * Evidence: shifted ADD and LDR at 020778f4..020778f8. */
u32 ImageObj_Unk_0778e8(int arg0)
{
  int value;
  value = ImageObj_Get_data_0217231c();
  return *(u32 *)(value + arg0 * 4 + 4);
}

/* In state 1, sets field 1c to 256 minus field 2c (0207916c..0207917c).
 * The work pointer must be valid; field semantics remain unknown. */
void ImageObj_Unk_07916c(ImageObjWork *work)
{
  if (work->UnkField0004 == 1) {
    work->UnkField001c = 0x100 - work->UnkField002c;
  }
}

/* Forwards the live work pointer to Release, then clears the singleton.
 * Evidence: BL at 020772fc preserves incoming r0; STR at 02077308 clears the word. */
void ImageObj_Unk_0772f8(ImageObjWork *work)
{
  ImageObj_Release(work);
  *data_0217231c = 0;
}



/* Tests singleton word +0x14 against 4 (LDR/CMP at 02079030..02079034).
 * Requires a live singleton; the state meaning is not established. */
int ImageObj_Unk_079028(void)
{
  int value;
  value = ImageObj_Get_data_0217231c();
  return *(int *)(value + 0x14) == 4;
}


/* If the singleton exists, sets words +0xc0 and +0xc4 to one.
 * Evidence: conditional stores at 020773cc..020773d0; flag meanings are unknown. */
void ImageObj_Unk_0773bc(void)
{
  int value;
  value = *data_0217231c;
  if (value != 0) {
    *(u32 *)(value + 0xc0) = 1;
    *(u32 *)(value + 0xc4) = 1;
  }
}

void ImageObj_Unk_0791a8(u32 arg0,int arg1,u32 arg2,u32 arg3);
/* Forwards the two supplied words to 0791a8 with slot and final flag zero.
 * Evidence: register moves at 02077830..02077840. */
void ImageObj_Unk_07782c(u32 arg0,u32 arg1)
{
  ImageObj_Unk_0791a8(0,arg0,arg1,0);
}


/* Forwards to slot one with the second value incremented and final flag zero.
 * Evidence: ADD/MOV operands at 0207786c..02077874. */
void ImageObj_Unk_077860(u32 arg0,int arg1)
{
  ImageObj_Unk_0791a8(1,arg0,arg1 + 1,0);
}


/* Forwards to slot two with the second value plus three and final flag zero.
 * Evidence: ADD/MOV operands at 020778a0..020778a8. */
void ImageObj_Unk_077894(u32 arg0,int arg1)
{
  ImageObj_Unk_0791a8(2,arg0,arg1 + 3,0);
}


/* Forwards to slot two with the second value plus three and final flag one.
 * Evidence: ADD/MOV operands at 020778c0..020778c8. */
void ImageObj_Unk_0778b4(u32 arg0,int arg1)
{
  ImageObj_Unk_0791a8(2,arg0,arg1 + 3,1);
}

int func_02061424(u32 handle);
/* Passes a nonzero indexed singleton word to func_02061424.
 * Evidence: LDR into r0 at 02079194 and BL at 020791a0.
 * Requires a live singleton and valid index; the original checks only the word. */
void ImageObj_Unk_079184(int arg0)
{
  u32 *table = (u32 *)ImageObj_Get_data_0217231c();
  u32 handle = *(table + arg0 + 1);
  if (handle == 0) {
    return;
  }
  func_02061424(handle);
}


void ImageObj_Unk_077554(int slot);
/* If the singleton exists, visits slots zero through two in order.
 * Evidence: accessor BL at 020775f0 and loop bound CMP at 02077614. */
void ImageObj_Unk_0775ec(void)
{
  int value1;
  int value2;
  value1 = ImageObj_Get_data_0217231c();
  if (value1 == 0) {
    return;
  }
  value2 = 0;
  do {
    if (value1 != 0) {
      ImageObj_Unk_077554(value2);
    }
    value2 = value2 + 1;
  } while (value2 < 3);
}

int func_02077a9c(ImageObjNode *node);
/* Returns one if any of the three slots is in node state 9 or 10.
 * Evidence: BLs at 020776e0 and 020776e4, loop bound CMP at 020776f8. */
u32 ImageObj_Unk_0776d4(void)
{
  int value1;
  int value2;
  value2 = 0;
  do {
    value1 = func_02077a9c((ImageObjNode *)ImageObj_Unk_0778e8(value2));
    if (value1 != 0) {
      return 1;
    }
    value2 = value2 + 1;
  } while (value2 < 3);
  return 0;
}



/* Returns zero when a live slot is in state 9 or 10; otherwise tears down each
 * live slot and returns one. Evidence: BLs at 02077234, 02077240 and 02077254;
 * loop bound CMP at 0207725c. Requires the slot table to stay valid. */
u32 ImageObj_Unk_077228(void)
{
  int value1;
  int value2;
  value2 = 0;
  do {
    value1 = ImageObj_Unk_0778e8(value2);
    if (value1 != 0) {
      value1 = func_02077a9c((ImageObjNode *)value1);
      if (value1 != 0) {
        return 0;
      }
      ImageObj_Unk_077554(value2);
    }
    value2 = value2 + 1;
  } while (value2 < 3);
  return 1;
}


typedef struct Unk077Tbl {
    u32 unk_0000;
    u32 e[48];                  /* +0x04 */
    u32 unk_00c4;
} Unk077Tbl;

u32 func_02077900();
int func_02077a9c(ImageObjNode *node);
void func_02077e74(ImageObjNode *node);
void ImageObj_Unk_079184(int arg0);
/* Returns the handle cached in slot `index`, creating and caching it through
 * func_02077900 when the slot is empty. Evidence: indexed LDR at 02077488,
 * BL at 020774a4 and indexed STR at 020774ac. Requires a live slot table and
 * an index in 0..47 (the table has 48 handle words starting at +4). */
int ImageObj_GetOrCreate(int index, int arg)
{
    Unk077Tbl *t = (Unk077Tbl *)ImageObj_Get_data_0217231c();
    if (t->e[index] != 0) {
        return t->e[index];
    }
    return t->e[index] = func_02077900(index, arg);
}

/* Tears down one slot when both the singleton and the slot handle exist: a
 * handle in state 9 or 10 only marks flag +0xc4, otherwise the node is torn
 * down and the slot is cleared through 079184. Evidence: BLs at 02077574,
 * 02077590 and 02077598; flag store at 02077584. */
void ImageObj_Unk_077554(int slot)
{
    Unk077Tbl *t = (Unk077Tbl *)ImageObj_Get_data_0217231c();
    u32 o;
    if (t == 0 || (o = t->e[slot]) == 0) {
        return;
    }
    if (func_02077a9c((ImageObjNode *)o) != 0) {
        t->unk_00c4 = 1;
        return;
    }
    func_02077e74((ImageObjNode *)o);
    ImageObj_Unk_079184(slot);
}

/* Returns one when the singleton is absent, when every slot handle is zero,
 * and when the work word at +0x10 is zero; any live slot or a nonzero +0x10
 * yields zero. Evidence: loop BL at 020776a4 and LDR/CMP at 020776c0. */
int ImageObj_Unk_077688(void)
{
  int value1;
  int value2;
  int value3;
  value1 = ImageObj_Get_data_0217231c();
  if (value1 == 0) {
    return 1;
  }
  value3 = 0;
  do {
    value2 = ImageObj_Unk_0778e8(value3);
    if (value2 != 0) {
      return 0;
    }
    value3 = value3 + 1;
  } while (value3 < 3);
  return *(int *)(value1 + 0x10) == 0;
}



/* Initializes the observed node defaults, including pair (400,400), mode 2,
 * flag +0x48 = 1 and sentinel +0x54 = -1. Stores at 020779a0..020779f0
 * establish the layout; the caller owns writable storage of at least 0x70 bytes. */
void ImageObj_Unk_0779a0(u32 *arg0,u32 arg1)
{
  arg0[3] = 0;
  *arg0 = arg1;
  arg0[5] = 400;
  arg0[6] = 400;
  arg0[7] = 0;
  arg0[8] = 0;
  arg0[9] = 0;
  arg0[10] = 0;
  arg0[0xb] = 0;
  arg0[0xd] = 2;
  *(u8 *)(arg0 + 0xe) = 0;
  arg0[0x12] = 1;
  arg0[0x13] = 0;
  arg0[0x1b] = 0;
  arg0[0x15] = 0xffffffff;
}

/* Visits slots zero through two in order via 077554.
 * Evidence: loop at 02077628..02077638; no singleton check is made here. */
void ImageObj_Unk_077620(void)
{
  int tmp1;
  tmp1 = 0;
  do {
    ImageObj_Unk_077554(tmp1);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 3);
}

/* When the singleton exists, releases the whole work object unless some slot
 * is in state 9 or 10; in that case only flag +0xc8 is set. Evidence: singleton
 * LDR at 020775a8, BL 0776d4 at 020775b4, flag store at 020775c0 and Release
 * BL at 020775cc. */
void ImageObj_Unk_0775a0(void)
{
  int tmp1;
  int tmp2;
  tmp2 = *data_0217231c;
  if (tmp2 == 0) {
    return;
  }
  tmp1 = ImageObj_Unk_0776d4();
  if (tmp1 == 0) {
    ImageObj_Release((ImageObjWork *)tmp2);
    return;
  }
  *(u32 *)(tmp2 + 200) = 1;
}

int func_0205bb68();
int func_0205ddb4();
/* When the singleton exists and its state word at +0x14 is four, releases the
 * +0x18 handle and clears it, calls the two shared flush helpers, then clears
 * +0x14. Evidence: BL 079028 at 02077650, load at 0207765c, stores at
 * 02077668 and 02077680. */
void ImageObj_Unk_077640(void)
{
  int tmp1;
  int tmp2;
  tmp1 = ImageObj_Get_data_0217231c();
  if (tmp1 == 0) {
    return;
  }
  tmp2 = ImageObj_Unk_079028();
  if (tmp2 == 0) {
    return;
  }
  if (*(int *)(tmp1 + 0x18) != 0) {
    func_0205ddb4();
    *(u32 *)(tmp1 + 0x18) = 0;
  }
  func_0205bb68();
  func_0205bb68();
  *(u32 *)(tmp1 + 0x14) = 0;
}

int ImageObj_GetOrCreate(int index, int arg);
int func_020774b4();
int func_02079268();
/* Returns one when the singleton is absent, or when every slot handle is zero
 * or has a zero word at +4; the first live handle stops the scan with zero.
 * Evidence: loop BL at 02077724 and conditional LDR at 02077728..02077730. */
int ImageObj_Unk_077708(void)
{
    int i;
    if (ImageObj_Get_data_0217231c() == 0) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        u32 *p = (u32 *)ImageObj_Unk_0778e8(i);
        if (p != 0 && p[1] != 0) {
            return 0;
        }
    }
    return 1;
}

extern u8 data_02145a54[];
extern u8 data_02145a70[];
extern u8 data_02145a88[];
void func_02013c3c();
int func_02095818();
void Unk065e88_SetPair04();
void ImageObj_ReleaseField68(ImageObjNode *node);
void ImageObj_Unk_077ea4();
void func_020a1a24();
/* Returns one if any of three live slots has a zero word at +0x48.
 * Evidence: indexed load and conditional comparison at 020777fc..02077808. */
int ImageObj_Unk_0777e0(void)
{
    Unk077Tbl *t = (Unk077Tbl *)ImageObj_Get_data_0217231c();
    int i;
    if (t == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        u8 *e = (u8 *)t->e[i];
        if (e != 0 && FIELD(u32, e, 0x48) == 0) {
            return 1;
        }
    }
    return 0;
}

void Unk065e88_SetUnkField28();
int Unk0a163c_Unk_0a1798();
void Unk0a163c_Call_020a1b08();
void func_020a1b68();
void Unk0a163c_Unk_0a21f8();

/* Maps signed byte +0x38 below 31 to three high color bytes (value*255/31),
 * otherwise uses all ones, then updates a live +0x68 handle. Evidence:
 * signed byte load, division and shifts at 02077a0c..02077a3c. Null is allowed. */
void ImageObj_Unk_0779f4(ImageObjNode *n)
{
    s32 v;
    u32 c;
    if (n == 0 || n->unk_68 == 0) {
        return;
    }
    v = n->unk_38;
    c = -1;
    if (v < 31) {
        v = v * 255 / 31;
        c = (v << 24) | (v << 16) | (v << 8);
    }
    Unk065e88_SetUnkField28(n->unk_68, c);
}

/* Copies one of three static descriptors into caller-owned storage for kinds
 * 0..2; other kinds do nothing. Evidence: branches and data relocations at
 * 02077a4c..02077a98. The last two parameters are unused (caller 02077f30). */
void ImageObj_Unk_077a4c(void *o, int kind, const void *arg2, const void *arg3)
{
    switch (kind) {
    case 0:
        func_02013c3c(o, data_02145a54);
        break;
    case 1:
        func_02013c3c(o, data_02145a70);
        break;
    case 2:
        func_02013c3c(o, data_02145a88);
        break;
    }
}

/* Dispatches node +0x50 as a 16-bit ID through the singleton sub-object,
 * selecting the translated-ID path when +0x70 is set; refreshes it and marks
 * +0x6c. Evidence: BLs at 02077c58..02077c8c. Requires a live singleton. */
void ImageObj_Unk_077c30(ImageObjNode *n)
{
    ImageObjWork *w = (ImageObjWork *)ImageObj_Get_data_0217231c();
    if (n == 0) {
        return;
    }
    if (n->unk_70 != 0) {
        Unk0a163c_Call_020a1b08(w->unk_0034, Unk0a163c_Unk_0a1798((u16)n->unk_50), w->unk_0010);
    } else {
        func_020a1b68(w->unk_0034, (u16)n->unk_50, w->unk_0010);
    }
    Unk0a163c_Unk_0a21f8(w->unk_0034);
    n->unk_6c = 1;
}

/* Reports whether a live object is type 2 and its +0x50 word is below 600.
 * Evidence: LDR/CMP at 02077d78 and LDR/CMP at 02077d84..02077d88. */
int ImageObj_Unk_077d68(s32 *o)
{
    if (o == 0) {
        return 0;
    }
    if (o[0] != 2) {
        return 0;
    }
    return FIELD(s32, o, 0x50) < 600;
}

/* Maps the current system state to a display parameter (8 for states 0 and 2,
 * zero otherwise) and forwards it together with the node's +0x68 handle to
 * Unk065e88_SetPair04. Evidence: BL at 02077da0, case MOVs at 02077db8 and
 * 02077dc0, and the final BL at 02077dd4. */
void ImageObj_Unk_077d98(ImageObjNode *node)
{
    int value;
    switch (func_02095818()) {
    case 0:
        value = 8;
        break;
    case 2:
        value = 8;
        break;
    default:
        value = 0;
        break;
    }
    Unk065e88_SetPair04(node->unk_68, 0, value);
}

/* decompiler-derived */
void ImageObj_Unk_0791a8(u32 arg0,int arg1,u32 arg2,u32 arg3)
{
  int tmp1;
  int tmp2;
  tmp1 = ImageObj_Unk_0778e8(arg0);
  if (tmp1 == 0) {
    tmp1 = ImageObj_GetOrCreate(arg0,arg1);
    func_02079268(tmp1,arg2);
  }
  else {
    if (((*(int *)(tmp1 + 0x48) == 1) || (*(int *)(tmp1 + 0x50) != arg1)) &&
       (tmp2 = func_02077a9c((ImageObjNode *)tmp1), tmp2 == 0)) {
      func_020774b4(tmp1,arg1);
    }
    if (*(int *)(tmp1 + 0x48) != 0) {
      func_02079268(tmp1,arg2);
    }
  }
  *(u32 *)(tmp1 + 0x70) = arg3;
}

/* Clears the singleton table slot named by *arg0 when the singleton exists.
 * Evidence: LDR of the singleton at 02079004, indexed store at 0207901c. */
void ImageObj_Unk_079000(int *arg0)
{
  if (*data_0217231c == 0) {
    return;
  }
  *(u32 *)(*data_0217231c + *arg0 * 4 + 4) = 0;
}

void Unk0a163c_Unk_0a1ae0(void *p);

/* Releases the object if loaded and clears its state.
 * Evidence: LDR/CMP at 02077de4..02077de8, teardown BL at 02077df0. */
void ImageObj_Release(ImageObjWork *work)
{
    if (work->unk_0010 == 0) {
        return;
    }
    Unk0a163c_Unk_0a1ae0(work->unk_0034);
    func_0205bb68();
    work->unk_0010 = 0;
    work->unk_0000 = 0;
}

void func_0205c368();

/* For a live +0x68 handle, releases and clears handles +0x68, +0x60 and
 * +0x64 in that order, skipping absent handles. Evidence: guarded BL/store
 * pairs at 02077ebc..02077ef4. Requires a valid node. */
void ImageObj_Unk_077ea4(ImageObjNode *n)
{
    if (n->unk_68 == 0) {
        return;
    }
    if (n->unk_68 != 0) {
        func_02061424(n->unk_68);
        n->unk_68 = 0;
    }
    if (n->unk_60 != 0) {
        func_0205ddb4(n->unk_60);
        n->unk_60 = 0;
    }
    if (n->unk_64 != 0) {
        func_0205c368(n->unk_64);
        n->unk_64 = 0;
    }
}

/* Releases the node's field 68 handle and refreshes the singleton sub-object.
 * Evidence: LDR at 02077f0c, BL to 02061424 at 02077f18 and BL at 02077f28. */
void ImageObj_ReleaseField68(ImageObjNode *node)
{
    u8 *t = (u8 *)ImageObj_Get_data_0217231c();
    if (node->unk_68 == 0) {
        return;
    }
    func_02061424(node->unk_68);
    node->unk_68 = 0;
    func_020a1a24(t + 52);
}

/* Reports whether a live node is in state 9 or 10; null is not live.
 * Evidence: null test at 02077a9c, LDR/CMP/CMPNE at 02077aa8..02077ab0. */
int func_02077a9c(ImageObjNode *node)
{
    if (node == 0) {
        return 0;
    }
    switch (FIELD(s32, node, 4)) {
    case 9:
    case 10:
        return 1;
    default:
        return 0;
    }
}

/* Releases the field-68 handle when present, otherwise the node's effect
 * resources; both branches clear the node's released state on the handle path.
 * Evidence: LDR at 02077e80, branch at 02077e88, store at 02077e94. */
void func_02077e74(ImageObjNode *node)
{
    if (node == 0) {
        return;
    }
    if (node->unk_6c != 0) {
        ImageObj_ReleaseField68(node);
        node->unk_6c = 0;
        return;
    }
    ImageObj_Unk_077ea4(node);
}

/* Offsets the handle's pair by (128, 151 - node[0x30]) plus caller offsets.
 * Evidence: predicate BL at 02077e1c and arithmetic at 02077e58..02077e6c.
 * Requires a valid node; only type 2 nodes with +0x50 below 600 are updated. */
void func_02077e0c(ImageObjNode *node, int x, int y)
{
    int baseX;
    int baseY;
    if (ImageObj_Unk_077d68((s32 *)node) == 0) {
        return;
    }
    baseX = 128;
    switch (func_02095818()) {
    case 0:
        baseX = 128;
        baseY = 151;
        break;
    case 2:
        baseX = 128;
        baseY = 151;
        break;
    default:
        baseY = 151;
        break;
    }
    baseY -= node->unk_30;
    baseX += x;
    baseY += y;
    Unk065e88_SetPair04(node->unk_68, baseX, baseY);
}

extern u8 data_02145ab4[];
extern u8 data_02145ab8[];
void func_0205ad2c(void *descriptor);
/* Builds a zeroed 64-byte descriptor, applies the kind-specific data and
 * submits it. Evidence: byte-clear loop at 02077f48..02077f60 and BLs at
 * 02077f70/02077f78. The two data pointers are unused by 077a4c. */
void func_02077f30(int kind)
{
    u8 descriptor[64] = {0};
    ImageObj_Unk_077a4c(descriptor, kind, data_02145ab4, data_02145ab8);
    func_0205ad2c(descriptor);
}
