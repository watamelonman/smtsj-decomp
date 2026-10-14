/*
 * unit_0202dcfc: initialiser for an object owned by the unit_02095560 system
 * (callers func_020956a8/func_020956c8/func_02095d5c).
 */
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Worker {
    u32 unk00[16];
    u32 owner;          /* 0x40: set from the argument */
    u32 state;          /* 0x44 */
    u32 timer;          /* 0x48 */
    u32 sub[2];         /* 0x4C: sub-object, has its own init */
    u32 field54;
    u32 field58;
    u8  flag5C;
    u8  pad5D[3];
    u32 field60;
    u32 field64;
    u32 field68;
    u32 unk6C;
    u32 field70;
    u32 slots[16];      /* 0x74 */
} Worker;

void func_020a2bb8(u32 *sub);

/* Resets the object and attaches it to `owner`. */
void Unk0202dcfc_InitWorker(Worker *w, u32 owner) {
    int i;

    w->owner = owner;
    w->state = 0;
    w->timer = 0;
    func_020a2bb8(w->sub);
    w->field54 = 0;
    w->field58 = 0;
    w->flag5C = 0;
    w->field60 = 0;
    w->field64 = 0;
    w->field68 = 0;
    w->field70 = 0;
    for (i = 0; i < 16; i++) {
        w->slots[i] = 0;
    }
}


void Unk095560_GetManagerAlias(void);
/* forwards to `Unk095560_GetManagerAlias` */
void Unk02dcfc_Thunk_Unk095560_GetManagerAlias(void) { Unk095560_GetManagerAlias(); }


/* decompiler-derived */
void Unk02dcfc_Unk_02df00(int arg0,u32 arg1)
{
  *(u32 *)(arg0 + 0x18) = 0x15;
  *(u32 *)(arg0 + 0x1c) = arg1;
  return;
}


/* decompiler-derived */
void Unk02dcfc_Unk_02de58(int arg0)
{
  *(u32 *)(arg0 + 0x18) = 0xc;
  *(u32 *)(arg0 + 0x54) = 1;
  return;
}



int func_0205e5b4();
int func_020a2c00();
/* decompiler-derived */
void Unk02dcfc_Unk_02dd9c(int arg0)
{
  int tmp1;
  *(u32 *)(arg0 + 0x18) = 0xb;
  *(u32 *)(arg0 + 0x44) = 1;
  tmp1 = func_0205e5b4();
  *(u32 *)(arg0 + 0x48) = (u32)(tmp1 != -1);
  func_020a2c00(arg0 + 0x4c);
  return;
}
