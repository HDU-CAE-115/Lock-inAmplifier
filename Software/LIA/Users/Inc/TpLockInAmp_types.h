/*
 * File: TpLockInAmp_types.h
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

#ifndef RTW_HEADER_TpLockInAmp_types_h_
#define RTW_HEADER_TpLockInAmp_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_72MydC7zUhyq0YzFvTOBKD
#define struct_tag_72MydC7zUhyq0YzFvTOBKD

struct tag_72MydC7zUhyq0YzFvTOBKD
{
  int32_T S0_isInitialized;
  int32_T W0_PhaseIdx;
  real32_T W1_Sums;
  int32_T W2_CoeffIdx;
  real32_T W3_StatesBuff[620];
  int32_T W4_TapDelayIndex;
  int32_T W5_PrevNumChan;
  real32_T P0_IC;
  real32_T P1_FILT[624];
  real32_T O0_Y0;
};

#endif                                 /*struct_tag_72MydC7zUhyq0YzFvTOBKD*/

#ifndef typedef_b_dsp_FIRDecimator_0_TpLockIn_T
#define typedef_b_dsp_FIRDecimator_0_TpLockIn_T

typedef struct tag_72MydC7zUhyq0YzFvTOBKD b_dsp_FIRDecimator_0_TpLockIn_T;

#endif                               /*typedef_b_dsp_FIRDecimator_0_TpLockIn_T*/

#ifndef struct_tag_IsYFv9fviifZeDiBwwUnfC
#define struct_tag_IsYFv9fviifZeDiBwwUnfC

struct tag_IsYFv9fviifZeDiBwwUnfC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRDecimator_0_TpLockIn_T cSFunObject;
};

#endif                                 /*struct_tag_IsYFv9fviifZeDiBwwUnfC*/

#ifndef typedef_b_dspcodegen_FIRDecimator_TpL_T
#define typedef_b_dspcodegen_FIRDecimator_TpL_T

typedef struct tag_IsYFv9fviifZeDiBwwUnfC b_dspcodegen_FIRDecimator_TpL_T;

#endif                               /*typedef_b_dspcodegen_FIRDecimator_TpL_T*/

#ifndef struct_tag_Ih36V9BVGVdv8KLOKKO2DB
#define struct_tag_Ih36V9BVGVdv8KLOKKO2DB

struct tag_Ih36V9BVGVdv8KLOKKO2DB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  b_dspcodegen_FIRDecimator_TpL_T *pFIRDecimator;
  b_dspcodegen_FIRDecimator_TpL_T _pobj0;
};

#endif                                 /*struct_tag_Ih36V9BVGVdv8KLOKKO2DB*/

#ifndef typedef_dsp_CICCompensationDecimator__T
#define typedef_dsp_CICCompensationDecimator__T

typedef struct tag_Ih36V9BVGVdv8KLOKKO2DB dsp_CICCompensationDecimator__T;

#endif                               /*typedef_dsp_CICCompensationDecimator__T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_TpLockInAmp_T RT_MODEL_TpLockInAmp_T;

#endif                                 /* RTW_HEADER_TpLockInAmp_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
