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
/* 0x020eda18 forwards the index through table (0x25, 0). The returned
 * provider record is consumed by 0x020eb83c when creating nine text entries. */
u32 CaveArea_Unk_0eda18(u32 arg0)
{
  void *tmp1;
  tmp1 = func_020445f4(0x25,0);
  return func_0204fed8(tmp1,arg0);
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
void func_020ec330(CaveAreaWork *p);
void func_020ec704(void);
void func_020ecc24(void);
void func_020eba60(CaveAreaWork *p);
void func_020ecfe8(CaveAreaWork *p, const u32 *message);

/* 0x020eb7e0 populates a caller-owned descriptor, preserving word +8. */
void func_020eb7e0(CaveAreaCallbacks *p)
{
    p->size = 360;
    p->enabled = 1;
    p->callbacks[0] = func_020ebb14;
    p->callbacks[1] = (void (*)(void))func_020ec330;
    p->callbacks[2] = func_020ec704;
    p->callbacks[3] = func_020ecc24;
    p->callbacks[4] = (void (*)(void))func_020eba60;
    p->callbacks[5] = (void (*)(void))func_020ecfe8;
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

/* 0x020ec4a8 submits flag 0x80 and the supplied word in slot seven.
 * The second argument is passed by 0x020ec330 but is unused by this callee. */
void func_020ec4a8(u32 value, int enabled)
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
 * Other modes only reset signed byte +0x164 to -1. See DEC-023 for the
 * lifetime pragma that keeps the original single r4 index range. */
#pragma push
#pragma opt_lifetimes off
void func_020ecf20(CaveAreaWork *p, int mode)
{
    int index, area;
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
#pragma pop

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

/* Borrowed prefix used by the marker loops; count and selection are signed. */
typedef struct CaveAreaMarkerView {
    u32 handle;
    u8 pad_0004[80];
    u32 marker;
    u8 pad_0058[80];
    u8 alternate;
    u8 pad_00a9[7];
    int count;
    u8 pad_00b4[8];
    int selected;
} CaveAreaMarkerView;
extern CaveAreaCoordinate data_0213c7a4[], data_0213c760[];
void func_02057eb8(int value);
void func_0205de40(int mode, u32 handle, int frame, int x, int y,
                  float sx, float sy, int zero, float scale, int layer);
/* 0x020ed800 walks the normal coordinate table, stopping at the signed sentinel
 * index. Each marker borrows provider handles for the duration of its calls. */
void func_020ed800(CaveAreaWork *p)
{
    int selected = p->unk_00bc;
    int i;
    for (i=0; i<((CaveAreaMarkerView *)p)->count; i++) {
        int y,x;
        if (i==p->unk_0164) return;
        func_02057eb8(3);
        if (i==selected) {
            y=data_0213c7a4[i].adjacent;
            x=data_0213c7a4[i].value;
            func_0205c748(2,((CaveAreaMarkerView *)p)->marker,x,y,1.0f,1.0f,0,1.0f,7);
            func_0205de40(2,p->unk_0000,16,x,y,1.0f,1.0f,0,1.0f,7);
            func_020edb94(p,p->unk_00a8,i);
        }
    }
}
/* 0x020ed8f4 performs the same marker traversal using the alternate table. */
void func_020ed8f4(CaveAreaWork *p)
{
    int selected = p->unk_00bc;
    int i;
    for (i=0; i<((CaveAreaMarkerView *)p)->count; i++) {
        int y,x;
        if (i==p->unk_0164) return;
        func_02057eb8(3);
        if (i==selected) {
            y=data_0213c760[i].adjacent;
            x=data_0213c760[i].value;
            func_0205c748(2,((CaveAreaMarkerView *)p)->marker,x,y,1.0f,1.0f,0,1.0f,7);
            func_0205de40(2,p->unk_0000,16,x,y,1.0f,1.0f,0,1.0f,7);
            func_020edb94(p,p->unk_00a8,i);
        }
    }
}

/* Caller-owned sixteen-byte animation state, as initialized by InitParams. */
typedef struct CaveAreaMotion { float position, timer; int offset, extent; } CaveAreaMotion;
/* 0x020ed634 decays position and timer, then derives integer drawing extents.
 * The original float-to-integer truncation is retained at each boundary. */
void func_020ed634(CaveAreaMotion *p)
{
    if ((int)p->timer==0) {
        p->position-=0.5f;
        if (p->position<=0.0f) { p->position=0.0f; p->timer=24.0f; }
    } else {
        if (p->timer>8.0f) p->timer-=0.48f;
        else p->timer-=1.0f;
    }
    if (p->position>80.0f) {
        p->extent=96-(int)p->position;
        p->offset=0;
    } else if (0.0f==p->position) {
        if (p->timer>=8.0f) {
            p->extent=(int)p->timer-8;
            p->offset=16-((int)p->timer-8);
        } else if ((int)p->timer==0) {
            p->position=96.0f;
            p->extent=0;
            p->offset=0;
        }
    } else { p->extent=16; p->offset=0; }
}

void func_020bcc7c(void *selection);
void func_020bccec(void *selection);
int Unk116598_Unk_11727c(int alternate, int index);
/* 0x020ec330 dispatches input only in states 3 and 9. The selection provider
 * borrows the embedded record at +0xac; transitions follow the ARM branches. */
void func_020ec330(CaveAreaWork *p)
{
    int selected=p->unk_00bc;
    switch (p->unk_00c8) {
    case 3:
    switch (func_020ec28c()) {
    case 0: break;
    case 1:
        Unk0a0ce4_Unk_0a0da4(0);
        func_020bcc7c((u8 *)p+0xac);
        CaveArea_Unk_0edb4c(p);
        break;
    case 2:
        Unk0a0ce4_Unk_0a0da4(0);
        func_020bccec((u8 *)p+0xac);
        CaveArea_Unk_0edb4c(p);
        break;
    case 3:
        Unk0a0ce4_Unk_0a0da4(11);
        CaveArea_Unk_0ec278(p);
        break;
    case 4:
        if (selected==p->unk_0164) {
            Unk0a0ce4_Unk_0a0da4(1);
            CaveArea_Unk_0ec278(p);
        } else func_020ec440(p);
        break;
    case 5:
        Unk0a0ce4_Unk_0a0da4(2);
        p->unk_00c8=2;
        break;
    }
    break;
    case 9:
        if (FIELD(int,p,0x12c)!=0) { p->unk_00c8=8; return; }
        func_020ec4a8(Unk116598_Unk_11727c(p->unk_00a8,selected),1);
        p->unk_00c8=11;
        break;
    }
}

/* Provider-owned record prefixes; only the written halfwords are exposed. */
typedef struct CaveAreaSpan { u16 reserved, start, preserved, length; } CaveAreaSpan;
typedef struct CaveAreaFrame { u8 prefix[14]; u16 length; } CaveAreaFrame;
/* 0x020ed3fc submits four spans through frames 40, 38, and 39. Float
 * conversion signedness follows the original calls, including the u32 length. */
void func_020ed3fc(CaveAreaWork *p)
{
    CaveAreaSpan *span=func_0205e328(p->unk_0000,0,28);
    CaveAreaFrame *frame=func_0205e318(p->unk_0000,40);
    frame->length=(int)FIELD(float,p,0x98);
    span->length=(u32)FIELD(float,p,0x98);
    span->start=64-(int)FIELD(float,p,0x98);
    func_0205e048(2,p->unk_0000,frame,0,-1,1.0f,1.0f,0,FIELD(u32,p,0x104),2,1);
    span=func_0205e328(p->unk_0000,0,28);
    frame=func_0205e318(p->unk_0000,38);
    frame->length=31;
    span->length=31;
    span->start=33;
    func_0205e048(2,p->unk_0000,frame,0,(int)FIELD(float,p,0x98)-32,1.0f,1.0f,0,FIELD(u32,p,0x104),2,1);
    func_0205e048(2,p->unk_0000,frame,0,(int)FIELD(float,p,0x98),1.0f,1.0f,0,FIELD(u32,p,0x104),2,1);
    span=func_0205e328(p->unk_0000,0,28);
    frame=func_0205e318(p->unk_0000,39);
    if (FIELD(float,p,0x98)>31.0f) { frame->length=0; span->length=0; }
    else {
        frame->length=31-(int)FIELD(float,p,0x98);
        span->length=31-(int)FIELD(float,p,0x98);
    }
    span->start=33;
    func_0205e048(2,p->unk_0000,frame,0,(int)FIELD(float,p,0x98),1.0f,1.0f,0,FIELD(u32,p,0x104),2,1);
}


void Unk0cb32c_Unk_0cb57c(u32 handle);
void func_020bcfc4(void *selection, int index);
void Unk124c5c_Set_124d6c(int index, int value);
void Unk124c5c_Set_124d8c(int index, int value);
void func_020525cc(int value);
void Unk0bc1a8_Unk_0bc504(CaveAreaWork *p, int value);
/* 0x020ecfe8 handles message kinds 1 and 3, borrowing the payload after its
 * kind word. The first payload byte guards reading its optional result word. */
void func_020ecfe8(CaveAreaWork *p, const u32 *message)
{
    u32 result[1]={0};
    const u32 *payload=message+1;
    int index;
    switch (message[0]) {
    case 0: break;
    case 3:
        if (p->unk_00c8==0) {
            func_020ecf20(p,payload[2]);
            func_020ed290(p);
            FIELD(int,p,0x118)=0;
            p->unk_00ca=0;
            Unk0cb32c_Unk_0cb57c(FIELD(u32,p,0xc));
            FIELD(int,p,0x15c)=payload[4];
            func_020bcfc4((u8 *)p+0xac,payload[3]);
            CaveArea_Unk_0edb4c(p);
            switch (FIELD(int,p,0x15c)) {
            case 0:
                Unk124c5c_Set_124d6c(0,1);
                Unk124c5c_Set_124d8c(0,31);
                p->unk_00c8=1;
                break;
            case 1:
                func_020525cc(0);
                index=((CaveAreaMarkerView *)p)->count-1;
                if (func_02117170()) index--;
                func_020bcfc4((u8 *)p+0xac,index);
                p->unk_00c8=13;
                break;
            case 2:
                Unk124c5c_Set_124d6c(0,1);
                Unk124c5c_Set_124d8c(0,31);
                index=((CaveAreaMarkerView *)p)->count-1;
                if (func_02117170()) index--;
                func_020bcfc4((u8 *)p+0xac,index);
                p->unk_00c8=13;
                break;
            }
        } else if (p->unk_00c8==10) {
            if (payload!=0) {
                u32 value=payload[4];
                if (*(const u8 *)payload&8) result[0]=value;
            }
            FIELD(u32,p,0x12c)=result[0];
            p->unk_00c8=FIELD(u8,p,0xc9);
        } else if (p->unk_00c8==17) p->unk_00c8=18;
        else if (p->unk_00c8==11) {
            Unk124c5c_Set_124d6c(0,1);
            Unk124c5c_Set_124d8c(1,0);
            p->unk_00c8=21;
        }
        break;
    case 2: break;
    case 1: Unk0bc1a8_Unk_0bc504(p,0); break;
    case 4: break;
    }
}

extern u32 data_0213c780[];
extern u8 data_02150d30[], data_02150d44[], data_02150d58[];
u32 func_0205dcd4(const u8 *name, int mode);
u32 func_0205c2c4(const u8 *name);
u32 func_0205c3c0(void);
void func_0205c3fc(u32 handle, u32 parent, u32 resource);
u32 func_020629ac(int a, int b, int c, int d);
void func_02063920(u32 handle);
u32 func_02061a04(int mode, u32 record, int value);
u32 func_02063a30(u32 record);
void func_02061f10(u32 handle, int index, int x, int y, u32 value);
int func_0205ca88(u32 handle);
/* Initialization view: fields follow stores in 0x020eb83c; providers own the
 * pointed-to resources, while this work object retains their handles. */
typedef struct CaveAreaInitView {
    u32 parent[3], handles[23];
    u8 gap_0068[28];
    u32 text;
    CaveAreaMotion motion;
    u32 secondary[4];
    u8 alternate, pad_00a9[3];
    u32 selection[7];
    u8 state, previous, flag, pad_00cb;
    int x[7]; float alpha[7];
    u32 depth; float scale; u32 zero_010c, zero_0110;
    int scroll, zero_0118, frames; float step, zero_0124, phase;
    u32 result, first, second, entries[9], mode, enabled;
    s8 sentinel;
} CaveAreaInitView;
/* 0x020eb83c allocates parent/row/text resources, initializes nine text entries,
 * and establishes the observed animation, selection, and state defaults. */
void func_020eb83c(CaveAreaWork *p)
{
    CaveAreaInitView *w=(CaveAreaInitView *)p;
    int i;
    data_02176de0=(u32)p;
    for (i=0;(u32)i<9;i++) Unk05b82c_Unk_05b82c(data_0213c780[i]);
    w->parent[1]=func_0205dcd4(data_02150d30,0);
    w->parent[0]=func_0205dcd4(data_02150d44,1);
    w->parent[2]=func_0205c2c4(data_02150d58);
    for (i=0;i<23;i++) {
        w->handles[i]=func_0205c3c0();
        func_0205c3fc(w->handles[i],w->parent[0],w->parent[2]);
    }
    w->text=func_020629ac(4,4,1,1);
    func_02063920(w->text);
    for (i=0;i<9;i++) {
        u32 entry=CaveArea_Unk_0eda18((u16)i);
        w->entries[i]=func_02061a04(1,entry,0);
        func_02061f10(w->text,-1,0,0,func_02063a30(entry));
    }
    Unk0bcef4_Unk_0bcef4(w->selection,7,7,1);
    w->flag=0;
    w->alternate=0;
    for (i=0;i<7;i++) { w->x[i]=-107; w->alpha[i]=0.0f; }
    w->scroll=0;
    w->zero_0118=0;
    w->depth=0;
    w->scale=1.0f;
    w->zero_0110=0;
    w->zero_010c=0;
    w->phase=0.0f;
    w->zero_0124=0.0f;
    w->first=103;
    w->second=112;
    w->mode=0;
    CaveArea_InitParams((float *)&w->motion);
    CaveArea_Unk_0ed3b4(w->secondary);
    func_0205caa8(w->handles[22],2);
    w->frames=func_0205ca88(w->handles[22])-1;
    w->step=1.0f/(float)w->frames;
    func_0205caa8(w->handles[19],21);
    func_0205caa8(w->handles[20],22);
    func_0205caa8(w->handles[21],23);
    func_0205caa8(w->handles[18],20);
    w->state=0;
    w->previous=0;
    w->enabled=0;
    w->sentinel=-1;
}
