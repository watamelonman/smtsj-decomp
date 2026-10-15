P='''void *func_020445d0();
u8 *func_0204fde0();
int func_02035890();
void func_020362c8();

typedef struct Unk02f2a8Res36 {
    u8 pad_0000[0x19];
    s8 unk_0019;
    s8 unk_001a;
    s8 unk_001b[0xd];
} Unk02f2a8Res36;               /* 40 bytes; entries of resource 36 */

typedef struct Unk02f2a8Pos {
    u16 unk_0000;
    s8 unk_0002;
    s8 unk_0003;
    u32 unk_0004;
} Unk02f2a8Pos;

#define UNK02F2A8_RES36() ((Unk02f2a8Res36 *)func_0204fde0(func_020445d0(36, 0)))'''
def gsopt(fn, off):
    return (fn, f'''u8 *{fn}(void)
{{
    GameState *gs = gGameState;
    if (gs == 0) {{
        return 0;
    }}
    if (FIELD(u32, gs, {off}) != 0) {{
        return (u8 *)gs + {off};
    }}
    return 0;
}}''')
SPECS=[('src/game/unit_0202f2a8.c',[
('func_02034ad4','''void func_02034ad4(u32 a, u32 b)
{
    FIELD(u32, gGameState->root, 0x60) = 1;
    FIELD(u32, gGameState->root, 0x64) = a;
    FIELD(u32, gGameState->root, 0x68) = b;
}'''),
('func_02034d5c','''void func_02034d5c(u16 a, u8 b, u8 c)
{
    FIELD(u32, gGameState, 0x7470) = 1;
    FIELD(u16, gGameState, 0x7474) = a;
    FIELD(u8, gGameState, 0x7476) = b;
    FIELD(u8, gGameState, 0x7477) = c;
}'''),
gsopt('func_020353cc','0x240'),
gsopt('func_020353f8','0x2cc'),
('func_02035a70','''int func_02035a70(int a)
{
    Unk02f2a8Pos pos = {0};
    int r = func_02035890(&pos, a);
    func_020362c8(pos.unk_0000);
    func_02036318(pos.unk_0002, pos.unk_0003, pos.unk_0004);
    return r;
}'''),
('func_02035ab8','''s8 func_02035ab8(int i)
{
    return UNK02F2A8_RES36()[i].unk_0019;
}'''),
('func_02035ae0','''s8 func_02035ae0(int i)
{
    return UNK02F2A8_RES36()[i].unk_001a;
}'''),
('func_02035bd8','''int func_02035bd8(int i, int j)
{
    Unk02f2a8Res36 *e = &UNK02F2A8_RES36()[i];
    s8 v = e->unk_001b[j];
    int r = -1;
    if (v >= 0) {
        r = v;
    }
    return r;
}'''),
],P,[('int func_02034ad4();\n','void func_02034ad4();\n')])]
