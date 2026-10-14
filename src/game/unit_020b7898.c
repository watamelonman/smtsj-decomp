/*
 * unit_020b7898: two small scene hooks (no direct callers; table entries).
 */
void func_02052634(int a, int b, int c);
void func_02111474(int a, int b, int c);
void func_02111494(void);
void func_0202cbdc(int a);

/* Calls func_02052634(1, 0, 31). 31 is the max 5-bit value (e.g. full brightness/alpha). */
void func_020b7898(void) { func_02052634(1, 0, 31); }

/* Calls func_02111474(4, 0xC03, 0), then func_02111494(), then func_0202cbdc(1). */
void func_020b78b0(void) {
    func_02111474(4, 0xc03, 0);
    func_02111494();
    func_0202cbdc(1);
}
