def get(fn, T, off):
    return (fn, f'''u32 {fn}(void)
{{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    if (p != 0) {{
        Unk03aae8_Unk_03acf4(FIELD({T}, p, {off}));
    }} else {{
        Unk03aae8_Unk_03acf4(0);
    }}
    return 1;
}}''')
def geti(fn, T, off):
    return (fn, f'''u32 {fn}(void)
{{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);
    if (i >= 3) {{
        i = 0;
    }}
    if (p != 0) {{
        Unk03aae8_Unk_03acf4(FIELD({T}, p + i * 10, {off}));
    }} else {{
        Unk03aae8_Unk_03acf4(0);
    }}
    return 1;
}}''')
SPECS=[
('src/game/unit_020bb6e8.c',[
('func_020bb770','''u32 func_020bb770(void)
{
    if (Unk02e000_GetRecordFlag0((u16)func_0203ac00(0)) != 0) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}'''),
('func_020bb7ac','''u32 func_020bb7ac(void)
{
    int on = func_0203ac00(1) != 0;
    func_0202ec48((u16)func_0203ac00(0), on);
    return 1;
}'''),
('func_020bb880','''u32 func_020bb880(void)
{
    u32 v = FIELD(u32, Unk0bac80_Unk_0badc0(), 68);
    Unk03aae8_Unk_03acf4((v << 19) >> 24);
    return 1;
}'''),
('func_020bb8c0','''u32 func_020bb8c0(void)
{
    int a = func_0203ac00(0);
    if (a < 15) {
        if (Unk0e5fb8_Unk_0e6254(a) != 0) {
            Unk03aae8_Unk_03acf4(1);
        } else {
            Unk03aae8_Unk_03acf4(0);
        }
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02e000_GetRecordFlag0();
void func_0202ec48();
u32 Unk0bac80_Unk_0badc0(void);
int Unk0e5fb8_Unk_0e6254();'''),
('src/game/unit_020bb908.c',[
get('func_020bb9e8','u16',4), get('func_020bba14','u16',0), get('func_020bba40','u16',2),
geti('func_020bba6c','s16',6), geti('func_020bbab4','u16',8), geti('func_020bbafc','u16',10),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u32 Unk0bac80_Unk_0bae08(void);'''),
]
