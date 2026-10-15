STEP='''void func_{a}(void *o, s32 *tick, s8 *state, s32 *limit, s32 *pos, s32 *vel, s32 *max)
{{
    if (*state >= 4) {{
        return;
    }}
    if (++*tick > *limit) {{
        *tick = 0;
        *vel = 0;
        func_{c}(o, state, limit, vel, max);
        return;
    }}
    Unk06fb70_AddClamped(pos, *vel, *max);
}}'''
SPECS=[
('src/game/unit_0206fb70.c',[
('func_02070500', STEP.format(a='02070500', c='0207126c')),
('func_0207057c', STEP.format(a='0207057c', c='02071334')),
('func_02071844','''void func_02071844(Unk06fb70Mgr *m)
{
    int i;
    if (m == 0) {
        return;
    }
    for (i = 0; i < 50; i++) {
        Unk06ae94_Unk_06c0b0(m->objs[i]);
    }
    m->unk_24 = 0;
    m->unk_28 = 0;
    m->unk_2c = 0;
    m->unk_30 = 0;
    if (m->unk_224 != 0) {
        *m->unk_224 = 0;
    }
    func_02061424(m);
}'''),
],'''typedef struct Unk06fb70Mgr {
    u8 pad_000[0x24];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 pad_034[0x1f0];
    u32 *unk_224;
    u8 pad_228[4];
    s32 cur;                    /* +0x22c */
    s32 end;                    /* +0x230 */
    u32 objs[50];               /* +0x234: count from the % 50 / < 50 bounds */
} Unk06fb70Mgr;
void func_0207126c();
void func_02071334();
void Unk06ae94_Unk_06c0b0();
void func_02061424();
'''),
]
