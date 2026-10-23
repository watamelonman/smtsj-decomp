TU = 'src/CampStatus.c'
FIX = [
("void func_020dab5c(CampStatusWork *work, s32 cur, s32 next, s32 add, s32 row, u32 arg5);", "void func_020dab5c(CampStatusWork *work, s16 cur, s32 next, s32 add, u8 row, u32 mode);"),
("""    u32 unk_000c;
    u8 pad_0010[0x4];
    u32 unk_0014;""", """    u32 unk_000c;
    s32 unk_0010;               /* +0x10: frame counter for the blinking bar segments */
    u32 unk_0014;"""),
("""    s16 unk_0118[10];""", """    s16 unk_0118[10];           /* +0x118: animated bar lengths: [row] current, [row + 5] target */"""),
]
SPECS = [(TU, [
('func_020dab5c', '''/* Draw one stat row (row 0-4, 11 px apart): label frame 20, the value next in the compare colour,
 * and its bar. While unk_0114 is clear the bar animates towards cur/next (steps of a fifth of the
 * distance, at least 3); afterwards mode 2 shows the gain add blinking, mode 3 and the default
 * show the change with an arrow (resource 0x1f00). */
void func_020dab5c(CampStatusWork *work, s16 cur, s32 next, s32 add, u8 row, u32 mode)
{
    char *width = func_020a9e14(1, data_021507ec);
    s32 y = row * 11;
    func_0205dee8(2, work->unk_0018, 20, 0, y, 1.0f, 1.0f, 0, 1.0f, 4);
    CampStatus_Unk_0db3e0(cur, next, add, mode);
    func_020a9fd8(1, 17, y + 84, 2, width, 10, data_021507f0, next);
    func_02057df8();
    if (work->unk_0114 == 0) {
        if (work->unk_0118[row] < cur) {
            if (cur > 15) {
                work->unk_0118[row] += cur / 5;
            } else {
                work->unk_0118[row] += 3;
            }
            if (work->unk_0118[row] >= cur) {
                work->unk_0118[row] = cur;
                work->unk_0118[row + 5] = cur;
            }
        } else if (next > cur) {
            if (work->unk_0118[row + 5] < next) {
                s32 d = next - cur;
                if (d > 15) {
                    work->unk_0118[row + 5] += d / 5;
                } else {
                    work->unk_0118[row + 5] += 3;
                }
                if (work->unk_0118[row + 5] > next) {
                    work->unk_0118[row + 5] = next;
                }
            }
            func_02058f10(2, 0x1dba, work->unk_0118[row], y, work->unk_0118[row + 5] - work->unk_0118[row], 5, 5);
        } else if (next < cur) {
            if (work->unk_0118[row + 5] > next) {
                s32 d = cur - next;
                if (d > 15) {
                    work->unk_0118[row + 5] -= d / 5;
                } else {
                    work->unk_0118[row + 5] -= 3;
                }
                if (work->unk_0118[row + 5] < next) {
                    work->unk_0118[row + 5] = next;
                }
            }
            func_02058f10(2, 0x1dbb, work->unk_0118[row + 5], y, work->unk_0118[row] - work->unk_0118[row + 5], 5, 5);
        }
        func_02058f10(2, 0x1db9, 0, y, work->unk_0118[row], 5, 4);
        return;
    }
    if (mode == 2) {
        if (next > cur) {
            func_02058f10(2, 0x1db9, 0, row * 11, cur - add, 5, 4);
            func_02058f10(2, 0x1dba, cur, row * 11, next - cur, 5, 4);
        } else if (next < cur) {
            func_02058f10(2, 0x1db9, 0, row * 11, next - add, 5, 4);
            func_02058f10(2, 0x1dbb, next, row * 11, cur - next, 5, 4);
        } else {
            func_02058f10(2, 0x1db9, 0, y, cur - add, 5, 4);
        }
        if (add <= 0) {
            return;
        }
        func_02057e18(CampStatus_Unk_0db2dc(work->unk_0010));
        if (next < cur) {
            func_02058f10(2, 0x1dbc, next - add, y, add, 5, 5);
        } else {
            func_02058f10(2, 0x1dbc, cur - add, y, add, 5, 5);
        }
        func_02057e18(31);
        return;
    }
    if (mode == 3) {
        if (next > add) {
            func_02058f10(2, 0x1db9, 0, row * 11, add, 5, 4);
            func_02058f10(2, 0x1dba, add, row * 11, next - add, 5, 4);
        } else if (next < add) {
            func_02058f10(2, 0x1db9, 0, row * 11, next, 5, 4);
            func_02058f10(2, 0x1dbb, next, row * 11, add - next, 5, 4);
        } else {
            func_02058f10(2, 0x1db9, 0, y, add, 5, 4);
        }
        func_02057fd8();
        func_02057e18(CampStatus_Unk_0db214(work->unk_0010));
        func_02058e9c(2, 0x1f00, next, y, 1.0f, 0, 5);
        func_02057e18(31);
        return;
    }
    if (next > cur) {
        func_02058f10(2, 0x1db9, 0, row * 11, cur, 5, 4);
        func_02058f10(2, 0x1dba, cur, row * 11, next - cur, 5, 4);
    } else if (next < cur) {
        func_02058f10(2, 0x1db9, 0, row * 11, next, 5, 4);
        func_02058f10(2, 0x1dbb, next, row * 11, cur - next, 5, 4);
    } else {
        func_02058f10(2, 0x1db9, 0, y, cur, 5, 4);
    }
    func_02057fd8();
    func_02057e18(CampStatus_Unk_0db214(work->unk_0010));
    func_02058e9c(2, 0x1f00, next, y, 1.0f, 0, 5);
    func_02057e18(31);
}'''),
], '''extern char data_021507ec[];
extern char data_021507f0[];
u8 CampStatus_Unk_0db214(s32 t);
u8 CampStatus_Unk_0db2dc(s32 t);''', FIX)]
