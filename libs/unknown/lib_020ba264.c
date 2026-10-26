#include "types.h"

/* Script handler wrappers; the original symbols are retained for delink matching. */

/* Reads a signed script argument by its zero-based index. */
extern int func_0203ac00(int index);
/* Forwards an integer to the selected ID; ownership stays with the caller. */
extern void func_020b8b18(int id, int value);
/* Counts entries for the supplied ID, as established by its existing definition. */
extern int Unk0afc28_CountById(unsigned int id);
/* Publishes the implicit script result; see game/unit_0203aae8. */
extern void Unk03aae8_Unk_03acf4(int value);
/* Supplies the current query input; the underlying domain is unresolved. */
extern unsigned int func_020b8ad8(void);
/* Queries a field of the supplied value; field numbering is unchanged. */
extern int func_02049d80(unsigned int value, int field);
/* Supplies a script-visible integer; its domain remains unresolved. */
extern int Unk03e43c_Unk_03fa28(void);

/* ARM evidence at 0x020ba264: forwards argument 0 with ID 17; returns completion 1. */
int func_020ba264(void)
{
    func_020b8b18(17, func_0203ac00(0));
    return 1;
}

/* ARM evidence at 0x020ba284: forwards argument 0 with ID 18; returns completion 1. */
int func_020ba284(void)
{
    func_020b8b18(18, func_0203ac00(0));
    return 1;
}

/* ARM evidence at 0x020ba2a4: forwards argument 0 with ID 19; returns completion 1. */
int func_020ba2a4(void)
{
    func_020b8b18(19, func_0203ac00(0));
    return 1;
}

/* ARM evidence at 0x020ba2c4: forwards argument 0 with ID 20; returns completion 1. */
int func_020ba2c4(void)
{
    func_020b8b18(20, func_0203ac00(0));
    return 1;
}

/* ARM evidence at 0x020ba344: publishes the count for ID 1; returns completion 1. */
int func_020ba344(void)
{
    Unk03aae8_Unk_03acf4(Unk0afc28_CountById(1));
    return 1;
}

/* ARM evidence at 0x020ba35c: publishes the count for ID 2; returns completion 1. */
int func_020ba35c(void)
{
    Unk03aae8_Unk_03acf4(Unk0afc28_CountById(2));
    return 1;
}

/* ARM evidence at 0x020ba374: publishes field 0 of the query input; returns completion 1. */
int func_020ba374(void)
{
    Unk03aae8_Unk_03acf4(func_02049d80(func_020b8ad8(), 0));
    return 1;
}

/* ARM evidence at 0x020ba390: publishes the query result; returns completion 1. */
int func_020ba390(void)
{
    Unk03aae8_Unk_03acf4(Unk03e43c_Unk_03fa28());
    return 1;
}


/* Borrowed record prefix: ARM 020ba3b8 reads only byte +5. */
typedef struct {
    u8 reserved[5];
    u8 value;
} Unk020ba264Record;

/* Returns a borrowed record selected by the halfword ID at query-input +0x1d8. */
extern const Unk020ba264Record *func_020a1428(u32 id);
/* Returns the address of provider-owned storage; indexed words start at +0x30. */
extern u32 Unk044904_Unk_045064(void);
/* Returns the address of provider-owned storage; the queried halfword is at +0x38. */
extern u32 Unk044904_Get_data_0215ee98(void);
/* Dispatches a request with three word arguments and returns its script result. */
extern int func_020b8b38(int request, int first, int second, int third);

/* ARM 020ba2e4: forwards script operand 0 with selector 21; returns completion 1. */
int func_020ba2e4(void)
{
    func_020b8b18(21, func_0203ac00(0));
    return 1;
}

/* ARM 020ba304: forwards script operand 0 with selector 22; returns completion 1. */
int func_020ba304(void)
{
    func_020b8b18(22, func_0203ac00(0));
    return 1;
}

/* ARM 020ba324: forwards script operand 0 with selector 23; returns completion 1. */
int func_020ba324(void)
{
    func_020b8b18(23, func_0203ac00(0));
    return 1;
}

/* ARM 020ba3a4: resolves the halfword at input +0x1d8 and publishes record byte +5.
 * Both records remain provider-owned; no explicit handler arguments are consumed. */
int func_020ba3a4(void)
{
    u16 id = *(const u16 *)(func_020b8ad8() + 0x1d8);
    Unk03aae8_Unk_03acf4(func_020a1428(id)->value);
    return 1;
}

/* ARM 020ba3c8: publishes indexed word at provider +0x30; operand 0 must be valid. */
int func_020ba3c8(void)
{
    u32 storage = Unk044904_Unk_045064();
    int index = func_0203ac00(0);
    Unk03aae8_Unk_03acf4(*(int *)(storage + index * 4 + 0x30));
    return 1;
}

/* ARM 020ba3f0: stores operand 1 at provider +0x30 indexed by operand 0.
 * The script must supply a valid index into provider-owned word storage. */
int func_020ba3f0(void)
{
    u32 storage = Unk044904_Unk_045064();
    int index = func_0203ac00(0);
    int value = func_0203ac00(1);
    *(int *)(storage + index * 4 + 0x30) = value;
    return 1;
}

/* ARM 020ba420: publishes provider halfword +0x38 modulo operand 0.
 * Operand 0 is a signed divisor and must be nonzero. */
int func_020ba420(void)
{
    int divisor = func_0203ac00(0);
    int value = *(const u16 *)(Unk044904_Get_data_0215ee98() + 0x38);
    Unk03aae8_Unk_03acf4(value % divisor);
    return 1;
}

/* ARM 020ba450: submits request 106 with zero arguments and publishes its result. */
int func_020ba450(void)
{
    Unk03aae8_Unk_03acf4(func_020b8b38(106, 0, 0, 0));
    return 1;
}
