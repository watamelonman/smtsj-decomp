#include "types.h"

extern int data_0215dd30;
extern int data_0215ddac;
extern char data_0215dd34[];
extern char data_0215ddb0[];
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

/* Starts or polls a request and stores its result at context offset 0x2470.
 * The caller must preserve context and suffix until this returns one. */
int func_02037dd4(void *context, const char *suffix)
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
    case 1:
        if (func_02051844(data_0215dd34, 0x10000) == 0) {
            *(void **)((char *)context + 0x2470) = func_020519e8(data_0215dd34);
            func_02008848(&data_0215dd30, 0, 0x7c);
            done = 1;
        }
        break;
    }
    return done;
}

/* Advances three sequential requests; results occupy offsets 0x30a4..0x30ac.
 * Context and suffix must remain valid across calls until completion. */
int func_02037ec4(void *context, const char *suffix)
{
    int done = 0;
    switch (data_0215ddac) {
    case 0:
        func_02058854((char *)context + 0x24a4);
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
    case 2:
        if (func_02051844(data_0215ddb0, 0x10000) == 0) {
            *(void **)((char *)context + 0x30a4) = func_020519e8(data_0215ddb0);
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
    case 4:
        if (func_02051844(data_0215ddb0, 0x10000) == 0) {
            *(void **)((char *)context + 0x30a8) = func_020519e8(data_0215ddb0);
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
    case 6:
        if (func_02051844(data_0215ddb0, 0x10000) == 0) {
            *(void **)((char *)context + 0x30ac) = func_020519e8(data_0215ddb0);
            func_02008848(&data_0215ddac, 0, 0x7c);
            done = 1;
        }
        break;
    }
    return done;
}
