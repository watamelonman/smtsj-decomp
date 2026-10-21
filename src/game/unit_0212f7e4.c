/* src/game/unit_0212f7e4.c: hand-matched. */
#include "types.h"

/* The ROM tail-calls with a plain `b` here, unlike the `ldr ip; bx ip` that the
 * project-wide -interworking flag produces, so interworking is off for this TU. */
#pragma interworking off

void func_021301f0(void);

/* Forwarding thunk: tail-calls func_021301f0 (shape: Unk12f7e4_Thunk_021301f0). */
void func_0212f7e4(void) { func_021301f0(); }
