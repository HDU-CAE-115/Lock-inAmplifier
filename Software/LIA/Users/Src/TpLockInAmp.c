/*
 * File: TpLockInAmp.c
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Feb 21 19:45:56 2022
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
}

/* Model step function */
void TpLockInAmp_step(void)
{
  b_dsp_FIRDecimator_0_TpLockIn_T *obj_0;
  b_dspcodegen_FIRDecimator_TpL_T *obj;
  int32_T i;
  int32_T jIdx;
  int32_T nSamps;
  int32_T nSampsAtBot;
  int32_T offsetFromMemBase;
  real32_T rtb_Buffer[4];
  real32_T rtb_Buffer1[4];
  real32_T rtb_Product2;
  real32_T rtb_SineWave2;

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
  nSamps = 8;
  offsetFromMemBase = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  if (8 - TpLockInAmp_DW.Buffer_inBufPtrIdx <= 1) {
    for (i = 0; i < 8 - TpLockInAmp_DW.Buffer_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_inBufPtrIdx + i] =
        rtb_SineWave2;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 7; i++) {
    TpLockInAmp_DW.Buffer_CircBuf[offsetFromMemBase + i] = rtb_SineWave2;
  }

  TpLockInAmp_DW.Buffer_inBufPtrIdx++;
  if (TpLockInAmp_DW.Buffer_inBufPtrIdx >= 8) {
    TpLockInAmp_DW.Buffer_inBufPtrIdx -= 8;
  }

  TpLockInAmp_DW.Buffer_bufferLength++;
  if (TpLockInAmp_DW.Buffer_bufferLength > 8) {
    TpLockInAmp_DW.Buffer_outBufPtrIdx = (TpLockInAmp_DW.Buffer_outBufPtrIdx +
      TpLockInAmp_DW.Buffer_bufferLength) - 8;
    if (TpLockInAmp_DW.Buffer_outBufPtrIdx > 8) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx -= 8;
    }

    TpLockInAmp_DW.Buffer_bufferLength = 8;
  }

  if (TpLockInAmp_M->Timing.TaskCounters.TID[1] == 0) {
    TpLockInAmp_DW.Buffer_bufferLength -= 4;
    if (TpLockInAmp_DW.Buffer_bufferLength < 0) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx += TpLockInAmp_DW.Buffer_bufferLength;
      if (TpLockInAmp_DW.Buffer_outBufPtrIdx < 0) {
        TpLockInAmp_DW.Buffer_outBufPtrIdx += 8;
      }

      TpLockInAmp_DW.Buffer_bufferLength = 0;
    }

    offsetFromMemBase = 0;
    if (TpLockInAmp_DW.Buffer_outBufPtrIdx < 0) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx += 8;
    }

    nSampsAtBot = 8 - TpLockInAmp_DW.Buffer_outBufPtrIdx;
    nSamps = 4;
    if (8 - TpLockInAmp_DW.Buffer_outBufPtrIdx <= 4) {
      for (i = 0; i < 8 - TpLockInAmp_DW.Buffer_outBufPtrIdx; i++) {
        rtb_Buffer[i] =
          TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_outBufPtrIdx + i];
      }

      offsetFromMemBase = 8 - TpLockInAmp_DW.Buffer_outBufPtrIdx;
      TpLockInAmp_DW.Buffer_outBufPtrIdx = 0;
      nSamps = 4 - nSampsAtBot;
    }

    for (i = 0; i < nSamps; i++) {
      rtb_Buffer[offsetFromMemBase + i] =
        TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_outBufPtrIdx + i];
    }

    TpLockInAmp_DW.Buffer_outBufPtrIdx += nSamps;

    /* MATLABSystem: '<S1>/CIC Compensation Decimator' incorporates:
     *  Buffer: '<S1>/Buffer'
     */
    obj = TpLockInAmp_DW.obj_b.pFIRDecimator;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->isSetupComplete = true;

      /* System object Initialization function: dsp.FIRDecimator */
      obj->cSFunObject.W2_CoeffIdx = 468;
      obj->cSFunObject.W0_PhaseIdx = 3;
      obj->cSFunObject.W4_TapDelayIndex = 465;
      obj->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 620; i++) {
        obj->cSFunObject.W3_StatesBuff[i] = 0.0F;
      }
    }

    obj_0 = &obj->cSFunObject;

    /* System object Outputs function: dsp.FIRDecimator */
    i = obj->cSFunObject.W4_TapDelayIndex;
    nSamps = obj->cSFunObject.W0_PhaseIdx;
    offsetFromMemBase = obj->cSFunObject.W2_CoeffIdx;
    nSampsAtBot = (nSamps + 1) * 155 - 155;
    obj->cSFunObject.W1_Sums += rtb_Buffer[0] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer[0];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps < 4) {
      nSampsAtBot += 155;
    } else {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }

      nSampsAtBot = 0;
    }

    obj->cSFunObject.W1_Sums += rtb_Buffer[1] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer[1];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps < 4) {
      nSampsAtBot += 155;
    } else {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }

      nSampsAtBot = 0;
    }

    obj->cSFunObject.W1_Sums += rtb_Buffer[2] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer[2];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps < 4) {
      nSampsAtBot += 155;
    } else {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }

      nSampsAtBot = 0;
    }

    obj->cSFunObject.W1_Sums += rtb_Buffer[3] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer[3];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps >= 4) {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }
    }

    obj->cSFunObject.W4_TapDelayIndex = i;
    obj->cSFunObject.W2_CoeffIdx = offsetFromMemBase;
    obj->cSFunObject.W0_PhaseIdx = nSamps;
    rtb_SineWave2 = obj->cSFunObject.O0_Y0;

    /* Product: '<S1>/Product2' incorporates:
     *  MATLABSystem: '<S1>/CIC Compensation Decimator'
     */
    rtb_Product2 = rtb_SineWave2 * rtb_SineWave2;
  }

  /* End of Buffer: '<S1>/Buffer' */

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
  nSamps = 8;
  offsetFromMemBase = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  if (8 - TpLockInAmp_DW.Buffer1_inBufPtrIdx <= 1) {
    for (i = 0; i < 8 - TpLockInAmp_DW.Buffer1_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_inBufPtrIdx + i] =
        rtb_SineWave2;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 7; i++) {
    TpLockInAmp_DW.Buffer1_CircBuf[offsetFromMemBase + i] = rtb_SineWave2;
  }

  TpLockInAmp_DW.Buffer1_inBufPtrIdx++;
  if (TpLockInAmp_DW.Buffer1_inBufPtrIdx >= 8) {
    TpLockInAmp_DW.Buffer1_inBufPtrIdx -= 8;
  }

  TpLockInAmp_DW.Buffer1_bufferLength++;
  if (TpLockInAmp_DW.Buffer1_bufferLength > 8) {
    TpLockInAmp_DW.Buffer1_outBufPtrIdx = (TpLockInAmp_DW.Buffer1_outBufPtrIdx +
      TpLockInAmp_DW.Buffer1_bufferLength) - 8;
    if (TpLockInAmp_DW.Buffer1_outBufPtrIdx > 8) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx -= 8;
    }

    TpLockInAmp_DW.Buffer1_bufferLength = 8;
  }

  if (TpLockInAmp_M->Timing.TaskCounters.TID[1] == 0) {
    TpLockInAmp_DW.Buffer1_bufferLength -= 4;
    if (TpLockInAmp_DW.Buffer1_bufferLength < 0) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx += TpLockInAmp_DW.Buffer1_bufferLength;
      if (TpLockInAmp_DW.Buffer1_outBufPtrIdx < 0) {
        TpLockInAmp_DW.Buffer1_outBufPtrIdx += 8;
      }

      TpLockInAmp_DW.Buffer1_bufferLength = 0;
    }

    offsetFromMemBase = 0;
    if (TpLockInAmp_DW.Buffer1_outBufPtrIdx < 0) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx += 8;
    }

    nSampsAtBot = 8 - TpLockInAmp_DW.Buffer1_outBufPtrIdx;
    nSamps = 4;
    if (8 - TpLockInAmp_DW.Buffer1_outBufPtrIdx <= 4) {
      for (i = 0; i < 8 - TpLockInAmp_DW.Buffer1_outBufPtrIdx; i++) {
        rtb_Buffer1[i] =
          TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_outBufPtrIdx + i];
      }

      offsetFromMemBase = 8 - TpLockInAmp_DW.Buffer1_outBufPtrIdx;
      TpLockInAmp_DW.Buffer1_outBufPtrIdx = 0;
      nSamps = 4 - nSampsAtBot;
    }

    for (i = 0; i < nSamps; i++) {
      rtb_Buffer1[offsetFromMemBase + i] =
        TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_outBufPtrIdx + i];
    }

    TpLockInAmp_DW.Buffer1_outBufPtrIdx += nSamps;

    /* MATLABSystem: '<S1>/CIC Compensation Decimator1' incorporates:
     *  Buffer: '<S1>/Buffer1'
     */
    obj = TpLockInAmp_DW.obj.pFIRDecimator;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->isSetupComplete = true;

      /* System object Initialization function: dsp.FIRDecimator */
      obj->cSFunObject.W2_CoeffIdx = 468;
      obj->cSFunObject.W0_PhaseIdx = 3;
      obj->cSFunObject.W4_TapDelayIndex = 465;
      obj->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 620; i++) {
        obj->cSFunObject.W3_StatesBuff[i] = 0.0F;
      }
    }

    obj_0 = &obj->cSFunObject;

    /* System object Outputs function: dsp.FIRDecimator */
    i = obj->cSFunObject.W4_TapDelayIndex;
    nSamps = obj->cSFunObject.W0_PhaseIdx;
    offsetFromMemBase = obj->cSFunObject.W2_CoeffIdx;
    nSampsAtBot = (nSamps + 1) * 155 - 155;
    obj->cSFunObject.W1_Sums += rtb_Buffer1[0] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer1[0];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps < 4) {
      nSampsAtBot += 155;
    } else {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }

      nSampsAtBot = 0;
    }

    obj->cSFunObject.W1_Sums += rtb_Buffer1[1] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer1[1];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps < 4) {
      nSampsAtBot += 155;
    } else {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }

      nSampsAtBot = 0;
    }

    obj->cSFunObject.W1_Sums += rtb_Buffer1[2] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer1[2];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps < 4) {
      nSampsAtBot += 155;
    } else {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }

      nSampsAtBot = 0;
    }

    obj->cSFunObject.W1_Sums += rtb_Buffer1[3] * obj->
      cSFunObject.P1_FILT[offsetFromMemBase];
    offsetFromMemBase++;
    for (jIdx = i + 1; jIdx < nSampsAtBot + 155; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    for (jIdx = nSampsAtBot; jIdx <= i; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->
        P1_FILT[offsetFromMemBase];
      offsetFromMemBase++;
    }

    obj->cSFunObject.W3_StatesBuff[i] = rtb_Buffer1[3];
    i += 155;
    if (i >= 620) {
      i -= 620;
    }

    nSamps++;
    if (nSamps >= 4) {
      obj->cSFunObject.O0_Y0 = obj->cSFunObject.W1_Sums;
      obj->cSFunObject.W1_Sums = 0.0F;
      nSamps = 0;
      offsetFromMemBase = 0;
      i--;
      if (i < 0) {
        i += 155;
      }
    }

    obj->cSFunObject.W4_TapDelayIndex = i;
    obj->cSFunObject.W2_CoeffIdx = offsetFromMemBase;
    obj->cSFunObject.W0_PhaseIdx = nSamps;
    rtb_SineWave2 = obj->cSFunObject.O0_Y0;

    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  MATLABSystem: '<S1>/CIC Compensation Decimator1'
     *  Product: '<S1>/Product3'
     *  Sum: '<S1>/Add1'
     */
    signal_amp = sqrtf(rtb_SineWave2 * rtb_SineWave2 + rtb_Product2) * 2.0F;
  }

  /* End of Buffer: '<S1>/Buffer1' */
  rate_scheduler();
}

/* Model initialize function */
void TpLockInAmp_initialize(void)
{
  {
    static const real32_T tmp[624] = { 2.69757862E-7F, 4.60730064E-7F,
      7.34964E-7F, 1.11698807E-6F, 1.63626009E-6F, 2.32778E-6F, 3.23267227E-6F,
      4.39875612E-6F, 5.88121338E-6F, 7.7431323E-6F, 1.00561065E-5F,
      1.29008449E-5F, 1.63675104E-5F, 2.05561573E-5F, 2.55771465E-5F,
      3.15513462E-5F, 3.86102802E-5F, 4.68962135E-5F, 5.6561712E-5F,
      6.77696153E-5F, 8.06926473E-5F, 9.55126961E-5F, 0.000112420035F,
      0.000131612207F, 0.000153293033F, 0.00017767126F, 0.000204958938F,
      0.000235369356F, 0.000269115641F, 0.000306408503F, 0.000347453722F,
      0.00039244967F, 0.000441585405F, 0.000495037646F, 0.000552967598F,
      0.000615519239F, 0.000682815793F, 0.000754956855F, 0.000832017045F,
      0.000914041186F, 0.00100104464F, 0.00109300786F, 0.00118987716F,
      0.00129156199F, 0.0013979316F, 0.00150881649F, 0.00162400596F,
      0.00174324785F, 0.00186624879F, 0.00199267361F, 0.00212214724F,
      0.00225425465F, 0.00238854322F, 0.00252452469F, 0.00266167754F,
      0.00279944926F, 0.00293726078F, 0.00307450932F, 0.00321057322F,
      0.00334481546F, 0.00347658829F, 0.00360523909F, 0.00373011455F,
      0.00385056646F, 0.00396595616F, 0.00407566037F, 0.00417907722F,
      0.00427563F, 0.0043647741F, 0.00444599846F, 0.00451883394F, 0.00458285538F,
      0.00463768654F, 0.00468300236F, 0.00471853279F, 0.00474406499F,
      0.00475944625F, 0.00476458389F, 0.00475944625F, 0.00474406499F,
      0.00471853279F, 0.00468300236F, 0.00463768654F, 0.00458285538F,
      0.00451883394F, 0.00444599846F, 0.0043647741F, 0.00427563F, 0.00417907722F,
      0.00407566037F, 0.00396595616F, 0.00385056646F, 0.00373011455F,
      0.00360523909F, 0.00347658829F, 0.00334481546F, 0.00321057322F,
      0.00307450932F, 0.00293726078F, 0.00279944926F, 0.00266167754F,
      0.00252452469F, 0.00238854322F, 0.00225425465F, 0.00212214724F,
      0.00199267361F, 0.00186624879F, 0.00174324785F, 0.00162400596F,
      0.00150881649F, 0.0013979316F, 0.00129156199F, 0.00118987716F,
      0.00109300786F, 0.00100104464F, 0.000914041186F, 0.000832017045F,
      0.000754956855F, 0.000682815793F, 0.000615519239F, 0.000552967598F,
      0.000495037646F, 0.000441585405F, 0.00039244967F, 0.000347453722F,
      0.000306408503F, 0.000269115641F, 0.000235369356F, 0.000204958938F,
      0.00017767126F, 0.000153293033F, 0.000131612207F, 0.000112420035F,
      9.55126961E-5F, 8.06926473E-5F, 6.77696153E-5F, 5.6561712E-5F,
      4.68962135E-5F, 3.86102802E-5F, 3.15513462E-5F, 2.55771465E-5F,
      2.05561573E-5F, 1.63675104E-5F, 1.29008449E-5F, 1.00561065E-5F,
      7.7431323E-6F, 5.88121338E-6F, 4.39875612E-6F, 3.23267227E-6F, 2.32778E-6F,
      1.63626009E-6F, 1.11698807E-6F, 7.34964E-7F, 4.60730064E-7F,
      2.69757862E-7F, 0.0F, 2.32551812E-7F, 4.06029244E-7F, 6.57319902E-7F,
      1.0098446E-6F, 1.49174366E-6F, 2.13660314E-6F, 2.98393115E-6F,
      4.07985135E-6F, 5.47762875E-6F, 7.23829817E-6F, 9.43130817E-6F,
      1.21350322E-5F, 1.54372265E-5F, 1.94354325E-5F, 2.42374117E-5F,
      2.99614076E-5F, 3.67362627E-5F, 4.47015336E-5F, 5.40072615E-5F,
      6.48137429E-5F, 7.72912754E-5F, 9.16195568E-5F, 0.000107986816F,
      0.0001265889F, 0.000147628147F, 0.000171312262F, 0.000197852612F,
      0.00022746234F, 0.000260354776F, 0.000296741433F, 0.000336829602F,
      0.000380819751F, 0.00042890344F, 0.000481260824F, 0.000538057182F,
      0.000599440886F, 0.000665540923F, 0.000736462884F, 0.000812287792F,
      0.000893068442F, 0.000978827477F, 0.00106955413F, 0.00116520422F,
      0.0012656959F, 0.00137090858F, 0.00148068275F, 0.00159481808F,
      0.00171307276F, 0.0018351638F, 0.00196076627F, 0.0020895151F,
      0.00222100504F, 0.00235479278F, 0.00249039871F, 0.00262730918F,
      0.00276497938F, 0.00290283654F, 0.00304028369F, 0.00317670312F,
      0.00331146084F, 0.00344391214F, 0.00357340486F, 0.00369928521F,
      0.00382090337F, 0.00393761741F, 0.00404880056F, 0.00415384443F,
      0.00425216602F, 0.00434321119F, 0.00442646118F, 0.00450143544F,
      0.00456769764F, 0.00462485896F, 0.00467258086F, 0.00471058F,
      0.00473862886F, 0.00475655869F, 0.00476426259F, 0.00476169307F,
      0.00474886689F, 0.00472586F, 0.00469281152F, 0.00464991899F, 0.0045974385F,
      0.0045356811F, 0.00446501095F, 0.00438584154F, 0.00429863157F,
      0.00420388114F, 0.00410212716F, 0.00399393914F, 0.0038799129F,
      0.00376066752F, 0.00363683747F, 0.00350906933F, 0.00337801548F,
      0.00324432971F, 0.00310866116F, 0.00297164964F, 0.00283392146F,
      0.00269608456F, 0.00255872426F, 0.00242239982F, 0.0022876407F,
      0.00215494423F, 0.00202477188F, 0.00189754798F, 0.00177365809F,
      0.00165344728F, 0.00153721939F, 0.00142523705F, 0.00131772109F,
      0.00121485209F, 0.00111676846F, 0.00102357194F, 0.000935325341F,
      0.000852056604F, 0.000773758395F, 0.000700393517F, 0.000631894218F,
      0.000568167F, 0.000509094447F, 0.000454537192F, 0.000404338352F,
      0.000358324731F, 0.000316310092F, 0.000278098218F, 0.000243484901F,
      0.000212260406F, 0.000184212127F, 0.000159126444F, 0.000136791F,
      0.000116995994F, 9.95362352E-5F, 8.42125E-5F, 7.08326115E-5F,
      5.92124888E-5F, 4.91770588E-5F, 4.05609717E-5F, 3.3208984E-5F,
      2.69763514E-5F, 2.17288052E-5F, 1.73428271E-5F, 1.37054503E-5F,
      1.07140777E-5F, 8.27608619E-6F, 6.30845943E-6F, 4.73737919E-6F,
      3.4976681E-6F, 2.53223357E-6F, 1.79148481E-6F, 1.23265045E-6F,
      8.19290335E-7F, 5.20585218E-7F, 3.10858837E-7F, 5.87492707E-7F,
      1.99018103E-7F, 3.56197546E-7F, 5.86010117E-7F, 9.10786071E-7F,
      1.3574105E-6F, 1.95807729E-6F, 2.75072398E-6F, 3.77979791E-6F,
      5.09669417E-6F, 6.76045738E-6F, 8.83842131E-6F, 1.14066088E-5F,
      1.45504146E-5F, 1.83649154E-5F, 2.29552788E-5F, 2.84371054E-5F,
      3.49365873E-5F, 4.25905819E-5F, 5.15465799E-5F, 6.19622951E-5F,
      7.40055693E-5F, 8.78538413E-5F, 0.000103693274F, 0.000121717909F,
      0.000142128585F, 0.000165131773F, 0.000190938066F, 0.000219760492F,
      0.000251812307F, 0.000287305767F, 0.000326449459F, 0.00036944577F,
      0.000416488707F, 0.000467761507F, 0.000523433497F, 0.000583657471F,
      0.000648567569F, 0.000718275493F, 0.000792868494F, 0.000872407F,
      0.000956920849F, 0.00104640867F, 0.00114083441F, 0.00124012481F,
      0.00134417077F, 0.00145282189F, 0.00156588794F, 0.00168313773F,
      0.00180429849F, 0.00192905578F, 0.00205705431F, 0.00218789908F,
      0.00232115597F, 0.00245635421F, 0.00259298855F, 0.00273052161F,
      0.00286838715F, 0.00300599379F, 0.00314272894F, 0.00327796233F,
      0.00341105112F, 0.00354134478F, 0.00366818951F, 0.00379093364F,
      0.00390893314F, 0.00402155705F, 0.00412819162F, 0.00422824686F,
      0.00432116119F, 0.00440640654F, 0.00448349258F, 0.00455197133F,
      0.0046114414F, 0.00466155214F, 0.00470200507F, 0.00473255944F,
      0.00475303177F, 0.00476329867F, 0.00476329867F, 0.00475303177F,
      0.00473255944F, 0.00470200507F, 0.00466155214F, 0.0046114414F,
      0.00455197133F, 0.00448349258F, 0.00440640654F, 0.00432116119F,
      0.00422824686F, 0.00412819162F, 0.00402155705F, 0.00390893314F,
      0.00379093364F, 0.00366818951F, 0.00354134478F, 0.00341105112F,
      0.00327796233F, 0.00314272894F, 0.00300599379F, 0.00286838715F,
      0.00273052161F, 0.00259298855F, 0.00245635421F, 0.00232115597F,
      0.00218789908F, 0.00205705431F, 0.00192905578F, 0.00180429849F,
      0.00168313773F, 0.00156588794F, 0.00145282189F, 0.00134417077F,
      0.00124012481F, 0.00114083441F, 0.00104640867F, 0.000956920849F,
      0.000872407F, 0.000792868494F, 0.000718275493F, 0.000648567569F,
      0.000583657471F, 0.000523433497F, 0.000467761507F, 0.000416488707F,
      0.00036944577F, 0.000326449459F, 0.000287305767F, 0.000251812307F,
      0.000219760492F, 0.000190938066F, 0.000165131773F, 0.000142128585F,
      0.000121717909F, 0.000103693274F, 8.78538413E-5F, 7.40055693E-5F,
      6.19622951E-5F, 5.15465799E-5F, 4.25905819E-5F, 3.49365873E-5F,
      2.84371054E-5F, 2.29552788E-5F, 1.83649154E-5F, 1.45504146E-5F,
      1.14066088E-5F, 8.83842131E-6F, 6.76045738E-6F, 5.09669417E-6F,
      3.77979791E-6F, 2.75072398E-6F, 1.95807729E-6F, 1.3574105E-6F,
      9.10786071E-7F, 5.86010117E-7F, 3.56197546E-7F, 1.99018103E-7F,
      5.87492707E-7F, 3.10858837E-7F, 5.20585218E-7F, 8.19290335E-7F,
      1.23265045E-6F, 1.79148481E-6F, 2.53223357E-6F, 3.4976681E-6F,
      4.73737919E-6F, 6.30845943E-6F, 8.27608619E-6F, 1.07140777E-5F,
      1.37054503E-5F, 1.73428271E-5F, 2.17288052E-5F, 2.69763514E-5F,
      3.3208984E-5F, 4.05609717E-5F, 4.91770588E-5F, 5.92124888E-5F,
      7.08326115E-5F, 8.42125E-5F, 9.95362352E-5F, 0.000116995994F, 0.000136791F,
      0.000159126444F, 0.000184212127F, 0.000212260406F, 0.000243484901F,
      0.000278098218F, 0.000316310092F, 0.000358324731F, 0.000404338352F,
      0.000454537192F, 0.000509094447F, 0.000568167F, 0.000631894218F,
      0.000700393517F, 0.000773758395F, 0.000852056604F, 0.000935325341F,
      0.00102357194F, 0.00111676846F, 0.00121485209F, 0.00131772109F,
      0.00142523705F, 0.00153721939F, 0.00165344728F, 0.00177365809F,
      0.00189754798F, 0.00202477188F, 0.00215494423F, 0.0022876407F,
      0.00242239982F, 0.00255872426F, 0.00269608456F, 0.00283392146F,
      0.00297164964F, 0.00310866116F, 0.00324432971F, 0.00337801548F,
      0.00350906933F, 0.00363683747F, 0.00376066752F, 0.0038799129F,
      0.00399393914F, 0.00410212716F, 0.00420388114F, 0.00429863157F,
      0.00438584154F, 0.00446501095F, 0.0045356811F, 0.0045974385F,
      0.00464991899F, 0.00469281152F, 0.00472586F, 0.00474886689F,
      0.00476169307F, 0.00476426259F, 0.00475655869F, 0.00473862886F,
      0.00471058F, 0.00467258086F, 0.00462485896F, 0.00456769764F,
      0.00450143544F, 0.00442646118F, 0.00434321119F, 0.00425216602F,
      0.00415384443F, 0.00404880056F, 0.00393761741F, 0.00382090337F,
      0.00369928521F, 0.00357340486F, 0.00344391214F, 0.00331146084F,
      0.00317670312F, 0.00304028369F, 0.00290283654F, 0.00276497938F,
      0.00262730918F, 0.00249039871F, 0.00235479278F, 0.00222100504F,
      0.0020895151F, 0.00196076627F, 0.0018351638F, 0.00171307276F,
      0.00159481808F, 0.00148068275F, 0.00137090858F, 0.0012656959F,
      0.00116520422F, 0.00106955413F, 0.000978827477F, 0.000893068442F,
      0.000812287792F, 0.000736462884F, 0.000665540923F, 0.000599440886F,
      0.000538057182F, 0.000481260824F, 0.00042890344F, 0.000380819751F,
      0.000336829602F, 0.000296741433F, 0.000260354776F, 0.00022746234F,
      0.000197852612F, 0.000171312262F, 0.000147628147F, 0.0001265889F,
      0.000107986816F, 9.16195568E-5F, 7.72912754E-5F, 6.48137429E-5F,
      5.40072615E-5F, 4.47015336E-5F, 3.67362627E-5F, 2.99614076E-5F,
      2.42374117E-5F, 1.94354325E-5F, 1.54372265E-5F, 1.21350322E-5F,
      9.43130817E-6F, 7.23829817E-6F, 5.47762875E-6F, 4.07985135E-6F,
      2.98393115E-6F, 2.13660314E-6F, 1.49174366E-6F, 1.0098446E-6F,
      6.57319902E-7F, 4.06029244E-7F, 2.32551812E-7F };

    b_dspcodegen_FIRDecimator_TpL_T *iobj_0;
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
    TpLockInAmp_DW.Buffer_inBufPtrIdx = 4;
    TpLockInAmp_DW.Buffer_bufferLength = 4;

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
    TpLockInAmp_DW.Buffer1_inBufPtrIdx = 4;
    TpLockInAmp_DW.Buffer1_bufferLength = 4;

    /* Start for MATLABSystem: '<S1>/CIC Compensation Decimator' */
    TpLockInAmp_DW.obj_b._pobj0.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj_b.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj_b.isInitialized = 0;
    TpLockInAmp_DW.obj_b.TunablePropsChanged = false;
    TpLockInAmp_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &TpLockInAmp_DW.obj_b;
    TpLockInAmp_DW.obj_b.isSetupComplete = false;
    TpLockInAmp_DW.obj_b.isInitialized = 1;
    wasTunablePropsChanged = TpLockInAmp_DW.obj_b.TunablePropsChanged;
    TpLockInAmp_DW.obj_b.TunablePropsChanged = wasTunablePropsChanged;
    iobj_0 = &TpLockInAmp_DW.obj_b._pobj0;
    obj->_pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRDecimator */
    iobj_0->cSFunObject.P0_IC = 0.0F;
    for (i = 0; i < 624; i++) {
      iobj_0->cSFunObject.P1_FILT[i] = tmp[i];
    }

    obj->_pobj0.matlabCodegenIsDeleted = false;
    TpLockInAmp_DW.obj_b.pFIRDecimator = &obj->_pobj0;
    iobj_0 = TpLockInAmp_DW.obj_b.pFIRDecimator;
    iobj_0->isSetupComplete = false;
    iobj_0->isInitialized = 1;
    iobj_0->isSetupComplete = true;
    TpLockInAmp_DW.obj_b.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S1>/CIC Compensation Decimator' */

    /* InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator' */
    iobj_0 = TpLockInAmp_DW.obj_b.pFIRDecimator;
    if (iobj_0->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRDecimator */
      iobj_0->cSFunObject.W2_CoeffIdx = 468;
      iobj_0->cSFunObject.W0_PhaseIdx = 3;
      iobj_0->cSFunObject.W4_TapDelayIndex = 465;
      iobj_0->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 620; i++) {
        iobj_0->cSFunObject.W3_StatesBuff[i] = 0.0F;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator' */

    /* Start for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
    TpLockInAmp_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj.matlabCodegenIsDeleted = true;
    TpLockInAmp_DW.obj.isInitialized = 0;
    TpLockInAmp_DW.obj.TunablePropsChanged = false;
    TpLockInAmp_DW.obj.matlabCodegenIsDeleted = false;
    obj = &TpLockInAmp_DW.obj;
    TpLockInAmp_DW.obj.isSetupComplete = false;
    TpLockInAmp_DW.obj.isInitialized = 1;
    wasTunablePropsChanged = TpLockInAmp_DW.obj.TunablePropsChanged;
    TpLockInAmp_DW.obj.TunablePropsChanged = wasTunablePropsChanged;
    iobj_0 = &TpLockInAmp_DW.obj._pobj0;
    obj->_pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRDecimator */
    iobj_0->cSFunObject.P0_IC = 0.0F;
    for (i = 0; i < 624; i++) {
      iobj_0->cSFunObject.P1_FILT[i] = tmp[i];
    }

    obj->_pobj0.matlabCodegenIsDeleted = false;
    TpLockInAmp_DW.obj.pFIRDecimator = &obj->_pobj0;
    iobj_0 = TpLockInAmp_DW.obj.pFIRDecimator;
    iobj_0->isSetupComplete = false;
    iobj_0->isInitialized = 1;
    iobj_0->isSetupComplete = true;
    TpLockInAmp_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S1>/CIC Compensation Decimator1' */

    /* InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
    iobj_0 = TpLockInAmp_DW.obj.pFIRDecimator;
    if (iobj_0->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRDecimator */
      iobj_0->cSFunObject.W2_CoeffIdx = 468;
      iobj_0->cSFunObject.W0_PhaseIdx = 3;
      iobj_0->cSFunObject.W4_TapDelayIndex = 465;
      iobj_0->cSFunObject.W1_Sums = 0.0F;
      for (i = 0; i < 620; i++) {
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
  if (!TpLockInAmp_DW.obj_b.matlabCodegenIsDeleted) {
    TpLockInAmp_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((TpLockInAmp_DW.obj_b.isInitialized == 1) &&
        TpLockInAmp_DW.obj_b.isSetupComplete) {
      obj = TpLockInAmp_DW.obj_b.pFIRDecimator;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }
    }
  }

  obj = &TpLockInAmp_DW.obj_b._pobj0;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator' */

  /* Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
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

  /* End of Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
