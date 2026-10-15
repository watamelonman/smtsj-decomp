B = '((Unk06ea70Bufs *)data_02170ccc.unk_04)'
def bit(fn, field, op):
    body = f'{B}->{field} |= 1 << i;' if op == 'set' else f'{B}->{field} &= ~(1 << i);'
    return (fn, f'''void {fn}(int i)
{{
    if (i < 0) {{
        return;
    }}
    {body}
}}''')
def buf(fn, field):
    return (fn, f'''u8 *{fn}(int i)
{{
    if (i < 0) {{
        return 0;
    }}
    return {B}->{field} + i * 512;
}}''')
SPECS=[('src/game/unit_0206ea70.c',[
('func_0206ebe8','''void func_0206ebe8(int i)
{
    if (data_02170ccc.table->entry[i] == 0) {
        return;
    }
    func_02061424(data_02170ccc.table->entry[i]);
    data_02170ccc.table->entry[i] = 0;
}'''),
('func_0206ec28','''void func_0206ec28(int i, u32 p)
{
    if (p == 0) {
        return;
    }
    data_02170ccc.table->entry[i] = p;
    func_0206f620(i);
}'''),
bit('func_0206f620','mask_0c','set'),
bit('func_0206f648','mask_0c','clr'),
buf('func_0206f674','buf_04'),
buf('func_0206f698','buf_00'),
bit('func_0206f6bc','mask_10','set'),
],'''typedef struct Unk06ea70Bufs {
    u8 *buf_00;                 /* 512-byte slots */
    u8 *buf_04;                 /* 512-byte slots */
    u8 pad_0008[4];
    u32 mask_0c;
    u32 mask_10;
} Unk06ea70Bufs;

void func_02061424();
void func_0206f620(int i);''',[('int func_0206f674();\n','u8 *func_0206f674();\n'),('    return func_0206f674(i);\n','    return (int)func_0206f674(i);\n')]),
('src/game/unit_0206fb70.c',[('func_020713fc','''void func_020713fc(s32 *p, s32 d, s32 lim)
{
    *p += d;
    if (d >= 0) {
        if (*p > lim) {
            *p = lim;
        }
    } else if (*p < lim) {
        *p = lim;
    }
}''')],''),
]
