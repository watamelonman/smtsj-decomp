/* Known-source comparison: pret/pokediamond, arm9/lib/NitroSDK/src/GX_load2d.c.
 * Keep configured symbol names so delink relocations remain compatible. */
typedef unsigned int u32;

extern u32 data_0213ce44;
extern void func_02007fb0(u32 channel, const void *source, void *destination, u32 size);
extern void func_02007f40(u32 channel, const void *source, void *destination, u32 size);
extern void func_0200866c(const void *source, void *destination, u32 size);
extern void func_020086bc(const void *source, void *destination, u32 size);

/* NitroSDK exposes these mappings through inline pointer accessors. */
static inline void *MainOBJ(void) { return (void *)0x06400000; }
static inline void *SubOBJ(void) { return (void *)0x06600000; }

/* Keep the selected OBJ mapping as an operand, as in NitroSDK's GXi helper. */
static inline void CopyOBJ(u32 channel, const void *source, u32 destination,
                          u32 size)
{
    if (channel != (u32)-1 && size > 48) {
        func_02007f40(channel, source, (void *)destination, size);
    } else {
        func_020086bc(source, (void *)destination, size);
    }
}

/* Copy size bytes to main OBJ palette at a byte offset. The hardware destination
 * and DMA/CPU branches are evidenced by the original instructions at 0x02004760.
 * Source, offset and size must satisfy the copy alignment: two bytes for palettes, four bytes otherwise. */
void func_02004760(const void *source, u32 offset, u32 size)
{
    if (data_0213ce44 != (u32)-1 && size > 28) {
        func_02007fb0(data_0213ce44, source, (void *)(0x05000200 + offset), size);
    } else {
        func_0200866c(source, (void *)(0x05000200 + offset), size);
    }
}

/* Copy size bytes to sub OBJ palette at a byte offset. The hardware destination
 * and DMA/CPU branches are evidenced by the original instructions at 0x020047b8.
 * Source, offset and size must satisfy the copy alignment: two bytes for palettes, four bytes otherwise. */
void func_020047b8(const void *source, u32 offset, u32 size)
{
    if (data_0213ce44 != (u32)-1 && size > 28) {
        func_02007fb0(data_0213ce44, source, (void *)(0x05000600 + offset), size);
    } else {
        func_0200866c(source, (void *)(0x05000600 + offset), size);
    }
}

/* Copy size bytes to main OAM at a byte offset. The hardware destination
 * and DMA/CPU branches are evidenced by the original instructions at 0x02004810.
 * Source, offset and size must satisfy the copy alignment: two bytes for palettes, four bytes otherwise. */
void func_02004810(const void *source, u32 offset, u32 size)
{
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, source, (void *)(0x07000000 + offset), size);
    } else {
        func_020086bc(source, (void *)(0x07000000 + offset), size);
    }
}

/* Copy size bytes to sub OAM at a byte offset. The hardware destination
 * and DMA/CPU branches are evidenced by the original instructions at 0x02004864.
 * Source, offset and size must satisfy the copy alignment: two bytes for palettes, four bytes otherwise. */
void func_02004864(const void *source, u32 offset, u32 size)
{
    if (data_0213ce44 != (u32)-1 && size > 48) {
        func_02007f40(data_0213ce44, source, (void *)(0x07000400 + offset), size);
    } else {
        func_020086bc(source, (void *)(0x07000400 + offset), size);
    }
}

/* Copy size bytes to main OBJ character memory at a byte offset. The hardware destination
 * and DMA/CPU branches are evidenced by the original instructions at 0x020048bc.
 * Source, offset and size must satisfy the copy alignment: two bytes for palettes, four bytes otherwise. */
void func_020048bc(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)MainOBJ();
    CopyOBJ(data_0213ce44, source, base + offset, size);
}

/* Copy size bytes to sub OBJ character memory at a byte offset. The hardware destination
 * and DMA/CPU branches are evidenced by the original instructions at 0x02004914.
 * Source, offset and size must satisfy the copy alignment: two bytes for palettes, four bytes otherwise. */
void func_02004914(const void *source, u32 offset, u32 size)
{
    u32 base = (u32)SubOBJ();
    CopyOBJ(data_0213ce44, source, base + offset, size);
}
