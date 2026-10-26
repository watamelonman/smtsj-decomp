#include "types.h"

/** Partial unit layout; unnamed fields retain their observed byte offsets. */
typedef struct Unit0ca69c {
    u32 unk_0000;
    u8 unk_0004[0x3e0];
    u8 unk_03e4[0x709c];
    s8 unk_7480;
    s8 unk_7481;
    s8 unk_7482;
    s8 unk_7483;
    int unk_7484;
} Unit0ca69c;

/** Cell metadata returned by the map lookups; upper flag bits are preserved. */
typedef struct Cell0ca69c {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u32 unk_04;
} Cell0ca69c;

/** Partial work-area layout used for the current map and coordinates. */
typedef struct Work0ca69c {
    u8 pad_0000[0x358];
    u32 unk_0358;
    u16 unk_035c;
    u8 pad_035e[6];
    s8 unk_0364;
    s8 unk_0365;
} Work0ca69c;

extern int func_020654cc(void);
extern int func_02098860(int);
extern void func_0206597c(int);
extern int func_02065cd0(void);
extern void func_02065c58(void);
extern void *Unk02f2a8_Unk_034970(void *, int, int);
extern void *Unk02f2a8_Unk_0349c4(void *, int, int);
extern Cell0ca69c *Unk038fbc_Unk_039160(void *, int, int);
extern Cell0ca69c *Unk038fbc_GetElement(void *, int, int);
extern int func_020987ac(int, int);
extern void func_02034dd0(void);
extern int Unk0e651c_Get2Bits(void *, int);
extern void Unk0e651c_Set2Bits(void *, int, int);
extern int Unk04bb9c_GetCtxUnka20(void);
extern Work0ca69c *Unk02e000_GetWorkArea(void);
extern void func_0204c698(int, s16, s16);
extern void func_02065bc0(void);
extern void func_0204c4cc(s16, s16);
extern void ScanVisor_Unk_0a2ab0(void);
extern int ScanVisor_GetConst20(void);
extern int func_020a03cc(void);
extern int Unk0a23f4_Unk_0a2490(void);
extern int Unk0a23f4_Unk_0a2448(void);
extern Cell0ca69c *Unk02f2a8_GetCurrentCell38e8(void);
extern void Unk09a268_Unk_09a80c(Cell0ca69c *, int);
extern void Unk09a268_Unk_09a830(Cell0ca69c *, int);
extern void Unk09a268_Unk_09a870(Cell0ca69c *, int);
extern void Unk09a268_SetOnlyBit(Cell0ca69c *, int);
extern int Unk09a268_Unk_09a844(Cell0ca69c *);
extern u8 *Unk0392f8_Unk_0394b8(void *, int, int);
extern int func_0209c4e0(void);
extern int func_02052728(void);
extern void func_02034e90(void);
extern void func_0204c5f8(s16, s16);
extern void func_0204c780(s16, s16);
extern void func_0204faf0(int, int);
extern void func_0205264c(int, int, int, int, int);
extern void ScanVisor_Unk_0a2b7c(void);
extern void ScanVisor_Unk_0a2920(int);
extern void GameState_ClearRootUnk60(void);
extern int func_020ca6b0(Unit0ca69c *);

/** Returns the observed 0x6200-relative offset; semantic identity is unknown. */
int Unk0ca69c_Unk_0ca69c(int arg0)
{
    return arg0 + 0x6200;
}

/** Converts an index to the observed 128-byte stride after a 0xc5 bias. */
int Unk0ca69c_Unk_0ca6a4(int arg0)
{
    return (arg0 + 0xc5) * 0x80;
}

/** Advances the three-stage sequence at 0x7481; returns one when finished. */
int func_020cab28(Unit0ca69c *p)
{
    int done = 0;
    switch (p->unk_7481) {
    case 0:
        if (func_020654cc() == 1) {
            if (func_02098860(5) == 1) {
                func_0206597c(11);
            } else {
                func_0206597c(41);
            }
            p->unk_7481++;
        }
        break;
    case 1:
        if (func_02065cd0() == 1) {
            func_02065c58();
            p->unk_7481++;
        }
        break;
    case 2:
        if (func_020654cc() == 1) done = 1;
        break;
    default:
        done = 1;
        break;
    }
    return done;
}

/** Updates the selected cell's two-bit state for metadata kinds 26 and 27. */
int func_020cad5c(Unit0ca69c *p)
{
    int y = p->unk_7483;
    int x = p->unk_7482;
    Cell0ca69c *cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(p->unk_0004, x, y), x, y);
    Cell0ca69c *data = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(p->unk_0004, p->unk_7482, p->unk_7483), 8, cell->unk_01);
    if (cell->unk_00 != 26 && cell->unk_00 != 27) return 0;
    if (func_020987ac(5, ((data->unk_04 << 24) >> 28) + 1) == 1) {
        p->unk_7480 = 1;
        func_02034dd0();
    } else {
        p->unk_7480 = 0;
        if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(p->unk_0004, p->unk_7482, p->unk_7483), data->unk_00) < 1) {
            Unk0e651c_Set2Bits(Unk02f2a8_Unk_0349c4(p->unk_0004, p->unk_7482, p->unk_7483), data->unk_00, 1);
        }
        if (Unk04bb9c_GetCtxUnka20() == Unk02e000_GetWorkArea()->unk_035c) {
            func_0204c698(23, p->unk_7482, p->unk_7483);
        }
        func_02065bc0();
    }
    return 1;
}

/** Dispatches the sequence selected by the signed flag at offset 0x7480. */
int Unk0ca69c_Unk_0cae84(Unit0ca69c *p)
{
    if (p->unk_7480 == 1) return func_020ca6b0(p);
    return func_020cab28(p);
}

/** Examines the adjacent cell in the work area's direction and updates its state. */
int func_020cabe4(Unit0ca69c *p)
{
    int done = 0;
    int x = Unk02e000_GetWorkArea()->unk_0364;
    int y = Unk02e000_GetWorkArea()->unk_0365;
    Cell0ca69c *cell;
    Cell0ca69c *data;
    u32 state;
    switch (Unk02e000_GetWorkArea()->unk_0358) {
    case 1: x++; break;
    case 2: y++; break;
    case 3: x--; break;
    case 0: y--; break;
    }
    cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(p->unk_0004, x, y), x, y);
    if (cell != 0 && (u8)(cell->unk_00 + 230) <= 1) {
        data = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(p->unk_0004, x, y), 8, cell->unk_01);
        if (func_020987ac(5, ((data->unk_04 << 24) >> 28) + 1) == 1) {
            state = Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(p->unk_0004, x, y), data->unk_00);
            if (state != 3) {
                if (state < 2) {
                    Unk0e651c_Set2Bits(Unk02f2a8_Unk_0349c4(p->unk_0004, x, y), data->unk_00, 2);
                    ScanVisor_Unk_0a2ab0();
                    if (Unk04bb9c_GetCtxUnka20() == Unk02e000_GetWorkArea()->unk_035c) {
                        func_0204c4cc(x, y);
                        func_0204c698(23, x, y);
                    }
                }
                done = 1;
            }
        }
    }
    return done;
}

/** Advances the selected-cell sequence, including its timeout state 100. */
int func_020ca6b0(Unit0ca69c *p)
{
    int y = p->unk_7483;
    int x = p->unk_7482;
    Cell0ca69c *cell = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(p->unk_0004, x, y), x, y);
    Cell0ca69c *data = Unk038fbc_GetElement(Unk02f2a8_Unk_034970(p->unk_0004, p->unk_7482, p->unk_7483), 8, cell->unk_01);
    int done = 0;
    u8 *entry;
    switch (p->unk_7481) {
    case 0:
        p->unk_7484++;
        if (ScanVisor_GetConst20() < p->unk_7484 && func_020a03cc() == 1) {
            p->unk_7484 = 0;
            p->unk_7481 = 100;
            break;
        }
        if (Unk0a23f4_Unk_0a2490() == 1) {
            cell = Unk02f2a8_GetCurrentCell38e8();
            Unk09a268_Unk_09a80c(cell, 1);
            Unk09a268_Unk_09a830(cell, 0);
            Unk09a268_SetOnlyBit(cell, 0);
            cell->unk_01 = 1;
            cell->unk_02 = 0;
            p->unk_7481++;
        }
        break;
    case 1:
        if (func_020a03cc() == 1) {
            p->unk_7481 = 100;
            break;
        }
        cell = Unk02f2a8_GetCurrentCell38e8();
        cell->unk_02++;
        if (Unk09a268_Unk_09a844(cell) == 1) {
            entry = Unk0392f8_Unk_0394b8(p->unk_03e4, p->unk_7482, p->unk_7483);
            if (func_0209c4e0() == 1) {
                *entry = 1;
                Unk09a268_Unk_09a80c(cell, 0);
                Unk09a268_Unk_09a830(cell, 0);
                Unk09a268_Unk_09a870(cell, 0);
                Unk09a268_SetOnlyBit(cell, 0);
                cell->unk_01 = 0;
                cell->unk_02 = 0;
            } else {
                Unk09a268_Unk_09a80c(cell, 1);
                Unk09a268_Unk_09a830(cell, 1);
                Unk09a268_Unk_09a870(cell, 0);
                Unk09a268_SetOnlyBit(cell, 0);
                cell->unk_01 = 2;
                cell->unk_02 = 0;
            }
            p->unk_7481++;
        }
        break;
    case 2:
        if (func_020a03cc() == 1) {
            p->unk_7481 = 100;
            break;
        }
        if (Unk0a23f4_Unk_0a2448() == 0) p->unk_7481++;
        break;
    case 3:
        if (func_02052728() == 0) {
            func_02034e90();
            Unk0e651c_Set2Bits(Unk02f2a8_Unk_0349c4(p->unk_0004, p->unk_7482, p->unk_7483), data->unk_00, 3);
            func_0204c5f8(p->unk_7482, p->unk_7483);
            if (Unk04bb9c_GetCtxUnka20() == Unk02e000_GetWorkArea()->unk_035c) {
                func_0204c780(p->unk_7482, p->unk_7483);
            }
            func_02065bc0();
            p->unk_7481++;
        }
        break;
    case 4:
        if (func_020654cc() == 1) {
            func_0204faf0(1, ((data->unk_04 << 24) >> 28) + 1);
            func_0206597c(5);
            p->unk_7481++;
        }
        break;
    case 5:
        if (func_02065cd0() == 1) {
            func_02065c58();
            p->unk_7481++;
        }
        break;
    case 6:
        if (func_020654cc() == 1) done = 1;
        break;
    case 100:
        func_0205264c(2, 4, 31, 1, 2);
        ScanVisor_Unk_0a2b7c();
        ScanVisor_Unk_0a2920(1);
        GameState_ClearRootUnk60();
        cell = Unk02f2a8_GetCurrentCell38e8();
        entry = Unk0392f8_Unk_0394b8(p->unk_03e4, p->unk_7482, p->unk_7483);
        if (func_0209c4e0() == 1) {
            *entry = 1;
            Unk09a268_Unk_09a80c(cell, 0);
            Unk09a268_Unk_09a830(cell, 0);
            Unk09a268_Unk_09a870(cell, 0);
            Unk09a268_SetOnlyBit(cell, 0);
            cell->unk_01 = 0;
            cell->unk_02 = 0;
        } else {
            Unk09a268_Unk_09a80c(cell, 1);
            Unk09a268_Unk_09a830(cell, 1);
            Unk09a268_Unk_09a870(cell, 0);
            Unk09a268_SetOnlyBit(cell, 0);
            cell->unk_01 = 2;
            cell->unk_02 = 0;
        }
        p->unk_7481 = 3;
        break;
    default:
        done = 1;
        break;
    }
    return done;
}
