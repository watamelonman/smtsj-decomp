"""Shared spec helpers. In a spec: exec(open(__import__('os').path.join(SJ_HAND, 'fam.py')).read())
or simply: from fam import *   (batch.py puts tools/hand on sys.path).
Script-command handlers write ad14()->sub(+0xe8)->state(+0x18); writing through an inline setter
taking (value, sub) reproduces the ROM register order."""
SUB = 'FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8)'
def ST(tu, extra=''):
    return f'''int Unk03aae8_Unk_03ad14();
static inline void Unk{tu}_SetSubState(u32 v, u8 *sub)
{{
    FIELD(u32, sub, 0x18) = v;
}}''' + ('\n' + extra if extra else '')
def h1(fn, tu, callee, st=15, cast='s16'):
    """handler: callee((cast)arg0); state st; return 3"""
    return (fn, f'''int {fn}(void)
{{
    {callee}(({cast})func_0203ac00(0));
    Unk{tu}_SetSubState({st}, {SUB});
    return 3;
}}''')
def setstate(tu, st):
    return f'Unk{tu}_SetSubState({st}, {SUB});'
