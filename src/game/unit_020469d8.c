/* Neutral names retain the original symbols; behavior is evidenced by ARM9 calls. */
#include "types.h"


void *Unk044904_Unk_044ff4(void);
int Unk044904_Unk_0459ec(void);
void func_02049594(void *context);
void func_02049620(void *context);
/* Initialize the current context, then conditionally run its second setup pass.
 * Evidence: the context getter feeds both setup calls at 020469dc..020469f4. */
u32 Unk0469d8_Unk_0469d8(void)
{
  int value;
  func_02049594(Unk044904_Unk_044ff4());
  value = Unk044904_Unk_0459ec();
  if (value != 0) {
    func_02049620(Unk044904_Unk_044ff4());
  }
  return 2;
}

void func_020496d0(void *context);
void Unk09d060_Unk_09d1b0(void);
int Unk09d42c_Unk_09d4bc(void);
/* Advance context setup; signal state 2 when the readiness probe is clear.
 * arg0 borrows the runner state halfword (STRH at 02046a20). */
u32 Unk0469d8_Unk_046a00(u16 *arg0)
{
  int value;
  func_020496d0(Unk044904_Unk_044ff4());
  Unk09d060_Unk_09d1b0();
  value = Unk09d42c_Unk_09d4bc();
  if (value == 0) {
    *arg0 = 2;
  }
  return 2;
}

/** Borrowed runner state: the signed phase at +6 selects four update steps. */
typedef struct Unk0469d8State {
    u16 state;
    u16 field2;
    u16 field4;
    s16 phase;
} Unk0469d8State;

void func_0209d500(void);
int Unk09d42c_Unk_09d4e0(void);
void Unk09d42c_Init_data_02176278(void);
void Unk071dc0_Unk_071fcc(void);
void func_02072068(void);
int Unk071dc0_GetMode604Sign(void);

/* Poll two successive subsystems; phases 0 and 2 deliberately fall through.
 * Evidence: signed +6 loads and the four-way switch at 02046a34..02046aa8. */
int func_02046a2c(Unk0469d8State *work)
{
    switch (work->phase) {
    case 0:
        Unk09d42c_Unk_09d4bc();
        work->phase++;
    case 1:
        func_0209d500();
        if (Unk09d42c_Unk_09d4e0()) {
            Unk09d42c_Init_data_02176278();
            work->phase++;
        }
        break;
    case 2:
        Unk071dc0_Unk_071fcc();
        work->phase++;
    case 3:
        func_02072068();
        if (Unk071dc0_GetMode604Sign())
            return 1;
        break;
    }
    return 0;
}

/** Borrowed queue record; +4 is an unsigned scheduling threshold. */
typedef struct Unk0469d8Record {
    s32 kind;
    u32 threshold;
} Unk0469d8Record;

Unk0469d8Record *func_02049724(void *context);
void func_02049744(void *context);
u32 Unk09d060_GetCtxUnk00(void);
int func_02046ab4(Unk0469d8Record *record, Unk0469d8State *work);

/* Consume eligible records until dispatch stops or the queue empties.
 * Evidence: +4 unsigned comparison at 02047300 and pop after dispatch. */
int func_020472e0(Unk0469d8State *work)
{
    Unk0469d8Record *record;
    int result;
    do {
        record = func_02049724(Unk044904_Unk_044ff4());
        if (record == 0)
            return 1;
        if (record->threshold > Unk09d060_GetCtxUnk00())
            return 0;
        result = func_02046ab4(record, work);
        func_02049744(Unk044904_Unk_044ff4());
    } while (result != 0);
    return 1;
}
