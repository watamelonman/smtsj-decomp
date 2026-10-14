/*
 * unit_02116598: empty callbacks and thin forwarders. func_021166e8 and
 * func_021166f4 are called back-to-back from func_0203c320.
 */

void func_021177e0(void);
void func_02117808(void);
void func_021172fc(void);

/* Empty callbacks (no direct callers; function-table slots). */
void func_02116b44(void) { }
void func_02116b68(void) { }
void func_02116b6c(void) { }
void func_02117cd0(void) { }

/* Forwarders: pass the caller's arguments straight through. */
void func_021166e8(void) { func_021177e0(); }
void func_021166f4(void) { func_02117808(); }
void func_02116804(void) { func_021172fc(); }
void func_02117950(void) { func_021177e0(); }
