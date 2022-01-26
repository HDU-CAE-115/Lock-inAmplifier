/*
 * File: TpLockInAmp_types.h
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

#ifndef RTW_HEADER_TpLockInAmp_types_h_
#define RTW_HEADER_TpLockInAmp_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_AdakoEbziPhUkexCdRFXHF
#define struct_tag_AdakoEbziPhUkexCdRFXHF

struct tag_AdakoEbziPhUkexCdRFXHF
{
  int32_T S0_isInitialized;
  int32_T W0_PhaseIdx;
  real32_T W1_Sums;
  int32_T W2_CoeffIdx;
  real32_T W3_StatesBuff[756];
  int32_T W4_TapDelayIndex;
  int32_T W5_PrevNumChan;
  real32_T P0_IC;
  real32_T P1_FILT[760];
  real32_T O0_Y0[2];
};

#endif                                 /*struct_tag_AdakoEbziPhUkexCdRFXHF*/

#ifndef typedef_b_dsp_FIRDecimator_0_TpLockIn_T
#define typedef_b_dsp_FIRDecimator_0_TpLockIn_T

typedef struct tag_AdakoEbziPhUkexCdRFXHF b_dsp_FIRDecimator_0_TpLockIn_T;

#endif                               /*typedef_b_dsp_FIRDecimator_0_TpLockIn_T*/

#ifndef struct_tag_g1zp8zYgSNYnAnpVodMzFF
#define struct_tag_g1zp8zYgSNYnAnpVodMzFF

struct tag_g1zp8zYgSNYnAnpVodMzFF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRDecimator_0_TpLockIn_T cSFunObject;
};

#endif                                 /*struct_tag_g1zp8zYgSNYnAnpVodMzFF*/

#ifndef typedef_b_dspcodegen_FIRDecimator_TpL_T
#define typedef_b_dspcodegen_FIRDecimator_TpL_T

typedef struct tag_g1zp8zYgSNYnAnpVodMzFF b_dspcodegen_FIRDecimator_TpL_T;

#endif                               /*typedef_b_dspcodegen_FIRDecimator_TpL_T*/

#ifndef struct_tag_VSCvABf4WPVFaZXIVACcwE
#define struct_tag_VSCvABf4WPVFaZXIVACcwE

struct tag_VSCvABf4WPVFaZXIVACcwE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dspcodegen_FIRDecimator_TpL_T *pFIRDecimator;
  b_dspcodegen_FIRDecimator_TpL_T _pobj0;
};

#endif                                 /*struct_tag_VSCvABf4WPVFaZXIVACcwE*/

#ifndef typedef_dsp_CICCompensationDecimator__T
#define typedef_dsp_CICCompensationDecimator__T

typedef struct tag_VSCvABf4WPVFaZXIVACcwE dsp_CICCompensationDecimator__T;

#endif                               /*typedef_dsp_CICCompensationDecimator__T*/

#ifndef struct_tag_YTIVTNT5abK1zmSUSzjpaH
#define struct_tag_YTIVTNT5abK1zmSUSzjpaH

struct tag_YTIVTNT5abK1zmSUSzjpaH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  b_dspcodegen_FIRDecimator_TpL_T *pFIRDecimator;
  b_dspcodegen_FIRDecimator_TpL_T _pobj0;
};

#endif                                 /*struct_tag_YTIVTNT5abK1zmSUSzjpaH*/

#ifndef typedef_dsp_CICCompensationDecimato_f_T
#define typedef_dsp_CICCompensationDecimato_f_T

typedef struct tag_YTIVTNT5abK1zmSUSzjpaH dsp_CICCompensationDecimato_f_T;

#endif                               /*typedef_dsp_CICCompensationDecimato_f_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_TpLockInAmp_T RT_MODEL_TpLockInAmp_T;

#endif                                 /* RTW_HEADER_TpLockInAmp_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
