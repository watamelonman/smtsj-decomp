#include "types.h"

/** Partial work layout inferred from the original loads and stores; gaps are opaque. */
typedef struct Unk11fc20Work {
    s32 state;
    u32 unknown04[3];
    u32 unknown10;
    u32 unknown14;
    s32 unknown18;
    s32 unknown1c;
    u32 unknown20[2];
    s32 unknown28;
    u32 unknown2c[5];
    s32 unknown40;
    s32 unknown44;
} Unk11fc20Work;

/** Entries have a 44-byte stride, as evidenced by the loop at 02120944. */
typedef struct Unk11fc20Entry {
    s32 value;
    u32 unknown04[10];
} Unk11fc20Entry;

/** Only the entry array at offset 424 is known; its 32 elements follow the loop bound. */
typedef struct Unk11fc20Entries {
    u32 unknown00[106];
    Unk11fc20Entry entries[32];
} Unk11fc20Entries;

extern Unk11fc20Work *data_02176e7c;
extern Unk11fc20Work *func_0211fcb0(void);
extern void func_02061424(Unk11fc20Work *work);
extern void Unk0a0ce4_Unk_0a0da4(s32 value);

/** Creates the global work only when absent, following the null guard at 0211fc20. */
void Unk11fc20_Unk_11fc20(void)
{
    if (data_02176e7c != 0) return;
    data_02176e7c = func_0211fcb0();
}

/** Passes existing global work to 02061424; an absent work pointer requires no call. */
void Unk11fc20_Unk_11fc48(void)
{
    if (data_02176e7c == 0) return;
    func_02061424(data_02176e7c);
}

/** Reports absent work or state 4, evidenced by the state comparison at 0211fc68. */
s32 Unk11fc20_IsState4(void)
{
    if (data_02176e7c == 0) return 1;
    return data_02176e7c->state == 4;
}

/** Returns the word at work offset 16, or zero when no work exists. */
u32 Unk11fc20_Unk_11fc94(void)
{
    if (data_02176e7c == 0) return 0;
    return data_02176e7c->unknown10;
}

/** Clears the global pointer without releasing its target, as the sole store at 0211fd24 shows. */
void Unk11fc20_Clear_data_02176e7c(void)
{
    data_02176e7c = 0;
}

/** Requires valid work; decreases offset 40 by 4096 and reports whether it is at most 8192. */
s32 Unk11fc20_Unk_120650(Unk11fc20Work *work)
{
    work->unknown28 -= 4096;
    return work->unknown28 <= 8192;
}

/** Requires valid work; advances the offset-68 countdown and selects the next state fields. */
s32 Unk11fc20_Unk_12066c(Unk11fc20Work *work)
{
    Unk0a0ce4_Unk_0a0da4(3);
    work->unknown40 = 0;
    work->unknown44 -= 4096;
    if (work->unknown44 <= 4096) {
        work->unknown1c = 0;
        return 1;
    }
    work->unknown18 = 15;
    return 0;
}

/** Counts nonzero words across the 32 entries starting at offset 424; requires valid work. */
s32 Unk11fc20_Unk_120944(const Unk11fc20Entries *work)
{
    s32 count = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (work->entries[i].value != 0) count++;
    }
    return count;
}

/* Request-provider declarations and coordinate forwarding helpers. */
void func_02120bd4(u32, u32, s32, s32, s32, s32, u32, u32, u32);
void func_02057d54(u32, s32, s32, u32, u32, u32);
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/** Submits kind 4 using work coordinates at +12/+16; the second input is in pixels. */
void Unk11fc20_Unk_12143c(Unk11fc20Work *arg0,int arg1,u32 arg2)
{
  func_02120bd4(4,0,arg0->unknown04[2],arg0->unknown10,0x3000,
                arg1 << 0xc,arg2,0,0);
  return;
}

/** Initializes the observed work header and signals provider 020a0da4 with 8. */
void Unk11fc20_Unk_11fd38(u32 *arg0)
{
  arg0[3] = 100;
  *arg0 = 0;
  arg0[6] = 0;
  arg0[7] = 1;
  arg0[10] = 0x40000;
  arg0[0xb] = 0xb8000;
  arg0[0x11] = 0x4000;
  Unk0a0ce4_Unk_0a0da4(8);
  return;
}

/** Converts four pixel coordinates to 20.12 before submitting the nine-word request. */
void Unk11fc20_Unk_120b88(u32 arg0,u32 arg1,int arg2,int arg3,int arg4,
                  int arg5,u32 arg6,u32 arg7,u32 arg8)
{
  func_02120bd4(arg0,arg1,arg2 << 0xc,arg3 << 0xc,arg4 << 0xc,arg5 << 0xc,arg6,
                arg7,arg8);
  return;
}

/** Finds the first free entry in the selected global pool; selector bounds follow 02120a58. */
int * Unk11fc20_Unk_120a58(u32 arg0)
{
  int *v1;
  int tmp2;
  tmp2 = (u32)data_02176e7c;
  switch(arg0) {
  case 0:
    break;
  case 1:
    v1 = (int *)(tmp2 + 0x48);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 8);
    break;
  case 2:
    v1 = (int *)(tmp2 + 0x728);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x10);
    break;
  case 3:
    v1 = (int *)(tmp2 + 0x1a8);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x20);
    break;
  case 4:
    v1 = (int *)(tmp2 + 0x9e8);
    tmp2 = 0;
    do {
      if (*v1 == 0) {
        return v1;
      }
      tmp2 = tmp2 + 1;
      v1 = v1 + 0xb;
    } while (tmp2 < 0x80);
  }
  return (int *)0x0;
}

/** Adds global offsets +4/+8 and the observed 64-pixel X bias before forwarding. */
void Unk11fc20_Unk_120898(u32 a, int b, int c, u32 d, u32 e, u32 f)
{
    u8 *w = (u8 *)(u32)data_02176e7c;
    func_02057d54(a, b + (FIELD(int, w, 4) + 64), c + FIELD(int, w, 8), d, e, f);
}

/** Converts all seven coordinate inputs from pixels to 20.12 for provider 02120bd4. */
void func_02120b30(u32 a, u32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i)
{
    func_02120bd4(a, b, c << 12, d << 12, e << 12, f << 12,
                   g << 12, h << 12, i << 12);
}

extern void func_0212034c(Unk11fc20Work *);
extern void func_021206a8(Unk11fc20Work *);
extern Unk11fc20Work *func_020611dc(void (*)(Unk11fc20Work *),
    void (*)(Unk11fc20Work *), u32, void (*)(void), u32, u32, u32, u32);
/** Allocates 0x1fe8 bytes with the observed callbacks; publishes and initializes successful work. */
Unk11fc20Work *func_0211fcb0(void)
{
    Unk11fc20Work *work = func_020611dc(func_0212034c, func_021206a8, 0,
        Unk11fc20_Clear_data_02176e7c, 0x1fe8, 4, 0, 1);
    if (work == 0) return 0;
    data_02176e7c = work;
    Unk11fc20_Unk_11fd38((u32 *)work);
    return work;
}

/** Borrowed 44-byte slot view; positions, velocities and extent use 20.12 units (02120bd4/021212f4). */
typedef struct Unk11fc20Slot {
    s32 active, kind, unknown08;
    s32 x, y, dx, dy, ax, ay, ticks, extent;
} Unk11fc20Slot;

extern void func_02120d7c(Unk11fc20Slot *slot);
/** Advances a live slot's velocity and position; clears it outside the observed 128x192 bounds. */
void func_02120cb4(Unk11fc20Slot *slot)
{
    slot->ticks++;
    if (slot->kind == 3) func_02120d7c(slot);
    slot->dx += slot->ax;
    slot->dy += slot->ay;
    slot->x += slot->dx;
    slot->y += slot->dy;
    if (slot->x < -slot->extent) slot->active = 0;
    if (slot->x > slot->extent + 0x80000) slot->active = 0;
    if (slot->y < -slot->extent) slot->active = 0;
    if (slot->y > slot->extent + 0xc0000) slot->active = 0;
}

extern s32 func_020537b8(s32 device, s32 mask);
/** Reads directional masks 16/32/64/128, clamps the slot and submits kind 1 on mask 1 (0211fd7c). */
void func_0211fd7c(Unk11fc20Slot *slot)
{
    s32 x, y;
    if (!slot->active) return;
    if (slot->extent < 0x4000) {
        slot->ticks++;
        if (slot->ticks > 45) {
            slot->extent += 0x1000;
            slot->ticks = 0;
        }
    }
    x = 0;
    y = 0;
    if (func_020537b8(0, 32)) x = -1;
    if (func_020537b8(0, 16)) x = 1;
    if (func_020537b8(0, 64)) y = -1;
    if (func_020537b8(0, 128)) y = 1;
    if (x == 0) slot->y += (y * 3) << 12;
    else if (y == 0) slot->x += (x * 3) << 12;
    else {
        slot->x += x * 0x21f0;
        slot->y += y * 0x21f0;
    }
    if (slot->x < slot->extent) slot->x = slot->extent;
    if (slot->x > 0x80000 - slot->extent) slot->x = 0x80000 - slot->extent;
    if (slot->y < slot->extent) slot->y = slot->extent;
    if (slot->y > 0xc0000 - slot->extent) slot->y = 0xc0000 - slot->extent;
    if (func_020537b8(0, 1))
        func_02120bd4(1, 0, slot->x, slot->y, 0x3000, 0x5a000, 0xa000, 0, 0);
}

/** Draws the tens and units of work +16 with provider rectangles observed at 02120970. */
void func_02120970(Unk11fc20Work *work)
{
    s32 tens = (s32)work->unknown10 / 10;
    s32 ones = (s32)work->unknown10 % 10;
    s32 i;
    s32 row;
    s32 j;
    for (i = 0; i < tens; i++)
        Unk11fc20_Unk_120898(0xffff0000, 3 + i * 5, 3, 3, 3, 19);
    row = 0;
    if (tens > 0) row = 1;
    for (j = 0; j < ones; j++)
        Unk11fc20_Unk_120898(0xffff0000, 3 + j * 3, 3 + row * 5, 1, 1, 19);
}

/** Submits a kind-specific rectangle; kind 4 oscillates its bounds with a 32-tick period (021212f4). */
void func_021212f4(Unk11fc20Slot *slot)
{
    s32 x, y, width, height, phase;
    if (slot->active == 0) return;
    x = (slot->x - slot->extent) >> 12;
    y = (slot->y - slot->extent) >> 12;
    width = height = slot->extent >> 11;
    switch (slot->kind) {
    case 0: Unk11fc20_Unk_120898(0x4040ff00, x, y, width, height, 20); break;
    case 1: Unk11fc20_Unk_120898(0x8080ff00, x, y, width, height, 20); break;
    case 2: Unk11fc20_Unk_120898(0x00ffff00, x, y, width, height, 20); break;
    case 3: Unk11fc20_Unk_120898(0x00ff0000, x, y, width, height, 20); break;
    case 4:
        phase = slot->ticks % 32;
        if (phase < 8) { width += 2; x--; y++; height -= 2; }
        else if (phase >= 16 && phase < 24) { width -= 2; x++; y--; height += 2; }
        Unk11fc20_Unk_120898(0xff000000, x, y, width, height, 20);
        break;
    }
}

extern const s16 data_0212629c[];
/** Allocates a pool slot; angle is 20.12 degrees, coordinates/speed are 20.12 (02120bd4 table arithmetic). */
void func_02120bd4(u32 kind, u32 value, s32 x, s32 y, s32 extent, s32 angle,
                   u32 speed, u32 ax, u32 ay)
{
    Unk11fc20Slot *slot;
    s32 index;
    s32 sine, cosine;
    s32 dx, dy;
    if (kind == 4 && y > 0xa0000) return;
    slot = (Unk11fc20Slot *)Unk11fc20_Unk_120a58(kind);
    if (slot == 0) return;
    index = (u16)(((s64)angle * 0xb60b60b60bLL + 0x80000000000LL) >> 44) >> 4;
    cosine = data_0212629c[index * 2 + 1];
    sine = data_0212629c[index * 2];
    dx = ((s32)speed * cosine) >> 12;
    dy = ((s32)speed * sine) >> 12;
    slot->active = 1;
    slot->kind = kind;
    slot->unknown08 = value;
    slot->x = x;
    slot->y = y;
    slot->extent = extent;
    slot->dx = dx;
    slot->dy = -dy;
    slot->ax = ax;
    slot->ay = ay;
    slot->ticks = 0;
}

/** Work storage view: pool extents are fixed by the four original loop bounds. */
typedef struct Unk11fc20All {
    s32 state, offsetX, offsetY, transition, count, ticks, countdown;
    Unk11fc20Slot player;
    Unk11fc20Slot pool1[8], pool3[32], pool2[16], pool4[128];
} Unk11fc20All;
extern void func_02057524(s32 value);
extern void func_02057fd8(void);
extern void func_02057e18(s32 value);
extern void func_02057534(void);
/** Draws transition bounds or the active pools; state 4 suppresses all rendering (021206a8). */
void func_021206a8(Unk11fc20Work *work)
{
    Unk11fc20All *w = (Unk11fc20All *)work;
    s32 transition;
    u32 color;
    if (w->state == 4) return;
    func_02057524(4);
    func_02057fd8();
    func_02057e18(25);
    color = 0;
    if (w->player.extent <= 0x2000) color = 0x80000000;
    switch (w->state) {
    case 0:
        transition = (w->transition << 6) / 100;
        Unk11fc20_Unk_120898(color, transition, 0, (64 - transition) * 2, 192, 18);
        return;
    case 3:
        transition = (w->transition << 6) / 100;
        Unk11fc20_Unk_120898(color, 64 - transition, 0, transition * 2, 192, 18);
        return;
    }
    Unk11fc20_Unk_120898(color, 0, 0, 128, 192, 18);
    func_02057e18(31);
    func_02120970(work);
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool1;
        for (index = 0; index < 8; index++, entry++)
            if (entry->active) func_021212f4(entry);
    }
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool2;
        for (index = 0; index < 16; index++, entry++)
            if (entry->active) func_021212f4(entry);
    }
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool3;
        for (index = 0; index < 32; index++, entry++)
            if (entry->active) func_021212f4(entry);
    }
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool4;
        for (index = 0; index < 128; index++, entry++)
            if (entry->active) func_021212f4(entry);
    }
    if (w->countdown % 4 < 2) func_021212f4(&w->player);
    func_02057534();
}

extern void func_0211ff14(Unk11fc20Work *work);
extern s32 func_021208dc(const Unk11fc20Slot *a, const Unk11fc20Slot *b);
/** Advances the five-state work controller and resolves pool/player and pool/pool overlaps (0212034c). */
void func_0212034c(Unk11fc20Work *work)
{
    Unk11fc20All *w = (Unk11fc20All *)work;
    s32 i;
    Unk11fc20Slot *slot;
    switch (w->state) {
    case 0:
        w->transition = w->transition * 90 / 100;
        if (w->transition < 1) { w->state = 1; w->ticks = 0; }
        return;
    case 1:
        w->ticks++;
        func_0211ff14(work);
        if (w->ticks >= 880 && Unk11fc20_Unk_120944((Unk11fc20Entries *)work) == 0) {
            w->state = 2;
            w->transition = 30;
            return;
        }
        break;
    case 2:
        w->transition--;
        if (w->transition < 1) { w->state = 3; w->transition = 100; }
        break;
    case 3:
        w->transition = w->transition * 90 / 100;
        if (w->transition < 1) w->state = 4;
        return;
    case 4: return;
    }
    if (w->countdown > 0) w->countdown--;
    func_0211fd7c(&w->player);
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool1;
        for (index = 0; index < 8; index++, entry++)
            if (entry->active) func_02120cb4(entry);
    }
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool2;
        for (index = 0; index < 16; index++, entry++)
            if (entry->active) func_02120cb4(entry);
    }
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool3;
        for (index = 0; index < 32; index++, entry++)
            if (entry->active) func_02120cb4(entry);
    }
    {
        s32 index;
        Unk11fc20Slot *entry = w->pool4;
        for (index = 0; index < 128; index++, entry++)
            if (entry->active) func_02120cb4(entry);
    }
    if (w->state != 1) return;
    slot = w->pool4;
    for (i = 0; i < 128; i++, slot++) {
        if (slot->active && w->countdown == 0 && func_021208dc(slot, &w->player)) {
            slot->active = 0;
            if (Unk11fc20_Unk_12066c(work)) {
                w->state = 2;
                w->transition = 30;
                Unk0a0ce4_Unk_0a0da4(6);
                return;
            }
            if (w->count > 0) w->count--;
            break;
        }
    }
    {
        s32 outerIndex;
        s32 j;
        Unk11fc20Slot *target;
        Unk11fc20Slot *other;
        target = w->pool3;
        for (outerIndex = 0; outerIndex < 32; outerIndex++, target++) {
            if (!target->active) continue;
            other = w->pool1;
            for (j = 0; j < 8; j++, other++) {
                if (other->active && func_021208dc(target, other)) {
                    other->active = 0;
                    if (Unk11fc20_Unk_120650((Unk11fc20Work *)target)) {
                        target->active = 0;
                        w->count++;
                        break;
                    }
                }
            }
        }
    }
}

/** Submits paired slot requests at the eight work ticks compared in 0211ff14; requires full work. */
void func_0211ff14(Unk11fc20Work *work)
{
    switch ((s32)work->unknown14) {
    case 30:
        func_02120b30(3, 1, 32, 8, 8, 270, 3, 0, 0);
        func_02120b30(3, 1, 96, 8, 8, 270, 3, 0, 0);
        break;
    case 200:
        Unk11fc20_Unk_120b88(3, 3, 32, 8, 8, 270, 4096, 0, 64);
        Unk11fc20_Unk_120b88(3, 3, 96, 8, 8, 270, 4096, 0, 64);
        break;
    case 360:
        Unk11fc20_Unk_120b88(3, 1, 32, 8, 10, 270, 8192, 256, 0);
        Unk11fc20_Unk_120b88(3, 1, 96, 8, 10, 270, 8192, -256, 0);
        break;
    case 480:
        Unk11fc20_Unk_120b88(3, 4, 32, 8, 8, 270, 8192, 256, 0);
        Unk11fc20_Unk_120b88(3, 4, 96, 8, 8, 270, 8192, -256, 0);
        break;
    case 600:
        Unk11fc20_Unk_120b88(3, 6, 32, 8, 8, 270, 20480, 0, 0);
        Unk11fc20_Unk_120b88(3, 6, 96, 8, 8, 270, 20480, 0, 0);
        break;
    case 720:
        Unk11fc20_Unk_120b88(3, 7, 8, 8, 8, 270, 4096, 0, 0);
        Unk11fc20_Unk_120b88(3, 7, 120, 8, 8, 270, 4096, 0, 0);
        break;
    case 840:
        func_02120b30(3, 1, 32, 8, 6, 270, 2, 0, 0);
        func_02120b30(3, 1, 96, 8, 6, 270, 2, 0, 0);
        break;
    case 880:
        Unk11fc20_Unk_120b88(3, 8, 16, 8, 6, 270, 4096, 64, 0);
        Unk11fc20_Unk_120b88(3, 8, 112, 8, 6, 270, 4096, -64, 0);
        break;
    }
}

extern void func_02121478(Unk11fc20Slot *slot, s32 angle, s32 speed);
extern s32 func_02050074(s32 lower, s32 upper);
/** Dispatches subtype-specific timed requests and velocity decay, evidenced by 02120d7c's switch.
 * Requires a live 44-byte slot; positions and velocities use 20.12 units. */
void func_02120d7c(Unk11fc20Slot *slot)
{
    s32 x = slot->x >> 12;
    s32 y = slot->y >> 12;
    s32 ticks = slot->ticks;
    switch (slot->unknown08) {
    case 1:
        if (ticks == 3) {
            func_02120b30(3, 2, x, y, 6, 225, 5, 0, 0);
            func_02120b30(3, 2, x, y, 6, 315, 5, 0, 0);
        }
        if (slot->ticks == 10) {
            func_02120b30(3, 2, x, y, 4, 240, 7, 0, 0);
            func_02120b30(3, 2, x, y, 4, 300, 7, 0, 0);
        }
        if (slot->ticks == 15) {
            func_02120b30(3, 2, x, y, 4, 255, 8, 0, 0);
            func_02120b30(3, 2, x, y, 4, 285, 8, 0, 0);
        }
        break;
    case 2:
        if (ticks < 300) {
            slot->dx = slot->dx * 90 / 100;
            slot->dy = slot->dy * 90 / 100;
            if (ticks % 60 == 0) {
                s32 i;
                for (i = 0; i < 3; i++) func_02121478(slot, (1 - i) * -3, 8192);
            }
        }
        if (slot->ticks == 300) slot->ay = -6144;
        break;
    case 3:
        if (ticks % 40 == 0) {
            s32 i;
            s32 speed = 4096;
            for (i = 0; i < 8; i++, speed += 512) {
                func_02121478(slot, -30, speed);
                func_02121478(slot, 0, speed);
                func_02121478(slot, 30, speed);
            }
        }
        break;
    case 4:
        if (ticks == 15 || ticks == 30) {
            s32 i = 0;
            s32 angle = 0;
            for (; i < 12; i++, angle += 30)
                func_02120b30(3, 5, x, y, 4, angle, 3, 0, 0);
        }
        break;
    case 5:
        if (ticks < 240) {
            slot->dx = slot->dx * 90 / 100;
            slot->dy = slot->dy * 90 / 100;
            if (ticks % 60 == 0) func_02121478(slot, 0, 12288);
        }
        if (slot->ticks == 240) {
            if (func_02050074(1, 2) == 0) slot->ax = 1536;
            else slot->ax = -1536;
            slot->ay = -6144;
        }
        break;
    case 6:
        slot->dx = slot->dx * 90 / 100;
        slot->dy = slot->dy * 90 / 100;
        if (slot->ticks < 60) break;
        if (slot->ticks < 240) {
            if (ticks % 2 == 0) {
                s32 angle = ticks << 14;
                s32 index = (u16)(((s64)angle * 0xb60b60b60bLL + 0x80000000000LL) >> 44) >> 4;
                Unk11fc20_Unk_12143c((Unk11fc20Work *)slot,
                    ((data_0212629c[index * 2] * 25) >> 12) + 270, 12288);
            }
        } else if (slot->ticks == 240) slot->ay = -6144;
        break;
    case 7:
        if (ticks % 8 == 0) {
            s32 angle = 0;
            s32 acceleration = 64;
            if (x > 64) { angle = 180; acceleration = -64; }
            Unk11fc20_Unk_120b88(4, 0, x, y, 3, angle, 8192, acceleration, 0);
        }
        break;
    case 8:
        Unk11fc20_Unk_12143c((Unk11fc20Work *)slot, ticks << 3, 8192);
        break;
    }
}
