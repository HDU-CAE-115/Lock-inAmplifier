#include "Usermain.h"

#define NUM_OF_ADC_BUF 60
#define NUM_OF_ADC_CHANNEL 4
#define ADC1_CHANNEL_1 0
#define ADC1_CHANNEL_2 1
#define ADC1_CHANNEL_3 2
#define ADC1_CHANNEL_4 3

volatile uint16_t adc1_val_buf[NUM_OF_ADC_BUF][NUM_OF_ADC_CHANNEL] = {0}; //传递给DMA存放多通道采样值的数组
volatile	uint8_t AdcConvEnd = 0;
	
int op_cnt = 1;
int i = 0;
float signal_output = 0;
float adc_result[MAXDATASIZE] = {0};
char SIGOP[45] = {0};

void Usermain(){
	//OLED初始化
	OLED_Init();
	OLED_ShowString(5, 0, "---------------", 16);
	
	//初始化、开启DAC和ADC
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0);
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
	
	HAL_TIM_Base_Start_IT(&htim6);
	HAL_ADCEx_Calibration_Start(&hadc1,ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*) &adc1_val_buf, NUM_OF_ADC_BUF*NUM_OF_ADC_CHANNEL*2);
	
	//锁相放大器初始化
	TpLockInAmp_initialize();
	
	while(1){
		if(i>=NUM_OF_ADC_BUF) i=0;
		printf("%f\r\n",(float)adc1_val_buf[i][ADC1_CHANNEL_2]*3.3/4095);
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t) adc1_val_buf[i][ADC1_CHANNEL_1]);
		//sprintf(SIGOP, "%f", (float)adc1_val_buf[i]*3.3/4095);
		//OLED_ShowString(5, 3, SIGOP, 16);
		signal_input = (float)(adc1_val_buf[i][ADC1_CHANNEL_1]*3.3/4095-1.66);
		TpLockInAmp_step();
		signal_output = signal_amp;
		//HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, signal_output/3.3*4095);
		//printf("%f\r\n",signal_output);
		i++;
		if( ( op_cnt++ ) % 100 == 0 ){
			//OLED_Clear();
			sprintf(SIGOP, "%f", signal_amp);
			OLED_ShowString(5, 3, SIGOP, 16);
		}
//		//printf("%f\n",signal_output);
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
