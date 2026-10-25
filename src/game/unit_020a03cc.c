#include "types.h"

/* Borrowed context; offsets are established by the ARM loads/stores in this unit. */
typedef struct Unk0a03ccContext {
    u32 unk_0000;
    u8 unk_0004[0x354];
    u8 unk_0358[0x8c];
    u8 unk_03e4[0x709c];
    s8 unk_7480;
    s8 unk_7481;
    s8 unk_7482;
    s8 unk_7483;
    s32 unk_7484;
} Unk0a03ccContext;

/* Sixteen-byte records in each of two adjacent tables. */
typedef struct Unk0a03ccRecord {
    u8 pad_0000[14];
    u8 unk_000e;
    u8 unk_000f;
} Unk0a03ccRecord;
typedef struct Unk0a03ccTables {
    Unk0a03ccRecord first[16];
    Unk0a03ccRecord second[16];
} Unk0a03ccTables;

int func_02053800(int a, int b);
int ScanVisor_Unk_0a2b58(void);
Unk0a03ccTables *Unk02e000_Unk_02e8b8(void);
void ScanVisor_Unk_0a2a8c(int value);
int func_020654cc(void);
int func_02098860(int value);
void func_0206597c(int value);
int func_02065cd0(void);
void func_02065c58(void);
int func_020a0450(Unk0a03ccContext *ctx);

/* ARM 020a03cc: accept only when both queries return exactly one. */
int func_020a03cc(void)
{
    if (func_02053800(0, 3) == 1) {
        if (ScanVisor_Unk_0a2b58() == 1) {
            return 1;
        }
    }
    return 0;
}

/* ARM 020a03fc: clear byte 14 of the first table and byte 15 of the second;
 * both 16-entry tables remain owned by the work-area provider. */
void func_020a03fc(void)
{
    Unk0a03ccTables *tables = Unk02e000_Unk_02e8b8();
    int i;
    ScanVisor_Unk_0a2a8c(1);
    for (i = 0; i < 16; i++) {
        tables->first[i].unk_000e = 0;
    }
    ScanVisor_Unk_0a2a8c(0);
    for (i = 0; i < 16; i++) {
        tables->second[i].unk_000f = 0;
    }
}

/* ARM 020a0924: advance the signed-byte substate after asynchronous queries;
 * returns one on completion or on an unrecognised substate. */
int func_020a0924(Unk0a03ccContext *ctx)
{
    int done = 0;
    switch (ctx->unk_7481) {
    case 0:
        if (func_020654cc() == 1) {
            if (func_02098860(2) == 1) {
                func_0206597c(10);
            } else {
                func_0206597c(40);
            }
            ctx->unk_7481++;
        }
        break;
    case 1:
        if (func_02065cd0() == 1) {
            func_02065c58();
            ctx->unk_7481++;
        }
        break;
    case 2:
        if (func_020654cc() == 1) {
            done = 1;
        }
        break;
    default:
        done = 1;
        break;
    }
    return done;
}

/* ARM 020a0cc0: dispatch using the signed mode byte at context+7480. */
int func_020a0cc0(Unk0a03ccContext *ctx)
{
    if (ctx->unk_7480 == 1) {
        return func_020a0450(ctx);
    }
    return func_020a0924(ctx);
}

/* Four direction bits, four mode bits and an eight-bit flag index, as shown
 * by the original shifts; remaining bits are not interpreted here. */
typedef struct Unk0a03ccElement {
    u32 direction : 4;
    u32 mode : 4;
    u32 index : 8;
    u32 rest : 16;
} Unk0a03ccElement;

/* Packed record: byte zero identifies the record, byte one selects an element. */
typedef struct Unk0a03ccCell {
    u8 unk_0000;
    u8 unk_0001;
    u16 unk_0002;
    u32 unk_0004;
} Unk0a03ccCell;
/* Work fields read by the neighbour query; coordinates are signed bytes. */
typedef struct Unk0a03ccWork {
    u8 pad_0000[0x358];
    u32 unk_0358;
    u16 unk_035c;
    u8 pad_035e[6];
    s8 unk_0364;
    s8 unk_0365;
} Unk0a03ccWork;

void *Unk02f2a8_Unk_034970(void *base, int x, int y);
void *Unk02f2a8_Unk_0349c4(void *base, int x, int y);
Unk0a03ccCell *Unk038fbc_Unk_039160(void *base, int x, int y);
Unk0a03ccElement *Unk038fbc_GetElement(void *base, int type, int index);
int func_020987ac(int a, int b);
void func_02034dd0(void);
int Unk0e651c_Get2Bits(void *base, int index);
void Unk0e651c_Set2Bits(void *base, int index, int value);
int Unk04bb9c_GetCtxUnka20(void);
Unk0a03ccWork *Unk02e000_GetWorkArea(void);
void func_0204c698(int type, s16 x, s16 y);
void func_02065bc0(void);
void ScanVisor_Unk_0a2ab0(void);
void func_0204c4cc(s16 x, s16 y);

/* ARM 020a0b88: inspect record kinds 24/25 at the context coordinates,
 * latch a mode result and ensure the selected two-bit entry is at least one. */
int func_020a0b88(Unk0a03ccContext *ctx)
{
    int y = ctx->unk_7483;
    int x = ctx->unk_7482;
    Unk0a03ccCell *cell;
    Unk0a03ccElement *element;
    int area;
    cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(ctx->unk_0004, x, y), x, y);
    element = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(ctx->unk_0004, ctx->unk_7482, ctx->unk_7483), 7, cell->unk_0001);
    if (cell->unk_0000 != 24 && cell->unk_0000 != 25) {
        return 0;
    }
    if (func_020987ac(2, element->mode + 1) == 1) {
        ctx->unk_7480 = 1;
        func_02034dd0();
    } else {
        ctx->unk_7480 = 0;
        if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(ctx->unk_0004, ctx->unk_7482, ctx->unk_7483), element->index) < 1) {
            Unk0e651c_Set2Bits(Unk02f2a8_Unk_0349c4(ctx->unk_0004, ctx->unk_7482, ctx->unk_7483), element->index, 1);
        }
        area = Unk04bb9c_GetCtxUnka20();
        if (area == Unk02e000_GetWorkArea()->unk_035c) {
            func_0204c698(24, ctx->unk_7482, ctx->unk_7483);
        }
        func_02065bc0();
    }
    return 1;
}

/* ARM 020a09e0: probe the adjacent coordinate selected by work heading 0..3.
 * Matching direction bits and mode permission promote the two-bit entry to two;
 * an entry already at three is left alone. Returns one when accepted. */
int func_020a09e0(Unk0a03ccContext *ctx)
{
    int done = 0;
    int x = Unk02e000_GetWorkArea()->unk_0364;
    int y = Unk02e000_GetWorkArea()->unk_0365;
    int mask = 0;
    Unk0a03ccCell *cell;
    Unk0a03ccElement *element;
    int area;
    switch (Unk02e000_GetWorkArea()->unk_0358) {
    case 1: x++; mask = 4; break;
    case 2: y++; mask = 1; break;
    case 3: x--; mask = 8; break;
    case 0: y--; mask = 2; break;
    }
    cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(ctx->unk_0004, x, y), x, y);
    if (cell != 0) {
        if ((u8)(cell->unk_0000 + 232) <= 1) {
            element = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(ctx->unk_0004, x, y), 7, cell->unk_0001);
            if (mask & element->direction) {
                if (func_020987ac(2, element->mode + 1) == 1) {
                    u32 state = Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(ctx->unk_0004, x, y), element->index);
                    if (state != 3) {
                        if (state < 2) {
                            Unk0e651c_Set2Bits(Unk02f2a8_Unk_0349c4(ctx->unk_0004, x, y), element->index, 2);
                            ScanVisor_Unk_0a2ab0();
                            area = Unk04bb9c_GetCtxUnka20();
                            if (area == Unk02e000_GetWorkArea()->unk_035c) {
                                func_0204c4cc(x, y);
                                func_0204c698(24, x, y);
                            }
                        }
                        done = 1;
                    }
                }
            }
        }
    }
    return done;
}

int ScanVisor_GetConst20(void);
int Unk0a23f4_Unk_0a2490(void);
int Unk0a23f4_Unk_0a2448(void);
Unk0a03ccCell *Unk02f2a8_GetCurrentCell38e8(void);
void Unk09a268_Unk_09a80c(Unk0a03ccCell *cell, int value);
void Unk09a268_Unk_09a830(Unk0a03ccCell *cell, int value);
void Unk09a268_SetOnlyBit(Unk0a03ccCell *cell, int value);
int Unk09a268_Unk_09a844(Unk0a03ccCell *cell);
void Unk09a268_Unk_09a870(Unk0a03ccCell *cell, int value);
u8 *Unk0392f8_Unk_0394b8(void *base, int x, int y);
int func_0209c4e0(void);
int func_02052728(void);
void func_02034e90(void);
void func_0204c5f8(int x, int y);
void func_0204c780(int x, int y);
void func_0204faf0(int type, int mode);
void func_0205264c(int a, int b, int c, int d, int e);
void ScanVisor_Unk_0a2b7c(void);
void ScanVisor_Unk_0a2920(int value);
void GameState_ClearRootUnk60(void);

/* ARM 020a0450: advance substates 0..6 of the selected packed-record operation.
 * State 100 cancels through the task/reset helpers and rejoins state 3.
 * The caller retains the context; returns one at completion or unknown state. */
int func_020a0450(Unk0a03ccContext *ctx)
{
    int done;
    int y = ctx->unk_7483;
    int x = ctx->unk_7482;
    Unk0a03ccCell *cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(ctx->unk_0004, x, y), x, y);
    Unk0a03ccElement *element = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(ctx->unk_0004, ctx->unk_7482, ctx->unk_7483), 7, cell->unk_0001);
    done = 0;
    switch (ctx->unk_7481) {
    case 0:
        ctx->unk_7484++;
        if (ScanVisor_GetConst20() < ctx->unk_7484 && func_020a03cc() == 1) {
            ctx->unk_7484 = 0;
            ctx->unk_7481 = 100;
            break;
        }
        if (Unk0a23f4_Unk_0a2490() == 1) {
            Unk0a03ccCell *current = Unk02f2a8_GetCurrentCell38e8();
            Unk09a268_Unk_09a80c(current, 1);
            Unk09a268_Unk_09a830(current, 0);
            Unk09a268_SetOnlyBit(current, 0);
            current->unk_0001 = 1;
            current->unk_0002 = 0;
            ctx->unk_7481++;
        }
        break;
    case 1:
        if (func_020a03cc() == 1) {
            ctx->unk_7481 = 100;
            break;
        }
        {
            Unk0a03ccCell *current = Unk02f2a8_GetCurrentCell38e8();
            current->unk_0002++;
            if (Unk09a268_Unk_09a844(current) == 1) {
                u8 *entry = Unk0392f8_Unk_0394b8(ctx->unk_03e4, ctx->unk_7482, ctx->unk_7483);
                if (func_0209c4e0() == 1) {
                    *entry = 1;
                    Unk09a268_Unk_09a80c(current, 0);
                    Unk09a268_Unk_09a830(current, 0);
                    Unk09a268_Unk_09a870(current, 0);
                    Unk09a268_SetOnlyBit(current, 0);
                    current->unk_0001 = 0;
                    current->unk_0002 = 0;
                } else {
                    Unk09a268_Unk_09a80c(current, 1);
                    Unk09a268_Unk_09a830(current, 1);
                    Unk09a268_Unk_09a870(current, 0);
                    Unk09a268_SetOnlyBit(current, 0);
                    current->unk_0001 = 2;
                    current->unk_0002 = 0;
                }
                ctx->unk_7481++;
            }
        }
        break;
    case 2:
        if (func_020a03cc() == 1) {
            ctx->unk_7481 = 100;
            break;
        }
        if (Unk0a23f4_Unk_0a2448() == 0) {
            ctx->unk_7481++;
        }
        break;
    case 3:
        if (func_02052728() == 0) {
            int area;
            func_02034e90();
            Unk0e651c_Set2Bits(Unk02f2a8_Unk_0349c4(ctx->unk_0004, ctx->unk_7482, ctx->unk_7483), element->index, 3);
            func_0204c5f8(ctx->unk_7482, ctx->unk_7483);
            area = Unk04bb9c_GetCtxUnka20();
            if (area == Unk02e000_GetWorkArea()->unk_035c) {
                func_0204c780(ctx->unk_7482, ctx->unk_7483);
            }
            area = Unk04bb9c_GetCtxUnka20();
            if (area == Unk02e000_GetWorkArea()->unk_035c) {
                Unk0a03ccCell *target = Unk038fbc_Unk_039160(ctx->unk_0358, ctx->unk_7482, ctx->unk_7483);
                if (target != 0) {
                    if ((u8)(target->unk_0000 + 232) <= 1) {
                        target->unk_0004 |= 0x1000000;
                    }
                }
            }
            func_02065bc0();
            ctx->unk_7481++;
        }
        break;
    case 4:
        if (func_020654cc() == 1) {
            func_0204faf0(1, element->mode + 1);
            func_0206597c(4);
            ctx->unk_7481++;
        }
        break;
    case 5:
        if (func_02065cd0() == 1) {
            func_02065c58();
            ctx->unk_7481++;
        }
        break;
    case 6:
        if (func_020654cc() == 1) {
            done = 1;
        }
        break;
    case 100:
        {
            Unk0a03ccCell *current;
            u8 *entry;
            func_0205264c(2, 4, 31, 1, 2);
            ScanVisor_Unk_0a2b7c();
            ScanVisor_Unk_0a2920(1);
            GameState_ClearRootUnk60();
            current = Unk02f2a8_GetCurrentCell38e8();
            entry = Unk0392f8_Unk_0394b8(ctx->unk_03e4, ctx->unk_7482, ctx->unk_7483);
            if (func_0209c4e0() == 1) {
                *entry = 1;
                Unk09a268_Unk_09a80c(current, 0);
                Unk09a268_Unk_09a830(current, 0);
                Unk09a268_Unk_09a870(current, 0);
                Unk09a268_SetOnlyBit(current, 0);
                current->unk_0001 = 0;
                current->unk_0002 = 0;
            } else {
                Unk09a268_Unk_09a80c(current, 1);
                Unk09a268_Unk_09a830(current, 1);
                Unk09a268_Unk_09a870(current, 0);
                Unk09a268_SetOnlyBit(current, 0);
                current->unk_0001 = 2;
                current->unk_0002 = 0;
            }
            ctx->unk_7481 = 3;
        }
        break;
    default:
        done = 1;
        break;
    }
    return done;
}
