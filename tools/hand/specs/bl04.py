TU = 'src/BattleShowingTask.c'
CODE = '''/* Advance the record-screen transition from state *work (ARM 0x0211C6AC). Record +0x1a bit 1
 * selects the 0x0211C4E0 path in state 4; state 5 posts message 3 with word 1 = 16 and the
 * record's selection, state 7 posts word 1 = 17 and then either starts the 0x0205264C fade
 * (arg != 0) or moves to state 10; states 9/10 refresh resource +0x20 and, with +0x1a bit 2,
 * store func_020e5e6c's value at +0x24. */
void func_0211c6ac(BattleShowingTaskWork *work, u32 arg)
{
    BattleShowingRecord *record = (BattleShowingRecord *)BattleShowingTask_Unk_11c230(work);
    BattleShowingMessage message1;
    BattleShowingMessage message2;
    /* The original also writes each message value to its own stack word. */
    volatile u32 word1;
    volatile u32 word2;
    volatile u32 word3;

    switch (work->unk_0000) {
    case 4:
        if (record->unk1a_1) {
            func_0211c4e0(work);
            work->unk_0000 = 5;
            return;
        }
        work->unk_0000 = 10;
        func_0211c6ac(work, 0);
        return;
    case 5:
        func_02065c30();
        BattleShowing_ClearMessage(&message1);
        message1.words[1] = 16;
        message1.flags[0] |= 2;
        word1 = 16;
        word2 = record->selection;
        message1.words[7] = record->selection;
        message1.flags[0] |= 0x80;
        func_020bcbc4(3, &message1);
        work->unk_0000 = 6;
        return;
    case 6:
        BattleShowingTask_Unk_11c5d0(work);
        work->unk_0000 = 7;
        return;
    case 7:
        BattleShowing_ClearMessage(&message2);
        word3 = 17;
        message2.words[1] = 17;
        message2.flags[0] |= 2;
        func_020bcbc4(3, &message2);
        if (arg != 0) {
            work->unk_0000 = 8;
            func_0205264c(2, 4, 31, 1, 2);
            func_02065c80();
            return;
        }
        work->unk_0000 = 10;
        BattleShowingTask_Unk_11c670(work);
        return;
    case 8:
        BattleShowingTask_Unk_11c610(work);
        work->unk_0000 = 9;
        return;
    case 9:
    case 10:
        if (record->unk20 != 0) {
            if (record->unk1a_2) {
                record->unk24 = func_020e5e6c(Unk02e000_GetAreaRecord(record->unk00));
                Unk09974c_Unk_099abc(record->unk20, record->unk24);
            }
            func_0211c548(work);
            work->unk_0000 = 11;
            return;
        }
        work->unk_0000 = 13;
        return;
    case 11:
        func_02065628(1);
        func_020659a4(record->unk20, 1);
        if (record->unk1a_2) {
            Unk02ee5c_SetRecordFlag0b(Unk02e000_GetAreaRecord(record->unk00)->unk_0036, 1);
        }
        work->unk_0000 = 12;
        return;
    case 12:
        work->unk_0000 = 13;
        break;
    }
}
'''
PRE = '''void func_0205264c(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_02065c80(void);
u32 func_020e5e6c(BattleShowingAreaRecord *area);
void Unk09974c_Unk_099abc(u32 resource, u16 value);
void func_020659a4(u32 resource, u32 mode);
void Unk02ee5c_SetRecordFlag0b(u16 id, u32 value);'''
FIX = [('''    u8 flags;                  /* +0x1A: dispatch flags */''', '''    u8 unk1a_0 : 1;            /* +0x1A: dispatch flags; bits 1 and 2 are tested by func_0211c6ac */
    u8 unk1a_1 : 1;
    u8 unk1a_2 : 1;
    u8 pad1a : 5;'''),
       ('''    u8 pad20[4];''', '''    u32 unk20;                  /* 0x20: resource refreshed by func_0211c6ac states 9..11 */'''),
       ('''    u8 pad_0036[2];''', '''    u16 unk_0036;               /* 0x36: record id passed to Unk02ee5c_SetRecordFlag0b */''')]
SPECS = [(TU, [('func_0211c6ac', CODE)], PRE, FIX)]
