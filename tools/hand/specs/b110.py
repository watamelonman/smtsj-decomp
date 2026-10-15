SPECS=[
('src/game/unit_0209a268.c',[
('func_0209ae60','''void func_0209ae60(Unk09ae60Ops *o)
{
    o->size = 60;
    o->unk_04 = 0;
    o->fn_0c = func_0209b1d4;
    o->fn_10 = Unk09a268_Nop_09b3c8;
    o->fn_14 = Unk09a268_Unk_09b3cc;
    o->fn_18 = func_0209b3f8;
    o->fn_1c = func_0209b5d8;
    o->fn_20 = func_0209aebc;
}'''),
],'''typedef struct Unk09ae60Ops {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*fn_0c)();
    void (*fn_10)();
    void (*fn_14)();
    void (*fn_18)();
    void (*fn_1c)();
    void (*fn_20)();
} Unk09ae60Ops;
int func_02058a64();
void Unk09a268_Unk_09b3cc(Unk09a268Work *work);
void func_02058944();
void func_0209b1d4();
void func_0209b3f8();
void func_0209b5d8();
void func_0209aebc();
'''),
('src/game/unit_0209d42c.c',[
('func_0209d73c','''u16 func_0209d73c(u16 id)
{
    int tab = func_020445d0(9, 4);
    Unk09d42cMap *e = (Unk09d42cMap *)func_0204fde0(tab);
    u32 n = func_0204fe18(tab);
    u32 i;
    for (i = 0; i < n; i++, e++) {
        if (e->key == id && Unk0e651c_Unk_0e666c(e->flag) != 0) {
            return e->val;
        }
    }
    return id;
}'''),
],'''typedef struct Unk09d42cList {
    char names[64][32];         /* count from the +0x800 count offset */
    s32 count;
} Unk09d42cList;
typedef struct Unk09d42cMap {
    u16 flag;
    u16 key;
    u16 val;
} Unk09d42cMap;
extern char data_0214c9cc[];
int func_020152cc();
void func_02013c3c();
int Unk0e651c_Unk_0e666c();
'''),
]
