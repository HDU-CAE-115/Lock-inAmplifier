#include "AD719X.h"

double value = 0;

void AD7190_RST(){
	unsigned char reset[1] = {0xFF};
	for(int i = 0 ; i < 55; i++){
		HAL_SPI_Transmit(&hspi1,reset,1,1000);
	}
}

void AD7190_WR_ConfigReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0){
	unsigned	char	buf[4] = {0};
	unsigned	char	rbuf[3] = {0};
	buf[0] = 0x10;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);	
	buf[0] = cbyte_2;
	buf[1] = cbyte_1;//通道4
	buf[2] = cbyte_0;
	HAL_SPI_Transmit(&hspi1,buf,3,1000);
}

void AD7190_WR_ModeReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0){
	unsigned	char	buf[4] = {0};
	unsigned	char	rbuf[3] = {0};
	buf[0] = 0x08;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);
	buf[0] = cbyte_2;//0x0C
	buf[1] = cbyte_1;
	buf[2] = cbyte_0;
	HAL_SPI_Transmit(&hspi1,buf,3,1000);
}

double AD7190_ReadDataC(void){
		uint32_t result = 0;
		uint16_t timeOutCnt = 0xFF;
		unsigned	char	buf[4] = {0};
		unsigned	char	rbuf[3] = {0};
		unsigned	char	data[3] = {0};
		value = 0;
		buf[0] = 0x40;
		HAL_SPI_Transmit(&hspi1,buf,1,1000);
		HAL_SPI_Receive(&hspi1,rbuf,1,1000);
		while( ((rbuf[0] & 0x80) !=0 ) && timeOutCnt-- ){//如果RDY置零，读数据
			;
		}
		buf[0] = 0x58;
		HAL_SPI_Transmit(&hspi1,buf,1,1000);//read data register
		HAL_SPI_Receive(&hspi1,data,3,1000);//read data register
		result = (result | data[0]) << 8;
		result = (result | data[1]) << 8;
		result = (result | data[2]);
		result = result&0x00FFFFFF;//24位
		value = (result*5)/pow(2,24) - V_REF;
		return value;
}