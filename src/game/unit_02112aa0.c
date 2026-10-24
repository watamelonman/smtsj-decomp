#include "types.h"

/* Layout follows this unit's byte state fields and word-sized resource slots. */
typedef struct Unit112aa0Work {
    u8 state;
    u8 phase;
    u8 pad_0002[2];
    int unk_0004;
    u8 unk_0008;
    u8 pad_0009[11];
    u16 unk_0014;
    u8 pad_0016[2];
    int unk_0018;
    int unk_001c;
    u8 pad_0020[4];
    void *unk_0024;
    void *unk_0028;
    void *unk_002c;
    void *slots[22];
    void *unk_0088;
    void *unk_008c;
    void *unk_0090;
    void *unk_0094[3];
    void *unk_00a0[6];
    void *unk_00b8;
    void *unk_00bc;
    void *unk_00c0;
    void *unk_00c4;
    int unk_00c8;
    float unk_00cc;
    int unk_00d0;
    u32 unk_00d4;
    u8 unk_00d8[];
} Unit112aa0Work;

extern int data_02176e54[];
extern void Unk113294_CopyIds(Unit112aa0Work *work);
extern void Unk0bc1a8_Unk_0bc9b4(int slot, int value);
extern void func_0205257c(int value);
extern int func_02052728(void);

/* Advance the two-phase transition, waiting for 02052728 before state 6. */
void func_02113200(Unit112aa0Work *work)
{
    switch (work->phase) {
    case 0:
        func_0205257c(0);
        work->phase++;
        break;
    case 1:
        if (func_02052728() == 0) {
            work->phase = 0;
            work->state = 6;
        }
        break;
    }
}

/* Copy IDs and publish completion in mode zero, then clear slot 39 in all modes. */
void func_02113258(Unit112aa0Work *work)
{
    switch (work->unk_0004) {
    case 0:
        Unk113294_CopyIds(work);
        data_02176e54[0] = 1;
        break;
    case 1:
        break;
    }
    Unk0bc1a8_Unk_0bc9b4(39, 0);
}

extern void func_02052634(int a, int b, int c);
extern void func_020525cc(int value);
extern void func_0205caa8(void *slot, int index);
extern void func_020e7f44(int a, int b, int c, int d);
extern void func_02124ce8(int value);
extern int Unk0cb32c_Unk_0cb58c(void *slot);

/* Stage the slot animations, then count five updates before entering state 2. */
void func_02112c68(Unit112aa0Work *work)
{
    switch (work->phase) {
    case 0:
        func_02052634(1, 0, 31);
        func_020525cc(0);
        work->phase++;
        break;
    case 1:
        if (func_02052728() != 0) return;
        func_0205caa8(work->slots[4], 4);
        func_0205caa8(work->slots[6], 6);
        func_0205caa8(work->slots[0], 0);
        func_0205caa8(work->slots[16], 16);
        func_0205caa8(work->slots[17], 17);
        func_0205caa8(work->slots[18], 18);
        func_0205caa8(work->slots[19], 19);
        func_0205caa8(work->slots[2], 2);
        func_020e7f44(19, 15, 9, 12);
        func_02124ce8(1);
        work->phase++;
        break;
    case 2:
        if (Unk0cb32c_Unk_0cb58c(work->slots[4]) == 0) return;
        func_0205caa8(work->slots[7], 7);
        func_0205caa8(work->slots[8], 8);
        func_0205caa8(work->slots[9], 9);
        work->unk_00cc += 1.334f;
        work->phase++;
        break;
    case 3:
        if (work->unk_00c8 == 5) {
            func_0205caa8(work->slots[3], 3);
            func_0205caa8(work->slots[5], 5);
            func_0205caa8(work->slots[10], 10);
            func_0205caa8(work->slots[11], 11);
            func_0205caa8(work->slots[1], 1);
            func_0205caa8(work->slots[12], 12);
            func_0205caa8(work->slots[13], 13);
            work->phase = 0;
            work->state = 2;
        } else {
            work->unk_00c8++;
            work->unk_00cc += 1.334f;
        }
        break;
    }
}

extern void Unk0cb32c_Unk_0cb57c(void *slot);
extern u8 data_0213cb92[][2];
extern u8 data_0213cb8c[][2];
extern int Unk113294_GetUnkField20(Unit112aa0Work *work);
extern void Unk113294_Unk_115144(Unit112aa0Work *work);

/* Wait for slot completion before choosing the next byte-valued selection. */
void func_02112e38(Unit112aa0Work *work)
{
    switch (work->phase) {
    case 0:
        Unk0cb32c_Unk_0cb57c(work->slots[14]);
        func_0205caa8(work->slots[14], 14);
        Unk0cb32c_Unk_0cb57c(work->slots[15]);
        func_0205caa8(work->slots[15], 15);
        Unk0cb32c_Unk_0cb57c(work->slots[20]);
        func_0205caa8(work->slots[20], 20);
        work->phase++;
        break;
    case 1:
        if (Unk0cb32c_Unk_0cb58c(work->slots[20]) == 0) return;
        switch (work->unk_00d0) {
        case 1: work->unk_0008 = 2; break;
        case 0: work->unk_0008 = 0; break;
        case -1:
            if (work->unk_0004 == 0)
                work->unk_0008 = data_0213cb92[work->unk_0008][work->unk_001c != 2];
            else
                work->unk_0008 = data_0213cb8c[work->unk_0008][work->unk_001c != 2];
            break;
        }
        if (Unk113294_GetUnkField20(work) != 0 && work->unk_0008 != 2)
            work->unk_0008++;
        Unk113294_Unk_115144(work);
        Unk0cb32c_Unk_0cb57c(work->slots[21]);
        func_0205caa8(work->slots[21], 21);
        work->phase++;
        break;
    case 2:
        if (Unk0cb32c_Unk_0cb58c(work->slots[21]) == 0) return;
        work->phase = 0;
        work->state = 2;
        break;
    }
}

extern void func_020629c4(void *resource);
extern void func_0205c3dc(void *resource);
extern void func_0205c368(void *resource);
extern void func_0205ddb4(void *resource);
extern void func_0205bb68(void);
extern void Unk065e88_Unk_065eac(int mode);
extern void Unk044394_Unk_044534(int value);
extern void func_0201fbe8(void);

/* Release the observed resource groups and clear the published work pointer. */
void func_02112aa0(Unit112aa0Work *work)
{
    int i;
    unsigned j;
    Unk0bc1a8_Unk_0bc9b4(10, 0);
    func_020629c4(work->unk_00c4);
    for (i = 0; i < 6; i++) func_020629c4(work->unk_00a0[i]);
    for (i = 0; i < 3; i++) func_020629c4(work->unk_0094[i]);
    func_020629c4(work->unk_00c0);
    func_020629c4(work->unk_00b8);
    func_020629c4(work->unk_00bc);
    func_020629c4(work->unk_0090);
    func_020629c4(work->unk_008c);
    func_020629c4(work->unk_0088);
    for (i = 0; i < 22; i++) {
        if (work->slots[i] != 0) {
            func_0205c3dc(work->slots[i]);
            work->slots[i] = 0;
        }
    }
    if (work->unk_002c != 0) {
        func_0205c368(work->unk_002c);
        work->unk_002c = 0;
    }
    if (work->unk_0024 != 0) {
        func_0205ddb4(work->unk_0024);
        work->unk_0024 = 0;
    }
    for (j = 0; j < 7; j++) func_0205bb68();
    /* The caller supplies a mode word immediately before the work payload. */
    if (((int *)work)[-1] != 6) {
        Unk065e88_Unk_065eac(((int *)work)[-1]);
        if (work->unk_0028 != 0) {
            func_0205ddb4(work->unk_0028);
            work->unk_0028 = 0;
        }
        func_0205bb68();
    }
    Unk044394_Unk_044534(42);
    func_0201fbe8();
    data_02176e54[1] = 0;
}

/* The helper writes a 60-byte temporary; its internal fields remain unknown. */
typedef struct Unit112aa0Transfer { u32 words[15]; } Unit112aa0Transfer;
extern int func_02065544(void);
extern int func_020654cc(void);
extern int func_0206557c(void);
extern int func_0206559c(void);
extern int func_020babdc(void);
extern int Unk113294_Unk_1150c8(int value, int code);
extern void func_02065864(int value, int mode);
extern void func_020658dc(int value, int a, int b, int c);
extern void func_02065c30(void);
extern void func_02065ca8(void);
extern int func_021115d4(Unit112aa0Transfer *out, void *source);
extern void Unk100810_Unk_1069c8(Unit112aa0Transfer *value);
extern void Unk0a0ce4_Unk_0a0da4(int value);
extern void Unk113294_Unk_1156ec(void);

/* Poll the external operation, processing result codes 120 through 125. */
void func_02112fb8(Unit112aa0Work *work)
{
    Unit112aa0Transfer transfer;
    int value;
    switch (work->phase) {
    case 0:
        if (func_02065544() == 0) return;
        if (func_020654cc() == 0) return;
        value = 0;
        if (work->unk_0014 >= 122)
            func_02065864(Unk113294_Unk_1150c8(value, work->unk_0014), -1);
        else
            func_020658dc(Unk113294_Unk_1150c8(value, work->unk_0014), 1, 0, 257);
        work->phase++;
        break;
    case 1:
        if (func_0206557c() == 0) return;
        work->phase++;
        break;
    case 2:
        if (work->unk_0014 >= 122) {
            if (func_0206557c() != 0) return;
            func_02065c30();
            work->phase++;
        } else {
            if (func_0206559c() == 0) return;
            work->unk_0018 = func_020babdc();
            func_02065c30();
            work->phase++;
        }
        break;
    case 3:
        if (func_020654cc() == 0) return;
        func_02065ca8();
        switch (work->unk_0014) {
        case 120:
            work->state = work->unk_0018 == 0 ? 5 : 2;
            work->phase = 0;
            break;
        case 121:
            if (work->unk_0018 == 0) {
                if (func_021115d4(&transfer, work->unk_00d8) != 0) {
                    Unk100810_Unk_1069c8(&transfer);
                    work->phase = 0;
                    work->state = 5;
                    data_02176e54[0] = 1;
                } else {
                    work->unk_0014 = 124;
                    work->phase++;
                }
            } else {
                work->phase = 0;
                work->state = 2;
            }
            break;
        case 122:
        case 123:
        case 124:
        case 125:
            work->phase = 0;
            work->state = 2;
            break;
        }
        break;
    case 4:
        if (work->unk_0014 == 124) Unk0a0ce4_Unk_0a0da4(4);
        Unk113294_Unk_1156ec();
        work->phase = 0;
        break;
    }
}

extern void func_0205c704(void *slot);

/* Dispatch the state handler, then update each slot while state is nonzero. */
void func_02112be4(Unit112aa0Work *work)
{
    int i;
    switch (work->state) {
    case 0: break;
    case 1: func_02112c68(work); break;
    case 2: break;
    case 3: func_02112e38(work); break;
    case 4: func_02112fb8(work); break;
    case 5: func_02113200(work); break;
    case 6: func_02113258(work); break;
    }
    if (work->state == 0) return;
    for (i = 0; i < 22; i++) func_0205c704(work->slots[i]);
}
