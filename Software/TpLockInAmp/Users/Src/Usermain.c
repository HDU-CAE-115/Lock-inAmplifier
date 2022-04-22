#include "Usermain.h"

//#define USE_AD7190
#define USE_MCUADC

#ifdef USE_AD7190
#define MAXDATASIZE 2048
float adc_result[MAXDATASIZE] = {0};
char ADC_VALUE[512] = {0};																											//ADC7190值显示数组
#elif defined USE_MCUADC
#define NUM_OF_ADC_BUF 60																										//ADC数组行数60
#define NUM_OF_ADC_CHANNEL 4																								//ADC通道数、数组列数60
#define ADC1_CHANNEL_1 0																											//通道0
#define ADC1_CHANNEL_2 1																											//通道1
#define ADC1_CHANNEL_3 2																											//通道2
#define ADC1_CHANNEL_4 3																											//通道3

volatile uint16_t adc1_val_buf[NUM_OF_ADC_BUF][NUM_OF_ADC_CHANNEL] = {0}; 	//传递给DMA存放多通道采样值的数组
volatile	uint8_t AdcConvEnd = 0;

uint8_t app_flag = 0;																																//追加标志位
uint8_t step_flag = 0;																															//步进标志位
float sum_value = 0;																															//240次采样和
char AVE[512] = {0};																															//均值显示数组
#endif

float signal_amp = 0;																															//锁相放大器输出幅值
uint8_t i = 0;																																			//ADC行计数变量

uint8_t display_cnt = 0;																														//1/240s计数
uint8_t display_flag = 0;																														//显示标志位
uint32_t time_cnt = 0;																															//秒数计数
char TIME_CNT[512] = {0};																													//秒数显示数组

void Usermain(){
	//OLED初始化
	uint8_t res = SSD1306_Init();
//	SSD1306_Fill(0);
//	OLED_Init(hi2c1);
//	OLED_BOOL_DrawStr(5,5,"Time:",OLED_BOOL_Replace);
//	OLED_Refresh(); 
//	//初始化DAC
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0);
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
//	
//	//LED点亮
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin,GPIO_PIN_RESET);
#ifdef USE_AD7190
	//AD7190初始化
	AD7190_RST();
	//写配置寄存器
	AD7190_WR_ConfigReg(0x00,0x20,0x08);//通道2、1倍增益
	//写模式寄存器7
	AD7190_WR_ModeReg(0x0C,0x00,0x14);// 240HZ(0x14)、400Hz(0x0C)、480Hz(0x0A)、960HZ(0x05)

	//锁相放大器初始化
	TpLockInAmpV1_initialize();
	
	//开启定时器7
	HAL_TIM_Base_Start_IT(&htim7);
#elif defined USE_MCUADC
	//初始化打开定时器2
	HAL_TIM_Base_Start_IT(&htim2);
	
	//初始化4通道ADC+校准
	HAL_ADCEx_Calibration_Start(&hadc1,ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*) &adc1_val_buf, NUM_OF_ADC_BUF*NUM_OF_ADC_CHANNEL*2);
	
	//初始化开启OPAMP
	HAL_OPAMP_Start(&hopamp2);
	HAL_OPAMP_Start(&hopamp3); 
#endif

	SSD1306_GotoXY(20,35);
	SSD1306_Puts("Ready!", &Font_11x18, 1);
	SSD1306_UpdateScreen(); 
	HAL_Delay(500);
	while(1){
#ifdef USE_AD7190
//		signal_input = AD7190_ReadDataOnce()-1;
//		TpLockInAmpV1_step();
//		signal_amp = signal_output;
		printf("%f\r\n",AD7190_ReadDataOnce());
//		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, signal_input/3.3*4095);
//		sprintf(ADC_VALUE, "%.5f", signal_input);
//		SSD1306_GotoXY(20,35);
//		SSD1306_Puts(ADC_VALUE, &Font_11x18, 1);
//		SSD1306_UpdateScreen(); 		
//		if(display_flag)
//		{
//			display_flag = 0;
//			sprintf(TIME_CNT, "Time: %d s", ++time_cnt);
//			SSD1306_GotoXY(5,5);
//			SSD1306_Puts(TIME_CNT, &Font_7x10, 1);
//			sprintf(ADC_VALUE, "%.5f", signal_amp);
//			SSD1306_GotoXY(20,35);
//			SSD1306_Puts(ADC_VALUE, &Font_11x18, 1);
//			SSD1306_UpdateScreen(); 																			//显示
//		}
#elif defined USE_MCUADC
		if(i>=NUM_OF_ADC_BUF) i=0;
		if(display_flag)		
		{
			display_flag = 0;
			sprintf(TIME_CNT, "Time: %d s", ++time_cnt);
//			OLED_BOOL_DrawStr(35,5,TIME_CNT,OLED_BOOL_Replace);
			SSD1306_GotoXY(5,5);
			SSD1306_Puts(TIME_CNT, &Font_7x10, 1);
			sprintf(AVE, "%f", sum_value/240);
			sum_value = 0;
//			OLED_BOOL_DrawStr(5,30,AVE,OLED_BOOL_Replace);
			SSD1306_GotoXY(20,35);
			SSD1306_Puts(AVE, &Font_11x18, 1);
			SSD1306_UpdateScreen(); 																			//显示
//			OLED_Refresh();
		}
		if(app_flag)
		{
			app_flag = 0;
			sum_value += (float)adc1_val_buf[i][ADC1_CHANNEL_1]*3.3/4095;
		}
//		//锁相放大器用
//		signal_input = (float)adc1_val_buf[i][ADC1_CHANNEL_3]*3.3/4095-2.5;
//		TpLockInAmpV1_step();
//		signal_amp = signal_output;
//		if(display_flag){
//			display_flag = 0;
//			sprintf(TIME_CNT, "Time: %d s", ++time_cnt);
//			SSD1306_GotoXY(5,5);
//			SSD1306_Puts(TIME_CNT, &Font_7x10, 1);
//			sprintf(AVE, "%f", signal_amp);
//			
//			SSD1306_GotoXY(20,35);
//			SSD1306_Puts(AVE, &Font_11x18, 1);
//			SSD1306_UpdateScreen();
//		}
		i++;
#endif
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
#ifdef USE_AD7190
	if(htim->Instance==TIM7)//1s
	{
		display_flag = 1;
	}
#elif defined USE_MCUADC
	if(htim->Instance==TIM2)//1/240s
	{
//		step_flag = 1;
		app_flag = 1;
		display_cnt ++;
		if(display_cnt >= 240)
		{
			display_cnt = 0;
			display_flag = 1;
		}
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
