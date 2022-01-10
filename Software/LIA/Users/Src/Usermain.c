#include "Usermain.h"
#define MAXDATASIZE 1024
int cnt = 0;
double result = 0;
double signal_output = 0;
double signal_input1 = 0;
unsigned char ID[1] = {0};
double adc_result[MAXDATASIZE] = {0};
//union test{
//	unsigned char t[4];
//	uint32_t te;
//}tes;
void Usermain(){
//AD7190初始化
	AD7190_RST();
//写配置寄存器
	AD7190_WR_ConfigReg(0x00,0x10,0x08);
//写模式寄存器
	AD7190_WR_ModeReg(0x0C,0x00,0x02);
//	buf[0] = 0x28;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register 
//	buf[0] = 0x40;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register
	
	while(cnt<MAXDATASIZE){
		adc_result[cnt] = AD7190_ReadDataC();
		printf("%lf\n",adc_result[cnt]);
		cnt++;
	}
	cnt = 0;
	TpLockInAmp_initialize();//锁相放大器初始化
	printf("*********************\r\n");
	while(1){
		if(cnt<MAXDATASIZE){
			signal_input = adc_result[cnt];
			//printf("%lf\n",signal_input);
			TpLockInAmp_step();
			signal_output = signal_amp;
			printf("%lf\n",signal_output);
			cnt++; 
		}
		else TpLockInAmp_terminate();//锁相放大器停止
	}
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