#include "types.h"

extern int func_0203ac00(int index);
extern void Unk03e43c_Unk_03fa28(void);
extern void Unk03e43c_Unk_03fa3c(void);
extern void Unk03aae8_Unk_03acf4(void);

/* Runs the two callbacks in the order recorded at 0203d168; returns completion. */
u32 Unk03d168_Unk_03d168(void)
{
    Unk03e43c_Unk_03fa28();
    Unk03aae8_Unk_03acf4();
    return 1;
}

/* Consumes argument zero and runs the three callbacks recorded at 0203d17c. */
u32 Unk03d168_Unk_03d17c(void)
{
    func_0203ac00(0);
    Unk03e43c_Unk_03fa3c();
    Unk03e43c_Unk_03fa28();
    Unk03aae8_Unk_03acf4();
    return 1;
}

