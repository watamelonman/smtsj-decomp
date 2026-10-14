/*
 * unit_02095560: owner of a static manager object at 0x02175eb0
 * (func_0209573c returns it; many functions in this unit use it).
 */
typedef signed char s8;

extern unsigned char data_02175eb0[];   /* static manager instance */

void func_0202d15c(void);
void func_020cb044(void);
void func_020773dc(void);
void func_020961a0(void);

/* Reads the signed byte at table[index]. */
int func_02095560(const s8 *table, int index) { return table[index]; }

/* Returns the static manager instance. */
unsigned char *func_0209573c(void) { return data_02175eb0; }

/* Same as func_0209573c, kept as a separate entry point. */
unsigned char *func_02095748(void) { return func_0209573c(); }

/* Returns the sub-object at offset 0x3A8 of the manager. */
unsigned char *func_02095754(void) { return func_0209573c() + 0x3a8; }

/* Forwarders. */
void func_02095600(void) { func_0202d15c(); }
void func_0209580c(void) { func_020cb044(); }
void func_02096140(void) { func_020773dc(); }
void func_02096274(void) { func_020961a0(); }
