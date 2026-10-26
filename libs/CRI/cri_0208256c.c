#include "types.h"

extern u32 data_021742c4[2];
extern u32 data_021742bc[2];

/* The worker combines six callback results for the supplied row index. */
extern u32 func_0208258c(u32 index);

/* Original STM stores both opaque words, in order, at data_021742c4. */
void func_0208256c(u32 first, u32 second)
{
    data_021742c4[0] = first;
    data_021742c4[1] = second;
}

/* Original STM stores both opaque words, in order, at data_021742bc. */
void func_0208257c(u32 first, u32 second)
{
    data_021742bc[0] = first;
    data_021742bc[1] = second;
}

/* Original MOV r0, #0 selects worker row 0; return its combined result. */
u32 func_02082608(void)
{
    return func_0208258c(0);
}

/* Original MOV r0, #1 selects worker row 1; return its combined result. */
u32 func_02082618(void)
{
    return func_0208258c(1);
}

/* Original MOV r0, #2 selects worker row 2; return its combined result. */
u32 func_02082628(void)
{
    return func_0208258c(2);
}

/* Original MOV r0, #3 selects worker row 3; return its combined result. */
u32 func_02082638(void)
{
    return func_0208258c(3);
}

/* Original MOV r0, #4 selects worker row 4; return its combined result. */
u32 func_02082648(void)
{
    return func_0208258c(4);
}

/* Original MOV r0, #5 selects worker row 5; return its combined result. */
u32 func_02082658(void)
{
    return func_0208258c(5);
}
