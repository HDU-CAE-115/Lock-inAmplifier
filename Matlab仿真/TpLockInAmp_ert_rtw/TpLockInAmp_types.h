/*
 * File: TpLockInAmp_types.h
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jan  4 16:58:07 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TpLockInAmp_types_h_
#define RTW_HEADER_TpLockInAmp_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_TuLbZova64ecIhlE2S5HyD
#define struct_tag_TuLbZova64ecIhlE2S5HyD

struct tag_TuLbZova64ecIhlE2S5HyD
{
  int32_T S0_isInitialized;
  int32_T W0_PhaseIdx;
  real_T W1_Sums;
  int32_T W2_CoeffIdx;
  real_T W3_StatesBuff[564];
  int32_T W4_TapDelayIndex;
  int32_T W5_PrevNumChan;
  real_T P0_IC;
  real_T P1_FILT[568];
  real_T O0_Y0[2];
};

#endif                                 /*struct_tag_TuLbZova64ecIhlE2S5HyD*/

#ifndef typedef_b_dsp_FIRDecimator_0_TpLockIn_T
#define typedef_b_dsp_FIRDecimator_0_TpLockIn_T

typedef struct tag_TuLbZova64ecIhlE2S5HyD b_dsp_FIRDecimator_0_TpLockIn_T;

#endif                               /*typedef_b_dsp_FIRDecimator_0_TpLockIn_T*/

#ifndef struct_tag_knZlfDgloGlhxlBsMrHpQH
#define struct_tag_knZlfDgloGlhxlBsMrHpQH

struct tag_knZlfDgloGlhxlBsMrHpQH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRDecimator_0_TpLockIn_T cSFunObject;
};

#endif                                 /*struct_tag_knZlfDgloGlhxlBsMrHpQH*/

#ifndef typedef_b_dspcodegen_FIRDecimator_TpL_T
#define typedef_b_dspcodegen_FIRDecimator_TpL_T

typedef struct tag_knZlfDgloGlhxlBsMrHpQH b_dspcodegen_FIRDecimator_TpL_T;

#endif                               /*typedef_b_dspcodegen_FIRDecimator_TpL_T*/

#ifndef struct_tag_5kU81dc6ZpakZLcdCPigTG
#define struct_tag_5kU81dc6ZpakZLcdCPigTG

struct tag_5kU81dc6ZpakZLcdCPigTG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  b_dspcodegen_FIRDecimator_TpL_T *pFIRDecimator;
  b_dspcodegen_FIRDecimator_TpL_T _pobj0;
};

#endif                                 /*struct_tag_5kU81dc6ZpakZLcdCPigTG*/

#ifndef typedef_dsp_CICCompensationDecimator__T
#define typedef_dsp_CICCompensationDecimator__T

typedef struct tag_5kU81dc6ZpakZLcdCPigTG dsp_CICCompensationDecimator__T;

#endif                               /*typedef_dsp_CICCompensationDecimator__T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_TpLockInAmp_T RT_MODEL_TpLockInAmp_T;

#endif                                 /* RTW_HEADER_TpLockInAmp_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
