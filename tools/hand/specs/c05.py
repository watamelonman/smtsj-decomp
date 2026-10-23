TU = 'src/CampStatus.c'
FIX = [
("""    u8 unk_00d2[0x8];           /* +0xd2: passed to func_020da710; size from the next field */""",
 """    u16 unk_00d2[4];            /* +0xd2: id list (4 slots, filled by func_020d3680) */"""),
("""void func_020da710();
""", """void func_020da710(void *obj, const u16 *ids, const u16 *ref, s32 sel);
"""),
("""extern char data_021507dc[];
""", """extern char data_021507dc[];
extern char data_021507e0[];
extern char data_021507e4[];
extern char data_021507e8[];
void CampStatus_Unk_0db3e0(s32 a, s32 b, s32 c, s32 mode);
"""),
]
SPECS = [(TU, [
('func_020da97c', '''/* Draw value b (mode 1) or a (other modes) in slot `slot` with the compare colour from
 * CampStatus_Unk_0db3e0; in mode 1 a bobbing arrow (frame 48 up / 49 down, 24-tick cycle)
 * shows whether b is above or below a. */
void func_020da97c(u32 obj, s32 a, s32 b, s32 mode, u8 slot)
{
    char *width = func_020a9e14(1, data_021507e0);
    CampStatus_Unk_0db3e0(a, b, 0, mode);
    if (mode == 1) {
        func_020a9fd8(1, slot * 85 + 64, 143, 2, (u32)width, 10, (u32)data_021507e4, b);
        if (b > a) {
            s32 t = data_0215f05c.unk_0018 % 24;
            s32 dy;
            if (t < 6) {
                dy = 0;
            } else if (t < 12) {
                dy = -1;
            } else if (t < 18) {
                dy = -2;
            } else {
                dy = -1;
            }
            func_0205dee8(2, obj, 48, slot * 85, dy, 1.0f, 1.0f, 0, 1.0f, 4);
        } else if (b < a) {
            s32 t = data_0215f05c.unk_0018 % 24;
            s32 dy;
            if (t < 6) {
                dy = -2;
            } else if (t < 12) {
                dy = -1;
            } else if (t < 18) {
                dy = 0;
            } else {
                dy = -1;
            }
            func_0205dee8(2, obj, 49, slot * 85, dy, 1.0f, 1.0f, 0, 1.0f, 4);
        }
    } else {
        func_020a9fd8(1, slot * 85 + 64, 143, 2, (u32)width, 10, (u32)data_021507e8, a);
    }
    func_02057df8();
}'''),
('func_020dbdac', '''/* Icons for record id: unk_0002 3 fills the first icon from it and the second from the
 * player's +0x02 record, 4 the other way round (player's +0x00 record); both then go to
 * unk_00c8. Other values fall back to CampStatus_Unk_0db824. */
void func_020dbdac(CampStatusWork *work, u32 id)
{
    u32 icons[2] = {0, 0};
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    CampStatusInfo *info = Unk09974c_Unk_099c60(id);
    if (info == 0) {
        return;
    }
    if (info->unk_0002 == 3) {
        if (info->lo != info->hi) {
            icons[0] = 1;
        } else {
            icons[0] = 0;
        }
        CampStatus_Unk_0db910(info);
        if (p->unk_0002 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0002)) != 0) {
            if (info->lo != info->hi) {
                icons[1] = 3;
            } else {
                icons[1] = 2;
            }
            CampStatus_Unk_0db910(info);
        }
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, icons, 2);
        return;
    }
    if (info->unk_0002 == 4) {
        if (info->lo != info->hi) {
            icons[1] = 3;
        } else {
            icons[1] = 2;
        }
        CampStatus_Unk_0db910(info);
        if (p->unk_0000 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000)) != 0) {
            if (info->lo != info->hi) {
                icons[0] = 1;
            } else {
                icons[0] = 0;
            }
            CampStatus_Unk_0db910(info);
        }
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, icons, 2);
        return;
    }
    CampStatus_Unk_0db824(work);
}'''),
], '', FIX)]
