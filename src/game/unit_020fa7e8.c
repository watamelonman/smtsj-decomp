/* Work-state reset, callback setup and indexed lookup helpers. */
#include "types.h"



/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0faa84(void) { }


/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0fae70(void) { }


/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0fae74(void) { }


/* Intentionally empty callback: the original consists only of a return. */
void Unk0fa7e8_Nop_0fae78(void) { }

u32 func_020445f4(u32 resource, u32 index);
u32 func_0204fed8(u32 resource, u32 value);
/* Forward the value through resource 0x25, entry zero, returning its result.
 * Evidence: original call operands and the consuming caller at 0x020fabf8. */
u32 Unk0fa7e8_Unk_0fb108(u32 arg0)
{
  u32 value;
  value = func_020445f4(0x25,0);
  return func_0204fed8(value,arg0);
}

void func_020655b4(u32 value);
void func_02065604(u32 value);
void func_02065bc0(void);
/* Reset the observed fields of a writable 0x30-byte work area, then reset three helpers.
 * Offset 4 and bytes 0x1c..0x27 are deliberately preserved by the original. */
void Unk0fa7e8_Unk_0fa7e8(u32 *arg0)
{
  *arg0 = 0;
  arg0[3] = 0;
  *(u16 *)(arg0 + 10) = 0;
  arg0[2] = 0;
  arg0[0xb] = 0;
  *(u8 *)(arg0 + 4) = 0;
  *(u8 *)((int)arg0 + 0x11) = 0;
  *(u8 *)((int)arg0 + 0x12) = 0;
  *(u8 *)((int)arg0 + 0x13) = 0;
  *(u8 *)(arg0 + 5) = 0;
  *(u8 *)((int)arg0 + 0x15) = 0;
  *(u8 *)((int)arg0 + 0x16) = 0;
  *(u8 *)((int)arg0 + 0x17) = 0;
  *(u8 *)(arg0 + 6) = 0;
  *(u8 *)((int)arg0 + 0x19) = 0;
  *(u8 *)((int)arg0 + 0x1a) = 0;
  *(u8 *)((int)arg0 + 0x1b) = 0;
  func_02065604(0);
  func_02065bc0();
  func_020655b4(0);
}

int Unk095560_Unk_0957c0(u32 value);
/* Query the word at +0x10 + i*4; use ID 0x259 if the first query returns zero.
 * The caller must supply a valid indexed word in p. */
int Unk0fa7e8_Unk_0fb0e0(u8 *p, int i)
{
    int r = Unk095560_Unk_0957c0(FIELD(u32, p + i * 4, 16));
    if (r != 0) {
        return r;
    }
    return Unk095560_Unk_0957c0(0x259);
}

/* Borrowed 0x30-byte callback work area; array extent follows reset stores. */
typedef struct Unk0fa7e8Work {
    u32 state;
    u32 handle;
    u32 mode;
    u32 result;
    u32 values[6];
    u16 id;
    u16 pad_2a;
    u32 notify;
} Unk0fa7e8Work;
typedef struct Unk0fa7e8Event Unk0fa7e8Event;

/* Callback addresses are stored, rather than called, by the descriptor initializer. */
void func_020faa88(Unk0fa7e8Work *work);
void func_020fae7c(Unk0fa7e8Work *work, Unk0fa7e8Event *event);

/* Descriptor layout follows the stores in func_020fa84c; field +8 is preserved. */
typedef struct Unk0fa7e8Descriptor {
    u32 size;
    u32 field04;
    u32 field08;
    void (*callbacks[6])(void);
} Unk0fa7e8Descriptor;

/* Initialize a writable descriptor with work size 0x30 and the six original callbacks.
 * Evidence: original literal relocations identify every callback address. */
void func_020fa84c(Unk0fa7e8Descriptor *descriptor)
{
    descriptor->size = 0x30;
    descriptor->field04 = 0;
    descriptor->callbacks[0] = (void (*)(void))func_020faa88;
    descriptor->callbacks[1] = Unk0fa7e8_Nop_0faa84;
    descriptor->callbacks[2] = Unk0fa7e8_Nop_0fae70;
    descriptor->callbacks[3] = Unk0fa7e8_Nop_0fae74;
    descriptor->callbacks[4] = Unk0fa7e8_Nop_0fae78;
    descriptor->callbacks[5] = (void (*)(void))func_020fae7c;
}

/* Stack messages carry two presence bytes and sixteen optional words. */
typedef struct Unk0fa7e8Message {
    u8 flags[2];
    u8 pad_02[2];
    u32 words[16];
} Unk0fa7e8Message;

void func_020bcbc4(u32 slot, Unk0fa7e8Message *message);
extern u32 data_02176e0c;

/* Clear only the flag bytes and optional words; alignment bytes are unused. */
static inline void ClearMessage(Unk0fa7e8Message *message)
{
    int i;
    for (i = 0; i < 2; i++) message->flags[i] = 0;
    for (i = 0; i < 16; i++) message->words[i] = 0;
}

/* Submit three supplied values with selector 3 and constant 6 to slot 23. */
void func_020fa8a8(u32 value, u32 argument, u32 mode)
{
    Unk0fa7e8Message m;
    int i;
    for (i = 0; i < 2; i++) m.flags[i] = 0;
    for (i = 0; i < 16; i++) m.words[i] = 0;
    m.words[6] = 3;
    m.flags[0] |= 64;
    m.words[2] = value;
    m.flags[0] |= 4;
    m.words[5] = argument;
    m.flags[0] |= 32;
    m.words[7] = 6;
    m.flags[0] |= 128;
    m.words[1] = mode;
    m.flags[0] |= 2;
    func_020bcbc4(23, &m);
}

/* Send selector 2 and return the shared response word after synchronous dispatch. */
u32 func_020fa92c(u32 value)
{
    Unk0fa7e8Message m;
    int i;
    for (i = 0; i < 2; i++) m.flags[i] = 0;
    for (i = 0; i < 16; i++) m.words[i] = 0;
    m.words[7] = value;
    m.words[6] = 2;
    m.flags[0] |= 0xc0;
    func_020bcbc4(23, &m);
    return data_02176e0c;
}

/* Send selector 1 and test whether the shared response equals one. */
int func_020fa9a0(u32 value)
{
    Unk0fa7e8Message m;
    int i;
    for (i = 0; i < 2; i++) m.flags[i] = 0;
    for (i = 0; i < 16; i++) m.words[i] = 0;
    m.words[7] = value;
    m.words[6] = 1;
    m.flags[0] |= 0xc0;
    func_020bcbc4(23, &m);
    return data_02176e0c == 1;
}

/* Send selector zero and the supplied value to slot 23. */
void func_020faa20(u32 value)
{
    Unk0fa7e8Message m;
    int i;
    for (i = 0; i < 2; i++) m.flags[i] = 0;
    for (i = 0; i < 16; i++) m.words[i] = 0;
    m.words[7] = value;
    m.words[6] = 0;
    m.flags[0] |= 0xc0;
    func_020bcbc4(23, &m);
}

/* Send the supplied values and destination 23 through slot 22. */
void func_020fadf4(u32 value, u32 phase, u32 argument)
{
    Unk0fa7e8Message m;
    int i;
    for (i = 0; i < 2; i++) m.flags[i] = 0;
    for (i = 0; i < 16; i++) m.words[i] = 0;
    m.words[2] = value;
    m.words[7] = phase;
    m.flags[0] |= 0x84;
    m.words[0] = 23;
    m.words[6] = argument;
    m.flags[0] |= 0x41;
    func_020bcbc4(22, &m);
}

int func_02065544(void);
int func_020654cc(void);
int func_0206557c(void);
int func_0206559c(void);
u32 func_020babdc(void);
int func_020bab80(void);
void func_02065c10(void);
void func_02065c30(void);
void func_02065ca8(void);
void func_0204fcb0(u32 slot, u32 value);
void func_0204faf0(u32 slot, u32 value);
void func_02065864(u32 handle, s32 value);
void func_020658dc(u32 handle, u32 mode, u32 value, u32 flags);
void Unk0bc1a8_Unk_0bc514(Unk0fa7e8Work *work, u32 value, Unk0fa7e8Message *message);
u32 Unk0bc1a8_GetHeaderWord(Unk0fa7e8Work *work, Unk0fa7e8Message *message);

/* Advance the five observed work states, forwarding optional completion messages.
 * State numbers, selectors and helper order follow the original ARM branches. */
void func_020faa88(Unk0fa7e8Work *w)
{
    Unk0fa7e8Message m;
    int i;
    switch (w->state) {
    case 0:
        if (!func_02065544()) return;
        if (!func_020654cc()) return;
        if (w->values[0]) {
            switch (w->id) {
            case 12: func_0204fcb0(4, Unk0fa7e8_Unk_0fb0e0((u8 *)w, 3));
            case 11: func_0204fcb0(3, Unk0fa7e8_Unk_0fb0e0((u8 *)w, 2));
            case 10:
                func_0204fcb0(2, Unk0fa7e8_Unk_0fb0e0((u8 *)w, 1));
                func_0204fcb0(1, Unk0fa7e8_Unk_0fb0e0((u8 *)w, 0));
                break;
            case 100: case 103:
                func_0204faf0(8, w->values[0]);
                func_0204faf0(1, w->values[1]);
                break;
            case 101: case 102: func_0204faf0(8, w->values[0]); break;
            case 110: case 111:
                func_0204fcb0(1, Unk0fa7e8_Unk_0fb108((u16)(w->values[0] - 1)));
                break;
            }
        }
        func_02065c10();
        switch (w->mode) {
        case 0: func_02065864(w->handle, -1); break;
        case 1: func_020658dc(w->handle, 1, 0, 257); break;
        case 2: func_020658dc(w->handle, 2, w->values[4], 257); break;
        }
        w->state = 1;
        break;
    case 1:
        if (!func_0206557c()) return;
        if (w->notify) func_020fadf4(w->id, 0, 0);
        if (w->mode == 0) w->state = 2;
        else w->state = 3;
        break;
    case 2:
        if (func_0206557c()) return;
        if (w->notify) func_020fadf4(w->id, 1, 0);
        func_02065c30();
        w->state = 4;
        break;
    case 3:
        if (!func_0206559c()) return;
        w->result = func_020babdc();
        if (w->notify) func_020fadf4(w->id, 1, w->result);
        func_02065c30();
        w->state = 4;
        break;
    case 4:
        if (!func_020654cc()) return;
        func_02065ca8();
        if (func_020fa9a0(w->result) || func_020bab80()) w->result = 100;
        for (i = 0; i < 2; i++) m.flags[i] = 0;
        for (i = 0; i < 16; i++) m.words[i] = 0;
        m.words[0] = 23;
        m.flags[0] |= 1;
        m.words[3] = w->result;
        m.flags[0] |= 8;
        Unk0bc1a8_Unk_0bc514(w, 1, &m);
        break;
    }
}

/* Incoming messages place their presence mask immediately after the event tag. */
struct Unk0fa7e8Event {
    u32 tag;
    Unk0fa7e8Message message;
};

/* Optional words are read before their flag is tested, matching the message ABI. */
static inline int ReadWord(Unk0fa7e8Message *m, u32 index, u32 *out)
{
    u32 value;
    if (!m) return 0;
    value = m->words[index];
    if (m->flags[index / 8] & (1 << (index % 8))) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Handle tag-four messages; selectors configure notification, response or work.
 * The sender owns all optional data, and selector three copies count words. */
void func_020fae7c(Unk0fa7e8Work *w, Unk0fa7e8Event *event)
{
    Unk0fa7e8Message *input = &event->message;
    u32 selector;
    u32 value;
    Unk0fa7e8Message m;
    u32 *temporary;
    u32 *source;
    u32 mode;
    u32 id;
    u32 i;
    switch (event->tag) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4:
        selector = 0;
        value = 0;
        if (!ReadWord(input, 6, &selector)) return;
        if (!ReadWord(input, 7, &value)) return;
        ClearMessage(&m);
        m.words[0] = Unk0bc1a8_GetHeaderWord(w, &m);
        switch (selector) {
        case 0: w->notify = value != 0; break;
        case 1:
            {
                int response;
                if (w->id == 12 && value == 4) response = 1;
                else if (w->id == 11 && value == 3) response = 1;
                else if (w->id == 10 && value == 2) response = 1;
                else response = 0;
                data_02176e0c = response;
            }
            break;
        case 2:
            data_02176e0c = value;
            if (w->state == 0) return;
            if (func_020bab80() == 1) return;
            data_02176e0c = func_020babdc();
            break;
        case 3:
            source = 0;
            mode = 0;
            id = 0;
            if (input && ReadWord(input, 5, (u32 *)&temporary)) source = temporary;
            ReadWord(input, 2, &id);
            ReadWord(input, 1, &mode);
            w->id = id;
            w->mode = mode;
            if (source) {
                for (i = 0; i < value; i++) w->values[i] = source[i];
            } else w->values[0] = 0;
            w->handle = func_0204fed8(func_020445f4(30, 5), w->id);
            break;
        }
        break;
    }
}
