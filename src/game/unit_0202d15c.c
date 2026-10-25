/*
 * src/game/unit_0202d15c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0213d898[];
/* Borrowed manager storage; layouts are established by the accessors in unit_02095560. */
u8 *Unk095560_GetManagerSub3a8(void);
u8 *Unk095560_GetManager(void);

u32 Unk02d15c_Unk_02d934(void);
u32 Unk02d15c_Unk_02d944(void);
void Unk02d15c_Unk_02d81c(void);
void Unk02d15c_Unk_02d91c(u32 arg0,u32 arg1);

/* Reset the manager pair to (second word 0, first word -1); see 0202d15c. */
void Unk02d15c_Call_02d91c(void)
{
    Unk02d15c_Unk_02d91c(0, -1);
}

int Unk095560_Unk_095d1c(void);
int func_0202d668(int record, int mode0, int mode, int mode1, int sentinel);
int Unk094fe0_Call_020950b4(int index);
void ImageObj_Unk_077894(u32 image, int flags);
void Unk02dcfc_SetField68(void);
void Unk095560_Unk_095cd8(int a, int c, int b, int flags);
void Unk095560_Unk_095d08(int value);
s32 *Unk094fe0_Unk_094fec(int index);
u8 *Unk02d15c_GetManagerRecord(int i);
int Unk02d15c_FindRecordEntry(int a, int key);
/* Eight-word request consumed by the dispatcher at 0202d390; storage is borrowed. */
typedef struct { u32 w[8]; } Unk02d15cRequest;
u8 *func_0202d390(Unk02d15cRequest *request);
int func_0204b01c(u8 *recordData, int key);
u8 *Unk02e000_GetWorkArea(void);
int Unk02f2a8_Unk_035c14(u16 area, s16 key);
/* Test the manager index against -1; 0202d18c resets the pair on that sentinel.
 * Other index meanings are unknown, so retain the original neutral symbol. */
int func_0202d170(void)
{
    int active;
    if (Unk095560_Unk_095d1c() != -1) {
        active = 1;
    } else {
        active = 0;
        Unk02d15c_Call_02d91c();
    }
    return active;
}

/* Switch at 0202d22c maps the record kind loaded by 0202d710 to its output kind. */
int Unk02d15c_MapKind_02d22c(int x)
{
    switch (x) {
    case 0: return 0;
    case 2: return 1;
    case 1: return 2;
    case 3: return 5;
    case 4: return 6;
    case 5: return 7;
    case 7: return 4;
    case 9: break;
    }
    return 0;
}

/* Reverse kind mapping established by the switch constants at 0202d2a0. */
int Unk02d15c_MapKind_02d2a0(int x)
{
    switch (x) {
    case 0: return 0;
    case 1: return 2;
    case 2: return 1;
    case 5: return 3;
    case 6: return 4;
    case 7: return 5;
    case 4: return 7;
    }
    return 0;
}

/* 0202d330 passes mode 0 and compares the dispatcher result with exactly 1. */
int Unk02d15c_IsMode0Match(int a)
{
    return func_0202d668(Unk095560_Unk_095d1c(), a, 0, 0, -1) == 1;
}

/* Accept negative sentinel indices or status 1; comparison at 0202d35c prove the name. */
int Unk02d15c_IsStatus1OrNeg(int a)
{
    if (a < 0) {
        return 1;
    }
    return Unk094fe0_Call_020950b4(a) == 1;
}

/* Accept negative sentinel indices or status 0; comparison at 0202d380 prove the name. */
int Unk02d15c_IsStatus0OrNeg(int a)
{
    if (a < 0) {
        return 1;
    }
    return Unk094fe0_Call_020950b4(a) == 0;
}

/* Build the request seen at 0202d710; on success write the mapped signed kind
 * to caller storage +40 and retain the returned image handle from record +8.
 * Both pointers are borrowed; the caller provides writable storage through +43. */
int func_0202d710(u8 *out, u32 a, u32 b)
{
    Unk02d15cRequest request;
    u8 *record;
    request.w[0] = Unk095560_Unk_095d1c();
    request.w[1] = -1;
    request.w[2] = 0;
    request.w[3] = -1;
    request.w[4] = -1;
    request.w[5] = Unk02d15c_Unk_02d944();
    request.w[6] = a;
    request.w[7] = b;
    record = func_0202d390(&request);
    if (record == 0) {
        return 0;
    }
    FIELD(int, out, 40) = Unk02d15c_MapKind_02d22c(FIELD(s16, record, 6));
    data_0213d898[0] = FIELD(u32, record, 8);
    return 1;
}

/* Dispatch the eight-word request observed at 0202d794; report a non-null result. */
int Unk02d15c_Unk_02d794(u32 a, u32 b)
{
    Unk02d15cRequest s;
    s.w[0] = Unk095560_Unk_095d1c();
    s.w[1] = -1;
    s.w[2] = 1;
    s.w[3] = 13;
    s.w[4] = -1;
    s.w[5] = Unk02d15c_Unk_02d944();
    s.w[6] = a;
    s.w[7] = b;
    return func_0202d390(&s) != 0;
}

/* 0202d808 releases the stored image with flags 0 unless its handle is -1. */
void Unk02d15c_ReleaseImage(void)
{
    if ((s32)data_0213d898[0] == -1) {
        return;
    }
    ImageObj_Unk_077894(data_0213d898[0], 0);
}

/* 0202d854 passes mode 1 and compares the dispatcher result with exactly 1. */
int Unk02d15c_IsMode1Match(int a)
{
    return func_0202d668(Unk095560_Unk_095d1c(), 0, 1, a, -1) == 1;
}

/* 0202d880 calls the setup helpers in order, forwarding (a,c,b,0) then d.
 * The helper sequence supports the existing Setup name; always returns 1. */
int Unk02d15c_Setup(int a, int b, int c, int d)
{
    Unk02dcfc_SetField68();
    Unk095560_Unk_095cd8(a, c, b, 0);
    Unk095560_Unk_095d08(d);
    return 1;
}

/* Return the second manager-pair word (load at 0202d93c); ownership stays with manager. */
u32 Unk02d15c_Unk_02d934(void)
{
    return ((u32 *)Unk095560_GetManagerSub3a8())[1];
}

/* Return the first manager-pair word (load at 0202d94c); its meaning is unknown. */
u32 Unk02d15c_Unk_02d944(void)
{
  u32 *v1;
  v1 = (u32 *)Unk095560_GetManagerSub3a8();
  return *v1;
}

/* Store the -1 sentinel in data_0213d898, as observed at 0202d824. */
void Unk02d15c_Unk_02d81c(void)
{
  *data_0213d898 = 0xffffffff;
}

/* At 0202d8a8, resolve c in record a and set up either its entry or fallback index.
 * Record and entry storage stay borrowed from the manager. */
int Unk02d15c_Unk_02d8a8(int a, int b, int c)
{
    u8 *r = Unk02d15c_GetManagerRecord(a);
    int i, e;
    if (r == 0) {
        return 0;
    }
    i = func_0204b01c(r + 16, c);
    if (i < 0) {
        return 0;
    }
    e = Unk02d15c_FindRecordEntry(a, i);
    if (e < 0) {
        Unk02d15c_Setup(a, b, -1, i);
        return 1;
    }
    return Unk02d15c_Setup(a, b, e, -1);
}

/* Store arg1 then arg0 in the manager pair; store-multiple at 0202d92c establishes order. */
void Unk02d15c_Unk_02d91c(u32 arg0,u32 arg1)
{
  u32 *v1;
  v1 = (u32 *)Unk095560_GetManagerSub3a8();
  *v1 = arg1;
  v1[1] = arg0;
}



/* Test signed condition fields +20/+22/+24 against the work-area key at +0x35c.
 * The loads and comparison at 0202d954 establish this borrowed-record contract. */
int Unk02d15c_Unk_02d954(u8 *p)
{
    u16 v;
    if (FIELD(s16, p, 20) == 0) {
        return 1;
    }
    v = FIELD(u16, Unk02e000_GetWorkArea() + 0x300, 0x5c);
    if (FIELD(s16, p, 20) == 1) {
        s16 k = FIELD(s16, p, 24);
        int r = Unk02f2a8_Unk_035c14(v, FIELD(s16, p, 22));
        if (r == k) {
            return 1;
        }
        return 0;
    }
    return 1;
}

/* 0202d9a8 maps unsigned indices 0..4 to observed constants; others use 26.
 * No caller evidence establishes the meaning of these values. */
u32 Unk02d15c_Unk_02d9a8(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1a;
  case 1:
    return 0x1d;
  case 2:
    return 0x14;
  case 3:
    return 0x17;
  case 4:
    return 0x20;
  default:
    return 0x1a;
  }
}


/* 0202d9f8 maps unsigned indices 0..4 to observed constants; others use 27.
 * Keep the neutral name because the value semantics are unknown. */
u32 Unk02d15c_Unk_02d9f8(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1b;
  case 1:
    return 0x1e;
  case 2:
    return 0x15;
  case 3:
    return 0x18;
  case 4:
    return 0x21;
  default:
    return 0x1b;
  }
}



/* Unsigned switch at 0202da48 maps 0..4 to 28,31,22,25,0; default is 28.
 * Constant meanings are unknown. */
u32 Unk02d15c_Unk_02da48(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x1c;
  case 1:
    return 0x1f;
  case 2:
    return 0x16;
  case 3:
    return 0x19;
  case 4:
    return 0;
  default:
    return 0x1c;
  }
}

/* Borrow record i: 0202dc50 adds manager offset 0xb4 and uses stride 0x54.
 * Caller must supply a valid index; the original performs no bounds check. */
u8 *Unk02d15c_GetManagerRecord(int i)
{
    return (u8 *)Unk095560_GetManager() + 180 + i * 84;
}

/* Stores at 0202dc84..0202dc9c reset five entries and word 6, and copy b
 * to both record headers. Index a must be valid for both borrowed records. */
int Unk02d15c_ResetRecord(int a, s32 b)
{
    u8 *rec = Unk02d15c_GetManagerRecord(a);
    s32 *p = Unk094fe0_Unk_094fec(a);
    int i;
    p[6] = 0;
    p[0] = b;
    FIELD(s32, rec, 0x50) = b;
    for (i = 0; i < 5; i++) {
        p[1 + i] = 0;
    }
    return 1;
}

/* Scan record a's count at +8 and entry pointer at +12, stride 0x30,
 * comparing each first byte (0202dccc); return its index or -1. */
int Unk02d15c_FindRecordEntry(int a, int key)
{
    u8 *rec = Unk02d15c_GetManagerRecord(a);
    u32 i;
    u8 *p;
    u32 n;
    if (rec == 0) {
        return -1;
    }
    p = FIELD(u8 *, rec, 0x0c);
    n = FIELD(u32, rec, 0x08);
    for (i = 0; i < n; i++) {
        if (key == p[0]) {
            return i;
        }
        p += 0x30;
    }
    return -1;
}
