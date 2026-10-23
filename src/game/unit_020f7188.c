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
