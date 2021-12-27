/******************************************************************************/
/** ģ�����ƣ���չ��������                                                   **/
/** �ļ����ƣ�ad7192function.c                                               **/
/** ��    ����V1.0.2                                                         **/
/** ��    �飺�����Ͷ���AD7192ģ��ת��оƬ��صĸ��ֺ����Ͳ���               **/
/**--------------------------------------------------------------------------**/
/** �޸ļ�¼��                                                               **/
/**     �汾      ����              ����              ˵��                   **/
/**     V1.0.0  2017-07-26          ľ��              �����ļ�               **/
/**     V1.0.1  2017-12-06          ľ��              ���Ĵ��������Ϊ����   **/
/**     V1.0.2  2018-05-09          ľ��              ��Ӳ�����ʱ����       **/
/**     V2.0.0  2018-05-23          ľ��              ��Ӳ������󣬲��޸�ȫ **/
/**                                                   ����غ������β�       **/
/**                                                                          **/
/******************************************************************************/ 

#include "stddef.h"
#include "ad7192function.h"

/*     ͨѶ�Ĵ���8λ��ֻд,RS2,RS1,RS0=0,0,0;                                 */
/*     ͨѶ�Ĵ���λ���ܲ����궨��                                             */
/*     +-------+-------+-------+-------+-------+--------+-------+-------+     */
/*     |  CR7  |  CR6  |  CR5  |  CR4  |  CR3  |  CR2   |  CR1  |  CR0  |     */
/*     +-------+-------+-------+-------+-------+--------+-------+-------+     */
/*     | WEN(0)| R/W(0)| RS2(0)| RS1(0)| RS0(0)|CREAD(0)|  0(0) |  0(0) |     */
/*     +-------+-------+-------+-------+-------+--------+-------+-------+     */
#define	WEN             0x00    //WENλΪ0ʱ���������дͨѶ�Ĵ���
#define WEN_DIS         0x80    //WENλΪ1ʱ����ֹ����дͨѶ�Ĵ���
#define RW_W            0x00    //R/WλΪ0ʱ����һ����Ϊдָ���Ĵ���
#define	RW_R            0x40    //R/WλΪ1ʱ����һ������дָ���Ĵ���
#define REG_COM_STA     0x00    //��Ϊ״̬�Ĵ�����дΪͨѶ�Ĵ���*/
#define	REG_MODE        0x08    //����ģʽ�Ĵ���
#define	REG_CONF        0x10    //�������üĴ���
#define	REG_DATA        0x18    //�������ݼĴ���
#define	REG_ID          0x20    //����ID�Ĵ���
#define	REG_GPOCON      0x28    //����GPOCON�Ĵ���
#define	REG_OFFSET      0x30    //����ʧ���Ĵ���
#define	REG_FS          0x38    //���������̼Ĵ���
#define	CREAD_EN        0x04    //������ȡ
#define	CREAD_DIS       0x00    //���ζ�ȡ

/*     ״̬�Ĵ���8λ��ֻ��,RS2,RS1,RS0=0,0,0;�ϵ�/��λ=0x80                   */
/*     ״̬�Ĵ���λ����ȡֵ�궨��                                             */
/*     +-------+-------+--------+---------+-------+-------+-------+-------+   */
/*     |  SR7  |  SR6  |  SR5   |  SR4    |  SR3  |  SR2  |  SR1  |  SR0  |   */
/*     +-------+-------+--------+---------+-------+-------+-------+-------+   */
/*     | RDY(1)| ERR(0)|NOREF(0)|PARITY(0)|  0(0) |CHD2(0)|CHD1(0)|CHD0(0)|   */
/*     +-------+-------+--------+---------+-------+-------+-------+-------+   */
#define	RDY_H			0x80    /*����δ����*/
#define	RDY_L			0x00    /*����׼������*/
#define	ERR_H			0x40    /*�������*/
#define	ERR_L			0x00    /*�����ȷ*/
#define	NOREF_H			0x20    /*��׼Դ����*/
#define	NOREF_L			0x00    /*��׼Դ��ȷ*/
#define	PARITY_H		0x10    /*������1*/
#define	PARITY_L		0x00    /*ż����1*/
#define	CHDST_AIN1_AIN2         0x00    /*��Ӧͨ��Ϊ��һ·�������*/
#define	CHDST_AIN3_AIN4         0x01    /*��Ӧͨ��Ϊ�ڶ�·�������*/
#define	CHDST_TEMP		0x02    /*��Ӧͨ��Ϊ�¶�����*/
#define	CHDST_AIN2_AIN2         0x03    /*��Ӧͨ��Ϊ�ڶ�·����*/
#define	CHDST_AIN1_COM          0x04    /*��Ӧͨ��Ϊ��һ·��������*/
#define	CHDST_AIN2_COM          0x05    /*��Ӧͨ��Ϊ�ڶ�·��������*/
#define	CHDST_AIN3_COM          0x06    /*��Ӧͨ��Ϊ����·��������*/
#define	CHDST_AIN4_COM          0x07    /*��Ӧͨ��Ϊ����·��������*/

/*   ģʽ�Ĵ���24λ���ɶ���д,RS2,RS1,RS0=0,0,1;�ϵ�/��λ=0x080060            */
/*   ģʽ�Ĵ���λ���ܲ����궨��                                               */
/*   +--------+------+--------+----------+---------+--------+------+------+   */
/*   |  MR23  | MR22 |  MR21  |  MR20    |   MR19  |  MR18  | MR17 | MR16 |   */
/*   +--------+------+--------+----------+---------+--------+------+------+   */
/*   | MD2(0) |MD1(0)| MD0(0) |DAT_STA(0)| CLK1(0) | CLK0(0)| 0(0) | 0(0) |   */
/*   +--------+------+--------+----------+---------+--------+------+------+   */
/*   |  MR15  | MR14 |  MR13  |  MR12    |   MR11  |  MR10  | MR9  | MR8  |   */
/*   +--------+------+--------+----------+---------+--------+------+------+   */
/*   |SINC3(0)| 0(0) |ENPAR(0)|CLK_DIV(0)|SINGLE(0)|REJ60(0)|FS9(0)|FS8(0)|   */
/*   +--------+------+--------+----------+---------+--------+------+------+   */
/*   |  MR7   | MR6  |  MR5   |  MR4     |   MR3   |   MR2  | MR1  | MR0  |   */
/*   +--------+------+--------+----------+---------+--------+------+------+   */
/*   | FS7(0) |FS6(0)| FS5(0) |  FS4(0)  |  FS3(0) | FS2(0) |FS1(0)|FS0(0)|   */
/*   +--------+------+--------+----------+---------+--------+------+------+   */
#define	MODE_CONT               0x000000        /*����ת��ģʽ��Ĭ�ϣ�*/
#define	MODE_SING               0x200000        /*����ת��ģʽ*/
#define	MODE_IDLE               0x400000        /*����ģʽ*/
#define	MODE_PD                 0x600000        /*�ض�ģʽ*/
#define	MODE_INZCL              0x800000        /*�ڲ����ƽУ׼*/
#define	MODE_INFCL              0xA00000        /*�ڲ�������У׼*/
#define	MODE_SYSZCL             0xC00000        /*ϵͳ���ƽУ׼*/
#define	MODE_SYSFCL             0xE00000        /*ϵͳ������У׼*/
#define	DAT_STA_EN              0x100000        /*״̬�����ݼĴ���ͬ��*/
#define	DAT_STA_DIS             0x000000        /*״̬�����ݼĴ�����ͬ��*/	  
#define	EXT_XTAL                0x000000        /*�ⲿ����*/
#define	EXT_CLK                 0x040000        /*�ⲿʱ��*/
#define	INCLK_MCLK2TRI          0x080000        /*�ڲ�ʱ��*/
#define	INCLK_MCLK2EN           0x0C0000        /*�ڲ�ʱ�ӣ����*/
#define	SINC_4                  0x000000        /*ʹ��sinc4�˲�*/
#define	SINC_3                  0x008000        /*ʹ��sinc3�˲�*/
#define	ENPAR_EN                0x002000        /*ʹ����żУ��*/
#define	ENPAR_DIS               0x000000        /*��ֹ��żУ��*/
#define	CLK_DIV_2               0x001000        /*��ʱ��2��Ƶ*/
#define	CLK_DIV_DIS             0x000000        /*��ʱ�Ӳ���Ƶ*/
#define	SINGLECYCLE_EN          0x000800        /*������ת��ʹ��*/
#define	SINGLECYCLE_DIS         0x000000        /*������ת��ʧ��*/
#define	REJ60_EN                0x000400        /*ʹ��60Hz�ݲ�Ƶ��*/
#define	REJ60_DIS               0x000000        /*ʧ��60Hz�ݲ�Ƶ��*/
										
/*    ���üĴ�����24λ���ɶ���д,RS2,RS1,RS0=0,1,0;�ϵ�/��λ=0x000117         */
/*    ���üĴ���λ���ܲ����궨��                                              */
/*    +-------+---------+------+---------+-------+-------+-------+-------+    */
/*    | CON23 |  CON22  | CON21|  CON20  | CON19 | CON18 | CON17 | CON16 |    */
/*    +-------+---------+------+---------+-------+-------+-------+-------+    */
/*    |CHOP(0)|   0(0)  | 0(0) |REFSEL(0)|  0(0) |  0(0) |  0(0) |  0(0) |    */
/*    +-------+---------+------+---------+-------+-------+-------+-------+    */
/*    | CON15 |  CON14  | CON13|  CON12  | CON11 | CON10 | CON9  | CON8  |    */
/*    +-------+---------+------+---------+-------+-------+-------+-------+    */
/*    | CH7(0)|  CH6(0) |CH5(0)|  CH4(0) | CH3(0)| CH2(0)| CH1(0)| CH0(0)|    */
/*    +-------+---------+------+---------+-------+-------+-------+-------+    */
/*    | CON7  |   CON6  | CON5 |  CON4   | CON3  |  CON2 | CON1  | CON0  |    */
/*    +-------+---------+------+---------+-------+-------+-------+-------+    */
/*    |BURN(0)|REFDET(0)| 0(0) |  BUF(0) | U/B(0)| G2(0) | G1(0) | G0(0) |    */
/*    +-------+---------+------+---------+-------+-------+-------+-------+    */			
#define CHOP_EN                 0x800000        /*ն��ʹ��*/
#define	CHOP_DIS                0x000000        /*ն������*/
#define	REF_IN1                 0x000000        /*��׼��ѹ����1*/
#define	REF_IN2                 0x100000        /*��׼��ѹ����2*/
#define	AIN1_AIN2               0x000100        /*���ͨ��1*/
#define	AIN3_AIN4               0x000200        /*���ͨ��2*/
#define	TEMP                    0x000400        /*�¶�*/
#define	AIN2_AIN2               0x000800        /*ģ��ͨ��2*/
#define	AIN1_COM                0x001000        /*��������1*/
#define	AIN2_COM                0x002000        /*��������2*/
#define	AIN3_COM                0x004000        /*��������3*/
#define	AIN4_COM                0x008000        /*��������4*/
#define	BURN_EN                 0x000080        /*ʹ�ܼ�������*/
#define	BURN_DIS                0x000000        /*���ü�������*/
#define	REFDET_EN               0x000040        /*ʹ�ܻ�׼��ѹ���*/
#define	REFDET_DIS              0x000000        /*���û�׼��ѹ���*/
#define	BUF_EN                  0x000010        /*ʹ��ģ������˵Ļ�����*/
#define	BUF_DIS                 0x000000        /*����ģ������˵Ļ�����*/
#define	UB_UNI                  0x000008        /*�����Թ���ģʽ*/
#define UB_BI                   0x000000        /*˫���Թ���ģʽ*/
#define	GAIN_1                  0x000000        /*1������*/
#define	GAIN_8                  0x000003        /*8������*/
#define	GAIN_16                 0x000004        /*16������*/
#define	GAIN_32                 0x000005        /*32������*/
#define	GAIN_64                 0x000006        /*64������*/
#define	GAIN_128                0x000007        /*128������*/

/*    GPOCON�Ĵ�����8λ��ֻ��,RS2,RS1,RS0=1,0,1;�ϵ�/��λ=0x00                */
/*    ���ݼĴ���λ���ܲ����궨��                                              */
/*   +----+--------+---------+---------+--------+--------+--------+--------+  */
/*   | GP7|   GP6  |   GP5   |   GP4   |   GP3  |   GP2  |   GP1  |  GP0   |  */
/*   +----+--------+---------+---------+--------+--------+--------+--------+  */
/*   |0(0)|BPDSW(0)|GP32EN(0)|GP10EN(0)|P3DAT(0)|P2DAT(0)|P1DAT(0)|P0DAT(0)|  */
/*   +----+--------+---------+---------+--------+--------+--------+--------+  */
#define BPDSW_CLOSE             0x40    /*�պϵ��ŹضϿ���*/
#define	BPDSW_OPEN              0x00    /*�Ͽ����ŹضϿ���*/
#define	GP32EN                  0x20    /*�������P3��P2Ϊ��Ч*/
#define	GP32DIS                 0x00    /*�������P3��P2������*/
#define	GP10EN                  0x10    /*�������P1��P0Ϊ��Ч*/
#define	GP10DIS                 0x00    /*�������P1��P0������*/
#define	P3DAT_H                 0x08    /*����P3Ϊ�ߵ�ƽ*/
#define	P3DAT_L                 0x00    /*����P3Ϊ�͵�ƽ*/
#define	P2DAT_H                 0x04    /*����P2Ϊ�ߵ�ƽ*/
#define	P2DAT_L                 0x00    /*����P2Ϊ�͵�ƽ*/
#define	P1DAT_H                 0x02    /*����P1Ϊ�ߵ�ƽ*/
#define	P1DAT_L                 0x00    /*����P1Ϊ�͵�ƽ*/
#define	P0DAT_H                 0x01    /*����P0Ϊ�ߵ�ƽ*/
#define	P0DAT_L                 0x00    /*����P0Ϊ�͵�ƽ*/

#define	NOP                     0x00    /*�޲���*/

uint8_t regAdd[]={REG_COM_STA,REG_MODE,REG_CONF,REG_DATA,REG_ID,REG_GPOCON,REG_OFFSET,REG_FS};

/*AD7192�����λ����������40��1�ͻḴλ*/
static void AD7192SoftwareReset(Ad7192ObjectType *adObj);
/*дAD7192�Ĵ���ֵ*/
static void WriteAD7192Register(Ad7192ObjectType *adObj,AD7192RegisterType startReg,uint8_t NumberOfRegistersToWrite);
/*��AD7192�Ĵ���ֵ*/
static void ReadAD7192Register(Ad7192ObjectType *adObj,AD7192RegisterType startReg,uint8_t NumberOfRegistersToRead);
/*����������*/
//static void AD7192StartContinuousRead(Ad7192ObjectType *adObj);
/*������ȡ*/
//static uint32_t AD7192ContinuousRead(Ad7192ObjectType *adObj);
/*��ȡת������*/
static uint32_t AD7192ReadConvertingData(Ad7192ObjectType *adObj);
/*�˳�������*/
//static void AD7192ExitContinuousRead(Ad7192ObjectType *adObj);
/*�ڲ����У׼*/
static void AD7192InternalZeroScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels);
/*�ڲ�����У׼*/
static void AD7192InternalFullScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels);
/*�ⲿ���У׼*/
static void AD7192ExternalZeroScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels);
/*�ⲿ����У׼*/
static void AD7192ExternalFullScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels);
/*��������ת��*/
static void AD7192StartSingleConvertion(Ad7192ObjectType *adObj,uint32_t Channels);
/*��������ת��*/
static void AD7192StartContinuousConvertion(Ad7192ObjectType *adObj,uint32_t Channels);
/* Ĭ�ϵ�Ƭѡ�źŴ����� */
static void AD719xChipSelect(AD7192CSType cs);

/*����ת�����ݻ�ȡ,dataCodesΪ8��Ԫ�ص������Ӧ8��ͨ��*/
void GettContinuousConvertionValue(Ad7192ObjectType *adObj,uint32_t Channels,uint32_t *dataCodes,int number)
{
  uint32_t dataCode=0;
  uint8_t status=255;
  AD7192StartContinuousConvertion(adObj,Channels&0x00FF00);
  
  for(int i=0;i<number;i++)
  {
    dataCode = AD7192ReadConvertingData(adObj);
    status=((uint8_t)dataCode)&0x07;
    dataCode =(dataCode>>8) & 0x00FFFFFF;
    dataCodes[status]=dataCode;
  }
}

/*����ת�����ݻ�ȡ*/
uint32_t GetSingleConvertionValue(Ad7192ObjectType *adObj,uint32_t Channels)
{
  uint32_t dataCode=0;
  AD7192StartSingleConvertion(adObj,Channels&0x00FF00);
  
  adObj->Delay(1);
  
  dataCode = AD7192ReadConvertingData(adObj);
  dataCode =dataCode & 0x00FFFFFF;

  ReadAD7192Register(adObj,AD7192_REG_DATA, 1);
  
  return dataCode;
}

/*AD7192��ʼ������*/
AD7192ErrorType AD7192Initialization(Ad7192ObjectType *adObj,           //AD7192����
                                     uint32_t Channels,                 //ͨ��
                                     AD7192PolarType polar,             //����
                                     AD7192GainType gain,               //����
                                     AD7192CalibrationType cali,        //У׼��ʽ
                                     uint16_t fs,                       //������������趨��1-1023����Խ��Ƶ��Խ��
                                     AD7192ReadWriteType readWrite,     //��д����ָ��
                                     AD7192ChipSelectType cs,           //Ƭѡ����ָ��
                                     AD7192GetReadyInputType ready,     //��������ָ��
                                     AD7192DelaymsType delayms          //��ʱ����ָ��
                                    )
{
  uint32_t polarity[]={UB_UNI,UB_BI};
  uint32_t gains[]={GAIN_1,GAIN_8,GAIN_16,GAIN_32,GAIN_64,GAIN_128};
  
  if((adObj==NULL)||(readWrite==NULL)||(ready==NULL)||(delayms==NULL))
  {
    return AD7192_InitError;
  }
  adObj->ReadWrite=readWrite;
  adObj->GetReadyInput=ready;
  adObj->Delay=delayms;
	
  if(cs==NULL)
  {
    adObj->ChipSelect=AD719xChipSelect;
  }
  else
  {
    adObj->ChipSelect=cs;
  }
  
  for(int i=0;i<AD7192RegisterNumber;i++)
  {
    adObj->Registers[i]=0x00;
  }
	
  adObj->polar=polarity[polar];
  adObj->gain=gains[gain];
  adObj->fs=fs>1023?1023:(fs<1?1:fs);
		
  AD7192SoftwareReset(adObj);
  adObj->Delay(1);
	
  if(cali==AD7192_Internal)
  {
    AD7192InternalZeroScaleCalibration(adObj,Channels&0x00FF00);
    adObj->Delay(1);
    AD7192InternalFullScaleCalibration(adObj,Channels&0x00FF00);
  }
  else
  {
    AD7192ExternalZeroScaleCalibration(adObj,Channels&0x00FF00);
    adObj->Delay(1);
    AD7192ExternalFullScaleCalibration(adObj,Channels&0x00FF00);
  }
		
  /*��ȡ���洢ȫ���Ĵ�����ֵ*/
  ReadAD7192Register(adObj,AD7192_REG_COM_STA, 8);

  return AD7192_OK;
}

/*AD7192�����λ����������40��1�ͻḴλ*/
static void AD7192SoftwareReset(Ad7192ObjectType *adObj)
{
  uint8_t WriteBuf[1];
  uint8_t ReadBuf[1];
  uint8_t i;
  
  adObj->ChipSelect(AD7192CS_Enable);
  
  WriteBuf[0]	= 0xFF;	 
  
  for(i=0; i<5; i++)
  {
    adObj->ReadWrite(WriteBuf, ReadBuf, 1);
  }
  
  adObj->ChipSelect(AD7192CS_Disable);
}

/*дAD7192�Ĵ���ֵ*/
static void WriteAD7192Register(Ad7192ObjectType *adObj,AD7192RegisterType startReg,uint8_t NumberOfRegistersToWrite)
{
  uint8_t WriteBuf[4];
  uint8_t ReadBuf[4];
  uint8_t i;

  adObj->ChipSelect(AD7192CS_Enable);
  
  for(i=0; i<NumberOfRegistersToWrite; i++)
  {
    WriteBuf[0] = WEN|RW_W|(regAdd[startReg + i])|CREAD_DIS;
    WriteBuf[1] = adObj->Registers[startReg + i]>>16;
    WriteBuf[2] = adObj->Registers[startReg + i]>>8;
    WriteBuf[3] = adObj->Registers[startReg + i];
    adObj->ReadWrite(WriteBuf, ReadBuf, 4);
  }
  
  adObj->ChipSelect(AD7192CS_Disable);
}

/*��AD7192�Ĵ���ֵ*/
static void ReadAD7192Register(Ad7192ObjectType *adObj,AD7192RegisterType startReg,uint8_t NumberOfRegistersToRead)
{
  uint8_t WriteBuf[4];
  uint8_t ReadBuf[4];
  uint8_t i;

  adObj->ChipSelect(AD7192CS_Enable);
  
  for(i=0; i < NumberOfRegistersToRead; i++)
  {
    //дͨѶ�Ĵ�������һ����Ϊ��
    WriteBuf[0] = WEN|RW_R|(regAdd[startReg + i])|CREAD_DIS;	 
    adObj->ReadWrite(WriteBuf, ReadBuf, 1);

    WriteBuf[0] = NOP;
    WriteBuf[1] = NOP;
    WriteBuf[2] = NOP;
    WriteBuf[3] = NOP;

    switch(regAdd[startReg + i])
    {

      case REG_ID       :
      case REG_COM_STA  : 
      case REG_GPOCON   :
        {
          adObj->ReadWrite(WriteBuf, ReadBuf, 1);
          adObj->Registers[startReg + i ] = ReadBuf[0];
          break;
        }
      case REG_MODE     : 
      case REG_CONF     : 
      case REG_OFFSET   :
      case REG_FS       : 
        {
          adObj->ReadWrite(WriteBuf, ReadBuf, 3);	   
          adObj->Registers[startReg + i ] = ReadBuf[0];
          adObj->Registers[startReg + i ] = (adObj->Registers[startReg + i ]<<8) + ReadBuf[1];
          adObj->Registers[startReg + i ] = (adObj->Registers[startReg + i ]<<8) + ReadBuf[2];  
          break;
        }
      case REG_DATA	 : 
        {
          if (adObj->Registers[AD7192_REG_MODE] & DAT_STA_EN)
          {
            adObj->ReadWrite(WriteBuf, ReadBuf, 4);	  
            adObj->Registers[startReg + i ] = ReadBuf[0];
            adObj->Registers[startReg + i ] = (adObj->Registers[startReg + i ]<<8) + ReadBuf[1];
            adObj->Registers[startReg + i ] = (adObj->Registers[startReg + i ]<<8) + ReadBuf[2];					
            adObj->Registers[startReg + i ] = (adObj->Registers[startReg + i ]<<8) + ReadBuf[3];
            break;
          }
          else
          {
            adObj->ReadWrite(WriteBuf, ReadBuf, 3);
            adObj->Registers[startReg + i ] = ReadBuf[0];
            adObj->Registers[startReg + i ] = (adObj->Registers[startReg + i ]<<8) + ReadBuf[1];
            adObj->Registers[startReg + i ] = (adObj->Registers[startReg + i ]<<8) + ReadBuf[2];
            break;
          }
        }
      default			 : 
        break;
    }
  }
  adObj->ChipSelect(AD7192CS_Disable);
}

/*����������*/
/*static void AD7192StartContinuousRead(Ad7192ObjectType *adObj)
{
  uint8_t WriteBuf[1];
  uint8_t ReadBuf[1];

  adObj->ChipSelected(AD719xCS_Enable);

  WriteBuf[0] = WEN|RW_R|(REG_DATA<<3)|CREAD_EN;
  
  adObj->ReadWrite(WriteBuf, ReadBuf, 1);
}*/

/*������ȡ*/
/*static uint32_t AD7192ContinuousRead(Ad7192ObjectType *adObj)
{
  uint8_t WriteBuf[4];
  uint8_t ReadBuf[4];
  uint32_t DataBuffer;

  WriteBuf[0] = NOP;
  WriteBuf[1] = NOP;	
  WriteBuf[2] = NOP;
  WriteBuf[3] = NOP;

  adObj->ChipSelected(AD719xCS_Enable);
  while(adObj->GetReadyInput()== 0){;}			
  while(adObj->GetReadyInput()== 1){;}			//�ȴ���һ��RDY�½���;

  if ((adObj->Registers[REG_MODE] & DAT_STA_EN) == DAT_STA_EN)   //��״̬��Ϣ
  {
    adObj->ReadWrite(WriteBuf, ReadBuf, 4);	  
    DataBuffer = ReadBuf[0];
    DataBuffer = (DataBuffer<<8) + ReadBuf[1];
    DataBuffer = (DataBuffer<<8) + ReadBuf[2];
    DataBuffer = (DataBuffer<<8) + ReadBuf[3];
  }
  else                                                          //����״̬��Ϣ
  {
    adObj->ReadWrite(WriteBuf, ReadBuf, 3); 
    DataBuffer = ReadBuf[0];
    DataBuffer = (DataBuffer<<8) + ReadBuf[1];
    DataBuffer = (DataBuffer<<8) + ReadBuf[2];
  }
  
  return DataBuffer;
}*/

/*��ȡת������*/
static uint32_t AD7192ReadConvertingData(Ad7192ObjectType *adObj)
{
  uint8_t WriteBuf[4];
  uint8_t ReadBuf[4];
  uint32_t DataBuffer;

  adObj->ChipSelect(AD7192CS_Enable);
  
  WriteBuf[0] = WEN|RW_R|(regAdd[AD7192_REG_DATA])|CREAD_DIS;	 

  adObj->ReadWrite(WriteBuf, ReadBuf, 1);

  WriteBuf[0] = NOP;
  WriteBuf[1] = NOP;	
  WriteBuf[2] = NOP;
  WriteBuf[3] = NOP;

  while(adObj->GetReadyInput()== 0){;}			
  while(adObj->GetReadyInput()== 1){;}			//�ȴ���һ��RDY�½���

  if ((adObj->Registers[AD7192_REG_MODE] & DAT_STA_EN) == DAT_STA_EN)//��״̬��Ϣ
  {
    adObj->ReadWrite(WriteBuf, ReadBuf, 4);	  
    DataBuffer = ReadBuf[0];
    DataBuffer = (DataBuffer<<8) + ReadBuf[1];
    DataBuffer = (DataBuffer<<8) + ReadBuf[2];
    DataBuffer = (DataBuffer<<8) + ReadBuf[3];
  }
  else //����״̬��Ϣ
  {
    adObj->ReadWrite(WriteBuf, ReadBuf, 3);
    DataBuffer = ReadBuf[0];
    DataBuffer = (DataBuffer<<8) + ReadBuf[1];
    DataBuffer = (DataBuffer<<8) + ReadBuf[2];
  }

  return DataBuffer;
}

/*�˳�������*/
/*static void AD7192ExitContinuousRead(Ad7192ObjectType *adObj)
{
  uint8_t WriteBuf[1];
  uint8_t ReadBuf[1];

  while(adObj->GetReadyInput()== 0){;}			
  while(adObj->GetReadyInput()== 1){;}			//�ȴ���һ��RDY�½���

  WriteBuf[0] = WEN|RW_R|(REG_DATA<<3)|CREAD_DIS;

  adObj->ReadWrite(WriteBuf, ReadBuf, 1);		

  adObj->ChipSelected(AD719xCS_Disable);
}*/

/*�ڲ����У׼*/
static void AD7192InternalZeroScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels)
{
  //���üĴ�����ն�����ã���׼��ѹ1��AI1-AI4��ͨ��4·�����ü������������û�׼��ѹ��⣬���û�����
  adObj->Registers[AD7192_REG_CONF] = 0;
  adObj->Registers[AD7192_REG_CONF] = CHOP_DIS|REF_IN1|Channels|BURN_DIS|REFDET_DIS|BUF_DIS|adObj->polar|adObj->gain;
  WriteAD7192Register(adObj,AD7192_REG_CONF,1);

  //ģʽ�Ĵ������ڲ����У׼������״̬ͬ�����ڲ�ʱ�������ն��4��ʹ����żУ�飬����Ƶ�����õ�����ת��ʹ�ܣ�����60Hz�ݲ�
  adObj->Registers[AD7192_REG_MODE] = 0;
  adObj->Registers[AD7192_REG_MODE] = MODE_INZCL|DAT_STA_DIS|INCLK_MCLK2EN|SINC_4|ENPAR_EN|CLK_DIV_DIS|SINGLECYCLE_DIS|REJ60_DIS|0x080;
  WriteAD7192Register(adObj,AD7192_REG_MODE, 1);

  adObj->ChipSelect(AD7192CS_Enable);
  while(adObj->GetReadyInput()== 1){;}			//�ȴ�RDYΪ0;
  adObj->ChipSelect(AD7192CS_Disable);
}

/*�ڲ�����У׼*/
static void AD7192InternalFullScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels)
{
  
  //���üĴ�����ն�����ã���׼��ѹ1��AI1-AI4��ͨ��4·�����ü������������û�׼��ѹ��⣬���û�����
  adObj->Registers[AD7192_REG_CONF] = 0;
  adObj->Registers[AD7192_REG_CONF] = CHOP_DIS|REF_IN1|Channels|BURN_DIS|REFDET_DIS|BUF_DIS|adObj->polar|adObj->gain;
  WriteAD7192Register(adObj,AD7192_REG_CONF,1);
  
  //ģʽ�Ĵ������ڲ�����У׼������״̬ͬ�����ڲ�ʱ�������ն��4��ʹ����żУ�飬����Ƶ�����õ�����ת��ʹ�ܣ�����60Hz�ݲ�
  adObj->Registers[AD7192_REG_MODE] = 0;
  adObj->Registers[AD7192_REG_MODE] = MODE_INFCL|DAT_STA_DIS|INCLK_MCLK2EN|SINC_4|ENPAR_EN|CLK_DIV_2|SINGLECYCLE_DIS|REJ60_DIS|adObj->fs;		
  WriteAD7192Register(adObj,AD7192_REG_MODE,1);

  adObj->ChipSelect(AD7192CS_Enable);
  while(adObj->GetReadyInput()== 1){;}			//�ȴ�RDYΪ0;
  adObj->ChipSelect(AD7192CS_Disable);
}

/*�ⲿ���У׼*/
static void AD7192ExternalZeroScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels)
{
	//�������üĴ���
  adObj->Registers[AD7192_REG_CONF] = 0;
  adObj->Registers[AD7192_REG_CONF] = CHOP_DIS|REF_IN2|Channels|BURN_DIS|REFDET_DIS|BUF_DIS|adObj->polar|adObj->gain;
  WriteAD7192Register(adObj,AD7192_REG_CONF,1);

  //��ϵͳ����������ӵ�ͨ���������Ų�ͨ�����üĴ�����CH7��CH0λ��������
  adObj->Registers[AD7192_REG_MODE] = 0;
  adObj->Registers[AD7192_REG_MODE] = MODE_SYSZCL|DAT_STA_EN|INCLK_MCLK2EN|SINC_4|ENPAR_EN|CLK_DIV_DIS|SINGLECYCLE_DIS|REJ60_DIS|adObj->fs;		
  WriteAD7192Register(adObj,AD7192_REG_MODE,1);

  adObj->ChipSelect(AD7192CS_Enable);
  while(adObj->GetReadyInput()== 1){;}			//�ȴ�RDYΪ0;
  adObj->ChipSelect(AD7192CS_Disable);
}

/*�ⲿ����У׼*/
static void AD7192ExternalFullScaleCalibration(Ad7192ObjectType *adObj,uint32_t Channels)
{
	//�������üĴ���
  adObj->Registers[AD7192_REG_CONF] = 0;
  adObj->Registers[AD7192_REG_CONF] = CHOP_DIS|REF_IN2|Channels|BURN_DIS|REFDET_DIS|BUF_DIS|adObj->polar|adObj->gain;
  WriteAD7192Register(adObj,AD7192_REG_CONF, 1);

  //��ϵͳ�����������ӵ�ͨ���������Ų�ͨ�����üĴ�����CH7��CH0λ��������
  adObj->Registers[AD7192_REG_MODE] = 0;
  adObj->Registers[AD7192_REG_MODE] = MODE_SYSFCL|DAT_STA_EN|INCLK_MCLK2EN|SINC_4|ENPAR_EN|CLK_DIV_2|SINGLECYCLE_DIS|REJ60_DIS|adObj->fs;		
  WriteAD7192Register(adObj,AD7192_REG_MODE, 1);

  adObj->ChipSelect(AD7192CS_Enable);
  while(adObj->GetReadyInput()== 1){;}			//�ȴ�RDYΪ0;
  adObj->ChipSelect(AD7192CS_Disable);
}

/*��������ת��*/
static void AD7192StartSingleConvertion(Ad7192ObjectType *adObj,uint32_t Channels)
{
  //���üĴ�����ն�����ã���׼��ѹ1������ͨ�������ü������������û�׼��ѹ��⣬���û�����
  adObj->Registers[AD7192_REG_CONF] = 0;
  adObj->Registers[AD7192_REG_CONF] = CHOP_DIS|REF_IN1|Channels|BURN_DIS|REFDET_DIS|BUF_DIS|adObj->polar|adObj->gain;
  WriteAD7192Register(adObj,AD7192_REG_CONF, 1);
  //ģʽ�Ĵ���������ת��ģʽ������״̬ͬ�����ڲ�ʱ�������ն��4��ʹ����żУ�飬����Ƶ�����õ�����ת��ʹ�ܣ�����60Hz�ݲ�
  adObj->Registers[AD7192_REG_MODE] = 0;
  adObj->Registers[AD7192_REG_MODE] = MODE_SING|DAT_STA_DIS|INCLK_MCLK2EN|SINC_4|ENPAR_EN|CLK_DIV_DIS|SINGLECYCLE_DIS|REJ60_DIS|adObj->fs;
  WriteAD7192Register(adObj,AD7192_REG_MODE, 1);
}

/*��������ת��*/
static void AD7192StartContinuousConvertion(Ad7192ObjectType *adObj,uint32_t Channels)
{
  //ģʽ�Ĵ���������ת��ģʽ��ʹ��״̬ͬ�����ڲ�ʱ�������ն��4��ʹ����żУ�飬����Ƶ�����õ�����ת��ʹ�ܣ�����60Hz�ݲ�
  adObj->Registers[AD7192_REG_MODE] = 0;
  adObj->Registers[AD7192_REG_MODE] = MODE_CONT|DAT_STA_EN|INCLK_MCLK2EN|SINC_4|ENPAR_EN|CLK_DIV_DIS|SINGLECYCLE_DIS|REJ60_DIS|adObj->fs;
  //���üĴ�����ն�����ã���׼��ѹ1������ͨ�������ü������������û�׼��ѹ��⣬���û�����
  adObj->Registers[AD7192_REG_CONF] = 0;
  adObj->Registers[AD7192_REG_CONF] = CHOP_DIS|REF_IN1|Channels|BURN_DIS|REFDET_DIS|BUF_DIS|adObj->polar|adObj->gain;	
  WriteAD7192Register(adObj,AD7192_REG_MODE, 2);
}

/*��ȡ�ڲ��¶����ݣ��������϶��¶�*/
float GetTemperatureValue(Ad7192ObjectType *adObj)
{
  uint32_t temperatureCode=0;
  float temp = 0.0;
  //ģʽ�Ĵ���������ת��ģʽ������״̬ͬ�����ڲ�ʱ�������ն��4��ʹ����żУ�飬����Ƶ�����õ�����ת��ʹ�ܣ�����60Hz�ݲ�
  adObj->Registers[AD7192_REG_MODE] = 0;
  adObj->Registers[AD7192_REG_MODE] = MODE_SING|DAT_STA_DIS|INCLK_MCLK2EN|SINC_4|ENPAR_EN|CLK_DIV_DIS|SINGLECYCLE_DIS|REJ60_DIS|adObj->fs;
  WriteAD7192Register(adObj,AD7192_REG_MODE, 1);
  //���üĴ�����ն�����ã���׼��ѹ1���ڲ��¶ȣ����ü������������û�׼��ѹ��⣬���û�����
  adObj->Registers[AD7192_REG_CONF] = 0;  
  adObj->Registers[AD7192_REG_CONF] = CHOP_DIS|REF_IN1|TEMP|BURN_DIS|REFDET_DIS|BUF_DIS|UB_BI|GAIN_1;
  WriteAD7192Register(adObj,AD7192_REG_CONF, 1);

  temperatureCode = AD7192ReadConvertingData(adObj);
  temp = (temperatureCode-0x800000)/2815.0-273;
  return temp;
}

/* Ĭ�ϵ�Ƭѡ�źŴ����� */
static void AD719xChipSelect(AD7192CSType cs)
{
  return;
}

/*********** (C) COPYRIGHT 1999-2017 Moonan Technology *********END OF FILE****/
