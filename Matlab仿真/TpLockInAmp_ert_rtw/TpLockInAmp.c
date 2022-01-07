/*
 * File: TpLockInAmp.c
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
real_T product;                        /* '<S1>/Product' */
real_T product1;                       /* '<S1>/Product1' */
real_T signal_amp;                     /* '<S1>/MATLAB Function' */
real_T signal_input;                   /* '<Root>/In1' */
real_T signal_pha;                     /* '<S1>/Trigonometric Function' */
real_T sinewave1;                      /* '<S1>/Sine Wave1' */
real_T sinewave2;                      /* '<S1>/Sine Wave2' */
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
  if ((TpLockInAmp_M->Timing.TaskCounters.TID[1]) > 3) {/* Sample time: [0.004s, 0.0s] */
    TpLockInAmp_M->Timing.TaskCounters.TID[1] = 0;
  }

  (TpLockInAmp_M->Timing.TaskCounters.TID[2])++;
  if ((TpLockInAmp_M->Timing.TaskCounters.TID[2]) > 7) {/* Sample time: [0.008s, 0.0s] */
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
  static const real_T tmp[568] = { -6.98697293914566E-5, -8.5897558737065872E-5,
    -0.00010362744794495198, -0.00012301988662261916, -0.00014403883936188087,
    -0.00016659049289468675, -0.00019055023591195452, -0.00021573174467758824,
    -0.00024191136769696287, -0.00026879517215341436, -0.0002960965079472443,
    -0.00032349311175668534, -0.00035066121236053627, -0.0003771511737046533,
    -0.00040249881104642, -0.00042616106747722703, -0.00044754955720610135,
    -0.00046617625055390738, -0.00048149462593234709, -0.00049284127206433194,
    -0.00049946155972476988, -0.00050074534055111967, -0.00049631573607338767,
    -0.00048526729589533276, -0.000466669193854618, -0.00044089123028814874,
    -0.00040588416802622425, -0.00036224530662062079, -0.0003089591281832871,
    -0.00024558559349900351, -0.00017168505374396043, -8.6891006554317221E-5,
    9.0891000999796228E-6, 0.00011650683378892809, 0.00023551725623365216,
    0.00036616401424266243, 0.00050847619818930319, 0.00066228958128398139,
    0.000827390404722141, 0.0010034495225914105, 0.001190110974340867,
    0.0013867639658539386, 0.0015928146355777978, 0.0018075411901206906,
    0.0020301754312854223, 0.0022596649896670352, 0.0024951087184334588,
    0.0027354261554902465, 0.0029793201103121281, 0.0032257499835700297,
    0.0034732364899363452, 0.0037206627601053138, 0.0039665062641850929,
    0.0042091597210382236, 0.0044475778280526693, 0.0046801669771208759,
    0.0049055345201552839, 0.0051222659189745813, 0.0053290081536121877,
    0.0055244468748860184, 0.0057073117510106448, 0.0058763617903063109,
    0.0060306210702107347, 0.0061688783205114369, 0.0062903108034068154,
    0.0063941243199506885, 0.0064795252540014673, 0.0065460377706726856,
    0.0065931102179017254, 0.0066204982306668743, 0.0066280095645834588,
    0.0066155048410121283, 0.0065831867763847685, 0.0065312147477062429,
    0.0064599257882520062, 0.006369865394287166, 0.0062615894156720945,
    0.0061358269878024983, 0.005993480149766162, 0.0058354817846032045,
    0.0056628395301798239, 0.0054767157920475092, 0.0052783314599937712,
    0.00506896730510859, 0.0048499474886106913, 0.0046226410958042728,
    0.0043884623098613892, 0.0041488190005002949, 0.0039050728315971912,
    0.0036588854823768739, 0.0034113533112608016, 0.0031639669399254212,
    0.0029180727711956176, 0.0026749649970351777, 0.0024357436214694876,
    0.0022017042696862565, 0.0019738279291361036, 0.001753096526781503,
    0.001540458590803401, 0.0013366912519234128, 0.0011424937595468296,
    0.00095841852639042143, 0.00078507156765711536, 0.00062278567493437515,
    0.0004718206460919625, 0.0003324553282162993, 0.00020466994655566137,
    8.8573183312935083E-5, -1.5969379381783214E-5, -0.00010912663435379451,
    -0.00019116850252482039, -0.00026239904977311431, -0.00032320881739542626,
    -0.0003740492676484377, -0.00041588151712766962, -0.00044817298166497505,
    -0.0004719959558010613, -0.0004887234958412481, -0.00049799477187651808,
    -0.000500944738653094, -0.0004982902011601972, -0.00049042012361084214,
    -0.000478012008046952, -0.00046179819886700004, -0.00044245169098732412,
    -0.00042043642342762553, -0.00039630824011633551, -0.00037060987512136268,
    -0.00034391520913559272, -0.00031666154251079728, -0.00028924367416191635,
    -0.00026202072911886274, -0.00023528322055876323, -0.00020933406848383231,
    -0.00018443927309146768, -0.00016081550143583575, -0.00013863672330283292,
    -0.00011801771738576889, -9.9034394213843224E-5, -8.1732004336227012E-5,
    -6.6129137358238068E-5, 0.0, -6.6129137358238068E-5, -8.1732004336227012E-5,
    -9.9034394213843224E-5, -0.00011801771738576889, -0.00013863672330283292,
    -0.00016081550143583575, -0.00018443927309146768, -0.00020933406848383231,
    -0.00023528322055876323, -0.00026202072911886274, -0.00028924367416191635,
    -0.00031666154251079728, -0.00034391520913559272, -0.00037060987512136268,
    -0.00039630824011633551, -0.00042043642342762553, -0.00044245169098732412,
    -0.00046179819886700004, -0.000478012008046952, -0.00049042012361084214,
    -0.0004982902011601972, -0.000500944738653094, -0.00049799477187651808,
    -0.0004887234958412481, -0.0004719959558010613, -0.00044817298166497505,
    -0.00041588151712766962, -0.0003740492676484377, -0.00032320881739542626,
    -0.00026239904977311431, -0.00019116850252482039, -0.00010912663435379451,
    -1.5969379381783214E-5, 8.8573183312935083E-5, 0.00020466994655566137,
    0.0003324553282162993, 0.0004718206460919625, 0.00062278567493437515,
    0.00078507156765711536, 0.00095841852639042143, 0.0011424937595468296,
    0.0013366912519234128, 0.001540458590803401, 0.001753096526781503,
    0.0019738279291361036, 0.0022017042696862565, 0.0024357436214694876,
    0.0026749649970351777, 0.0029180727711956176, 0.0031639669399254212,
    0.0034113533112608016, 0.0036588854823768739, 0.0039050728315971912,
    0.0041488190005002949, 0.0043884623098613892, 0.0046226410958042728,
    0.0048499474886106913, 0.00506896730510859, 0.0052783314599937712,
    0.0054767157920475092, 0.0056628395301798239, 0.0058354817846032045,
    0.005993480149766162, 0.0061358269878024983, 0.0062615894156720945,
    0.006369865394287166, 0.0064599257882520062, 0.0065312147477062429,
    0.0065831867763847685, 0.0066155048410121283, 0.0066280095645834588,
    0.0066204982306668743, 0.0065931102179017254, 0.0065460377706726856,
    0.0064795252540014673, 0.0063941243199506885, 0.0062903108034068154,
    0.0061688783205114369, 0.0060306210702107347, 0.0058763617903063109,
    0.0057073117510106448, 0.0055244468748860184, 0.0053290081536121877,
    0.0051222659189745813, 0.0049055345201552839, 0.0046801669771208759,
    0.0044475778280526693, 0.0042091597210382236, 0.0039665062641850929,
    0.0037206627601053138, 0.0034732364899363452, 0.0032257499835700297,
    0.0029793201103121281, 0.0027354261554902465, 0.0024951087184334588,
    0.0022596649896670352, 0.0020301754312854223, 0.0018075411901206906,
    0.0015928146355777978, 0.0013867639658539386, 0.001190110974340867,
    0.0010034495225914105, 0.000827390404722141, 0.00066228958128398139,
    0.00050847619818930319, 0.00036616401424266243, 0.00023551725623365216,
    0.00011650683378892809, 9.0891000999796228E-6, -8.6891006554317221E-5,
    -0.00017168505374396043, -0.00024558559349900351, -0.0003089591281832871,
    -0.00036224530662062079, -0.00040588416802622425, -0.00044089123028814874,
    -0.000466669193854618, -0.00048526729589533276, -0.00049631573607338767,
    -0.00050074534055111967, -0.00049946155972476988, -0.00049284127206433194,
    -0.00048149462593234709, -0.00046617625055390738, -0.00044754955720610135,
    -0.00042616106747722703, -0.00040249881104642, -0.0003771511737046533,
    -0.00035066121236053627, -0.00032349311175668534, -0.0002960965079472443,
    -0.00026879517215341436, -0.00024191136769696287, -0.00021573174467758824,
    -0.00019055023591195452, -0.00016659049289468675, -0.00014403883936188087,
    -0.00012301988662261916, -0.00010362744794495198, -8.5897558737065872E-5,
    -6.98697293914566E-5, 0.0, -6.2497769899523E-5, -7.76703262689614E-5,
    -9.4550037512612585E-5, -0.00011311849897232038, -0.0001333320467064858,
    -0.00015513095809564721, -0.00017840539391693512, -0.00020300657546085951,
    -0.00022870795626515347, -0.00025530261383472703, -0.0002824189928973693,
    -0.00030981858475228886, -0.00033713130612994969, -0.00036401083354752582,
    -0.00039001478200201918, -0.0004145731081212723, -0.00043716965959090121,
    -0.0004572497008490644, -0.00047428365646147474, -0.00048771351627858507,
    -0.00049679145669386882, -0.00050079406419616189, -0.00049928230450934437,
    -0.00049170169668966168, -0.0004768895850585792, -0.00045480175006468377,
    -0.00042380111929518318, -0.00038526807632168012, -0.000336832237838907,
    -0.00027855933275649212, -0.00020997680997679176, -0.00013066737355817951,
    -4.0317428033997949E-5, 6.1359350258916468E-5, 0.000174558859508817,
    0.00029938301437742424, 0.00043591056699337583, 0.00058398212642261959,
    0.000743439285540216, 0.00091406510212088915, 0.0010955017931849672,
    0.0012872158592585751, 0.0014886527522187519, 0.0016991362875405018,
    0.001917936173541536, 0.0021441192457435968, 0.0023767038981404457,
    0.0026147429227226441, 0.0028569968697829619, 0.0031022837840134479,
    0.0033494689925381562, 0.0035970173134832655, 0.0038436920179607493,
    0.0040882415756761563, 0.0043290072572666066, 0.0045646840937417828,
    0.0047938424176203224, 0.005015065593309968, 0.0052269680914505089,
    0.0054282218202998753, 0.0056175242089277011, 0.0057936485665351324,
    0.0059553644466424013, 0.0061017587943901289, 0.0062317790458408587,
    0.006344462718207689, 0.0064391585347737387, 0.006515183474313695,
    0.0065720311392400256, 0.0066092807751480537, 0.0066267500628226618,
    0.0066242576592227863, 0.0066018107427911841, 0.0065596453846051648,
    0.0064979498629691088, 0.0064172239018549532, 0.0063179390231474508,
    0.0062008731464579915, 0.006066698809981016, 0.0059164272111455708,
    0.0057509177415884117, 0.0055713902017344684, 0.0053789793617476144,
    0.005174939200832774, 0.0049605816054334286, 0.0047372407109344625,
    0.0045063237764901027, 0.0042692332941294707, 0.0040273185475112527,
    0.0037822704053549604, 0.0035351235632343275, 0.00328759463611603,
    0.0030407284850513605, 0.0027961083389455377, 0.0025547830677223843,
    0.0023180027138050949, 0.0020869359746514479, 0.001862506882493536,
    0.0016457026365503053, 0.0014374200861213317, 0.0012383520385288317,
    0.0010491483829674741, 0.00087038960579448, 0.00070250677856486122,
    0.00054587453724787272, 0.00040068711971294024, 0.00026709122520560276,
    0.00014517109466930303, 3.4863128294741904E-5, -6.3956140886892588E-5,
    -0.00015151930551221809, -0.00022811404614726685, -0.00029407605969323575,
    -0.00034984321666364847, -0.00039589667183392505, -0.000432739566225176,
    -0.0004609411792221228, -0.00048131983754593394, -0.00049422542505011332,
    -0.00050019402483269322, -0.00050029792072981078, -0.00049497117153776,
    -0.00048472997669526914, -0.00047034018920489792, -0.00045247604068064326,
    -0.00043173641227268566, -0.0004085890702106157, -0.00038362390501745636,
    -0.00035736102095512489, -0.00033031915690718915, -0.00030296076689604083,
    -0.00027560863992291017, -0.00024856267581990191, -0.00022219461406248136,
    -0.00019674166503818083, -0.00017245387048144684, -0.00014953821307066783,
    -0.0001281250488776344, -0.00010832278214074019, -9.0171622567462753E-5,
    -7.3713886619518787E-5, -0.00053011797379672108, -0.00053011797379672108,
    -7.3713886619518787E-5, -9.0171622567462753E-5, -0.00010832278214074019,
    -0.0001281250488776344, -0.00014953821307066783, -0.00017245387048144684,
    -0.00019674166503818083, -0.00022219461406248136, -0.00024856267581990191,
    -0.00027560863992291017, -0.00030296076689604083, -0.00033031915690718915,
    -0.00035736102095512489, -0.00038362390501745636, -0.0004085890702106157,
    -0.00043173641227268566, -0.00045247604068064326, -0.00047034018920489792,
    -0.00048472997669526914, -0.00049497117153776, -0.00050029792072981078,
    -0.00050019402483269322, -0.00049422542505011332, -0.00048131983754593394,
    -0.0004609411792221228, -0.000432739566225176, -0.00039589667183392505,
    -0.00034984321666364847, -0.00029407605969323575, -0.00022811404614726685,
    -0.00015151930551221809, -6.3956140886892588E-5, 3.4863128294741904E-5,
    0.00014517109466930303, 0.00026709122520560276, 0.00040068711971294024,
    0.00054587453724787272, 0.00070250677856486122, 0.00087038960579448,
    0.0010491483829674741, 0.0012383520385288317, 0.0014374200861213317,
    0.0016457026365503053, 0.001862506882493536, 0.0020869359746514479,
    0.0023180027138050949, 0.0025547830677223843, 0.0027961083389455377,
    0.0030407284850513605, 0.00328759463611603, 0.0035351235632343275,
    0.0037822704053549604, 0.0040273185475112527, 0.0042692332941294707,
    0.0045063237764901027, 0.0047372407109344625, 0.0049605816054334286,
    0.005174939200832774, 0.0053789793617476144, 0.0055713902017344684,
    0.0057509177415884117, 0.0059164272111455708, 0.006066698809981016,
    0.0062008731464579915, 0.0063179390231474508, 0.0064172239018549532,
    0.0064979498629691088, 0.0065596453846051648, 0.0066018107427911841,
    0.0066242576592227863, 0.0066267500628226618, 0.0066092807751480537,
    0.0065720311392400256, 0.006515183474313695, 0.0064391585347737387,
    0.006344462718207689, 0.0062317790458408587, 0.0061017587943901289,
    0.0059553644466424013, 0.0057936485665351324, 0.0056175242089277011,
    0.0054282218202998753, 0.0052269680914505089, 0.005015065593309968,
    0.0047938424176203224, 0.0045646840937417828, 0.0043290072572666066,
    0.0040882415756761563, 0.0038436920179607493, 0.0035970173134832655,
    0.0033494689925381562, 0.0031022837840134479, 0.0028569968697829619,
    0.0026147429227226441, 0.0023767038981404457, 0.0021441192457435968,
    0.001917936173541536, 0.0016991362875405018, 0.0014886527522187519,
    0.0012872158592585751, 0.0010955017931849672, 0.00091406510212088915,
    0.000743439285540216, 0.00058398212642261959, 0.00043591056699337583,
    0.00029938301437742424, 0.000174558859508817, 6.1359350258916468E-5,
    -4.0317428033997949E-5, -0.00013066737355817951, -0.00020997680997679176,
    -0.00027855933275649212, -0.000336832237838907, -0.00038526807632168012,
    -0.00042380111929518318, -0.00045480175006468377, -0.0004768895850585792,
    -0.00049170169668966168, -0.00049928230450934437, -0.00050079406419616189,
    -0.00049679145669386882, -0.00048771351627858507, -0.00047428365646147474,
    -0.0004572497008490644, -0.00043716965959090121, -0.0004145731081212723,
    -0.00039001478200201918, -0.00036401083354752582, -0.00033713130612994969,
    -0.00030981858475228886, -0.0002824189928973693, -0.00025530261383472703,
    -0.00022870795626515347, -0.00020300657546085951, -0.00017840539391693512,
    -0.00015513095809564721, -0.0001333320467064858, -0.00011311849897232038,
    -9.4550037512612585E-5, -7.76703262689614E-5, -6.2497769899523E-5 };

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
  for (i = 0; i < 568; i++) {
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
    iobj_0->cSFunObject.W2_CoeffIdx = 426;
    iobj_0->cSFunObject.W0_PhaseIdx = 3;
    iobj_0->cSFunObject.W4_TapDelayIndex = 423;
    iobj_0->cSFunObject.W1_Sums = 0.0;
    for (i = 0; i < 564; i++) {
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
    obj->cSFunObject.W2_CoeffIdx = 426;
    obj->cSFunObject.W0_PhaseIdx = 3;
    obj->cSFunObject.W4_TapDelayIndex = 423;
    obj->cSFunObject.W1_Sums = 0.0;
    for (i = 0; i < 564; i++) {
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
  maxWindow = (phaseIdx + 1) * 141 - 141;
  for (i = 0; i < 8; i++) {
    obj_0->W1_Sums += rtu_0[inputIdx] * obj_0->P1_FILT[cffIdx];
    cffIdx++;
    for (jIdx = curTapIdx + 1; jIdx < maxWindow + 141; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
    }

    for (jIdx = maxWindow; jIdx <= curTapIdx; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
    }

    obj_0->W3_StatesBuff[curTapIdx] = rtu_0[inputIdx];
    inputIdx++;
    curTapIdx += 141;
    if (curTapIdx >= 564) {
      curTapIdx -= 564;
    }

    phaseIdx++;
    if (phaseIdx < 4) {
      maxWindow += 141;
    } else {
      obj_0->O0_Y0[outBufIdx] = obj_0->W1_Sums;
      outBufIdx++;
      obj_0->W1_Sums = 0.0;
      phaseIdx = 0;
      cffIdx = 0;
      curTapIdx--;
      if (curTapIdx < 0) {
        curTapIdx += 141;
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
  real_T rtb_Unbuffer1;
  real_T rtb_Unbuffer2;
  int32_T i;
  int32_T nSamps;
  int32_T nSampsAtBot;
  int32_T offsetFromMemBase;

  /* S-Function (sdspsine2): '<S1>/Sine Wave1' */
  sinewave1 = 5.0 * sin(TpLockInAmp_DW.SineWave1_AccFreqNorm);

  /* S-Function (sdspsine2): '<S1>/Sine Wave1' */
  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave1_AccFreqNorm += 0.12566370614359174;
  if (TpLockInAmp_DW.SineWave1_AccFreqNorm >= 6.2831853071795862) {
    TpLockInAmp_DW.SineWave1_AccFreqNorm -= 6.2831853071795862;
  } else {
    if (TpLockInAmp_DW.SineWave1_AccFreqNorm < 0.0) {
      TpLockInAmp_DW.SineWave1_AccFreqNorm += 6.2831853071795862;
    }
  }

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/In1'
   */
  product = signal_input * sinewave1;

  /* Buffer: '<S1>/Buffer' */
  nSamps = 16;
  offsetFromMemBase = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  if (16 - TpLockInAmp_DW.Buffer_inBufPtrIdx <= 1) {
    for (i = 0; i < 16 - TpLockInAmp_DW.Buffer_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer_CircBuf[TpLockInAmp_DW.Buffer_inBufPtrIdx + i] =
        product;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 15; i++) {
    TpLockInAmp_DW.Buffer_CircBuf[offsetFromMemBase + i] = product;
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
  sinewave2 = 5.0 * sin(TpLockInAmp_DW.SineWave2_AccFreqNorm);

  /* S-Function (sdspsine2): '<S1>/Sine Wave2' */
  /* Update accumulated normalized freq value
     for next sample.  Keep in range [0 2*pi) */
  TpLockInAmp_DW.SineWave2_AccFreqNorm += 0.12566370614359174;
  if (TpLockInAmp_DW.SineWave2_AccFreqNorm >= 6.2831853071795862) {
    TpLockInAmp_DW.SineWave2_AccFreqNorm -= 6.2831853071795862;
  } else {
    if (TpLockInAmp_DW.SineWave2_AccFreqNorm < 0.0) {
      TpLockInAmp_DW.SineWave2_AccFreqNorm += 6.2831853071795862;
    }
  }

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/In1'
   */
  product1 = signal_input * sinewave2;

  /* Buffer: '<S1>/Buffer1' */
  nSamps = 16;
  offsetFromMemBase = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  if (16 - TpLockInAmp_DW.Buffer1_inBufPtrIdx <= 1) {
    for (i = 0; i < 16 - TpLockInAmp_DW.Buffer1_inBufPtrIdx; i++) {
      TpLockInAmp_DW.Buffer1_CircBuf[TpLockInAmp_DW.Buffer1_inBufPtrIdx + i] =
        product1;
    }

    offsetFromMemBase = 0;
    nSamps = TpLockInAmp_DW.Buffer1_inBufPtrIdx;
  }

  for (i = 0; i < nSamps - 15; i++) {
    TpLockInAmp_DW.Buffer1_CircBuf[offsetFromMemBase + i] = product1;
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
    rtb_Unbuffer2 =
      TpLockInAmp_DW.Unbuffer2_CircBuff[TpLockInAmp_DW.Unbuffer2_memIdx];
    if (TpLockInAmp_DW.Unbuffer2_memIdx < 1) {
      TpLockInAmp_DW.Unbuffer2_memIdx++;
    }

    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Product: '<S1>/Product2'
     *  Product: '<S1>/Product3'
     *  Sum: '<S1>/Add1'
     */
    signal_amp = sqrt(rtb_Unbuffer1 * rtb_Unbuffer1 + rtb_Unbuffer2 *
                      rtb_Unbuffer2) * 2.0;

    /* Trigonometry: '<S1>/Trigonometric Function' incorporates:
     *  Product: '<S1>/Divide'
     */
    signal_pha = atan(rtb_Unbuffer1 / rtb_Unbuffer2);
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
