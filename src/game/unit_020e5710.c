typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
/* Borrowed six-byte table entry; only bits 4..5 are interpreted here. */
typedef struct {
    u16 id;
    u8 group, rank;
    u8 low:4, eligible:2, selectable:2;
    u8 pad;
} Entry;
/* Borrowed record view: the low seven bits at +0x24 supply a probability term. */
typedef struct {
    u8 pad[36];
    u32 chance:7;
    u32 reserved:25;
} Record;
/* Borrowed caller work: six IDs at +0x28 and a record ID at +0x36. */
typedef struct {
    u8 pad[40];
    u16 ids[6];
    u16 pad34, record;
} Work;
extern Entry *func_020e6874(u16 id);
extern u8 *func_020e679c(u8 rank);
extern int Unk03e43c_Unk_03fa28(void);
extern void *Unk0986ac_Unk_098978(int id);
extern int Unk0986ac_Thunk_02098714(void *entry);
extern u32 func_02050074(u32 low, u32 high);
extern int Unk0e651c_Unk_0e666c(u32 index);
extern Record *func_020a1428(u16 id);
extern int Unk02e000_GetRecordUnk1c(u16 id);
extern void func_02008848(void *dest, int value, u32 size);

/* Test bits 4..5 in six referenced records, as shown by the +4 byte loads.
 * ids must contain six valid table IDs; zero is also looked up. */
int func_020e5710(const u16 *ids)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (func_020e6874(ids[i])->eligible) return 1;
    }
    return 0;
}

/* Select a byte-valued adjustment from five cumulative table weights.
 * The table lookup and flag 131 establish the three weight sets; additions wrap. */
u8 func_020e5750(u8 rank)
{
    u8 *table = func_020e679c(rank);
    int mode = Unk03e43c_Unk_03fa28();
    int flag = Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(131));
    u8 *weights = table + 6;
    u8 sum, i;
    u32 roll;
    if (mode == 0 || flag != 0) weights = table + 1;
    else if (mode == 8) weights = table + 11;
    sum = 0;
    roll = func_02050074(1, 99);
    for (i = 0; i < 5; i++) {
        sum += weights[i];
        if (roll < sum) break;
    }
    switch (i) {
    case 0: if (rank >= 2) rank -= 2; break;
    case 1: if (rank >= 1) rank -= 1; break;
    case 2: break;
    case 3: rank += 1; break;
    case 4: rank += 2; break;
    }
    return rank;
}

/* Test the record-derived probability up to attempts times; nonpositive counts fail.
 * Evidence: work +0x36 lookup, record +0x24 low seven bits, and flags 188/133.
 * work is borrowed and must contain valid lookup IDs. */
int func_020e582c(const Work *work, int attempts)
{
    Record *record;
    int value;
    int eligible, boost, force, i;
    u32 chance;
    if (attempts <= 0) return 0;
    if (!Unk0e651c_Unk_0e666c(0x706)) return 0;
    record = func_020a1428(work->record);
    value = Unk02e000_GetRecordUnk1c(work->record);
    eligible = func_020e5710(work->ids);
    boost = Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(188));
    force = Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(133));
    if (eligible) {
        for (i = 0; i < attempts; i++) {
            chance = value / 25 + record->chance;
            if (force) return 1;
            if (boost) chance = (chance * 150) / 100;
            if (func_02050074(1, 99) < chance) return 1;
        }
    }
    return 0;
}

/* Return a slot in the caller's six IDs whose record has bits 4..5 set, or -1.
 * Zero IDs are excluded; multiple slots use the original random bounds (1, count-1).
 * ids is borrowed and must contain six halfwords. */
int func_020e5924(const u16 *ids)
{
    u8 count = 0;
    s8 i;
    s8 slots[6];
    func_02008848(slots, count, 6);
    for (i = 0; i < 6; i++) {
        if (ids[i] != 0) {
            if (func_020e6874(ids[i])->eligible) {
                slots[count] = i;
                count++;
            }
        }
    }
    if (count == 0) return -1;
    if (count <= 1) return slots[0];
    return slots[func_02050074(1, count - 1)];
}

