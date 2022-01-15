#include "AD719X.h"

double value = 0;
uint32_t AD7190_data[MAXDATASIZE] = {0};

void AD7190_RST(void){
	unsigned char reset_cmd[7] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
		HAL_SPI_Transmit(&hspi1,reset_cmd,7,1000);
}

void AD7190_WR_ConfigReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0){
	unsigned	char	buf[4] = {0};
	buf[0] = 0x10;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);	
	buf[0] = cbyte_2;
	buf[1] = cbyte_1;//通道4
	buf[2] = cbyte_0;
	HAL_SPI_Transmit(&hspi1,buf,3,1000);
}

void AD7190_WR_ModeReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0){
	unsigned	char	buf[4] = {0};
	buf[0] = 0x08;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);
	buf[0] = cbyte_2;//0x0C
	buf[1] = cbyte_1;
	buf[2] = cbyte_0;
	HAL_SPI_Transmit(&hspi1,buf,3,1000);
}

void AD7190_ReadDataContinous(int length){
		uint16_t timeOutCnt = 0xFFFF;
		unsigned	char	buf[4] = {0};
		unsigned	char	rbuf[3] = {0};
		unsigned	char	rdata[3] = {0};
		for(int i = 0 ;i < length; i++){
			//value = 0;
			buf[0] = 0x40;
			HAL_SPI_Transmit(&hspi1,buf,1,1000);
			HAL_SPI_Receive(&hspi1,rbuf,1,1000);
			while(((rbuf[0] & 0x80) !=0) && timeOutCnt--){//如果RDY置零，读数据
				buf[0] = 0x40;
				HAL_SPI_Transmit(&hspi1,buf,1,1000);
				HAL_SPI_Receive(&hspi1,rbuf,1,1000);
			}
			buf[0] = 0x58;
			HAL_SPI_Transmit(&hspi1,buf,1,1000);//read data register
			HAL_SPI_Receive(&hspi1,rdata,3,1000);//read data register
			AD7190_data[i] = (AD7190_data[i] | rdata[0]) << 8;
			AD7190_data[i] = (AD7190_data[i] | rdata[1]) << 8;
			AD7190_data[i] = (AD7190_data[i] | rdata[2]);
			AD7190_data[i] = AD7190_data[i] & 0x00FFFFFF;//24位
			//value = (result*5)/pow(2,24) - V_REF;
			//return value;
	}
}

void AD7190_ValueConversion(float *value,int length){//double
	for(int i=0; i<length; i++)
	value[i] = (AD7190_data[i]*5)/pow(2,24) - V_REF;
}

double AD7190_ReadDataOnce(void){
		uint32_t result = 0;
		uint16_t timeOutCnt = 0xFFFF;
		unsigned	char	buf[4] = {0};
		unsigned	char	rbuf[3] = {0};
		unsigned	char	rdata[3] = {0};
		value = 0;
		buf[0] = 0x40;
		HAL_SPI_Transmit(&hspi1,buf,1,1000);
		HAL_SPI_Receive(&hspi1,rbuf,1,1000);
		while(((rbuf[0] & 0x80) !=0) && timeOutCnt--){//如果RDY置零，读数据
			buf[0] = 0x40;
			HAL_SPI_Transmit(&hspi1,buf,1,1000);
			HAL_SPI_Receive(&hspi1,rbuf,1,1000);
		}
		buf[0] = 0x58;
		HAL_SPI_Transmit(&hspi1,buf,1,1000);//read data register
		HAL_SPI_Receive(&hspi1,rdata,3,1000);//read data register
		result = (result | rdata[0]) << 8;
		result = (result | rdata[1]) << 8;
		result = (result | rdata[2]);
		result = result & 0x00FFFFFF;//24位
		value = (result*5)/pow(2,24) - V_REF;
		return value;
}

