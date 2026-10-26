/* Cave-area helpers reconstructed from ARM field accesses and call relocations. */
#include "types.h"



/* Adjacent handles selected with an eight-byte stride at 0x020ec440. */
typedef union CaveAreaHandlePairs {
    u32 first[22];
    struct { u32 preceding; u32 second[21]; } shifted;
} CaveAreaHandlePairs;

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct CaveAreaWork {
    u32 unk_0000;
    u32 unk_0004;
    u8 pad_0008[0xc];
    CaveAreaHandlePairs unk_0014; /* Extent bounded by the next observed field. */
    const u8 *unk_006c;
    u8 pad_0070[0xc];
    u32 unk_007c;
    u32 unk_0080;
    u8 pad_0084[0x24];
    u8 unk_00a8;
    u8 pad_00a9[0x13];
    s32 unk_00bc;
    u8 pad_00c0[0x8];
    u8 unk_00c8;
    u8 pad_00c9;
    u8 unk_00ca;
    u8 pad_00cb[0x59];
    s32 unk_0124;
    u8 pad_0128[0x38];
    u32 unk_0160;
    s8 unk_0164;
} CaveAreaWork;

void func_0205bb68(void);
/* At 0x020ed354, invokes the no-argument helper twice; its wider purpose is unknown. */
void CaveArea_Unk_0ed354(void)
{
  func_0205bb68();
  func_0205bb68();
  return;
}


/* ARM stores at 0x020ec278 select byte state 2 and set the word at +0x160. */
void CaveArea_Unk_0ec278(CaveAreaWork *arg0)
{
  ((CaveAreaWork *)arg0)->unk_00c8 = 2;
  ((CaveAreaWork *)arg0)->unk_0160 = 1;
  return;
}


extern u8 data_02150d6c[];
u32 func_0205ba98(u32 size, u32 alignment, const u8 *source, u32 line);
/* 0x020ed1a8 requests 0x4000 bytes aligned to 0x200 and retains the handle at +0x80. */
void CaveArea_AllocBuf(CaveAreaWork *p)
{
    p->unk_0080 = func_0205ba98(0x4000, 0x200, data_02150d6c, 0x5a1);
}

/* 0x020ed3b4 resets words 0 and 2 and sets word 3 to 16; word 1 is preserved. */
void CaveArea_Unk_0ed3b4(u32 *arg0)
{
  *arg0 = 0;
  arg0[2] = 0;
  arg0[3] = 0x10;
  return;
}

void *func_020445f4(int index, int item);
u32 func_0204fed8(void *table, u32 index);
/* 0x020eda18 forwards the index through table (0x25, 0), discarding the result. */
void CaveArea_Unk_0eda18(u32 arg0)
{
  void *tmp1;
  tmp1 = func_020445f4(0x25,0);
  func_0204fed8(tmp1,arg0);
  return;
}


/* 0x020ed26c calls the helper only for a nonzero +0x124 flag, then clears it. */
void CaveArea_Unk_0ed26c(CaveAreaWork *arg0)
{
  if (((CaveAreaWork *)arg0)->unk_0124 == 0) {
    return;
  }
  func_0205bb68();
  ((CaveAreaWork *)arg0)->unk_0124 = 0;
  return;
}

extern u8 data_02150d78[];
extern u8 data_02150d94[];
extern u8 data_02150dac[];
int func_02013c3c(u8 *buffer, const u8 *format, ...);
int func_0205ae60(void *request);
int func_0205b398(u32 handle, void *request);
/* Format strings at data_02150d78/94/ac name Cave/Area layouts, including
 * cave_privatearmy. The loader consumes the stack-backed name synchronously. */
void CaveArea_LoadAreaLayout(CaveAreaWork *arg0)
{
  int tmp1;
  u8 auStack_48 [64];
  tmp1 = ((CaveAreaWork *)arg0)->unk_00bc;
  if (((CaveAreaWork *)arg0)->unk_00a8 == '\0') {
    if (tmp1 == 5) {
      func_02013c3c(auStack_48,data_02150d78);
    }
    else {
      func_02013c3c(auStack_48,data_02150d94,tmp1 + 1);
    }
  }
  else {
    func_02013c3c(auStack_48,data_02150dac,tmp1 + 6);
  }
  CaveArea_AllocBuf(arg0);
  arg0->unk_006c = auStack_48;
  ((CaveAreaWork *)arg0)->unk_007c = 0;
  func_0205ae60((u8 *)arg0 + 0x68);
  func_0205b398(((CaveAreaWork *)arg0)->unk_0080,(u8 *)arg0 + 0x68);
  ((CaveAreaWork *)arg0)->unk_0124 = 1;
}

void func_0205de30(u32 handle, u32 index, u32 buffer);
void Unk1241ec_Unk_124224(u16 index);
/* 0x020ed364 selects index 8 for area 5, or adds 5 for the alternate set. */
void CaveArea_Unk_0ed364(CaveAreaWork *p)
{
    u32 c = p->unk_00bc;
    if (p->unk_00a8 == 0) {
        if (c == 5) {
            func_0205de30(p->unk_0004, 8, p->unk_0080);
            return;
        }
        func_0205de30(p->unk_0004, c, p->unk_0080);
        return;
    }
    func_0205de30(p->unk_0004, c + 5, p->unk_0080);
}

typedef struct CaveAreaUnk0ed9e8 {
    u8 pad_000[296];
    float t;
} CaveAreaUnk0ed9e8;

/* 0x020ed3cc advances the caller-owned float by 0.6, resetting at >= 32. */
void CaveArea_Unk_0ed3cc(float *p)
{
    *p += 0.6f;
    if (*p >= 32.0f) {
        *p = 0.0f;
    }
}

/* Stores at 0x020ed60c initialize three floats and the following integer word.
 * The caller must provide at least 16 writable bytes. */
void CaveArea_InitParams(float *p)
{
    p[0] = 96.0f;
    p[1] = 8.0f;
    p[2] = 0.0f;
    FIELD(u32, p, 12) = 16;
}

/* 0x020ed9e8 advances the float at +0x128 by 0.5 and wraps at 192. */
void CaveArea_Unk_0ed9e8(CaveAreaUnk0ed9e8 *o)
{
    o->t += 0.5f;
    if (o->t >= 192.0f) {
        o->t = 0.0f;
    }
}

/* 0x020edb4c selects a u16 helper index using area, signed byte +0x164,
 * and the alternate-set flag; input storage must cover those fields. */
void CaveArea_Unk_0edb4c(CaveAreaWork *p)
{
    int x;
    s8 s = p->unk_0164;
    int c = p->unk_00bc;
    u8 b = p->unk_00a8;
    if (c == s) {
        x = b == 0 ? 50 : 51;
    } else {
        x = b == 0 ? c + 10 : c + 16;
    }
    Unk1241ec_Unk_124224((u16)x);
}

/* Callback addresses are established by the six literals at 0x020eb824. */
typedef struct CaveAreaCallbacks {
    u32 size;
    u32 enabled;
    u32 preserved;
    void (*callbacks[6])(void);
} CaveAreaCallbacks;
void func_020ebb14(void);
void func_020ec330(void);
void func_020ec704(void);
void func_020ecc24(void);
void func_020eba60(CaveAreaWork *p);
void func_020ecfe8(void);

/* 0x020eb7e0 populates a caller-owned descriptor, preserving word +8. */
void func_020eb7e0(CaveAreaCallbacks *p)
{
    p->size = 360;
    p->enabled = 1;
    p->callbacks[0] = func_020ebb14;
    p->callbacks[1] = func_020ec330;
    p->callbacks[2] = func_020ec704;
    p->callbacks[3] = func_020ecc24;
    p->callbacks[4] = (void (*)(void))func_020eba60;
    p->callbacks[5] = func_020ecfe8;
}

void Unk0a0ce4_Unk_0a0da4(int value);
void Unk0fedd4_SetState0(void);
void func_0205caa8(u32 handle, u32 value);
extern u32 data_0213c81c[];
extern u32 data_0213c820[];

/* 0x020ec440 uses pairs of handles/table entries for the current area,
 * loads its layout, then sets the observed byte states. */
void func_020ec440(CaveAreaWork *p)
{
    int index;
    Unk0a0ce4_Unk_0a0da4(1);
    Unk0fedd4_SetState0();
    index = p->unk_00bc * 2;
    func_0205caa8(p->unk_0014.first[index], data_0213c81c[index]);
    func_0205caa8(p->unk_0014.shifted.second[index], data_0213c820[index]);
    CaveArea_LoadAreaLayout(p);
    p->unk_00ca = 0;
    p->unk_00c8 = 4;
}

/* Stack record layout follows byte stores and sixteen word stores at 0x020ec4a8. */
typedef struct CaveAreaRequest {
    u8 flags[2];
    u8 padding[2];
    u32 words[16];
} CaveAreaRequest;
void func_020bcbc4(int index, CaveAreaRequest *request);
void func_020bc9f4(int index, int value);

/* 0x020ec4a8 submits flag 0x80 and the supplied word in slot seven. */
void func_020ec4a8(u32 value)
{
    CaveAreaRequest request;
    int i;
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.words[i] = 0;
    request.flags[0] |= 0x80;
    request.words[7] = value;
    func_020bcbc4(15, &request);
    func_020bc9f4(16, 0);
}

/* Six-word borrowed request, initialized before passing to the external provider. */
typedef struct CaveAreaSelection { s32 words[6]; } CaveAreaSelection;
void func_020fa8a8(u32 handle, CaveAreaSelection *selection, u32 value);

/* 0x020edad8 passes a one-based area selection; normal area 5 maps to 9. */
void func_020edad8(CaveAreaWork *p, u32 handle, u32 value)
{
    CaveAreaSelection selection = {0};
    if (p->unk_00a8 == 0) {
        if (p->unk_00bc == 5) selection.words[0] = 8;
        else selection.words[0] = p->unk_00bc;
    } else selection.words[0] = p->unk_00bc + 5;
    selection.words[0]++;
    func_020fa8a8(handle, &selection, value);
}

void *func_0205e328(u32 handle, int index, int value);
void *func_0205e318(u32 handle, int index);
void func_0205e048(int mode, u32 handle, void *record, int value, int frame,
                    float x, float y, int zero, u32 extra, int a, int b);
/* 0x020ed768 copies work coordinates into borrowed provider records, then
 * submits the frame at +0x88 minus one. Work storage must cover +0x104. */
void func_020ed768(CaveAreaWork *p)
{
    void *a = func_0205e328(p->unk_0000, 5, 0);
    void *b = func_0205e318(p->unk_0000, 43);
    FIELD(u16, b, 14) = FIELD(u32, p, 0x94);
    FIELD(u16, a, 6) = FIELD(u32, p, 0x94);
    FIELD(u16, a, 2) = FIELD(u32, p, 0x90);
    func_0205e048(2, p->unk_0000, b, 0, (int)FIELD(float, p, 0x88)-1,
                   1.0f, 1.0f, 0, FIELD(u32,p,0x104), 2, 1);
}

void func_0205c748(int mode, u32 handle, int x, int y, float sx, float sy,
                    int zero, float scale, int layer);
/* 0x020ecb88 draws handle +0xc or +0x10 only in byte states 2 and 3. */
void func_020ecb88(CaveAreaWork *p, int x, int y)
{
    if (p->unk_00c8 < 2) return;
    if (p->unk_00c8 > 3) return;
    if (p->unk_00a8 == 0)
        func_0205c748(2, FIELD(u32,p,12), x,y,1.0f,1.0f,0,1.0f,6);
    else
        func_0205c748(2, FIELD(u32,p,16), x,y,1.0f,1.0f,0,1.0f,6);
}

/* Borrowed provider object: only its handle and signed visibility byte are known. */
typedef struct CaveAreaDrawObject { u32 handle; u8 pad[60]; s8 hidden; } CaveAreaDrawObject;
void func_02060dd4(void *out, CaveAreaDrawObject *p, int zero, int value, int extra);
void func_02057ddc(u32 color);
void func_02059f70(u32 handle, int zero, int x, int y, void *record, int value, int extra);
/* 0x020eda38 submits two adjacent rows with separate colors when +0x40 is zero.
 * The provider borrows the four-word stack record during each call. */
void func_020eda38(CaveAreaDrawObject *p, int x, int y, int value, int extra, int layer, u32 color)
{
    u32 record[4];
    if (p->hidden != 0) return;
    func_02060dd4(record,p,0,value,extra);
    func_02057ddc(255);
    func_02059f70(p->handle,0,x,y+1,record,0,layer);
    func_02057ddc(color);
    func_02059f70(p->handle,0,x,y,record,0,layer);
}

int func_02053824(int device, int mask);
int func_02053800(int device, int mask);
int func_02117170(void);
/* 0x020ec28c prioritizes masks 64/128, then conditional masks 32/16,
 * followed by masks 1/2; the result is a selector in 0..5. */
int func_020ec28c(void)
{
    if (func_02053824(0,64)) return 1;
    if (func_02053824(0,128)) return 2;
    if (func_02117170()) {
        if (func_02053800(0,32)) return 3;
        if (func_02053800(0,16)) return 3;
    }
    if (func_02053800(0,1)) return 4;
    if (func_02053800(0,2)) return 5;
    return 0;
}

/* Prefix view exposes the 23 contiguous owned handle slots at +0xc. */
typedef struct CaveAreaHandleView { u32 prefix[3]; u32 handles[23]; } CaveAreaHandleView;
void func_020629c4(u32 handle);
void func_0205c3dc(u32 handle);
void func_0205c368(u32 handle);
void func_0205ddb4(u32 handle);
extern u32 data_02176de0;
/* 0x020eba60 releases 23 handles and three parent handles, clearing each
 * released slot, then invokes nine cleanup calls and clears the global word. */
void func_020eba60(CaveAreaWork *p)
{
    int i;
    CaveArea_Unk_0ed26c(p);
    func_020629c4(FIELD(u32,p,0x84));
    for (i=0;i<23;i++) {
        if (((CaveAreaHandleView *)p)->handles[i]) {
            func_0205c3dc(((CaveAreaHandleView *)p)->handles[i]);
            ((CaveAreaHandleView *)p)->handles[i]=0;
        }
    }
    if (FIELD(u32,p,8)) { func_0205c368(FIELD(u32,p,8)); FIELD(u32,p,8)=0; }
    if (p->unk_0000) { func_0205ddb4(p->unk_0000); p->unk_0000=0; }
    if (p->unk_0004) { func_0205ddb4(p->unk_0004); p->unk_0004=0; }
    for (i=0;(u32)i<9;i++) func_0205bb68();
    data_02176de0=0;
}

int func_0211708c(void);
void Unk05b82c_Unk_05b82c(int index);
/* 0x020ed290 selects two provider indices from the area and alternate flag,
 * retaining them at +0x130/+0x134 before forwarding both. */
void func_020ed290(CaveAreaWork *p)
{
    int area=func_0211708c();
    if (p->unk_00a8==0) {
        if (area<=4) { FIELD(int,p,0x130)=area+103; FIELD(int,p,0x134)=area+112; }
        else if (area==5) { FIELD(int,p,0x130)=107; FIELD(int,p,0x134)=116; }
        else { FIELD(int,p,0x130)=108; FIELD(int,p,0x134)=117; }
    } else {
        if (area>=5) {
            if (area==8) { FIELD(int,p,0x130)=109; FIELD(int,p,0x134)=118; }
            else { int index=area-5; FIELD(int,p,0x130)=index+109; FIELD(int,p,0x134)=index+118; }
        } else { FIELD(int,p,0x130)=111; FIELD(int,p,0x134)=120; }
    }
    Unk05b82c_Unk_05b82c(FIELD(int,p,0x130));
    Unk05b82c_Unk_05b82c(FIELD(int,p,0x134));
}

void Unk0bcef4_Unk_0bcef4(void *record, int a, int b, int enabled);
/* 0x020ecf20 initializes the selection at +0xac and flags for mode 0 or 1.
 * Other modes only reset signed byte +0x164 to -1. */
void func_020ecf20(CaveAreaWork *p, int mode)
{
    int area, index;
    p->unk_0164=-1;
    area=func_0211708c();
    index=0;
    switch (mode) {
    case 0:
        if (area<=4) {
            index=area+1;
            Unk0bcef4_Unk_0bcef4((u8 *)p+0xac,index,index,1);
        } else {
            index=area==5 ? 5:6;
        }
        if (func_02117170()) { p->unk_0164=index; index++; }
        Unk0bcef4_Unk_0bcef4((u8 *)p+0xac,index,index,1);
        p->unk_00a8=0;
        break;
    case 1:
        if (area<=7) index=area-4;
        else if (area==8) index=1;
        p->unk_0164=index;
        Unk0bcef4_Unk_0bcef4((u8 *)p+0xac,index+1,index+1,1);
        p->unk_00a8=1;
        break;
    }
}

/* Table entries have an observed eight-byte stride. */
typedef struct CaveAreaCoordinate { int value; int adjacent; } CaveAreaCoordinate;
extern CaveAreaCoordinate data_0213c7dc[], data_0213c7e0[], data_0213c740[], data_0213c744[];
int Unk02ee5c_GetTierFromField70(void);
void func_02057df8(void);
/* 0x020edb94 selects paired coordinates from eight-byte table entries and
 * handle slot 19..21 from the tier. Tables require a valid nonnegative index. */
void func_020edb94(CaveAreaWork *p, int alternate, int index)
{
    int x,y,slot;
    u32 color;
    if (alternate==0) {
        if (index>=7) return;
        x=data_0213c7dc[index].value; y=data_0213c7e0[index].value;
    } else {
        if (index>=4) return;
        x=data_0213c740[index].value; y=data_0213c744[index].value;
    }
    switch (Unk02ee5c_GetTierFromField70()) {
    case 4: slot=19; color=0x00ffffff; break;
    case 5: slot=20; color=0xff7b63ff; break;
    default: slot=21; color=0xffffffff; break;
    }
    func_02057ddc(color);
    func_0205c748(2,((CaveAreaHandleView *)p)->handles[slot],x,y,1.0f,1.0f,0,1.0f,7);
    func_02057df8();
}
