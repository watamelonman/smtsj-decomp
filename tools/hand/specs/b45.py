TBL = '(*(Unk0bc1a8Slot **)*data_02176ba8)'
FX = '#ifndef FIELD\n#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))\n#endif\n'
SPECS=[
('src/game/unit_020bc1a8.c',[
('func_020bc5ac','''int func_020bc5ac(u8 *p)
{
    if (p == 0) {
        return 0xffff;
    }
    return FIELD(u32, p, -4);
}'''),
('func_020bc650',f'''int func_020bc650(int i)
{{
    if (i >= 41) {{
        return 1;
    }}
    return {TBL}[i].obj == 0;
}}'''),
('func_020bc688',f'''int func_020bc688(int i)
{{
    u8 *o;
    if (i >= 41) {{
        return 1;
    }}
    o = {TBL}[i].obj;
    if (o == 0) {{
        return 1;
    }}
    return (FIELD(u32, o, 36) & 8) == 8;
}}'''),
],'''extern u32 data_02176ba8[];
typedef struct Unk0bc1a8Slot {
    u8 *obj;
    u32 pad_04[2];
} Unk0bc1a8Slot;'''),
('src/game/unit_020bcc7c.c',[
('func_020bcd58','''int func_020bcd58(s32 *p)
{
    if (p[2] <= 0) {
        return 0;
    }
    p[2] = p[2] - (p[0] - 1);
    if (p[2] <= 0) {
        p[2] = 0;
    }
    p[4] = p[4] + (p[2] - p[3]);
    return 1;
}'''),
],''),
('src/game/unit_020bd5f0.c',[
('func_020bd5f0','''int func_020bd5f0(s32 *p)
{
    if (p[2] == 2 && p[1] >= 2) {
        return 1;
    }
    return 0;
}'''),
],FX+'int Unk02e000_GetWorkArea();'),
]
# skipped: func_020bc614 (ROM sets j=0 before the literal load), func_020bd034 (ROM reloads lo/hi after the store), func_020c1968 (ROM adds i + base; mwcc emits base + i either way)
# skipped: func_020bd54c (matches, but gatecheck: caller Unk0bcef4_Unk_0bd29c drops to 99.79% - same-file callee effect)
