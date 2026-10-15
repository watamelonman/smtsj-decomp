SPECS=[
('src/game/unit_020946e0.c',[
('func_020949e0','''void func_020949e0(int a)
{
    u8 *v = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    s32 x = (FIELD(s32, v, 4) << 12) / 32;
    s32 y = (FIELD(s32, v, 8) << 12) / 32;
    s32 w = (FIELD(s16, v, 16) << 14) / 256;
    s32 h = (FIELD(s16, v, 18) * 12288) / 192;
    func_020575ac(a, h - y, -(h + y), x - w, x + w);
}'''),
('func_02094a90','''void func_02094a90(int a)
{
    u8 *v = (u8 *)Unk0946e0_GetAddr_data_02175d94();
    func_02057678(a, FIELD(u32, v, 4), FIELD(u32, v, 8));
    func_02057628(a, ((FIELD(s16, v, 16) - 256) / 2) << 12, ((FIELD(s16, v, 18) - 192) / 2) << 12);
}'''),
],'''#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020575ac();'''),
]
