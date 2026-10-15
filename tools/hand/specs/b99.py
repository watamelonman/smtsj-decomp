SPECS=[
('src/game/unit_02094fe0.c',[
('func_02095258','''int func_02095258(u32 i, u32 id, u8 cnt)
{
    Unk094fe0Timer *t;
    if (i >= 4) {
        return 0;
    }
    if (id >= 4096) {
        return 0;
    }
    if (cnt == 0) {
        return 0;
    }
    t = Unk094fe0_Thunk_0202e8cc()->timers;
    t[i].id = id;
    t[i].cnt = cnt;
    return 1;
}'''),
('func_020952ac','''void func_020952ac(void)
{
    Unk094fe0Timer *t = Unk094fe0_Thunk_0202e8cc()->timers;
    int i;
    for (i = 0; i < 4; i++) {
        if (t[i].cnt != 0) {
            if (--t[i].cnt == 0) {
                t[i].cnt = 0;
                Unk0e651c_SetBitChecked(t[i].id, 1);
            }
        }
    }
}'''),
('func_020953f0','''int func_020953f0(void)
{
    Unk094fe0Timer *t = &Unk094fe0_Thunk_0202e8cc()->unk_09a4;
    u8 cnt = t->cnt;
    u8 flag;
    u16 id;
    if (cnt == 0) {
        return 0;
    }
    flag = t->flag;
    if (flag == 0) {
        return 0;
    }
    id = t->id;
    if (id == 0) {
        return 0;
    }
    if (Unk09ee4c_Thunk_02118c6c(Unk02f2a8_Unk_035b08(cnt, flag)) == 0) {
        return 0;
    }
    t->cnt = 0;
    t->flag = 0;
    Unk0e651c_SetBitChecked(t->id, 1);
    t->id = 0;
    return 1;
}'''),
],'void Unk0e651c_SetBitChecked();\nint Unk02f2a8_Unk_035b08();\nint Unk09ee4c_Thunk_02118c6c();\n',
[('''typedef struct Unk094fe0Work {
    u8 pad_0000[0x9a0];
    u32 unk_09a0;
} Unk094fe0Work;''','''typedef struct Unk094fe0Timer {
    u16 id;
    u8 cnt;
    u8 flag;
} Unk094fe0Timer;

typedef struct Unk094fe0Work {
    u8 pad_0000[0x980];
    Unk094fe0Timer timers[4];   /* +0x980: count from the < 4 bounds */
    u8 pad_0990[0x10];
    u32 unk_09a0;
    Unk094fe0Timer unk_09a4;
} Unk094fe0Work;''')]),
]
