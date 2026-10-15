/* src/game/unit_02039bb4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk039bb4Work {
    u8 pad_0000[0x18];
    s32 unk_0018;
    s32 unk_001c;
    u8 pad_0020[0x94];
    s32 unk_00b4;
    s32 unk_00b8;
    s32 unk_00bc;
    s32 unk_00c0;
    u8 pad_00c4[0x14];
    s32 unk_00d8;
    s32 unk_00dc;
} Unk039bb4Work;

int func_0203a334();
/* decompiler-derived */
u32 Unk039bb4_Unk_03a9ec(int arg0)
{
  func_0203a334(arg0,5);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03aa10(int arg0)
{
  func_0203a334(arg0,6);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03aa34(int arg0)
{
  func_0203a334(arg0,7);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03aa58(int arg0)
{
  func_0203a334(arg0,8);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03aa7c(int arg0)
{
  func_0203a334(arg0,9);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03aaa0(int arg0)
{
  func_0203a334(arg0,10);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03aac4(int arg0)
{
  func_0203a334(arg0,0xb);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a298(int arg0)
{
  ((Unk039bb4Work *)arg0)->unk_0018 =
       *(u32 *)
        (((Unk039bb4Work *)arg0)->unk_00b4 +
         (u32)*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 0x20 +
        0x18);
  return 1;
}


void func_0203ab84(void);
/* forwards to `func_0203ab84` */
void Unk039bb4_Thunk_0203ab84(void) { func_0203ab84(); }


/* decompiler-derived */
u32 Unk039bb4_Unk_03a1c8(int arg0)
{
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a2f8(int arg0)
{
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a7f8(int arg0)
{
  func_0203a334(arg0,0);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a81c(int arg0)
{
  func_0203a334(arg0,1);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a840(int arg0)
{
  func_0203a334(arg0,2);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a864(int arg0)
{
  func_0203a334(arg0,3);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a9c8(int arg0)
{
  func_0203a334(arg0,4);
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}



/* decompiler-derived */
u32 Unk039bb4_Unk_03a30c(int arg0)
{
  ((Unk039bb4Work *)arg0)->unk_0018 =
       *(u32 *)
        (((Unk039bb4Work *)arg0)->unk_00b8 +
         (u32)*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 0x20 +
        0x18);
  return 1;
}


/* decompiler-derived */
void Unk039bb4_Unk_039d10(int arg0,u32 arg1)
{
  *(u8 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c + 0x20) = 0;
  *(u32 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c * 4 + 0x3c) = arg1;
  ((Unk039bb4Work *)arg0)->unk_001c = ((Unk039bb4Work *)arg0)->unk_001c + 1;
  return;
}


/* decompiler-derived */
void Unk039bb4_Unk_039d3c(int arg0,u32 arg1)
{
  *(u8 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c + 0x20) = 1;
  *(u32 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c * 4 + 0x3c) = arg1;
  ((Unk039bb4Work *)arg0)->unk_001c = ((Unk039bb4Work *)arg0)->unk_001c + 1;
  return;
}


/* decompiler-derived */
void Unk039bb4_Unk_039d68(int arg0,u32 arg1)
{
  *(u8 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c + 0x20) = 5;
  *(u32 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c * 4 + 0x3c) = arg1;
  ((Unk039bb4Work *)arg0)->unk_001c = ((Unk039bb4Work *)arg0)->unk_001c + 1;
  return;
}


/* decompiler-derived */
void Unk039bb4_Unk_039d94(int arg0,u32 arg1)
{
  *(u8 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c + 0x20) = 4;
  *(u32 *)(arg0 + ((Unk039bb4Work *)arg0)->unk_001c * 4 + 0x3c) = arg1;
  ((Unk039bb4Work *)arg0)->unk_001c = ((Unk039bb4Work *)arg0)->unk_001c + 1;
  return;
}

int func_02039dc0();
/* decompiler-derived */
u32 Unk039bb4_Unk_03a26c(int arg0)
{
  int tmp1;
  if (((Unk039bb4Work *)arg0)->unk_001c != 0) {
    tmp1 = func_02039dc0(arg0);
    ((Unk039bb4Work *)arg0)->unk_0018 = tmp1 + 1;
    return 1;
  }
  return 0;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_039f1c(int arg0)
{
  Unk039bb4_Unk_039d10(arg0,*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2)
               );
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_039ee8(int arg0)
{
  int tmp1;
  tmp1 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  ((Unk039bb4Work *)arg0)->unk_0018 = tmp1;
  Unk039bb4_Unk_039d10(arg0,*(u32 *)(((Unk039bb4Work *)arg0)->unk_00bc + tmp1 * 4));
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}



/* decompiler-derived */
u32 Unk039bb4_Unk_039f4c(int arg0)
{
  int tmp1;
  tmp1 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  ((Unk039bb4Work *)arg0)->unk_0018 = tmp1;
  Unk039bb4_Unk_039d3c(arg0,*(u32 *)(((Unk039bb4Work *)arg0)->unk_00bc + tmp1 * 4));
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_039ff8(int arg0)
{
  Unk039bb4_Unk_039d10(arg0,*(u32 *)
                         (((Unk039bb4Work *)arg0)->unk_00d8 +
                         (u32)*(u16 *)
                                (((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 4));
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a030(int arg0)
{
  Unk039bb4_Unk_039d3c(arg0,*(u32 *)
                         (((Unk039bb4Work *)arg0)->unk_00dc +
                         (u32)*(u16 *)
                                (((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 4));
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a068(int arg0)
{
  Unk039bb4_Unk_039d68(arg0,((Unk039bb4Work *)arg0)->unk_00c0 +
                        (u32)*(u16 *)
                               (((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2));
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a158(int arg0)
{
  u32 tmp1;
  tmp1 = func_02039dc0();
  *(u32 *)
   (((Unk039bb4Work *)arg0)->unk_00d8 +
   (u32)*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 4) = tmp1;
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}

int func_02039e50();
/* decompiler-derived */
u32 Unk039bb4_Unk_03a190(int arg0)
{
  u32 tmp1;
  tmp1 = func_02039e50();
  *(u32 *)
   (((Unk039bb4Work *)arg0)->unk_00dc +
   (u32)*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 4) = tmp1;
  ((Unk039bb4Work *)arg0)->unk_0018 = ((Unk039bb4Work *)arg0)->unk_0018 + 1;
  return 1;
}


/* decompiler-derived */
u32 Unk039bb4_Unk_03a2c0(int arg0)
{
  Unk039bb4_Unk_039d94(arg0,((Unk039bb4Work *)arg0)->unk_0018);
  ((Unk039bb4Work *)arg0)->unk_0018 =
       *(u32 *)
        (((Unk039bb4Work *)arg0)->unk_00b4 +
         (u32)*(u16 *)(((Unk039bb4Work *)arg0)->unk_00bc + ((Unk039bb4Work *)arg0)->unk_0018 * 4 + 2) * 0x20 +
        0x18);
  return 1;
}


