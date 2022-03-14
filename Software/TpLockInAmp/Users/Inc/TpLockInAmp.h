/*
 * File: TpLockInAmp.h
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

#ifndef RTW_HEADER_TpLockInAmp_h_
#define RTW_HEADER_TpLockInAmp_h_
#include <math.h>
#ifndef TpLockInAmp_COMMON_INCLUDES_
#define TpLockInAmp_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TpLockInAmp_COMMON_INCLUDES_ */

#include "TpLockInAmp_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S1>/Moving Average1' */
typedef struct {
  real32_T MovingAverage1;             /* '<S1>/Moving Average1' */
} B_MovingAverage1_TpLockInAmp_T;

/* Block states (default storage) for system '<S1>/Moving Average1' */
typedef struct {
  dsp_simulink_MovingAverage_Tp_T obj; /* '<S1>/Moving Average1' */
  boolean_T objisempty;                /* '<S1>/Moving Average1' */
} DW_MovingAverage1_TpLockInAmp_T;

/* Block signals (default storage) */
typedef struct {
  B_MovingAverage1_TpLockInAmp_T MovingAverage2;/* '<S1>/Moving Average1' */
  B_MovingAverage1_TpLockInAmp_T MovingAverage1;/* '<S1>/Moving Average1' */
} B_TpLockInAmp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_LowpassFilter_TpLockInAmp_T obj; /* '<S1>/Lowpass Filter1' */
  dsp_LowpassFilter_TpLockInAmp_T obj_n;/* '<S1>/Lowpass Filter' */
  real32_T GeneratedFilterBlock_states[791];/* '<S2>/Generated Filter Block' */
  real32_T SineWave1_AccFreqNorm;      /* '<S1>/Sine Wave1' */
  real32_T SineWave2_AccFreqNorm;      /* '<S1>/Sine Wave2' */
  int32_T GeneratedFilterBlock_circBuf;/* '<S2>/Generated Filter Block' */
  boolean_T isInitialized;             /* '<S1>/Lowpass Filter1' */
  boolean_T isInitialized_c;           /* '<S1>/Lowpass Filter' */
  DW_MovingAverage1_TpLockInAmp_T MovingAverage2;/* '<S1>/Moving Average1' */
  DW_MovingAverage1_TpLockInAmp_T MovingAverage1;/* '<S1>/Moving Average1' */
} DW_TpLockInAmp_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: GeneratedFilterBlock_Coefficien
   * Referenced by: '<S2>/Generated Filter Block'
   */
  real32_T GeneratedFilterBlock_Coefficien[792];
} ConstP_TpLockInAmp_T;

/* Real-time Model Data Structure */
struct tag_RTM_TpLockInAmp_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_TpLockInAmp_T TpLockInAmp_B;

/* Block states (default storage) */
extern DW_TpLockInAmp_T TpLockInAmp_DW;

/* Constant parameters (default storage) */
extern const ConstP_TpLockInAmp_T TpLockInAmp_ConstP;

/* Model entry point functions */
extern void TpLockInAmp_initialize(void);
extern void TpLockInAmp_step(void);
extern void TpLockInAmp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TpLockInAmp_T *const TpLockInAmp_M;

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern real32_T signal_amp;            /* '<S1>/MATLAB Function' */
extern real32_T signal_bpf;            /* '<S2>/Generated Filter Block' */
extern real32_T signal_input;          /* '<Root>/In1' */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TpLockInAmp'
 * '<S1>'   : 'TpLockInAmp/Subsystem'
 * '<S2>'   : 'TpLockInAmp/Subsystem/Bandpass Filter'
 * '<S3>'   : 'TpLockInAmp/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_TpLockInAmp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
