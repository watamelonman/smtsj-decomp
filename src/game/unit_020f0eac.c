#include "types.h"

/* Borrowed context view: only the three observed subobjects are exposed. */
typedef struct Unk0f0eacContext {
    u8 padding[0x40];
    void *field40;
    u8 padding44[8];
    void *field4c;
    u8 field50[1];
} Unk0f0eacContext;

/* Comparison records have unsigned keys at offsets 0, 2 and 4. */
typedef struct Unk0f0eacRecord {
    u16 key0;
    u16 key2;
    u8 key4;
} Unk0f0eacRecord;

extern Unk0f0eacContext *data_02176dfc;
void Unk0e8228_Unk_0e8c80(void);
void func_02044ec4(void);
int Unk0e8228_Unk_0e82ac(void);
void Unk0f8448_Init(void *object, int value);
int Unk0e8228_IsField4One(void);
void Unk0e8228_Unk_0e8d18(int value);
void func_020e86a0(void);
void func_020f7e48(void *object, int first, int second);
int Unk0f8448_GetUnkField10(void *object);
void Unk0e8228_Unk_0e8d90(void *object, int value);
void func_020f7d7c(void *object, int value);
void func_020ea3cc(int value);
int Unk0e651c_Unk_0e666c(int value);
void *Unk0986ac_Unk_098978(int id);
int Unk0986ac_Thunk_02098714(void *object);

/* Run the context setup sequence, initializing +0x50 only when the query is zero. */
void Unk0f0eac_Unk_0f0eac(void)
{
    Unk0f0eacContext *context = data_02176dfc;
    Unk0e8228_Unk_0e8c80();
    func_02044ec4();
    if (!Unk0e8228_Unk_0e82ac())
        Unk0f8448_Init(context->field50, 0);
    if (Unk0e8228_IsField4One()) {
        Unk0e8228_Unk_0e8d18(1);
        func_020e86a0();
    }
    func_020f7e48(context->field40, 0, 2);
}

/* Forward the supplied object's field-10 query to the context's +0x4c object. */
void Unk0f0eac_Unk_0f0f08(void *object)
{
    Unk0f0eacContext *context = data_02176dfc;
    int value = Unk0f8448_GetUnkField10(object);
    Unk0e8228_Unk_0e8d90(context->field4c, value);
}

/* Issue the observed (0,7) and 34 operations on the context's +0x40 object. */
void Unk0f0eac_Unk_0f0f2c(void)
{
    Unk0f0eacContext *context = data_02176dfc;
    func_020f7e48(context->field40, 0, 7);
    func_020f7d7c(context->field40, 34);
}

/* Dispatch field-10 values 0..4; value 3 additionally queries identifier 0x703. */
void func_020f0f5c(void *object)
{
    switch (Unk0f8448_GetUnkField10(object)) {
    case 0: func_020ea3cc(4); break;
    case 1: func_020ea3cc(5); break;
    case 2: func_020ea3cc(6); break;
    case 3:
        if (!Unk0e651c_Unk_0e666c(0x703))
            func_020ea3cc(13);
        else
            func_020ea3cc(7);
        break;
    case 4: func_020ea3cc(8); break;
    }
}

/* Compare unsigned byte +4 first, breaking ties with unsigned halfword +0. */
int Unk0f0eac_Compare(const Unk0f0eacRecord *first, const Unk0f0eacRecord *second)
{
    int result = first->key4 - second->key4;
    if (!result)
        result = first->key0 - second->key0;
    return result;
}

/* Compare unsigned halfword +2 first, breaking ties with unsigned halfword +0. */
int Unk0f0eac_Unk_0f1000(const Unk0f0eacRecord *first, const Unk0f0eacRecord *second)
{
    int result = first->key2 - second->key2;
    if (!result)
        result = first->key0 - second->key0;
    return result;
}

/* Prioritize records with a nonzero id-query result, then compare +4 and +0. */
int func_020f1020(const Unk0f0eacRecord *first, const Unk0f0eacRecord *second)
{
    int result = 0;
    void *a = Unk0986ac_Unk_098978(first->key0);
    void *b = Unk0986ac_Unk_098978(second->key0);
    int left = Unk0986ac_Thunk_02098714(a);
    int right = Unk0986ac_Thunk_02098714(b);
    if (left && !right) result = -1;
    if (!left && right) result = 1;
    if (!result) result = first->key4 - second->key4;
    if (!result) result = first->key0 - second->key0;
    return result;
}

/* Prioritize nonzero id-query results, then compare +2 and finally +0. */
int func_020f10a4(const Unk0f0eacRecord *first, const Unk0f0eacRecord *second)
{
    int result = 0;
    void *a = Unk0986ac_Unk_098978(first->key0);
    void *b = Unk0986ac_Unk_098978(second->key0);
    int left = Unk0986ac_Thunk_02098714(a);
    int right = Unk0986ac_Thunk_02098714(b);
    if (left && !right) result = -1;
    if (!left && right) result = 1;
    if (!result) {
        result = first->key2 - second->key2;
        if (!result) result = first->key0 - second->key0;
    }
    return result;
}
