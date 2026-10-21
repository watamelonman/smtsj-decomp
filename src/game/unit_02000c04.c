/* src/game/unit_02000c04.c: the ARM9 entry point `main` (startup and the endless frame loop). */
#include "types.h"

/* Display engine registers: BLDCNT for the main (A) and sub (B) engines, DISPCNT of the sub engine. */
#define REG_BLDCNT_A ((void *)0x04000050)
#define REG_BLDCNT_B ((void *)0x04001050)
#define REG_DISPCNT_B (*(volatile u32 *)0x04001000)

/* Only the frame counter at +0x14 of the block at 0x0213d338 is used here (see unit_0202cad4.c
   for the first three words). */
typedef struct MainLoopGlobals {
    u8 pad_0000[0x14];
    u32 frameCount;
} MainLoopGlobals;

/* No relocation is recorded for this word in config/arm9/relocs.txt (it lies past the static
   ARM9 image), so it is read through its fixed address. */
#define START_ARG (*(u32 *)0x0212b35c)
extern u8 data_0213d354[];
extern MainLoopGlobals data_0213d338;

void func_0204ffa8(u32 *arg, int count);
void func_02060f68(void);
void func_0201fbe8(void);
void func_0201fba8(void);
void func_02007ad4(void);
void func_0205e348(u32 a, u32 size, u8 *buf, u32 b, u32 c);
void Unk0a0ce4_Unk_0a0d04(void);
void func_0208dc78(void);
void Unk02cad4_SetupDisplayMode(int mode, u32 unused, u32 arg);
void func_02003e58(void *reg, int plane, int brightness);
void func_0205397c(void);
void func_020539cc(int arg);
void func_0202cbfc(void);
int func_02053bc8(void);
void func_02053640(void);
void func_02053cac(void);
void func_0208dd44(void);
void func_0205e464(void);
void func_02052158(void);
void func_0202cd14(void);
void func_02002860(void);
void func_02052198(void);
void func_0208dd68(void);

/* Game entry point: initialises the subsystems, blanks both screens (brightness -16), then runs
   the per-frame loop forever. The first frame only arms the start-up; on the second the
   brightness is restored, the sub engine's display is switched on (DISPCNT bit 16) and from then
   on func_0202cd14 runs every frame. */
void main(void)
{
    u32 arg = START_ARG;
    int state;

    func_0204ffa8(&arg, 1);
    func_02060f68();
    func_0201fbe8();
    func_0201fba8();
    func_02007ad4();
    func_0205e348(0, 0x40000, data_0213d354, 0, 0);
    Unk0a0ce4_Unk_0a0d04();
    func_0208dc78();
    Unk02cad4_SetupDisplayMode(0, 0, 0);
    func_02003e58(REG_BLDCNT_A, 1, -16);
    func_02003e58(REG_BLDCNT_B, 1, -16);
    func_0205397c();
    func_020539cc(1);
    func_0202cbfc();

    state = 0;
    for (;;) {
        data_0213d338.frameCount++;
        if (func_02053bc8() == 3 && state != 0) {
            func_02053640();
            func_02053cac();
        }
        func_0208dd44();
        func_0205e464();
        func_02052158();
        if (state >= 2) {
            func_0202cd14();
        } else if (state == 0) {
            state = 1;
        } else if (state == 1) {
            func_02003e58(REG_BLDCNT_A, 1, 0);
            func_02003e58(REG_BLDCNT_B, 1, 0);
            state = 2;
            func_02002860();
            REG_DISPCNT_B |= 0x10000;
        }
        func_02052198();
        func_0208dd68();
    }
}
