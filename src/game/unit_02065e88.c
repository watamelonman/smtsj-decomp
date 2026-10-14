/*
 * unit_02065e88: small accessors for a game object whose fields are written
 * from many systems (callers in 0x020a7..., 0x020b7..., 0x020fe...).
 * Field meanings are not known yet; offsets are named by position.
 */
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef unsigned int u32;

typedef struct GameObj {
    u32 unk00;
    u32 pairA;      /* 0x04: first of a pair set together */
    u32 pairB;      /* 0x08: second of the pair */
    u32 unk0C[5];
    u32 field20;    /* 0x20 */
    u32 field24;    /* 0x24 */
    u32 field28;    /* 0x28 */
    u32 field2C;    /* 0x2C */
    u32 field30;    /* 0x30 */
    u32 field34;    /* 0x34 */
} GameObj;

/* Stores both halves of the 0x04/0x08 pair. */
void Unk065e88_SetPair04(GameObj *obj, u32 a, u32 b) {
    obj->pairA = a;
    obj->pairB = b;
}

/* Setters for single fields. */
void Unk065e88_SetUnkField20(GameObj *obj, u32 value) { obj->field20 = value; }
void Unk065e88_SetUnkField28(GameObj *obj, u32 value) { obj->field28 = value; }
void Unk065e88_SetUnkField24(GameObj *obj, u32 value) { obj->field24 = value; }
void Unk065e88_SetUnkField2C(GameObj *obj, u32 value) { obj->field2C = value; }
void Unk065e88_SetUnkField30(GameObj *obj, u32 value) { obj->field30 = value; }
void Unk065e88_SetUnkField34(GameObj *obj, u32 value) { obj->field34 = value; }

/* Empty callback (no callers; likely a function-table entry). */
void Unk065e88_Nop_066c90(void) { }



/* set u32 at +0x3c */
void Unk065e88_SetUnkField3c(void *obj, u32 value) { FIELD(u32, obj, 0x3c) = value; }


/* set +0xc and +0x10 */
void Unk065e88_SetUnkFieldsc_10(void *obj, u32 a, u32 b) {
    FIELD(u32, obj, 0xc) = a;
    FIELD(u32, obj, 0x10) = b;
}

int func_020684c0();
int func_020a1428();
/* decompiler-derived */
void Unk065e88_Unk_068554(void)
{
  func_020a1428();
  func_020684c0();
}

int func_0205bb68();
/* decompiler-derived */
void Unk065e88_Unk_065eac(void)
{
  func_0205bb68();
  func_0205bb68();
  func_0205bb68();
}

int func_0205af2c();
int func_020617c8();
/* decompiler-derived */
void Unk065e88_Unk_0663bc(u32 arg0,u32 arg1)
{
  func_0205af2c(arg1);
  func_020617c8(arg0);
}
