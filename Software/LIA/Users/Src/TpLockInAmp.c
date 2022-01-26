/*
 * File: TpLockInAmp.c
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun Jan 16 09:32:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "TpLockInAmp.h"
#include "TpLockInAmp_private.h"

/* Block states (default storage) */
DW_TpLockInAmp_T TpLockInAmp_DW;

/* Real-time model */
static RT_MODEL_TpLockInAmp_T TpLockInAmp_M_;
RT_MODEL_TpLockInAmp_T *const TpLockInAmp_M = &TpLockInAmp_M_;

/* Exported data definition */

/* Definition for custom storage class: Global */
real32_T signal_amp;                   /* '<S1>/MATLAB Function' */
real32_T signal_input;                 /* '<Root>/In1' */
real32_T signal_pha;                   /* '<S1>/Trigonometric Function' */
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (TpLockInAmp_M->Timing.TaskCounters.TID[1])++;
  if ((TpLockInAmp_M->Timing.TaskCounters.TID[1]) > 3) {
                               /* Sample time: [0.0041666666666666666s, 0.0s] */
    TpLockInAmp_M->Timing.TaskCounters.TID[1] = 0;
  }

  (TpLockInAmp_M->Timing.TaskCounters.TID[2])++;
  if ((TpLockInAmp_M->Timing.TaskCounters.TID[2]) > 7) {
                               /* Sample time: [0.0083333333333333332s, 0.0s] */
    TpLockInAmp_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function */
void TpLockInAmp_step(void)
{
  b_dsp_FIRDecimator_0_TpLockIn_T *obj_0;
  b_dspcodegen_FIRDecimator_TpL_T *obj;
  int32_T cffIdx;
  int32_T i;
  int32_T jIdx;
  int32_T maxWindow;
  int32_T nSamps;
  int32_T nSampsAtBot;
  int32_T offsetFromMemBase;
  int32_T outBufIdx;
  real32_T rtb_Buffer[8];
  real32_T rtb_Buffer1[8];
  real32_T rtb_SineWave2;
  real32_T rtb_Unbuffer1;

  /* S-Function (sdspsine2): '<S1>/Sine Wave1' */
  rtb_SineWave2 = sinf(TpLockInAmp_DW.SineWave1_AccFreqNorm);

  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave1_AccFreqNorm += 0.130899698F;
  if (TpLockInAmp_DW.SineWave1_AccFreqNorm >= 6.28318548F) {
    TpLockInAmp_DW.SineWave1_AccFreqNorm -= 6.28318548F;
  } else {
    if (TpLockInAmp_DW.SineWave1_AccFreqNorm < 0.0F) {
      TpLockInAmp_DW.SineWave1_AccFreqNorm += 6.28318548F;
    }
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave1' */

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_SineWave2 *= signal_input;

  /* Buffer: '<S1>/Buffer' */
  nSamps = 16;
  offsetFromMemBase = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  if (16 - TpLockInAmp_DW.Buffer_inBufPtrIdx <= 1) {
    for (i = 0; i < 16 - TpLockInAmp_DW.Buffer_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_inBufPtrIdx + i] =
        rtb_SineWave2;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 15; i++) {
    TpLockInAmp_DW.Buffer_CircBuf[offsetFromMemBase + i] = rtb_SineWave2;
  }

  TpLockInAmp_DW.Buffer_inBufPtrIdx++;
  if (TpLockInAmp_DW.Buffer_inBufPtrIdx >= 16) {
    TpLockInAmp_DW.Buffer_inBufPtrIdx -= 16;
  }

  TpLockInAmp_DW.Buffer_bufferLength++;
  if (TpLockInAmp_DW.Buffer_bufferLength > 16) {
    TpLockInAmp_DW.Buffer_outBufPtrIdx = (TpLockInAmp_DW.Buffer_outBufPtrIdx +
      TpLockInAmp_DW.Buffer_bufferLength) - 16;
    if (TpLockInAmp_DW.Buffer_outBufPtrIdx > 16) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx -= 16;
    }

    TpLockInAmp_DW.Buffer_bufferLength = 16;
  }

  if (TpLockInAmp_M->Timing.TaskCounters.TID[2] == 0) {
    TpLockInAmp_DW.Buffer_bufferLength -= 8;
    if (TpLockInAmp_DW.Buffer_bufferLength < 0) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx += TpLockInAmp_DW.Buffer_bufferLength;
      if (TpLockInAmp_DW.Buffer_outBufPtrIdx < 0) {
        TpLockInAmp_DW.Buffer_outBufPtrIdx += 16;
      }

      TpLockInAmp_DW.Buffer_bufferLength = 0;
    }

    offsetFromMemBase = 0;
    if (TpLockInAmp_DW.Buffer_outBufPtrIdx < 0) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx += 16;
    }

    nSampsAtBot = 16 - TpLockInAmp_DW.Buffer_outBufPtrIdx;
    nSamps = 8;
    if (16 - TpLockInAmp_DW.Buffer_outBufPtrIdx <= 8) {
      for (i = 0; i < 16 - TpLockInAmp_DW.Buffer_outBufPtrIdx; i++) {
        rtb_Buffer[i] =
          TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_outBufPtrIdx + i];
      }

      offsetFromMemBase = 16 - TpLockInAmp_DW.Buffer_outBufPtrIdx;
      TpLockInAmp_DW.Buffer_outBufPtrIdx = 0;
      nSamps = 8 - nSampsAtBot;
    }

    for (i = 0; i < nSamps; i++) {
      rtb_Buffer[offsetFromMemBase + i] =
        TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_outBufPtrIdx + i];
    }

    TpLockInAmp_DW.Buffer_outBufPtrIdx += nSamps;

    /* MATLABSystem: '<S1>/CIC Compensation Decimator' incorporates:
     *  Buffer: '<S1>/Buffer'
     */
    obj = TpLockInAmp_DW.obj.pFIRDecimator;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->isSetupComplete = true;

      /* System object Initialization function: dsp.FIRDecimator */
      obj->cSFunObject.W2_CoeffIdx = 570;
      obj->cSFunObject.W0_PhaseIdx = 3;
      obj->cSFunObject.W4_TapDelayIndex = 567;
      obj->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 756; i++) {
        obj->cSFunObject.W3_StatesBuff[i] = 0.0F;
      }
    }

    obj_0 = &obj->cSFunObject;

    /* System object Outputs function: dsp.FIRDecimator */
    nSamps = 0;
    offsetFromMemBase = obj->cSFunObject.W4_TapDelayIndex;
    nSampsAtBot = obj->cSFunObject.W0_PhaseIdx;
    cffIdx = obj->cSFunObject.W2_CoeffIdx;
    outBufIdx = 0;
    maxWindow = (nSampsAtBot + 1) * 189 - 189;
    for (i = 0; i < 8; i++) {
      obj_0->W1_Sums += rtb_Buffer[nSamps] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
      for (jIdx = offsetFromMemBase + 1; jIdx < maxWindow + 189; jIdx++) {
        obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
        cffIdx++;
      }

      for (jIdx = maxWindow; jIdx <= offsetFromMemBase; jIdx++) {
        obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
        cffIdx++;
      }

      obj_0->W3_StatesBuff[offsetFromMemBase] = rtb_Buffer[nSamps];
      nSamps++;
      offsetFromMemBase += 189;
      if (offsetFromMemBase >= 756) {
        offsetFromMemBase -= 756;
      }

      nSampsAtBot++;
      if (nSampsAtBot < 4) {
        maxWindow += 189;
      } else {
        obj_0->O0_Y0[outBufIdx] = obj_0->W1_Sums;
        outBufIdx++;
        obj_0->W1_Sums = 0.0F;
        nSampsAtBot = 0;
        cffIdx = 0;
        offsetFromMemBase--;
        if (offsetFromMemBase < 0) {
          offsetFromMemBase += 189;
        }

        maxWindow = 0;
      }
    }

    obj->cSFunObject.W4_TapDelayIndex = offsetFromMemBase;
    obj->cSFunObject.W2_CoeffIdx = cffIdx;
    obj->cSFunObject.W0_PhaseIdx = nSampsAtBot;

    /* Unbuffer: '<S1>/Unbuffer1' incorporates:
     *  MATLABSystem: '<S1>/CIC Compensation Decimator'
     */
    TpLockInAmp_DW.Unbuffer1_CircBuff[0] = obj->cSFunObject.O0_Y0[0];
    TpLockInAmp_DW.Unbuffer1_CircBuff[1] = obj->cSFunObject.O0_Y0[1];
    TpLockInAmp_DW.Unbuffer1_memIdx = 0;
  }

  /* End of Buffer: '<S1>/Buffer' */

  /* Unbuffer: '<S1>/Unbuffer1' */
  if (TpLockInAmp_M->Timing.TaskCounters.TID[1] == 0) {
    rtb_Unbuffer1 =
      TpLockInAmp_DW.Unbuffer1_CircBuff[TpLockInAmp_DW.Unbuffer1_memIdx];
    if (TpLockInAmp_DW.Unbuffer1_memIdx < 1) {
      TpLockInAmp_DW.Unbuffer1_memIdx++;
    }
  }

  /* S-Function (sdspsine2): '<S1>/Sine Wave2' */
  rtb_SineWave2 = sinf(TpLockInAmp_DW.SineWave2_AccFreqNorm);

  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave2_AccFreqNorm += 0.130899698F;
  if (TpLockInAmp_DW.SineWave2_AccFreqNorm >= 6.28318548F) {
    TpLockInAmp_DW.SineWave2_AccFreqNorm -= 6.28318548F;
  } else {
    if (TpLockInAmp_DW.SineWave2_AccFreqNorm < 0.0F) {
      TpLockInAmp_DW.SineWave2_AccFreqNorm += 6.28318548F;
    }
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave2' */

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_SineWave2 *= signal_input;

  /* Buffer: '<S1>/Buffer1' */
  nSamps = 16;
  offsetFromMemBase = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  if (16 - TpLockInAmp_DW.Buffer1_inBufPtrIdx <= 1) {
    for (i = 0; i < 16 - TpLockInAmp_DW.Buffer1_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_inBufPtrIdx + i] =
        rtb_SineWave2;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 15; i++) {
    TpLockInAmp_DW.Buffer1_CircBuf[offsetFromMemBase + i] = rtb_SineWave2;
  }

  TpLockInAmp_DW.Buffer1_inBufPtrIdx++;
  if (TpLockInAmp_DW.Buffer1_inBufPtrIdx >= 16) {
    TpLockInAmp_DW.Buffer1_inBufPtrIdx -= 16;
  }

  TpLockInAmp_DW.Buffer1_bufferLength++;
  if (TpLockInAmp_DW.Buffer1_bufferLength > 16) {
    TpLockInAmp_DW.Buffer1_outBufPtrIdx = (TpLockInAmp_DW.Buffer1_outBufPtrIdx +
      TpLockInAmp_DW.Buffer1_bufferLength) - 16;
    if (TpLockInAmp_DW.Buffer1_outBufPtrIdx > 16) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx -= 16;
    }

    TpLockInAmp_DW.Buffer1_bufferLength = 16;
  }

  if (TpLockInAmp_M->Timing.TaskCounters.TID[2] == 0) {
    TpLockInAmp_DW.Buffer1_bufferLength -= 8;
    if (TpLockInAmp_DW.Buffer1_bufferLength < 0) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx += TpLockInAmp_DW.Buffer1_bufferLength;
      if (TpLockInAmp_DW.Buffer1_outBufPtrIdx < 0) {
        TpLockInAmp_DW.Buffer1_outBufPtrIdx += 16;
      }

      TpLockInAmp_DW.Buffer1_bufferLength = 0;
    }

    offsetFromMemBase = 0;
    if (TpLockInAmp_DW.Buffer1_outBufPtrIdx < 0) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx += 16;
    }

    nSampsAtBot = 16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx;
    nSamps = 8;
    if (16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx <= 8) {
      for (i = 0; i < 16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx; i++) {
        rtb_Buffer1[i] =
          TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_outBufPtrIdx + i];
      }

      offsetFromMemBase = 16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx;
      TpLockInAmp_DW.Buffer1_outBufPtrIdx = 0;
      nSamps = 8 - nSampsAtBot;
    }

    for (i = 0; i < nSamps; i++) {
      rtb_Buffer1[offsetFromMemBase + i] =
        TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_outBufPtrIdx + i];
    }

    TpLockInAmp_DW.Buffer1_outBufPtrIdx += nSamps;

    /* MATLABSystem: '<S1>/CIC Compensation Decimator1' incorporates:
     *  Buffer: '<S1>/Buffer1'
     */
    obj = TpLockInAmp_DW.obj_l.pFIRDecimator;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->isSetupComplete = true;

      /* System object Initialization function: dsp.FIRDecimator */
      obj->cSFunObject.W2_CoeffIdx = 570;
      obj->cSFunObject.W0_PhaseIdx = 3;
      obj->cSFunObject.W4_TapDelayIndex = 567;
      obj->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 756; i++) {
        obj->cSFunObject.W3_StatesBuff[i] = 0.0F;
      }
    }

    obj_0 = &obj->cSFunObject;

    /* System object Outputs function: dsp.FIRDecimator */
    nSamps = 0;
    offsetFromMemBase = obj->cSFunObject.W4_TapDelayIndex;
    nSampsAtBot = obj->cSFunObject.W0_PhaseIdx;
    cffIdx = obj->cSFunObject.W2_CoeffIdx;
    outBufIdx = 0;
    maxWindow = (nSampsAtBot + 1) * 189 - 189;
    for (i = 0; i < 8; i++) {
      obj_0->W1_Sums += rtb_Buffer1[nSamps] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
      for (jIdx = offsetFromMemBase + 1; jIdx < maxWindow + 189; jIdx++) {
        obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
        cffIdx++;
      }

      for (jIdx = maxWindow; jIdx <= offsetFromMemBase; jIdx++) {
        obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
        cffIdx++;
      }

      obj_0->W3_StatesBuff[offsetFromMemBase] = rtb_Buffer1[nSamps];
      nSamps++;
      offsetFromMemBase += 189;
      if (offsetFromMemBase >= 756) {
        offsetFromMemBase -= 756;
      }

      nSampsAtBot++;
      if (nSampsAtBot < 4) {
        maxWindow += 189;
      } else {
        obj_0->O0_Y0[outBufIdx] = obj_0->W1_Sums;
        outBufIdx++;
        obj_0->W1_Sums = 0.0F;
        nSampsAtBot = 0;
        cffIdx = 0;
        offsetFromMemBase--;
        if (offsetFromMemBase < 0) {
          offsetFromMemBase += 189;
        }

        maxWindow = 0;
      }
    }

    obj->cSFunObject.W4_TapDelayIndex = offsetFromMemBase;
    obj->cSFunObject.W2_CoeffIdx = cffIdx;
    obj->cSFunObject.W0_PhaseIdx = nSampsAtBot;

    /* Unbuffer: '<S1>/Unbuffer2' incorporates:
     *  MATLABSystem: '<S1>/CIC Compensation Decimator1'
     */
    TpLockInAmp_DW.Unbuffer2_CircBuff[0] = obj->cSFunObject.O0_Y0[0];
    TpLockInAmp_DW.Unbuffer2_CircBuff[1] = obj->cSFunObject.O0_Y0[1];
    TpLockInAmp_DW.Unbuffer2_memIdx = 0;
  }

  /* End of Buffer: '<S1>/Buffer1' */

  /* Unbuffer: '<S1>/Unbuffer2' */
  if (TpLockInAmp_M->Timing.TaskCounters.TID[1] == 0) {
    rtb_SineWave2 =
      TpLockInAmp_DW.Unbuffer2_CircBuff[TpLockInAmp_DW.Unbuffer2_memIdx];
    if (TpLockInAmp_DW.Unbuffer2_memIdx < 1) {
      TpLockInAmp_DW.Unbuffer2_memIdx++;
    }

    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Product: '<S1>/Product2'
     *  Product: '<S1>/Product3'
     *  Sum: '<S1>/Add1'
     */
    signal_amp = sqrtf(rtb_Unbuffer1 * rtb_Unbuffer1 + rtb_SineWave2 *
                       rtb_SineWave2) * 2.0F;

    /* Trigonometry: '<S1>/Trigonometric Function' incorporates:
     *  Product: '<S1>/Divide'
     */
    signal_pha = atanf(rtb_Unbuffer1 / rtb_SineWave2);
  }

  rate_scheduler();
}

/* Model initialize function */
void TpLockInAmp_initialize(void)
{
  {
    static const real32_T tmp[760] = { 7.842983E-6F, 9.89838E-6F, 1.22808187E-5F,
      1.50236265E-5F, 1.8160019E-5F, 2.17250181E-5F, 2.57548454E-5F,
      3.02876288E-5F, 3.53638898E-5F, 4.10247849E-5F, 4.73165819E-5F,
      5.42784874E-5F, 6.19532075E-5F, 7.03835E-5F, 7.96129316E-5F,
      8.96898709E-5F, 0.000100665391F, 0.000112584785F, 0.000125491759F,
      0.000139425625F, 0.000154432069F, 0.000170564934F, 0.000187872123F,
      0.0002063828F, 0.00022612825F, 0.000247168151F, 0.000269550452F,
      0.000293258257F, 0.000318397069F, 0.000344880886F, 0.000372928596F,
      0.000402399688F, 0.000433366746F, 0.00046584729F, 0.000499855727F,
      0.000535401574F, 0.000572489749F, 0.000611119962F, 0.000651289243F,
      0.000692989735F, 0.000736214046F, 0.000780938542F, 0.000827140932F,
      0.000874792866F, 0.000923860876F, 0.000974308467F, 0.00102608697F,
      0.0010791471F, 0.0011334361F, 0.0011888945F, 0.0012454493F, 0.00130303425F,
      0.00136157649F, 0.00142098905F, 0.00148118485F, 0.00154208217F,
      0.00160356786F, 0.00166556472F, 0.00172794051F, 0.00179060397F,
      0.00185346277F, 0.00191636744F, 0.00197921414F, 0.00204188307F,
      0.00210425025F, 0.00216619181F, 0.00222758157F, 0.00228829309F,
      0.00234819716F, 0.00240716361F, 0.00246507069F, 0.00252178661F,
      0.00257718703F, 0.00263114204F, 0.00268353056F, 0.00273423432F,
      0.00278313132F, 0.00283010793F, 0.00287505309F, 0.00291785854F,
      0.00295841927F, 0.00299663935F, 0.00303242449F, 0.00306568481F,
      0.00309634185F, 0.00312431343F, 0.00314953853F, 0.00317194359F,
      0.00319147715F, 0.00320809032F, 0.00322174886F, 0.00323240412F,
      0.00324003468F, 0.00324462052F, 0.00324615068F, 0.00324462052F,
      0.00324003468F, 0.00323240412F, 0.00322174886F, 0.00320809032F,
      0.00319147715F, 0.00317194359F, 0.00314953853F, 0.00312431343F,
      0.00309634185F, 0.00306568481F, 0.00303242449F, 0.00299663935F,
      0.00295841927F, 0.00291785854F, 0.00287505309F, 0.00283010793F,
      0.00278313132F, 0.00273423432F, 0.00268353056F, 0.00263114204F,
      0.00257718703F, 0.00252178661F, 0.00246507069F, 0.00240716361F,
      0.00234819716F, 0.00228829309F, 0.00222758157F, 0.00216619181F,
      0.00210425025F, 0.00204188307F, 0.00197921414F, 0.00191636744F,
      0.00185346277F, 0.00179060397F, 0.00172794051F, 0.00166556472F,
      0.00160356786F, 0.00154208217F, 0.00148118485F, 0.00142098905F,
      0.00136157649F, 0.00130303425F, 0.0012454493F, 0.0011888945F,
      0.0011334361F, 0.0010791471F, 0.00102608697F, 0.000974308467F,
      0.000923860876F, 0.000874792866F, 0.000827140932F, 0.000780938542F,
      0.000736214046F, 0.000692989735F, 0.000651289243F, 0.000611119962F,
      0.000572489749F, 0.000535401574F, 0.000499855727F, 0.00046584729F,
      0.000433366746F, 0.000402399688F, 0.000372928596F, 0.000344880886F,
      0.000318397069F, 0.000293258257F, 0.000269550452F, 0.000247168151F,
      0.00022612825F, 0.0002063828F, 0.000187872123F, 0.000170564934F,
      0.000154432069F, 0.000139425625F, 0.000125491759F, 0.000112584785F,
      0.000100665391F, 8.96898709E-5F, 7.96129316E-5F, 7.03835E-5F,
      6.19532075E-5F, 5.42784874E-5F, 4.73165819E-5F, 4.10247849E-5F,
      3.53638898E-5F, 3.02876288E-5F, 2.57548454E-5F, 2.17250181E-5F,
      1.8160019E-5F, 1.50236265E-5F, 1.22808187E-5F, 9.89838E-6F, 7.842983E-6F,
      0.0F, 7.37548316E-6F, 9.35404569E-6F, 1.16516E-5F, 1.43012085E-5F,
      1.7336024E-5F, 2.07903504E-5F, 2.47006064E-5F, 2.91038068E-5F,
      3.40404549E-5F, 3.95525749E-5F, 4.56811176E-5F, 5.2471205E-5F,
      5.99645391E-5F, 6.82018726E-5F, 7.7226774E-5F, 8.70873264E-5F,
      9.78334429E-5F, 0.000109512344F, 0.000122169338F, 0.000135841983F,
      0.000150576801F, 0.000166422134F, 0.000183432247F, 0.000201639836F,
      0.000221072274F, 0.000241781832F, 0.000263828406F, 0.000287204341F,
      0.000311967655F, 0.000338144193F, 0.000365791057F, 0.000394891336F,
      0.000425482547F, 0.000457583286F, 0.000491208513F, 0.000526369375F,
      0.00056307175F, 0.000601316744F, 0.000641101564F, 0.000682422891F,
      0.000725264836F, 0.000769616745F, 0.000815452775F, 0.00086274452F,
      0.00091146148F, 0.000961568847F, 0.00101301854F, 0.00106576364F,
      0.00111975055F, 0.00117492303F, 0.001231211F, 0.00128854427F,
      0.00134685449F, 0.00140605844F, 0.0014660653F, 0.00152679684F,
      0.00158814481F, 0.00165002258F, 0.00171231211F, 0.00177492818F,
      0.00183774065F, 0.0019006409F, 0.0019635132F, 0.00202623801F,
      0.00208869227F, 0.00215075188F, 0.00221229158F, 0.00227318448F,
      0.00233330275F, 0.00239252F, 0.00245069969F, 0.00250772596F,
      0.00256346702F, 0.00261779339F, 0.00267058611F, 0.00272172131F,
      0.00277108164F, 0.00281854859F, 0.00286401249F, 0.00290736253F,
      0.0029484944F, 0.00298730773F, 0.00302371057F, 0.00305760955F,
      0.00308892527F, 0.00311757415F, 0.00314349332F, 0.00316660665F,
      0.00318686664F, 0.00320421858F, 0.00321861473F, 0.0032300218F,
      0.00323841069F, 0.00324375904F, 0.00324605359F, 0.00324528851F,
      0.00324146589F, 0.00323459483F, 0.0032246937F, 0.00321179163F,
      0.00319590722F, 0.00317709963F, 0.003155404F, 0.00313087902F,
      0.00310358778F, 0.00307359523F, 0.00304097799F, 0.0030058166F,
      0.00296819629F, 0.00292821229F, 0.00288595865F, 0.00284153805F,
      0.00279505854F, 0.00274663162F, 0.00269636745F, 0.00264438987F,
      0.00259081391F, 0.00253576413F, 0.00247936719F, 0.00242174743F,
      0.00236303126F, 0.00230334862F, 0.00224282686F, 0.00218159473F,
      0.00211977912F, 0.0020575067F, 0.00199490157F, 0.00193208805F,
      0.00186918664F, 0.00180632656F, 0.00174359139F, 0.0016811263F,
      0.00161902129F, 0.00155740115F, 0.00149634609F, 0.00143596623F,
      0.00137635064F, 0.00131758209F, 0.00125975092F, 0.00120293221F,
      0.00114719348F, 0.00109260518F, 0.00103923306F, 0.000987128587F,
      0.00093634415F, 0.000886927F, 0.00083891768F, 0.000792351144F,
      0.000747255574F, 0.000703654776F, 0.000661570637F, 0.000621016952F,
      0.000582001696F, 0.000544527662F, 0.000508596597F, 0.000474204397F,
      0.000441343203F, 0.000409999309F, 0.000380156096F, 0.000351843046F,
      0.000324911147F, 0.000299399078F, 0.000275352213F, 0.000252636557F,
      0.000231262791F, 0.000211200502F, 0.000192384992F, 0.000174779168F,
      0.000158356925F, 0.000143074052F, 0.000128876811F, 0.000115716823F,
      0.000103553728F, 9.23462794E-5F, 8.20496571E-5F, 7.26127473E-5F,
      6.39872305E-5F, 5.61282759E-5F, 4.89920785E-5F, 4.25374128E-5F,
      3.67217726E-5F, 3.15031139E-5F, 2.68381391E-5F, 2.2686334E-5F,
      1.90084156E-5F, 1.57683371E-5F, 1.29303262E-5F, 1.04609862E-5F,
      8.32681599E-6F, 5.33248167E-5F, 6.92832054E-6F, 8.83179837E-6F,
      1.10467363E-5F, 1.36051867E-5F, 1.65405363E-5F, 1.98865546E-5F,
      2.36795386E-5F, 2.79557498E-5F, 3.27552734E-5F, 3.81182872E-5F,
      4.40903641E-5F, 5.07109071E-5F, 5.80248634E-5F, 6.60715596E-5F,
      7.4895157E-5F, 8.45424147E-5F, 9.50621E-5F, 0.000106503845F,
      0.000118912925F, 0.000132327637F, 0.000146791179F, 0.000162354612F,
      0.000179069626F, 0.000196975656F, 0.000216098284F, 0.000236481865F,
      0.000258191692F, 0.000281238055F, 0.000305635971F, 0.000331498595F,
      0.000358734367F, 0.000387478445F, 0.000417695119F, 0.000449416984F,
      0.000482659729F, 0.00051743607F, 0.000553752703F, 0.000591612305F,
      0.000631012372F, 0.000671948772F, 0.000714414287F, 0.000758391F,
      0.000803857809F, 0.000850787503F, 0.000899151666F, 0.000948915433F,
      0.00100003381F, 0.00105246052F, 0.0011061416F, 0.00116102386F,
      0.00121703884F, 0.00127411773F, 0.00133219082F, 0.00139118009F,
      0.0014509937F, 0.00151155237F, 0.00157275738F, 0.00163450849F,
      0.00169670989F, 0.00175926043F, 0.00182202144F, 0.00188491505F,
      0.00194780563F, 0.00201057852F, 0.00207311194F, 0.00213528192F,
      0.00219696364F, 0.00225803F, 0.00231835409F, 0.00237780577F,
      0.00243626139F, 0.00249358756F, 0.00254966016F, 0.00260435161F,
      0.00265754038F, 0.0027091F, 0.00275891623F, 0.00280686654F, 0.00285284198F,
      0.00289673F, 0.00293842587F, 0.0029778278F, 0.00301484251F, 0.00304937502F,
      0.0030813443F, 0.00311066699F, 0.00313727465F, 0.00316109508F,
      0.00318207615F, 0.00320015894F, 0.0032152934F, 0.00322745321F,
      0.00323659903F, 0.00324270898F, 0.0032457679F, 0.0032457679F,
      0.00324270898F, 0.00323659903F, 0.00322745321F, 0.0032152934F,
      0.00320015894F, 0.00318207615F, 0.00316109508F, 0.00313727465F,
      0.00311066699F, 0.0030813443F, 0.00304937502F, 0.00301484251F,
      0.0029778278F, 0.00293842587F, 0.00289673F, 0.00285284198F, 0.00280686654F,
      0.00275891623F, 0.0027091F, 0.00265754038F, 0.00260435161F, 0.00254966016F,
      0.00249358756F, 0.00243626139F, 0.00237780577F, 0.00231835409F,
      0.00225803F, 0.00219696364F, 0.00213528192F, 0.00207311194F,
      0.00201057852F, 0.00194780563F, 0.00188491505F, 0.00182202144F,
      0.00175926043F, 0.00169670989F, 0.00163450849F, 0.00157275738F,
      0.00151155237F, 0.0014509937F, 0.00139118009F, 0.00133219082F,
      0.00127411773F, 0.00121703884F, 0.00116102386F, 0.0011061416F,
      0.00105246052F, 0.00100003381F, 0.000948915433F, 0.000899151666F,
      0.000850787503F, 0.000803857809F, 0.000758391F, 0.000714414287F,
      0.000671948772F, 0.000631012372F, 0.000591612305F, 0.000553752703F,
      0.00051743607F, 0.000482659729F, 0.000449416984F, 0.000417695119F,
      0.000387478445F, 0.000358734367F, 0.000331498595F, 0.000305635971F,
      0.000281238055F, 0.000258191692F, 0.000236481865F, 0.000216098284F,
      0.000196975656F, 0.000179069626F, 0.000162354612F, 0.000146791179F,
      0.000132327637F, 0.000118912925F, 0.000106503845F, 9.50621E-5F,
      8.45424147E-5F, 7.4895157E-5F, 6.60715596E-5F, 5.80248634E-5F,
      5.07109071E-5F, 4.40903641E-5F, 3.81182872E-5F, 3.27552734E-5F,
      2.79557498E-5F, 2.36795386E-5F, 1.98865546E-5F, 1.65405363E-5F,
      1.36051867E-5F, 1.10467363E-5F, 8.83179837E-6F, 6.92832054E-6F,
      5.33248167E-5F, 8.32681599E-6F, 1.04609862E-5F, 1.29303262E-5F,
      1.57683371E-5F, 1.90084156E-5F, 2.2686334E-5F, 2.68381391E-5F,
      3.15031139E-5F, 3.67217726E-5F, 4.25374128E-5F, 4.89920785E-5F,
      5.61282759E-5F, 6.39872305E-5F, 7.26127473E-5F, 8.20496571E-5F,
      9.23462794E-5F, 0.000103553728F, 0.000115716823F, 0.000128876811F,
      0.000143074052F, 0.000158356925F, 0.000174779168F, 0.000192384992F,
      0.000211200502F, 0.000231262791F, 0.000252636557F, 0.000275352213F,
      0.000299399078F, 0.000324911147F, 0.000351843046F, 0.000380156096F,
      0.000409999309F, 0.000441343203F, 0.000474204397F, 0.000508596597F,
      0.000544527662F, 0.000582001696F, 0.000621016952F, 0.000661570637F,
      0.000703654776F, 0.000747255574F, 0.000792351144F, 0.00083891768F,
      0.000886927F, 0.00093634415F, 0.000987128587F, 0.00103923306F,
      0.00109260518F, 0.00114719348F, 0.00120293221F, 0.00125975092F,
      0.00131758209F, 0.00137635064F, 0.00143596623F, 0.00149634609F,
      0.00155740115F, 0.00161902129F, 0.0016811263F, 0.00174359139F,
      0.00180632656F, 0.00186918664F, 0.00193208805F, 0.00199490157F,
      0.0020575067F, 0.00211977912F, 0.00218159473F, 0.00224282686F,
      0.00230334862F, 0.00236303126F, 0.00242174743F, 0.00247936719F,
      0.00253576413F, 0.00259081391F, 0.00264438987F, 0.00269636745F,
      0.00274663162F, 0.00279505854F, 0.00284153805F, 0.00288595865F,
      0.00292821229F, 0.00296819629F, 0.0030058166F, 0.00304097799F,
      0.00307359523F, 0.00310358778F, 0.00313087902F, 0.003155404F,
      0.00317709963F, 0.00319590722F, 0.00321179163F, 0.0032246937F,
      0.00323459483F, 0.00324146589F, 0.00324528851F, 0.00324605359F,
      0.00324375904F, 0.00323841069F, 0.0032300218F, 0.00321861473F,
      0.00320421858F, 0.00318686664F, 0.00316660665F, 0.00314349332F,
      0.00311757415F, 0.00308892527F, 0.00305760955F, 0.00302371057F,
      0.00298730773F, 0.0029484944F, 0.00290736253F, 0.00286401249F,
      0.00281854859F, 0.00277108164F, 0.00272172131F, 0.00267058611F,
      0.00261779339F, 0.00256346702F, 0.00250772596F, 0.00245069969F,
      0.00239252F, 0.00233330275F, 0.00227318448F, 0.00221229158F,
      0.00215075188F, 0.00208869227F, 0.00202623801F, 0.0019635132F,
      0.0019006409F, 0.00183774065F, 0.00177492818F, 0.00171231211F,
      0.00165002258F, 0.00158814481F, 0.00152679684F, 0.0014660653F,
      0.00140605844F, 0.00134685449F, 0.00128854427F, 0.001231211F,
      0.00117492303F, 0.00111975055F, 0.00106576364F, 0.00101301854F,
      0.000961568847F, 0.00091146148F, 0.00086274452F, 0.000815452775F,
      0.000769616745F, 0.000725264836F, 0.000682422891F, 0.000641101564F,
      0.000601316744F, 0.00056307175F, 0.000526369375F, 0.000491208513F,
      0.000457583286F, 0.000425482547F, 0.000394891336F, 0.000365791057F,
      0.000338144193F, 0.000311967655F, 0.000287204341F, 0.000263828406F,
      0.000241781832F, 0.000221072274F, 0.000201639836F, 0.000183432247F,
      0.000166422134F, 0.000150576801F, 0.000135841983F, 0.000122169338F,
      0.000109512344F, 9.78334429E-5F, 8.70873264E-5F, 7.7226774E-5F,
      6.82018726E-5F, 5.99645391E-5F, 5.2471205E-5F, 4.56811176E-5F,
      3.95525749E-5F, 3.40404549E-5F, 2.91038068E-5F, 2.47006064E-5F,
      2.07903504E-5F, 1.7336024E-5F, 1.43012085E-5F, 1.16516E-5F, 9.35404569E-6F,
      7.37548316E-6F };

    b_dspcodegen_FIRDecimator_TpL_T *iobj_0;
    dsp_CICCompensationDecimato_f_T *obj_0;
    dsp_CICCompensationDecimator__T *obj;
    int32_T i;
    boolean_T wasTunablePropsChanged;

    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */
    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */

    /* InitializeConditions for Buffer: '<S1>/Buffer' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */
    TpLockInAmp_DW.Buffer_inBufPtrIdx = 8;
    TpLockInAmp_DW.Buffer_bufferLength = 8;

    /* InitializeConditions for S-Function (sdspsine2): '<S1>/Sine Wave2' */
    /* This code only executes when block is re-enabled in an
       enabled subsystem when the enabled subsystem states on
       re-enabling are set to 'Reset' */
    /* Reset to time zero on re-enable */
    /* Trigonometric mode: compute accumulated
       normalized trig fcn argument for each channel */
    /* Keep normalized value in range [0 2*pi) */
    TpLockInAmp_DW.SineWave2_AccFreqNorm = 1.57079637F;

    /* InitializeConditions for Buffer: '<S1>/Buffer1' */
    TpLockInAmp_DW.Buffer1_inBufPtrIdx = 8;
    TpLockInAmp_DW.Buffer1_bufferLength = 8;

    /* Start for MATLABSystem: '<S1>/CIC Compensation Decimator' */
    TpLockInAmp_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj.isInitialized = 0;
    TpLockInAmp_DW.obj.matlabCodegenIsDeleted = false;
    obj = &TpLockInAmp_DW.obj;
    TpLockInAmp_DW.obj.isSetupComplete = false;
    TpLockInAmp_DW.obj.isInitialized = 1;
    iobj_0 = &TpLockInAmp_DW.obj._pobj0;
    obj->_pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRDecimator */
    iobj_0->cSFunObject.P0_IC = 0.0F;
    for (i = 0; i < 760; i++) {
      iobj_0->cSFunObject.P1_FILT[i] = tmp[i];
    }

    obj->_pobj0.matlabCodegenIsDeleted = false;
    TpLockInAmp_DW.obj.pFIRDecimator = &obj->_pobj0;
    iobj_0 = TpLockInAmp_DW.obj.pFIRDecimator;
    iobj_0->isSetupComplete = false;
    iobj_0->isInitialized = 1;
    iobj_0->isSetupComplete = true;
    TpLockInAmp_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S1>/CIC Compensation Decimator' */

    /* InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator' */
    iobj_0 = TpLockInAmp_DW.obj.pFIRDecimator;
    if (iobj_0->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRDecimator */
      iobj_0->cSFunObject.W2_CoeffIdx = 570;
      iobj_0->cSFunObject.W0_PhaseIdx = 3;
      iobj_0->cSFunObject.W4_TapDelayIndex = 567;
      iobj_0->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 756; i++) {
        iobj_0->cSFunObject.W3_StatesBuff[i] = 0.0F;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator' */

    /* Start for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
    TpLockInAmp_DW.obj_l._pobj0.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj_l.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj_l.isInitialized = 0;
    TpLockInAmp_DW.obj_l.TunablePropsChanged = false;
    TpLockInAmp_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &TpLockInAmp_DW.obj_l;
    TpLockInAmp_DW.obj_l.isSetupComplete = false;
    TpLockInAmp_DW.obj_l.isInitialized = 1;
    wasTunablePropsChanged = TpLockInAmp_DW.obj_l.TunablePropsChanged;
    TpLockInAmp_DW.obj_l.TunablePropsChanged = wasTunablePropsChanged;
    iobj_0 = &TpLockInAmp_DW.obj_l._pobj0;
    obj_0->_pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRDecimator */
    iobj_0->cSFunObject.P0_IC = 0.0F;
    for (i = 0; i < 760; i++) {
      iobj_0->cSFunObject.P1_FILT[i] = tmp[i];
    }

    obj_0->_pobj0.matlabCodegenIsDeleted = false;
    TpLockInAmp_DW.obj_l.pFIRDecimator = &obj_0->_pobj0;
    iobj_0 = TpLockInAmp_DW.obj_l.pFIRDecimator;
    iobj_0->isSetupComplete = false;
    iobj_0->isInitialized = 1;
    iobj_0->isSetupComplete = true;
    TpLockInAmp_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S1>/CIC Compensation Decimator1' */

    /* InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
    iobj_0 = TpLockInAmp_DW.obj_l.pFIRDecimator;
    if (iobj_0->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRDecimator */
      iobj_0->cSFunObject.W2_CoeffIdx = 570;
      iobj_0->cSFunObject.W0_PhaseIdx = 3;
      iobj_0->cSFunObject.W4_TapDelayIndex = 567;
      iobj_0->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 756; i++) {
        iobj_0->cSFunObject.W3_StatesBuff[i] = 0.0F;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
  }
}

/* Model terminate function */
void TpLockInAmp_terminate(void)
{
  b_dspcodegen_FIRDecimator_TpL_T *obj;

  /* Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator' */
  if (!TpLockInAmp_DW.obj.matlabCodegenIsDeleted) {
    TpLockInAmp_DW.obj.matlabCodegenIsDeleted = true;
    if ((TpLockInAmp_DW.obj.isInitialized == 1) &&
        TpLockInAmp_DW.obj.isSetupComplete) {
      obj = TpLockInAmp_DW.obj.pFIRDecimator;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }
    }
  }

  obj = &TpLockInAmp_DW.obj._pobj0;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator' */

  /* Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
  if (!TpLockInAmp_DW.obj_l.matlabCodegenIsDeleted) {
    TpLockInAmp_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((TpLockInAmp_DW.obj_l.isInitialized == 1) &&
        TpLockInAmp_DW.obj_l.isSetupComplete) {
      obj = TpLockInAmp_DW.obj_l.pFIRDecimator;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }
    }
  }

  obj = &TpLockInAmp_DW.obj_l._pobj0;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
