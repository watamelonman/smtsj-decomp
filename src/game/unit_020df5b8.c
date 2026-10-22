typedef unsigned int u32;
typedef signed short s16;
typedef unsigned char u8;

/* The lookup stride and halfword loads establish this 42-byte record layout. */
typedef struct Entry42 {
    s16 condition;
    s16 bit;
    s16 unk04;
    u8 payload[24];
    s16 limits[6];
} Entry42;

/* Six records are initialized together; sizes are bytes and blocks are 128 bytes. */
typedef struct Record {
    u8 *data;
    u32 size;
    u32 blocks;
    void (*transfer)(void *, u32, u32);
    void (*finish)(void);
    u32 flag;
} Record;
extern Record data_02176be8[];
extern void func_ov000_02176ea0(void);
extern void func_ov001_0217797c(void);
extern u32 func_020445d0(u32 kind, u32 index);
extern u32 func_0204fe18(u32 handle);
extern Entry42 *func_0204fde0(u32 handle);
extern int Unk0e651c_Unk_0e666c(int condition);
extern int func_0209993c(int index);
extern void Unk0e651c_SetBitChecked(int bit, int value);
extern void Unk0de678_Unk_0dec94(void *payload);
extern u32 Unk108bc8_Unk_108c60(void);
extern void func_02008904(void *destination, u32 value, u32 size);
extern u8 *Unk02e000_Unk_02e8f0(void);
extern u8 *Unk02e000_Unk_02e170(void);
extern u32 Unk108bc8_GetSize(void);

/* Evidence: the resource result is indexed using a 42-byte stride. */
Entry42 *Unk0df5b8_GetEntry42(int index)
{
    u32 handle = func_020445d0(32, 0);
    func_0204fe18(handle);
    return func_0204fde0(handle) + index;
}

/* Check the first entry's condition and three limits before setting its bit. */
int func_020df5e8(void)
{
    Entry42 *entry = Unk0df5b8_GetEntry42(0);
    int found;
    int i;
    if (!Unk0e651c_Unk_0e666c(entry->condition)) return 0;
    found = 0;
    for (i = 0; i < 6; i += 2) {
        if (func_0209993c(entry->limits[i]) >= entry->limits[i + 1]) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    Unk0e651c_SetBitChecked(entry->bit, 1);
    Unk0de678_Unk_0dec94(entry->payload);
    return 1;
}

/* Empty callback: the original consists solely of a return instruction. */
void Unk0df5b8_Nop_0df668(void) {}

/* Tail-call the fixed callback address recorded in the original literal pool. */
void func_020df66c(void) { func_ov000_02176ea0(); }

/* Tail-call the second fixed callback address from the original literal pool. */
void func_020df678(void) { func_ov001_0217797c(); }

/* Forward the allocated buffer while preserving destination and byte size. */
void Unk0df5b8_Unk_0df684(void *destination, u32 value, u32 size)
{
    func_02008904(destination, Unk108bc8_Unk_108c60(), size);
}

/* Initialize six descriptors; the instruction stream establishes each case's sizes. */
Record *func_020df6a8(void)
{
    int i;
    Record *record = data_02176be8;
    for (i = 0; i < 6; i++, record++) {
        record->transfer = 0;
        record->finish = 0;
        record->flag = 0;
        switch (i) {
        case 0:
            record->data = Unk02e000_Unk_02e8f0();
            record->size = 8;
            record->blocks = (record->size + 127) >> 7;
            record->flag = 1;
            break;
        case 3:
            record->data = Unk02e000_Unk_02e8f0();
            record->size = 72;
            record->blocks = (record->size + 127) >> 7;
            record->flag = 0;
            break;
        case 1:
        case 2:
            if (i == 1) record->data = Unk02e000_Unk_02e170();
            else record->data = Unk02e000_Unk_02e170() + 72;
            record->size = 72;
            record->blocks = (record->size + 127) >> 7;
            record->flag = 0;
            break;
        case 4:
        case 5:
            record->data = Unk02e000_Unk_02e170();
            record->size = Unk108bc8_GetSize();
            record->blocks = (record->size + 127) >> 7;
            record->transfer = Unk0df5b8_Unk_0df684;
            record->finish = Unk0df5b8_Nop_0df668;
            break;
        }
    }
    return data_02176be8;
}
