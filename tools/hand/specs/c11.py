TU = 'src/CampStatus.c'
FIX = [
("""    s16 unk_0100;
    s16 unk_0102;
    s16 unk_0104;
    s16 unk_0106;
    s16 unk_0108;
""", """    s16 unk_0100[5];            /* +0x100: x of the five rows drawn by func_020d6e10 */
"""),
("""    work->unk_0100 = -224;
    work->unk_0102 = -288;
    work->unk_0104 = -352;
    work->unk_0106 = -416;
    work->unk_0108 = -480;""", """    work->unk_0100[0] = -224;
    work->unk_0100[1] = -288;
    work->unk_0100[2] = -352;
    work->unk_0100[3] = -416;
    work->unk_0100[4] = -480;"""),
]
SPECS = [(TU, [
('func_020d6e10', '''/* Draw the main status panel: frames 5, 7, 8, 12-14 and the eight icons of data_0213c5b0 at
 * x unk_00fe, the five row frames 15-19 at x unk_0100[0..4], frame 33 at y unk_010c, then the
 * five row labels of unk_00b4. */
void func_020d6e10(CampStatusWork *work)
{
    CampStatusIds8 icons;
    int i;
    func_02057fd8();
    func_02057df8();
    func_0205dee8(2, work->unk_0018, 5, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_02057e18(31);
    func_0205dee8(2, work->unk_0018, 7, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 8, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 12, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 13, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_02057e18(31);
    func_0205dee8(2, work->unk_0018, 14, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    icons = data_0213c5b0;
    for (i = 0; i < 8; i++) {
        func_02058e9c(2, Unk0c855c_Unk_0ca690(icons.v[i]), work->unk_00fe + (i * 14 + 5), 53, work->unk_0110, 0, 3);
    }
    func_0205dee8(2, work->unk_0018, 15, work->unk_0100[0], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 16, work->unk_0100[1], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 17, work->unk_0100[2], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 18, work->unk_0100[3], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 19, work->unk_0100[4], 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_0205dee8(2, work->unk_0018, 33, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
    func_02057e18(31);
    func_02057fd8();
    for (i = 0; i <= 4; i++) {
        Unk0ddeb0_Unk_0ddeb0(work->unk_00b4, work->unk_0100[i] + 4, i * 11 + 82, i, 2, 10);
    }
}'''),
], '''/* Eight icon ids copied from data_0213c5b0. */
typedef struct CampStatusIds8 {
    u32 v[8];
} CampStatusIds8;
extern const CampStatusIds8 data_0213c5b0;
u32 Unk0c855c_Unk_0ca690(u32 id);''', FIX)]
