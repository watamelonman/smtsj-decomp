/*
 * ImageBgDual3D.c (name from the assert string at 0x02125c68):
 * a dual-screen 3D image background used by the ending/event scenes
 * (neighbouring code loads "Data/Tex/Event/ED/").
 * These are its empty callbacks and two thin forwarders.
 */

void func_021255b4(void);
void func_021177e0(void);

/* Empty per-frame / lifecycle callbacks (no direct callers; table entries). */
void func_021252f4(void) { }
void func_021252f8(void) { }
void func_021252fc(void) { }
void func_02125c3c(void) { }
void func_02125c60(void) { }
void func_02125c64(void) { }

/* Forwards to func_021255b4 with the caller's arguments. */
void func_021257e8(void) { func_021255b4(); }

/* Forwards to func_021177e0 (shared helper also used by unit_02116598). */
void func_021259ac(void) { func_021177e0(); }
