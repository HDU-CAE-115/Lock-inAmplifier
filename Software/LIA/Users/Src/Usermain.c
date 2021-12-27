#include "Usermain.h"
int adc_result = 0x00;
unsigned	char	buf[4] = {0,0,0,0};
unsigned char reset[1] = {0xFF};
double result = 0;
unsigned char ID[1] = {0};
void Usermain(){
	init_AD7190_cmds();
//	AD7190_reset();
//	for(int i = 0 ; i < 6; i++)
//	SPIDEV1_single_transfer(0xFF);
//	HAL_Delay(20);
//	ID[0] = AD7190_get_ID();
/*
	config 0x10 0x00 0x20 0x08
	mode 0x08 0x00 0x00 0x05
	GPO  0x28 0x40
	stat   0x40 0x00
	data  0x58 0xFF 0xFF 0xFF
	*/
//	AD7190_configure(0x00,0x20,0x08);//通道四、单极性
//	AD7190_mode(0x00,0x00,0x05);//fs960Hz	
	buf[0] = 0x10;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);	  	//write communication register 0x10 to control the progress to write configuration register 

	buf[0] = 0x00;
	buf[1] = 0x20;
	buf[2] = 0x08;
	HAL_SPI_Transmit(&hspi1,buf,3,1000);//write configuration register,unipolar operation,gain=1,channel:AIN1 to AIN2

	buf[0] = 0x08;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);//write communication register 0x08 to control the progress to write mode register 

	buf[0] = 0x00;
	buf[1] = 0x00;
	buf[2] = 0x05;
	HAL_SPI_Transmit(&hspi1,buf,3,1000);//write mode register,internal 4.92MHz clock,output data rate=4.7Hz

 	buf[0] = 0x50;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);//write communication register 0x50 to control the progress to read configuration register
	HAL_SPI_Receive(&hspi1,buf,3,1000);//read configuration register
//	putchar(buf[2]);
//	putchar(buf[1]);
//	putchar(buf[0]);

 	buf[0] = 0x58;
	HAL_SPI_Transmit(&hspi1,buf,1,1000);//write communication register 0x58 to control the progress to read data register
	HAL_SPI_Receive(&hspi1,buf,3,1000);//read data register
//	putchar(buf[2]);
//	putchar(buf[1]);
//	putchar(buf[0]);
	while(1){
//		adc_result = AD7190_read_data();
	}
}

//#ifdef __GNUC__
//#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
//#else
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
//#endif 


///* printf重定向 */
//int fputc(int ch,FILE *f)
//{
//    uint8_t temp[1]={ch};
//    HAL_UART_Transmit(&huart1,temp,1,10);        //UartHandle??????
//  return ch;
//}


//PUTCHAR_PROTOTYPE
//{
// HAL_UART_Transmit(&huart1,(uint8_t*)&ch,1,10);
// return ch;
//}
