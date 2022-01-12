#include "Usermain.h"
#define MAXDATASIZE 1024
int cnt = 0;
double result = 0;
double signal_output = 0;
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
	AD7190_WR_ModeReg(0x0C,0x00,0x05);//960HZ
	
//	buf[0] = 0x28;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register 
//	buf[0] = 0x40;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register

	AD7190_ReadDataContinous(MAXDATASIZE);
	AD7190_ValueConversion(adc_result,MAXDATASIZE);
	//for(cnt = 0;cnt<MAXDATASIZE;cnt++) printf("%lf\n",adc_result[cnt]);
	TpLockInAmp_initialize();//锁相放大器初始化
	//printf("***********************\n");
	while(cnt<MAXDATASIZE){
			signal_input = adc_result[cnt];
			//printf("%lf\n",0.02365*sin(TpLockInAmp_DW.SineWave1_AccFreqNorm));
			TpLockInAmp_step();
			signal_output = signal_amp;
			printf("%lf\n",signal_output);
			cnt++;
	}
	TpLockInAmp_terminate();//锁相放大器停止
	while(1){
		
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
