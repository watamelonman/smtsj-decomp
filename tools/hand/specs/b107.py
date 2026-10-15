T='''void *func_{a}(int id)
{{
    {rt} key;
    void *base;
    int n;
    void *tab = func_020445d0(5, {k});
    if (tab == 0) {{
        return 0;
    }}
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.{fld} = id;
    return func_02011810(&key, base, n, {sz}, {cmp});
}}'''
SPECS=[
('src/game/unit_0209974c.c',[
('func_02099bfc', T.format(a='02099bfc', rt='Unk09974cRec8', k=0, fld='id', sz=8, cmp='Unk09974c_Unk_099860')),
('func_02099c60', T.format(a='02099c60', rt='Unk09974cRec80', k=2, fld='id', sz=80, cmp='Unk09974c_Unk_099870')),
('func_02099d14', T.format(a='02099d14', rt='Unk09974cRec56', k=1, fld='id', sz=56, cmp='Unk09974c_Unk_099880')),
('func_02099d78', T.format(a='02099d78', rt='Unk09974cRec16', k=3, fld='id', sz=16, cmp='Unk09974c_Unk_099890')),
('func_02099ddc', T.format(a='02099ddc', rt='Unk09974cRec16', k=4, fld='id', sz=16, cmp='Unk09974c_Unk_0998a0')),
],'''typedef struct Unk09974cRec8 {
    u16 id;
    u8 pad_02[6];
} Unk09974cRec8;
typedef struct Unk09974cRec16 {
    u16 id;
    u8 pad_02[14];
} Unk09974cRec16;
typedef struct Unk09974cRec56 {
    u8 pad_00[32];
    u16 id;
    u8 pad_22[22];
} Unk09974cRec56;
typedef struct Unk09974cRec80 {
    u16 id;
    u8 pad_02[78];
} Unk09974cRec80;
void *func_020445d0();
void *func_0204fde0();
int func_0204fe18();
void *func_02011810();
''',[('int func_02099d14();\n','void *func_02099d14(int id);\n'),('int func_02099bfc();\n','void *func_02099bfc(int id);\n')]),
]
