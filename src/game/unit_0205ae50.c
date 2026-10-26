/*
 * Matched singleton, VCOUNT and transfer-queue helpers (see function docs).
 * Private layouts expose only offsets established by the original instructions.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk05ae50Work {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
    struct Unk05ae50Work *unk_0014;
    u8 pad_0018[0x41];
    u8 unk_0059;
} Unk05ae50Work;

extern u8 data_0216a184[];
void func_02053000(u32 resource);
Unk05ae50Work *func_0205ad9c(void);
u8 *func_0205ae60(Unk05ae50Work *work);
int func_0205b36c(Unk05ae50Work *work);

void Unk05ae50_Unk_05b228(Unk05ae50Work *work);
void Unk05ae50_Unk_05ae50(void);
void Unk05ae50_Unk_05b388(void);
void Unk05ae50_Unk_05afd8(u32 arg0);
int Unk05ae50_Unk_05b358(const Unk05ae50Work *work);
u32 Unk05ae50_Unk_05af3c(Unk05ae50Work *work);

void func_02008848(void *destination, int value, u32 size);
int func_02052624(void);
void Unk05ae50_Unk_05af64(int *arg0);
/* VCOUNT reads establish the 191..213 window; clamp and align the byte limit. */
int Unk05ae50_Unk_05afec(int x)
{
    s32 vc = *(volatile u16 *)0x04000006;
    int lim;
    if (vc < 191 || vc > 213) {
        return 0;
    }
    lim = FIELD(s32, data_0216a184, 0x5a8);
    if (lim < x) {
        x = lim;
    }
    return x & ~3;
}

/* Clear the singleton and set its aligned limit to 0x18000 (call evidence). */
void Unk05ae50_Reset(void)
{
    func_02008848(data_0216a184, 0, 0x5ac);
    Unk05ae50_Unk_05afd8(0x18000);
}

/* Set the byte at +0x59; the original STRB provides no stronger meaning. */
void Unk05ae50_Unk_05b228(Unk05ae50Work *work)
{
  work->unk_0059 = 1;
}

/* Forward the borrowed singleton to func_0205ae60, as in the original calls. */
void Unk05ae50_Unk_05ae50(void)
{
  func_0205ae60(func_0205ad9c());
}

/* Below helper result 31, wait for VCOUNT 191..213 before the transfer calls. */
void Unk05ae50_WaitVCountThen_05af64(int *x)
{
    if (func_02052624() < 31) {
        while ((s32)*(volatile u16 *)0x04000006 < 191 || (s32)*(volatile u16 *)0x04000006 > 213) {
        }
        Unk05ae50_Unk_05af64(x);
    } else {
        Unk05ae50_Unk_05af64(x);
    }
}

/* Query the singleton through its +0x14 link; original forwards R0 unchanged. */
void Unk05ae50_Unk_05b388(void)
{
  func_0205b36c(func_0205ad9c());
}

/* Store a four-byte-aligned limit at singleton +0x5a8 (BIC/STR evidence). */
void Unk05ae50_Unk_05afd8(u32 arg0)
{
  FIELD(u32, data_0216a184, 0x5a8) = arg0 & 0xfffffffc;
}

/* Normalize the byte at +0x59 to 0 or 1; work must be non-null. */
int Unk05ae50_Unk_05b358(const Unk05ae50Work *work)
{
  return work->unk_0059 != 0;
}

/* Original LDR +0x14 and null guard establish an optional borrowed work link. */
int func_0205b36c(Unk05ae50Work *work)
{
  if (work->unk_0014 == 0) {
    return 0;
  }
  return Unk05ae50_Unk_05b358(work->unk_0014);
}

/* Pass +0x10 to func_02053000, clear +0x10/+8/+0xc, and return success. */
u32 Unk05ae50_Unk_05af3c(Unk05ae50Work *work)
{
  func_02053000(work->unk_0010);
  work->unk_0010 = 0;
  work->unk_0008 = 0;
  work->unk_000c = 0;
  return 1;
}



void func_02005334(void);
void func_02005390(int source, int destination, int size);
void func_020054d0(void);
void func_0200551c(void);
void func_02005550(int source, int destination, int size);
void func_020055bc(void);
void func_02006c94(int source, int size);
u32 func_02007a58(void);
void func_02007a6c(u32 state);
/* Six descriptor words feed the two guarded call groups; restore saved state. */
void Unk05ae50_Unk_05af64(int *arg0)
{
  u32 tmp1;
  tmp1 = func_02007a58();
  if (*arg0 != 0) {
    func_02005334();
    func_02006c94(*arg0,arg0[2]);
    func_02005390(*arg0,arg0[1],arg0[2]);
    func_020054d0();
  }
  if (arg0[3] != 0) {
    func_0200551c();
    func_02006c94(arg0[3],arg0[5]);
    func_02005550(arg0[3],arg0[4],arg0[5]);
    func_020055bc();
  }
  func_02007a6c(tmp1);
  return;
}

/* Apply the clearing helper to the borrowed singleton (original call pair). */
void Unk05ae50_Unk_05af2c(void)
{
    Unk05ae50_Unk_05af3c((Unk05ae50Work *)func_0205ad9c());
}

/* Nine-word queue records: callback offsets come from LDR +0x1c/+0x20. */
typedef struct Unk05ae50Entry {
    int transfer[6];
    u32 unk_0018;
    void (*callback)(void *);
    void *argument;
} Unk05ae50Entry;

/* Forty 36-byte slots precede the two indices in data_0216a184. */
typedef struct Unk05ae50Queue {
    Unk05ae50Entry entries[40];
    int read;
    int write;
} Unk05ae50Queue;

/* Borrowed request prefix; +0x10 supplies data, +0x14 records the work. */
typedef struct Unk05ae50Request {
    u32 unk_0000[2];
    u32 unk_0008;
    u32 unk_000c;
    u8 *unk_0010;
    Unk05ae50Work *work;
} Unk05ae50Request;

int func_0205b02c(Unk05ae50Entry *entry);
void func_0205aa78(void *bounds, int *first, int *second, s16 *third, s16 *fourth);
void func_0205ac68(Unk05ae50Work *work, u32 first, u32 second, void *data);
int func_0205accc(void *resource);
int func_0205acd4(void *resource);
void func_0205b234(Unk05ae50Entry *entry, void (*callback)(Unk05ae50Work *), Unk05ae50Work *work);

/* Drain successful slots and invoke their callbacks during the VCOUNT window.
 * The original compares 191/213 on entry, 211 between entries, and wraps at 40. */
void func_0205b154(void)
{
    u32 state = func_02007a58();
    if ((s32)*(volatile u16 *)0x04000006 >= 191 &&
        (s32)*(volatile u16 *)0x04000006 <= 213) {
        while (((Unk05ae50Queue *)data_0216a184)->read !=
               ((Unk05ae50Queue *)data_0216a184)->write) {
            int index;
            Unk05ae50Entry *entry = &((Unk05ae50Queue *)data_0216a184)->entries[
                ((Unk05ae50Queue *)data_0216a184)->read];
            if (!func_0205b02c(entry)) break;
            if (entry->callback != 0) entry->callback(entry->argument);
            index = ((Unk05ae50Queue *)data_0216a184)->read + 1;
            if (index == 40) index = 0;
            ((Unk05ae50Queue *)data_0216a184)->read = index;
            if ((s32)*(volatile u16 *)0x04000006 >= 211) break;
        }
    }
    func_02007a6c(state);
}

/* Bind an unused request to work, then queue its six-word descriptor.
 * Guards and the +12 data adjustment are taken directly from the original. */
void func_0205b398(Unk05ae50Work *work, Unk05ae50Request *request)
{
    Unk05ae50Entry entry;
    int first, second;
    if (request->work != 0) return;
    if (request->unk_0010 == 0) return;
    func_0205ac68(work, request->unk_0008, request->unk_000c, request->unk_0010 + 12);
    request->work = work;
    work->unk_0059 = 0;
    func_0205aa78((u8 *)work + 24, &first, &second, 0, 0);
    entry.transfer[0] = work->unk_000c;
    entry.transfer[1] = work->unk_0000;
    entry.transfer[2] = first;
    entry.transfer[3] = work->unk_0010;
    entry.transfer[4] = work->unk_0004;
    entry.transfer[5] = second;
    func_0205b234(&entry, Unk05ae50_Unk_05b228, work);
}

/* Queue the descriptor using resource helper results; +0x59 is cleared until
 * the callback sets it, as established by the original STRB and relocation. */
void func_0205b444(Unk05ae50Work *work, void *resource)
{
    Unk05ae50Entry entry;
    int first, second;
    work->unk_0059 = 0;
    func_0205aa78((u8 *)work + 24, &first, &second, 0, 0);
    entry.transfer[0] = func_0205accc(resource);
    entry.transfer[1] = work->unk_0000;
    entry.transfer[2] = first;
    entry.transfer[3] = func_0205acd4(resource);
    entry.transfer[4] = work->unk_0004;
    entry.transfer[5] = second;
    func_0205b234(&entry, Unk05ae50_Unk_05b228, work);
}

/* Submit the same descriptor synchronously through the VCOUNT wrapper,
 * then set +0x59; the original call and STRB establish the completion order. */
void func_0205b4c4(Unk05ae50Work *work, void *resource)
{
    Unk05ae50Entry entry;
    int first, second;
    work->unk_0059 = 0;
    func_0205aa78((u8 *)work + 24, &first, &second, 0, 0);
    entry.transfer[0] = func_0205accc(resource);
    entry.transfer[1] = work->unk_0000;
    entry.transfer[2] = first;
    entry.transfer[3] = func_0205acd4(resource);
    entry.transfer[4] = work->unk_0004;
    entry.transfer[5] = second;
    Unk05ae50_WaitVCountThen_05af64(entry.transfer);
    work->unk_0059 = 1;
}

const char *func_0205ad6c(void);
void func_02015134(char *destination, const char *source);
void func_0201524c(char *destination, const char *source);
int func_020519f0(void *result, const char *path);
u8 *func_02051610(const char *path);
extern const char data_02143bcc[], data_02143bd4[];

/* Build a path with the two original suffix relocations, load it, and expose
 * its payload ranges at work +8/+12. Work is borrowed and must be valid. */
u8 *func_0205ae60(Unk05ae50Work *work)
{
    char path[64];
    int first;
    u32 result[2];
    u8 *resource;
    int size;
    func_02015134(path, func_0205ad6c());
    func_0201524c(path, (const char *)work->unk_0004);
    func_0201524c(path, data_02143bcc);
    if (!func_020519f0(result, path)) {
        func_02015134(path, func_0205ad6c());
        func_0201524c(path, (const char *)work->unk_0004);
        func_0201524c(path, data_02143bd4);
    }
    resource = func_02051610(path);
    if (!resource) return 0;
    func_0205aa78(resource + 12, &first, 0, 0, 0);
    size = (u32)(resource + 28) + first;
    work->unk_0008 = (u32)(resource + 28);
    work->unk_000c = size;
    work->unk_0010 = (u32)resource;
    return resource;
}

/* Advance the borrowed descriptor within the VCOUNT byte limit. Original
 * unsigned comparisons place group two before group one in cumulative progress. */
int func_0205b02c(Unk05ae50Entry *entry)
{
    u32 remaining;
    int amount;
    int complete;
    if (entry->unk_0018 >= (u32)(entry->transfer[2] + entry->transfer[5])) return 1;
    if (entry->transfer[3] && entry->unk_0018 < (u32)entry->transfer[5]) {
        remaining = entry->transfer[5] - entry->unk_0018;
        amount = Unk05ae50_Unk_05afec(remaining);
        if (amount > 0) {
            remaining = entry->transfer[5] - remaining;
            func_0200551c();
            func_02006c94(entry->transfer[3], entry->transfer[5]);
            func_02005550(entry->transfer[3] + remaining, entry->transfer[4] + remaining, amount);
            func_020055bc();
            entry->unk_0018 += amount;
        }
    }
    if (entry->transfer[0] && entry->unk_0018 < (u32)(entry->transfer[2] + entry->transfer[5])) {
        remaining = entry->transfer[2] + entry->transfer[5] - entry->unk_0018;
        amount = Unk05ae50_Unk_05afec(remaining);
        if (amount > 0) {
            remaining = entry->transfer[2] - remaining;
            func_02005334();
            func_02006c94(entry->transfer[0], entry->transfer[2]);
            func_02005390(entry->transfer[0] + remaining, entry->transfer[1] + remaining, amount);
            func_020054d0();
            entry->unk_0018 += amount;
        }
    }
    complete = 0;
    if (entry->unk_0018 >= (u32)(entry->transfer[2] + entry->transfer[5])) complete = 1;
    return complete;
}

void func_020059d8(int value);
void func_020059a8(int value);
void func_02007e94(void);
void func_02008904(const void *source, void *destination, u32 size);

/* Copy a borrowed descriptor into the forty-slot singleton ring, normalize
 * absent groups, and retain the callback/work until draining (original offsets).
 * A full ring invokes the original failure helper without publishing a slot. */
void func_0205b234(Unk05ae50Entry *entry, void (*callback)(Unk05ae50Work *), Unk05ae50Work *work)
{
    Unk05ae50Entry *slot;
    int next;
    func_020059d8(1);
    next = (((Unk05ae50Queue *)data_0216a184)->write + 1 == 40) ? 0 : ((Unk05ae50Queue *)data_0216a184)->write + 1;
    if (((Unk05ae50Queue *)data_0216a184)->read == next) {
        func_02007e94();
        func_020059a8(1);
        return;
    }
    slot = &((Unk05ae50Queue *)data_0216a184)->entries[((Unk05ae50Queue *)data_0216a184)->write];
    func_02008904(entry, slot, 36);
    if (!slot->transfer[0] || !slot->transfer[2]) {
        slot->transfer[0] = 0;
        slot->transfer[2] = 0;
    }
    if (!slot->transfer[3] || !slot->transfer[5]) {
        slot->transfer[3] = 0;
        slot->transfer[5] = 0;
    }
    slot->unk_0018 = 0;
    slot->callback = (void (*)(void *))callback;
    slot->argument = work;
    next = (((Unk05ae50Queue *)data_0216a184)->write + 1 == 40) ? 0 : ((Unk05ae50Queue *)data_0216a184)->write + 1;
    ((Unk05ae50Queue *)data_0216a184)->write = next;
    func_020059a8(1);
}
