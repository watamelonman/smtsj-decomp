#include "types.h"

/* Eight-byte queue entry: ID plus dispatch choice; padding is not initialized here. */
typedef struct { u16 id; u16 pad; int primary; } Entry;
/* Task-owned queue; entries are released by its cleanup callback. */
typedef struct { int state; Entry *entries; int count; int index; } Work;
/* Borrowed lookup result; the 37-byte gap preserves the observed +0x28 packed field. */
typedef struct { u16 id; u8 kind; u8 pad[37]; u16 enabled : 1; u16 other : 15; } Record;
/* Six-byte caller-owned input; bits two and three request the two queue entry forms. */
typedef struct { u16 id; u16 pad; u8 unused : 2; u8 primary : 1; u8 secondary : 1; u8 rest : 4; u8 tail; } Input;
/* Callback descriptor view; the word at +8 belongs to the caller and is preserved. */
typedef struct { int size, mode, unused; void (*callbacks[6])(void *); } Descriptor;
extern Work *data_02176e74;
void func_02008848(void *, int, int);
void func_0211c960(void *);
void func_0211ccf8(void *);
void func_0211ce10(void *);
void BattleShowingTask_Unk_11ce80(void *);
void BattleShowingTask_Unk_11d050(void *);
void func_02065628(int);
void func_020655b4(int);
Record *func_020a1428(int);
Record *func_020a1480(int);
int func_020a14e0(Record *);
int Unk02e000_GetRecordUnk1f(int);
void func_0204faf0(int, int);
void func_020493e0(int);
void func_0206569c(void);
void func_02065b10(int, int);
int func_020654cc(void);
int func_02065cd0(void);
void func_02065c30(void);
int func_0206552c(void);
void func_02061424(Work *);
void func_02053000(void *);
void *func_02052fe0(int);
void func_020614b0(u32 *);
Work *func_020611dc(void (*)(Work *), int, int, void (*)(Work *), int, int, int, int);
void func_02065bc0(void);
void Unk0a0ce4_Unk_0a0da4(int);
void func_020615ec(u32 *, Work *);
void func_0211d200(Work *);
void Unk11d120_Unk_11d288(Work *);

/* Installs the callback descriptor; literal targets in the original establish this layout. */
void func_0211d120(Descriptor *d)
{
    d->size = 176;
    d->mode = 1;
    d->callbacks[0] = func_0211c960;
    d->callbacks[1] = func_0211ccf8;
    d->callbacks[2] = func_0211ce10;
    d->callbacks[3] = 0;
    d->callbacks[4] = BattleShowingTask_Unk_11ce80;
    d->callbacks[5] = BattleShowingTask_Unk_11d050;
}

/* Registers the borrowed 176-byte work area and clears it through the original fill routine. */
void Unk11d120_Init(Work *w)
{
    data_02176e74 = w;
    func_02008848(w, 0, 176);
}

/* Dispatches one eight-byte entry; primary entries supply record kind to slot seven. */
void Unk11d120_Unk_11d198(Entry *e)
{
    Record *r;
    func_02065628(1);
    func_020655b4(1);
    if (e->primary) {
        r = func_020a1428(e->id);
        func_0204faf0(6, e->id);
        func_0204faf0(7, r->kind);
        func_020493e0(8);
        func_0206569c();
    } else {
        func_02065b10(1, e->id);
    }
}

/* Advances a borrowed queue only after both readiness predicates succeed. */
void func_0211d200(Work *w)
{
    switch (w->state) {
    case 0:
        if (!func_020654cc()) return;
        if (!func_02065cd0()) return;
        w->index++;
        if (w->index >= w->count) {
            w->state = 1;
            func_02065c30();
        } else {
            Unk11d120_Unk_11d198(&w->entries[w->index]);
        }
        break;
    case 1:
        if (!func_0206552c()) return;
        func_02061424(w);
        break;
    }
}

/* Releases the queue allocation and clears its owning pointer. */
void Unk11d120_Unk_11d288(Work *w)
{
    func_02053000(w->entries);
    w->entries = 0;
}

/* Resolves an eligible record ID, returning zero when either record predicate excludes it. */
int func_0211d2a4(int id)
{
    Record *r = func_020a1480(id);
    if (r) {
        if (Unk02e000_GetRecordUnk1f(r->id)) return 0;
        if (func_020a14e0(r)) return r->id;
    } else {
        r = func_020a1428(id);
        if (r->enabled) {
            int other = r->other;
            if (other && Unk02e000_GetRecordUnk1f(other)) return 0;
            if (func_020a14e0(r)) return id;
        }
    }
    return 0;
}

/* Builds an owned eight-byte entry queue from six-byte input records and returns its task token. */
u32 func_0211d338(Input *input, int count, int special)
{
    u32 token;
    int total;
    Input *p;
    int i;
    Work *w;
    int n, j;
    func_020614b0(&token);
    total = 0;
    p = input;
    for (i = 0; i < count; i++, p++) {
        if (p->id) {
            if (p->primary) total++;
            if (p->secondary) {
                if (func_0211d2a4(p->id)) total++;
            }
        }
    }
    if (!special && !total) return token;
    w = func_020611dc(func_0211d200, 0, 0, Unk11d120_Unk_11d288, 16, 0, 0, 1);
    func_02065bc0();
    w->count = total;
    if (total) {
        w->entries = func_02052fe0(total * 8);
        n = 0;
        for (j = 0; j < count; j++, input++) {
            if (input->id) {
                if (input->primary) {
                    w->entries[n].id = input->id;
                    w->entries[n].primary = 1;
                    n++;
                }
                if (input->secondary) {
                    int id = func_0211d2a4(input->id);
                    if (id) {
                        w->entries[n].id = id;
                        w->entries[n].primary = 0;
                        n++;
                    }
                }
            }
            if (n >= w->count) break;
        }
        w->index = 0;
    }
    if (special) {
        w->index = -1;
        func_02065628(1);
        func_020655b4(1);
        func_020493e0(11);
        func_0206569c();
        Unk0a0ce4_Unk_0a0da4(83);
    } else {
        Unk11d120_Unk_11d198(&w->entries[w->index]);
    }
    func_020615ec(&token, w);
    return token;
}
