#ifndef GAME_UNIT_020BAC80_H
#define GAME_UNIT_020BAC80_H

/* Borrowed state prefix; signed bytes and word offsets follow 020bac80/020bad40. */
typedef struct Unk0bac80State {
    unsigned char pad_0000[0x7440];
    unsigned int unk_7440;
    unsigned char pad_7444[0x3d];
    signed char unk_7481;
    signed char unk_7482;
    signed char unk_7483;
} Unk0bac80State;

/* Borrowed work prefix; fields preserve the word and halfword load widths. */
typedef struct Unk0bac80Area {
    unsigned char pad_0000[0x358];
    unsigned int unk_0358;
    unsigned short unk_035c;
} Unk0bac80Area;

/* Borrowed entry prefix; handle bits 16..23 select eligibility. */
typedef struct Unk0bac80Entry {
    unsigned int handle;
} Unk0bac80Entry;

/* Borrowed table prefix; the original loop visits exactly ten pointer slots. */
typedef struct Unk0bac80Table {
    unsigned char pad_0000[0x64];
    Unk0bac80Entry *entries[10]; /* Ten slots: original loop bound. */
} Unk0bac80Table;

#endif
