/* Layouts and contracts below follow the delinked ARM loads and calls. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11d520Work {
    u8 pad_0000[0x18];
    s32 unk_0018;
    u8 pad_001c[0x8c];
    u32 *unk_00a8;
    u8 pad_00ac[0x1c0];
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
