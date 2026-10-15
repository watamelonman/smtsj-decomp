/*
 * src/game/unit_02044904.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0215ee98[];
int func_0206df10();
int func_02072200();
int func_0209d13c();

int Unk044904_GetConst1(void);
u32 Unk044904_Get_data_0215ee98(void);
u32 Unk044904_Unk_0459ec(void);
void Unk044904_Unk_045c98(void);
void Unk044904_Unk_044e90(int arg0);
int Unk044904_Unk_045fd4(void);
void Unk044904_Unk_044ea8(void);

/* returns 1 */
int Unk044904_GetConst1(void) { return 1; }

/* decompiler-derived */
u32 Unk044904_Get_data_0215ee98(void)
{
  return *data_0215ee98;
}

/* decompiler-derived */
u32 Unk044904_Unk_0459ec(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  return *(u32 *)(value + 0x50);
}

/* decompiler-derived */
void Unk044904_Unk_045c98(void)
{
  func_0206df10();
  func_02072200();
}

/* decompiler-derived */
void Unk044904_Unk_044e90(int arg0)
{
  if (*data_0215ee98 == 0) {
    *data_0215ee98 = arg0;
  }
}

/* decompiler-derived */
int Unk044904_Unk_045fd4(void)
{
  int value;
  value = func_0209d13c();
  return value != 0;
}

/* decompiler-derived */
void Unk044904_Unk_044ea8(void)
{
  if (*data_0215ee98 != 0) {
    *data_0215ee98 = 0;
  }
}



/* decompiler-derived */
int Unk044904_Unk_044fd8(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x379c;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_044ff4(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x3fb0;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045010(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x77bc;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_04502c(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x372c;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045048(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x7804;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045064(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x7874;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_045080(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x78e4;
  }
  return value;
}


/* decompiler-derived */
int Unk044904_Unk_04509c(void)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  if (value == 0) {
    value = 0;
  }
  else {
    value = value + 0x7970;
  }
  return value;
}


int func_020bc650();
/* decompiler-derived */
int Unk044904_Unk_045c7c(void)
{
  int value;
  value = func_020bc650(0x1a);
  return value == 0;
}

int func_020452c4();
int func_020aa224();
/* decompiler-derived */
u32 Unk044904_Unk_046688(void)
{
  func_020452c4();
  Unk044904_Unk_044fd8();
  func_020aa224();
  Unk044904_Unk_045c98();
  return 1;
}


/* decompiler-derived */
int Unk044904_Unk_045460(int arg0)
{
  int value;
  value = Unk044904_Get_data_0215ee98();
  return arg0 == *(int *)(value + 0x5c);
}

int func_02045ca8();
/* decompiler-derived */
u32 Unk044904_Unk_046448(u16 *arg0)
{
  int value;
  value = func_02045ca8();
  if (value != 0) {
    *arg0 = 2;
  }
  return 1;
}


int func_020450b8();
int func_02045138();
int func_0204527c();
int func_020aa118();
int func_020f8098();
/* decompiler-derived */
u32 func_02046108(u16 *arg0)
{
  u32 tmp1;
  int tmp2;
  Unk044904_Unk_044fd8();
  func_020aa118();
  func_02045138();
  func_0204527c();
  func_020450b8();
  tmp1 = Unk044904_Unk_045080();
  tmp2 = func_020f8098(tmp1,0,0);
  if (tmp2 != 0) {
    *arg0 = 2;
  }
  return 2;
}


int func_020a5c14();
/* decompiler-derived */
u32 func_0204599c(u32 *arg0)
{
  int tmp1;
  u32 tmp2;
  int tmp3;
  tmp2 = 0;
  tmp3 = 0;
  do {
    if ((*arg0 != 0) &&
       (tmp1 = func_020a5c14(*arg0 & 0xffff,arg0[1],arg0[2]), tmp1 != 0)) {
      tmp2 = 1;
    }
    tmp3 = tmp3 + 1;
    arg0 = arg0 + 3;
  } while (tmp3 < 6);
  return tmp2;
}



