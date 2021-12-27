/******************************************************************************/
/** ģ�����ƣ���չ��������                                                   **/
/** �ļ����ƣ�ad7192function.h                                               **/
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

#ifndef __AD7192FUNCTION_H
#define __AD7192FUNCTION_H

#include "stdint.h"

/* ����AD7192�������� */
typedef enum AD7192Error {
  AD7192_OK,            //�޴���
  AD7192_InitError,     //��ʼ������
}AD7192ErrorType;

/* ����AD7192Ƭѡ�ź�ö�� */
typedef enum AD719xCS {
  AD7192CS_Enable,
  AD7192CS_Disable
}AD7192CSType;

/*����AD7192У׼��ʽö��*/
typedef enum AD7192Calibration {
  AD7192_Internal,	//�ڲ�У׼ģʽ
  AD7192_External		//�ⲿУ׼ģʽ
}AD7192CalibrationType;

/*����AD7192�Ĵ���ö��*/
typedef enum AD7192Register {
  AD7192_REG_COM_STA=0x00,      //��Ϊ״̬�Ĵ�����дΪͨѶ�Ĵ���*/
  AD7192_REG_MODE=0x01,         //����ģʽ�Ĵ���*/
  AD7192_REG_CONF=0x02,         //�������üĴ���*/
  AD7192_REG_DATA=0x03,         //�������ݼĴ���*/
  AD7192_REG_ID=0x04,           //����ID�Ĵ���*/
  AD7192_REG_GPOCON=0x05,       //����GPOCON�Ĵ���*/
  AD7192_REG_OFFSET=0x06,       //����ʧ���Ĵ���*/
  AD7192_REG_FS=0x07,           //���������̼Ĵ���*/
  AD7192RegisterNumber          //�Ĵ�������
}AD7192RegisterType;

/*����AD719x����ͨ��ö��*/
typedef enum AD7192Channel{
  CHAIN1AIN2=0x000100,  //���ͨ��1
  CHAIN3AIN4=0x000200,  //���ͨ��2
  CHTEMP=0x000400,      //�ڲ��¶�
  CHAIN2AIN2=0x000800,  //ģ��ͨ��2
  CHAIN1COM=0x001000,   //��������1
  CHAIN2COM=0x002000,   //��������2
  CHAIN3COM=0x004000,   //��������3
  CHAIN4COM=0x008000    //��������4
}AD7192ChannelType;

/* ����AD719x����ö������ */
typedef enum AD7192Gain {
  AD7192Gain1,          //1������
  AD7192Gain8,          //8������
  AD7192Gain16,         //16������
  AD7192Gain32,         //32������
  AD7192Gain64,         //64������
  AD7192Gain128         //128������
}AD7192GainType;

/* ����AD719x����ö������ */
typedef enum AD7192Polar {
  AD7192_Unipolar,      //������
  AD7192_Bipolar        //˫����
}AD7192PolarType;


/*�������ڲ����Ľṹ��*/
typedef struct Ad7192Object {
  uint8_t polar;        //ͨ���ļ���
  uint8_t gain;         //ͨ������
  uint16_t fs;          //��������ٶ�
  uint32_t Registers[8];        //��żĴ���ֵ������
  void (*ReadWrite)(uint8_t *wData,uint8_t *rData,uint16_t size);       //ʵ�ֶ�д����
  void (*ChipSelect)(AD7192CSType cs);  //ʵ��Ƭѡ
  uint16_t (*GetReadyInput)(void);      //ʵ��Ready״̬����
  void (*Delay)(volatile uint32_t nTime);       //ʵ��ms��ʱ����
}Ad7192ObjectType;

/*�����д��������ָ������*/
typedef void (*AD7192ReadWriteType)(uint8_t *wData,uint8_t *rData,uint16_t size);
/*ʵ��Ƭѡ*/
typedef void (*AD7192ChipSelectType)(AD7192CSType cs);
/*ʵ��Ready״̬����*/
typedef uint16_t (*AD7192GetReadyInputType)(void);
/*ʵ��ms��ʱ����*/
typedef void (*AD7192DelaymsType)(volatile uint32_t nTime);

/*����ת�����ݻ�ȡ*/
void GettContinuousConvertionValue(Ad7192ObjectType *adObj,uint32_t Channels,uint32_t *dataCodes,int number);

/*����ת�����ݻ�ȡ*/
uint32_t GetSingleConvertionValue(Ad7192ObjectType *adObj,uint32_t Channels);

/*��ȡ�ڲ��¶����ݣ��������϶��¶�*/
float GetTemperatureValue(Ad7192ObjectType *adObj);

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
                                    );
#endif
/*********** (C) COPYRIGHT 1999-2017 Moonan Technology *********END OF FILE****/
