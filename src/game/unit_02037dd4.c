#include "types.h"

/* Each state word is followed by the 0x78-byte request object it drives;
 * the pair is cleared as one 0x7c-byte block on completion. The original
 * relocations name the request symbols (data_0215dd34/data_0215ddb0)
 * directly, so a single struct extern (data_0215dd30+4) does not match and
 * the halves stay separate externs. */
#define UNK_REQUEST_BLOCK_SIZE 0x7c

/* Caller context; only the fields touched here are named. */
typedef struct {
    u8 pad_0000[0x2470];
    void *unk_2470;
    u8 pad_2474[0x30];
    u8 unk_24a4[0x30a4 - 0x24a4]; /* object of unknown size; extent guessed up to unk_30a4 */
    void *unk_30a4;
    void *unk_30a8;
    void *unk_30ac;
} Unk02037dd4Context;

extern int data_0215dd30;
extern u8 data_0215dd34[0x78];
extern int data_0215ddac;
extern u8 data_0215ddb0[0x78];
extern const char *data_02141f98[];
extern const char data_02141fdc[];
extern const char data_02141fe4[];
extern const char data_02141fec[];
extern const char data_02141ff4[];

extern void func_02015134(char *dest, const char *source);
extern void func_0201524c(char *dest, const char *source);
extern void func_020516dc(void *request, const char *path, int mode, int flags);
extern int func_02051844(void *request, int flags);
extern void *func_020519e8(void *request);
extern void func_02008848(void *dest, int value, unsigned int size);
extern void func_02058854(void *object);

/* Starts or polls a request and stores its result at context->unk_2470.
 * The caller must preserve context and suffix until this returns one. */
int func_02037dd4(Unk02037dd4Context *context, const char *suffix)
{
    int done = 0;
    switch (data_0215dd30) {
    case 0: {
        char path[64] = {0};
        func_02015134(path, data_02141f98[1]);
        func_0201524c(path, suffix);
        func_0201524c(path, data_02141fdc);
        func_020516dc(data_0215dd34, path, 0, 0x10000);
        data_0215dd30 = 1;
    }
        /* fall through: poll immediately after starting */
    case 1:
        if (func_02051844(data_0215dd34, 0x10000) == 0) {
            context->unk_2470 = func_020519e8(data_0215dd34);
            func_02008848(&data_0215dd30, 0, UNK_REQUEST_BLOCK_SIZE);
            done = 1;
        }
        break;
    }
    return done;
}

/* The prefix + suffix + extension path build and request start appear
 * inlined at each start state in the original, so they are not a helper. */

/* Advances three sequential requests; results go to context->unk_30a4..unk_30ac.
 * Context and suffix must remain valid across calls until completion. */
int func_02037ec4(Unk02037dd4Context *context, const char *suffix)
{
    int done = 0;
    switch (data_0215ddac) {
    case 0:
        func_02058854(context->unk_24a4);
        data_0215ddac = 1;
        break;
    case 1: {
        char path[64] = {0};
        func_02015134(path, data_02141f98[1]);
        func_0201524c(path, suffix);
        func_0201524c(path, data_02141fe4);
        func_020516dc(data_0215ddb0, path, 0, 0x10000);
        data_0215ddac = 2;
    }
        /* fall through: poll immediately after starting */
    case 2:
        if (func_02051844(data_0215ddb0, 0x10000) == 0) {
            context->unk_30a4 = func_020519e8(data_0215ddb0);
            data_0215ddac = 3;
        }
        break;
    case 3: {
        char path[64] = {0};
        func_02015134(path, data_02141f98[1]);
        func_0201524c(path, suffix);
        func_0201524c(path, data_02141fec);
        func_020516dc(data_0215ddb0, path, 0, 0x10000);
        data_0215ddac = 4;
    }
        /* fall through: poll immediately after starting */
    case 4:
        if (func_02051844(data_0215ddb0, 0x10000) == 0) {
            context->unk_30a8 = func_020519e8(data_0215ddb0);
            data_0215ddac = 5;
        }
        break;
    case 5: {
        char path[64] = {0};
        func_02015134(path, data_02141f98[1]);
        func_0201524c(path, suffix);
        func_0201524c(path, data_02141ff4);
        func_020516dc(data_0215ddb0, path, 0, 0x10000);
        data_0215ddac = 6;
    }
        /* fall through: poll immediately after starting */
    case 6:
        if (func_02051844(data_0215ddb0, 0x10000) == 0) {
            context->unk_30ac = func_020519e8(data_0215ddb0);
            func_02008848(&data_0215ddac, 0, UNK_REQUEST_BLOCK_SIZE);
            done = 1;
        }
        break;
    }
    return done;
}
