/*
 * File: TpLockInAmp_private.h
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Mar  3 17:19:34 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TpLockInAmp_private_h_
#define RTW_HEADER_TpLockInAmp_private_h_
#include "rtwtypes.h"
#include "TpLockInAmp.h"

extern void TpLockInAmp_MovingAverage1_Init(DW_MovingAverage1_TpLockInAmp_T
  *localDW);
extern void TpLockInAmp_MovingAverage1(real32_T rtu_0,
  B_MovingAverage1_TpLockInAmp_T *localB, DW_MovingAverage1_TpLockInAmp_T
  *localDW);
extern void TpLockInAmp_MovingAverage1_Term(DW_MovingAverage1_TpLockInAmp_T
  *localDW);

#endif                                 /* RTW_HEADER_TpLockInAmp_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
