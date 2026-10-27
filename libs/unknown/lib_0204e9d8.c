#include "libs/unknown/lib_0204e9d8.h"

extern s32 func_0204d938(const Unk04e9d8Request *, u32);
extern const u32 *func_020cb1a0(u32);
extern u32 func_020b0f2c(s32);
extern u32 func_020b0e08(s32);
extern u32 func_020b0d48(s32, u32);
extern s32 func_02050074(s32, s32);
extern s32 func_02049d80(Unk04e9d8Object *, s32);
extern s32 func_0204d4ac(Unk04e9d8Object *, s32);
extern s32 func_0204d3fc(Unk04e9d8Object *, s32);
extern s32 func_0204d370(Unk04e9d8Object *, s32);
extern s32 func_0204d380(Unk04e9d8Object *, s32);
extern s32 func_0204d350(Unk04e9d8Object *, s32);
extern s32 func_0204d360(Unk04e9d8Object *, s32);
extern s32 func_0204d3cc(Unk04e9d8Object *, s32);
extern s32 func_0204d3e4(Unk04e9d8Object *, s32);
extern s32 func_0204d390(Unk04e9d8Object *, s32);

/* ARM 0204e9d8: tail-forwards the request unchanged to 0204d938. */
s32 func_0204e9d8(const Unk04e9d8Request *request, u32 id)
{
    return func_0204d938(request, id);
}

/* ARM 0204ebb4: mode 6 consults provider bits 5..8; mode 1 swaps groups 1/2. */
u32 func_0204ebb4(const Unk04e9d8Request *request, u32 id, u32 flags, s32 argument)
{
    s32 group = 0;
    switch (request->mode) {
    case 1:
        if (((id >> 16) & 255) == 1) group = 2;
        else if (((id >> 16) & 255) == 2) group = 1;
        break;
    case 6: {
        const u32 *entry = func_020cb1a0(request->argument);
        if (entry) {
            switch ((entry[9] << 23) >> 28) {
            case 2: case 3: case 4: group = (id >> 16) & 255; break;
            case 0: case 1: case 5: case 6:
                if (((id >> 16) & 255) == 1) group = 2;
                else if (((id >> 16) & 255) == 2) group = 1;
                break;
            }
        } else {
            if (((id >> 16) & 255) == 1) group = 2;
            else if (((id >> 16) & 255) == 2) group = 1;
        }
        break;
    }
    }
    {
        s32 flag_b = (flags & 0x4000) ? 0 : 1;
        u32 mode = flags & 255;
        s32 flag_a = (flags & 0x8000) ? 0 : 1;
        return func_0204ecc8(mode, argument, group, flag_a, flag_b, id);
    }
}

/* ARM 0204ecc8: dispatches the 23 observed selection modes, then chooses a candidate.
 * The original stack reserves six IDs; callers must satisfy that capacity contract. */
u32 func_0204ecc8(u32 mode, s32 argument, s32 group, s32 flag_a, s32 flag_b, u32 id)
{
    u32 candidates[6];
    s32 count = 0;
    switch (mode) {
    case 1: candidates[0] = func_020b0f2c(group); count = 1; break;
    case 2: candidates[0] = func_020b0e08(group); count = 1; break;
    case 3: count = func_0204eaac(candidates, group, 0, func_02049d80, 0); break;
    case 4: count = func_0204eaac(candidates, group, 0, func_02049d80, 1); break;
    case 5: count = func_0204eaac(candidates, group, 1, func_02049d80, 0); break;
    case 6: count = func_0204eaac(candidates, group, 1, func_02049d80, 1); break;
    case 7: count = func_0204e9e4(candidates, group, argument, func_0204d4ac, 0); break;
    case 8: count = func_0204e9e4(candidates, group, argument, func_0204d4ac, 1); break;
    case 9: count = func_0204e9e4(candidates, group, argument, func_0204d3fc, 0); break;
    case 10: count = func_0204e9e4(candidates, group, argument, func_0204d3fc, 1); break;
    case 11: candidates[0] = id; count = 1; break;
    case 12: candidates[0] = func_020b0d48(group, id); count = 1; break;
    case 13: count = func_0204e9e4(candidates, group, argument, func_0204d370, 0); break;
    case 14: count = func_0204e9e4(candidates, group, argument, func_0204d380, 0); break;
    case 15: count = func_0204e9e4(candidates, group, argument, func_0204d350, 0); break;
    case 16: count = func_0204e9e4(candidates, group, argument, func_0204d360, 0); break;
    case 17: count = func_0204e9e4(candidates, group, argument, func_0204d370, 1); break;
    case 18: count = func_0204e9e4(candidates, group, argument, func_0204d380, 1); break;
    case 19: count = func_0204e9e4(candidates, group, argument, func_0204d350, 1); break;
    case 20: count = func_0204e9e4(candidates, group, argument, func_0204d360, 1); break;
    case 21: count = func_0204e9e4(candidates, group, argument, func_0204d3cc, 0); break;
    case 22: count = func_0204e9e4(candidates, group, argument, func_0204d3e4, 0); break;
    case 23: count = func_0204e9e4(candidates, group, argument, func_0204d390, 0); break;
    }
    if (count == 0) {
        return func_020b0e08(group);
    } else {
        s32 index = func_02050074(0, count - 1);
        return candidates[index];
    }
}
