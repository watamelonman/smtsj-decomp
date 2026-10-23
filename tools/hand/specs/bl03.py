TU = 'src/BattleShowingTask.c'
CODE_D050 = '''/* Event handler for the battle-showing screen (ARM 0x0211D050): *event 3 finishes the
 * current record (states 7 and 9 go through 0x0211C5D0 / 0x0211C610); event 1 hands a
 * cleared message to Unk0bc1a8_Unk_0bc514 with mode 1. Other events are ignored. */
void func_0211d050(BattleShowingTaskWork *work, u32 *event)
{
    BattleShowingMessage message;

    switch (*event) {
    case 0:
        break;
    case 3:
        switch (work->unk_0000) {
        case 7:
            func_02065bc0();
            func_02065628(1);
            BattleShowingTask_Unk_11c5d0(work);
            break;
        case 9:
            func_02065bc0();
            func_02065628(1);
            BattleShowingTask_Unk_11c610(work);
            break;
        }
        break;
    case 1:
        BattleShowing_ClearMessage(&message);
        Unk0bc1a8_Unk_0bc514(work, 1, &message);
        break;
    case 2:
        break;
    case 4:
        break;
    }
}
'''
PRE = 'void Unk0bc1a8_Unk_0bc514(BattleShowingTaskWork *work, u32 mode, BattleShowingMessage *message);'
CODE_C24C = '''/* Prepare the current record's display, then post message kind 3 (ARM 0x0211C24C). The
 * record's +0x10 byte pairs go to CampStatus_Copy176. A negative record id loads the bust-up
 * texture data_02151cc4 ("Data/Tex/Camp/Status/bust_up/st_bu_pc001.gfnt"; the source file name
 * data_02151cf4 and line 162 go to func_0205ba28) and sets message word 1 to 14; otherwise the
 * loader is started with the record's id and the message gets word 1 = 15 and word 7 = the
 * record id. */
void func_0211c24c(BattleShowingTaskWork *object)
{
    BattleShowingScreenWork *work = (BattleShowingScreenWork *)object;
    BattleShowingRecord *record = (BattleShowingRecord *)BattleShowingTask_Unk_11c230(object);
    BattleShowingMessage message;
    /* The original also writes each message value to its own stack word. */
    volatile u32 word1;
    volatile u32 word2;
    volatile u32 word3;

    BattleShowing_ClearMessage(&message);
    CampStatus_Copy176(&record->pad0a[6]);
    if (record->unk00 < 0) {
        work->allocation = func_02051610(data_02151cc4);
        work->sub = func_0205ba28(((BattleShowingTexFile *)work->allocation)->desc, data_02151cf4, 162);
        func_0205b444(work->sub, work->allocation);
        word1 = 14;
        message.words[1] = 14;
        message.flags[0] |= 2;
    } else {
        func_020a1b68(work->loader, record->id, 0);
        Unk0a163c_Unk_0a21f8(work->loader);
        message.words[1] = 15;
        word2 = 15;
        message.flags[0] |= 2;
        word3 = record->unk00;
        message.words[7] = record->unk00;
        message.flags[0] |= 0x80;
    }
    func_020bcbc4(3, &message);
}
'''
PRE_C24C = '''/* Bust-up texture file returned by func_02051610; its draw descriptor starts at +0x0c. */
typedef struct BattleShowingTexFile {
    u8 pad_0000[0xc];
    u8 desc[0x10];
} BattleShowingTexFile;
extern char data_02151cc4[];
extern char data_02151cf4[];
void CampStatus_Copy176(const void *pairs);
u32 *func_02051610(const char *path);
BattleShowingTaskSub *func_0205ba28(void *desc, const char *file, u32 line);
void func_0205b444(BattleShowingTaskSub *slot, u32 *texture);
void func_020a1b68(void *loader, u32 id, u32 mode);
void Unk0a163c_Unk_0a21f8(void *loader);'''
SRC = open('~/sj-decomp/' + TU).read()
_a = SRC.index('/* Message/option block passed to the 020BCxxx UI helpers')
_b = SRC.index('int func_020654cc(void);\n', _a)
MSG = SRC[_a:_b]
FIX = [(MSG, ''),
       ('/* Record fields read by the resource dispatchers at 0x0211c4e0..0x0211c670. */\n',
        MSG + '/* Record fields read by the resource dispatchers at 0x0211c4e0..0x0211c670. */\n')]
SPECS = [(TU, [('func_0211c24c', CODE_C24C), ('func_0211d050', CODE_D050)], PRE + '\n' + PRE_C24C, FIX)]
