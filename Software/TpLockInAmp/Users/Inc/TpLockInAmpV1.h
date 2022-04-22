/*
 * File: TpLockInAmpV1.h
 *
 * Code generated for Simulink model 'TpLockInAmpV1'.
 *
 * Model version                  : 6.4
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Apr 22 15:16:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TpLockInAmpV1_h_
#define RTW_HEADER_TpLockInAmpV1_h_
#include <math.h>
#ifndef TpLockInAmpV1_COMMON_INCLUDES_
#define TpLockInAmpV1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TpLockInAmpV1_COMMON_INCLUDES_ */

#include "TpLockInAmpV1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S1>/Unit Delay1' */
  uint32_T Counter_Count;              /* '<S1>/Counter' */
  uint16_T SineWave1_TableIdx;         /* '<S1>/Sine Wave1' */
  uint16_T SineWave7_TableIdx;         /* '<S1>/Sine Wave7' */
} DW_TpLockInAmpV1_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: SineWave1_Values_SineTable
   * Referenced by: '<S1>/Sine Wave1'
   */
  real32_T SineWave1_Values_SineTable[12];

  /* Computed Parameter: SineWave7_Values_SineTable
   * Referenced by: '<S1>/Sine Wave7'
   */
  real32_T SineWave7_Values_SineTable[12];
} ConstP_TpLockInAmpV1_T;

/* Real-time Model Data Structure */
struct tag_RTM_TpLockInAmpV1_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TpLockInAmpV1_T TpLockInAmpV1_DW;

/* Constant parameters (default storage) */
extern const ConstP_TpLockInAmpV1_T TpLockInAmpV1_ConstP;

/* Model entry point functions */
extern void TpLockInAmpV1_initialize(void);
extern void TpLockInAmpV1_step(void);
extern void TpLockInAmpV1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TpLockInAmpV1_T *const TpLockInAmpV1_M;

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern real32_T signal_input;          /* '<Root>/In1' */
extern real32_T signal_output;         /* '<S1>/Multiply' */

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
 * '<Root>' : 'TpLockInAmpV1'
 * '<S1>'   : 'TpLockInAmpV1/Subsystem'
 */
#endif                                 /* RTW_HEADER_TpLockInAmpV1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
