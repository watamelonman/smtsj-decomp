/*
 * src/game/unit_02094fe0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk094fe0Timer {
    u16 id;
    u8 cnt;
    u8 flag;
} Unk094fe0Timer;

typedef struct Unk094fe0Work {
    u8 pad_0000[0x200];
    u8 unk_0200[0x780];         /* +0x200: bit array, 15360 bits from the bounds checks */
    Unk094fe0Timer timers[4];   /* +0x980: count from the < 4 bounds */
    u8 pad_0990[0x10];
    u32 unk_09a0;
    Unk094fe0Timer unk_09a4;
} Unk094fe0Work;

/* 28-byte record from Unk094fe0_Unk_094fec (stride 0x1c); slots[5] from the < 5 bounds. */
typedef struct Unk094fe0Record {
    u32 unk_0000;
    u32 slots[5];
    u32 unk_0018;
} Unk094fe0Record;

extern u8 data_02175dac[];
Unk094fe0Work *Unk02e000_GetUnk094fe0Work(void);

u8 *Unk094fe0_Nop_095000(Unk094fe0Work *w);
u8 *Unk094fe0_Unk_095004(Unk094fe0Work *w);
u32 Unk094fe0_GetUnkField9a0(const Unk094fe0Work *obj);
Unk094fe0Work *Unk094fe0_Thunk_0202e8cc(void);
u8 *Unk094fe0_Unk_094fec(int index);

/* Borrow the work byte view unchanged: 0x02095000 is only bx lr. */
u8 *Unk094fe0_Nop_095000(Unk094fe0Work *w) { return (u8 *)w; }

/* Borrow the +0x990 bit-array view; the add at 0x02095004 proves the offset. */
u8 *Unk094fe0_Unk_095004(Unk094fe0Work *w)
{
    return (u8 *)w + 0x990;
}

int Unk094fe0_TestBit(Unk094fe0Work *w, u32 a);
int Unk094fe0_TestBit990(Unk094fe0Work *w, u32 a);
/* Query the work bit selected by a; 0x020950ac calls TestBit with that index. */
int Unk094fe0_Call_020950b4(u32 a)
{
    return Unk094fe0_TestBit(Unk094fe0_Thunk_0202e8cc(), a);
}

/* Test bit a-1 of the shared work's +0x990 bit array; tail of 0x02095308 calls TestBit990. */
int Unk094fe0_Call_02095320(u32 a)
{
    return Unk094fe0_TestBit990(Unk094fe0_Thunk_0202e8cc(), a);
}

/* Read a valid borrowed work object; ldr at 0x020953bc proves the +0x9a0 field. */
u32 Unk094fe0_GetUnkField9a0(const Unk094fe0Work *obj) { return obj->unk_09a0; }

/* Borrow the shared work pointer via the tail-call literal at 0x02094fe8. */
Unk094fe0Work *Unk094fe0_Thunk_0202e8cc(void) { return Unk02e000_GetUnk094fe0Work(); }

/* Borrow an unchecked record address; 0x02094ff4 scales index by 28.
 * The table extent and record meaning are unknown; callers must supply a valid index.
 */
u8 *Unk094fe0_Unk_094fec(int index)
{
    return data_02175dac + index * 0x1c;
}

void Unk094fe0_Unk_09502c(Unk094fe0Work *w, int a, int b);
/* Forward (a, b) with the shared work pointer to Unk094fe0_Unk_09502c (calls at 0x02095018/0x02095024). */
void Unk094fe0_Call_0209502c(int a, int b)
{
    Unk094fe0_Unk_09502c(Unk094fe0_Thunk_0202e8cc(), a, b);
}

int func_020950e4(u8 *bits, u32 bit, int set);
void func_020e6708(int bit, int value);
void *Unk02e000_GetWorkArea(void);

/* Update a leading-array bit and notify 0x020e6708; the switch at
 * 0x02095060 raises work-area byte +0x357 for indices 0x70c/0x70d. */
void Unk094fe0_Unk_09502c(Unk094fe0Work *w, int a, int b)
{
    u8 v;
    func_020950e4(Unk094fe0_Nop_095000(w), a, b);
    func_020e6708(a, b);
    v = ((u8 *)Unk02e000_GetWorkArea())[855];
    switch (a) {
    case 0x70c:
        if (v < 10) {
            v = 10;
        }
        break;
    case 0x70d:
        if (v < 12) {
            v = 12;
        }
        break;
    }
    ((u8 *)Unk02e000_GetWorkArea())[855] = v;
}

/* Return 1 if bit `bit` of the work's leading 512-byte bit array (the Nop_095000 view) is set;
 * 0 if clear or bit >= 4096 (the index >= 512 check). */
int Unk094fe0_TestBit(Unk094fe0Work *w, u32 bit)
{
    u32 sh = bit & 7;
    u32 idx = bit >> 3;
    u8 *bits = Unk094fe0_Nop_095000(w);
    if (idx >= 512) {
        return 0;
    }
    return (bits[idx] & (1 << sh)) != 0;
}

void Unk094fe0_Unk_095370(Unk094fe0Work *w, u32 a, int b);
/* Return 1 if bit `bit` (0..31) of the record's +0x18 flag word is set; 0 for a null record,
 * an out-of-range bit or a clear bit. */
int Unk094fe0_TestFlag18(const Unk094fe0Record *p, int bit)
{
    if (p == 0) {
        return 0;
    }
    if (bit < 0 || bit > 31) {
        return 0;
    }
    return (p->unk_0018 & (1 << bit)) != 0;
}

/* Store v in slot i (0..4) of a record; ignores a null record or out-of-range slot. */
void Unk094fe0_SetSlot(Unk094fe0Record *p, int i, u32 v)
{
    if (p == 0) {
        return;
    }
    if (i < 0 || i >= 5) {
        return;
    }
    p->slots[i] = v;
}

/* Return slot i (0..4) of a record, or 0 for a null record or out-of-range slot.
 * Counterpart of Unk094fe0_SetSlot; unit_0203aae8 reads the result as an s16. */
u32 Unk094fe0_GetSlot(const Unk094fe0Record *p, int i)
{
    if (p == 0) {
        return 0;
    }
    if (i < 0 || i >= 5) {
        return 0;
    }
    return p->slots[i];
}

/* Set (b == 1) or clear bit a of the shared work's +0x200 bit array; ignores a >= 15360. */
void Unk094fe0_Unk_095204(u32 a, int b)
{
    if (a >= 15360) {
        return;
    }
    func_020950e4(Unk094fe0_Thunk_0202e8cc()->unk_0200, a, b);
}

/* Return 1 if bit a of w's +0x200 bit array is set, 0 if clear or a >= 15360. */
int Unk094fe0_TestBit200(Unk094fe0Work *w, u32 a)
{
    if (a >= 15360) {
        return 0;
    }
    return (w->unk_0200[a >> 3] & (1 << (a & 7))) != 0;
}

void Unk0e651c_SetBitChecked();
int Unk02f2a8_Unk_035b08(int cnt, int flag);
int Unk09ee4c_Thunk_02118c6c(int value);

/* Arm countdown slot i (0..3) of the shared work with (id, cnt). Returns 1 on success, 0 if
 * i >= 4, id >= 4096 or cnt == 0. Unk094fe0_Unk_0952ac ticks these slots down. */
int Unk094fe0_Unk_095258(u32 i, u32 id, u8 cnt)
{
    Unk094fe0Timer *t;
    if (i >= 4) {
        return 0;
    }
    if (id >= 4096) {
        return 0;
    }
    if (cnt == 0) {
        return 0;
    }
    t = Unk094fe0_Thunk_0202e8cc()->timers;
    t[i].id = id;
    t[i].cnt = cnt;
    return 1;
}

/* Tick the four countdown slots of the shared work down by one. When a slot reaches 0, its id is
 * passed with 1 to Unk0e651c_SetBitChecked. */
void Unk094fe0_Unk_0952ac(void)
{
    Unk094fe0Timer *t = Unk094fe0_Thunk_0202e8cc()->timers;
    int i;
    for (i = 0; i < 4; i++) {
        if (t[i].cnt != 0) {
            if (--t[i].cnt == 0) {
                t[i].cnt = 0;
                Unk0e651c_SetBitChecked(t[i].id, 1);
            }
        }
    }
}

/* Return 1 if bit a-1 of the work's +0x990 bit array is set; 0 if clear or a is outside 1..128. */
int Unk094fe0_TestBit990(Unk094fe0Work *w, u32 a)
{
    u32 i = a - 1;
    u8 *bits;
    if (i >= 128) {
        return 0;
    }
    bits = Unk094fe0_Unk_095004(w);
    return (bits[i >> 3] & (1 << (i & 7))) != 0;
}

/* Forward (a, b) with the shared work pointer to Unk094fe0_Unk_095370. */
void Unk094fe0_Call_02095370(u32 a, int b)
{
    Unk094fe0_Unk_095370(Unk094fe0_Thunk_0202e8cc(), a, b);
}

/* Set (b == 1) or clear bit a-1 of w's +0x990 bit array; ignores a outside 1..128. */
void Unk094fe0_Unk_095370(Unk094fe0Work *w, u32 a, int b)
{
    u32 i = a - 1;
    if (i >= 128) {
        return;
    }
    func_020950e4(Unk094fe0_Unk_095004(w), i, b);
}

/* Store a word in shared work; str at 0x020953a4 proves the +0x9a0 field. */
void Unk094fe0_SetUnkField9a0(u32 value)
{
    Unk094fe0_Thunk_0202e8cc()->unk_09a0 = value;
}

/* Store (cnt, flag, id) into the shared work's +0x9a4 record that Unk094fe0_Unk_0953f0 consumes
 * (strb +0x9a6, strb +0x9a7, strh +0x9a4 in that order). */
void func_020953c4(u32 cnt, u32 flag, u32 id)
{
    Unk094fe0Timer *t = &Unk094fe0_Thunk_0202e8cc()->unk_09a4;
    t->cnt = cnt;
    t->flag = flag;
    t->id = id;
}

/* Read shared work through the getter, as the two calls at 0x020953b0 show. */
u32 Unk094fe0_GetWorkUnkField9a0(void)
{
    return Unk094fe0_GetUnkField9a0(Unk094fe0_Thunk_0202e8cc());
}

/* Consume the +0x9a4 record only when all fields and the 0x02118c6c
 * predicate are nonzero; 0x02095450 sets its id bit before clearing the id. */
int Unk094fe0_Unk_0953f0(void)
{
    Unk094fe0Timer *t = &Unk094fe0_Thunk_0202e8cc()->unk_09a4;
    u8 cnt = t->cnt;
    u8 flag;
    u16 id;
    if (cnt == 0) {
        return 0;
    }
    flag = t->flag;
    if (flag == 0) {
        return 0;
    }
    id = t->id;
    if (id == 0) {
        return 0;
    }
    if (Unk09ee4c_Thunk_02118c6c(Unk02f2a8_Unk_035b08(cnt, flag)) == 0) {
        return 0;
    }
    t->cnt = 0;
    t->flag = 0;
    Unk0e651c_SetBitChecked(t->id, 1);
    t->id = 0;
    return 1;
}

int Unk0e5fb8_Unk_0e61e8(Unk094fe0Work *work, int row, u8 column);
void Unk0e5fb8_Unk_0e622c(Unk094fe0Work *work, int row, u8 column);

/* Merge selected set bits from source into destination. The table at 0x0213bdbc,
 * 15-by-10 loop at 0x020954d8 and 128-index loop at 0x02095524 establish
 * the three ranges; clear source bits leave destination unchanged. */
void func_02095468(Unk094fe0Work *destination, Unk094fe0Work *source)
{
    u32 bits[7] = {1024, 1025, 1026, 1027, 1803, 1804, 1805};
    u32 i;
    int column;
    for (i = 0; i < 7; i++) {
        u32 bit = bits[i];
        if (Unk094fe0_TestBit(source, bit)) {
            Unk094fe0_Unk_09502c(destination, bit, 1);
        }
    }
    for (i = 0; (int)i < 15; i++) {
        for (column = 0; column < 10; column++) {
            if (Unk0e5fb8_Unk_0e61e8(source, i, column)) {
                Unk0e5fb8_Unk_0e622c(destination, i, column);
            }
        }
    }
    for (i = 0; i < 128; i++) {
        if (Unk094fe0_TestBit990(source, i)) {
            Unk094fe0_Unk_095370(destination, i, 1);
        }
    }
}
