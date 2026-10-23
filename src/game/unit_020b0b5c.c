#include "types.h"

extern int func_02049f24(u32 value, int mode);
extern int func_02049d80(u32 value, int mode);
extern int func_0204ab98(u32 value);
extern int func_0204ab14(u32 value);
extern int func_0200219c(int numerator, int denominator);

/* Scale a percentage below 100 using rounded Q12 products, with a minimum of one.
 * Values at least 100 return the supplied base unchanged. */
int func_020b0bd4(int percent, int base, int multiplier)
{
    int numerator;
    int ratio;
    int result;
    if (percent >= 100) {
        return base;
    }
    numerator = (int)(((s64)(base << 12) * (percent << 12) + 0x800) >> 12);
    ratio = func_0200219c(numerator, 100 << 12);
    result = (int)(((s64)ratio * multiplier + 0x800) >> 12) >> 12;
    if (result <= 0) {
        result = 1;
    }
    return result;
}

/* Cap the requested amount by the mode-zero remaining capacity from three queries. */
int Unk0b0b5c_Unk_0b0c30(int a, int l)
{
    int x = func_02049f24(a, 0);
    int y = func_02049d80(a, 0);
    int r = x - (y - func_0204ab98(a));
    if (r < l) {
        l = r;
    }
    return l;
}

/* Compare the pointed-to signed values; callers must supply valid int pointers. */
int Unk0b0b5c_Unk_0b0d28(int *arg0,int *arg1)
{
  return *arg1 - *arg0;
}


/* Compare the pointed-to signed values; callers must supply valid int pointers. */
int Unk0b0b5c_Unk_0b0d38(int *arg0,int *arg1)
{
  return *arg0 - *arg1;
}

/* Cap the requested amount by the difference of the selected mode queries. */
int Unk0b0b5c_Unk_0b0c78(u32 arg0,int arg1)
{
  int value1;
  int value2;
  value1 = func_02049d80(arg0,0);
  value2 = func_0204ab98(arg0);
  if (value1 - value2 < arg1) {
    arg1 = value1 - value2;
  }
  return arg1;
}

/* Cap the requested amount by the mode-one remaining capacity from three queries. */
int Unk0b0b5c_Unk_0b0cac(int a, int l)
{
    int x = func_02049f24(a, 1);
    int y = func_02049d80(a, 1);
    int r = x - (y - func_0204ab14(a));
    if (r < l) {
        l = r;
    }
    return l;
}

/* Cap the requested amount by the difference of the selected mode queries. */
int Unk0b0b5c_Unk_0b0cf4(u32 arg0,int arg1)
{
  int value1;
  int value2;
  value1 = func_02049d80(arg0,1);
  value2 = func_0204ab14(arg0);
  if (value1 - value2 < arg1) {
    arg1 = value1 - value2;
  }
  return arg1;
}
