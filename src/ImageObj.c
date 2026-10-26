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



/* decompiler-derived */
int ImageObj_Unk_079028(void)
{
  int value;
  value = ImageObj_Get_data_0217231c();
  return *(int *)(value + 0x14) == 4;
}


/* decompiler-derived */
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
/* decompiler-derived */
void ImageObj_Unk_07782c(u32 arg0,u32 arg1)
{
  ImageObj_Unk_0791a8(0,arg0,arg1,0);
}


/* decompiler-derived */
void ImageObj_Unk_077860(u32 arg0,int arg1)
{
  ImageObj_Unk_0791a8(1,arg0,arg1 + 1,0);
}


/* decompiler-derived */
void ImageObj_Unk_077894(u32 arg0,int arg1)
{
  ImageObj_Unk_0791a8(2,arg0,arg1 + 3,0);
}


/* decompiler-derived */
void ImageObj_Unk_0778b4(u32 arg0,int arg1)
{
  ImageObj_Unk_0791a8(2,arg0,arg1 + 3,1);
}

int func_02061424();
/* decompiler-derived */
void ImageObj_Unk_079184(int arg0)
{
  int value;
  value = ImageObj_Get_data_0217231c();
  if (*(int *)(value + arg0 * 4 + 4) == 0) {
    return;
  }
  func_02061424();
}


void ImageObj_Unk_077554();
/* decompiler-derived */
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

int func_02077a9c();
/* decompiler-derived */
u32 ImageObj_Unk_0776d4(void)
{
  int value1;
  int value2;
  value2 = 0;
  do {
    ImageObj_Unk_0778e8(value2);
    value1 = func_02077a9c();
    if (value1 != 0) {
      return 1;
    }
    value2 = value2 + 1;
  } while (value2 < 3);
  return 0;
}



/* decompiler-derived */
u32 ImageObj_Unk_077228(void)
{
  int value1;
  int value2;
  value2 = 0;
  do {
    value1 = ImageObj_Unk_0778e8(value2);
    if (value1 != 0) {
      value1 = func_02077a9c();
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
int func_02077a9c();
void func_02077e74();
void ImageObj_Unk_079184(int arg0);
int ImageObj_GetOrCreate(int i, int b)
{
    Unk077Tbl *t = (Unk077Tbl *)ImageObj_Get_data_0217231c();
    if (t->e[i] != 0) {
        return t->e[i];
    }
    return t->e[i] = func_02077900(i, b);
}

void ImageObj_Unk_077554(int i)
{
    Unk077Tbl *t = (Unk077Tbl *)ImageObj_Get_data_0217231c();
    u32 o;
    if (t == 0 || (o = t->e[i]) == 0) {
        return;
    }
    if (func_02077a9c(o) != 0) {
        t->unk_00c4 = 1;
        return;
    }
    func_02077e74(o);
    ImageObj_Unk_079184(i);
}

/* decompiler-derived */
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



/* decompiler-derived */
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

/* decompiler-derived */
void ImageObj_Unk_077620(void)
{
  int tmp1;
  tmp1 = 0;
  do {
    ImageObj_Unk_077554(tmp1);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 3);
}

/* decompiler-derived */
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
/* decompiler-derived */
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

int ImageObj_GetOrCreate();
int func_020774b4();
int func_02079268();
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
void ImageObj_ReleaseField68(u32 o);
void ImageObj_Unk_077ea4();
void func_020a1a24();
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
void Unk065e88_SetUnkField28();
int Unk0a163c_Unk_0a1798();
void Unk0a163c_Call_020a1b08();
void func_020a1b68();
void Unk0a163c_Unk_0a21f8();

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

void ImageObj_Unk_077a4c(void *o, int kind)
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

void ImageObj_Unk_077d98(u8 *o)
{
    int v;
    switch (func_02095818()) {
    case 0:
        v = 8;
        break;
    case 2:
        v = 8;
        break;
    default:
        v = 0;
        break;
    }
    Unk065e88_SetPair04(FIELD(u32, o, 0x68), 0, v);
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
       (tmp2 = func_02077a9c(tmp1), tmp2 == 0)) {
      func_020774b4(tmp1,arg1);
    }
    if (*(int *)(tmp1 + 0x48) != 0) {
      func_02079268(tmp1,arg2);
    }
  }
  *(u32 *)(tmp1 + 0x70) = arg3;
}

/* decompiler-derived */
void ImageObj_Unk_079000(int *arg0)
{
  if (*data_0217231c == 0) {
    return;
  }
  *(u32 *)(*data_0217231c + *arg0 * 4 + 4) = 0;
}

void Unk0a163c_Unk_0a1ae0(void *p);

/* Releases the object if loaded and clears its state. */
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

void ImageObj_ReleaseField68(u32 o)
{
    u8 *t = (u8 *)ImageObj_Get_data_0217231c();
    if (FIELD(u32, o, 0x68) == 0) {
        return;
    }
    func_02061424(FIELD(u32, o, 0x68));
    FIELD(u32, o, 0x68) = 0;
    func_020a1a24(t + 52);
}
