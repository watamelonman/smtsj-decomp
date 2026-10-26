#ifndef GAME_UNIT_020CB32C_H
#define GAME_UNIT_020CB32C_H

/* Borrowed work offsets evidenced by 020ccb28 and 020cbc50; providers own
 * the list at +0x20 and the nested display object at +0x94. */
typedef struct Unk0cb32cFullWork {
    signed int state;
    unsigned int field_004, field_008, field_00c;
    unsigned int handles[4];
    unsigned char list[0x74];
    struct Unk0cb32cDisplay *display;
    unsigned char reserved_098[0x8c];
    unsigned int field_124;
} Unk0cb32cFullWork;
/* Only the two provider fields loaded by 020cb8f8/020cb98c are exposed. */
typedef struct Unk0cb32cDisplay {
    unsigned char reserved_000[0xe0];
    unsigned int field_0e0, field_0e4;
} Unk0cb32cDisplay;

/* The global cell borrows the active work; teardown clears it. */
extern Unk0cb32cFullWork *data_02176bc4;
/* Return the unsigned selector consumed by the original jump table. */
unsigned int Unk02cad4_GetUnk00(void);
/* Accept the original 32-bit provider selector (37 in these callers). */
void Unk044394_Unk_044534(unsigned int value);
/* Borrow the list at work +0x20; return its signed iteration bound. */
int Unk0de678_CountLeading(const void *list);
/* Release one nonzero list handle before its caller clears the slot. */
void func_020ffebc(unsigned int handle);
/* Complete provider cleanup before the global work cell is detached. */
void Unk0de678_Unk_0dea60(void);
/* Begin the first drawing pass with the original byte-range value. */
void func_02057ddc(unsigned int value);
/* End the first pass before the second provider submission. */
void func_02057df8(void);
/* Submit a borrowed display handle and signed coordinates; final values
 * preserve the original two stack arguments without narrowing. */
void func_02060b60(unsigned int mode, unsigned int handle, signed int x, signed int y, unsigned int zero, unsigned int value);
/* Borrow the work word at +4 and return the dispatch result. */
int func_020cb5b4(unsigned int value, unsigned int *field);
/* Update borrowed work before the paired 0cca80 call on result 2. */
void func_020ccba0(Unk0cb32cFullWork *work);
/* Release work-owned handles while preserving the borrowed work allocation. */
void func_020ccb28(Unk0cb32cFullWork *work);

/* Partial borrowed work view: original 020cccb4 reads only the word at +0x124. */
typedef struct Unk0cb32cWork {
    unsigned char reserved_000[0x124];
    unsigned int field_124;
} Unk0cb32cWork;

#endif
