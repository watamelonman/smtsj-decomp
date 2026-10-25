/*
 * ImageBgDual3D.c (name from the assert string at 0x02125c68):
 * a dual-screen 3D image background used by the ending/event scenes
 * (neighbouring code loads "Data/Tex/Event/ED/").
 * These are its empty callbacks and two thin forwarders.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct ImageBgDual3DWork {
    u32 unk_0000;
    s32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x7c];
    u32 unk_008c;
    u8 pad_0090[0x5d];
    u8 unk_00ed;
    u8 pad_00ee[0x11a];
    u32 unk_0208;
} ImageBgDual3DWork;

void func_021255b4(ImageBgDual3DWork *work);
void Unk116598_Set(u32 a, u32 b);

/* At 0x021252f4, BX LR returns without reading arguments or changing state. */
void ImageBgDual3D_Nop_1252f4(void) { }
/* At 0x021252f8, BX LR returns without reading arguments or changing state. */
void ImageBgDual3D_Nop_1252f8(void) { }
/* At 0x021252fc, BX LR returns without reading arguments or changing state. */
void ImageBgDual3D_Nop_1252fc(void) { }
void func_02117360(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_02117400(u32 a, u32 b, u32 c, u32 d, u8 e);
/* At 0x02125984, forwards four words and the fifth argument as an unsigned
 * byte (LDRB / STR) to func_02117360; no result is consumed. */
void ImageBgDual3D_Call_02117360(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117360(a, b, c, d, e);
}

/* At 0x02125998, forwards four words and the fifth argument as an unsigned
 * byte (LDRB / STR) to func_02117400; no result is consumed. */
void ImageBgDual3D_Call_02117400(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_02117400(a, b, c, d, e);
}

/* At 0x02125c3c, BX LR returns without reading arguments or changing state. */
void ImageBgDual3D_Nop_125c3c(void) { }
/* At 0x02125c60, BX LR returns without reading arguments or changing state. */
void ImageBgDual3D_Nop_125c60(void) { }
/* At 0x02125c64, BX LR returns without reading arguments or changing state. */
void ImageBgDual3D_Nop_125c64(void) { }

/* At 0x021257e8, LDR IP / BX IP forwards to func_021255b4.
 * The caller at 0x02125934 forwards the borrowed work in R0. */
void ImageBgDual3D_Thunk_021255b4(ImageBgDual3DWork *work) { func_021255b4(work); }

/* At 0x021259ac, LDR IP / BX IP forwards two opaque words unchanged
 * to Unk116598_Set (0x021177e0); the target returns no value. */
void ImageBgDual3D_Thunk_021177e0(u32 a, u32 b) { Unk116598_Set(a, b); }

void Unk116598_Reset(void);
/* At 0x021259b8, LDR IP / BX IP forwards without arguments to
 * Unk116598_Reset (0x02117808); the target has no return value. */
void ImageBgDual3D_Thunk_02117808(void) { Unk116598_Reset(); }

extern u32 data_02176e94[];
/* At 0x021259f8, loads the word at data_02176e94 unchanged. Callers
 * (including 0x021259e0) treat it as a borrowed work address; no null check. */
u32 ImageBgDual3D_Get_data_02176e94(void)
{
  return *data_02176e94;
}

void Unk065e88_Unk_065eac(void);
void Unk095560_Unk_096130(void);
/* At 0x02125a80, calls 0x02096130 then 0x02065eac, without arguments.
 * Their wider purpose is not established here, so retain the neutral name. */
void ImageBgDual3D_Unk_125a80(void)
{
  Unk095560_Unk_096130();
  Unk065e88_Unk_065eac();
}

extern u32 data_02176e8c[];
/* At 0x02125300, stores a zero word at data_02176e8c. The name describes
 * only this observed store, without assigning a meaning to the global. */
void ImageBgDual3D_Clear_data_02176e8c(void)
{
  *data_02176e8c = 0;
}

void Unk116598_Unk_1172dc(void);
void Unk116598_Unk_1177cc(u32 arg0);
/* At 0x02125afc, calls 0x021177cc with zero, then 0x021172dc.
 * The work argument supplied by 0x02125a90 is borrowed and never accessed. */
void ImageBgDual3D_Unk_125afc(ImageBgDual3DWork *work)
{
  Unk116598_Unk_1177cc(0);
  Unk116598_Unk_1172dc();
}

/* At 0x021259e0, obtains the non-null borrowed work address, writes one
 * to its first word, then calls 0x02125a80; the state meaning is unknown. */
void ImageBgDual3D_Unk_1259e0(void)
{
  ImageBgDual3DWork *work;
  work = (ImageBgDual3DWork *)ImageBgDual3D_Get_data_02176e94();
  work->unk_0000 = 1;
  ImageBgDual3D_Unk_125a80();
}

void Unk065e88_Unk_065e88(void);
void func_020773dc(u32 arg0);
void ImageBgDual3D_AllocBuf(void);
/* At 0x02125a68, allocates the shared buffer, calls 0x02065e88, then
 * calls 0x020773dc with one. No results are consumed. */
void ImageBgDual3D_Unk_125a68(void)
{
  ImageBgDual3D_AllocBuf();
  Unk065e88_Unk_065e88();
  func_020773dc(1);
}

u32 ImageBgDual3D_Unk_12594c(void);
/* At 0x02125ca4, returns one exactly when 0x0212594c returns zero;
 * all other values produce zero. */
int ImageBgDual3D_Unk_125ca4(void)
{
  int value;
  value = ImageBgDual3D_Unk_12594c();
  return value == 0;
}

/* At 0x02125cbc, returns one exactly when 0x0212594c returns one;
 * all other values produce zero. */
int ImageBgDual3D_Unk_125cbc(void)
{
  int value;
  value = ImageBgDual3D_Unk_12594c();
  return value == 1;
}

void ImageBgDual3D_Unk_1258e8(void);
/* At 0x02125d30, calls 0x021258e8 only when the predicate at
 * 0x02125cbc is nonzero; no arguments or results are forwarded. */
void ImageBgDual3D_Unk_125d30(void)
{
  int value;
  value = ImageBgDual3D_Unk_125cbc();
  if (value == 0) {
    return;
  }
  ImageBgDual3D_Unk_1258e8();
}

/* At 0x021259c4, stores the opaque argument at work offset 4 and one
 * at offset 0xc. The global getter supplies a non-null borrowed work address. */
void ImageBgDual3D_Unk_1259c4(u32 arg0)
{
  ImageBgDual3DWork *work;
  work = (ImageBgDual3DWork *)ImageBgDual3D_Get_data_02176e94();
  work->unk_0004 = arg0;
  work->unk_000c = 1;
}

void Unk116598_Unk_117294(void);
void Unk116598_Unk_117790(void);
u32 func_02125a08(void);
/* At 0x02125c40, calls 0x02117790 then 0x02117294, and publishes the
 * word returned by 0x02125a08 in data_02176e94; its ownership is unspecified. */
void ImageBgDual3D_Unk_125c40(void)
{
  u32 value;
  Unk116598_Unk_117790();
  Unk116598_Unk_117294();
  value = func_02125a08();
  *data_02176e94 = value;
}

void ImageBgDual3D_Unk_1258a0(u32 arg0);
/* At 0x02125d10, forwards the opaque word to 0x021258a0 only when
 * the predicate at 0x02125cbc is nonzero. */
void ImageBgDual3D_Unk_125d10(u32 arg0)
{
  int value;
  value = ImageBgDual3D_Unk_125cbc();
  if (value == 0) {
    return;
  }
  ImageBgDual3D_Unk_1258a0(arg0);
}

void func_0205c408(u32 handle, u32 arg1);
void func_0205c6e0(u32 handle);
/* At 0x02125650, passes the word at offset 0x8c to 0x0205c408
 * with zero, then to 0x0205c6e0, and clears offset 0x208. Work is borrowed
 * and non-null; neither helper result is consumed. */
void ImageBgDual3D_Unk_125650(ImageBgDual3DWork *work)
{
  func_0205c408(work->unk_008c,0);
  func_0205c6e0(work->unk_008c);
  work->unk_0208 = 0;
}

/* At 0x02125618, checks count (signed, offset 0x204) records at stride
 * 0x5c for nonzero bytes at offset 0xed. Borrowed work must cover all records;
 * a nonpositive count succeeds without accessing any record. */
u32 ImageBgDual3D_Unk_125618(ImageBgDual3DWork *work)
{
  s32 *count = (s32 *)((u8 *)work + 0x204);
  s32 index = 0;
  if (0 < *count) {
    do {
      if (work->unk_00ed == 0) {
        return 0;
      }
      index++;
      work = (ImageBgDual3DWork *)((u8 *)work + 0x5c);
    } while (index < *count);
  }
  return 1;
}

extern u32 data_02176e98[];
void func_021257f4(u32 buffer, u32 value, u32 mode);
void ImageBgDual3D_Unk_125910(u32 value);
/* At 0x02125cd4, forwards the opaque word to 0x02125910 when the
 * predicate is true; otherwise calls 0x021257f4 with the shared buffer and 1. */
void ImageBgDual3D_Unk_125cd4(u32 arg0)
{
  int tmp1;
  tmp1 = ImageBgDual3D_Unk_125cbc();
  if (tmp1 != 0) {
    ImageBgDual3D_Unk_125910(arg0);
    return;
  }
  func_021257f4(*data_02176e98,arg0,1);
  return;
}

int func_0205bb68(u32 buffer);
/* At 0x02125d48, conditionally calls 0x021258e8, then releases the nonzero
 * shared buffer through 0x0205bb68 and clears its global word. */
void ImageBgDual3D_Unk_125d48(void)
{
  int tmp1;
  tmp1 = ImageBgDual3D_Unk_125cbc();
  if (tmp1 != 0) {
    ImageBgDual3D_Unk_1258e8();
  }
  if (*data_02176e98 == 0) {
    return;
  }
  func_0205bb68(*data_02176e98);
  *data_02176e98 = 0;
  return;
}

int Unk0bc1a8_IsSlotEmpty(u32 slot);
void Unk0bc1a8_Unk_0bc504(u32 *work, u32 value);
/* At 0x021252b4, calls 0x020bc504(work, 0) only when borrowed work
 * word 2 is nonzero, unsigned word 0 is at most 1, and slot 0x24 is empty. */
void ImageBgDual3D_Unk_1252b4(u32 *arg0)
{
  int tmp1;
  if (arg0[2] == 0) {
    return;
  }
  if (1 < *arg0) {
    return;
  }
  tmp1 = Unk0bc1a8_IsSlotEmpty(0x24);
  if (tmp1 == 0) {
    return;
  }
  Unk0bc1a8_Unk_0bc504(arg0,0);
  return;
}

void Unk02f2a8_Unk_035440(u32 value);
void Unk095560_Unk_0956e8(void);
void func_021177b8(void);
void ImageObj_Unk_0773bc(void);
void Unk116598_Unk_1172bc(void);
void Unk02cad4_Unk_02cbdc(s32 value);
/* At 0x02125b10, runs teardown helpers, clears the global work, and
 * releases work words 8 (only for kind 3) and 4. Work is borrowed, non-null. */
void ImageBgDual3D_Unk_125b10(ImageBgDual3DWork *arg0)
{
  Unk095560_Unk_0956e8();
  ImageBgDual3D_Unk_125d48();
  ImageObj_Unk_0773bc();
  ImageBgDual3D_Unk_125a80();
  Unk116598_Unk_1172bc();
  func_021177b8();
  *data_02176e94 = 0;
  if (arg0->unk_0004 == 3) {
    Unk02f2a8_Unk_035440(arg0->unk_0008);
  }
  Unk02cad4_Unk_02cbdc(arg0->unk_0004);
  return;
}

extern u8 data_02176e90[];
int func_02061698(u8 *handle);
int func_020616c0(u8 *handle);
/* At 0x021258a0, resolves a valid global handle, forwards the argument
 * with its offset-0x8c word to two helpers, then sets offset 0x208 to one. */
void ImageBgDual3D_Unk_1258a0(u32 arg0)
{
  int tmp1;
  tmp1 = func_02061698(data_02176e90);
  if (tmp1 == 0) {
    return;
  }
  tmp1 = func_020616c0(data_02176e90);
  func_0205c408(*(u32 *)(tmp1 + 0x8c),arg0);
  func_0205c6e0(*(u32 *)(tmp1 + 0x8c));
  *(u32 *)(tmp1 + 0x208) = 1;
}

/* At 0x0212594c, returns one only if the global handle is valid and
 * its borrowed work has first word 5; otherwise returns zero. */
u32 ImageBgDual3D_Unk_12594c(void)
{
  int tmp1;
  int *v2;
  tmp1 = func_02061698(data_02176e90);
  if ((tmp1 != 0) && (v2 = (int *)func_020616c0(data_02176e90), *v2 == 5)) {
    return 1;
  }
  return 0;
}

int func_02061424(u32 work);
/* At 0x021258e8, forwards the resolved work to 0x02061424 only when
 * the global handle passes 0x02061698. No result is consumed. */
void ImageBgDual3D_Unk_1258e8(void)
{
  int tmp1;
  tmp1 = func_02061698(data_02176e90);
  if (tmp1 == 0) {
    return;
  }
  func_02061424(func_020616c0(data_02176e90));
}

void func_02077314(void);
int Unk095560_Unk_095b28(int id);
void Unk02d15c_Unk_02d91c(int a, int b);
void Unk02d15c_Setup(int a, int b, int c, int d);
void func_02095f94(void);

extern u8 data_02152180[];
u32 func_0205ba98(u32 size, u32 alignment, const u8 *file, u32 line);
/* At 0x02125910, resolves valid borrowed work, calls 0x021257e8 with it,
 * then writes the opaque argument at offset 0x80 and zero at offset 0. */
void ImageBgDual3D_Unk_125910(u32 x)
{
    u8 *q;
    if (func_02061698(data_02176e90) == 0) {
        return;
    }
    q = (u8 *)func_020616c0(data_02176e90);
    ImageBgDual3D_Thunk_021255b4((ImageBgDual3DWork *)q);
    FIELD(u32, q, 128) = x;
    FIELD(u32, q, 0) = 0;
}

/* At 0x02125a90, calls setup helpers and initializes the four work words
 * to 0, 13, 1, 0 only when helper 0x02095b28(3) succeeds. Work is borrowed. */
void ImageBgDual3D_Unk_125a90(ImageBgDual3DWork *work)
{
    func_02077314();
    ImageBgDual3D_Unk_125a68();
    if (Unk095560_Unk_095b28(3) == 0) {
        return;
    }
    Unk02d15c_Unk_02d91c(8, 3);
    Unk02d15c_Setup(8, 42, 0, -1);
    func_02095f94();
    work->unk_0000 = 0;
    work->unk_0004 = 13;
    work->unk_0008 = 1;
    work->unk_000c = 0;
    ImageBgDual3D_Unk_125afc(work);
}

/* At 0x02125c68, allocates 0x28000 bytes aligned to 0x800 only if the
 * shared buffer is absent; allocator diagnostic arguments are file and line 22. */
void ImageBgDual3D_AllocBuf(void)
{
    if (*data_02176e98 != 0) {
        return;
    }
    *data_02176e98 = func_0205ba98(0x28000, 0x800, data_02152180, 22);
}

void func_0205c3dc(u32 handle);
void func_0205ddb4(u32 handle);
void func_0205c368(u32 handle);
void func_02053000(u32 handle);
/* At 0x021255b4, releases and clears words 0x8c, 0x84 and 0x88 when
 * nonzero, then unconditionally releases and clears word 0x7c. Work is borrowed. */
void func_021255b4(ImageBgDual3DWork *work)
{
    if (work->unk_008c != 0) {
        func_0205c3dc(work->unk_008c);
        work->unk_008c = 0;
    }
    if (FIELD(u32, work, 0x84) != 0) {
        func_0205ddb4(FIELD(u32, work, 0x84));
        FIELD(u32, work, 0x84) = 0;
    }
    if (FIELD(u32, work, 0x88) != 0) {
        func_0205c368(FIELD(u32, work, 0x88));
        FIELD(u32, work, 0x88) = 0;
    }
    func_02053000(FIELD(u32, work, 0x7c));
    FIELD(u32, work, 0x7c) = 0;
}

void func_02057524(u32 value);
void func_02057534(void);
void func_0205c748(u32 mode, u32 handle, s32 x, s32 y,
                  float a, float b, u32 c, float d, u32 e);
/* At 0x02125738, work state 5 enables the offset-0x8c helper call with
 * coordinates (0, 0), bracketed by 0x02057524(0) and 0x02057534. */
void func_02125738(ImageBgDual3DWork *work)
{
    if (work->unk_0000 != 5) return;
    func_02057524(0);
    func_0205c748(2, work->unk_008c, 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
    func_02057534();
}

/* At 0x02125790, the same state-5 helper sequence uses coordinates
 * (0, -256). Borrowed work supplies the handle at offset 0x8c. */
void func_02125790(ImageBgDual3DWork *work)
{
    if (work->unk_0000 != 5) return;
    func_02057524(0);
    func_0205c748(2, work->unk_008c, 0, -256, 1.0f, 1.0f, 0, 1.0f, 0);
    func_02057534();
}

void func_02125678(ImageBgDual3DWork *work);
void func_02125b60(ImageBgDual3DWork *work);
void func_02125314(ImageBgDual3DWork *work, u32 value);
void func_021253c4(ImageBgDual3DWork *work, u32 value);
/* Callback receives borrowed work owned by the task provider. */
typedef void (*ImageBgDual3DCallback)(ImageBgDual3DWork *work);
ImageBgDual3DWork *func_020611dc(ImageBgDual3DCallback update,
    ImageBgDual3DCallback first, ImageBgDual3DCallback second,
    ImageBgDual3DCallback cleanup, u32 size, u32 a, u32 b, u32 c);
void func_020615ec(u8 *handle, ImageBgDual3DWork *work);
/* At 0x02125a08, creates a 16-byte callback work and calls 0x02125a90
 * on success. Returns zero on allocation failure, otherwise the created address. */
u32 func_02125a08(void)
{
    ImageBgDual3DWork *work = func_020611dc(func_02125b60,
        (ImageBgDual3DCallback)ImageBgDual3D_Nop_125c3c, 0,
        ImageBgDual3D_Unk_125b10, 16, 0, 0, 1);
    if (work == 0) return 0;
    ImageBgDual3D_Unk_125a90(work);
    return (u32)work;
}

/* At 0x021257f4, creates 0x20c bytes with four observed callbacks,
 * stores buffer/value at 0x90/0x80 and publishes its handle. Mode zero
 * additionally calls both initialization helpers and sets state 5. */
void func_021257f4(u32 buffer, u32 value, u32 mode)
{
    ImageBgDual3DWork *work = func_020611dc(func_02125678,
        func_02125738, func_02125790, ImageBgDual3D_Thunk_021255b4,
        0x20c, 0, 0, 1);
    FIELD(u32, work, 0x90) = buffer;
    FIELD(u32, work, 0x80) = value;
    func_020615ec(data_02176e90, work);
    if (mode != 0) return;
    func_02125314(work, 0);
    func_021253c4(work, 0);
    ImageBgDual3D_Unk_125650(work);
    work->unk_0000 = 5;
}
