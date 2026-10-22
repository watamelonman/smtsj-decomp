#include "types.h"

/* The matching toolchain does not provide standard headers. */
#define NULL ((void *)0)

/* Only the worker pointer at +0xe8 is accessed by these handlers. */
typedef struct Unk03e02cContext {
    u8 pad_0000[0xe8];
    void *unk_00e8;
} Unk03e02cContext;

int func_0203ac00(int index);
void Unk03aae8_Unk_03acf4(u32 result);
Unk03e02cContext *Unk03aae8_Unk_03ad14(void);
int Unk02f2a8_Unk_035b08(u32 first, u32 second);
int Unk09ee4c_Thunk_02118c6c(int value);
void func_020953c4(u32 first, u32 second, u32 third);
int Unk094fe0_Unk_0953f0(void);
int Unk0bc1a8_IsSlotEmpty(int slot);
struct Unk1250a8Req;
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 value, struct Unk1250a8Req *req);
int func_02095818(void);
void func_02116758(int value);
void func_021179a0(int value);
void Unk116598_Unk_1167e0(void);
void Unk116598_Unk_117a28(void);
void Unk0bc1a8_Unk_0bc9b4(u32 slot, u32 value);
int Unk02dcfc_GetState(void *worker);
void Unk02dcfc_ResetWorker(void *worker);
void Unk02dcfc_Unk_02dd9c(void *worker);
void func_020df520(int value);
void func_0209e3a8(int value);

/* Pass two byte arguments through the query chain and publish a Boolean result. */
int func_0203e02c(void)
{
    u8 first = func_0203ac00(0);
    u8 second = func_0203ac00(1);
    if (Unk09ee4c_Thunk_02118c6c(Unk02f2a8_Unk_035b08(first, second))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Forward two byte arguments and one halfword, then publish the follow-up query. */
int func_0203e078(void)
{
    u8 first = func_0203ac00(0);
    u8 second = func_0203ac00(1);
    u16 third = func_0203ac00(2);
    func_020953c4(first, second, third);
    if (Unk094fe0_Unk_0953f0()) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* Initialize slot 24 with value 0xffff only when the slot query reports empty. */
int func_0203e0d8(void)
{
    if (Unk0bc1a8_IsSlotEmpty(24)) {
        Unk0bc1a8_Unk_0bc928(24, 0xffff, NULL);
    }
    return 1;
}

/* Forward argument zero to the mode-3 or mode-4 operation; other modes finish directly. */
int func_0203e108(void)
{
    int value = func_0203ac00(0);
    switch (func_02095818()) {
    case 3: func_02116758(value); break;
    case 4: func_021179a0(value); break;
    }
    return 1;
}

/* Dispatch modes 3/4 to their operations, otherwise call Unk0bc1a8_Unk_0bc9b4(24, 0). */
int func_0203e14c(void)
{
    switch (func_02095818()) {
    case 3: Unk116598_Unk_1167e0(); break;
    case 4: Unk116598_Unk_117a28(); break;
    default: Unk0bc1a8_Unk_0bc9b4(24, 0); break;
    }
    return 1;
}

/* In modes 0/2, reset an active worker or start a signed-halfword operation.
 * Return zero after starting the worker; all completed paths publish result 1. */
int func_0203e18c(void)
{
    void *worker = Unk03aae8_Unk_03ad14()->unk_00e8;
    int mode = func_02095818();
    s16 value;
    if (mode != 0 && mode != 2) {
        Unk03aae8_Unk_03acf4(1);
        return 1;
    }
    if (Unk02dcfc_GetState(worker) != 0) {
        Unk02dcfc_ResetWorker(worker);
        Unk03aae8_Unk_03acf4(1);
        return 1;
    }
    value = func_0203ac00(0);
    switch (func_02095818()) {
    case 2: func_020df520(value); break;
    case 0: func_0209e3a8(value); break;
    default:
        Unk03aae8_Unk_03acf4(1);
        return 1;
    }
    Unk02dcfc_Unk_02dd9c(worker);
    return 0;
}
