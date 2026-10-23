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

/* Arrays retain the observed handle slots and their byte offsets. */
typedef struct Unk112714Work {
    u8 prefix[48];
    u32 handles[22];
    u32 unk88[3];
    u32 group94[3];
    u32 groupA0[6];
} Unk112714Work;

#define WORD(p, offset) (*(u32 *)((p) + (offset)))
#define HALF(p, offset) (*(u16 *)((p) + (offset)))

/* Initializes a 284-byte work record; the caller supplies its preceding mode word. */
void func_0211279c(u8 *p)
{
    int i;
    u32 j;
    func_02008848(p + 216, 0, 66);
    WORD(p, 212) = -1;
    WORD(p, 208) = 0;
    WORD(p, 204) = 0;
    WORD(p, 28) = 0;
    WORD(p, 24) = 0;
    HALF(p, 20) = 0;
    WORD(p, 12) = 0;
    WORD(p, 16) = 0;
    WORD(p, 200) = 0;
    p[8] = 0;
    WORD(p, 4) = 0;
    p[9] = 0;
    WORD(p, 32) = 0;
    p[1] = 0;
    p[0] = 0;
    Unk044394_Unk_044428(42);
    if (WORD(p, -4) != 6) {
        Unk05b82c_Unk_05b82c(57);
        WORD(p, 40) = func_0205dcd4(data_02151ac4, 1);
        Unk065e88_Unk_065e88(WORD(p, 40));
    }
    for (j = 0; j < 7; j++)
        Unk05b82c_Unk_05b82c(data_0213cb98[j]);
    WORD(p, 36) = func_0205dcd4(data_02151ad4, 1);
    WORD(p, 44) = func_0205c2c4(data_02151ae8);
    for (i = 0; i < 22; i++) {
        ((Unk112714Work *)p)->handles[i] = func_0205c3c0();
        func_0205c3fc(((Unk112714Work *)p)->handles[i], WORD(p, 36), WORD(p, 44));
    }
    func_0205caa8(WORD(p, 104), 14);
    func_0205caa8(WORD(p, 108), 15);
    func_0205caa8(WORD(p, 120), 18);
    Unk0cb32c_Unk_0cb57c(WORD(p, 120));
    Unk0cb32c_Unk_0cb57c(WORD(p, 56));
    WORD(p, 136) = func_020629ac(4, 1, 1, 1);
    WORD(p, 140) = func_020629ac(5, 2, 1, 1);
    WORD(p, 144) = func_020629ac(3, 3, 1, 1);
    WORD(p, 184) = func_020629ac(5, 1, 1, 1);
    WORD(p, 188) = func_020629ac(5, 1, 1, 1);
    WORD(p, 192) = func_020629ac(5, 3, 1, 1);
    func_02061e98(WORD(p, 188), 32, 1);
    func_02061e98(WORD(p, 184), 32, 1);
    func_02061e98(WORD(p, 192), 32, 1);
    for (i = 0; i < 3; i++) {
        ((Unk112714Work *)p)->group94[i] = func_020629ac(5, 4, 1, 1);
        func_02061e98(((Unk112714Work *)p)->group94[i], 32, 1);
    }
    for (i = 0; i < 6; i++) {
        ((Unk112714Work *)p)->groupA0[i] = func_020629ac(5, 4, 1, 1);
        func_02061e98(((Unk112714Work *)p)->groupA0[i], 32, 1);
    }
    WORD(p, 196) = func_020629ac(1, 1, 1, 1);
    func_02061e98(WORD(p, 196), 32, 1);
    func_02061e98(WORD(p, 136), 16, 1);
    func_02061e98(WORD(p, 140), 16, 1);
    Unk113294_Unk_11518c(WORD(p, 144));
    func_0211527c(p);
    Unk113294_Unk_115144(p);
    Unk0bc1a8_Unk_0bc928(10, 39, 0);
    func_02053924(30, 5);
}
