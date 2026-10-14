/*
 * unit_0202f2a8: accessors around a global game-state pointer at 0x0215dd2c
 * (read by ~60 callers across the game).
 */
typedef unsigned short u16;

extern unsigned char *data_0215dd2c;    /* global game state */

void func_0203428c(void);
void func_0206146c(void);
void func_02057660(int a, int b);

/* Empty callbacks (no direct callers). */
void func_020303c8(void) { }
void func_020303cc(void) { }
void func_02035430(void) { }

/* Forwarders. */
void func_02035424(void) { func_0203428c(); }
void func_02035434(void) { func_0206146c(); }

/* Returns the global game-state pointer. */
unsigned char *func_02034388(void) { return data_0215dd2c; }

/* Calls func_02057660(2, 0). */
void func_02030594(void) { func_02057660(2, 0); }

/* Reads the u16 at offset 0x74F4 of the global game state. */
u16 func_02034da0(void) { return *(u16 *)(data_0215dd2c + 0x74f4); }
