#include "Usermain.h"
#define Immediate //Immediate|Temporary

int cnt = 0;
float result = 0;
float signal_output = 0;
float amp_avr = 0;
float adc_result[MAXDATASIZE] = {0};

void Usermain(){
	//初始化、开启DAC
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 2048);
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
	//AD7190初始化
	AD7190_RST();
	//写配置寄存器
	AD7190_WR_ConfigReg(0x00,0x10,0x08);//通道1、1倍增益
	//写模式寄存器7
	AD7190_WR_ModeReg(0x0C,0x00,0x14);// 240HZ、960HZ(0x05)

//	buf[0] = 0x28;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register 
//	buf[0] = 0x40;
//	HAL_SPI_Transmit(&hspi1,buf,1,1000);//control the progress to write mode register

#ifdef Temporary

	AD7190_ReadDataContinous(MAXDATASIZE);
	AD7190_ValueConversion(adc_result,MAXDATASIZE);
	//for(cnt = 0;cnt<MAXDATASIZE;cnt++) printf("%lf\n",adc_result[cnt]);
	TpLockInAmp_initialize();//锁相放大器初始化
	//printf("***********************\n");
	cnt=0;
	while(cnt<MAXDATASIZE){
		signal_input = adc_result[cnt];
		TpLockInAmp_step();
		signal_output = signal_amp;
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (signal_output/3.3)*4096);
		printf("%lf\n",signal_output);
//		if( (cnt==(MAXDATASIZE-500)) || (cnt==(MAXDATASIZE-450)) || (cnt==(MAXDATASIZE-400)) || (cnt==(MAXDATASIZE-350))
//			|| (cnt==MAXDATASIZE-300) || (cnt==(MAXDATASIZE-250)) || (cnt==(MAXDATASIZE-200)) || (cnt==(MAXDATASIZE-150))
//			|| (cnt==(MAXDATASIZE-100)) || (cnt==(MAXDATASIZE-50)) || (cnt==MAXDATASIZE) ){
//			amp_avr += signal_output;
//		}
		cnt++;
	}
//	TpLockInAmp_terminate();//锁相放大器停止
	//printf("***********************\n");
	while(1){
		cnt = 0;
		AD7190_ReadDataContinous(MAXDATASIZE);
		AD7190_ValueConversion(adc_result,MAXDATASIZE);
		while(cnt<MAXDATASIZE){
			signal_input = adc_result[cnt];
			TpLockInAmp_step();
			signal_output = signal_amp;
			if(cnt>1000){
				HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (signal_output/3.3)*4096);
				printf("%lf\n",signal_output);
			}
			cnt++;
		}
	}

#elif defined Immediate
	
	TpLockInAmp_initialize();
	while(1){
		signal_input = AD7190_ReadDataOnce();
		TpLockInAmp_step();
		signal_output = signal_amp;
		//HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (signal_output/3.3)*4096);
		//printf("%lf %lf %lf %lf %lf %lf\n",signal_input,TpLockInAmp_B.LowpassFilter.LowpassFilter,TpLockInAmp_B.MovingAverage2.MovingAverage1,TpLockInAmp_B.LowpassFilter1.LowpassFilter,TpLockInAmp_B.MovingAverage1.MovingAverage1,signal_output);
		//printf("%lf\n",signal_output);
	}

#endif

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
