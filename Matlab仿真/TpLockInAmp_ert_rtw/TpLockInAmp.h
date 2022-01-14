/*
 * File: TpLockInAmp.h
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

/* Block signals for system '<S1>/CIC Compensation Decimator' */
typedef struct {
  real_T CICCompensationDecimator[2];  /* '<S1>/CIC Compensation Decimator' */
} B_CICCompensationDecimator_Tp_T;

/* Block states (default storage) for system '<S1>/CIC Compensation Decimator' */
typedef struct {
  dsp_CICCompensationDecimator__T obj; /* '<S1>/CIC Compensation Decimator' */
  boolean_T objisempty;                /* '<S1>/CIC Compensation Decimator' */
  boolean_T isInitialized;             /* '<S1>/CIC Compensation Decimator' */
} DW_CICCompensationDecimator_T_T;

/* Block signals (default storage) */
typedef struct {
  B_CICCompensationDecimator_Tp_T CICCompensationDecimator1;/* '<S1>/CIC Compensation Decimator' */
  B_CICCompensationDecimator_Tp_T CICCompensationDecimator;/* '<S1>/CIC Compensation Decimator' */
} B_TpLockInAmp_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SineWave1_AccFreqNorm;        /* '<S1>/Sine Wave1' */
  real_T Buffer_CircBuf[16];           /* '<S1>/Buffer' */
  real_T Unbuffer1_CircBuff[2];        /* '<S1>/Unbuffer1' */
  real_T SineWave2_AccFreqNorm;        /* '<S1>/Sine Wave2' */
  real_T Buffer1_CircBuf[16];          /* '<S1>/Buffer1' */
  real_T Unbuffer2_CircBuff[2];        /* '<S1>/Unbuffer2' */
  int32_T Buffer_inBufPtrIdx;          /* '<S1>/Buffer' */
  int32_T Buffer_outBufPtrIdx;         /* '<S1>/Buffer' */
  int32_T Buffer_bufferLength;         /* '<S1>/Buffer' */
  int32_T Unbuffer1_memIdx;            /* '<S1>/Unbuffer1' */
  int32_T Buffer1_inBufPtrIdx;         /* '<S1>/Buffer1' */
  int32_T Buffer1_outBufPtrIdx;        /* '<S1>/Buffer1' */
  int32_T Buffer1_bufferLength;        /* '<S1>/Buffer1' */
  int32_T Unbuffer2_memIdx;            /* '<S1>/Unbuffer2' */
  DW_CICCompensationDecimator_T_T CICCompensationDecimator1;/* '<S1>/CIC Compensation Decimator' */
  DW_CICCompensationDecimator_T_T CICCompensationDecimator;/* '<S1>/CIC Compensation Decimator' */
} DW_TpLockInAmp_T;

/* Real-time Model Data Structure */
struct tag_RTM_TpLockInAmp_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_TpLockInAmp_T TpLockInAmp_B;

/* Block states (default storage) */
extern DW_TpLockInAmp_T TpLockInAmp_DW;

/* Model entry point functions */
extern void TpLockInAmp_initialize(void);
extern void TpLockInAmp_step(void);
extern void TpLockInAmp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TpLockInAmp_T *const TpLockInAmp_M;

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern real_T signal_amp;              /* '<S1>/MATLAB Function' */
extern real_T signal_input;            /* '<Root>/In1' */
extern real_T signal_pha;              /* '<S1>/Trigonometric Function' */

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
 * '<S2>'   : 'TpLockInAmp/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_TpLockInAmp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
