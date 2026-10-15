HDR='typedef struct Unk06fb70Key {\n    u8 pad_00[16];\n    s32 t[2];\n    u8 pad_18[28];\n    u8 c[4];\n    u8 pad_38[12];\n} Unk06fb70Key;\ntypedef struct Unk06fb70Anim {\n    Unk06fb70Key keys[4]; /* count from the < 4 bounds */\n    u8 pad_110[212];\n    s32 pos[4];\n    u8 pad_1f4[28];\n    s32 vel[4];\n    u8 pad_220[28];\n    s32 max[4];\n    u8 pad_24c[111];\n    s8 state0;\n    s8 state1;\n    u8 pad_2bd[11];\n    s32 tick0;\n    s32 tick1;\n    u8 pad_2d0[32];\n    s32 limit0;\n    s32 limit1;\n} Unk06fb70Anim;\nvoid Unk06fb70_AddClamped(s32 *p, s32 d, s32 lim);\n'
F05f8='''void func_020705f8(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s = a->state0;
    int k = 1;
    if (s + 1 >= 4) {
        a->state0 = 4;
        return;
    }
    for (; s + k < 4; k++, s = a->state0) {
        a->limit0 = b->keys[s + k].t[0] - b->keys[s].t[0];
        if (a->limit0 > 0) {
            a->vel[0] = Unk06fb70_Unk_06fb70(a->keys[a->state0].t[0], a->keys[a->state0 + k].t[0], a->keys[a->state0].c[0], a->keys[a->state0 + k].c[0]);
            a->vel[1] = Unk06fb70_Unk_06fb70(a->keys[a->state0].t[0], a->keys[a->state0 + k].t[0], a->keys[a->state0].c[1], a->keys[a->state0 + k].c[1]);
            a->vel[2] = Unk06fb70_Unk_06fb70(a->keys[a->state0].t[0], a->keys[a->state0 + k].t[0], a->keys[a->state0].c[2], a->keys[a->state0 + k].c[2]);
            a->max[0] = a->keys[a->state0 + k].c[0] << 12;
            a->max[1] = a->keys[a->state0 + k].c[1] << 12;
            a->max[2] = a->keys[a->state0 + k].c[2] << 12;
            a->state0 = a->state0 + k;
            return;
        }
    }
}'''
F0758='''void func_02070758(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state1 + 1 >= 4) {
        a->state1 = 4;
    }
    s = a->state1;
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state1) {
        a->limit1 = b->keys[s + k].t[1] - b->keys[s].t[1];
        if (a->limit1 > 0) {
            a->vel[3] = Unk06fb70_Unk_06fb70(a->keys[a->state1].t[1], a->keys[a->state1 + k].t[1], a->keys[a->state1].c[3], a->keys[a->state1 + k].c[3]);
            a->max[3] = a->keys[a->state1 + k].c[3] << 12;
            a->state1 = a->state1 + k;
            return;
        }
    }
}'''
SPECS=[('src/game/unit_0206fb70.c',[('func_020705f8',F05f8),('func_02070758',F0758)],HDR)]
