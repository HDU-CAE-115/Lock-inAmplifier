/*
 * File: TpLockInAmp_types.h
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Jan 10 12:27:51 2022
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
#ifndef struct_tag_PQqzetjOvttfXwUrCjm4jF
#define struct_tag_PQqzetjOvttfXwUrCjm4jF

struct tag_PQqzetjOvttfXwUrCjm4jF
{
  int32_T S0_isInitialized;
  int32_T W0_PhaseIdx;
  real_T W1_Sums;
  int32_T W2_CoeffIdx;
  real_T W3_StatesBuff[540];
  int32_T W4_TapDelayIndex;
  int32_T W5_PrevNumChan;
  real_T P0_IC;
  real_T P1_FILT[544];
  real_T O0_Y0[2];
};

#endif                                 /*struct_tag_PQqzetjOvttfXwUrCjm4jF*/

#ifndef typedef_b_dsp_FIRDecimator_0_TpLockIn_T
#define typedef_b_dsp_FIRDecimator_0_TpLockIn_T

typedef struct tag_PQqzetjOvttfXwUrCjm4jF b_dsp_FIRDecimator_0_TpLockIn_T;

#endif                               /*typedef_b_dsp_FIRDecimator_0_TpLockIn_T*/

#ifndef struct_tag_RUbMqdr1C1UsIGjy3mtb
#define struct_tag_RUbMqdr1C1UsIGjy3mtb

struct tag_RUbMqdr1C1UsIGjy3mtb
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRDecimator_0_TpLockIn_T cSFunObject;
};

#endif                                 /*struct_tag_RUbMqdr1C1UsIGjy3mtb*/

#ifndef typedef_b_dspcodegen_FIRDecimator_TpL_T
#define typedef_b_dspcodegen_FIRDecimator_TpL_T

typedef struct tag_RUbMqdr1C1UsIGjy3mtb b_dspcodegen_FIRDecimator_TpL_T;

#endif                               /*typedef_b_dspcodegen_FIRDecimator_TpL_T*/

#ifndef struct_tag_DJ6qkcE7Wuwb7W3rWUG1AF
#define struct_tag_DJ6qkcE7Wuwb7W3rWUG1AF

struct tag_DJ6qkcE7Wuwb7W3rWUG1AF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  b_dspcodegen_FIRDecimator_TpL_T *pFIRDecimator;
  b_dspcodegen_FIRDecimator_TpL_T _pobj0;
};

#endif                                 /*struct_tag_DJ6qkcE7Wuwb7W3rWUG1AF*/

#ifndef typedef_dsp_CICCompensationDecimator__T
#define typedef_dsp_CICCompensationDecimator__T

typedef struct tag_DJ6qkcE7Wuwb7W3rWUG1AF dsp_CICCompensationDecimator__T;

#endif                               /*typedef_dsp_CICCompensationDecimator__T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_TpLockInAmp_T RT_MODEL_TpLockInAmp_T;

#endif                                 /* RTW_HEADER_TpLockInAmp_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
