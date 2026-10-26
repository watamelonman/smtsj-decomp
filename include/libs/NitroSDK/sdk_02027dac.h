#ifndef SDK_02027DAC_H
#define SDK_02027DAC_H

/** NSBVA resource prefix; visibility words continue for every frame/node pair. */
typedef struct Sdk027dacVisResource {
    unsigned int header;
    unsigned short numFrame, numNode, size, reserved;
    unsigned int visData[1];
} Sdk027dacVisResource;

/** Visibility output preserves the selected bit mask rather than normalizing it. */
typedef struct Sdk027dacVisResult {
    unsigned int isVisible;
} Sdk027dacVisResult;

typedef struct Sdk027dacAnmObj Sdk027dacAnmObj;
/** Callback consumes a valid animation frame and node index. */
typedef void (*Sdk027dacVisCallback)(Sdk027dacVisResult *, const Sdk027dacAnmObj *, unsigned int);

/** Animation object prefix; caller allocates numMapData trailing map entries. */
struct Sdk027dacAnmObj {
    int frame;
    unsigned int reserved04;
    const Sdk027dacVisResource *resAnm;
    Sdk027dacVisCallback funcAnm;
    unsigned char reserved10[9];
    unsigned char numMapData;
    unsigned short mapData[1];
};

/** Model prefix through the node count used to size the identity mapping. */
typedef struct Sdk027dacModel {
    unsigned char reserved00[23];
    unsigned char numNode;
} Sdk027dacModel;

/** Fixed-point joint result; rotation and translation form contiguous 4x3 data. */
typedef struct Sdk027dacJointResult {
    unsigned int flag;
    int scale[3], scaleEx0[3], scaleEx1[3];
    int rot[9], trans[3];
} Sdk027dacJointResult;

/** Initialize the visibility callback and caller-sized node identity map. */
void func_02027dac(Sdk027dacAnmObj *, const Sdk027dacVisResource *, const Sdk027dacModel *);
/** Sample a valid frame/node pair; the caller ensures the resource covers it. */
void func_02027df8(Sdk027dacVisResult *, const Sdk027dacAnmObj *, unsigned int);
/** Submit nonidentity joint components to the geometry command buffer. */
void func_02027e30(const Sdk027dacJointResult *);

#endif
