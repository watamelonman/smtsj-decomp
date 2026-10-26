#include "libs/unknown/lib_02021920.h"

/* NitroSystem libraries/g3d/src/kernel.c removeLink_: unlink by identity,
 * preserving the list when absent; the caller owns the nodes and head storage. */
int func_02021920(G3dAnimationLink **head, G3dAnimationLink *item)
{
    G3dAnimationLink *node;
    G3dAnimationLink *previous;

    if (!*head) {
        return 0;
    }
    if (*head == item) {
        *head = (*head)->next;
        item->next = 0;
        return 1;
    }
    node = (*head)->next;
    previous = *head;
    while (node) {
        if (node == item) {
            previous->next = node->next;
            node->next = 0;
            return 1;
        }
        previous = node;
        node = node->next;
    }
    return 0;
}

/* NitroSystem kernel.c NNS_G3dRenderObjRemoveAnmObj: the three list offsets
 * and HINT_OBSOLETE bit (0x10) agree with the original instructions. */
void func_02021994(G3dRenderLists *render, G3dAnimationLink *item)
{
    if (func_02021920(&render->material, item) ||
        func_02021920(&render->joint, item) ||
        func_02021920(&render->visibility, item)) {
        render->flags |= 0x10;
        return;
    }
}

/* NitroSystem kernel.c NNS_G3dTexGetRequiredSize: sizeTex at +0x0c
 * counts eight-byte units; null resources require no texture storage. */
unsigned int func_020219e8(const G3dTextureSizes *texture)
{
    if (texture) {
        return (unsigned int)(texture->textureSize << 3);
    } else {
        return 0;
    }
}

/* NitroSystem kernel.c NNS_G3dTex4x4GetRequiredSize: sizeTex at +0x1c
 * counts eight-byte units, excluding the separate palette-index storage. */
unsigned int func_020219fc(const G3dTextureSizes *texture)
{
    if (texture) {
        return (unsigned int)(texture->compressedSize << 3);
    } else {
        return 0;
    }
}
