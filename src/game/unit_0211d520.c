/* Layouts and contracts below follow the delinked ARM loads and calls. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11d520Work {
    s32 state;
    s32 group;
    s32 list_count;
    s32 list_000c;
    s32 first;
    s32 list_0014;
    s32 unk_0018;
    s32 list_001c[2];
    s32 cursor[29];
    u8 pad_0098[0x10];
    u32 *unk_00a8;
    s32 count;
    s32 *flags;
    u8 pad_00b4[0x1b8];
    u32 unk_026c;
    u32 unk_0270;
    u32 unk_0274;
    u32 unk_0278[2];
    u32 unk_0280[2];
    u32 unk_0288;
    u32 unk_028c[18];
    u32 unk_02d4;
    u32 unk_02d8;
    u32 unk_02dc;
    u32 unk_02e0;
    s32 direction;
    s32 widths[11];
    s32 title_width;
    s32 delay;
} Unk11d520Work;

/* Read the selected table entry; the index at 0x18 must address the table at 0xa8. */
u32 Unk11d520_Unk_11da60(Unk11d520Work *p)
{
    return p->unk_00a8[p->unk_0018];
}

u32 func_0204fe68(u32 resource, u32 group);
u32 func_0204fed8(u32 group, u32 entry);

/* Resolve an entry in a selected group of the resource at offset 0x26c. */
u32 Unk11d520_Unk_11d520(Unk11d520Work *p, u32 entry, u32 group)
{
    u32 table = func_0204fe68(p->unk_026c, group);
    return func_0204fed8(table, entry);
}

void func_0205c408(u32 handle, u32 value);
void func_0205c6e0(u32 handle);
/* Alternate work-area view: 218 halfword IDs, count at 0x268, handles at 0x28c. */
typedef struct Unk11d520Ids {
    u8 pad[180];
    u16 ids[218];
    u32 n;
    u8 pad2[32];
    u32 h[18];
} Unk11d520Ids;
/* Append absent IDs (halfword scan, count at 0x268); caller must leave capacity. */
void Unk11d520_AddUniqueId(Unk11d520Ids *p, u32 id)
{
    int i;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (id == p->ids[i]) {
            return;
        }
    }
    p->ids[n] = id;
    p->n++;
}

/* Resolve group 4 in the resource at 0x26c, as shown by the ARM call arguments. */
u32 Unk11d520_Unk_11d838(Unk11d520Work *p, u32 entry)
{
    u32 table = func_0204fe68(p->unk_026c, 4);
    return func_0204fed8(table, entry);
}

extern u8 data_02151d18[];

/* Resolve group 0 at 0x270; a missing entry uses the original static fallback. */
int Unk11d520_Unk_11d858(Unk11d520Work *p, u32 entry)
{
    u32 table = func_0204fe68(p->unk_0270, 0);
    int result = func_0204fed8(table, entry);
    if (result == 0) {
        result = (int)data_02151d18;
    }
    return result;
}

/* Apply a value then refresh a valid indexed handle; ARM uses the table at 0x28c. */
void Unk11d520_Unk_11dde8(Unk11d520Ids *p, int i, u32 v)
{
    func_0205c408(p->h[i], v);
    func_0205c6e0(p->h[i]);
}

void func_0205ddb4(u32 handle);
void func_0205bb68(void);
void func_020629c4(u32 handle);
void func_0205c3dc(u32 handle);
void func_0205c368(u32 handle);
s32 Unk118b04_GetEntryKey(s32 id);
u32 Unk02f2a8_GetRes36Unk19(s32 key);
void func_0204fcb0(s32 slot, u32 entry);
s32 Unk118b04_Unk_118b78(s32 id);
void func_02061f10(u32 handle, s32 index, s32 x, s32 y, u32 entry);

/* Release and clear owned handles in the order observed in the ARM teardown calls. */
void func_0211d6fc(Unk11d520Work *p)
{
    int i;
    u32 j;
    if (p->unk_0288) {
        func_0205ddb4(p->unk_0288);
        p->unk_0288 = 0;
    }
    func_0205bb68();
    func_020629c4(p->unk_02dc);
    p->unk_02dc = 0;
    func_020629c4(p->unk_02d4);
    p->unk_02d4 = 0;
    func_020629c4(p->unk_02d8);
    p->unk_02d8 = 0;
    func_020629c4(p->unk_02e0);
    p->unk_02e0 = 0;
    for (i = 0; i < 18; i++) {
        if (p->unk_028c[i]) {
            func_0205c3dc(p->unk_028c[i]);
            p->unk_028c[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (p->unk_0278[i]) {
            func_0205ddb4(p->unk_0278[i]);
            p->unk_0278[i] = 0;
        }
        if (p->unk_0280[i]) {
            func_0205c368(p->unk_0280[i]);
            p->unk_0280[i] = 0;
        }
    }
    for (j = 0; j < 16; j++) {
        func_0205bb68();
    }
}

/* Record the selected ID and resolve its text; the key lookup applies to IDs >= 128. */
void func_0211da70(Unk11d520Work *p)
{
    s32 id = Unk11d520_Unk_11da60(p);
    s32 key;
    Unk11d520_AddUniqueId((Unk11d520Ids *)p, id);
    if (id >= 128) {
        key = Unk118b04_GetEntryKey(id);
        if (key >= 0) {
            func_0204fcb0(1, Unk11d520_Unk_11d838(p, Unk02f2a8_GetRes36Unk19(key)));
            func_0204fcb0(2, Unk11d520_Unk_11d858(p, key));
        }
        func_02061f10(p->unk_02e0, -1, 0, 0,
            Unk11d520_Unk_11d520(p, 128, Unk118b04_Unk_118b78(id) ? 2 : 3));
    } else {
        func_02061f10(p->unk_02e0, -1, 0, 0,
            Unk11d520_Unk_11d520(p, id, Unk118b04_Unk_118b78(id) ? 2 : 3));
    }
}

void func_0211d884(Unk11d520Work *p);
void func_0211db58(Unk11d520Work *p);
s32 func_02061a04(s32 font, u32 text, s32 mode);
void func_02053000(void *p);
s32 func_02119460(s32 group);
void *func_02052fe0(s32 size);
void func_0211955c(u32 *entries, s32 count, s32 group);
void Unk0bcef4_Unk_0bcef4(s32 *list, s32 visible, s32 count, s32 mode);
void Unk0bcef4_Unk_0bd29c(s32 *cursor, s32 *list);
void func_020bd1a8(s32 *cursor, s32 *list, s32 *flags, s32 mode);

s32 func_020537b8(s32 device, s32 mask);
s32 func_02053800(s32 device, s32 mask);
s32 func_02053824(s32 device, s32 mask);
s32 func_020bce08(s32 *list, s32 mode);
void Unk0a0ce4_Unk_0a0da4(s32 sound);
void Unk0bc1a8_SetFlag4Inv(Unk11d520Work *p, s32 enabled);
void func_0205257c(s32 mode);

/* Handle list movement, wrapped group changes and cancel; masks and state stores follow ARM. */
void func_0211e0ec(Unk11d520Work *p)
{
    s32 first, next;
    if (func_020537b8(0, 512)) p->direction = -1;
    else if (func_020537b8(0, 256)) p->direction = 1;
    else p->direction = 0;
    first = p->first;
    if (func_020bce08(&p->list_count, 1)) {
        next = p->first;
        Unk0a0ce4_Unk_0a0da4(0);
        if (next != first) func_0211d884(p);
        func_0211da70(p);
        func_020bd1a8(p->cursor, &p->list_count, p->flags, 1);
        return;
    }
    if (func_02053800(0, 512)) {
        if (--p->group < 0) p->group = 6;
        func_0211db58(p);
        Unk0a0ce4_Unk_0a0da4(11);
        Unk0bc1a8_SetFlag4Inv(p, 0);
        p->delay = 2;
        return;
    }
    if (func_02053800(0, 256)) {
        if (++p->group >= 7) p->group = 0;
        func_0211db58(p);
        Unk0a0ce4_Unk_0a0da4(11);
        Unk0bc1a8_SetFlag4Inv(p, 0);
        p->delay = 2;
        return;
    }
    if (func_02053824(0, 2)) {
        Unk0a0ce4_Unk_0a0da4(2);
        func_0205257c(3);
        p->state = 3;
        Unk0bc1a8_SetFlag4Inv(p, 0);
    }
}
void func_02063920(void);
u32 func_02063a44(u32 text, s32 slot);
u32 func_02063a30(u32 text);
s32 func_020619b8(s32 font, s32 value);

/* Resolve visible-entry text and widths; IDs >=128 use the key and resource-36 lookups. */
void func_0211d884(Unk11d520Work *p)
{
    s32 first = p->first;
    s32 i;
    u32 text, resolved;
    s32 id, group;
    func_02063920();
    for (i = 0; i < p->list_count; i++) {
        id = p->unk_00a8[first + i];
        if (id >= 128) {
            if (Unk118b04_Unk_118b78(id)) {
                id = Unk118b04_GetEntryKey(id);
                text = Unk11d520_Unk_11d520(p, 128, 0);
                resolved = func_02063a44(text, 0);
                p->widths[i] = func_02061a04(1, text, 0);
                if (id >= 0) {
                    text = Unk11d520_Unk_11d838(p, Unk02f2a8_GetRes36Unk19(id));
                    resolved = func_02063a44(text, 1);
                    p->widths[i] += func_02061a04(1, text, 0);
                    p->widths[i] += func_020619b8(1, 1);
                    text = Unk11d520_Unk_11d858(p, id);
                    resolved = func_02063a30(text);
                    p->widths[i] += func_02061a04(1, text, 0);
                }
            } else {
                text = Unk11d520_Unk_11d520(p, 128, 1);
                p->widths[i] = func_02061a04(1, text, 0);
                resolved = func_02063a30(text);
            }
        } else {
            group = Unk118b04_Unk_118b78(id);
            if (group != 0) group = 0;
            else group = 1;
            text = Unk11d520_Unk_11d520(p, id, group);
            resolved = func_02063a30(text);
            p->widths[i] = func_02061a04(1, text, 0);
        }
    }
    func_02061f10(p->unk_02d8, -1, 0, 0, resolved);
}
/* Rebuild the group's entry and flag arrays; ARM establishes the group-five title lookup. */
void func_0211db58(Unk11d520Work *p)
{
    u32 text = func_0204fed8(func_0204fe68(p->unk_026c, 5), p->group);
    s32 i, visible;
    func_02061f10(p->unk_02d4, -1, 0, 0, text);
    p->title_width = func_02061a04(1, text, 0);
    func_02053000(p->unk_00a8);
    p->unk_00a8 = 0;
    func_02053000(p->flags);
    p->flags = 0;
    p->count = func_02119460(p->group);
    p->unk_00a8 = func_02052fe0(p->count * 4);
    p->flags = func_02052fe0(p->count * 4);
    func_0211955c(p->unk_00a8, p->count, p->group);
    for (i = 0; i < p->count; i++) p->flags[i] = 1;
    visible = 11;
    if (p->count < 11) visible = p->count;
    Unk0bcef4_Unk_0bcef4(&p->list_count, visible, p->count, 1);
    Unk0bcef4_Unk_0bd29c(p->cursor, &p->list_count);
    func_020bd1a8(p->cursor, &p->list_count, p->flags, 1);
    func_0211d884(p);
    func_0211da70(p);
}
