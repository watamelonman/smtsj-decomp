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
typedef struct Unk0f7188Descriptor {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*unk_0c)(void);
    void (*unk_10)(void);
    u32 unk_14;
    void (*unk_18)(void);
    void (*unk_1c)(void);
    void (*unk_20)(void);
} Unk0f7188Descriptor;
void func_020f7888(void);
void func_020f7ae8(void);
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
