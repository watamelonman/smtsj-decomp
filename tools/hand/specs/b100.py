SPECS=[
('src/CaveArea.c',[
('func_020ed3cc','''void func_020ed3cc(float *p)
{
    *p += 0.6f;
    if (*p >= 32.0f) {
        *p = 0.0f;
    }
}'''),
('func_020ed9e8','''void func_020ed9e8(CaveAreaUnk0ed9e8 *o)
{
    o->t += 0.5f;
    if (o->t >= 192.0f) {
        o->t = 0.0f;
    }
}'''),
],'typedef struct CaveAreaUnk0ed9e8 {\n    u8 pad_000[296];\n    float t;\n} CaveAreaUnk0ed9e8;\n'),
('src/game/unit_020ef248.c',[
('func_020ef2ec','''void func_020ef2ec(float *p, int v)
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
]
