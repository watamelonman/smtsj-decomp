#include "types.h"

extern u32 data_02176e54[];
extern int Unk0bc1a8_IsSlotEmpty(int slot);

/* Reports whether slot 0x27 is empty, as identified by the called slot query. */
int Unk112714_Unk_112714(void)
{
    return Unk0bc1a8_IsSlotEmpty(0x27) != 0;
}

/* Reads the shared word also cleared by Unk113294_Unk_113eb4. */
u32 Unk112714_Get_data_02176e54(void)
{
    return *data_02176e54;
}

/* Callback signatures are unknown; these addresses are stored, never called here. */
extern void func_02112be4(void);
extern void func_02113294(void);
extern void func_02113edc(void);
extern void Unk113294_Unk_114488(void);
extern void func_02112aa0(void);
extern void func_02114fac(void);

/* Descriptor layout follows the word stores in the original initializer. */
typedef struct Unk112714Descriptor {
    u32 size;
    u32 unk04;
    u32 unk08;
    void (*callbacks[6])(void);
} Unk112714Descriptor;

/* Installs the six observed callbacks; word +8 belongs to the caller. */
void func_02112740(Unk112714Descriptor *p)
{
    p->size = 284;
    p->unk04 = 0;
    p->callbacks[0] = func_02112be4;
    p->callbacks[1] = func_02113294;
    p->callbacks[2] = func_02113edc;
    p->callbacks[3] = Unk113294_Unk_114488;
    p->callbacks[4] = func_02112aa0;
    p->callbacks[5] = func_02114fac;
}

extern void func_02008848(void *p, int value, u32 size);
extern void Unk044394_Unk_044428(int value);
extern void Unk05b82c_Unk_05b82c(u32 id);
extern u32 func_0205dcd4(const void *p, int flag);
extern void Unk065e88_Unk_065e88(u32 handle);
extern u32 func_0205c2c4(const void *p);
extern u32 func_0205c3c0(void);
extern void func_0205c3fc(u32 handle, u32 a, u32 b);
extern void func_0205caa8(u32 handle, int index);
extern void Unk0cb32c_Unk_0cb57c(u32 handle);
extern u32 func_020629ac(int a, int b, int c, int d);
extern void func_02061e98(u32 handle, int a, int b);
extern void Unk113294_Unk_11518c(u32 handle);
extern void func_0211527c(void *p);
extern void Unk113294_Unk_115144(void *p);
extern void Unk0bc1a8_Unk_0bc928(int a, int b, int c);
extern void func_02053924(int a, int b);
extern u8 data_02151ac4[], data_02151ad4[], data_02151ae8[];
extern u32 data_0213cb98[];

/* 284-byte work record; field names are the byte offsets of the original stores.
 * Array lengths follow the loop bounds in func_0211279c. */
typedef struct Unk112714Work {
    u8 unk_0000;
    u8 unk_0001;
    u8 pad_0002[2];
    u32 unk_0004;
    u8 unk_0008;
    u8 unk_0009;
    u8 pad_000a[2];
    u32 unk_000c;
    u32 unk_0010;
    u16 unk_0014;
    u8 pad_0016[2];
    u32 unk_0018;
    u32 unk_001c;
    u32 unk_0020;
    u32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u32 handles[22];   /* +0x30: 22 handles, loop bound */
    u32 unk_0088[3];   /* +0x88: created individually */
    u32 unk_0094[3];   /* +0x94: 3 handles, loop bound */
    u32 unk_00a0[6];   /* +0xa0: 6 handles, loop bound */
    u32 unk_00b8;
    u32 unk_00bc;
    u32 unk_00c0;
    u32 unk_00c4;
    u32 unk_00c8;
    u32 unk_00cc;
    u32 unk_00d0;
    u32 unk_00d4;
    u8 unk_00d8[66];   /* cleared as one 66-byte block */
    u8 pad_011a[2];
} Unk112714Work;

/* Initializes the work record and creates its resource handles.
 * The record is allocated directly after a u32 mode word owned by the
 * framework that allocates it (the size 284 comes from func_02112740's
 * descriptor), so the mode is read as ((u32 *)w)[-1]; mode 6 skips the
 * optional resource stored in unk_0028. */
void func_0211279c(Unk112714Work *w)
{
    int i;
    u32 j;
    func_02008848(w->unk_00d8, 0, 66);
    w->unk_00d4 = -1;
    w->unk_00d0 = 0;
    w->unk_00cc = 0;
    w->unk_001c = 0;
    w->unk_0018 = 0;
    w->unk_0014 = 0;
    w->unk_000c = 0;
    w->unk_0010 = 0;
    w->unk_00c8 = 0;
    w->unk_0008 = 0;
    w->unk_0004 = 0;
    w->unk_0009 = 0;
    w->unk_0020 = 0;
    w->unk_0001 = 0;
    w->unk_0000 = 0;
    Unk044394_Unk_044428(42);
    if (((u32 *)w)[-1] != 6) {
        Unk05b82c_Unk_05b82c(57);
        w->unk_0028 = func_0205dcd4(data_02151ac4, 1);
        Unk065e88_Unk_065e88(w->unk_0028);
    }
    for (j = 0; j < 7; j++)
        Unk05b82c_Unk_05b82c(data_0213cb98[j]);
    w->unk_0024 = func_0205dcd4(data_02151ad4, 1);
    w->unk_002c = func_0205c2c4(data_02151ae8);
    for (i = 0; i < 22; i++) {
        w->handles[i] = func_0205c3c0();
        func_0205c3fc(w->handles[i], w->unk_0024, w->unk_002c);
    }
    func_0205caa8(w->handles[14], 14);
    func_0205caa8(w->handles[15], 15);
    func_0205caa8(w->handles[18], 18);
    Unk0cb32c_Unk_0cb57c(w->handles[18]);
    Unk0cb32c_Unk_0cb57c(w->handles[2]);
    w->unk_0088[0] = func_020629ac(4, 1, 1, 1);
    w->unk_0088[1] = func_020629ac(5, 2, 1, 1);
    w->unk_0088[2] = func_020629ac(3, 3, 1, 1);
    w->unk_00b8 = func_020629ac(5, 1, 1, 1);
    w->unk_00bc = func_020629ac(5, 1, 1, 1);
    w->unk_00c0 = func_020629ac(5, 3, 1, 1);
    func_02061e98(w->unk_00bc, 32, 1);
    func_02061e98(w->unk_00b8, 32, 1);
    func_02061e98(w->unk_00c0, 32, 1);
    for (i = 0; i < 3; i++) {
        w->unk_0094[i] = func_020629ac(5, 4, 1, 1);
        func_02061e98(w->unk_0094[i], 32, 1);
    }
    for (i = 0; i < 6; i++) {
        w->unk_00a0[i] = func_020629ac(5, 4, 1, 1);
        func_02061e98(w->unk_00a0[i], 32, 1);
    }
    w->unk_00c4 = func_020629ac(1, 1, 1, 1);
    func_02061e98(w->unk_00c4, 32, 1);
    func_02061e98(w->unk_0088[0], 16, 1);
    func_02061e98(w->unk_0088[1], 16, 1);
    Unk113294_Unk_11518c(w->unk_0088[2]);
    func_0211527c(w);
    Unk113294_Unk_115144(w);
    Unk0bc1a8_Unk_0bc928(10, 39, 0);
    func_02053924(30, 5);
}
