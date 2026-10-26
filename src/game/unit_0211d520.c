/* Layouts and contracts below follow the delinked ARM loads and calls. */
#include "game/unit_0211d520.h"

/* Read the selected table entry; the index at 0x18 must address the table at 0xa8. */
u32 Unk11d520_Unk_11da60(Unk11d520Work *p)
{
    return p->unk_00a8[p->unk_0018];
}

/* Resolve an entry in a selected group of the resource at offset 0x26c. */
u32 Unk11d520_Unk_11d520(Unk11d520Work *p, u32 entry, u32 group)
{
    u32 table = func_0204fe68(p->unk_026c, group);
    return func_0204fed8(table, entry);
}

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

void *func_02052fe0(s32 size);

/* Resolve visible-entry text and widths; IDs >=128 use the key and resource-36 lookups. */
/* Preserve the original conditional assignment ordering. See DEC-019. */
#pragma opt_rebuildconditionals off
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
            group = Unk118b04_Unk_118b78(id) ? 0 : 1;
            text = Unk11d520_Unk_11d520(p, id, group);
            resolved = func_02063a30(text);
            p->widths[i] = func_02061a04(1, text, 0);
        }
    }
    func_02061f10(p->unk_02d8, -1, 0, 0, resolved);
}
#pragma opt_rebuildconditionals on
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

/* Allocate display handles; the 24-byte descriptor stride and resource group 5 follow ARM. */
void func_0211d540(Unk11d520Work *p)
{
    u32 j;
    s32 i;
    u8 *entry;
    u32 handle;
    func_0205ad2c(data_02151d14[2]);
    for (j = 0, entry = data_02151dd8; j < 16; j++, entry += 24)
        Unk05b82c_CreateEntry(entry);
    p->unk_0278[0] = func_0205dcd4(data_02151f58, 1);
    p->unk_0280[0] = func_0205c2c4(data_02151f64);
    p->unk_0278[1] = func_0205dcd4(data_02151f70, 1);
    p->unk_0280[1] = func_0205c2c4(data_02151f7c);
    p->unk_02dc = func_020629ac(4, 2, 0, 1);
    func_02061e98(p->unk_02dc, 16, 1);
    func_02061f10(p->unk_02dc, -1, 0, 0,
        func_0204fed8(func_0204fe68(p->unk_026c, 5), 10));
    p->unk_02d4 = func_020629ac(4, 1, 0, 1);
    func_02061e98(p->unk_02d4, 16, 1);
    handle = func_020629ac(5, 5, 0, 1);
    p->unk_02d8 = handle;
    func_02061e98(handle, 16, 1);
    p->unk_02e0 = func_020629ac(5, 5, 0, 1);
    func_02061e98(p->unk_02e0, 16, 1);
    for (i = 0; i < 18; i++) {
        p->unk_028c[i] = func_0205c3c0();
        if (i == 0 || i == 2)
            func_0205c3fc(p->unk_028c[i], p->unk_0278[1], p->unk_0280[1]);
        else
            func_0205c3fc(p->unk_028c[i], p->unk_0278[0], p->unk_0280[0]);
    }
    Unk02e000_Unk_02e0cc();
    Unk05b82c_Unk_05b82c(57);
    p->unk_0288 = func_0205dcd4(data_02151f88, 1);
}

/* Clear only the fields consumed by the slot provider, preserving its padding contract. */
static inline void Unk11d520_ClearRequest(Unk11d520Request *r)
{
    s32 i;
    for (i = 0; i < 2; i++) r->flags[i] = 0;
    for (i = 0; i < 16; i++) r->words[i] = 0;
}

/* Initialize state zero's display and slot ten; state one enables the owner callback. */
void func_0211dc74(Unk11d520Work *p, const s32 *state)
{
    switch (*state) {
    case 0: {
        Unk11d520Request r;
        Unk0bc1a8_SetFlag4Inv(p, 0);
        func_0211d540(p);
        func_0211db58(p);
        if (Unk0bc1a8_IsSlotEmpty(10)) {
            Unk11d520_ClearRequest(&r);
            Unk0bc1a8_Unk_0bc928(10, Unk0bc1a8_GetHeaderWord(p), &r);
        }
        func_020e7f44(0, 0, 0, 12);
        Unk0e7ac4_Unk_0e8000(1);
        Unk11d520_ClearRequest(&r);
        r.words[1] = 1;
        r.flags[0] |= 2;
        func_020bcbc4(10, &r);
        func_020525cc(3);
        break;
    }
    case 1: {
        Unk11d520Request r;
        Unk11d520_ClearRequest(&r);
        Unk0bc1a8_Unk_0bc514(p, 1, &r);
        break;
    }
    case 2: case 3: case 4: break;
    }
}

/* Advance display phases, wait for handles, and clear recorded ID flags on teardown. */
void func_0211de14(Unk11d520Work *p)
{
    s32 ready;
    u32 j;
    s32 i;
    Unk0bcef4_Unk_0bd388(p->cursor, &p->list_count);
    switch (p->state) {
    case 0:
        if (func_02052728()) return;
        p->state = 1;
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 0, 0);
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 3, 0);
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 1, 2);
        break;
    case 1:
        ready = 1;
        for (j = 0; j < 3; j++) {
            if (func_0205c704(p->unk_028c[data_0213cd1c[j]])) ready = 0;
        }
        if (!ready) return;
        Unk0bc1a8_SetFlag4Inv(p, 1);
        p->state = 2;
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 2, 1);
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 3, 1);
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 4, 9);
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 5, 6);
        Unk11d520_Unk_11dde8((Unk11d520Ids *)p, 6, 7);
        for (i = 7; i <= 17; i++) Unk11d520_Unk_11dde8((Unk11d520Ids *)p, i, 8);
        break;
    case 2:
        for (i = 2; i < 18; i++) func_0205c704(p->unk_028c[i]);
        if (!func_0205b36c(*(u32 *)p->unk_02d4)) return;
        if (!func_0205b36c(*(u32 *)p->unk_02d8)) return;
        if (!func_0205b36c(*(u32 *)p->unk_02e0)) return;
        if (p->delay == 0) return;
        if (--p->delay != 0) return;
        Unk0bc1a8_SetFlag4Inv(p, 1);
        break;
    case 3: {
        Unk11d520Request r;
        if (func_02052728()) return;
        Unk11d520_ClearRequest(&r);
        Unk0bc1a8_Unk_0bc9b4(10, &r);
        func_0211d6fc(p);
        p->state = 4;
        for (i = 0; i < (s32)((Unk11d520Ids *)p)->n; i++)
            Unk118b04_ClearFlag2(((Unk11d520Ids *)p)->ids[i]);
        break;
    }
    case 4: {
        Unk11d520Request r;
        Unk11d520_ClearRequest(&r);
        Unk0bc1a8_Unk_0bc9b4(Unk0bc1a8_GetHeaderWord(p), &r);
        break;
    }
    }
}

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

/* Draw state-dependent list and selected-entry text; ARM supplies layer 2 and row spacing 13. */
void func_0211e260(Unk11d520Work *p)
{
    Unk11d520Rect rect;
    Unk11d520Rect detail;
    Unk11d520Rect row;
    s32 selected, i, id, index;
    if (p->state == 4) return;
    func_020580ec(0);
    func_02057524(0);
    Unk_LoadPalette_020de678(p->unk_0288);
    func_02057534();
    func_02057df8();
    func_02057e18(31);
    switch (p->state) {
    case 0: case 1:
        func_0205c748(2, p->unk_028c[0], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        break;
    case 2: case 3:
        func_0205de40(2, p->unk_0278[1], 0, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
        if (p->group == 0) {
            func_02057e18(31);
            if (p->delay == 0) {
                func_02057ddc(0xffffff);
                index = p->unk_0018 - p->first;
                func_02060dd4(&rect, p->unk_02d8, 0, index, 22);
                rect.d = rect.c + p->widths[index];
                func_02059f70(*(u32 *)p->unk_02d8, 0x1000001, 128, 8, &rect, 0, 10);
                func_02057df8();
                func_02060dd4(&detail, p->unk_02e0, 0, 0, 22);
                func_02059f70(*(u32 *)p->unk_02e0, 1, 14, 27, &detail, 0, 10);
            }
            func_02057ddc(255);
            func_02057fd8();
            func_0205dee8(2, p->unk_0278[1], 15, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
            selected = Unk11d520_Unk_11da60(p);
            for (i = 0; i < p->count; i++) {
                id = p->unk_00a8[i];
                if (Unk118b04_Unk_118b78(id)) {
                    if (id == selected) func_02057df8();
                    else func_02057ddc(0x292929ff);
                    func_0205de40(2, p->unk_0278[1], i + 3, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
                }
            }
        } else {
            if (Unk118b04_Unk_118b78(Unk11d520_Unk_11da60(p))) {
                func_0205de40(2, p->unk_0278[1], 2, 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
                func_0205c748(2, p->unk_028c[2], 0, 0, 1.0f, 1.0f, 0, 1.0f, 5);
            }
            func_02057e18(31);
            func_02057df8();
            func_02060dd4(&rect, p->unk_02dc, 0, 1, 10);
            func_02059f70(*(u32 *)p->unk_02dc, 1, 14, 27, &rect, 0, 10);
            if (p->delay == 0) {
                func_02057ddc(0xffffff);
                index = p->unk_0018 - p->first;
                func_02060dd4(&rect, p->unk_02d8, 0, index, 22);
                rect.d = rect.c + p->widths[index];
                func_02059f70(*(u32 *)p->unk_02d8, 0x1000001, 128, 8, &rect, 0, 10);
                func_02057df8();
                for (s32 line = 0; line < 10; line++) {
                    func_02060dd4(&row, p->unk_02e0, 0, line, 22);
                    func_02059f70(*(u32 *)p->unk_02e0, 1, 24, 49 + line * 13, &row, 0, 10);
                }
            }
        }
        break;
    }
    func_020580ec(1);
}
