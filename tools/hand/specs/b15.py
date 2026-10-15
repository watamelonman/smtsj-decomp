P='''typedef struct Unk044904Obj {
    u32 unk_0000;               /* bits 16-23 tested as "active" */
    u8 pad_0004[0x1da];
    u8 unk_01de;
} Unk044904Obj;

typedef struct Unk044904Mgr {
    u8 pad_0000[0x40];
    u32 pad_0040_0 : 10;
    u32 flag_0040_10 : 1;
    u32 pad_0040_11 : 7;
    u32 flag_0040_18 : 1;
    u8 pad_0044[0xc];
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[0xc];
    Unk044904Obj *slots[10];    /* +0x64 */
} Unk044904Mgr;

#define UNK044904_MGR() ((Unk044904Mgr *)Unk044904_Get_data_0215ee98())
void func_0204a780();
void func_0204a694();
void Unk0bc1a8_Unk_0bc928();'''
SPECS=[('src/game/unit_02044904.c',[
('func_02044fa0','''Unk044904Obj *func_02044fa0(int i)
{
    Unk044904Mgr *m = UNK044904_MGR();
    if (m == 0) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }
    if (i >= 4) {
        return 0;
    }
    return m->slots[i];
}'''),
('func_0204527c','''void func_0204527c(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0 && (o->unk_0000 >> 16 & 0xff)) {
            func_0204a780(o, 11);
        }
    }
}'''),
('func_020453ac','''void func_020453ac(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0) {
            o->unk_01de = 0;
        }
    }
}'''),
('func_02045430','''void func_02045430(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0) {
            func_0204a694(o);
        }
    }
}'''),
('func_020457a8','''Unk044904Obj *func_020457a8(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0 && (o->unk_0000 >> 16 & 0xff) == 0) {
            return o;
        }
    }
    return 0;
}'''),
('func_020459fc','''void func_020459fc(void)
{
    if (UNK044904_MGR()->flag_0040_10) {
        return;
    }
    UNK044904_MGR()->unk_0050 = 1;
    UNK044904_MGR()->unk_0054 = 0;
}'''),
('func_02045c38','''int func_02045c38(void)
{
    return UNK044904_MGR()->flag_0040_18 ? 1 : 0;
}'''),
('func_02045c58','''void func_02045c58(int x)
{
    if (x != 1) {
        return;
    }
    Unk0bc1a8_Unk_0bc928(26, 0xffff, 0);
}'''),
],P,[('int func_0204527c();\n','void func_0204527c();\n')])]
