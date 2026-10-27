/* Adapted from ntrtwl/NitroSystem libraries/g3d/src/anm/nsbta.c,
 * revision d636fb5d2b212e8736f09859fff447be2bd0ac85.
 * Original linker names are retained because symbols.txt is human-owned. */
#include "libs/NitroSDK/sdk_020276f8.h"

/** Interpolate a scalar texture track; NitroSystem nsbta.c GetTexSRTAnmVectorVal_. Frames are whole indices, output is Q12. */
fx32 func_020276f8 (const NNSG3dResTexSRTAnm * pTexAnm, u32 info, u32 data, u32 frame)
{
    u32 idx, idx_sub;
    u32 last_interp;
    const void * pDataHead;

    if (info & NNS_G3D_TEXSRTANM_ELEM_CONST) {
        return (fx32)data;
    }

    pDataHead = (const void *)((u8 *)pTexAnm + data);

    if (!(info & NNS_G3D_TEXSRTANM_ELEM_STEP_MASK)) {
        idx = frame;
        goto TEXSRT_VAL_NONINTERP;
    }

    last_interp = (NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_MASK & info) >>
                  NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_TEXSRTANM_ELEM_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto TEXSRT_VAL_NONINTERP;
            } else {
                idx = frame >> 1;
                goto TEXSRT_VAL_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto TEXSRT_VAL_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto TEXSRT_VAL_NONINTERP;
            }

            if (frame & 1) {
                fx32 v, v_sub;
                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx = idx_sub + 1;
                } else {
                    idx = (frame >> 2);
                    idx_sub = idx + 1;
                }

                if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
                    v = *((const fx16 *)pDataHead + idx);
                    v_sub = *((const fx16 *)pDataHead + idx_sub);
                } else {
                    v = *((const fx32 *)pDataHead + idx);
                    v_sub = *((const fx32 *)pDataHead + idx_sub);
                }
                return (v + v + v + v_sub) >> 2;
            } else {
                idx = frame >> 2;
                goto TEXSRT_VAL_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto TEXSRT_VAL_NONINTERP;
        }
    }

TEXSRT_VAL_NONINTERP:
    if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
        return *((const fx16 *)pDataHead + idx);
    } else {
        return *((const fx32 *)pDataHead + idx);
    }
TEXSRT_VAL_INTERP_2:
    {
        fx32 v0, v1;
        if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
            v0 = *((const fx16 *)pDataHead + idx);
            v1 = *((const fx16 *)pDataHead + idx + 1);
        } else {
            v0 = *((const fx32 *)pDataHead + idx);
            v1 = *((const fx32 *)pDataHead + idx + 1);
        }
        return ((v0 + v1) >> 1);
    }
}

/** Evaluate a texture SRT dictionary entry into caller-owned material storage; NitroSystem nsbta.c GetTexSRTAnm_. */
void func_02027904 (const NNSG3dResTexSRTAnm * pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult * pResult)
{




    {
        const NNSG3dResDictTexSRTAnmData * pAnmData =
            (const NNSG3dResDictTexSRTAnmData *)NNS_G3dGetResDataByIdx(&pTexAnm->dict, idx);
        NNSG3dMatAnmResultFlag flag = pResult->flag;

        {
            fx32 transS, transT;

            transS = func_020276f8(pTexAnm,
                                            pAnmData->transS,
                                            pAnmData->transSEx,
                                            frame);
            transT = func_020276f8(pTexAnm,
                                            pAnmData->transT,
                                            pAnmData->transTEx,
                                            frame);

            if (transS == 0 && transT == 0) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO;
            } else {
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO;
                pResult->transS = transS;
                pResult->transT = transT;
            }
        }

        {

            u32 data = func_020277f8(pTexAnm,
                                              pAnmData->rot,
                                              pAnmData->rotEx,
                                              frame);

            if (data == ((FX32_ONE << 16) | 0)) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO;
            } else {
                pResult->sinR = (fx16)(data & 0x0000FFFF);
                pResult->cosR = (fx16)(data >> 16);
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO;
            }
        }

        {
            fx32 scaleS, scaleT;

            scaleS = func_020276f8(pTexAnm,
                                            pAnmData->scaleS,
                                            pAnmData->scaleSEx,
                                            frame);
            scaleT = func_020276f8(pTexAnm,
                                            pAnmData->scaleT,
                                            pAnmData->scaleTEx,
                                            frame);

            if (scaleS == FX32_ONE && scaleT == FX32_ONE) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE;
            } else {
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE;
                pResult->scaleS = scaleS;
                pResult->scaleT = scaleT;
            }
        }

        pResult->flag = flag;
    }
}

/** Map animation material names to model indices; NitroSystem nsbta.c NNSi_G3dAnmObjInitNsBta. Object storage includes numMat map entries. */
void func_02027a04 (NNSG3dAnmObj * pAnmObj, void * pResAnm, const NNSG3dResMdl * pResMdl)
{
    u32 i;
    NNSG3dResTexSRTAnm * srtAnm;
    const NNSG3dResMat * mat;




    srtAnm = (NNSG3dResTexSRTAnm *)pResAnm;
    mat = NNS_G3dGetMat(pResMdl);
    pAnmObj->funcAnm = (void *) NNS_G3dFuncAnmMatNsBtaDefault;
    pAnmObj->numMapData = pResMdl->info.numMat;

    MI_CpuClear16(&pAnmObj->mapData[0], sizeof(u16) * pAnmObj->numMapData);

    for (i = 0; i < srtAnm->dict.numEntry; ++i) {
        const NNSG3dResName * name = NNS_G3dGetResNameByIdx(&srtAnm->dict, i);
        int idx = NNS_G3dGetMatIdxByName(mat, name);
        if (!(idx < 0)) {
            pAnmObj->mapData[idx] = (u16)(i | NNS_G3D_ANMOBJ_MAPDATA_EXIST);
        }
    }
}

/** Apply the object frame and texture-coordinate generation flags; NitroSystem nsbta.c NNSi_G3dAnmCalcNsBta. Result is caller-owned. */
void func_02027ad8 (NNSG3dMatAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{



    {
        const NNSG3dResTexSRTAnm * pTexAnm
            = (const NNSG3dResTexSRTAnm *)pAnmObj->resAnm;

        func_02027904(pTexAnm,
                      (u16)dataIdx,
                      (u32)FX_Whole(pAnmObj->frame),
                      pResult);

        pResult->prmTexImage &= ~REG_G3_TEXIMAGE_PARAM_TGEN_MASK;
        pResult->prmTexImage |= GX_TEXGEN_TEXCOORD << REG_G3_TEXIMAGE_PARAM_TGEN_SHIFT;

        pResult->flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET;

    }
}
