/*
 * File: TpLockInAmp_types.h
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Feb 25 10:10:11 2022
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
#ifndef struct_tag_XdlEALNcG6IydpD9a28YoH
#define struct_tag_XdlEALNcG6IydpD9a28YoH

struct tag_XdlEALNcG6IydpD9a28YoH
{
  int32_T S0_isInitialized;
  real32_T W0_states[569];
  real32_T P0_InitialStates;
  real32_T P1_Coefficients[570];
};

#endif                                 /*struct_tag_XdlEALNcG6IydpD9a28YoH*/

#ifndef typedef_b_dsp_FIRFilter_0_TpLockInAmp_T
#define typedef_b_dsp_FIRFilter_0_TpLockInAmp_T

typedef struct tag_XdlEALNcG6IydpD9a28YoH b_dsp_FIRFilter_0_TpLockInAmp_T;

#endif                               /*typedef_b_dsp_FIRFilter_0_TpLockInAmp_T*/

#ifndef struct_tag_xfVGiaTXVbMGxZAE1jG9OE
#define struct_tag_xfVGiaTXVbMGxZAE1jG9OE

struct tag_xfVGiaTXVbMGxZAE1jG9OE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_TpLockInAmp_T cSFunObject;
};

#endif                                 /*struct_tag_xfVGiaTXVbMGxZAE1jG9OE*/

#ifndef typedef_b_dspcodegen_FIRFilter_TpLock_T
#define typedef_b_dspcodegen_FIRFilter_TpLock_T

typedef struct tag_xfVGiaTXVbMGxZAE1jG9OE b_dspcodegen_FIRFilter_TpLock_T;

#endif                               /*typedef_b_dspcodegen_FIRFilter_TpLock_T*/

#ifndef struct_tag_Zcgq8NYRZcfTEKau6Tqp2C
#define struct_tag_Zcgq8NYRZcfTEKau6Tqp2C

struct tag_Zcgq8NYRZcfTEKau6Tqp2C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_TpLock_T *FilterObj;
  b_dspcodegen_FIRFilter_TpLock_T _pobj0;
};

#endif                                 /*struct_tag_Zcgq8NYRZcfTEKau6Tqp2C*/

#ifndef typedef_dsp_LowpassFilter_TpLockInAmp_T
#define typedef_dsp_LowpassFilter_TpLockInAmp_T

typedef struct tag_Zcgq8NYRZcfTEKau6Tqp2C dsp_LowpassFilter_TpLockInAmp_T;

#endif                               /*typedef_dsp_LowpassFilter_TpLockInAmp_T*/

#ifndef struct_tag_TwJGHvXPradEDghFizrOxE
#define struct_tag_TwJGHvXPradEDghFizrOxE

struct tag_TwJGHvXPradEDghFizrOxE
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[179];
  real32_T pCumRevIndex;
};

#endif                                 /*struct_tag_TwJGHvXPradEDghFizrOxE*/

#ifndef typedef_g_dsp_private_SlidingWindowAv_T
#define typedef_g_dsp_private_SlidingWindowAv_T

typedef struct tag_TwJGHvXPradEDghFizrOxE g_dsp_private_SlidingWindowAv_T;

#endif                               /*typedef_g_dsp_private_SlidingWindowAv_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_TpLockInAmp_T
#define typedef_cell_wrap_TpLockInAmp_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_TpLockInAmp_T;

#endif                                 /*typedef_cell_wrap_TpLockInAmp_T*/

#ifndef struct_tag_8edqVRHMd2pyRQ4RFw1NMH
#define struct_tag_8edqVRHMd2pyRQ4RFw1NMH

struct tag_8edqVRHMd2pyRQ4RFw1NMH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_TpLockInAmp_T inputVarSize;
  g_dsp_private_SlidingWindowAv_T *pStatistic;
  int32_T NumChannels;
  g_dsp_private_SlidingWindowAv_T _pobj0;
};

#endif                                 /*struct_tag_8edqVRHMd2pyRQ4RFw1NMH*/

#ifndef typedef_dsp_simulink_MovingAverage_Tp_T
#define typedef_dsp_simulink_MovingAverage_Tp_T

typedef struct tag_8edqVRHMd2pyRQ4RFw1NMH dsp_simulink_MovingAverage_Tp_T;

#endif                               /*typedef_dsp_simulink_MovingAverage_Tp_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_TpLockInAmp_T RT_MODEL_TpLockInAmp_T;

#endif                                 /* RTW_HEADER_TpLockInAmp_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
