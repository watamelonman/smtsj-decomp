FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_02039774.c',[
('func_02039774','''void func_02039774(u8 *n)
{
    if (data_0215de28.tail == 0) {
        data_0215de28.head = n;
        data_0215de28.tail = n;
        FIELD(u8 *, n, 224) = 0;
        FIELD(u8 *, n, 228) = 0;
    } else {
        FIELD(u8 *, n, 224) = data_0215de28.tail;
        FIELD(u8 *, data_0215de28.tail, 228) = n;
        FIELD(u8 *, n, 228) = 0;
        data_0215de28.tail = n;
    }
    data_0215de28.count++;
}'''),
('func_020397cc','''void func_020397cc(u8 *n)
{
    if (data_0215de28.head == n) {
        data_0215de28.head = FIELD(u8 *, n, 228);
    } else {
        FIELD(u8 *, FIELD(u8 *, n, 224), 228) = FIELD(u8 *, n, 228);
    }
    if (data_0215de28.tail == n) {
        data_0215de28.tail = FIELD(u8 *, n, 224);
    } else {
        FIELD(u8 *, FIELD(u8 *, n, 228), 224) = FIELD(u8 *, n, 224);
    }
    FIELD(u8 *, n, 224) = 0;
    FIELD(u8 *, n, 228) = 0;
    data_0215de28.count--;
}'''),
],FX),
('src/game/unit_0203aae8.c',[
('func_0203ad24','''void func_0203ad24(u8 *p)
{
    switch (FIELD(s32, p, 8)) {
    case 0: {
        u8 buf[64] = {0};
        func_02095b48(buf, FIELD(u32, p, 64));
        func_0204b344(p, buf);
        break;
    }
    case 1:
    case 2:
    case 3:
        break;
    }
}'''),
('func_0203ad98','''void *func_0203ad98(u8 *p, int key)
{
    void *r = 0;
    switch (FIELD(s32, p, 8)) {
    case 0:
        r = func_0204b3cc(p, key);
        break;
    case 1:
        break;
    case 2:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 92), r), key);
        break;
    case 3:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 116), r), key);
        break;
    }
    return r;
}'''),
('func_0203ae10','''void *func_0203ae10(u8 *p, int key)
{
    void *r = 0;
    switch (FIELD(s32, p, 8)) {
    case 0:
        r = Unk095560_Unk_095778(key);
        break;
    case 1:
        break;
    case 2:
        r = func_0204fed8(func_0204fe68(FIELD(u32, p, 80), r), key);
        break;
    case 3:
        break;
    }
    return r;
}'''),
],FX+'typedef int (*Unk03aae8StepFn)(u8 *);\nextern u8 data_02142170[];\nvoid func_02095b48();\nvoid func_0204b344();\nvoid *func_0204b3cc();\nvoid *func_0204fe68();\nvoid *func_0204fed8();\nvoid *Unk095560_Unk_095778();\nint func_0201f1dc();\n'),
]
