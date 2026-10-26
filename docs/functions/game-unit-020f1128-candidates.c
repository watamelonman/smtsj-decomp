/* Unmatched, reproducible M1-T877 candidates; never linked into the image.
 * Compile from repository root with the production mwcc flags and -i . . */
#include "src/game/unit_020f1128.c"

/* Provider halfwords expose only instruction-established fields. */
typedef struct { u16 pad[2]; u16 cost; u16 flags; } CandidateProvider;
extern int func_020537b8(int, int), func_020537dc(int, int);
extern int func_02053824(int, int), func_02053800(int, int);
extern CandidateProvider *Unk09974c_Unk_099d78(u16);
extern void Unk0986ac_Unk_09894c(void *);
extern int Unk0f0eac_Compare(const void *, const void *);
extern int Unk0f0eac_Unk_0f1000(const void *, const void *);
extern int func_020f1020(const void *, const void *);
extern int func_020f10a4(const void *, const void *);
extern void func_02013c68(void *, u32, u32, int (*)(const void *, const void *));

/* State-13 input callback. Borrows the complete work allocation and providers.
 * Evidence: input masks, twelve-byte rows, and +6 provider bit extraction. */
void func_020f1914(void *argument)
{
    Unk0f1128_Work *w = argument;
    int old, mode, i;
    if (w->state != 13) return;
    if (func_020537b8(0, 512) && ((u8 *)w->handles[0])[0x3a])
        Unk065e88_SetFlag3a(w->handles[0], 0);
    else if (func_020537dc(0, 512) && !((u8 *)w->handles[0])[0x3a])
        Unk065e88_SetFlag3a(w->handles[0], 1);
    if (func_020537b8(0, 256) && ((u8 *)w->handles[1])[0x3a])
        Unk065e88_SetFlag3a(w->handles[1], 0);
    else if (func_020537dc(0, 256) && !((u8 *)w->handles[1])[0x3a])
        Unk065e88_SetFlag3a(w->handles[1], 1);
    old = w->selected;
    mode = (s8)w->unk25[0];
    if (func_02053824(0, 64)) {
        w->selected -= 2;
        if (w->count > 18 && w->selected < w->first) {
            w->first -= 2; func_020f2c90(w);
        }
        if (w->selected % 2 == 0) {
            if (w->selected < 0) {
                w->selected += w->count;
                if (w->selected % 2) w->selected++;
                if (w->count > 18) {
                    w->first = (s16)(w->count - 18);
                    if (w->first % 2) w->first++;
                    func_020f2c90(w);
                }
            }
        } else if (w->selected < 0) {
            w->selected += w->count;
            if (w->count > 18) {
                w->first = (s16)(w->count - 18);
                if (w->first % 2) w->first++;
                func_020f2c90(w);
            }
        }
    } else if (func_02053824(0, 128)) {
        w->selected += 2;
        if (w->selected - w->first >= 18) {
            w->first += 2; func_020f2c90(w);
        }
        if (w->selected % 2 == 0) {
            if (w->selected >= w->count) {
                w->selected = w->first = 0; func_020f2c90(w);
            }
        } else if (w->selected == w->count) w->selected = (s16)(w->count - 1);
        else if (w->selected > w->count) {
            w->selected -= w->count; w->first = 0; func_020f2c90(w);
        }
    } else if (func_02053824(0, 32) || func_02053824(0, 16)) {
        if (w->selected % 2 == 0) {
            if (w->selected < w->count - 1) w->selected++;
        } else w->selected--;
    } else if (func_02053800(0, 1)) {
        if (w->flag4f4) {
            void *entry = Unk0986ac_Unk_098978(w->rows[w->selected].id);
            if (Unk0986ac_Thunk_02098714()) {
                Unk0986ac_Unk_09895c(entry);
                Unk0986ac_Unk_098978(138);
                if (Unk0986ac_Thunk_02098714()) w->status++;
                else w->status += w->rows[w->selected].rest[2];
                if (w->rows[w->selected].id == 138) {
                    func_020f2e1c(w); w->status = Unk0986ac_Unk_098980();
                }
                Unk0a0ce4_Unk_0a0da4(35);
            } else {
                int enough, changed = 0;
                CandidateProvider *selected;
                Unk0986ac_Unk_098978(138);
                enough = Unk0986ac_Thunk_02098714() && w->status >= 1;
                if (!enough) {
                    Unk0986ac_Unk_098978(138);
                    enough = !Unk0986ac_Thunk_02098714() && w->status >= w->rows[w->selected].rest[2];
                }
                if (enough) {
                    if (w->rows[w->selected].id == 138) { func_020f2e1c(w); w->status = 7; }
                    selected = Unk09974c_Unk_099d78(w->rows[w->selected].id);
                    if ((selected->flags >> 8) & 63) {
                        for (i = 0; i < w->count; i++) {
                            CandidateProvider *other = Unk09974c_Unk_099d78(w->rows[i].id);
                            void *other_entry = Unk0986ac_Unk_098978(w->rows[i].id);
                            if (Unk0986ac_Thunk_02098714() &&
                                ((selected->flags >> 8) & 63) == ((other->flags >> 8) & 63)) {
                                Unk0986ac_Unk_09895c(other_entry);
                                Unk0986ac_Unk_098978(138);
                                if (Unk0986ac_Thunk_02098714()) w->status++;
                                else w->status += (u8)other->cost;
                                changed = 1;
                            }
                        }
                    }
                    Unk0986ac_Unk_09894c(entry);
                    Unk0986ac_Unk_098978(138);
                    if (Unk0986ac_Thunk_02098714()) w->status--;
                    else w->status -= w->rows[w->selected].rest[2];
                    Unk0a0ce4_Unk_0a0da4(changed ? 35 : 38);
                    if (w->rows[w->selected].id == 139) {
                        Unk0986ac_Unk_098978(139);
                        if (Unk0986ac_Thunk_02098714()) {
                            w->pending = 1; w->state = 10; w->timer = 0;
                            Unk0bc1a8_Unk_0bc928(7, 4); func_020f7bac(23, 0, 1);
                            Unk065e88_SetFlag3a(w->handles[0], 0);
                            Unk065e88_SetFlag3a(w->handles[1], 0);
                        }
                    }
                } else Unk0a0ce4_Unk_0a0da4(4);
            }
        }
    } else if (func_02053800(0, 1024)) {
        if (w->flag4f4) {
            w->state = 9; w->timer = 0;
            Unk0bc1a8_Unk_0bc928(7, 4); func_020f7bac(1, 0, 1);
            Unk065e88_SetFlag3a(w->handles[0], 0);
            Unk065e88_SetFlag3a(w->handles[1], 0);
            Unk0a0ce4_Unk_0a0da4(1);
        }
    } else if (func_02053800(0, 512)) {
        Unk065e88_SetFlag3a(w->handles[0], 0);
        w->unk25[0]--;
        if ((s8)w->unk25[0] < 0) w->unk25[0] = 2;
        Unk0f1128_Unk_0f2d30((u32)w->handlec, (s8)w->unk25[0], 0, 0);
        switch ((s8)w->unk25[0]) {
        case 0: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Compare); break;
        case 1: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Unk_0f1000); break;
        case 2: func_02013c68(w->rows, w->count, 12, func_020f1020); break;
        }
        func_020f2c90(w); Unk0a0ce4_Unk_0a0da4(11);
        Unk0bc1a8_SetFlag4Inv(w, 0); w->cooldown = 2;
    } else if (func_02053800(0, 256)) {
        Unk065e88_SetFlag3a(w->handles[1], 0);
        w->unk25[0]++;
        if ((s8)w->unk25[0] > 2) w->unk25[0] = 0;
        Unk0f1128_Unk_0f2d30((u32)w->handlec, (s8)w->unk25[0], 0, 0);
        switch ((s8)w->unk25[0]) {
        case 0: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Compare); break;
        case 1: func_02013c68(w->rows, w->count, 12, Unk0f0eac_Unk_0f1000); break;
        case 2: func_02013c68(w->rows, w->count, 12, func_020f10a4); break;
        }
        func_020f2c90(w); Unk0a0ce4_Unk_0a0da4(11);
        Unk0bc1a8_SetFlag4Inv(w, 0); w->cooldown = 2;
    } else if (func_02053824(0, 2)) {
        Unk065e88_SetFlag3a(w->handles[0], 0);
        Unk065e88_SetFlag3a(w->handles[1], 0); func_020f2d80(w);
    }
    if (old != w->selected || mode != (s8)w->unk25[0]) {
        Unk0f1128_Unk_0f2d60(w->rows[w->selected].id);
        if (old != w->selected) Unk0a0ce4_Unk_0a0da4(0);
    }
}

extern void func_02057e58(int, int, int), func_02057eb8(int);
extern void func_02057fd8(void), func_02057df8(void), func_02057ddc(u32);
extern void func_0205dee8(int, void *, int, int, int, float, float, int, float, int);
extern void func_02058f10(int, int, int, int, int, int, int);
extern void func_020c83a0(void), func_02057e18(int), func_020ddf38(void *);
extern int func_02061a04(void *, int, int);
extern void Unk0ddeb0_Unk_0ddeb0(void *, int, int, int, int, int);
extern int func_020a9e14(int, const void *);
extern void func_020a9fd8(int, int, int, int, int, int, const void *, ...);
extern void Unk0bd5f0_Unk_0c842c(void);
extern void func_02057dcc(u32, u32, u32, u32);
extern void func_02057524(int), func_02057534(void);
extern void func_02057d54(int, int, int, int, int, int);
extern void *data_0215f05c[];
extern const u8 data_02150df4[], data_02150df8[], data_02150dfc[];
extern const u8 data_02150e00[], data_02150e04[], data_02150e08[];
extern const u8 data_02150e0c[], data_02150e10[];

/* Draw callback borrows resource handles; grid positions are pixel offsets.
 * Evidence: nine two-column rows, spacing 13/122, draw IDs 0x37..0x46.
 * Repeated provider calls intentionally retain their original sequencing. */
void func_020f21b0(void *argument)
{
    Unk0f1128_Work *w = argument;
    u32 count, height, offset;
    int row, column, i, x, y, font;
    func_02057e58(3, 10, 20);
    func_02057eb8(3);
    func_02057fd8();
    func_0205dee8(2, w->handle0, 55, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 1);
    func_02057fd8();
    func_02058f10(2, 0x1d69, w->fade, 0, 1, 126, 2);
    func_0205dee8(2, w->handle0, 65, 0, 0, 1.0f, 1.0f, 0, w->progress, 1);
    func_0205dee8(2, w->handle0, 69, 0, 0, 1.0f, 1.0f, 0, w->progress, 1);
    func_02057fd8();
    count = w->count;
    if (count < 18) count = 18;
    height = ((0x12000U / count) * 116) >> 12;
    offset = (((u32)((w->first / 2) << 12) / ((count & 1) + (count >> 1) - 9)) * (116 - height)) >> 12;
    func_02058f10(2, 0x1d6a, w->fade, offset, 1, height, 2);
    func_02057fd8();
    func_0205dee8(2, w->handle0, 57, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 2);
    for (row = 0; row < 9; row++) {
        for (column = 0; column < 2; column++) {
            Unk0986ac_Unk_098978(w->rows[w->first + row * 2 + column].id);
            if (!Unk0986ac_Thunk_02098714()) {
                int disabled;
                Unk0986ac_Unk_098978(138);
                disabled = Unk0986ac_Thunk_02098714() && w->status == 0;
                if (!disabled) {
                    Unk0986ac_Unk_098978(138);
                    disabled = !Unk0986ac_Thunk_02098714() &&
                        w->rows[w->first + row * 2 + column].rest[2] > w->status;
                }
                if (disabled)
                    func_0205dee8(2, w->handle0, 61, w->fade + column * 122, row * 13, 1.0f, 1.0f, 0, w->progress, 2);
                else
                    func_0205dee8(2, w->handle0, 59, w->fade + column * 122, row * 13, 1.0f, 1.0f, 0, w->progress, 2);
            } else {
                func_0205dee8(2, w->handle0, 59, w->fade + column * 122, row * 13, 1.0f, 1.0f, 0, w->progress, 2);
            }
        }
    }
    func_02057ddc(0x00ffffff);
    func_0205dee8(2, w->handle0, 66, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_0205dee8(2, w->handle0, 67, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_02057fd8(); func_02057df8();
    func_0205dee8(2, w->handle0, 68, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_0205dee8(2, w->handle0, 70, 0, 0, 1.0f, 1.0f, 0, w->progress, 2);
    func_0205dee8(2, w->handle0, 58, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 3);
    if (w->state == 13) {
        int enabled;
        func_02057fd8(); func_020c83a0();
        x = (w->selected % 2) * 122;
        y = ((w->selected - w->first) / 2) * 13;
        Unk0986ac_Unk_098978(w->rows[w->selected].id);
        enabled = Unk0986ac_Thunk_02098714();
        if (enabled) {
            func_0205dee8(2, w->handle0, 60, x, y, 1.0f, 1.0f, 0, 1.0f, 4);
        } else {
            Unk0986ac_Unk_098978(138);
            enabled = Unk0986ac_Thunk_02098714() && w->status >= 1;
            if (!enabled) {
                Unk0986ac_Unk_098978(138);
                enabled = !Unk0986ac_Thunk_02098714() && w->rows[w->selected].rest[2] <= w->status;
            }
            if (enabled) func_0205dee8(2, w->handle0, 60, x, y, 1.0f, 1.0f, 0, 1.0f, 4);
        }
        func_02057fd8();
        func_020ddf38(data_0215f05c[6]);
        /* 020ddf38's result is forwarded in r0 to 02057e18. */
        func_02057e18(31);
        func_02058f10(2, 0x1d77, x, y, 119, 12, 5);
        func_02057e18(31);
    }
    func_02057fd8();
    func_0205dee8(2, w->handle0, 63, w->fade, 0, 1.0f, 1.0f, 0, w->progress, 6);
    func_02057df8();
    if (w->progress > 0.0f) {
        int width;
        func_02057fd8();
        width = func_02061a04(((void **)w->handlec)[10], ((int *)w->handlec)[5], 0);
        Unk0ddeb0_Unk_0ddeb0(w->handlec, (48 - width) / 2 + 122, 6, 0, 5, 10);
        func_02057df8();
        font = func_020a9e14(1, data_02150df4);
        func_020a9fd8(1, 223, 9, 2, font, 10, data_02150df8, w->status);
        Unk0986ac_Unk_098978(138);
        if (Unk0986ac_Thunk_02098714())
            func_020a9fd8(1, 241, 9, 2, font, 10, data_02150dfc, 7);
        else {
            int status = Unk0986ac_Unk_098980();
            func_020a9fd8(1, 241, 9, 2, font, 10, data_02150e00, status);
        }
        func_020a9fd8(1, 235, 9, 0, 1, 10, data_02150e04);
    }
    Unk0bd5f0_Unk_0c842c();
    for (i = 0; i < 18; i++) {
        if (!w->rows[w->first + i].id) continue;
        x = i % 2 == 0 ? 0 : 122;
        func_02057df8();
        font = func_020a9e14(1, data_02150e08);
        Unk0986ac_Unk_098978(138);
        y = (i / 2) * 13;
        if (Unk0986ac_Thunk_02098714())
            func_020a9fd8(1, x + 111 + w->fade, y + 35, 2, font, 10, data_02150e0c, 1);
        else
            func_020a9fd8(1, x + 111 + w->fade, y + 35, 2, font, 10, data_02150e10, w->rows[w->first + i].rest[2]);
        Unk0986ac_Unk_098978(w->rows[w->first + i].id);
        if (Unk0986ac_Thunk_02098714()) {
            func_0205dee8(2, w->handle0, 64, x + w->fade, y, 1.0f, 1.0f, 0, 1.0f, 10);
            func_02057dcc(0xff942100, 0xff942100, 0xff942100, 0xff942100);
            Unk0ddeb0_Unk_0ddeb0(w->handle8, x + 21 + w->fade, y + 32, i, 8, 10);
        } else {
            int disabled;
            Unk0986ac_Unk_098978(138);
            disabled = Unk0986ac_Thunk_02098714() && w->status < 1;
            if (!disabled) {
                Unk0986ac_Unk_098978(138);
                disabled = !Unk0986ac_Thunk_02098714() && w->status < w->rows[w->first + i].rest[2];
            }
            if (disabled) func_02057dcc(0x7b7b7b00, 0x7b7b7b00, 0x7b7b7b00, 0x7b7b7b00);
            Unk0ddeb0_Unk_0ddeb0(w->handle8, x + 21 + w->fade, y + 32, i, 8, 10);
        }
    }
    func_02057524(6);
    if ((u32)(w->state - 9) <= 1) {
        func_02057fd8();
        if ((u8)(w->timer * 24 / 16) >= 1) {
            func_02057e18((u8)(w->timer * 24 / 16));
            func_02057d54(0, 0, 0, 256, 192, 21);
            func_02057e18(31);
        }
    }
    func_02057534(); func_02057eb8(-1);
}
