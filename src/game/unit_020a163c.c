/*
 * src/game/unit_020a163c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_020445f4();
int func_0204fed8();
void func_020a208c(void);

void Unk0a163c_Thunk_020a208c(void);
int Unk0a163c_Unk_0a1718(u16 *arg0,u16 *arg1);
void Unk0a163c_Unk_0a1814(u32 arg0);
void Unk0a163c_Unk_0a1834(u32 arg0);

u32 func_020445d0(int kind, u32 id);
void func_0204fe18(u32 h);
void func_020a1b08(u32 a, u16 id);
void func_020a2218(u32 a, u16 id);
void Unk0a163c_Unk_0a1728(void)
{
    func_0204fe18(func_020445d0(19, 1));
}

void Unk0a163c_Call_020a1b08(u32 a, int id)
{
    func_020a1b08(a, (u16)(id + 500));
}

/* forwards to `func_020a208c` */
void Unk0a163c_Thunk_020a208c(void) { func_020a208c(); }

/* decompiler-derived */
int Unk0a163c_Unk_0a1718(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

int func_020a1740();
int func_02011804();
extern u8 data_0213c258[];
extern u8 data_0213c244[];
int Unk02e000_GetRecordUnk1e();
u16 func_020a1798(u32 id)
{
    s32 v = FIELD(s16, func_020a1740(id), 106);
    if (v < 0) {
        return func_02011804(v);
    }
    return data_0213c244[data_0213c258[v]];
}

int func_020a17d8(u32 id)
{
    u8 *e = (u8 *)func_020a1740(id);
    if (FIELD(s16, e, 106) < 0) {
        return 1;
    }
    return Unk02e000_GetRecordUnk1e(id) < e[90];
}

/* decompiler-derived */
void Unk0a163c_Unk_0a1814(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x12,1);
  func_0204fed8(value,arg0);
}

/* decompiler-derived */
void Unk0a163c_Unk_0a1834(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x12,0);
  func_0204fed8(value,arg0);
}


int func_02053000();
int func_020a1a24();
/* decompiler-derived */
u32 Unk0a163c_Unk_0a1ae0(u32 *arg0)
{
  func_020a1a24();
  func_02053000(arg0[1]);
  arg0[1] = 0;
  *arg0 = 0;
  return 1;
}

void func_020a21f8(u8 *p)
{
    FIELD(u32, p, 12) = 1;
    func_020a208c();
}

void Unk0a163c_Call_020a2218(u32 a, int id)
{
    func_020a2218(a, (u16)(id + 500));
}
