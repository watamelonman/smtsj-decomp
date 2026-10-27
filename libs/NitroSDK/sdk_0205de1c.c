#include "libs/NitroSDK/sdk_0205de1c.h"

extern int func_0205db8c(Unk05de1cObject *object);
extern void func_02057fd8(void);
extern void func_0205ad18(Unk05de1cProvider *provider, u32 **data, u32 *auxiliary);
extern void func_0205ad0c(Unk05de1cProvider *provider, u32 *data, u32 auxiliary);
extern void func_02058fd0(Unk05de1cProvider *provider, u32 index, Unk05de1cPacket *packet);

/* The loads at 0205de1c/24 select objects[index] before the provider resolver. */
int func_0205de1c(Unk05de1cTable *table, u32 index)
{
    return func_0205db8c(table->objects[index]);
}

/* The store at 0205de38 replaces only the borrowed pointer at object +48. */
void func_0205de30(Unk05de1cTable *table, u32 index, Unk05de1cProvider *provider)
{
    table->objects[index]->provider = provider;
}

/* The range's byte offset and count drive 24-byte ascending submissions;
 * the last argument is one at 0205debc. */
void func_0205de40(u32 flags, Unk05de1cTable *table, u32 index, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth)
{
    Unk05de1cRecord *record = table->records;
    u32 i;
    u32 count = table->ranges[index].count;
    record = (Unk05de1cRecord *)((u8 *)record + table->ranges[index].offset);
    for (i = 0; i < count; i++, record++) {
        func_0205e048(flags, table, record, x, y, sx, sy, angle, alpha, depth, 1);
    }
}

/* Same range traversal as 0205de40, with zero as the final submission flag. */
void func_0205dee8(u32 flags, Unk05de1cTable *table, u32 index, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth)
{
    Unk05de1cRecord *record = table->records;
    u32 i;
    u32 count = table->ranges[index].count;
    record = (Unk05de1cRecord *)((u8 *)record + table->ranges[index].offset);
    for (i = 0; i < count; i++, record++) {
        func_0205e048(flags, table, record, x, y, sx, sy, angle, alpha, depth, 0);
    }
}

/* The pre-loop provider call and descending 24-byte cursor at 0205dfdc..e038
 * establish reverse traversal; the range must refer to valid storage. */
void func_0205df90(u32 flags, Unk05de1cTable *table, u32 index, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth)
{
    Unk05de1cRecord *record = table->records;
    u32 i;
    u32 count = table->ranges[index].count;
    record = (Unk05de1cRecord *)((u8 *)record + table->ranges[index].offset);
    func_02057fd8();
    record += count - 1;
    for (i = 0; i < count; i++, record--) {
        func_0205e048(flags, table, record, x, y, sx, sy, angle, alpha, depth, 0);
    }
}

/* The paired 0205ad18/0205ad0c calls save and restore provider +80/+76;
 * object +52/+12 are bound only for the intervening 02058fd0 call. */
void func_0205e2bc(Unk05de1cObject *object, u32 index, Unk05de1cPacket *packet)
{
    u32 *data;
    u32 auxiliary;
    func_0205ad18(object->provider, &data, &auxiliary);
    func_0205ad0c(object->provider, object->auxiliaryData, object->auxiliary);
    func_02058fd0(object->provider, index, packet);
    func_0205ad0c(object->provider, data, auxiliary);
}

extern void func_02057e18(u32 alpha);
extern void func_020574d4(void);

/* Packet fields follow the stores at 0205e0a4..e110. Record flag bits
 * select flips, opacity and angle additions; 04000444/448 bracket submission
 * with the original geometry matrix-stack commands. */
void func_0205e048(u32 flags, Unk05de1cTable *table, Unk05de1cRecord *record, s32 x, s32 y, float sx, float sy, s32 angle, float alpha, u32 depth, int reset)
{
    Unk05de1cObject *object = table->objects[record->objectIndex];
    Unk05de1cPacket packet;
    u8 opacity;
    if (!(flags & 0x800000)) {
        /* Q12 degrees to the provider's unsigned 16-bit turn angle. */
        angle = (u16)(((s64)(angle << 12) * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    }
    packet.flags = flags;
    packet.x = record->x + x;
    packet.y = record->y + y;
    packet.scaleX = sx;
    packet.scaleY = sy;
    packet.angle = ((record->flags << 6) >> 16) + angle;
    packet.depth = record->depth + depth;
    packet.width = record->width;
    packet.height = record->height;
    packet.repeatX = 1;
    packet.repeatY = 1;
    if (alpha == 1.0f) {
        opacity = (record->flags << 22) >> 27;
    } else {
        opacity = (s32)(u32)((float)((record->flags << 22) >> 24) * alpha) >> 3;
    }
    if (opacity == 0) return;
    packet.flags |= 0x10000000;
    if (record->bits.flipX || record->bits.flipY) {
        if (record->bits.flipX && record->bits.flipY) packet.flags |= 0x4000;
        else if (record->bits.flipX) packet.flags |= 0x1000;
        else if (record->bits.flipY) packet.flags |= 0x2000;
    }
    if (record->bits.special) packet.flags |= 0x5000000;
    if (packet.angle != 0) packet.flags |= 0x800010;
    if (packet.scaleX != 1.0f || packet.scaleY != 1.0f) packet.flags |= 0x80;
    packet.flags |= 0x8000;
    if (reset) {
        if (opacity != 31) func_02057fd8();
        else if (object->provider->mode == 1 || object->provider->mode == 6) func_02057fd8();
    }
    func_02057e18(opacity);
    func_020574d4();
    *(volatile u32 *)0x04000444 = 0;
    func_0205e2bc(object, record->entryIndex, &packet);
    *(volatile u32 *)0x04000448 = 1;
}
