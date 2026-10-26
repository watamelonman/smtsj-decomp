typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/* Fixed 56-byte command storage, as consumed by func_0204f098. */
typedef struct Command { u32 words[14]; } Command;
/* Sixteen-byte records in data_02143494; field meanings remain unknown. */
typedef struct Record {
    u16 key;
    u8 byte2;
    u8 byte3;
    u32 word4;
    u32 word8;
    u8 byte12;
    u8 reserved[3];
} Record;
extern Record data_02143494[50];
extern void func_0204f0a4(Command *command, u32 context, u32 second, u32 first);
extern void func_0204f098(Command *command);

/* Builds command 28; evidence: initializer and command dispatch at 0204f0a4/0204f098. */
void func_0204f7d4(u32 first, u32 second)
{
    Command command;
    func_0204f0a4(&command, second, second, first);
    command.words[0] = 28;
    func_0204f098(&command);
}

/* Dispatches command 26 with payload words at offsets 20 and 24 (original stores). */
void func_0204f804(u32 first, u32 second, u32 value5, u32 value6)
{
    Command command;
    func_0204f0a4(&command, second, second, first);
    command.words[0] = 26;
    command.words[5] = value5;
    command.words[6] = value6;
    func_0204f098(&command);
}

/* Dispatches command 27 with the same payload layout as command 26. */
void func_0204f848(u32 first, u32 second, u32 value5, u32 value6)
{
    Command command;
    func_0204f0a4(&command, second, second, first);
    command.words[0] = 27;
    command.words[5] = value5;
    command.words[6] = value6;
    func_0204f098(&command);
}

/* Returns the first matching key in the 50-entry table, or null (original loop bound). */
Record *func_0204f88c(u32 key)
{
    u32 i;
    Record *record = data_02143494;
    for (i = 0; i < 50; i++, record++) {
        if (record->key == key) return record;
    }
    return 0;
}

/* Retrieves byte 2 of a keyed record; missing keys return zero. */
u32 func_0204f8c0(u32 key)
{
    Record *record = func_0204f88c(key);
    return record == 0 ? 0 : record->byte2;
}

/* Retrieves byte 12 of a keyed record; missing keys return zero. */
u32 func_0204f8d8(u32 key)
{
    Record *record = func_0204f88c(key);
    return record == 0 ? 0 : record->byte12;
}

/* A zero selector yields one; otherwise retrieves word 8, or zero for missing keys. */
u32 func_0204f8f0(u32 key, u32 selector)
{
    Record *record;
    if (selector == 0) return 1;
    record = func_0204f88c(key);
    return record == 0 ? 0 : record->word8;
}

