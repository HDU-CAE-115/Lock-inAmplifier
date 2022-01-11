/*
 * File: TpLockInAmp_private.h
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jan 11 13:29:13 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TpLockInAmp_private_h_
#define RTW_HEADER_TpLockInAmp_private_h_
#include "rtwtypes.h"
#include "TpLockInAmp.h"

extern void T_CICCompensationDecimator_Init(DW_CICCompensationDecimator_T_T
  *localDW);
extern void TpLock_CICCompensationDecimator(const real_T rtu_0[8],
  B_CICCompensationDecimator_Tp_T *localB, DW_CICCompensationDecimator_T_T
  *localDW);
extern void T_CICCompensationDecimator_Term(DW_CICCompensationDecimator_T_T
  *localDW);

#endif                                 /* RTW_HEADER_TpLockInAmp_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
