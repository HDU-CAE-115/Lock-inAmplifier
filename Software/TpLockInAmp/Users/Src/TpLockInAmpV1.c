/*
 * File: TpLockInAmpV1.c
 *
 * Code generated for Simulink model 'TpLockInAmpV1'.
 *
 * Model version                  : 6.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Apr 22 15:16:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "TpLockInAmpV1.h"
#include "TpLockInAmpV1_private.h"

/* Block states (default storage) */
DW_TpLockInAmpV1_T TpLockInAmpV1_DW;

/* Real-time model */
static RT_MODEL_TpLockInAmpV1_T TpLockInAmpV1_M_;
RT_MODEL_TpLockInAmpV1_T *const TpLockInAmpV1_M = &TpLockInAmpV1_M_;

/* Exported data definition */

/* Definition for custom storage class: Global */
real32_T signal_input;                 /* '<Root>/In1' */
real32_T signal_output;                /* '<S1>/Multiply' */

/* Model step function */
void TpLockInAmpV1_step(void)
{
  real32_T rtb_Divide1;
  real32_T rtb_Sqrt;
  real32_T rtb_Square;

  /* S-Function (sdspsine2): '<S1>/Sine Wave1' */
  rtb_Divide1 =
    TpLockInAmpV1_ConstP.SineWave1_Values_SineTable[TpLockInAmpV1_DW.SineWave1_TableIdx];
  TpLockInAmpV1_DW.SineWave1_TableIdx++;
  if (TpLockInAmpV1_DW.SineWave1_TableIdx >= 12) {
    TpLockInAmpV1_DW.SineWave1_TableIdx = 0U;
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave1' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/In1'
   *  Product: '<S1>/Product'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  TpLockInAmpV1_DW.UnitDelay_DSTATE += signal_input * rtb_Divide1;

  /* S-Function (sdspcount2): '<S1>/Counter' */
  rtb_Divide1 = (real32_T)TpLockInAmpV1_DW.Counter_Count;
  TpLockInAmpV1_DW.Counter_Count++;

  /* Product: '<S1>/Divide' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Sqrt = TpLockInAmpV1_DW.UnitDelay_DSTATE / rtb_Divide1;

  /* Math: '<S1>/Square' */
  rtb_Square = rtb_Sqrt * rtb_Sqrt;

  /* S-Function (sdspsine2): '<S1>/Sine Wave7' */
  rtb_Sqrt =
    TpLockInAmpV1_ConstP.SineWave7_Values_SineTable[TpLockInAmpV1_DW.SineWave7_TableIdx];
  TpLockInAmpV1_DW.SineWave7_TableIdx++;
  if (TpLockInAmpV1_DW.SineWave7_TableIdx >= 12) {
    TpLockInAmpV1_DW.SineWave7_TableIdx = 0U;
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave7' */

  /* Sum: '<S1>/Sum2' incorporates:
   *  Inport: '<Root>/In1'
   *  Product: '<S1>/Product1'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  TpLockInAmpV1_DW.UnitDelay1_DSTATE += signal_input * rtb_Sqrt;

  /* Product: '<S1>/Divide1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  rtb_Divide1 = TpLockInAmpV1_DW.UnitDelay1_DSTATE / rtb_Divide1;

  /* Gain: '<S1>/Multiply' incorporates:
   *  Math: '<S1>/Square1'
   *  Sqrt: '<S1>/Sqrt'
   *  Sum: '<S1>/Add'
   */
  signal_output = sqrtf(rtb_Divide1 * rtb_Divide1 + rtb_Square) * 2.0F;
}

/* Model initialize function */
void TpLockInAmpV1_initialize(void)
{
  /* Full-cycle Table lookup */
  /* Full-cycle Table lookup */

  /* InitializeConditions for S-Function (sdspcount2): '<S1>/Counter' */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Full-cycle Table lookup */
  TpLockInAmpV1_DW.Counter_Count = 1U;

  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Full-cycle Table lookup */
}

/* Model terminate function */
void TpLockInAmpV1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
