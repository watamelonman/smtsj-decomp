SPECS=[
('src/game/unit_020efff4.c',[
('func_020f0098','''void func_020f0098(float *p, int v)
{
    if (v < 0) {
        *p = 0.0f;
        return;
    }
    if (v > 100) {
        *p = 1.0f;
        return;
    }
    *p = v / 100.0f;
}'''),
],''),
('src/game/unit_02113294.c',[
('func_02115778','''int func_02115778(int a, int b, int c)
{
    return ((float *)(data_0215159c + a * 220))[b * 11 + c] != 0.0f;
}'''),
],''),
('src/CampStatus.c',[
('func_020dd308','''void func_020dd308(s32 *v, s32 add, int n, s32 *cnt, float *out)
{
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] > 0) {
            v[i] += add;
        }
    }
    if (*cnt >= 10) {
        return;
    }
    (*cnt)++;
    *out = *cnt / 10.0f;
}'''),
],''),
('src/ScanVisor.c',[
('func_020a3274','''s8 func_020a3274(void)
{
    u8 *w;
    s16 a;
    s16 b;
    s32 r;
    if (GameState_Exists() == 0) {
        return 0;
    }
    w = (u8 *)Unk02e000_GetWorkArea();
    b = *(s16 *)(w + 2804);
    a = (s16)(*(s16 *)(w + 2802) * 100);
    if (b <= 0) {
        return 0;
    }
    r = a / b;
    if (r >= 100) {
        r = 99;
    }
    return r;
}'''),
],'int GameState_Exists();\nvoid *Unk02e000_GetWorkArea();\n'),
]
