/* src/game/unit_021250a8.c: setup, message handler and activation for the ImageBgDual3D task
   (callback table entries point into src/ImageBgDual3D.c). */
#include "types.h"

/* Owner object for the handler below; ImageBgDual3D keeps it in data_02176e8c. */
typedef struct Unk1250a8Work {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
} Unk1250a8Work;

/* Payload of a type-0 message: flag byte, value valid when bit 3 is set. */
typedef struct Unk1250a8Payload {
    u8 flags;
    u8 pad_0001[0xf];
    u32 unk_0010;
} Unk1250a8Payload;

typedef struct Unk1250a8Msg {
    u32 type;
    Unk1250a8Payload payload;
} Unk1250a8Msg;

/* Request block for Unk0bc1a8_Unk_0bc928: bit i of mask marks ptrs[i] valid. */
typedef struct Unk1250a8Req {
    u8 mask[2];
    void *ptrs[16];
} Unk1250a8Req;

typedef struct Unk1250a8WorkArea {
    u8 pad_0000[0x35c];
    u16 unk_035c;
} Unk1250a8WorkArea;

/* Callback table filled by func_021250a8. */
typedef struct Unk1250a8Desc {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    void *unk_000c;
    void *unk_0010;
    void *unk_0014;
    void *unk_0018;
    void *unk_001c;
    void *unk_0020;
} Unk1250a8Desc;

extern Unk1250a8Work *data_02176e8c;

void ImageBgDual3D_Unk_1252b4(void);
void ImageBgDual3D_Nop_1252f4(void);
void ImageBgDual3D_Nop_1252f8(void);
void ImageBgDual3D_Nop_1252fc(void);
void ImageBgDual3D_Clear_data_02176e8c(void);
void func_02125104(Unk1250a8Work *w, Unk1250a8Msg *msg);
void func_02008644(u32 val, void *dst, u32 size);
int func_0203546c(void *dst, u32 n, u16 key);
int Unk02f2a8_Unk_03550c(void *dst, u32 n, u16 key);
Unk1250a8WorkArea *Unk02e000_GetWorkArea(void);
void *Unk0cb32c_Unk_0cb54c(void);
void Unk0bc1a8_Unk_0bc928(u32 a, u32 b, Unk1250a8Req *req);
void Unk0bc1a8_Unk_0bc504(Unk1250a8Work *w, u32 b);
void func_02052634(int a, int b, int c);

/* Fills the callback descriptor for the ImageBgDual3D task (size 12, handler func_02125104). */
void func_021250a8(Unk1250a8Desc *d)
{
    d->unk_0000 = 12;
    d->unk_0004 = 0;
    d->unk_000c = ImageBgDual3D_Unk_1252b4;
    d->unk_0010 = ImageBgDual3D_Nop_1252f4;
    d->unk_0014 = ImageBgDual3D_Nop_1252f8;
    d->unk_0018 = ImageBgDual3D_Nop_1252fc;
    d->unk_001c = ImageBgDual3D_Clear_data_02176e8c;
    d->unk_0020 = func_02125104;
}

static inline int Unk1250a8_GetPayloadValue(Unk1250a8Payload *p, u32 *out)
{
    u32 value;

    if (p == 0) {
        return 0;
    }
    value = p->unk_0010;
    if (p->flags & 8) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Message handler: type 0 builds a request (mode 0: two cleared buffers, mode 1: a looked-up
   pointer) and sends it as request 36/9; type 1 forwards to Unk0bc1a8_Unk_0bc504. */
void func_02125104(Unk1250a8Work *w, Unk1250a8Msg *msg)
{
    u8 buf32[32];
    u8 buf12[12];
    Unk1250a8Req req;
    int i;
    int j;
    u32 mode;
    u32 type = msg->type;
    Unk1250a8Payload *payload = &msg->payload;

    switch (type) {
    case 0:
        if (!Unk1250a8_GetPayloadValue(payload, &mode)) {
            return;
        }
        for (i = 0; i < 2; i++) {
            req.mask[i] = 0;
        }
        for (j = 0; j < 16; j++) {
            req.ptrs[j] = 0;
        }
        w->unk_0000 = mode;
        if (mode == 0) {
            func_02008644(0, buf32, sizeof(buf32));
            func_02008644(0, buf12, sizeof(buf12));
            if (func_0203546c(buf32, 16, Unk02e000_GetWorkArea()->unk_035c)) {
                req.ptrs[7] = buf32;
                req.mask[0] |= 0x80;
            }
            if (Unk02f2a8_Unk_03550c(buf12, 6, Unk02e000_GetWorkArea()->unk_035c)) {
                req.ptrs[8] = buf12;
                req.mask[1] |= 1;
            }
            Unk0bc1a8_Unk_0bc928(36, 9, &req);
        } else if (mode == 1) {
            req.ptrs[7] = Unk0cb32c_Unk_0cb54c();
            req.mask[0] |= 0x80;
            Unk0bc1a8_Unk_0bc928(36, 9, &req);
        }
        w->unk_0008 = 1;
        break;
    case 1:
        Unk0bc1a8_Unk_0bc504(w, 0);
        break;
    case 2:
    case 3:
    case 4:
        break;
    }
}

/* Registers w as the active ImageBgDual3D object and calls func_02052634(1, 0, 31). */
void func_0212528c(Unk1250a8Work *w)
{
    data_02176e8c = w;
    w->unk_0008 = 0;
    func_02052634(1, 0, 31);
}
