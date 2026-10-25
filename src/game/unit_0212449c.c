/* Resource lifetime and drawing callbacks for the 64-byte work block. */
#include "types.h"


void Unk044394_Unk_044534(int value);
void func_0205bb68(void);
void func_0205c368(int handle);
void func_0205c3dc(int handle);
void func_0205ddb4(int handle);
void func_020629c4(int handle);
/* Releases the handles at +0..+24 and conditionally resets group 30 (+36). */
void Unk12449c_Unk_12449c(int *arg0)
{
  u32 value1;
  int value2;
  func_020629c4(arg0[6]);
  value2 = 0;
  do {
    if (arg0[value2 + 2] != 0) {
      func_0205c3dc(arg0[value2 + 2]);
      arg0[value2 + 2] = 0;
    }
    value2 = value2 + 1;
  } while (value2 < 4);
  if (arg0[1] != 0) {
    func_0205c368(arg0[1]);
    arg0[1] = 0;
  }
  if (*arg0 != 0) {
    func_0205ddb4(*arg0);
    *arg0 = 0;
  }
  value1 = 0;
  do {
    func_0205bb68();
    value1 = value1 + 1;
  } while (value1 < 4);
  if (arg0[9] == 0) {
    return;
  }
  Unk044394_Unk_044534(0x1e);
}

void func_021245bc(int *work);
/* Temporarily clears +40 while submitting an enabled (+60) work block. */
void Unk12449c_Unk_124590(int *work)
{
    if (work[15] == 0) {
        return;
    }
    work[10] = 0;
    func_021245bc(work);
    work[10] = 1;
}

void func_0205c704(int handle);
/* Advances the two signed scrolling offsets, wrapping at 192, then updates four handles. */
void func_02124538(int *work)
{
    int i;
    work[7]++;
    if (work[7] >= 192) work[7] = -192;
    work[8]++;
    if (work[8] >= 192) work[8] = -192;
    i = 0;
    do {
        func_0205c704(work[i + 2]);
        i++;
    } while (i < 4);
}

void func_02057524(int mode);
void func_02057eb8(int mask);
void func_02057fd8(void);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
void func_02057ddc(u32 color);
void func_02057df8(void);
void func_02057e18(int value);
void func_020572d8(void);
int func_020cb3dc(void);
void func_0205de40(int engine, int handle, int entry, int x, int y,
                    float sx, float sy, int angle, float scale, int layer);
void func_0205c748(int engine, int handle, int x, int y,
                    float sx, float sy, int angle, float scale, int layer);
void func_02060b60(int engine, int handle, int x, int y, int zero, int layer);
/* Submits the mode-specific resource entries; evidence: repeated calls to
 * 0205de40/0205c748 and color-state calls at 02057ddc, with mode from 020cb3dc.
 * The caller supplies the complete, borrowed 64-byte work block. */
void func_021245bc(int *work)
{
    int mode;
    func_02057524(4);
    if (work[12]) {
        func_02057eb8(-1);
        func_02057fd8();
        func_02057dcc(0x081018ff, -1, -1, 0x081018ff);
        func_0205de40(2, work[0], 16, 0, work[7], 1.0f, 1.0f, 0, 1.0f, 0);
        func_02057dcc(-1, 0x081018ff, 0x081018ff, -1);
        func_0205de40(2, work[0], 16, 0, work[8], 1.0f, 1.0f, 0, 1.0f, 0);
        func_02057df8();
        func_0205de40(2, work[0], 15, 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
        if (work[14]) {
            mode = func_020cb3dc();
            switch (mode) {
            case 1:
                func_0205de40(2, work[0], 4, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0x186bdeff);
                func_0205de40(2, work[0], 3, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0x084aa5ff);
                func_0205de40(2, work[0], 2, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0xffffff);
                func_0205c748(2, work[2], 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
                func_02057ddc(0x4a637bff);
                func_0205de40(2, work[0], 1, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057df8();
                func_0205de40(2, work[0], 0, 49, 89, 1.0f, 1.0f, 0, 1.0f, 1);
                break;
            case 2:
            case 3:
                func_0205de40(2, work[0], 9, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0x186bdeff);
                func_0205de40(2, work[0], 8, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0x084aa5ff);
                func_0205de40(2, work[0], 7, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_0205de40(2, work[0], 6, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                if (mode == 2) {
                    func_02057ddc(0xffffff);
                    func_0205c748(2, work[4], 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
                } else {
                    func_02057ddc(0xffffff);
                    func_0205c748(2, work[3], 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
                }
                func_02057ddc(0x4a637bff);
                func_0205de40(2, work[0], 5, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057df8();
                if (mode == 2) {
                    func_0205de40(2, work[0], 0, 129, 89, 1.0f, 1.0f, 0, 1.0f, 1);
                } else {
                    func_0205de40(2, work[0], 0, 81, 89, 1.0f, 1.0f, 0, 1.0f, 1);
                }
                break;
            case 4:
                func_0205de40(2, work[0], 13, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0x186bdeff);
                func_0205de40(2, work[0], 12, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0x084aa5ff);
                func_0205de40(2, work[0], 11, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057ddc(0xffffff);
                func_0205c748(2, work[5], 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
                func_02057ddc(0x4a637bff);
                func_0205de40(2, work[0], 10, 0, 0, 1.0f, 1.0f, 0, 1.0f, 1);
                func_02057df8();
                func_0205de40(2, work[0], 0, 129, 89, 1.0f, 1.0f, 0, 1.0f, 1);
                break;
            }
            func_02057e18(31);
        }
    }
    if (work[10]) {
        func_0205de40(2, work[0], 14, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
    }
    if (work[11]) {
        func_02057ddc(255);
        func_02060b60(0x1000001, work[6], 128, 2, 0, 15);
        func_02057df8();
        func_02060b60(0x1000001, work[6], 128, 1, 0, 15);
    }
    func_02057eb8(-1);
    func_02057fd8();
    func_020572d8();
}
