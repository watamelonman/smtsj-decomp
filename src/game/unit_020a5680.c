/* Entry lookup and state helpers; layouts reflect observed ARM field accesses. */
#include "types.h"


typedef struct Unk0a5680Entry {
    s32 unk_0000;
    u32 unk_0004;
    u32 handle;
    u32 id;
    u16 unk_0010;
    s8 unk_0012;
    u8 pad_0013;
    s32 unk_0014;
    s32 unk_0018;
    const void *source;
    u8 unk_0020[0x200];
} Unk0a5680Entry;

/* Six entry slots precede the signed count observed at owner +0xcc0. */
typedef struct Unk0a5680Owner {
    Unk0a5680Entry entries[6];
    volatile int count; /* Preserve each observed count read during table scans. */
    void *unk_0cc4;
} Unk0a5680Owner;
extern Unk0a5680Owner *data_02176b14;
/* Clear the global owner slot; 0x020a5718 stores zero to data_02176b14. */
void Unk0a5680_Clear_data_02176b14(void)
{
  data_02176b14 = 0;
}

extern s16 data_0213c3e0[];
Unk0a5680Entry *func_020a5680(u32 id);
/* The copy uses three arguments; existing selector forwarding also preserves r3. */
int func_02008904(const void *source, void *dest, u32 size, ...);
int func_0206f24c(void *dest, const void *source, u32 size, u32 control);
int func_02044ec4(u32 id);
int func_0204a244(int value);
extern s8 data_0213c3d4[];
u8 *func_020616c0(void *handle);
int Unk0a5680_Unk_0a572c(Unk0a5680Entry *p, u32 c);

/* Copy 512 bytes for selector -1; otherwise expand the selector-sized source. */
int Unk0a5680_Unk_0a572c(Unk0a5680Entry *p, u32 c)
{
    s32 k = p->unk_0012;
    if (k == -1) {
        return func_02008904(p->source, p->unk_0020, 512, c);
    }
    return func_0206f24c(p->unk_0020, p->source, 1 << (k + 13), c);
}

/* Refresh the signed selector from data_0213c3d4; force bypasses equality. */
int Unk0a5680_Unk_0a5778(Unk0a5680Entry *p, int force)
{
    s8 k = data_0213c3d4[func_0204a244(func_02044ec4(p->id))];
    if (p->unk_0012 == k && force == 0) {
        return 0;
    }
    p->unk_0012 = k;
    Unk0a5680_Unk_0a572c(p, 4096);
    return 1;
}

/* Return entry +0x14, or -1 when absent (loads at 0x020a5e48). */
s32 Unk0a5680_GetEntryUnk14(u32 id)
{
    Unk0a5680Entry *e = func_020a5680(id);
    if (e != 0) {
        return e->unk_0014;
    }
    return -1;
}

/* Borrow entry +0x20, or NULL when absent (address at 0x020a5e60). */
u8 *Unk0a5680_GetEntrySub20(u32 id)
{
    Unk0a5680Entry *e = func_020a5680(id);
    if (e != 0) {
        return e->unk_0020;
    }
    return 0;
}

/* Read a signed halfword; 0x020a5e78 indexes data_0213c3e0 without bounds checks. */
int Unk0a5680_Unk_0a5e78(int index)
{
  return data_0213c3e0[index];
}

u8 *Unk0a5680_Unk_0a5e28(u32 id);
/* Set resolved bytes +0x38/+0x39 to 1/0 if present (0x020a6150 stores). */
void Unk0a5680_Unk_0a6150(u32 id)
{
  u8 *value;
  value = Unk0a5680_Unk_0a5e28(id);
  if (value == 0) {
    return;
  }
  value[0x38] = 1;
  value[0x39] = 0;
}


u32 func_020a1854(u32 value);
Unk0a5680Entry *func_020a59f4(u32 value, u32 id, u32 direction);
/* Normalize the entry search result after transforming the incoming value. */
int Unk0a5680_Unk_0a5c14(u32 arg0,u32 arg1,u32 arg2)
{
  u32 value1;
  Unk0a5680Entry *value2;
  value1 = func_020a1854(arg0);
  value2 = func_020a59f4(value1,arg1,arg2);
  return value2 != 0;
}

int func_0205c41c(u32 handle, int value);
int func_0205ca88(u32 handle);
/* Resolve the handle at entry +8; 0x020a5e28 returns NULL for missing IDs. */
u8 *Unk0a5680_Unk_0a5e28(u32 id)
{
    u8 *e = (u8 *)func_020a5680(id);
    if (e == 0) {
        return 0;
    }
    return func_020616c0(e + 8);
}

/* Borrowed prefix of the resolved object; only observed offsets are exposed. */
typedef struct Unk0a5680Resolved {
    u32 handle;
    u8 pad_0004[0x34];
    u8 unk_0038;
} Unk0a5680Resolved;

/* Decrement the resolved handle value and clear its byte +0x38 if present. */
void Unk0a5680_Unk_0a611c(u32 id)
{
  Unk0a5680Resolved *v1;
  int value;
  v1 = (Unk0a5680Resolved *)Unk0a5680_Unk_0a5e28(id);
  if (v1 == 0) {
    return;
  }
  value = func_0205ca88(v1->handle);
  func_0205c41c(v1->handle,value - 1);
  v1->unk_0038 = 0;
}

void func_020a5e8c(u32 owner);
/* Forward the global owner to func_020a5e8c (tail call at 0x020a5fb0). */
void Unk0a5680_Unk_0a5fb0(void)
{
  func_020a5e8c((u32)data_02176b14);
}

/* Normalize resolved byte +0x38 to 0/1; missing IDs yield 0 (0x020a60fc). */
int Unk0a5680_Unk_0a60fc(u32 id)
{
    u8 *e = (u8 *)Unk0a5680_Unk_0a5e28(id);
    if (e != 0 && e[56] != 0) {
        return 1;
    }
    return 0;
}

/* Return the first entry with matching +0x0c ID, or NULL; owner must exist. */
Unk0a5680Entry *func_020a5680(u32 id)
{
    Unk0a5680Owner *owner = data_02176b14;
    Unk0a5680Entry *entry = owner->entries;
    int i = 0;
    for (; i < owner->count; i++, entry++) {
        if (entry->id == id) return entry;
    }
    return 0;
}

/* Return the first entry whose +0x14 word matches, or NULL; owner must exist. */
Unk0a5680Entry *func_020a56cc(s32 value)
{
    Unk0a5680Owner *owner = data_02176b14;
    Unk0a5680Entry *entry = owner->entries;
    int i = 0;
    for (; i < owner->count; i++, entry++) {
        if (entry->unk_0014 == value) return entry;
    }
    return 0;
}

/* Store the word in the next entry and advance count; caller ensures capacity. */
void func_020a59c4(u32 value)
{
    data_02176b14->entries[data_02176b14->count].unk_0000 = value;
    data_02176b14->count++;
}

void Unk065e88_SetUnkField20(void *object, float value);
/* Set resolved objects' +0x20 to float 1 or 0 according to the input flag. */
void func_020a609c(int enabled)
{
    Unk0a5680Owner **slot = &data_02176b14;
    Unk0a5680Entry *entry = (*slot)->entries;
    int i;
    float value = enabled ? 1.0f : 0.0f;
    i = 0;
    if (((Unk0a5680Owner *)entry)->count <= 0) return;
    do {
        void *object = func_020616c0(&entry->handle);
        if (object != 0) Unk065e88_SetUnkField20(object, value);
        i++;
        entry++;
    } while (i < (*slot)->count);
}

void *Unk06ea70_GetBuf00Slot(s32 index);
void Unk06ea70_SetMask10Bit(s32 index);
/* Refresh the ID's selector, copying 510 bytes only when refreshed (020a6038). */
int func_020a6038(u32 id, int force)
{
    Unk0a5680Entry *e = func_020a5680(id);
    if (e == 0) return 0;
    if (e->unk_0014 < 0) return 0;
    if (Unk0a5680_Unk_0a5778(e, force)) {
        void *dest = Unk06ea70_GetBuf00Slot(e->unk_0014);
        func_02008904(e->unk_0020, dest, 510);
        Unk06ea70_SetMask10Bit(e->unk_0014);
    }
    return 1;
}

Unk0a5680Entry *func_020a56cc(s32 value);
/* Refresh a nonnegative slot, optionally copying its 510-byte buffer (020a5fc8). */
int func_020a5fc8(s32 slot, int copy)
{
    Unk0a5680Entry *e;
    if (slot < 0) return 0;
    e = func_020a56cc(slot);
    if (e == 0) return 0;
    if (e->unk_0014 < 0) return 0;
    Unk0a5680_Unk_0a5778(e, 0);
    if (copy) {
        void *dest = Unk06ea70_GetBuf00Slot(e->unk_0014);
        func_02008904(e->unk_0020, dest, 510);
        Unk06ea70_SetMask10Bit(e->unk_0014);
    }
    return 1;
}

void func_02061424(void *object);
void Unk06ea70_ClearMask0cBit(s32 index);
void func_020614b0(u32 *handle);
/* Release each resolved object and reset its slot fields; NULL owner is allowed. */
void func_020a594c(void)
{
    Unk0a5680Entry *e = (Unk0a5680Entry *)data_02176b14;
    int i;
    if (e == 0) return;
    i = 0;
    if (((Unk0a5680Owner *)e)->count <= 0) return;
    do {
        void *object = func_020616c0(&e->handle);
        if (object != 0) func_02061424(object);
        Unk06ea70_ClearMask0cBit(e->unk_0014);
        func_020614b0(&e->handle);
        e->unk_0012 = -1;
        e->unk_0014 = -1;
        e->unk_0018 = -1;
        i++;
        e++;
    } while (i < data_02176b14->count);
}

/* Select the eligible entry with greatest signed word +0; ties keep the first. */
Unk0a5680Entry *func_020a5b98(void)
{
    Unk0a5680Entry *e = data_02176b14->entries;
    Unk0a5680Entry *best = 0;
    int i;
    for (i = 0; i < data_02176b14->count; i++, e++) {
        if (((e->id >> 16) & 255) == 0 || func_02044ec4(e->id) == 0) {
            if (best == 0 || best->unk_0000 < e->unk_0000) best = e;
        }
    }
    return best;
}

/* Test eligibility of the adjacent entry; duplicate IDs use the last index. */
int func_020a5c40(u32 id, int forward)
{
    Unk0a5680Owner *owner = data_02176b14;
    Unk0a5680Entry *e;
    int index = 0;
    int i;
    int count;
    count = owner->count;
    e = owner->entries;
    i = 0;
    if (count > 0) do {
        if (e->id == id) index = i;
        e++;
        i++;
    } while (i < owner->count);
    if (forward) {
        i = index + 1;
        if (i < count) {
            u32 next = owner->entries[i].id;
            if (((next >> 16) & 255) == 0) return 1;
            if (func_02044ec4(next) == 0) return 1;
        }
    } else {
        i = index - 1;
        if (i >= 0) {
            u32 next = owner->entries[i].id;
            if (((next >> 16) & 255) == 0) return 1;
            if (func_02044ec4(next) == 0) return 1;
        }
    }
    return 0;
}

int Unk06ea70_Unk_06ebb8(s32 index);
void Unk065e88_SetUnkField34(void *object, s32 value);
/* Update resolved +0x34 or clear stale slot fields; owner must exist (020a57c8). */
void func_020a57c8(Unk0a5680Owner *owner)
{
    Unk0a5680Entry *e = owner->entries;
    int i;
    for (i = 0; i < owner->count; i++, e++) {
        void *object = func_020616c0(&e->handle);
        if (object != 0) {
            if (Unk06ea70_Unk_06ebb8(e->unk_0014) >= 0) {
                Unk065e88_SetUnkField34(object, e->unk_0018);
            } else if (e->unk_0012 == -1) {
                Unk065e88_SetUnkField34(object, -1);
            } else {
                Unk065e88_SetUnkField34(object, e->unk_0018);
            }
        } else if (e->unk_0014 >= 0) {
            Unk06ea70_ClearMask0cBit(e->unk_0014);
            func_020614b0(&e->handle);
            e->unk_0012 = -1;
            e->unk_0014 = -1;
            e->unk_0018 = -1;
        }
    }
}

/* Borrowed resource views expose only offsets loaded at 020a5d08/020a5dac. */
typedef struct Unk0a5680Record {
    u8 pad[0x1d8];
    u16 key;
} Unk0a5680Record;
typedef struct Unk0a5680Resource {
    u8 pad[0x18c];
    const s16 *values;
    u8 tail[0x10];
} Unk0a5680Resource;
typedef struct Unk0a5680Binding {
    u32 unk_0000;
    u32 unk_0004;
    s32 unk_0008;
} Unk0a5680Binding;
Unk0a5680Resource *func_020a2250(void *context, u32 key);
void func_020615ec(u32 *handle, Unk0a5680Binding *binding);
void func_020616ec(Unk0a5680Owner *owner, Unk0a5680Binding *binding);
s32 func_0206f5cc(u32 key);
s32 Unk06ea70_GetBuf04Slot(s32 index);
/* Bind an entry and load resource/selector fields; all pointers must be valid. */
void func_020a5d08(Unk0a5680Entry *e, Unk0a5680Binding *binding, u32 id)
{
    Unk0a5680Record *record = (Unk0a5680Record *)func_02044ec4(id);
    Unk0a5680Resource *resource = func_020a2250(data_02176b14->unk_0cc4, record->key);
    func_020615ec(&e->handle, binding);
    func_020616ec(data_02176b14, binding);
    e->id = id;
    {
        u32 key = record->key;
        e->unk_0010 = key;
        e->unk_0014 = func_0206f5cc(key);
    }
    e->unk_0018 = Unk06ea70_GetBuf04Slot(e->unk_0014);
    e->source = resource + 1;
    Unk0a5680_Unk_0a5778(e, 1);
    binding->unk_0004 = e->unk_0004;
    binding->unk_0008 = resource->values[3];
}

/* Find an entry by ID, then resource value, then eligibility, and bind it. */
void func_020a5dac(Unk0a5680Binding *binding, u32 id, u32 value, u32 direction)
{
    Unk0a5680Record *record = (Unk0a5680Record *)func_02044ec4(id);
    Unk0a5680Resource *resource = func_020a2250(data_02176b14->unk_0cc4, record->key);
    u32 key = (u16)resource->values[0];
    Unk0a5680Entry *e = func_020a5680(id);
    if (e == 0) {
        e = func_020a59f4(key, value, direction);
        if (e == 0) e = func_020a5b98();
    }
    func_020a5d08(e, binding, id);
}
