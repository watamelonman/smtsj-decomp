G = 'ScanVisor_Get_data_02176b04()'
LOOP = '''    int j;
    ScanVisorSlot *e = (ScanVisorSlot *)((u8 *)p + 32);
    for (j = 0; j < 7; j++, e++) {'''
SPECS=[
('src/ScanVisor.c',[
('func_020a2980',f'''int func_020a2980(void)
{{
    u8 *v = (u8 *){G};
    if (v == 0) {{
        return 1;
    }}
    return Unk0c855c_Unk_0c9bac(v + 120);
}}'''),
('func_020a2b58',f'''int func_020a2b58(void)
{{
    u8 *v = (u8 *){G};
    if (v == 0) {{
        return 1;
    }}
    return func_020a8c04(v + 40 + 1024);
}}'''),
('func_020a2bb8','''void func_020a2bb8(ScanVisorBits *p)
{
    p->word = 0;
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b3 = 0;
    p->b4 = 0;
    p->b67 = 0;
}'''),
('func_020a3254','''void func_020a3254(ScanVisor *p)
{
    if (FIELD(s32, p, 528) >= 50) {
        return;
    }
    Unk0c855c_Unk_0c9890((u8 *)p + 120, 12);
}'''),
('func_020a3760','''void func_020a3760(u32 a, u32 b, u32 c)
{
    func_020616ec(*data_02176b04, func_020c9db4((u8 *)*data_02176b04 + 120, a, b, c));
}'''),
('func_020a379c','''void func_020a379c(u32 a, u32 b)
{
    func_020616ec(*data_02176b04, func_020c9eb0((u8 *)*data_02176b04 + 120, a, b));
}'''),
('func_020a4284','''int func_020a4284(u32 id)
{
    u32 j;
    ScanVisorEnt20 *e = (ScanVisorEnt20 *)data_0214ce2c;
    for (j = 0; j < 6; j++, e++) {
        if (id == e->id) {
            return (int)e;
        }
    }
    return 0;
}'''),
('func_020a4578','void func_020a4578(u32 *p)\n{\n'+LOOP+'''
        if (e->active != 0) {
            func_02057eb8(2);
            func_020a43f4(e, p[0]);
        }
    }
}'''),
('func_020a45c0','ScanVisor *func_020a45c0(u32 p, u32 k)\n{\n'+LOOP+'''
        if (e->active != 0 && e->key == k) {
            return (ScanVisor *)e;
        }
    }
    return 0;
}'''),
('func_020a4600','int func_020a4600(u8 *p)\n{\n'+LOOP+'''
        if (e->active != 0 && ScanVisor_Unk_0a45f8((ScanVisor *)e) != 0) {
            return 1;
        }
    }
    return 0;
}'''),
('func_020a4994','int func_020a4994(u8 *p)\n{\n'+LOOP+'''
        if (e->active != 0 && e->f28 != 80) {
            return 0;
        }
    }
    return 1;
}'''),
],'''typedef struct ScanVisorSlot {
    u32 active;
    u32 key;
    u8 pad_08[0x14];
    u32 f28;
    u8 pad_20[0x14];
} ScanVisorSlot;

typedef struct ScanVisorEnt20 {
    u32 id;
    u8 pad_04[0x10];
} ScanVisorEnt20;

typedef struct ScanVisorBits {
    u32 word;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b67 : 2;
} ScanVisorBits;

extern u8 data_0214ce2c[];
int Unk0c855c_Unk_0c9bac();
int func_020a8c04();
void Unk0c855c_Unk_0c9890();
int func_020c9db4();
int func_020c9eb0();
void func_020616ec();
int func_02057eb8();
void func_020a43f4();''',[('void func_020a4600(void);','int func_020a4600();')]),
]
