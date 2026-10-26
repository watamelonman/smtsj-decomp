/* Partial CRI record layout, established by the loads/stores at 0208081c..02080904. */
/** A caller-owned 0x3c-byte record; unknown words retain their observed offsets. */
typedef struct Unk0208073cRecord {
    int active;
    int unk04;
    int unk08;
    int state;
    int unk10;
    int request;
    int arg0;
    int arg1;
    int arg2;
    int arg3;
    short pairs[4];
    short derived[2];
    short values[3];
    short unk3a;
} Unk0208073cRecord;

/* The original call at 020808c4 uses the standard destination/value/byte-count ABI. */
extern void *func_020119c0(void *destination, int value, unsigned int bytes);
/* 02080828 and 0208082c pass the two adjacent signed halfword outputs. */
extern void func_0207ae34(int first, int second, short *out0, short *out1);

/** Forward the two scalar inputs to the helper; record must provide outputs at +0x30/+0x32. */
void func_0208081c(Unk0208073cRecord *record, int second, int first)
{
    func_0207ae34(first, second, &record->derived[0], &record->derived[1]);
}

/** Interleave two signed halfword pairs, preserving the store order seen at 02080838. */
void func_02080838(Unk0208073cRecord *record, const short *first, const short *second)
{
    record->pairs[0] = first[0];
    record->pairs[1] = second[0];
    record->pairs[2] = first[1];
    record->pairs[3] = second[1];
}

/** Extract the interleaved pairs; outputs must each hold two signed halfwords. */
void func_0208085c(Unk0208073cRecord *record, short *first, short *second)
{
    first[0] = record->pairs[0];
    second[0] = record->pairs[1];
    first[1] = record->pairs[2];
    second[1] = record->pairs[3];
}

/** Store the three halfwords at +0x34/+0x36/+0x38, as observed at 02080880. */
void func_02080880(Unk0208073cRecord *record, short first, short second, short third)
{
    record->values[0] = first;
    record->values[1] = second;
    record->values[2] = third;
}

/** Copy the three signed values to caller-provided halfword outputs. */
void func_02080890(Unk0208073cRecord *record, short *first, short *second, short *third)
{
    *first = record->values[0];
    *second = record->values[1];
    *third = record->values[2];
}

/** Clear a non-null 0x3c-byte record; 020808c0 clears the active word before the fill call. */
void func_020808ac(Unk0208073cRecord *record)
{
    if (record == 0) return;
    record->active = 0;
    func_020119c0(record, 0, sizeof(*record));
}

/** Return the state word at +0x0c; the record must be non-null (020808cc). */
int func_020808cc(Unk0208073cRecord *record)
{
    return record->state;
}

/** Set request 1 and its four words only when state is zero; return whether accepted. */
int func_020808d4(Unk0208073cRecord *record, int arg0, int arg1, int arg2, int arg3)
{
    if (record->state != 0) return 0;
    record->request = 1;
    record->arg0 = arg0;
    record->arg1 = arg1;
    record->arg2 = arg2;
    record->arg3 = arg3;
    return 1;
}
