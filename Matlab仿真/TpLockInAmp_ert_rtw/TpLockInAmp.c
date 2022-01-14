/*
 * File: TpLockInAmp.c
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
real_T signal_amp;                     /* '<S1>/MATLAB Function' */
real_T signal_input;                   /* '<Root>/In1' */
real_T signal_pha;                     /* '<S1>/Trigonometric Function' */
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (TpLockInAmp_M->Timing.TaskCounters.TID[1])++;
  if ((TpLockInAmp_M->Timing.TaskCounters.TID[1]) > 3) {
                               /* Sample time: [0.0041666666666666666s, 0.0s] */
    TpLockInAmp_M->Timing.TaskCounters.TID[1] = 0;
  }

  (TpLockInAmp_M->Timing.TaskCounters.TID[2])++;
  if ((TpLockInAmp_M->Timing.TaskCounters.TID[2]) > 7) {
                               /* Sample time: [0.0083333333333333332s, 0.0s] */
    TpLockInAmp_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void T_CICCompensationDecimator_Init(DW_CICCompensationDecimator_T_T *localDW)
{
  static const real_T tmp[508] = { 1.9116705593954993E-5, 1.7571274216050618E-5,
    2.3542100047988739E-5, 3.1045624153773355E-5, 4.0092948888351311E-5,
    5.0867180070123966E-5, 6.3575814733591492E-5, 7.843165498344016E-5,
    9.5652651910537581E-5, 0.00011546937046114288, 0.00013811083961570435,
    0.00016379949540847665, 0.00019277126816660188, 0.00022525960359553988,
    0.00026149005669362822, 0.00030168557735425647, 0.00034605741753030616,
    0.00039479709162142806, 0.00044808602142191897, 0.00050609541732094573,
    0.00056897796248948722, 0.00063685301493073064, 0.00070980756231738256,
    0.00078791220333267274, 0.00087121780260143473, 0.00095973420111373565,
    0.0010534119325969085, 0.0011521896432669164, 0.0012559842382673973,
    0.0013646388515277177, 0.0014779481001636859, 0.0015957496984411788,
    0.0017176934788644353, 0.001843560436070119, 0.0019729080691434724,
    0.0021054293339370341, 0.0022406750529828873, 0.0023781810380697813,
    0.0025174612848930496, 0.0026579912480708548, 0.0027991715247025059,
    0.0029404721361369754, 0.0030812818418872959, 0.0032209577752660623,
    0.0033588847563289547, 0.0034944362501378927, 0.0036269103747944148,
    0.0037557167006570047, 0.0038802040647312954, 0.0039997097743213958,
    0.0041136258603931041, 0.0042213620989890984, 0.0043223457476847813,
    0.0044160320131654014, 0.004501908516359154, 0.004579499009462959,
    0.0046483795154482112, 0.0047081684463995254, 0.0047585144352149042,
    0.0047991364292103884, 0.0048298180424175257, 0.0048503610247979572,
    0.0048606697673049207, 0.0048606697673049207, 0.0048503610247979572,
    0.0048298180424175257, 0.0047991364292103884, 0.0047585144352149042,
    0.0047081684463995254, 0.0046483795154482112, 0.004579499009462959,
    0.004501908516359154, 0.0044160320131654014, 0.0043223457476847813,
    0.0042213620989890984, 0.0041136258603931041, 0.0039997097743213958,
    0.0038802040647312954, 0.0037557167006570047, 0.0036269103747944148,
    0.0034944362501378927, 0.0033588847563289547, 0.0032209577752660623,
    0.0030812818418872959, 0.0029404721361369754, 0.0027991715247025059,
    0.0026579912480708548, 0.0025174612848930496, 0.0023781810380697813,
    0.0022406750529828873, 0.0021054293339370341, 0.0019729080691434724,
    0.001843560436070119, 0.0017176934788644353, 0.0015957496984411788,
    0.0014779481001636859, 0.0013646388515277177, 0.0012559842382673973,
    0.0011521896432669164, 0.0010534119325969085, 0.00095973420111373565,
    0.00087121780260143473, 0.00078791220333267274, 0.00070980756231738256,
    0.00063685301493073064, 0.00056897796248948722, 0.00050609541732094573,
    0.00044808602142191897, 0.00039479709162142806, 0.00034605741753030616,
    0.00030168557735425647, 0.00026149005669362822, 0.00022525960359553988,
    0.00019277126816660188, 0.00016379949540847665, 0.00013811083961570435,
    0.00011546937046114288, 9.5652651910537581E-5, 7.843165498344016E-5,
    6.3575814733591492E-5, 5.0867180070123966E-5, 4.0092948888351311E-5,
    3.1045624153773355E-5, 2.3542100047988739E-5, 1.7571274216050618E-5,
    1.9116705593954993E-5, 0.0, -5.0307956808166488E-6, 1.5573605911708422E-5,
    2.1867967565201184E-5, 2.9030935963511513E-5, 3.767891196113044E-5,
    4.8002708232221478E-5, 6.0208333131308438E-5, 7.45063686766828E-5,
    9.1115537376359974E-5, 0.00011026122590634836, 0.00013217271685333768,
    0.000157080828886177, 0.00018521294320016996, 0.00021679685250011196,
    0.00025206927915795457, 0.00029125517469334592, 0.00033456400618948136,
    0.00038219312264728427, 0.00043432784677133228, 0.00049114413416530929,
    0.0005527980051690752, 0.0006194152468825783, 0.00069108998268264032,
    0.00076789830980113574, 0.0008498999460607421, 0.00093711586814011413,
    0.0010295077576763202, 0.001127018705424017, 0.0012295715833781635,
    0.001337036009008759, 0.0014491961769586951, 0.0015658953852021379,
    0.001686834088909257, 0.001811747216114072, 0.0019402545689761513,
    0.0020720438158618533, 0.0022066615929493779, 0.0023436399428973225,
    0.0024825037888934138, 0.0026227597048469431, 0.0027638543200023866,
    0.0029051694627446984, 0.0030461622237128688, 0.0031861768419781744,
    0.0033246156365110153, 0.0034607925458973576, 0.0035941228718933387,
    0.0037239117979161072, 0.0038495116013825929, 0.0039703135384662556,
    0.0040856910442115743, 0.0041950336913002479, 0.0042977610735968775,
    0.0043933206922872571, 0.0044811980983369354, 0.004560906556609714,
    0.0046320041350742282, 0.0046940972865790534, 0.0047468283149531727,
    0.0047899087785689271, 0.0048230932644402948, 0.0048461856778576722,
    0.0048590562407452029, 0.0048616395399111723, 0.0048539020258817995,
    0.0048359151904568609, 0.0048077468628350871, 0.0047695941320318423,
    0.0047216522101347965, 0.0046641935383466724, 0.00459755611070293,
    0.0045221068612300644, 0.004438256606614217, 0.0043464753254495439,
    0.0042472631892630664, 0.0041411538054398535, 0.00402871447506084,
    0.0039105486472951617, 0.0037872778085305285, 0.0036595030141068395,
    0.003527852492733516, 0.0033930249746628623, 0.0032556393479098548,
    0.0031163208816969196, 0.0029757573065132392, 0.0028345072362534088,
    0.0026932353967486561, 0.0025525175052456203, 0.0024128705659831927,
    0.0022748666888094838, 0.0021390093954866715, 0.0020057789490056737,
    0.0018755922902925031, 0.0017487999308991951, 0.0016258609341030616,
    0.001506990193662337, 0.0013925406892423785, 0.0012827047559735144,
    0.001177668848987599, 0.0010776266089369386, 0.0009826685770626736,
    0.00089285691967479533, 0.00080825016493347231, 0.000728848777864767,
    0.00065461232503581451, 0.00058547823470190153, 0.00052135860003993514,
    0.00046214204867988144, 0.00040768687381664137, 0.00035782800971508472,
    0.0003123844777272818, 0.00027116251872354033, 0.00023395889390491581,
    0.0002005576391336123, 0.00017072667083984462, 0.00014423785420027949,
    0.00012085958787703372, 0.0001003567988061895, 8.2507149096272927E-5,
    6.70830445701384E-5, 5.3856987134880578E-5, 4.2617940953945155E-5,
    3.31572672069207E-5, 2.52783698702088E-5, 1.8727697245788167E-5,
    1.0808241747924549E-5, 2.2583708660223944E-5, 5.029800446505052E-5,
    1.5884212521745742E-5, 2.0331895798273927E-5, 2.711229490069894E-5,
    3.5364819246541119E-5, 4.52519834596391E-5, 5.6968149998125033E-5,
    7.0719804174566454E-5, 8.6733666903220268E-5, 0.00010522323700056864,
    0.00012642157971386823, 0.00015055849627000707, 0.00017786042680991153,
    0.00020856282408084949, 0.00024289456192683913, 0.00028107986523630182,
    0.00032333762128759086, 0.00036986929462634117, 0.00042086217493685741,
    0.00047649197662850772, 0.00053692076222688131, 0.0006022880482664,
    0.00067269144266273926, 0.00074821164998002936, 0.00082891425084351516,
    0.00091482607152345359, 0.0010059296175789635, 0.0011021686322275747,
    0.0012034671926617804, 0.0013097195651460083, 0.0014207192599267674,
    0.0015363047328643207, 0.0016562264400164927, 0.0017801499423832526,
    0.001907813841262336, 0.0020388340125961778, 0.0021727678101922652,
    0.0023092031075049287, 0.0024476580402035871, 0.0025875968932910043,
    0.0027285199932496978, 0.0028698585561600558, 0.0030109683974283183,
    0.0031513061753868847, 0.0032901753844003893, 0.0034270023402112192,
    0.003561095870004059, 0.0036918143115710379, 0.0038185386605700798,
    0.0039406145518518934, 0.0040574075336981584, 0.0041683094441748317,
    0.004272736429276407, 0.0043701363460739544, 0.0044599791932727183,
    0.0045417715857383146, 0.00461505933730677, 0.0046794326691295606,
    0.0047345359637002045, 0.0047800600629360106, 0.0048157323635889737,
    0.0048413668729690752, 0.0048567976936683592, 0.0048619612599322664,
    0.0048567976936683592, 0.0048413668729690752, 0.0048157323635889737,
    0.0047800600629360106, 0.0047345359637002045, 0.0046794326691295606,
    0.00461505933730677, 0.0045417715857383146, 0.0044599791932727183,
    0.0043701363460739544, 0.004272736429276407, 0.0041683094441748317,
    0.0040574075336981584, 0.0039406145518518934, 0.0038185386605700798,
    0.0036918143115710379, 0.003561095870004059, 0.0034270023402112192,
    0.0032901753844003893, 0.0031513061753868847, 0.0030109683974283183,
    0.0028698585561600558, 0.0027285199932496978, 0.0025875968932910043,
    0.0024476580402035871, 0.0023092031075049287, 0.0021727678101922652,
    0.0020388340125961778, 0.001907813841262336, 0.0017801499423832526,
    0.0016562264400164927, 0.0015363047328643207, 0.0014207192599267674,
    0.0013097195651460083, 0.0012034671926617804, 0.0011021686322275747,
    0.0010059296175789635, 0.00091482607152345359, 0.00082891425084351516,
    0.00074821164998002936, 0.00067269144266273926, 0.0006022880482664,
    0.00053692076222688131, 0.00047649197662850772, 0.00042086217493685741,
    0.00036986929462634117, 0.00032333762128759086, 0.00028107986523630182,
    0.00024289456192683913, 0.00020856282408084949, 0.00017786042680991153,
    0.00015055849627000707, 0.00012642157971386823, 0.00010522323700056864,
    8.6733666903220268E-5, 7.0719804174566454E-5, 5.6968149998125033E-5,
    4.52519834596391E-5, 3.5364819246541119E-5, 2.711229490069894E-5,
    2.0331895798273927E-5, 1.5884212521745742E-5, 5.029800446505052E-5,
    2.2583708660223944E-5, 1.0808241747924549E-5, 1.8727697245788167E-5,
    2.52783698702088E-5, 3.31572672069207E-5, 4.2617940953945155E-5,
    5.3856987134880578E-5, 6.70830445701384E-5, 8.2507149096272927E-5,
    0.0001003567988061895, 0.00012085958787703372, 0.00014423785420027949,
    0.00017072667083984462, 0.0002005576391336123, 0.00023395889390491581,
    0.00027116251872354033, 0.0003123844777272818, 0.00035782800971508472,
    0.00040768687381664137, 0.00046214204867988144, 0.00052135860003993514,
    0.00058547823470190153, 0.00065461232503581451, 0.000728848777864767,
    0.00080825016493347231, 0.00089285691967479533, 0.0009826685770626736,
    0.0010776266089369386, 0.001177668848987599, 0.0012827047559735144,
    0.0013925406892423785, 0.001506990193662337, 0.0016258609341030616,
    0.0017487999308991951, 0.0018755922902925031, 0.0020057789490056737,
    0.0021390093954866715, 0.0022748666888094838, 0.0024128705659831927,
    0.0025525175052456203, 0.0026932353967486561, 0.0028345072362534088,
    0.0029757573065132392, 0.0031163208816969196, 0.0032556393479098548,
    0.0033930249746628623, 0.003527852492733516, 0.0036595030141068395,
    0.0037872778085305285, 0.0039105486472951617, 0.00402871447506084,
    0.0041411538054398535, 0.0042472631892630664, 0.0043464753254495439,
    0.004438256606614217, 0.0045221068612300644, 0.00459755611070293,
    0.0046641935383466724, 0.0047216522101347965, 0.0047695941320318423,
    0.0048077468628350871, 0.0048359151904568609, 0.0048539020258817995,
    0.0048616395399111723, 0.0048590562407452029, 0.0048461856778576722,
    0.0048230932644402948, 0.0047899087785689271, 0.0047468283149531727,
    0.0046940972865790534, 0.0046320041350742282, 0.004560906556609714,
    0.0044811980983369354, 0.0043933206922872571, 0.0042977610735968775,
    0.0041950336913002479, 0.0040856910442115743, 0.0039703135384662556,
    0.0038495116013825929, 0.0037239117979161072, 0.0035941228718933387,
    0.0034607925458973576, 0.0033246156365110153, 0.0031861768419781744,
    0.0030461622237128688, 0.0029051694627446984, 0.0027638543200023866,
    0.0026227597048469431, 0.0024825037888934138, 0.0023436399428973225,
    0.0022066615929493779, 0.0020720438158618533, 0.0019402545689761513,
    0.001811747216114072, 0.001686834088909257, 0.0015658953852021379,
    0.0014491961769586951, 0.001337036009008759, 0.0012295715833781635,
    0.001127018705424017, 0.0010295077576763202, 0.00093711586814011413,
    0.0008498999460607421, 0.00076789830980113574, 0.00069108998268264032,
    0.0006194152468825783, 0.0005527980051690752, 0.00049114413416530929,
    0.00043432784677133228, 0.00038219312264728427, 0.00033456400618948136,
    0.00029125517469334592, 0.00025206927915795457, 0.00021679685250011196,
    0.00018521294320016996, 0.000157080828886177, 0.00013217271685333768,
    0.00011026122590634836, 9.1115537376359974E-5, 7.45063686766828E-5,
    6.0208333131308438E-5, 4.8002708232221478E-5, 3.767891196113044E-5,
    2.9030935963511513E-5, 2.1867967565201184E-5, 1.5573605911708422E-5,
    -5.0307956808166488E-6 };

  b_dspcodegen_FIRDecimator_TpL_T *iobj_0;
  dsp_CICCompensationDecimator__T *obj;
  int32_T i;
  boolean_T wasTunablePropsChanged;

  /* Start for MATLABSystem: '<S1>/CIC Compensation Decimator' */
  localDW->obj._pobj0.matlabCodegenIsDeleted = true;
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.TunablePropsChanged = false;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  wasTunablePropsChanged = localDW->obj.TunablePropsChanged;
  localDW->obj.TunablePropsChanged = wasTunablePropsChanged;
  iobj_0 = &localDW->obj._pobj0;
  obj->_pobj0.isInitialized = 0;

  /* System object Constructor function: dsp.FIRDecimator */
  localDW->obj._pobj0.cSFunObject.P0_IC = 0.0;
  for (i = 0; i < 508; i++) {
    iobj_0->cSFunObject.P1_FILT[i] = tmp[i];
  }

  obj->_pobj0.matlabCodegenIsDeleted = false;
  localDW->obj.pFIRDecimator = &obj->_pobj0;
  iobj_0 = localDW->obj.pFIRDecimator;
  iobj_0->isSetupComplete = false;
  iobj_0->isInitialized = 1;
  iobj_0->isSetupComplete = true;
  localDW->obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<S1>/CIC Compensation Decimator' */

  /* InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator' */
  iobj_0 = localDW->obj.pFIRDecimator;
  if (iobj_0->isInitialized == 1) {
    /* System object Initialization function: dsp.FIRDecimator */
    iobj_0->cSFunObject.W2_CoeffIdx = 381;
    iobj_0->cSFunObject.W0_PhaseIdx = 3;
    iobj_0->cSFunObject.W4_TapDelayIndex = 378;
    iobj_0->cSFunObject.W1_Sums = 0.0;
    for (i = 0; i < 504; i++) {
      iobj_0->cSFunObject.W3_StatesBuff[i] = 0.0;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S1>/CIC Compensation Decimator' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void TpLock_CICCompensationDecimator(const real_T rtu_0[8],
  B_CICCompensationDecimator_Tp_T *localB, DW_CICCompensationDecimator_T_T
  *localDW)
{
  b_dsp_FIRDecimator_0_TpLockIn_T *obj_0;
  b_dspcodegen_FIRDecimator_TpL_T *obj;
  int32_T cffIdx;
  int32_T curTapIdx;
  int32_T i;
  int32_T inputIdx;
  int32_T jIdx;
  int32_T maxWindow;
  int32_T outBufIdx;
  int32_T phaseIdx;

  /* MATLABSystem: '<S1>/CIC Compensation Decimator' */
  obj = localDW->obj.pFIRDecimator;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRDecimator */
    obj->cSFunObject.W2_CoeffIdx = 381;
    obj->cSFunObject.W0_PhaseIdx = 3;
    obj->cSFunObject.W4_TapDelayIndex = 378;
    obj->cSFunObject.W1_Sums = 0.0;
    for (i = 0; i < 504; i++) {
      obj->cSFunObject.W3_StatesBuff[i] = 0.0;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRDecimator */
  inputIdx = 0;
  curTapIdx = obj->cSFunObject.W4_TapDelayIndex;
  phaseIdx = obj->cSFunObject.W0_PhaseIdx;
  cffIdx = obj->cSFunObject.W2_CoeffIdx;
  outBufIdx = 0;
  maxWindow = (phaseIdx + 1) * 126 - 126;
  for (i = 0; i < 8; i++) {
    obj_0->W1_Sums += rtu_0[inputIdx] * obj_0->P1_FILT[cffIdx];
    cffIdx++;
    for (jIdx = curTapIdx + 1; jIdx < maxWindow + 126; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
    }

    for (jIdx = maxWindow; jIdx <= curTapIdx; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
    }

    obj_0->W3_StatesBuff[curTapIdx] = rtu_0[inputIdx];
    inputIdx++;
    curTapIdx += 126;
    if (curTapIdx >= 504) {
      curTapIdx -= 504;
    }

    phaseIdx++;
    if (phaseIdx < 4) {
      maxWindow += 126;
    } else {
      obj_0->O0_Y0[outBufIdx] = obj_0->W1_Sums;
      outBufIdx++;
      obj_0->W1_Sums = 0.0;
      phaseIdx = 0;
      cffIdx = 0;
      curTapIdx--;
      if (curTapIdx < 0) {
        curTapIdx += 126;
      }

      maxWindow = 0;
    }
  }

  obj->cSFunObject.W4_TapDelayIndex = curTapIdx;
  obj->cSFunObject.W2_CoeffIdx = cffIdx;
  obj->cSFunObject.W0_PhaseIdx = phaseIdx;

  /* MATLABSystem: '<S1>/CIC Compensation Decimator' */
  localB->CICCompensationDecimator[0] = obj->cSFunObject.O0_Y0[0];
  localB->CICCompensationDecimator[1] = obj->cSFunObject.O0_Y0[1];
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void T_CICCompensationDecimator_Term(DW_CICCompensationDecimator_T_T *localDW)
{
  b_dspcodegen_FIRDecimator_TpL_T *obj;

  /* Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pFIRDecimator;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }
    }
  }

  if (!localDW->obj._pobj0.matlabCodegenIsDeleted) {
    localDW->obj._pobj0.matlabCodegenIsDeleted = true;
    if (localDW->obj._pobj0.isInitialized == 1) {
      localDW->obj._pobj0.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/CIC Compensation Decimator' */
}

/* Model step function */
void TpLockInAmp_step(void)
{
  /* local block i/o variables */
  real_T rtb_Buffer[8];
  real_T rtb_Buffer1[8];
  real_T rtb_SineWave2;
  real_T rtb_Unbuffer1;
  int32_T i;
  int32_T nSamps;
  int32_T nSampsAtBot;
  int32_T offsetFromMemBase;

  /* S-Function (sdspsine2): '<S1>/Sine Wave1' */
  rtb_SineWave2 = sin(TpLockInAmp_DW.SineWave1_AccFreqNorm);

  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave1_AccFreqNorm += 0.1308996938995747;
  if (TpLockInAmp_DW.SineWave1_AccFreqNorm >= 6.2831853071795862) {
    TpLockInAmp_DW.SineWave1_AccFreqNorm -= 6.2831853071795862;
  } else {
    if (TpLockInAmp_DW.SineWave1_AccFreqNorm < 0.0) {
      TpLockInAmp_DW.SineWave1_AccFreqNorm += 6.2831853071795862;
    }
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave1' */

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_SineWave2 *= signal_input;

  /* Buffer: '<S1>/Buffer' */
  nSamps = 16;
  offsetFromMemBase = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  if (16 - TpLockInAmp_DW.Buffer_inBufPtrIdx <= 1) {
    for (i = 0; i < 16 - TpLockInAmp_DW.Buffer_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_inBufPtrIdx + i] =
        rtb_SineWave2;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 15; i++) {
    TpLockInAmp_DW.Buffer_CircBuf[offsetFromMemBase + i] = rtb_SineWave2;
  }

  TpLockInAmp_DW.Buffer_inBufPtrIdx++;
  if (TpLockInAmp_DW.Buffer_inBufPtrIdx >= 16) {
    TpLockInAmp_DW.Buffer_inBufPtrIdx -= 16;
  }

  TpLockInAmp_DW.Buffer_bufferLength++;
  if (TpLockInAmp_DW.Buffer_bufferLength > 16) {
    TpLockInAmp_DW.Buffer_outBufPtrIdx = (TpLockInAmp_DW.Buffer_outBufPtrIdx +
      TpLockInAmp_DW.Buffer_bufferLength) - 16;
    if (TpLockInAmp_DW.Buffer_outBufPtrIdx > 16) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx -= 16;
    }

    TpLockInAmp_DW.Buffer_bufferLength = 16;
  }

  if (TpLockInAmp_M->Timing.TaskCounters.TID[2] == 0) {
    TpLockInAmp_DW.Buffer_bufferLength -= 8;
    if (TpLockInAmp_DW.Buffer_bufferLength < 0) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx += TpLockInAmp_DW.Buffer_bufferLength;
      if (TpLockInAmp_DW.Buffer_outBufPtrIdx < 0) {
        TpLockInAmp_DW.Buffer_outBufPtrIdx += 16;
      }

      TpLockInAmp_DW.Buffer_bufferLength = 0;
    }

    offsetFromMemBase = 0;
    if (TpLockInAmp_DW.Buffer_outBufPtrIdx < 0) {
      TpLockInAmp_DW.Buffer_outBufPtrIdx += 16;
    }

    nSampsAtBot = 16 - TpLockInAmp_DW.Buffer_outBufPtrIdx;
    nSamps = 8;
    if (16 - TpLockInAmp_DW.Buffer_outBufPtrIdx <= 8) {
      for (i = 0; i < 16 - TpLockInAmp_DW.Buffer_outBufPtrIdx; i++) {
        rtb_Buffer[i] =
          TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_outBufPtrIdx + i];
      }

      offsetFromMemBase = 16 - TpLockInAmp_DW.Buffer_outBufPtrIdx;
      TpLockInAmp_DW.Buffer_outBufPtrIdx = 0;
      nSamps = 8 - nSampsAtBot;
    }

    for (i = 0; i < nSamps; i++) {
      rtb_Buffer[offsetFromMemBase + i] =
        TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_outBufPtrIdx + i];
    }

    TpLockInAmp_DW.Buffer_outBufPtrIdx += nSamps;
    TpLock_CICCompensationDecimator(rtb_Buffer,
      &TpLockInAmp_B.CICCompensationDecimator,
      &TpLockInAmp_DW.CICCompensationDecimator);

    /* Unbuffer: '<S1>/Unbuffer1' incorporates:
     *  Buffer: '<S1>/Buffer'
     *  MATLABSystem: '<S1>/CIC Compensation Decimator'
     */
    TpLockInAmp_DW.Unbuffer1_CircBuff[0] =
      TpLockInAmp_B.CICCompensationDecimator.CICCompensationDecimator[0];
    TpLockInAmp_DW.Unbuffer1_CircBuff[1] =
      TpLockInAmp_B.CICCompensationDecimator.CICCompensationDecimator[1];
    TpLockInAmp_DW.Unbuffer1_memIdx = 0;
  }

  /* End of Buffer: '<S1>/Buffer' */

  /* Unbuffer: '<S1>/Unbuffer1' */
  if (TpLockInAmp_M->Timing.TaskCounters.TID[1] == 0) {
    rtb_Unbuffer1 =
      TpLockInAmp_DW.Unbuffer1_CircBuff[TpLockInAmp_DW.Unbuffer1_memIdx];
    if (TpLockInAmp_DW.Unbuffer1_memIdx < 1) {
      TpLockInAmp_DW.Unbuffer1_memIdx++;
    }
  }

  /* S-Function (sdspsine2): '<S1>/Sine Wave2' */
  rtb_SineWave2 = sin(TpLockInAmp_DW.SineWave2_AccFreqNorm);

  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave2_AccFreqNorm += 0.1308996938995747;
  if (TpLockInAmp_DW.SineWave2_AccFreqNorm >= 6.2831853071795862) {
    TpLockInAmp_DW.SineWave2_AccFreqNorm -= 6.2831853071795862;
  } else {
    if (TpLockInAmp_DW.SineWave2_AccFreqNorm < 0.0) {
      TpLockInAmp_DW.SineWave2_AccFreqNorm += 6.2831853071795862;
    }
  }

  /* End of S-Function (sdspsine2): '<S1>/Sine Wave2' */

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_SineWave2 *= signal_input;

  /* Buffer: '<S1>/Buffer1' */
  nSamps = 16;
  offsetFromMemBase = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  if (16 - TpLockInAmp_DW.Buffer1_inBufPtrIdx <= 1) {
    for (i = 0; i < 16 - TpLockInAmp_DW.Buffer1_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_inBufPtrIdx + i] =
        rtb_SineWave2;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 15; i++) {
    TpLockInAmp_DW.Buffer1_CircBuf[offsetFromMemBase + i] = rtb_SineWave2;
  }

  TpLockInAmp_DW.Buffer1_inBufPtrIdx++;
  if (TpLockInAmp_DW.Buffer1_inBufPtrIdx >= 16) {
    TpLockInAmp_DW.Buffer1_inBufPtrIdx -= 16;
  }

  TpLockInAmp_DW.Buffer1_bufferLength++;
  if (TpLockInAmp_DW.Buffer1_bufferLength > 16) {
    TpLockInAmp_DW.Buffer1_outBufPtrIdx = (TpLockInAmp_DW.Buffer1_outBufPtrIdx +
      TpLockInAmp_DW.Buffer1_bufferLength) - 16;
    if (TpLockInAmp_DW.Buffer1_outBufPtrIdx > 16) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx -= 16;
    }

    TpLockInAmp_DW.Buffer1_bufferLength = 16;
  }

  if (TpLockInAmp_M->Timing.TaskCounters.TID[2] == 0) {
    TpLockInAmp_DW.Buffer1_bufferLength -= 8;
    if (TpLockInAmp_DW.Buffer1_bufferLength < 0) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx += TpLockInAmp_DW.Buffer1_bufferLength;
      if (TpLockInAmp_DW.Buffer1_outBufPtrIdx < 0) {
        TpLockInAmp_DW.Buffer1_outBufPtrIdx += 16;
      }

      TpLockInAmp_DW.Buffer1_bufferLength = 0;
    }

    offsetFromMemBase = 0;
    if (TpLockInAmp_DW.Buffer1_outBufPtrIdx < 0) {
      TpLockInAmp_DW.Buffer1_outBufPtrIdx += 16;
    }

    nSampsAtBot = 16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx;
    nSamps = 8;
    if (16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx <= 8) {
      for (i = 0; i < 16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx; i++) {
        rtb_Buffer1[i] =
          TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_outBufPtrIdx + i];
      }

      offsetFromMemBase = 16 - TpLockInAmp_DW.Buffer1_outBufPtrIdx;
      TpLockInAmp_DW.Buffer1_outBufPtrIdx = 0;
      nSamps = 8 - nSampsAtBot;
    }

    for (i = 0; i < nSamps; i++) {
      rtb_Buffer1[offsetFromMemBase + i] =
        TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_outBufPtrIdx + i];
    }

    TpLockInAmp_DW.Buffer1_outBufPtrIdx += nSamps;
    TpLock_CICCompensationDecimator(rtb_Buffer1,
      &TpLockInAmp_B.CICCompensationDecimator1,
      &TpLockInAmp_DW.CICCompensationDecimator1);

    /* Unbuffer: '<S1>/Unbuffer2' incorporates:
     *  Buffer: '<S1>/Buffer1'
     *  MATLABSystem: '<S1>/CIC Compensation Decimator1'
     */
    TpLockInAmp_DW.Unbuffer2_CircBuff[0] =
      TpLockInAmp_B.CICCompensationDecimator1.CICCompensationDecimator[0];
    TpLockInAmp_DW.Unbuffer2_CircBuff[1] =
      TpLockInAmp_B.CICCompensationDecimator1.CICCompensationDecimator[1];
    TpLockInAmp_DW.Unbuffer2_memIdx = 0;
  }

  /* End of Buffer: '<S1>/Buffer1' */

  /* Unbuffer: '<S1>/Unbuffer2' */
  if (TpLockInAmp_M->Timing.TaskCounters.TID[1] == 0) {
    rtb_SineWave2 =
      TpLockInAmp_DW.Unbuffer2_CircBuff[TpLockInAmp_DW.Unbuffer2_memIdx];
    if (TpLockInAmp_DW.Unbuffer2_memIdx < 1) {
      TpLockInAmp_DW.Unbuffer2_memIdx++;
    }

    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Product: '<S1>/Product2'
     *  Product: '<S1>/Product3'
     *  Sum: '<S1>/Add1'
     */
    signal_amp = sqrt(rtb_Unbuffer1 * rtb_Unbuffer1 + rtb_SineWave2 *
                      rtb_SineWave2) * 2.0;

    /* Trigonometry: '<S1>/Trigonometric Function' incorporates:
     *  Product: '<S1>/Divide'
     */
    signal_pha = atan(rtb_Unbuffer1 / rtb_SineWave2);
  }

  rate_scheduler();
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

  /* InitializeConditions for Buffer: '<S1>/Buffer' */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  TpLockInAmp_DW.Buffer_inBufPtrIdx = 8;
  TpLockInAmp_DW.Buffer_bufferLength = 8;

  /* InitializeConditions for S-Function (sdspsine2): '<S1>/Sine Wave2' */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  TpLockInAmp_DW.SineWave2_AccFreqNorm = 1.5707963267948966;

  /* InitializeConditions for Buffer: '<S1>/Buffer1' */
  TpLockInAmp_DW.Buffer1_inBufPtrIdx = 8;
  TpLockInAmp_DW.Buffer1_bufferLength = 8;
  T_CICCompensationDecimator_Init(&TpLockInAmp_DW.CICCompensationDecimator);
  T_CICCompensationDecimator_Init(&TpLockInAmp_DW.CICCompensationDecimator1);
}

/* Model terminate function */
void TpLockInAmp_terminate(void)
{
  T_CICCompensationDecimator_Term(&TpLockInAmp_DW.CICCompensationDecimator);
  T_CICCompensationDecimator_Term(&TpLockInAmp_DW.CICCompensationDecimator1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
