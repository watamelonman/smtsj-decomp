/* Battle event resource loading and record selection. */
#include "types.h"

/* On-disk event records have a four-byte condition followed by a script name. */
typedef struct Unk0f7eb4Record {
    u8 kind;
    u8 condition;
    u16 value;
    char name[32];
} Unk0f7eb4Record;

/* Offsets follow accesses in the five original ARM functions. */
typedef struct Unk0f7eb4Work {
    u8  pad_0000[0x44];
    u32 unk_0044;               /* +0x44  set to 1 on load */
    u32 unk_0048;
    u32 unk_004c;
    u32 unk_0050;
    u8  unk_0054;
    u8  pad_0055[0x1f];
    u32 messageData;                 /* +0x74  loaded Data/Battle/Event/%s.mbb */
    u32 tableData;                /* +0x78  loaded ProTable%s.tbb */
    Unk0f7eb4Record *unk_007c;
    s32 unk_0080;
    u32 unk_0084;
    u32 unk_0088;
} Unk0f7eb4Work;




/* Reset selection state; 0xffffffff denotes no selected script. */
void Unk0f7eb4_Unk_0f8078(Unk0f7eb4Work *arg0){
  arg0->unk_0048 = 0;
  arg0->unk_004c = 0;
  arg0->unk_0050 = 0;
  arg0->unk_0084 = 0xffffffff;
  arg0->unk_0054 = 0;
  return;
}


/* Translate the input code; unsupported codes share the fallback value 18. */
u32 Unk0f7eb4_Unk_0f7eb4(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 7;
  case 1:
    return 8;
  case 2:
    return 0;
  case 3:
    return 1;
  case 4:
    return 2;
  case 5:
    return 3;
  case 6:
    return 5;
  case 7:
    return 6;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    return 4;
  case 0x13:
    return 0xf;
  }
  return 0x12;
}

extern char data_02150e64[];
extern char data_02150e7c[];
extern char data_02150e98[];
extern char data_02150ea4[];
int func_02013c3c(char *destination, const char *format, ...);
void func_0204ae84(Unk0f7eb4Work *w);
void func_0204aecc(Unk0f7eb4Work *w, const char *path, int mode);
void func_0204af70(Unk0f7eb4Work *w, Unk0f7eb4Work *context);
u32 func_02051610(const char *path);
int func_02015118(const char *text);
u32 func_0204fdac(u32 data, int index);
Unk0f7eb4Record *func_0204fde0(void);
s32 func_0204fe18(u32 message);
void func_0204af80(Unk0f7eb4Work *w);
void Unk039774_Unk_039b74(int mode);
void func_02053000(u32 data);

/* Load script, message and condition-table resources. Evidence: format strings
 * at 0x02150e64, 0x02150e7c and 0x02150ea4 name .bf, .mbb and ProTable.tbb.
 * name must include the prefix whose length is measured from "BtlEvent". */
void func_020f7f68(Unk0f7eb4Work *w, char *name, u32 arg2, u32 arg3)
{
    char path[64];
    int msg;

    w->unk_0044 = 1;
    func_02013c3c(path, data_02150e64, name);
    func_0204ae84(w);
    func_0204aecc(w, path, 3);
    func_0204af70(w, w);
    func_02013c3c(path, data_02150e7c, name);
    w->messageData = func_02051610(path);
    func_02013c3c(path, data_02150ea4, name + func_02015118(data_02150e98));
    w->tableData = func_02051610(path);
    msg = func_0204fdac(w->tableData, 0);
    w->unk_007c = func_0204fde0();
    w->unk_0080 = func_0204fe18(msg);
    Unk0f7eb4_Unk_0f8078(w);
}

/* Release the resources loaded above; the original Release symbol and paired
 * load/free calls support the name. An inactive work object owns no resources. */
void Unk0f7eb4_Release(Unk0f7eb4Work *w)
{
    if (w->unk_0044 == 0) {
        return;
    }
    func_0204af80(w);
    Unk039774_Unk_039b74(3);
    func_02053000(w->messageData);
    w->messageData = 0;
    func_02053000(w->tableData);
    w->tableData = 0;
}

/* Only the halfword at +0x1d8 is identified by this caller. */
typedef struct Unk0f7eb4Context {
    u8 pad[0x1d8];
    u16 value;
} Unk0f7eb4Context;

Unk0f7eb4Context *func_02044ec4(u32 key);
u32 func_0204b01c(Unk0f7eb4Work *w, const char *name);

/* Select the first eligible record and retain its script handle. The record
 * tags and context value lack evidence for more descriptive names. Returns a
 * boolean; an inactive object or exhausted scan returns zero. */
int func_020f8098(Unk0f7eb4Work *w, u32 kind, u32 key)
{
    Unk0f7eb4Record *record;
    int i;
    if (w->unk_0044 == 0) {
        return 0;
    }
    Unk0f7eb4_Unk_0f8078(w);
    record = w->unk_007c;
    for (i = 0; i < w->unk_0080; i++, record++) {
        if (record->kind == kind) {
            if (kind != 0) {
                Unk0f7eb4Context *context = func_02044ec4(key);
                switch (record->condition) {
                case 0:
                    break;
                case 1:
                    if (((key >> 16) & 0xff) != 2 || record->value != context->value)
                        continue;
                    break;
                case 2:
                    if (((key >> 16) & 0xff) != 1 || record->value != context->value)
                        continue;
                    break;
                case 3:
                    if (context->value != 0)
                        continue;
                    break;
                }
            }
            w->unk_0084 = func_0204b01c(w, record->name);
            if (w->unk_0084 != 0xffffffff) {
                w->unk_0088 = kind;
                return 1;
            }
        }
    }
    return 0;
}
