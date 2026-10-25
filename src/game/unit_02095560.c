/*
 * unit_02095560: owner of a static manager object at 0x02175eb0
 * (Unk095560_GetManager returns it; many functions in this unit use it).
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef signed char s8;

extern unsigned char gUnkManager_02175eb0[];   /* static manager instance */

void Unk02d15c_Call_02d91c(void);
void Unk0caea8_Unk_0cb044(u32 index);
void func_020773dc(int mode);
int func_020961a0(void);

/* 0x02095560 uses LDRSB [r0, r1]; index must address a readable table byte. */
int Unk095560_GetSignedByte(const s8 *table, int index) { return table[index]; }

u32 Unk095560_ReadU32LE(const u8 *p, int o)
{
    return p[o] | (p[o + 1] << 8) | (p[o + 2] << 16) | (p[o + 3] << 24);
}

/* 0x0209573c loads gUnkManager_02175eb0; returns borrowed static storage. */
unsigned char *Unk095560_GetManager(void) { return gUnkManager_02175eb0; }

/* 0x02095748 tail-calls GetManager; preserves its borrowed-storage contract. */
unsigned char *Unk095560_GetManagerAlias(void) { return Unk095560_GetManager(); }

/* 0x02095754 adds 0x3a8 to GetManager; returns a borrowed interior pointer. */
unsigned char *Unk095560_GetManagerSub3a8(void) { return Unk095560_GetManager() + 0x3a8; }

/* 0x02095600 tail-calls Unk02d15c_Call_02d91c without changing arguments. */
void Unk095560_Thunk_0202d15c(void) { Unk02d15c_Call_02d91c(); }
void Unk0a163c_Unk_0a1814(u16 id);
void Unk0a163c_Unk_0a1834(u16 id);
/* 0x020957e4 truncates the ID to 16 bits before forwarding to 020a1814. */
void Unk095560_Call_0a1814(int id)
{
    Unk0a163c_Unk_0a1814((u16)id);
}

/* 0x020957f8 truncates the ID to 16 bits before forwarding to 020a1834. */
void Unk095560_Call_0a1834(int id)
{
    Unk0a163c_Unk_0a1834((u16)id);
}

/* 0x0209580c tail-calls Unk0caea8_Unk_0cb044 with r0 unchanged (index). */
void Unk095560_Thunk_020cb044(u32 index) { Unk0caea8_Unk_0cb044(index); }
int func_02095d5c(u32 a, u32 b, int c);

/* 0x02095950 passes mode 1 to 095d5c and normalizes its result to 0 or 1. */
int Unk095560_Unk_095950(u32 a, u32 b)
{
    return func_02095d5c(a, b, 1) != 0;
}

/* 0x02096140 forwards r0 unchanged; callers of 020773dc supply a mode. */
void Unk095560_Thunk_020773dc(int mode) { func_020773dc(mode); }
/* 0x02096274 tail-calls 020961a0; 0202f2a8 callers consume its predicate. */
int Unk095560_Thunk_020961a0(void) { return func_020961a0(); }



/* Borrowed three-word view: 02095d2c/1c/4c load offsets 0, 4 and 8.
 * Field meanings beyond their instruction-observed positions remain unknown. */
typedef struct Unk095560Words {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk095560Words;

/* 0x02095d2c reads subobject offset 0; manager storage remains borrowed. */
u32 Unk095560_Unk_095d2c(void)
{
    const Unk095560Words *words = (const Unk095560Words *)Unk095560_GetManagerSub3a8();
    return words->unk_00;
}

extern u8 data_02175ea8[];
/* 0x02095d3c loads global offset 4; no manager lookup or ownership transfer. */
u32 Unk095560_Unk_095d3c(void)
{
    return ((const Unk095560Words *)data_02175ea8)->unk_04;
}

int func_02065ca8(void);
void Unk095560_Unk_095728(void);
/* 0x02096130 calls 095728 then 02065ca8, discarding the provider result. */
void Unk095560_Unk_096130(void)
{
    Unk095560_Unk_095728();
    func_02065ca8();
}

void *func_020445d0(int index, int item);
/* 0x02095764 forwards item with resource index 27; 020445d0 returns a
 * provider-owned resource pointer (see its definition in unit_0204459c). */
void *Unk095560_Unk_095764(int item)
{
    return func_020445d0(27, item);
}


void ImageObj_Unk_0775ec(void);
void ImageObj_Unk_077640(void);
/* 0x0209615c calls the three providers in order; results are discarded. */
void Unk095560_Unk_09615c(void)
{
  ImageObj_Unk_0775ec();
  ImageObj_Unk_077640();
  func_02065ca8();
}

void func_02077750(u32 arg0, u32 arg1);
void ImageBg_Unk_0e5550(u32 arg0, u32 arg1);
/* 0x020958a8 preserves both arguments across 020e5550 for 02077750. */
void Unk095560_Unk_0958a8(u32 arg0, u32 arg1)
{
    ImageBg_Unk_0e5550(arg0, arg1);
    func_02077750(arg0, arg1);
}


int func_0204459c();
int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk095560_Unk_095778(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x19);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk095560_Unk_09579c(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1a);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}


/* decompiler-derived */
void Unk095560_Unk_0957c0(u32 arg0)
{
  u32 value;
  value = func_0204459c(0x1a);
  value = func_0204fe68(value,0);
  func_0204fed8(value,arg0);
}

u32 Unk095560_Unk_0956e8(void);
int func_020958c8();
int Unk095560_Unk_095950();
/* decompiler-derived */
u32 Unk095560_Unk_095af8(u32 arg0)
{
  int value;
  Unk095560_Unk_0956e8();
  value = Unk095560_Unk_095950(0,arg0);
  if (value != 0) {
    func_020958c8(value);
    return 1;
  }
  return 0;
}

int func_02095818();
void ImageBg_Unk_0e5530(void);
void ImageObj_Unk_0775d8(void);
void Unk02d15c_Unk_02d81c(void);
/* decompiler-derived */
void Unk095560_Unk_096170(void)
{
  int value;
  value = func_02095818();
  if (value == 0) {
    ImageBg_Unk_0e5530();
    ImageObj_Unk_077640();
    func_02065ca8();
  }
  else {
    ImageObj_Unk_0775d8();
  }
  Unk02d15c_Unk_02d81c();
  func_02065ca8();
}



/* decompiler-derived */
u32 Unk095560_Unk_095a2c(u32 arg0)
{
  int value;
  Unk095560_Unk_0956e8();
  value = Unk095560_Unk_095950(1,arg0);
  if (value != 0) {
    func_020958c8(value);
    Unk02d15c_Call_02d91c();
    return 1;
  }
  return 0;
}

int Unk02d15c_GetManagerRecord();
int Unk095560_Unk_09560c();
/* decompiler-derived */
u32 Unk095560_Unk_095660(void)
{
  u32 *v1;
  int value1;
  int value2;
  value2 = 2;
  do {
    v1 = (u32 *)Unk094fe0_Unk_094fec(value2);
    value1 = Unk02d15c_GetManagerRecord(value2);
    Unk095560_Unk_09560c(value2);
    *v1 = 0xffffffff;
    value2 = value2 + 1;
    *(u32 *)(value1 + 0x50) = 0xffffffff;
  } while (value2 < 8);
  return 1;
}



int func_02052f58();
int func_02052f68();
int func_02052fe0();
int func_02052ff0();
int func_02053000();
int func_0205f508();
int func_0205f534();
int func_0205f590();
int func_0205f5f0();
int func_0205f668();
/* decompiler-derived */
u32
func_02095a60(u32 arg0,u32 arg1,u32 arg2,u32 arg3)
{
  u32 value1;
  u32 value2;
  u8 auStack_20 [12];
  u32 uStack_14;
  uStack_14 = arg3;
  func_02052f58(0);
  func_0205f508(auStack_20,arg0);
  value1 = func_0205f534(auStack_20);
  value2 = func_02052ff0();
  func_0205f590(auStack_20,value2,value1);
  func_0205f5f0(auStack_20,value2,arg1);
  value1 = func_02052fe0();
  func_02052f68();
  func_0205f668(auStack_20,value2,arg1,value1);
  func_02052f58(0);
  func_02053000(value2);
  func_02052f68();
  return value1;
}

extern char data_0214c6f8[];
extern char data_0214c720[];
extern char data_0214c750[];
extern char data_0214c774[];
extern char data_0214c798[];
extern char data_0214c7bc[];
extern char data_0214c7e4[];
extern char data_0214c808[];
extern char data_0214c830[];
extern char data_0214c854[];
extern char data_0214c874[];
void func_02013c3c(char *buf, const char *fmt, ...);
u8 *Unk02e000_GetWorkArea(void);
u32 Unk02f2a8_GetRes36Unk19(u16 n);
int func_02096448(int id);

/* Mission/progress record returned by Unk02d15c_GetManagerRecord. */
typedef struct MissionInfo {
    u8  pad_0000[0x50];
    u32 stage;                  /* +0x50 */
} MissionInfo;

/* Builds the event-message .bin path for event id `id` into `buf`. */
void func_02095b48(char *buf, int id)
{
    u16 n;
    u32 v;

    if (func_02096448(id) != 0) {
        func_02013c3c(buf, data_0214c6f8, ((MissionInfo *)Unk02d15c_GetManagerRecord(id))->stage);
        return;
    }
    if (id == 0) {
        n = *(u16 *)(Unk02e000_GetWorkArea() + 0x35c);
        v = Unk02f2a8_GetRes36Unk19(n);
        if (n >= 0x3d4) {
            v = 99;
        }
        func_02013c3c(buf, data_0214c720, v);
    } else if (id == 8) {
        switch (((MissionInfo *)Unk02d15c_GetManagerRecord(id))->stage) {
        case 0: func_02013c3c(buf, data_0214c750); return;
        case 1: func_02013c3c(buf, data_0214c774); return;
        case 2: func_02013c3c(buf, data_0214c798); return;
        case 3: func_02013c3c(buf, data_0214c7bc); return;
        }
    } else if (id == 1) {
        switch (((MissionInfo *)Unk02d15c_GetManagerRecord(id))->stage) {
        case 0: func_02013c3c(buf, data_0214c7e4); return;
        case 1: func_02013c3c(buf, data_0214c808); return;
        case 2: func_02013c3c(buf, data_0214c830); return;
        case 3: func_02013c3c(buf, data_0214c854); return;
        case 4: func_02013c3c(buf, data_0214c874); return;
        }
    }
}

/* 0x02095728 calls these three providers in order; no results are consumed. */
void Unk095560_Unk_095728(void)
{
    ImageBg_Unk_0e5530();
    ImageObj_Unk_0775d8();
    Unk02d15c_Unk_02d81c();
}

/* 0x02095d1c reads subobject offset 4; callers interpret -1 as no record. */
u32 Unk095560_Unk_095d1c(void)
{
    const Unk095560Words *words = (const Unk095560Words *)Unk095560_GetManagerSub3a8();
    return words->unk_04;
}

/* 0x02095d4c reads subobject offset 8; manager storage remains borrowed. */
u32 Unk095560_Unk_095d4c(void)
{
    const Unk095560Words *words = (const Unk095560Words *)Unk095560_GetManagerSub3a8();
    return words->unk_08;
}

/* 0x02095d08 stores the caller's word at subobject offset 8.
 * The subobject borrows the manager's static storage. */
void Unk095560_Unk_095d08(u32 value)
{
    Unk095560Words *words = (Unk095560Words *)Unk095560_GetManagerSub3a8();
    words->unk_08 = value;
}

typedef struct Worker Worker;
void Unk0202dcfc_InitWorker(Worker *worker, u32 owner);
u32 Unk0964f8_Unk_0964f8(void);

/* 0x020956a8 resets through 0956e8/0964f8, initializes the borrowed manager
 * worker with owner 0, and returns 1 regardless of the reset results. */
u32 Unk095560_Unk_0956a8(void)
{
    Unk095560_Unk_0956e8();
    Unk0964f8_Unk_0964f8();
    Unk0202dcfc_InitWorker((Worker *)Unk095560_GetManagerAlias(), 0);
    return 1;
}

/* 0x020956c8 repeats 0956a8's provider sequence and unconditional success;
 * the original has a separate entry point with identical instructions. */
u32 Unk095560_Unk_0956c8(void)
{
    Unk095560_Unk_0956e8();
    Unk0964f8_Unk_0964f8();
    Unk0202dcfc_InitWorker((Worker *)Unk095560_GetManagerAlias(), 0);
    return 1;
}

int func_0204af80();
/* decompiler-derived */
u32 Unk095560_Unk_0956e8(void)
{
  int tmp1;
  int tmp2;
  tmp1 = (int)(Unk095560_GetManagerAlias());
  *(u32 *)(tmp1 + 0x14) = 0;
  func_0204af80();
  tmp1 = 0;
  do {
    tmp2 = Unk095560_Unk_09560c(tmp1);
    if (tmp2 == 0) {
      return 0;
    }
    tmp1 = tmp1 + 1;
  } while (tmp1 < 9);
  return 1;
}

int func_02008848();
int func_0204ae84();
/* decompiler-derived */
void Unk095560_Unk_095598(void)
{
  u32 tmp1;
  int tmp2;
  int tmp3;
  u32 *v4;
  int tmp5;
  tmp1 = (unsigned int)(Unk095560_GetManager());
  tmp2 = (int)(Unk095560_GetManagerAlias());
  func_02008848(tmp1,0,0x3c0);
  tmp5 = 0;
  do {
    tmp3 = Unk02d15c_GetManagerRecord(tmp5);
    v4 = (u32 *)Unk094fe0_Unk_094fec(tmp5);
    func_0204ae84(tmp3 + 0x10);
    *(u32 *)(tmp3 + 0x50) = 0xffffffff;
    tmp5 = tmp5 + 1;
    *v4 = 0xffffffff;
  } while (tmp5 < 9);
  *(u32 *)(tmp2 + 0x18) = 0xffffffff;
}

typedef struct Unk095560Rec {
    u32 buf;
    u8 pad_04[12];
    u8 unk_10[4];
    u32 unk_14;
    u8 pad_18[56];
    s32 id;
} Unk095560Rec;
int func_02053000();
int Unk095560_Unk_0959d0(s32 a, s32 *out);

int Unk095560_Unk_09560c(int i)
{
    Unk095560Rec *r = (Unk095560Rec *)Unk02d15c_GetManagerRecord(i);
    s32 *slot = (s32 *)Unk094fe0_Unk_094fec(i);
    if (r->buf != 0) {
        func_02053000(r->buf);
        r->buf = 0;
        r->unk_14 = 0;
    }
    r->id = -1;
    *slot = -1;
    func_0204af80(&r->unk_10);
    return 1;
}

int Unk095560_Unk_09596c(u32 a)
{
    s32 slot = -1;
    switch (Unk095560_Unk_0959d0(a, &slot)) {
    case 0:
        return 0;
    case 1:
        break;
    case 2:
        return 1;
    }
    return Unk095560_Unk_095950(slot, a);
}

int Unk095560_Unk_0959d0(s32 a, s32 *out)
{
    int i;
    for (i = 2; i < 8; i++) {
        Unk095560Rec *r = (Unk095560Rec *)Unk02d15c_GetManagerRecord(i);
        Unk094fe0_Unk_094fec(i);
        if (r->id == a) {
            return 2;
        }
        if (r->id == -1) {
            *out = i;
            return 1;
        }
    }
    return 0;
}

int Unk095560_Unk_095b28(u32 x)
{
    return Unk095560_Unk_095950(8, x) != 0;
}

int Unk095560_Unk_095cd8(u32 a, u32 b, u32 c, u32 d)
{
    u32 *q;
    ((u32 *)data_02175ea8)[0] = c;
    ((u32 *)data_02175ea8)[1] = d;
    q = (u32 *)Unk095560_GetManagerSub3a8();
    q[1] = a;
    q[0] = b;
    q[2] = -1;
    return 1;
}

/* 0x0209614c tail-forwards mode 1 to 020773dc, as the literal/BX shows. */
void Unk095560_Call_020773dc(void)
{
    func_020773dc(1);
}

int func_0206552c();

int Unk095560_Unk_096484(void)
{
    switch (func_02095818()) {
    case 0:
        return func_0206552c() == 0;
    case 2:
        return func_0206552c() == 0;
    case 3:
        return func_0206552c() == 0;
    case 1:
    case 4:
    case 5:
    case 6:
    default:
        return 1;
    }
}
