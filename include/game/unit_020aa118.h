#ifndef GAME_UNIT_020AA118_H
#define GAME_UNIT_020AA118_H

/* Borrowed prefix of the object returned by Unk044904_Get_data_0215ee98.
 * Request checks use the halfwords at +0x38/+0x3a and flags at +0x40;
 * the full object extends beyond this prefix and remains externally owned. */
typedef struct Unk0aa118Global {
    unsigned char pad_0000[0x38];
    unsigned short unk_0038;
    unsigned short unk_003a;
    unsigned char pad_003c[4];
    unsigned int unk_0040;
} Unk0aa118Global;

#endif
