/*
 * File: TpLockInAmp.c
 *
 * Code generated for Simulink model 'TpLockInAmp'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Feb 23 16:29:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "TpLockInAmp.h"
#include "TpLockInAmp_private.h"

/* Block signals (default storage) */
B_TpLockInAmp_T TpLockInAmp_B;

/* Block states (default storage) */
DW_TpLockInAmp_T TpLockInAmp_DW;

/* Real-time model */
static RT_MODEL_TpLockInAmp_T TpLockInAmp_M_;
RT_MODEL_TpLockInAmp_T *const TpLockInAmp_M = &TpLockInAmp_M_;

/* Exported data definition */

/* Definition for custom storage class: Global */
real32_T signal_amp;                   /* '<S1>/MATLAB Function' */
real32_T signal_input;                 /* '<Root>/In1' */

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void TpLockInAmp_LowpassFilter_Init(DW_LowpassFilter_TpLockInAmp_T *localDW)
{
  static const real32_T tmp[570] = { 1.73948192E-5F, 3.81724567E-6F,
    4.23394522E-6F, 4.67927748E-6F, 5.15454121E-6F, 5.66118297E-6F,
    6.20036826E-6F, 6.77374692E-6F, 7.38297E-6F, 8.02898739E-6F, 8.71389148E-6F,
    9.43881423E-6F, 1.02056056E-5F, 1.10157207E-5F, 1.18708949E-5F,
    1.27729763E-5F, 1.3723703E-5F, 1.4724741E-5F, 1.57779887E-5F, 1.68852403E-5F,
    1.80485422E-5F, 1.9269788E-5F, 2.05509496E-5F, 2.18940786E-5F,
    2.33012106E-5F, 2.47744738E-5F, 2.63160982E-5F, 2.79283195E-5F,
    2.96134458E-5F, 3.13737E-5F, 3.32112686E-5F, 3.51285198E-5F, 3.71277893E-5F,
    3.92116199E-5F, 4.13824346E-5F, 4.36425653E-5F, 4.59944204E-5F, 4.84406E-5F,
    5.09837337E-5F, 5.3626587E-5F, 5.63713475E-5F, 5.92207944E-5F,
    6.21776271E-5F, 6.52448362E-5F, 6.84251791E-5F, 7.1721217E-5F,
    7.51356856E-5F, 7.86727178E-5F, 8.23332884E-5F, 8.61227163E-5F,
    9.00411251E-5F, 9.40938189E-5F, 9.82834463E-5F, 0.000102611157F,
    0.000107081469F, 0.000111697766F, 0.000116461335F, 0.000121376746F,
    0.000126445564F, 0.000131672539F, 0.000137059687F, 0.000142610079F,
    0.000148327104F, 0.000154214256F, 0.000160274736F, 0.000166511614F,
    0.000172927786F, 0.000179526818F, 0.000186311852F, 0.00019328596F,
    0.000200451948F, 0.000207812656F, 0.000215371096F, 0.000223130352F,
    0.000231093538F, 0.000239263827F, 0.000247644319F, 0.000256238272F,
    0.00026504905F, 0.00027407991F, 0.000283334055F, 0.000292814366F,
    0.00030252352F, 0.000312464021F, 0.000322638283F, 0.000333048782F,
    0.000343698426F, 0.00035459004F, 0.000365727057F, 0.000377112679F,
    0.000388750341F, 0.000400642952F, 0.000412792579F, 0.000425200531F,
    0.000437867915F, 0.000450795807F, 0.000463987439F, 0.000477446709F,
    0.000491179875F, 0.000505190575F, 0.000519477355F, 0.000534034F,
    0.000548857322F, 0.000563965237F, 0.000579391432F, 0.000595050456F,
    0.000611025491F, 0.000627278758F, 0.000643821841F, 0.000660655147F,
    0.000677779783F, 0.000695197145F, 0.000712908572F, 0.000730914646F,
    0.000749216764F, 0.000767815625F, 0.00078671216F, 0.000805906893F,
    0.000825400464F, 0.000845193514F, 0.000865286449F, 0.000885679445F,
    0.000906372676F, 0.000927366142F, 0.000948659785F, 0.000970253372F,
    0.000992146553F, 0.00101433892F, 0.00103683013F, 0.00105961948F,
    0.00108270603F, 0.00110608898F, 0.00112976728F, 0.0011537401F,
    0.00117800594F, 0.00120256352F, 0.00122741121F, 0.00125254737F,
    0.0012779705F, 0.00130367861F, 0.0013296695F, 0.00135594094F, 0.00138249062F,
    0.00140931644F, 0.00143641548F, 0.00146378507F, 0.00149142242F,
    0.00151932461F, 0.00154748885F, 0.00157591153F, 0.00160458905F,
    0.00163351931F, 0.00166269601F, 0.00169211929F, 0.00172178F, 0.00175167853F,
    0.00178180949F, 0.00181216653F, 0.00184274698F, 0.00187354709F,
    0.00190456049F, 0.00193578319F, 0.00196720916F, 0.00199883524F,
    0.00203065528F, 0.00206266297F, 0.00209485297F, 0.00212722F, 0.00215975847F,
    0.00219246233F, 0.00222532521F, 0.00225834129F, 0.00229150453F,
    0.00232480862F, 0.00235824729F, 0.00239181356F, 0.00242550066F,
    0.00245930138F, 0.00249320874F, 0.00252721598F, 0.00256131589F,
    0.00259550149F, 0.00262976554F, 0.00266410038F, 0.00269849855F,
    0.00273295236F, 0.00276745367F, 0.00280199456F, 0.00283656735F,
    0.00287116366F, 0.00290577626F, 0.00294039724F, 0.002975018F, 0.00300963013F,
    0.00304422481F, 0.00307879318F, 0.00311332685F, 0.00314781815F,
    0.00318225939F, 0.00321664126F, 0.00325095421F, 0.0032851873F,
    0.00331933377F, 0.00335338665F, 0.00338733802F, 0.00342117576F,
    0.00345488684F, 0.00348846847F, 0.00352191855F, 0.00355520728F,
    0.00358834723F, 0.00362131605F, 0.00365411025F, 0.00368671957F,
    0.00371913449F, 0.00375134661F, 0.00378334685F, 0.00381512544F,
    0.00384667446F, 0.00387798413F, 0.00390904583F, 0.00393985119F, 0.00397039F,
    0.00400065491F, 0.00403063605F, 0.00406032521F, 0.00408971356F,
    0.00411879225F, 0.00414755289F, 0.00417598663F, 0.00420408556F,
    0.00423184084F, 0.00425924407F, 0.00428628782F, 0.00431296276F,
    0.00433926191F, 0.00436517643F, 0.00439069886F, 0.00441582082F,
    0.00444053533F, 0.004464834F, 0.00448871F, 0.00451215543F, 0.00453516329F,
    0.0045577269F, 0.00457983837F, 0.00460149162F, 0.0046226792F, 0.00464339461F,
    0.00466363132F, 0.00468338234F, 0.00470264256F, 0.00472140498F,
    0.00473966403F, 0.00475741364F, 0.00477464963F, 0.00479136268F,
    0.00480755419F, 0.00482320972F, 0.00483833253F, 0.00485291472F,
    0.00486694928F, 0.0048804339F, 0.00489336532F, 0.00490573794F,
    0.00491754757F, 0.00492878957F, 0.00493946252F, 0.00494956272F,
    0.00495908549F, 0.00496802805F, 0.00497638714F, 0.00498416042F,
    0.0049913465F, 0.00499794167F, 0.00500394451F, 0.0050093527F, 0.00501416437F,
    0.00501837768F, 0.00502199167F, 0.00502500497F, 0.00502741709F,
    0.00502922712F, 0.00503043365F, 0.00503103714F, 0.00503103714F,
    0.00503043365F, 0.00502922712F, 0.00502741709F, 0.00502500497F,
    0.00502199167F, 0.00501837768F, 0.00501416437F, 0.0050093527F,
    0.00500394451F, 0.00499794167F, 0.0049913465F, 0.00498416042F,
    0.00497638714F, 0.00496802805F, 0.00495908549F, 0.00494956272F,
    0.00493946252F, 0.00492878957F, 0.00491754757F, 0.00490573794F,
    0.00489336532F, 0.0048804339F, 0.00486694928F, 0.00485291472F,
    0.00483833253F, 0.00482320972F, 0.00480755419F, 0.00479136268F,
    0.00477464963F, 0.00475741364F, 0.00473966403F, 0.00472140498F,
    0.00470264256F, 0.00468338234F, 0.00466363132F, 0.00464339461F,
    0.0046226792F, 0.00460149162F, 0.00457983837F, 0.0045577269F, 0.00453516329F,
    0.00451215543F, 0.00448871F, 0.004464834F, 0.00444053533F, 0.00441582082F,
    0.00439069886F, 0.00436517643F, 0.00433926191F, 0.00431296276F,
    0.00428628782F, 0.00425924407F, 0.00423184084F, 0.00420408556F,
    0.00417598663F, 0.00414755289F, 0.00411879225F, 0.00408971356F,
    0.00406032521F, 0.00403063605F, 0.00400065491F, 0.00397039F, 0.00393985119F,
    0.00390904583F, 0.00387798413F, 0.00384667446F, 0.00381512544F,
    0.00378334685F, 0.00375134661F, 0.00371913449F, 0.00368671957F,
    0.00365411025F, 0.00362131605F, 0.00358834723F, 0.00355520728F,
    0.00352191855F, 0.00348846847F, 0.00345488684F, 0.00342117576F,
    0.00338733802F, 0.00335338665F, 0.00331933377F, 0.0032851873F,
    0.00325095421F, 0.00321664126F, 0.00318225939F, 0.00314781815F,
    0.00311332685F, 0.00307879318F, 0.00304422481F, 0.00300963013F, 0.002975018F,
    0.00294039724F, 0.00290577626F, 0.00287116366F, 0.00283656735F,
    0.00280199456F, 0.00276745367F, 0.00273295236F, 0.00269849855F,
    0.00266410038F, 0.00262976554F, 0.00259550149F, 0.00256131589F,
    0.00252721598F, 0.00249320874F, 0.00245930138F, 0.00242550066F,
    0.00239181356F, 0.00235824729F, 0.00232480862F, 0.00229150453F,
    0.00225834129F, 0.00222532521F, 0.00219246233F, 0.00215975847F, 0.00212722F,
    0.00209485297F, 0.00206266297F, 0.00203065528F, 0.00199883524F,
    0.00196720916F, 0.00193578319F, 0.00190456049F, 0.00187354709F,
    0.00184274698F, 0.00181216653F, 0.00178180949F, 0.00175167853F, 0.00172178F,
    0.00169211929F, 0.00166269601F, 0.00163351931F, 0.00160458905F,
    0.00157591153F, 0.00154748885F, 0.00151932461F, 0.00149142242F,
    0.00146378507F, 0.00143641548F, 0.00140931644F, 0.00138249062F,
    0.00135594094F, 0.0013296695F, 0.00130367861F, 0.0012779705F, 0.00125254737F,
    0.00122741121F, 0.00120256352F, 0.00117800594F, 0.0011537401F,
    0.00112976728F, 0.00110608898F, 0.00108270603F, 0.00105961948F,
    0.00103683013F, 0.00101433892F, 0.000992146553F, 0.000970253372F,
    0.000948659785F, 0.000927366142F, 0.000906372676F, 0.000885679445F,
    0.000865286449F, 0.000845193514F, 0.000825400464F, 0.000805906893F,
    0.00078671216F, 0.000767815625F, 0.000749216764F, 0.000730914646F,
    0.000712908572F, 0.000695197145F, 0.000677779783F, 0.000660655147F,
    0.000643821841F, 0.000627278758F, 0.000611025491F, 0.000595050456F,
    0.000579391432F, 0.000563965237F, 0.000548857322F, 0.000534034F,
    0.000519477355F, 0.000505190575F, 0.000491179875F, 0.000477446709F,
    0.000463987439F, 0.000450795807F, 0.000437867915F, 0.000425200531F,
    0.000412792579F, 0.000400642952F, 0.000388750341F, 0.000377112679F,
    0.000365727057F, 0.00035459004F, 0.000343698426F, 0.000333048782F,
    0.000322638283F, 0.000312464021F, 0.00030252352F, 0.000292814366F,
    0.000283334055F, 0.00027407991F, 0.00026504905F, 0.000256238272F,
    0.000247644319F, 0.000239263827F, 0.000231093538F, 0.000223130352F,
    0.000215371096F, 0.000207812656F, 0.000200451948F, 0.00019328596F,
    0.000186311852F, 0.000179526818F, 0.000172927786F, 0.000166511614F,
    0.000160274736F, 0.000154214256F, 0.000148327104F, 0.000142610079F,
    0.000137059687F, 0.000131672539F, 0.000126445564F, 0.000121376746F,
    0.000116461335F, 0.000111697766F, 0.000107081469F, 0.000102611157F,
    9.82834463E-5F, 9.40938189E-5F, 9.00411251E-5F, 8.61227163E-5F,
    8.23332884E-5F, 7.86727178E-5F, 7.51356856E-5F, 7.1721217E-5F,
    6.84251791E-5F, 6.52448362E-5F, 6.21776271E-5F, 5.92207944E-5F,
    5.63713475E-5F, 5.3626587E-5F, 5.09837337E-5F, 4.84406E-5F, 4.59944204E-5F,
    4.36425653E-5F, 4.13824346E-5F, 3.92116199E-5F, 3.71277893E-5F,
    3.51285198E-5F, 3.32112686E-5F, 3.13737E-5F, 2.96134458E-5F, 2.79283195E-5F,
    2.63160982E-5F, 2.47744738E-5F, 2.33012106E-5F, 2.18940786E-5F,
    2.05509496E-5F, 1.9269788E-5F, 1.80485422E-5F, 1.68852403E-5F,
    1.57779887E-5F, 1.4724741E-5F, 1.3723703E-5F, 1.27729763E-5F, 1.18708949E-5F,
    1.10157207E-5F, 1.02056056E-5F, 9.43881423E-6F, 8.71389148E-6F,
    8.02898739E-6F, 7.38297E-6F, 6.77374692E-6F, 6.20036826E-6F, 5.66118297E-6F,
    5.15454121E-6F, 4.67927748E-6F, 4.23394522E-6F, 3.81724567E-6F,
    1.73948192E-5F };

  b_dspcodegen_FIRFilter_TpLock_T *iobj_0;
  int32_T i;
  boolean_T wasTunablePropsChanged;

  /* Start for MATLABSystem: '<S1>/Lowpass Filter' */
  localDW->obj._pobj0.matlabCodegenIsDeleted = true;
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.TunablePropsChanged = false;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  wasTunablePropsChanged = localDW->obj.TunablePropsChanged;
  localDW->obj.TunablePropsChanged = wasTunablePropsChanged;
  iobj_0 = &localDW->obj._pobj0;
  localDW->obj._pobj0.isInitialized = 0;

  /* System object Constructor function: dsp.FIRFilter */
  localDW->obj._pobj0.cSFunObject.P0_InitialStates = 0.0F;
  for (i = 0; i < 570; i++) {
    iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
  }

  localDW->obj._pobj0.matlabCodegenIsDeleted = false;
  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.NumChannels = 1;
  localDW->obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<S1>/Lowpass Filter' */

  /* InitializeConditions for MATLABSystem: '<S1>/Lowpass Filter' */
  iobj_0 = localDW->obj.FilterObj;
  if (iobj_0->isInitialized == 1) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 569; i++) {
      iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S1>/Lowpass Filter' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void TpLockInAmp_LowpassFilter(real32_T rtu_0, B_LowpassFilter_TpLockInAmp_T
  *localB, DW_LowpassFilter_TpLockInAmp_T *localDW)
{
  b_dsp_FIRFilter_0_TpLockInAmp_T *obj_0;
  b_dspcodegen_FIRFilter_TpLock_T *obj;
  int32_T j;
  real32_T acc1;
  real32_T acc2;

  /* MATLABSystem: '<S1>/Lowpass Filter' */
  obj = localDW->obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (j = 0; j < 569; j++) {
      obj->cSFunObject.W0_states[j] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  /* Consume delay line and beginning of input samples */
  acc2 = rtu_0 * obj->cSFunObject.P1_Coefficients[0];
  acc1 = acc2;
  for (j = 0; j < 569; j++) {
    acc2 = obj_0->P1_Coefficients[j + 1] * obj_0->W0_states[j];
    acc1 += acc2;
  }

  /* Update delay line for next frame */
  for (j = 567; j >= 0; j--) {
    obj_0->W0_states[j + 1] = obj_0->W0_states[j];
  }

  obj->cSFunObject.W0_states[0] = rtu_0;

  /* MATLABSystem: '<S1>/Lowpass Filter' */
  localB->LowpassFilter = acc1;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void TpLockInAmp_LowpassFilter_Term(DW_LowpassFilter_TpLockInAmp_T *localDW)
{
  b_dspcodegen_FIRFilter_TpLock_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Lowpass Filter' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.FilterObj;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  if (!localDW->obj._pobj0.matlabCodegenIsDeleted) {
    localDW->obj._pobj0.matlabCodegenIsDeleted = true;
    if (localDW->obj._pobj0.isInitialized == 1) {
      localDW->obj._pobj0.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Lowpass Filter' */
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void TpLockInAmp_MovingAverage1_Init(DW_MovingAverage1_TpLockInAmp_T *localDW)
{
  dsp_simulink_MovingAverage_Tp_T *obj;
  g_dsp_private_SlidingWindowAv_T *obj_0;
  int32_T i;

  /* Start for MATLABSystem: '<S1>/Moving Average1' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  obj->_pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &obj->_pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average1' */
  obj_0 = localDW->obj.pStatistic;
  if (obj_0->isInitialized == 1) {
    obj_0->pCumSum = 0.0F;
    for (i = 0; i < 179; i++) {
      obj_0->pCumSumRev[i] = 0.0F;
    }

    obj_0->pCumRevIndex = 1.0F;
  }

  /* End of InitializeConditions for MATLABSystem: '<S1>/Moving Average1' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void TpLockInAmp_MovingAverage1(real32_T rtu_0, B_MovingAverage1_TpLockInAmp_T
  *localB, DW_MovingAverage1_TpLockInAmp_T *localDW)
{
  g_dsp_private_SlidingWindowAv_T *obj;
  int32_T i;
  real32_T csumrev[179];
  real32_T csum;
  real32_T cumRevIndex;
  real32_T z;

  /* MATLABSystem: '<S1>/Moving Average1' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0F;
    for (i = 0; i < 179; i++) {
      obj->pCumSumRev[i] = 0.0F;
    }

    obj->pCumRevIndex = 1.0F;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0F;
    for (i = 0; i < 179; i++) {
      obj->pCumSumRev[i] = 0.0F;
    }

    obj->pCumRevIndex = 1.0F;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 179; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  csum += rtu_0;
  z = csumrev[(int32_T)cumRevIndex - 1] + csum;
  csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 179.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    for (i = 177; i >= 0; i--) {
      csumrev[i] += csumrev[i + 1];
    }
  }

  obj->pCumSum = csum;
  for (i = 0; i < 179; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;

  /* MATLABSystem: '<S1>/Moving Average1' */
  localB->MovingAverage1 = z / 180.0F;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void TpLockInAmp_MovingAverage1_Term(DW_MovingAverage1_TpLockInAmp_T *localDW)
{
  g_dsp_private_SlidingWindowAv_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Moving Average1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average1' */
}

/* Model step function */
void TpLockInAmp_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Product;
  real32_T rtb_Product1;
  real32_T rtb_SineWave2;

  /* S-Function (sdspsine2): '<S1>/Sine Wave1' */
  rtb_SineWave2 = sinf(TpLockInAmp_DW.SineWave1_AccFreqNorm);

  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave1_AccFreqNorm += 0.52359879F;
  if (TpLockInAmp_DW.SineWave1_AccFreqNorm >= 6.28318548F) {
    TpLockInAmp_DW.SineWave1_AccFreqNorm -= 6.28318548F;
  } else {
    if (TpLockInAmp_DW.SineWave1_AccFreqNorm < 0.0F) {
      TpLockInAmp_DW.SineWave1_AccFreqNorm += 6.28318548F;
    }
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave1' */

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_Product = signal_input * rtb_SineWave2;
  TpLockInAmp_LowpassFilter(rtb_Product, &TpLockInAmp_B.LowpassFilter,
    &TpLockInAmp_DW.LowpassFilter);
  TpLockInAmp_MovingAverage1(TpLockInAmp_B.LowpassFilter.LowpassFilter,
    &TpLockInAmp_B.MovingAverage2, &TpLockInAmp_DW.MovingAverage2);

  /* S-Function (sdspsine2): '<S1>/Sine Wave2' */
  rtb_SineWave2 = sinf(TpLockInAmp_DW.SineWave2_AccFreqNorm);

  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave2_AccFreqNorm += 0.52359879F;
  if (TpLockInAmp_DW.SineWave2_AccFreqNorm >= 6.28318548F) {
    TpLockInAmp_DW.SineWave2_AccFreqNorm -= 6.28318548F;
  } else {
    if (TpLockInAmp_DW.SineWave2_AccFreqNorm < 0.0F) {
      TpLockInAmp_DW.SineWave2_AccFreqNorm += 6.28318548F;
    }
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave2' */

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_Product1 = signal_input * rtb_SineWave2;
  TpLockInAmp_LowpassFilter(rtb_Product1, &TpLockInAmp_B.LowpassFilter1,
    &TpLockInAmp_DW.LowpassFilter1);
  TpLockInAmp_MovingAverage1(TpLockInAmp_B.LowpassFilter1.LowpassFilter,
    &TpLockInAmp_B.MovingAverage1, &TpLockInAmp_DW.MovingAverage1);

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Product: '<S1>/Product2'
   *  Product: '<S1>/Product3'
   *  Sum: '<S1>/Add1'
   */
  signal_amp = sqrtf(TpLockInAmp_B.MovingAverage2.MovingAverage1 *
                     TpLockInAmp_B.MovingAverage2.MovingAverage1 +
                     TpLockInAmp_B.MovingAverage1.MovingAverage1 *
                     TpLockInAmp_B.MovingAverage1.MovingAverage1) * 2.0F;
}

/* Model initialize function */
void TpLockInAmp_initialize(void)
{
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */

  /* InitializeConditions for S-Function (sdspsine2): '<S1>/Sine Wave2' */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  TpLockInAmp_DW.SineWave2_AccFreqNorm = 1.57079637F;
  TpLockInAmp_LowpassFilter_Init(&TpLockInAmp_DW.LowpassFilter);
  TpLockInAmp_MovingAverage1_Init(&TpLockInAmp_DW.MovingAverage2);
  TpLockInAmp_LowpassFilter_Init(&TpLockInAmp_DW.LowpassFilter1);
  TpLockInAmp_MovingAverage1_Init(&TpLockInAmp_DW.MovingAverage1);
}

/* Model terminate function */
void TpLockInAmp_terminate(void)
{
  TpLockInAmp_LowpassFilter_Term(&TpLockInAmp_DW.LowpassFilter);
  TpLockInAmp_MovingAverage1_Term(&TpLockInAmp_DW.MovingAverage2);
  TpLockInAmp_LowpassFilter_Term(&TpLockInAmp_DW.LowpassFilter1);
  TpLockInAmp_MovingAverage1_Term(&TpLockInAmp_DW.MovingAverage1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
