/*
 * File: TpLockInAmp.c
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
  static const real_T tmp[544] = { -7.2714332828795485E-5,
    -9.0120954701438684E-5, -0.00010945146779746249, -0.0001306820874754246,
    -0.00015370759303421738, -0.00017842657427060115, -0.00020468015602867408,
    -0.00023229075588404461, -0.00026094388620766077, -0.00029031082651764518,
    -0.0003200356129464503, -0.00034969202758580059, -0.00037886409969917646,
    -0.00040704214586459854, -0.00043364501238500348, -0.00045798285197048619,
    -0.00047939516744318879, -0.00049725563781124994, -0.0005109026937415986,
    -0.00051954914095196582, -0.00052230451045506, -0.0005184642678305101,
    -0.00050752103453045221, -0.00048841595777255969, -0.00046023477176276807,
    -0.00042308188830163094, -0.00037503677220598441, -0.00031656755110235697,
    -0.00024656673882810138, -0.00016464264711997431, -7.02889172592217E-5,
    3.6735785577682962E-5, 0.000156710888810145, 0.00028982634764948567,
    0.00043609461324888249, 0.00059546976269535755, 0.00076776029784069257,
    0.00095263056765269784, 0.0011496563318115875, 0.0013583259881900232,
    0.0015779228831079386, 0.0018076113011157163, 0.0020464723092323755,
    0.0022934896229431204, 0.00254750623486489, 0.0028072031791727525,
    0.0030712767836724659, 0.0033382967842870027, 0.0036066699797203737,
    0.0038749727750450528, 0.0041414006299919232, 0.0044045608103191461,
    0.0046626104356235695, 0.0049136672994331936, 0.0051564466215787835,
    0.0053891589542369809, 0.0056101751059685406, 0.005818039813582661,
    0.006011257824972617, 0.0061884015539193735, 0.0063482688954380993,
    0.0064896357701849719, 0.0066115493617965506, 0.0067130621208737213,
    0.00679346061969954, 0.0068521175581522237, 0.0068886170361975307,
    0.0069027095819426789, 0.0068942454017221627, 0.0068633331432694372,
    0.006810185308110249, 0.0067351637161330528, 0.0066388735229927082,
    0.0065219838842133816, 0.0063853834012265907, 0.0062300355659316992,
    0.00605709488105954, 0.0058677494933969555, 0.005663435166437236,
    0.0054455911614666209, 0.0052156332083100341, 0.0049752158124108971,
    0.0047258700609739968, 0.0044695373785125624, 0.0042075528986448858,
    0.0039418379304998023, 0.0036738109239125576, 0.00340532443645309,
    0.0031378185752344015, 0.0028728529916150496, 0.0026119488227710512,
    0.0023563947706633122, 0.0021075043951756978, 0.001866504825879223,
    0.0016344347558074721, 0.0014122269483569103, 0.0012007568368064203,
    0.0010007644607162567, 0.00081281866019155646, 0.00063733849462713221,
    0.00047471625063728249, 0.00032515061682303158, 0.00018875682632302752,
    6.5515879820194441E-5, -4.4746243870273877E-5, -0.00014218942767751068,
    -0.00022721769579038, -0.00030016119513285477, -0.00036153946953162714,
    -0.00041180461523107479, -0.00045186045169718107, -0.00048221419488123031,
    -0.00050354689929956939, -0.00051642002147602893, -0.00052198114700849059,
    -0.00052082215469092521, -0.00051356677385285844, -0.00050109609898744511,
    -0.00048421416656688074, -0.00046363512254886488, -0.00043996725491763625,
    -0.00041386606926286848, -0.00038602679228993042, -0.00035704928837753216,
    -0.00032747046068418455, -0.0002977205998591429, -0.00026823174518450336,
    -0.00023935951072665245, -0.0002114787286856682, -0.00018485675321765514,
    -0.00015972490932381441, -0.00013626069551155528, -0.0001145762478087726,
    -9.4772534708761718E-5, -7.6884862727246187E-5, -0.00052633996473955844,
    -6.8665462784000934E-5, -8.5589412898523216E-5, -0.00010443817076041351,
    -0.00012517360607426355, -0.00014777923860694525, -0.00017208779096756669,
    -0.00019798289327849726, -0.00022528239385782433, -0.00025369711063378885,
    -0.0002829214889524323, -0.000312591587388045, -0.00034230278028430088,
    -0.0003716456401932872, -0.00040012607721850329, -0.00042717713690815565,
    -0.00045214519984069509, -0.00047435149265046309, -0.00049315233223843919,
    -0.00050792567033385093, -0.00051791398386965149, -0.00052221001603756229,
    -0.00052005922091325429, -0.00051095523847901345, -0.00049402907614949881,
    -0.00046809867665934348, -0.0004334138184832695, -0.0003885422937837705,
    -0.0003322611795319629, -0.0002651676266491118, -0.00018624553591258637,
    -9.5073561461815614E-5, 8.7546070817932876E-6, 0.00012548892709157933,
    0.00025531468224675982, 0.00039828579300918248, 0.00055441046147556444,
    0.00072349319544659984, 0.00090525371743225961, 0.0010992850937805434,
    0.0013051061284106921, 0.0015220404173487251, 0.0017492897080464763,
    0.0019859551720165141, 0.002231028409318216, 0.0024834194823418528,
    0.0027418176824048793, 0.0030049143065661206, 0.0032713501894769967,
    0.003539519915865996, 0.0038080038850251546, 0.004075062368086484,
    0.0043391937508463242, 0.0045985165846269514, 0.0048515902177125123,
    0.0050966313699402754, 0.0053320150593746873, 0.0055561806237017126,
    0.0057674296548045224, 0.0059643991909294125, 0.0061456711625206377,
    0.0063100048139513917, 0.006456078837857945, 0.0065829559078893259,
    0.0066896425668744128, 0.0067753767189279047, 0.00683951411611599,
    0.0068815839648008713, 0.0069012988366650985, 0.0068984750212282755,
    0.0068731583874781944, 0.0068255378743048989, 0.0067559411861884593,
    0.0066649037843089717, 0.0065530954198212811, 0.0064213267522713422,
    0.0062705888027908066, 0.0061019048494232817, 0.0059165494515888992,
    0.0057158912513312473, 0.0055012002009434905, 0.0052741635260395011,
    0.0050362132915468191, 0.0047890496478725951, 0.0045341497066509447,
    0.0042734997268358745, 0.0040085371934356611, 0.0037409197025008579,
    0.0034724012202268046, 0.0032045180521833921, 0.0029387692556755315,
    0.0026767243596072421, 0.0024197113892275497, 0.0021690261819568169,
    0.0019259576023407613, 0.001691559611981041, 0.0014668061875428731,
    0.0012525810872809169, 0.0010496506234757151, 0.0008586480724497034,
    0.00068001258211327189, 0.00051415595865473033, 0.000361299641221268,
    0.00022163625513016248, 9.5096638833577155E-5, -1.8409618933853218E-5,
    -0.00011905589159648356, -0.00020711716532226829, -0.00028303049255180347,
    -0.0003472491591041669, -0.00039978437378566717, -0.0004429506414522398,
    -0.00047543576099125641, -0.00049907948043380074, -0.00051391307849594841,
    -0.00052123063476867981, -0.00052170910874588846, -0.00051590740377815329,
    -0.00050465440621061885, -0.00048880423293568812, -0.00046909864202201534,
    -0.00044613538675857266, -0.00042058041739254689, -0.00039311628033708297,
    -0.0003643701810843529, -0.00033489234555271626, -0.00030515421461078241,
    -0.00027556142646147666, -0.00024649661002574473, -0.00021834170578591858,
    -0.00019137178262470568, -0.00016584951270678694, -0.000141952625682808,
    -0.00011983869399633803, -9.9546004631043757E-5, -8.1176438908954235E-5,
    -6.47372967215282E-5, -6.47372967215282E-5, -8.1176438908954235E-5,
    -9.9546004631043757E-5, -0.00011983869399633803, -0.000141952625682808,
    -0.00016584951270678694, -0.00019137178262470568, -0.00021834170578591858,
    -0.00024649661002574473, -0.00027556142646147666, -0.00030515421461078241,
    -0.00033489234555271626, -0.0003643701810843529, -0.00039311628033708297,
    -0.00042058041739254689, -0.00044613538675857266, -0.00046909864202201534,
    -0.00048880423293568812, -0.00050465440621061885, -0.00051590740377815329,
    -0.00052170910874588846, -0.00052123063476867981, -0.00051391307849594841,
    -0.00049907948043380074, -0.00047543576099125641, -0.0004429506414522398,
    -0.00039978437378566717, -0.0003472491591041669, -0.00028303049255180347,
    -0.00020711716532226829, -0.00011905589159648356, -1.8409618933853218E-5,
    9.5096638833577155E-5, 0.00022163625513016248, 0.000361299641221268,
    0.00051415595865473033, 0.00068001258211327189, 0.0008586480724497034,
    0.0010496506234757151, 0.0012525810872809169, 0.0014668061875428731,
    0.001691559611981041, 0.0019259576023407613, 0.0021690261819568169,
    0.0024197113892275497, 0.0026767243596072421, 0.0029387692556755315,
    0.0032045180521833921, 0.0034724012202268046, 0.0037409197025008579,
    0.0040085371934356611, 0.0042734997268358745, 0.0045341497066509447,
    0.0047890496478725951, 0.0050362132915468191, 0.0052741635260395011,
    0.0055012002009434905, 0.0057158912513312473, 0.0059165494515888992,
    0.0061019048494232817, 0.0062705888027908066, 0.0064213267522713422,
    0.0065530954198212811, 0.0066649037843089717, 0.0067559411861884593,
    0.0068255378743048989, 0.0068731583874781944, 0.0068984750212282755,
    0.0069012988366650985, 0.0068815839648008713, 0.00683951411611599,
    0.0067753767189279047, 0.0066896425668744128, 0.0065829559078893259,
    0.006456078837857945, 0.0063100048139513917, 0.0061456711625206377,
    0.0059643991909294125, 0.0057674296548045224, 0.0055561806237017126,
    0.0053320150593746873, 0.0050966313699402754, 0.0048515902177125123,
    0.0045985165846269514, 0.0043391937508463242, 0.004075062368086484,
    0.0038080038850251546, 0.003539519915865996, 0.0032713501894769967,
    0.0030049143065661206, 0.0027418176824048793, 0.0024834194823418528,
    0.002231028409318216, 0.0019859551720165141, 0.0017492897080464763,
    0.0015220404173487251, 0.0013051061284106921, 0.0010992850937805434,
    0.00090525371743225961, 0.00072349319544659984, 0.00055441046147556444,
    0.00039828579300918248, 0.00025531468224675982, 0.00012548892709157933,
    8.7546070817932876E-6, -9.5073561461815614E-5, -0.00018624553591258637,
    -0.0002651676266491118, -0.0003322611795319629, -0.0003885422937837705,
    -0.0004334138184832695, -0.00046809867665934348, -0.00049402907614949881,
    -0.00051095523847901345, -0.00052005922091325429, -0.00052221001603756229,
    -0.00051791398386965149, -0.00050792567033385093, -0.00049315233223843919,
    -0.00047435149265046309, -0.00045214519984069509, -0.00042717713690815565,
    -0.00040012607721850329, -0.0003716456401932872, -0.00034230278028430088,
    -0.000312591587388045, -0.0002829214889524323, -0.00025369711063378885,
    -0.00022528239385782433, -0.00019798289327849726, -0.00017208779096756669,
    -0.00014777923860694525, -0.00012517360607426355, -0.00010443817076041351,
    -8.5589412898523216E-5, -6.8665462784000934E-5, -0.00052633996473955844,
    -7.6884862727246187E-5, -9.4772534708761718E-5, -0.0001145762478087726,
    -0.00013626069551155528, -0.00015972490932381441, -0.00018485675321765514,
    -0.0002114787286856682, -0.00023935951072665245, -0.00026823174518450336,
    -0.0002977205998591429, -0.00032747046068418455, -0.00035704928837753216,
    -0.00038602679228993042, -0.00041386606926286848, -0.00043996725491763625,
    -0.00046363512254886488, -0.00048421416656688074, -0.00050109609898744511,
    -0.00051356677385285844, -0.00052082215469092521, -0.00052198114700849059,
    -0.00051642002147602893, -0.00050354689929956939, -0.00048221419488123031,
    -0.00045186045169718107, -0.00041180461523107479, -0.00036153946953162714,
    -0.00030016119513285477, -0.00022721769579038, -0.00014218942767751068,
    -4.4746243870273877E-5, 6.5515879820194441E-5, 0.00018875682632302752,
    0.00032515061682303158, 0.00047471625063728249, 0.00063733849462713221,
    0.00081281866019155646, 0.0010007644607162567, 0.0012007568368064203,
    0.0014122269483569103, 0.0016344347558074721, 0.001866504825879223,
    0.0021075043951756978, 0.0023563947706633122, 0.0026119488227710512,
    0.0028728529916150496, 0.0031378185752344015, 0.00340532443645309,
    0.0036738109239125576, 0.0039418379304998023, 0.0042075528986448858,
    0.0044695373785125624, 0.0047258700609739968, 0.0049752158124108971,
    0.0052156332083100341, 0.0054455911614666209, 0.005663435166437236,
    0.0058677494933969555, 0.00605709488105954, 0.0062300355659316992,
    0.0063853834012265907, 0.0065219838842133816, 0.0066388735229927082,
    0.0067351637161330528, 0.006810185308110249, 0.0068633331432694372,
    0.0068942454017221627, 0.0069027095819426789, 0.0068886170361975307,
    0.0068521175581522237, 0.00679346061969954, 0.0067130621208737213,
    0.0066115493617965506, 0.0064896357701849719, 0.0063482688954380993,
    0.0061884015539193735, 0.006011257824972617, 0.005818039813582661,
    0.0056101751059685406, 0.0053891589542369809, 0.0051564466215787835,
    0.0049136672994331936, 0.0046626104356235695, 0.0044045608103191461,
    0.0041414006299919232, 0.0038749727750450528, 0.0036066699797203737,
    0.0033382967842870027, 0.0030712767836724659, 0.0028072031791727525,
    0.00254750623486489, 0.0022934896229431204, 0.0020464723092323755,
    0.0018076113011157163, 0.0015779228831079386, 0.0013583259881900232,
    0.0011496563318115875, 0.00095263056765269784, 0.00076776029784069257,
    0.00059546976269535755, 0.00043609461324888249, 0.00028982634764948567,
    0.000156710888810145, 3.6735785577682962E-5, -7.02889172592217E-5,
    -0.00016464264711997431, -0.00024656673882810138, -0.00031656755110235697,
    -0.00037503677220598441, -0.00042308188830163094, -0.00046023477176276807,
    -0.00048841595777255969, -0.00050752103453045221, -0.0005184642678305101,
    -0.00052230451045506, -0.00051954914095196582, -0.0005109026937415986,
    -0.00049725563781124994, -0.00047939516744318879, -0.00045798285197048619,
    -0.00043364501238500348, -0.00040704214586459854, -0.00037886409969917646,
    -0.00034969202758580059, -0.0003200356129464503, -0.00029031082651764518,
    -0.00026094388620766077, -0.00023229075588404461, -0.00020468015602867408,
    -0.00017842657427060115, -0.00015370759303421738, -0.0001306820874754246,
    -0.00010945146779746249, -9.0120954701438684E-5, -7.2714332828795485E-5 };

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
  for (i = 0; i < 544; i++) {
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
    iobj_0->cSFunObject.W2_CoeffIdx = 408;
    iobj_0->cSFunObject.W0_PhaseIdx = 3;
    iobj_0->cSFunObject.W4_TapDelayIndex = 405;
    iobj_0->cSFunObject.W1_Sums = 0.0;
    for (i = 0; i < 540; i++) {
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
    obj->cSFunObject.W2_CoeffIdx = 408;
    obj->cSFunObject.W0_PhaseIdx = 3;
    obj->cSFunObject.W4_TapDelayIndex = 405;
    obj->cSFunObject.W1_Sums = 0.0;
    for (i = 0; i < 540; i++) {
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
  maxWindow = (phaseIdx + 1) * 135 - 135;
  for (i = 0; i < 8; i++) {
    obj_0->W1_Sums += rtu_0[inputIdx] * obj_0->P1_FILT[cffIdx];
    cffIdx++;
    for (jIdx = curTapIdx + 1; jIdx < maxWindow + 135; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
    }

    for (jIdx = maxWindow; jIdx <= curTapIdx; jIdx++) {
      obj_0->W1_Sums += obj_0->W3_StatesBuff[jIdx] * obj_0->P1_FILT[cffIdx];
      cffIdx++;
    }

    obj_0->W3_StatesBuff[curTapIdx] = rtu_0[inputIdx];
    inputIdx++;
    curTapIdx += 135;
    if (curTapIdx >= 540) {
      curTapIdx -= 540;
    }

    phaseIdx++;
    if (phaseIdx < 4) {
      maxWindow += 135;
    } else {
      obj_0->O0_Y0[outBufIdx] = obj_0->W1_Sums;
      outBufIdx++;
      obj_0->W1_Sums = 0.0;
      phaseIdx = 0;
      cffIdx = 0;
      curTapIdx--;
      if (curTapIdx < 0) {
        curTapIdx += 135;
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
