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

