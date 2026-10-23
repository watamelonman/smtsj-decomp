PRE = r'''/* Request block passed to func_020bc9f4 (same shape as the 020bcbc4 requests). */
typedef struct Unk065e88Request {
    u8 flags[2];
    u8 pad_02[2];
    u32 values[16];
} Unk065e88Request;
void func_0205ad2c(const void *descriptor);
void CampStatus_Unk_0dc6c0(void);
void func_020bc9f4(u32 kind, Unk065e88Request *request);
void Unk06a224_Unk_06aa0c(void);
extern u8 data_02145788[], data_02145794[], data_021457b0[];
'''

F66E80 = r'''/* Re-creates the owner's handles in one pass (the work of stages 1..7 of
 * func_020667d0): submits a zeroed kind-3 request, creates the handles at
 * +0x108..+0x150 and the two descriptor handles, the twelve list slots
 * (rows 11 pixels apart) and eight objects, and shows the first two objects. */
void func_02066e80(Unk065e88InitOwner *o)
{
    Unk065e88Request request;
    int i;
    int j;

    func_0205ad2c(data_02145788);
    CampStatus_Unk_0dc6c0();
    for (j = 0; j < 2; j++) request.flags[j] = 0;
    for (j = 0; j < 16; j++) request.values[j] = 0;
    func_020bc9f4(3, &request);
    Unk06a224_Unk_06aa0c();
    Unk05b82c_Unk_05b82c(65);
    o->h108 = func_020629ac(5, 4, 1, 1);
    o->h10c = func_020629ac(3, 1, 0, 0);
    o->h114 = func_020629ac(3, 4, 0, 0);
    o->h110 = func_020629ac(3, 4, 0, 0);
    o->h150 = func_020629ac(4, 5, 1, 0);
    func_02061e98(o->h10c, 16, 1);
    func_02061e98(o->h114, 16, 1);
    func_02061e98(o->h110, 16, 1);
    func_02061e98(o->h150, 16, 1);
    {
        u8 *area = Unk02e000_Thunk_0202e788();
        func_02061f10(o->h10c, -1, 0, 0, (int)(area + 72));
    }
    o->h118 = func_020629ac(3, 4, 1, 0);
    o->h11c = func_020629ac(3, 4, 1, 0);
    func_02061e98(o->h118, 16, 1);
    func_02061e98(o->h11c, 16, 1);
    o->h3b0 = func_0205dcd4(data_02145794, 1);
    o->h3b4 = func_0205c2c4(data_021457b0);
    for (i = 0, j = 0; i < 12; i++) {
        o->slots[i] = Unk065e88_Call_02065fc0(o->h3b0, o->h3b4, 0, 0);
        func_0205c408(o->slots[i]->unk00, 8);
        func_0205c6f8(o->slots[i]->unk00);
        Unk065e88_SetFlag3a((Unk065e88Flag *)o->slots[i], 0);
        o->slots[i]->field30 = 6;
        o->slots[i]->field24 = 11;
        o->slots[i]->field10 = j;
        j += 11;
    }
    for (i = 0; i <= 7; i++)
        o->objs[i] = Unk065e88_Call_02065fc0(o->h3b0, o->h3b4, 0, 0);
    func_0205c408(o->objs[0]->unk00, 0);
    func_0205c6f8(o->objs[0]->unk00);
    func_0205c408(o->objs[1]->unk00, 1);
    func_0205c6f8(o->objs[1]->unk00);
}'''

SPECS = [('src/game/unit_02065e88.c', [('func_02066e80', F66E80)], PRE)]
