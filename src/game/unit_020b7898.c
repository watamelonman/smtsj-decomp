/*
 * unit_020b7898: two small scene hooks (no direct callers; table entries).
 */
void func_02052634(int a, int b, int c);
void Unk111400_Unk_111474(int a, int b, int c);
void func_02111494(void);
void Unk02cad4_Unk_02cbdc(int a);

/* Calls func_02052634(1, 0, 31). 31 is the max 5-bit value (e.g. full brightness/alpha). */
void Unk0b7898_Call_02052634(void) { func_02052634(1, 0, 31); }

/* Calls Unk111400_Unk_111474(4, 0xC03, 0), then func_02111494(), then Unk02cad4_Unk_02cbdc(1). */
void Unk0b7898_Unk_0b78b0(void) {
    Unk111400_Unk_111474(4, 0xc03, 0);
    func_02111494();
    Unk02cad4_Unk_02cbdc(1);
}
