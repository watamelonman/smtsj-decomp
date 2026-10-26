typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed long long s64;

/* Six 20.12 scale factors, including inverse scale factors. */
typedef struct ScalePair { s32 v[6]; } ScalePair;
/* Only the flags and scale portion of the joint result are used here. */
typedef struct JointResult {
    u32 flags;
    s32 scale[3];
    ScalePair inherited;
} JointResult;
/* Identity-scale bits start at the observed render-state offset 0xc4. */
typedef struct RenderState {
    u8 pad_0000[0xc4];
    u32 identity[8];
} RenderState;
extern RenderState *data_02156f8c;
extern ScalePair data_02157d90[];
extern void func_020086bc(const void *source, void *destination, u32 bytes);

/* NNSi_G3dGetJointScaleSi3d: combine joint and parent scales and identity bits.
 * Source: ntrtwl/NitroSystem, libraries/g3d/src/cgtool/si3d.c.
 * Six signed products shifted by 12 and 24-byte copies confirm this match.
 * Node indices are byte-sized; callers supply valid cache and bitset indices. */
void func_02028810(JointResult *result, const s32 *scale, const u8 *command, u32 flags)
{
    u32 node = command[1];
    u32 parent = command[2];
    if (flags & 4) {
        result->flags |= 1;
        if (data_02156f8c->identity[parent >> 5] & (1U << (parent & 31))) {
            data_02156f8c->identity[node >> 5] |= 1U << (node & 31);
            result->flags |= 24;
        } else {
            func_020086bc(&data_02157d90[parent], &data_02157d90[node], 24);
            func_020086bc(&data_02157d90[parent], &result->inherited, 24);
        }
    } else {
        result->scale[0] = scale[0];
        result->scale[1] = scale[1];
        result->scale[2] = scale[2];
        if (data_02156f8c->identity[parent >> 5] & (1U << (parent & 31))) {
            func_020086bc(scale, &data_02157d90[node], 24);
            data_02156f8c->identity[node >> 5] &= ~(1U << (node & 31));
            result->flags |= 24;
        } else {
            data_02156f8c->identity[node >> 5] &= ~(1U << (node & 31));
            data_02157d90[node].v[0] = (s64)scale[0] * data_02157d90[parent].v[0] >> 12;
            data_02157d90[node].v[1] = (s64)scale[1] * data_02157d90[parent].v[1] >> 12;
            data_02157d90[node].v[2] = (s64)scale[2] * data_02157d90[parent].v[2] >> 12;
            data_02157d90[node].v[3] = (s64)scale[3] * data_02157d90[parent].v[3] >> 12;
            data_02157d90[node].v[4] = (s64)scale[4] * data_02157d90[parent].v[4] >> 12;
            data_02157d90[node].v[5] = (s64)scale[5] * data_02157d90[parent].v[5] >> 12;
            func_020086bc(&data_02157d90[parent], &result->inherited, 24);
        }
    }
}
