P='''void func_02008904();
u8 *func_020a1740();
int func_020a17d8();
int func_0202ee18(u32 id);

typedef struct Unk02e000Rec {
    u8 pad_0000[0x1c];
    u16 unk_001c;
    u8 unk_001e_0 : 7;
    u8 unk_001e_7 : 1;
    u8 flag_001f_0 : 1;
    u8 flag_001f_1 : 1;
    u8 unk_001f_2 : 6;
    u8 pad_0020[4];
} Unk02e000Rec;                 /* 36 bytes; table at work+0x16FC, ids 1..491 */

typedef struct Unk02e000ObjFlags {
    u16 pad_0000[11];
    u16 flag_0016_0 : 1;
} Unk02e000ObjFlags;

#define UNK02E000_RECS() ((Unk02e000Rec *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc))'''
def get(fn, ret, expr):
    return (fn, f'''{ret} {fn}(u32 id)
{{
    if (id > 491) {{
        return 0;
    }}
    {{
        Unk02e000Rec *r = &UNK02E000_RECS()[id - 1];
        return {expr};
    }}
}}''')
SPECS=[('src/game/unit_0202e000.c',[
('func_0202e9c8','''int func_0202e9c8(u32 id, void *src)
{
    if (id > 491) {
        return 0;
    }
    func_02008904(&UNK02E000_RECS()[id - 1], src, 36);
    return 1;
}'''),
('func_0202ea68','''int func_0202ea68(int i, void *src)
{
    u8 *base = (u8 *)Unk02e000_Unk_02e774() + 8 + 0x5c00;
    if (i >= 0 && i < 3) {
        func_02008904(base + i * 40 + 4, src, 36);
        return 1;
    }
    return 0;
}'''),
get('func_0202eb0c','u32','r->unk_001c'),
get('func_0202ebb8','u32','r->unk_001e_0'),
('func_0202ebfc','''int func_0202ebfc(u32 id)
{
    Unk02e000ObjFlags *o = (Unk02e000ObjFlags *)func_020a1740(id);
    if (func_020a17d8(id) == 0 && o->flag_0016_0 && func_0202ee18(id) > 0) {
        return 1;
    }
    return 0;
}'''),
get('func_0202ecac','int','r->flag_001f_0 ? 1 : 0'),
get('func_0202ed5c','int','r->flag_001f_1 ? 1 : 0'),
get('func_0202ee18','int','r->unk_001f_2'),
],P)]
