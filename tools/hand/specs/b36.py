G = 'ScanVisor_Get_data_02176b04()'
def fwd(fn, callee):
    return (fn, f'''int {fn}(void)
{{
    u8 *v = (u8 *){G};
    if (v == 0) {{
        return 0;
    }}
    return {callee}(v + 40 + 1024);
}}''')
def eq(fn, off, k):
    return (fn, f'''int {fn}(void)
{{
    u8 *v = (u8 *){G};
    if (v == 0) {{
        return 0;
    }}
    return FIELD(s32, v, {off}) == {k};
}}''')
def sel(fn, off, a, b):
    return (fn, f'''void {fn}(int on)
{{
    u8 *v = (u8 *){G};
    if (v == 0) {{
        return;
    }}
    if (on) {{
        FIELD(s32, v, {off}) = {a};
    }} else {{
        FIELD(s32, v, {off}) = {b};
    }}
}}''')
def call2(fn, a, b):
    return (fn, f'''void {fn}(int on)
{{
    u8 *v = (u8 *){G};
    if (v == 0) {{
        return;
    }}
    if (on) {{
        {a}(v + 588);
    }} else {{
        {b}(v + 588);
    }}
}}''')
SPECS=[
('src/game/unit_020a23f4.c',[
fwd('func_020a2448','func_020a8608'),
fwd('func_020a246c','func_020a8628'),
fwd('func_020a2490','Unk0a7d54_Unk_0a8648'),
eq('func_020a24b4',528,0), eq('func_020a24dc',44,0), eq('func_020a2510',20,0),
eq('func_020a2538',528,50), eq('func_020a2560',44,81), eq('func_020a2594',20,-54),
('func_020a25c0',f'''int func_020a25c0(void)
{{
    u8 *v = (u8 *){G};
    if (v == 0) {{
        return 0;
    }}
    return func_020a4994(v + 588);
}}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_020a8608();
int func_020a8628();
int Unk0a7d54_Unk_0a8648();
int func_020a4994();'''),
('src/ScanVisor.c',[
sel('func_020a277c',52,-3,3),
sel('func_020a2820',28,2,-2),
sel('func_020a2884',532,-3,3),
call2('func_020a2920','ScanVisor_Unk_0a4904','ScanVisor_Unk_0a4864'),
call2('func_020a2950','ScanVisor_Unk_0a4910','ScanVisor_Unk_0a48b4'),
],'void ScanVisor_Unk_0a4904();\nvoid ScanVisor_Unk_0a4864();\nvoid ScanVisor_Unk_0a4910();\nvoid ScanVisor_Unk_0a48b4();'),
]
# skipped: func_020a2218 (loop register/load placement; 4 layouts)
