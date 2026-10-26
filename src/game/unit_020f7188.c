/* Field offsets are evidenced by the loads/stores in the original ARM code. */
typedef unsigned int u32;
typedef signed short s16;

/* Layout of the object registered at 0x02176e08; field purposes are unknown. */
typedef struct Unk0f7188State {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    s16 unk_0c;
    s16 pad_0e;
    int unk_10;
    u32 unk_14;
    u32 unk_18;
    int unk_1c;
} Unk0f7188State;

extern Unk0f7188State *data_02176e08;
void func_02065cfc(int a, s16 id);
void Unk0f7188_Unk_0f7ca8(u32 value);

/* Tests signed field 0x10 against 0x1c only in state 10 with field 0x14 clear. */
int Unk0f7188_Unk_0f7210(const Unk0f7188State *p)
{
    if (p->unk_08 != 10) {
        return 0;
    }
    if (p->unk_14 != 0) {
        return 0;
    }
    return p->unk_10 >= p->unk_1c;
}

/* Registers caller-owned storage and clears the four fields written by the original. */
void Unk0f7188_Unk_0f780c(Unk0f7188State *p)
{
    data_02176e08 = p;
    p->unk_00 = 0;
    p->unk_08 = 0;
    p->unk_14 = 0;
    p->unk_18 = 0;
}

/* No-op callback: the original consists solely of bx lr. */
void Unk0f7188_Nop_0f7884(void) { }

/* No-op callback: the original consists solely of bx lr. */
void Unk0f7188_Nop_0f7ae0(void) { }

/* No-op callback: the original consists solely of bx lr. */
void Unk0f7188_Nop_0f7ae4(void) { }

/* Updates three fields when registered; the original reloads the global after each store. */
void func_020f7c64(u32 value, s16 id, int limit)
{
    if (data_02176e08 != 0) {
        data_02176e08->unk_10 = limit;
        data_02176e08->unk_0c = id;
        data_02176e08->unk_04 = value;
    }
}

/* Tail-calls 0x02065cfc with constant 1 and a signed 16-bit argument (ARM evidence). */
void Unk0f7188_Call_02065cfc(int id)
{
    func_02065cfc(1, (s16)id);
}

/* Stores field 0x18 only when caller-owned storage has been registered. */
void Unk0f7188_Unk_0f7ca8(u32 value)
{
    if (data_02176e08 != 0) {
        data_02176e08->unk_18 = value;
    }
}

/* Sets field 0x18 to one for states 0, 1, 7, 8 and 10, otherwise zero. */
void Unk0f7188_Unk_0f7cc0(u32 arg0)
{
  switch(arg0) {
  case 0:
    goto LAB_020f7cfc;
  case 1:
    goto LAB_020f7cfc;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    goto LAB_020f7cfc;
  case 8:
    goto LAB_020f7cfc;
  case 9:
    break;
  case 10:
LAB_020f7cfc:
    Unk0f7188_Unk_0f7ca8(1);
    return;
  }
  Unk0f7188_Unk_0f7ca8(0);
}

/* Borrowed callback descriptor: offsets and the constant size come from 0f7830. */
struct Unk0f7188Event;
typedef struct Unk0f7188Descriptor {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*unk_0c)(Unk0f7188State *);
    void (*unk_10)(void);
    u32 unk_14;
    void (*unk_18)(void);
    void (*unk_1c)(void);
    void (*unk_20)(Unk0f7188State *, const struct Unk0f7188Event *);
} Unk0f7188Descriptor;
typedef struct Unk0f7188Event Unk0f7188Event;
void func_020f7888(Unk0f7188State *p);
void func_020f7ae8(Unk0f7188State *p, const Unk0f7188Event *event);
u32 func_020445f4(int group, int index);
u32 func_0204fed8(u32 handle, u32 value);

/* Initializes the callback descriptor; ARM literals identify the five callbacks.
 * Offset 8 is deliberately retained, as the original never writes it. */
void func_020f7830(Unk0f7188Descriptor *p)
{
    p->size = 28;
    p->unk_04 = 0;
    p->unk_0c = func_020f7888;
    p->unk_10 = Unk0f7188_Nop_0f7884;
    p->unk_14 = 0;
    p->unk_18 = Unk0f7188_Nop_0f7ae0;
    p->unk_1c = Unk0f7188_Nop_0f7ae4;
    p->unk_20 = func_020f7ae8;
}

/* ARM stores establish the signed ID and boolean-to-0/2 field conversion;
 * calls resolve group 12/index 27, then update field 0x18 through the selector. */
void func_020f7bac(u32 value, s16 id, int enabled)
{
    if (data_02176e08 == 0) return;
    if (enabled) {
        data_02176e08->unk_10 = 2;
    } else {
        data_02176e08->unk_10 = 0;
    }
    data_02176e08->unk_0c = id;
    data_02176e08->unk_04 = func_0204fed8(func_020445f4(12, 27), value);
    Unk0f7188_Unk_0f7cc0(value);
}

/* Like 0f7bac, but stores the caller's full limit at offset 0x10 (ARM evidence). */
void func_020f7c10(u32 value, s16 id, int limit)
{
    if (data_02176e08 == 0) return;
    data_02176e08->unk_10 = limit;
    data_02176e08->unk_0c = id;
    data_02176e08->unk_04 = func_0204fed8(func_020445f4(12, 27), value);
    Unk0f7188_Unk_0f7cc0(value);
}

/* Stack request view: two flag bytes and sixteen words, evidenced by ARM loops.
 * Callees borrow the request only for the duration of the call. */
/* One-word record copies retain the original source stack stores. See DEC-013. */
typedef struct Unk0f7188Word {
    u32 value;
} Unk0f7188Word;

typedef struct Unk0f7188Request {
    unsigned char flags[2];
    unsigned char pad_02[2];
    Unk0f7188Word words[16];
} Unk0f7188Request;
void func_020bcacc(u32 kind, const Unk0f7188Request *request);
void func_020bc9f4(u32 kind, const Unk0f7188Request *request);
void func_020bcbc4(u32 kind, const Unk0f7188Request *request);

/* Submits kind with flag 1 and record 0 set to 65535 to 020bcacc.
 * ARM stores establish the mask and value; the request is borrowed during the call. */
void func_020f7d14(u32 kind)
{
    Unk0f7188Request request;
    int i;
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.words[i].value = 0;
    Unk0f7188Word word;
    word.value = 65535;
    request.words[0] = word;
    request.flags[0] |= 1;
    func_020bcacc(kind, &request);
}

/* Submits the caller value in record 0 with flag 1 to 020bcacc.
 * ARM stores establish the index and mask; kind is the second argument. */
void func_020f7d7c(u32 value, u32 kind)
{
    Unk0f7188Request request;
    int i;
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.words[i].value = 0;
    Unk0f7188Word word = {value};
    request.words[0] = word;
    request.flags[0] |= 1;
    func_020bcacc(kind, &request);
}

/* Submits the caller value in record 2 with flag 4 to 020bc9f4.
 * ARM stores establish the index and mask; the request is borrowed during the call. */
void func_020f7de4(u32 kind, u32 value)
{
    Unk0f7188Request request;
    int i;
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.words[i].value = 0;
    request.flags[0] |= 4;
    Unk0f7188Word word = {value};
    request.words[2] = word;
    func_020bc9f4(kind, &request);
}

/* Submits caller values in records 6 and 7 with flags 0xc0 to 020bcbc4.
 * ARM stores establish the indices and mask; the request is borrowed during the call. */
void func_020f7e48(u32 kind, u32 first, u32 second)
{
    Unk0f7188Request request;
    int i;
    for (i = 0; i < 2; i++) request.flags[i] = 0;
    for (i = 0; i < 16; i++) request.words[i].value = 0;
    Unk0f7188Word word = {first};
    request.words[6] = word;
    Unk0f7188Word other = {second};
    request.words[7] = other;
    request.flags[0] |= 192;
    func_020bcbc4(kind, &request);
}

/* Borrowed 0x40-byte record, evidenced by word accesses in 0f7188/0f7248. */
typedef struct Unk0f7188Record {
    u32 unk_00, unk_04, unk_08, unk_0c;
    int unk_10, unk_14, unk_18, unk_1c;
    int unk_20, unk_24;
    u32 unk_28, unk_2c, unk_30;
    void (*unk_34)(struct Unk0f7188Record *);
    void (*unk_38)(struct Unk0f7188Record *);
    void (*unk_3c)(struct Unk0f7188Record *, u32, u32);
} Unk0f7188Record;
int func_020fec00(Unk0f7188Record *record);

/* Advance the signed value only when 020fec00 permits it; clamp at either
 * bound and restore field 8 from field 0xc on crossing (ARM comparisons). */
int func_020f7188(Unk0f7188Record *p)
{
    if (!func_020fec00(p)) return 0;
    if (p->unk_14 != 0) {
        p->unk_10 += p->unk_14;
        if (p->unk_10 < p->unk_18) {
            p->unk_10 = p->unk_18;
            p->unk_14 = 0;
            p->unk_08 = p->unk_0c;
            return 1;
        }
        if (p->unk_10 > p->unk_1c) {
            p->unk_10 = p->unk_1c;
            p->unk_14 = 0;
            p->unk_08 = p->unk_0c;
            return 1;
        }
    }
    return 0;
}

/* Event payload follows its kind word; flags indicate which words are present. */
struct Unk0f7188Event {
    u32 kind;
    Unk0f7188Request request;
};

/* Return presence separately from value, retaining the caller's word if absent.
 * The original reads the requested word even when its flag is clear. */
static inline int Unk0f7188_Read(const Unk0f7188Request *p, int index, Unk0f7188Word *out)
{
    if (p == 0) return 0;
    int present = 0;
    {
        u32 value = p->words[index].value;
        if (p->flags[index / 8] & (1 << (index % 8))) {
            *(u32 *)out = value;
            present = 1;
        } else {
            present = 0;
        }
    }
    return present;
}
void func_02065604(int value);
void func_02065bc0(void);
void func_020655b4(int value);

/* Kind zero toggles both 02065604 and 020655b4 using presence of word 4.
 * Evidence: ARM tests flag 0x10 twice around the 02065bc0 call. */
void func_020f7ae8(Unk0f7188State *p, const Unk0f7188Event *event)
{
    Unk0f7188Word value = {0};
    const Unk0f7188Request *request = &event->request;
    switch (event->kind) {
    case 0:
        if (Unk0f7188_Read(request, 4, &value)) func_02065604(0);
        else func_02065604(1);
        func_02065bc0();
        if (Unk0f7188_Read(request, 4, &value)) func_020655b4(0);
        else func_020655b4(1);
        break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    }
}

/* Borrowed result prefix: byte 2 is read after the ID lookup in 0f7888. */
typedef struct Unk0f7188Lookup { unsigned char pad[2], unk_02; } Unk0f7188Lookup;
int func_02065544(void);
int func_020654cc(void);
void func_0204faf0(u32 index, u32 value);
Unk0f7188Lookup *func_020a1428(unsigned short id);
void func_020658dc(u32 handle, int mode, u32 value, u32 flags);
void func_02065864(u32 handle, int mode);
int func_0206557c(void);
int func_02065cd0(void);
void func_02065c30(void);
int func_0206559c(void);
u32 func_020babdc(void);
void func_02065ca8(void);
int Unk0bc1a8_IsSlotEmpty(u32 slot);
void Unk0bc1a8_Unk_0bc514(Unk0f7188State *p, u32 kind, const Unk0f7188Request *request);

/* Advance phases 0..4, waiting on the observed service predicates. ARM calls
 * establish ID slots 6/7, mode flags 0x101 and the final kind-1 request. */
void func_020f7888(Unk0f7188State *p)
{
    switch (p->unk_00) {
    case 0:
        if (!func_02065544()) return;
        if (!func_020654cc()) return;
        if ((unsigned short)p->unk_0c != 0) {
            func_0204faf0(6, (unsigned short)p->unk_0c);
            func_0204faf0(7, func_020a1428((unsigned short)p->unk_0c)->unk_02);
        }
        if (p->unk_10 == 4) {
            func_020658dc(p->unk_04, 0, p->unk_18, 0x101);
        } else if (p->unk_10 == 2) {
            func_020658dc(p->unk_04, 1, p->unk_18, 0x101);
        } else if (p->unk_10 == 1) {
            func_020658dc(p->unk_04, 0, p->unk_18, 0x101);
        } else if (p->unk_10 == 3) {
            func_02065864(p->unk_04, 2);
        } else {
            func_02065864(p->unk_04, -1);
        }
        p->unk_00 = 1;
        break;
    case 1:
        if (!func_0206557c()) return;
        if (p->unk_10 == 0) p->unk_00 = 2;
        else p->unk_00 = 3;
        break;
    case 2:
        if (func_0206557c()) return;
        if (!func_02065cd0()) return;
        func_02065c30();
        p->unk_00 = 4;
        break;
    case 3:
        if (!func_0206559c()) return;
        p->unk_08 = func_020babdc();
        func_02065c30();
        p->unk_00 = 4;
        break;
    case 4:
        if (p->unk_14 == 0 && func_020654cc()) {
            func_02065ca8();
            p->unk_14 = 1;
        }
        if (p->unk_14 == 0) return;
        if (!Unk0bc1a8_IsSlotEmpty(25)) return;
        {
            Unk0f7188Request request;
            int i;
            for (i = 0; i < 2; i++) request.flags[i] = 0;
            for (i = 0; i < 16; i++) request.words[i].value = 0;
            request.words[0].value = 7;
            request.flags[0] |= 1;
            request.words[3].value = p->unk_08;
            request.flags[0] |= 8;
            Unk0bc1a8_Unk_0bc514(p, 1, &request);
        }
        break;
    }
}

/* Borrowed input prefix: the selector occupies bits 5..8 of the word at 0x24. */
typedef struct Unk0f7188Input {
    unsigned char pad_00[0x20];
    unsigned short unk_20;
    unsigned char unk_22, unk_23;
    u32 low : 5;
    u32 selector : 4;
    u32 high : 23;
} Unk0f7188Input;
void func_020e8ebc(unsigned short value);
void Unk0e8228_Unk_0e8f50(int value);
int Unk0e8228_IsField4One(void);
void func_020e8710(u32 handle, u32 value, const Unk0f7188Input *input);
void Unk0feba0_Unk_0febe8(int value);
int Unk0cb0d0_Unk_0cb274(const Unk0f7188Input *input);
void Unk0e8228_Unk_0e8db8(void);
void func_020e8a30(u32 handle, u32 value);

/* Dispatch the input selector to the original service sequence. Evidence:
 * 0x24 bit extraction, slot 30 requests and byte-0x23 comparison with 7. */
void func_020f7578(Unk0f7188Record *p, const Unk0f7188Input *input)
{
    func_020e8ebc(input->unk_20);
    Unk0e8228_Unk_0e8f50(0);
    switch (input->selector) {
    case 0:
        if (Unk0e8228_IsField4One()) {
            func_020f7e48(30, 1, p->unk_28);
            func_020f7d7c(p->unk_00, 30);
            func_020f7e48(p->unk_00, 0, 7);
        } else {
            func_020e8710(p->unk_00, p->unk_28, input);
            func_020f7e48(p->unk_00, 0, 7);
        }
        Unk0feba0_Unk_0febe8(0);
        break;
    case 1:
    case 6:
        Unk0e8228_Unk_0e8f50(1);
        func_020f7e48(30, 1, p->unk_28);
        func_020f7d7c(p->unk_00, 30);
        func_020f7e48(30, 2, input->selector);
        func_020f7e48(p->unk_00, 0, 7);
        Unk0feba0_Unk_0febe8(0);
        break;
    case 2:
        if (Unk0cb0d0_Unk_0cb274(input)) {
            Unk0e8228_Unk_0e8db8();
            func_020e8a30(p->unk_00, p->unk_28);
            func_020f7e48(p->unk_00, 0, 7);
        } else if (Unk0e8228_IsField4One()) {
            func_020e8710(p->unk_00, p->unk_28, input);
            func_020f7e48(p->unk_00, 0, 7);
        } else {
            func_020f7e48(30, 1, p->unk_28);
            func_020f7d7c(p->unk_00, 30);
            func_020f7e48(p->unk_00, 0, 7);
        }
        Unk0feba0_Unk_0febe8(0);
        break;
    case 3:
    case 5:
    case 8:
        if (input->selector == 5) Unk0e8228_Unk_0e8f50(1);
        else Unk0e8228_Unk_0e8f50(2);
        func_020e8710(p->unk_00, p->unk_28, input);
        func_020f7e48(p->unk_00, 0, 7);
        Unk0feba0_Unk_0febe8(0);
        break;
    case 4:
        func_020e8710(p->unk_00, p->unk_28, input);
        func_020f7e48(p->unk_00, 0, 7);
        Unk0feba0_Unk_0febe8(0);
        break;
    case 7:
        if (input->unk_23 == 7) {
            if (Unk0cb0d0_Unk_0cb274(input)) Unk0e8228_Unk_0e8db8();
            func_020e8710(p->unk_00, p->unk_28, input);
            func_020f7e48(p->unk_00, 0, 7);
        } else {
            func_020e8a30(p->unk_00, p->unk_28);
            func_020f7e48(p->unk_00, 0, 7);
        }
        Unk0feba0_Unk_0febe8(0);
        break;
    }
}

/* Missing request values default to zero; presence is distinct from value. */
static inline u32 Unk0f7188_Value(const Unk0f7188Request *request, int index)
{
    u32 value = 0;
    if (request != 0) {
        Unk0f7188Word supplied;
        if (Unk0f7188_Read(request, index, &supplied)) value = supplied.value;
    }
    return value;
}
/* Preserve the default when the requested record is absent. */
static inline void Unk0f7188_ReadValue(const Unk0f7188Request *request, int index, u32 *value)
{
    if (request != 0) {
        Unk0f7188Word supplied;
        if (Unk0f7188_Read(request, index, &supplied)) *value = supplied.value;
    }
}
void Unk0bc1a8_Unk_0bc504(Unk0f7188Record *p, u32 value);

/* Handle kinds 1..4, retaining absent fields and notifying borrowed callbacks.
 * ARM request masks identify words 0, 2, 6 and 7; field offsets establish
 * the state transitions without supporting a gameplay-specific name. */
void func_020f7248(Unk0f7188Record *p, const Unk0f7188Event *event)
{
    const Unk0f7188Request *request = &event->request;
    switch (event->kind) {
    case 0: break;
    case 3:
        if (p->unk_10 < p->unk_1c) {
            p->unk_14 = p->unk_20;
            p->unk_0c = 9;
            p->unk_08 = 0;
        } else {
            p->unk_08 = 9;
        }
        if (request != 0) {
            u32 value = Unk0f7188_Value(request, 0);
            if (value != 65535) p->unk_04 = value;
        }
        if (p->unk_34 != 0) p->unk_34(p);
        break;
    case 2:
        switch (Unk0f7188_Value(request, 2)) {
        case 0:
            p->unk_14 = p->unk_24;
            p->unk_0c = 1;
            break;
        case 3: break;
        }
        if (p->unk_38 != 0) p->unk_38(p);
        break;
    case 1:
        Unk0bc1a8_Unk_0bc504(p, 0);
        break;
    case 4:
        {
            u32 first, second;
            if (p->unk_0c == 11) return;
            first = 0;
            second = 0;
            Unk0f7188_ReadValue(request, 6, &first);
            Unk0f7188_ReadValue(request, 7, &second);
            switch (first) {
            case 0:
                switch (second) {
                case 6:
                    if (p->unk_04 != 65535) func_020f7e48(p->unk_04, 0, second);
                    /* Fall through: selector 6 also performs selector 0's transition. */
                case 0:
                    func_020f7de4(p->unk_00, 2);
                    p->unk_0c = 1;
                    p->unk_14 = p->unk_24;
                    break;
                case 3:
                    p->unk_0c = 11;
                    p->unk_14 = p->unk_24;
                    break;
                case 7:
                    if (p->unk_04 != 65535) func_020f7e48(p->unk_04, 0, second);
                    /* Fall through: selector 7 also performs selector 1's transition. */
                case 1:
                    func_020f7de4(p->unk_00, 0);
                    p->unk_10 = p->unk_18;
                    break;
                case 8:
                    if (p->unk_04 != 65535) func_020f7e48(p->unk_04, 0, second);
                    /* Fall through: selector 8 also performs selector 2's transition. */
                case 2:
                    func_020f7de4(p->unk_00, 2);
                    p->unk_0c = 2;
                    p->unk_14 = p->unk_24;
                    break;
                case 5:
                    if (p->unk_04 != 65535) func_020f7e48(p->unk_04, 0, second);
                    /* Fall through: selector 5 also performs selector 4's transition. */
                case 4:
                    if (p->unk_08 == 1) p->unk_08 = 3;
                    p->unk_0c = p->unk_08;
                    p->unk_14 = p->unk_20;
                    break;
                }
                break;
            case 1:
                p->unk_28 = second;
                break;
            }
            if (p->unk_3c != 0) p->unk_3c(p, first, second);
        }
        break;
    }
}
