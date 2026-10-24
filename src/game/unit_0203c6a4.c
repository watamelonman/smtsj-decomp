/* Script handlers; neutral names retain meanings not established by the ARM code. */
#include "types.h"

int Unk03aae8_Unk_03ae10(void *worker, int value);
void Unk03aae8_Nop_03ae0c(void *worker);
void func_02065bc0(void);


/* Returns handler result 1, as established by mov r0, #1 at 0x0203c710. */
int Unk03c6a4_GetConst1(void) { return 1; }

int func_0203ac00(int index);
int func_0203c748(int mode, int value, int kind, int option, int flags);
int Unk03aae8_Unk_03ad14(void);
void func_02065c30(void);
int func_02065544(void);
/* Keeps the value in r0 and worker in r1 for the store seen at 0x0203c73c. */
static inline void Unk03c6a4_SetSubState(u32 v, u8 *sub)
{
    FIELD(u32, sub, 0x18) = v;
}
/* On a nonzero poll, calls 0x02065c30 and writes owner worker +0x18 = 4; returns 3. */
int Unk03c6a4_Unk_03c718(void)
{
    if (func_02065544() == 0) {
        return 3;
    }
    func_02065c30();
    Unk03c6a4_SetSubState(4, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

/* Only fields accessed by 0x0203c748 are modeled; owner +0xe8 supplies this worker. */
typedef struct Unk03c6a4Worker {
    u8 pad_0000[0x18];
    int state;
    u8 pad_001c[0xc];
    int initialized28;
    int initialized2c;
} Unk03c6a4Worker;

int func_020ba944(void);
void func_020ba990(void);
int func_020babdc(void);
void Unk03aae8_Unk_03acf4(int value);
void Unk03aae8_Unk_03ad24(Unk03c6a4Worker *worker);
int Unk03aae8_Unk_03ad98(Unk03c6a4Worker *worker, int value);
void func_020658dc(int value, int mode, int option, int flags);

/* ARM 0x0203c748: requires owner +0xe8; initializes the selected worker path,
 * resolves value for kinds 0/1, and forwards it with mode, option and flags.
 * The global early-exit path forwards a signed 16-bit value and returns 1.
 */
int func_0203c748(int mode, int value, int kind, int option, int flags)
{
    Unk03c6a4Worker *worker = FIELD(Unk03c6a4Worker *, Unk03aae8_Unk_03ad14(), 0xe8);
    int resolved;
    if (func_020ba944() != 0) {
        func_020ba990();
        Unk03aae8_Unk_03acf4((s16)func_020babdc());
        return 1;
    }
    worker->state = 9;
    switch (kind) {
    case 0:
        if (worker->initialized28 == 0) {
            Unk03aae8_Unk_03ad24(worker);
            worker->initialized28 = 1;
        }
        break;
    case 1:
        if (worker->initialized2c == 0) {
            Unk03aae8_Nop_03ae0c(worker);
            worker->initialized2c = 1;
        }
        break;
    }
    resolved = 0;
    switch (kind) {
    case 0:
        resolved = Unk03aae8_Unk_03ad98(worker, value);
        break;
    case 1:
        resolved = Unk03aae8_Unk_03ae10(worker, value);
        break;
    }
    if (func_02065544() == 0) {
        func_02065bc0();
    }
    func_020658dc(resolved, mode, option, flags);
    return 0;
}

/* ARM at 0x0203c84c: forwards signed low 16 bits of argument 0 with mode 0, kind 0, options 0. */
void Unk03c6a4_Unk_03c84c(void)
{
  s16 value;
  value = func_0203ac00(0);
  func_0203c748(0, (int)value, 0, 0, 0);
}


/* ARM at 0x0203c878: forwards signed low 16 bits of argument 0 with mode 1, kind 0, options 0. */
void Unk03c6a4_Unk_03c878(void)
{
  s16 value;
  value = func_0203ac00(0);
  func_0203c748(1, (int)value, 0, 0, 0);
}


/* ARM at 0x0203c8a4: forwards signed low 16 bits of argument 0 with mode 2, kind 0, options 0. */
void Unk03c6a4_Unk_03c8a4(void)
{
  s16 value;
  value = func_0203ac00(0);
  func_0203c748(2, (int)value, 0, 0, 0);
}


/* ARM at 0x0203c8d0: forwards signed low 16 bits of argument 0 with mode 0, kind 1, options 0. */
void Unk03c6a4_Unk_03c8d0(void)
{
  s16 value;
  value = func_0203ac00(0);
  func_0203c748(0, (int)value, 1, 0, 0);
}


/* ARM at 0x0203c8fc: forwards signed low 16 bits of argument 0 with mode 1, kind 1, options 0. */
void Unk03c6a4_Unk_03c8fc(void)
{
  s16 value;
  value = func_0203ac00(0);
  func_0203c748(1, (int)value, 1, 0, 0);
}


/* ARM at 0x0203c928: forwards signed low 16 bits of argument 0 with mode 2, kind 1, options 0. */
void Unk03c6a4_Unk_03c928(void)
{
  s16 value;
  value = func_0203ac00(0);
  func_0203c748(2, (int)value, 1, 0, 0);
}


void func_0206569c(int value);
/* ARM 0x0203c6a4: initializes worker +0x2c, resolves argument 0, and sets state 28. */
u32 Unk03c6a4_Unk_03c6a4(void)
{
  u32 value1;
  Unk03c6a4Worker *worker;
  int value3;
  value1 = func_0203ac00(0);
  worker = FIELD(Unk03c6a4Worker *, Unk03aae8_Unk_03ad14(), 0xe8);
  if (worker->initialized2c == 0) {
    Unk03aae8_Nop_03ae0c(worker);
    worker->initialized2c = 1;
  }
  value1 = Unk03aae8_Unk_03ae10(worker, value1);
  value3 = func_02065544();
  if (value3 == 0) {
    func_02065bc0();
  }
  func_0206569c(value1);
  worker->state = 0x1c;
  return 3;
}


/* ARM 0x0203c954: forwards a signed argument and selector with flags 0x101. */
int Unk03c6a4_Unk_03c954(void)
{
    s16 a = func_0203ac00(0);
    int k = func_0203ac00(1);
    int m;
    m = 0;
    switch (k) {
    case 0:
        break;
    case 1:
        m = 1;
        break;
    case 2:
        m = 2;
        break;
    }
    return func_0203c748(m, a, 0, 0, 0x101);
}

/* ARM 0x0203c9c0: reads four script arguments, forwarding the first three. */
int Unk03c6a4_Unk_03c9c0(void)
{
    s16 a = func_0203ac00(0);
    int b = func_0203ac00(1);
    int k = func_0203ac00(2);
    int m;
    func_0203ac00(3);
    m = 0;
    switch (k) {
    case 0:
        break;
    case 1:
        m = 1;
        break;
    case 2:
        m = 2;
        break;
    }
    return func_0203c748(m, a, b, 0, 0);
}

