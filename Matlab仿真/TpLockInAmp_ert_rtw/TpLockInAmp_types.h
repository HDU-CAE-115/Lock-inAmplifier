/*
 * File: TpLockInAmp_types.h
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jan 14 16:54:24 2022
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
#ifndef struct_tag_R6cskI0ley3NFqzhtDw3K
#define struct_tag_R6cskI0ley3NFqzhtDw3K

struct tag_R6cskI0ley3NFqzhtDw3K
{
  int32_T S0_isInitialized;
  int32_T W0_PhaseIdx;
  real_T W1_Sums;
  int32_T W2_CoeffIdx;
  real_T W3_StatesBuff[504];
  int32_T W4_TapDelayIndex;
  int32_T W5_PrevNumChan;
  real_T P0_IC;
  real_T P1_FILT[508];
  real_T O0_Y0[2];
};

#endif                                 /*struct_tag_R6cskI0ley3NFqzhtDw3K*/

#ifndef typedef_b_dsp_FIRDecimator_0_TpLockIn_T
#define typedef_b_dsp_FIRDecimator_0_TpLockIn_T

typedef struct tag_R6cskI0ley3NFqzhtDw3K b_dsp_FIRDecimator_0_TpLockIn_T;

#endif                               /*typedef_b_dsp_FIRDecimator_0_TpLockIn_T*/

#ifndef struct_tag_GlLawrRFrVtFmsVe30VRJ
#define struct_tag_GlLawrRFrVtFmsVe30VRJ

struct tag_GlLawrRFrVtFmsVe30VRJ
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRDecimator_0_TpLockIn_T cSFunObject;
};

#endif                                 /*struct_tag_GlLawrRFrVtFmsVe30VRJ*/

#ifndef typedef_b_dspcodegen_FIRDecimator_TpL_T
#define typedef_b_dspcodegen_FIRDecimator_TpL_T

typedef struct tag_GlLawrRFrVtFmsVe30VRJ b_dspcodegen_FIRDecimator_TpL_T;

#endif                               /*typedef_b_dspcodegen_FIRDecimator_TpL_T*/

#ifndef struct_tag_UoUGwTJNeQkKOfioFJSBRF
#define struct_tag_UoUGwTJNeQkKOfioFJSBRF

struct tag_UoUGwTJNeQkKOfioFJSBRF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  b_dspcodegen_FIRDecimator_TpL_T *pFIRDecimator;
  b_dspcodegen_FIRDecimator_TpL_T _pobj0;
};

#endif                                 /*struct_tag_UoUGwTJNeQkKOfioFJSBRF*/

#ifndef typedef_dsp_CICCompensationDecimator__T
#define typedef_dsp_CICCompensationDecimator__T

typedef struct tag_UoUGwTJNeQkKOfioFJSBRF dsp_CICCompensationDecimator__T;

#endif                               /*typedef_dsp_CICCompensationDecimator__T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_TpLockInAmp_T RT_MODEL_TpLockInAmp_T;

#endif                                 /* RTW_HEADER_TpLockInAmp_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
