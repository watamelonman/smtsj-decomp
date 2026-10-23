TU = 'src/CampStatus.c'
FIX = [
("""    u8 pad_01a4[0x4];""", """    u32 unk_01a4;               /* +0x1a4: when set, func_020d5d44 skips one frame */"""),
("""void func_020bc9f4(u32 a, u32 b);
void func_020bcacc(u32 a, u32 b);""", """/* Request block sent with func_020bc9f4 / func_020bcacc (same layout as unit_020e1648's). */
typedef struct CampStatusRequest {
    u8 flags[2];
    u8 pad_0002[2];
    u32 values[16];
} CampStatusRequest;
void func_020bc9f4(u32 kind, CampStatusRequest *req);
void func_020bcacc(u32 kind, CampStatusRequest *req);"""),
]
SPECS = [(TU, [
('func_020d5d44', '''/* Handler 0x10 of the CampStatus_Unk_0d3624 table: per-frame input. With unk_00e8 set, move
 * the 3x2 cursor unk_00f0 (keys 0x40/0x80 change rows except in modes 1 and 18, 0x20/0x10
 * columns) and confirm with 0x800 or 2; otherwise (unk_01a0 and unk_00f8 set) move between the
 * two columns of the record and confirm with 0x400 or 2. */
void func_020d5d44(CampStatusWork *work)
{
    CampStatusRequest req;
    u32 ids[6];
    s8 old;
    s32 i;
    u32 n;
    if (work->unk_00f4 == 0) {
        return;
    }
    if (work->unk_01a4 != 0) {
        work->unk_01a4 = 0;
        return;
    }
    if (work->unk_00e8 != 0) {
        old = work->unk_00f0;
        if (work->unk_0000 != 1 && work->unk_0000 != 18) {
            if (func_02053824(0, 0x40)) {
                work->unk_00f0 -= 3;
                if (work->unk_00f0 < 0) {
                    work->unk_00f0 += 6;
                }
            } else if (func_02053824(0, 0x80)) {
                work->unk_00f0 += 3;
                if (work->unk_00f0 > 5) {
                    work->unk_00f0 -= 6;
                }
            }
        }
        if (func_02053824(0, 0x20)) {
            work->unk_00f0--;
            if (work->unk_00f0 < 0 || work->unk_00f0 == 2) {
                work->unk_00f0 += 3;
            }
        } else if (func_02053824(0, 0x10)) {
            work->unk_00f0++;
            if (work->unk_00f0 == 3 || work->unk_00f0 == 6) {
                work->unk_00f0 -= 3;
            }
        }
        if (old != work->unk_00f0) {
            work->unk_0008 = 1;
            CampStatus_Unk_0dbf6c(work);
            Unk0a0ce4_Unk_0a0da4(0);
            return;
        }
        if (func_02053800(0, 0x800) == 0 && func_02053800(0, 2) == 0) {
            return;
        }
        for (i = 0; i < 2; i++) {
            req.flags[i] = 0;
        }
        for (i = 0; i < 16; i++) {
            req.values[i] = 0;
        }
        req.values[0] = 3;
        req.flags[0] |= 1;
        work->unk_00e8 = 0;
        func_020bc9f4(3, &req);
        func_020bcacc(work->unk_0014, &req);
        work->unk_0004 = 0;
        CampStatus_Unk_0db548(work);
        work->unk_0004 = 1;
        Unk0a0ce4_Unk_0a0da4(10);
        if (work->unk_0268 != 0) {
            Unk065e88_SetFlag3a(work->unk_0024[21], 1);
        }
        if (Unk0e8228_IsSet_data_02176cdc() == 0) {
            return;
        }
        if (Unk0e7ac4_Unk_0e8060() != 0) {
            return;
        }
        Unk0e7ac4_Unk_0e8198();
        return;
    }
    if (work->unk_01a0 == 0 || work->unk_00f8 == 0) {
        return;
    }
    old = work->unk_00f0;
    if (func_02053824(0, 0x20)) {
        work->unk_00f0--;
        if (work->unk_00f0 < 0 || work->unk_00f0 == 2) {
            work->unk_00f0 += 3;
        }
    } else if (func_02053824(0, 0x10)) {
        work->unk_00f0++;
        if (work->unk_00f0 == 3 || work->unk_00f0 == 6) {
            work->unk_00f0 -= 3;
        }
    }
    if (old != work->unk_00f0) {
        work->unk_0008 = 1;
        CampStatus_Unk_0dc540(work);
        Unk0a0ce4_Unk_0a0da4(0);
        return;
    }
    if (func_02053800(0, 0x400) == 0 && func_02053800(0, 2) == 0) {
        return;
    }
    work->unk_01a0 = 0;
    work->unk_00f8 = 0;
    work->unk_010c = 60;
    func_02008644(0, work->unk_00dc, 12);
    if (func_020a18c8(work->unk_00da, work->unk_00dc, 6) != 0) {
        for (n = 0; n < 6; n++) {
            if (work->unk_00dc[n] == 0) {
                break;
            }
            ids[n] = work->unk_00dc[n];
        }
        CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, n);
    }
    CampStatus_Unk_0dba84(work, work->unk_00da);
    Unk0a0ce4_Unk_0a0da4(10);
    Unk0e7ac4_Unk_0e8198();
}'''),
], '''int func_02053824(u32 player, u32 mask);
int func_02053800(u32 player, u32 mask);
void Unk0a0ce4_Unk_0a0da4(u32 se);
int Unk0e8228_IsSet_data_02176cdc(void);
int Unk0e7ac4_Unk_0e8060(void);
void Unk0e7ac4_Unk_0e8198(void);
void CampStatus_Unk_0dbf6c(CampStatusWork *work);
void CampStatus_Unk_0dc540(CampStatusWork *work);
void CampStatus_Unk_0db548(CampStatusWork *work);
void CampStatus_Unk_0dba84(CampStatusWork *work, u16 id);''', FIX)]
