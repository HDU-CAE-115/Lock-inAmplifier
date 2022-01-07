#include "Usermain.h"
int adc_result = 0x00;
unsigned	char	buf[4] = {0};
unsigned	char	rbuf[3] = {0};
unsigned	char	data[3] = {0};
uint32_t result = 0;
double value = 0;
unsigned char ID[1] = {0};

void Usermain(){
	//reset
	AD7190_RST();
	HAL_Delay(20);
	ID[0] = AD7190_get_ID();
//Ð´ÅäÖÃ¼Ä´æÆ÷
	AD7190_WR_ConfigReg(0x00,0x80,0x08);
//Ð´Ä£Ê½¼Ä´æÆ÷
	AD7190_WR_ModeReg(0x0C,0x00,0x02);
//	buf[0] = 0x28;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register 
//	buf[0] = 0x40;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register 

	while(1){
		//¶Á×´Ì¬¼Ä´æ
		result = 0;
		buf[0] = 0x40;
		HAL_SPI_Transmit(&hspi1,buf,1,1000);
		HAL_SPI_Receive(&hspi1,rbuf,1,1000);
		if((rbuf[0] & 0x80)==0){//Èç¹ûRDYÖÃÁã£¬¶ÁÊý¾Ý
			//printf("***********************\n%d\n",result);
			buf[0] = 0x58;
			HAL_SPI_Transmit(&hspi1,buf,1,1000);//write communication register 0x58 to control the progress to read data register
			HAL_SPI_Receive(&hspi1,data,3,1000);//read data register
			result = (result | data[0]) << 8;
			//printf("%d %d\n",result,data[0]);
			result = (result | data[1]) << 8;
			//printf("%d %d\n",result,data[1]);
			result = (result | data[2]);
			//printf("%d %d\n",result,data[2]);
			result = result&0x00FFFFFF;
			//printf("%d\n",result);
			value = (result*5)/pow(2,24);
			printf("%lf\n",value);
		}
;//			HAL_SPI_Transmit(&hspi1,buf,1,1000);
//			HAL_SPI_Receive(&hspi1,ID,1,1000);//read configuration register
//		adc_result = AD7190_read_data();
	}
}

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
	buf[1] = cbyte_1;//Í¨µÀ4
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

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1 , 0xffff);
    return ch;
}





